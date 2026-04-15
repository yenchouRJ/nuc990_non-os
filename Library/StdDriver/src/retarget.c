/**************************************************************************//**
 * @file     retarget.c
 * @brief    NuMicro retarget code
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2024 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#include <stdio.h>
#include <stdio.h>
#if defined (__CC_ARM)
#include <rt_misc.h>
#endif
#include "NuMicro.h"
#include "sys.h"

#if defined (__CC_ARM)

#pragma import(__use_no_semihosting_swi)

/// @cond HIDDEN_SYMBOLS

int sendchar(int ch)
{
    while (UART0->FIFOSTS & UART_FIFOSTS_TXFULL_Msk);
    UART0->DAT = ch;

    if (ch == '\n')
    {
        while (UART0->FIFOSTS & UART_FIFOSTS_TXFULL_Msk);
        UART0->DAT = '\r';
    }
    return (ch);
}

static void flush_uart(void)
{
    while (!(UART0->FIFOSTS & UART_FIFOSTS_TXEMPTY_Msk));
}

/**
 * @brief    Check any char input from UART
 *
 * @param    None
 *
 * @retval   1: No any char input
 * @retval   0: Have some char input
 *
 * @details  Check UART RSR RX EMPTY or not to determine if any char input from UART
 */

int kbhit(void)
{
    return !((UART0->FIFOSTS & UART_FIFOSTS_RXEMPTY_Msk) == 0);
}

int recvchar(void)
{
    while(1)
    {
        if ((UART0->FIFOSTS & UART_FIFOSTS_RXEMPTY_Msk) == 0)
        {
            return UART0->DAT;
        }
    }
}

int sysGetChar(void)
{
    while(1)
    {
        if ((UART0->FIFOSTS & UART_FIFOSTS_RXEMPTY_Msk) == 0)
        {
            return UART0->DAT;
        }
    }
}

struct __FILE
{
    int handle; /* Add whatever you need here */
};

FILE __stdout;
FILE __stdin;
FILE __stderr;

int fflush(FILE *f)
{
    flush_uart();
    return 0;
}

int fputc(int ch, FILE *f)
{
    return (sendchar(ch));
}

int fgetc(FILE *stream)
{
    return (recvchar());
}

int fclose(FILE* f)
{
    return (0);
}

int fseek (FILE *f, long nPos, int nMode)
{
    return (0);
}

int ferror(FILE *f)
{
    /* Your implementation of ferror */
    return EOF;
}

void _ttywrch(int ch)
{
    sendchar(ch);
}

void _sys_exit(int return_code)
{
label:
    goto label;  /* No where to go, endless loop */
}

#pragma import(__use_two_region_memory)
extern unsigned int Image$$ARM_LIB_HEAP$$ZI$$Base;
extern unsigned int Image$$ARM_LIB_HEAP$$ZI$$Limit;

__value_in_regs struct __initial_stackheap __user_initial_stackheap(unsigned int R0, unsigned int SP, unsigned int R2, unsigned int SL)

{
    struct __initial_stackheap config;

    config.heap_base = (unsigned int)&Image$$ARM_LIB_HEAP$$ZI$$Base;
    config.heap_limit =(unsigned int)&Image$$ARM_LIB_HEAP$$ZI$$Limit;
    config.stack_base = SP;
    config.heap_limit = SP - 0x10000;
    return config;
}
/// @endcond HIDDEN_SYMBOLS

#else  // expect defined(__GNUC__)

#include "uart.h"

/// @cond HIDDEN_SYMBOLS

int _write(int fd, char *ptr, int len)
{
    int i = len;

    while (i--)
    {
        while (UART0->FIFOSTS & UART_FIFOSTS_TXFULL_Msk);
        UART0->DAT = *ptr;

        if (*ptr == '\n')
        {
            while (UART0->FIFOSTS & UART_FIFOSTS_TXFULL_Msk);
            UART0->DAT = '\r';
        }
        ptr++;
    }
    return len;
}

int _read (int fd, char *ptr, int len)
{
    while (UART0->FIFOSTS & UART_FIFOSTS_RXEMPTY_Msk);

    *ptr = UART0->DAT;

    return 1;
}

void C_SWI_Handler( int swi_num, int *regs )
{
    int w, x, y, z;

    switch( swi_num )
    {
        case 0:
            regs[0] = regs[0] * regs[1];
            break;

        case 1:
            regs[0] = regs[0] + regs[1];
            break;

        case 2:
            regs[0] = (regs[0] * regs[1]) + (regs[2] * regs[3]);
            break;

        case 3:
            w = regs[0];
            x = regs[1];
            y = regs[2];
            z = regs[3];

            regs[0] = w + x + y + z;
            regs[1] = w - x - y - z;
            regs[2] = w * x * y * z;
            regs[3] =(w + x) * (y - z);
        break;
    }
}

/// @endcond HIDDEN_SYMBOLS
#endif

