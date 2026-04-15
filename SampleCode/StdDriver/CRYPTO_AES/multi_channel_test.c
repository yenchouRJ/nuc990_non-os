/******************************************************************************
* @file main.c
* @version V1.00
* @brief Demonstrate the AES encryption/decryption capabilities of the
*        Cryptographic Accelerator (Crypto), including modes such as
*        AES CBC, CCM, and GCM, and show how to support multiple
*        concurrent AES encryption/decryption tasks.
*
* @copyright SPDX-License-Identifier: Apache-2.0
* @copyright (C) 2026 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "NuMicro.h"

extern void dump_buff_hex(uint8_t *pucBuff, int nBytes);

int do_compare(uint8_t *expect, uint8_t *output, int cmp_len)
{
    uint8_t   *p_exp, *p_out;

    p_exp = (uint8_t *)((uint32_t)expect | NON_CACHE_MASK);
    p_out = (uint8_t *)((uint32_t)output | NON_CACHE_MASK);

    if (memcmp(p_exp, p_out, cmp_len))
    {
        printf("\nMismatch!! - %d\n", cmp_len);
        printf("Expect data:\n");
        dump_buff_hex(expect, cmp_len);
        printf("Compared data:\n");
        dump_buff_hex(output, cmp_len);
        return -1;
    }
    return 0;
}

#define CHANNEL_CNT         8               /* channel count        */
#define TBLK_LEN            64              /* test block length    */
#define TEST_TEXT_LEN       (TBLK_LEN*32)
#define TEST_MODE_CNT       8

typedef struct aes_mode_t
{
    int     mode;
    char    name[16];
} AES_MODE_T;

static AES_MODE_T  _mode_list[TEST_MODE_CNT] =
{
    AES_MODE_ECB,     "ECB",
    AES_MODE_CBC,     "CBC",
    AES_MODE_CFB,     "CFB",
    AES_MODE_OFB,     "OFB",
    AES_MODE_CTR,     "CTR",
    AES_MODE_CBC_CS1, "CBC_CS1",
    AES_MODE_CBC_CS2, "CBC_CS2",
    AES_MODE_CBC_CS3, "CBC_CS3",
};

typedef struct aes_ctx_t
{
    uint32_t    ctrl;
    int         sm4en;
    int         mode_sel;
    int         encrypt;            // 1: encrypt; 0: decrypt
    int         keylen;
    uint32_t    key[8];
    uint32_t    iv[4];
}   AES_CTX_T;

AES_CTX_T   g_test_ctx[CHANNEL_CNT];

uint8_t g_in_buff[TEST_TEXT_LEN] __attribute__((aligned(32)));
uint8_t g_out_buff[CHANNEL_CNT][TEST_TEXT_LEN] __attribute__((aligned(32)));
uint8_t g_test_buff[CHANNEL_CNT][TEST_TEXT_LEN] __attribute__((aligned(32)));
uint32_t g_fdbck[CHANNEL_CNT][24] __attribute__((aligned(32)));

extern volatile int  g_AES_done;
extern volatile int  g_PRNG_done;

void random_gen_256()
{
    g_PRNG_done = 0;
    CRYPTO->PRNG_CTL = (PRNG_KEY_SIZE_256 << CRYPTO_PRNG_CTL_KEYSZ_Pos) | CRYPTO_PRNG_CTL_START_Msk;
    while (!g_PRNG_done);
}

void  set_AES_control(AES_CTX_T *ctx, int channel)
{
    int         i;

    CRYPTO->AES_CTL = CRYPTO_AES_CTL_STOP_Msk;
    CRYPTO->AES_CTL = 0;
    ctx->ctrl = CRYPTO_AES_CTL_FBOUT_Msk;

    if (ctx->keylen == 0)
    {
        printf("AES-128");
        ctx->ctrl |= (AES_KEY_SIZE_128 << CRYPTO_AES_CTL_KEYSZ_Pos);
    }
    if (ctx->keylen == 1)
    {
        printf("AES-192");
        ctx->ctrl |= (AES_KEY_SIZE_192 << CRYPTO_AES_CTL_KEYSZ_Pos);
    }
    else
    {
        printf("AES-256");
        ctx->ctrl |= (AES_KEY_SIZE_256 << CRYPTO_AES_CTL_KEYSZ_Pos);
    }

    //printf( "%s mode, ", _mode_list[ctx->mode_sel].name);
    ctx->ctrl |= (_mode_list[ctx->mode_sel].mode << CRYPTO_AES_CTL_OPMODE_Pos);

    if (ctx->encrypt)
    {
        printf("encode");
        ctx->ctrl |= CRYPTO_AES_CTL_ENCRYPT_Msk;
    }
    else
    {
        printf("decode");
    }
    printf("\n");

    for (i = 0; i < 8; i++)
        CRYPTO->AES_KEY[i] = ctx->key[i];

    for (i = 0; i < 4; i++)
        CRYPTO->AES_IV[i] = ctx->iv[i];

    printf("key => ");
    for (i = 0; i < 8; i++)
        printf("%08x", ctx->key[i]);
    printf("\niv => %08x%08x%08x%08x\n", ctx->iv[0], ctx->iv[1], ctx->iv[2], ctx->iv[3]);

    /*
     *  Start AES encode/decode
     */
    CRYPTO->AES_SADDR = (uint32_t)&g_in_buff[0];
    CRYPTO->AES_DADDR = (uint32_t)&g_out_buff[channel][0];
    CRYPTO->AES_CNT   = TEST_TEXT_LEN;
    CRYPTO->AES_FBADDR = (uint32_t)&g_fdbck[0];

    printf("SADDR = 0x%x\n", CRYPTO->AES_SADDR);
    printf("DADDR = 0x%x\n", CRYPTO->AES_DADDR);

    g_AES_done = 0;
    CRYPTO->AES_CTL = ctx->ctrl | CRYPTO_AES_CTL_START_Msk | CRYPTO_AES_CTL_DMAEN_Msk | CRYPTO_AES_CTL_DMALAST_Msk;
    printf("ctrl = 0x%x, AES_CTL = 0x%x\n", ctx->ctrl, CRYPTO->AES_CTL);
    while (!g_AES_done) ;
}


void generate_test_patterns()
{
    int         i, j;
    uint32_t    *prng_data;

    prng_data = (uint32_t *)((uint32_t)CRYPTO_BASE + 0x10);

    // generate input text
    for (i = 0; i < TEST_TEXT_LEN; i+=32)
    {
        random_gen_256();

        for (j = 0; j < 8; j++)
        {
            // *(uint32_t *)&(g_in_buff[i+j*4]) = prng_data[j];
            *(uint32_t *)((uint32_t)(&(g_in_buff[i+j*4])) | NON_CACHE_MASK) = prng_data[j];
        }
    }

    for (i = 0; i < CHANNEL_CNT; i++)
    {
        random_gen_256();
        for (j = 0; j < 8; j++)
            g_test_ctx[i].key[j] = prng_data[j];

        random_gen_256();
        for (j = 0; j < 4; j++)
            g_test_ctx[i].iv[j] = prng_data[j];

        random_gen_256();

        g_test_ctx[i].encrypt = prng_data[1] & 0x1;
        g_test_ctx[i].keylen = prng_data[2] % 3;
        g_test_ctx[i].mode_sel = (prng_data[3] & 0xff) % TEST_MODE_CNT;
        g_test_ctx[i].sm4en = 0; //prng_data[4] & 0x1;
    }

    for (i = 0; i < CHANNEL_CNT; i++)
    {
        printf("PIPE%d - ", i);
        set_AES_control(&g_test_ctx[i], i);
    }
}

int AES_multi_channel_test(void)
{
    AES_CTX_T *ctx;
    int i, j, test_loop, data_idx;

    printf("\n\n");
    printf("+----------------------------------------+\n");
    printf("|  AES multi-channel test                |\n");
    printf("+----------------------------------------+\n");

    for (test_loop = 1; test_loop < 1000; test_loop++)
    {
        printf("\n\nTEST LOOP %d ...\n\n", test_loop);
        generate_test_patterns();

        for (data_idx = 0; data_idx < TEST_TEXT_LEN; data_idx += TBLK_LEN)
        {
            for (i = 0; i < CHANNEL_CNT; i++)
            {
                ctx = &g_test_ctx[i];

                for (j = 0; j < 8; j++)
                    CRYPTO->AES_KEY[j] = ctx->key[j];

                if (data_idx == 0)
                {
                    for (j = 0; j < 4; j++)
                        CRYPTO->AES_IV[j] = ctx->iv[j];
                }

                CRYPTO->AES_SADDR = (uint32_t)&g_in_buff[data_idx];
                CRYPTO->AES_DADDR = (uint32_t)&g_test_buff[i][data_idx];
                CRYPTO->AES_CNT   = TBLK_LEN;
                CRYPTO->AES_FBADDR = (uint32_t)&g_fdbck[i];
                g_AES_done = 0;

                if (data_idx == 0)
                    CRYPTO->AES_CTL = ctx->ctrl | CRYPTO_AES_CTL_DMAEN_Msk | CRYPTO_AES_CTL_START_Msk;
                    else if (data_idx + TBLK_LEN >= TEST_TEXT_LEN)
                        CRYPTO->AES_CTL = ctx->ctrl | CRYPTO_AES_CTL_FBIN_Msk | CRYPTO_AES_CTL_DMAEN_Msk | CRYPTO_AES_CTL_DMACSCAD_Msk | CRYPTO_AES_CTL_DMALAST_Msk | CRYPTO_AES_CTL_START_Msk;
                    else
                        CRYPTO->AES_CTL = ctx->ctrl | CRYPTO_AES_CTL_FBIN_Msk | CRYPTO_AES_CTL_DMAEN_Msk | CRYPTO_AES_CTL_DMACSCAD_Msk | CRYPTO_AES_CTL_START_Msk;
                    while (!g_AES_done) ;

                if (do_compare(&g_out_buff[i][data_idx], &g_test_buff[i][data_idx], TBLK_LEN) != 0)
                {
                    printf("CH %d, index %d\n", i, data_idx);
                    printf("AES_CTL = 0x%x\n", CRYPTO->AES_CTL);
                    printf("\n\nCH=%d, OFFSET = %d\n", i, data_idx);
                    while (1);
                }

                while (CRYPTO->AES_STS & CRYPTO_AES_STS_BUSY_Msk);
            }
        }
    }
    printf("\n\nTEST OK!\n");
    return 0;
}
