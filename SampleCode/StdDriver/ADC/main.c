/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * @brief    NUC990 ADC Sample Code
 *
 * @note
 * Copyright (C) 2026 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NuMicro.h"
#include "adc.h"

/*-----------------------------------------------------------------------------*/
volatile int normal_complete = 0;

INT32 NormalConvCallback(UINT32 status, UINT32 userData)
{
    /*  The status content that contains normal data. */
    normal_complete = 1;
    printf("\r normal data=0x%3x", status);
    return 0;
}

void normal_demo()
{
    char c;
    int val;
    printf("Select channel 0 ~ 8 (0~7 for external channel, 8 for Vref)\n");
    c = getchar();
    val = c - '0';
    adcIoctl(NAC_ON, (UINT32)NormalConvCallback, 0);  /* Enable Normal AD Conversion */
    adcChangeChannel(val << ADC_CONF_CHSEL_Pos);
    do
    {
        adcIoctl(START_MST, 0, 0);
    }
    while(1);
}

/*-----------------------------------------------------------------------------*/
void UART_Init()
{
    SYS_UnlockReg();

    CLK_SetModuleClock(UART0_MODULE, CLK_DIV4_UART0SEL_HXT, CLK_DIV4_UART0(1));

    sysResetModule(UART0_RST);
    UART_Open(UART0, 115200);
    // UART0->BAUD = 0x3000000E;  /* for palladium */

    /* GPF11, GPF12 */
    SET_UART0_RXD_PF11();
    SET_UART0_TXD_PF12();
}

int main(void)
{
    sysDisableCache();
    sysFlushCache(I_D_CACHE);
    sysEnableCache(CACHE_WRITE_BACK);

    UART_Init();

    printf("+-------------------------------------------------+\n");
    printf("|                 ADC Sample Code                  |\n");
    printf("+-------------------------------------------------+\n\n");

    adcOpen();
    normal_demo();

    while(1);
}
