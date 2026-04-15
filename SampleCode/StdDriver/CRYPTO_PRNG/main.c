/**
 ******************************************************************************
 * @file    main.c
 * @version V1.00
 * @brief   NUC990 Series Crypto Engine PRNG (Pseudo Random Number Generator)
 * Demonstration and Verification Program.
 *
 * This sample code demonstrates the usage of the Hardware PRNG engine within
 * the NUC990 Crypto Accelerator. It includes various test cases to verify
 * the randomness, seed reload consistency, and output integrity.
 *
 * @details
 * The program covers the following functional demonstrations:
 * - Support for multiple PRNG key sizes: 128, 163, 192, 224, 233, 255, and 256 bits.
 * - Hardware Interrupt handling via CRYPTO_IRQHandler.
 * - Deterministic sequence verification (Seed Reload test).
 * - Seed Differential test to ensure distinct entropy between different seeds.
 *
 * @copyright SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2026 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************
 */
#include <stdio.h>
#include <string.h>

#include "NuMicro.h"

#define USER_SEED     0x20061108

uint32_t rand_num[18];

static volatile int g_PRNG_done;

void CRYPTO_IRQHandler()
{
    if (PRNG_GET_INT_FLAG()) {
        g_PRNG_done = 1;
        PRNG_CLR_INT_FLAG();
    }
}

void dump_PRNG()
{
    int   i;

    printf("PRNG DATA ==>\n");
    for (i = 0; i < 8; i++)
        printf("  0x%08x", CRYPTO->PRNG_KEY[i]);
    printf("\n");
}

void dump_buff_data(uint32_t *buff)
{
    int   i;

    printf("BUFF DATA ==>\n");
    for (i = 0; i < 8; i++)
        printf("  0x%08x", buff[i]);
    printf("\n");
}

void  prng_gen_and_dump(uint32_t keysz, uint32_t wcnt)
{
    int  j;

    for (j = 0; j <5; j++)
    {
        g_PRNG_done = 0;
        CRYPTO->PRNG_CTL = (keysz << CRYPTO_PRNG_CTL_KEYSZ_Pos) | CRYPTO_PRNG_CTL_START_Msk;

        printf("Start PRNG...\n");
        while (!g_PRNG_done);
        dump_PRNG();
    }
}

void SYS_Init()
{
    CLK_SetModuleClock(UART0_MODULE, CLK_DIV4_UART0SEL_HXT, CLK_DIV4_UART0(1));

    CLK_EnableModuleClock(CRYPTO_MODULE);
    CLK_EnableModuleClock(KS_MODULE);
    CLK_EnableModuleClock(UART0_MODULE);

    SET_UART0_RXD_PF11();
    SET_UART0_TXD_PF12();
}

void UART0_Init(void)
{
    sysResetModule(UART0_RST);
    UART_Open(UART0, 115200);
    UART0->BAUD = 0x3000000E;  /* for palladium */
}

int main()
{
    int        item, i, j;

    SYS_UnlockReg();

    sysDisableCache();
    sysFlushCache(I_D_CACHE);
    sysEnableCache(CACHE_WRITE_BACK);

    SYS_Init();

    UART0_Init();

    printf("PRNG Test ==>\n");

    sysInstallISR(IRQ_LEVEL_1, CRYPTO_IRQn, (PVOID)CRYPTO_IRQHandler);
    sysSetLocalInterrupt(ENABLE_IRQ);
    sysEnableInterrupt(CRYPTO_IRQn);

    PRNG_ENABLE_INT();

    while (1)
    {
        printf("\n");
        printf("+---------------------------------------------------------------+\n");
        printf("|  NUC990 CRYPTO PRNG test program                              |\n");
        printf("+---------------------------------------------------------------+\n");
        printf("| [1] Generate 128/163/192/224/233/255/256 bits random runber   |\n");
        printf("| [2] Inifinite loop redundancy check                           |\n");
        printf("| [3] Inifinite loop seed reload test                           |\n");
        printf("| [4] Seed differential test                                    |\n");
        printf("+---------------------------------------------------------------+\n");

        printf("\nSelect [1~A]: \n");

        item = getchar();

        switch (item)
        {
            case '1':
                printf("\nPRNG Key size 128 ==>\n");
                prng_gen_and_dump(PRNG_KEY_SIZE_128, 4);
                printf("\nPRNG Key size 163 ==>\n");
                prng_gen_and_dump(PRNG_KEY_SIZE_163, 6);
                printf("\nPRNG Key size 192 ==>\n");
                prng_gen_and_dump(PRNG_KEY_SIZE_192, 6);
                printf("\nPRNG Key size 224 ==>\n");
                prng_gen_and_dump(PRNG_KEY_SIZE_224, 7);
                printf("\nPRNG Key size 233 ==>\n");
                prng_gen_and_dump(PRNG_KEY_SIZE_233, 8);
                printf("\nPRNG Key size 255 ==>\n");
                prng_gen_and_dump(PRNG_KEY_SIZE_255, 8);
                printf("\nPRNG Key size 256 ==>\n");
                prng_gen_and_dump(PRNG_KEY_SIZE_256, 8);
                printf("\nPress any key...\n");
                break;

            case '2':
                PRNG_ReSeed(PRNG_KEY_SIZE_256, USER_SEED);
                for (j = 0; j < 8; j++)
                    rand_num[j] = CRYPTO->PRNG_KEY[j];

                for (i = 1; i < 1000; i++) {
                    printf("Cycle: %d\n", i);
                    g_PRNG_done = 0;
                    CRYPTO->PRNG_CTL = (PRNG_KEY_SIZE_256 << CRYPTO_PRNG_CTL_KEYSZ_Pos) | CRYPTO_PRNG_CTL_START_Msk;

                    while (!g_PRNG_done);

                    for (j = 0; j < 8; j++) {
                        if (CRYPTO->PRNG_KEY[j] == rand_num[j]) {
                            printf("Random number not changed!! Test failed!!\n");
                            while (1);
                        }
                        rand_num[j] = CRYPTO->PRNG_KEY[j];
                    }
                }
                printf("\nTest passed. Press any key...\n");
                getchar();
                break;

            case '3':
                PRNG_ReSeed(PRNG_KEY_SIZE_256, USER_SEED);
                for (j = 0; j < 8; j++)
                    rand_num[j] = CRYPTO->PRNG_KEY[j];

                for (i = 1; i < 50; i++) {
                    if ((i % 5) == 0) {
                        printf("Test cycle: %d/50\n", i);
                        PRNG_ReSeed(PRNG_KEY_SIZE_256, USER_SEED);
                        for (j = 0; j < 8; j++) {
                            if (CRYPTO->PRNG_KEY[j] != rand_num[j]) {
                                // re-seed with the same seed must be identical
                                printf("\nSeed reload test failed!\n");
                                dump_PRNG();
                                dump_buff_data(rand_num);
                                while (1);
                            }
                        }
                        printf("\nSeed reload test passed.\n");
                    }
                    g_PRNG_done = 0;
                    CRYPTO->PRNG_CTL = (PRNG_KEY_SIZE_256 << CRYPTO_PRNG_CTL_KEYSZ_Pos) | CRYPTO_PRNG_CTL_START_Msk;
                    while (!g_PRNG_done);
                }
                break;

            case '4':
                printf("\nPress any key to do seed differential test and press 'x' to stop test...\n");

                PRNG_ReSeed(PRNG_KEY_SIZE_256, ++item);

                for (j = 0; j < 8; j++)
                    rand_num[j] = CRYPTO->PRNG_KEY[j];

                for (i = 1; i < 50; i++) {
                    printf("Test cycle: %d/50\n", i);
                    item += USER_SEED;
                    PRNG_ReSeed(PRNG_KEY_SIZE_256, item);
                    for (j = 0; j < 8; j++) {
                        if (CRYPTO->PRNG_KEY[j] == rand_num[j]) {
                            printf("\nSeed differential test failed!\n");
                            dump_buff_data((uint32_t *)CRYPTO->PRNG_KEY);
                            dump_buff_data(rand_num);
                            while (1);
                        }
                    }
                    for (j = 0; j < 8; j++)
                        rand_num[j] = CRYPTO->PRNG_KEY[j];

                    g_PRNG_done = 0;
                    CRYPTO->PRNG_CTL = (PRNG_KEY_SIZE_256 << CRYPTO_PRNG_CTL_KEYSZ_Pos) | CRYPTO_PRNG_CTL_START_Msk;
                    while (!g_PRNG_done);
                }
                printf("\nTest passed.\n");
                break;

        }  // end of switch
    }  // end of while (1)
}
