/**************************************************************************//**
 * @file     main.c
 * @version  V1.00
 * $Date: 15/05/07 6:35p $
 * @brief    NUC970 Driver Sample Code
 *
 * @note
 * Copyright (C) 2015 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NuMicro.h"
#include "adc.h"

/*-----------------------------------------------------------------------------*/
volatile int normal_complete=0;
INT32 NormalConvCallback(UINT32 status, UINT32 userData)
{
    /*  The status content that contains normal data.
     */
    normal_complete=1;
    printf("\r normal data=0x%3x",status);
    return 0;
}
void normal_demo()
{
    char c;
    int val;
    printf("Select channel 0 ~ 8 (0~7 for external channel, 8 for Vref)\n");
    c = getchar();
    val = c - '0';
    // adcIoctl(NAC_ON,(UINT32)NormalConvCallback,0); //Enable Normal AD Conversion
    // adcChangeChannel(val << ADC_CONF_CHSEL_Pos);
    // do
    // {
    //     adcIoctl(START_MST,0,0);
    // }
    while(1);
}
/*-----------------------------------------------------------------------------*/
/*! Unlock protected register */
#define UNLOCKREG(x)  do{outpw(REG_SYS_REGWPCTL,0x59); outpw(REG_SYS_REGWPCTL,0x16); outpw(REG_SYS_REGWPCTL,0x88);}while(inpw(REG_SYS_REGWPCTL) == 0x00)
/*! Lock protected register */
#define LOCKREG(x)  do{outpw(REG_SYS_REGWPCTL,0x00);}while(0)

/*-----------------------------------------------------------------------------*/
void UART_Init()
{
    SYS_UnlockReg();
    sysDisableCache();
    sysFlushCache(I_D_CACHE);
    sysEnableCache(CACHE_WRITE_BACK);

    sysResetModule(UART0_RST);
    UART_Open(UART0, 115200);
    UART0->BAUD = 0x3000000E;  /* for palladium */

    /* GPF11, GPF12 */
    SET_UART0_RXD_PF11();
    SET_UART0_TXD_PF12();

    sysSetLocalInterrupt(ENABLE_IRQ);
}

int main(void)
{
    // *((volatile unsigned int *)REG_AIC_INTDIS0)=0xFFFFFFFF;  // disable all interrupt channel
    // *((volatile unsigned int *)REG_AIC_INTDIS1)=0xFFFFFFFF;  // disable all interrupt channel
    sysDisableCache();
    sysFlushCache(I_D_CACHE);
    sysEnableCache(CACHE_WRITE_BACK);

    UART_Init();

    printf("+-------------------------------------------------+\n");
    printf("|                 ADC Sample Code                 |\n");
    printf("+-------------------------------------------------+\n\n");
    ADC_Open(ADC, ADC_INPUT_MODE_NORMAL_CONV, ADC_NORMAL_SPEED_MODE, 0x1); //Enable channel 0 for normal AD conversion
    ADC_EnableInt(ADC, ADC_IER_M_IEN_Msk); //Enable normal AD
    normal_demo();
    while(1);
}
