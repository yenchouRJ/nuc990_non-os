/**************************************************************************//**
 * @file     crypto.h
 * @version  V1.10
 * @brief    Cryptographic Accelerator driver header file
 *
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#ifndef __CRYPTO_H__
#define __CRYPTO_H__

#include "NuMicro.h"
#include "crypto_reg.h"

#ifdef __cplusplus
extern "C"
{
#endif

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup CRYPTO_Driver CRYPTO Driver
  @{
*/

/** @addtogroup CRYPTO_EXPORTED_CONSTANTS CRYPTO Exported Constants
  @{
*/

#define PRNG_KEY_SIZE_128       0UL
#define PRNG_KEY_SIZE_163       1UL
#define PRNG_KEY_SIZE_192       2UL
#define PRNG_KEY_SIZE_224       3UL
#define PRNG_KEY_SIZE_233       4UL
#define PRNG_KEY_SIZE_255       5UL
#define PRNG_KEY_SIZE_256       6UL
#define PRNG_KEY_SIZE_283       7UL
#define PRNG_KEY_SIZE_384       8UL
#define PRNG_KEY_SIZE_409       9UL
#define PRNG_KEY_SIZE_512       10UL
#define PRNG_KEY_SIZE_521       11UL
#define PRNG_KEY_SIZE_571       12UL

#define PRNG_SEED_CONT          0UL     /*!< PRNG using current seed                 \hideinitializer */
#define PRNG_SEED_RELOAD        1UL     /*!< PRNG reload new seed                    \hideinitializer */

#define AES_MAX_CHN             16      /*!< Maximum number of AES channels          \hideinitializer */

#define AES_KEY_SIZE_128        0UL     /*!< AES select 128-bit key length           \hideinitializer */
#define AES_KEY_SIZE_192        1UL     /*!< AES select 192-bit key length           \hideinitializer */
#define AES_KEY_SIZE_256        2UL     /*!< AES select 256-bit key length           \hideinitializer */

#define AES_MODE_ECB            0UL     /*!< AES select ECB mode                     \hideinitializer */
#define AES_MODE_CBC            1UL     /*!< AES select CBC mode                     \hideinitializer */
#define AES_MODE_CFB            2UL     /*!< AES select CFB mode                     \hideinitializer */
#define AES_MODE_OFB            3UL     /*!< AES select OFB mode                     \hideinitializer */
#define AES_MODE_CTR            4UL     /*!< AES select CTR mode                     \hideinitializer */
#define AES_MODE_CBC_CS1        0x10UL  /*!< AES select CBC CS1 mode                 \hideinitializer */
#define AES_MODE_CBC_CS2        0x11UL  /*!< AES select CBC CS2 mode                 \hideinitializer */
#define AES_MODE_CBC_CS3        0x12UL  /*!< AES select CBC CS3 mode                 \hideinitializer */
#define AES_MODE_GCM            0x20UL  /*!< AES select GCM (Galois/Counter Mode)    \hideinitializer */
#define AES_MODE_GHASH          0x21UL  /*!< AES select GHASH (Galois Hash Function) \hideinitializer */
#define AES_MODE_CCM            0x22UL  /*!< AES select CCM (Counter with CBC-MAC Mode)   \hideinitializer */

#define AES_NO_SWAP             0UL     /*!< AES do not swap input and output data   \hideinitializer */
#define AES_OUT_SWAP            1UL     /*!< AES swap output data                    \hideinitializer */
#define AES_IN_SWAP             2UL     /*!< AES swap input data                     \hideinitializer */
#define AES_IN_OUT_SWAP         3UL     /*!< AES swap both input and output data     \hideinitializer */

#define CHAPOLY_MODE_CHACHA20   0UL     /*!< CHAPOLY select ChaCha20 mode            \hideinitializer */
#define CHAPOLY_MODE_POLY1305   1UL     /*!< CHAPOLY select Poly1305 mode            \hideinitializer */
#define CHAPOLY_MODE_AEAD       2UL     /*!< CHAPOLY select AEAD mode                \hideinitializer */

#define SHA_MODE_SEL_SHA1       0UL     /*!< SHA engine select SHA1                  \hideinitializer */
#define SHA_MODE_SEL_SHA2       0UL     /*!< SHA engine select SHA2                  \hideinitializer */
#define SHA_MODE_SEL_SHA3       1UL     /*!< SHA engine select SHA3                  \hideinitializer */
#define SHA_MODE_SEL_MD5        4UL     /*!< SHA engine select MD5                   \hideinitializer */

#define SHA_MODE_SHA1           0UL     /*!< SHA select SHA-1 160-bit                \hideinitializer */
#define SHA_MODE_SHA224         5UL     /*!< SHA select SHA-224 224-bit              \hideinitializer */
#define SHA_MODE_SHA256         4UL     /*!< SHA select SHA-256 256-bit              \hideinitializer */
#define SHA_MODE_SHA384         7UL     /*!< SHA select SHA-384 384-bit              \hideinitializer */
#define SHA_MODE_SHA512         6UL     /*!< SHA select SHA-512 512-bit              \hideinitializer */
#define SHA_MODE_SHAKE128       0UL     /*!< SHA select SHA-3 SHAKE128               \hideinitializer */
#define SHA_MODE_SHAKE256       1UL     /*!< SHA select SHA-3 SHAKE256               \hideinitializer */

#define SHA_NO_SWAP             0UL     /*!< SHA do not swap input and output data   \hideinitializer */
#define SHA_OUT_SWAP            1UL     /*!< SHA swap output data                    \hideinitializer */
#define SHA_IN_SWAP             2UL     /*!< SHA swap input data                     \hideinitializer */
#define SHA_IN_OUT_SWAP         3UL     /*!< SHA swap both input and output data     \hideinitializer */

#define CRYPTO_DMA_FIRST        0x4UL   /*!< Do first encrypt/decrypt in DMA cascade \hideinitializer */
#define CRYPTO_DMA_ONE_SHOT     0x5UL   /*!< Do one shot encrypt/decrypt with DMA      \hideinitializer */
#define CRYPTO_DMA_CONTINUE     0x6UL   /*!< Do continuous encrypt/decrypt in DMA cascade \hideinitializer */
#define CRYPTO_DMA_LAST         0x7UL   /*!< Do last encrypt/decrypt in DMA cascade          \hideinitializer */

typedef enum
{
    /*!< ECC curve                \hideinitializer */
    CURVE_P_192  = 0x01,                /*!< ECC curve P-192          \hideinitializer */
    CURVE_P_224  = 0x02,                /*!< ECC curve P-224          \hideinitializer */
    CURVE_P_256  = 0x03,                /*!< ECC curve P-256          \hideinitializer */
    CURVE_P_384  = 0x04,                /*!< ECC curve P-384          \hideinitializer */
    CURVE_P_521  = 0x05,                /*!< ECC curve P-521          \hideinitializer */
    CURVE_K_163  = 0x11,                /*!< ECC curve K-163          \hideinitializer */
    CURVE_K_233  = 0x12,                /*!< ECC curve K-233          \hideinitializer */
    CURVE_K_283  = 0x13,                /*!< ECC curve K-283          \hideinitializer */
    CURVE_K_409  = 0x14,                /*!< ECC curve K-409          \hideinitializer */
    CURVE_K_571  = 0x15,                /*!< ECC curve K-571          \hideinitializer */
    CURVE_B_163  = 0x21,                /*!< ECC curve B-163          \hideinitializer */
    CURVE_B_233  = 0x22,                /*!< ECC curve B-233          \hideinitializer */
    CURVE_B_283  = 0x23,                /*!< ECC curve B-283          \hideinitializer */
    CURVE_B_409  = 0x24,                /*!< ECC curve B-409          \hideinitializer */
    CURVE_B_571  = 0x25,                /*!< ECC curve K-571          \hideinitializer */
    CURVE_KO_192 = 0x31,                /*!< ECC 192-bits "Koblitz" curve   \hideinitializer */
    CURVE_KO_224 = 0x32,                /*!< ECC 224-bits "Koblitz" curve   \hideinitializer */
    CURVE_KO_256 = 0x33,                /*!< ECC 256-bits "Koblitz" curve   \hideinitializer */
    CURVE_BP_256 = 0x41,                /*!< ECC Brainpool 256-bits curve   \hideinitializer */
    CURVE_BP_384 = 0x42,                /*!< ECC Brainpool 256-bits curve   \hideinitializer */
    CURVE_BP_512 = 0x43,                /*!< ECC Brainpool 256-bits curve   \hideinitializer */
    CURVE_25519  = 0x51,
    CURVE_Ed448  = 0x52,
    CURVE_UNDEF,                        /*!< Invalid curve            \hideinitializer */
} E_ECC_CURVE;                          /*!< ECC curve                \hideinitializer */

enum ed_type {
    EDDSA_ED25519,
    EDDSA_ED25519PH,
    EDDSA_ED25519CTX,
    EDDSA_ED448,
    EDDSA_ED448PH,
};

#define RSA_MAX_KLEN            (4096)
#define RSA_KBUF_HLEN           (RSA_MAX_KLEN / 4 + 8)
#define RSA_KBUF_BLEN           (RSA_MAX_KLEN + 32)

#define KEY_OWNER_AES           (0x0ul)
#define KEY_OWNER_ECC           (0x4ul)
#define KEY_OWNER_CPU           (0x5ul)

#define KEY_WSDST_SRAM          (0x0ul)
#define KEY_WSDST_OTP           (0x2ul)

extern volatile uint32_t g_ECC_done, g_ECCERR_done;

/*@}*/ /* end of group CRYPTO_EXPORTED_CONSTANTS */

/** @addtogroup M480_CRYPTO_EXPORTED_MACROS CRYPTO Exported Macros
  @{
*/

/*----------------------------------------------------------------------------------------------*/
/*  Macros                                                                                      */
/*----------------------------------------------------------------------------------------------*/

/**
  * @brief This macro enables PRNG interrupt.
  * @return None
  * \hideinitializer
  */
#define PRNG_ENABLE_INT()           (CRYPTO->INTEN |= CRYPTO_INTEN_PRNGIEN_Msk)

/**
  * @brief This macro disables PRNG interrupt.
  * @return None
  * \hideinitializer
  */
#define PRNG_DISABLE_INT()          (CRYPTO->INTEN &= ~CRYPTO_INTEN_PRNGIEN_Msk)

/**
  * @brief This macro gets PRNG interrupt flag.
  * @return PRNG interrupt flag.
  * \hideinitializer
  */
#define PRNG_GET_INT_FLAG()         (CRYPTO->INTSTS & CRYPTO_INTSTS_PRNGIF_Msk)

/**
  * @brief This macro clears PRNG interrupt flag.
  * @return None
  * \hideinitializer
  */
#define PRNG_CLR_INT_FLAG()         (CRYPTO->INTSTS = CRYPTO_INTSTS_PRNGIF_Msk)

/**
  * @brief This macro enables AES interrupt.
  * @return None
  * \hideinitializer
  */
#define AES_ENABLE_INT()            (CRYPTO->INTEN |= (CRYPTO_INTEN_AESIEN_Msk | CRYPTO_INTEN_AESEIEN_Msk))

/**
  * @brief This macro disables AES interrupt.
  * @return None
  * \hideinitializer
  */
#define AES_DISABLE_INT()           (CRYPTO->INTEN &= ~(CRYPTO_INTEN_AESIEN_Msk | CRYPTO_INTEN_AESEIEN_Msk))

/**
  * @brief This macro gets AES interrupt flag.
  * @return AES interrupt flag.
  * \hideinitializer
  */
#define AES_GET_INT_FLAG()          (CRYPTO->INTSTS & (CRYPTO_INTSTS_AESIF_Msk | CRYPTO_INTSTS_AESEIF_Msk))

/**
  * @brief This macro clears AES interrupt flag.
  * @return None
  * \hideinitializer
  */
#define AES_CLR_INT_FLAG()          (CRYPTO->INTSTS = (CRYPTO_INTSTS_AESIF_Msk | CRYPTO_INTSTS_AESEIF_Msk))

/**
  * @brief This macro enables AES key protection.
  * @return None
  * \hideinitializer
  */
#define AES_ENABLE_KEY_PROTECT(CRYPTO)  (CRYPTO->AES_CTL |= CRYPTO_AES_CTL_KEYPRT_Msk)

/**
  * @brief This macro disables AES key protection.
  * @return None
  * \hideinitializer
  */
#define AES_DISABLE_KEY_PROTECT()   (CRYPTO->AES_CTL = (CRYPTO->AES_CTL & ~CRYPTO_AES_CTL_KEYPRT_Msk) | (0x16UL << CRYPTO_AES_CTL_KEYUNPRT_Pos)); \
                                      (CRYPTO->AES_CTL &= ~CRYPTO_AES_CTL_KEYPRT_Msk)

/**
  * @brief This macro enables SHA interrupt.
  * @return None
  * \hideinitializer
  */
#define SHA_ENABLE_INT()            (CRYPTO->INTEN |= (CRYPTO_INTEN_HMACIEN_Msk | CRYPTO_INTEN_HMACEIEN_Msk))

/**
  * @brief This macro disables SHA interrupt.
  * @return None
  * \hideinitializer
  */
#define SHA_DISABLE_INT()           (CRYPTO->INTEN &= ~(CRYPTO_INTEN_HMACIEN_Msk | CRYPTO_INTEN_HMACEIEN_Msk))

/**
  * @brief This macro gets SHA interrupt flag.
  * @return SHA interrupt flag.
  * \hideinitializer
  */
#define SHA_GET_INT_FLAG()          (CRYPTO->INTSTS & (CRYPTO_INTSTS_HMACIF_Msk | CRYPTO_INTSTS_HMACEIF_Msk))

/**
  * @brief This macro clears SHA interrupt flag.
  * @return None
  * \hideinitializer
  */
#define SHA_CLR_INT_FLAG()          (CRYPTO->INTSTS = (CRYPTO_INTSTS_HMACIF_Msk | CRYPTO_INTSTS_HMACEIF_Msk))

/**
  * @brief This macro enables ECC interrupt.
  * @return None
  * \hideinitializer
  */
#define ECC_ENABLE_INT()            (CRYPTO->INTEN |= (CRYPTO_INTEN_ECCIEN_Msk | CRYPTO_INTEN_ECCEIEN_Msk))

/**
  * @brief This macro disables ECC interrupt.
  * @return None
  * \hideinitializer
  */
#define ECC_DISABLE_INT()           (CRYPTO->INTEN &= ~(CRYPTO_INTEN_ECCIEN_Msk | CRYPTO_INTEN_ECCEIEN_Msk))

/**
  * @brief This macro gets ECC interrupt flag.
  * @return ECC interrupt flag.
  * \hideinitializer
  */
#define ECC_GET_INT_FLAG()          (CRYPTO->INTSTS & (CRYPTO_INTSTS_ECCIF_Msk | CRYPTO_INTSTS_ECCEIF_Msk))

/**
  * @brief This macro clears ECC interrupt flag.
  * @return None
  * \hideinitializer
  */
#define ECC_CLR_INT_FLAG()          (CRYPTO->INTSTS = (CRYPTO_INTSTS_ECCIF_Msk | CRYPTO_INTSTS_ECCEIF_Msk))

/*@}*/ /* end of group M480_CRYPTO_EXPORTED_MACROS */

/** @addtogroup CRYPTO_EXPORTED_FUNCTIONS CRYPTO Exported Functions
  @{
*/

/*---------------------------------------------------------------------------------------------------------*/
/*  Functions                                                                                              */
/*---------------------------------------------------------------------------------------------------------*/

void PRNG_Open(uint32_t u32KeySize, uint32_t u32SeedReload, uint32_t u32Seed);
void PRNG_Start(void);
void PRNG_Read(uint32_t u32RandKey[]);
int  AES_Open(uint32_t u32Channel, uint32_t u32EncDec, uint32_t u32OpMode, uint32_t u32KeySize, uint32_t u32SwapType);
int  AES_Start(uint32_t u32Channel, uint32_t u32DMAMode);
int  AES_SetKey(uint32_t u32Channel, uint32_t au32Keys[], uint32_t u32KeySize);
int  AES_SetInitVect(uint32_t u32Channel, uint32_t au32IV[]);
int  AES_SetDMATransfer(uint32_t u32Channel, uint32_t u32SrcAddr, uint32_t u32DstAddr, uint32_t u32TransCnt);
void SHA_Open(uint32_t u32OpMode, uint32_t u32SwapType, uint32_t hmac_key_len);
void SHA_Start(uint32_t u32DMAMode);
void SHA_SetDMATransfer(uint32_t u32SrcAddr, uint32_t u32TransCnt);
void SHA_Read(uint32_t u32Digest[]);
void ECC_Start(uint32_t ecc_ctl);
void ECC_Complete(void);
int  ECC_IsPrivateKeyValid(E_ECC_CURVE ecc_curve,  char private_k[]);
int  ECC_GeneratePublicKey(E_ECC_CURVE ecc_curve, char *private_k, char public_k1[], char public_k2[]);
int  ECC_Mutiply(E_ECC_CURVE ecc_curve, char x1[], char y1[], char *k, char x2[], char y2[]);
int  ECC_GenerateSecretZ(E_ECC_CURVE ecc_curve, char *private_k, char public_k1[], char public_k2[], char secret_z[]);
int  ECC_GenerateSignature(E_ECC_CURVE ecc_curve, char *message, char *d, char *k, char *R, char *S);
int  ECC_VerifySignature(E_ECC_CURVE ecc_curve, char *message, char *public_k1, char *public_k2, char *R, char *S);

int  AES_Start_KS(uint32_t u32Channel, uint32_t u32DMAMode, int ksel, int knum);
int  ECC_Write_N(E_ECC_CURVE ecc_curve);
int  ECC_GeneratePublicKey_KS(E_ECC_CURVE ecc_curve, int k_ksnum, char public_k1[], char public_k2[]);
int  ECC_Mutiply_KS(E_ECC_CURVE ecc_curve, int x1_ksnum, char x1[], int y1_ksnum, char y1[], int k_ksnum, char *k, char x2[], char y2[]);
int  ECC_GenerateSignature_KS(E_ECC_CURVE ecc_curve, char *message, int d_ksnum, char *R, char *S);
int  ECC_VerifySignature_KS(E_ECC_CURVE ecc_curve, char *message, int x_ksnum, int y_ksnum, char *R, char *S);

int  ECC_ED448_SigGen(enum ed_type eddsa_type, uint8_t *priv_key, uint8_t *message, int msg_len, uint8_t *ctx, int ctx_len, uint32_t *R, uint32_t *S);
int  ECC_ED448_Verify(enum ed_type eddsa_type, uint8_t *pub_key, uint8_t *message, int msg_len, uint8_t *ctx, int ctx_len, uint32_t *R, uint32_t *S);
int  ECC_ED25519_SigGen(enum ed_type eddsa_type, uint8_t *priv_key, uint8_t *message, int msg_len, uint8_t *ctx, int ctx_len, uint32_t *R, uint32_t *S);
int  ECC_ED25519_Verify(enum ed_type eddsa_type, uint8_t *pub_key, uint8_t *message, int msg_len, uint8_t *ctx, int ctx_len, uint32_t *R, uint32_t *S);

void Hex2Reg(char input[], uint32_t volatile reg[]);
void Reg2Hex(int count, uint32_t volatile reg[], char output[]);
void Hex2RegEx(char input[], uint32_t volatile reg[], int shift);

int ecc_strcmp(char *s1, char *s2);

/*@}*/ /* end of group CRYPTO_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group CRYPTO_Driver */

/*@}*/ /* end of group Standard_Driver */

#ifdef __cplusplus
}
#endif

#endif  /* __CRYPTO_H__ */
