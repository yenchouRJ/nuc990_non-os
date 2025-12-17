/**************************************************************************//**
 * @file     adc_reg.h
 * @version  V1.00
 * @brief    NUC990 ADC driver header file
 *
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __ADC_REG_H__
#define __ADC_REG_H__

#ifdef __cplusplus
extern "C"
{
#endif

/** @addtogroup REGISTER Control Register

  @{

*/

/*---------------------- Analog to Digital Converter -------------------------*/
/**
    @addtogroup ADC Analog to Digital Converter(ADC)
    Memory Mapped Structure for ADC Controller
@{ */

typedef struct
{


/**
 * @var ADC_T::CTL
 * Offset: 0x00  ADC Control
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |AD_EN     |ADC Power Control
 * |        |          |0 = Power down ADC.
 * |        |          |1 = Power on ADC.
 * |[8]     |MST       |Menu Start Conversion
 * |        |          |0 = Functional menu not start.
 * |        |          |1 = Start all enable bit in ADC_FM register.
 * |        |          |Note: This bit is set by software and cleared by hardware when all the jobs listed in ADC_CONF are done.
 * |[9]     |PEDE_EN   |Pen Down Event Enable
 * |        |          |0 = Disable pen down event interrupt.
 * |        |          |1 = Enable pen down event interrupt.
 * |[10]    |WKP_EN    |Keypad Press Wake Up Enable
 * |        |          |0 = Disable key press wake up.
 * |        |          |1 = Enable key press wake up.
 * |[11]    |WKT_EN    |Touch Wake Up Enable
 * |        |          |0 = Disable touch wake up.
 * |        |          |1 = Enable touch wake up.
 * |[16]    |WMSWCH    |Wire Mode Switch for 5-wire/4-wire Configuration
 * |        |          |0 = 4-wire mode.
 * |        |          |1 = 5-wire mode.
 * |[20]    |PTEN      |PDMA Transfer Enable Bit
 * |        |          |When A/D conversion is completed, the converted data is loaded into ADC_DATA registers
 * |        |          |Software can enable this bit to generate a PDMA data transfer request.
 * |        |          |0 = PDMA data transfer Disabled.
 * |        |          |1 = PDMA data transfer in ADC_DATA Enabled.
 * |        |          |Note: When PTEN=1, software must set M_IEN(ADC_IEC[0])=0 to disable interrupt.
 * @var ADC_T::CONF
 * Offset: 0x04  ADC Configure
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |T_EN      |Touch Enable
 * |        |          |Touch detection function enable
 * |[1]     |Z_EN      |Press Enable
 * |        |          |Press measure function enable
 * |[2]     |NAC_EN    |Normal A/D Conversion Enable
 * |        |          |ADC normal conversion function enable
 * |        |          |0 = Normal A/D Conversion Disabled.
 * |        |          |1 = Normal A/D Conversion Enable.
 * |[7:6]   |REFSEL    |ADC Reference Select
 * |        |          |ADC reference voltage select when ADC operate in normal conversion.
 * |        |          |00 = AGND33 vs 2.5v buffer output, or VREF input.
 * |        |          |00 = AGND33 vs VREF input.
 * |        |          |01 = YM vs YP.
 * |        |          |10 = XM vs XP.
 * |        |          |11 = AGND33 vs AVDD33.
 * |[15:12] |CHSEL     |Channel Selection
 * |        |          |ADC input channel selection.
 * |        |          |0000 = Channel 0.
 * |        |          |0001 = Channel 1.
 * |        |          |0010 = Channel 2.
 * |        |          |0011 = Channel 3.
 * |        |          |0100 = Channel 4.
 * |        |          |0101 = Channel 5.
 * |        |          |0110 = Channel 6.
 * |        |          |0111 = Channel 7.
 * |        |          |1000 = VREF.
 * |[20]    |TMAVEN    |Display T Mean Average Enable
 * |        |          |Touch Mean average for X and Y function enable.f
 * |[21]    |ZMAVEN    |Display Z Mean Average Enable
 * |        |          |Pressure Mean average for Z1 and Z2 function enable.
 * |[22]    |HSPEED    |High Speed Enable
 * |        |          |Enable ADC to high speed mode.
 * |        |          |0 = High Speed Disabled.
 * |        |          |1 = High Speed Enable.
 * |[31:24] |SAMPCNT   |ADC Sample Counter
 * |        |          |Set the counter value to extend the ADC start signal period to get more sampling time for precise conversion.
 * @var ADC_T::IER
 * Offset: 0x08  ADC Interrupt Enable Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |M_IEN     |Menu Interrupt Enable
 * |        |          |Function menu complete interrupt enable.
 * |        |          |0 = Menu Interrupt Disabled.
 * |        |          |1 = Menu Interrupt Enable.
 * |[2]     |PEDE_IEN  |Pen Down Even Interrupt Enable
 * |        |          |Pen down event detection interrupt enable.
 * |[3]     |WKT_IEN   |Wake Up Touch Interrupt Enable
 * |        |          |Wake up touch detection interrupt enable.
 * |[6]     |PEUE_IEN  |Pen Up Event Interrupt Enable
 * |        |          |Pen up event detection interrupt enable.
 * @var ADC_T::ISR
 * Offset: 0x0C  ADC Interrupt Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |M_F       |Menu Complete Flag
 * |        |          |Function menu complete status indicator.
 * |        |          |Note: set by hardware and write 1 to clear this bit.
 * |[2]     |PEDE_F    |Pen Down Event Flag
 * |        |          |Pen down event status indicator.
 * |        |          |Note: set by hardware and write 1 to clear this bit.
 * |[4]     |PEUE_F    |Pen Up Event Flag
 * |        |          |Pen up event status indicator.
 * |        |          |Note: set by hardware and write 1 to clear this bit.
 * |[8]     |T_F       |Touch Conversion Finish
 * |        |          |Functional menu touch detection conversion finish.
 * |        |          |Note: set by hardware and write 1 to clear this bit. 
 * |[9]     |Z_F       |Press Conversion Finish
 * |        |          |Functional menu press measure conversion finish.
 * |        |          |Note: set by hardware and write 1 to clear this bit.
 * |[10]    |NAC_F     |Normal AD Conversion Finish
 * |        |          |Functional menu normal AD conversion finish.
 * |        |          |Note: set by hardware and write 1 to clear this bit.
 * |[17]    |INT_TC    |Interrupt Signal for Touch Screen Touching Detection
 * |        |          |This signal is directly from analog macro without de-bouncing and can be used to determine the pen down touch event together with PEDE_F (ADC_ISR[2]) flag.
 * @var ADC_T::WKISR
 * Offset: 0x10  ADC Wake Up Interrupt Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[1]     |WPEDE_F   |Wake Up Pen Down Event Flag
 * |        |          |Pen down event wake up status indicator.
 * @var ADC_T::XYDATA
 * Offset: 0x20  ADC Touch X,Y Position Data
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[11:0]  |XDATA     |ADC X Data
 * |        |          |When T_EN (ADC_CONF[0]) in ADC_FM register is set; the touch x-position will be stored in this register.
 * |        |          |Note: If the TMAVEN (ADC_CONF[20]) = 1, both x and y position are the results of the mean average of x and y in ADC_XYSORT0 ~ ADC_XYSORT3.
 * |[27:16] |YDATA     |ADC Y Data
 * |        |          |When T_EN (ADC_CONF[0]) in ADC_FM register is set; the touch y-position will be stored in this register.
 * |        |          |Note: If the TMAVEN (ADC_CONF[20]) = 1, both x and y position are the results of the mean average of x and y in ADC_XYSORT0 ~ ADC_XYSORT3.
 * @var ADC_T::ZDATA
 * Offset: 0x24  ADC Touch Z Pressure Data
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[11:0]  |Z1DATA    |ADC Z1 Data
 * |        |          |When Z_EN (ADC_CONF[1]) in ADC_FM register is set; the touch pressure measure Z1 will be stored in this register.
 * |        |          |Note: If the ZMAVEN (ADC_CONF[21])= 1, both Z1 and Z2 data is the results of the mean average of Z1 and Z2 in ADC_ZSORT0 ~ ADC_ZSORT3.
 * |[26:16] |Z2DATA    |ADC Z2 Data
 * |        |          |When Z_EN (ADC_CONF[1]) in ADC_FM register is set; the touch pressure measure Z2 will be stored in this register.
 * |        |          |Note: If the ZMAVEN (ADC_CONF[21]) = 1, both Z1 and Z2 data is the results of the mean average of Z1 and Z2 in ADC_ZSORT0 ~ ADC_ZSORT3.
 * @var ADC_T::DATA
 * Offset: 0x28  ADC Normal Conversion Data
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[11:0]  |ADC_DATA  |ADC Data
 * |        |          |When NAC_EN (ADC_CONF[2]) in ADC_FM is enable, the AD converting result with corresponding channel is stored in this register.
 * @var ADC_T::XYSORT0
 * Offset: 0x1F4  ADC Touch XY Position Mean Value Sort 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[11:0]  |X_SORT0   |X Position Sort Data 0
 * |        |          |X position mean average sort data 0.
 * |[27:16] |Y_SORT0   |Y Position Sort Data 0
 * |        |          |Y position mean average sort data 0.
 * @var ADC_T::XYSORT1
 * Offset: 0x1F8  ADC Touch XY Position Mean Value Sort 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[11:0]  |X_SORT1   |X Position Sort Data 1
 * |        |          |X position mean average sort data 1.
 * |[27:16] |Y_SORT1   |Y Position Sort Data 1
 * |        |          |Y position mean average sort data 1.
 * @var ADC_T::XYSORT2
 * Offset: 0x1FC  ADC Touch XY Position Mean Value Sort 2
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[11:0]  |X_SORT2   |X Position Sort Data 2
 * |        |          |X position mean average sort data 2.
 * |[27:16] |Y_SORT2   |Y Position Sort Data 2
 * |        |          |Y position mean average sort data 2.
 * @var ADC_T::XYSORT3
 * Offset: 0x200  ADC Touch XY Position Mean Value Sort 3
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[11:0]  |X_SORT3   |X Position Sort Data 3
 * |        |          |X position mean average sort data 3.
 * |[27:16] |Y_SORT3   |Y Position Sort Data 3
 * |        |          |Y position mean average sort data 3.
 * @var ADC_T::ZSORT0
 * Offset: 0x204  ADC Touch Z Pressure Mean Value Sort 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[11:0]  |Z1_SORT0  |Z1 Position Sort Data 0
 * |        |          |Z1 position Mean average sort data 0.
 * |[27:16] |Z2_SORT0  |Z2 Position Sort Data 0
 * |        |          |Z2 position Mean average sort data 0.
 * @var ADC_T::ZSORT1
 * Offset: 0x208  ADC Touch Z Pressure Mean Value Sort 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[11:0]  |Z1_SORT1  |Z1 Position Sort Data 1
 * |        |          |Z1 position Mean average sort data 1.
 * |[27:16] |Z2_SORT1  |Z2 Position Sort Data 1
 * |        |          |Z2 position Mean average sort data 1.
 * @var ADC_T::ZSORT2
 * Offset: 0x20C  ADC Touch Z Pressure Mean Value Sort 2
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[11:0]  |Z1_SORT2  |Z1 Position Sort Data 2
 * |        |          |Z1 position Mean average sort data 2.
 * |[27:16] |Z2_SORT2  |Z2 Position Sort Data 2
 * |        |          |Z2 position Mean average sort data 2.
 * @var ADC_T::ZSORT3
 * Offset: 0x210  ADC Touch Z Pressure Mean Value Sort 3
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[11:0]  |Z1_SORT3  |Z1 Position Sort Data 3
 * |        |          |Z1 position Mean average sort data 3.
 * |[27:16] |Z2_SORT3  |Z2 Position Sort Data 3
 * |        |          |Z2 position Mean average sort data 3.
 */
    __IO uint32_t CTL;                   /*!< [0x0000] ADC Control                                                      */
    __IO uint32_t CONF;                  /*!< [0x0004] ADC Configure                                                    */
    __IO uint32_t IER;                   /*!< [0x0008] ADC Interrupt Enable Register                                    */
    __IO uint32_t ISR;                   /*!< [0x000c] ADC Interrupt Status Register                                    */
    __IO uint32_t WKISR;                 /*!< [0x0010] ADC Wake Up Interrupt Status Register                            */
    __I  uint32_t RESERVE0[3];
    __I  uint32_t XYDATA;                /*!< [0x0020] ADC Touch X,Y Position Data                                      */
    __I  uint32_t ZDATA;                 /*!< [0x0024] ADC Touch Z Pressure Data                                        */
    __I  uint32_t DATA;                  /*!< [0x0028] ADC Normal Conversion Data                                       */
    __I  uint32_t RESERVE1[114];
    __I  uint32_t XYSORT0;               /*!< [0x01f4] ADC Touch XY Position Mean Value Sort 0                          */
    __I  uint32_t XYSORT1;               /*!< [0x01f8] ADC Touch XY Position Mean Value Sort 1                          */
    __I  uint32_t XYSORT2;               /*!< [0x01fc] ADC Touch XY Position Mean Value Sort 2                          */
    __I  uint32_t XYSORT3;               /*!< [0x0200] ADC Touch XY Position Mean Value Sort 3                          */
    __I  uint32_t ZSORT0;                /*!< [0x0204] ADC Touch Z Pressure Mean Value Sort 0                           */
    __I  uint32_t ZSORT1;                /*!< [0x0208] ADC Touch Z Pressure Mean Value Sort 1                           */
    __I  uint32_t ZSORT2;                /*!< [0x020c] ADC Touch Z Pressure Mean Value Sort 2                           */
    __I  uint32_t ZSORT3;                /*!< [0x0210] ADC Touch Z Pressure Mean Value Sort 3                           */

} ADC_T;

/**
    @addtogroup ADC_CONST ADC Bit Field Definition
    Constant Definitions for ADC Controller
@{ */

#define ADC_CTL_AD_EN_Pos                (0)                                               /*!< ADC_T::CTL: AD_EN Position             */
#define ADC_CTL_AD_EN_Msk                (0x1ul << ADC_CTL_AD_EN_Pos)                      /*!< ADC_T::CTL: AD_EN Mask                 */

#define ADC_CTL_MST_Pos                  (8)                                               /*!< ADC_T::CTL: MST Position               */
#define ADC_CTL_MST_Msk                  (0x1ul << ADC_CTL_MST_Pos)                        /*!< ADC_T::CTL: MST Mask                   */

#define ADC_CTL_PEDE_EN_Pos              (9)                                               /*!< ADC_T::CTL: PEDE_EN Position           */
#define ADC_CTL_PEDE_EN_Msk              (0x1ul << ADC_CTL_PEDE_EN_Pos)                    /*!< ADC_T::CTL: PEDE_EN Mask               */

#define ADC_CTL_WKT_EN_Pos               (11)                                              /*!< ADC_T::CTL: WKT_EN Position            */
#define ADC_CTL_WKT_EN_Msk               (0x1ul << ADC_CTL_WKT_EN_Pos)                     /*!< ADC_T::CTL: WKT_EN Mask                */

#define ADC_CTL_WMSWCH_Pos               (16)                                              /*!< ADC_T::CTL: WMSWCH Position            */
#define ADC_CTL_WMSWCH_Msk               (0x1ul << ADC_CTL_WMSWCH_Pos)                     /*!< ADC_T::CTL: WMSWCH Mask                */

#define ADC_CONF_T_EN_Pos                (0)                                               /*!< ADC_T::CONF: T_EN Position             */
#define ADC_CONF_T_EN_Msk                (0x1ul << ADC_CONF_T_EN_Pos)                      /*!< ADC_T::CONF: T_EN Mask                 */

#define ADC_CONF_Z_EN_Pos                (1)                                               /*!< ADC_T::CONF: Z_EN Position             */
#define ADC_CONF_Z_EN_Msk                (0x1ul << ADC_CONF_Z_EN_Pos)                      /*!< ADC_T::CONF: Z_EN Mask                 */

#define ADC_CONF_NAC_EN_Pos              (2)                                               /*!< ADC_T::CONF: NAC_EN Position           */
#define ADC_CONF_NAC_EN_Msk              (0x1ul << ADC_CONF_NAC_EN_Pos)                    /*!< ADC_T::CONF: NAC_EN Mask               */

#define ADC_CONF_REFSEL_Pos              (6)                                               /*!< ADC_T::CONF: REFSEL Position           */
#define ADC_CONF_REFSEL_Msk              (0x3ul << ADC_CONF_REFSEL_Pos)                    /*!< ADC_T::CONF: REFSEL Mask               */

#define ADC_CONF_CHSEL_Pos               (12)                                              /*!< ADC_T::CONF: CHSEL Position            */
#define ADC_CONF_CHSEL_Msk               (0xful << ADC_CONF_CHSEL_Pos)                     /*!< ADC_T::CONF: CHSEL Mask                */

#define ADC_CONF_REFCNT_Pos              (16)                                              /*!< ADC_T::CONF: REFCNT Position           */
#define ADC_CONF_REFCNT_Msk              (0xful << ADC_CONF_REFCNT_Pos)                    /*!< ADC_T::CONF: REFCNT Mask               */

#define ADC_CONF_TMAVEN_Pos              (20)                                              /*!< ADC_T::CONF: TMAVEN Position           */
#define ADC_CONF_TMAVEN_Msk              (0x1ul << ADC_CONF_TMAVEN_Pos)                    /*!< ADC_T::CONF: TMAVEN Mask               */

#define ADC_CONF_ZMAVEN_Pos              (21)                                              /*!< ADC_T::CONF: ZMAVEN Position           */
#define ADC_CONF_ZMAVEN_Msk              (0x1ul << ADC_CONF_ZMAVEN_Pos)                    /*!< ADC_T::CONF: ZMAVEN Mask               */

#define ADC_CONF_HSPEED_Pos              (22)                                              /*!< ADC_T::CONF: HSPEED Position           */
#define ADC_CONF_HSPEED_Msk              (0x1ul << ADC_CONF_HSPEED_Pos)                    /*!< ADC_T::CONF: HSPEED Mask               */

#define ADC_CONF_SAMPCNT_Pos             (24)                                              /*!< ADC_T::CONF: SAMPCNT Position          */
#define ADC_CONF_SAMPCNT_Msk             (0xfful << ADC_CONF_SAMPCNT_Pos)                  /*!< ADC_T::CONF: SAMPCNT Mask              */

#define ADC_IER_M_IEN_Pos                (0)                                               /*!< ADC_T::IER: M_IEN Position             */
#define ADC_IER_M_IEN_Msk                (0x1ul << ADC_IER_M_IEN_Pos)                      /*!< ADC_T::IER: M_IEN Mask                 */

#define ADC_IER_PEDE_IEN_Pos             (2)                                               /*!< ADC_T::IER: PEDE_IEN Position          */
#define ADC_IER_PEDE_IEN_Msk             (0x1ul << ADC_IER_PEDE_IEN_Pos)                   /*!< ADC_T::IER: PEDE_IEN Mask              */

#define ADC_IER_WKT_IEN_Pos              (3)                                               /*!< ADC_T::IER: WKT_IEN Position           */
#define ADC_IER_WKT_IEN_Msk              (0x1ul << ADC_IER_WKT_IEN_Pos)                    /*!< ADC_T::IER: WKT_IEN Mask               */

#define ADC_IER_PEUE_IEN_Pos             (6)                                               /*!< ADC_T::IER: PEUE_IEN Position          */
#define ADC_IER_PEUE_IEN_Msk             (0x1ul << ADC_IER_PEUE_IEN_Pos)                   /*!< ADC_T::IER: PEUE_IEN Mask              */

#define ADC_ISR_M_F_Pos                  (0)                                               /*!< ADC_T::ISR: M_F Position               */
#define ADC_ISR_M_F_Msk                  (0x1ul << ADC_ISR_M_F_Pos)                        /*!< ADC_T::ISR: M_F Mask                   */

#define ADC_ISR_PEDE_F_Pos               (2)                                               /*!< ADC_T::ISR: PEDE_F Position            */
#define ADC_ISR_PEDE_F_Msk               (0x1ul << ADC_ISR_PEDE_F_Pos)                     /*!< ADC_T::ISR: PEDE_F Mask                */

#define ADC_ISR_PEUE_F_Pos               (4)                                               /*!< ADC_T::ISR: PEUE_F Position            */
#define ADC_ISR_PEUE_F_Msk               (0x1ul << ADC_ISR_PEUE_F_Pos)                     /*!< ADC_T::ISR: PEUE_F Mask                */

#define ADC_ISR_T_F_Pos                  (8)                                               /*!< ADC_T::ISR: T_F Position               */
#define ADC_ISR_T_F_Msk                  (0x1ul << ADC_ISR_T_F_Pos)                        /*!< ADC_T::ISR: T_F Mask                   */

#define ADC_ISR_Z_F_Pos                  (9)                                               /*!< ADC_T::ISR: Z_F Position               */
#define ADC_ISR_Z_F_Msk                  (0x1ul << ADC_ISR_Z_F_Pos)                        /*!< ADC_T::ISR: Z_F Mask                   */

#define ADC_ISR_NAC_F_Pos                (10)                                              /*!< ADC_T::ISR: NAC_F Position             */
#define ADC_ISR_NAC_F_Msk                (0x1ul << ADC_ISR_NAC_F_Pos)                      /*!< ADC_T::ISR: NAC_F Mask                 */

#define ADC_ISR_INT_TC_Pos               (17)                                              /*!< ADC_T::ISR: INT_TC Position            */
#define ADC_ISR_INT_TC_Msk               (0x1ul << ADC_ISR_INT_TC_Pos)                     /*!< ADC_T::ISR: INT_TC Mask                */

#define ADC_WKISR_WPEDE_F_Pos            (1)                                               /*!< ADC_T::WKISR: WPEDE_F Position         */
#define ADC_WKISR_WPEDE_F_Msk            (0x1ul << ADC_WKISR_WPEDE_F_Pos)                  /*!< ADC_T::WKISR: WPEDE_F Mask             */

#define ADC_XYDATA_XDATA_Pos             (0)                                               /*!< ADC_T::XYDATA: XDATA Position          */
#define ADC_XYDATA_XDATA_Msk             (0xffful << ADC_XYDATA_XDATA_Pos)                 /*!< ADC_T::XYDATA: XDATA Mask              */

#define ADC_XYDATA_YDATA_Pos             (16)                                              /*!< ADC_T::XYDATA: YDATA Position          */
#define ADC_XYDATA_YDATA_Msk             (0xffful << ADC_XYDATA_YDATA_Pos)                 /*!< ADC_T::XYDATA: YDATA Mask              */

#define ADC_ZDATA_Z1DATA_Pos             (0)                                               /*!< ADC_T::ZDATA: Z1DATA Position          */
#define ADC_ZDATA_Z1DATA_Msk             (0xffful << ADC_ZDATA_Z1DATA_Pos)                 /*!< ADC_T::ZDATA: Z1DATA Mask              */

#define ADC_ZDATA_Z2DATA_Pos             (16)                                              /*!< ADC_T::ZDATA: Z2DATA Position          */
#define ADC_ZDATA_Z2DATA_Msk             (0x7fful << ADC_ZDATA_Z2DATA_Pos)                 /*!< ADC_T::ZDATA: Z2DATA Mask              */

#define ADC_DATA_ADC_DATA_Pos            (0)                                               /*!< ADC_T::DATA: ADC_DATA Position         */
#define ADC_DATA_ADC_DATA_Msk            (0xffful << ADC_DATA_ADC_DATA_Pos)                /*!< ADC_T::DATA: ADC_DATA Mask             */

#define ADC_XYSORT0_X_SORT0_Pos          (0)                                               /*!< ADC_T::XYSORT0: X_SORT0 Position       */
#define ADC_XYSORT0_X_SORT0_Msk          (0xffful << ADC_XYSORT0_X_SORT0_Pos)              /*!< ADC_T::XYSORT0: X_SORT0 Mask           */

#define ADC_XYSORT0_Y_SORT0_Pos          (16)                                              /*!< ADC_T::XYSORT0: Y_SORT0 Position       */
#define ADC_XYSORT0_Y_SORT0_Msk          (0xffful << ADC_XYSORT0_Y_SORT0_Pos)              /*!< ADC_T::XYSORT0: Y_SORT0 Mask           */

#define ADC_XYSORT1_X_SORT1_Pos          (0)                                               /*!< ADC_T::XYSORT1: X_SORT1 Position       */
#define ADC_XYSORT1_X_SORT1_Msk          (0xffful << ADC_XYSORT1_X_SORT1_Pos)              /*!< ADC_T::XYSORT1: X_SORT1 Mask           */

#define ADC_XYSORT1_Y_SORT1_Pos          (16)                                              /*!< ADC_T::XYSORT1: Y_SORT1 Position       */
#define ADC_XYSORT1_Y_SORT1_Msk          (0xffful << ADC_XYSORT1_Y_SORT1_Pos)              /*!< ADC_T::XYSORT1: Y_SORT1 Mask           */

#define ADC_XYSORT2_X_SORT2_Pos          (0)                                               /*!< ADC_T::XYSORT2: X_SORT2 Position       */
#define ADC_XYSORT2_X_SORT2_Msk          (0xffful << ADC_XYSORT2_X_SORT2_Pos)              /*!< ADC_T::XYSORT2: X_SORT2 Mask           */

#define ADC_XYSORT2_Y_SORT2_Pos          (16)                                              /*!< ADC_T::XYSORT2: Y_SORT2 Position       */
#define ADC_XYSORT2_Y_SORT2_Msk          (0xffful << ADC_XYSORT2_Y_SORT2_Pos)              /*!< ADC_T::XYSORT2: Y_SORT2 Mask           */

#define ADC_XYSORT3_X_SORT3_Pos          (0)                                               /*!< ADC_T::XYSORT3: X_SORT3 Position       */
#define ADC_XYSORT3_X_SORT3_Msk          (0xffful << ADC_XYSORT3_X_SORT3_Pos)              /*!< ADC_T::XYSORT3: X_SORT3 Mask           */

#define ADC_XYSORT3_Y_SORT3_Pos          (16)                                              /*!< ADC_T::XYSORT3: Y_SORT3 Position       */
#define ADC_XYSORT3_Y_SORT3_Msk          (0xffful << ADC_XYSORT3_Y_SORT3_Pos)              /*!< ADC_T::XYSORT3: Y_SORT3 Mask           */

#define ADC_ZSORT0_Z1_SORT0_Pos          (0)                                               /*!< ADC_T::ZSORT0: Z1_SORT0 Position       */
#define ADC_ZSORT0_Z1_SORT0_Msk          (0xffful << ADC_ZSORT0_Z1_SORT0_Pos)              /*!< ADC_T::ZSORT0: Z1_SORT0 Mask           */

#define ADC_ZSORT0_Z2_SORT0_Pos          (16)                                              /*!< ADC_T::ZSORT0: Z2_SORT0 Position       */
#define ADC_ZSORT0_Z2_SORT0_Msk          (0xffful << ADC_ZSORT0_Z2_SORT0_Pos)              /*!< ADC_T::ZSORT0: Z2_SORT0 Mask           */

#define ADC_ZSORT1_Z1_SORT1_Pos          (0)                                               /*!< ADC_T::ZSORT1: Z1_SORT1 Position       */
#define ADC_ZSORT1_Z1_SORT1_Msk          (0xffful << ADC_ZSORT1_Z1_SORT1_Pos)              /*!< ADC_T::ZSORT1: Z1_SORT1 Mask           */

#define ADC_ZSORT1_Z2_SORT1_Pos          (16)                                              /*!< ADC_T::ZSORT1: Z2_SORT1 Position       */
#define ADC_ZSORT1_Z2_SORT1_Msk          (0xffful << ADC_ZSORT1_Z2_SORT1_Pos)              /*!< ADC_T::ZSORT1: Z2_SORT1 Mask           */

#define ADC_ZSORT2_Z1_SORT2_Pos          (0)                                               /*!< ADC_T::ZSORT2: Z1_SORT2 Position       */
#define ADC_ZSORT2_Z1_SORT2_Msk          (0xffful << ADC_ZSORT2_Z1_SORT2_Pos)              /*!< ADC_T::ZSORT2: Z1_SORT2 Mask           */

#define ADC_ZSORT2_Z2_SORT2_Pos          (16)                                              /*!< ADC_T::ZSORT2: Z2_SORT2 Position       */
#define ADC_ZSORT2_Z2_SORT2_Msk          (0xffful << ADC_ZSORT2_Z2_SORT2_Pos)              /*!< ADC_T::ZSORT2: Z2_SORT2 Mask           */

#define ADC_ZSORT3_Z1_SORT3_Pos          (0)                                               /*!< ADC_T::ZSORT3: Z1_SORT3 Position       */
#define ADC_ZSORT3_Z1_SORT3_Msk          (0xffful << ADC_ZSORT3_Z1_SORT3_Pos)              /*!< ADC_T::ZSORT3: Z1_SORT3 Mask           */

#define ADC_ZSORT3_Z2_SORT3_Pos          (16)                                              /*!< ADC_T::ZSORT3: Z2_SORT3 Position       */
#define ADC_ZSORT3_Z2_SORT3_Msk          (0xffful << ADC_ZSORT3_Z2_SORT3_Pos)              /*!< ADC_T::ZSORT3: Z2_SORT3 Mask           */

#ifdef __cplusplus
}
#endif

#endif

/**@}*/ /* ADC_CONST */
/**@}*/ /* end of ADC register group */


/**@}*/ /* end of REGISTER group */

/*** (C) COPYRIGHT 2025 Nuvoton Technology Corp. ***/
