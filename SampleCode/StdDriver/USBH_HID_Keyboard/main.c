/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 *
 * @brief
 * This sample program demonstrates how to use the NUC990 USB Host controller
 * to operate a USB HID keyboard device. It shows how to receive keyboard
 * interrupt reports, translate HID key codes to ASCII characters, and handle
 * keyboard states such as modifier keys and LED indicators.
 *
 * The application performs the following operations:
 * - USB Host stack initialization (EHCI / OHCI)
 * - HID keyboard device enumeration
 * - HID report descriptor retrieval
 * - Interrupt IN pipe setup for keyboard input
 * - Separation of interrupt-context callback and main-loop processing
 * - HID keyboard report parsing and key state tracking
 * - OEM key code to ASCII translation
 * - Handling of modifier keys (Shift, Ctrl, Alt)
 * - Handling of locking keys and LED control (Caps Lock, Num Lock, Scroll Lock)
 *
 * To minimize processing time in interrupt context, the interrupt callback
 * only copies received HID reports to a buffer. The actual keyboard report
 * parsing and key processing are handled later in the main loop.
 *
 * All keyboard events and translated ASCII characters are output via UART0
 * for debugging and verification.
 *
 * @note
 * - Non-cacheable aligned memory is required for USB DMA buffers.
 * - This sample supports one keyboard device at a time.
 * - HID report format and key mapping follow the USB HID specification.
 * - This code is intended for debugging, validation, and reference purposes.
 *
 * @copyright
 * Copyright (C) 2026 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#include <stdio.h>
#include <string.h>

#include "NuMicro.h"
#include "usbh_lib.h"
#include "usbh_hid.h"

uint32_t   g_buff_pool[1024] __attribute__((aligned(32)));

static HID_DEV_T  *hdev_ToDo = NULL;
static uint8_t    data_ToDo[8];

volatile uint32_t  g_ticks;
extern int  kbd_parse_report(HID_DEV_T *hdev, uint8_t *buf, int len);

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
    while (nBytes > 0)
    {
        printf("0x%04X  ", nIdx);
        for (i = 0; (i < 16) && (nBytes > 0); i++)
        {
            printf("%02x ", pucBuff[nIdx + i]);
            nBytes--;
        }
        nIdx += 16;
        printf("\n");
    }
    printf("\n");
}

void  int_read_callback(HID_DEV_T *hdev, uint16_t ep_addr, int status, uint8_t *rdata, uint32_t data_len)
{
    /*
     *  This callback is in interrupt context.
     *  Copy the device and data and then handle it somewhere not in interrupt context.
     */
    //dump_buff_hex(rdata, data_len);
    hdev_ToDo = hdev;
    memcpy(data_ToDo, rdata, sizeof(data_ToDo));
}


int  init_hid_device(HID_DEV_T *hdev)
{
    uint8_t   *data_buff;
    int       ret;

    data_buff = (uint8_t *)((uint32_t)g_buff_pool | 0x80000000);   // get non-cacheable buffer address

    printf("\n\n==================================\n");
    printf("  Init HID device : 0x%x\n", (int)hdev);
    printf("  VID: 0x%x, PID: 0x%x\n\n", hdev->idVendor, hdev->idProduct);

    ret = usbh_hid_get_report_descriptor(hdev, data_buff, 1024);
    if (ret > 0)
    {
        printf("\nDump report descriptor =>\n");
        dump_buff_hex(data_buff, ret);
    }

    printf("\nUSBH_HidStartIntReadPipe...\n");
    ret = usbh_hid_start_int_read(hdev, 0, int_read_callback);
    if (ret != HID_RET_OK)
        printf("usbh_hid_start_int_read failed!\n");
    else
        printf("Interrupt in transfer started...\n");

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
    HID_DEV_T *hdev;

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
    printf("|    USB Host HID Keyboard sample program       |\n");
    printf("|                                               |\n");
    printf("+-----------------------------------------------+\n");

    usbh_core_init();
    usbh_hid_init();
    usbh_memory_used();

    while (1)
    {
        if (usbh_pooling_hubs())
        {
            printf("\n Has hub events.\n");
            hdev = usbh_hid_get_device_list();
            if (hdev == NULL)
                continue;

            while (hdev != NULL)
            {
                init_hid_device(hdev);

                if (hdev != NULL)
                    hdev = hdev->next;
            }
        }

        if (hdev_ToDo != NULL)
        {
            kbd_parse_report(hdev_ToDo, data_ToDo, 8);
            hdev_ToDo = NULL;
        }
    }
}
