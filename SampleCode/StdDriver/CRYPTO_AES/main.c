/******************************************************************************
* @file main.c
* @version V1.00
* @brief Demonstrate the AES encryption/decryption capabilities of the
*        Cryptographic Accelerator (Crypto), including modes such as
*        AES CBC, CCM, and GCM, and show how to support multiple
*        concurrent AES encryption/decryption tasks.
*
* @copyright SPDX-License-Identifier: Apache-2.0
* @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#include <stdio.h>
#include <string.h>

#include "NuMicro.h"

#define BUFF_SIZE           1024

uint32_t au32MyAESKey[8] = {
    0x00010203, 0x04050607, 0x08090a0b, 0x0c0d0e0f,
    0x00010203, 0x04050607, 0x08090a0b, 0x0c0d0e0f
};

uint32_t au32MyAESIV[4] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000
};

uint8_t au8InputData_Pool[BUFF_SIZE] __attribute__((aligned(32))) = {
    0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
    0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff
} ;

uint8_t au8OutputData_Pool[BUFF_SIZE] __attribute__((aligned(32)));
uint8_t au8CascadeOut_Pool[BUFF_SIZE] __attribute__((aligned(32)));
uint8_t au8FDBCK_Pool[64] __attribute__((aligned(32)));

uint8_t  *au8InputData;
uint8_t  *au8OutputData;
uint8_t  *au8CascadeOut;
uint8_t  *au8FDBCK;

volatile int  g_AES_done, g_AESERR_done;
volatile int  g_PRNG_done;

void CRYPTO_IRQHandler(void)
{
    if (PRNG_GET_INT_FLAG())
        g_PRNG_done = 1;

    if (AES_GET_INT_FLAG() & CRYPTO_INTSTS_AESEIF_Msk)
    {
        printf("IRQ: AESERRIF is set!!  INTSTS:0x%x, AES_STS:0x%x\n",
               CRYPTO->INTSTS, CRYPTO->AES_STS);
        g_AESERR_done = 1;
    }

    if (AES_GET_INT_FLAG() & CRYPTO_INTSTS_AESIF_Msk)
        g_AES_done = 1;

    PRNG_CLR_INT_FLAG();
    AES_CLR_INT_FLAG();
}

void do_swap(uint8_t *buff, int len)
{
    int       i;
    uint8_t   val8;

    len = (len+3) & 0xfffffffc;
    for (i = 0; i < len; i+=4)
    {
        val8 = buff[i];
        buff[i] = buff[i+3];
        buff[i+3] = val8;
        val8 = buff[i+1];
        buff[i+1] = buff[i+2];
        buff[i+2] = val8;
    }
}

void  dump_buff_hex(uint8_t *pucBuff, int nBytes)
{
    uint32_t  addr, end_addr;
    int       i;

    addr = (uint32_t)pucBuff;
    end_addr = addr + nBytes - 1;

    if ((addr % 16) != 0)
    {
        printf("0x%04x_%04x  ", (addr>>16)&0xffff, addr & 0xffff);
        for (i = 0; i < addr % 16; i++)
            printf(".. ");

        for ( ; (addr % 16) != 0; addr++)
            printf("%02x ", inpb((uint8_t *)addr) & 0xff);
        printf("\n");
    }

    for ( ; addr <= end_addr; )
    {
        printf("0x%04x_%04x  ", (addr>>16)&0xffff, addr & 0xffff);
        for (i = 0; i < 16; i++, addr++)
        {
            if (addr > end_addr)
                break;
            printf("%02x ", inpb((uint8_t *)addr) & 0xff);
        }
        printf("\n");
    }
    printf("\n");
}

int AES_basic_test(int polling_mode)
{
    memset(au8InputData, 0x55, BUFF_SIZE);

    /*-----------------------------------------------------------------------*/
    /*  AES-128 ECB mode encrypt                                             */
    /*-----------------------------------------------------------------------*/
    AES_Open(0, 1, AES_MODE_ECB, AES_KEY_SIZE_128, AES_IN_OUT_SWAP);
    AES_SetKey(0, au32MyAESKey, AES_KEY_SIZE_128);
    AES_SetInitVect(0, au32MyAESIV);
    AES_SetDMATransfer(0, (uint32_t)au8InputData, (uint32_t)au8OutputData, BUFF_SIZE);

    dump_buff_hex(au8InputData, 16);

    AES_ENABLE_INT();
    g_AES_done = 0;
    AES_Start(0, CRYPTO_DMA_ONE_SHOT);
    while (!g_AES_done);

    printf("AES encrypt done.\n\n");
    dump_buff_hex(au8OutputData, 16);

    /*-----------------------------------------------------------------------*/
    /*  AES-128 ECB mode decrypt                                             */
    /*-----------------------------------------------------------------------*/
    AES_Open(0, 0, AES_MODE_ECB, AES_KEY_SIZE_128, AES_IN_OUT_SWAP);
    AES_SetKey(0, au32MyAESKey, AES_KEY_SIZE_128);
    AES_SetInitVect(0, au32MyAESIV);
    AES_SetDMATransfer(0, (uint32_t)au8OutputData,
                      (uint32_t)au8InputData, sizeof(au8InputData_Pool));

	if (polling_mode)
    {
        AES_DISABLE_INT();
        AES_Start(0, CRYPTO_DMA_ONE_SHOT);
        while (CRYPTO->AES_STS & CRYPTO_AES_STS_BUSY_Msk);
    }
    else
    {
        AES_ENABLE_INT();
        g_AES_done = 0;
        AES_Start(0, CRYPTO_DMA_ONE_SHOT);
        while (!g_AES_done);
    }

    printf("AES decrypt done.\n\n");
    dump_buff_hex(au8InputData, 16);

    printf("Press any key to continue...\n");
    return 0;
}

int AES_cascade_test(int keysz, int opmode)
{
    int  i, count;

    memset(au8OutputData, 0, BUFF_SIZE);
    memset(au8CascadeOut, 0, BUFF_SIZE);

    /*-----------------------------------------------------------------------*/
    /*  AES-256 CBC mode one-shot encrypt                                    */
    /*-----------------------------------------------------------------------*/
    AES_Open(0, 1, opmode, keysz, AES_IN_OUT_SWAP);
    AES_SetKey(0, au32MyAESKey, keysz);
    AES_SetInitVect(0, au32MyAESIV);
    AES_SetDMATransfer(0, (uint32_t)au8InputData, (uint32_t)au8OutputData, BUFF_SIZE);

    g_AES_done = 0;
    AES_Start(0, CRYPTO_DMA_ONE_SHOT);
    while (!g_AES_done);

    printf("AES one-shot encrypt done.\n\n");

    /*-----------------------------------------------------------------------*/
    /*  AES-256 CBC mode cascade encrypt                                     */
    /*-----------------------------------------------------------------------*/
    AES_Open(0, 1, opmode, keysz, AES_IN_OUT_SWAP);
    AES_SetKey(0, au32MyAESKey, keysz);
    AES_SetInitVect(0, au32MyAESIV);
    AES_SetDMATransfer(0, (uint32_t)au8InputData, (uint32_t)au8CascadeOut, BUFF_SIZE);

    for (count = 0; count < BUFF_SIZE; count += 64)
    {
        AES_SetDMATransfer(0, (uint32_t)au8InputData+count, (uint32_t)au8CascadeOut+count, 64);
        g_AES_done = 0;
        if (count == 0)
            AES_Start(0, CRYPTO_DMA_FIRST);
        else if (count >= BUFF_SIZE - 64)
            AES_Start(0, CRYPTO_DMA_LAST);
        else
            AES_Start(0, CRYPTO_DMA_CONTINUE);

        while (!g_AES_done);
    }

    printf("AES cascade encrypt done.\n\n");

    for (i = 0; i < BUFF_SIZE; i ++)
    {
        if (au8OutputData[i] != au8CascadeOut[i])
        {
            printf("Data mismatch at offset 0x%x!\n", i);
            dump_buff_hex(au8OutputData, 16);
            dump_buff_hex(au8CascadeOut, 16);
            return -1;
        }
    }
    printf("[PASS]\n");
    return 0;
}

void SYS_Init()
{
    CLK_EnableModuleClock(CRYPTO_MODULE);
    CLK_EnableModuleClock(KS_MODULE);
    CLK_EnableModuleClock(UART0_MODULE);

    SET_UART0_RXD_PF11();
    SET_UART0_TXD_PF12();
}

void UART0_Init(void)
{
    SYS_ResetModule(UART0_RST);
    UART_Open(UART0, 9600);
}

int main(void)
{
    int        item, ret;
    uint32_t   i, j;

    SYS_UnlockReg();

    SYS_Init();

    UART_Init();

    sysDisableCache();
    sysFlushCache(I_D_CACHE);
    sysEnableCache(CACHE_WRITE_BACK);

    /* Get pointer for non-cacheable DMA buffer */
    au8InputData  = nc_ptr(au8InputData_Pool);
    au8OutputData = nc_ptr(au8OutputData_Pool);
    au8CascadeOut = nc_ptr(au8CascadeOut_Pool);
    au8FDBCK      = nc_ptr(au8FDBCK_Pool);

    sysInstallISR(IRQ_LEVEL_1, IRQ_CRYPTO, (PVOID)CRYPTO_IRQHandler);
    sysSetLocalInterrupt(ENABLE_IRQ);
    sysEnableInterrupt(IRQ_CRYPTO);

    AES_ENABLE_INT();
    PRNG_ENABLE_INT();

    while (1)
    {
        printf("\n");
        printf("+---------------------------------------------------------------+\n");
        printf("|  NUC990 CRYPTO AES demo program                               |\n");
        printf("+---------------------------------------------------------------+\n");
        printf("| [1] AES encode/decode pair demo                               |\n");
        printf("| [2] AES DMA cascade demo                                      |\n");
        printf("| [3] AES NIST known answer test                                |\n");
        printf("| [4] AES encrypt/decrypt polling                               |\n");
        printf("| [5] AES multi-channel test                                    |\n");
        printf("| [6] AES-GCM mode test                                         |\n");
        printf("| [7] AES-CCM mode test                                         |\n");
        printf("+---------------------------------------------------------------+\n");

        printf("\nSelect [1~7]: \n");

        item = getchar();

        switch (item)
        {
            case '1':
                ret = AES_basic_test(0);
                break;

            case '2':
                ret = AES_cascade_test(AES_KEY_SIZE_256, AES_MODE_CBC);
                break;

            case '3':
                ret = AES_KAT_test();
                break;

            case '5':
                ret = AES_basic_test(1);
                AES_ENABLE_INT();
                break;

            case '6':
                ret = AES_GCM_Test();
                break;

            case '7':
                ret = AES_CCM_Test();
                break;

            default:
                ret = 1;
                break;
        }

        if (ret == 0)
        {
            printf("\nTest passed. Press any key to continue...\n");
            getchar();
        }

        if (ret < 0)
        {
            printf("\nTest FAILED!!!\n\nPress any key to continue...\n");
            getchar();
        }
    }
}
