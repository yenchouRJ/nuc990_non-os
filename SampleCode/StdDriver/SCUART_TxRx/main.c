/**************************************************************************//**
 * @file     main.c
 * @brief    Demonstrate smartcard UART mode
 *
 * @copyright (C) 2026 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#include <stdio.h>
#include "NuMicro.h"
#include "scuart.h"

char au8TxBuf[] = "Hello World!";


/**
  * @brief  The interrupt services routine of smartcard port 0
  * @param  None
  * @retval None
  */
void SC0_IRQHandler(void)
{
    // Print SCUART received data to UART port
    // Data length here is short, so we're not care about UART FIFO over flow.
    printf("%c", SCUART_READ(0));
    fflush(stdout);
    // RDA is the only interrupt enabled in this sample, this status bit
    // automatically cleared after Rx FIFO empty. So no need to clear interrupt
    // status here.

    return;
}

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

    sysSetLocalInterrupt(ENABLE_IRQ);
}

int main(void)
{

    sysDisableCache();
    sysFlushCache(I_D_CACHE);
    sysEnableCache(CACHE_WRITE_BACK);
    UART_Init();

    // Enable SC0 engine clock
    CLK->PCLKEN1 |= CLK_PCLKEN1_SMC0CKEN_Msk;

    // Enable SCUART Tx/Rx pin (PC12=SC0_CLK, PC13=SC0_DAT)
    SET_SC0_CLK_PC12();
    SET_SC0_DAT_PC13();

    printf("This sample code demos smartcard interface UART mode\n");
    printf("Please connect SC0 CLK pin(PC.12) with SC0 I/O pin(PC.13)\n");
    printf("Hit any key to continue\n");
    getchar();

    // Open smartcard interface 0 in UART mode.
    SCUART_Open(0, 115200);
    // Enable receive interrupt
    SCUART_ENABLE_INT(0, SC_INTEN_RDAIEN_Msk);

    sysInstallISR(IRQ_LEVEL_1, SMC0_IRQn, (PVOID)SC0_IRQHandler);
    sysSetLocalInterrupt(ENABLE_IRQ);
    sysEnableInterrupt(SMC0_IRQn);


    SCUART_Write(0, au8TxBuf, sizeof(au8TxBuf));

    while(1);
}
