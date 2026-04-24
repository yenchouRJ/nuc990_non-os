/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 *
 * @brief
 * This sample program demonstrates how to use the NUC990 USB Host controller
 * to enumerate and communicate with USB CDC ACM (Virtual COM Port, VCOM)
 * devices, such as USB-to-UART converters.
 *
 * The application performs the following operations:
 * - USB Host stack initialization (EHCI / OHCI)
 * - USB CDC class device enumeration
 * - Multiple VCOM device management (up to MAX_VCOM_PORT ports)
 * - CDC control requests for line coding configuration
 *   (baud rate, parity, data bits, stop bits)
 * - Control line state configuration (DTR / RTS)
 * - CDC interrupt IN endpoint handling for status notification
 * - Bulk IN data reception with user callback
 * - Bulk OUT data transmission to CDC devices
 *
 * The program continuously polls USB hub events to detect device connection
 * and removal. Newly attached CDC devices are automatically initialized and
 * assigned to available VCOM slots. All received and transmitted data, as
 * well as device status information, are printed via UART0 for debugging
 * and validation purposes.
 *
 * @note
 * - Non-cacheable aligned memory is required for USB DMA buffers.
 * - This sample supports multiple CDC devices simultaneously.
 * - Bulk transfer performance may be affected by excessive console output.
 * - This sample is intended for debugging, validation, and reference purposes.
 *
 * @copyright
 * Copyright (C) 2026 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#include <stdio.h>
#include <string.h>

#include "NuMicro.h"
#include "usbh_lib.h"
#include "usbh_cdc.h"

#define MAX_VCOM_PORT      8

uint32_t  g_buff_pool[1024] __attribute__((aligned(32)));

char Line[64];

typedef struct
{
    CDC_DEV_T  *cdev;
    LINE_CODING_T  line_code;
    int    checked;
}  VCOM_PORT_T;

VCOM_PORT_T vcom_dev[MAX_VCOM_PORT];

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

void  vcom_status_callback(CDC_DEV_T *cdev, uint8_t *rdata, int data_len)
{
    int  i, slot;

    slot = (int)cdev->client;

    printf("[VCOM%d STS] ", slot);
    for(i = 0; i < data_len; i++)
        printf("0x%02x ", rdata[i]);
    printf("\n");
}

void  vcom_rx_callback(CDC_DEV_T *cdev, uint8_t *rdata, int data_len)
{
    int   i, slot;

    slot = (int)cdev->client;
    //printf("[%d][RX %d] ", cdev->iface_cdc->if_num, data_len);
    printf("[RX][VCOM%d]: ", slot);
    for (i = 0; i < data_len; i++)
    {
        //printf("0x%02x ", rdata[i]);
        printf("%c", rdata[i]);
    }
    printf("\n");
}

void show_line_coding(LINE_CODING_T *lc)
{
    printf("[CDC device line coding]\n");
    printf("====================================\n");
    printf("Baud rate:  %d bps\n", lc->baud);
    printf("Parity:     ");
    switch (lc->parity)
    {
    case 0:
        printf("None\n");
        break;
    case 1:
        printf("Odd\n");
        break;
    case 2:
        printf("Even\n");
        break;
    case 3:
        printf("Mark\n");
        break;
    case 4:
        printf("Space\n");
        break;
    default:
        printf("Invalid!\n");
        break;
    }
    printf("Data Bits:  ");
    switch (lc->data_bits)
    {
    case 5 :
    case 6 :
    case 7 :
    case 8 :
    case 16:
        printf("%d\n", lc->data_bits);
        break;
    default:
        printf("Invalid!\n");
        break;
    }
    printf("Stop Bits:  %s\n\n", (lc->stop_bits == 0) ? "1" : ((lc->stop_bits == 1) ? "1.5" : "2"));
}

int  init_cdc_device(CDC_DEV_T *cdev, int slot)
{
    int     ret;
    LINE_CODING_T  *line_code;

    printf("\n\n===  VCOM%d  ===============================\n", slot);
    printf("  Init CDC device : 0x%x\n", (int)cdev);
    printf("  VID: 0x%x, PID: 0x%x, interface: %d\n\n", cdev->udev->descriptor.idVendor, cdev->udev->descriptor.idProduct, cdev->iface_cdc->if_num);

    line_code = &(vcom_dev[slot].line_code);

    ret = usbh_cdc_get_line_coding(cdev, line_code);
    if (ret < 0)
    {
        printf("Get Line Coding command failed: %d\n", ret);
    }
    else
        show_line_coding(line_code);

    line_code->baud = 115200;
    line_code->parity = 0;
    line_code->data_bits = 8;
    line_code->stop_bits = 0;

    ret = usbh_cdc_set_line_coding(cdev, line_code);
    if (ret < 0)
    {
        printf("Set Line Coding command failed: %d\n", ret);
    }

    ret = usbh_cdc_get_line_coding(cdev, line_code);
    if (ret < 0)
    {
        printf("Get Line Coding command failed: %d\n", ret);
    }
    else
    {
        printf("New line coding =>\n");
        show_line_coding(line_code);
    }

    usbh_cdc_set_control_line_state(cdev, 1, 1);

    printf("usbh_cdc_start_polling_status...\n");
    usbh_cdc_start_polling_status(cdev, vcom_status_callback);

    printf("usbh_cdc_start_to_receive_data...\n");
    usbh_cdc_start_to_receive_data(cdev, vcom_rx_callback);

    return 0;
}

void update_vcom_device()
{
    int    i, free_slot;
    CDC_DEV_T   *cdev;

    for (i = 0; i < MAX_VCOM_PORT; i++)
        vcom_dev[i].checked = 0;

    cdev = usbh_cdc_get_device_list();
    while (cdev != NULL)
    {
        free_slot = -1;
        for (i = MAX_VCOM_PORT-1; i >= 0; i--)
        {
            if (vcom_dev[i].cdev == NULL)
                free_slot = i;

            if ((vcom_dev[i].cdev == cdev) && (i == (int)cdev->client))
            {
                vcom_dev[i].checked = 1;
                break;
            }
        }

        printf("free_slot %d\n", free_slot);

        if (i < 0)      /* not found in VCOM device list, add it */
        {
            if (free_slot == -1)
            {
                printf("No free VCOM device slots!\n");
                goto next_cdev;
            }

            i = free_slot;
            vcom_dev[i].cdev = cdev;
            cdev->client = (void *)i;
            init_cdc_device(cdev, i);
            vcom_dev[i].checked = 1;
        }

next_cdev:
        cdev = cdev->next;
    }

    for (i = 0; i < MAX_VCOM_PORT; i++)
    {
        if ((vcom_dev[i].cdev != NULL) && (vcom_dev[i].checked == 0))
        {
            vcom_dev[i].cdev = NULL;
        }
    }
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
    CDC_DEV_T   *cdev;
    int         i, ret;
    char        *message;

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
    printf("|     USB Host VCOM sample program              |\n");
    printf("|                                               |\n");
    printf("+-----------------------------------------------+\n");

    for (i = 0; i < MAX_VCOM_PORT; i++)
        vcom_dev[i].cdev = NULL;

    usbh_core_init();
    usbh_cdc_init();
    usbh_memory_used();

    while(1)
    {
        if (usbh_pooling_hubs())             /* USB Host port detect polling and management */
        {
            usbh_memory_used();              /* print out USB memory allocating information */

            if (usbh_cdc_get_device_list() == NULL)
            {
                /* There's no any VCOM device connected. */
                memset(vcom_dev, 0, sizeof(vcom_dev));
                continue;
            }

            update_vcom_device();
        }

        for (i = 0; i < MAX_VCOM_PORT; i++)
        {
            cdev = vcom_dev[i].cdev;
            if (cdev == NULL)
                continue;

            if (!cdev->rx_busy)
            {
                usbh_cdc_start_to_receive_data(cdev, vcom_rx_callback);
            }
        }

        /*
         *  Check user input and send data to CDC device immediately. For loopback test only.
         */
        if (!kbhit())
        {
            getchar();
            for (i = 0; i < MAX_VCOM_PORT; i++)
            {
                cdev = vcom_dev[i].cdev;
                if (cdev == NULL)
                    continue;

                memset(message, 0, 64);
                sprintf(message, "To VCOM%d (VID:0x%x, PID:0x%x, interface %d).\n",
                        i, cdev->udev->descriptor.idVendor, cdev->udev->descriptor.idProduct, cdev->iface_cdc->if_num);

                ret = usbh_cdc_send_data(cdev, (uint8_t *)message, 64);
                if (ret != 0)
                    printf("\n!! Send data failed, 0x%x!\n", ret);
            }

        }
    }
}
