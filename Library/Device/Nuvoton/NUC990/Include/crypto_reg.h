/**************************************************************************//**
 * @file     crypto_reg.h
 * @version  V1.00
 * @brief    CRYPTO register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __CRYPTO_REG_H__
#define __CRYPTO_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/**
   @addtogroup REGISTER Control Register
   @{
*/

/*---------------------- Cryptographic Accelerator -------------------------*/
/**
    @addtogroup CRYPTO Cryptographic Accelerator
    Memory Mapped Structure for CRYPTO Controller
@{ */

typedef struct
{

/**
 * @var CRYPTO_T::INTEN
 * Offset: 0x00  Crypto Interrupt Enable Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |AESIEN    |AES Interrupt Enable Bit
 * |        |          |0 = AES interrupt Disabled.
 * |        |          |1 = AES interrupt Enabled.
 * |        |          |Note: In DMA mode, an interrupt will be triggered when an amount of data set in AES_DMA_CNT is fed into the AES engine.
 * |        |          |In Non-DMA mode, an interrupt will be triggered when the AES engine finishes the operation.
 * |[1]     |AESEIEN   |AES Error Flag Enable Bit
 * |        |          |0 = AES error interrupt flag Disabled.
 * |        |          |1 = AES error interrupt flag Enabled.
 * |[16]    |PRNGIEN   |PRNG Interrupt Enable Bit
 * |        |          |0 = PRNG interrupt Disabled.
 * |        |          |1 = PRNG interrupt Enabled.
 * |[17]    |PRNGEIEN  |PRNG Error Flag Enable Bit
 * |        |          |0 = PRNG error interrupt flag Disabled.
 * |        |          |1 = PRNG error interrupt flag Enabled.
 * |[22]    |ECCIEN    |ECC Interrupt Enable Bit
 * |        |          |0 = ECC interrupt Disabled.
 * |        |          |1 = ECC interrupt Enabled.
 * |        |          |Note: In DMA mode, an interrupt will be triggered when an amount of data set in ECC_DMA_CNT is fed into the ECC engine
 * |        |          |In Non-DMA mode, an interrupt will be triggered when the ECC engine finishes the operation.
 * |[23]    |ECCEIEN   |ECC Error Interrupt Enable Bit
 * |        |          |0 = ECC error interrupt flag Disabled.
 * |        |          |1 = ECC error interrupt flag Enabled.
 * |[24]    |HMACIEN   |SHA/HMAC Interrupt Enable Bit
 * |        |          |0 = SHA/HMAC interrupt Disabled.
 * |        |          |1 = SHA/HMAC interrupt Enabled.
 * |        |          |Note: In DMA mode, an interrupt will be triggered when an amount of data set in HMAC_DMA_CNT is fed into the SHA/HMAC engine
 * |        |          |In Non-DMA mode, an interrupt will be triggered when the SHA/HMAC engine finishes the operation.
 * |[25]    |HMACEIEN  |SHA/HMAC Error Interrupt Enable Bit
 * |        |          |0 = SHA/HMAC error interrupt flag Disabled.
 * |        |          |1 = HMAC error interrupt flag Enabled.
 * |[30]    |RSAIEN    |RSA Interrupt Enable Bit
 * |        |          |0 = RSA interrupt Disabled.
 * |        |          |1 = RSA interrupt Enabled.
 * |[31]    |RSAEIEN   |RSA Error Interrupt Enable Bit
 * |        |          |0 = RSA error interrupt flag Disabled.
 * |        |          |1 = RSA error interrupt flag Enabled.
 * @var CRYPTO_T::INTSTS
 * Offset: 0x04  Crypto Interrupt Flag
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |AESIF     |AES Finish Interrupt Flag
 * |        |          |0 = No AES interrupt.
 * |        |          |1 = AES done interrupt.
 * |        |          |Note: This bit is cleared by writing 1, and it has no effect by writing 0.
 * |[1]     |AESEIF    |AES Error Flag
 * |        |          |This register includes operating and setting error
 * |        |          |The detail flag is shown in CRYPTO_AES_STS register.
 * |        |          |0 = No AES error.
 * |        |          |1 = AES error interrupt.
 * |        |          |Note: This bit is cleared by writing 1, and it has no effect by writing 0.
 * |[16]    |PRNGIF    |PRNG Finish Interrupt Flag
 * |        |          |0 = No PRNG interrupt.
 * |        |          |1 = PRNG done interrupt.
 * |        |          |Note: This bit is cleared by writing 1, and it has no effect by writing 0.
 * |[17]    |PRNGEIF   |PRNG Error Flag
 * |        |          |This register includes operating and setting error
 * |        |          |The detail flag is shown in CRYPTO_PRNG_STS register.
 * |        |          |0 = No PRNG error.
 * |        |          |1 = PRNG error interrupt.
 * |        |          |Note: This bit is cleared by writing 1, and it has no effect by writing 0.
 * |[22]    |ECCIF     |ECC Finish Interrupt Flag
 * |        |          |0 = No ECC interrupt.
 * |        |          |1 = ECC operation done interrupt.
 * |        |          |Note: This bit is cleared by writing 1, and it has no effect by writing 0.
 * |[23]    |ECCEIF    |ECC Error Flag
 * |        |          |This register includes operating and setting error
 * |        |          |The detail flag is shown in CRYPTO_ECC_STS register.
 * |        |          |0 = No ECC error.
 * |        |          |1 = ECC error interrupt.
 * |        |          |Note: This bit is cleared by writing 1, and it has no effect by writing 0.
 * |[24]    |HMACIF    |SHA/HMAC Finish Interrupt Flag
 * |        |          |0 = No SHA/HMAC interrupt.
 * |        |          |1 = SHA/HMAC operation done interrupt.
 * |        |          |Note: This bit is cleared by writing 1, and it has no effect by writing 0.
 * |[25]    |HMACEIF   |SHA/HMAC Error Flag
 * |        |          |This register includes operating and setting error
 * |        |          |The detail flag is shown in CRYPTO_HMAC_STS register.
 * |        |          |0 = No SHA/HMAC error.
 * |        |          |1 = SHA/HMAC error interrupt.
 * |        |          |Note: This bit is cleared by writing 1, and it has no effect by writing 0.
 * |[30]    |RSAIF     |RSA Finish Interrupt Flag
 * |        |          |0 = No RSA interrupt.
 * |        |          |1 = RSA operation done interrupt.
 * |        |          |Note: This bit is cleared by writing 1, and it has no effect by writing 0.
 * |[31]    |RSAEIF    |RSA Error Interrupt Flag
 * |        |          |This register includes operating and setting error
 * |        |          |The detail flag is shown in CRYPTO_RSA_STS register.
 * |        |          |0 = No RSA error.
 * |        |          |1 = RSA error interrupt.
 * |        |          |Note: This bit is cleared by writing 1, and it has no effect by writing 0.
 * @var CRYPTO_T::PRNG_CTL
 * Offset: 0x08  PRNG Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |START     |Start PRNG Engine
 * |        |          |0 = Stop PRNG engine.
 * |        |          |1 = Generate new key and store the new key to register CRYPTO_PRNG_KEYx, which will be cleared when the new key is generated.
 * |[1]     |SEEDRLD   |Reload New Seed for PRNG Engine
 * |        |          |0 = Generating key based on the current seed.
 * |        |          |1 = Reload new seed.
 * |[5:2]   |KEYSZ     |PRNG Generate Key Size
 * |        |          |0000 = 128 bits.
 * |        |          |0001 = 163 bits.
 * |        |          |0010 = 192 bits.
 * |        |          |0011 = 224 bits.
 * |        |          |0100 = 233 bits.
 * |        |          |0101 = 255 bits.
 * |        |          |0110 = 256 bits.
 * |        |          |0111 = 283 bits (only for Key Store).
 * |        |          |1000 = 384 bits (only for Key Store).
 * |        |          |1001 = 409 bits (only for Key Store).
 * |        |          |1010 = 512 bits (only for Key Store).
 * |        |          |1011 = 521 bits (only for Key Store).
 * |        |          |1100 = 571 bits (only for Key Store).
 * |        |          |others = Reserved.
 * |[8]     |BUSY      |PRNG Busy (Read Only)
 * |        |          |0 = PRNG engine is idle.
 * |        |          |1 = PRNG engine is generating CRYPTO_PRNG_KEYx.
 * @var CRYPTO_T::PRNG_SEED
 * Offset: 0x0C  Seed for PRNG
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SEED      |Seed for PRNG (Write Only)
 * |        |          |The bits store the seed for PRNG engine.
 * @var CRYPTO_T::PRNG_KEY0
 * Offset: 0x10  PRNG Generated Key0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |Store PRNG Generated Key (Read Only)
 * |        |          |The bits store the key that is generated by PRNG.
 * @var CRYPTO_T::PRNG_KEY1
 * Offset: 0x14  PRNG Generated Key1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |Store PRNG Generated Key (Read Only)
 * |        |          |The bits store the key that is generated by PRNG.
 * @var CRYPTO_T::PRNG_KEY2
 * Offset: 0x18  PRNG Generated Key2
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |Store PRNG Generated Key (Read Only)
 * |        |          |The bits store the key that is generated by PRNG.
 * @var CRYPTO_T::PRNG_KEY3
 * Offset: 0x1C  PRNG Generated Key3
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |Store PRNG Generated Key (Read Only)
 * |        |          |The bits store the key that is generated by PRNG.
 * @var CRYPTO_T::PRNG_KEY4
 * Offset: 0x20  PRNG Generated Key4
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |Store PRNG Generated Key (Read Only)
 * |        |          |The bits store the key that is generated by PRNG.
 * @var CRYPTO_T::PRNG_KEY5
 * Offset: 0x24  PRNG Generated Key5
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |Store PRNG Generated Key (Read Only)
 * |        |          |The bits store the key that is generated by PRNG.
 * @var CRYPTO_T::PRNG_KEY6
 * Offset: 0x28  PRNG Generated Key6
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |Store PRNG Generated Key (Read Only)
 * |        |          |The bits store the key that is generated by PRNG.
 * @var CRYPTO_T::PRNG_KEY7
 * Offset: 0x2C  PRNG Generated Key7
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |Store PRNG Generated Key (Read Only)
 * |        |          |The bits store the key that is generated by PRNG.
 * @var CRYPTO_T::PRNG_STS
 * Offset: 0x30  PRNG Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |BUSY      |PRNG Busy Flag
 * |        |          |0 = PRNG engine is idle.
 * |        |          |1 = PRNG engine is generating CRYPTO_PRNG_KEYx.
 * |[17]    |KSERR     |PRNG Access Key Store Error Flag
 * |        |          |0 = No error.
 * |        |          |1 = Access Key Store failed.
 * @var CRYPTO_T::AES_GCM_IVCNT0
 * Offset: 0x80  AES GCM IV Byte Count Register 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CNT       |AES GCM IV Byte Count
 * |        |          |The bit   length of IV is 64 bits for AES GCM mode
 * |        |          |The CRYPTO_AES_GCM_IVCNT0 keeps the low weight byte count of initial vector (i.e., len(IV)[34:3]) of AES GCM mode and can be read and written.
 * @var CRYPTO_T::AES_GCM_IVCNT1
 * Offset: 0x84  AES GCM IV Byte Count Register 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[28:0]  |CNT       |AES GCM IV Byte Count
 * |        |          |The bit   length of IV is 64 bits for AES GCM mode
 * |        |          |The CRYPTO_AES_GCM_IVCNT1 keeps the high weight byte   count of initial vector   (i.e., len(IV)[64:35]) of AES GCM mode and can be read and written.
 * @var CRYPTO_T::AES_GCM_ACNT0
 * Offset: 0x88  AES GCM A Byte Count Register 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CNT       |AES GCM A Byte Count
 * |        |          |The bit   length of A is 64 bits for AES GCM mode
 * |        |          |The CRYPTO_AES_GCM_ACNT0 keeps the low weight byte count of the additional authenticated data (i.e., len(A)[34:3]) of AES GCM mode and can be read and written.
 * @var CRYPTO_T::AES_GCM_ACNT1
 * Offset: 0x8C  AES GCM A Byte Count Register 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[28:0]  |CNT       |AES GCM A Byte Count
 * |        |          |The bit   length of A is 64 bits for AES GCM mode
 * |        |          |The CRYPTO_AES_GCM_ACNT0 keeps the high weight byte   count of the additional authenticated data (i.e., len(A)[63:35]) of AES GCM mode and can be read and written.
 * @var CRYPTO_T::AES_GCM_PCNT0
 * Offset: 0x90  AES GCM P Byte Count Register 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CNT       |AES GCM P Byte Count
 * |        |          |The bit   length of Por C is 39 bits for AES GCM mode
 * |        |          |The CRYPTO_AES_GCM_PCNT0 keeps the low weight byte count of the plaintext or ciphertext (i.e., len(P)[34:3] or   len(C)[34:3]) of AES GCM mode and can be read and written.
 * @var CRYPTO_T::AES_GCM_PCNT1
 * Offset: 0x94  AES GCM P Byte Count Register 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[28:0]  |CNT       |AES GCM P Byte Count
 * |        |          |The bit   length of Por C is 39 bits for AES GCM mode
 * |        |          |The CRYPTO_AES_GCM_PCNT1 keeps the high weight byte   count of the plaintext or ciphertext (i.e.,   len(P)[38:35] or len(C)[38:35]) of   AES GCM mode and can be   read and written.
 * |        |          |The bit   length of Por C is 64 bits for AES CCM mode
 * |        |          |The CRYPTO_AES_GCM_PCNT1 keeps the high weight byte   count of the plaintext or ciphertext (i.e.,   len(P)[63:35] or len(C)[63:35]) of   AES CCM mode and can be   read and written.
 * @var CRYPTO_T::AES_FBADDR
 * Offset: 0xA0  AES DMA Feedback Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |FBADDR    |AES DMA Feedback Address
 * |        |          |In DMA cascade mode, software can update DMA feedback address register for automatically reading and writing feedback values via DMA
 * |        |          |The FBADDR keeps the feedback address of the feedback data for the next cascade operation
 * |        |          |Based on the feedback address, the AES accelerator can read the feedback data of the last cascade operation from system memory space and write the feedback data of the current cascade operation to system memory space
 * |        |          |The start of feedback address should be located at word boundary
 * |        |          |In other words, bit 1 and 0 of FBADDR are ignored.
 * |        |          |FBADDR can be read and written.
 * |        |          |In DMA mode, software can update the next CRYPTO_AES_FBADDR before triggering START.
 * @var CRYPTO_T::AES_CTL
 * Offset: 0x100  AES Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |START     |AES Engine Start
 * |        |          |0 = No effect.
 * |        |          |1 = Start AES engine. BUSY flag will be set.
 * |        |          |Note: This bit is always 0 when it is read back.
 * |[1]     |STOP      |AES Engine Stop
 * |        |          |0 = No effect.
 * |        |          |1 = Stop AES engine.
 * |        |          |Note: This bit is always 0 when it is read back.
 * |[3:2]   |KEYSZ     |AES Key Size
 * |        |          |This bit defines three different key size for AES operation.
 * |        |          |0x0 = 128 bits key.
 * |        |          |0x1 = 192 bits key.
 * |        |          |0x2 = 256 bits key.
 * |        |          |0x3 = Reserved.
 * |        |          |If the AES accelerator is operating and the corresponding flag BUSY is 1, updating this register has no effect.
 * |[5]     |DMALAST   |AES Last Block
 * |        |          |In DMA mode, this bit must be set as beginning the last DMA cascade round.
 * |        |          |In Non-DMA mode, this bit must be set when feeding in the last block of data in ECB, CBC, CTR, OFB, and CFB mode, and feeding in the (last-1) block of data at CBC-CS1, CBC-CS2, and CBC-CS3 mode.
 * |        |          |This bit is always 0 when it is read back, and must be written again once START is triggered.
 * |[6]     |DMACSCAD  |AES Engine DMA with Cascade Mode
 * |        |          |0 = DMA cascade function Disabled.
 * |        |          |1 = In DMA cascade mode, software can update DMA source address register, destination address register, and byte count register during a cascade operation, without finishing the accelerator operation.
 * |        |          |Note: The last two blocks of AES-CBC-CS1/2/3 must be in the last cascade operation.
 * |[7]     |DMAEN     |AES Engine DMA Enable Bit
 * |        |          |0 = AES DMA engine Disabled.
 * |        |          |The AES engine operates in Non-DMA mode. The data need to be written in CRYPTO_AES_DATIN.
 * |        |          |1 = AES_DMA engine Enabled.
 * |        |          |The AES engine operates in DMA mode, and data movement from/to the engine is done by DMA logic.
 * |[15:8]  |OPMODE    |AES Engine Operation Modes
 * |        |          |0x00 = ECB (Electronic Codebook Mode)  0x01 = CBC (Cipher Block Chaining Mode).
 * |        |          |0x02 = CFB (Cipher Feedback Mode).
 * |        |          |0x03 = OFB (Output Feedback Mode).
 * |        |          |0x04 = CTR (Counter Mode).
 * |        |          |0x10 = CBC-CS1 (CBC Ciphertext-Stealing 1 Mode).
 * |        |          |0x11 = CBC-CS2 (CBC Ciphertext-Stealing 2 Mode).
 * |        |          |0x12 = CBC-CS3 (CBC Ciphertext-Stealing 3 Mode).
 * |        |          |0x20 = GCM (Galois/Counter Mode).
 * |        |          |0x21 = GHASH (Galois Hash Function).
 * |        |          |0x22 = CCM (Counter with CBC-MAC Mode).
 * |[16]    |ENCRYPT   |AES Encryption/Decryption
 * |        |          |0 = AES engine executes decryption operation.
 * |        |          |1 = AES engine executes encryption operation.
 * |[20]    |FBIN      |Feedback Input to AES Via DMA Automatically
 * |        |          |0 = DMA automatic feedback input function Disabled.
 * |        |          |1 = DMA automatic feedback input function Enabled when DMAEN = 1.
 * |[21]    |FBOUT     |Feedback Output From AES Via DMA Automatically
 * |        |          |0 = DMA automatic feedback output function Disabled.
 * |        |          |1 = DMA automatic feedback output function Enabled when DMAEN = 1.
 * |[22]    |OUTSWAP   |AES Engine Output Data Swap
 * |        |          |0 = Keep the original order.
 * |        |          |1 = The order that CPU reads data from the accelerator will be changed from {byte3, byte2, byte1, byte0} to {byte0, byte1, byte2, byte3}.
 * |[23]    |INSWAP    |AES Engine Input Data Swap
 * |        |          |0 = Keep the original order.
 * |        |          |1 = The order that CPU feeds data to the accelerator will be changed from {byte3, byte2, byte1, byte0} to {byte0, byte1, byte2, byte3}.
 * |[24]    |KOUTSWAP  |AES Engine Output Key and Initial Vector Swap
 * |        |          |0 = Keep the original order.
 * |        |          |1 = The order that CPU reads key and initial vector from the accelerator will be changed from {byte3, byte2, byte1, byte0} to {byte0, byte1, byte2, byte3}.
 * |[25]    |KINSWAP   |AES Engine Input Key and Initial Vector Swap
 * |        |          |0 = Keep the original order.
 * |        |          |1 = The order that CPU feeds key and initial vector to the accelerator will be changed from {byte3, byte2, byte1, byte0} to {byte0, byte1, byte2, byte3}.
 * |[30:26] |KEYUNPRT  |Unprotect Key
 * |        |          |Writing 0 to CRYPTO_AES_CTL[31] and u201C10110u201D to CRYPTO_AES_CTL[30:26] is to unprotect the AES key.
 * |        |          |The KEYUNPRT can be read and written
 * |        |          |When it is written as the AES engine is operating, BUSY flag is 1, there would be no effect on KEYUNPRT.
 * |[31]    |KEYPRT    |Protect Key
 * |        |          |Read as a flag to reflect KEYPRT.
 * |        |          |0 = No effect.
 * |        |          |1 = Protect the content of the AES key from reading
 * |        |          |The return value for reading CRYPTO_AES_KEYx is not the content of the registers CRYPTO_AES_KEYx
 * |        |          |Once it is set, it can be cleared by asserting KEYUNPRT
 * |        |          |The key content would be cleared as well.
 * @var CRYPTO_T::AES_STS
 * Offset: 0x104  AES Engine Flag
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |BUSY      |AES Engine Busy
 * |        |          |0 = The AES engine is idle or finished.
 * |        |          |1 = The AES engine is under processing.
 * |[8]     |INBUFEMPTY|AES Input Buffer Empty
 * |        |          |0 = There are some data in input buffer waiting for the AES engine to process.
 * |        |          |1 = AES input buffer is empty
 * |        |          |Software needs to feed data to the AES engine
 * |        |          |Otherwise, the AES engine will be pending to wait for input data.
 * |[9]     |INBUFFULL |AES Input Buffer Full Flag
 * |        |          |0 = AES input buffer is not full. Software can feed the data into the AES engine.
 * |        |          |1 = AES input buffer is full
 * |        |          |Software cannot feed data to the AES engine
 * |        |          |Otherwise, the flag INBUFERR will be set to 1.
 * |[10]    |INBUFERR  |AES Input Buffer Error Flag
 * |        |          |0 = No error.
 * |        |          |1 = Error happened during feeding data to the AES engine.
 * |[12]    |CNTERR    |CRYPTO_AES_CNT Setting Error
 * |        |          |0 = No error in CRYPTO_AES_CNT setting.
 * |        |          |1 = CRYPTO_AES_CNT is 0 if DMAEN (CRYPTO_AES_CTL[7]) is enabled.
 * |[16]    |OUTBUFEMPTY|AES Out Buffer Empty
 * |        |          |0 = AES output buffer is not empty. There are some valid data kept in output buffer.
 * |        |          |1 = AES output buffer is empty
 * |        |          |Software cannot get data from CRYPTO_AES_DATOUT
 * |        |          |Otherwise, the flag OUTBUFERR will be set to 1 since the output buffer is empty.
 * |[17]    |OUTBUFFULL|AES Out Buffer Full Flag
 * |        |          |0 = AES output buffer is not full.
 * |        |          |1 = AES output buffer is full, and software needs to get data from CRYPTO_AES_DATOUT
 * |        |          |Otherwise, the AES engine will be pending since the output buffer is full.
 * |[18]    |OUTBUFERR |AES Out Buffer Error Flag
 * |        |          |0 = No error.
 * |        |          |1 = Error happened during getting the result from AES engine.
 * |[20]    |BUSERR    |AES DMA Access Bus Error Flag
 * |        |          |0 = No error.
 * |        |          |1 = Bus error will stop DMA operation and AES engine.
 * |[21]    |KSERR     |AES Engine Access Key Store Error Flag
 * |        |          |0 = No error.
 * |        |          |1 = Key Store access error will stop AES engine.
 * @var CRYPTO_T::AES_DATIN
 * Offset: 0x108  AES Engine Data Input Port Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DATIN     |AES Engine Input Port
 * |        |          |CPU feeds data to AES engine through this port by checking CRYPTO_AES_STS. Feed data as INBUFFULL is 0.
 * @var CRYPTO_T::AES_DATOUT
 * Offset: 0x10C  AES Engine Data Output Port Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DATOUT    |AES Engine Output Port
 * |        |          |CPU gets results from the AES engine through this port by checking CRYPTO_AES_STS
 * |        |          |Get data as OUTBUFEMPTY is 0.
 * @var CRYPTO_T::AES_KEY0
 * Offset: 0x110  AES Key Word 0 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |CRYPTO_AES_KEYx
 * |        |          |The KEY keeps the security key for AES operation.
 * |        |          |x = 0, 1..7.
 * |        |          |The security key for AES accelerator can be 128, 192, or 256 bits and four, six, or eight 32-bit registers are to store each security key.
 * |        |          |{CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 128-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 192-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY7, CRYPTO_AES_KEY6, CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 256-bit security key for AES operation.
 * @var CRYPTO_T::AES_KEY1
 * Offset: 0x114  AES Key Word 1 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |CRYPTO_AES_KEYx
 * |        |          |The KEY keeps the security key for AES operation.
 * |        |          |x = 0, 1..7.
 * |        |          |The security key for AES accelerator can be 128, 192, or 256 bits and four, six, or eight 32-bit registers are to store each security key.
 * |        |          |{CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 128-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 192-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY7, CRYPTO_AES_KEY6, CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 256-bit security key for AES operation.
 * @var CRYPTO_T::AES_KEY2
 * Offset: 0x118  AES Key Word 2 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |CRYPTO_AES_KEYx
 * |        |          |The KEY keeps the security key for AES operation.
 * |        |          |x = 0, 1..7.
 * |        |          |The security key for AES accelerator can be 128, 192, or 256 bits and four, six, or eight 32-bit registers are to store each security key.
 * |        |          |{CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 128-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 192-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY7, CRYPTO_AES_KEY6, CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 256-bit security key for AES operation.
 * @var CRYPTO_T::AES_KEY3
 * Offset: 0x11C  AES Key Word 3 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |CRYPTO_AES_KEYx
 * |        |          |The KEY keeps the security key for AES operation.
 * |        |          |x = 0, 1..7.
 * |        |          |The security key for AES accelerator can be 128, 192, or 256 bits and four, six, or eight 32-bit registers are to store each security key.
 * |        |          |{CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 128-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 192-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY7, CRYPTO_AES_KEY6, CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 256-bit security key for AES operation.
 * @var CRYPTO_T::AES_KEY4
 * Offset: 0x120  AES Key Word 4 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |CRYPTO_AES_KEYx
 * |        |          |The KEY keeps the security key for AES operation.
 * |        |          |x = 0, 1..7.
 * |        |          |The security key for AES accelerator can be 128, 192, or 256 bits and four, six, or eight 32-bit registers are to store each security key.
 * |        |          |{CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 128-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 192-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY7, CRYPTO_AES_KEY6, CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 256-bit security key for AES operation.
 * @var CRYPTO_T::AES_KEY5
 * Offset: 0x124  AES Key Word 5 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |CRYPTO_AES_KEYx
 * |        |          |The KEY keeps the security key for AES operation.
 * |        |          |x = 0, 1..7.
 * |        |          |The security key for AES accelerator can be 128, 192, or 256 bits and four, six, or eight 32-bit registers are to store each security key.
 * |        |          |{CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 128-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 192-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY7, CRYPTO_AES_KEY6, CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 256-bit security key for AES operation.
 * @var CRYPTO_T::AES_KEY6
 * Offset: 0x128  AES Key Word 6 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |CRYPTO_AES_KEYx
 * |        |          |The KEY keeps the security key for AES operation.
 * |        |          |x = 0, 1..7.
 * |        |          |The security key for AES accelerator can be 128, 192, or 256 bits and four, six, or eight 32-bit registers are to store each security key.
 * |        |          |{CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 128-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 192-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY7, CRYPTO_AES_KEY6, CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 256-bit security key for AES operation.
 * @var CRYPTO_T::AES_KEY7
 * Offset: 0x12C  AES Key Word 7 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEY       |CRYPTO_AES_KEYx
 * |        |          |The KEY keeps the security key for AES operation.
 * |        |          |x = 0, 1..7.
 * |        |          |The security key for AES accelerator can be 128, 192, or 256 bits and four, six, or eight 32-bit registers are to store each security key.
 * |        |          |{CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 128-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 192-bit security key for AES operation.
 * |        |          |{CRYPTO_AES_KEY7, CRYPTO_AES_KEY6, CRYPTO_AES_KEY5, CRYPTO_AES_KEY4, CRYPTO_AES_KEY3, CRYPTO_AES_KEY2, CRYPTO_AES_KEY1, CRYPTO_AES_KEY0} stores the 256-bit security key for AES operation.
 * @var CRYPTO_T::AES_IV0
 * Offset: 0x130  AES Initial Vector Word 0 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |IV        |AES Initial Vectors
 * |        |          |x = 0, 1..3.
 * |        |          |Four initial vectors (CRYPTO_AES_IV0, CRYPTO_AES_IV1, CRYPTO_AES_IV2, and CRYPTO_AES_IV3) are for AES operating in CBC, CFB, and OFB mode
 * |        |          |Four registers (CRYPTO_AES_IV0, CRYPTO_AES_IV1, CRYPTO_AES_IV2, and CRYPTO_AES_IV3) act as Nonce counter when the AES engine is operating in CTR mode.
 * @var CRYPTO_T::AES_IV1
 * Offset: 0x134  AES Initial Vector Word 1 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |IV        |AES Initial Vectors
 * |        |          |x = 0, 1..3.
 * |        |          |Four initial vectors (CRYPTO_AES_IV0, CRYPTO_AES_IV1, CRYPTO_AES_IV2, and CRYPTO_AES_IV3) are for AES operating in CBC, CFB, and OFB mode
 * |        |          |Four registers (CRYPTO_AES_IV0, CRYPTO_AES_IV1, CRYPTO_AES_IV2, and CRYPTO_AES_IV3) act as Nonce counter when the AES engine is operating in CTR mode.
 * @var CRYPTO_T::AES_IV2
 * Offset: 0x138  AES Initial Vector Word 2 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |IV        |AES Initial Vectors
 * |        |          |x = 0, 1..3.
 * |        |          |Four initial vectors (CRYPTO_AES_IV0, CRYPTO_AES_IV1, CRYPTO_AES_IV2, and CRYPTO_AES_IV3) are for AES operating in CBC, CFB, and OFB mode
 * |        |          |Four registers (CRYPTO_AES_IV0, CRYPTO_AES_IV1, CRYPTO_AES_IV2, and CRYPTO_AES_IV3) act as Nonce counter when the AES engine is operating in CTR mode.
 * @var CRYPTO_T::AES_IV3
 * Offset: 0x13C  AES Initial Vector Word 3 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |IV        |AES Initial Vectors
 * |        |          |x = 0, 1..3.
 * |        |          |Four initial vectors (CRYPTO_AES_IV0, CRYPTO_AES_IV1, CRYPTO_AES_IV2, and CRYPTO_AES_IV3) are for AES operating in CBC, CFB, and OFB mode
 * |        |          |Four registers (CRYPTO_AES_IV0, CRYPTO_AES_IV1, CRYPTO_AES_IV2, and CRYPTO_AES_IV3) act as Nonce counter when the AES engine is operating in CTR mode.
 * @var CRYPTO_T::AES_SADDR
 * Offset: 0x140  AES DMA Source Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SADDR     |AES DMA Source Address
 * |        |          |The AES accelerator supports DMA function to transfer the plain text between system memory space and embedded FIFO
 * |        |          |The SADDR keeps the source address of the data buffer where the source text is stored
 * |        |          |Based on the source address, the AES accelerator can read the plain text (encryption) / cipher text (decryption) from system memory space and do AES operation
 * |        |          |The start of source address should be located at word boundary
 * |        |          |In other words, bit 1 and 0 of SADDR are ignored.
 * |        |          |SADDR can be read and written
 * |        |          |Writing to SADDR while the AES accelerator is operating doesnu2019t affect the current AES operation
 * |        |          |But the value of SADDR will be updated later on
 * |        |          |Consequently, software can prepare the DMA source address for the next AES operation.
 * |        |          |In DMA mode, software can update the next CRYPTO_AES_SADDR before triggering START.
 * |        |          |The value of CRYPTO_AES_SADDR and CRYPTO_AES_DADDR can be the same.
 * @var CRYPTO_T::AES_DADDR
 * Offset: 0x144  AES DMA Destination Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DADDR     |AES DMA Destination Address
 * |        |          |The AES accelerator supports DMA function to transfer the cipher text between system memory space and embedded FIFO
 * |        |          |The DADDR keeps the destination address of the data buffer where the engine outputu2019s text will be stored
 * |        |          |Based on the destination address, the AES accelerator can write the cipher text (encryption) / plain text (decryption) back to system memory space after the AES operation is finished
 * |        |          |The start of destination address should be located at word boundary
 * |        |          |In other words, bit 1 and 0 of DADDR are ignored.
 * |        |          |DADDR can be read and written
 * |        |          |Writing to DADDR while the AES accelerator is operating doesnu2019t affect the current AES operation
 * |        |          |But the value of DADDR will be updated later on
 * |        |          |Consequently, software can prepare the destination address for the next AES operation.
 * |        |          |In DMA mode, software can update the next CRYPTO_AES_DADDR before triggering START.
 * |        |          |The value of CRYPTO_AES_SADDR and CRYPTO_AES_DADDR can be the same.
 * @var CRYPTO_T::AES_CNT
 * Offset: 0x148  AES Byte Count Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CNT       |AES   Byte Count
 * |        |          |The   CRYPTO_AES_CNT keeps the byte count of source text that is for the AES engine   operating in DMA mode
 * |        |          |The CRYPTO_AES_CNT is 32-bit and the maximum of byte   count is 4G bytes.
 * |        |          |CRYPTO_AES_CNT   can be read and written
 * |        |          |Writing to CRYPTO_AES_CNT while the AES accelerator   is operating doesnu2019t affect the current AES operation
 * |        |          |But the value of   CRYPTO_AES_CNT will be updated later on
 * |        |          |Consequently, software can prepare   the byte count of data for the next AES operation.
 * |        |          |According   to CBC-CS1, CBC-CS2, and CBC-CS3 standard, the count of operation data must   be more than 16 bytes
 * |        |          |Operations that are qual to or less than one block   will output unexpected result.
 * |        |          |In   Non-DMA ECB, CBC, CFB, OFB, CTR, CCM and GCM mode, CRYPTO_AES_CNT must be set as byte count for the   last block of data before feeding in the last block of data
 * |        |          |In Non-DMA   CBC-CS1, CBC-CS2, and CBC-CS3 mode, CRYPTO_AES_CNT must be set as byte count   for the last two blocks of data before feeding in the last two blocks of   data.
 * |        |          |In AES   GCM mode without DMA cascade function, the value of CRYPTO_AES_CNT is equal to the total value of {CRYPTO_AES_GCM_IVCNT1,   CRYPTO_AES_GCM_IVCNT0}, {CRYPTO_AES_GCM_ACNT1, CRYPTO_AES_GCM_ACNT0} and {CRYPTO_AES_GCM_PCNT1,   CRYPTO_AES_GCM_PCNT0}.
 * |        |          |In AES   GCM mode with DMA cascade function, the value of CRYPTO_AES_CNT represents the byte count of source text in this cascade function
 * |        |          |Thus, the value of CRYPTO_AES_CNT is less than or equal to the total value of {CRYPTO_AES_GCM_IVCNT1,   CRYPTO_AES_GCM_IVCNT0}, {CRYPTO_AES_GCM_ACNT1, CRYPTO_AES_GCM_ACNT0} and {CRYPTO_AES_GCM_PCNT1,   CRYPTO_AES_GCM_PCNT0} and must be block alignment.
 * |        |          |In AES CCM   mode without DMA cascade function, the value of CRYPTO_AES_CNT is equal to the total value of {CRYPTO_AES_GCM_ACNT1,   CRYPTO_AES_GCM_ACNT0} and {CRYPTO_AES_GCM_PCNT1, CRYPTO_AES_GCM_PCNT0}.
 * |        |          |In AES   CCM mode with DMA cascade function, the value of CRYPTO_AES_CNT represents the byte count of source text in this cascade function
 * |        |          |Thus, the value of CRYPTO_AES_CNT is less than or equal to the total value of {CRYPTO_AES_GCM_ACNT1,   CRYPTO_AES_GCM_ACNT0} and {CRYPTO_AES_GCM_PCNT1, CRYPTO_AES_GCM_PCNT0} and   must be block alignment, except for the last block of plaintext or   ciphertext.
 * @var CRYPTO_T::HMAC_CTL
 * Offset: 0x300  SHA/HMAC Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |START     |SHA/HMAC Engine Start
 * |        |          |0 = No effect.
 * |        |          |1 = Start SHA/HMAC engine. BUSY flag will be set.
 * |        |          |Note: This bit is always 0 when it is read back.
 * |[1]     |STOP      |SHA/HMAC Engine Stop
 * |        |          |0 = No effect.
 * |        |          |1 = Stop SHA/HMAC engine.
 * |        |          |Note: This bit is always 0 when it is read back.
 * |[4]     |DMAFIRST  |SHA/HMAC First Block in Cascade function
 * |        |          |This bit must be set as feeding in first byte of data.
 * |[5]     |DMALAST   |SHA/HMAC Last Block
 * |        |          |This bit must be set as feeding in last byte of data.
 * |[6]     |DMACSCAD  |SHA/HMAC Engine DMA with Cascade Mode
 * |        |          |0 = DMA cascade function Disabled.
 * |        |          |1 = In DMA cascade mode, software can update DMA source address register, destination address register, and byte count register during a cascade operation, without finishing the accelerator operation.
 * |[7]     |DMAEN     |SHA/HMAC Engine DMA Enable Bit
 * |        |          |0 = SHA/HMAC DMA engine Disabled.
 * |        |          |SHA/HMAC engine operates in Non-DMA mode. The data need to be written in CRYPTO_HMAC_DATIN.
 * |        |          |1 = SHA/HMAC DMA engine Enabled.
 * |        |          |SHA/HMAC engine operates in DMA mode, and data movement from/to the engine is done by DMA logic.
 * |[10:8]  |OPMODE    |SHA/HMAC Engine Operation Modes
 * |        |          |When SHA3EN=0,.
 * |        |          |0x0xx: SHA1-160
 * |        |          |0x100: SHA2-256
 * |        |          |0x101: SHA2-224
 * |        |          |0x110: SHA2-512
 * |        |          |0x111: SHA2-384
 * |        |          |When SHA3EN=1,.
 * |        |          |0x100: SHA3-256
 * |        |          |0x101: SHA3-224
 * |        |          |0x110: SHA3-512
 * |        |          |0x111: SHA3-384
 * |        |          |0x000: SHAKE128
 * |        |          |0x001: SHAKE256
 * |        |          |Note: These bits can be read and written. But writing to them wouldnu2019t take effect as BUSY is 1.
 * |        |          |Note: When MD5EN=1, SHA/HMAC only execute MD5 and then generate 128 bits digest.
 * |[11]    |HMACEN    |HMAC_SHA Engine Operating Mode
 * |        |          |0 = Execute SHA function.
 * |        |          |1 = Execute HMAC function.
 * |[12]    |SHA3EN    |SHA3 Engine Enable Bit
 * |        |          |0 = Execute other function.
 * |        |          |1 = Execute SHA3 function.
 * |[14]    |MD5EN     |MD5 Engine Enable Bit
 * |        |          |0 = Execute other function.
 * |        |          |1 = Execute MD5 function if SHA3EN=0.
 * |[20]    |FBIN      |Feedback Input to SHA/HMAC Via DMA Automatically
 * |        |          |0 = DMA automatic feedback input function Disabled.
 * |        |          |1 = DMA automatic feedback input function Enabled when DMAEN = 1.
 * |[21]    |FBOUT     |Feedback Output From SHA/HMAC Via DMA Automatically
 * |        |          |0 = DMA automatic feedback output function Disabled.
 * |        |          |1 = DMA automatic feedback output function Enabled when DMAEN = 1.
 * |[22]    |OUTSWAP   |SHA/HMAC Engine Output Data Swap
 * |        |          |0 = Keep the original order.
 * |        |          |1 = The order that CPU feeds data to the accelerator will be changed from {byte3, byte2, byte1, byte0} to {byte0, byte1, byte2, byte3}.
 * |[23]    |INSWAP    |SHA/HMAC Engine Input Data Swap
 * |        |          |0 = Keep the original order.
 * |        |          |1 = The order that CPU feeds data to the accelerator will be changed from {byte3, byte2, byte1, byte0} to {byte0, byte1, byte2, byte3}.
 * |[24]    |NEXTDGST  |SHAKE128/256 Next Digest Start
 * |        |          |0 = No effect.
 * |        |          |1 = Start SHAKE engine to generate the next digest only when SHAKEBUSY is 0
 * |        |          |BUSY and SHAKEBUSY flag will be set.
 * |[25]    |FINISHDGST|SHAKE128/256 Next Digest Finish
 * |        |          |0 = No effect.
 * |        |          |1 = finish generating the next digest.
 * @var CRYPTO_T::HMAC_STS
 * Offset: 0x304  SHA/HMAC Status Flag
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |BUSY      |SHA/HMAC Engine Busy
 * |        |          |0 = SHA/HMAC engine is idle or finished.
 * |        |          |1 = SHA/HMAC engine is busy.
 * |[1]     |DMABUSY   |SHA/HMAC Engine DMA Busy Flag
 * |        |          |0 = SHA/HMAC DMA engine is idle or finished.
 * |        |          |1 = SHA/HMAC DMA engine is busy.
 * |[2]     |SHAKEBUSY |SHAKE Engine Busy Flag
 * |        |          |0 = SHAKE engine is idle or finished.
 * |        |          |1 = SHAKE engine is busy.
 * |[8]     |DMAERR    |SHA/HMAC Engine DMA Error Flag
 * |        |          |0 = Show the SHA/HMAC engine access normal.
 * |        |          |1 = Show the SHA/HMAC engine access error.
 * |[9]     |KSERR     |HMAC Engine Access Key Store Error Flag
 * |        |          |0 = No error.
 * |        |          |1 = Access error will stop HMAC engine.
 * |[16]    |DATINREQ  |SHA/HMAC Non-DMA Mode Data Input Request
 * |        |          |0 = No effect.
 * |        |          |1 = Request SHA/HMAC Non-DMA mode data input.
 * @var CRYPTO_T::HMAC_DGST0
 * Offset: 0x308  SHA/HMAC Output Digest Data 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_DGST1
 * Offset: 0x30C  SHA/HMAC Output Digest Data 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_DGST2
 * Offset: 0x310  SHA/HMAC Output Digest Data 2
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_DGST3
 * Offset: 0x314  SHA/HMAC Output Digest Data 3
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_DGST4
 * Offset: 0x318  SHA/HMAC Output Digest Data 4
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_DGST5
 * Offset: 0x31C  SHA/HMAC Output Digest Data 5
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_DGST6
 * Offset: 0x320  SHA/HMAC Output Digest Data 6
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_DGST7
 * Offset: 0x324  SHA/HMAC Output Digest Data 7
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_DGST8
 * Offset: 0x328  SHA/HMAC Output Digest Data 8
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_DGST9
 * Offset: 0x32C  SHA/HMAC Output Digest Data 9
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_DGST10
 * Offset: 0x330  SHA/HMAC Output Digest Data 10
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_DGST11
 * Offset: 0x334  SHA/HMAC Output Digest Data 11
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_DGST12
 * Offset: 0x338  SHA/HMAC Output Digest Data 12
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_DGST13
 * Offset: 0x33C  SHA/HMAC Output Digest Data 13
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_DGST14
 * Offset: 0x340  SHA/HMAC Output Digest Data 14
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_DGST15
 * Offset: 0x344  SHA/HMAC Output Digest Data 15
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC Output Digest Data Register
 * |        |          |For SHA-160, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST4.
 * |        |          |For SHA-224, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST6.
 * |        |          |For SHA-256, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST7.
 * |        |          |For SHA-384, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST11.
 * |        |          |For SHA-512, the digest is stored in CRYPTO_HMAC_DGST0 ~ CRYPTO_HMAC_DGST15.
 * @var CRYPTO_T::HMAC_KEYCNT
 * Offset: 0x348  SHA/HMAC Key Byte Count Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |KEYCNT    |SHA/HMAC Key Byte Count
 * |        |          |The CRYPTO_HMAC_KEYCNT keeps the byte count of key that SHA/HMAC engine operates
 * |        |          |The register is 32-bit and the maximum byte count is 4G bytes
 * |        |          |It can be read and written.
 * |        |          |Writing to the register CRYPTO_HMAC_KEYCNT as the SHA/HMAC accelerator operating doesnu2019t affect the current SHA/HMAC operation
 * |        |          |But the value of CRYPTO_HMAC_KEYCNT will be updated later on
 * |        |          |Consequently, software can prepare the key count for the next SHA/HMAC operation.
 * @var CRYPTO_T::HMAC_SADDR
 * Offset: 0x34C  SHA/HMAC DMA Source Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SADDR     |SHA/HMAC DMA Source Address
 * |        |          |The SHA/HMAC accelerator supports DMA function to transfer the plain text between system memory space and embedded FIFO
 * |        |          |The CRYPTO_HMAC_SADDR keeps the source address of the data buffer where the source text is stored
 * |        |          |Based on the source address, the SHA/HMAC accelerator can read the plain text from system memory space and do SHA/HMAC operation
 * |        |          |The start of source address should be located at word boundary
 * |        |          |In other words, bit 1 and 0 of CRYPTO_HMAC_SADDR are ignored.
 * |        |          |CRYPTO_HMAC_SADDR can be read and written
 * |        |          |Writing to CRYPTO_HMAC_SADDR while the SHA/HMAC accelerator is operating doesnu2019t affect the current SHA/HMAC operation
 * |        |          |But the value of CRYPTO_HMAC_SADDR will be updated later on
 * |        |          |Consequently, software can prepare the DMA source address for the next SHA/HMAC operation.
 * |        |          |In DMA mode, software can update the next CRYPTO_HMAC_SADDR before triggering START.
 * |        |          |CRYPTO_HMAC_SADDR and CRYPTO_HMAC_DADDR can be the same in the value.
 * @var CRYPTO_T::HMAC_DMACNT
 * Offset: 0x350  SHA/HMAC Byte Count Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DMACNT    |SHA/HMAC Operation Byte Count
 * |        |          |The CRYPTO_HMAC_DMACNT keeps the byte count of source text that is for the SHA/HMAC engine operating in DMA mode
 * |        |          |The CRYPTO_HMAC_DMACNT is 32-bit and the maximum of byte count is 4G bytes.
 * |        |          |CRYPTO_HMAC_DMACNT can be read and written
 * |        |          |Writing to CRYPTO_HMAC_DMACNT while the SHA/HMAC accelerator is operating doesnu2019t affect the current SHA/HMAC operation
 * |        |          |But the value of CRYPTO_HMAC_DMACNT will be updated later on
 * |        |          |Consequently, software can prepare the byte count of data for the next SHA/HMAC operation.
 * |        |          |In Non-DMA mode, CRYPTO_HMAC_DMACNT must be set as the byte count of the last block before feeding in the last block of data.
 * @var CRYPTO_T::HMAC_DATIN
 * Offset: 0x354  SHA/HMAC Engine Non-DMA Mode Data Input Port Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DATIN     |SHA/HMAC Engine Input Port
 * |        |          |CPU feeds data to SHA/HMAC engine through this port by checking CRYPTO_HMAC_STS
 * |        |          |Feed data as DATINREQ is 1.
 * @var CRYPTO_T::HMAC_DOMCNT
 * Offset: 0x358  SHA/HMAC DOM Byte Count Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[8:0]   |DOMCNT    |SHA/HMAC DOM Byte Count
 * |        |          |The CRYPTO_HMAC_DOMCNT keeps the byte count of DOM2 or DOM4 in EdDSA that is for the SHA/HMAC engine operating the r generation of EdDSA SignGen with KS in DMA mode
 * |        |          |The CRYPTO_HMAC_DOMCNT is 9-bit and the maximum of byte count is 512 bytes.
 * |        |          |CRYPTO_HMAC_DOMCNT can be read and written
 * |        |          |Writing to CRYPTO_HMAC_DOMCNT while the SHA/HMAC accelerator is operating doesnu2019t affect the current SHA/HMAC operation
 * |        |          |But the value of CRYPTO_HMAC_DOMCNT will be updated later on
 * |        |          |Consequently, software can prepare the byte count of data for the next SHA/HMAC operation.
 * @var CRYPTO_T::HMAC_SHA512T
 * Offset: 0x4F8  SHA/HMAC SHA512/t Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |SHA512TEN |SHA512/t Engine Enable Bit
 * |        |          |0 = Execute other function.
 * |        |          |1 = Execute SHA512/t function if SHA3EN=0 and MD5EN=0.
 * |        |          |Note: When SHA512TEN=1, SHA/HMAC only execute SHA2-512.
 * |[16:8]  |TLEN      |SHA512/t Output Digest Length
 * |        |          |The TLEN is equal to value t of SHA512/t. It also means the output digest length of SHA512 /t.
 * |        |          |Note: TLEN < 512, and TLEN is not 384
 * @var CRYPTO_T::HMAC_FBADDR
 * Offset: 0x4FC  SHA/HMAC DMA Feedback Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |FBADDR    |SHA/HMAC DMA Feedback Address
 * |        |          |In DMA cascade mode, software can update DMA feedback address register for automatically reading and writing feedback values via DMA
 * |        |          |The FBADDR keeps the feedback address of the feedback data for the next cascade operation
 * |        |          |Based on the feedback address, the SHA/HMAC accelerator can read the feedback data of the last cascade operation from system memory space and write the feedback data of the current cascade operation to system memory space
 * |        |          |The start of feedback address should be located at word boundary
 * |        |          |In other words, bit 1 and 0 of FBADDR are ignored.
 * |        |          |FBADDR can be read and written.
 * |        |          |In DMA mode, software can update the next CRYPTO_HMAC_FBADDR before triggering START.
 * @var CRYPTO_T::HMAC_SHAKEDGST0
 * Offset: 0x500  SHA/HMAC SHAKE Digest Message 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST1
 * Offset: 0x504  SHA/HMAC SHAKE Digest Message 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST2
 * Offset: 0x508  SHA/HMAC SHAKE Digest Message 2
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST3
 * Offset: 0x50C  SHA/HMAC SHAKE Digest Message 3
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST4
 * Offset: 0x510  SHA/HMAC SHAKE Digest Message 4
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST5
 * Offset: 0x514  SHA/HMAC SHAKE Digest Message 5
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST6
 * Offset: 0x518  SHA/HMAC SHAKE Digest Message 6
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST7
 * Offset: 0x51C  SHA/HMAC SHAKE Digest Message 7
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST8
 * Offset: 0x520  SHA/HMAC SHAKE Digest Message 8
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST9
 * Offset: 0x524  SHA/HMAC SHAKE Digest Message 9
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST10
 * Offset: 0x528  SHA/HMAC SHAKE Digest Message 10
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST11
 * Offset: 0x52C  SHA/HMAC SHAKE Digest Message 11
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST12
 * Offset: 0x530  SHA/HMAC SHAKE Digest Message 12
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST13
 * Offset: 0x534  SHA/HMAC SHAKE Digest Message 13
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST14
 * Offset: 0x538  SHA/HMAC SHAKE Digest Message 14
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST15
 * Offset: 0x53C  SHA/HMAC SHAKE Digest Message 15
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST16
 * Offset: 0x540  SHA/HMAC SHAKE Digest Message 16
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST17
 * Offset: 0x544  SHA/HMAC SHAKE Digest Message 17
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST18
 * Offset: 0x548  SHA/HMAC SHAKE Digest Message 18
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST19
 * Offset: 0x54C  SHA/HMAC SHAKE Digest Message 19
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST20
 * Offset: 0x550  SHA/HMAC SHAKE Digest Message 20
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST21
 * Offset: 0x554  SHA/HMAC SHAKE Digest Message 21
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST22
 * Offset: 0x558  SHA/HMAC SHAKE Digest Message 22
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST23
 * Offset: 0x55C  SHA/HMAC SHAKE Digest Message 23
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST24
 * Offset: 0x560  SHA/HMAC SHAKE Digest Message 24
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST25
 * Offset: 0x564  SHA/HMAC SHAKE Digest Message 25
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST26
 * Offset: 0x568  SHA/HMAC SHAKE Digest Message 26
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST27
 * Offset: 0x56C  SHA/HMAC SHAKE Digest Message 27
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST28
 * Offset: 0x570  SHA/HMAC SHAKE Digest Message 28
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST29
 * Offset: 0x574  SHA/HMAC SHAKE Digest Message 29
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST30
 * Offset: 0x578  SHA/HMAC SHAKE Digest Message 30
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST31
 * Offset: 0x57C  SHA/HMAC SHAKE Digest Message 31
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST32
 * Offset: 0x580  SHA/HMAC SHAKE Digest Message 32
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST33
 * Offset: 0x584  SHA/HMAC SHAKE Digest Message 33
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST34
 * Offset: 0x588  SHA/HMAC SHAKE Digest Message 34
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST35
 * Offset: 0x58C  SHA/HMAC SHAKE Digest Message 35
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST36
 * Offset: 0x590  SHA/HMAC SHAKE Digest Message 36
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST37
 * Offset: 0x594  SHA/HMAC SHAKE Digest Message 37
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST38
 * Offset: 0x598  SHA/HMAC SHAKE Digest Message 38
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST39
 * Offset: 0x59C  SHA/HMAC SHAKE Digest Message 39
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST40
 * Offset: 0x5A0  SHA/HMAC SHAKE Digest Message 40
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::HMAC_SHAKEDGST41
 * Offset: 0x5A4  SHA/HMAC SHAKE Digest Message 41
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DGST      |SHA/HMAC SHAKE Digest Message Register
 * |        |          |For SHAKE-128, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 41.
 * |        |          |For SHAKE-256, the digest is stored in CRYPTO_HMAC_SHAKEDGST0 0 ~ CRYPTO_HMAC_ SHAKEDGST0 33.
 * @var CRYPTO_T::ECC_CTL
 * Offset: 0x800  ECC Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |START     |ECC Accelerator Start
 * |        |          |0 = No effect.
 * |        |          |1 = Start ECC accelerator. BUSY flag will be set.
 * |        |          |This bit is always 0 when it is read back.
 * |        |          |ECC accelerator will ignore this START signal when BUSY flag is 1.
 * |[1]     |STOP      |ECC Accelerator Stop
 * |        |          |0 = No effect.
 * |        |          |1 = Abort ECC accelerator and make it into idle state.
 * |        |          |This bit is always 0 when it is read back.
 * |        |          |Remember to clear ECC interrupt flag after stopping ECC accelerator.
 * |[2]     |SMOD      |Special Modulus Operation in Prime Field
 * |        |          |0 = Normal modulus operation.
 * |        |          |1 = Special modulus operation.
 * |[4]     |ECDSAS    |Generate S in ECDSA Signature Generation
 * |        |          |0 = No effect.
 * |        |          |1 = Formula for generating S.
 * |        |          |POINTX1 = ((POINTX2 * POINTY1 + POINTY2 ) / POINTX1) % CURVEN when SPCEN is not 1 or SPCSEL is not 1 in ECDSA.
 * |        |          |POINTX1 = (((POINTY1[543:0]*2544 + POINTX1[543:0]) % CURVEN) * POINTX2 + POINTY2) % CURVEN when SPCEN is 1 and SPCSEL is 1 in EdDSA.
 * |[5]     |ECDSAR    |Generate R in ECDSA Signature Generation
 * |        |          |0 = No effect.
 * |        |          |1 = Formula for generating R.
 * |        |          |(POINTX1, POINTY1) = SCALARK * (POINTX1, POINTY1).
 * |[7]     |DMAEN     |ECC Accelerator DMA Enable Bit
 * |        |          |0 = ECC DMA engine Disabled.
 * |        |          |1 = ECC DMA engine Enabled.
 * |        |          |Only when START and DMAEN are 1, ECC DMA engine will be active.
 * |[8]     |FSEL      |Field Selection
 * |        |          |0 = Binary Field (GF(2m )).
 * |        |          |1 = Prime Field (GF(p)).
 * |[10:9]  |ECCOP     |Point Operation for BF and PF
 * |        |          |00 = Point multiplication:.
 * |        |          |(POINTX1, POINTY1) = SCALARK * (POINTX1, POINTY1).
 * |        |          |01 = Modulus operation: choose by MODOP (CRYPTO_ECC_CTL[12:11]).
 * |        |          |10 = Point addition:.
 * |        |          |(POINTX1, POINTY1) = (POINTX1, POINTY1) +.
 * |        |          |(POINTX2, POINTY2)
 * |        |          |11 = Point doubling:.
 * |        |          |(POINTX1, POINTY1) = 2 * (POINTX1, POINTY1).
 * |        |          |Besides above three input data, point operations still need the parameters of elliptic curve (CURVEA, CURVEB, CURVEN and CURVEM) as shown in Figure 6.27-11
 * |[12:11] |MODOP     |Modulus Operation for PF
 * |        |          |When SMOD is 0,
 * |        |          |00 = Division:.
 * |        |          |POINTX1 = (POINTY1 / POINTX1) % CURVEN.
 * |        |          |01 = Multiplication:.
 * |        |          |POINTX1 = (POINTX1 * POINTY1) % CURVEN.
 * |        |          |10 = Addition:.
 * |        |          |POINTX1 = (POINTX1 + POINTY1) % CURVEN.
 * |        |          |11 = Subtraction:.
 * |        |          |POINTX1 = (POINTX1 - POINTY1) % CURVEN.
 * |        |          |When SMOD is 1,
 * |        |          |00 = Modulo:.
 * |        |          |POINTX1 = (POINTY1[543:0]*2544 + POINTX1[543:0]) % CURVEN.
 * |        |          |01 = Exponential:.
 * |        |          |POINTX1 = (POINTX1(SCALARK)) % CURVEN.
 * |        |          |10 = Square root:.
 * |        |          |POINTX1 = (POINTX1(0.5)) % CURVEN.
 * |        |          |MODOP is active only when ECCOP = 01.
 * |[13]    |SPCEN     |Special Curve Enable
 * |        |          |0 = NIST suggested.
 * |        |          |1 = Montgomery curve or Edwards curve.
 * |[16]    |SPCSEL    |Special Curve Selection
 * |        |          |0 = Montgomery curve when SPCEN is 1.
 * |        |          |1 = Edwards curve when SPCEN is 1.
 * |[31:22] |CURVEM    |The key length of elliptic curve.
 * @var CRYPTO_T::ECC_STS
 * Offset: 0x804  ECC Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |BUSY      |ECC Accelerator Busy Flag
 * |        |          |0 = The ECC accelerator is idle or finished.
 * |        |          |1 = The ECC accelerator is under processing and protects all registers.
 * |        |          |Note: Remember to clear ECC interrupt flag after ECC accelerator is finished
 * |[1]     |DMABUSY   |ECC DMA Busy Flag
 * |        |          |0 = ECC DMA is idle or finished.
 * |        |          |1 = ECC DMA is busy.
 * |[16]    |BUSERR    |ECC DMA Access Bus Error Flag
 * |        |          |0 = No error.
 * |        |          |1 = Bus error will stop DMA operation and ECC accelerator.
 * |[17]    |KSERR     |ECC Engine Access Key Store Error Flag
 * |        |          |0 = No error.
 * |        |          |1 = Access error will stop ECC engine.
 * |[19]    |ECDSAERR  |ECC Engine ECDAS Error Flag
 * |        |          |0 = No error.
 * |        |          |1 = ECDSA fail happened in ECC engine. The results from ECC engine are incorrect.
 * @var CRYPTO_T::ECC_X1_00
 * Offset: 0x808  ECC the X-coordinate Word0 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_01
 * Offset: 0x80C  ECC the X-coordinate Word1 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_02
 * Offset: 0x810  ECC the X-coordinate Word2 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_03
 * Offset: 0x814  ECC the X-coordinate Word3 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_04
 * Offset: 0x818  ECC the X-coordinate Word4 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_05
 * Offset: 0x81C  ECC the X-coordinate Word5 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_06
 * Offset: 0x820  ECC the X-coordinate Word6 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_07
 * Offset: 0x824  ECC the X-coordinate Word7 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_08
 * Offset: 0x828  ECC the X-coordinate Word8 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_09
 * Offset: 0x82C  ECC the X-coordinate Word9 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_10
 * Offset: 0x830  ECC the X-coordinate Word10 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_11
 * Offset: 0x834  ECC the X-coordinate Word11 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_12
 * Offset: 0x838  ECC the X-coordinate Word12 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_13
 * Offset: 0x83C  ECC the X-coordinate Word13 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_14
 * Offset: 0x840  ECC the X-coordinate Word14 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_15
 * Offset: 0x844  ECC the X-coordinate Word15 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_16
 * Offset: 0x848  ECC the X-coordinate Word16 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_X1_17
 * Offset: 0x84C  ECC the X-coordinate Word17 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX1   |ECC the X-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For B-233 or K-233, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For B-283 or K-283, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_08
 * |        |          |For B-409 or K-409, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_12
 * |        |          |For B-571 or K-571, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_17
 * |        |          |For P-192, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_05
 * |        |          |For P-224, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_06
 * |        |          |For P-256, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_07
 * |        |          |For P-384, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_11
 * |        |          |For P-521, POINTX1 is stored in CRYPTO_ECC_X1_00~CRYPTO_ECC_X1_16
 * @var CRYPTO_T::ECC_Y1_00
 * Offset: 0x850  ECC the Y-coordinate Word0 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_01
 * Offset: 0x854  ECC the Y-coordinate Word1 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_02
 * Offset: 0x858  ECC the Y-coordinate Word2 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_03
 * Offset: 0x85C  ECC the Y-coordinate Word3 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_04
 * Offset: 0x860  ECC the Y-coordinate Word4 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_05
 * Offset: 0x864  ECC the Y-coordinate Word5 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_06
 * Offset: 0x868  ECC the Y-coordinate Word6 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_07
 * Offset: 0x86C  ECC the Y-coordinate Word7 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_08
 * Offset: 0x870  ECC the Y-coordinate Word8 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_09
 * Offset: 0x874  ECC the Y-coordinate Word9 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_10
 * Offset: 0x878  ECC the Y-coordinate Word10 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_11
 * Offset: 0x87C  ECC the Y-coordinate Word11 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_12
 * Offset: 0x880  ECC the Y-coordinate Word12 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_13
 * Offset: 0x884  ECC the Y-coordinate Word13 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_14
 * Offset: 0x888  ECC the Y-coordinate Word14 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_15
 * Offset: 0x88C  ECC the Y-coordinate Word15 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_16
 * Offset: 0x890  ECC the Y-coordinate Word16 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_Y1_17
 * Offset: 0x894  ECC the Y-coordinate Word17 of the First Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY1   |ECC the Y-coordinate Value of the First Point
 * |        |          |For B-163 or K-163, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For B-233 or K-233, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For B-283 or K-283, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_08
 * |        |          |For B-409 or K-409, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_12
 * |        |          |For B-571 or K-571, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_17
 * |        |          |For P-192, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_05
 * |        |          |For P-224, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_06
 * |        |          |For P-256, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_07
 * |        |          |For P-384, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_11
 * |        |          |For P-521, POINTY1 is stored in CRYPTO_ECC_Y1_00~CRYPTO_ECC_Y1_16
 * @var CRYPTO_T::ECC_X2_00
 * Offset: 0x898  ECC the X-coordinate Word0 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_01
 * Offset: 0x89C  ECC the X-coordinate Word1 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_02
 * Offset: 0x8A0  ECC the X-coordinate Word2 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_03
 * Offset: 0x8A4  ECC the X-coordinate Word3 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_04
 * Offset: 0x8A8  ECC the X-coordinate Word4 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_05
 * Offset: 0x8AC  ECC the X-coordinate Word5 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_06
 * Offset: 0x8B0  ECC the X-coordinate Word6 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_07
 * Offset: 0x8B4  ECC the X-coordinate Word7 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_08
 * Offset: 0x8B8  ECC the X-coordinate Word8 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_09
 * Offset: 0x8BC  ECC the X-coordinate Word9 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_10
 * Offset: 0x8C0  ECC the X-coordinate Word10 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_11
 * Offset: 0x8C4  ECC the X-coordinate Word11 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_12
 * Offset: 0x8C8  ECC the X-coordinate Word12 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_13
 * Offset: 0x8CC  ECC the X-coordinate Word13 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_14
 * Offset: 0x8D0  ECC the X-coordinate Word14 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_15
 * Offset: 0x8D4  ECC the X-coordinate Word15 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_16
 * Offset: 0x8D8  ECC the X-coordinate Word16 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_X2_17
 * Offset: 0x8DC  ECC the X-coordinate Word17 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTX2   |ECC the X-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For B-233 or K-233, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For B-283 or K-283, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_08
 * |        |          |For B-409 or K-409, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_12
 * |        |          |For B-571 or K-571, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_17
 * |        |          |For P-192, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_05
 * |        |          |For P-224, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_06
 * |        |          |For P-256, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_07
 * |        |          |For P-384, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_11
 * |        |          |For P-521, POINTX2 is stored in CRYPTO_ECC_X2_00~CRYPTO_ECC_X2_16
 * @var CRYPTO_T::ECC_Y2_00
 * Offset: 0x8E0  ECC the Y-coordinate Word0 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_01
 * Offset: 0x8E4  ECC the Y-coordinate Word1 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_02
 * Offset: 0x8E8  ECC the Y-coordinate Word2 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_03
 * Offset: 0x8EC  ECC the Y-coordinate Word3 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_04
 * Offset: 0x8F0  ECC the Y-coordinate Word4 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_05
 * Offset: 0x8F4  ECC the Y-coordinate Word5 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_06
 * Offset: 0x8F8  ECC the Y-coordinate Word6 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_07
 * Offset: 0x8FC  ECC the Y-coordinate Word7 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_08
 * Offset: 0x900  ECC the Y-coordinate Word8 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_09
 * Offset: 0x904  ECC the Y-coordinate Word9 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_10
 * Offset: 0x908  ECC the Y-coordinate Word10 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_11
 * Offset: 0x90C  ECC the Y-coordinate Word11 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_12
 * Offset: 0x910  ECC the Y-coordinate Word12 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_13
 * Offset: 0x914  ECC the Y-coordinate Word13 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_14
 * Offset: 0x918  ECC the Y-coordinate Word14 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_15
 * Offset: 0x91C  ECC the Y-coordinate Word15 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_16
 * Offset: 0x920  ECC the Y-coordinate Word16 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_Y2_17
 * Offset: 0x924  ECC the Y-coordinate Word17 of the Second Point
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |POINTY2   |ECC the Y-coordinate Value of the Second Point
 * |        |          |For B-163 or K-163, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For B-233 or K-233, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For B-283 or K-283, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_08
 * |        |          |For B-409 or K-409, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_12
 * |        |          |For B-571 or K-571, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_17
 * |        |          |For P-192, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_05
 * |        |          |For P-224, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_06
 * |        |          |For P-256, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_07
 * |        |          |For P-384, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_11
 * |        |          |For P-521, POINTY2 is stored in CRYPTO_ECC_Y2_00~CRYPTO_ECC_Y2_16
 * @var CRYPTO_T::ECC_A_00
 * Offset: 0x928  ECC the Parameter CURVEA Word0 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_01
 * Offset: 0x92C  ECC the Parameter CURVEA Word1 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_02
 * Offset: 0x930  ECC the Parameter CURVEA Word2 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_03
 * Offset: 0x934  ECC the Parameter CURVEA Word3 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_04
 * Offset: 0x938  ECC the Parameter CURVEA Word4 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_05
 * Offset: 0x93C  ECC the Parameter CURVEA Word5 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_06
 * Offset: 0x940  ECC the Parameter CURVEA Word6 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_07
 * Offset: 0x944  ECC the Parameter CURVEA Word7 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_08
 * Offset: 0x948  ECC the Parameter CURVEA Word8 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_09
 * Offset: 0x94C  ECC the Parameter CURVEA Word9 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_10
 * Offset: 0x950  ECC the Parameter CURVEA Word10 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_11
 * Offset: 0x954  ECC the Parameter CURVEA Word11 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_12
 * Offset: 0x958  ECC the Parameter CURVEA Word12 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_13
 * Offset: 0x95C  ECC the Parameter CURVEA Word13 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_14
 * Offset: 0x960  ECC the Parameter CURVEA Word14 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_15
 * Offset: 0x964  ECC the Parameter CURVEA Word15 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_16
 * Offset: 0x968  ECC the Parameter CURVEA Word16 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_A_17
 * Offset: 0x96C  ECC the Parameter CURVEA Word17 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEA    |ECC the Parameter CURVEA Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For B-233 or K-233, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For B-283 or K-283, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_08
 * |        |          |For B-409 or K-409, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_12
 * |        |          |For B-571 or K-571, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_17
 * |        |          |For P-192, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_05
 * |        |          |For P-224, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_06
 * |        |          |For P-256, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_07
 * |        |          |For P-384, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_11
 * |        |          |For P-521, CURVEA is stored in CRYPTO_ECC_A_00~CRYPTO_ECC_A_16
 * @var CRYPTO_T::ECC_B_00
 * Offset: 0x970  ECC the Parameter CURVEB Word0 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_01
 * Offset: 0x974  ECC the Parameter CURVEB Word1 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_02
 * Offset: 0x978  ECC the Parameter CURVEB Word2 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_03
 * Offset: 0x97C  ECC the Parameter CURVEB Word3 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_04
 * Offset: 0x980  ECC the Parameter CURVEB Word4 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_05
 * Offset: 0x984  ECC the Parameter CURVEB Word5 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_06
 * Offset: 0x988  ECC the Parameter CURVEB Word6 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_07
 * Offset: 0x98C  ECC the Parameter CURVEB Word7 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_08
 * Offset: 0x990  ECC the Parameter CURVEB Word8 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_09
 * Offset: 0x994  ECC the Parameter CURVEB Word9 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_10
 * Offset: 0x998  ECC the Parameter CURVEB Word10 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_11
 * Offset: 0x99C  ECC the Parameter CURVEB Word11 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_12
 * Offset: 0x9A0  ECC the Parameter CURVEB Word12 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_13
 * Offset: 0x9A4  ECC the Parameter CURVEB Word13 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_14
 * Offset: 0x9A8  ECC the Parameter CURVEB Word14 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_15
 * Offset: 0x9AC  ECC the Parameter CURVEB Word15 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_16
 * Offset: 0x9B0  ECC the Parameter CURVEB Word16 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_B_17
 * Offset: 0x9B4  ECC the Parameter CURVEB Word17 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEB    |ECC the Parameter CURVEB Value of Elliptic Curve
 * |        |          |The formula of elliptic curve is y2=x3+CURVEA*x+CURVEB in GF(p) and y2+x*y=x3+CURVEA*x2+CURVEB in GF(2m).
 * |        |          |For B-163 or K-163, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For B-233 or K-233, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For B-283 or K-283, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_08
 * |        |          |For B-409 or K-409, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_12
 * |        |          |For B-521 or K-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_17
 * |        |          |For P-192, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_05
 * |        |          |For P-224, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_06
 * |        |          |For P-256, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_07
 * |        |          |For P-384, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_11
 * |        |          |For P-521, CURVEB is stored in CRYPTO_ECC_B_00~CRYPTO_ECC_B_16
 * @var CRYPTO_T::ECC_N_00
 * Offset: 0x9B8  ECC the Parameter CURVEN Word0 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_01
 * Offset: 0x9BC  ECC the Parameter CURVEN Word1 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_02
 * Offset: 0x9C0  ECC the Parameter CURVEN Word2 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_03
 * Offset: 0x9C4  ECC the Parameter CURVEN Word3 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_04
 * Offset: 0x9C8  ECC the Parameter CURVEN Word4 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_05
 * Offset: 0x9CC  ECC the Parameter CURVEN Word5 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_06
 * Offset: 0x9D0  ECC the Parameter CURVEN Word6 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_07
 * Offset: 0x9D4  ECC the Parameter CURVEN Word7 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_08
 * Offset: 0x9D8  ECC the Parameter CURVEN Word8 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_09
 * Offset: 0x9DC  ECC the Parameter CURVEN Word9 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_10
 * Offset: 0x9E0  ECC the Parameter CURVEN Word10 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_11
 * Offset: 0x9E4  ECC the Parameter CURVEN Word11 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_12
 * Offset: 0x9E8  ECC the Parameter CURVEN Word12 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_13
 * Offset: 0x9EC  ECC the Parameter CURVEN Word13 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_14
 * Offset: 0x9F0  ECC the Parameter CURVEN Word14 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_15
 * Offset: 0x9F4  ECC the Parameter CURVEN Word15 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_16
 * Offset: 0x9F8  ECC the Parameter CURVEN Word16 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_N_17
 * Offset: 0x9FC  ECC the Parameter CURVEN Word17 of Elliptic Curve
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CURVEN    |ECC the Parameter CURVEN Value of Elliptic Curve
 * |        |          |In GF(p), CURVEN is the prime p.
 * |        |          |In GF(2m), CURVEN is the irreducible polynomial.
 * |        |          |For B-163 or K-163, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For B-233 or K-233, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For B-283 or K-283, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_08
 * |        |          |For B-409 or K-409, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_12
 * |        |          |For B-571 or K-571, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_17
 * |        |          |For P-192, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_05
 * |        |          |For P-224, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_06
 * |        |          |For P-256, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_07
 * |        |          |For P-384, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_11
 * |        |          |For P-521, CURVEN is stored in CRYPTO_ECC_N_00~CRYPTO_ECC_N_16
 * @var CRYPTO_T::ECC_K_00
 * Offset: 0xA00  ECC the Scalar SCALARK Word0 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_01
 * Offset: 0xA04  ECC the Scalar SCALARK Word1 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_02
 * Offset: 0xA08  ECC the Scalar SCALARK Word2 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_03
 * Offset: 0xA0C  ECC the Scalar SCALARK Word3 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_04
 * Offset: 0xA10  ECC the Scalar SCALARK Word4 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_05
 * Offset: 0xA14  ECC the Scalar SCALARK Word5 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_06
 * Offset: 0xA18  ECC the Scalar SCALARK Word6 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_07
 * Offset: 0xA1C  ECC the Scalar SCALARK Word7 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_08
 * Offset: 0xA20  ECC the Scalar SCALARK Word8 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_09
 * Offset: 0xA24  ECC the Scalar SCALARK Word9 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_10
 * Offset: 0xA28  ECC the Scalar SCALARK Word10 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_11
 * Offset: 0xA2C  ECC the Scalar SCALARK Word11 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_12
 * Offset: 0xA30  ECC the Scalar SCALARK Word12 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_13
 * Offset: 0xA34  ECC the Scalar SCALARK Word13 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_14
 * Offset: 0xA38  ECC the Scalar SCALARK Word14 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_15
 * Offset: 0xA3C  ECC the Scalar SCALARK Word15 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_16
 * Offset: 0xA40  ECC the Scalar SCALARK Word16 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_K_17
 * Offset: 0xA44  ECC the Scalar SCALARK Word17 of Point Multiplication
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SCALARK   |ECC the Scalar SCALARK Value of Point Multiplication
 * |        |          |Because the SCALARK usually stores the private key, ECC accelerator do not allow to read the register SCALARK.
 * |        |          |For B-163 or K-163, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For B-233 or K-233, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For B-283 or K-283, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_08
 * |        |          |For B-409 or K-409, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_12
 * |        |          |For B-571 or K-571, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_17
 * |        |          |For P-192, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_05
 * |        |          |For P-224, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_06
 * |        |          |For P-256, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_07
 * |        |          |For P-384, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_11
 * |        |          |For P-521, SCALARK is stored in CRYPTO_ECC_K_00~CRYPTO_ECC_K_16
 * @var CRYPTO_T::ECC_SADDR
 * Offset: 0xA48  ECC DMA Source Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * @var CRYPTO_T::ECC_DADDR
 * Offset: 0xA4C  ECC DMA Destination Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DADDR     |ECC DMA Destination Address
 * |        |          |The ECC accelerator supports DMA function to transfer the DATA and PARAMETER between system memory and ECC accelerator
 * |        |          |The DADDR keeps the destination address of the data buffer where output data of ECC engine will be stored
 * |        |          |Based on the destination address, the ECC accelerator can write the result data back to system memory space after the ECC operation is finished
 * |        |          |The start of destination address should be located at word boundary
 * |        |          |That is, bit 1 and 0 of DADDR are ignored
 * |        |          |DADDR can be read and written
 * |        |          |In DMA mode, software must update the CRYPTO_ECC_DADDR before triggering START
 * @var CRYPTO_T::ECC_STARTREG
 * Offset: 0xA50  ECC Starting Address of Updated Registers
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |STARTREG  |ECC Starting Address of Updated Registers
 * |        |          |The address of the updated registers that DMA feeds the first data or parameter to ECC engine
 * |        |          |When ECC engine is active, ECC accelerator does not allow users to modify STARTRE.G
 * |        |          |For example, to update input data from register CRYPTO_ECC POINTX1
 * |        |          |Thus, the value of STARTREG is 0x808.
 * @var CRYPTO_T::ECC_WORDCNT
 * Offset: 0xA54  ECC DMA Word Count
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |WORDCNT   |ECC DMA Word Count
 * |        |          |The CRYPTO_ECC_WORDCNT keeps the word count of source data that is for the required input data of ECC accelerator with various operations in DMA mode
 * |        |          |Although CRYPTO_ECC_WORDCNT is 32-bit, the maximum of word count in ECC accelerator is 144 words
 * |        |          |CRYPTO_ECC_WORDCNT can be read and written
 * @var CRYPTO_T::ECC_DMA_CTL
 * Offset: 0xA58  ECC DMA Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |LDP1      |The Control Signal of Register POINTX1 and POINTY1 for the x and Y Coordinate of the First Point
 * |        |          |0 = The register for POINTX1 and POINTY1 is not modified by DMA or user.
 * |        |          |1 = The register for POINTX1 and POINTY1 is modified by DMA or user.
 * |[1]     |LDP2      |The Control Signal of Register POINTX2 and POINTY2 for the x and Y Coordinate of the Second Point
 * |        |          |0 = The register for POINTX2 and POINTY2 is not modified by DMA or user.
 * |        |          |1 = The register for POINTX2 and POINTY2 is modified by DMA or user.
 * |[2]     |LDA       |The Control Signal of Register for the Parameter CURVEA of Elliptic Curve
 * |        |          |0 = The register for CURVEA is not modified by DMA or user.
 * |        |          |1 = The register for CURVEA is modified by DMA or user.
 * |[3]     |LDB       |The Control Signal of Register for the Parameter CURVEB of Elliptic Curve
 * |        |          |0 = The register for CURVEB is not modified by DMA or user.
 * |        |          |1 = The register for CURVEB is modified by DMA or user.
 * |[4]     |LDN       |The Control Signal of Register for the Parameter CURVEN of Elliptic Curve
 * |        |          |0 = The register for CURVEN is not modified by DMA or user.
 * |        |          |1 = The register for CURVEN is modified by DMA or user.
 * |[5]     |LDK       |The Control Signal of Register for SCALARK
 * |        |          |0 = The register for SCALARK is not modified by DMA or user.
 * |        |          |1 = The register for SCALARK is modified by DMA or user.
 * @var CRYPTO_T::ECC_PRNGSEED
 * Offset: 0xA60  ECC PRNG Seed Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SEED      |Seed for ECC PRNG (Write Only)
 * |        |          |The bits store the seed for ECC PRNG engine.
 * @var CRYPTO_T::ECC_PRNGSTS
 * Offset: 0xA64  ECC PRNG Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[8]     |RDCNT     |ECC ECDAS K Read Count
 * |        |          |0 = K does not exit in ECC.
 * |        |          |1 = K exists in ECC.
 * @var CRYPTO_T::ECC_EDDSA
 * Offset: 0xA70  ECC EDDSA Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |SHASP     |ECC EdDSA Scalar And Prefix Generation
 * |        |          |1 = SHA generates scalar and prefix.
 * |        |          |0 = No effect.
 * |[1]     |ECCSB     |ECC EdDSA Public Key Generation
 * |        |          |1 = ECC generates public key via point multiplication.
 * |        |          |0 = No effect.
 * |[2]     |SHALR     |ECC EdDSA r Generation
 * |        |          |1 = SHA generates r.
 * |        |          |0 = No effect.
 * |[3]     |ECCSR     |ECC EdDSA r Modulo
 * |        |          |1 = ECC executes r modulo order via modulo multiplication.
 * |        |          |0 = No effect.
 * |[4]     |ECCRB     |ECC EdDSA R Generation
 * |        |          |1 = ECC generates R via point multiplication.
 * |        |          |0 = No effect.
 * |[5]     |ECCSG     |ECC EdDSA S Generation
 * |        |          |1 = ECC generates S via ECDSAS in Edwards curve.
 * |        |          |0 = No effect.
 * @var CRYPTO_T::RSA_CTL
 * Offset: 0xB00  RSA Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |START     |RSA Accelerator Start
 * |        |          |0 = No effect.
 * |        |          |1 = Start RSA accelerator. BUSY flag will be set.
 * |        |          |This bit is always 0 when it is read back.
 * |        |          |RSA accelerator will ignore this START signal when BUSY flag is 1.
 * |[1]     |STOP      |RSA Accelerator Stop
 * |        |          |0 = No effect.
 * |        |          |1 = Abort RSA accelerator and make it into initial state.
 * |        |          |This bit is always 0 when it is read back.
 * |        |          |Remember to clear RSA interrupt flag after stopping RSA accelerator.
 * |[2]     |CRT       |CRT Enable Control
 * |        |          |0 = CRT Disabled.
 * |        |          |1 = CRT Enabled.
 * |        |          |CRT is only used in decryption with key length 2048, 3072,4096 bits.
 * |[3]     |CRTBYP    |CRT Bypass Enable Control
 * |        |          |0 = CRT Bypass Disabled.
 * |        |          |1 = CRT Bypass Enabled.
 * |        |          |CRT bypass is only used in CRT decryption with the same key.
 * |        |          |CRT mode saved the data when the first time CRT decryption (CRTBYP is 0), then users can use these already known data to bypass some operation when the second time to the latest time CRT decryption (CRTBYP is 1) for improve performance.
 * |        |          |Note: Users cannot set CRTBYP to 1 in non-CRT mode (CRT (CRYPTO_RSA_CTL[2]) is 0).
 * |[5:4]   |KEYLENG   |The Key Length of RSA Operation
 * |        |          |00 = 1024-bits.
 * |        |          |01 = 2048-bits.
 * |        |          |10 = 3072-bits.
 * |        |          |11 = 4096-bits.
 * @var CRYPTO_T::RSA_STS
 * Offset: 0xB04  RSA Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |BUSY      |RSA Accelerator Busy Flag
 * |        |          |0 = The RSA accelerator is idle or finished.
 * |        |          |1 = The RSA accelerator is under processing and protects all registers.
 * |        |          |Remember to clear RSA interrupt flag after RSA accelerator finished.
 * |[1]     |DMABUSY   |RSA DMA Busy Flag
 * |        |          |0 = RSA DMA is idle or finished.
 * |        |          |1 = RSA DMA is busy.
 * |[16]    |BUSERR    |RSA DMA Access Bus Error Flag
 * |        |          |0 = No error.
 * |        |          |1 = Bus error will stop DMA operation and RSA accelerator.
 * |[17]    |CTLERR    |RSA Control Register Error Flag
 * |        |          |0 = No error.
 * |        |          |1 = RSA control error. RSA will not start in the unsupported situation.
 * |        |          |Note: If users use the error combination of control, even though they donu2019t set START(CRYPTO_RSA_CTL[0]) to 1, CTLERR still be set to 1.
 * @var CRYPTO_T::RSA_SADDR0
 * Offset: 0xB08  RSA DMA Source Address Register0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SADDR0    |RSA DMA Source Address Register0
 * |        |          |The RSA accelerator supports DMA function to transfer the DATA and PARAMETER between system memory space and RSA accelerator.
 * |        |          |This register is stored the address of RSA the Base of Exponentiation (M).
 * @var CRYPTO_T::RSA_SADDR1
 * Offset: 0xB0C  RSA DMA Source Address Register1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SADDR1    |RSA DMA Source Address Register1
 * |        |          |The RSA accelerator supports DMA function to transfer the DATA and PARAMETER between system memory space and RSA accelerator.
 * |        |          |This register is stored the address of RSA the Base of Modulus Operation (N).
 * @var CRYPTO_T::RSA_SADDR2
 * Offset: 0xB10  RSA DMA Source Address Register2
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SADDR2    |RSA DMA Source Address Register2
 * |        |          |The RSA accelerator supports DMA function to transfer the DATA and PARAMETER between system memory space and RSA accelerator.
 * |        |          |This register is stored the address of RSA the Exponent of Exponentiation (E).
 * @var CRYPTO_T::RSA_SADDR3
 * Offset: 0xB14  RSA DMA Source Address Register3
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SADDR3    |RSA DMA Source Address Register3
 * |        |          |The RSA accelerator supports DMA function to transfer the DATA and PARAMETER between system memory space and RSA accelerator.
 * |        |          |This register is stored the address of RSA the Factor of Modulus Operation (p).
 * @var CRYPTO_T::RSA_SADDR4
 * Offset: 0xB18  RSA DMA Source Address Register4
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SADDR4    |RSA DMA Source Address Register4
 * |        |          |The RSA accelerator supports DMA function to transfer the DATA and PARAMETER between system memory space and RSA accelerator.
 * |        |          |This register is stored the address of RSA the Factor of Modulus Operation (q).
 * @var CRYPTO_T::RSA_DADDR
 * Offset: 0xB1C  RSA DMA Destination Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DADDR     |RSA DMA Destination Address Register
 * |        |          |The RSA accelerator supports DMA function to transfer the DATA and PARAMETER between system memory space and RSA accelerator.
 * |        |          |This register is stored the address of RSA DMA Destination Address Register (Ans).
 * @var CRYPTO_T::RSA_MADDR0
 * Offset: 0xB20  RSA DMA Middle Address Register0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |MADDR0    |RSA DMA Middle Address Register0
 * |        |          |The RSA accelerator supports DMA function to transfer the DATA and PARAMETER between system memory space and RSA accelerator.
 * |        |          |This register is stored the address of RSA CRT the Temporary Value (Cp -> Mp -> Sp).
 * @var CRYPTO_T::RSA_MADDR1
 * Offset: 0xB24  RSA DMA Middle Address Register1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |MADDR1    |RSA DMA Middle Address Register1
 * |        |          |The RSA accelerator supports DMA function to transfer the DATA and PARAMETER between system memory space and RSA accelerator.
 * |        |          |This register is stored the address of RSA CRT the Temporary Value (Cq -> Mq -> Sq).
 * @var CRYPTO_T::RSA_MADDR2
 * Offset: 0xB28  RSA DMA Middle Address Register2
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |MADDR2    |RSA DMA Middle Address Register2
 * |        |          |The RSA accelerator supports DMA function to transfer the DATA and PARAMETER between system memory space and RSA accelerator.
 * |        |          |This register is stored the address of RSA CRT the Temporary Value (Dp).
 * @var CRYPTO_T::RSA_MADDR3
 * Offset: 0xB2C  RSA DMA Middle Address Register3
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |MADDR3    |RSA DMA Middle Address Register3
 * |        |          |The RSA accelerator supports DMA function to transfer the DATA and PARAMETER between system memory space and RSA accelerator.
 * |        |          |This register is stored the address of RSA CRT the Temporary Value (Dq).
 * @var CRYPTO_T::RSA_MADDR4
 * Offset: 0xB30  RSA DMA Middle Address Register4
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |MADDR4    |RSA DMA Middle Address Register4
 * |        |          |The RSA accelerator supports DMA function to transfer the DATA and PARAMETER between system memory space and RSA accelerator.
 * |        |          |This register is stored the address of RSA CRT the Temporary Value (Rp).
 * @var CRYPTO_T::RSA_MADDR5
 * Offset: 0xB34  RSA DMA Middle Address Register5
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |MADDR5    |RSA DMA Middle Address Register5
 * |        |          |The RSA accelerator supports DMA function to transfer the DATA and PARAMETER between system memory space and RSA accelerator.
 * |        |          |This register is stored the address of RSA CRT the Temporary Value (Rq).
 * @var CRYPTO_T::PRNG_KSCTL
 * Offset: 0xF00  PRNG Key Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[4:0]   |NUM       |Write Key Number
 * |        |          |The key number is sent to Key Store
 * |        |          |Note: Only for destination Is OTP of Key Store.
 * |[21]    |WDST      |Write Key Destination
 * |        |          |0 = Key is written to registers CRYPTO_PRNG_KEYx.
 * |        |          |1 = Key is written to Key Store.
 * |[23:22] |WSDST     |Write Key Store Destination
 * |        |          |00 = Key is written to the SRAM of Key Store.
 * |        |          |10 = Key is written to the OTP of Key Store.
 * |        |          |Others = reserved.
 * |[26:24] |OWNER     |Write Key Owner Selection Bits
 * |        |          |000 = Only for AES use.
 * |        |          |001 = Only for HMAC engine (excludes HMAC-SHA3 series) use.
 * |        |          |100 = Only for ECC engine use.
 * |        |          |101 = Only for CPU engine use.
 * |        |          |Others = reserved.
 * |        |          |Note: If users want to generate ECC key for Key Store (CRYPTO_PRNG_KSCTL[26:24] is u2018100u2019), ECC key would must in the interval [1, n-1] (the parameter n is from ECC)
 * |        |          |The value of n cannot be 0 or 1, otherwise, PRNG will always keep busy.
 * @var CRYPTO_T::HMAC_KSCTL
 * Offset: 0xF30  HMAC Key Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[4:0]   |NUM       |Read Key Number
 * |        |          |The key number is sent to Key Store
 * |[5]     |RSRC      |Read Key Source
 * |        |          |0 = Key is read from HMAC registers.
 * |        |          |1 = Key is read from Key Store.
 * |[7:6]   |RSSRC     |Read Key Store Source
 * |        |          |RSSRC takes effect only when RSRC is 1 (the key is from Key Store).
 * |        |          |00 = Key is read from the SRAM of Key Store.
 * |        |          |Others = reserved.
 * @var CRYPTO_T::ECC_KSCTL
 * Offset: 0xF40  ECC Key Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[4:0]   |NUMK      |Read Key Number K
 * |        |          |The key number of CRYPTO_ECC_K is sent to Key Store when RSRCK =1.
 * |[5]     |RSRCK     |Read Key Source for Key Number K
 * |        |          |0 = Key is read from ECC registers.
 * |        |          |1 = Key is read from Key Store.
 * |[7:6]   |RSSRCK    |Read Key Store Source for Key Number K
 * |        |          |RSSRCK takes effect only when RSRCK is 1 (the key is from Key Store).
 * |        |          |00 = Key is read from the SRAM of Key Store.
 * |        |          |10 = Key is read from the OTP of Key Store.
 * |        |          |Others = reserved.
 * |[20]    |XY        |ECDH Output Select Bit
 * |        |          |0 = The ECDH written key is from X-coordinate Value.
 * |        |          |1 = The ECDH written key is from Y-coordinate Value.
 * |[21]    |WDST      |Write Key Destination for ECDH and EDDSALR
 * |        |          |0 = The ECC written key is in registers CRYPTO_ECC_X1 and CRYPTO_ECC_Y.
 * |        |          |1 = The ECC written key is written to Key Store.
 * |[23:22] |WSDST     |Write Key Store Destination for ECDH and EDDSALR
 * |        |          |WSDST takes effect only when WDST is 1 (the key is written to Key Store).
 * |        |          |00 = The ECC written key is written to the SRAM of Key Store.
 * |        |          |10 = The ECC written key is written to the OTP of Key Store.
 * |        |          |Others = reserved.
 * |[26:24] |OWNER     |Write Key Owner Selection Bits for ECDH and EDDSALR
 * |        |          |000 = The ECC written key is only for AES used.
 * |        |          |001 = The ECC written key is only for HMAC engine used.
 * |        |          |100 = The ECC written key is only for ECC engine used.
 * |        |          |101 = The ECC written key is only for CPU engine use.
 * |        |          |Others = reserved.
 * @var CRYPTO_T::ECC_KSXY
 * Offset: 0xF48  ECC XY Number Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[4:0]   |NUMX1     |Read Key Number X1
 * |        |          |The key number of CRYPTO_ECC_X1 is sent to Key Store when RSRCXY1 =1.
 * |[5]     |RSRCXY1   |Read Key Source for Key Number X1 and Y1
 * |        |          |0 = Key is read from ECC registers.
 * |        |          |1 = Key is read from Key Store.
 * |[7:6]   |RSSRCX1   |Read Key Store Source for Key Number X1
 * |        |          |RSSRCX1 takes effect only when RSRCXY1 is 1 (the key is from Key Store).
 * |        |          |00 = Key is read from the SRAM of Key Store.
 * |        |          |10 = Key is read from the OTP of Key Store.
 * |        |          |Others = Reserved.
 * |[12:8]  |NUMY1     |Read Key Number Y1
 * |        |          |The key number of CRYPTO_ECC_Y1 is sent to Key Store when RSRCXY1 =1.
 * |[15:14] |RSSRCY1   |Read Key Store Source for Key Number Y1
 * |        |          |RSSRCY1 takes effect only when RSRCXY1 is 1 (the key is from Key Store).
 * |        |          |00 = Key is read from the SRAM of Key Store.
 * |        |          |10 = Key is read from the OTP of Key Store.
 * |        |          |Others = reserved.
 * @var CRYPTO_T::VERSION
 * Offset: 0xFFC  Crypto RTL Design Version Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[15:0]  |MINOR     |RTL Design Minor Version Number
 * |        |          |Minor version number is dependent on moduleu2019s ECO version control.
 * |        |          |0x0000:(Current Minor Version Number)
 * |[23:16] |SUB       |RTL Design Sub Version Number
 * |        |          |Sub version number is correlated to moduleu2019s key feature.
 * |        |          |0x01:(Current Sub Version Number)
 * |[31:24] |MAJOR     |RTL Design Major Version Number
 * |        |          |Major version number is correlated to Product Line.
 * |        |          |0x24:(Current Major Version Number)
 */
    __IO uint32_t INTEN;                 /*!< [0x0000] Crypto Interrupt Enable Control Register                         */
    __IO uint32_t INTSTS;                /*!< [0x0004] Crypto Interrupt Flag                                            */
    __IO uint32_t PRNG_CTL;              /*!< [0x0008] PRNG Control Register                                            */
    __O  uint32_t PRNG_SEED;             /*!< [0x000c] Seed for PRNG                                                    */
    __I  uint32_t PRNG_KEY[8];           /*!< [0x0010] PRNG Generated Key0 ~ Key7                                       */
    __I  uint32_t PRNG_STS;              /*!< [0x0030] PRNG Status Register                                             */
    __I  uint32_t RESERVE0[19];
    __IO uint32_t AES_GCM_IVCNT[2];      /*!< [0x0080] AES GCM IV Byte Count Register 0 ~ 1                             */
    __IO uint32_t AES_GCM_ACNT[2];       /*!< [0x0088] AES GCM A Byte Count Register 0 ~ 1                              */
    __IO uint32_t AES_GCM_PCNT[2];       /*!< [0x0090] AES GCM P Byte Count Register 0 ~ 1                              */
    __I  uint32_t RESERVE1[2];
    __IO uint32_t AES_FBADDR;            /*!< [0x00a0] AES DMA Feedback Address Register                                */
    __I  uint32_t RESERVE2[23];
    __IO uint32_t AES_CTL;               /*!< [0x0100] AES Control Register                                             */
    __I  uint32_t AES_STS;               /*!< [0x0104] AES Engine Flag                                                  */
    __IO uint32_t AES_DATIN;             /*!< [0x0108] AES Engine Data Input Port Register                              */
    __I  uint32_t AES_DATOUT;            /*!< [0x010c] AES Engine Data Output Port Register                             */
    __IO uint32_t AES_KEY[8];            /*!< [0x0110] AES Key Word 0 ~ 7 Registers                                     */
    __IO uint32_t AES_IV[4];             /*!< [0x0130] AES Initial Vector Word 0 ~ 3 Register                           */
    __IO uint32_t AES_SADDR;             /*!< [0x0140] AES DMA Source Address Register                                  */
    __IO uint32_t AES_DADDR;             /*!< [0x0144] AES DMA Destination Address Register                             */
    __IO uint32_t AES_CNT;               /*!< [0x0148] AES Byte Count Register                                          */
    __I  uint32_t RESERVE3[109];
    __IO uint32_t HMAC_CTL;              /*!< [0x0300] SHA/HMAC Control Register                                        */
    __I  uint32_t HMAC_STS;              /*!< [0x0304] SHA/HMAC Status Flag                                             */
    __I  uint32_t HMAC_DGST[16];         /*!< [0x0308] SHA/HMAC Output Digest Data 0 ~ 15                               */
    __IO uint32_t HMAC_KEYCNT;           /*!< [0x0348] SHA/HMAC Key Byte Count Register                                 */
    __IO uint32_t HMAC_SADDR;            /*!< [0x034c] SHA/HMAC DMA Source Address Register                             */
    __IO uint32_t HMAC_DMACNT;           /*!< [0x0350] SHA/HMAC Byte Count Register                                     */
    __IO uint32_t HMAC_DATIN;            /*!< [0x0354] SHA/HMAC Engine Non-DMA Mode Data Input Port Register            */
    __IO uint32_t HMAC_DOMCNT;           /*!< [0x0358] SHA/HMAC DOM Byte Count Register                                 */
    __I  uint32_t RESERVE4[103];
    __IO uint32_t HMAC_SHA512T;          /*!< [0x04f8] SHA/HMAC SHA512/t Control Register                               */
    __IO uint32_t HMAC_FBADDR;           /*!< [0x04fc] SHA/HMAC DMA Feedback Address Register                           */
    __I  uint32_t HMAC_SHAKEDGST[42];    /*!< [0x0500] SHA/HMAC SHAKE Digest Message 0 ~ 41                             */
    __I  uint32_t RESERVE5[150];
    __IO uint32_t ECC_CTL;               /*!< [0x0800] ECC Control Register                                             */
    __I  uint32_t ECC_STS;               /*!< [0x0804] ECC Status Register                                              */
    __IO uint32_t ECC_X1[18];            /*!< [0x0808] ECC the X-coordinate Word 0 ~ 17 of the First Point              */
    __IO uint32_t ECC_Y1[18];            /*!< [0x0850] ECC the Y-coordinate Word 0 ~ 17 of the First Point              */
    __IO uint32_t ECC_X2[18];            /*!< [0x0898] ECC the X-coordinate Word 0 ~ 17 of the Second Point             */
    __IO uint32_t ECC_Y2[18];            /*!< [0x08e0] ECC the Y-coordinate Word 0 ~ 17 of the Second Point             */
    __IO uint32_t ECC_A[18];             /*!< [0x0928] ECC the Parameter CURVEA Word 0 ~ 17 of Elliptic Curve           */
    __IO uint32_t ECC_B[18];             /*!< [0x0970] ECC the Parameter CURVEB Word 0 ~ 17 of Elliptic Curve           */
    __IO uint32_t ECC_N[18];             /*!< [0x09b8] ECC the Parameter CURVEN Word 0 ~ 17 of Elliptic Curve           */
    __O  uint32_t ECC_K[18];             /*!< [0x0a00] ECC the Scalar SCALARK Word 0 ~ 17 of Point Multiplication       */
    __IO uint32_t ECC_SADDR;             /*!< [0x0a48] ECC DMA Source Address Register                                  */
    __IO uint32_t ECC_DADDR;             /*!< [0x0a4c] ECC DMA Destination Address Register                             */
    __IO uint32_t ECC_STARTREG;          /*!< [0x0a50] ECC Starting Address of Updated Registers                        */
    __IO uint32_t ECC_WORDCNT;           /*!< [0x0a54] ECC DMA Word Count                                               */
    __IO uint32_t ECC_DMA_CTL;           /*!< [0x0a58] ECC DMA Control Register                                         */
    __I  uint32_t RESERVE6[1];
    __O  uint32_t ECC_PRNGSEED;          /*!< [0x0a60] ECC PRNG Seed Register                                           */
    __I  uint32_t ECC_PRNGSTS;           /*!< [0x0a64] ECC PRNG Status Register                                         */
    __I  uint32_t RESERVE7[2];
    __IO uint32_t ECC_EDDSA;             /*!< [0x0a70] ECC EDDSA Register                                               */
    __I  uint32_t RESERVE8[35];
    __IO uint32_t RSA_CTL;               /*!< [0x0b00] RSA Control Register                                             */
    __I  uint32_t RSA_STS;               /*!< [0x0b04] RSA Status Register                                              */
    __IO uint32_t RSA_SADDR[5];          /*!< [0x0b08] RSA DMA Source Address Register 0 ~ 4                            */
    __IO uint32_t RSA_DADDR;             /*!< [0x0b1c] RSA DMA Destination Address Register                             */
    __IO uint32_t RSA_MADDR[6];          /*!< [0x0b20] RSA DMA Middle Address Register 0 ~ 5                            */
    __I  uint32_t RESERVE9[242];
    __O  uint32_t PRNG_KSCTL;            /*!< [0x0f00] PRNG Key Control Register                                        */
    __I  uint32_t RESERVE10[3];
    __O  uint32_t AES_KSCTL;             /*!< [0x0f10] AES Key Control Register                                         */
    __I  uint32_t RESERVE11[7];
    __O  uint32_t HMAC_KSCTL;            /*!< [0x0f30] HMAC Key Control Register                                        */
    __I  uint32_t RESERVE12[3];
    __O  uint32_t ECC_KSCTL;             /*!< [0x0f40] ECC Key Control Register                                         */
    __I  uint32_t RESERVE13[1];
    __O  uint32_t ECC_KSXY;              /*!< [0x0f48] ECC XY Number Register                                           */
} CRYPTO_T;

/**
    @addtogroup CRYPTO_CONST CRYPTO Bit Field Definition
    Constant Definitions for CRYPTO Controller
@{ */

#define CRYPTO_INTEN_AESIEN_Pos          (0)                                               /*!< CRYPTO_T::INTEN: AESIEN Position       */
#define CRYPTO_INTEN_AESIEN_Msk          (0x1ul << CRYPTO_INTEN_AESIEN_Pos)                /*!< CRYPTO_T::INTEN: AESIEN Mask           */

#define CRYPTO_INTEN_AESEIEN_Pos         (1)                                               /*!< CRYPTO_T::INTEN: AESEIEN Position      */
#define CRYPTO_INTEN_AESEIEN_Msk         (0x1ul << CRYPTO_INTEN_AESEIEN_Pos)               /*!< CRYPTO_T::INTEN: AESEIEN Mask          */

#define CRYPTO_INTEN_PRNGIEN_Pos         (16)                                              /*!< CRYPTO_T::INTEN: PRNGIEN Position      */
#define CRYPTO_INTEN_PRNGIEN_Msk         (0x1ul << CRYPTO_INTEN_PRNGIEN_Pos)               /*!< CRYPTO_T::INTEN: PRNGIEN Mask          */

#define CRYPTO_INTEN_PRNGEIEN_Pos        (17)                                              /*!< CRYPTO_T::INTEN: PRNGEIEN Position     */
#define CRYPTO_INTEN_PRNGEIEN_Msk        (0x1ul << CRYPTO_INTEN_PRNGEIEN_Pos)              /*!< CRYPTO_T::INTEN: PRNGEIEN Mask         */

#define CRYPTO_INTEN_ECCIEN_Pos          (22)                                              /*!< CRYPTO_T::INTEN: ECCIEN Position       */
#define CRYPTO_INTEN_ECCIEN_Msk          (0x1ul << CRYPTO_INTEN_ECCIEN_Pos)                /*!< CRYPTO_T::INTEN: ECCIEN Mask           */

#define CRYPTO_INTEN_ECCEIEN_Pos         (23)                                              /*!< CRYPTO_T::INTEN: ECCEIEN Position      */
#define CRYPTO_INTEN_ECCEIEN_Msk         (0x1ul << CRYPTO_INTEN_ECCEIEN_Pos)               /*!< CRYPTO_T::INTEN: ECCEIEN Mask          */

#define CRYPTO_INTEN_HMACIEN_Pos         (24)                                              /*!< CRYPTO_T::INTEN: HMACIEN Position      */
#define CRYPTO_INTEN_HMACIEN_Msk         (0x1ul << CRYPTO_INTEN_HMACIEN_Pos)               /*!< CRYPTO_T::INTEN: HMACIEN Mask          */

#define CRYPTO_INTEN_HMACEIEN_Pos        (25)                                              /*!< CRYPTO_T::INTEN: HMACEIEN Position     */
#define CRYPTO_INTEN_HMACEIEN_Msk        (0x1ul << CRYPTO_INTEN_HMACEIEN_Pos)              /*!< CRYPTO_T::INTEN: HMACEIEN Mask         */

#define CRYPTO_INTEN_RSAIEN_Pos          (30)                                              /*!< CRYPTO_T::INTEN: RSAIEN Position       */
#define CRYPTO_INTEN_RSAIEN_Msk          (0x1ul << CRYPTO_INTEN_RSAIEN_Pos)                /*!< CRYPTO_T::INTEN: RSAIEN Mask           */

#define CRYPTO_INTEN_RSAEIEN_Pos         (31)                                              /*!< CRYPTO_T::INTEN: RSAEIEN Position      */
#define CRYPTO_INTEN_RSAEIEN_Msk         (0x1ul << CRYPTO_INTEN_RSAEIEN_Pos)               /*!< CRYPTO_T::INTEN: RSAEIEN Mask          */

#define CRYPTO_INTSTS_AESIF_Pos          (0)                                               /*!< CRYPTO_T::INTSTS: AESIF Position       */
#define CRYPTO_INTSTS_AESIF_Msk          (0x1ul << CRYPTO_INTSTS_AESIF_Pos)                /*!< CRYPTO_T::INTSTS: AESIF Mask           */

#define CRYPTO_INTSTS_AESEIF_Pos         (1)                                               /*!< CRYPTO_T::INTSTS: AESEIF Position      */
#define CRYPTO_INTSTS_AESEIF_Msk         (0x1ul << CRYPTO_INTSTS_AESEIF_Pos)               /*!< CRYPTO_T::INTSTS: AESEIF Mask          */

#define CRYPTO_INTSTS_PRNGIF_Pos         (16)                                              /*!< CRYPTO_T::INTSTS: PRNGIF Position      */
#define CRYPTO_INTSTS_PRNGIF_Msk         (0x1ul << CRYPTO_INTSTS_PRNGIF_Pos)               /*!< CRYPTO_T::INTSTS: PRNGIF Mask          */

#define CRYPTO_INTSTS_PRNGEIF_Pos        (17)                                              /*!< CRYPTO_T::INTSTS: PRNGEIF Position     */
#define CRYPTO_INTSTS_PRNGEIF_Msk        (0x1ul << CRYPTO_INTSTS_PRNGEIF_Pos)              /*!< CRYPTO_T::INTSTS: PRNGEIF Mask         */

#define CRYPTO_INTSTS_ECCIF_Pos          (22)                                              /*!< CRYPTO_T::INTSTS: ECCIF Position       */
#define CRYPTO_INTSTS_ECCIF_Msk          (0x1ul << CRYPTO_INTSTS_ECCIF_Pos)                /*!< CRYPTO_T::INTSTS: ECCIF Mask           */

#define CRYPTO_INTSTS_ECCEIF_Pos         (23)                                              /*!< CRYPTO_T::INTSTS: ECCEIF Position      */
#define CRYPTO_INTSTS_ECCEIF_Msk         (0x1ul << CRYPTO_INTSTS_ECCEIF_Pos)               /*!< CRYPTO_T::INTSTS: ECCEIF Mask          */

#define CRYPTO_INTSTS_HMACIF_Pos         (24)                                              /*!< CRYPTO_T::INTSTS: HMACIF Position      */
#define CRYPTO_INTSTS_HMACIF_Msk         (0x1ul << CRYPTO_INTSTS_HMACIF_Pos)               /*!< CRYPTO_T::INTSTS: HMACIF Mask          */

#define CRYPTO_INTSTS_HMACEIF_Pos        (25)                                              /*!< CRYPTO_T::INTSTS: HMACEIF Position     */
#define CRYPTO_INTSTS_HMACEIF_Msk        (0x1ul << CRYPTO_INTSTS_HMACEIF_Pos)              /*!< CRYPTO_T::INTSTS: HMACEIF Mask         */

#define CRYPTO_INTSTS_RSAIF_Pos          (30)                                              /*!< CRYPTO_T::INTSTS: RSAIF Position       */
#define CRYPTO_INTSTS_RSAIF_Msk          (0x1ul << CRYPTO_INTSTS_RSAIF_Pos)                /*!< CRYPTO_T::INTSTS: RSAIF Mask           */

#define CRYPTO_INTSTS_RSAEIF_Pos         (31)                                              /*!< CRYPTO_T::INTSTS: RSAEIF Position      */
#define CRYPTO_INTSTS_RSAEIF_Msk         (0x1ul << CRYPTO_INTSTS_RSAEIF_Pos)               /*!< CRYPTO_T::INTSTS: RSAEIF Mask          */

#define CRYPTO_PRNG_CTL_START_Pos        (0)                                               /*!< CRYPTO_T::PRNG_CTL: START Position     */
#define CRYPTO_PRNG_CTL_START_Msk        (0x1ul << CRYPTO_PRNG_CTL_START_Pos)              /*!< CRYPTO_T::PRNG_CTL: START Mask         */

#define CRYPTO_PRNG_CTL_SEEDRLD_Pos      (1)                                               /*!< CRYPTO_T::PRNG_CTL: SEEDRLD Position   */
#define CRYPTO_PRNG_CTL_SEEDRLD_Msk      (0x1ul << CRYPTO_PRNG_CTL_SEEDRLD_Pos)            /*!< CRYPTO_T::PRNG_CTL: SEEDRLD Mask       */

#define CRYPTO_PRNG_CTL_KEYSZ_Pos        (2)                                               /*!< CRYPTO_T::PRNG_CTL: KEYSZ Position     */
#define CRYPTO_PRNG_CTL_KEYSZ_Msk        (0xful << CRYPTO_PRNG_CTL_KEYSZ_Pos)              /*!< CRYPTO_T::PRNG_CTL: KEYSZ Mask         */

#define CRYPTO_PRNG_CTL_BUSY_Pos         (8)                                               /*!< CRYPTO_T::PRNG_CTL: BUSY Position      */
#define CRYPTO_PRNG_CTL_BUSY_Msk         (0x1ul << CRYPTO_PRNG_CTL_BUSY_Pos)               /*!< CRYPTO_T::PRNG_CTL: BUSY Mask          */

#define CRYPTO_PRNG_SEED_SEED_Pos        (0)                                               /*!< CRYPTO_T::PRNG_SEED: SEED Position     */
#define CRYPTO_PRNG_SEED_SEED_Msk        (0xfffffffful << CRYPTO_PRNG_SEED_SEED_Pos)       /*!< CRYPTO_T::PRNG_SEED: SEED Mask         */

#define CRYPTO_PRNG_KEY0_KEY_Pos         (0)                                               /*!< CRYPTO_T::PRNG_KEY0: KEY Position      */
#define CRYPTO_PRNG_KEY0_KEY_Msk         (0xfffffffful << CRYPTO_PRNG_KEY0_KEY_Pos)        /*!< CRYPTO_T::PRNG_KEY0: KEY Mask          */

#define CRYPTO_PRNG_KEY1_KEY_Pos         (0)                                               /*!< CRYPTO_T::PRNG_KEY1: KEY Position      */
#define CRYPTO_PRNG_KEY1_KEY_Msk         (0xfffffffful << CRYPTO_PRNG_KEY1_KEY_Pos)        /*!< CRYPTO_T::PRNG_KEY1: KEY Mask          */

#define CRYPTO_PRNG_KEY2_KEY_Pos         (0)                                               /*!< CRYPTO_T::PRNG_KEY2: KEY Position      */
#define CRYPTO_PRNG_KEY2_KEY_Msk         (0xfffffffful << CRYPTO_PRNG_KEY2_KEY_Pos)        /*!< CRYPTO_T::PRNG_KEY2: KEY Mask          */

#define CRYPTO_PRNG_KEY3_KEY_Pos         (0)                                               /*!< CRYPTO_T::PRNG_KEY3: KEY Position      */
#define CRYPTO_PRNG_KEY3_KEY_Msk         (0xfffffffful << CRYPTO_PRNG_KEY3_KEY_Pos)        /*!< CRYPTO_T::PRNG_KEY3: KEY Mask          */

#define CRYPTO_PRNG_KEY4_KEY_Pos         (0)                                               /*!< CRYPTO_T::PRNG_KEY4: KEY Position      */
#define CRYPTO_PRNG_KEY4_KEY_Msk         (0xfffffffful << CRYPTO_PRNG_KEY4_KEY_Pos)        /*!< CRYPTO_T::PRNG_KEY4: KEY Mask          */

#define CRYPTO_PRNG_KEY5_KEY_Pos         (0)                                               /*!< CRYPTO_T::PRNG_KEY5: KEY Position      */
#define CRYPTO_PRNG_KEY5_KEY_Msk         (0xfffffffful << CRYPTO_PRNG_KEY5_KEY_Pos)        /*!< CRYPTO_T::PRNG_KEY5: KEY Mask          */

#define CRYPTO_PRNG_KEY6_KEY_Pos         (0)                                               /*!< CRYPTO_T::PRNG_KEY6: KEY Position      */
#define CRYPTO_PRNG_KEY6_KEY_Msk         (0xfffffffful << CRYPTO_PRNG_KEY6_KEY_Pos)        /*!< CRYPTO_T::PRNG_KEY6: KEY Mask          */

#define CRYPTO_PRNG_KEY7_KEY_Pos         (0)                                               /*!< CRYPTO_T::PRNG_KEY7: KEY Position      */
#define CRYPTO_PRNG_KEY7_KEY_Msk         (0xfffffffful << CRYPTO_PRNG_KEY7_KEY_Pos)        /*!< CRYPTO_T::PRNG_KEY7: KEY Mask          */

#define CRYPTO_PRNG_STS_BUSY_Pos         (0)                                               /*!< CRYPTO_T::PRNG_STS: BUSY Position      */
#define CRYPTO_PRNG_STS_BUSY_Msk         (0x1ul << CRYPTO_PRNG_STS_BUSY_Pos)               /*!< CRYPTO_T::PRNG_STS: BUSY Mask          */

#define CRYPTO_PRNG_STS_KSERR_Pos        (17)                                              /*!< CRYPTO_T::PRNG_STS: KSERR Position     */
#define CRYPTO_PRNG_STS_KSERR_Msk        (0x1ul << CRYPTO_PRNG_STS_KSERR_Pos)              /*!< CRYPTO_T::PRNG_STS: KSERR Mask         */

#define CRYPTO_AES_GCM_IVCNT0_CNT_Pos    (0)                                               /*!< CRYPTO_T::AES_GCM_IVCNT0: CNT Position */
#define CRYPTO_AES_GCM_IVCNT0_CNT_Msk    (0xfffffffful << CRYPTO_AES_GCM_IVCNT0_CNT_Pos)   /*!< CRYPTO_T::AES_GCM_IVCNT0: CNT Mask     */

#define CRYPTO_AES_GCM_IVCNT1_CNT_Pos    (0)                                               /*!< CRYPTO_T::AES_GCM_IVCNT1: CNT Position */
#define CRYPTO_AES_GCM_IVCNT1_CNT_Msk    (0x1ffffffful << CRYPTO_AES_GCM_IVCNT1_CNT_Pos)   /*!< CRYPTO_T::AES_GCM_IVCNT1: CNT Mask     */

#define CRYPTO_AES_GCM_ACNT0_CNT_Pos     (0)                                               /*!< CRYPTO_T::AES_GCM_ACNT0: CNT Position  */
#define CRYPTO_AES_GCM_ACNT0_CNT_Msk     (0xfffffffful << CRYPTO_AES_GCM_ACNT0_CNT_Pos)    /*!< CRYPTO_T::AES_GCM_ACNT0: CNT Mask      */

#define CRYPTO_AES_GCM_ACNT1_CNT_Pos     (0)                                               /*!< CRYPTO_T::AES_GCM_ACNT1: CNT Position  */
#define CRYPTO_AES_GCM_ACNT1_CNT_Msk     (0x1ffffffful << CRYPTO_AES_GCM_ACNT1_CNT_Pos)    /*!< CRYPTO_T::AES_GCM_ACNT1: CNT Mask      */

#define CRYPTO_AES_GCM_PCNT0_CNT_Pos     (0)                                               /*!< CRYPTO_T::AES_GCM_PCNT0: CNT Position  */
#define CRYPTO_AES_GCM_PCNT0_CNT_Msk     (0xfffffffful << CRYPTO_AES_GCM_PCNT0_CNT_Pos)    /*!< CRYPTO_T::AES_GCM_PCNT0: CNT Mask      */

#define CRYPTO_AES_GCM_PCNT1_CNT_Pos     (0)                                               /*!< CRYPTO_T::AES_GCM_PCNT1: CNT Position  */
#define CRYPTO_AES_GCM_PCNT1_CNT_Msk     (0x1ffffffful << CRYPTO_AES_GCM_PCNT1_CNT_Pos)    /*!< CRYPTO_T::AES_GCM_PCNT1: CNT Mask      */

#define CRYPTO_AES_FBADDR_FBADDR_Pos     (0)                                               /*!< CRYPTO_T::AES_FBADDR: FBADDR Position  */
#define CRYPTO_AES_FBADDR_FBADDR_Msk     (0xfffffffful << CRYPTO_AES_FBADDR_FBADDR_Pos)    /*!< CRYPTO_T::AES_FBADDR: FBADDR Mask      */

#define CRYPTO_AES_CTL_START_Pos         (0)                                               /*!< CRYPTO_T::AES_CTL: START Position      */
#define CRYPTO_AES_CTL_START_Msk         (0x1ul << CRYPTO_AES_CTL_START_Pos)               /*!< CRYPTO_T::AES_CTL: START Mask          */

#define CRYPTO_AES_CTL_STOP_Pos          (1)                                               /*!< CRYPTO_T::AES_CTL: STOP Position       */
#define CRYPTO_AES_CTL_STOP_Msk          (0x1ul << CRYPTO_AES_CTL_STOP_Pos)                /*!< CRYPTO_T::AES_CTL: STOP Mask           */

#define CRYPTO_AES_CTL_KEYSZ_Pos         (2)                                               /*!< CRYPTO_T::AES_CTL: KEYSZ Position      */
#define CRYPTO_AES_CTL_KEYSZ_Msk         (0x3ul << CRYPTO_AES_CTL_KEYSZ_Pos)               /*!< CRYPTO_T::AES_CTL: KEYSZ Mask          */

#define CRYPTO_AES_CTL_DMALAST_Pos       (5)                                               /*!< CRYPTO_T::AES_CTL: DMALAST Position    */
#define CRYPTO_AES_CTL_DMALAST_Msk       (0x1ul << CRYPTO_AES_CTL_DMALAST_Pos)             /*!< CRYPTO_T::AES_CTL: DMALAST Mask        */

#define CRYPTO_AES_CTL_DMACSCAD_Pos      (6)                                               /*!< CRYPTO_T::AES_CTL: DMACSCAD Position   */
#define CRYPTO_AES_CTL_DMACSCAD_Msk      (0x1ul << CRYPTO_AES_CTL_DMACSCAD_Pos)            /*!< CRYPTO_T::AES_CTL: DMACSCAD Mask       */

#define CRYPTO_AES_CTL_DMAEN_Pos         (7)                                               /*!< CRYPTO_T::AES_CTL: DMAEN Position      */
#define CRYPTO_AES_CTL_DMAEN_Msk         (0x1ul << CRYPTO_AES_CTL_DMAEN_Pos)               /*!< CRYPTO_T::AES_CTL: DMAEN Mask          */

#define CRYPTO_AES_CTL_OPMODE_Pos        (8)                                               /*!< CRYPTO_T::AES_CTL: OPMODE Position     */
#define CRYPTO_AES_CTL_OPMODE_Msk        (0xfful << CRYPTO_AES_CTL_OPMODE_Pos)             /*!< CRYPTO_T::AES_CTL: OPMODE Mask         */

#define CRYPTO_AES_CTL_ENCRYPT_Pos       (16)                                              /*!< CRYPTO_T::AES_CTL: ENCRYPT Position    */
#define CRYPTO_AES_CTL_ENCRYPT_Msk       (0x1ul << CRYPTO_AES_CTL_ENCRYPT_Pos)             /*!< CRYPTO_T::AES_CTL: ENCRYPT Mask        */

#define CRYPTO_AES_CTL_FBIN_Pos          (20)                                              /*!< CRYPTO_T::AES_CTL: FBIN Position       */
#define CRYPTO_AES_CTL_FBIN_Msk          (0x1ul << CRYPTO_AES_CTL_FBIN_Pos)                /*!< CRYPTO_T::AES_CTL: FBIN Mask           */

#define CRYPTO_AES_CTL_FBOUT_Pos         (21)                                              /*!< CRYPTO_T::AES_CTL: FBOUT Position      */
#define CRYPTO_AES_CTL_FBOUT_Msk         (0x1ul << CRYPTO_AES_CTL_FBOUT_Pos)               /*!< CRYPTO_T::AES_CTL: FBOUT Mask          */

#define CRYPTO_AES_CTL_OUTSWAP_Pos       (22)                                              /*!< CRYPTO_T::AES_CTL: OUTSWAP Position    */
#define CRYPTO_AES_CTL_OUTSWAP_Msk       (0x1ul << CRYPTO_AES_CTL_OUTSWAP_Pos)             /*!< CRYPTO_T::AES_CTL: OUTSWAP Mask        */

#define CRYPTO_AES_CTL_INSWAP_Pos        (23)                                              /*!< CRYPTO_T::AES_CTL: INSWAP Position     */
#define CRYPTO_AES_CTL_INSWAP_Msk        (0x1ul << CRYPTO_AES_CTL_INSWAP_Pos)              /*!< CRYPTO_T::AES_CTL: INSWAP Mask         */

#define CRYPTO_AES_CTL_KOUTSWAP_Pos      (24)                                              /*!< CRYPTO_T::AES_CTL: KOUTSWAP Position   */
#define CRYPTO_AES_CTL_KOUTSWAP_Msk      (0x1ul << CRYPTO_AES_CTL_KOUTSWAP_Pos)            /*!< CRYPTO_T::AES_CTL: KOUTSWAP Mask       */

#define CRYPTO_AES_CTL_KINSWAP_Pos       (25)                                              /*!< CRYPTO_T::AES_CTL: KINSWAP Position    */
#define CRYPTO_AES_CTL_KINSWAP_Msk       (0x1ul << CRYPTO_AES_CTL_KINSWAP_Pos)             /*!< CRYPTO_T::AES_CTL: KINSWAP Mask        */

#define CRYPTO_AES_CTL_KEYUNPRT_Pos      (26)                                              /*!< CRYPTO_T::AES_CTL: KEYUNPRT Position   */
#define CRYPTO_AES_CTL_KEYUNPRT_Msk      (0x1ful << CRYPTO_AES_CTL_KEYUNPRT_Pos)           /*!< CRYPTO_T::AES_CTL: KEYUNPRT Mask       */

#define CRYPTO_AES_CTL_KEYPRT_Pos        (31)                                              /*!< CRYPTO_T::AES_CTL: KEYPRT Position     */
#define CRYPTO_AES_CTL_KEYPRT_Msk        (0x1ul << CRYPTO_AES_CTL_KEYPRT_Pos)              /*!< CRYPTO_T::AES_CTL: KEYPRT Mask         */

#define CRYPTO_AES_STS_BUSY_Pos          (0)                                               /*!< CRYPTO_T::AES_STS: BUSY Position       */
#define CRYPTO_AES_STS_BUSY_Msk          (0x1ul << CRYPTO_AES_STS_BUSY_Pos)                /*!< CRYPTO_T::AES_STS: BUSY Mask           */

#define CRYPTO_AES_STS_INBUFEMPTY_Pos    (8)                                               /*!< CRYPTO_T::AES_STS: INBUFEMPTY Position */
#define CRYPTO_AES_STS_INBUFEMPTY_Msk    (0x1ul << CRYPTO_AES_STS_INBUFEMPTY_Pos)          /*!< CRYPTO_T::AES_STS: INBUFEMPTY Mask     */

#define CRYPTO_AES_STS_INBUFFULL_Pos     (9)                                               /*!< CRYPTO_T::AES_STS: INBUFFULL Position  */
#define CRYPTO_AES_STS_INBUFFULL_Msk     (0x1ul << CRYPTO_AES_STS_INBUFFULL_Pos)           /*!< CRYPTO_T::AES_STS: INBUFFULL Mask      */

#define CRYPTO_AES_STS_INBUFERR_Pos      (10)                                              /*!< CRYPTO_T::AES_STS: INBUFERR Position   */
#define CRYPTO_AES_STS_INBUFERR_Msk      (0x1ul << CRYPTO_AES_STS_INBUFERR_Pos)            /*!< CRYPTO_T::AES_STS: INBUFERR Mask       */

#define CRYPTO_AES_STS_CNTERR_Pos        (12)                                              /*!< CRYPTO_T::AES_STS: CNTERR Position     */
#define CRYPTO_AES_STS_CNTERR_Msk        (0x1ul << CRYPTO_AES_STS_CNTERR_Pos)              /*!< CRYPTO_T::AES_STS: CNTERR Mask         */

#define CRYPTO_AES_STS_OUTBUFEMPTY_Pos   (16)                                              /*!< CRYPTO_T::AES_STS: OUTBUFEMPTY Position*/
#define CRYPTO_AES_STS_OUTBUFEMPTY_Msk   (0x1ul << CRYPTO_AES_STS_OUTBUFEMPTY_Pos)         /*!< CRYPTO_T::AES_STS: OUTBUFEMPTY Mask    */

#define CRYPTO_AES_STS_OUTBUFFULL_Pos    (17)                                              /*!< CRYPTO_T::AES_STS: OUTBUFFULL Position */
#define CRYPTO_AES_STS_OUTBUFFULL_Msk    (0x1ul << CRYPTO_AES_STS_OUTBUFFULL_Pos)          /*!< CRYPTO_T::AES_STS: OUTBUFFULL Mask     */

#define CRYPTO_AES_STS_OUTBUFERR_Pos     (18)                                              /*!< CRYPTO_T::AES_STS: OUTBUFERR Position  */
#define CRYPTO_AES_STS_OUTBUFERR_Msk     (0x1ul << CRYPTO_AES_STS_OUTBUFERR_Pos)           /*!< CRYPTO_T::AES_STS: OUTBUFERR Mask      */

#define CRYPTO_AES_STS_BUSERR_Pos        (20)                                              /*!< CRYPTO_T::AES_STS: BUSERR Position     */
#define CRYPTO_AES_STS_BUSERR_Msk        (0x1ul << CRYPTO_AES_STS_BUSERR_Pos)              /*!< CRYPTO_T::AES_STS: BUSERR Mask         */

#define CRYPTO_AES_STS_KSERR_Pos         (21)                                              /*!< CRYPTO_T::AES_STS: KSERR Position      */
#define CRYPTO_AES_STS_KSERR_Msk         (0x1ul << CRYPTO_AES_STS_KSERR_Pos)               /*!< CRYPTO_T::AES_STS: KSERR Mask          */

#define CRYPTO_AES_DATIN_DATIN_Pos       (0)                                               /*!< CRYPTO_T::AES_DATIN: DATIN Position    */
#define CRYPTO_AES_DATIN_DATIN_Msk       (0xfffffffful << CRYPTO_AES_DATIN_DATIN_Pos)      /*!< CRYPTO_T::AES_DATIN: DATIN Mask        */

#define CRYPTO_AES_DATOUT_DATOUT_Pos     (0)                                               /*!< CRYPTO_T::AES_DATOUT: DATOUT Position  */
#define CRYPTO_AES_DATOUT_DATOUT_Msk     (0xfffffffful << CRYPTO_AES_DATOUT_DATOUT_Pos)    /*!< CRYPTO_T::AES_DATOUT: DATOUT Mask      */

#define CRYPTO_AES_KEY0_KEY_Pos          (0)                                               /*!< CRYPTO_T::AES_KEY0: KEY Position       */
#define CRYPTO_AES_KEY0_KEY_Msk          (0xfffffffful << CRYPTO_AES_KEY0_KEY_Pos)         /*!< CRYPTO_T::AES_KEY0: KEY Mask           */

#define CRYPTO_AES_KEY1_KEY_Pos          (0)                                               /*!< CRYPTO_T::AES_KEY1: KEY Position       */
#define CRYPTO_AES_KEY1_KEY_Msk          (0xfffffffful << CRYPTO_AES_KEY1_KEY_Pos)         /*!< CRYPTO_T::AES_KEY1: KEY Mask           */

#define CRYPTO_AES_KEY2_KEY_Pos          (0)                                               /*!< CRYPTO_T::AES_KEY2: KEY Position       */
#define CRYPTO_AES_KEY2_KEY_Msk          (0xfffffffful << CRYPTO_AES_KEY2_KEY_Pos)         /*!< CRYPTO_T::AES_KEY2: KEY Mask           */

#define CRYPTO_AES_KEY3_KEY_Pos          (0)                                               /*!< CRYPTO_T::AES_KEY3: KEY Position       */
#define CRYPTO_AES_KEY3_KEY_Msk          (0xfffffffful << CRYPTO_AES_KEY3_KEY_Pos)         /*!< CRYPTO_T::AES_KEY3: KEY Mask           */

#define CRYPTO_AES_KEY4_KEY_Pos          (0)                                               /*!< CRYPTO_T::AES_KEY4: KEY Position       */
#define CRYPTO_AES_KEY4_KEY_Msk          (0xfffffffful << CRYPTO_AES_KEY4_KEY_Pos)         /*!< CRYPTO_T::AES_KEY4: KEY Mask           */

#define CRYPTO_AES_KEY5_KEY_Pos          (0)                                               /*!< CRYPTO_T::AES_KEY5: KEY Position       */
#define CRYPTO_AES_KEY5_KEY_Msk          (0xfffffffful << CRYPTO_AES_KEY5_KEY_Pos)         /*!< CRYPTO_T::AES_KEY5: KEY Mask           */

#define CRYPTO_AES_KEY6_KEY_Pos          (0)                                               /*!< CRYPTO_T::AES_KEY6: KEY Position       */
#define CRYPTO_AES_KEY6_KEY_Msk          (0xfffffffful << CRYPTO_AES_KEY6_KEY_Pos)         /*!< CRYPTO_T::AES_KEY6: KEY Mask           */

#define CRYPTO_AES_KEY7_KEY_Pos          (0)                                               /*!< CRYPTO_T::AES_KEY7: KEY Position       */
#define CRYPTO_AES_KEY7_KEY_Msk          (0xfffffffful << CRYPTO_AES_KEY7_KEY_Pos)         /*!< CRYPTO_T::AES_KEY7: KEY Mask           */

#define CRYPTO_AES_IV0_IV_Pos            (0)                                               /*!< CRYPTO_T::AES_IV0: IV Position         */
#define CRYPTO_AES_IV0_IV_Msk            (0xfffffffful << CRYPTO_AES_IV0_IV_Pos)           /*!< CRYPTO_T::AES_IV0: IV Mask             */

#define CRYPTO_AES_IV1_IV_Pos            (0)                                               /*!< CRYPTO_T::AES_IV1: IV Position         */
#define CRYPTO_AES_IV1_IV_Msk            (0xfffffffful << CRYPTO_AES_IV1_IV_Pos)           /*!< CRYPTO_T::AES_IV1: IV Mask             */

#define CRYPTO_AES_IV2_IV_Pos            (0)                                               /*!< CRYPTO_T::AES_IV2: IV Position         */
#define CRYPTO_AES_IV2_IV_Msk            (0xfffffffful << CRYPTO_AES_IV2_IV_Pos)           /*!< CRYPTO_T::AES_IV2: IV Mask             */

#define CRYPTO_AES_IV3_IV_Pos            (0)                                               /*!< CRYPTO_T::AES_IV3: IV Position         */
#define CRYPTO_AES_IV3_IV_Msk            (0xfffffffful << CRYPTO_AES_IV3_IV_Pos)           /*!< CRYPTO_T::AES_IV3: IV Mask             */

#define CRYPTO_AES_SADDR_SADDR_Pos       (0)                                               /*!< CRYPTO_T::AES_SADDR: SADDR Position    */
#define CRYPTO_AES_SADDR_SADDR_Msk       (0xfffffffful << CRYPTO_AES_SADDR_SADDR_Pos)      /*!< CRYPTO_T::AES_SADDR: SADDR Mask        */

#define CRYPTO_AES_DADDR_DADDR_Pos       (0)                                               /*!< CRYPTO_T::AES_DADDR: DADDR Position    */
#define CRYPTO_AES_DADDR_DADDR_Msk       (0xfffffffful << CRYPTO_AES_DADDR_DADDR_Pos)      /*!< CRYPTO_T::AES_DADDR: DADDR Mask        */

#define CRYPTO_AES_CNT_CNT_Pos           (0)                                               /*!< CRYPTO_T::AES_CNT: CNT Position        */
#define CRYPTO_AES_CNT_CNT_Msk           (0xfffffffful << CRYPTO_AES_CNT_CNT_Pos)          /*!< CRYPTO_T::AES_CNT: CNT Mask            */

#define CRYPTO_HMAC_CTL_START_Pos        (0)                                               /*!< CRYPTO_T::HMAC_CTL: START Position     */
#define CRYPTO_HMAC_CTL_START_Msk        (0x1ul << CRYPTO_HMAC_CTL_START_Pos)              /*!< CRYPTO_T::HMAC_CTL: START Mask         */

#define CRYPTO_HMAC_CTL_STOP_Pos         (1)                                               /*!< CRYPTO_T::HMAC_CTL: STOP Position      */
#define CRYPTO_HMAC_CTL_STOP_Msk         (0x1ul << CRYPTO_HMAC_CTL_STOP_Pos)               /*!< CRYPTO_T::HMAC_CTL: STOP Mask          */

#define CRYPTO_HMAC_CTL_DMAFIRST_Pos     (4)                                               /*!< CRYPTO_T::HMAC_CTL: DMAFIRST Position  */
#define CRYPTO_HMAC_CTL_DMAFIRST_Msk     (0x1ul << CRYPTO_HMAC_CTL_DMAFIRST_Pos)           /*!< CRYPTO_T::HMAC_CTL: DMAFIRST Mask      */

#define CRYPTO_HMAC_CTL_DMALAST_Pos      (5)                                               /*!< CRYPTO_T::HMAC_CTL: DMALAST Position   */
#define CRYPTO_HMAC_CTL_DMALAST_Msk      (0x1ul << CRYPTO_HMAC_CTL_DMALAST_Pos)            /*!< CRYPTO_T::HMAC_CTL: DMALAST Mask       */

#define CRYPTO_HMAC_CTL_DMACSCAD_Pos     (6)                                               /*!< CRYPTO_T::HMAC_CTL: DMACSCAD Position  */
#define CRYPTO_HMAC_CTL_DMACSCAD_Msk     (0x1ul << CRYPTO_HMAC_CTL_DMACSCAD_Pos)           /*!< CRYPTO_T::HMAC_CTL: DMACSCAD Mask      */

#define CRYPTO_HMAC_CTL_DMAEN_Pos        (7)                                               /*!< CRYPTO_T::HMAC_CTL: DMAEN Position     */
#define CRYPTO_HMAC_CTL_DMAEN_Msk        (0x1ul << CRYPTO_HMAC_CTL_DMAEN_Pos)              /*!< CRYPTO_T::HMAC_CTL: DMAEN Mask         */

#define CRYPTO_HMAC_CTL_OPMODE_Pos       (8)                                               /*!< CRYPTO_T::HMAC_CTL: OPMODE Position    */
#define CRYPTO_HMAC_CTL_OPMODE_Msk       (0x7ul << CRYPTO_HMAC_CTL_OPMODE_Pos)             /*!< CRYPTO_T::HMAC_CTL: OPMODE Mask        */

#define CRYPTO_HMAC_CTL_HMACEN_Pos       (11)                                              /*!< CRYPTO_T::HMAC_CTL: HMACEN Position    */
#define CRYPTO_HMAC_CTL_HMACEN_Msk       (0x1ul << CRYPTO_HMAC_CTL_HMACEN_Pos)             /*!< CRYPTO_T::HMAC_CTL: HMACEN Mask        */

#define CRYPTO_HMAC_CTL_SHA3EN_Pos       (12)                                              /*!< CRYPTO_T::HMAC_CTL: SHA3EN Position    */
#define CRYPTO_HMAC_CTL_SHA3EN_Msk       (0x1ul << CRYPTO_HMAC_CTL_SHA3EN_Pos)             /*!< CRYPTO_T::HMAC_CTL: SHA3EN Mask        */

#define CRYPTO_HMAC_CTL_MD5EN_Pos        (14)                                              /*!< CRYPTO_T::HMAC_CTL: MD5EN Position     */
#define CRYPTO_HMAC_CTL_MD5EN_Msk        (0x1ul << CRYPTO_HMAC_CTL_MD5EN_Pos)              /*!< CRYPTO_T::HMAC_CTL: MD5EN Mask         */

#define CRYPTO_HMAC_CTL_FBIN_Pos         (20)                                              /*!< CRYPTO_T::HMAC_CTL: FBIN Position      */
#define CRYPTO_HMAC_CTL_FBIN_Msk         (0x1ul << CRYPTO_HMAC_CTL_FBIN_Pos)               /*!< CRYPTO_T::HMAC_CTL: FBIN Mask          */

#define CRYPTO_HMAC_CTL_FBOUT_Pos        (21)                                              /*!< CRYPTO_T::HMAC_CTL: FBOUT Position     */
#define CRYPTO_HMAC_CTL_FBOUT_Msk        (0x1ul << CRYPTO_HMAC_CTL_FBOUT_Pos)              /*!< CRYPTO_T::HMAC_CTL: FBOUT Mask         */

#define CRYPTO_HMAC_CTL_OUTSWAP_Pos      (22)                                              /*!< CRYPTO_T::HMAC_CTL: OUTSWAP Position   */
#define CRYPTO_HMAC_CTL_OUTSWAP_Msk      (0x1ul << CRYPTO_HMAC_CTL_OUTSWAP_Pos)            /*!< CRYPTO_T::HMAC_CTL: OUTSWAP Mask       */

#define CRYPTO_HMAC_CTL_INSWAP_Pos       (23)                                              /*!< CRYPTO_T::HMAC_CTL: INSWAP Position    */
#define CRYPTO_HMAC_CTL_INSWAP_Msk       (0x1ul << CRYPTO_HMAC_CTL_INSWAP_Pos)             /*!< CRYPTO_T::HMAC_CTL: INSWAP Mask        */

#define CRYPTO_HMAC_CTL_NEXTDGST_Pos     (24)                                              /*!< CRYPTO_T::HMAC_CTL: NEXTDGST Position  */
#define CRYPTO_HMAC_CTL_NEXTDGST_Msk     (0x1ul << CRYPTO_HMAC_CTL_NEXTDGST_Pos)           /*!< CRYPTO_T::HMAC_CTL: NEXTDGST Mask      */

#define CRYPTO_HMAC_CTL_FINISHDGST_Pos   (25)                                              /*!< CRYPTO_T::HMAC_CTL: FINISHDGST Position*/
#define CRYPTO_HMAC_CTL_FINISHDGST_Msk   (0x1ul << CRYPTO_HMAC_CTL_FINISHDGST_Pos)         /*!< CRYPTO_T::HMAC_CTL: FINISHDGST Mask    */

#define CRYPTO_HMAC_STS_BUSY_Pos         (0)                                               /*!< CRYPTO_T::HMAC_STS: BUSY Position      */
#define CRYPTO_HMAC_STS_BUSY_Msk         (0x1ul << CRYPTO_HMAC_STS_BUSY_Pos)               /*!< CRYPTO_T::HMAC_STS: BUSY Mask          */

#define CRYPTO_HMAC_STS_DMABUSY_Pos      (1)                                               /*!< CRYPTO_T::HMAC_STS: DMABUSY Position   */
#define CRYPTO_HMAC_STS_DMABUSY_Msk      (0x1ul << CRYPTO_HMAC_STS_DMABUSY_Pos)            /*!< CRYPTO_T::HMAC_STS: DMABUSY Mask       */

#define CRYPTO_HMAC_STS_SHAKEBUSY_Pos    (2)                                               /*!< CRYPTO_T::HMAC_STS: SHAKEBUSY Position */
#define CRYPTO_HMAC_STS_SHAKEBUSY_Msk    (0x1ul << CRYPTO_HMAC_STS_SHAKEBUSY_Pos)          /*!< CRYPTO_T::HMAC_STS: SHAKEBUSY Mask     */

#define CRYPTO_HMAC_STS_DMAERR_Pos       (8)                                               /*!< CRYPTO_T::HMAC_STS: DMAERR Position    */
#define CRYPTO_HMAC_STS_DMAERR_Msk       (0x1ul << CRYPTO_HMAC_STS_DMAERR_Pos)             /*!< CRYPTO_T::HMAC_STS: DMAERR Mask        */

#define CRYPTO_HMAC_STS_KSERR_Pos        (9)                                               /*!< CRYPTO_T::HMAC_STS: KSERR Position     */
#define CRYPTO_HMAC_STS_KSERR_Msk        (0x1ul << CRYPTO_HMAC_STS_KSERR_Pos)              /*!< CRYPTO_T::HMAC_STS: KSERR Mask         */

#define CRYPTO_HMAC_STS_DATINREQ_Pos     (16)                                              /*!< CRYPTO_T::HMAC_STS: DATINREQ Position  */
#define CRYPTO_HMAC_STS_DATINREQ_Msk     (0x1ul << CRYPTO_HMAC_STS_DATINREQ_Pos)           /*!< CRYPTO_T::HMAC_STS: DATINREQ Mask      */

#define CRYPTO_HMAC_DGST0_DGST_Pos       (0)                                               /*!< CRYPTO_T::HMAC_DGST0: DGST Position    */
#define CRYPTO_HMAC_DGST0_DGST_Msk       (0xfffffffful << CRYPTO_HMAC_DGST0_DGST_Pos)      /*!< CRYPTO_T::HMAC_DGST0: DGST Mask        */

#define CRYPTO_HMAC_DGST1_DGST_Pos       (0)                                               /*!< CRYPTO_T::HMAC_DGST1: DGST Position    */
#define CRYPTO_HMAC_DGST1_DGST_Msk       (0xfffffffful << CRYPTO_HMAC_DGST1_DGST_Pos)      /*!< CRYPTO_T::HMAC_DGST1: DGST Mask        */

#define CRYPTO_HMAC_DGST2_DGST_Pos       (0)                                               /*!< CRYPTO_T::HMAC_DGST2: DGST Position    */
#define CRYPTO_HMAC_DGST2_DGST_Msk       (0xfffffffful << CRYPTO_HMAC_DGST2_DGST_Pos)      /*!< CRYPTO_T::HMAC_DGST2: DGST Mask        */

#define CRYPTO_HMAC_DGST3_DGST_Pos       (0)                                               /*!< CRYPTO_T::HMAC_DGST3: DGST Position    */
#define CRYPTO_HMAC_DGST3_DGST_Msk       (0xfffffffful << CRYPTO_HMAC_DGST3_DGST_Pos)      /*!< CRYPTO_T::HMAC_DGST3: DGST Mask        */

#define CRYPTO_HMAC_DGST4_DGST_Pos       (0)                                               /*!< CRYPTO_T::HMAC_DGST4: DGST Position    */
#define CRYPTO_HMAC_DGST4_DGST_Msk       (0xfffffffful << CRYPTO_HMAC_DGST4_DGST_Pos)      /*!< CRYPTO_T::HMAC_DGST4: DGST Mask        */

#define CRYPTO_HMAC_DGST5_DGST_Pos       (0)                                               /*!< CRYPTO_T::HMAC_DGST5: DGST Position    */
#define CRYPTO_HMAC_DGST5_DGST_Msk       (0xfffffffful << CRYPTO_HMAC_DGST5_DGST_Pos)      /*!< CRYPTO_T::HMAC_DGST5: DGST Mask        */

#define CRYPTO_HMAC_DGST6_DGST_Pos       (0)                                               /*!< CRYPTO_T::HMAC_DGST6: DGST Position    */
#define CRYPTO_HMAC_DGST6_DGST_Msk       (0xfffffffful << CRYPTO_HMAC_DGST6_DGST_Pos)      /*!< CRYPTO_T::HMAC_DGST6: DGST Mask        */

#define CRYPTO_HMAC_DGST7_DGST_Pos       (0)                                               /*!< CRYPTO_T::HMAC_DGST7: DGST Position    */
#define CRYPTO_HMAC_DGST7_DGST_Msk       (0xfffffffful << CRYPTO_HMAC_DGST7_DGST_Pos)      /*!< CRYPTO_T::HMAC_DGST7: DGST Mask        */

#define CRYPTO_HMAC_DGST8_DGST_Pos       (0)                                               /*!< CRYPTO_T::HMAC_DGST8: DGST Position    */
#define CRYPTO_HMAC_DGST8_DGST_Msk       (0xfffffffful << CRYPTO_HMAC_DGST8_DGST_Pos)      /*!< CRYPTO_T::HMAC_DGST8: DGST Mask        */

#define CRYPTO_HMAC_DGST9_DGST_Pos       (0)                                               /*!< CRYPTO_T::HMAC_DGST9: DGST Position    */
#define CRYPTO_HMAC_DGST9_DGST_Msk       (0xfffffffful << CRYPTO_HMAC_DGST9_DGST_Pos)      /*!< CRYPTO_T::HMAC_DGST9: DGST Mask        */

#define CRYPTO_HMAC_DGST10_DGST_Pos      (0)                                               /*!< CRYPTO_T::HMAC_DGST10: DGST Position   */
#define CRYPTO_HMAC_DGST10_DGST_Msk      (0xfffffffful << CRYPTO_HMAC_DGST10_DGST_Pos)     /*!< CRYPTO_T::HMAC_DGST10: DGST Mask       */

#define CRYPTO_HMAC_DGST11_DGST_Pos      (0)                                               /*!< CRYPTO_T::HMAC_DGST11: DGST Position   */
#define CRYPTO_HMAC_DGST11_DGST_Msk      (0xfffffffful << CRYPTO_HMAC_DGST11_DGST_Pos)     /*!< CRYPTO_T::HMAC_DGST11: DGST Mask       */

#define CRYPTO_HMAC_DGST12_DGST_Pos      (0)                                               /*!< CRYPTO_T::HMAC_DGST12: DGST Position   */
#define CRYPTO_HMAC_DGST12_DGST_Msk      (0xfffffffful << CRYPTO_HMAC_DGST12_DGST_Pos)     /*!< CRYPTO_T::HMAC_DGST12: DGST Mask       */

#define CRYPTO_HMAC_DGST13_DGST_Pos      (0)                                               /*!< CRYPTO_T::HMAC_DGST13: DGST Position   */
#define CRYPTO_HMAC_DGST13_DGST_Msk      (0xfffffffful << CRYPTO_HMAC_DGST13_DGST_Pos)     /*!< CRYPTO_T::HMAC_DGST13: DGST Mask       */

#define CRYPTO_HMAC_DGST14_DGST_Pos      (0)                                               /*!< CRYPTO_T::HMAC_DGST14: DGST Position   */
#define CRYPTO_HMAC_DGST14_DGST_Msk      (0xfffffffful << CRYPTO_HMAC_DGST14_DGST_Pos)     /*!< CRYPTO_T::HMAC_DGST14: DGST Mask       */

#define CRYPTO_HMAC_DGST15_DGST_Pos      (0)                                               /*!< CRYPTO_T::HMAC_DGST15: DGST Position   */
#define CRYPTO_HMAC_DGST15_DGST_Msk      (0xfffffffful << CRYPTO_HMAC_DGST15_DGST_Pos)     /*!< CRYPTO_T::HMAC_DGST15: DGST Mask       */

#define CRYPTO_HMAC_KEYCNT_KEYCNT_Pos    (0)                                               /*!< CRYPTO_T::HMAC_KEYCNT: KEYCNT Position */
#define CRYPTO_HMAC_KEYCNT_KEYCNT_Msk    (0xfffffffful << CRYPTO_HMAC_KEYCNT_KEYCNT_Pos)   /*!< CRYPTO_T::HMAC_KEYCNT: KEYCNT Mask     */

#define CRYPTO_HMAC_SADDR_SADDR_Pos      (0)                                               /*!< CRYPTO_T::HMAC_SADDR: SADDR Position   */
#define CRYPTO_HMAC_SADDR_SADDR_Msk      (0xfffffffful << CRYPTO_HMAC_SADDR_SADDR_Pos)     /*!< CRYPTO_T::HMAC_SADDR: SADDR Mask       */

#define CRYPTO_HMAC_DMACNT_DMACNT_Pos    (0)                                               /*!< CRYPTO_T::HMAC_DMACNT: DMACNT Position */
#define CRYPTO_HMAC_DMACNT_DMACNT_Msk    (0xfffffffful << CRYPTO_HMAC_DMACNT_DMACNT_Pos)   /*!< CRYPTO_T::HMAC_DMACNT: DMACNT Mask     */

#define CRYPTO_HMAC_DATIN_DATIN_Pos      (0)                                               /*!< CRYPTO_T::HMAC_DATIN: DATIN Position   */
#define CRYPTO_HMAC_DATIN_DATIN_Msk      (0xfffffffful << CRYPTO_HMAC_DATIN_DATIN_Pos)     /*!< CRYPTO_T::HMAC_DATIN: DATIN Mask       */

#define CRYPTO_HMAC_DOMCNT_DOMCNT_Pos    (0)                                               /*!< CRYPTO_T::HMAC_DOMCNT: DOMCNT Position */
#define CRYPTO_HMAC_DOMCNT_DOMCNT_Msk    (0x1fful << CRYPTO_HMAC_DOMCNT_DOMCNT_Pos)        /*!< CRYPTO_T::HMAC_DOMCNT: DOMCNT Mask     */

#define CRYPTO_HMAC_SHA512T_SHA512TEN_Pos (0)                                              /*!< CRYPTO_T::HMAC_SHA512T: SHA512TEN Position*/
#define CRYPTO_HMAC_SHA512T_SHA512TEN_Msk (0x1ul << CRYPTO_HMAC_SHA512T_SHA512TEN_Pos)     /*!< CRYPTO_T::HMAC_SHA512T: SHA512TEN Mask */

#define CRYPTO_HMAC_SHA512T_TLEN_Pos     (8)                                               /*!< CRYPTO_T::HMAC_SHA512T: TLEN Position  */
#define CRYPTO_HMAC_SHA512T_TLEN_Msk     (0x1fful << CRYPTO_HMAC_SHA512T_TLEN_Pos)         /*!< CRYPTO_T::HMAC_SHA512T: TLEN Mask      */

#define CRYPTO_HMAC_FBADDR_FBADDR_Pos    (0)                                               /*!< CRYPTO_T::HMAC_FBADDR: FBADDR Position */
#define CRYPTO_HMAC_FBADDR_FBADDR_Msk    (0xfffffffful << CRYPTO_HMAC_FBADDR_FBADDR_Pos)   /*!< CRYPTO_T::HMAC_FBADDR: FBADDR Mask     */

#define CRYPTO_HMAC_SHAKEDGST0_DGST_Pos  (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST0: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST0_DGST_Msk  (0xfffffffful << CRYPTO_HMAC_SHAKEDGST0_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST0: DGST Mask   */

#define CRYPTO_HMAC_SHAKEDGST1_DGST_Pos  (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST1: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST1_DGST_Msk  (0xfffffffful << CRYPTO_HMAC_SHAKEDGST1_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST1: DGST Mask   */

#define CRYPTO_HMAC_SHAKEDGST2_DGST_Pos  (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST2: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST2_DGST_Msk  (0xfffffffful << CRYPTO_HMAC_SHAKEDGST2_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST2: DGST Mask   */

#define CRYPTO_HMAC_SHAKEDGST3_DGST_Pos  (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST3: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST3_DGST_Msk  (0xfffffffful << CRYPTO_HMAC_SHAKEDGST3_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST3: DGST Mask   */

#define CRYPTO_HMAC_SHAKEDGST4_DGST_Pos  (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST4: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST4_DGST_Msk  (0xfffffffful << CRYPTO_HMAC_SHAKEDGST4_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST4: DGST Mask   */

#define CRYPTO_HMAC_SHAKEDGST5_DGST_Pos  (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST5: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST5_DGST_Msk  (0xfffffffful << CRYPTO_HMAC_SHAKEDGST5_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST5: DGST Mask   */

#define CRYPTO_HMAC_SHAKEDGST6_DGST_Pos  (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST6: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST6_DGST_Msk  (0xfffffffful << CRYPTO_HMAC_SHAKEDGST6_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST6: DGST Mask   */

#define CRYPTO_HMAC_SHAKEDGST7_DGST_Pos  (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST7: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST7_DGST_Msk  (0xfffffffful << CRYPTO_HMAC_SHAKEDGST7_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST7: DGST Mask   */

#define CRYPTO_HMAC_SHAKEDGST8_DGST_Pos  (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST8: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST8_DGST_Msk  (0xfffffffful << CRYPTO_HMAC_SHAKEDGST8_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST8: DGST Mask   */

#define CRYPTO_HMAC_SHAKEDGST9_DGST_Pos  (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST9: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST9_DGST_Msk  (0xfffffffful << CRYPTO_HMAC_SHAKEDGST9_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST9: DGST Mask   */

#define CRYPTO_HMAC_SHAKEDGST10_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST10: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST10_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST10_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST10: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST11_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST11: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST11_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST11_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST11: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST12_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST12: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST12_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST12_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST12: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST13_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST13: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST13_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST13_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST13: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST14_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST14: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST14_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST14_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST14: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST15_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST15: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST15_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST15_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST15: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST16_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST16: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST16_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST16_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST16: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST17_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST17: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST17_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST17_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST17: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST18_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST18: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST18_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST18_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST18: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST19_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST19: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST19_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST19_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST19: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST20_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST20: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST20_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST20_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST20: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST21_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST21: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST21_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST21_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST21: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST22_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST22: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST22_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST22_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST22: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST23_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST23: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST23_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST23_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST23: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST24_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST24: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST24_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST24_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST24: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST25_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST25: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST25_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST25_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST25: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST26_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST26: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST26_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST26_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST26: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST27_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST27: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST27_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST27_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST27: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST28_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST28: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST28_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST28_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST28: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST29_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST29: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST29_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST29_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST29: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST30_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST30: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST30_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST30_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST30: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST31_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST31: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST31_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST31_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST31: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST32_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST32: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST32_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST32_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST32: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST33_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST33: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST33_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST33_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST33: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST34_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST34: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST34_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST34_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST34: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST35_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST35: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST35_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST35_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST35: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST36_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST36: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST36_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST36_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST36: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST37_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST37: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST37_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST37_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST37: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST38_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST38: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST38_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST38_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST38: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST39_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST39: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST39_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST39_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST39: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST40_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST40: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST40_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST40_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST40: DGST Mask  */

#define CRYPTO_HMAC_SHAKEDGST41_DGST_Pos (0)                                               /*!< CRYPTO_T::HMAC_SHAKEDGST41: DGST Position*/
#define CRYPTO_HMAC_SHAKEDGST41_DGST_Msk (0xfffffffful << CRYPTO_HMAC_SHAKEDGST41_DGST_Pos) /*!< CRYPTO_T::HMAC_SHAKEDGST41: DGST Mask  */

#define CRYPTO_ECC_CTL_START_Pos         (0)                                               /*!< CRYPTO_T::ECC_CTL: START Position      */
#define CRYPTO_ECC_CTL_START_Msk         (0x1ul << CRYPTO_ECC_CTL_START_Pos)               /*!< CRYPTO_T::ECC_CTL: START Mask          */

#define CRYPTO_ECC_CTL_STOP_Pos          (1)                                               /*!< CRYPTO_T::ECC_CTL: STOP Position       */
#define CRYPTO_ECC_CTL_STOP_Msk          (0x1ul << CRYPTO_ECC_CTL_STOP_Pos)                /*!< CRYPTO_T::ECC_CTL: STOP Mask           */

#define CRYPTO_ECC_CTL_SMOD_Pos          (2)                                               /*!< CRYPTO_T::ECC_CTL: SMOD Position       */
#define CRYPTO_ECC_CTL_SMOD_Msk          (0x1ul << CRYPTO_ECC_CTL_SMOD_Pos)                /*!< CRYPTO_T::ECC_CTL: SMOD Mask           */

#define CRYPTO_ECC_CTL_ECDSAS_Pos        (4)                                               /*!< CRYPTO_T::ECC_CTL: ECDSAS Position     */
#define CRYPTO_ECC_CTL_ECDSAS_Msk        (0x1ul << CRYPTO_ECC_CTL_ECDSAS_Pos)              /*!< CRYPTO_T::ECC_CTL: ECDSAS Mask         */

#define CRYPTO_ECC_CTL_ECDSAR_Pos        (5)                                               /*!< CRYPTO_T::ECC_CTL: ECDSAR Position     */
#define CRYPTO_ECC_CTL_ECDSAR_Msk        (0x1ul << CRYPTO_ECC_CTL_ECDSAR_Pos)              /*!< CRYPTO_T::ECC_CTL: ECDSAR Mask         */

#define CRYPTO_ECC_CTL_DMAEN_Pos         (7)                                               /*!< CRYPTO_T::ECC_CTL: DMAEN Position      */
#define CRYPTO_ECC_CTL_DMAEN_Msk         (0x1ul << CRYPTO_ECC_CTL_DMAEN_Pos)               /*!< CRYPTO_T::ECC_CTL: DMAEN Mask          */

#define CRYPTO_ECC_CTL_FSEL_Pos          (8)                                               /*!< CRYPTO_T::ECC_CTL: FSEL Position       */
#define CRYPTO_ECC_CTL_FSEL_Msk          (0x1ul << CRYPTO_ECC_CTL_FSEL_Pos)                /*!< CRYPTO_T::ECC_CTL: FSEL Mask           */

#define CRYPTO_ECC_CTL_ECCOP_Pos         (9)                                               /*!< CRYPTO_T::ECC_CTL: ECCOP Position      */
#define CRYPTO_ECC_CTL_ECCOP_Msk         (0x3ul << CRYPTO_ECC_CTL_ECCOP_Pos)               /*!< CRYPTO_T::ECC_CTL: ECCOP Mask          */

#define CRYPTO_ECC_CTL_MODOP_Pos         (11)                                              /*!< CRYPTO_T::ECC_CTL: MODOP Position      */
#define CRYPTO_ECC_CTL_MODOP_Msk         (0x3ul << CRYPTO_ECC_CTL_MODOP_Pos)               /*!< CRYPTO_T::ECC_CTL: MODOP Mask          */

#define CRYPTO_ECC_CTL_SPCEN_Pos         (13)                                              /*!< CRYPTO_T::ECC_CTL: SPCEN Position      */
#define CRYPTO_ECC_CTL_SPCEN_Msk         (0x1ul << CRYPTO_ECC_CTL_SPCEN_Pos)               /*!< CRYPTO_T::ECC_CTL: SPCEN Mask          */

#define CRYPTO_ECC_CTL_SPCSEL_Pos        (16)                                              /*!< CRYPTO_T::ECC_CTL: SPCSEL Position     */
#define CRYPTO_ECC_CTL_SPCSEL_Msk        (0x1ul << CRYPTO_ECC_CTL_SPCSEL_Pos)              /*!< CRYPTO_T::ECC_CTL: SPCSEL Mask         */

#define CRYPTO_ECC_CTL_CURVEM_Pos        (22)                                              /*!< CRYPTO_T::ECC_CTL: CURVEM Position     */
#define CRYPTO_ECC_CTL_CURVEM_Msk        (0x3fful << CRYPTO_ECC_CTL_CURVEM_Pos)            /*!< CRYPTO_T::ECC_CTL: CURVEM Mask         */

#define CRYPTO_ECC_STS_BUSY_Pos          (0)                                               /*!< CRYPTO_T::ECC_STS: BUSY Position       */
#define CRYPTO_ECC_STS_BUSY_Msk          (0x1ul << CRYPTO_ECC_STS_BUSY_Pos)                /*!< CRYPTO_T::ECC_STS: BUSY Mask           */

#define CRYPTO_ECC_STS_DMABUSY_Pos       (1)                                               /*!< CRYPTO_T::ECC_STS: DMABUSY Position    */
#define CRYPTO_ECC_STS_DMABUSY_Msk       (0x1ul << CRYPTO_ECC_STS_DMABUSY_Pos)             /*!< CRYPTO_T::ECC_STS: DMABUSY Mask        */

#define CRYPTO_ECC_STS_BUSERR_Pos        (16)                                              /*!< CRYPTO_T::ECC_STS: BUSERR Position     */
#define CRYPTO_ECC_STS_BUSERR_Msk        (0x1ul << CRYPTO_ECC_STS_BUSERR_Pos)              /*!< CRYPTO_T::ECC_STS: BUSERR Mask         */

#define CRYPTO_ECC_STS_KSERR_Pos         (17)                                              /*!< CRYPTO_T::ECC_STS: KSERR Position      */
#define CRYPTO_ECC_STS_KSERR_Msk         (0x1ul << CRYPTO_ECC_STS_KSERR_Pos)               /*!< CRYPTO_T::ECC_STS: KSERR Mask          */

#define CRYPTO_ECC_STS_ECDSAERR_Pos      (19)                                              /*!< CRYPTO_T::ECC_STS: ECDSAERR Position   */
#define CRYPTO_ECC_STS_ECDSAERR_Msk      (0x1ul << CRYPTO_ECC_STS_ECDSAERR_Pos)            /*!< CRYPTO_T::ECC_STS: ECDSAERR Mask       */

#define CRYPTO_ECC_X1_00_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_00: POINTX1 Position  */
#define CRYPTO_ECC_X1_00_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_00_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_00: POINTX1 Mask      */

#define CRYPTO_ECC_X1_01_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_01: POINTX1 Position  */
#define CRYPTO_ECC_X1_01_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_01_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_01: POINTX1 Mask      */

#define CRYPTO_ECC_X1_02_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_02: POINTX1 Position  */
#define CRYPTO_ECC_X1_02_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_02_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_02: POINTX1 Mask      */

#define CRYPTO_ECC_X1_03_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_03: POINTX1 Position  */
#define CRYPTO_ECC_X1_03_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_03_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_03: POINTX1 Mask      */

#define CRYPTO_ECC_X1_04_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_04: POINTX1 Position  */
#define CRYPTO_ECC_X1_04_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_04_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_04: POINTX1 Mask      */

#define CRYPTO_ECC_X1_05_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_05: POINTX1 Position  */
#define CRYPTO_ECC_X1_05_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_05_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_05: POINTX1 Mask      */

#define CRYPTO_ECC_X1_06_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_06: POINTX1 Position  */
#define CRYPTO_ECC_X1_06_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_06_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_06: POINTX1 Mask      */

#define CRYPTO_ECC_X1_07_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_07: POINTX1 Position  */
#define CRYPTO_ECC_X1_07_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_07_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_07: POINTX1 Mask      */

#define CRYPTO_ECC_X1_08_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_08: POINTX1 Position  */
#define CRYPTO_ECC_X1_08_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_08_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_08: POINTX1 Mask      */

#define CRYPTO_ECC_X1_09_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_09: POINTX1 Position  */
#define CRYPTO_ECC_X1_09_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_09_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_09: POINTX1 Mask      */

#define CRYPTO_ECC_X1_10_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_10: POINTX1 Position  */
#define CRYPTO_ECC_X1_10_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_10_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_10: POINTX1 Mask      */

#define CRYPTO_ECC_X1_11_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_11: POINTX1 Position  */
#define CRYPTO_ECC_X1_11_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_11_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_11: POINTX1 Mask      */

#define CRYPTO_ECC_X1_12_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_12: POINTX1 Position  */
#define CRYPTO_ECC_X1_12_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_12_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_12: POINTX1 Mask      */

#define CRYPTO_ECC_X1_13_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_13: POINTX1 Position  */
#define CRYPTO_ECC_X1_13_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_13_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_13: POINTX1 Mask      */

#define CRYPTO_ECC_X1_14_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_14: POINTX1 Position  */
#define CRYPTO_ECC_X1_14_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_14_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_14: POINTX1 Mask      */

#define CRYPTO_ECC_X1_15_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_15: POINTX1 Position  */
#define CRYPTO_ECC_X1_15_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_15_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_15: POINTX1 Mask      */

#define CRYPTO_ECC_X1_16_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_16: POINTX1 Position  */
#define CRYPTO_ECC_X1_16_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_16_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_16: POINTX1 Mask      */

#define CRYPTO_ECC_X1_17_POINTX1_Pos     (0)                                               /*!< CRYPTO_T::ECC_X1_17: POINTX1 Position  */
#define CRYPTO_ECC_X1_17_POINTX1_Msk     (0xfffffffful << CRYPTO_ECC_X1_17_POINTX1_Pos)    /*!< CRYPTO_T::ECC_X1_17: POINTX1 Mask      */

#define CRYPTO_ECC_Y1_00_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_00: POINTY1 Position  */
#define CRYPTO_ECC_Y1_00_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_00_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_00: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_01_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_01: POINTY1 Position  */
#define CRYPTO_ECC_Y1_01_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_01_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_01: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_02_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_02: POINTY1 Position  */
#define CRYPTO_ECC_Y1_02_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_02_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_02: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_03_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_03: POINTY1 Position  */
#define CRYPTO_ECC_Y1_03_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_03_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_03: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_04_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_04: POINTY1 Position  */
#define CRYPTO_ECC_Y1_04_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_04_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_04: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_05_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_05: POINTY1 Position  */
#define CRYPTO_ECC_Y1_05_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_05_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_05: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_06_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_06: POINTY1 Position  */
#define CRYPTO_ECC_Y1_06_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_06_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_06: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_07_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_07: POINTY1 Position  */
#define CRYPTO_ECC_Y1_07_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_07_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_07: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_08_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_08: POINTY1 Position  */
#define CRYPTO_ECC_Y1_08_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_08_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_08: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_09_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_09: POINTY1 Position  */
#define CRYPTO_ECC_Y1_09_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_09_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_09: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_10_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_10: POINTY1 Position  */
#define CRYPTO_ECC_Y1_10_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_10_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_10: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_11_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_11: POINTY1 Position  */
#define CRYPTO_ECC_Y1_11_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_11_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_11: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_12_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_12: POINTY1 Position  */
#define CRYPTO_ECC_Y1_12_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_12_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_12: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_13_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_13: POINTY1 Position  */
#define CRYPTO_ECC_Y1_13_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_13_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_13: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_14_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_14: POINTY1 Position  */
#define CRYPTO_ECC_Y1_14_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_14_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_14: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_15_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_15: POINTY1 Position  */
#define CRYPTO_ECC_Y1_15_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_15_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_15: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_16_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_16: POINTY1 Position  */
#define CRYPTO_ECC_Y1_16_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_16_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_16: POINTY1 Mask      */

#define CRYPTO_ECC_Y1_17_POINTY1_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y1_17: POINTY1 Position  */
#define CRYPTO_ECC_Y1_17_POINTY1_Msk     (0xfffffffful << CRYPTO_ECC_Y1_17_POINTY1_Pos)    /*!< CRYPTO_T::ECC_Y1_17: POINTY1 Mask      */

#define CRYPTO_ECC_X2_00_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_00: POINTX2 Position  */
#define CRYPTO_ECC_X2_00_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_00_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_00: POINTX2 Mask      */

#define CRYPTO_ECC_X2_01_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_01: POINTX2 Position  */
#define CRYPTO_ECC_X2_01_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_01_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_01: POINTX2 Mask      */

#define CRYPTO_ECC_X2_02_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_02: POINTX2 Position  */
#define CRYPTO_ECC_X2_02_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_02_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_02: POINTX2 Mask      */

#define CRYPTO_ECC_X2_03_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_03: POINTX2 Position  */
#define CRYPTO_ECC_X2_03_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_03_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_03: POINTX2 Mask      */

#define CRYPTO_ECC_X2_04_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_04: POINTX2 Position  */
#define CRYPTO_ECC_X2_04_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_04_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_04: POINTX2 Mask      */

#define CRYPTO_ECC_X2_05_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_05: POINTX2 Position  */
#define CRYPTO_ECC_X2_05_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_05_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_05: POINTX2 Mask      */

#define CRYPTO_ECC_X2_06_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_06: POINTX2 Position  */
#define CRYPTO_ECC_X2_06_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_06_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_06: POINTX2 Mask      */

#define CRYPTO_ECC_X2_07_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_07: POINTX2 Position  */
#define CRYPTO_ECC_X2_07_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_07_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_07: POINTX2 Mask      */

#define CRYPTO_ECC_X2_08_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_08: POINTX2 Position  */
#define CRYPTO_ECC_X2_08_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_08_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_08: POINTX2 Mask      */

#define CRYPTO_ECC_X2_09_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_09: POINTX2 Position  */
#define CRYPTO_ECC_X2_09_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_09_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_09: POINTX2 Mask      */

#define CRYPTO_ECC_X2_10_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_10: POINTX2 Position  */
#define CRYPTO_ECC_X2_10_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_10_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_10: POINTX2 Mask      */

#define CRYPTO_ECC_X2_11_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_11: POINTX2 Position  */
#define CRYPTO_ECC_X2_11_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_11_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_11: POINTX2 Mask      */

#define CRYPTO_ECC_X2_12_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_12: POINTX2 Position  */
#define CRYPTO_ECC_X2_12_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_12_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_12: POINTX2 Mask      */

#define CRYPTO_ECC_X2_13_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_13: POINTX2 Position  */
#define CRYPTO_ECC_X2_13_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_13_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_13: POINTX2 Mask      */

#define CRYPTO_ECC_X2_14_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_14: POINTX2 Position  */
#define CRYPTO_ECC_X2_14_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_14_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_14: POINTX2 Mask      */

#define CRYPTO_ECC_X2_15_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_15: POINTX2 Position  */
#define CRYPTO_ECC_X2_15_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_15_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_15: POINTX2 Mask      */

#define CRYPTO_ECC_X2_16_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_16: POINTX2 Position  */
#define CRYPTO_ECC_X2_16_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_16_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_16: POINTX2 Mask      */

#define CRYPTO_ECC_X2_17_POINTX2_Pos     (0)                                               /*!< CRYPTO_T::ECC_X2_17: POINTX2 Position  */
#define CRYPTO_ECC_X2_17_POINTX2_Msk     (0xfffffffful << CRYPTO_ECC_X2_17_POINTX2_Pos)    /*!< CRYPTO_T::ECC_X2_17: POINTX2 Mask      */

#define CRYPTO_ECC_Y2_00_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_00: POINTY2 Position  */
#define CRYPTO_ECC_Y2_00_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_00_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_00: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_01_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_01: POINTY2 Position  */
#define CRYPTO_ECC_Y2_01_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_01_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_01: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_02_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_02: POINTY2 Position  */
#define CRYPTO_ECC_Y2_02_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_02_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_02: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_03_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_03: POINTY2 Position  */
#define CRYPTO_ECC_Y2_03_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_03_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_03: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_04_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_04: POINTY2 Position  */
#define CRYPTO_ECC_Y2_04_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_04_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_04: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_05_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_05: POINTY2 Position  */
#define CRYPTO_ECC_Y2_05_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_05_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_05: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_06_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_06: POINTY2 Position  */
#define CRYPTO_ECC_Y2_06_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_06_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_06: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_07_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_07: POINTY2 Position  */
#define CRYPTO_ECC_Y2_07_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_07_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_07: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_08_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_08: POINTY2 Position  */
#define CRYPTO_ECC_Y2_08_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_08_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_08: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_09_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_09: POINTY2 Position  */
#define CRYPTO_ECC_Y2_09_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_09_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_09: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_10_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_10: POINTY2 Position  */
#define CRYPTO_ECC_Y2_10_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_10_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_10: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_11_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_11: POINTY2 Position  */
#define CRYPTO_ECC_Y2_11_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_11_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_11: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_12_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_12: POINTY2 Position  */
#define CRYPTO_ECC_Y2_12_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_12_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_12: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_13_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_13: POINTY2 Position  */
#define CRYPTO_ECC_Y2_13_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_13_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_13: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_14_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_14: POINTY2 Position  */
#define CRYPTO_ECC_Y2_14_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_14_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_14: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_15_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_15: POINTY2 Position  */
#define CRYPTO_ECC_Y2_15_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_15_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_15: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_16_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_16: POINTY2 Position  */
#define CRYPTO_ECC_Y2_16_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_16_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_16: POINTY2 Mask      */

#define CRYPTO_ECC_Y2_17_POINTY2_Pos     (0)                                               /*!< CRYPTO_T::ECC_Y2_17: POINTY2 Position  */
#define CRYPTO_ECC_Y2_17_POINTY2_Msk     (0xfffffffful << CRYPTO_ECC_Y2_17_POINTY2_Pos)    /*!< CRYPTO_T::ECC_Y2_17: POINTY2 Mask      */

#define CRYPTO_ECC_A_00_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_00: CURVEA Position    */
#define CRYPTO_ECC_A_00_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_00_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_00: CURVEA Mask        */

#define CRYPTO_ECC_A_01_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_01: CURVEA Position    */
#define CRYPTO_ECC_A_01_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_01_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_01: CURVEA Mask        */

#define CRYPTO_ECC_A_02_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_02: CURVEA Position    */
#define CRYPTO_ECC_A_02_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_02_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_02: CURVEA Mask        */

#define CRYPTO_ECC_A_03_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_03: CURVEA Position    */
#define CRYPTO_ECC_A_03_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_03_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_03: CURVEA Mask        */

#define CRYPTO_ECC_A_04_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_04: CURVEA Position    */
#define CRYPTO_ECC_A_04_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_04_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_04: CURVEA Mask        */

#define CRYPTO_ECC_A_05_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_05: CURVEA Position    */
#define CRYPTO_ECC_A_05_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_05_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_05: CURVEA Mask        */

#define CRYPTO_ECC_A_06_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_06: CURVEA Position    */
#define CRYPTO_ECC_A_06_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_06_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_06: CURVEA Mask        */

#define CRYPTO_ECC_A_07_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_07: CURVEA Position    */
#define CRYPTO_ECC_A_07_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_07_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_07: CURVEA Mask        */

#define CRYPTO_ECC_A_08_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_08: CURVEA Position    */
#define CRYPTO_ECC_A_08_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_08_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_08: CURVEA Mask        */

#define CRYPTO_ECC_A_09_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_09: CURVEA Position    */
#define CRYPTO_ECC_A_09_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_09_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_09: CURVEA Mask        */

#define CRYPTO_ECC_A_10_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_10: CURVEA Position    */
#define CRYPTO_ECC_A_10_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_10_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_10: CURVEA Mask        */

#define CRYPTO_ECC_A_11_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_11: CURVEA Position    */
#define CRYPTO_ECC_A_11_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_11_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_11: CURVEA Mask        */

#define CRYPTO_ECC_A_12_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_12: CURVEA Position    */
#define CRYPTO_ECC_A_12_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_12_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_12: CURVEA Mask        */

#define CRYPTO_ECC_A_13_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_13: CURVEA Position    */
#define CRYPTO_ECC_A_13_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_13_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_13: CURVEA Mask        */

#define CRYPTO_ECC_A_14_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_14: CURVEA Position    */
#define CRYPTO_ECC_A_14_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_14_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_14: CURVEA Mask        */

#define CRYPTO_ECC_A_15_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_15: CURVEA Position    */
#define CRYPTO_ECC_A_15_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_15_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_15: CURVEA Mask        */

#define CRYPTO_ECC_A_16_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_16: CURVEA Position    */
#define CRYPTO_ECC_A_16_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_16_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_16: CURVEA Mask        */

#define CRYPTO_ECC_A_17_CURVEA_Pos       (0)                                               /*!< CRYPTO_T::ECC_A_17: CURVEA Position    */
#define CRYPTO_ECC_A_17_CURVEA_Msk       (0xfffffffful << CRYPTO_ECC_A_17_CURVEA_Pos)      /*!< CRYPTO_T::ECC_A_17: CURVEA Mask        */

#define CRYPTO_ECC_B_00_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_00: CURVEB Position    */
#define CRYPTO_ECC_B_00_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_00_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_00: CURVEB Mask        */

#define CRYPTO_ECC_B_01_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_01: CURVEB Position    */
#define CRYPTO_ECC_B_01_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_01_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_01: CURVEB Mask        */

#define CRYPTO_ECC_B_02_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_02: CURVEB Position    */
#define CRYPTO_ECC_B_02_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_02_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_02: CURVEB Mask        */

#define CRYPTO_ECC_B_03_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_03: CURVEB Position    */
#define CRYPTO_ECC_B_03_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_03_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_03: CURVEB Mask        */

#define CRYPTO_ECC_B_04_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_04: CURVEB Position    */
#define CRYPTO_ECC_B_04_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_04_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_04: CURVEB Mask        */

#define CRYPTO_ECC_B_05_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_05: CURVEB Position    */
#define CRYPTO_ECC_B_05_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_05_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_05: CURVEB Mask        */

#define CRYPTO_ECC_B_06_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_06: CURVEB Position    */
#define CRYPTO_ECC_B_06_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_06_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_06: CURVEB Mask        */

#define CRYPTO_ECC_B_07_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_07: CURVEB Position    */
#define CRYPTO_ECC_B_07_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_07_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_07: CURVEB Mask        */

#define CRYPTO_ECC_B_08_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_08: CURVEB Position    */
#define CRYPTO_ECC_B_08_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_08_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_08: CURVEB Mask        */

#define CRYPTO_ECC_B_09_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_09: CURVEB Position    */
#define CRYPTO_ECC_B_09_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_09_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_09: CURVEB Mask        */

#define CRYPTO_ECC_B_10_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_10: CURVEB Position    */
#define CRYPTO_ECC_B_10_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_10_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_10: CURVEB Mask        */

#define CRYPTO_ECC_B_11_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_11: CURVEB Position    */
#define CRYPTO_ECC_B_11_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_11_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_11: CURVEB Mask        */

#define CRYPTO_ECC_B_12_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_12: CURVEB Position    */
#define CRYPTO_ECC_B_12_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_12_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_12: CURVEB Mask        */

#define CRYPTO_ECC_B_13_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_13: CURVEB Position    */
#define CRYPTO_ECC_B_13_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_13_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_13: CURVEB Mask        */

#define CRYPTO_ECC_B_14_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_14: CURVEB Position    */
#define CRYPTO_ECC_B_14_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_14_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_14: CURVEB Mask        */

#define CRYPTO_ECC_B_15_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_15: CURVEB Position    */
#define CRYPTO_ECC_B_15_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_15_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_15: CURVEB Mask        */

#define CRYPTO_ECC_B_16_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_16: CURVEB Position    */
#define CRYPTO_ECC_B_16_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_16_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_16: CURVEB Mask        */

#define CRYPTO_ECC_B_17_CURVEB_Pos       (0)                                               /*!< CRYPTO_T::ECC_B_17: CURVEB Position    */
#define CRYPTO_ECC_B_17_CURVEB_Msk       (0xfffffffful << CRYPTO_ECC_B_17_CURVEB_Pos)      /*!< CRYPTO_T::ECC_B_17: CURVEB Mask        */

#define CRYPTO_ECC_N_00_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_00: CURVEN Position    */
#define CRYPTO_ECC_N_00_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_00_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_00: CURVEN Mask        */

#define CRYPTO_ECC_N_01_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_01: CURVEN Position    */
#define CRYPTO_ECC_N_01_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_01_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_01: CURVEN Mask        */

#define CRYPTO_ECC_N_02_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_02: CURVEN Position    */
#define CRYPTO_ECC_N_02_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_02_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_02: CURVEN Mask        */

#define CRYPTO_ECC_N_03_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_03: CURVEN Position    */
#define CRYPTO_ECC_N_03_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_03_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_03: CURVEN Mask        */

#define CRYPTO_ECC_N_04_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_04: CURVEN Position    */
#define CRYPTO_ECC_N_04_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_04_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_04: CURVEN Mask        */

#define CRYPTO_ECC_N_05_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_05: CURVEN Position    */
#define CRYPTO_ECC_N_05_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_05_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_05: CURVEN Mask        */

#define CRYPTO_ECC_N_06_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_06: CURVEN Position    */
#define CRYPTO_ECC_N_06_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_06_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_06: CURVEN Mask        */

#define CRYPTO_ECC_N_07_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_07: CURVEN Position    */
#define CRYPTO_ECC_N_07_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_07_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_07: CURVEN Mask        */

#define CRYPTO_ECC_N_08_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_08: CURVEN Position    */
#define CRYPTO_ECC_N_08_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_08_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_08: CURVEN Mask        */

#define CRYPTO_ECC_N_09_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_09: CURVEN Position    */
#define CRYPTO_ECC_N_09_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_09_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_09: CURVEN Mask        */

#define CRYPTO_ECC_N_10_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_10: CURVEN Position    */
#define CRYPTO_ECC_N_10_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_10_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_10: CURVEN Mask        */

#define CRYPTO_ECC_N_11_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_11: CURVEN Position    */
#define CRYPTO_ECC_N_11_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_11_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_11: CURVEN Mask        */

#define CRYPTO_ECC_N_12_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_12: CURVEN Position    */
#define CRYPTO_ECC_N_12_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_12_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_12: CURVEN Mask        */

#define CRYPTO_ECC_N_13_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_13: CURVEN Position    */
#define CRYPTO_ECC_N_13_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_13_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_13: CURVEN Mask        */

#define CRYPTO_ECC_N_14_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_14: CURVEN Position    */
#define CRYPTO_ECC_N_14_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_14_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_14: CURVEN Mask        */

#define CRYPTO_ECC_N_15_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_15: CURVEN Position    */
#define CRYPTO_ECC_N_15_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_15_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_15: CURVEN Mask        */

#define CRYPTO_ECC_N_16_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_16: CURVEN Position    */
#define CRYPTO_ECC_N_16_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_16_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_16: CURVEN Mask        */

#define CRYPTO_ECC_N_17_CURVEN_Pos       (0)                                               /*!< CRYPTO_T::ECC_N_17: CURVEN Position    */
#define CRYPTO_ECC_N_17_CURVEN_Msk       (0xfffffffful << CRYPTO_ECC_N_17_CURVEN_Pos)      /*!< CRYPTO_T::ECC_N_17: CURVEN Mask        */

#define CRYPTO_ECC_K_00_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_00: SCALARK Position   */
#define CRYPTO_ECC_K_00_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_00_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_00: SCALARK Mask       */

#define CRYPTO_ECC_K_01_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_01: SCALARK Position   */
#define CRYPTO_ECC_K_01_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_01_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_01: SCALARK Mask       */

#define CRYPTO_ECC_K_02_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_02: SCALARK Position   */
#define CRYPTO_ECC_K_02_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_02_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_02: SCALARK Mask       */

#define CRYPTO_ECC_K_03_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_03: SCALARK Position   */
#define CRYPTO_ECC_K_03_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_03_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_03: SCALARK Mask       */

#define CRYPTO_ECC_K_04_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_04: SCALARK Position   */
#define CRYPTO_ECC_K_04_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_04_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_04: SCALARK Mask       */

#define CRYPTO_ECC_K_05_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_05: SCALARK Position   */
#define CRYPTO_ECC_K_05_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_05_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_05: SCALARK Mask       */

#define CRYPTO_ECC_K_06_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_06: SCALARK Position   */
#define CRYPTO_ECC_K_06_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_06_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_06: SCALARK Mask       */

#define CRYPTO_ECC_K_07_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_07: SCALARK Position   */
#define CRYPTO_ECC_K_07_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_07_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_07: SCALARK Mask       */

#define CRYPTO_ECC_K_08_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_08: SCALARK Position   */
#define CRYPTO_ECC_K_08_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_08_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_08: SCALARK Mask       */

#define CRYPTO_ECC_K_09_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_09: SCALARK Position   */
#define CRYPTO_ECC_K_09_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_09_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_09: SCALARK Mask       */

#define CRYPTO_ECC_K_10_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_10: SCALARK Position   */
#define CRYPTO_ECC_K_10_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_10_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_10: SCALARK Mask       */

#define CRYPTO_ECC_K_11_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_11: SCALARK Position   */
#define CRYPTO_ECC_K_11_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_11_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_11: SCALARK Mask       */

#define CRYPTO_ECC_K_12_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_12: SCALARK Position   */
#define CRYPTO_ECC_K_12_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_12_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_12: SCALARK Mask       */

#define CRYPTO_ECC_K_13_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_13: SCALARK Position   */
#define CRYPTO_ECC_K_13_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_13_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_13: SCALARK Mask       */

#define CRYPTO_ECC_K_14_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_14: SCALARK Position   */
#define CRYPTO_ECC_K_14_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_14_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_14: SCALARK Mask       */

#define CRYPTO_ECC_K_15_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_15: SCALARK Position   */
#define CRYPTO_ECC_K_15_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_15_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_15: SCALARK Mask       */

#define CRYPTO_ECC_K_16_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_16: SCALARK Position   */
#define CRYPTO_ECC_K_16_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_16_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_16: SCALARK Mask       */

#define CRYPTO_ECC_K_17_SCALARK_Pos      (0)                                               /*!< CRYPTO_T::ECC_K_17: SCALARK Position   */
#define CRYPTO_ECC_K_17_SCALARK_Msk      (0xfffffffful << CRYPTO_ECC_K_17_SCALARK_Pos)     /*!< CRYPTO_T::ECC_K_17: SCALARK Mask       */

#define CRYPTO_ECC_DADDR_DADDR_Pos       (0)                                               /*!< CRYPTO_T::ECC_DADDR: DADDR Position    */
#define CRYPTO_ECC_DADDR_DADDR_Msk       (0xfffffffful << CRYPTO_ECC_DADDR_DADDR_Pos)      /*!< CRYPTO_T::ECC_DADDR: DADDR Mask        */

#define CRYPTO_ECC_STARTREG_STARTREG_Pos (0)                                               /*!< CRYPTO_T::ECC_STARTREG: STARTREG Position*/
#define CRYPTO_ECC_STARTREG_STARTREG_Msk (0xfffffffful << CRYPTO_ECC_STARTREG_STARTREG_Pos) /*!< CRYPTO_T::ECC_STARTREG: STARTREG Mask  */

#define CRYPTO_ECC_WORDCNT_WORDCNT_Pos   (0)                                               /*!< CRYPTO_T::ECC_WORDCNT: WORDCNT Position*/
#define CRYPTO_ECC_WORDCNT_WORDCNT_Msk   (0xfffffffful << CRYPTO_ECC_WORDCNT_WORDCNT_Pos)  /*!< CRYPTO_T::ECC_WORDCNT: WORDCNT Mask    */

#define CRYPTO_ECC_DMA_CTL_LDP1_Pos      (0)                                               /*!< CRYPTO_T::ECC_DMA_CTL: LDP1 Position   */
#define CRYPTO_ECC_DMA_CTL_LDP1_Msk      (0x1ul << CRYPTO_ECC_DMA_CTL_LDP1_Pos)            /*!< CRYPTO_T::ECC_DMA_CTL: LDP1 Mask       */

#define CRYPTO_ECC_DMA_CTL_LDP2_Pos      (1)                                               /*!< CRYPTO_T::ECC_DMA_CTL: LDP2 Position   */
#define CRYPTO_ECC_DMA_CTL_LDP2_Msk      (0x1ul << CRYPTO_ECC_DMA_CTL_LDP2_Pos)            /*!< CRYPTO_T::ECC_DMA_CTL: LDP2 Mask       */

#define CRYPTO_ECC_DMA_CTL_LDA_Pos       (2)                                               /*!< CRYPTO_T::ECC_DMA_CTL: LDA Position    */
#define CRYPTO_ECC_DMA_CTL_LDA_Msk       (0x1ul << CRYPTO_ECC_DMA_CTL_LDA_Pos)             /*!< CRYPTO_T::ECC_DMA_CTL: LDA Mask        */

#define CRYPTO_ECC_DMA_CTL_LDB_Pos       (3)                                               /*!< CRYPTO_T::ECC_DMA_CTL: LDB Position    */
#define CRYPTO_ECC_DMA_CTL_LDB_Msk       (0x1ul << CRYPTO_ECC_DMA_CTL_LDB_Pos)             /*!< CRYPTO_T::ECC_DMA_CTL: LDB Mask        */

#define CRYPTO_ECC_DMA_CTL_LDN_Pos       (4)                                               /*!< CRYPTO_T::ECC_DMA_CTL: LDN Position    */
#define CRYPTO_ECC_DMA_CTL_LDN_Msk       (0x1ul << CRYPTO_ECC_DMA_CTL_LDN_Pos)             /*!< CRYPTO_T::ECC_DMA_CTL: LDN Mask        */

#define CRYPTO_ECC_DMA_CTL_LDK_Pos       (5)                                               /*!< CRYPTO_T::ECC_DMA_CTL: LDK Position    */
#define CRYPTO_ECC_DMA_CTL_LDK_Msk       (0x1ul << CRYPTO_ECC_DMA_CTL_LDK_Pos)             /*!< CRYPTO_T::ECC_DMA_CTL: LDK Mask        */

#define CRYPTO_ECC_PRNGSEED_SEED_Pos     (0)                                               /*!< CRYPTO_T::ECC_PRNGSEED: SEED Position  */
#define CRYPTO_ECC_PRNGSEED_SEED_Msk     (0xfffffffful << CRYPTO_ECC_PRNGSEED_SEED_Pos)    /*!< CRYPTO_T::ECC_PRNGSEED: SEED Mask      */

#define CRYPTO_ECC_PRNGSTS_RDCNT_Pos     (8)                                               /*!< CRYPTO_T::ECC_PRNGSTS: RDCNT Position  */
#define CRYPTO_ECC_PRNGSTS_RDCNT_Msk     (0x1ul << CRYPTO_ECC_PRNGSTS_RDCNT_Pos)           /*!< CRYPTO_T::ECC_PRNGSTS: RDCNT Mask      */

#define CRYPTO_ECC_EDDSA_SHASP_Pos       (0)                                               /*!< CRYPTO_T::ECC_EDDSA: SHASP Position    */
#define CRYPTO_ECC_EDDSA_SHASP_Msk       (0x1ul << CRYPTO_ECC_EDDSA_SHASP_Pos)             /*!< CRYPTO_T::ECC_EDDSA: SHASP Mask        */

#define CRYPTO_ECC_EDDSA_ECCSB_Pos       (1)                                               /*!< CRYPTO_T::ECC_EDDSA: ECCSB Position    */
#define CRYPTO_ECC_EDDSA_ECCSB_Msk       (0x1ul << CRYPTO_ECC_EDDSA_ECCSB_Pos)             /*!< CRYPTO_T::ECC_EDDSA: ECCSB Mask        */

#define CRYPTO_ECC_EDDSA_SHALR_Pos       (2)                                               /*!< CRYPTO_T::ECC_EDDSA: SHALR Position    */
#define CRYPTO_ECC_EDDSA_SHALR_Msk       (0x1ul << CRYPTO_ECC_EDDSA_SHALR_Pos)             /*!< CRYPTO_T::ECC_EDDSA: SHALR Mask        */

#define CRYPTO_ECC_EDDSA_ECCSR_Pos       (3)                                               /*!< CRYPTO_T::ECC_EDDSA: ECCSR Position    */
#define CRYPTO_ECC_EDDSA_ECCSR_Msk       (0x1ul << CRYPTO_ECC_EDDSA_ECCSR_Pos)             /*!< CRYPTO_T::ECC_EDDSA: ECCSR Mask        */

#define CRYPTO_ECC_EDDSA_ECCRB_Pos       (4)                                               /*!< CRYPTO_T::ECC_EDDSA: ECCRB Position    */
#define CRYPTO_ECC_EDDSA_ECCRB_Msk       (0x1ul << CRYPTO_ECC_EDDSA_ECCRB_Pos)             /*!< CRYPTO_T::ECC_EDDSA: ECCRB Mask        */

#define CRYPTO_ECC_EDDSA_ECCSG_Pos       (5)                                               /*!< CRYPTO_T::ECC_EDDSA: ECCSG Position    */
#define CRYPTO_ECC_EDDSA_ECCSG_Msk       (0x1ul << CRYPTO_ECC_EDDSA_ECCSG_Pos)             /*!< CRYPTO_T::ECC_EDDSA: ECCSG Mask        */

#define CRYPTO_RSA_CTL_START_Pos         (0)                                               /*!< CRYPTO_T::RSA_CTL: START Position      */
#define CRYPTO_RSA_CTL_START_Msk         (0x1ul << CRYPTO_RSA_CTL_START_Pos)               /*!< CRYPTO_T::RSA_CTL: START Mask          */

#define CRYPTO_RSA_CTL_STOP_Pos          (1)                                               /*!< CRYPTO_T::RSA_CTL: STOP Position       */
#define CRYPTO_RSA_CTL_STOP_Msk          (0x1ul << CRYPTO_RSA_CTL_STOP_Pos)                /*!< CRYPTO_T::RSA_CTL: STOP Mask           */

#define CRYPTO_RSA_CTL_CRT_Pos           (2)                                               /*!< CRYPTO_T::RSA_CTL: CRT Position        */
#define CRYPTO_RSA_CTL_CRT_Msk           (0x1ul << CRYPTO_RSA_CTL_CRT_Pos)                 /*!< CRYPTO_T::RSA_CTL: CRT Mask            */

#define CRYPTO_RSA_CTL_CRTBYP_Pos        (3)                                               /*!< CRYPTO_T::RSA_CTL: CRTBYP Position     */
#define CRYPTO_RSA_CTL_CRTBYP_Msk        (0x1ul << CRYPTO_RSA_CTL_CRTBYP_Pos)              /*!< CRYPTO_T::RSA_CTL: CRTBYP Mask         */

#define CRYPTO_RSA_CTL_KEYLENG_Pos       (4)                                               /*!< CRYPTO_T::RSA_CTL: KEYLENG Position    */
#define CRYPTO_RSA_CTL_KEYLENG_Msk       (0x3ul << CRYPTO_RSA_CTL_KEYLENG_Pos)             /*!< CRYPTO_T::RSA_CTL: KEYLENG Mask        */

#define CRYPTO_RSA_STS_BUSY_Pos          (0)                                               /*!< CRYPTO_T::RSA_STS: BUSY Position       */
#define CRYPTO_RSA_STS_BUSY_Msk          (0x1ul << CRYPTO_RSA_STS_BUSY_Pos)                /*!< CRYPTO_T::RSA_STS: BUSY Mask           */

#define CRYPTO_RSA_STS_DMABUSY_Pos       (1)                                               /*!< CRYPTO_T::RSA_STS: DMABUSY Position    */
#define CRYPTO_RSA_STS_DMABUSY_Msk       (0x1ul << CRYPTO_RSA_STS_DMABUSY_Pos)             /*!< CRYPTO_T::RSA_STS: DMABUSY Mask        */

#define CRYPTO_RSA_STS_BUSERR_Pos        (16)                                              /*!< CRYPTO_T::RSA_STS: BUSERR Position     */
#define CRYPTO_RSA_STS_BUSERR_Msk        (0x1ul << CRYPTO_RSA_STS_BUSERR_Pos)              /*!< CRYPTO_T::RSA_STS: BUSERR Mask         */

#define CRYPTO_RSA_STS_CTLERR_Pos        (17)                                              /*!< CRYPTO_T::RSA_STS: CTLERR Position     */
#define CRYPTO_RSA_STS_CTLERR_Msk        (0x1ul << CRYPTO_RSA_STS_CTLERR_Pos)              /*!< CRYPTO_T::RSA_STS: CTLERR Mask         */

#define CRYPTO_RSA_SADDR0_SADDR0_Pos     (0)                                               /*!< CRYPTO_T::RSA_SADDR0: SADDR0 Position  */
#define CRYPTO_RSA_SADDR0_SADDR0_Msk     (0xfffffffful << CRYPTO_RSA_SADDR0_SADDR0_Pos)    /*!< CRYPTO_T::RSA_SADDR0: SADDR0 Mask      */

#define CRYPTO_RSA_SADDR1_SADDR1_Pos     (0)                                               /*!< CRYPTO_T::RSA_SADDR1: SADDR1 Position  */
#define CRYPTO_RSA_SADDR1_SADDR1_Msk     (0xfffffffful << CRYPTO_RSA_SADDR1_SADDR1_Pos)    /*!< CRYPTO_T::RSA_SADDR1: SADDR1 Mask      */

#define CRYPTO_RSA_SADDR2_SADDR2_Pos     (0)                                               /*!< CRYPTO_T::RSA_SADDR2: SADDR2 Position  */
#define CRYPTO_RSA_SADDR2_SADDR2_Msk     (0xfffffffful << CRYPTO_RSA_SADDR2_SADDR2_Pos)    /*!< CRYPTO_T::RSA_SADDR2: SADDR2 Mask      */

#define CRYPTO_RSA_SADDR3_SADDR3_Pos     (0)                                               /*!< CRYPTO_T::RSA_SADDR3: SADDR3 Position  */
#define CRYPTO_RSA_SADDR3_SADDR3_Msk     (0xfffffffful << CRYPTO_RSA_SADDR3_SADDR3_Pos)    /*!< CRYPTO_T::RSA_SADDR3: SADDR3 Mask      */

#define CRYPTO_RSA_SADDR4_SADDR4_Pos     (0)                                               /*!< CRYPTO_T::RSA_SADDR4: SADDR4 Position  */
#define CRYPTO_RSA_SADDR4_SADDR4_Msk     (0xfffffffful << CRYPTO_RSA_SADDR4_SADDR4_Pos)    /*!< CRYPTO_T::RSA_SADDR4: SADDR4 Mask      */

#define CRYPTO_RSA_DADDR_DADDR_Pos       (0)                                               /*!< CRYPTO_T::RSA_DADDR: DADDR Position    */
#define CRYPTO_RSA_DADDR_DADDR_Msk       (0xfffffffful << CRYPTO_RSA_DADDR_DADDR_Pos)      /*!< CRYPTO_T::RSA_DADDR: DADDR Mask        */

#define CRYPTO_RSA_MADDR0_MADDR0_Pos     (0)                                               /*!< CRYPTO_T::RSA_MADDR0: MADDR0 Position  */
#define CRYPTO_RSA_MADDR0_MADDR0_Msk     (0xfffffffful << CRYPTO_RSA_MADDR0_MADDR0_Pos)    /*!< CRYPTO_T::RSA_MADDR0: MADDR0 Mask      */

#define CRYPTO_RSA_MADDR1_MADDR1_Pos     (0)                                               /*!< CRYPTO_T::RSA_MADDR1: MADDR1 Position  */
#define CRYPTO_RSA_MADDR1_MADDR1_Msk     (0xfffffffful << CRYPTO_RSA_MADDR1_MADDR1_Pos)    /*!< CRYPTO_T::RSA_MADDR1: MADDR1 Mask      */

#define CRYPTO_RSA_MADDR2_MADDR2_Pos     (0)                                               /*!< CRYPTO_T::RSA_MADDR2: MADDR2 Position  */
#define CRYPTO_RSA_MADDR2_MADDR2_Msk     (0xfffffffful << CRYPTO_RSA_MADDR2_MADDR2_Pos)    /*!< CRYPTO_T::RSA_MADDR2: MADDR2 Mask      */

#define CRYPTO_RSA_MADDR3_MADDR3_Pos     (0)                                               /*!< CRYPTO_T::RSA_MADDR3: MADDR3 Position  */
#define CRYPTO_RSA_MADDR3_MADDR3_Msk     (0xfffffffful << CRYPTO_RSA_MADDR3_MADDR3_Pos)    /*!< CRYPTO_T::RSA_MADDR3: MADDR3 Mask      */

#define CRYPTO_RSA_MADDR4_MADDR4_Pos     (0)                                               /*!< CRYPTO_T::RSA_MADDR4: MADDR4 Position  */
#define CRYPTO_RSA_MADDR4_MADDR4_Msk     (0xfffffffful << CRYPTO_RSA_MADDR4_MADDR4_Pos)    /*!< CRYPTO_T::RSA_MADDR4: MADDR4 Mask      */

#define CRYPTO_RSA_MADDR5_MADDR5_Pos     (0)                                               /*!< CRYPTO_T::RSA_MADDR5: MADDR5 Position  */
#define CRYPTO_RSA_MADDR5_MADDR5_Msk     (0xfffffffful << CRYPTO_RSA_MADDR5_MADDR5_Pos)    /*!< CRYPTO_T::RSA_MADDR5: MADDR5 Mask      */

#define CRYPTO_PRNG_KSCTL_NUM_Pos        (0)                                               /*!< CRYPTO_T::PRNG_KSCTL: NUM Position     */
#define CRYPTO_PRNG_KSCTL_NUM_Msk        (0x1ful << CRYPTO_PRNG_KSCTL_NUM_Pos)             /*!< CRYPTO_T::PRNG_KSCTL: NUM Mask         */

#define CRYPTO_PRNG_KSCTL_WDST_Pos       (21)                                              /*!< CRYPTO_T::PRNG_KSCTL: WDST Position    */
#define CRYPTO_PRNG_KSCTL_WDST_Msk       (0x1ul << CRYPTO_PRNG_KSCTL_WDST_Pos)             /*!< CRYPTO_T::PRNG_KSCTL: WDST Mask        */

#define CRYPTO_PRNG_KSCTL_WSDST_Pos      (22)                                              /*!< CRYPTO_T::PRNG_KSCTL: WSDST Position   */
#define CRYPTO_PRNG_KSCTL_WSDST_Msk      (0x3ul << CRYPTO_PRNG_KSCTL_WSDST_Pos)            /*!< CRYPTO_T::PRNG_KSCTL: WSDST Mask       */

#define CRYPTO_PRNG_KSCTL_OWNER_Pos      (24)                                              /*!< CRYPTO_T::PRNG_KSCTL: OWNER Position   */
#define CRYPTO_PRNG_KSCTL_OWNER_Msk      (0x7ul << CRYPTO_PRNG_KSCTL_OWNER_Pos)            /*!< CRYPTO_T::PRNG_KSCTL: OWNER Mask       */

#define CRYPTO_AES_KSCTL_NUM_Pos         (0)                                               /*!< CRYPTO_T::AES_KSCTL: NUM Position      */
#define CRYPTO_AES_KSCTL_NUM_Msk         (0x1ful << CRYPTO_AES_KSCTL_NUM_Pos)              /*!< CRYPTO_T::AES_KSCTL: NUM Mask          */

#define CRYPTO_AES_KSCTL_RSRC_Pos        (5)                                               /*!< CRYPTO_T::AES_KSCTL: RSRC Position     */
#define CRYPTO_AES_KSCTL_RSRC_Msk        (0x1ul << CRYPTO_AES_KSCTL_RSRC_Pos)              /*!< CRYPTO_T::AES_KSCTL: RSRC Mask         */

#define CRYPTO_AES_KSCTL_RSSRC_Pos       (6)                                               /*!< CRYPTO_T::AES_KSCTL: RSSRC Position    */
#define CRYPTO_AES_KSCTL_RSSRC_Msk       (0x3ul << CRYPTO_AES_KSCTL_RSSRC_Pos)             /*!< CRYPTO_T::AES_KSCTL: RSSRC Mask        */

#define CRYPTO_HMAC_KSCTL_NUM_Pos        (0)                                               /*!< CRYPTO_T::HMAC_KSCTL: NUM Position     */
#define CRYPTO_HMAC_KSCTL_NUM_Msk        (0x1ful << CRYPTO_HMAC_KSCTL_NUM_Pos)             /*!< CRYPTO_T::HMAC_KSCTL: NUM Mask         */

#define CRYPTO_HMAC_KSCTL_RSRC_Pos       (5)                                               /*!< CRYPTO_T::HMAC_KSCTL: RSRC Position    */
#define CRYPTO_HMAC_KSCTL_RSRC_Msk       (0x1ul << CRYPTO_HMAC_KSCTL_RSRC_Pos)             /*!< CRYPTO_T::HMAC_KSCTL: RSRC Mask        */

#define CRYPTO_HMAC_KSCTL_RSSRC_Pos      (6)                                               /*!< CRYPTO_T::HMAC_KSCTL: RSSRC Position   */
#define CRYPTO_HMAC_KSCTL_RSSRC_Msk      (0x3ul << CRYPTO_HMAC_KSCTL_RSSRC_Pos)            /*!< CRYPTO_T::HMAC_KSCTL: RSSRC Mask       */

#define CRYPTO_ECC_KSCTL_NUMK_Pos        (0)                                               /*!< CRYPTO_T::ECC_KSCTL: NUMK Position     */
#define CRYPTO_ECC_KSCTL_NUMK_Msk        (0x1ful << CRYPTO_ECC_KSCTL_NUMK_Pos)             /*!< CRYPTO_T::ECC_KSCTL: NUMK Mask         */

#define CRYPTO_ECC_KSCTL_RSRCK_Pos       (5)                                               /*!< CRYPTO_T::ECC_KSCTL: RSRCK Position    */
#define CRYPTO_ECC_KSCTL_RSRCK_Msk       (0x1ul << CRYPTO_ECC_KSCTL_RSRCK_Pos)             /*!< CRYPTO_T::ECC_KSCTL: RSRCK Mask        */

#define CRYPTO_ECC_KSCTL_RSSRCK_Pos      (6)                                               /*!< CRYPTO_T::ECC_KSCTL: RSSRCK Position   */
#define CRYPTO_ECC_KSCTL_RSSRCK_Msk      (0x3ul << CRYPTO_ECC_KSCTL_RSSRCK_Pos)            /*!< CRYPTO_T::ECC_KSCTL: RSSRCK Mask       */

#define CRYPTO_ECC_KSCTL_XY_Pos          (20)                                              /*!< CRYPTO_T::ECC_KSCTL: XY Position       */
#define CRYPTO_ECC_KSCTL_XY_Msk          (0x1ul << CRYPTO_ECC_KSCTL_XY_Pos)                /*!< CRYPTO_T::ECC_KSCTL: XY Mask           */

#define CRYPTO_ECC_KSCTL_WDST_Pos        (21)                                              /*!< CRYPTO_T::ECC_KSCTL: WDST Position     */
#define CRYPTO_ECC_KSCTL_WDST_Msk        (0x1ul << CRYPTO_ECC_KSCTL_WDST_Pos)              /*!< CRYPTO_T::ECC_KSCTL: WDST Mask         */

#define CRYPTO_ECC_KSCTL_WSDST_Pos       (22)                                              /*!< CRYPTO_T::ECC_KSCTL: WSDST Position    */
#define CRYPTO_ECC_KSCTL_WSDST_Msk       (0x3ul << CRYPTO_ECC_KSCTL_WSDST_Pos)             /*!< CRYPTO_T::ECC_KSCTL: WSDST Mask        */

#define CRYPTO_ECC_KSCTL_OWNER_Pos       (24)                                              /*!< CRYPTO_T::ECC_KSCTL: OWNER Position    */
#define CRYPTO_ECC_KSCTL_OWNER_Msk       (0x7ul << CRYPTO_ECC_KSCTL_OWNER_Pos)             /*!< CRYPTO_T::ECC_KSCTL: OWNER Mask        */

#define CRYPTO_ECC_KSXY_NUMX1_Pos        (0)                                               /*!< CRYPTO_T::ECC_KSXY: NUMX1 Position     */
#define CRYPTO_ECC_KSXY_NUMX1_Msk        (0x1ful << CRYPTO_ECC_KSXY_NUMX1_Pos)             /*!< CRYPTO_T::ECC_KSXY: NUMX1 Mask         */

#define CRYPTO_ECC_KSXY_RSRCXY1_Pos      (5)                                               /*!< CRYPTO_T::ECC_KSXY: RSRCXY1 Position   */
#define CRYPTO_ECC_KSXY_RSRCXY1_Msk      (0x1ul << CRYPTO_ECC_KSXY_RSRCXY1_Pos)            /*!< CRYPTO_T::ECC_KSXY: RSRCXY1 Mask       */

#define CRYPTO_ECC_KSXY_RSSRCX1_Pos      (6)                                               /*!< CRYPTO_T::ECC_KSXY: RSSRCX1 Position   */
#define CRYPTO_ECC_KSXY_RSSRCX1_Msk      (0x3ul << CRYPTO_ECC_KSXY_RSSRCX1_Pos)            /*!< CRYPTO_T::ECC_KSXY: RSSRCX1 Mask       */

#define CRYPTO_ECC_KSXY_NUMY1_Pos        (8)                                               /*!< CRYPTO_T::ECC_KSXY: NUMY1 Position     */
#define CRYPTO_ECC_KSXY_NUMY1_Msk        (0x1ful << CRYPTO_ECC_KSXY_NUMY1_Pos)             /*!< CRYPTO_T::ECC_KSXY: NUMY1 Mask         */

#define CRYPTO_ECC_KSXY_RSSRCY1_Pos      (14)                                              /*!< CRYPTO_T::ECC_KSXY: RSSRCY1 Position   */
#define CRYPTO_ECC_KSXY_RSSRCY1_Msk      (0x3ul << CRYPTO_ECC_KSXY_RSSRCY1_Pos)            /*!< CRYPTO_T::ECC_KSXY: RSSRCY1 Mask       */

/**@}*/ /* CRYPTO_CONST */
/**@}*/ /* end of CRYPTO register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __CRYPTO_REG_H__ */
