/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 *
 * @brief
 * This sample program demonstrates how to use the NUC990 USB Host controller
 * to enumerate and communicate with USB Human Interface Device (HID) class
 * devices, such as keyboards, mice, and custom HID devices.
 *
 * The application performs the following operations:
 * - USB Host stack initialization (EHCI / OHCI)
 * - HID class device enumeration and device list management
 * - HID report descriptor parsing and dumping
 * - Standard HID class requests (GET_REPORT, GET_PROTOCOL, SET_PROTOCOL)
 * - Interrupt IN pipe handling with user callback
 * - Optional Interrupt OUT pipe support (compile-time enabled)
 *
 * The program continuously polls USB hub events and automatically initializes
 * newly attached HID devices. All debug and report data are printed through
 * UART0 for inspection and testing.
 *
 * @compile_option
 * - Define HAVE_INT_OUT to enable Interrupt OUT endpoint demonstration.
 *
 * @note
 * - Non-cacheable aligned memory is required for USB DMA buffers.
 * - This sample is intended for debugging, validation, and reference purposes.
 * - Some HID requests (e.g., report ID usage) may depend on device firmware.
 *
 * @copyright
 * Copyright (C) 2026 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#include <stdio.h>
#include <string.h>

#include "NuMicro.h"
#include "usbh_lib.h"
#include "usbh_hid.h"

//#define HAVE_INT_OUT

uint32_t g_buff_pool[1024] __attribute__((aligned(32)));

HID_DEV_T *g_hid_list[CONFIG_HID_MAX_DEV];

volatile uint32_t  g_ticks;

void TIMER0_IRQHandler(void)
{
    g_ticks++;
    TIMER_ClearIntFlag(TIMER0);
}

uint32_t  get_ticks(void)
{
    // return g_ticks;
    return g_ticks++/1000;
}

void Start_TIMER0(void)
{
    g_ticks = 0;

    sysInstallISR(IRQ_LEVEL_1, TIMER0_IRQn, (PVOID)TIMER0_IRQHandler);
    sysSetLocalInterrupt(ENABLE_IRQ);
    sysEnableInterrupt(TIMER0_IRQn);

    TIMER_Open(TIMER0, TIMER_PERIODIC_MODE, 100);
    TIMER_EnableInt(TIMER0);
    TIMER_Start(TIMER0);
}

void delay_us(int usec)
{
    volatile int  loop = 2 * usec;
    while (loop > 0) loop--;
}

void  dump_buff_hex(uint8_t *pucBuff, int nBytes)
{
    int     nIdx, i;

    nIdx = 0;
    while (nBytes > 0) {
        printf("0x%04X  ", nIdx);
        for (i = 0; (i < 16) && (nBytes > 0); i++) {
            printf("%02x ", pucBuff[nIdx + i]);
            nBytes--;
        }
        nIdx += 16;
        printf("\n");
    }
    printf("\n");
}

int  is_a_new_hid_device(HID_DEV_T *hdev)
{
    int    i;
    for (i = 0; i < CONFIG_HID_MAX_DEV; i++) {
        if ((g_hid_list[i] != NULL) && (g_hid_list[i] == hdev) &&
                (g_hid_list[i]->uid == hdev->uid))
            return 0;
    }
    return 1;
}

void update_hid_device_list(HID_DEV_T *hdev)
{
    int  i = 0;
    memset(g_hid_list, 0, sizeof(g_hid_list));
    while ((i < CONFIG_HID_MAX_DEV) && (hdev != NULL)) {
        g_hid_list[i++] = hdev;
        hdev = hdev->next;
    }
}

void  int_read_callback(HID_DEV_T *hdev, uint16_t ep_addr, int status, uint8_t *rdata, uint32_t data_len)
{
    /*
     *  USB host HID driver notify user the transfer status via <status> parameter. If the
     *  If <status> is 0, the USB transfer is fine. If <status> is not zero, this interrupt in
     *  transfer failed and HID driver will stop this pipe. It can be caused by USB transfer error
     *  or device disconnected.
     */
    if (status < 0) {
        printf("Interrupt in transfer failed! status: %d\n", status);
        return;
    }
    printf("Device [0x%x,0x%x] ep 0x%x, %d bytes received =>\n",
           hdev->idVendor, hdev->idProduct, ep_addr, data_len);
    dump_buff_hex(rdata, data_len);
}

#ifdef HAVE_INT_OUT
void  int_write_callback(HID_DEV_T *hdev, uint16_t ep_addr, int staus, uint8_t *wbuff, uint32_t *data_len)
{
    int   max_len = *data_len;

    printf("Device [0x%x,0x%x] ep 0x%x, ask user to fill data buffer and length.\n",
           hdev->idVendor, hdev->idProduct, ep_addr);

    memset(wbuff, 0, max_len);         /* Fill data to be sent via interrupt out pipe     */

    *data_len = max_len;               /* Tell HID driver transfer length of this time    */
}
#endif

int  init_hid_device(HID_DEV_T *hdev)
{
    uint8_t   *data_buff;
    int       i, ret;

    data_buff = (uint8_t *)((uint32_t)g_buff_pool | 0x80000000);

    printf("\n\n==================================\n");
    printf("  Init HID device : 0x%x\n", (int)hdev);
    printf("  VID: 0x%x, PID: 0x%x\n\n", hdev->idVendor, hdev->idProduct);

    ret = usbh_hid_get_report_descriptor(hdev, data_buff, 1024);
    if (ret > 0) {
        printf("\nDump report descriptor =>\n");
        dump_buff_hex(data_buff, ret);
    }

    /*
     *  Example: GET_PROTOCOL request.
     */
    ret = usbh_hid_get_protocol(hdev, data_buff);
    printf("[GET_PROTOCOL] ret = %d, protocol = %d\n", ret, data_buff[0]);

    /*
     *  Example: SET_PROTOCOL request.
     */
    ret = usbh_hid_set_protocol(hdev, data_buff[0]);
    printf("[SET_PROTOCOL] ret = %d, protocol = %d\n", ret, data_buff[0]);

    /*
     *  Example: GET_REPORT request on report ID 0x1, report type FEATURE.
     */
    ret = usbh_hid_get_report(hdev, RT_FEATURE, 0x1, data_buff, 64);
    if (ret > 0) {
        printf("[GET_REPORT] Data => ");
        for (i = 0; i < ret; i++)
            printf("%02x ", data_buff[i]);
        printf("\n");
    }

    printf("\nUSBH_HidStartIntReadPipe...\n");
    ret = usbh_hid_start_int_read(hdev, 0, int_read_callback);
    if (ret != HID_RET_OK)
        printf("usbh_hid_start_int_read failed! %d\n", ret);
    else
        printf("Interrupt in transfer started...\n");

#ifdef HAVE_INT_OUT
    ret = usbh_hid_start_int_write(hdev, 0, int_write_callback);
    if ((ret != HID_RET_OK) && (ret != HID_RET_EP_USED))
        printf("usbh_hid_start_int_write failed!\n");
    else
        printf("Interrupt out transfer started...\n");
#endif

    return 0;
}

void SYS_Init()
{
    SYS_UnlockReg();

    CLK_SetModuleClock(UART0_MODULE, CLK_DIV4_UART0SEL_HXT, CLK_DIV4_UART0(1));

    CLK_EnableModuleClock(USBH_MODULE);
    CLK_EnableModuleClock(TMR0_MODULE);
    CLK_EnableModuleClock(UART0_MODULE);

    /* set USRHDSEN as 1; USB host/device role selection decided by USBID (SYS_PWRON[16]) */
    SYS->MISCFCR |= SYS_MISCFCR_USRHDSEN_Msk;

    /* set USB port 0 used for Host */
    SYS->PWRON |= SYS_PWRON_USBID_Msk;

    SET_USB_OVC_PE10();
    SET_USBH_PWREN_PE12();

    SET_UART0_RXD_PF11();
    SET_UART0_TXD_PF12();
}

void UART0_Init(void)
{
    sysResetModule(UART0_RST);
    UART_Open(UART0, 115200);
    UART0->BAUD = 0x3000000E;  /* for palladium */
}

/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int32_t main(void)
{
    HID_DEV_T *hdev, *hdev_list;

    SYS_UnlockReg();

    sysDisableCache();
    sysFlushCache(I_D_CACHE);
    sysEnableCache(CACHE_WRITE_BACK);

    SYS_Init();

    UART0_Init();

    Start_TIMER0();

    printf("\n\n");
    printf("+-----------------------------------------------+\n");
    printf("|                                               |\n");
    printf("|     USB Host HID class sample program         |\n");
    printf("|                                               |\n");
    printf("+-----------------------------------------------+\n");

    usbh_core_init();
    usbh_hid_init();
    usbh_memory_used();

    memset(g_hid_list, 0, sizeof(g_hid_list));

    while (1)
    {
        if (usbh_pooling_hubs())
        {
            usbh_memory_used();

            printf("\n Has hub events.\n");
            hdev_list = usbh_hid_get_device_list();
            hdev = hdev_list;
            while (hdev != NULL)
            {
                if (is_a_new_hid_device(hdev))
                    init_hid_device(hdev);

                hdev = hdev->next;
            }
            update_hid_device_list(hdev_list);
            usbh_memory_used();
        }
    }
}
