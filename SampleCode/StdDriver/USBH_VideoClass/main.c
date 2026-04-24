/**************************************************************************//**
 * @file     main.c
 *
 * @brief
 * This sample program demonstrates how to use the NUC990 USB Host controller
 * to enumerate and operate a USB Video Class (UVC) device (e.g. USB camera),
 * receive video frames through isochronous streaming, and store captured
 * images into a USB Mass Storage device using the FatFs file system.
 *
 * The application performs the following operations:
 * - USB Host stack initialization (EHCI / OHCI)
 * - USB Video Class (UVC) device enumeration and format query
 * - Video format selection (MJPEG or YUYV) and resolution configuration
 * - Isochronous video streaming and frame reception callback
 * - Multi-buffer image management for USB DMA reception
 * - Saving captured image frames to USB mass storage as image files
 *
 * The program polls USB hub events to detect device connection and
 * automatically starts video streaming when a UVC device is attached.
 * Captured frames are stored into pre-allocated buffers and written
 * to files on a USB disk for inspection and testing.
 *
 * @compile_option
 * - Define SELECT_MJPEG to capture MJPEG format video.
 * - Otherwise, YUYV (uncompressed) format is used.
 *
 * @note
 * - Video buffers must be cache-line aligned and non-cacheable for USB DMA.
 * - This sample supports only one UVC device at a time.
 * - Captured image size and format depend on the connected UVC device.
 * - Excessive UART printing may affect isochronous transfer timing.
 *
 * @copyright
 * Copyright (C) 2026 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#include <stdio.h>
#include <string.h>

#include "NuMicro.h"
#include "usbh_lib.h"
#include "usbh_uvc.h"
#include "ff.h"
#include "diskio.h"

#define SELECT_MJPEG

#define SELECT_RES_WIDTH     640  // 1920
#define SELECT_RES_HEIGHT    480  // 1080

#define OSD_WIDTH            640
#define OSD_HEIGHT           480

#define IMAGE_MAX_SIZE       (640*480*2)

static UVC_DEV_T   *g_vdev = NULL;

#define IMAGE_BUFF_CNT       20

enum
{
    IMAGE_BUFF_FREE,
    IMAGE_BUFF_USB,
    IMAGE_BUFF_READY,
    IMAGE_BUFF_POST
};

struct ig_buff_t
{
    uint8_t   *buff;
    int       len;
    int       state;
};

struct ig_buff_t _ig[IMAGE_BUFF_CNT];

uint8_t  image_buff_pool[IMAGE_BUFF_CNT][IMAGE_MAX_SIZE] __attribute__((aligned(32)));
volatile int _image_cnt;

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

void  init_image_buffers(void)
{
    int   i;
    for (i = 0; i < IMAGE_BUFF_CNT; i++)
    {
        _ig[i].buff   = (uint8_t *)((uint32_t)image_buff_pool[i] | 0x80000000);
        _ig[i].len    = 0;
        _ig[i].state  = IMAGE_BUFF_FREE;
    }
    _image_cnt = 0;
}

int  uvc_rx_callbak(UVC_DEV_T *vdev, uint8_t *data, int len)
{
    //printf("RX: %d\n", len);

    if (_image_cnt >= IMAGE_BUFF_CNT)
    {
        printf("Buffer full!\n");
    }
    else
    {
        _ig[_image_cnt].state = IMAGE_BUFF_READY;   /* mark the current buffer as ready for decode/display */
        _ig[_image_cnt].len   = len;                /* length of this newly received image   */

        /* proceed to the next image buffer */
        _image_cnt = (_image_cnt + 1) % IMAGE_BUFF_CNT;
        _ig[_image_cnt].state = IMAGE_BUFF_USB;     /* mark the next image as used by USB    */

        /* assign the next image buffer to receive next image from USB */
        usbh_uvc_set_video_buffer(vdev, _ig[_image_cnt].buff, IMAGE_MAX_SIZE);
    }
    return 0;
}

unsigned long get_fattime (void)
{
    unsigned long tmr;

    tmr=0x00000;

    return tmr;
}

void put_rc (FRESULT rc)
{
    const TCHAR *p =
        _T("OK\0DISK_ERR\0INT_ERR\0NOT_READY\0NO_FILE\0NO_PATH\0INVALID_NAME\0")
        _T("DENIED\0EXIST\0INVALID_OBJECT\0WRITE_PROTECTED\0INVALID_DRIVE\0")
        _T("NOT_ENABLED\0NO_FILE_SYSTEM\0MKFS_ABORTED\0TIMEOUT\0LOCKED\0")
        _T("NOT_ENOUGH_CORE\0TOO_MANY_OPEN_FILES\0");
    //FRESULT i;
    uint32_t i;
    for (i = 0; (i != (UINT)rc) && *p; i++) {
        while(*p++) ;
    }
    printf(_T("rc=%d FR_%s\n"), (UINT)rc, p);
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
    UVC_DEV_T       *vdev;
    IMAGE_FORMAT_E  format;
    FRESULT         res;
    TCHAR           disk_path[32] = { '3', ':', 0 };
    FIL             file;
    UINT            image_len;
    int             i, width, height, ret;

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
    printf("|   USB Host video class sample program         |\n");
    printf("|                                               |\n");
    printf("+-----------------------------------------------+\n");

    usbh_core_init();
    usbh_umas_init();
    usbh_uvc_init();

    init_image_buffers();

    while (_image_cnt < IMAGE_BUFF_CNT)
    {
        if (usbh_pooling_hubs())       /* USB Host port detect polling and management     */
        {
            /*
             *  Has hub port event.
             */
            vdev = usbh_uvc_get_device_list();
            if (vdev == NULL)
            {
                g_vdev = NULL;
                printf("\n[No device connected]\n\n");
                continue;
            }

            if (g_vdev == vdev)
            {
                printf("\n\n\nWaiting for UVC device connected...\n");
                continue;
            }

            if (vdev->next != NULL)
            {
                printf("Warning!! Multiple UVC device is not supported!!\n");
                while (1);
            }

            /*----------------------------------------------------------------------------*/
            /*  New UVC device connected.                                                 */
            /*----------------------------------------------------------------------------*/
            g_vdev = vdev;
            printf("\n\n----------------------------------------------------------\n");
            printf("[Video format list]\n");
            for (i = 0; ; i++)
            {
                ret = usbh_get_video_format(g_vdev, i, &format, &width, &height);
                if (ret != 0)
                    break;

                printf("[%d] %s, %d x %d\n", i, (format == UVC_FORMAT_MJPEG ? "MJPEG" : "YUYV"), width, height);
            }
            printf("\n\n");

#ifdef SELECT_MJPEG
            ret = usbh_set_video_format(g_vdev, UVC_FORMAT_MJPEG, SELECT_RES_WIDTH, SELECT_RES_HEIGHT);
#else
            ret = usbh_set_video_format(g_vdev, UVC_FORMAT_YUY2, SELECT_RES_WIDTH, SELECT_RES_HEIGHT);
#endif
            if (ret != 0)
                printf("usbh_set_video_format failed! - 0x%x\n", ret);

            /* assign the first image buffer to receive the image from USB */
            usbh_uvc_set_video_buffer(vdev, _ig[_image_cnt].buff, IMAGE_MAX_SIZE);
            _ig[_image_cnt].state = IMAGE_BUFF_USB;

            ret = usbh_uvc_start_streaming(g_vdev, uvc_rx_callbak);
            if (ret != 0)
            {
                printf("usbh_uvc_start_streaming failed! - %d\n", ret);
                printf("Please re-connect UVC device...\n");
            }
        }
    }

    f_chdrive(disk_path);          /* set default path */

    for (i = 0; i < IMAGE_BUFF_CNT; i++)
    {
        sprintf(disk_path, "image%03d.jpg", i+1);
        printf("Writing image %d to file %s...\n", i+1, disk_path);
        res = f_open(&file, disk_path, FA_CREATE_ALWAYS | FA_WRITE);
        if (res)
        {
            printf("Failed to open file %s!!\n", disk_path);
            break;
        }

        res = f_write(&file, _ig[i].buff, _ig[i].len, &image_len);
        if (res)
        {
            printf("Write failed!!\n");
            put_rc(res);
            break;
        }

        printf("    %d bytes written.\n", image_len);
        f_close(&file);
    }

    while (1);
}
