/**************************************************************************//**
 * @file     aic_reg.h
 * @version  V1.00
 * @brief    AIC register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __AIC_REG_H__
#define __AIC_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/** @addtogroup REGISTER Control Register

  @{

*/


/*---------------------- Advanced Interrupt Controller -------------------------*/
/**
    @addtogroup AIC Advanced Interrupt Controller(AIC)
    Memory Mapped Structure for AIC Controller
@{ */

typedef struct
{


/**
 * @var AIC_T::SRC00-SRC20
 * Offset: 0x00-0x50  AIC Source Configuration Register 0-20
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[2:0]   |PL0       |Priority Level
 * |        |          |000 = Priority Level 0 (the highest priority).
 * |        |          |001 = Priority Level 1.
 * |        |          |010 = Priority Level 2.
 * |        |          |011 = Priority Level 3.
 * |        |          |100 = Priority Level 4.
 * |        |          |101 = Priority Level 5.
 * |        |          |110 = Priority Level 6.
 * |        |          |111 = Priority Level 7 (the lowest priority, Default).
 * |        |          |For the register AIC_SRCm, PLn is applied to the interrupt source (m x 4 + n).
 * |        |          |An interrupt request with priority level 0 will activate a FIQ interrupt
 * |        |          |An interrupt request with other priority levels will activate an IRQ interrupt.
 * |[7:6]   |T0        |Trigger Type
 * |        |          |00 = low-level trigger.
 * |        |          |01 = high-level trigger. (Default)
 * |        |          |10 = falling-edge trigger.
 * |        |          |11 = rising-edge trigger.
 * |        |          |For the register AIC_SRCm, TTn is applied to the interrupt source (m x 4 + n).
 * |[10:8]  |PL1       |Priority Level
 * |        |          |000 = Priority Level 0 (the highest priority).
 * |        |          |001 = Priority Level 1.
 * |        |          |010 = Priority Level 2.
 * |        |          |011 = Priority Level 3.
 * |        |          |100 = Priority Level 4.
 * |        |          |101 = Priority Level 5.
 * |        |          |110 = Priority Level 6.
 * |        |          |111 = Priority Level 7 (the lowest priority, Default).
 * |        |          |For the register AIC_SRCm, PLn is applied to the interrupt source (m x 4 + n).
 * |        |          |An interrupt request with priority level 0 will activate a FIQ interrupt
 * |        |          |An interrupt request with other priority levels will activate an IRQ interrupt.
 * |[15:14] |T1        |Trigger Type
 * |        |          |00 = low-level trigger.
 * |        |          |01 = high-level trigger. (Default)
 * |        |          |10 = falling-edge trigger.
 * |        |          |11 = rising-edge trigger.
 * |        |          |For the register AIC_SRCm, TTn is applied to the interrupt source (m x 4 + n).
 * |[18:16] |PL2       |Priority Level
 * |        |          |000 = Priority Level 0 (the highest priority).
 * |        |          |001 = Priority Level 1.
 * |        |          |010 = Priority Level 2.
 * |        |          |011 = Priority Level 3.
 * |        |          |100 = Priority Level 4.
 * |        |          |101 = Priority Level 5.
 * |        |          |110 = Priority Level 6.
 * |        |          |111 = Priority Level 7 (the lowest priority, Default).
 * |        |          |For the register AIC_SRCm, PLn is applied to the interrupt source (m x 4 + n).
 * |        |          |An interrupt request with priority level 0 will activate a FIQ interrupt
 * |        |          |An interrupt request with other priority levels will activate an IRQ interrupt.
 * |[23:22] |T2        |Trigger Type
 * |        |          |00 = low-level trigger.
 * |        |          |01 = high-level trigger. (Default)
 * |        |          |10 = falling-edge trigger.
 * |        |          |11 = rising-edge trigger.
 * |        |          |For the register AIC_SRCm, TTn is applied to the interrupt source (m x 4 + n).
 * |[26:24] |PL3       |Priority Level
 * |        |          |000 = Priority Level 0 (the highest priority).
 * |        |          |001 = Priority Level 1.
 * |        |          |010 = Priority Level 2.
 * |        |          |011 = Priority Level 3.
 * |        |          |100 = Priority Level 4.
 * |        |          |101 = Priority Level 5.
 * |        |          |110 = Priority Level 6.
 * |        |          |111 = Priority Level 7 (the lowest priority, Default).
 * |        |          |For the register AIC_SRCm, PLn is applied to the interrupt source (m x 4 + n).
 * |        |          |An interrupt request with priority level 0 will activate a FIQ interrupt
 * |        |          |An interrupt request with other priority levels will activate an IRQ interrupt.
 * |[31:30] |T3        |Trigger Type
 * |        |          |00 = low-level trigger.
 * |        |          |01 = high-level trigger. (Default)
 * |        |          |10 = falling-edge trigger.
 * |        |          |11 = rising-edge trigger.
 * |        |          |For the register AIC_SRCm, TTn is applied to the interrupt source (m x 4 + n).
 * @var AIC_T::RAW0
 * Offset: 0x100  AIC Source Raw Value Register 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |RVx       |Interrupt Source Raw Value
 * |        |          |Each bit indicates the raw logic value of interrupt source x. (x = 0-31)
 * |        |          |0 = Logic value of interrupt source x is 0.
 * |        |          |1 = Logic value of interrupt source x is 1.
 * @var AIC_T::RAW1
 * Offset: 0x104  AIC Source Raw Value Register 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |RVx       |Interrupt Source Raw Value
 * |        |          |Each bit indicates the raw logic value of interrupt source x. (x = 32-63)
 * |        |          |0 = Logic value of interrupt source x is 0.
 * |        |          |1 = Logic value of interrupt source x is 1.
 * @var AIC_T::RAW2
 * Offset: 0x108  AIC Source Raw Value Register 2
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[17:0]  |RVx       |Interrupt Source Raw Value
 * |        |          |Each bit indicates the raw logic value of interrupt source x. (x = 64-81)
 * |        |          |0 = Logic value of interrupt source x is 0.
 * |        |          |1 = Logic value of interrupt source x is 1.
 * @var AIC_T::IS0
 * Offset: 0x110  AIC Interrupt Status Register 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |ISx       |Interrupt Status
 * |        |          |Each bit indicates the inactive/active status of an interrupt source. (x = 0-31)
 * |        |          |0 = Interrupt source x is inactive.
 * |        |          |1 = Interrupt source x is active.
 * |        |          |An interrupt source is active if it is enabled and generates an interrupt request to AIC.
 * |        |          |An interrupt source is inactive if it is disabled, or it is enabled but does not generate an interrupt request to AIC.
 * @var AIC_T::IS1
 * Offset: 0x114  AIC Interrupt Status Register 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |ISx       |Interrupt Status
 * |        |          |Each bit indicates the inactive/active status of an interrupt source x. (x = 32-63)
 * |        |          |0 = Interrupt source x is inactive.
 * |        |          |1 = Interrupt source x is active.
 * |        |          |An interrupt source is active if it is enabled and generates an interrupt request to AIC.
 * |        |          |An interrupt source is inactive if it is disabled, or it is enabled but does not generate an interrupt request to AIC.
 * @var AIC_T::IS2
 * Offset: 0x118  AIC Interrupt Status Register 2
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[17:0]  |ISx       |Interrupt Status
 * |        |          |Each bit indicates the inactive/active status of an interrupt source x. (x = 64-81)
 * |        |          |0 = Interrupt source x is inactive.
 * |        |          |1 = Interrupt source x is active.
 * |        |          |An interrupt source is active if it is enabled and generates an interrupt request to AIC.
 * |        |          |An interrupt source is inactive if it is disabled, or it is enabled but does not generate an interrupt request to AIC.
 * @var AIC_T::IRQ
 * Offset: 0x120  AIC IRQ Source Number Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[6:0]   |NUM       |Interrup Source Number
 * |        |          |The number indicates an interrupt source that activates an IRQ interrupt currently.
 * @var AIC_T::FIQ
 * Offset: 0x124  AIC FIQ Source Number Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[6:0]   |NUM       |Interrupt Source Number
 * |        |          |The number indicates an interrupt source that activates an FIQ interrupt currently.
 * @var AIC_T::IE0
 * Offset: 0x130  AIC Interrupt Enable Register 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |IEx       |Interrupt Enable Status
 * |        |          |Each bit indicates the disabled/enabled status of an interrupt source. (x = 0-31)
 * |        |          |0 = Interrupt source x Disabled.
 * |        |          |1 = Interrupt source x Enabled.
 * |        |          |Note: The interrupt request from a disabled interrupt source is always ignored by AIC.
 * @var AIC_T::IE1
 * Offset: 0x134  AIC Interrupt Enable Register 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |IEx       |Interrupt Enable Status
 * |        |          |Each bit indicates the disabled/enabled status of an interrupt source. (x = 32-63)
 * |        |          |0 = Interrupt source x Disabled.
 * |        |          |1 = Interrupt source x Enabled.
 * |        |          |Note: The interrupt request from a disabled interrupt source is always ignored by AIC.
 * @var AIC_T::IE2
 * Offset: 0x138  AIC Interrupt Enable Register 2
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[17:0]  |IEx       |Interrupt Enable Status
 * |        |          |Each bit indicates the disabled/enabled status of an interrupt source. (x = 64-81)
 * |        |          |0 = Interrupt source x Disabled.
 * |        |          |1 = Interrupt source x Enabled.
 * |        |          |Note: The interrupt request from a disabled interrupt source is always ignored by AIC.
 * @var AIC_T::IEN0
 * Offset: 0x140  AIC Interrupt Enabling-only Register 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |IENx      |Interrupt Enabling
 * |        |          |Writing 1 to a bit enables the corresponding interrupt source. (x = 0-31)
 * |        |          |0 = No effect.
 * |        |          |1 = Enable interrupt source x.
 * |        |          |Note: Writing 0 to a given bit of AIC_IEN0 cannot change the current disabled/enabled status of the corresponding interrupt source
 * |        |          |Users should write 0 to the the same bit of AIC_IE0, or write 1 to the same bit of AIC_IDIS0, to disable the interrupt source.
 * @var AIC_T::IEN1
 * Offset: 0x144  AIC Interrupt Enabling-only Register 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |IENx      |Interrupt Enabling
 * |        |          |Writing 1 to a bit enables the corresponding interrupt source. (x = 32-63)
 * |        |          |0 = No effect.
 * |        |          |1 = Enable interrupt source x.
 * |        |          |Note: Writing 0 to a given bit of AIC_IEN1 cannot change the current disabled/enabled status of the corresponding interrupt source
 * |        |          |Users should write 0 to the the same bit of AIC_IE1, or write 1 to the same bit of AIC_IDIS1, to disable the interrupt source.
 * @var AIC_T::IEN2
 * Offset: 0x148  AIC Interrupt Enabling-only Register 2
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[17:0]  |IENx      |Interrupt Enabling
 * |        |          |Writing 1 to a bit enables the corresponding interrupt source. (x = 64-81)
 * |        |          |0 = No effect.
 * |        |          |1 = Enable interrupt source x.
 * |        |          |Note: Writing 0 to a given bit of AIC_IEN2 cannot change the current disabled/enabled status of the corresponding interrupt source
 * |        |          |Users should write 0 to the the same bit of AIC_IE2, or write 1 to the same bit of AIC_IDIS2, to disable the interrupt source.
 * @var AIC_T::IDIS0
 * Offset: 0x150  AIC Interrupt Disabling-only Register 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |IDISx     |Interrupt Disabling
 * |        |          |Writing 1 to a bit disables the corresponding interrupt source. (x = 0-31)
 * |        |          |0 = No effect.
 * |        |          |1 = Disable interrupt source x.
 * @var AIC_T::IDIS1
 * Offset: 0x154  AIC Interrupt Disabling-only Register 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |IDISx     |Interrupt Disabling
 * |        |          |Writing 1 to a bit disables the corresponding interrupt source. (x = 32-63)
 * |        |          |0 = No effect.
 * |        |          |1 = Disable interrupt source x.
 * @var AIC_T::IDIS2
 * Offset: 0x158  AIC Interrupt Disabling-only Register 2
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[17:0]  |IDISx     |Interrupt Disabling
 * |        |          |Writing 1 to a bit disables the corresponding interrupt source. (x = 64-81)
 * |        |          |0 = No effect.
 * |        |          |1 = Disable interrupt source x.
 * @var AIC_T::IRQRST
 * Offset: 0x170  AIC IRQ Reset Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |Null      |Writing any value to this register will reset and restart AICu2019s IRQ processing.
 * @var AIC_T::FIQRST
 * Offset: 0x174  AIC FIQ Reset Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |Null      |Writing any value to this register will reset and restart AICu2019s FIQ processing.
 */
	__IO uint32_t SRC[21];               /*!< [0x0000-0x0050] AIC Source Configuration Register 0-20                    */
    __I  uint32_t RESERVE0[43];
    __I  uint32_t RAW[3];                /*!< [0x0100-0x0108] AIC Source Raw Value Register 0-2                         */
    __I  uint32_t RESERVE1[1];
    __I  uint32_t IS[3];                 /*!< [0x0110-0x0118] AIC Interrupt Status Register 0-2                         */
    __I  uint32_t RESERVE2[1];
    __I  uint32_t IRQ;                   /*!< [0x0120] AIC IRQ Source Number Register                                   */
    __I  uint32_t FIQ;                   /*!< [0x0124] AIC FIQ Source Number Register                                   */
    __I  uint32_t RESERVE3[2];
    __IO uint32_t IE[3];                 /*!< [0x0130-0x0138] AIC Interrupt Enable Register 0-2                         */
    __I  uint32_t RESERVE4[1];
    __O  uint32_t IEN[3];                /*!< [0x0140-0x0148] AIC Interrupt Enabling-only Register 0-2                  */
    __I  uint32_t RESERVE5[1];
    __O  uint32_t IDIS[3];               /*!< [0x0150-0x0158] AIC Interrupt Disabling-only Register 0-2                 */
    __I  uint32_t RESERVE6[5];
    __O  uint32_t IRQRST;                /*!< [0x0170] AIC IRQ Reset Register                                           */
    __O  uint32_t FIQRST;                /*!< [0x0174] AIC FIQ Reset Register                                           */
} AIC_T;

/**
    @addtogroup AIC_CONST AIC Bit Field Definition
    Constant Definitions for AIC Controller
@{ */

#define AIC_SRC_PL0_Pos                  (0)                                               /*!< AIC_T::SRCm: PL0 Position              */
#define AIC_SRC_PL0_Msk                  (0x7ul << AIC_SRC_PL0_Pos)                        /*!< AIC_T::SRCm: PL0 Mask                  */

#define AIC_SRC_TT0_Pos                  (6)                                               /*!< AIC_T::SRCm: TT0 Position              */
#define AIC_SRC_TT0_Msk                  (0x3ul << AIC_SRC_TT0_Pos)                        /*!< AIC_T::SRCm: TT0 Mask                  */

#define AIC_SRC_PL1_Pos                  (8)                                               /*!< AIC_T::SRCm: PL1 Position              */
#define AIC_SRC_PL1_Msk                  (0x7ul << AIC_SRC_PL1_Pos)                        /*!< AIC_T::SRCm: PL1 Mask                  */

#define AIC_SRC_TT1_Pos                  (14)                                              /*!< AIC_T::SRCm: TT1 Position              */
#define AIC_SRC_TT1_Msk                  (0x3ul << AIC_SRC_TT1_Pos)                        /*!< AIC_T::SRCm: TT1 Mask                  */

#define AIC_SRC_PL2_Pos                  (16)                                              /*!< AIC_T::SRCm: PL2 Position              */
#define AIC_SRC_PL2_Msk                  (0x7ul << AIC_SRC_PL2_Pos)                        /*!< AIC_T::SRCm: PL2 Mask                  */

#define AIC_SRC_TT2_Pos                  (22)                                              /*!< AIC_T::SRCm: TT2 Position              */
#define AIC_SRC_TT2_Msk                  (0x3ul << AIC_SRC_TT2_Pos)                        /*!< AIC_T::SRCm: TT2 Mask                  */

#define AIC_SRC_PL3_Pos                  (24)                                              /*!< AIC_T::SRCm: PL3 Position              */
#define AIC_SRC_PL3_Msk                  (0x7ul << AIC_SRC_PL3_Pos)                        /*!< AIC_T::SRCm: PL3 Mask                  */

#define AIC_SRC_TT3_Pos                  (30)                                              /*!< AIC_T::SRCm: TT3 Position              */
#define AIC_SRC_TT3_Msk                  (0x3ul << AIC_SRC_TT3_Pos)                        /*!< AIC_T::SRCm: TT3 Mask                  */

#define AIC_RAW_RV_Msk(x)                (0x1ul << x)                                      /*!< AIC_T::RAW: RVx Mask                   */

#define AIC_IS_IS_Msk(x)                 (0x1ul << x)                                      /*!< AIC_T::IS: ISx Mask                    */

#define AIC_IRQ_NUM_Pos                  (0)                                               /*!< AIC_T::IRQ: NUM Position               */
#define AIC_IRQ_NUM_Msk                  (0x7ful << AIC_IRQ_NUM_Pos)                       /*!< AIC_T::IRQ: NUM Mask                   */

#define AIC_FIQ_NUM_Pos                  (0)                                               /*!< AIC_T::FIQ: NUM Position               */
#define AIC_FIQ_NUM_Msk                  (0x7ful << AIC_FIQ_NUM_Pos)                       /*!< AIC_T::FIQ: NUM Mask                   */

#define AIC_IE_IE_Msk(x)                 (0x1ul << x)                                      /*!< AIC_T::IE: IEx Mask                    */

#define AIC_IEN_IEN_Msk(x)               (0x1ul << x)                                      /*!< AIC_T::IEN: IENx Mask                  */

#define AIC_IDIS_IDIS_Msk(x)             (0x1ul << x)                                      /*!< AIC_T::IDIS: IDISx Mask                */

#define AIC_IRQRST_Null_Pos              (0)                                               /*!< AIC_T::IRQRST: Null Position           */
#define AIC_IRQRST_Null_Msk              (0xfffffffful << AIC_IRQRST_Null_Pos)             /*!< AIC_T::IRQRST: Null Mask               */

#define AIC_FIQRST_Null_Pos              (0)                                               /*!< AIC_T::FIQRST: Null Position           */
#define AIC_FIQRST_Null_Msk              (0xfffffffful << AIC_FIQRST_Null_Pos)             /*!< AIC_T::FIQRST: Null Mask               */

/**@}*/ /* AIC_CONST */
/**@}*/ /* end of AIC register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __AIC_REG_H__ */