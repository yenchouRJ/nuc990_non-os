/**************************************************************************//**
 * @file     otp_reg.h
 * @brief    OTP register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __OTP_REG_H__
#define __OTP_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/

/** @addtogroup REGISTER Control Register

  @{

*/


/*---------------------- One-Time Programming Controller -------------------------*/
/**
    @addtogroup OTP One-Time Programming Controller(OTP)
    Memory Mapped Structure for OTP Controller
@{ */

typedef struct
{


/**
 * @var OTP_T::CTL
 * Offset: 0x00  OTP Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |START     |OTP Start Control Bit
 * |        |          |0 = No operation.
 * |        |          |1 = Start the operation.
 * |[7:4]   |CMD       |OTP Command Selection Bits
 * |        |          |0x0 = Read command.
 * |        |          |0x1 = Program command.
 * |        |          |0x2 = Read only lock command.
 * |        |          |0x3 = Fault Tolerance Mechanism command.
 * |        |          |0x6 = Read checker0 command.
 * |        |          |0x7 = Read checker1 command.
 * |        |          |0xB = Read company ID.
 * |        |          |0xC = Read device ID.
 * |        |          |0xD = Read unique ID.
 * |        |          |Others = reserved.
 * @var OTP_T::STS
 * Offset: 0x04  OTP Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |BUSY      |OTP Busy Flag
 * |        |          |0 = OTP is idle or finished.
 * |        |          |1 = OTP is busy.
 * |[2]     |ADDRFF    |OTP Address Fail Flag
 * |        |          |0 = OTP Address is legal.
 * |        |          |1 = OTP Address is illegal or use non-Read_checker command to access the checker region(block5, block19).
 * |[3]     |FTMFF     |OTP Fault Tolerance Mechanism Fail Flag
 * |        |          |This bit is set after Fault Tolerance Mechanism command is triggered and address is assigned to a block without available spare memory.
 * |        |          |0 = No OTP fault tolerance mechanism failed.
 * |        |          |1 = OTP fault tolerance mechanism failed.
 * |[4]     |CMDFF     |OTP Command Fail Flag
 * |        |          |This bit is set after program command or Fault Tolerance Mechanism command is triggered and address is assigned a locked block.
 * |        |          |0 = No OTP command failed.
 * |        |          |1 = OTP command is failed.
 * |[7]     |TFF       |OTP Test Mode Fail Flag
 * |        |          |0 = No EFUSE test mode failed.
 * |        |          |1 = EFUSE test mode is failed.
 * |[15]    |LOCK      |OTP Lock Flag
 * |        |          |0 = OTP is unlocked.
 * |        |          |1 = OTP is locked and program will failed.
 * @var OTP_T::ADDR
 * Offset: 0x08  OTP Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[11:0]  |ADDR      |OTP Address
 * |        |          |OTP_ADDR register is byte addressable.
 * |        |          |If OTP_ADDR is written to illegal region and START(OTP_CTL[0]) bit is triggered, ADDRFF(OTP_STS[2]) will be set and this operation will not be executed.
 * @var OTP_T::DATA
 * Offset: 0x0C  OTP Data Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DATA      |OTP Data
 * |        |          |Writing data to OTP_DATA register before OTP program operation.
 * |        |          |Reading data from OTP_DATA register after OTP read operation.
 * |        |          |Writing password, 0x55aa_92d6, before OTP read only lock operation or OTP Fault Tolerance Mechanism operation.
 * @var OTP_T::USMSTS0
 * Offset: 0x10  OTP Unused Spare Memory 0 Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[1:0]   |BLK0      |Block 0 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 2.
 * |[3:2]   |BLK1      |Block 1 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 2.
 * |[5:4]   |BLK2      |Block 2 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 0.
 * |[7:6]   |BLK3      |Block 3 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 2.
 * |[9:8]   |BLK4      |Block 4 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 2.
 * |[11:10] |BLK5      |Block 5 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 0.
 * |[13:12] |BLK6      |Block 6 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 1.
 * |[15:14] |BLK7      |Block 7 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 1.
 * |[17:16] |BLK8      |Block 8 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 1.
 * |[19:18] |BLK9      |Block 9 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 1.
 * |[21:20] |BLK10     |Block 10 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 1.
 * |[23:22] |BLK11     |Block 11 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 1.
 * |[25:24] |BLK12     |Block 12 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 1.
 * |[27:26] |BLK13     |Block 13 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 1.
 * |[29:28] |BLK14     |Block 14 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 1.
 * |[31:30] |BLK15     |Block 15 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 0.
 * @var OTP_T::USMSTS1
 * Offset: 0x14  OTP Unused Spare Memory 1 Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[1:0]   |BLK16     |Block 16 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 1.
 * |[3:2]   |BLK17     |Block 17 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 0.
 * |[5:4]   |BLK18     |Block 18 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 0.
 * |[7:6]   |BLK19     |Block 19 Unused Spare Memory
 * |        |          |Maximum unused spare memory is 0.
 * @var OTP_T::LDO_CTL_EN
 * Offset: 0x18  OTP LDO Control Enable Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |LDP_CTL_EN|LDO Control Enable bit
 * |        |          |0 = Disable LDO controlled by OTP_LDO_CTL_TEST.
 * |        |          |1 = Enable LDO controlled by OTP_LDO_CTL_TEST.
 * |        |          |(This bit is valid in vendor stage and RMA stage
 * |        |          |For testing purposes, this bit can be used to directly control the LDO and measure the voltage.).
 * |        |          |(Before general command operations on OTP, you must set LDO_CTL_EN to 0.)
 * @var OTP_T::LDO_CTL_TEST
 * Offset: 0x1C  OTP LDO Control Testing Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |PD        |PD
 * |        |          |LDO power down control signal. Default value is u201C0u201D.
 * |        |          |0 = Enable LDO, VOUT=2.5V(Typ.).
 * |        |          |1 = Disable LDO, VOUT pull down.
 * |        |          |pull-down resistor is 500u03A9
 * |        |          |(This bit is valid when LDO_CTL_EN(OTP_LDO_CTL_EN[0]) is set 1.)
 * |[3:2]   |TMUX      |TMUX
 * |        |          |Select DC_TP(LDO output to pad for testing) output to test this LDO.
 * |        |          |00 = High Z;.
 * |        |          |01 = VOUT, through internal buffer;.
 * |        |          |10 = internal signal: VREF, through internal buffer;.
 * |        |          |11 = Reserve.
 * |        |          |Default value is u201C00u201D
 * |        |          |(These bits are valid when LDO_CTL_EN(OTP_LDO_CTL_EN[0]) is set 1.)
 * |[7:4]   |TUNE      |TUNE
 * |        |          |LDO output voltage tuning bits. Default value is u201C0000u201D.
 * |        |          |(These bits are valid when LDO_CTL_EN(OTP_LDO_CTL_EN[0]) is set 1.)
 * @var OTP_T::VERSION
 * Offset: 0xFFC  OTP RTL Design Version Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[15:0]  |MINOR     |RTL Design Minor Version Number
 * |        |          |Minor version number is dependent on moduleu2019s ECO version control.
 * |        |          |0x0000 (Current Minor Version Number)
 * |[23:16] |SUB       |RTL Design Sub Version Number
 * |        |          |Sub version number is correlated to moduleu2019s key feature.
 * |        |          |0x01 (Current Sub Version Number)
 * |[31:24] |MAJOR     |RTL Design Major Version Number
 * |        |          |Major version number is correlated to Product Line.
 * |        |          |0x01 (Current Major Version Number)
 */
    __IO uint8_t CTL;                    /*!< [0x0000] OTP Control Register                                             */
    __I  uint8_t RESERVE0[3];
    __I  uint8_t STS;                    /*!< [0x0004] OTP Status Register                                              */
    __I  uint8_t RESERVE1[3];
    __IO uint8_t ADDR;                   /*!< [0x0008] OTP Address Register                                             */
    __I  uint8_t RESERVE2[3];
    __IO uint8_t DATA;                   /*!< [0x000c] OTP Data Register                                                */
    __I  uint8_t RESERVE3[3];
    __I  uint8_t USMSTS0;                /*!< [0x0010] OTP Unused Spare Memory 0 Status Register                        */
    __I  uint8_t RESERVE4[3];
    __I  uint8_t USMSTS1;                /*!< [0x0014] OTP Unused Spare Memory 1 Status Register                        */
    __I  uint8_t RESERVE5[3];
    __IO uint8_t LDO_CTL_EN;             /*!< [0x0018] OTP LDO Control Enable Register                                  */
    __I  uint8_t RESERVE6[3];
    __IO uint8_t LDO_CTL_TEST;           /*!< [0x001c] OTP LDO Control Testing Register                                 */
    __I  uint8_t RESERVE7[4063];
    __I  uint8_t VERSION;                /*!< [0x0ffc] OTP RTL Design Version Register                                  */

} OTP_T;

/**
    @addtogroup OTP_CONST OTP Bit Field Definition
    Constant Definitions for OTP Controller
@{ */

#define OTP_CTL_START_Pos                (0)                                               /*!< OTP_T::CTL: START Position             */
#define OTP_CTL_START_Msk                (0x1ul << OTP_CTL_START_Pos)                      /*!< OTP_T::CTL: START Mask                 */

#define OTP_CTL_CMD_Pos                  (4)                                               /*!< OTP_T::CTL: CMD Position               */
#define OTP_CTL_CMD_Msk                  (0xful << OTP_CTL_CMD_Pos)                        /*!< OTP_T::CTL: CMD Mask                   */

#define OTP_STS_BUSY_Pos                 (0)                                               /*!< OTP_T::STS: BUSY Position              */
#define OTP_STS_BUSY_Msk                 (0x1ul << OTP_STS_BUSY_Pos)                       /*!< OTP_T::STS: BUSY Mask                  */

#define OTP_STS_ADDRFF_Pos               (2)                                               /*!< OTP_T::STS: ADDRFF Position            */
#define OTP_STS_ADDRFF_Msk               (0x1ul << OTP_STS_ADDRFF_Pos)                     /*!< OTP_T::STS: ADDRFF Mask                */

#define OTP_STS_FTMFF_Pos                (3)                                               /*!< OTP_T::STS: FTMFF Position             */
#define OTP_STS_FTMFF_Msk                (0x1ul << OTP_STS_FTMFF_Pos)                      /*!< OTP_T::STS: FTMFF Mask                 */

#define OTP_STS_CMDFF_Pos                (4)                                               /*!< OTP_T::STS: CMDFF Position             */
#define OTP_STS_CMDFF_Msk                (0x1ul << OTP_STS_CMDFF_Pos)                      /*!< OTP_T::STS: CMDFF Mask                 */

#define OTP_STS_TFF_Pos                  (7)                                               /*!< OTP_T::STS: TFF Position               */
#define OTP_STS_TFF_Msk                  (0x1ul << OTP_STS_TFF_Pos)                        /*!< OTP_T::STS: TFF Mask                   */

#define OTP_STS_LOCK_Pos                 (15)                                              /*!< OTP_T::STS: LOCK Position              */
#define OTP_STS_LOCK_Msk                 (0x1ul << OTP_STS_LOCK_Pos)                       /*!< OTP_T::STS: LOCK Mask                  */

#define OTP_ADDR_ADDR_Pos                (0)                                               /*!< OTP_T::ADDR: ADDR Position             */
#define OTP_ADDR_ADDR_Msk                (0xffful << OTP_ADDR_ADDR_Pos)                    /*!< OTP_T::ADDR: ADDR Mask                 */

#define OTP_DATA_DATA_Pos                (0)                                               /*!< OTP_T::DATA: DATA Position             */
#define OTP_DATA_DATA_Msk                (0xfffffffful << OTP_DATA_DATA_Pos)               /*!< OTP_T::DATA: DATA Mask                 */

#define OTP_USMSTS0_BLK0_Pos             (0)                                               /*!< OTP_T::USMSTS0: BLK0 Position          */
#define OTP_USMSTS0_BLK0_Msk             (0x3ul << OTP_USMSTS0_BLK0_Pos)                   /*!< OTP_T::USMSTS0: BLK0 Mask              */

#define OTP_USMSTS0_BLK1_Pos             (2)                                               /*!< OTP_T::USMSTS0: BLK1 Position          */
#define OTP_USMSTS0_BLK1_Msk             (0x3ul << OTP_USMSTS0_BLK1_Pos)                   /*!< OTP_T::USMSTS0: BLK1 Mask              */

#define OTP_USMSTS0_BLK2_Pos             (4)                                               /*!< OTP_T::USMSTS0: BLK2 Position          */
#define OTP_USMSTS0_BLK2_Msk             (0x3ul << OTP_USMSTS0_BLK2_Pos)                   /*!< OTP_T::USMSTS0: BLK2 Mask              */

#define OTP_USMSTS0_BLK3_Pos             (6)                                               /*!< OTP_T::USMSTS0: BLK3 Position          */
#define OTP_USMSTS0_BLK3_Msk             (0x3ul << OTP_USMSTS0_BLK3_Pos)                   /*!< OTP_T::USMSTS0: BLK3 Mask              */

#define OTP_USMSTS0_BLK4_Pos             (8)                                               /*!< OTP_T::USMSTS0: BLK4 Position          */
#define OTP_USMSTS0_BLK4_Msk             (0x3ul << OTP_USMSTS0_BLK4_Pos)                   /*!< OTP_T::USMSTS0: BLK4 Mask              */

#define OTP_USMSTS0_BLK5_Pos             (10)                                              /*!< OTP_T::USMSTS0: BLK5 Position          */
#define OTP_USMSTS0_BLK5_Msk             (0x3ul << OTP_USMSTS0_BLK5_Pos)                   /*!< OTP_T::USMSTS0: BLK5 Mask              */

#define OTP_USMSTS0_BLK6_Pos             (12)                                              /*!< OTP_T::USMSTS0: BLK6 Position          */
#define OTP_USMSTS0_BLK6_Msk             (0x3ul << OTP_USMSTS0_BLK6_Pos)                   /*!< OTP_T::USMSTS0: BLK6 Mask              */

#define OTP_USMSTS0_BLK7_Pos             (14)                                              /*!< OTP_T::USMSTS0: BLK7 Position          */
#define OTP_USMSTS0_BLK7_Msk             (0x3ul << OTP_USMSTS0_BLK7_Pos)                   /*!< OTP_T::USMSTS0: BLK7 Mask              */

#define OTP_USMSTS0_BLK8_Pos             (16)                                              /*!< OTP_T::USMSTS0: BLK8 Position          */
#define OTP_USMSTS0_BLK8_Msk             (0x3ul << OTP_USMSTS0_BLK8_Pos)                   /*!< OTP_T::USMSTS0: BLK8 Mask              */

#define OTP_USMSTS0_BLK9_Pos             (18)                                              /*!< OTP_T::USMSTS0: BLK9 Position          */
#define OTP_USMSTS0_BLK9_Msk             (0x3ul << OTP_USMSTS0_BLK9_Pos)                   /*!< OTP_T::USMSTS0: BLK9 Mask              */

#define OTP_USMSTS0_BLK10_Pos            (20)                                              /*!< OTP_T::USMSTS0: BLK10 Position         */
#define OTP_USMSTS0_BLK10_Msk            (0x3ul << OTP_USMSTS0_BLK10_Pos)                  /*!< OTP_T::USMSTS0: BLK10 Mask             */

#define OTP_USMSTS0_BLK11_Pos            (22)                                              /*!< OTP_T::USMSTS0: BLK11 Position         */
#define OTP_USMSTS0_BLK11_Msk            (0x3ul << OTP_USMSTS0_BLK11_Pos)                  /*!< OTP_T::USMSTS0: BLK11 Mask             */

#define OTP_USMSTS0_BLK12_Pos            (24)                                              /*!< OTP_T::USMSTS0: BLK12 Position         */
#define OTP_USMSTS0_BLK12_Msk            (0x3ul << OTP_USMSTS0_BLK12_Pos)                  /*!< OTP_T::USMSTS0: BLK12 Mask             */

#define OTP_USMSTS0_BLK13_Pos            (26)                                              /*!< OTP_T::USMSTS0: BLK13 Position         */
#define OTP_USMSTS0_BLK13_Msk            (0x3ul << OTP_USMSTS0_BLK13_Pos)                  /*!< OTP_T::USMSTS0: BLK13 Mask             */

#define OTP_USMSTS0_BLK14_Pos            (28)                                              /*!< OTP_T::USMSTS0: BLK14 Position         */
#define OTP_USMSTS0_BLK14_Msk            (0x3ul << OTP_USMSTS0_BLK14_Pos)                  /*!< OTP_T::USMSTS0: BLK14 Mask             */

#define OTP_USMSTS0_BLK15_Pos            (30)                                              /*!< OTP_T::USMSTS0: BLK15 Position         */
#define OTP_USMSTS0_BLK15_Msk            (0x3ul << OTP_USMSTS0_BLK15_Pos)                  /*!< OTP_T::USMSTS0: BLK15 Mask             */

#define OTP_USMSTS1_BLK16_Pos            (0)                                               /*!< OTP_T::USMSTS1: BLK16 Position         */
#define OTP_USMSTS1_BLK16_Msk            (0x3ul << OTP_USMSTS1_BLK16_Pos)                  /*!< OTP_T::USMSTS1: BLK16 Mask             */

#define OTP_USMSTS1_BLK17_Pos            (2)                                               /*!< OTP_T::USMSTS1: BLK17 Position         */
#define OTP_USMSTS1_BLK17_Msk            (0x3ul << OTP_USMSTS1_BLK17_Pos)                  /*!< OTP_T::USMSTS1: BLK17 Mask             */

#define OTP_USMSTS1_BLK18_Pos            (4)                                               /*!< OTP_T::USMSTS1: BLK18 Position         */
#define OTP_USMSTS1_BLK18_Msk            (0x3ul << OTP_USMSTS1_BLK18_Pos)                  /*!< OTP_T::USMSTS1: BLK18 Mask             */

#define OTP_USMSTS1_BLK19_Pos            (6)                                               /*!< OTP_T::USMSTS1: BLK19 Position         */
#define OTP_USMSTS1_BLK19_Msk            (0x3ul << OTP_USMSTS1_BLK19_Pos)                  /*!< OTP_T::USMSTS1: BLK19 Mask             */

#define OTP_LDO_CTL_EN_LDP_CTL_EN_Pos    (0)                                               /*!< OTP_T::LDO_CTL_EN: LDP_CTL_EN Position */
#define OTP_LDO_CTL_EN_LDP_CTL_EN_Msk    (0x1ul << OTP_LDO_CTL_EN_LDP_CTL_EN_Pos)          /*!< OTP_T::LDO_CTL_EN: LDP_CTL_EN Mask     */

#define OTP_LDO_CTL_TEST_PD_Pos          (0)                                               /*!< OTP_T::LDO_CTL_TEST: PD Position       */
#define OTP_LDO_CTL_TEST_PD_Msk          (0x1ul << OTP_LDO_CTL_TEST_PD_Pos)                /*!< OTP_T::LDO_CTL_TEST: PD Mask           */

#define OTP_LDO_CTL_TEST_TMUX_Pos        (2)                                               /*!< OTP_T::LDO_CTL_TEST: TMUX Position     */
#define OTP_LDO_CTL_TEST_TMUX_Msk        (0x3ul << OTP_LDO_CTL_TEST_TMUX_Pos)              /*!< OTP_T::LDO_CTL_TEST: TMUX Mask         */

#define OTP_LDO_CTL_TEST_TUNE_Pos        (4)                                               /*!< OTP_T::LDO_CTL_TEST: TUNE Position     */
#define OTP_LDO_CTL_TEST_TUNE_Msk        (0xful << OTP_LDO_CTL_TEST_TUNE_Pos)              /*!< OTP_T::LDO_CTL_TEST: TUNE Mask         */

#define OTP_VERSION_MINOR_Pos            (0)                                               /*!< OTP_T::VERSION: MINOR Position         */
#define OTP_VERSION_MINOR_Msk            (0xfffful << OTP_VERSION_MINOR_Pos)               /*!< OTP_T::VERSION: MINOR Mask             */

#define OTP_VERSION_SUB_Pos              (16)                                              /*!< OTP_T::VERSION: SUB Position           */
#define OTP_VERSION_SUB_Msk              (0xfful << OTP_VERSION_SUB_Pos)                   /*!< OTP_T::VERSION: SUB Mask               */

#define OTP_VERSION_MAJOR_Pos            (24)                                              /*!< OTP_T::VERSION: MAJOR Position         */
#define OTP_VERSION_MAJOR_Msk            (0xfful << OTP_VERSION_MAJOR_Pos)                 /*!< OTP_T::VERSION: MAJOR Mask             */

/**@}*/ /* OTP_CONST */
/**@}*/ /* end of OTP register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __OTP_REG_H__ */
