/******************************************************************************
* @file aes_kat.c
* @version V1.00
* @brief AES Known-Answer-Test
*
* @copyright SPDX-License-Identifier: Apache-2.0
* @copyright (C) 2026 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/

#define TEXT_MAX_LEN        256

typedef struct kat_t
{
    uint32_t    u32OpMode;
    uint32_t    u32KeySize;
    int         keylen;
    char        key[128];
    char        iv[128];
    char        plainT[TEXT_MAX_LEN];
    char        cipherT[TEXT_MAX_LEN];
} KAT_T;

static KAT_T  g_test_vector[] = {
    {
        AES_MODE_CBC, AES_KEY_SIZE_128, 16,
        "10a58869d74be5a374cf867cfb473859",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "6d251e6944b051e04eaa6fb4dbf78465"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_128, 16,
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "ffc00000000000000000000000000000",
        "77e2b508db7fd89234caf7939ee5621a"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_128, 16,
        "80000000000000000000000000000000",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "0edd33d3c621e546455bd8ba1418bec8",
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_128, 16,
        "ff800000000000000000000000000000",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "42ffb34c743de4d88ca38011c990890b"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_128, 16,
        "ffff8000000000000000000000000000",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "c6a0b3e998d05068a5399778405200b4"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_128, 16,
        "ffffffff800000000000000000000000",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "ed62e16363638360fdd6ad62112794f0"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_128, 16,
        "fffffffffffffffffffffffffffffffe",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "9ba4a9143f4e5d4048521c4f8877d88e"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_128, 16,
        "ffffffffffffffffffffffffffffffff",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "a1f6258c877d5fcd8964484538bfc92c"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_128, 16,
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "80000000000000000000000000000000",
        "3ad78e726c1ec02b7ebfe92b23d9ec34"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_128, 16,
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "ffc00000000000000000000000000000",
        "77e2b508db7fd89234caf7939ee5621a"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_128, 16,
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "ffffffffffffffffffffffffffffffe0",
        "8568261797de176bf0b43becc6285afb"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_128, 16,
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "fffffffffffffffffffffffffffffff0",
        "f9b0fda0c4a898f5b9e6f661c4ce4d07"
    },
    {
        AES_MODE_CFB, AES_KEY_SIZE_128, 16,
        "00000000000000000000000000000000",
        "cb9fceec81286ca3e989bd979b0cb284",
        "00",
        "92"
    },
    {
        AES_MODE_CFB, AES_KEY_SIZE_128, 16,
        "10a58869d74be5a374cf867cfb473859",
        "00000000000000000000000000000000",
        "00",
        "6d"
    },
    {
        AES_MODE_ECB, AES_KEY_SIZE_128, 16,
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "f34481ec3cc627bacd5dc3fb08f273e6",
        "0336763e966d92595a567cc9ce537f5e"
    },
    {
        AES_MODE_ECB, AES_KEY_SIZE_128, 16,
        "10a58869d74be5a374cf867cfb473859",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "6d251e6944b051e04eaa6fb4dbf78465"
    },
    {
        AES_MODE_OFB, AES_KEY_SIZE_128, 16,
        "00000000000000000000000000000000",
        "f34481ec3cc627bacd5dc3fb08f273e6",
        "00000000000000000000000000000000",
        "0336763e966d92595a567cc9ce537f5e"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_192, 24,
        "000000000000000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "1b077a6af4b7f98229de786d7516b639",
        "275cfc0413d8ccb70513c3859b1d0f72"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_192, 24,
        "e9f065d7c13573587f7875357dfbb16c53489f6a4bd0f7cd",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "0956259c9cd5cfd0181cca53380cde06"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_192, 24,
        "800000000000000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "de885dc87f5a92594082d02cc1e1b42c"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_192, 24,
        "ff8000000000000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "eba83ff200cff9318a92f8691a06b09f"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_192, 24,
        "fffffffff800000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "cc4ba8a8e029f8b26d8afff9df133bb6"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_192, 24,
        "fffffffffffffffffffffffffffffffffffffffffffffffe",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "018596e15e78e2c064159defce5f3085"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_192, 24,
        "ffffffffffffffffffffffffffffffffffffffffffffffff",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "dd8a493514231cbf56eccee4c40889fb"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_192, 24,
        "000000000000000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "80000000000000000000000000000000",
        "6cd02513e8d4dc986b4afe087a60bd0c"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_192, 24,
        "000000000000000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "fffffffffffffffffffffffffffffffe",
        "cef41d16d266bdfe46938ad7884cc0cf"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_192, 24,
        "000000000000000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "ffffffffffffffffffffffffffffffff",
        "b13db4da1f718bc6904797c82bcf2d32"
    },
    {
        AES_MODE_CFB, AES_KEY_SIZE_192, 24,
        "000000000000000000000000000000000000000000000000",
        "9c2d8842e5f48f57648205d39a239af1",
        "00",
        "c9"
    },
    {
        AES_MODE_CFB, AES_KEY_SIZE_192, 24,
        "e9f065d7c13573587f7875357dfbb16c53489f6a4bd0f7cd",
        "00000000000000000000000000000000",
        "00",
        "09"
    },
    {
        AES_MODE_ECB, AES_KEY_SIZE_192, 24,
        "000000000000000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "1b077a6af4b7f98229de786d7516b639",
        "275cfc0413d8ccb70513c3859b1d0f72"
    },
    {
        AES_MODE_ECB, AES_KEY_SIZE_192, 24,
        "e9f065d7c13573587f7875357dfbb16c53489f6a4bd0f7cd",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "0956259c9cd5cfd0181cca53380cde06"
    },
    {
        AES_MODE_OFB, AES_KEY_SIZE_192, 24,
        "000000000000000000000000000000000000000000000000",
        "1b077a6af4b7f98229de786d7516b639",
        "00000000000000000000000000000000",
        "275cfc0413d8ccb70513c3859b1d0f72"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_256, 32,
        "0000000000000000000000000000000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "761c1fe41a18acf20d241650611d90f1",
        "623a52fcea5d443e48d9181ab32c7421"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_256, 32,
        "c47b0294dbbbee0fec4757f22ffeee3587ca4730c3d33b691df38bab076bc558",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "46f2fb342d6f0ab477476fc501242c5f"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_256, 32,
        "8000000000000000000000000000000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "e35a6dcb19b201a01ebcfa8aa22b5759"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_256, 32,
        "ffff800000000000000000000000000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "610b71dfc688e150d8152c5b35ebc14d"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_256, 32,
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe0",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "cf78618f74f6f3696e0a4779b90b5a77"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_256, 32,
        "fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "b07d4f3e2cd2ef2eb545980754dfea0f"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_256, 32,
        "ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "4bf85f1b5d54adbc307b0a048389adcb"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_256, 32,
        "0000000000000000000000000000000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "80000000000000000000000000000000",
        "ddc6bf790c15760d8d9aeb6f9a75fd4e"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_256, 32,
        "0000000000000000000000000000000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "fffffffffffffffffffffffffffffffe",
        "7bfe9d876c6d63c1d035da8fe21c409d"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_256, 32,
        "0000000000000000000000000000000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "ffffffffffffffffffffffffffffffff",
        "acdace8078a32b1a182bfa4987ca1347"
    },
    {
        AES_MODE_CFB, AES_KEY_SIZE_256, 32,
        "0000000000000000000000000000000000000000000000000000000000000000",
        "014730f80ac625fe84f026c60bfd547d",
        "00",
        "5c"
    },
    {
        AES_MODE_CFB, AES_KEY_SIZE_256, 32,
        "c47b0294dbbbee0fec4757f22ffeee3587ca4730c3d33b691df38bab076bc558",
        "00000000000000000000000000000000",
        "00",
        "46"
    },
    {
        AES_MODE_ECB, AES_KEY_SIZE_256, 32,
        "0000000000000000000000000000000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "014730f80ac625fe84f026c60bfd547d",
        "5c9d844ed46f9885085e5d6a4f94c7d7"
    },
    {
        AES_MODE_ECB, AES_KEY_SIZE_256, 32,
        "c47b0294dbbbee0fec4757f22ffeee3587ca4730c3d33b691df38bab076bc558",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "46f2fb342d6f0ab477476fc501242c5f"
    },
    {
        AES_MODE_CFB, AES_KEY_SIZE_256, 32,
        "0000000000000000000000000000000000000000000000000000000000000000",
        "014730f80ac625fe84f026c60bfd547d",
        "00000000000000000000000000000000",
        "5c9d844ed46f9885085e5d6a4f94c7d7"
    },
    {
        AES_MODE_ECB, AES_KEY_SIZE_128, 16,
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "f34481ec3cc627bacd5dc3fb08f273e6",
        "0336763e966d92595a567cc9ce537f5e"
    },
    {
        AES_MODE_ECB, AES_KEY_SIZE_128, 16,
        "10a58869d74be5a374cf867cfb473859",
        "00000000000000000000000000000000",
        "00000000000000000000000000000000",
        "6d251e6944b051e04eaa6fb4dbf78465"
    },
    {
        AES_MODE_OFB, AES_KEY_SIZE_128, 16,
        "00000000000000000000000000000000",
        "f34481ec3cc627bacd5dc3fb08f273e6",
        "00000000000000000000000000000000",
        "0336763e966d92595a567cc9ce537f5e"
    },
    {
        AES_MODE_CBC, AES_KEY_SIZE_192, 24,
        "000000000000000000000000000000000000000000000000",
        "00000000000000000000000000000000",
        "1b077a6af4b7f98229de786d7516b639",
        "275cfc0413d8ccb70513c3859b1d0f72"
    },
};

uint8_t  *pPlainText, *pCipherText, *pOutput;

uint8_t char_to_hex(uint8_t c)
{
    if ((c >= '0') && (c <= '9'))
        return c - '0';
    if ((c >= 'a') && (c <= 'f'))
        return c - 'a' + 10;
    if ((c >= 'A') && (c <= 'F'))
        return c - 'A' + 10;
    return 0;
}

int  str2hex(char *str, uint8_t *hex)
{
    int  val8, count = 0;

    while (*str)
    {
        val8 = char_to_hex(*str);
        str++;
        val8 = (val8 << 4) | char_to_hex(*str);
        str++;

        hex[count] = val8;
        count++;
    }
    return count;
}

void  word_swap_hex(uint8_t *hex, int len)
{
    int      i;
    uint8_t  val8;

    len = (len + 3) & 0xfffffffc;

    for (i = 0; i < len; i+=4)
    {
        val8 = hex[i];
        hex[i] = hex[i+3];
        hex[i+3] = val8;

        val8 = hex[i+1];
        hex[i+1] = hex[i+2];
        hex[i+2] = val8;
    }
}

void swap_registers(volatile uint32_t *reg_base, int reg_cnt)
{
    int       i;
    volatile uint32_t  *reg = reg_base;
    uint32_t  data32;

    reg = reg_base;
    for (i = 0; i < reg_cnt; i++, reg++)
    {
        data32 = ((*reg >> 24) & 0xff) | ((*reg >> 8) & 0xff00) |
                 ((*reg << 8) & 0xff0000) | ((*reg << 24) & 0xff000000);
        *reg = data32;
    }
}

int read_test_vector(KAT_T *t)
{
    int       i, count;
    uint8_t   k_hex[256];
    uint32_t  key[8];

    /*-----------------------------------------------------------------------*/
    /*  read AES key                                                         */
    /*-----------------------------------------------------------------------*/
    if (str2hex(t->key, k_hex) != t->keylen)
        return -1;

    for (i = 0; i < t->keylen; i += 4)
    {
        key[i / 4] = (k_hex[i] << 24) | (k_hex[i + 1] << 16) |
                     (k_hex[i + 2] << 8) | k_hex[i + 3];
    }

    AES_SetKey(key, t->u32KeySize);

    /*-----------------------------------------------------------------------*/
    /*  read AES initial vector                                              */
    /*-----------------------------------------------------------------------*/
    if (str2hex(t->iv, k_hex) != 16)
        return -1;

    for (i = 0; i < 16; i += 4)
    {
        key[i / 4] = (k_hex[i] << 24) | (k_hex[i + 1] << 16) |
                     (k_hex[i + 2] << 8) | k_hex[i + 3];
    }

    AES_SetInitVect(key);

    /*-----------------------------------------------------------------------*/
    /*  read plain text and cipher text                                      */
    /*-----------------------------------------------------------------------*/
    count = str2hex(t->plainT, pPlainText);

    str2hex(t->cipherT, pCipherText);

    return count;
}

int  AES_KAT_test()
{
    int       i, len;

    pPlainText  = nc_ptr(au8InputData);
    pCipherText = nc_ptr(au8OutputData);
    pOutput     = nc_ptr(au8CascadeOut);

    for (i = 0; i < sizeof(g_test_vector) / sizeof(KAT_T); i++)
    {
        printf("KAT vecotr %d...\n", i);

        /*-------------------------------------------------------------------*/
        /*  Encrypt test                                                     */
        /*-------------------------------------------------------------------*/
        len = read_test_vector((KAT_T *)&g_test_vector[i]);
        if (len < 0)
        {
            printf("Failed to read test vector!\n");
            return -1;
        }

        memset(pOutput, 0, len);

        AES_Open(AES_ENCRYPT, g_test_vector[i].u32OpMode,
                 g_test_vector[i].u32KeySize, AES_IN_OUT_SWAP);

        AES_SetDMATransfer((UINT32)pPlainText, (uint32_t)pOutput, len);

        g_AES_done = 0;
        AES_Start(CRYPTO_DMA_ONE_SHOT, CRYPTO_AES_FB_NONE, 0);
        while (!g_AES_done);

        if (memcmp(pCipherText, pOutput, len) != 0)
        {
            printf("AES test vector encrypt failed at =>\n");
            printf("KEY        = %s\n", g_test_vector[i].key);
            printf("IV         = %s\n", g_test_vector[i].iv);
            printf("PLAINTEXT  = %s\n", g_test_vector[i].plainT);
            printf("CIPHERTEXT = %s\n", g_test_vector[i].cipherT);

            printf("AES encrypt output:\n");
            dump_buff_hex(pOutput, len);
            return -1;
        }
        printf("[OK]\n");

        /*-------------------------------------------------------------------*/
        /*  Decrypt test                                                     */
        /*-------------------------------------------------------------------*/
        read_test_vector((KAT_T *)&g_test_vector[i]);

        AES_Open(AES_DECRYPT, g_test_vector[i].u32OpMode,
                 g_test_vector[i].u32KeySize, AES_IN_OUT_SWAP);

        AES_SetDMATransfer((uint32_t)pCipherText, (uint32_t)pOutput, len);

        memset(pOutput, 0,  len);

        g_AES_done = 0;
        g_AES_done = 0;
        AES_Start(CRYPTO_DMA_ONE_SHOT, CRYPTO_AES_FB_NONE, 0);
        while (!g_AES_done);

        if (memcmp(pPlainText, pOutput, len) != 0)
        {
            printf("AES test vector decrypt failed at =>\n");
            printf("KEY        = %s\n", g_test_vector[i].key);
            printf("IV         = %s\n", g_test_vector[i].iv);
            printf("PLAINTEXT  = %s\n", g_test_vector[i].plainT);
            printf("CIPHERTEXT = %s\n", g_test_vector[i].cipherT);

            printf("AES decrypt output:\n");
            dump_buff_hex(pOutput, len);
            return -1;
        }
        printf("[OK]\n");
    }

    printf("All test vector passed.\n");
    return 0;
}
