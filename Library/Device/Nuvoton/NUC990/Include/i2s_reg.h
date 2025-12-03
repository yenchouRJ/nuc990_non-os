/**************************************************************************//**
* @file     i2s_reg.h
* @version  V1.00
* @brief    I2S register definition header file
*
* SPDX-License-Identifier: Apache-2.0
* @copyright (C) 2024 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#ifndef __I2S_REG_H__
#define __I2S_REG_H__

#if defined(__CC_ARM)
#pragma anon_unions
#endif

/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/

/**
   @addtogroup REGISTER Control Register
   @{
*/

/*---------------------- I2S Interface Controller -------------------------*/
/**
    @addtogroup I2S I2S Interface Controller(I2S)
    Memory Mapped Structure for I2S Controller
@{ */
typedef struct
{


/**
 * @var I2S_T::GLBCON
 * Offset: 0x00  I2S Global Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[1:0]   |BLOCK_EN  |Block Function Enable Register
 * |        |          |00 = The I2S & PCM interface Disabled.
 * |        |          |01 = The I2S interface Enabled.
 * |        |          |10 = The PCM interface Enabled.
 * |        |          |11 = Reserved.
 * |[3]     |IRQ_DMA_DATA_ZERO_EN|IRQ_DMA_DATA Zero and Sign Detect Enable Bit
 * |        |          |0 = Not allowed to set P_DMA_IRQ (I2S_GLBCON[10]) if I2S_PSR[3] is set to 1.
 * |        |          |1 = Allowed to set P_DMA_IRQ (I2S_GLBCON[10]) if I2S_PSR[3] is set to 1.
 * |[4]     |IRQ_DMA_CNTER_EN|IRQ_DMA Counter Function Enable Bit
 * |        |          |0 = Not allowed to set P_DMA_IRQ (I2S_GLBCON[10]) if I2S_PSR[4] is set to 1.
 * |        |          |1 = Allowed to set P_DMA_IRQ (I2S_GLBCON[10]) if (I2S_PSR[4]) is set to 1.
 * |[7]     |FIFO_TH   |FIFO Threshold Control Bit
 * |        |          |0 = The FIFO threshold is 8 levels.
 * |        |          |1 = The FIFO threshold is 4 levels.
 * |[9:8]   |BITS_SELECT|BITS Selection
 * |        |          |00 = Data format is 8-bits of a channel.
 * |        |          |01 = Data format is 16-bits of a channel.
 * |        |          |10 = Data format is 24-bits of a channel.
 * |        |          |11 = Reserve.
 * |[10]    |P_DMA_IRQ |Playback DMA Interrupt Request Bit
 * |        |          |When P_DMA_RIA_IRQ (I2S_PSR[0]) or DMA_DATA_ZERO_IRQ (I2S_PSR[3]) or DMA_CNTER_IRQ (I2S_PSR[4]) or P_FIFO_FULL (I2S_PSR[2]) or P_FIFO_EMPTY (I2S_PSR[1]) is set to 1 in playback and these corresponding interrupt enable bits are set to u201C1u201D, the bit P_DMA_IRQ will be set to 1, and this bit could be clear to 0 by CPU writing u201C1u201D
 * |        |          |And the bit is hardwired to ARM926 as interrupt request signal with an inverter.
 * |[11]    |R_DMA_IRQ |Record DMA Interrupt Request Bit
 * |        |          |When R_DMA_RIA_IRQ or R_FIFO_FULL or R_FIFO_EMPTY is set to u201C1u201D in record and these corresponding interrupt enable bits are set to u201C1u201D, the R_DMA_IRQ bit will be set to 1 automatically, and this bit could be cleared to 0 by CPU writing u201C1u201D
 * |        |          |The bit is hardwired to A rm96 as interrupt request signal with an inverter.
 * |[13:12] |P_DMA_IRQ_SEL|Play DMA Interrupt Request Selection Bits
 * |        |          |00 = When play DMA address reach DMA play destination end address, the P_DMA_RIA_IRQ will be issued.
 * |        |          |01 = When play DMA address reach each half of DMA play destination end address, the P_DMA_RIA_IRQ will be issued.
 * |        |          |10 = When play DMA address reach each quarter of DMA play destination end address, the P_DMA_RIA_IRQ will be issued.
 * |        |          |11 = When play DMA address reach each eighth of DMA play destination end address, the P_DMA_RIA_IRQ will be issued.
 * |[15:14] |R_DMA_IRQ_SEL|Record DMA Interrupt Request Selection Bits
 * |        |          |00 = When record DMA address reach DMA record destination end address, the R_DMA_RIA_IRQ will be issued.
 * |        |          |01 = When record DMA address reach each half of DMA record destination end address, the R_DMA_RIA_IRQ will be issued.
 * |        |          |10 = When record DMA address reach each quarter of DMA record destination end address, the R_DMA_RIA_IRQ will be issued.
 * |        |          |11 = When record DMA address reach each eighth of DMA record destination end address, the R_DMA_RIA_IRQ will be issued.
 * |[16]    |P_FIFO_EMPTY_IRQ_EN|Playback FIFO Empty Interrupt Request Enable Bit
 * |        |          |0 = P_FIFO_EMPTY_IRQ Disabled.
 * |        |          |1 = P_FIFO_EMPTY_IRQ Enabled.
 * |[17]    |P_FIFO_FULL_IRQ_EN|Playback FIFO Full Interrupt Request Enable Bit
 * |        |          |0 = P_FIFO_FULL_IRQ Disabled.
 * |        |          |1 = P_FIFO_FULL_IRQ Enabled.
 * |[18]    |R_FIFO_EMPTY_IRQ_EN|Record FIFO Empty Interrupt Request Enable Bit
 * |        |          |0 = R_FIFO_EMPTY_IRQ Disabled.
 * |        |          |1 = R_FIFO_EMPTY_IRQ Enabled.
 * |[19]    |R_FIFO_FULL_IRQ_EN|Record FIFO Full Interrupt Request Enable Bit
 * |        |          |0 = R_FIFO_FULL_IRQ Disabled.
 * |        |          |1 = R_FIFO_FULL_IRQ Enabled.
 * |[20]    |P_DMA_IRQ_EN|Playback DMA Interrupt Request Enable Bit
 * |        |          |0 = P_DMA_IRQ Disabled.
 * |        |          |1 = P_DMA_IRQ Enabled.
 * |[21]    |R_DMA_IRQ_EN|Record DMA Interrupt Request Enable Bit
 * |        |          |0 = R_DMA_IRQ Disabled.
 * |        |          |1 = R_DMA_IRQ Enabled.
 * @var I2S_T::RESET
 * Offset: 0x04  I2S Sub Block Reset Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |BLOCK_RESET|I2S/PCM RESET Control Bit
 * |        |          |0 = Release the I2S/PCM function block from reset mode.
 * |        |          |1 = Force the I2S/PCM function block to reset mode.
 * |[3]     |DMA_DATA_ZERO_EN|DMA_DATA Zero and Sign Detect Enable Bit
 * |        |          |0 = The DMA_DATA zero and sign detect function Disabled.
 * |        |          |1 = The DMA_DATA zero and sign detect function Enabled.
 * |[4]     |DMA_CNTER_EN|DMA Counter Function Enable Bit
 * |        |          |This function is supported to count playback data for software monitoring
 * |        |          |When one playback data is transferred to codec, the DMA counter subtracts 1
 * |        |          |When the I2S_COUNTER [31:0] register is Zero that set DMA_CNTER_IRQ bit =1.
 * |        |          |0 = The DMA counter function Disabled.
 * |        |          |1 = The DMA counter function Enabled.
 * |[5]     |PLAY      |I2S/PCM Playback Enable Bit
 * |        |          |0 = The playback path of I2S/PCM Disabled.
 * |        |          |1 = The playback path of I2S/PCM Enabled.
 * |[6]     |RECORD    |I2S/PCM Record Enable Bit
 * |        |          |0 = The record path of I2S/PCM Disabled.
 * |        |          |1 = The record path of I2S/PCM Enabled. 
 * |[13:12] |PLAY_SINGLE|Playback Single/Dual Channel Select Bits
 * |        |          |In I2S mode,
 * |        |          |00 = Reserved.
 * |        |          |01 = Reserved.
 * |        |          |10 = The playback is mono mode.
 * |        |          |11 = The playback is stereo mode.
 * |        |          |In PCM mode,
 * |        |          |00 = The playback is dual slot with slot1 data.
 * |        |          |01 = The playback is dual slot with slot0 data.
 * |        |          |10 = The playback is mono data. slot0 only.
 * |        |          |11 = The playback is dual slot.
 * |[15:14] |RECORD_SINGLE|Record Single/Dual Channel Select Bits
 * |        |          |00 = Reserved.
 * |        |          |01 = The record only selects i2s left channel/pcm slot0.
 * |        |          |10 = The record only selects i2s right channel/pcm slot1.
 * |        |          |11 = The record is dual channel.
 * |[16]    |RESET     |Audio Controller Reset Control Bit
 * |        |          |0 = The audio controller is normal operation.
 * |        |          |1 = The whole audio controller is reset.
 * |[20]    |SPLIT_DATA|SPLIT Left/Right and Slot1/Slot2 Data
 * |        |          |1 = Left channel data at I2S_RDESB / I2S_PDESB address, Right channel data at I2S_RDESB2 / I2S_PDESB2.
 * |        |          |0 = Left/Right channel data place at I2S_RDESB / I2S_PDESB address.
 * |        |          |The detail descriptions are shown in section 1.1.5.3 for this split data.
 * |        |          |Note: This bit work at stereo/dual slot mode only
 * @var I2S_T::RDESB
 * Offset: 0x08  I2S Record DMA Destination Base Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |AUDIO_RDESB|32-bit Record Destination Base Address
 * |        |          |This bit field indicates the record destination base address of DMA.
 * @var I2S_T::RDES_LENGTH
 * Offset: 0x0C  I2S Record DMA Destination Length Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |AUDIO_RDES_L|32-bit Record Destination Address Length
 * |        |          |The AUDIO_RDES_L [31:0] bits are read/write
 * |        |          |The minimum values for 8-bits, 16-bits, 18-bits, 20-bits, and 24-bits modes are 0x40.
 * @var I2S_T::RDESC
 * Offset: 0x10  I2S Record DMA Destination Current Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |AUDIO_RDESC|32-bit Record Destination Current Address (Read Only)
 * |        |          |This bit field indicates the current address of DMA record destination.
 * @var I2S_T::PDESB
 * Offset: 0x14  I2S Play DMA Destination Base Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |AUDIO_PDESB|32-bit Play Destination Base Address
 * |        |          |This bit field indicates the play destination base address of DMA.
 * @var I2S_T::PDES_LENGTH
 * Offset: 0x18  I2S Play DMA Destination Length Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |AUDIO_PDES_L|32-bit Play Destination Address Length
 * |        |          |The minimum values for 8-bits, 16-bits, 18-bits, 20-bits, and 24-bits modes are 0x40.
 * @var I2S_T::PDESC
 * Offset: 0x1C  I2S Play DMA Destination Current Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |AUDIO_PDESC|32-bit Play Destination Current Address (Read Only)
 * |        |          |This bit field indicates the current address of DMA play destination.
 * @var I2S_T::RSR
 * Offset: 0x20  I2S Record Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |R_DMA_RIA_IRQ|Record DMA Reach Indicative Address Interrupt Request Bit
 * |        |          |0 = Record DMA address does not reach the indicative address by R_DMA_IRQ_SEL (I2S_GLBCON[15:14]).
 * |        |          |1 = Record the DMA address reach the indicative address by R_DMA_IRQ_SEL (I2S_GLBCON[15:14]).
 * |        |          |Note: The R_DMA_RIA_IRQ bit is readable, and only can be clear by write u201C1u201D to this bit.
 * |[1]     |R_FIFO_EMPTY|Record FIFO EMPTY Indicator Bit
 * |        |          |When record FIFO is empty and the record data is read from record FIFO, the R_FIFO_EMPTY bit is set to 1
 * |        |          |This bit indicates the empty error of record FIFO is happened.
 * |        |          |0 = The empty error of record FIFO is not happened.
 * |        |          |1 = The empty error of record FIFO is happened.
 * |        |          |Note: The R_FIFO_EMPTY bit is readable, and only can be clear by write u201C1u201D to this bit.
 * |[2]     |R_FIFO_FULL|Record FIFO Full Indicator Bit
 * |        |          |When record FIFO is full and the record data is written into record FIFO, the R_FIFO_FULL bit is set to 1
 * |        |          |This bit indicates the full error of record FIFO is happened.
 * |        |          |0 = The full error of record FIFO is not happened.
 * |        |          |1 = The full error of record FIFO is happened.
 * |        |          |Note: The R_FIFO_FULL bit is readable, and only can be clear by write u201C1u201D to this bit.
 * |[7:5]   |R_DMA_RIA_SN|Record DMA Reach Indicative Address Section Number Bit (Read Only)
 * |        |          |R_DMA_IRQ_SEL (I2S_GLBCON[15:14]) = 01, R_DMA_RIA_SN[2:0]= 1, 0.
 * |        |          |R_DMA_IRQ_SEL (I2S_GLBCON[15:14]) = 10, R_DMA_RIA_SN[2:0]= 1, 2, 3, 0.
 * |        |          |R_DMA_IRQ_SEL (I2S_GLBCON[15:14]) = 11, R_DMA_RIA_SN[2:0]= 1, 2, 3, 4, 5, 6, 7, 0.
 * @var I2S_T::PSR
 * Offset: 0x24  I2S Play Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |P_DMA_RIA_IRQ|Playback DMA Reach Indicative Address Interrupt Request Bit
 * |        |          |0 = Playback DMA address does not reach the specific address by P_DMA_IRQ_SEL (I2S_GLBCON[13:12]) bits.
 * |        |          |1 = Playback DMA address reach the indicative address by P_DMA_IRQ_SEL (I2S_GLBCON[13:12]) bits.
 * |        |          |Note: The P_DMA_RIA_IRQ bit is readable, and only can be clear by write u201C1u201D to this bit.
 * |[1]     |P_FIFO_EMPTY|Playback FIFO EMPTY Indicator Bit
 * |        |          |When playback FIFO is empty and the playback data is read from playback FIFO, the P_FIFO_EMPTY bit is set to 1
 * |        |          |This bit indicates the empty error of playback FIFO is happened.
 * |        |          |0 = The empty error of playback FIFO is not happened.
 * |        |          |1 = The empty error of playback FIFO is happened.
 * |        |          |Note: The P_FIFO_EMPTY bit is readable, and only can be clear by write u201C1u201D to this bit.
 * |[2]     |P_FIFO_FULL|Playback FIFO Full Indicator Bit
 * |        |          |When playback FIFO is full and the playback data is written into playback FIFO, the P_FIFO_FULL bit is set to 1
 * |        |          |This bit indicates the full error of playback FIFO is happened.
 * |        |          |0 = The full error of playback FIFO is not happened.
 * |        |          |1 = The full error of playback FIFO is happened.
 * |        |          |Note: The TP_FIFO_FULL bit is readable, and only can be clear by write u201C1u201D to this bit.
 * |[3]     |DMA_DATA_ZERO_IRQ|DMA_DATA Zero IRQ
 * |        |          |0 = Not found the all data bit of playback DMA is zero or its sign bit does not change (two channels).
 * |        |          |1 = Found all the data bit of playback DMA is zero or its sign bit change (two channels).
 * |        |          |Note: The DMA_DATA_ZERO_IRQ bit is readable , and only can be clear by write u201C1u201D to clear this bit.
 * |[4]     |DMA_CNTER_IRQ|DMA Counter IRQ
 * |        |          |When one playback data is transferred to codec, the DMA counter subtracts 1
 * |        |          |The counting of playback data number is used for software monitoring
 * |        |          |If the DMA counter I2S_COUNTER [31:0] is Zero, this bit DMA_CNTER_IRQ will be set to 1.
 * |        |          |0 = DMA counter I2S_COUNTER [31:0] has not counted to zero.
 * |        |          |1 = DMA counter I2S_COUNTER [31:0] has counted down to zero.
 * |        |          |Note: The DMA_CNTER_IRQ bit is readable , and only can be clear by write u201C1u201D to clear this bit.
 * |[7:5]   |P_DMA_RIA_SN|Play DMA Reach Indicative Address Section Number Bit (Read Only)
 * |        |          |P_DMA_IRQ_SEL (I2S_GLBCON[13:12]) = 01, P_DMA_RIA_SN[2:0]= 1, 0.
 * |        |          |P_DMA_IRQ_SEL (I2S_GLBCON[13:12]) = 10, P_DMA_RIA_SN[2:0]= 1, 2, 3, 0.
 * |        |          |P_DMA_IRQ_SEL (I2S_GLBCON[13:12]) = 11, P_DMA_RIA_SN[2:0]= 1, 2, 3, 4, 5, 6, 7, 0.
 * @var I2S_T::CON
 * Offset: 0x28  I2S Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3]     |FORMAT    |I2S Format Selection Bit
 * |        |          |0 = I2S compatible format is selected.
 * |        |          |1 = MSB-justified format is selected.
 * |[4]     |MCLK_SEL  |MCLK Clock Selection Bit
 * |        |          |0 = I2S MCLK output will follow the PRS [3:0] setting.
 * |        |          |1 = I2S MCLK output will be the same with the input frequency of PLL.
 * |[7:5]   |BCLK_DIV  |I2S Serial Data Clock Frequency Selection Bit
 * |        |          |This bit field is used to decide the relationship of frequency between PLL and I2S serial data clock
 * |        |          |The frequency of I2S serial data clock follows the formula below:
 * |[19:16] |PRS       |I2S Frequency PRE_SCALER Selection Bits
 * |        |          |0000 = MCLK=FPLL/1.
 * |        |          |0001 = MCLK=FPLL/2.
 * |        |          |0010 = MCLK=FPLL/3.
 * |        |          |0011 = MCLK=FPLL/4.
 * |        |          |0100 = MCLK=FPLL/5.
 * |        |          |0101 = MCLK=FPLL/6.
 * |        |          |0110 = MCLK=FPLL/7.
 * |        |          |0111 = MCLK=FPLL/8.
 * |        |          |1000 = RESERVED.
 * |        |          |1001 = MCLK=FPLL/10.
 * |        |          |1010 = RESERVED.
 * |        |          |1011 = MCLK=FPLL/12.
 * |        |          |1100 = RESERVED.
 * |        |          |1101 = MCLK=FPLL/14.
 * |        |          |1110 = RESERVED.
 * |        |          |1111 = MCLK=FPLL/16.
 * |        |          |Note 1: FPLL Is the Input PLL Frequency, MCLK Is the Output Main Clock.
 * |        |          |Note 2: When the division factor is 3/5/7, the duty cycle of MCLK is not 50%, the high duration is 0.5*FPLL.
 * |[20]    |SLAVE     |I2S Slave Mode Selection Bit
 * |        |          |0 = I2S Master mode.
 * |        |          |1 = I2S Slave mode. 
 * @var I2S_T::COUNTER
 * Offset: 0x2C  I2S Play DMA Down Counter Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |COUNTER   |Play DMA Down Counter
 * |        |          |This bit field is used to count playback data number for software monitoring
 * |        |          |When one playback data is transferred to codec, the DMA counter subtracts 1
 * |        |          |If the I2S_COUNTER [31:0] register is Zero, the DMA_CNTER_IRQ (I2S_PSR[4]) will be set to 1.
 * @var I2S_T::PCMCON
 * Offset: 0x30  I2S PCM Mode Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |BCLKP     |BCLK Polarity
 * |        |          |0 = Send data at rising edge, latch data at falling edge.
 * |        |          |1 = Send data at falling edge, latch data at rising edge.
 * |[15:8]  |PCM_PRS   |PCM_BCLK Frequency PRE_SCALER Selection Bits
 * |        |          |For BCLK of PCM mode, this control register setting and PCM BCLK frequency are describes as follows.
 * |        |          |(1) Case1 : When PCM_MCLK_PRS (I2S_PCMCON[31:28]) = 0.
 * |        |          |BCLK frequency = PCM_MCLK frequency / (2*(PCM_PRS + 1)).
 * |        |          |Where PCM_PRS = 0,1,2,3,4,u2026.
 * |        |          |(2) Case2 : When PCM_MCLK_PRS (I2S_PCMCON[31:28])u22600
 * |        |          |BCLK frequency = PCM_MCLK frequency / (2*n), where n=1,2,3,4,u2026.
 * |        |          |PCM_PRS = (PCM_MCLK_PRS + 1)*n u2013 1, where the value of n equals to the value of n, which is shown in above BCLK frequency formula.
 * |[25:16] |FS_PERIOD |FS Pulse Period
 * |        |          |BCLK counts between two FS pulse.
 * |        |          |User uses this register to set sample rate.
 * |        |          |0x0 = 1 BCLK.
 * |        |          |0x1 = 2 BCLKs.
 * |        |          |0x2 = 3 BCLKs.
 * |        |          |u2026
 * |        |          |0x3FF = 1024 BCLKs.
 * |[31:28] |PCM_MCLK_PRS|PCM MCLK Frequency PRE_SCALER Selection Bits
 * |        |          |0000 = PCM_MCLK=FPLL/1.
 * |        |          |0001 = PCM_MCLK=FPLL/2.
 * |        |          |0010 = PCM_MCLK=FPLL/3.
 * |        |          |0011 = PCM_MCLK=FPLL/4.
 * |        |          |0100 = PCM_MCLK=FPLL/5.
 * |        |          |0101 = PCM_MCLK=FPLL/6.
 * |        |          |0110 = PCM_MCLK=FPLL/7.
 * |        |          |0111 = PCM_MCLK=FPLL/8.
 * |        |          |1000 = Reserved.
 * |        |          |1001 = PCM_MCLK=FPLL/10.
 * |        |          |1010 = Reserved.
 * |        |          |1011 = PCM_MCLK=FPLL/12.
 * |        |          |1100 = Reserved.
 * |        |          |1101 = PCM_MCLK=FPLL/14.
 * |        |          |1110 = Reserved.
 * |        |          |1111 = PCM_MCLK=FPLL/16.
 * |        |          |Note 1: FPLL Is the Input PLL Frequency, MCLK Is the Output Main Clock.
 * |        |          |Note 2: When the division factor is 3/5/7, the duty cycle of MCLK is not 50%, the high duration is 0.5*FPLL.
 * @var I2S_T::PCMS1ST
 * Offset: 0x34  I2S PCM Mode Slot 1 Start Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[9:0]   |SLOT1_I_START|Slot 1 Data in Start Position
 * |        |          |This bit field is used to set the start position of slot1 input data.
 * |        |          |Example as follows.
 * |        |          |For Short Frame Sync, set SLOT1_I_START to 1.
 * |        |          |For Long Frame Sync, set SLOT1_I_START to 0.
 * |[25:16] |SLOT1_O_START|Slot 1 Data Out Start Position
 * |        |          |This bit field is used to set the start position of slot1 output data.
 * |        |          |Example as follows.
 * |        |          |For Short Frame Sync, set SLOT1_O_START to 1.
 * |        |          |For Long Frame Sync, set SLOT1_O_START to 0.
 * @var I2S_T::PCMS2ST
 * Offset: 0x38  I2S PCM Mode Slot 2 Start Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[9:0]   |SLOT2_I_START|Slot 2 Data in Start Position
 * |        |          |This bit field is used to set the start position of slot2 input data.
 * |[25:16] |SLOT2_O_START|Slot 2 Data Out Start Position
 * |        |          |This bit field is used to set the start position of slot2 output data.
 * @var I2S_T::RDESB2
 * Offset: 0x40  I2S Record DMA Destination Base Address 2 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |AUDIO_RDESB2|32-bit Record Destination Base Address for Right Channel
 * |        |          |This bit field indicates the record destination base address of DMA.
 * @var I2S_T::PDESB2
 * Offset: 0x44  I2S Play DMA Destination Base Address 2 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |AUDIO_PDESB2|32-bit Play Destination Base Address for Right Channel
 * |        |          |This bit field indicates the play destination base address of DMA.
 */
    __IO uint32_t GLBCON;                /*!< [0x0000] I2S Global Control Register                                      */
    __IO uint32_t RESET;                 /*!< [0x0004] I2S Sub Block Reset Control Register                             */
    __IO uint32_t RDESB;                 /*!< [0x0008] I2S Record DMA Destination Base Address Register                 */
    __IO uint32_t RDES_LENGTH;           /*!< [0x000c] I2S Record DMA Destination Length Register                       */
    __I  uint32_t RDESC;                 /*!< [0x0010] I2S Record DMA Destination Current Address Register              */
    __IO uint32_t PDESB;                 /*!< [0x0014] I2S Play DMA Destination Base Address Register                   */
    __IO uint32_t PDES_LENGTH;           /*!< [0x0018] I2S Play DMA Destination Length Register                         */
    __I  uint32_t PDESC;                 /*!< [0x001c] I2S Play DMA Destination Current Address Register                */
    __IO uint32_t RSR;                   /*!< [0x0020] I2S Record Status Register                                       */
    __IO uint32_t PSR;                   /*!< [0x0024] I2S Play Status Register                                         */
    __IO uint32_t CON;                   /*!< [0x0028] I2S Control Register                                             */
    __IO uint32_t COUNTER;               /*!< [0x002c] I2S Play DMA Down Counter Register                               */
    __IO uint32_t PCMCON;                /*!< [0x0030] I2S PCM Mode Control Register                                    */
    __IO uint32_t PCMS1ST;               /*!< [0x0034] I2S PCM Mode Slot 1 Start Register                               */
    __IO uint32_t PCMS2ST;               /*!< [0x0038] I2S PCM Mode Slot 2 Start Register                               */
    __I  uint32_t RESERVE0[1];
    __IO uint32_t RDESB2;                /*!< [0x0040] I2S Record DMA Destination Base Address 2 Register               */
    __IO uint32_t PDESB2;                /*!< [0x0044] I2S Play DMA Destination Base Address 2 Register                 */

} I2S_T;

/**
    @addtogroup I2S_CONST I2S Bit Field Definition
    Constant Definitions for I2S Controller
@{ */

#define I2S_GLBCON_BLOCK_EN_Pos          (0)                                               /*!< I2S_T::GLBCON: BLOCK_EN Position       */
#define I2S_GLBCON_BLOCK_EN_Msk          (0x3ul << I2S_GLBCON_BLOCK_EN_Pos)                /*!< I2S_T::GLBCON: BLOCK_EN Mask           */

#define I2S_GLBCON_IRQ_DMA_DATA_ZERO_EN_Pos (3)                                            /*!< I2S_T::GLBCON: IRQ_DMA_DATA_ZERO_EN Position*/
#define I2S_GLBCON_IRQ_DMA_DATA_ZERO_EN_Msk (0x1ul << I2S_GLBCON_IRQ_DMA_DATA_ZERO_EN_Pos) /*!< I2S_T::GLBCON: IRQ_DMA_DATA_ZERO_EN Mask*/

#define I2S_GLBCON_IRQ_DMA_CNTER_EN_Pos  (4)                                               /*!< I2S_T::GLBCON: IRQ_DMA_CNTER_EN Position*/
#define I2S_GLBCON_IRQ_DMA_CNTER_EN_Msk  (0x1ul << I2S_GLBCON_IRQ_DMA_CNTER_EN_Pos)        /*!< I2S_T::GLBCON: IRQ_DMA_CNTER_EN Mask   */

#define I2S_GLBCON_FIFO_TH_Pos           (7)                                               /*!< I2S_T::GLBCON: FIFO_TH Position        */
#define I2S_GLBCON_FIFO_TH_Msk           (0x1ul << I2S_GLBCON_FIFO_TH_Pos)                 /*!< I2S_T::GLBCON: FIFO_TH Mask            */

#define I2S_GLBCON_BITS_SELECT_Pos       (8)                                               /*!< I2S_T::GLBCON: BITS_SELECT Position    */
#define I2S_GLBCON_BITS_SELECT_Msk       (0x3ul << I2S_GLBCON_BITS_SELECT_Pos)             /*!< I2S_T::GLBCON: BITS_SELECT Mask        */

#define I2S_GLBCON_P_DMA_IRQ_Pos         (10)                                              /*!< I2S_T::GLBCON: P_DMA_IRQ Position      */
#define I2S_GLBCON_P_DMA_IRQ_Msk         (0x1ul << I2S_GLBCON_P_DMA_IRQ_Pos)               /*!< I2S_T::GLBCON: P_DMA_IRQ Mask          */

#define I2S_GLBCON_R_DMA_IRQ_Pos         (11)                                              /*!< I2S_T::GLBCON: R_DMA_IRQ Position      */
#define I2S_GLBCON_R_DMA_IRQ_Msk         (0x1ul << I2S_GLBCON_R_DMA_IRQ_Pos)               /*!< I2S_T::GLBCON: R_DMA_IRQ Mask          */

#define I2S_GLBCON_P_DMA_IRQ_SEL_Pos     (12)                                              /*!< I2S_T::GLBCON: P_DMA_IRQ_SEL Position  */
#define I2S_GLBCON_P_DMA_IRQ_SEL_Msk     (0x3ul << I2S_GLBCON_P_DMA_IRQ_SEL_Pos)           /*!< I2S_T::GLBCON: P_DMA_IRQ_SEL Mask      */

#define I2S_GLBCON_R_DMA_IRQ_SEL_Pos     (14)                                              /*!< I2S_T::GLBCON: R_DMA_IRQ_SEL Position  */
#define I2S_GLBCON_R_DMA_IRQ_SEL_Msk     (0x3ul << I2S_GLBCON_R_DMA_IRQ_SEL_Pos)           /*!< I2S_T::GLBCON: R_DMA_IRQ_SEL Mask      */

#define I2S_GLBCON_P_FIFO_EMPTY_IRQ_EN_Pos (16)                                            /*!< I2S_T::GLBCON: P_FIFO_EMPTY_IRQ_EN Position*/
#define I2S_GLBCON_P_FIFO_EMPTY_IRQ_EN_Msk (0x1ul << I2S_GLBCON_P_FIFO_EMPTY_IRQ_EN_Pos)   /*!< I2S_T::GLBCON: P_FIFO_EMPTY_IRQ_EN Mask*/

#define I2S_GLBCON_P_FIFO_FULL_IRQ_EN_Pos (17)                                             /*!< I2S_T::GLBCON: P_FIFO_FULL_IRQ_EN Position*/
#define I2S_GLBCON_P_FIFO_FULL_IRQ_EN_Msk (0x1ul << I2S_GLBCON_P_FIFO_FULL_IRQ_EN_Pos)     /*!< I2S_T::GLBCON: P_FIFO_FULL_IRQ_EN Mask */

#define I2S_GLBCON_R_FIFO_EMPTY_IRQ_EN_Pos (18)                                            /*!< I2S_T::GLBCON: R_FIFO_EMPTY_IRQ_EN Position*/
#define I2S_GLBCON_R_FIFO_EMPTY_IRQ_EN_Msk (0x1ul << I2S_GLBCON_R_FIFO_EMPTY_IRQ_EN_Pos)   /*!< I2S_T::GLBCON: R_FIFO_EMPTY_IRQ_EN Mask*/

#define I2S_GLBCON_R_FIFO_FULL_IRQ_EN_Pos (19)                                             /*!< I2S_T::GLBCON: R_FIFO_FULL_IRQ_EN Position*/
#define I2S_GLBCON_R_FIFO_FULL_IRQ_EN_Msk (0x1ul << I2S_GLBCON_R_FIFO_FULL_IRQ_EN_Pos)     /*!< I2S_T::GLBCON: R_FIFO_FULL_IRQ_EN Mask */

#define I2S_GLBCON_P_DMA_IRQ_EN_Pos      (20)                                              /*!< I2S_T::GLBCON: P_DMA_IRQ_EN Position   */
#define I2S_GLBCON_P_DMA_IRQ_EN_Msk      (0x1ul << I2S_GLBCON_P_DMA_IRQ_EN_Pos)            /*!< I2S_T::GLBCON: P_DMA_IRQ_EN Mask       */

#define I2S_GLBCON_R_DMA_IRQ_EN_Pos      (21)                                              /*!< I2S_T::GLBCON: R_DMA_IRQ_EN Position   */
#define I2S_GLBCON_R_DMA_IRQ_EN_Msk      (0x1ul << I2S_GLBCON_R_DMA_IRQ_EN_Pos)            /*!< I2S_T::GLBCON: R_DMA_IRQ_EN Mask       */

#define I2S_RESET_BLOCK_RESET_Pos        (0)                                               /*!< I2S_T::RESET: BLOCK_RESET Position     */
#define I2S_RESET_BLOCK_RESET_Msk        (0x1ul << I2S_RESET_BLOCK_RESET_Pos)              /*!< I2S_T::RESET: BLOCK_RESET Mask         */

#define I2S_RESET_DMA_DATA_ZERO_EN_Pos   (3)                                               /*!< I2S_T::RESET: DMA_DATA_ZERO_EN Position*/
#define I2S_RESET_DMA_DATA_ZERO_EN_Msk   (0x1ul << I2S_RESET_DMA_DATA_ZERO_EN_Pos)         /*!< I2S_T::RESET: DMA_DATA_ZERO_EN Mask    */

#define I2S_RESET_DMA_CNTER_EN_Pos       (4)                                               /*!< I2S_T::RESET: DMA_CNTER_EN Position    */
#define I2S_RESET_DMA_CNTER_EN_Msk       (0x1ul << I2S_RESET_DMA_CNTER_EN_Pos)             /*!< I2S_T::RESET: DMA_CNTER_EN Mask        */

#define I2S_RESET_PLAY_Pos               (5)                                               /*!< I2S_T::RESET: PLAY Position            */
#define I2S_RESET_PLAY_Msk               (0x1ul << I2S_RESET_PLAY_Pos)                     /*!< I2S_T::RESET: PLAY Mask                */

#define I2S_RESET_RECORD_Pos             (6)                                               /*!< I2S_T::RESET: RECORD Position          */
#define I2S_RESET_RECORD_Msk             (0x1ul << I2S_RESET_RECORD_Pos)                   /*!< I2S_T::RESET: RECORD Mask              */

#define I2S_RESET_PLAY_SINGLE_Pos        (12)                                              /*!< I2S_T::RESET: PLAY_SINGLE Position     */
#define I2S_RESET_PLAY_SINGLE_Msk        (0x3ul << I2S_RESET_PLAY_SINGLE_Pos)              /*!< I2S_T::RESET: PLAY_SINGLE Mask         */

#define I2S_RESET_RECORD_SINGLE_Pos      (14)                                              /*!< I2S_T::RESET: RECORD_SINGLE Position   */
#define I2S_RESET_RECORD_SINGLE_Msk      (0x3ul << I2S_RESET_RECORD_SINGLE_Pos)            /*!< I2S_T::RESET: RECORD_SINGLE Mask       */

#define I2S_RESET_RESET_Pos              (16)                                              /*!< I2S_T::RESET: RESET Position           */
#define I2S_RESET_RESET_Msk              (0x1ul << I2S_RESET_RESET_Pos)                    /*!< I2S_T::RESET: RESET Mask               */

#define I2S_RESET_SPLIT_DATA_Pos         (20)                                              /*!< I2S_T::RESET: SPLIT_DATA Position      */
#define I2S_RESET_SPLIT_DATA_Msk         (0x1ul << I2S_RESET_SPLIT_DATA_Pos)               /*!< I2S_T::RESET: SPLIT_DATA Mask          */

#define I2S_RDESB_AUDIO_RDESB_Pos        (0)                                               /*!< I2S_T::RDESB: AUDIO_RDESB Position     */
#define I2S_RDESB_AUDIO_RDESB_Msk        (0xfffffffful << I2S_RDESB_AUDIO_RDESB_Pos)       /*!< I2S_T::RDESB: AUDIO_RDESB Mask         */

#define I2S_RDES_LENGTH_AUDIO_RDES_L_Pos (0)                                               /*!< I2S_T::RDES_LENGTH: AUDIO_RDES_L Position*/
#define I2S_RDES_LENGTH_AUDIO_RDES_L_Msk (0xfffffffful << I2S_RDES_LENGTH_AUDIO_RDES_L_Pos) /*!< I2S_T::RDES_LENGTH: AUDIO_RDES_L Mask  */

#define I2S_RDESC_AUDIO_RDESC_Pos        (0)                                               /*!< I2S_T::RDESC: AUDIO_RDESC Position     */
#define I2S_RDESC_AUDIO_RDESC_Msk        (0xfffffffful << I2S_RDESC_AUDIO_RDESC_Pos)       /*!< I2S_T::RDESC: AUDIO_RDESC Mask         */

#define I2S_PDESB_AUDIO_PDESB_Pos        (0)                                               /*!< I2S_T::PDESB: AUDIO_PDESB Position     */
#define I2S_PDESB_AUDIO_PDESB_Msk        (0xfffffffful << I2S_PDESB_AUDIO_PDESB_Pos)       /*!< I2S_T::PDESB: AUDIO_PDESB Mask         */

#define I2S_PDES_LENGTH_AUDIO_PDES_L_Pos (0)                                               /*!< I2S_T::PDES_LENGTH: AUDIO_PDES_L Position*/
#define I2S_PDES_LENGTH_AUDIO_PDES_L_Msk (0xfffffffful << I2S_PDES_LENGTH_AUDIO_PDES_L_Pos) /*!< I2S_T::PDES_LENGTH: AUDIO_PDES_L Mask  */

#define I2S_PDESC_AUDIO_PDESC_Pos        (0)                                               /*!< I2S_T::PDESC: AUDIO_PDESC Position     */
#define I2S_PDESC_AUDIO_PDESC_Msk        (0xfffffffful << I2S_PDESC_AUDIO_PDESC_Pos)       /*!< I2S_T::PDESC: AUDIO_PDESC Mask         */

#define I2S_RSR_R_DMA_RIA_IRQ_Pos        (0)                                               /*!< I2S_T::RSR: R_DMA_RIA_IRQ Position     */
#define I2S_RSR_R_DMA_RIA_IRQ_Msk        (0x1ul << I2S_RSR_R_DMA_RIA_IRQ_Pos)              /*!< I2S_T::RSR: R_DMA_RIA_IRQ Mask         */

#define I2S_RSR_R_FIFO_EMPTY_Pos         (1)                                               /*!< I2S_T::RSR: R_FIFO_EMPTY Position      */
#define I2S_RSR_R_FIFO_EMPTY_Msk         (0x1ul << I2S_RSR_R_FIFO_EMPTY_Pos)               /*!< I2S_T::RSR: R_FIFO_EMPTY Mask          */

#define I2S_RSR_R_FIFO_FULL_Pos          (2)                                               /*!< I2S_T::RSR: R_FIFO_FULL Position       */
#define I2S_RSR_R_FIFO_FULL_Msk          (0x1ul << I2S_RSR_R_FIFO_FULL_Pos)                /*!< I2S_T::RSR: R_FIFO_FULL Mask           */

#define I2S_RSR_R_DMA_RIA_SN_Pos         (5)                                               /*!< I2S_T::RSR: R_DMA_RIA_SN Position      */
#define I2S_RSR_R_DMA_RIA_SN_Msk         (0x7ul << I2S_RSR_R_DMA_RIA_SN_Pos)               /*!< I2S_T::RSR: R_DMA_RIA_SN Mask          */

#define I2S_PSR_P_DMA_RIA_IRQ_Pos        (0)                                               /*!< I2S_T::PSR: P_DMA_RIA_IRQ Position     */
#define I2S_PSR_P_DMA_RIA_IRQ_Msk        (0x1ul << I2S_PSR_P_DMA_RIA_IRQ_Pos)              /*!< I2S_T::PSR: P_DMA_RIA_IRQ Mask         */

#define I2S_PSR_P_FIFO_EMPTY_Pos         (1)                                               /*!< I2S_T::PSR: P_FIFO_EMPTY Position      */
#define I2S_PSR_P_FIFO_EMPTY_Msk         (0x1ul << I2S_PSR_P_FIFO_EMPTY_Pos)               /*!< I2S_T::PSR: P_FIFO_EMPTY Mask          */

#define I2S_PSR_P_FIFO_FULL_Pos          (2)                                               /*!< I2S_T::PSR: P_FIFO_FULL Position       */
#define I2S_PSR_P_FIFO_FULL_Msk          (0x1ul << I2S_PSR_P_FIFO_FULL_Pos)                /*!< I2S_T::PSR: P_FIFO_FULL Mask           */

#define I2S_PSR_DMA_DATA_ZERO_IRQ_Pos    (3)                                               /*!< I2S_T::PSR: DMA_DATA_ZERO_IRQ Position */
#define I2S_PSR_DMA_DATA_ZERO_IRQ_Msk    (0x1ul << I2S_PSR_DMA_DATA_ZERO_IRQ_Pos)          /*!< I2S_T::PSR: DMA_DATA_ZERO_IRQ Mask     */

#define I2S_PSR_DMA_CNTER_IRQ_Pos        (4)                                               /*!< I2S_T::PSR: DMA_CNTER_IRQ Position     */
#define I2S_PSR_DMA_CNTER_IRQ_Msk        (0x1ul << I2S_PSR_DMA_CNTER_IRQ_Pos)              /*!< I2S_T::PSR: DMA_CNTER_IRQ Mask         */

#define I2S_PSR_P_DMA_RIA_SN_Pos         (5)                                               /*!< I2S_T::PSR: P_DMA_RIA_SN Position      */
#define I2S_PSR_P_DMA_RIA_SN_Msk         (0x7ul << I2S_PSR_P_DMA_RIA_SN_Pos)               /*!< I2S_T::PSR: P_DMA_RIA_SN Mask          */

#define I2S_CON_FORMAT_Pos               (3)                                               /*!< I2S_T::CON: FORMAT Position            */
#define I2S_CON_FORMAT_Msk               (0x1ul << I2S_CON_FORMAT_Pos)                     /*!< I2S_T::CON: FORMAT Mask                */

#define I2S_CON_MCLK_SEL_Pos             (4)                                               /*!< I2S_T::CON: MCLK_SEL Position          */
#define I2S_CON_MCLK_SEL_Msk             (0x1ul << I2S_CON_MCLK_SEL_Pos)                   /*!< I2S_T::CON: MCLK_SEL Mask              */

#define I2S_CON_BCLK_DIV_Pos             (5)                                               /*!< I2S_T::CON: BCLK_DIV Position          */
#define I2S_CON_BCLK_DIV_Msk             (0x7ul << I2S_CON_BCLK_DIV_Pos)                   /*!< I2S_T::CON: BCLK_DIV Mask              */

#define I2S_CON_PRS_Pos                  (16)                                              /*!< I2S_T::CON: PRS Position               */
#define I2S_CON_PRS_Msk                  (0xful << I2S_CON_PRS_Pos)                        /*!< I2S_T::CON: PRS Mask                   */

#define I2S_CON_SLAVE_Pos                (20)                                              /*!< I2S_T::CON: SLAVE Position             */
#define I2S_CON_SLAVE_Msk                (0x1ul << I2S_CON_SLAVE_Pos)                      /*!< I2S_T::CON: SLAVE Mask                 */

#define I2S_COUNTER_COUNTER_Pos          (0)                                               /*!< I2S_T::COUNTER: COUNTER Position       */
#define I2S_COUNTER_COUNTER_Msk          (0xfffffffful << I2S_COUNTER_COUNTER_Pos)         /*!< I2S_T::COUNTER: COUNTER Mask           */

#define I2S_PCMCON_BCLKP_Pos             (0)                                               /*!< I2S_T::PCMCON: BCLKP Position          */
#define I2S_PCMCON_BCLKP_Msk             (0x1ul << I2S_PCMCON_BCLKP_Pos)                   /*!< I2S_T::PCMCON: BCLKP Mask              */

#define I2S_PCMCON_PCM_PRS_Pos           (8)                                               /*!< I2S_T::PCMCON: PCM_PRS Position        */
#define I2S_PCMCON_PCM_PRS_Msk           (0xfful << I2S_PCMCON_PCM_PRS_Pos)                /*!< I2S_T::PCMCON: PCM_PRS Mask            */

#define I2S_PCMCON_FS_PERIOD_Pos         (16)                                              /*!< I2S_T::PCMCON: FS_PERIOD Position      */
#define I2S_PCMCON_FS_PERIOD_Msk         (0x3fful << I2S_PCMCON_FS_PERIOD_Pos)             /*!< I2S_T::PCMCON: FS_PERIOD Mask          */

#define I2S_PCMCON_PCM_MCLK_PRS_Pos      (28)                                              /*!< I2S_T::PCMCON: PCM_MCLK_PRS Position   */
#define I2S_PCMCON_PCM_MCLK_PRS_Msk      (0xful << I2S_PCMCON_PCM_MCLK_PRS_Pos)            /*!< I2S_T::PCMCON: PCM_MCLK_PRS Mask       */

#define I2S_PCMS1ST_SLOT1_I_START_Pos    (0)                                               /*!< I2S_T::PCMS1ST: SLOT1_I_START Position */
#define I2S_PCMS1ST_SLOT1_I_START_Msk    (0x3fful << I2S_PCMS1ST_SLOT1_I_START_Pos)        /*!< I2S_T::PCMS1ST: SLOT1_I_START Mask     */

#define I2S_PCMS1ST_SLOT1_O_START_Pos    (16)                                              /*!< I2S_T::PCMS1ST: SLOT1_O_START Position */
#define I2S_PCMS1ST_SLOT1_O_START_Msk    (0x3fful << I2S_PCMS1ST_SLOT1_O_START_Pos)        /*!< I2S_T::PCMS1ST: SLOT1_O_START Mask     */

#define I2S_PCMS2ST_SLOT2_I_START_Pos    (0)                                               /*!< I2S_T::PCMS2ST: SLOT2_I_START Position */
#define I2S_PCMS2ST_SLOT2_I_START_Msk    (0x3fful << I2S_PCMS2ST_SLOT2_I_START_Pos)        /*!< I2S_T::PCMS2ST: SLOT2_I_START Mask     */

#define I2S_PCMS2ST_SLOT2_O_START_Pos    (16)                                              /*!< I2S_T::PCMS2ST: SLOT2_O_START Position */
#define I2S_PCMS2ST_SLOT2_O_START_Msk    (0x3fful << I2S_PCMS2ST_SLOT2_O_START_Pos)        /*!< I2S_T::PCMS2ST: SLOT2_O_START Mask     */

#define I2S_RDESB2_AUDIO_RDESB2_Pos      (0)                                               /*!< I2S_T::RDESB2: AUDIO_RDESB2 Position   */
#define I2S_RDESB2_AUDIO_RDESB2_Msk      (0xfffffffful << I2S_RDESB2_AUDIO_RDESB2_Pos)     /*!< I2S_T::RDESB2: AUDIO_RDESB2 Mask       */

#define I2S_PDESB2_AUDIO_PDESB2_Pos      (0)                                               /*!< I2S_T::PDESB2: AUDIO_PDESB2 Position   */
#define I2S_PDESB2_AUDIO_PDESB2_Msk      (0xfffffffful << I2S_PDESB2_AUDIO_PDESB2_Pos)     /*!< I2S_T::PDESB2: AUDIO_PDESB2 Mask       */

/**@}*/ /* I2S_CONST */
/**@}*/ /* end of I2S register group */
/**@}*/ /* end of REGISTER group */

#if defined(__CC_ARM)
#pragma no_anon_unions
#endif

#endif /* __I2S_REG_H__ */
