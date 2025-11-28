/**************************************************************************//**
 * @file     eadc_reg.h
 * @brief    EADC register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __EADC_REG_H__
#define __EADC_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/

/** @addtogroup REGISTER Control Register

  @{

*/

/*---------------------- Enhanced Analog to Digital Converter -------------------------*/
/**
    @addtogroup EADC Enhanced Analog to Digital Converter(EADC)
    Memory Mapped Structure for EADC Controller
@{ */

typedef struct
{

    /**
     * @var EADC_T::DAT0
     * Offset: 0x00  EADC Data Register 0 for Sample Module 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RESULT    |EADC Conversion Result
     * |        |          |This field contains 12 bits conversion result.
     * |        |          |When DMOF (EADC_CTL[9]) is set to 0, 12-bit EADC conversion result with unsigned format will be filled in RESULT[11:0] and zero will be filled in RESULT[15:12].
     * |        |          |When DMOF (EADC_CTL[9]) set to 1, 12-bit EADC conversion result with 2u2019complement format will be filled in RESULT[11:0] and signed bits to will be filled in RESULT[15:12].
     * |[16]    |OV        |Overrun Flag
     * |        |          |If converted data in RESULT[11:0] has not been read before new conversion result is loaded to this register, OV is set to 1.
     * |        |          |0 = Data in RESULT[11:0] is recent conversion result.
     * |        |          |1 = Data in RESULT[11:0] is overwrite.
     * |        |          |Note: It is cleared by hardware after EADC_DAT register is read.
     * |[17]    |VALID     |Valid Flag
     * |        |          |This bit is set to 1 when corresponding sample module channel analog input conversion is completed and cleared by hardware after EADC_DAT register is read.
     * |        |          |0 = Data in RESULT[11:0] bits is not valid.
     * |        |          |1 = Data in RESULT[11:0] bits is valid.
     * @var EADC_T::DAT1
     * Offset: 0x04  EADC Data Register 1 for Sample Module 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RESULT    |EADC Conversion Result
     * |        |          |This field contains 12 bits conversion result.
     * |        |          |When DMOF (EADC_CTL[9]) is set to 0, 12-bit EADC conversion result with unsigned format will be filled in RESULT[11:0] and zero will be filled in RESULT[15:12].
     * |        |          |When DMOF (EADC_CTL[9]) set to 1, 12-bit EADC conversion result with 2u2019complement format will be filled in RESULT[11:0] and signed bits to will be filled in RESULT[15:12].
     * |[16]    |OV        |Overrun Flag
     * |        |          |If converted data in RESULT[11:0] has not been read before new conversion result is loaded to this register, OV is set to 1.
     * |        |          |0 = Data in RESULT[11:0] is recent conversion result.
     * |        |          |1 = Data in RESULT[11:0] is overwrite.
     * |        |          |Note: It is cleared by hardware after EADC_DAT register is read.
     * |[17]    |VALID     |Valid Flag
     * |        |          |This bit is set to 1 when corresponding sample module channel analog input conversion is completed and cleared by hardware after EADC_DAT register is read.
     * |        |          |0 = Data in RESULT[11:0] bits is not valid.
     * |        |          |1 = Data in RESULT[11:0] bits is valid.
     * @var EADC_T::DAT2
     * Offset: 0x08  EADC Data Register 2 for Sample Module 2
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RESULT    |EADC Conversion Result
     * |        |          |This field contains 12 bits conversion result.
     * |        |          |When DMOF (EADC_CTL[9]) is set to 0, 12-bit EADC conversion result with unsigned format will be filled in RESULT[11:0] and zero will be filled in RESULT[15:12].
     * |        |          |When DMOF (EADC_CTL[9]) set to 1, 12-bit EADC conversion result with 2u2019complement format will be filled in RESULT[11:0] and signed bits to will be filled in RESULT[15:12].
     * |[16]    |OV        |Overrun Flag
     * |        |          |If converted data in RESULT[11:0] has not been read before new conversion result is loaded to this register, OV is set to 1.
     * |        |          |0 = Data in RESULT[11:0] is recent conversion result.
     * |        |          |1 = Data in RESULT[11:0] is overwrite.
     * |        |          |Note: It is cleared by hardware after EADC_DAT register is read.
     * |[17]    |VALID     |Valid Flag
     * |        |          |This bit is set to 1 when corresponding sample module channel analog input conversion is completed and cleared by hardware after EADC_DAT register is read.
     * |        |          |0 = Data in RESULT[11:0] bits is not valid.
     * |        |          |1 = Data in RESULT[11:0] bits is valid.
     * @var EADC_T::DAT3
     * Offset: 0x0C  EADC Data Register 3 for Sample Module 3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RESULT    |EADC Conversion Result
     * |        |          |This field contains 12 bits conversion result.
     * |        |          |When DMOF (EADC_CTL[9]) is set to 0, 12-bit EADC conversion result with unsigned format will be filled in RESULT[11:0] and zero will be filled in RESULT[15:12].
     * |        |          |When DMOF (EADC_CTL[9]) set to 1, 12-bit EADC conversion result with 2u2019complement format will be filled in RESULT[11:0] and signed bits to will be filled in RESULT[15:12].
     * |[16]    |OV        |Overrun Flag
     * |        |          |If converted data in RESULT[11:0] has not been read before new conversion result is loaded to this register, OV is set to 1.
     * |        |          |0 = Data in RESULT[11:0] is recent conversion result.
     * |        |          |1 = Data in RESULT[11:0] is overwrite.
     * |        |          |Note: It is cleared by hardware after EADC_DAT register is read.
     * |[17]    |VALID     |Valid Flag
     * |        |          |This bit is set to 1 when corresponding sample module channel analog input conversion is completed and cleared by hardware after EADC_DAT register is read.
     * |        |          |0 = Data in RESULT[11:0] bits is not valid.
     * |        |          |1 = Data in RESULT[11:0] bits is valid.
     * @var EADC_T::DAT4
     * Offset: 0x10  EADC Data Register 4 for Sample Module 4
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RESULT    |EADC Conversion Result
     * |        |          |This field contains 12 bits conversion result.
     * |        |          |When DMOF (EADC_CTL[9]) is set to 0, 12-bit EADC conversion result with unsigned format will be filled in RESULT[11:0] and zero will be filled in RESULT[15:12].
     * |        |          |When DMOF (EADC_CTL[9]) set to 1, 12-bit EADC conversion result with 2u2019complement format will be filled in RESULT[11:0] and signed bits to will be filled in RESULT[15:12].
     * |[16]    |OV        |Overrun Flag
     * |        |          |If converted data in RESULT[11:0] has not been read before new conversion result is loaded to this register, OV is set to 1.
     * |        |          |0 = Data in RESULT[11:0] is recent conversion result.
     * |        |          |1 = Data in RESULT[11:0] is overwrite.
     * |        |          |Note: It is cleared by hardware after EADC_DAT register is read.
     * |[17]    |VALID     |Valid Flag
     * |        |          |This bit is set to 1 when corresponding sample module channel analog input conversion is completed and cleared by hardware after EADC_DAT register is read.
     * |        |          |0 = Data in RESULT[11:0] bits is not valid.
     * |        |          |1 = Data in RESULT[11:0] bits is valid.
     * @var EADC_T::DAT5
     * Offset: 0x14  EADC Data Register 5 for Sample Module 5
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RESULT    |EADC Conversion Result
     * |        |          |This field contains 12 bits conversion result.
     * |        |          |When DMOF (EADC_CTL[9]) is set to 0, 12-bit EADC conversion result with unsigned format will be filled in RESULT[11:0] and zero will be filled in RESULT[15:12].
     * |        |          |When DMOF (EADC_CTL[9]) set to 1, 12-bit EADC conversion result with 2u2019complement format will be filled in RESULT[11:0] and signed bits to will be filled in RESULT[15:12].
     * |[16]    |OV        |Overrun Flag
     * |        |          |If converted data in RESULT[11:0] has not been read before new conversion result is loaded to this register, OV is set to 1.
     * |        |          |0 = Data in RESULT[11:0] is recent conversion result.
     * |        |          |1 = Data in RESULT[11:0] is overwrite.
     * |        |          |Note: It is cleared by hardware after EADC_DAT register is read.
     * |[17]    |VALID     |Valid Flag
     * |        |          |This bit is set to 1 when corresponding sample module channel analog input conversion is completed and cleared by hardware after EADC_DAT register is read.
     * |        |          |0 = Data in RESULT[11:0] bits is not valid.
     * |        |          |1 = Data in RESULT[11:0] bits is valid.
     * @var EADC_T::DAT6
     * Offset: 0x18  EADC Data Register 6 for Sample Module 6
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RESULT    |EADC Conversion Result
     * |        |          |This field contains 12 bits conversion result.
     * |        |          |When DMOF (EADC_CTL[9]) is set to 0, 12-bit EADC conversion result with unsigned format will be filled in RESULT[11:0] and zero will be filled in RESULT[15:12].
     * |        |          |When DMOF (EADC_CTL[9]) set to 1, 12-bit EADC conversion result with 2u2019complement format will be filled in RESULT[11:0] and signed bits to will be filled in RESULT[15:12].
     * |[16]    |OV        |Overrun Flag
     * |        |          |If converted data in RESULT[11:0] has not been read before new conversion result is loaded to this register, OV is set to 1.
     * |        |          |0 = Data in RESULT[11:0] is recent conversion result.
     * |        |          |1 = Data in RESULT[11:0] is overwrite.
     * |        |          |Note: It is cleared by hardware after EADC_DAT register is read.
     * |[17]    |VALID     |Valid Flag
     * |        |          |This bit is set to 1 when corresponding sample module channel analog input conversion is completed and cleared by hardware after EADC_DAT register is read.
     * |        |          |0 = Data in RESULT[11:0] bits is not valid.
     * |        |          |1 = Data in RESULT[11:0] bits is valid.
     * @var EADC_T::DAT7
     * Offset: 0x1C  EADC Data Register 7 for Sample Module 7
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RESULT    |EADC Conversion Result
     * |        |          |This field contains 12 bits conversion result.
     * |        |          |When DMOF (EADC_CTL[9]) is set to 0, 12-bit EADC conversion result with unsigned format will be filled in RESULT[11:0] and zero will be filled in RESULT[15:12].
     * |        |          |When DMOF (EADC_CTL[9]) set to 1, 12-bit EADC conversion result with 2u2019complement format will be filled in RESULT[11:0] and signed bits to will be filled in RESULT[15:12].
     * |[16]    |OV        |Overrun Flag
     * |        |          |If converted data in RESULT[11:0] has not been read before new conversion result is loaded to this register, OV is set to 1.
     * |        |          |0 = Data in RESULT[11:0] is recent conversion result.
     * |        |          |1 = Data in RESULT[11:0] is overwrite.
     * |        |          |Note: It is cleared by hardware after EADC_DAT register is read.
     * |[17]    |VALID     |Valid Flag
     * |        |          |This bit is set to 1 when corresponding sample module channel analog input conversion is completed and cleared by hardware after EADC_DAT register is read.
     * |        |          |0 = Data in RESULT[11:0] bits is not valid.
     * |        |          |1 = Data in RESULT[11:0] bits is valid.
     * @var EADC_T::DAT8
     * Offset: 0x20  EADC Data Register 8 for Sample Module 8
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RESULT    |EADC Conversion Result
     * |        |          |This field contains 12 bits conversion result.
     * |        |          |When DMOF (EADC_CTL[9]) is set to 0, 12-bit EADC conversion result with unsigned format will be filled in RESULT[11:0] and zero will be filled in RESULT[15:12].
     * |        |          |When DMOF (EADC_CTL[9]) set to 1, 12-bit EADC conversion result with 2u2019complement format will be filled in RESULT[11:0] and signed bits to will be filled in RESULT[15:12].
     * |[16]    |OV        |Overrun Flag
     * |        |          |If converted data in RESULT[11:0] has not been read before new conversion result is loaded to this register, OV is set to 1.
     * |        |          |0 = Data in RESULT[11:0] is recent conversion result.
     * |        |          |1 = Data in RESULT[11:0] is overwrite.
     * |        |          |Note: It is cleared by hardware after EADC_DAT register is read.
     * |[17]    |VALID     |Valid Flag
     * |        |          |This bit is set to 1 when corresponding sample module channel analog input conversion is completed and cleared by hardware after EADC_DAT register is read.
     * |        |          |0 = Data in RESULT[11:0] bits is not valid.
     * |        |          |1 = Data in RESULT[11:0] bits is valid.
     * @var EADC_T::CURDAT
     * Offset: 0x4C  EADC PDMA Current Transfer Data Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |CURDAT0   |EADC PDMA Current Transfer Data 0(Read Only)
     * |        |          |This CURDAT0 content 12-bit EADC conversion result of the (N)th EADC_DATx (x=0~8) for PDMA support.
     * |        |          |Note: The CURDAT0 cannot be read by CPU when PDMA transfer enabled.
     * |[31:16] |CURDAT1   |EADC PDMA Current Transfer Data 1(Read Only)
     * |        |          |This CURDAT1 content 12-bit EADC conversion result of the (N+1)th EADC_DATx (x=0~8) for PDMA support.
     * |        |          |Note: The CURDAT1 cannot be read by CPU when PDMA transfer enabled.
     * @var EADC_T::CTL
     * Offset: 0x50  EADC Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |EADCEN    |EADC Converter Enable Bit
     * |        |          |0 = EADC Disabled.
     * |        |          |1 = EADC Enabled.
     * |        |          |Note: Before starting EADC conversion function, this bit should be set to 1
     * |        |          |Clear it to 0 to disable EADC converter analog circuit power consumption.
     * |[1]     |EADCRST   |EADC Converter Control Circuits Reset
     * |        |          |0 = No effect.
     * |        |          |1 = Cause EADC control circuits reset to initial state, but not change the EADC registers value.
     * |        |          |Note: EADCRST bit remains 1 during EADC reset, when EADC reset end, the EADCRST bit is automatically cleared to 0.
     * |[2]     |EADCIEN0  |Specific Sample Module EADC ADINT0 Interrupt Enable Bit
     * |        |          |The EADC converter generates a conversion end ADIF0 (EADC_STATUS2[0]) upon the end of specific sample module EADC conversion
     * |        |          |If EADCIEN0 bit is set then conversion end interrupt request ADINT0 is generated.
     * |        |          |0 = Specific sample module EADC ADINT0 interrupt function Disabled.
     * |        |          |1 = Specific sample module EADC ADINT0 interrupt function Enabled.
     * |[3]     |EADCIEN1  |Specific Sample Module EADC ADINT1 Interrupt Enable Bit
     * |        |          |The EADC converter generates a conversion end ADIF1 (EADC_STATUS2[1]) upon the end of specific sample module EADC conversion
     * |        |          |If EADCIEN1 bit is set then conversion end interrupt request ADINT1 is generated.
     * |        |          |0 = Specific sample module EADC ADINT1 interrupt function Disabled.
     * |        |          |1 = Specific sample module EADC ADINT1 interrupt function Enabled.
     * |[4]     |EADCIEN2  |Specific Sample Module EADC ADINT2 Interrupt Enable Bit
     * |        |          |The EADC converter generates a conversion end ADIF2 (EADC_STATUS2[2]) upon the end of specific sample module EADC conversion
     * |        |          |If EADCIEN2 bit is set then conversion end interrupt request ADINT2 is generated.
     * |        |          |0 = Specific sample module EADC ADINT2 interrupt function Disabled.
     * |        |          |1 = Specific sample module EADC ADINT2 interrupt function Enabled.
     * |[5]     |EADCIEN3  |Specific Sample Module EADC ADINT3 Interrupt Enable Bit
     * |        |          |The EADC converter generates a conversion end ADIF3 (EADC_STATUS2[3]) upon the end of specific sample module EADC conversion
     * |        |          |If EADCIEN3 bit is set then conversion end interrupt request ADINT3 is generated.
     * |        |          |0 = Specific sample module EADC ADINT3 interrupt function Disabled.
     * |        |          |1 = Specific sample module EADC ADINT3 interrupt function Enabled.
     * |[7:6]   |RES       |Resolution (Read Only)
     * |        |          |00 = 6-bit EADC result will be put at RESULT (EADC_DATn[5:0]).
     * |        |          |01 = 8-bit EADC result will be put at RESULT (EADC_DATn[7:0]).
     * |        |          |10 = 10-bit EADC result will be put at RESULT (EADC_DATn[9:0]).
     * |        |          |11 = 12-bit EADC result will be put at RESULT (EADC_DATn[11:0]).
     * |[8]     |DIFFEN    |Differential Analog Input Mode Enable Bit
     * |        |          |0 = Single-end analog input mode.
     * |        |          |1 = Differential analog input mode.
     * |[9]     |DMOF      |EADC Differential Input Mode Output Format
     * |        |          |0 = EADC conversion result will be filled in RESULT (EADC_DATn[15:0], where n= 0 ~ 8) with unsigned format.
     * |        |          |1 = EADC conversion result will be filled in RESULT (EADC_DATn[15:0], where n= 0 ~ 8) with 2'complement format.
     * |[10]    |VREFSEL   |EADC Voltage Reference Select Bit
     * |        |          |EADC reference voltage select when EADC operate, user can control this bit to select reference voltage for EADC.
     * |        |          |0 = AGND33 vs 2.5V buffer output, or VREF input.
     * |        |          |1 = AGND33 vs AVDD33.
     * |        |          |Note 1: If EADC reference voltage come from VREF input, set this bit to 0 and set PDREF(EADC_REFADJCTL[0]) to 1.
     * |        |          |Note 2: If EADC reference voltage come from 2.5V buffer output, set this bit to 0 and set PDREF(EADC_REFADJCTL[0]) to 0
     * |        |          |And keep VREF input floating.
     * |        |          |Note 3: If EADC reference voltage come from AVDD33 input, set this bit to 1 and set PDREF(EADC_REFADJCTL[0]) to 1.
     * |[12]    |SPEED     |Speed Mode Select Bit
     * |        |          |Control signal for EADC conversion speed
     * |        |          |0 = Low speed mode.
     * |        |          |1 = High speed mode.
     * |[13]    |FFTDIEN   |EADC Ping-Pong FIFO Full Transfer Done Interrupt Enable Bit
     * |        |          |If FFTDIEN bit is set then the ping-pong fifo full transfer done interrupt request ADINT3 is generated.
     * |        |          |0 = Specific the ping-pong fifo full transfer done interrupt function Disabled.
     * |        |          |1 = Specific the ping-pong fifo full transfer done interrupt function Enabled.
     * @var EADC_T::SWTRG
     * Offset: 0x54  EADC Sample Module Software Start Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[8:0]   |SWTRG     |EADC Sample Module 0~8 Software Force to Start EADC Conversion
     * |        |          |0 = No effect.
     * |        |          |1 = Cause an EADC conversion when the priority is given to sample module.
     * |        |          |Note: After writing this register to start EADC conversion, the EADC_PENDSTS register will show which sample module will conversion
     * |        |          |If user want to disable the conversion of the sample module, user can write EADC_PENDSTS register to clear it.
     * @var EADC_T::PENDSTS
     * Offset: 0x58  EADC Start of Conversion Pending Flag Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[8:0]   |STPF      |EADC Sample Module 0~8 Start of Conversion Pending Flag
     * |        |          |Read Operation:
     * |        |          |0 = There is no pending conversion for sample module.
     * |        |          |1 = Sample module EADC start of conversion is pending.
     * |        |          |Write Operation:
     * |        |          |1 = Clear pending flag & cancel the conversion for sample module.
     * |        |          |Note: This bit remains 1 during pending state
     * |        |          |When the respective EADC conversion is ended, the STPFn (n=0~8) bit is automatically cleared to 0
     * @var EADC_T::OVSTS
     * Offset: 0x5C  EADC Sample Module Start of Conversion Overrun Flag Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[8:0]   |SPOVF     |EADC SAMPLE0~8 Overrun Flag
     * |        |          |0 = No sample module event overrun.
     * |        |          |1 = Indicates a new sample module event is generated while an old one event is pending.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * @var EADC_T::SELFTCTL
     * Offset: 0x7C  EADC Self Test Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |SELFTEN   |EADC Self Test Enable (Write Protect)
     * |        |          |0 = EADC self-test mode Disabled.
     * |        |          |1 = EADC self-test mode Enabled.
     * |        |          |When EADC self-test mode enable, the EADC channel can controlled by correlate GPIO register
     * |        |          |User can use GPIO to force each EADC channel as GND or VDD to check each channel path is OK.
     * |        |          |Note: This bit is write protected. Refer to the SYS_REGLCTL register.
     * @var EADC_T::SCTL0
     * Offset: 0x80  EADC Sample Module 0 Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |CHSEL     |EADC Sample Module Channel Selection
     * |        |          |00H = EADC_CH0.
     * |        |          |01H = EADC_CH1.
     * |        |          |02H = EADC_CH2.
     * |        |          |03H = EADC_CH3.
     * |        |          |04H = EADC_CH4.
     * |        |          |05H = EADC_CH5.
     * |        |          |06H = EADC_CH6.
     * |        |          |07H = EADC_CH7.
     * |        |          |08H = VREF.
     * |[4]     |EXTREN    |EADC External Trigger Rising Edge Enable Bit
     * |        |          |0 = Rising edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Rising edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[5]     |EXTFEN    |EADC External Trigger Falling Edge Enable Bit
     * |        |          |0 = Falling edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Falling edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[7:6]   |TRGDLYDIV |EADC Sample Module Start of Conversion Trigger Delay Clock Divider Selection
     * |        |          |Trigger delay clock frequency:
     * |        |          |00 = EADC_CLK/1.
     * |        |          |01 = EADC_CLK/2.
     * |        |          |10 = EADC_CLK/4.
     * |        |          |11 = EADC_CLK/16.
     * |[15:8]  |TRGDLYCNT |EADC Sample Module Start of Conversion Trigger Delay Time
     * |        |          |Trigger delay time = TRGDLYCNT x EADC_CLK period x n (n=1,2,4,16 from TRGDLYDIV setting).
     * |        |          |Note: If TRGDLYCNT is set to 1, trigger delay time is actually the same as TRGDLYCNT is set to 2 for hardware operation.
     * |[21:16] |TRGSEL    |EADC Sample Module Start of Conversion Trigger Source Selection
     * |        |          |0H = Disable trigger.
     * |        |          |1H = EADC ADINT0 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |2H = EADC ADINT1 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |3H = Timer0 overflow pulse trigger.
     * |        |          |4H = Timer1 overflow pulse trigger.
     * |        |          |5H = Timer2 overflow pulse trigger.
     * |        |          |6H = Timer3 overflow pulse trigger.
     * |        |          |7H = Timer4 overflow pulse trigger.
     * |        |          |8H = Timer5 overflow pulse trigger.
     * |        |          |9H = BPWM0TG.
     * |        |          |AH = BPWM1TG.
     * |        |          |other = Reserved.
     * |[22]    |INTPOS    |Interrupt Flag Position Select
     * |        |          |0 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC end of conversion.
     * |        |          |1 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC start of conversion.
     * |[23]    |DBMEN     |Double Buffer Mode Enable Bit
     * |        |          |0 = Sample has one sample result register (default).
     * |        |          |1 = Sample has two sample result registers.
     * |[31:24] |EXTSMPT   |EADC Sampling Time Extend
     * |        |          |When EADC converting at high conversion rate, the sampling time of analog input voltage may not be enough if input channel loading is heavy, and software can extend EADC sampling time after trigger source is coming to get enough sampling time.
     * |        |          |Extended Sampling Time = (EXTSMPT + 1) x EADC_CLK period.
     * @var EADC_T::SCTL1
     * Offset: 0x84  EADC Sample Module 1 Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |CHSEL     |EADC Sample Module Channel Selection
     * |        |          |00H = EADC_CH0.
     * |        |          |01H = EADC_CH1.
     * |        |          |02H = EADC_CH2.
     * |        |          |03H = EADC_CH3.
     * |        |          |04H = EADC_CH4.
     * |        |          |05H = EADC_CH5.
     * |        |          |06H = EADC_CH6.
     * |        |          |07H = EADC_CH7.
     * |        |          |08H = VREF.
     * |[4]     |EXTREN    |EADC External Trigger Rising Edge Enable Bit
     * |        |          |0 = Rising edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Rising edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[5]     |EXTFEN    |EADC External Trigger Falling Edge Enable Bit
     * |        |          |0 = Falling edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Falling edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[7:6]   |TRGDLYDIV |EADC Sample Module Start of Conversion Trigger Delay Clock Divider Selection
     * |        |          |Trigger delay clock frequency:
     * |        |          |00 = EADC_CLK/1.
     * |        |          |01 = EADC_CLK/2.
     * |        |          |10 = EADC_CLK/4.
     * |        |          |11 = EADC_CLK/16.
     * |[15:8]  |TRGDLYCNT |EADC Sample Module Start of Conversion Trigger Delay Time
     * |        |          |Trigger delay time = TRGDLYCNT x EADC_CLK period x n (n=1,2,4,16 from TRGDLYDIV setting).
     * |        |          |Note: If TRGDLYCNT is set to 1, trigger delay time is actually the same as TRGDLYCNT is set to 2 for hardware operation.
     * |[21:16] |TRGSEL    |EADC Sample Module Start of Conversion Trigger Source Selection
     * |        |          |0H = Disable trigger.
     * |        |          |1H = EADC ADINT0 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |2H = EADC ADINT1 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |3H = Timer0 overflow pulse trigger.
     * |        |          |4H = Timer1 overflow pulse trigger.
     * |        |          |5H = Timer2 overflow pulse trigger.
     * |        |          |6H = Timer3 overflow pulse trigger.
     * |        |          |7H = Timer4 overflow pulse trigger.
     * |        |          |8H = Timer5 overflow pulse trigger.
     * |        |          |9H = BPWM0TG.
     * |        |          |AH = BPWM1TG.
     * |        |          |other = Reserved.
     * |[22]    |INTPOS    |Interrupt Flag Position Select
     * |        |          |0 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC end of conversion.
     * |        |          |1 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC start of conversion.
     * |[23]    |DBMEN     |Double Buffer Mode Enable Bit
     * |        |          |0 = Sample has one sample result register (default).
     * |        |          |1 = Sample has two sample result registers.
     * |[31:24] |EXTSMPT   |EADC Sampling Time Extend
     * |        |          |When EADC converting at high conversion rate, the sampling time of analog input voltage may not be enough if input channel loading is heavy, and software can extend EADC sampling time after trigger source is coming to get enough sampling time.
     * |        |          |Extended Sampling Time = (EXTSMPT + 1) x EADC_CLK period.
     * @var EADC_T::SCTL2
     * Offset: 0x88  EADC Sample Module 2 Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |CHSEL     |EADC Sample Module Channel Selection
     * |        |          |00H = EADC_CH0.
     * |        |          |01H = EADC_CH1.
     * |        |          |02H = EADC_CH2.
     * |        |          |03H = EADC_CH3.
     * |        |          |04H = EADC_CH4.
     * |        |          |05H = EADC_CH5.
     * |        |          |06H = EADC_CH6.
     * |        |          |07H = EADC_CH7.
     * |        |          |08H = VREF.
     * |[4]     |EXTREN    |EADC External Trigger Rising Edge Enable Bit
     * |        |          |0 = Rising edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Rising edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[5]     |EXTFEN    |EADC External Trigger Falling Edge Enable Bit
     * |        |          |0 = Falling edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Falling edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[7:6]   |TRGDLYDIV |EADC Sample Module Start of Conversion Trigger Delay Clock Divider Selection
     * |        |          |Trigger delay clock frequency:
     * |        |          |00 = EADC_CLK/1.
     * |        |          |01 = EADC_CLK/2.
     * |        |          |10 = EADC_CLK/4.
     * |        |          |11 = EADC_CLK/16.
     * |[15:8]  |TRGDLYCNT |EADC Sample Module Start of Conversion Trigger Delay Time
     * |        |          |Trigger delay time = TRGDLYCNT x EADC_CLK period x n (n=1,2,4,16 from TRGDLYDIV setting).
     * |        |          |Note: If TRGDLYCNT is set to 1, trigger delay time is actually the same as TRGDLYCNT is set to 2 for hardware operation.
     * |[21:16] |TRGSEL    |EADC Sample Module Start of Conversion Trigger Source Selection
     * |        |          |0H = Disable trigger.
     * |        |          |1H = EADC ADINT0 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |2H = EADC ADINT1 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |3H = Timer0 overflow pulse trigger.
     * |        |          |4H = Timer1 overflow pulse trigger.
     * |        |          |5H = Timer2 overflow pulse trigger.
     * |        |          |6H = Timer3 overflow pulse trigger.
     * |        |          |7H = Timer4 overflow pulse trigger.
     * |        |          |8H = Timer5 overflow pulse trigger.
     * |        |          |9H = BPWM0TG.
     * |        |          |AH = BPWM1TG.
     * |        |          |other = Reserved.
     * |[22]    |INTPOS    |Interrupt Flag Position Select
     * |        |          |0 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC end of conversion.
     * |        |          |1 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC start of conversion.
     * |[23]    |DBMEN     |Double Buffer Mode Enable Bit
     * |        |          |0 = Sample has one sample result register (default).
     * |        |          |1 = Sample has two sample result registers.
     * |[31:24] |EXTSMPT   |EADC Sampling Time Extend
     * |        |          |When EADC converting at high conversion rate, the sampling time of analog input voltage may not be enough if input channel loading is heavy, and software can extend EADC sampling time after trigger source is coming to get enough sampling time.
     * |        |          |Extended Sampling Time = (EXTSMPT + 1) x EADC_CLK period.
     * @var EADC_T::SCTL3
     * Offset: 0x8C  EADC Sample Module 3 Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |CHSEL     |EADC Sample Module Channel Selection
     * |        |          |00H = EADC_CH0.
     * |        |          |01H = EADC_CH1.
     * |        |          |02H = EADC_CH2.
     * |        |          |03H = EADC_CH3.
     * |        |          |04H = EADC_CH4.
     * |        |          |05H = EADC_CH5.
     * |        |          |06H = EADC_CH6.
     * |        |          |07H = EADC_CH7.
     * |        |          |08H = VREF.
     * |[4]     |EXTREN    |EADC External Trigger Rising Edge Enable Bit
     * |        |          |0 = Rising edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Rising edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[5]     |EXTFEN    |EADC External Trigger Falling Edge Enable Bit
     * |        |          |0 = Falling edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Falling edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[7:6]   |TRGDLYDIV |EADC Sample Module Start of Conversion Trigger Delay Clock Divider Selection
     * |        |          |Trigger delay clock frequency:
     * |        |          |00 = EADC_CLK/1.
     * |        |          |01 = EADC_CLK/2.
     * |        |          |10 = EADC_CLK/4.
     * |        |          |11 = EADC_CLK/16.
     * |[15:8]  |TRGDLYCNT |EADC Sample Module Start of Conversion Trigger Delay Time
     * |        |          |Trigger delay time = TRGDLYCNT x EADC_CLK period x n (n=1,2,4,16 from TRGDLYDIV setting).
     * |        |          |Note: If TRGDLYCNT is set to 1, trigger delay time is actually the same as TRGDLYCNT is set to 2 for hardware operation.
     * |[21:16] |TRGSEL    |EADC Sample Module Start of Conversion Trigger Source Selection
     * |        |          |0H = Disable trigger.
     * |        |          |1H = EADC ADINT0 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |2H = EADC ADINT1 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |3H = Timer0 overflow pulse trigger.
     * |        |          |4H = Timer1 overflow pulse trigger.
     * |        |          |5H = Timer2 overflow pulse trigger.
     * |        |          |6H = Timer3 overflow pulse trigger.
     * |        |          |7H = Timer4 overflow pulse trigger.
     * |        |          |8H = Timer5 overflow pulse trigger.
     * |        |          |9H = BPWM0TG.
     * |        |          |AH = BPWM1TG.
     * |        |          |other = Reserved.
     * |[22]    |INTPOS    |Interrupt Flag Position Select
     * |        |          |0 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC end of conversion.
     * |        |          |1 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC start of conversion.
     * |[23]    |DBMEN     |Double Buffer Mode Enable Bit
     * |        |          |0 = Sample has one sample result register (default).
     * |        |          |1 = Sample has two sample result registers.
     * |[31:24] |EXTSMPT   |EADC Sampling Time Extend
     * |        |          |When EADC converting at high conversion rate, the sampling time of analog input voltage may not be enough if input channel loading is heavy, and software can extend EADC sampling time after trigger source is coming to get enough sampling time.
     * |        |          |Extended Sampling Time = (EXTSMPT + 1) x EADC_CLK period.
     * @var EADC_T::SCTL4
     * Offset: 0x90  EADC Sample Module 4 Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |CHSEL     |EADC Sample Module Channel Selection
     * |        |          |00H = EADC_CH0.
     * |        |          |01H = EADC_CH1.
     * |        |          |02H = EADC_CH2..
     * |        |          |03H = EADC_CH3.
     * |        |          |04H = EADC_CH4.
     * |        |          |05H = EADC_CH5.
     * |        |          |06H = EADC_CH6.
     * |        |          |07H = EADC_CH7.
     * |        |          |08H = VREF.
     * |[4]     |EXTREN    |EADC External Trigger Rising Edge Enable Bit
     * |        |          |0 = Rising edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Rising edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[5]     |EXTFEN    |EADC External Trigger Falling Edge Enable Bit
     * |        |          |0 = Falling edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Falling edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[7:6]   |TRGDLYDIV |EADC Sample Module Start of Conversion Trigger Delay Clock Divider Selection
     * |        |          |Trigger delay clock frequency:
     * |        |          |00 = EADC_CLK/1.
     * |        |          |01 = EADC_CLK/2.
     * |        |          |10 = EADC_CLK/4.
     * |        |          |11 = EADC_CLK/16.
     * |[15:8]  |TRGDLYCNT |EADC Sample Module Start of Conversion Trigger Delay Time
     * |        |          |Trigger delay time = TRGDLYCNT x EADC_CLK period x n (n=1,2,4,16 from TRGDLYDIV setting).
     * |        |          |Note: If TRGDLYCNT is set to 1, trigger delay time is actually the same as TRGDLYCNT is set to 2 for hardware operation.
     * |[21:16] |TRGSEL    |EADC Sample Module Start of Conversion Trigger Source Selection
     * |        |          |0H = Disable trigger.
     * |        |          |1H = EADC ADINT0 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |2H = EADC ADINT1 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |3H = Timer0 overflow pulse trigger.
     * |        |          |4H = Timer1 overflow pulse trigger.
     * |        |          |5H = Timer2 overflow pulse trigger.
     * |        |          |6H = Timer3 overflow pulse trigger.
     * |        |          |7H = Timer4 overflow pulse trigger.
     * |        |          |8H = Timer5 overflow pulse trigger.
     * |        |          |9H = BPWM0TG.
     * |        |          |AH = BPWM1TG.
     * |        |          |other = Reserved.
     * |[22]    |INTPOS    |Interrupt Flag Position Select
     * |        |          |0 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC end of conversion.
     * |        |          |1 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC start of conversion.
     * |[31:24] |EXTSMPT   |EADC Sampling Time Extend
     * |        |          |When EADC converting at high conversion rate, the sampling time of analog input voltage may not be enough if input channel loading is heavy, and software can extend EADC sampling time after trigger source is coming to get enough sampling time.
     * |        |          |Extended Sampling Time = (EXTSMPT + 1) x EADC_CLK period.
     * @var EADC_T::SCTL5
     * Offset: 0x94  EADC Sample Module 5 Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |CHSEL     |EADC Sample Module Channel Selection
     * |        |          |00H = EADC_CH0.
     * |        |          |01H = EADC_CH1.
     * |        |          |02H = EADC_CH2..
     * |        |          |03H = EADC_CH3.
     * |        |          |04H = EADC_CH4.
     * |        |          |05H = EADC_CH5.
     * |        |          |06H = EADC_CH6.
     * |        |          |07H = EADC_CH7.
     * |        |          |08H = VREF.
     * |[4]     |EXTREN    |EADC External Trigger Rising Edge Enable Bit
     * |        |          |0 = Rising edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Rising edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[5]     |EXTFEN    |EADC External Trigger Falling Edge Enable Bit
     * |        |          |0 = Falling edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Falling edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[7:6]   |TRGDLYDIV |EADC Sample Module Start of Conversion Trigger Delay Clock Divider Selection
     * |        |          |Trigger delay clock frequency:
     * |        |          |00 = EADC_CLK/1.
     * |        |          |01 = EADC_CLK/2.
     * |        |          |10 = EADC_CLK/4.
     * |        |          |11 = EADC_CLK/16.
     * |[15:8]  |TRGDLYCNT |EADC Sample Module Start of Conversion Trigger Delay Time
     * |        |          |Trigger delay time = TRGDLYCNT x EADC_CLK period x n (n=1,2,4,16 from TRGDLYDIV setting).
     * |        |          |Note: If TRGDLYCNT is set to 1, trigger delay time is actually the same as TRGDLYCNT is set to 2 for hardware operation.
     * |[21:16] |TRGSEL    |EADC Sample Module Start of Conversion Trigger Source Selection
     * |        |          |0H = Disable trigger.
     * |        |          |1H = EADC ADINT0 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |2H = EADC ADINT1 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |3H = Timer0 overflow pulse trigger.
     * |        |          |4H = Timer1 overflow pulse trigger.
     * |        |          |5H = Timer2 overflow pulse trigger.
     * |        |          |6H = Timer3 overflow pulse trigger.
     * |        |          |7H = Timer4 overflow pulse trigger.
     * |        |          |8H = Timer5 overflow pulse trigger.
     * |        |          |9H = BPWM0TG.
     * |        |          |AH = BPWM1TG.
     * |        |          |other = Reserved.
     * |[22]    |INTPOS    |Interrupt Flag Position Select
     * |        |          |0 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC end of conversion.
     * |        |          |1 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC start of conversion.
     * |[31:24] |EXTSMPT   |EADC Sampling Time Extend
     * |        |          |When EADC converting at high conversion rate, the sampling time of analog input voltage may not be enough if input channel loading is heavy, and software can extend EADC sampling time after trigger source is coming to get enough sampling time.
     * |        |          |Extended Sampling Time = (EXTSMPT + 1) x EADC_CLK period.
     * @var EADC_T::SCTL6
     * Offset: 0x98  EADC Sample Module 6 Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |CHSEL     |EADC Sample Module Channel Selection
     * |        |          |00H = EADC_CH0.
     * |        |          |01H = EADC_CH1.
     * |        |          |02H = EADC_CH2..
     * |        |          |03H = EADC_CH3.
     * |        |          |04H = EADC_CH4.
     * |        |          |05H = EADC_CH5.
     * |        |          |06H = EADC_CH6.
     * |        |          |07H = EADC_CH7.
     * |        |          |08H = VREF.
     * |[4]     |EXTREN    |EADC External Trigger Rising Edge Enable Bit
     * |        |          |0 = Rising edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Rising edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[5]     |EXTFEN    |EADC External Trigger Falling Edge Enable Bit
     * |        |          |0 = Falling edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Falling edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[7:6]   |TRGDLYDIV |EADC Sample Module Start of Conversion Trigger Delay Clock Divider Selection
     * |        |          |Trigger delay clock frequency:
     * |        |          |00 = EADC_CLK/1.
     * |        |          |01 = EADC_CLK/2.
     * |        |          |10 = EADC_CLK/4.
     * |        |          |11 = EADC_CLK/16.
     * |[15:8]  |TRGDLYCNT |EADC Sample Module Start of Conversion Trigger Delay Time
     * |        |          |Trigger delay time = TRGDLYCNT x EADC_CLK period x n (n=1,2,4,16 from TRGDLYDIV setting).
     * |        |          |Note: If TRGDLYCNT is set to 1, trigger delay time is actually the same as TRGDLYCNT is set to 2 for hardware operation.
     * |[21:16] |TRGSEL    |EADC Sample Module Start of Conversion Trigger Source Selection
     * |        |          |0H = Disable trigger.
     * |        |          |1H = EADC ADINT0 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |2H = EADC ADINT1 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |3H = Timer0 overflow pulse trigger.
     * |        |          |4H = Timer1 overflow pulse trigger.
     * |        |          |5H = Timer2 overflow pulse trigger.
     * |        |          |6H = Timer3 overflow pulse trigger.
     * |        |          |7H = Timer4 overflow pulse trigger.
     * |        |          |8H = Timer5 overflow pulse trigger.
     * |        |          |9H = BPWM0TG.
     * |        |          |AH = BPWM1TG.
     * |        |          |other = Reserved.
     * |[22]    |INTPOS    |Interrupt Flag Position Select
     * |        |          |0 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC end of conversion.
     * |        |          |1 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC start of conversion.
     * |[31:24] |EXTSMPT   |EADC Sampling Time Extend
     * |        |          |When EADC converting at high conversion rate, the sampling time of analog input voltage may not be enough if input channel loading is heavy, and software can extend EADC sampling time after trigger source is coming to get enough sampling time.
     * |        |          |Extended Sampling Time = (EXTSMPT + 1) x EADC_CLK period.
     * @var EADC_T::SCTL7
     * Offset: 0x9C  EADC Sample Module 7 Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |CHSEL     |EADC Sample Module Channel Selection
     * |        |          |00H = EADC_CH0.
     * |        |          |01H = EADC_CH1.
     * |        |          |02H = EADC_CH2..
     * |        |          |03H = EADC_CH3.
     * |        |          |04H = EADC_CH4.
     * |        |          |05H = EADC_CH5.
     * |        |          |06H = EADC_CH6.
     * |        |          |07H = EADC_CH7.
     * |        |          |08H = VREF.
     * |[4]     |EXTREN    |EADC External Trigger Rising Edge Enable Bit
     * |        |          |0 = Rising edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Rising edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[5]     |EXTFEN    |EADC External Trigger Falling Edge Enable Bit
     * |        |          |0 = Falling edge Disabled when EADC selects EADC0_ST as trigger source.
     * |        |          |1 = Falling edge Enabled when EADC selects EADC0_ST as trigger source.
     * |[7:6]   |TRGDLYDIV |EADC Sample Module Start of Conversion Trigger Delay Clock Divider Selection
     * |        |          |Trigger delay clock frequency:
     * |        |          |00 = EADC_CLK/1.
     * |        |          |01 = EADC_CLK/2.
     * |        |          |10 = EADC_CLK/4.
     * |        |          |11 = EADC_CLK/16.
     * |[15:8]  |TRGDLYCNT |EADC Sample Module Start of Conversion Trigger Delay Time
     * |        |          |Trigger delay time = TRGDLYCNT x EADC_CLK period x n (n=1,2,4,16 from TRGDLYDIV setting).
     * |        |          |Note: If TRGDLYCNT is set to 1, trigger delay time is actually the same as TRGDLYCNT is set to 2 for hardware operation.
     * |[21:16] |TRGSEL    |EADC Sample Module Start of Conversion Trigger Source Selection
     * |        |          |0H = Disable trigger.
     * |        |          |1H = EADC ADINT0 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |2H = EADC ADINT1 interrupt EOC (End of conversion) pulse trigger.
     * |        |          |3H = Timer0 overflow pulse trigger.
     * |        |          |4H = Timer1 overflow pulse trigger.
     * |        |          |5H = Timer2 overflow pulse trigger.
     * |        |          |6H = Timer3 overflow pulse trigger.
     * |        |          |7H = Timer4 overflow pulse trigger.
     * |        |          |8H = Timer5 overflow pulse trigger.
     * |        |          |9H = BPWM0TG.
     * |        |          |AH = BPWM1TG.
     * |        |          |other = Reserved.
     * |[22]    |INTPOS    |Interrupt Flag Position Select
     * |        |          |0 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC end of conversion.
     * |        |          |1 = Set ADIFn (EADC_STATUS2[n], n=0~3) at EADC start of conversion.
     * |[31:24] |EXTSMPT   |EADC Sampling Time Extend
     * |        |          |When EADC converting at high conversion rate, the sampling time of analog input voltage may not be enough if input channel loading is heavy, and software can extend EADC sampling time after trigger source is coming to get enough sampling time.
     * |        |          |Extended Sampling Time = (EXTSMPT + 1) x EADC_CLK period.
     * @var EADC_T::SCTL8
     * Offset: 0xA0  EADC Sample Module 8 Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:24] |EXTSMPT   |EADC Sampling Time Extend
     * |        |          |When EADC converting at high conversion rate, the sampling time of analog input voltage may not be enough if input channel loading is heavy, and software can extend EADC sampling time after trigger source is coming to get enough sampling time.
     * |        |          |Extended Sampling Time = (EXTSMPT + 1) x EADC_CLK period.
     * @var EADC_T::INTSRC0
     * Offset: 0xD0  EADC Interrupt 0 Source Enable Control Register.
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |SPLIE0    |Sample Module 0 Interrupt Enable Bit
     * |        |          |0 = Sample Module 0 interrupt Disabled.
     * |        |          |1 = Sample Module 0 interrupt Enabled.
     * |[1]     |SPLIE1    |Sample Module 1 Interrupt Enable Bit
     * |        |          |0 = Sample Module 1 interrupt Disabled.
     * |        |          |1 = Sample Module 1 interrupt Enabled.
     * |[2]     |SPLIE2    |Sample Module 2 Interrupt Enable Bit
     * |        |          |0 = Sample Module 2 interrupt Disabled.
     * |        |          |1 = Sample Module 2 interrupt Enabled.
     * |[3]     |SPLIE3    |Sample Module 3 Interrupt Enable Bit
     * |        |          |0 = Sample Module 3 interrupt Disabled.
     * |        |          |1 = Sample Module 3 interrupt Enabled.
     * |[4]     |SPLIE4    |Sample Module 4 Interrupt Enable Bit
     * |        |          |0 = Sample Module 4 interrupt Disabled.
     * |        |          |1 = Sample Module 4 interrupt Enabled.
     * |[5]     |SPLIE5    |Sample Module 5 Interrupt Enable Bit
     * |        |          |0 = Sample Module 5 interrupt Disabled.
     * |        |          |1 = Sample Module 5 interrupt Enabled.
     * |[6]     |SPLIE6    |Sample Module 6 Interrupt Enable Bit
     * |        |          |0 = Sample Module 6 interrupt Disabled.
     * |        |          |1 = Sample Module 6 interrupt Enabled.
     * |[7]     |SPLIE7    |Sample Module 7 Interrupt Enable Bit
     * |        |          |0 = Sample Module 7 interrupt Disabled.
     * |        |          |1 = Sample Module 7 interrupt Enabled.
     * |[8]     |SPLIE8    |Sample Module 8 Interrupt Enable Bit
     * |        |          |0 = Sample Module 8 interrupt Disabled.
     * |        |          |1 = Sample Module 8 interrupt Enabled.
     * |[9]     |SPLIE9    |Sample Module 9 Interrupt Enable Bit
     * |        |          |0 = Sample Module 9 interrupt Disabled.
     * |        |          |1 = Sample Module 9 interrupt Enabled.
     * |[10]    |SPLIE10   |Sample Module 10 Interrupt Enable Bit
     * |        |          |0 = Sample Module 10 interrupt Disabled.
     * |        |          |1 = Sample Module 10 interrupt Enabled.
     * |[11]    |SPLIE11   |Sample Module 11 Interrupt Enable Bit
     * |        |          |0 = Sample Module 11 interrupt Disabled.
     * |        |          |1 = Sample Module 11 interrupt Enabled.
     * |[12]    |SPLIE12   |Sample Module 12 Interrupt Enable Bit
     * |        |          |0 = Sample Module 12 interrupt Disabled.
     * |        |          |1 = Sample Module 12 interrupt Enabled.
     * |[13]    |SPLIE13   |Sample Module 13 Interrupt Enable Bit
     * |        |          |0 = Sample Module 13 interrupt Disabled.
     * |        |          |1 = Sample Module 13 interrupt Enabled.
     * |[14]    |SPLIE14   |Sample Module 14 Interrupt Enable Bit
     * |        |          |0 = Sample Module 14 interrupt Disabled.
     * |        |          |1 = Sample Module 14 interrupt Enabled.
     * |[15]    |SPLIE15   |Sample Module 15 Interrupt Enable Bit
     * |        |          |0 = Sample Module 15 interrupt Disabled.
     * |        |          |1 = Sample Module 15 interrupt Enabled.
     * |[16]    |SPLIE16   |Sample Module 16 Interrupt Enable Bit
     * |        |          |0 = Sample Module 16 interrupt Disabled.
     * |        |          |1 = Sample Module 16 interrupt Enabled.
     * |[17]    |SPLIE17   |Sample Module 17 Interrupt Enable Bit
     * |        |          |0 = Sample Module 17 interrupt Disabled.
     * |        |          |1 = Sample Module 17 interrupt Enabled.
     * |[18]    |SPLIE18   |Sample Module 18 Interrupt Enable Bit
     * |        |          |0 = Sample Module 18 interrupt Disabled.
     * |        |          |1 = Sample Module 18 interrupt Enabled.
     * @var EADC_T::INTSRC1
     * Offset: 0xD4  EADC Interrupt 1 Source Enable Control Register.
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |SPLIE0    |Sample Module 0 Interrupt Enable Bit
     * |        |          |0 = Sample Module 0 interrupt Disabled.
     * |        |          |1 = Sample Module 0 interrupt Enabled.
     * |[1]     |SPLIE1    |Sample Module 1 Interrupt Enable Bit
     * |        |          |0 = Sample Module 1 interrupt Disabled.
     * |        |          |1 = Sample Module 1 interrupt Enabled.
     * |[2]     |SPLIE2    |Sample Module 2 Interrupt Enable Bit
     * |        |          |0 = Sample Module 2 interrupt Disabled.
     * |        |          |1 = Sample Module 2 interrupt Enabled.
     * |[3]     |SPLIE3    |Sample Module 3 Interrupt Enable Bit
     * |        |          |0 = Sample Module 3 interrupt Disabled.
     * |        |          |1 = Sample Module 3 interrupt Enabled.
     * |[4]     |SPLIE4    |Sample Module 4 Interrupt Enable Bit
     * |        |          |0 = Sample Module 4 interrupt Disabled.
     * |        |          |1 = Sample Module 4 interrupt Enabled.
     * |[5]     |SPLIE5    |Sample Module 5 Interrupt Enable Bit
     * |        |          |0 = Sample Module 5 interrupt Disabled.
     * |        |          |1 = Sample Module 5 interrupt Enabled.
     * |[6]     |SPLIE6    |Sample Module 6 Interrupt Enable Bit
     * |        |          |0 = Sample Module 6 interrupt Disabled.
     * |        |          |1 = Sample Module 6 interrupt Enabled.
     * |[7]     |SPLIE7    |Sample Module 7 Interrupt Enable Bit
     * |        |          |0 = Sample Module 7 interrupt Disabled.
     * |        |          |1 = Sample Module 7 interrupt Enabled.
     * |[8]     |SPLIE8    |Sample Module 8 Interrupt Enable Bit
     * |        |          |0 = Sample Module 8 interrupt Disabled.
     * |        |          |1 = Sample Module 8 interrupt Enabled.
     * |[9]     |SPLIE9    |Sample Module 9 Interrupt Enable Bit
     * |        |          |0 = Sample Module 9 interrupt Disabled.
     * |        |          |1 = Sample Module 9 interrupt Enabled.
     * |[10]    |SPLIE10   |Sample Module 10 Interrupt Enable Bit
     * |        |          |0 = Sample Module 10 interrupt Disabled.
     * |        |          |1 = Sample Module 10 interrupt Enabled.
     * |[11]    |SPLIE11   |Sample Module 11 Interrupt Enable Bit
     * |        |          |0 = Sample Module 11 interrupt Disabled.
     * |        |          |1 = Sample Module 11 interrupt Enabled.
     * |[12]    |SPLIE12   |Sample Module 12 Interrupt Enable Bit
     * |        |          |0 = Sample Module 12 interrupt Disabled.
     * |        |          |1 = Sample Module 12 interrupt Enabled.
     * |[13]    |SPLIE13   |Sample Module 13 Interrupt Enable Bit
     * |        |          |0 = Sample Module 13 interrupt Disabled.
     * |        |          |1 = Sample Module 13 interrupt Enabled.
     * |[14]    |SPLIE14   |Sample Module 14 Interrupt Enable Bit
     * |        |          |0 = Sample Module 14 interrupt Disabled.
     * |        |          |1 = Sample Module 14 interrupt Enabled.
     * |[15]    |SPLIE15   |Sample Module 15 Interrupt Enable Bit
     * |        |          |0 = Sample Module 15 interrupt Disabled.
     * |        |          |1 = Sample Module 15 interrupt Enabled.
     * |[16]    |SPLIE16   |Sample Module 16 Interrupt Enable Bit
     * |        |          |0 = Sample Module 16 interrupt Disabled.
     * |        |          |1 = Sample Module 16 interrupt Enabled.
     * |[17]    |SPLIE17   |Sample Module 17 Interrupt Enable Bit
     * |        |          |0 = Sample Module 17 interrupt Disabled.
     * |        |          |1 = Sample Module 17 interrupt Enabled.
     * |[18]    |SPLIE18   |Sample Module 18 Interrupt Enable Bit
     * |        |          |0 = Sample Module 18 interrupt Disabled.
     * |        |          |1 = Sample Module 18 interrupt Enabled.
     * @var EADC_T::INTSRC2
     * Offset: 0xD8  EADC Interrupt 2 Source Enable Control Register.
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |SPLIE0    |Sample Module 0 Interrupt Enable Bit
     * |        |          |0 = Sample Module 0 interrupt Disabled.
     * |        |          |1 = Sample Module 0 interrupt Enabled.
     * |[1]     |SPLIE1    |Sample Module 1 Interrupt Enable Bit
     * |        |          |0 = Sample Module 1 interrupt Disabled.
     * |        |          |1 = Sample Module 1 interrupt Enabled.
     * |[2]     |SPLIE2    |Sample Module 2 Interrupt Enable Bit
     * |        |          |0 = Sample Module 2 interrupt Disabled.
     * |        |          |1 = Sample Module 2 interrupt Enabled.
     * |[3]     |SPLIE3    |Sample Module 3 Interrupt Enable Bit
     * |        |          |0 = Sample Module 3 interrupt Disabled.
     * |        |          |1 = Sample Module 3 interrupt Enabled.
     * |[4]     |SPLIE4    |Sample Module 4 Interrupt Enable Bit
     * |        |          |0 = Sample Module 4 interrupt Disabled.
     * |        |          |1 = Sample Module 4 interrupt Enabled.
     * |[5]     |SPLIE5    |Sample Module 5 Interrupt Enable Bit
     * |        |          |0 = Sample Module 5 interrupt Disabled.
     * |        |          |1 = Sample Module 5 interrupt Enabled.
     * |[6]     |SPLIE6    |Sample Module 6 Interrupt Enable Bit
     * |        |          |0 = Sample Module 6 interrupt Disabled.
     * |        |          |1 = Sample Module 6 interrupt Enabled.
     * |[7]     |SPLIE7    |Sample Module 7 Interrupt Enable Bit
     * |        |          |0 = Sample Module 7 interrupt Disabled.
     * |        |          |1 = Sample Module 7 interrupt Enabled.
     * |[8]     |SPLIE8    |Sample Module 8 Interrupt Enable Bit
     * |        |          |0 = Sample Module 8 interrupt Disabled.
     * |        |          |1 = Sample Module 8 interrupt Enabled.
     * |[9]     |SPLIE9    |Sample Module 9 Interrupt Enable Bit
     * |        |          |0 = Sample Module 9 interrupt Disabled.
     * |        |          |1 = Sample Module 9 interrupt Enabled.
     * |[10]    |SPLIE10   |Sample Module 10 Interrupt Enable Bit
     * |        |          |0 = Sample Module 10 interrupt Disabled.
     * |        |          |1 = Sample Module 10 interrupt Enabled.
     * |[11]    |SPLIE11   |Sample Module 11 Interrupt Enable Bit
     * |        |          |0 = Sample Module 11 interrupt Disabled.
     * |        |          |1 = Sample Module 11 interrupt Enabled.
     * |[12]    |SPLIE12   |Sample Module 12 Interrupt Enable Bit
     * |        |          |0 = Sample Module 12 interrupt Disabled.
     * |        |          |1 = Sample Module 12 interrupt Enabled.
     * |[13]    |SPLIE13   |Sample Module 13 Interrupt Enable Bit
     * |        |          |0 = Sample Module 13 interrupt Disabled.
     * |        |          |1 = Sample Module 13 interrupt Enabled.
     * |[14]    |SPLIE14   |Sample Module 14 Interrupt Enable Bit
     * |        |          |0 = Sample Module 14 interrupt Disabled.
     * |        |          |1 = Sample Module 14 interrupt Enabled.
     * |[15]    |SPLIE15   |Sample Module 15 Interrupt Enable Bit
     * |        |          |0 = Sample Module 15 interrupt Disabled.
     * |        |          |1 = Sample Module 15 interrupt Enabled.
     * |[16]    |SPLIE16   |Sample Module 16 Interrupt Enable Bit
     * |        |          |0 = Sample Module 16 interrupt Disabled.
     * |        |          |1 = Sample Module 16 interrupt Enabled.
     * |[17]    |SPLIE17   |Sample Module 17 Interrupt Enable Bit
     * |        |          |0 = Sample Module 17 interrupt Disabled.
     * |        |          |1 = Sample Module 17 interrupt Enabled.
     * |[18]    |SPLIE18   |Sample Module 18 Interrupt Enable Bit
     * |        |          |0 = Sample Module 18 interrupt Disabled.
     * |        |          |1 = Sample Module 18 interrupt Enabled.
     * @var EADC_T::INTSRC3
     * Offset: 0xDC  EADC Interrupt 3 Source Enable Control Register.
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |SPLIE0    |Sample Module 0 Interrupt Enable Bit
     * |        |          |0 = Sample Module 0 interrupt Disabled.
     * |        |          |1 = Sample Module 0 interrupt Enabled.
     * |[1]     |SPLIE1    |Sample Module 1 Interrupt Enable Bit
     * |        |          |0 = Sample Module 1 interrupt Disabled.
     * |        |          |1 = Sample Module 1 interrupt Enabled.
     * |[2]     |SPLIE2    |Sample Module 2 Interrupt Enable Bit
     * |        |          |0 = Sample Module 2 interrupt Disabled.
     * |        |          |1 = Sample Module 2 interrupt Enabled.
     * |[3]     |SPLIE3    |Sample Module 3 Interrupt Enable Bit
     * |        |          |0 = Sample Module 3 interrupt Disabled.
     * |        |          |1 = Sample Module 3 interrupt Enabled.
     * |[4]     |SPLIE4    |Sample Module 4 Interrupt Enable Bit
     * |        |          |0 = Sample Module 4 interrupt Disabled.
     * |        |          |1 = Sample Module 4 interrupt Enabled.
     * |[5]     |SPLIE5    |Sample Module 5 Interrupt Enable Bit
     * |        |          |0 = Sample Module 5 interrupt Disabled.
     * |        |          |1 = Sample Module 5 interrupt Enabled.
     * |[6]     |SPLIE6    |Sample Module 6 Interrupt Enable Bit
     * |        |          |0 = Sample Module 6 interrupt Disabled.
     * |        |          |1 = Sample Module 6 interrupt Enabled.
     * |[7]     |SPLIE7    |Sample Module 7 Interrupt Enable Bit
     * |        |          |0 = Sample Module 7 interrupt Disabled.
     * |        |          |1 = Sample Module 7 interrupt Enabled.
     * |[8]     |SPLIE8    |Sample Module 8 Interrupt Enable Bit
     * |        |          |0 = Sample Module 8 interrupt Disabled.
     * |        |          |1 = Sample Module 8 interrupt Enabled.
     * |[9]     |SPLIE9    |Sample Module 9 Interrupt Enable Bit
     * |        |          |0 = Sample Module 9 interrupt Disabled.
     * |        |          |1 = Sample Module 9 interrupt Enabled.
     * |[10]    |SPLIE10   |Sample Module 10 Interrupt Enable Bit
     * |        |          |0 = Sample Module 10 interrupt Disabled.
     * |        |          |1 = Sample Module 10 interrupt Enabled.
     * |[11]    |SPLIE11   |Sample Module 11 Interrupt Enable Bit
     * |        |          |0 = Sample Module 11 interrupt Disabled.
     * |        |          |1 = Sample Module 11 interrupt Enabled.
     * |[12]    |SPLIE12   |Sample Module 12 Interrupt Enable Bit
     * |        |          |0 = Sample Module 12 interrupt Disabled.
     * |        |          |1 = Sample Module 12 interrupt Enabled.
     * |[13]    |SPLIE13   |Sample Module 13 Interrupt Enable Bit
     * |        |          |0 = Sample Module 13 interrupt Disabled.
     * |        |          |1 = Sample Module 13 interrupt Enabled.
     * |[14]    |SPLIE14   |Sample Module 14 Interrupt Enable Bit
     * |        |          |0 = Sample Module 14 interrupt Disabled.
     * |        |          |1 = Sample Module 14 interrupt Enabled.
     * |[15]    |SPLIE15   |Sample Module 15 Interrupt Enable Bit
     * |        |          |0 = Sample Module 15 interrupt Disabled.
     * |        |          |1 = Sample Module 15 interrupt Enabled.
     * |[16]    |SPLIE16   |Sample Module 16 Interrupt Enable Bit
     * |        |          |0 = Sample Module 16 interrupt Disabled.
     * |        |          |1 = Sample Module 16 interrupt Enabled.
     * |[17]    |SPLIE17   |Sample Module 17 Interrupt Enable Bit
     * |        |          |0 = Sample Module 17 interrupt Disabled.
     * |        |          |1 = Sample Module 17 interrupt Enabled.
     * |[18]    |SPLIE18   |Sample Module 18 Interrupt Enable Bit
     * |        |          |0 = Sample Module 18 interrupt Disabled.
     * |        |          |1 = Sample Module 18 interrupt Enabled.
     * @var EADC_T::CMP0
     * Offset: 0xE0  EADC Result Compare Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |EADCMPEN  |EADC Result Compare Enable Bit
     * |        |          |0 = Compare Disabled.
     * |        |          |1 = Compare Enabled.
     * |        |          |Set this bit to 1 to enable compare CMPDAT (EADC_CMPn[27:16], n=0~3) with specified sample module conversion result when converted data is loaded into EADC_DAT register.
     * |[1]     |EADCMPIE  |EADC Result Compare Interrupt Enable Bit
     * |        |          |0 = Compare function interrupt Disabled.
     * |        |          |1 = Compare function interrupt Enabled.
     * |        |          |If the compare function is enabled and the compare condition matches the setting of CMPCOND (EADC_CMPn[2], n=0~3) and CMPMCNT (EADC_CMPn[11:8], n=0~3), EADCMPFn (EADC_STATUS2[7:4], n=0~3) will be asserted, in the meanwhile, if EADCMPIE is set to 1, a compare interrupt request is generated.
     * |[2]     |CMPCOND   |Compare Condition
     * |        |          |0= Set the compare condition as that when a 12-bit EADC conversion result is less than the 12-bit CMPDAT (EADC_CMPn [27:16]), the internal match counter will increase one.
     * |        |          |1= Set the compare condition as that when a 12-bit EADC conversion result is greater or equal to the 12-bit CMPDAT (EADC_CMPn [27:16]), the internal match counter will increase one.
     * |        |          |Note: When the internal counter reaches the value to (CMPMCNT (EADC_CMPn[11:8], n=0~3) +1), the CMPF bit will be set.
     * |[6:3]   |CMPSPL    |Compare Sample Module Selection
     * |        |          |00000 = Sample Module 0 conversion result EADC_DAT0 is selected to be compared.
     * |        |          |00001 = Sample Module 1 conversion result EADC_DAT1 is selected to be compared.
     * |        |          |00010 = Sample Module 2 conversion result EADC_DAT2 is selected to be compared.
     * |        |          |00011 = Sample Module 3 conversion result EADC_DAT3 is selected to be compared.
     * |        |          |00100 = Sample Module 4 conversion result EADC_DAT4 is selected to be compared.
     * |        |          |00101 = Sample Module 5 conversion result EADC_DAT5 is selected to be compared.
     * |        |          |00110 = Sample Module 6 conversion result EADC_DAT6 is selected to be compared.
     * |        |          |00111 = Sample Module 7 conversion result EADC_DAT7 is selected to be compared.
     * |        |          |01000 = Sample Module 8 conversion result EADC_DAT8 is selected to be compared.
     * |        |          |01001 = Sample Module 9 conversion result EADC_DAT9 is selected to be compared.
     * |        |          |01010 = Sample Module 10 conversion result EADC_DAT10 is selected to be compared.
     * |        |          |01011 = Sample Module 11 conversion result EADC_DAT11 is selected to be compared.
     * |        |          |01100 = Sample Module 12 conversion result EADC_DAT12 is selected to be compared.
     * |        |          |01101 = Sample Module 13 conversion result EADC_DAT13 is selected to be compared.
     * |        |          |01110 = Sample Module 14 conversion result EADC_DAT14 is selected to be compared.
     * |        |          |01111 = Sample Module 15 conversion result EADC_DAT15 is selected to be compared.
     * |        |          |10000 = Sample Module 16 conversion result EADC_DAT16 is selected to be compared.
     * |        |          |10001 = Sample Module 17 conversion result EADC_DAT17 is selected to be compared.
     * |        |          |10010 = Sample Module 18 conversion result EADC_DAT18 is selected to be compared.
     * |[11:8]  |CMPMCNT   |Compare Match Count
     * |        |          |When the specified EADC sample module analog conversion result matches the compare condition defined by CMPCOND (EADC_CMPn[2], n=0~3), the internal match counter will increase 1
     * |        |          |If the compare result does not meet the compare condition, the internal compare match counter will reset to 0
     * |        |          |When the internal counter reaches the value to (CMPMCNT +1), the EADCMPFn (EADC_STATUS2[7:4], n=0~3) will be set.
     * |[15]    |CMPWEN    |Compare Window Mode Enable Bit
     * |        |          |0 = EADCMPF0 (EADC_STATUS2[4]) will be set when EADC_CMP0 compared condition matched
     * |        |          |EADCMPF2 (EADC_STATUS2[6]) will be set when EADC_CMP2 compared condition matched
     * |        |          |1 = EADCMPF0 (EADC_STATUS2[4]) will be set when both EADC_CMP0 and EADC_CMP1 compared condition matched
     * |        |          |EADCMPF2 (EADC_STATUS2[6]) will be set when both EADC_CMP2 and EADC_CMP3 compared condition matched.
     * |        |          |Note: This bit is only present in EADC_CMP0 and EADC_CMP2 register.
     * |[31:16] |CMPDAT    |Comparison Data
     * |        |          |Except for the oversampling mode, the comparison data CMPDAT (EADC_CMPn[27:16], n=0~3) is 12 bits
     * |        |          |This 12 bits data is used to compare with conversion result of specified sample module
     * |        |          |User can use it to monitor the external analog input pin voltage transition without imposing a load on software.
     * |        |          |In oversampling mode, the width of comparison data CMPDAT (EADC_CMPn[31:16], n=0~3) can reach 16 bits.
     * |        |          |Note: The EADC_CMPn[31:28] (n=0~3) is only workable in oversampling mode.
     * @var EADC_T::CMP1
     * Offset: 0xE4  EADC Result Compare Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |EADCMPEN  |EADC Result Compare Enable Bit
     * |        |          |0 = Compare Disabled.
     * |        |          |1 = Compare Enabled.
     * |        |          |Set this bit to 1 to enable compare CMPDAT (EADC_CMPn[27:16], n=0~3) with specified sample module conversion result when converted data is loaded into EADC_DAT register.
     * |[1]     |EADCMPIE  |EADC Result Compare Interrupt Enable Bit
     * |        |          |0 = Compare function interrupt Disabled.
     * |        |          |1 = Compare function interrupt Enabled.
     * |        |          |If the compare function is enabled and the compare condition matches the setting of CMPCOND (EADC_CMPn[2], n=0~3) and CMPMCNT (EADC_CMPn[11:8], n=0~3), EADCMPFn (EADC_STATUS2[7:4], n=0~3) will be asserted, in the meanwhile, if EADCMPIE is set to 1, a compare interrupt request is generated.
     * |[2]     |CMPCOND   |Compare Condition
     * |        |          |0= Set the compare condition as that when a 12-bit EADC conversion result is less than the 12-bit CMPDAT (EADC_CMPn [27:16]), the internal match counter will increase one.
     * |        |          |1= Set the compare condition as that when a 12-bit EADC conversion result is greater or equal to the 12-bit CMPDAT (EADC_CMPn [27:16]), the internal match counter will increase one.
     * |        |          |Note: When the internal counter reaches the value to (CMPMCNT (EADC_CMPn[11:8], n=0~3) +1), the CMPF bit will be set.
     * |[6:3]   |CMPSPL    |Compare Sample Module Selection
     * |        |          |00000 = Sample Module 0 conversion result EADC_DAT0 is selected to be compared.
     * |        |          |00001 = Sample Module 1 conversion result EADC_DAT1 is selected to be compared.
     * |        |          |00010 = Sample Module 2 conversion result EADC_DAT2 is selected to be compared.
     * |        |          |00011 = Sample Module 3 conversion result EADC_DAT3 is selected to be compared.
     * |        |          |00100 = Sample Module 4 conversion result EADC_DAT4 is selected to be compared.
     * |        |          |00101 = Sample Module 5 conversion result EADC_DAT5 is selected to be compared.
     * |        |          |00110 = Sample Module 6 conversion result EADC_DAT6 is selected to be compared.
     * |        |          |00111 = Sample Module 7 conversion result EADC_DAT7 is selected to be compared.
     * |        |          |01000 = Sample Module 8 conversion result EADC_DAT8 is selected to be compared.
     * |        |          |01001 = Sample Module 9 conversion result EADC_DAT9 is selected to be compared.
     * |        |          |01010 = Sample Module 10 conversion result EADC_DAT10 is selected to be compared.
     * |        |          |01011 = Sample Module 11 conversion result EADC_DAT11 is selected to be compared.
     * |        |          |01100 = Sample Module 12 conversion result EADC_DAT12 is selected to be compared.
     * |        |          |01101 = Sample Module 13 conversion result EADC_DAT13 is selected to be compared.
     * |        |          |01110 = Sample Module 14 conversion result EADC_DAT14 is selected to be compared.
     * |        |          |01111 = Sample Module 15 conversion result EADC_DAT15 is selected to be compared.
     * |        |          |10000 = Sample Module 16 conversion result EADC_DAT16 is selected to be compared.
     * |        |          |10001 = Sample Module 17 conversion result EADC_DAT17 is selected to be compared.
     * |        |          |10010 = Sample Module 18 conversion result EADC_DAT18 is selected to be compared.
     * |[11:8]  |CMPMCNT   |Compare Match Count
     * |        |          |When the specified EADC sample module analog conversion result matches the compare condition defined by CMPCOND (EADC_CMPn[2], n=0~3), the internal match counter will increase 1
     * |        |          |If the compare result does not meet the compare condition, the internal compare match counter will reset to 0
     * |        |          |When the internal counter reaches the value to (CMPMCNT +1), the EADCMPFn (EADC_STATUS2[7:4], n=0~3) will be set.
     * |[15]    |CMPWEN    |Compare Window Mode Enable Bit
     * |        |          |0 = EADCMPF0 (EADC_STATUS2[4]) will be set when EADC_CMP0 compared condition matched
     * |        |          |EADCMPF2 (EADC_STATUS2[6]) will be set when EADC_CMP2 compared condition matched
     * |        |          |1 = EADCMPF0 (EADC_STATUS2[4]) will be set when both EADC_CMP0 and EADC_CMP1 compared condition matched
     * |        |          |EADCMPF2 (EADC_STATUS2[6]) will be set when both EADC_CMP2 and EADC_CMP3 compared condition matched.
     * |        |          |Note: This bit is only present in EADC_CMP0 and EADC_CMP2 register.
     * |[31:16] |CMPDAT    |Comparison Data
     * |        |          |Except for the oversampling mode, the comparison data CMPDAT (EADC_CMPn[27:16], n=0~3) is 12 bits
     * |        |          |This 12 bits data is used to compare with conversion result of specified sample module
     * |        |          |User can use it to monitor the external analog input pin voltage transition without imposing a load on software.
     * |        |          |In oversampling mode, the width of comparison data CMPDAT (EADC_CMPn[31:16], n=0~3) can reach 16 bits.
     * |        |          |Note: The EADC_CMPn[31:28] (n=0~3) is only workable in oversampling mode.
     * @var EADC_T::CMP2
     * Offset: 0xE8  EADC Result Compare Register 2
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |EADCMPEN  |EADC Result Compare Enable Bit
     * |        |          |0 = Compare Disabled.
     * |        |          |1 = Compare Enabled.
     * |        |          |Set this bit to 1 to enable compare CMPDAT (EADC_CMPn[27:16], n=0~3) with specified sample module conversion result when converted data is loaded into EADC_DAT register.
     * |[1]     |EADCMPIE  |EADC Result Compare Interrupt Enable Bit
     * |        |          |0 = Compare function interrupt Disabled.
     * |        |          |1 = Compare function interrupt Enabled.
     * |        |          |If the compare function is enabled and the compare condition matches the setting of CMPCOND (EADC_CMPn[2], n=0~3) and CMPMCNT (EADC_CMPn[11:8], n=0~3), EADCMPFn (EADC_STATUS2[7:4], n=0~3) will be asserted, in the meanwhile, if EADCMPIE is set to 1, a compare interrupt request is generated.
     * |[2]     |CMPCOND   |Compare Condition
     * |        |          |0= Set the compare condition as that when a 12-bit EADC conversion result is less than the 12-bit CMPDAT (EADC_CMPn [27:16]), the internal match counter will increase one.
     * |        |          |1= Set the compare condition as that when a 12-bit EADC conversion result is greater or equal to the 12-bit CMPDAT (EADC_CMPn [27:16]), the internal match counter will increase one.
     * |        |          |Note: When the internal counter reaches the value to (CMPMCNT (EADC_CMPn[11:8], n=0~3) +1), the CMPF bit will be set.
     * |[6:3]   |CMPSPL    |Compare Sample Module Selection
     * |        |          |00000 = Sample Module 0 conversion result EADC_DAT0 is selected to be compared.
     * |        |          |00001 = Sample Module 1 conversion result EADC_DAT1 is selected to be compared.
     * |        |          |00010 = Sample Module 2 conversion result EADC_DAT2 is selected to be compared.
     * |        |          |00011 = Sample Module 3 conversion result EADC_DAT3 is selected to be compared.
     * |        |          |00100 = Sample Module 4 conversion result EADC_DAT4 is selected to be compared.
     * |        |          |00101 = Sample Module 5 conversion result EADC_DAT5 is selected to be compared.
     * |        |          |00110 = Sample Module 6 conversion result EADC_DAT6 is selected to be compared.
     * |        |          |00111 = Sample Module 7 conversion result EADC_DAT7 is selected to be compared.
     * |        |          |01000 = Sample Module 8 conversion result EADC_DAT8 is selected to be compared.
     * |        |          |01001 = Sample Module 9 conversion result EADC_DAT9 is selected to be compared.
     * |        |          |01010 = Sample Module 10 conversion result EADC_DAT10 is selected to be compared.
     * |        |          |01011 = Sample Module 11 conversion result EADC_DAT11 is selected to be compared.
     * |        |          |01100 = Sample Module 12 conversion result EADC_DAT12 is selected to be compared.
     * |        |          |01101 = Sample Module 13 conversion result EADC_DAT13 is selected to be compared.
     * |        |          |01110 = Sample Module 14 conversion result EADC_DAT14 is selected to be compared.
     * |        |          |01111 = Sample Module 15 conversion result EADC_DAT15 is selected to be compared.
     * |        |          |10000 = Sample Module 16 conversion result EADC_DAT16 is selected to be compared.
     * |        |          |10001 = Sample Module 17 conversion result EADC_DAT17 is selected to be compared.
     * |        |          |10010 = Sample Module 18 conversion result EADC_DAT18 is selected to be compared.
     * |[11:8]  |CMPMCNT   |Compare Match Count
     * |        |          |When the specified EADC sample module analog conversion result matches the compare condition defined by CMPCOND (EADC_CMPn[2], n=0~3), the internal match counter will increase 1
     * |        |          |If the compare result does not meet the compare condition, the internal compare match counter will reset to 0
     * |        |          |When the internal counter reaches the value to (CMPMCNT +1), the EADCMPFn (EADC_STATUS2[7:4], n=0~3) will be set.
     * |[15]    |CMPWEN    |Compare Window Mode Enable Bit
     * |        |          |0 = EADCMPF0 (EADC_STATUS2[4]) will be set when EADC_CMP0 compared condition matched
     * |        |          |EADCMPF2 (EADC_STATUS2[6]) will be set when EADC_CMP2 compared condition matched
     * |        |          |1 = EADCMPF0 (EADC_STATUS2[4]) will be set when both EADC_CMP0 and EADC_CMP1 compared condition matched
     * |        |          |EADCMPF2 (EADC_STATUS2[6]) will be set when both EADC_CMP2 and EADC_CMP3 compared condition matched.
     * |        |          |Note: This bit is only present in EADC_CMP0 and EADC_CMP2 register.
     * |[31:16] |CMPDAT    |Comparison Data
     * |        |          |Except for the oversampling mode, the comparison data CMPDAT (EADC_CMPn[27:16], n=0~3) is 12 bits
     * |        |          |This 12 bits data is used to compare with conversion result of specified sample module
     * |        |          |User can use it to monitor the external analog input pin voltage transition without imposing a load on software.
     * |        |          |In oversampling mode, the width of comparison data CMPDAT (EADC_CMPn[31:16], n=0~3) can reach 16 bits.
     * |        |          |Note: The EADC_CMPn[31:28] (n=0~3) is only workable in oversampling mode.
     * @var EADC_T::CMP3
     * Offset: 0xEC  EADC Result Compare Register 3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |EADCMPEN  |EADC Result Compare Enable Bit
     * |        |          |0 = Compare Disabled.
     * |        |          |1 = Compare Enabled.
     * |        |          |Set this bit to 1 to enable compare CMPDAT (EADC_CMPn[27:16], n=0~3) with specified sample module conversion result when converted data is loaded into EADC_DAT register.
     * |[1]     |EADCMPIE  |EADC Result Compare Interrupt Enable Bit
     * |        |          |0 = Compare function interrupt Disabled.
     * |        |          |1 = Compare function interrupt Enabled.
     * |        |          |If the compare function is enabled and the compare condition matches the setting of CMPCOND (EADC_CMPn[2], n=0~3) and CMPMCNT (EADC_CMPn[11:8], n=0~3), EADCMPFn (EADC_STATUS2[7:4], n=0~3) will be asserted, in the meanwhile, if EADCMPIE is set to 1, a compare interrupt request is generated.
     * |[2]     |CMPCOND   |Compare Condition
     * |        |          |0= Set the compare condition as that when a 12-bit EADC conversion result is less than the 12-bit CMPDAT (EADC_CMPn [27:16]), the internal match counter will increase one.
     * |        |          |1= Set the compare condition as that when a 12-bit EADC conversion result is greater or equal to the 12-bit CMPDAT (EADC_CMPn [27:16]), the internal match counter will increase one.
     * |        |          |Note: When the internal counter reaches the value to (CMPMCNT (EADC_CMPn[11:8], n=0~3) +1), the CMPF bit will be set.
     * |[6:3]   |CMPSPL    |Compare Sample Module Selection
     * |        |          |00000 = Sample Module 0 conversion result EADC_DAT0 is selected to be compared.
     * |        |          |00001 = Sample Module 1 conversion result EADC_DAT1 is selected to be compared.
     * |        |          |00010 = Sample Module 2 conversion result EADC_DAT2 is selected to be compared.
     * |        |          |00011 = Sample Module 3 conversion result EADC_DAT3 is selected to be compared.
     * |        |          |00100 = Sample Module 4 conversion result EADC_DAT4 is selected to be compared.
     * |        |          |00101 = Sample Module 5 conversion result EADC_DAT5 is selected to be compared.
     * |        |          |00110 = Sample Module 6 conversion result EADC_DAT6 is selected to be compared.
     * |        |          |00111 = Sample Module 7 conversion result EADC_DAT7 is selected to be compared.
     * |        |          |01000 = Sample Module 8 conversion result EADC_DAT8 is selected to be compared.
     * |        |          |01001 = Sample Module 9 conversion result EADC_DAT9 is selected to be compared.
     * |        |          |01010 = Sample Module 10 conversion result EADC_DAT10 is selected to be compared.
     * |        |          |01011 = Sample Module 11 conversion result EADC_DAT11 is selected to be compared.
     * |        |          |01100 = Sample Module 12 conversion result EADC_DAT12 is selected to be compared.
     * |        |          |01101 = Sample Module 13 conversion result EADC_DAT13 is selected to be compared.
     * |        |          |01110 = Sample Module 14 conversion result EADC_DAT14 is selected to be compared.
     * |        |          |01111 = Sample Module 15 conversion result EADC_DAT15 is selected to be compared.
     * |        |          |10000 = Sample Module 16 conversion result EADC_DAT16 is selected to be compared.
     * |        |          |10001 = Sample Module 17 conversion result EADC_DAT17 is selected to be compared.
     * |        |          |10010 = Sample Module 18 conversion result EADC_DAT18 is selected to be compared.
     * |[11:8]  |CMPMCNT   |Compare Match Count
     * |        |          |When the specified EADC sample module analog conversion result matches the compare condition defined by CMPCOND (EADC_CMPn[2], n=0~3), the internal match counter will increase 1
     * |        |          |If the compare result does not meet the compare condition, the internal compare match counter will reset to 0
     * |        |          |When the internal counter reaches the value to (CMPMCNT +1), the EADCMPFn (EADC_STATUS2[7:4], n=0~3) will be set.
     * |[15]    |CMPWEN    |Compare Window Mode Enable Bit
     * |        |          |0 = EADCMPF0 (EADC_STATUS2[4]) will be set when EADC_CMP0 compared condition matched
     * |        |          |EADCMPF2 (EADC_STATUS2[6]) will be set when EADC_CMP2 compared condition matched
     * |        |          |1 = EADCMPF0 (EADC_STATUS2[4]) will be set when both EADC_CMP0 and EADC_CMP1 compared condition matched
     * |        |          |EADCMPF2 (EADC_STATUS2[6]) will be set when both EADC_CMP2 and EADC_CMP3 compared condition matched.
     * |        |          |Note: This bit is only present in EADC_CMP0 and EADC_CMP2 register.
     * |[31:16] |CMPDAT    |Comparison Data
     * |        |          |Except for the oversampling mode, the comparison data CMPDAT (EADC_CMPn[27:16], n=0~3) is 12 bits
     * |        |          |This 12 bits data is used to compare with conversion result of specified sample module
     * |        |          |User can use it to monitor the external analog input pin voltage transition without imposing a load on software.
     * |        |          |In oversampling mode, the width of comparison data CMPDAT (EADC_CMPn[31:16], n=0~3) can reach 16 bits.
     * |        |          |Note: The EADC_CMPn[31:28] (n=0~3) is only workable in oversampling mode.
     * @var EADC_T::STATUS0
     * Offset: 0xF0  EADC Status Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[8:0]   |VALID     |EADC_DAT0~8 Data Valid Flag
     * |        |          |It is a mirror of VALID bit in sample module EADC result data register EADC_DATn. (n=0~8).
     * |[24:16] |OV        |EADC_DAT0~8 Overrun Flag
     * |        |          |It is a mirror to OV bit in sample module EADC result data register EADC_DATn. (n=0~8).
     * @var EADC_T::STATUS1
     * Offset: 0xF4  EADC Status Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * @var EADC_T::STATUS2
     * Offset: 0xF8  EADC Status Register 2
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ADIF0     |EADC ADINT0 Interrupt Flag
     * |        |          |0 = No ADINT0 interrupt pulse received.
     * |        |          |1 = ADINT0 interrupt pulse has been received.
     * |        |          |Note 1: This bit is cleared by writing 1 to it.
     * |        |          |Note 2: This bit indicates whether an EADC conversion of specific sample module has been completed
     * |[1]     |ADIF1     |EADC ADINT1 Interrupt Flag
     * |        |          |0 = No ADINT1 interrupt pulse received.
     * |        |          |1 = ADINT1 interrupt pulse has been received.
     * |        |          |Note 1: This bit is cleared by writing 1 to it.
     * |        |          |Note 2: This bit indicates whether an EADC conversion of specific sample module has been completed
     * |[2]     |ADIF2     |EADC ADINT2 Interrupt Flag
     * |        |          |0 = No ADINT2 interrupt pulse received.
     * |        |          |1 = ADINT2 interrupt pulse has been received.
     * |        |          |Note 1: This bit is cleared by writing 1 to it.
     * |        |          |Note 2: This bit indicates whether an EADC conversion of specific sample module has been completed
     * |[3]     |ADIF3     |EADC ADINT3 Interrupt Flag
     * |        |          |0 = No ADINT3 interrupt pulse received.
     * |        |          |1 = ADINT3 interrupt pulse has been received.
     * |        |          |Note 1: This bit is cleared by writing 1 to it.
     * |        |          |Note 2: This bit indicates whether an EADC conversion of specific sample module has been completed
     * |[4]     |EADCMPF0  |EADC Compare 0 Flag
     * |        |          |When the specific sample module EADC conversion result meets setting condition in EADC_CMP0 then this bit is set to 1.
     * |        |          |0 = Conversion result in EADC_DAT does not meet EADC_CMP0 register setting.
     * |        |          |1 = Conversion result in EADC_DAT meets EADC_CMP0 register setting.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * |[5]     |EADCMPF1  |EADC Compare 1 Flag
     * |        |          |When the specific sample module EADC conversion result meets setting condition in EADC_CMP1 then this bit is set to 1.
     * |        |          |0 = Conversion result in EADC_DAT does not meet EADC_CMP1 register setting.
     * |        |          |1 = Conversion result in EADC_DAT meets EADC_CMP1 register setting.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * |[6]     |EADCMPF2  |EADC Compare 2 Flag
     * |        |          |When the specific sample module EADC conversion result meets setting condition in EADC_CMP2 then this bit is set to 1.
     * |        |          |0 = Conversion result in EADC_DAT does not meet EADC_CMP2 register setting.
     * |        |          |1 = Conversion result in EADC_DAT meets EADC_CMP2 register setting.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * |[7]     |EADCMPF3  |EADC Compare 3 Flag
     * |        |          |When the specific sample module EADC conversion result meets setting condition in EADC_CMP3 then this bit is set to 1.
     * |        |          |0 = Conversion result in EADC_DAT does not meet EADC_CMP3 register setting.
     * |        |          |1 = Conversion result in EADC_DAT meets EADC_CMP3 register setting.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * |[8]     |ADOVIF0   |EADC ADINT0 Interrupt Flag Overrun
     * |        |          |0 = ADINT0 interrupt flag is not overwritten to 1.
     * |        |          |1 = ADINT0 interrupt flag is overwritten to 1.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * |[9]     |ADOVIF1   |EADC ADINT1 Interrupt Flag Overrun
     * |        |          |0 = ADINT1 interrupt flag is not overwritten to 1.
     * |        |          |1 = ADINT1 interrupt flag is overwritten to 1.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * |[10]    |ADOVIF2   |EADC ADINT2 Interrupt Flag Overrun
     * |        |          |0 = ADINT2 interrupt flag is not overwritten to 1.
     * |        |          |1 = ADINT2 interrupt flag is overwritten to 1.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * |[11]    |ADOVIF3   |EADC ADINT3 Interrupt Flag Overrun
     * |        |          |0 = ADINT3 interrupt flag is not overwritten to 1.
     * |        |          |1 = ADINT3 interrupt flag is overwritten to 1.
     * |        |          |Note: This bit is cleared by writing 1 to it.
     * |[12]    |EADCMPO0  |EADC Compare 0 Output Status (Read Only)
     * |        |          |The 12 bits compare0 data CMPDAT0 (EADC_CMP0[27:16]) is used to compare with conversion result of specified sample module
     * |        |          |User can use it to monitor the external analog input pin voltage status.
     * |        |          |0 = Conversion result in EADC_DAT is less than CMPDAT0 setting.
     * |        |          |1 = Conversion result in EADC_DAT is greater than or equal to CMPDAT0 setting.
     * |[13]    |EADCMPO1  |EADC Compare 1 Output Status (Read Only)
     * |        |          |The 12 bits compare1 data CMPDAT1 (EADC_CMP1[27:16]) is used to compare with conversion result of specified sample module
     * |        |          |User can use it to monitor the external analog input pin voltage status.
     * |        |          |0 = Conversion result in EADC_DAT is less than CMPDAT1 setting.
     * |        |          |1 = Conversion result in EADC_DAT is greater than or equal to CMPDAT1 setting.
     * |[14]    |EADCMPO2  |EADC Compare 2 Output Status (Read Only)
     * |        |          |The 12 bits compare2 data CMPDAT2 (EADC_CMP2[27:16]) is used to compare with conversion result of specified sample module
     * |        |          |User can use it to monitor the external analog input pin voltage status.
     * |        |          |0 = Conversion result in EADC_DAT is less than CMPDAT2 setting.
     * |        |          |1 = Conversion result in EADC_DAT is greater than or equal to CMPDAT2 setting.
     * |[15]    |EADCMPO3  |EADC Compare 3 Output Status (Read Only)
     * |        |          |The 12 bits compare3 data CMPDAT3 (EADC_CMP3[27:16]) is used to compare with conversion result of specified sample module
     * |        |          |User can use it to monitor the external analog input pin voltage status.
     * |        |          |0 = Conversion result in EADC_DAT is less than CMPDAT3 setting.
     * |        |          |1 = Conversion result in EADC_DAT is greater than or equal to CMPDAT3 setting.
     * |[20:16] |CHANNEL   |Current Conversion Channel (Read Only)
     * |        |          |This filed reflects EADC current conversion channel when BUSY=1.
     * |        |          |00H = EADC_CH0.
     * |        |          |01H = EADC_CH1.
     * |        |          |02H = EADC_CH2.
     * |        |          |03H = EADC_CH3.
     * |        |          |04H = EADC_CH4.
     * |        |          |05H = EADC_CH5.
     * |        |          |06H = EADC_CH6.
     * |        |          |07H = EADC_CH7.
     * |        |          |08H = VREF.
     * |        |          |09H = EADC_CH9.
     * |        |          |0AH = EADC_CH10.
     * |        |          |0BH = EADC_CH11.
     * |        |          |0CH = EADC_CH12.
     * |        |          |0DH = EADC_CH13.
     * |        |          |0EH = EADC_CH14.
     * |        |          |0FH = EADC_CH15.
     * |        |          |10H = VBG.
     * |        |          |11H = VTEMP.
     * |        |          |12H = VBAT/4.
     * |[23]    |BUSY      |Busy/Idle (Read Only)
     * |        |          |0 = EADC is in idle state.
     * |        |          |1 = EADC is busy at conversion.
     * |[24]    |ADOVIF    |All EADC Interrupt Flag Overrun Bits Check (Read Only)
     * |        |          |n=0~3.
     * |        |          |0 = None of ADINT interrupt flag ADOVIFn (EADC_STATUS2[11:8]) is overwritten to 1.
     * |        |          |1 = Any one of ADINT interrupt flag ADOVIFn (EADC_STATUS2[11:8]) is overwritten to 1.
     * |        |          |Note: This bit will keep 1 when any ADOVIFn Flag is equal to 1.
     * |[25]    |STOVF     |All EADC Sample Module Start of Conversion Overrun Flags Check (Read Only)
     * |        |          |n=0~8.
     * |        |          |0 = None of sample module event overrun flag SPOVF (EADC_OVSTS[n]) is set to 1.
     * |        |          |1 = Any one of sample module event overrun flag SPOVF (EADC_OVSTS[n]) is set to 1.
     * |        |          |Note: This bit will keep 1 when any SPOVF Flag is equal to 1.
     * |[26]    |AVALID    |All Sample Module EADC Result Data Register EADC_DAT Data Valid Flag Check (Read Only)
     * |        |          |n=0~8.
     * |        |          |0 = None of sample module data register valid flag VALID (EADC_DATn[17]) is set to 1.
     * |        |          |1 = Any one of sample module data register valid flag VALID (EADC_DATn[17]) is set to 1.
     * |        |          |Note: This bit will keep 1 when any VALID Flag is equal to 1.
     * |[27]    |AOV       |All Sample Module EADC Result Data Register Overrun Flags Check (Read Only)
     * |        |          |n=0~8.
     * |        |          |0 = None of sample module data register overrun flag OV (EADC_DATn[16]) is set to 1.
     * |        |          |1 = Any one of sample module data register overrun flag OV (EADC_DATn[16]) is set to 1.
     * |        |          |Note: This bit will keep 1 when any OV Flag is equal to 1.
     * |[28]    |FFULL     |EADC Ping-Pong FIFO Full Flag (Read Only)
     * |        |          |This bit wil be triggered when ping-pong fifo is full.
     * |        |          |0 = No ping-pong fifo full flag has been received.
     * |        |          |1 = The ping-pong fifo full flag has been received.
     * |        |          |Note 1: This bit only can be triggered when enable PDMA transfer function.
     * |        |          |Note 2: This bit is automatically cleared after user clears FFTDF(EADC_STATUS2[29]).
     * |[29]    |FFTDF     |EADC Ping-Pong FIFO Full Transfer Done Flag
     * |        |          |This bit may only be triggered after ping-pong fifo is full
     * |        |          |If this bit to1 means the PDMA has completed the transfer
     * |        |          |After the user writes 1 to clear ths bit, the EADC will be able to fill the conversion result into the ping-pong fifo and send the request to PDMA.
     * |        |          |0 = No ping-pong fifo full transfer done flag has been received.
     * |        |          |1 = The ping-pong fifo full transfer done flag has been received.
     * |        |          |Note 1: This bit is cleared by writing 1 to it.
     * @var EADC_T::STATUS3
     * Offset: 0xFC  EADC Status Register 3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[4:0]   |CURSPL    |EADC Current Sample Module (Read Only)
     * |        |          |This register shows the current EADC is controlled by which sample module control logic modules.
     * |        |          |If the EADC is Idle, the bit filed will be set to 0x1F.
     * @var EADC_T::DDAT0
     * Offset: 0x100  EADC Double Data Register 0 for Sample Module 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RESULT    |EADC Conversion Results
     * |        |          |This field contains 12 bits conversion results.
     * |        |          |When the DMOF (EADC_CTL[9]) is set to 0, 12-bit EADC conversion result with unsigned format will be filled in RESULT [11:0] and zero will be filled in RESULT [15:12].
     * |        |          |When DMOF (EADC_CTL[9]) is set to 1, 12-bit EADC conversion result with 2u2019complement format will be filled in RESULT [11:0] and signed bits to will be filled in RESULT [15:12].
     * |[16]    |OV        |Overrun Flag
     * |        |          |0 = Data in RESULT (EADC_DATn[15:0], n=0~3) is recent conversion result.
     * |        |          |1 = Data in RESULT (EADC_DATn[15:0], n=0~3) is overwrite.
     * |        |          |Note: If converted data in RESULT[15:0] has not been read before new conversion result is loaded to this register, OV is set to 1
     * |        |          |It is cleared by hardware after EADC_DDAT register is read.
     * |[17]    |VALID     |Valid Flag
     * |        |          |0 = Double data in RESULT (EADC_DDATn[15:0]) is not valid.
     * |        |          |1 = Double data in RESULT (EADC_DDATn[15:0]) is valid.
     * |        |          |Note: This bit is set to 1 when corresponding sample module channel analog input conversion is completed and cleared by hardware after EADC_DDATn register is read (n=0~3).
     * @var EADC_T::DDAT1
     * Offset: 0x104  EADC Double Data Register 1 for Sample Module 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RESULT    |EADC Conversion Results
     * |        |          |This field contains 12 bits conversion results.
     * |        |          |When the DMOF (EADC_CTL[9]) is set to 0, 12-bit EADC conversion result with unsigned format will be filled in RESULT [11:0] and zero will be filled in RESULT [15:12].
     * |        |          |When DMOF (EADC_CTL[9]) is set to 1, 12-bit EADC conversion result with 2u2019complement format will be filled in RESULT [11:0] and signed bits to will be filled in RESULT [15:12].
     * |[16]    |OV        |Overrun Flag
     * |        |          |0 = Data in RESULT (EADC_DATn[15:0], n=0~3) is recent conversion result.
     * |        |          |1 = Data in RESULT (EADC_DATn[15:0], n=0~3) is overwrite.
     * |        |          |Note: If converted data in RESULT[15:0] has not been read before new conversion result is loaded to this register, OV is set to 1
     * |        |          |It is cleared by hardware after EADC_DDAT register is read.
     * |[17]    |VALID     |Valid Flag
     * |        |          |0 = Double data in RESULT (EADC_DDATn[15:0]) is not valid.
     * |        |          |1 = Double data in RESULT (EADC_DDATn[15:0]) is valid.
     * |        |          |Note: This bit is set to 1 when corresponding sample module channel analog input conversion is completed and cleared by hardware after EADC_DDATn register is read (n=0~3).
     * @var EADC_T::DDAT2
     * Offset: 0x108  EADC Double Data Register 2 for Sample Module 2
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RESULT    |EADC Conversion Results
     * |        |          |This field contains 12 bits conversion results.
     * |        |          |When the DMOF (EADC_CTL[9]) is set to 0, 12-bit EADC conversion result with unsigned format will be filled in RESULT [11:0] and zero will be filled in RESULT [15:12].
     * |        |          |When DMOF (EADC_CTL[9]) is set to 1, 12-bit EADC conversion result with 2u2019complement format will be filled in RESULT [11:0] and signed bits to will be filled in RESULT [15:12].
     * |[16]    |OV        |Overrun Flag
     * |        |          |0 = Data in RESULT (EADC_DATn[15:0], n=0~3) is recent conversion result.
     * |        |          |1 = Data in RESULT (EADC_DATn[15:0], n=0~3) is overwrite.
     * |        |          |Note: If converted data in RESULT[15:0] has not been read before new conversion result is loaded to this register, OV is set to 1
     * |        |          |It is cleared by hardware after EADC_DDAT register is read.
     * |[17]    |VALID     |Valid Flag
     * |        |          |0 = Double data in RESULT (EADC_DDATn[15:0]) is not valid.
     * |        |          |1 = Double data in RESULT (EADC_DDATn[15:0]) is valid.
     * |        |          |Note: This bit is set to 1 when corresponding sample module channel analog input conversion is completed and cleared by hardware after EADC_DDATn register is read (n=0~3).
     * @var EADC_T::DDAT3
     * Offset: 0x10C  EADC Double Data Register 3 for Sample Module 3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RESULT    |EADC Conversion Results
     * |        |          |This field contains 12 bits conversion results.
     * |        |          |When the DMOF (EADC_CTL[9]) is set to 0, 12-bit EADC conversion result with unsigned format will be filled in RESULT [11:0] and zero will be filled in RESULT [15:12].
     * |        |          |When DMOF (EADC_CTL[9]) is set to 1, 12-bit EADC conversion result with 2u2019complement format will be filled in RESULT [11:0] and signed bits to will be filled in RESULT [15:12].
     * |[16]    |OV        |Overrun Flag
     * |        |          |0 = Data in RESULT (EADC_DATn[15:0], n=0~3) is recent conversion result.
     * |        |          |1 = Data in RESULT (EADC_DATn[15:0], n=0~3) is overwrite.
     * |        |          |Note: If converted data in RESULT[15:0] has not been read before new conversion result is loaded to this register, OV is set to 1
     * |        |          |It is cleared by hardware after EADC_DDAT register is read.
     * |[17]    |VALID     |Valid Flag
     * |        |          |0 = Double data in RESULT (EADC_DDATn[15:0]) is not valid.
     * |        |          |1 = Double data in RESULT (EADC_DDATn[15:0]) is valid.
     * |        |          |Note: This bit is set to 1 when corresponding sample module channel analog input conversion is completed and cleared by hardware after EADC_DDATn register is read (n=0~3).
     * @var EADC_T::PWRM
     * Offset: 0x110  EADC Power Management Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |PWUPRDY   |EADC   Power-up Sequence Completed and Ready for Conversion (Read Only)
     * |        |          |0 =   EADC is not ready for conversion may   be in power down state or in the progress of start-up.
     * |        |          |1 =   EADC is ready for conversion.
     * |[1]     |PWUCALEN  |Power Up Calibration Function Enable Bit
     * |        |          |0 = Calibration function Disabled at power up.
     * |        |          |1 = Calibration function Enabled at power up.
     * |        |          |Note: This bit works together with CALSEL (EADC_CALCTL [3]), see the following
     * |        |          |{PWUCALEN, CALSEL } Description:
     * |        |          |PWUCALEN is 0 and CALSEL is 0: No need to calibrate.
     * |        |          |PWUCALEN is 0 and CALSEL is 1: No need to calibrate.
     * |        |          |PWUCALEN is 1 and CALSEL is 0: Load calibration word when power up.
     * |        |          |PWUCALEN is 1 and CALSEL is 1: Calibrate when power up.
     * |[3:2]   |PWDMOD    |EADC Power-down Mode
     * |        |          |Set this bit field to select EADC Power-down mode when system   power-down.
     * |        |          |00 = EADC Deep Power-down mode.
     * |        |          |01 = EADC Power down.
     * |        |          |10 = EADC Standby mode.
     * |        |          |11 = EADC Deep Power-down mode.
     * |        |          |Note: Different PWDMOD has different power down/up sequence;   in order to avoid EADC powering up with wrong sequence, user must keep PWMOD   consistent each time in power down and start-up.
     * |[4]     |PWAWARE   |Power Aware Function Enable Bit
     * |        |          |0 = EADC clock always Enabled.
     * |        |          |1 =When EADCEN(EADC_CTL[0]) is set to 0, EADC clock will   automatically be gated to save power.
     * |[27:8]  |IREFSUT   |EADC   Internal REF Start-up Time
     * |        |          |Set   this bit field to control internal reference   start-up time
     * |        |          |The typical required internal reference start-up time is 20us when EADC fully power down
     * |        |          |Internal   reference start-up time   = (1/EADC_CLK) x IREFSUT
     * |        |          |Please set start-up time longer than 20us.
     * |        |          |Note 1: EADC fully Power-down mode means both EADC macro and   internal reference enter Power-down mode.
     * |        |          |Note   2: EADC macro enters Power-down mode when   EADCEN(EADC_CTL[0] = 0.
     * |        |          |Note   3: EADC internal reference enters   Power-down mode when PDREF(EADC_REFADJCT[0] = 1.
     * @var EADC_T::CALCTL
     * Offset: 0x114  EADC Calibration Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1]     |CALSTART  |Calibration Functional Block Start
     * |        |          |0 = Stop calibration functional block.
     * |        |          |1 = Start calibration functional block.
     * |        |          |Note: This bit is set by software and cleared by hardware after re-calibration is finished.
     * |[2]     |CALDONE   |Calibration Functional Block Complete (Read Only)
     * |        |          |0 = During a calibration.
     * |        |          |1 = Calibration is completed.
     * |[3]     |CALSEL    |Select Calibration Functional Block Enable Bit
     * |        |          |0 = Calibration functional block Disabled.
     * |        |          |1 = Calibration functional block Enabled.
     * @var EADC_T::PDMACTL
     * Offset: 0x130  EADC PDMA Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[8:0]   |PDMATEN   |PDMA Transfer Enable Bit
     * |        |          |When EADC conversion is completed, the converted data is loaded into EADC_DATn (n: 0 ~ 8) register, user can enable this bit to generate a PDMA data transfer request.
     * |        |          |0 = PDMA data transfer Disabled.
     * |        |          |1 = PDMA data transfer Enabled.
     * |        |          |Note:When this bit field is set to 1, user must set EADCIENn (EADC_CTL[5:2], n=0~3) = 0 to disable interrupt.
     * |[24]    |FDRO      |EADC Ping-Pong FIFO Data Reserve Option Bit
     * |        |          |The ping-pong fifo can store up to 8-words (16 EADC conversion results)
     * |        |          |When the fifo stores every 4-words (8 EADC conversion results), the EADC will send a request to PDMA
     * |        |          |If the PDMA is too busy to transfer data from the fifo, subsequent conversion results will continue to be stored in the remaining 4-words of the fifo
     * |        |          |When the fifo stores 8-words of conversion results, the fifo is full
     * |        |          |And this bit provides the user with two options on how to handle the data stored in the ping-pong fifo when fifo full event occurs
     * |        |          |User can decide whether PDMA transfers the first 8 EADC conversion results or all EADC conversion results stored in the fifo.
     * |        |          |0 = Transfer the 8 EADC conversion results put in ping-pong fifo first.
     * |        |          |1 = Transfer all EADC conversion results in ping-pong fifo.
     * |        |          |Note: This bit must be set at the same time as PDMATEN(EADC_PDMACTL[8:0])
     * |        |          |And only useful when PDMA transfer is enabled.
     * |[30]    |FIFOEN    |EADC Ping-Pong FIFO Function Enable Bit (Read only)
     * |        |          |When user enables any PDMATEN (EADC_PDMACTL[8:0]), the EADC Ping-Pong fifo function is also enabled
     * |        |          |The EADC has an 8-words (Up to stored 16 EADC conversion results) ping-pong fifo and supports PDMA transmission
     * |        |          |The EADC controller sends a request to PDMA when every 8 EADC conversion results of the ping-pong fifo are stored
     * |        |          |While waiting for PDMA to assist in the transfer, the EADC controller can continuously fill the ping-pong FIFO with EADC conversion result.
     * |        |          |0 = EADC Ping-Pong fifo function Disabled.
     * |        |          |1 = EADC Ping-Pong fifo function Enabled.
     * |        |          |Note 1: This bit will be automatically set if any PDMATEN(EADC_PDMACTL[8:0]) is set.
     * |        |          |Note 2: If FIFO_DBUG(EADC_FIFODEBUG[0]) is set, this bit will be set to 0 regardless of any PDMATEN(EADC_PDMACTL[8:0]) is set to 1
     * |        |          |It means EADC ping-pong fifo function disabled.
     * |[31]    |FIFORST   |EADC Ping-Pong FIFO Function Reset Bit
     * |        |          |This bit can only reset EADC Ping-Pong fifo registers.
     * |        |          |0 = No effect.
     * |        |          |1 = Reset EADC Ping-Pong fifo registers.
     * |        |          |Note: FIFORST bit remains 1 during ping-pong fifo reset, when ping-pong fifo reset end, the FIFORST bit is automatically cleared to 0.
     * @var EADC_T::FIFOSTS
     * Offset: 0x134  EADC FIFO Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[4:0]   |FIFOWR    |EADC Ping-Pong FIFO Write Point
     * |        |          |Thist bit present the EADC ping-pong fifo write status
     * |        |          |The MSB of FIFOWR(EADC_FIFOSTS[4:0]) is only for compare read point and it does not represent the space location of EADC ping-pong fifo.
     * |        |          |0H = Write start point and it represents the 1st space location where data will be written into the fifo.
     * |        |          |1H = It represents the 2nd space location where data will be written into the fifo.
     * |        |          |2H = It represents the 3rd space location where data will be written into the fifo.
     * |        |          |3H = It represents the 4th space location where data will be written into the fifo.
     * |        |          |4H = It represents the 5th space location where data will be written into the fifo.
     * |        |          |5H = It represents the 6th space location where data will be written into the fifo.
     * |        |          |6H = It represents the 7th space location where data will be written into the fifo.
     * |        |          |7H = It represents the 8th space location where data will be written into the fifo.
     * |        |          |8H = It represents the 9th space location where data will be written into the fifo.
     * |        |          |9H = It represents the 10th space location where data will be written into the fifo.
     * |        |          |AH = It represents the 11th space location where data will be written into the fifo.
     * |        |          |BH = It represents the 12th space location where data will be written into the fifo.
     * |        |          |CH = It represents the 13th space location where data will be written into the fifo.
     * |        |          |DH = It represents the 14th space location where data will be written into the fifo.
     * |        |          |EH = It represents the 15th space location where data will be written into the fifo.
     * |        |          |FH = It represents the 16th space location where data will be written into the fifo.
     * |        |          |Note: This bit must be set to 0 in normal.
     * |[12:8]  |FIFORD    |EADC Ping-Pong FIFO Read Point
     * |        |          |Thist bit present the EADC ping-pong fifo read status
     * |        |          |The MSB of FIFORD(EADC_FIFOSTS[4:0]) is only for compare write point and it does not represent the space location of EADC ping-pong fifo.
     * |        |          |0H = Read start point and it represents the 1st space location where data will be read into the fifo.
     * |        |          |1H = It represents the 2nd space location where data will be read into the fifo.
     * |        |          |2H = It represents the 3rd space location where data will be read into the fifo.
     * |        |          |3H = It represents the 4th space location where data will be read into the fifo.
     * |        |          |4H = It represents the 5th space location where data will be read into the fifo.
     * |        |          |5H = It represents the 6th space location where data will be read into the fifo.
     * |        |          |6H = It represents the 7th space location where data will be read into the fifo.
     * |        |          |7H = It represents the 8th space location where data will be read into the fifo.
     * |        |          |8H = It represents the 9th space location where data will be read into the fifo.
     * |        |          |9H = It represents the 10th space location where data will be read into the fifo.
     * |        |          |AH = It represents the 11th space location where data will be read into the fifo.
     * |        |          |BH = It represents the 12th space location where data will be read into the fifo.
     * |        |          |CH = It represents the 13th space location where data will be read into the fifo.
     * |        |          |DH = It represents the 14th space location where data will be read into the fifo.
     * |        |          |EH = It represents the 15th space location where data will be read into the fifo.
     * |        |          |FH = It represents the 16th space location where data will be read into the fifo.
     * |        |          |Note: This bit must be set to 0 in normal.
     * |[30]    |FIFOFULL  |EADC Ping-Pong FIFO Full Flag
     * |        |          |When the EADC ping-pong fifo full, this flag will set to 1.
     * |[31]    |FIFOEMPT  |EADC Ping-Pong FIFO Empty Flag
     * |        |          |When the EADC ping-pong fifo empty, this flag will set to 1.
     * @var EADC_T::FIFODEBUG
     * Offset: 0x138  EADC FIFO Debug Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |FIFODBUG  |EADC Ping-Pong FIFO Debug Enable Bit
     * |        |          |EADC has ping-pong fifo function and it can be disabled if this bit is set
     * |        |          |Due to FIFO_EN(EADC_PDMACTL[30]) link to PDMATEN(EADC_PDMACTL[8:0]), it means EADC ping-pong fifo function will be enabled if any PDMATEN(EADC_PDMACTL[8:0]) is set to 1
     * |        |          |Hardware provide FIFODBUG(EADC_FIFODEBUG[0]) bit to control from the side, setting this bit to 1 disables the EADC ping-pong fifo function regardless of whether any PDMATEN(EADC_PDMACTL[8:0]) is set to 1.
     * |        |          |0 = EADC Ping-Pong fifo debug Disabled.
     * |        |          |1 = EADC Ping-Pong fifo debug Enabled.
     * |        |          |Note: This bit must be set to 0 in normal.
     * @var EADC_T::SELSMP0
     * Offset: 0x140  EADC Select Sampling Time Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1:0]   |SELSMP0   |Sample Module n Select Sampling Time Option
     * |        |          |EADC sampling time selection bit, in case more sampling time is needed when the input signal resistance is higher.
     * |        |          |00 = 3+0 EADC_CLK.
     * |        |          |01 = 3+2 EADC_CLK.
     * |        |          |10 = 3+4 EADC_CLK.
     * |        |          |11 = 3+6 EADC_CLK.
     * |[5:4]   |SELSMP1   |Sample Module n Select Sampling Time Option
     * |        |          |EADC sampling time selection bit, in case more sampling time is needed when the input signal resistance is higher.
     * |        |          |00 = 3+0 EADC_CLK.
     * |        |          |01 = 3+2 EADC_CLK.
     * |        |          |10 = 3+4 EADC_CLK.
     * |        |          |11 = 3+6 EADC_CLK.
     * |[9:8]   |SELSMP2   |Sample Module n Select Sampling Time Option
     * |        |          |EADC sampling time selection bit, in case more sampling time is needed when the input signal resistance is higher.
     * |        |          |00 = 3+0 EADC_CLK.
     * |        |          |01 = 3+2 EADC_CLK.
     * |        |          |10 = 3+4 EADC_CLK.
     * |        |          |11 = 3+6 EADC_CLK.
     * |[13:12] |SELSMP3   |Sample Module n Select Sampling Time Option
     * |        |          |EADC sampling time selection bit, in case more sampling time is needed when the input signal resistance is higher.
     * |        |          |00 = 3+0 EADC_CLK.
     * |        |          |01 = 3+2 EADC_CLK.
     * |        |          |10 = 3+4 EADC_CLK.
     * |        |          |11 = 3+6 EADC_CLK.
     * |[17:16] |SELSMP4   |Sample Module n Select Sampling Time Option
     * |        |          |EADC sampling time selection bit, in case more sampling time is needed when the input signal resistance is higher.
     * |        |          |00 = 3+0 EADC_CLK.
     * |        |          |01 = 3+2 EADC_CLK.
     * |        |          |10 = 3+4 EADC_CLK.
     * |        |          |11 = 3+6 EADC_CLK.
     * |[21:20] |SELSMP5   |Sample Module n Select Sampling Time Option
     * |        |          |EADC sampling time selection bit, in case more sampling time is needed when the input signal resistance is higher.
     * |        |          |00 = 3+0 EADC_CLK.
     * |        |          |01 = 3+2 EADC_CLK.
     * |        |          |10 = 3+4 EADC_CLK.
     * |        |          |11 = 3+6 EADC_CLK.
     * |[25:24] |SELSMP6   |Sample Module n Select Sampling Time Option
     * |        |          |EADC sampling time selection bit, in case more sampling time is needed when the input signal resistance is higher.
     * |        |          |00 = 3+0 EADC_CLK.
     * |        |          |01 = 3+2 EADC_CLK.
     * |        |          |10 = 3+4 EADC_CLK.
     * |        |          |11 = 3+6 EADC_CLK.
     * |[29:28] |SELSMP7   |Sample Module n Select Sampling Time Option
     * |        |          |EADC sampling time selection bit, in case more sampling time is needed when the input signal resistance is higher.
     * |        |          |00 = 3+0 EADC_CLK.
     * |        |          |01 = 3+2 EADC_CLK.
     * |        |          |10 = 3+4 EADC_CLK.
     * |        |          |11 = 3+6 EADC_CLK.
     * @var EADC_T::SELSMP1
     * Offset: 0x144  EADC Select Sampling Time Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1:0]   |SELSMP8   |Sample Module 8 Select Sampling Time Option
     * |        |          |EADC sampling time selection bit, in case more sampling time is needed when the input signal resistance is higher.
     * |        |          |00 = 3+0 EADC_CLK.
     * |        |          |01 = 3+2 EADC_CLK.
     * |        |          |10 = 3+4 EADC_CLK.
     * |        |          |11 = 3+6 EADC_CLK.
     * @var EADC_T::REFADJCTL
     * Offset: 0x150  EADC Reference Voltage Adjust Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |PDREF     |EADC Power Down Internal Reference Control Bit
     * |        |          |0 = Normal operating mode.
     * |        |          |1 = Power-down mode.
     * |        |          |Note: If internal reference is in Power-down mode, EADCu2019s reference voltage must come from external VREF.
     * |[4:1]   |REFADJ    |EADC Internal Band-gap Voltage Option
     * |        |          |By setting REFADJ according to the following formula and configuration table, one can adjust reference voltage VREF in a small range:
     * |        |          |VREF = GAIN x VBG.
     * |        |          |GAIN = 1.6, 2.0, 2.5, 3.0(by setting VREFSEL(EADC_CTL[11:10]) = 00, 01, 10, 11 respectively).
     * |        |          |VBG is internal band-gap voltage, typical 1.0V, VBG can be configured by the following:
     * |        |          |0000 = VBG_type.
     * |        |          |0001 = VBG_type + 20 mV.
     * |        |          |0010 = VBG_type + 40 mV.
     * |        |          |0011 = VBG_type + 60 mV.
     * |        |          |0100 = VBG_type + 80 mV.
     * |        |          |0101 = VBG_type + 100 mV.
     * |        |          |0110 = VBG_type + 120 mV.
     * |        |          |0111 = VBG_type + 160 mV.
     * |        |          |1000 = VBG_type u2013 20 mV.
     * |        |          |1001 = VBG_type u2013 40 mV.
     * |        |          |1010 = VBG_type u2013 60 mV.
     * |        |          |1011 = VBG_type u2013 80 mV.
     * |        |          |1100 = VBG_type u2013 100 mV.
     * |        |          |1101 = VBG_type u2013 120 mV.
     * |        |          |1110 = VBG_type u2013 140 mV.
     * |        |          |1111 = VBG_type u2013 160 mV.
     * |        |          |Note: VBG_type = 1.0 V.
     * |        |          |Note: Please wait 1ms for the internal reference voltage to stabilize after setting REFADJ(EADC_REFADJCTL[4:1]).
     * @var EADC_T::SETCTL
     * Offset: 0x160  EADC Set Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[7:0]   |EADCSET   |EADC Set Control
     * |        |          |Reserved configuration signals.
     * @var EADC_T::WRBCTL
     * Offset: 0x164  EADC WRB Select Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[1:0]   |WRBSEL    |EADC WRB Select Option
     * |        |          |EADC WRB (Start of conversion) can be selected by WRBSEL.
     * |        |          |00 = WRB is one EADC_CLK period wide and it active on EADC_CLK rising to rising.
     * |        |          |01 = WRB is one EADC_CLK period wide and it active on EADC_CLK falling to falling.
     * |        |          |10 = WRB is one EADC_CLK period wide and it active on EADC_CLK falling to falling
     * |        |          |The WRB will be one EADC_CLK later than when WRBSEL select to 2u2019b01.
     * |        |          |11 = WRB is two EADC_CLK period wide and it active on EADC_CLK falling to falling.
     * @var EADC_T::SMCTL0
     * Offset: 0x180  EADC Sample Module 0 Control Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ALIGN     |Alignment Selection
     * |        |          |0 = The conversion result will be right aligned in data register.
     * |        |          |1 = The conversion result will be left aligned in data register.
     * |[1]     |AVG       |Average Mode Selection
     * |        |          |0 = Conversion results will be stored in data register without averaging.
     * |        |          |1 = Conversion results in data register will be averaged.
     * |        |          |Note: This bit needs to work with ACU (EADC_SMCTLn[7:4], n=0~7).
     * |[7:4]   |ACU       |Number of Accumulated Conversion Results Selection
     * |        |          |0000 = 1 conversion result will be accumulated.
     * |        |          |0001 = 2 conversion result will be accumulated.
     * |        |          |0010 = 4 conversion result will be accumulated.
     * |        |          |0011 = 8 conversion result will be accumulated.
     * |        |          |0100 = 16 conversion result will be accumulated.
     * |        |          |0101 = 32 conversion result will be accumulated.
     * |        |          |0110 = 64 conversion result will be accumulated.
     * |        |          |0111 = 128 conversion result will be accumulated.
     * |        |          |1000 = 256 conversion result will be accumulated.
     * |        |          |Others = Reserved.
     * @var EADC_T::SMCTL1
     * Offset: 0x184  EADC Sample Module 1 Control Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ALIGN     |Alignment Selection
     * |        |          |0 = The conversion result will be right aligned in data register.
     * |        |          |1 = The conversion result will be left aligned in data register.
     * |[1]     |AVG       |Average Mode Selection
     * |        |          |0 = Conversion results will be stored in data register without averaging.
     * |        |          |1 = Conversion results in data register will be averaged.
     * |        |          |Note: This bit needs to work with ACU (EADC_SMCTLn[7:4], n=0~7).
     * |[7:4]   |ACU       |Number of Accumulated Conversion Results Selection
     * |        |          |0000 = 1 conversion result will be accumulated.
     * |        |          |0001 = 2 conversion result will be accumulated.
     * |        |          |0010 = 4 conversion result will be accumulated.
     * |        |          |0011 = 8 conversion result will be accumulated.
     * |        |          |0100 = 16 conversion result will be accumulated.
     * |        |          |0101 = 32 conversion result will be accumulated.
     * |        |          |0110 = 64 conversion result will be accumulated.
     * |        |          |0111 = 128 conversion result will be accumulated.
     * |        |          |1000 = 256 conversion result will be accumulated.
     * |        |          |Others = Reserved.
     * @var EADC_T::SMCTL2
     * Offset: 0x188  EADC Sample Module 2 Control Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ALIGN     |Alignment Selection
     * |        |          |0 = The conversion result will be right aligned in data register.
     * |        |          |1 = The conversion result will be left aligned in data register.
     * |[1]     |AVG       |Average Mode Selection
     * |        |          |0 = Conversion results will be stored in data register without averaging.
     * |        |          |1 = Conversion results in data register will be averaged.
     * |        |          |Note: This bit needs to work with ACU (EADC_SMCTLn[7:4], n=0~7).
     * |[7:4]   |ACU       |Number of Accumulated Conversion Results Selection
     * |        |          |0000 = 1 conversion result will be accumulated.
     * |        |          |0001 = 2 conversion result will be accumulated.
     * |        |          |0010 = 4 conversion result will be accumulated.
     * |        |          |0011 = 8 conversion result will be accumulated.
     * |        |          |0100 = 16 conversion result will be accumulated.
     * |        |          |0101 = 32 conversion result will be accumulated.
     * |        |          |0110 = 64 conversion result will be accumulated.
     * |        |          |0111 = 128 conversion result will be accumulated.
     * |        |          |1000 = 256 conversion result will be accumulated.
     * |        |          |Others = Reserved.
     * @var EADC_T::SMCTL3
     * Offset: 0x18C  EADC Sample Module 3 Control Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ALIGN     |Alignment Selection
     * |        |          |0 = The conversion result will be right aligned in data register.
     * |        |          |1 = The conversion result will be left aligned in data register.
     * |[1]     |AVG       |Average Mode Selection
     * |        |          |0 = Conversion results will be stored in data register without averaging.
     * |        |          |1 = Conversion results in data register will be averaged.
     * |        |          |Note: This bit needs to work with ACU (EADC_SMCTLn[7:4], n=0~7).
     * |[7:4]   |ACU       |Number of Accumulated Conversion Results Selection
     * |        |          |0000 = 1 conversion result will be accumulated.
     * |        |          |0001 = 2 conversion result will be accumulated.
     * |        |          |0010 = 4 conversion result will be accumulated.
     * |        |          |0011 = 8 conversion result will be accumulated.
     * |        |          |0100 = 16 conversion result will be accumulated.
     * |        |          |0101 = 32 conversion result will be accumulated.
     * |        |          |0110 = 64 conversion result will be accumulated.
     * |        |          |0111 = 128 conversion result will be accumulated.
     * |        |          |1000 = 256 conversion result will be accumulated.
     * |        |          |Others = Reserved.
     * @var EADC_T::SMCTL4
     * Offset: 0x190  EADC Sample Module 4 Control Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ALIGN     |Alignment Selection
     * |        |          |0 = The conversion result will be right aligned in data register.
     * |        |          |1 = The conversion result will be left aligned in data register.
     * |[1]     |AVG       |Average Mode Selection
     * |        |          |0 = Conversion results will be stored in data register without averaging.
     * |        |          |1 = Conversion results in data register will be averaged.
     * |        |          |Note: This bit needs to work with ACU (EADC_SMCTLn[7:4], n=0~7).
     * |[7:4]   |ACU       |Number of Accumulated Conversion Results Selection
     * |        |          |0000 = 1 conversion result will be accumulated.
     * |        |          |0001 = 2 conversion result will be accumulated.
     * |        |          |0010 = 4 conversion result will be accumulated.
     * |        |          |0011 = 8 conversion result will be accumulated.
     * |        |          |0100 = 16 conversion result will be accumulated.
     * |        |          |0101 = 32 conversion result will be accumulated.
     * |        |          |0110 = 64 conversion result will be accumulated.
     * |        |          |0111 = 128 conversion result will be accumulated.
     * |        |          |1000 = 256 conversion result will be accumulated.
     * |        |          |Others = Reserved.
     * @var EADC_T::SMCTL5
     * Offset: 0x194  EADC Sample Module 5 Control Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ALIGN     |Alignment Selection
     * |        |          |0 = The conversion result will be right aligned in data register.
     * |        |          |1 = The conversion result will be left aligned in data register.
     * |[1]     |AVG       |Average Mode Selection
     * |        |          |0 = Conversion results will be stored in data register without averaging.
     * |        |          |1 = Conversion results in data register will be averaged.
     * |        |          |Note: This bit needs to work with ACU (EADC_SMCTLn[7:4], n=0~7).
     * |[7:4]   |ACU       |Number of Accumulated Conversion Results Selection
     * |        |          |0000 = 1 conversion result will be accumulated.
     * |        |          |0001 = 2 conversion result will be accumulated.
     * |        |          |0010 = 4 conversion result will be accumulated.
     * |        |          |0011 = 8 conversion result will be accumulated.
     * |        |          |0100 = 16 conversion result will be accumulated.
     * |        |          |0101 = 32 conversion result will be accumulated.
     * |        |          |0110 = 64 conversion result will be accumulated.
     * |        |          |0111 = 128 conversion result will be accumulated.
     * |        |          |1000 = 256 conversion result will be accumulated.
     * |        |          |Others = Reserved.
     * @var EADC_T::SMCTL6
     * Offset: 0x198  EADC Sample Module 6 Control Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ALIGN     |Alignment Selection
     * |        |          |0 = The conversion result will be right aligned in data register.
     * |        |          |1 = The conversion result will be left aligned in data register.
     * |[1]     |AVG       |Average Mode Selection
     * |        |          |0 = Conversion results will be stored in data register without averaging.
     * |        |          |1 = Conversion results in data register will be averaged.
     * |        |          |Note: This bit needs to work with ACU (EADC_SMCTLn[7:4], n=0~7).
     * |[7:4]   |ACU       |Number of Accumulated Conversion Results Selection
     * |        |          |0000 = 1 conversion result will be accumulated.
     * |        |          |0001 = 2 conversion result will be accumulated.
     * |        |          |0010 = 4 conversion result will be accumulated.
     * |        |          |0011 = 8 conversion result will be accumulated.
     * |        |          |0100 = 16 conversion result will be accumulated.
     * |        |          |0101 = 32 conversion result will be accumulated.
     * |        |          |0110 = 64 conversion result will be accumulated.
     * |        |          |0111 = 128 conversion result will be accumulated.
     * |        |          |1000 = 256 conversion result will be accumulated.
     * |        |          |Others = Reserved.
     * @var EADC_T::SMCTL7
     * Offset: 0x19C  EADC Sample Module 7 Control Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ALIGN     |Alignment Selection
     * |        |          |0 = The conversion result will be right aligned in data register.
     * |        |          |1 = The conversion result will be left aligned in data register.
     * |[1]     |AVG       |Average Mode Selection
     * |        |          |0 = Conversion results will be stored in data register without averaging.
     * |        |          |1 = Conversion results in data register will be averaged.
     * |        |          |Note: This bit needs to work with ACU (EADC_SMCTLn[7:4], n=0~7).
     * |[7:4]   |ACU       |Number of Accumulated Conversion Results Selection
     * |        |          |0000 = 1 conversion result will be accumulated.
     * |        |          |0001 = 2 conversion result will be accumulated.
     * |        |          |0010 = 4 conversion result will be accumulated.
     * |        |          |0011 = 8 conversion result will be accumulated.
     * |        |          |0100 = 16 conversion result will be accumulated.
     * |        |          |0101 = 32 conversion result will be accumulated.
     * |        |          |0110 = 64 conversion result will be accumulated.
     * |        |          |0111 = 128 conversion result will be accumulated.
     * |        |          |1000 = 256 conversion result will be accumulated.
     * |        |          |Others = Reserved.
     * @var EADC_T::TEST
     * Offset: 0x200  EADC Test Mode Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |PCHSEN    |EADC Pre-channel Switch Enable Control
     * |        |          |0 = The next channel select will be active at the end of conversion.
     * |        |          |1 = The next channel select will be active at the last PCHSEN conversion cycle.
     * |[6:4]   |PCHSSEL   |EADC Pre-channel Switch Select
     * |        |          |This register defined the pre-channel switch cycles (0~7 EADC _CLK).
     * @var EADC_T::VERSION
     * Offset: 0xFFC  EADC RTL Design Version Number
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |MINOR     |RTL Design MINOR Version Number
     * |        |          |Minor version number is dependent on ECO version control.
     * |        |          |0x0000: (current Minor Version Number).
     * |[23:16] |SUB       |RTL Design SUB Version Number
     * |        |          |Sub version number is relative to key feature.
     * |        |          |0x02: (current Sub Version Number).
     * |[31:24] |MAJOR     |RTL Design MAJOR Version Number
     * |        |          |Major version number is correlated to Product Line.
     * |        |          |0x02: (current Major Version Number).
     */
    __I  uint32_t DAT0;                  /*!< [0x0000] EADC Data Register 0 for Sample Module 0                         */
    __I  uint32_t DAT1;                  /*!< [0x0004] EADC Data Register 1 for Sample Module 1                         */
    __I  uint32_t DAT2;                  /*!< [0x0008] EADC Data Register 2 for Sample Module 2                         */
    __I  uint32_t DAT3;                  /*!< [0x000c] EADC Data Register 3 for Sample Module 3                         */
    __I  uint32_t DAT4;                  /*!< [0x0010] EADC Data Register 4 for Sample Module 4                         */
    __I  uint32_t DAT5;                  /*!< [0x0014] EADC Data Register 5 for Sample Module 5                         */
    __I  uint32_t DAT6;                  /*!< [0x0018] EADC Data Register 6 for Sample Module 6                         */
    __I  uint32_t DAT7;                  /*!< [0x001c] EADC Data Register 7 for Sample Module 7                         */
    __I  uint32_t DAT8;                  /*!< [0x0020] EADC Data Register 8 for Sample Module 8                         */
    __I  uint32_t RESERVE0[10];
    __I  uint32_t CURDAT;                /*!< [0x004c] EADC PDMA Current Transfer Data Register                         */
    __IO uint32_t CTL;                   /*!< [0x0050] EADC Control Register                                            */
    __O  uint32_t SWTRG;                 /*!< [0x0054] EADC Sample Module Software Start Register                       */
    __IO uint32_t PENDSTS;               /*!< [0x0058] EADC Start of Conversion Pending Flag Register                   */
    __IO uint32_t OVSTS;                 /*!< [0x005c] EADC Sample Module Start of Conversion Overrun Flag Register     */
    __I  uint32_t RESERVE1[7];
    __IO uint32_t SELFTCTL;              /*!< [0x007c] EADC Self Test Control Register                                  */
    __IO uint32_t SCTL0;                 /*!< [0x0080] EADC Sample Module 0 Control Register                            */
    __IO uint32_t SCTL1;                 /*!< [0x0084] EADC Sample Module 1 Control Register                            */
    __IO uint32_t SCTL2;                 /*!< [0x0088] EADC Sample Module 2 Control Register                            */
    __IO uint32_t SCTL3;                 /*!< [0x008c] EADC Sample Module 3 Control Register                            */
    __IO uint32_t SCTL4;                 /*!< [0x0090] EADC Sample Module 4 Control Register                            */
    __IO uint32_t SCTL5;                 /*!< [0x0094] EADC Sample Module 5 Control Register                            */
    __IO uint32_t SCTL6;                 /*!< [0x0098] EADC Sample Module 6 Control Register                            */
    __IO uint32_t SCTL7;                 /*!< [0x009c] EADC Sample Module 7 Control Register                            */
    __IO uint32_t SCTL8;                 /*!< [0x00a0] EADC Sample Module 8 Control Register                            */
    __I  uint32_t RESERVE2[11];
    __IO uint32_t INTSRC0;               /*!< [0x00d0] EADC Interrupt 0 Source Enable Control Register.                 */
    __IO uint32_t INTSRC1;               /*!< [0x00d4] EADC Interrupt 1 Source Enable Control Register.                 */
    __IO uint32_t INTSRC2;               /*!< [0x00d8] EADC Interrupt 2 Source Enable Control Register.                 */
    __IO uint32_t INTSRC3;               /*!< [0x00dc] EADC Interrupt 3 Source Enable Control Register.                 */
    __IO uint32_t CMP0;                  /*!< [0x00e0] EADC Result Compare Register 0                                   */
    __IO uint32_t CMP1;                  /*!< [0x00e4] EADC Result Compare Register 1                                   */
    __IO uint32_t CMP2;                  /*!< [0x00e8] EADC Result Compare Register 2                                   */
    __IO uint32_t CMP3;                  /*!< [0x00ec] EADC Result Compare Register 3                                   */
    __I  uint32_t STATUS0;               /*!< [0x00f0] EADC Status Register 0                                           */
    __IO uint32_t STATUS1;               /*!< [0x00f4] EADC Status Register 1                                           */
    __IO uint32_t STATUS2;               /*!< [0x00f8] EADC Status Register 2                                           */
    __I  uint32_t STATUS3;               /*!< [0x00fc] EADC Status Register 3                                           */
    __I  uint32_t DDAT0;                 /*!< [0x0100] EADC Double Data Register 0 for Sample Module 0                  */
    __I  uint32_t DDAT1;                 /*!< [0x0104] EADC Double Data Register 1 for Sample Module 1                  */
    __I  uint32_t DDAT2;                 /*!< [0x0108] EADC Double Data Register 2 for Sample Module 2                  */
    __I  uint32_t DDAT3;                 /*!< [0x010c] EADC Double Data Register 3 for Sample Module 3                  */
    __IO uint32_t PWRM;                  /*!< [0x0110] EADC Power Management Register                                   */
    __IO uint32_t CALCTL;                /*!< [0x0114] EADC Calibration Control Register                                */
    __I  uint32_t RESERVE3[6];
    __IO uint32_t PDMACTL;               /*!< [0x0130] EADC PDMA Control Register                                       */
    __I  uint32_t FIFOSTS;               /*!< [0x0134] EADC FIFO Status Register                                        */
    __IO uint32_t FIFODEBUG;             /*!< [0x0138] EADC FIFO Debug Register                                         */
    __I  uint32_t RESERVE4[1];
    __IO uint32_t SELSMP0;               /*!< [0x0140] EADC Select Sampling Time Register 0                             */
    __IO uint32_t SELSMP1;               /*!< [0x0144] EADC Select Sampling Time Register 1                             */
    __I  uint32_t RESERVE5[2];
    __IO uint32_t REFADJCTL;             /*!< [0x0150] EADC Reference Voltage Adjust Control Register                   */
    __I  uint32_t RESERVE6[3];
    __IO uint32_t SETCTL;                /*!< [0x0160] EADC Set Control Register                                        */
    __IO uint32_t WRBCTL;                /*!< [0x0164] EADC WRB Select Control Register                                 */
    __I  uint32_t RESERVE7[6];
    __IO uint32_t SMCTL0;                /*!< [0x0180] EADC Sample Module 0 Control Register 1                          */
    __IO uint32_t SMCTL1;                /*!< [0x0184] EADC Sample Module 1 Control Register 1                          */
    __IO uint32_t SMCTL2;                /*!< [0x0188] EADC Sample Module 2 Control Register 1                          */
    __IO uint32_t SMCTL3;                /*!< [0x018c] EADC Sample Module 3 Control Register 1                          */
    __IO uint32_t SMCTL4;                /*!< [0x0190] EADC Sample Module 4 Control Register 1                          */
    __IO uint32_t SMCTL5;                /*!< [0x0194] EADC Sample Module 5 Control Register 1                          */
    __IO uint32_t SMCTL6;                /*!< [0x0198] EADC Sample Module 6 Control Register 1                          */
    __IO uint32_t SMCTL7;                /*!< [0x019c] EADC Sample Module 7 Control Register 1                          */
    __I  uint32_t RESERVE8[24];
    __IO uint32_t TEST;                  /*!< [0x0200] EADC Test Mode Control Register                                  */
    __I  uint32_t RESERVE9[894];
    __I  uint32_t VERSION;               /*!< [0x0ffc] EADC RTL Design Version Number                                   */

} EADC_T;

/**
    @addtogroup EADC_CONST EADC Bit Field Definition
    Constant Definitions for EADC Controller
@{ */

#define EADC_DAT0_RESULT_Pos             (0)                                               /*!< EADC_T::DAT0: RESULT Position          */
#define EADC_DAT0_RESULT_Msk             (0xfffful << EADC_DAT0_RESULT_Pos)                /*!< EADC_T::DAT0: RESULT Mask              */

#define EADC_DAT0_OV_Pos                 (16)                                              /*!< EADC_T::DAT0: OV Position              */
#define EADC_DAT0_OV_Msk                 (0x1ul << EADC_DAT0_OV_Pos)                       /*!< EADC_T::DAT0: OV Mask                  */

#define EADC_DAT0_VALID_Pos              (17)                                              /*!< EADC_T::DAT0: VALID Position           */
#define EADC_DAT0_VALID_Msk              (0x1ul << EADC_DAT0_VALID_Pos)                    /*!< EADC_T::DAT0: VALID Mask               */

#define EADC_DAT1_RESULT_Pos             (0)                                               /*!< EADC_T::DAT1: RESULT Position          */
#define EADC_DAT1_RESULT_Msk             (0xfffful << EADC_DAT1_RESULT_Pos)                /*!< EADC_T::DAT1: RESULT Mask              */

#define EADC_DAT1_OV_Pos                 (16)                                              /*!< EADC_T::DAT1: OV Position              */
#define EADC_DAT1_OV_Msk                 (0x1ul << EADC_DAT1_OV_Pos)                       /*!< EADC_T::DAT1: OV Mask                  */

#define EADC_DAT1_VALID_Pos              (17)                                              /*!< EADC_T::DAT1: VALID Position           */
#define EADC_DAT1_VALID_Msk              (0x1ul << EADC_DAT1_VALID_Pos)                    /*!< EADC_T::DAT1: VALID Mask               */

#define EADC_DAT2_RESULT_Pos             (0)                                               /*!< EADC_T::DAT2: RESULT Position          */
#define EADC_DAT2_RESULT_Msk             (0xfffful << EADC_DAT2_RESULT_Pos)                /*!< EADC_T::DAT2: RESULT Mask              */

#define EADC_DAT2_OV_Pos                 (16)                                              /*!< EADC_T::DAT2: OV Position              */
#define EADC_DAT2_OV_Msk                 (0x1ul << EADC_DAT2_OV_Pos)                       /*!< EADC_T::DAT2: OV Mask                  */

#define EADC_DAT2_VALID_Pos              (17)                                              /*!< EADC_T::DAT2: VALID Position           */
#define EADC_DAT2_VALID_Msk              (0x1ul << EADC_DAT2_VALID_Pos)                    /*!< EADC_T::DAT2: VALID Mask               */

#define EADC_DAT3_RESULT_Pos             (0)                                               /*!< EADC_T::DAT3: RESULT Position          */
#define EADC_DAT3_RESULT_Msk             (0xfffful << EADC_DAT3_RESULT_Pos)                /*!< EADC_T::DAT3: RESULT Mask              */

#define EADC_DAT3_OV_Pos                 (16)                                              /*!< EADC_T::DAT3: OV Position              */
#define EADC_DAT3_OV_Msk                 (0x1ul << EADC_DAT3_OV_Pos)                       /*!< EADC_T::DAT3: OV Mask                  */

#define EADC_DAT3_VALID_Pos              (17)                                              /*!< EADC_T::DAT3: VALID Position           */
#define EADC_DAT3_VALID_Msk              (0x1ul << EADC_DAT3_VALID_Pos)                    /*!< EADC_T::DAT3: VALID Mask               */

#define EADC_DAT4_RESULT_Pos             (0)                                               /*!< EADC_T::DAT4: RESULT Position          */
#define EADC_DAT4_RESULT_Msk             (0xfffful << EADC_DAT4_RESULT_Pos)                /*!< EADC_T::DAT4: RESULT Mask              */

#define EADC_DAT4_OV_Pos                 (16)                                              /*!< EADC_T::DAT4: OV Position              */
#define EADC_DAT4_OV_Msk                 (0x1ul << EADC_DAT4_OV_Pos)                       /*!< EADC_T::DAT4: OV Mask                  */

#define EADC_DAT4_VALID_Pos              (17)                                              /*!< EADC_T::DAT4: VALID Position           */
#define EADC_DAT4_VALID_Msk              (0x1ul << EADC_DAT4_VALID_Pos)                    /*!< EADC_T::DAT4: VALID Mask               */

#define EADC_DAT5_RESULT_Pos             (0)                                               /*!< EADC_T::DAT5: RESULT Position          */
#define EADC_DAT5_RESULT_Msk             (0xfffful << EADC_DAT5_RESULT_Pos)                /*!< EADC_T::DAT5: RESULT Mask              */

#define EADC_DAT5_OV_Pos                 (16)                                              /*!< EADC_T::DAT5: OV Position              */
#define EADC_DAT5_OV_Msk                 (0x1ul << EADC_DAT5_OV_Pos)                       /*!< EADC_T::DAT5: OV Mask                  */

#define EADC_DAT5_VALID_Pos              (17)                                              /*!< EADC_T::DAT5: VALID Position           */
#define EADC_DAT5_VALID_Msk              (0x1ul << EADC_DAT5_VALID_Pos)                    /*!< EADC_T::DAT5: VALID Mask               */

#define EADC_DAT6_RESULT_Pos             (0)                                               /*!< EADC_T::DAT6: RESULT Position          */
#define EADC_DAT6_RESULT_Msk             (0xfffful << EADC_DAT6_RESULT_Pos)                /*!< EADC_T::DAT6: RESULT Mask              */

#define EADC_DAT6_OV_Pos                 (16)                                              /*!< EADC_T::DAT6: OV Position              */
#define EADC_DAT6_OV_Msk                 (0x1ul << EADC_DAT6_OV_Pos)                       /*!< EADC_T::DAT6: OV Mask                  */

#define EADC_DAT6_VALID_Pos              (17)                                              /*!< EADC_T::DAT6: VALID Position           */
#define EADC_DAT6_VALID_Msk              (0x1ul << EADC_DAT6_VALID_Pos)                    /*!< EADC_T::DAT6: VALID Mask               */

#define EADC_DAT7_RESULT_Pos             (0)                                               /*!< EADC_T::DAT7: RESULT Position          */
#define EADC_DAT7_RESULT_Msk             (0xfffful << EADC_DAT7_RESULT_Pos)                /*!< EADC_T::DAT7: RESULT Mask              */

#define EADC_DAT7_OV_Pos                 (16)                                              /*!< EADC_T::DAT7: OV Position              */
#define EADC_DAT7_OV_Msk                 (0x1ul << EADC_DAT7_OV_Pos)                       /*!< EADC_T::DAT7: OV Mask                  */

#define EADC_DAT7_VALID_Pos              (17)                                              /*!< EADC_T::DAT7: VALID Position           */
#define EADC_DAT7_VALID_Msk              (0x1ul << EADC_DAT7_VALID_Pos)                    /*!< EADC_T::DAT7: VALID Mask               */

#define EADC_DAT8_RESULT_Pos             (0)                                               /*!< EADC_T::DAT8: RESULT Position          */
#define EADC_DAT8_RESULT_Msk             (0xfffful << EADC_DAT8_RESULT_Pos)                /*!< EADC_T::DAT8: RESULT Mask              */

#define EADC_DAT8_OV_Pos                 (16)                                              /*!< EADC_T::DAT8: OV Position              */
#define EADC_DAT8_OV_Msk                 (0x1ul << EADC_DAT8_OV_Pos)                       /*!< EADC_T::DAT8: OV Mask                  */

#define EADC_DAT8_VALID_Pos              (17)                                              /*!< EADC_T::DAT8: VALID Position           */
#define EADC_DAT8_VALID_Msk              (0x1ul << EADC_DAT8_VALID_Pos)                    /*!< EADC_T::DAT8: VALID Mask               */

#define EADC_CURDAT_CURDAT0_Pos          (0)                                               /*!< EADC_T::CURDAT: CURDAT0 Position       */
#define EADC_CURDAT_CURDAT0_Msk          (0xfffful << EADC_CURDAT_CURDAT0_Pos)             /*!< EADC_T::CURDAT: CURDAT0 Mask           */

#define EADC_CURDAT_CURDAT1_Pos          (16)                                              /*!< EADC_T::CURDAT: CURDAT1 Position       */
#define EADC_CURDAT_CURDAT1_Msk          (0xfffful << EADC_CURDAT_CURDAT1_Pos)             /*!< EADC_T::CURDAT: CURDAT1 Mask           */

#define EADC_CTL_EADCEN_Pos              (0)                                               /*!< EADC_T::CTL: EADCEN Position           */
#define EADC_CTL_EADCEN_Msk              (0x1ul << EADC_CTL_EADCEN_Pos)                    /*!< EADC_T::CTL: EADCEN Mask               */

#define EADC_CTL_EADCRST_Pos             (1)                                               /*!< EADC_T::CTL: EADCRST Position          */
#define EADC_CTL_EADCRST_Msk             (0x1ul << EADC_CTL_EADCRST_Pos)                   /*!< EADC_T::CTL: EADCRST Mask              */

#define EADC_CTL_EADCIEN0_Pos            (2)                                               /*!< EADC_T::CTL: EADCIEN0 Position         */
#define EADC_CTL_EADCIEN0_Msk            (0x1ul << EADC_CTL_EADCIEN0_Pos)                  /*!< EADC_T::CTL: EADCIEN0 Mask             */

#define EADC_CTL_EADCIEN1_Pos            (3)                                               /*!< EADC_T::CTL: EADCIEN1 Position         */
#define EADC_CTL_EADCIEN1_Msk            (0x1ul << EADC_CTL_EADCIEN1_Pos)                  /*!< EADC_T::CTL: EADCIEN1 Mask             */

#define EADC_CTL_EADCIEN2_Pos            (4)                                               /*!< EADC_T::CTL: EADCIEN2 Position         */
#define EADC_CTL_EADCIEN2_Msk            (0x1ul << EADC_CTL_EADCIEN2_Pos)                  /*!< EADC_T::CTL: EADCIEN2 Mask             */

#define EADC_CTL_EADCIEN3_Pos            (5)                                               /*!< EADC_T::CTL: EADCIEN3 Position         */
#define EADC_CTL_EADCIEN3_Msk            (0x1ul << EADC_CTL_EADCIEN3_Pos)                  /*!< EADC_T::CTL: EADCIEN3 Mask             */

#define EADC_CTL_RES_Pos                 (6)                                               /*!< EADC_T::CTL: RES Position              */
#define EADC_CTL_RES_Msk                 (0x3ul << EADC_CTL_RES_Pos)                       /*!< EADC_T::CTL: RES Mask                  */

#define EADC_CTL_DIFFEN_Pos              (8)                                               /*!< EADC_T::CTL: DIFFEN Position           */
#define EADC_CTL_DIFFEN_Msk              (0x1ul << EADC_CTL_DIFFEN_Pos)                    /*!< EADC_T::CTL: DIFFEN Mask               */

#define EADC_CTL_DMOF_Pos                (9)                                               /*!< EADC_T::CTL: DMOF Position             */
#define EADC_CTL_DMOF_Msk                (0x1ul << EADC_CTL_DMOF_Pos)                      /*!< EADC_T::CTL: DMOF Mask                 */

#define EADC_CTL_VREFSEL_Pos             (10)                                              /*!< EADC_T::CTL: VREFSEL Position          */
#define EADC_CTL_VREFSEL_Msk             (0x1ul << EADC_CTL_VREFSEL_Pos)                   /*!< EADC_T::CTL: VREFSEL Mask              */

#define EADC_CTL_SPEED_Pos               (12)                                              /*!< EADC_T::CTL: SPEED Position            */
#define EADC_CTL_SPEED_Msk               (0x1ul << EADC_CTL_SPEED_Pos)                     /*!< EADC_T::CTL: SPEED Mask                */

#define EADC_CTL_FFTDIEN_Pos             (13)                                              /*!< EADC_T::CTL: FFTDIEN Position          */
#define EADC_CTL_FFTDIEN_Msk             (0x1ul << EADC_CTL_FFTDIEN_Pos)                   /*!< EADC_T::CTL: FFTDIEN Mask              */

#define EADC_SWTRG_SWTRG_Pos             (0)                                               /*!< EADC_T::SWTRG: SWTRG Position          */
#define EADC_SWTRG_SWTRG_Msk             (0x1fful << EADC_SWTRG_SWTRG_Pos)                 /*!< EADC_T::SWTRG: SWTRG Mask              */

#define EADC_PENDSTS_STPF_Pos            (0)                                               /*!< EADC_T::PENDSTS: STPF Position         */
#define EADC_PENDSTS_STPF_Msk            (0x1fful << EADC_PENDSTS_STPF_Pos)                /*!< EADC_T::PENDSTS: STPF Mask             */

#define EADC_OVSTS_SPOVF_Pos             (0)                                               /*!< EADC_T::OVSTS: SPOVF Position          */
#define EADC_OVSTS_SPOVF_Msk             (0x1fful << EADC_OVSTS_SPOVF_Pos)                 /*!< EADC_T::OVSTS: SPOVF Mask              */

#define EADC_SELFTCTL_SELFTEN_Pos        (0)                                               /*!< EADC_T::SELFTCTL: SELFTEN Position     */
#define EADC_SELFTCTL_SELFTEN_Msk        (0x1ul << EADC_SELFTCTL_SELFTEN_Pos)              /*!< EADC_T::SELFTCTL: SELFTEN Mask         */

#define EADC_SCTL0_CHSEL_Pos             (0)                                               /*!< EADC_T::SCTL0: CHSEL Position          */
#define EADC_SCTL0_CHSEL_Msk             (0xful << EADC_SCTL0_CHSEL_Pos)                   /*!< EADC_T::SCTL0: CHSEL Mask              */

#define EADC_SCTL0_EXTREN_Pos            (4)                                               /*!< EADC_T::SCTL0: EXTREN Position         */
#define EADC_SCTL0_EXTREN_Msk            (0x1ul << EADC_SCTL0_EXTREN_Pos)                  /*!< EADC_T::SCTL0: EXTREN Mask             */

#define EADC_SCTL0_EXTFEN_Pos            (5)                                               /*!< EADC_T::SCTL0: EXTFEN Position         */
#define EADC_SCTL0_EXTFEN_Msk            (0x1ul << EADC_SCTL0_EXTFEN_Pos)                  /*!< EADC_T::SCTL0: EXTFEN Mask             */

#define EADC_SCTL0_TRGDLYDIV_Pos         (6)                                               /*!< EADC_T::SCTL0: TRGDLYDIV Position      */
#define EADC_SCTL0_TRGDLYDIV_Msk         (0x3ul << EADC_SCTL0_TRGDLYDIV_Pos)               /*!< EADC_T::SCTL0: TRGDLYDIV Mask          */

#define EADC_SCTL0_TRGDLYCNT_Pos         (8)                                               /*!< EADC_T::SCTL0: TRGDLYCNT Position      */
#define EADC_SCTL0_TRGDLYCNT_Msk         (0xfful << EADC_SCTL0_TRGDLYCNT_Pos)              /*!< EADC_T::SCTL0: TRGDLYCNT Mask          */

#define EADC_SCTL0_TRGSEL_Pos            (16)                                              /*!< EADC_T::SCTL0: TRGSEL Position         */
#define EADC_SCTL0_TRGSEL_Msk            (0x3ful << EADC_SCTL0_TRGSEL_Pos)                 /*!< EADC_T::SCTL0: TRGSEL Mask             */

#define EADC_SCTL0_INTPOS_Pos            (22)                                              /*!< EADC_T::SCTL0: INTPOS Position         */
#define EADC_SCTL0_INTPOS_Msk            (0x1ul << EADC_SCTL0_INTPOS_Pos)                  /*!< EADC_T::SCTL0: INTPOS Mask             */

#define EADC_SCTL0_DBMEN_Pos             (23)                                              /*!< EADC_T::SCTL0: DBMEN Position          */
#define EADC_SCTL0_DBMEN_Msk             (0x1ul << EADC_SCTL0_DBMEN_Pos)                   /*!< EADC_T::SCTL0: DBMEN Mask              */

#define EADC_SCTL0_EXTSMPT_Pos           (24)                                              /*!< EADC_T::SCTL0: EXTSMPT Position        */
#define EADC_SCTL0_EXTSMPT_Msk           (0xfful << EADC_SCTL0_EXTSMPT_Pos)                /*!< EADC_T::SCTL0: EXTSMPT Mask            */

#define EADC_SCTL1_CHSEL_Pos             (0)                                               /*!< EADC_T::SCTL1: CHSEL Position          */
#define EADC_SCTL1_CHSEL_Msk             (0xful << EADC_SCTL1_CHSEL_Pos)                   /*!< EADC_T::SCTL1: CHSEL Mask              */

#define EADC_SCTL1_EXTREN_Pos            (4)                                               /*!< EADC_T::SCTL1: EXTREN Position         */
#define EADC_SCTL1_EXTREN_Msk            (0x1ul << EADC_SCTL1_EXTREN_Pos)                  /*!< EADC_T::SCTL1: EXTREN Mask             */

#define EADC_SCTL1_EXTFEN_Pos            (5)                                               /*!< EADC_T::SCTL1: EXTFEN Position         */
#define EADC_SCTL1_EXTFEN_Msk            (0x1ul << EADC_SCTL1_EXTFEN_Pos)                  /*!< EADC_T::SCTL1: EXTFEN Mask             */

#define EADC_SCTL1_TRGDLYDIV_Pos         (6)                                               /*!< EADC_T::SCTL1: TRGDLYDIV Position      */
#define EADC_SCTL1_TRGDLYDIV_Msk         (0x3ul << EADC_SCTL1_TRGDLYDIV_Pos)               /*!< EADC_T::SCTL1: TRGDLYDIV Mask          */

#define EADC_SCTL1_TRGDLYCNT_Pos         (8)                                               /*!< EADC_T::SCTL1: TRGDLYCNT Position      */
#define EADC_SCTL1_TRGDLYCNT_Msk         (0xfful << EADC_SCTL1_TRGDLYCNT_Pos)              /*!< EADC_T::SCTL1: TRGDLYCNT Mask          */

#define EADC_SCTL1_TRGSEL_Pos            (16)                                              /*!< EADC_T::SCTL1: TRGSEL Position         */
#define EADC_SCTL1_TRGSEL_Msk            (0x3ful << EADC_SCTL1_TRGSEL_Pos)                 /*!< EADC_T::SCTL1: TRGSEL Mask             */

#define EADC_SCTL1_INTPOS_Pos            (22)                                              /*!< EADC_T::SCTL1: INTPOS Position         */
#define EADC_SCTL1_INTPOS_Msk            (0x1ul << EADC_SCTL1_INTPOS_Pos)                  /*!< EADC_T::SCTL1: INTPOS Mask             */

#define EADC_SCTL1_DBMEN_Pos             (23)                                              /*!< EADC_T::SCTL1: DBMEN Position          */
#define EADC_SCTL1_DBMEN_Msk             (0x1ul << EADC_SCTL1_DBMEN_Pos)                   /*!< EADC_T::SCTL1: DBMEN Mask              */

#define EADC_SCTL1_EXTSMPT_Pos           (24)                                              /*!< EADC_T::SCTL1: EXTSMPT Position        */
#define EADC_SCTL1_EXTSMPT_Msk           (0xfful << EADC_SCTL1_EXTSMPT_Pos)                /*!< EADC_T::SCTL1: EXTSMPT Mask            */

#define EADC_SCTL2_CHSEL_Pos             (0)                                               /*!< EADC_T::SCTL2: CHSEL Position          */
#define EADC_SCTL2_CHSEL_Msk             (0xful << EADC_SCTL2_CHSEL_Pos)                   /*!< EADC_T::SCTL2: CHSEL Mask              */

#define EADC_SCTL2_EXTREN_Pos            (4)                                               /*!< EADC_T::SCTL2: EXTREN Position         */
#define EADC_SCTL2_EXTREN_Msk            (0x1ul << EADC_SCTL2_EXTREN_Pos)                  /*!< EADC_T::SCTL2: EXTREN Mask             */

#define EADC_SCTL2_EXTFEN_Pos            (5)                                               /*!< EADC_T::SCTL2: EXTFEN Position         */
#define EADC_SCTL2_EXTFEN_Msk            (0x1ul << EADC_SCTL2_EXTFEN_Pos)                  /*!< EADC_T::SCTL2: EXTFEN Mask             */

#define EADC_SCTL2_TRGDLYDIV_Pos         (6)                                               /*!< EADC_T::SCTL2: TRGDLYDIV Position      */
#define EADC_SCTL2_TRGDLYDIV_Msk         (0x3ul << EADC_SCTL2_TRGDLYDIV_Pos)               /*!< EADC_T::SCTL2: TRGDLYDIV Mask          */

#define EADC_SCTL2_TRGDLYCNT_Pos         (8)                                               /*!< EADC_T::SCTL2: TRGDLYCNT Position      */
#define EADC_SCTL2_TRGDLYCNT_Msk         (0xfful << EADC_SCTL2_TRGDLYCNT_Pos)              /*!< EADC_T::SCTL2: TRGDLYCNT Mask          */

#define EADC_SCTL2_TRGSEL_Pos            (16)                                              /*!< EADC_T::SCTL2: TRGSEL Position         */
#define EADC_SCTL2_TRGSEL_Msk            (0x3ful << EADC_SCTL2_TRGSEL_Pos)                 /*!< EADC_T::SCTL2: TRGSEL Mask             */

#define EADC_SCTL2_INTPOS_Pos            (22)                                              /*!< EADC_T::SCTL2: INTPOS Position         */
#define EADC_SCTL2_INTPOS_Msk            (0x1ul << EADC_SCTL2_INTPOS_Pos)                  /*!< EADC_T::SCTL2: INTPOS Mask             */

#define EADC_SCTL2_DBMEN_Pos             (23)                                              /*!< EADC_T::SCTL2: DBMEN Position          */
#define EADC_SCTL2_DBMEN_Msk             (0x1ul << EADC_SCTL2_DBMEN_Pos)                   /*!< EADC_T::SCTL2: DBMEN Mask              */

#define EADC_SCTL2_EXTSMPT_Pos           (24)                                              /*!< EADC_T::SCTL2: EXTSMPT Position        */
#define EADC_SCTL2_EXTSMPT_Msk           (0xfful << EADC_SCTL2_EXTSMPT_Pos)                /*!< EADC_T::SCTL2: EXTSMPT Mask            */

#define EADC_SCTL3_CHSEL_Pos             (0)                                               /*!< EADC_T::SCTL3: CHSEL Position          */
#define EADC_SCTL3_CHSEL_Msk             (0xful << EADC_SCTL3_CHSEL_Pos)                   /*!< EADC_T::SCTL3: CHSEL Mask              */

#define EADC_SCTL3_EXTREN_Pos            (4)                                               /*!< EADC_T::SCTL3: EXTREN Position         */
#define EADC_SCTL3_EXTREN_Msk            (0x1ul << EADC_SCTL3_EXTREN_Pos)                  /*!< EADC_T::SCTL3: EXTREN Mask             */

#define EADC_SCTL3_EXTFEN_Pos            (5)                                               /*!< EADC_T::SCTL3: EXTFEN Position         */
#define EADC_SCTL3_EXTFEN_Msk            (0x1ul << EADC_SCTL3_EXTFEN_Pos)                  /*!< EADC_T::SCTL3: EXTFEN Mask             */

#define EADC_SCTL3_TRGDLYDIV_Pos         (6)                                               /*!< EADC_T::SCTL3: TRGDLYDIV Position      */
#define EADC_SCTL3_TRGDLYDIV_Msk         (0x3ul << EADC_SCTL3_TRGDLYDIV_Pos)               /*!< EADC_T::SCTL3: TRGDLYDIV Mask          */

#define EADC_SCTL3_TRGDLYCNT_Pos         (8)                                               /*!< EADC_T::SCTL3: TRGDLYCNT Position      */
#define EADC_SCTL3_TRGDLYCNT_Msk         (0xfful << EADC_SCTL3_TRGDLYCNT_Pos)              /*!< EADC_T::SCTL3: TRGDLYCNT Mask          */

#define EADC_SCTL3_TRGSEL_Pos            (16)                                              /*!< EADC_T::SCTL3: TRGSEL Position         */
#define EADC_SCTL3_TRGSEL_Msk            (0x3ful << EADC_SCTL3_TRGSEL_Pos)                 /*!< EADC_T::SCTL3: TRGSEL Mask             */

#define EADC_SCTL3_INTPOS_Pos            (22)                                              /*!< EADC_T::SCTL3: INTPOS Position         */
#define EADC_SCTL3_INTPOS_Msk            (0x1ul << EADC_SCTL3_INTPOS_Pos)                  /*!< EADC_T::SCTL3: INTPOS Mask             */

#define EADC_SCTL3_DBMEN_Pos             (23)                                              /*!< EADC_T::SCTL3: DBMEN Position          */
#define EADC_SCTL3_DBMEN_Msk             (0x1ul << EADC_SCTL3_DBMEN_Pos)                   /*!< EADC_T::SCTL3: DBMEN Mask              */

#define EADC_SCTL3_EXTSMPT_Pos           (24)                                              /*!< EADC_T::SCTL3: EXTSMPT Position        */
#define EADC_SCTL3_EXTSMPT_Msk           (0xfful << EADC_SCTL3_EXTSMPT_Pos)                /*!< EADC_T::SCTL3: EXTSMPT Mask            */

#define EADC_SCTL4_CHSEL_Pos             (0)                                               /*!< EADC_T::SCTL4: CHSEL Position          */
#define EADC_SCTL4_CHSEL_Msk             (0xful << EADC_SCTL4_CHSEL_Pos)                   /*!< EADC_T::SCTL4: CHSEL Mask              */

#define EADC_SCTL4_EXTREN_Pos            (4)                                               /*!< EADC_T::SCTL4: EXTREN Position         */
#define EADC_SCTL4_EXTREN_Msk            (0x1ul << EADC_SCTL4_EXTREN_Pos)                  /*!< EADC_T::SCTL4: EXTREN Mask             */

#define EADC_SCTL4_EXTFEN_Pos            (5)                                               /*!< EADC_T::SCTL4: EXTFEN Position         */
#define EADC_SCTL4_EXTFEN_Msk            (0x1ul << EADC_SCTL4_EXTFEN_Pos)                  /*!< EADC_T::SCTL4: EXTFEN Mask             */

#define EADC_SCTL4_TRGDLYDIV_Pos         (6)                                               /*!< EADC_T::SCTL4: TRGDLYDIV Position      */
#define EADC_SCTL4_TRGDLYDIV_Msk         (0x3ul << EADC_SCTL4_TRGDLYDIV_Pos)               /*!< EADC_T::SCTL4: TRGDLYDIV Mask          */

#define EADC_SCTL4_TRGDLYCNT_Pos         (8)                                               /*!< EADC_T::SCTL4: TRGDLYCNT Position      */
#define EADC_SCTL4_TRGDLYCNT_Msk         (0xfful << EADC_SCTL4_TRGDLYCNT_Pos)              /*!< EADC_T::SCTL4: TRGDLYCNT Mask          */

#define EADC_SCTL4_TRGSEL_Pos            (16)                                              /*!< EADC_T::SCTL4: TRGSEL Position         */
#define EADC_SCTL4_TRGSEL_Msk            (0x3ful << EADC_SCTL4_TRGSEL_Pos)                 /*!< EADC_T::SCTL4: TRGSEL Mask             */

#define EADC_SCTL4_INTPOS_Pos            (22)                                              /*!< EADC_T::SCTL4: INTPOS Position         */
#define EADC_SCTL4_INTPOS_Msk            (0x1ul << EADC_SCTL4_INTPOS_Pos)                  /*!< EADC_T::SCTL4: INTPOS Mask             */

#define EADC_SCTL4_EXTSMPT_Pos           (24)                                              /*!< EADC_T::SCTL4: EXTSMPT Position        */
#define EADC_SCTL4_EXTSMPT_Msk           (0xfful << EADC_SCTL4_EXTSMPT_Pos)                /*!< EADC_T::SCTL4: EXTSMPT Mask            */

#define EADC_SCTL5_CHSEL_Pos             (0)                                               /*!< EADC_T::SCTL5: CHSEL Position          */
#define EADC_SCTL5_CHSEL_Msk             (0xful << EADC_SCTL5_CHSEL_Pos)                   /*!< EADC_T::SCTL5: CHSEL Mask              */

#define EADC_SCTL5_EXTREN_Pos            (4)                                               /*!< EADC_T::SCTL5: EXTREN Position         */
#define EADC_SCTL5_EXTREN_Msk            (0x1ul << EADC_SCTL5_EXTREN_Pos)                  /*!< EADC_T::SCTL5: EXTREN Mask             */

#define EADC_SCTL5_EXTFEN_Pos            (5)                                               /*!< EADC_T::SCTL5: EXTFEN Position         */
#define EADC_SCTL5_EXTFEN_Msk            (0x1ul << EADC_SCTL5_EXTFEN_Pos)                  /*!< EADC_T::SCTL5: EXTFEN Mask             */

#define EADC_SCTL5_TRGDLYDIV_Pos         (6)                                               /*!< EADC_T::SCTL5: TRGDLYDIV Position      */
#define EADC_SCTL5_TRGDLYDIV_Msk         (0x3ul << EADC_SCTL5_TRGDLYDIV_Pos)               /*!< EADC_T::SCTL5: TRGDLYDIV Mask          */

#define EADC_SCTL5_TRGDLYCNT_Pos         (8)                                               /*!< EADC_T::SCTL5: TRGDLYCNT Position      */
#define EADC_SCTL5_TRGDLYCNT_Msk         (0xfful << EADC_SCTL5_TRGDLYCNT_Pos)              /*!< EADC_T::SCTL5: TRGDLYCNT Mask          */

#define EADC_SCTL5_TRGSEL_Pos            (16)                                              /*!< EADC_T::SCTL5: TRGSEL Position         */
#define EADC_SCTL5_TRGSEL_Msk            (0x3ful << EADC_SCTL5_TRGSEL_Pos)                 /*!< EADC_T::SCTL5: TRGSEL Mask             */

#define EADC_SCTL5_INTPOS_Pos            (22)                                              /*!< EADC_T::SCTL5: INTPOS Position         */
#define EADC_SCTL5_INTPOS_Msk            (0x1ul << EADC_SCTL5_INTPOS_Pos)                  /*!< EADC_T::SCTL5: INTPOS Mask             */

#define EADC_SCTL5_EXTSMPT_Pos           (24)                                              /*!< EADC_T::SCTL5: EXTSMPT Position        */
#define EADC_SCTL5_EXTSMPT_Msk           (0xfful << EADC_SCTL5_EXTSMPT_Pos)                /*!< EADC_T::SCTL5: EXTSMPT Mask            */

#define EADC_SCTL6_CHSEL_Pos             (0)                                               /*!< EADC_T::SCTL6: CHSEL Position          */
#define EADC_SCTL6_CHSEL_Msk             (0xful << EADC_SCTL6_CHSEL_Pos)                   /*!< EADC_T::SCTL6: CHSEL Mask              */

#define EADC_SCTL6_EXTREN_Pos            (4)                                               /*!< EADC_T::SCTL6: EXTREN Position         */
#define EADC_SCTL6_EXTREN_Msk            (0x1ul << EADC_SCTL6_EXTREN_Pos)                  /*!< EADC_T::SCTL6: EXTREN Mask             */

#define EADC_SCTL6_EXTFEN_Pos            (5)                                               /*!< EADC_T::SCTL6: EXTFEN Position         */
#define EADC_SCTL6_EXTFEN_Msk            (0x1ul << EADC_SCTL6_EXTFEN_Pos)                  /*!< EADC_T::SCTL6: EXTFEN Mask             */

#define EADC_SCTL6_TRGDLYDIV_Pos         (6)                                               /*!< EADC_T::SCTL6: TRGDLYDIV Position      */
#define EADC_SCTL6_TRGDLYDIV_Msk         (0x3ul << EADC_SCTL6_TRGDLYDIV_Pos)               /*!< EADC_T::SCTL6: TRGDLYDIV Mask          */

#define EADC_SCTL6_TRGDLYCNT_Pos         (8)                                               /*!< EADC_T::SCTL6: TRGDLYCNT Position      */
#define EADC_SCTL6_TRGDLYCNT_Msk         (0xfful << EADC_SCTL6_TRGDLYCNT_Pos)              /*!< EADC_T::SCTL6: TRGDLYCNT Mask          */

#define EADC_SCTL6_TRGSEL_Pos            (16)                                              /*!< EADC_T::SCTL6: TRGSEL Position         */
#define EADC_SCTL6_TRGSEL_Msk            (0x3ful << EADC_SCTL6_TRGSEL_Pos)                 /*!< EADC_T::SCTL6: TRGSEL Mask             */

#define EADC_SCTL6_INTPOS_Pos            (22)                                              /*!< EADC_T::SCTL6: INTPOS Position         */
#define EADC_SCTL6_INTPOS_Msk            (0x1ul << EADC_SCTL6_INTPOS_Pos)                  /*!< EADC_T::SCTL6: INTPOS Mask             */

#define EADC_SCTL6_EXTSMPT_Pos           (24)                                              /*!< EADC_T::SCTL6: EXTSMPT Position        */
#define EADC_SCTL6_EXTSMPT_Msk           (0xfful << EADC_SCTL6_EXTSMPT_Pos)                /*!< EADC_T::SCTL6: EXTSMPT Mask            */

#define EADC_SCTL7_CHSEL_Pos             (0)                                               /*!< EADC_T::SCTL7: CHSEL Position          */
#define EADC_SCTL7_CHSEL_Msk             (0xful << EADC_SCTL7_CHSEL_Pos)                   /*!< EADC_T::SCTL7: CHSEL Mask              */

#define EADC_SCTL7_EXTREN_Pos            (4)                                               /*!< EADC_T::SCTL7: EXTREN Position         */
#define EADC_SCTL7_EXTREN_Msk            (0x1ul << EADC_SCTL7_EXTREN_Pos)                  /*!< EADC_T::SCTL7: EXTREN Mask             */

#define EADC_SCTL7_EXTFEN_Pos            (5)                                               /*!< EADC_T::SCTL7: EXTFEN Position         */
#define EADC_SCTL7_EXTFEN_Msk            (0x1ul << EADC_SCTL7_EXTFEN_Pos)                  /*!< EADC_T::SCTL7: EXTFEN Mask             */

#define EADC_SCTL7_TRGDLYDIV_Pos         (6)                                               /*!< EADC_T::SCTL7: TRGDLYDIV Position      */
#define EADC_SCTL7_TRGDLYDIV_Msk         (0x3ul << EADC_SCTL7_TRGDLYDIV_Pos)               /*!< EADC_T::SCTL7: TRGDLYDIV Mask          */

#define EADC_SCTL7_TRGDLYCNT_Pos         (8)                                               /*!< EADC_T::SCTL7: TRGDLYCNT Position      */
#define EADC_SCTL7_TRGDLYCNT_Msk         (0xfful << EADC_SCTL7_TRGDLYCNT_Pos)              /*!< EADC_T::SCTL7: TRGDLYCNT Mask          */

#define EADC_SCTL7_TRGSEL_Pos            (16)                                              /*!< EADC_T::SCTL7: TRGSEL Position         */
#define EADC_SCTL7_TRGSEL_Msk            (0x3ful << EADC_SCTL7_TRGSEL_Pos)                 /*!< EADC_T::SCTL7: TRGSEL Mask             */

#define EADC_SCTL7_INTPOS_Pos            (22)                                              /*!< EADC_T::SCTL7: INTPOS Position         */
#define EADC_SCTL7_INTPOS_Msk            (0x1ul << EADC_SCTL7_INTPOS_Pos)                  /*!< EADC_T::SCTL7: INTPOS Mask             */

#define EADC_SCTL7_EXTSMPT_Pos           (24)                                              /*!< EADC_T::SCTL7: EXTSMPT Position        */
#define EADC_SCTL7_EXTSMPT_Msk           (0xfful << EADC_SCTL7_EXTSMPT_Pos)                /*!< EADC_T::SCTL7: EXTSMPT Mask            */

#define EADC_SCTL8_EXTSMPT_Pos           (24)                                              /*!< EADC_T::SCTL8: EXTSMPT Position        */
#define EADC_SCTL8_EXTSMPT_Msk           (0xfful << EADC_SCTL8_EXTSMPT_Pos)                /*!< EADC_T::SCTL8: EXTSMPT Mask            */

#define EADC_INTSRC0_SPLIE0_Pos          (0)                                               /*!< EADC_T::INTSRC0: SPLIE0 Position       */
#define EADC_INTSRC0_SPLIE0_Msk          (0x1ul << EADC_INTSRC0_SPLIE0_Pos)                /*!< EADC_T::INTSRC0: SPLIE0 Mask           */

#define EADC_INTSRC0_SPLIE1_Pos          (1)                                               /*!< EADC_T::INTSRC0: SPLIE1 Position       */
#define EADC_INTSRC0_SPLIE1_Msk          (0x1ul << EADC_INTSRC0_SPLIE1_Pos)                /*!< EADC_T::INTSRC0: SPLIE1 Mask           */

#define EADC_INTSRC0_SPLIE2_Pos          (2)                                               /*!< EADC_T::INTSRC0: SPLIE2 Position       */
#define EADC_INTSRC0_SPLIE2_Msk          (0x1ul << EADC_INTSRC0_SPLIE2_Pos)                /*!< EADC_T::INTSRC0: SPLIE2 Mask           */

#define EADC_INTSRC0_SPLIE3_Pos          (3)                                               /*!< EADC_T::INTSRC0: SPLIE3 Position       */
#define EADC_INTSRC0_SPLIE3_Msk          (0x1ul << EADC_INTSRC0_SPLIE3_Pos)                /*!< EADC_T::INTSRC0: SPLIE3 Mask           */

#define EADC_INTSRC0_SPLIE4_Pos          (4)                                               /*!< EADC_T::INTSRC0: SPLIE4 Position       */
#define EADC_INTSRC0_SPLIE4_Msk          (0x1ul << EADC_INTSRC0_SPLIE4_Pos)                /*!< EADC_T::INTSRC0: SPLIE4 Mask           */

#define EADC_INTSRC0_SPLIE5_Pos          (5)                                               /*!< EADC_T::INTSRC0: SPLIE5 Position       */
#define EADC_INTSRC0_SPLIE5_Msk          (0x1ul << EADC_INTSRC0_SPLIE5_Pos)                /*!< EADC_T::INTSRC0: SPLIE5 Mask           */

#define EADC_INTSRC0_SPLIE6_Pos          (6)                                               /*!< EADC_T::INTSRC0: SPLIE6 Position       */
#define EADC_INTSRC0_SPLIE6_Msk          (0x1ul << EADC_INTSRC0_SPLIE6_Pos)                /*!< EADC_T::INTSRC0: SPLIE6 Mask           */

#define EADC_INTSRC0_SPLIE7_Pos          (7)                                               /*!< EADC_T::INTSRC0: SPLIE7 Position       */
#define EADC_INTSRC0_SPLIE7_Msk          (0x1ul << EADC_INTSRC0_SPLIE7_Pos)                /*!< EADC_T::INTSRC0: SPLIE7 Mask           */

#define EADC_INTSRC0_SPLIE8_Pos          (8)                                               /*!< EADC_T::INTSRC0: SPLIE8 Position       */
#define EADC_INTSRC0_SPLIE8_Msk          (0x1ul << EADC_INTSRC0_SPLIE8_Pos)                /*!< EADC_T::INTSRC0: SPLIE8 Mask           */

#define EADC_INTSRC0_SPLIE9_Pos          (9)                                               /*!< EADC_T::INTSRC0: SPLIE9 Position       */
#define EADC_INTSRC0_SPLIE9_Msk          (0x1ul << EADC_INTSRC0_SPLIE9_Pos)                /*!< EADC_T::INTSRC0: SPLIE9 Mask           */

#define EADC_INTSRC0_SPLIE10_Pos         (10)                                              /*!< EADC_T::INTSRC0: SPLIE10 Position      */
#define EADC_INTSRC0_SPLIE10_Msk         (0x1ul << EADC_INTSRC0_SPLIE10_Pos)               /*!< EADC_T::INTSRC0: SPLIE10 Mask          */

#define EADC_INTSRC0_SPLIE11_Pos         (11)                                              /*!< EADC_T::INTSRC0: SPLIE11 Position      */
#define EADC_INTSRC0_SPLIE11_Msk         (0x1ul << EADC_INTSRC0_SPLIE11_Pos)               /*!< EADC_T::INTSRC0: SPLIE11 Mask          */

#define EADC_INTSRC0_SPLIE12_Pos         (12)                                              /*!< EADC_T::INTSRC0: SPLIE12 Position      */
#define EADC_INTSRC0_SPLIE12_Msk         (0x1ul << EADC_INTSRC0_SPLIE12_Pos)               /*!< EADC_T::INTSRC0: SPLIE12 Mask          */

#define EADC_INTSRC0_SPLIE13_Pos         (13)                                              /*!< EADC_T::INTSRC0: SPLIE13 Position      */
#define EADC_INTSRC0_SPLIE13_Msk         (0x1ul << EADC_INTSRC0_SPLIE13_Pos)               /*!< EADC_T::INTSRC0: SPLIE13 Mask          */

#define EADC_INTSRC0_SPLIE14_Pos         (14)                                              /*!< EADC_T::INTSRC0: SPLIE14 Position      */
#define EADC_INTSRC0_SPLIE14_Msk         (0x1ul << EADC_INTSRC0_SPLIE14_Pos)               /*!< EADC_T::INTSRC0: SPLIE14 Mask          */

#define EADC_INTSRC0_SPLIE15_Pos         (15)                                              /*!< EADC_T::INTSRC0: SPLIE15 Position      */
#define EADC_INTSRC0_SPLIE15_Msk         (0x1ul << EADC_INTSRC0_SPLIE15_Pos)               /*!< EADC_T::INTSRC0: SPLIE15 Mask          */

#define EADC_INTSRC0_SPLIE16_Pos         (16)                                              /*!< EADC_T::INTSRC0: SPLIE16 Position      */
#define EADC_INTSRC0_SPLIE16_Msk         (0x1ul << EADC_INTSRC0_SPLIE16_Pos)               /*!< EADC_T::INTSRC0: SPLIE16 Mask          */

#define EADC_INTSRC0_SPLIE17_Pos         (17)                                              /*!< EADC_T::INTSRC0: SPLIE17 Position      */
#define EADC_INTSRC0_SPLIE17_Msk         (0x1ul << EADC_INTSRC0_SPLIE17_Pos)               /*!< EADC_T::INTSRC0: SPLIE17 Mask          */

#define EADC_INTSRC0_SPLIE18_Pos         (18)                                              /*!< EADC_T::INTSRC0: SPLIE18 Position      */
#define EADC_INTSRC0_SPLIE18_Msk         (0x1ul << EADC_INTSRC0_SPLIE18_Pos)               /*!< EADC_T::INTSRC0: SPLIE18 Mask          */

#define EADC_INTSRC1_SPLIE0_Pos          (0)                                               /*!< EADC_T::INTSRC1: SPLIE0 Position       */
#define EADC_INTSRC1_SPLIE0_Msk          (0x1ul << EADC_INTSRC1_SPLIE0_Pos)                /*!< EADC_T::INTSRC1: SPLIE0 Mask           */

#define EADC_INTSRC1_SPLIE1_Pos          (1)                                               /*!< EADC_T::INTSRC1: SPLIE1 Position       */
#define EADC_INTSRC1_SPLIE1_Msk          (0x1ul << EADC_INTSRC1_SPLIE1_Pos)                /*!< EADC_T::INTSRC1: SPLIE1 Mask           */

#define EADC_INTSRC1_SPLIE2_Pos          (2)                                               /*!< EADC_T::INTSRC1: SPLIE2 Position       */
#define EADC_INTSRC1_SPLIE2_Msk          (0x1ul << EADC_INTSRC1_SPLIE2_Pos)                /*!< EADC_T::INTSRC1: SPLIE2 Mask           */

#define EADC_INTSRC1_SPLIE3_Pos          (3)                                               /*!< EADC_T::INTSRC1: SPLIE3 Position       */
#define EADC_INTSRC1_SPLIE3_Msk          (0x1ul << EADC_INTSRC1_SPLIE3_Pos)                /*!< EADC_T::INTSRC1: SPLIE3 Mask           */

#define EADC_INTSRC1_SPLIE4_Pos          (4)                                               /*!< EADC_T::INTSRC1: SPLIE4 Position       */
#define EADC_INTSRC1_SPLIE4_Msk          (0x1ul << EADC_INTSRC1_SPLIE4_Pos)                /*!< EADC_T::INTSRC1: SPLIE4 Mask           */

#define EADC_INTSRC1_SPLIE5_Pos          (5)                                               /*!< EADC_T::INTSRC1: SPLIE5 Position       */
#define EADC_INTSRC1_SPLIE5_Msk          (0x1ul << EADC_INTSRC1_SPLIE5_Pos)                /*!< EADC_T::INTSRC1: SPLIE5 Mask           */

#define EADC_INTSRC1_SPLIE6_Pos          (6)                                               /*!< EADC_T::INTSRC1: SPLIE6 Position       */
#define EADC_INTSRC1_SPLIE6_Msk          (0x1ul << EADC_INTSRC1_SPLIE6_Pos)                /*!< EADC_T::INTSRC1: SPLIE6 Mask           */

#define EADC_INTSRC1_SPLIE7_Pos          (7)                                               /*!< EADC_T::INTSRC1: SPLIE7 Position       */
#define EADC_INTSRC1_SPLIE7_Msk          (0x1ul << EADC_INTSRC1_SPLIE7_Pos)                /*!< EADC_T::INTSRC1: SPLIE7 Mask           */

#define EADC_INTSRC1_SPLIE8_Pos          (8)                                               /*!< EADC_T::INTSRC1: SPLIE8 Position       */
#define EADC_INTSRC1_SPLIE8_Msk          (0x1ul << EADC_INTSRC1_SPLIE8_Pos)                /*!< EADC_T::INTSRC1: SPLIE8 Mask           */

#define EADC_INTSRC1_SPLIE9_Pos          (9)                                               /*!< EADC_T::INTSRC1: SPLIE9 Position       */
#define EADC_INTSRC1_SPLIE9_Msk          (0x1ul << EADC_INTSRC1_SPLIE9_Pos)                /*!< EADC_T::INTSRC1: SPLIE9 Mask           */

#define EADC_INTSRC1_SPLIE10_Pos         (10)                                              /*!< EADC_T::INTSRC1: SPLIE10 Position      */
#define EADC_INTSRC1_SPLIE10_Msk         (0x1ul << EADC_INTSRC1_SPLIE10_Pos)               /*!< EADC_T::INTSRC1: SPLIE10 Mask          */

#define EADC_INTSRC1_SPLIE11_Pos         (11)                                              /*!< EADC_T::INTSRC1: SPLIE11 Position      */
#define EADC_INTSRC1_SPLIE11_Msk         (0x1ul << EADC_INTSRC1_SPLIE11_Pos)               /*!< EADC_T::INTSRC1: SPLIE11 Mask          */

#define EADC_INTSRC1_SPLIE12_Pos         (12)                                              /*!< EADC_T::INTSRC1: SPLIE12 Position      */
#define EADC_INTSRC1_SPLIE12_Msk         (0x1ul << EADC_INTSRC1_SPLIE12_Pos)               /*!< EADC_T::INTSRC1: SPLIE12 Mask          */

#define EADC_INTSRC1_SPLIE13_Pos         (13)                                              /*!< EADC_T::INTSRC1: SPLIE13 Position      */
#define EADC_INTSRC1_SPLIE13_Msk         (0x1ul << EADC_INTSRC1_SPLIE13_Pos)               /*!< EADC_T::INTSRC1: SPLIE13 Mask          */

#define EADC_INTSRC1_SPLIE14_Pos         (14)                                              /*!< EADC_T::INTSRC1: SPLIE14 Position      */
#define EADC_INTSRC1_SPLIE14_Msk         (0x1ul << EADC_INTSRC1_SPLIE14_Pos)               /*!< EADC_T::INTSRC1: SPLIE14 Mask          */

#define EADC_INTSRC1_SPLIE15_Pos         (15)                                              /*!< EADC_T::INTSRC1: SPLIE15 Position      */
#define EADC_INTSRC1_SPLIE15_Msk         (0x1ul << EADC_INTSRC1_SPLIE15_Pos)               /*!< EADC_T::INTSRC1: SPLIE15 Mask          */

#define EADC_INTSRC1_SPLIE16_Pos         (16)                                              /*!< EADC_T::INTSRC1: SPLIE16 Position      */
#define EADC_INTSRC1_SPLIE16_Msk         (0x1ul << EADC_INTSRC1_SPLIE16_Pos)               /*!< EADC_T::INTSRC1: SPLIE16 Mask          */

#define EADC_INTSRC1_SPLIE17_Pos         (17)                                              /*!< EADC_T::INTSRC1: SPLIE17 Position      */
#define EADC_INTSRC1_SPLIE17_Msk         (0x1ul << EADC_INTSRC1_SPLIE17_Pos)               /*!< EADC_T::INTSRC1: SPLIE17 Mask          */

#define EADC_INTSRC1_SPLIE18_Pos         (18)                                              /*!< EADC_T::INTSRC1: SPLIE18 Position      */
#define EADC_INTSRC1_SPLIE18_Msk         (0x1ul << EADC_INTSRC1_SPLIE18_Pos)               /*!< EADC_T::INTSRC1: SPLIE18 Mask          */

#define EADC_INTSRC2_SPLIE0_Pos          (0)                                               /*!< EADC_T::INTSRC2: SPLIE0 Position       */
#define EADC_INTSRC2_SPLIE0_Msk          (0x1ul << EADC_INTSRC2_SPLIE0_Pos)                /*!< EADC_T::INTSRC2: SPLIE0 Mask           */

#define EADC_INTSRC2_SPLIE1_Pos          (1)                                               /*!< EADC_T::INTSRC2: SPLIE1 Position       */
#define EADC_INTSRC2_SPLIE1_Msk          (0x1ul << EADC_INTSRC2_SPLIE1_Pos)                /*!< EADC_T::INTSRC2: SPLIE1 Mask           */

#define EADC_INTSRC2_SPLIE2_Pos          (2)                                               /*!< EADC_T::INTSRC2: SPLIE2 Position       */
#define EADC_INTSRC2_SPLIE2_Msk          (0x1ul << EADC_INTSRC2_SPLIE2_Pos)                /*!< EADC_T::INTSRC2: SPLIE2 Mask           */

#define EADC_INTSRC2_SPLIE3_Pos          (3)                                               /*!< EADC_T::INTSRC2: SPLIE3 Position       */
#define EADC_INTSRC2_SPLIE3_Msk          (0x1ul << EADC_INTSRC2_SPLIE3_Pos)                /*!< EADC_T::INTSRC2: SPLIE3 Mask           */

#define EADC_INTSRC2_SPLIE4_Pos          (4)                                               /*!< EADC_T::INTSRC2: SPLIE4 Position       */
#define EADC_INTSRC2_SPLIE4_Msk          (0x1ul << EADC_INTSRC2_SPLIE4_Pos)                /*!< EADC_T::INTSRC2: SPLIE4 Mask           */

#define EADC_INTSRC2_SPLIE5_Pos          (5)                                               /*!< EADC_T::INTSRC2: SPLIE5 Position       */
#define EADC_INTSRC2_SPLIE5_Msk          (0x1ul << EADC_INTSRC2_SPLIE5_Pos)                /*!< EADC_T::INTSRC2: SPLIE5 Mask           */

#define EADC_INTSRC2_SPLIE6_Pos          (6)                                               /*!< EADC_T::INTSRC2: SPLIE6 Position       */
#define EADC_INTSRC2_SPLIE6_Msk          (0x1ul << EADC_INTSRC2_SPLIE6_Pos)                /*!< EADC_T::INTSRC2: SPLIE6 Mask           */

#define EADC_INTSRC2_SPLIE7_Pos          (7)                                               /*!< EADC_T::INTSRC2: SPLIE7 Position       */
#define EADC_INTSRC2_SPLIE7_Msk          (0x1ul << EADC_INTSRC2_SPLIE7_Pos)                /*!< EADC_T::INTSRC2: SPLIE7 Mask           */

#define EADC_INTSRC2_SPLIE8_Pos          (8)                                               /*!< EADC_T::INTSRC2: SPLIE8 Position       */
#define EADC_INTSRC2_SPLIE8_Msk          (0x1ul << EADC_INTSRC2_SPLIE8_Pos)                /*!< EADC_T::INTSRC2: SPLIE8 Mask           */

#define EADC_INTSRC2_SPLIE9_Pos          (9)                                               /*!< EADC_T::INTSRC2: SPLIE9 Position       */
#define EADC_INTSRC2_SPLIE9_Msk          (0x1ul << EADC_INTSRC2_SPLIE9_Pos)                /*!< EADC_T::INTSRC2: SPLIE9 Mask           */

#define EADC_INTSRC2_SPLIE10_Pos         (10)                                              /*!< EADC_T::INTSRC2: SPLIE10 Position      */
#define EADC_INTSRC2_SPLIE10_Msk         (0x1ul << EADC_INTSRC2_SPLIE10_Pos)               /*!< EADC_T::INTSRC2: SPLIE10 Mask          */

#define EADC_INTSRC2_SPLIE11_Pos         (11)                                              /*!< EADC_T::INTSRC2: SPLIE11 Position      */
#define EADC_INTSRC2_SPLIE11_Msk         (0x1ul << EADC_INTSRC2_SPLIE11_Pos)               /*!< EADC_T::INTSRC2: SPLIE11 Mask          */

#define EADC_INTSRC2_SPLIE12_Pos         (12)                                              /*!< EADC_T::INTSRC2: SPLIE12 Position      */
#define EADC_INTSRC2_SPLIE12_Msk         (0x1ul << EADC_INTSRC2_SPLIE12_Pos)               /*!< EADC_T::INTSRC2: SPLIE12 Mask          */

#define EADC_INTSRC2_SPLIE13_Pos         (13)                                              /*!< EADC_T::INTSRC2: SPLIE13 Position      */
#define EADC_INTSRC2_SPLIE13_Msk         (0x1ul << EADC_INTSRC2_SPLIE13_Pos)               /*!< EADC_T::INTSRC2: SPLIE13 Mask          */

#define EADC_INTSRC2_SPLIE14_Pos         (14)                                              /*!< EADC_T::INTSRC2: SPLIE14 Position      */
#define EADC_INTSRC2_SPLIE14_Msk         (0x1ul << EADC_INTSRC2_SPLIE14_Pos)               /*!< EADC_T::INTSRC2: SPLIE14 Mask          */

#define EADC_INTSRC2_SPLIE15_Pos         (15)                                              /*!< EADC_T::INTSRC2: SPLIE15 Position      */
#define EADC_INTSRC2_SPLIE15_Msk         (0x1ul << EADC_INTSRC2_SPLIE15_Pos)               /*!< EADC_T::INTSRC2: SPLIE15 Mask          */

#define EADC_INTSRC2_SPLIE16_Pos         (16)                                              /*!< EADC_T::INTSRC2: SPLIE16 Position      */
#define EADC_INTSRC2_SPLIE16_Msk         (0x1ul << EADC_INTSRC2_SPLIE16_Pos)               /*!< EADC_T::INTSRC2: SPLIE16 Mask          */

#define EADC_INTSRC2_SPLIE17_Pos         (17)                                              /*!< EADC_T::INTSRC2: SPLIE17 Position      */
#define EADC_INTSRC2_SPLIE17_Msk         (0x1ul << EADC_INTSRC2_SPLIE17_Pos)               /*!< EADC_T::INTSRC2: SPLIE17 Mask          */

#define EADC_INTSRC2_SPLIE18_Pos         (18)                                              /*!< EADC_T::INTSRC2: SPLIE18 Position      */
#define EADC_INTSRC2_SPLIE18_Msk         (0x1ul << EADC_INTSRC2_SPLIE18_Pos)               /*!< EADC_T::INTSRC2: SPLIE18 Mask          */

#define EADC_INTSRC3_SPLIE0_Pos          (0)                                               /*!< EADC_T::INTSRC3: SPLIE0 Position       */
#define EADC_INTSRC3_SPLIE0_Msk          (0x1ul << EADC_INTSRC3_SPLIE0_Pos)                /*!< EADC_T::INTSRC3: SPLIE0 Mask           */

#define EADC_INTSRC3_SPLIE1_Pos          (1)                                               /*!< EADC_T::INTSRC3: SPLIE1 Position       */
#define EADC_INTSRC3_SPLIE1_Msk          (0x1ul << EADC_INTSRC3_SPLIE1_Pos)                /*!< EADC_T::INTSRC3: SPLIE1 Mask           */

#define EADC_INTSRC3_SPLIE2_Pos          (2)                                               /*!< EADC_T::INTSRC3: SPLIE2 Position       */
#define EADC_INTSRC3_SPLIE2_Msk          (0x1ul << EADC_INTSRC3_SPLIE2_Pos)                /*!< EADC_T::INTSRC3: SPLIE2 Mask           */

#define EADC_INTSRC3_SPLIE3_Pos          (3)                                               /*!< EADC_T::INTSRC3: SPLIE3 Position       */
#define EADC_INTSRC3_SPLIE3_Msk          (0x1ul << EADC_INTSRC3_SPLIE3_Pos)                /*!< EADC_T::INTSRC3: SPLIE3 Mask           */

#define EADC_INTSRC3_SPLIE4_Pos          (4)                                               /*!< EADC_T::INTSRC3: SPLIE4 Position       */
#define EADC_INTSRC3_SPLIE4_Msk          (0x1ul << EADC_INTSRC3_SPLIE4_Pos)                /*!< EADC_T::INTSRC3: SPLIE4 Mask           */

#define EADC_INTSRC3_SPLIE5_Pos          (5)                                               /*!< EADC_T::INTSRC3: SPLIE5 Position       */
#define EADC_INTSRC3_SPLIE5_Msk          (0x1ul << EADC_INTSRC3_SPLIE5_Pos)                /*!< EADC_T::INTSRC3: SPLIE5 Mask           */

#define EADC_INTSRC3_SPLIE6_Pos          (6)                                               /*!< EADC_T::INTSRC3: SPLIE6 Position       */
#define EADC_INTSRC3_SPLIE6_Msk          (0x1ul << EADC_INTSRC3_SPLIE6_Pos)                /*!< EADC_T::INTSRC3: SPLIE6 Mask           */

#define EADC_INTSRC3_SPLIE7_Pos          (7)                                               /*!< EADC_T::INTSRC3: SPLIE7 Position       */
#define EADC_INTSRC3_SPLIE7_Msk          (0x1ul << EADC_INTSRC3_SPLIE7_Pos)                /*!< EADC_T::INTSRC3: SPLIE7 Mask           */

#define EADC_INTSRC3_SPLIE8_Pos          (8)                                               /*!< EADC_T::INTSRC3: SPLIE8 Position       */
#define EADC_INTSRC3_SPLIE8_Msk          (0x1ul << EADC_INTSRC3_SPLIE8_Pos)                /*!< EADC_T::INTSRC3: SPLIE8 Mask           */

#define EADC_INTSRC3_SPLIE9_Pos          (9)                                               /*!< EADC_T::INTSRC3: SPLIE9 Position       */
#define EADC_INTSRC3_SPLIE9_Msk          (0x1ul << EADC_INTSRC3_SPLIE9_Pos)                /*!< EADC_T::INTSRC3: SPLIE9 Mask           */

#define EADC_INTSRC3_SPLIE10_Pos         (10)                                              /*!< EADC_T::INTSRC3: SPLIE10 Position      */
#define EADC_INTSRC3_SPLIE10_Msk         (0x1ul << EADC_INTSRC3_SPLIE10_Pos)               /*!< EADC_T::INTSRC3: SPLIE10 Mask          */

#define EADC_INTSRC3_SPLIE11_Pos         (11)                                              /*!< EADC_T::INTSRC3: SPLIE11 Position      */
#define EADC_INTSRC3_SPLIE11_Msk         (0x1ul << EADC_INTSRC3_SPLIE11_Pos)               /*!< EADC_T::INTSRC3: SPLIE11 Mask          */

#define EADC_INTSRC3_SPLIE12_Pos         (12)                                              /*!< EADC_T::INTSRC3: SPLIE12 Position      */
#define EADC_INTSRC3_SPLIE12_Msk         (0x1ul << EADC_INTSRC3_SPLIE12_Pos)               /*!< EADC_T::INTSRC3: SPLIE12 Mask          */

#define EADC_INTSRC3_SPLIE13_Pos         (13)                                              /*!< EADC_T::INTSRC3: SPLIE13 Position      */
#define EADC_INTSRC3_SPLIE13_Msk         (0x1ul << EADC_INTSRC3_SPLIE13_Pos)               /*!< EADC_T::INTSRC3: SPLIE13 Mask          */

#define EADC_INTSRC3_SPLIE14_Pos         (14)                                              /*!< EADC_T::INTSRC3: SPLIE14 Position      */
#define EADC_INTSRC3_SPLIE14_Msk         (0x1ul << EADC_INTSRC3_SPLIE14_Pos)               /*!< EADC_T::INTSRC3: SPLIE14 Mask          */

#define EADC_INTSRC3_SPLIE15_Pos         (15)                                              /*!< EADC_T::INTSRC3: SPLIE15 Position      */
#define EADC_INTSRC3_SPLIE15_Msk         (0x1ul << EADC_INTSRC3_SPLIE15_Pos)               /*!< EADC_T::INTSRC3: SPLIE15 Mask          */

#define EADC_INTSRC3_SPLIE16_Pos         (16)                                              /*!< EADC_T::INTSRC3: SPLIE16 Position      */
#define EADC_INTSRC3_SPLIE16_Msk         (0x1ul << EADC_INTSRC3_SPLIE16_Pos)               /*!< EADC_T::INTSRC3: SPLIE16 Mask          */

#define EADC_INTSRC3_SPLIE17_Pos         (17)                                              /*!< EADC_T::INTSRC3: SPLIE17 Position      */
#define EADC_INTSRC3_SPLIE17_Msk         (0x1ul << EADC_INTSRC3_SPLIE17_Pos)               /*!< EADC_T::INTSRC3: SPLIE17 Mask          */

#define EADC_INTSRC3_SPLIE18_Pos         (18)                                              /*!< EADC_T::INTSRC3: SPLIE18 Position      */
#define EADC_INTSRC3_SPLIE18_Msk         (0x1ul << EADC_INTSRC3_SPLIE18_Pos)               /*!< EADC_T::INTSRC3: SPLIE18 Mask          */

#define EADC_CMP0_EADCMPEN_Pos           (0)                                               /*!< EADC_T::CMP0: EADCMPEN Position        */
#define EADC_CMP0_EADCMPEN_Msk           (0x1ul << EADC_CMP0_EADCMPEN_Pos)                 /*!< EADC_T::CMP0: EADCMPEN Mask            */

#define EADC_CMP0_EADCMPIE_Pos           (1)                                               /*!< EADC_T::CMP0: EADCMPIE Position        */
#define EADC_CMP0_EADCMPIE_Msk           (0x1ul << EADC_CMP0_EADCMPIE_Pos)                 /*!< EADC_T::CMP0: EADCMPIE Mask            */

#define EADC_CMP0_CMPCOND_Pos            (2)                                               /*!< EADC_T::CMP0: CMPCOND Position         */
#define EADC_CMP0_CMPCOND_Msk            (0x1ul << EADC_CMP0_CMPCOND_Pos)                  /*!< EADC_T::CMP0: CMPCOND Mask             */

#define EADC_CMP0_CMPSPL_Pos             (3)                                               /*!< EADC_T::CMP0: CMPSPL Position          */
#define EADC_CMP0_CMPSPL_Msk             (0xful << EADC_CMP0_CMPSPL_Pos)                   /*!< EADC_T::CMP0: CMPSPL Mask              */

#define EADC_CMP0_CMPMCNT_Pos            (8)                                               /*!< EADC_T::CMP0: CMPMCNT Position         */
#define EADC_CMP0_CMPMCNT_Msk            (0xful << EADC_CMP0_CMPMCNT_Pos)                  /*!< EADC_T::CMP0: CMPMCNT Mask             */

#define EADC_CMP0_CMPWEN_Pos             (15)                                              /*!< EADC_T::CMP0: CMPWEN Position          */
#define EADC_CMP0_CMPWEN_Msk             (0x1ul << EADC_CMP0_CMPWEN_Pos)                   /*!< EADC_T::CMP0: CMPWEN Mask              */

#define EADC_CMP0_CMPDAT_Pos             (16)                                              /*!< EADC_T::CMP0: CMPDAT Position          */
#define EADC_CMP0_CMPDAT_Msk             (0xfffful << EADC_CMP0_CMPDAT_Pos)                /*!< EADC_T::CMP0: CMPDAT Mask              */

#define EADC_CMP1_EADCMPEN_Pos           (0)                                               /*!< EADC_T::CMP1: EADCMPEN Position        */
#define EADC_CMP1_EADCMPEN_Msk           (0x1ul << EADC_CMP1_EADCMPEN_Pos)                 /*!< EADC_T::CMP1: EADCMPEN Mask            */

#define EADC_CMP1_EADCMPIE_Pos           (1)                                               /*!< EADC_T::CMP1: EADCMPIE Position        */
#define EADC_CMP1_EADCMPIE_Msk           (0x1ul << EADC_CMP1_EADCMPIE_Pos)                 /*!< EADC_T::CMP1: EADCMPIE Mask            */

#define EADC_CMP1_CMPCOND_Pos            (2)                                               /*!< EADC_T::CMP1: CMPCOND Position         */
#define EADC_CMP1_CMPCOND_Msk            (0x1ul << EADC_CMP1_CMPCOND_Pos)                  /*!< EADC_T::CMP1: CMPCOND Mask             */

#define EADC_CMP1_CMPSPL_Pos             (3)                                               /*!< EADC_T::CMP1: CMPSPL Position          */
#define EADC_CMP1_CMPSPL_Msk             (0xful << EADC_CMP1_CMPSPL_Pos)                   /*!< EADC_T::CMP1: CMPSPL Mask              */

#define EADC_CMP1_CMPMCNT_Pos            (8)                                               /*!< EADC_T::CMP1: CMPMCNT Position         */
#define EADC_CMP1_CMPMCNT_Msk            (0xful << EADC_CMP1_CMPMCNT_Pos)                  /*!< EADC_T::CMP1: CMPMCNT Mask             */

#define EADC_CMP1_CMPWEN_Pos             (15)                                              /*!< EADC_T::CMP1: CMPWEN Position          */
#define EADC_CMP1_CMPWEN_Msk             (0x1ul << EADC_CMP1_CMPWEN_Pos)                   /*!< EADC_T::CMP1: CMPWEN Mask              */

#define EADC_CMP1_CMPDAT_Pos             (16)                                              /*!< EADC_T::CMP1: CMPDAT Position          */
#define EADC_CMP1_CMPDAT_Msk             (0xfffful << EADC_CMP1_CMPDAT_Pos)                /*!< EADC_T::CMP1: CMPDAT Mask              */

#define EADC_CMP2_EADCMPEN_Pos           (0)                                               /*!< EADC_T::CMP2: EADCMPEN Position        */
#define EADC_CMP2_EADCMPEN_Msk           (0x1ul << EADC_CMP2_EADCMPEN_Pos)                 /*!< EADC_T::CMP2: EADCMPEN Mask            */

#define EADC_CMP2_EADCMPIE_Pos           (1)                                               /*!< EADC_T::CMP2: EADCMPIE Position        */
#define EADC_CMP2_EADCMPIE_Msk           (0x1ul << EADC_CMP2_EADCMPIE_Pos)                 /*!< EADC_T::CMP2: EADCMPIE Mask            */

#define EADC_CMP2_CMPCOND_Pos            (2)                                               /*!< EADC_T::CMP2: CMPCOND Position         */
#define EADC_CMP2_CMPCOND_Msk            (0x1ul << EADC_CMP2_CMPCOND_Pos)                  /*!< EADC_T::CMP2: CMPCOND Mask             */

#define EADC_CMP2_CMPSPL_Pos             (3)                                               /*!< EADC_T::CMP2: CMPSPL Position          */
#define EADC_CMP2_CMPSPL_Msk             (0xful << EADC_CMP2_CMPSPL_Pos)                   /*!< EADC_T::CMP2: CMPSPL Mask              */

#define EADC_CMP2_CMPMCNT_Pos            (8)                                               /*!< EADC_T::CMP2: CMPMCNT Position         */
#define EADC_CMP2_CMPMCNT_Msk            (0xful << EADC_CMP2_CMPMCNT_Pos)                  /*!< EADC_T::CMP2: CMPMCNT Mask             */

#define EADC_CMP2_CMPWEN_Pos             (15)                                              /*!< EADC_T::CMP2: CMPWEN Position          */
#define EADC_CMP2_CMPWEN_Msk             (0x1ul << EADC_CMP2_CMPWEN_Pos)                   /*!< EADC_T::CMP2: CMPWEN Mask              */

#define EADC_CMP2_CMPDAT_Pos             (16)                                              /*!< EADC_T::CMP2: CMPDAT Position          */
#define EADC_CMP2_CMPDAT_Msk             (0xfffful << EADC_CMP2_CMPDAT_Pos)                /*!< EADC_T::CMP2: CMPDAT Mask              */

#define EADC_CMP3_EADCMPEN_Pos           (0)                                               /*!< EADC_T::CMP3: EADCMPEN Position        */
#define EADC_CMP3_EADCMPEN_Msk           (0x1ul << EADC_CMP3_EADCMPEN_Pos)                 /*!< EADC_T::CMP3: EADCMPEN Mask            */

#define EADC_CMP3_EADCMPIE_Pos           (1)                                               /*!< EADC_T::CMP3: EADCMPIE Position        */
#define EADC_CMP3_EADCMPIE_Msk           (0x1ul << EADC_CMP3_EADCMPIE_Pos)                 /*!< EADC_T::CMP3: EADCMPIE Mask            */

#define EADC_CMP3_CMPCOND_Pos            (2)                                               /*!< EADC_T::CMP3: CMPCOND Position         */
#define EADC_CMP3_CMPCOND_Msk            (0x1ul << EADC_CMP3_CMPCOND_Pos)                  /*!< EADC_T::CMP3: CMPCOND Mask             */

#define EADC_CMP3_CMPSPL_Pos             (3)                                               /*!< EADC_T::CMP3: CMPSPL Position          */
#define EADC_CMP3_CMPSPL_Msk             (0xful << EADC_CMP3_CMPSPL_Pos)                   /*!< EADC_T::CMP3: CMPSPL Mask              */

#define EADC_CMP3_CMPMCNT_Pos            (8)                                               /*!< EADC_T::CMP3: CMPMCNT Position         */
#define EADC_CMP3_CMPMCNT_Msk            (0xful << EADC_CMP3_CMPMCNT_Pos)                  /*!< EADC_T::CMP3: CMPMCNT Mask             */

#define EADC_CMP3_CMPWEN_Pos             (15)                                              /*!< EADC_T::CMP3: CMPWEN Position          */
#define EADC_CMP3_CMPWEN_Msk             (0x1ul << EADC_CMP3_CMPWEN_Pos)                   /*!< EADC_T::CMP3: CMPWEN Mask              */

#define EADC_CMP3_CMPDAT_Pos             (16)                                              /*!< EADC_T::CMP3: CMPDAT Position          */
#define EADC_CMP3_CMPDAT_Msk             (0xfffful << EADC_CMP3_CMPDAT_Pos)                /*!< EADC_T::CMP3: CMPDAT Mask              */

#define EADC_STATUS0_VALID_Pos           (0)                                               /*!< EADC_T::STATUS0: VALID Position        */
#define EADC_STATUS0_VALID_Msk           (0x1fful << EADC_STATUS0_VALID_Pos)               /*!< EADC_T::STATUS0: VALID Mask            */

#define EADC_STATUS0_OV_Pos              (16)                                              /*!< EADC_T::STATUS0: OV Position           */
#define EADC_STATUS0_OV_Msk              (0x1fful << EADC_STATUS0_OV_Pos)                  /*!< EADC_T::STATUS0: OV Mask               */

#define EADC_STATUS2_ADIF0_Pos           (0)                                               /*!< EADC_T::STATUS2: ADIF0 Position        */
#define EADC_STATUS2_ADIF0_Msk           (0x1ul << EADC_STATUS2_ADIF0_Pos)                 /*!< EADC_T::STATUS2: ADIF0 Mask            */

#define EADC_STATUS2_ADIF1_Pos           (1)                                               /*!< EADC_T::STATUS2: ADIF1 Position        */
#define EADC_STATUS2_ADIF1_Msk           (0x1ul << EADC_STATUS2_ADIF1_Pos)                 /*!< EADC_T::STATUS2: ADIF1 Mask            */

#define EADC_STATUS2_ADIF2_Pos           (2)                                               /*!< EADC_T::STATUS2: ADIF2 Position        */
#define EADC_STATUS2_ADIF2_Msk           (0x1ul << EADC_STATUS2_ADIF2_Pos)                 /*!< EADC_T::STATUS2: ADIF2 Mask            */

#define EADC_STATUS2_ADIF3_Pos           (3)                                               /*!< EADC_T::STATUS2: ADIF3 Position        */
#define EADC_STATUS2_ADIF3_Msk           (0x1ul << EADC_STATUS2_ADIF3_Pos)                 /*!< EADC_T::STATUS2: ADIF3 Mask            */

#define EADC_STATUS2_EADCMPF0_Pos        (4)                                               /*!< EADC_T::STATUS2: EADCMPF0 Position     */
#define EADC_STATUS2_EADCMPF0_Msk        (0x1ul << EADC_STATUS2_EADCMPF0_Pos)              /*!< EADC_T::STATUS2: EADCMPF0 Mask         */

#define EADC_STATUS2_EADCMPF1_Pos        (5)                                               /*!< EADC_T::STATUS2: EADCMPF1 Position     */
#define EADC_STATUS2_EADCMPF1_Msk        (0x1ul << EADC_STATUS2_EADCMPF1_Pos)              /*!< EADC_T::STATUS2: EADCMPF1 Mask         */

#define EADC_STATUS2_EADCMPF2_Pos        (6)                                               /*!< EADC_T::STATUS2: EADCMPF2 Position     */
#define EADC_STATUS2_EADCMPF2_Msk        (0x1ul << EADC_STATUS2_EADCMPF2_Pos)              /*!< EADC_T::STATUS2: EADCMPF2 Mask         */

#define EADC_STATUS2_EADCMPF3_Pos        (7)                                               /*!< EADC_T::STATUS2: EADCMPF3 Position     */
#define EADC_STATUS2_EADCMPF3_Msk        (0x1ul << EADC_STATUS2_EADCMPF3_Pos)              /*!< EADC_T::STATUS2: EADCMPF3 Mask         */

#define EADC_STATUS2_ADOVIF0_Pos         (8)                                               /*!< EADC_T::STATUS2: ADOVIF0 Position      */
#define EADC_STATUS2_ADOVIF0_Msk         (0x1ul << EADC_STATUS2_ADOVIF0_Pos)               /*!< EADC_T::STATUS2: ADOVIF0 Mask          */

#define EADC_STATUS2_ADOVIF1_Pos         (9)                                               /*!< EADC_T::STATUS2: ADOVIF1 Position      */
#define EADC_STATUS2_ADOVIF1_Msk         (0x1ul << EADC_STATUS2_ADOVIF1_Pos)               /*!< EADC_T::STATUS2: ADOVIF1 Mask          */

#define EADC_STATUS2_ADOVIF2_Pos         (10)                                              /*!< EADC_T::STATUS2: ADOVIF2 Position      */
#define EADC_STATUS2_ADOVIF2_Msk         (0x1ul << EADC_STATUS2_ADOVIF2_Pos)               /*!< EADC_T::STATUS2: ADOVIF2 Mask          */

#define EADC_STATUS2_ADOVIF3_Pos         (11)                                              /*!< EADC_T::STATUS2: ADOVIF3 Position      */
#define EADC_STATUS2_ADOVIF3_Msk         (0x1ul << EADC_STATUS2_ADOVIF3_Pos)               /*!< EADC_T::STATUS2: ADOVIF3 Mask          */

#define EADC_STATUS2_EADCMPO0_Pos        (12)                                              /*!< EADC_T::STATUS2: EADCMPO0 Position     */
#define EADC_STATUS2_EADCMPO0_Msk        (0x1ul << EADC_STATUS2_EADCMPO0_Pos)              /*!< EADC_T::STATUS2: EADCMPO0 Mask         */

#define EADC_STATUS2_EADCMPO1_Pos        (13)                                              /*!< EADC_T::STATUS2: EADCMPO1 Position     */
#define EADC_STATUS2_EADCMPO1_Msk        (0x1ul << EADC_STATUS2_EADCMPO1_Pos)              /*!< EADC_T::STATUS2: EADCMPO1 Mask         */

#define EADC_STATUS2_EADCMPO2_Pos        (14)                                              /*!< EADC_T::STATUS2: EADCMPO2 Position     */
#define EADC_STATUS2_EADCMPO2_Msk        (0x1ul << EADC_STATUS2_EADCMPO2_Pos)              /*!< EADC_T::STATUS2: EADCMPO2 Mask         */

#define EADC_STATUS2_EADCMPO3_Pos        (15)                                              /*!< EADC_T::STATUS2: EADCMPO3 Position     */
#define EADC_STATUS2_EADCMPO3_Msk        (0x1ul << EADC_STATUS2_EADCMPO3_Pos)              /*!< EADC_T::STATUS2: EADCMPO3 Mask         */

#define EADC_STATUS2_CHANNEL_Pos         (16)                                              /*!< EADC_T::STATUS2: CHANNEL Position      */
#define EADC_STATUS2_CHANNEL_Msk         (0x1ful << EADC_STATUS2_CHANNEL_Pos)              /*!< EADC_T::STATUS2: CHANNEL Mask          */

#define EADC_STATUS2_BUSY_Pos            (23)                                              /*!< EADC_T::STATUS2: BUSY Position         */
#define EADC_STATUS2_BUSY_Msk            (0x1ul << EADC_STATUS2_BUSY_Pos)                  /*!< EADC_T::STATUS2: BUSY Mask             */

#define EADC_STATUS2_ADOVIF_Pos          (24)                                              /*!< EADC_T::STATUS2: ADOVIF Position       */
#define EADC_STATUS2_ADOVIF_Msk          (0x1ul << EADC_STATUS2_ADOVIF_Pos)                /*!< EADC_T::STATUS2: ADOVIF Mask           */

#define EADC_STATUS2_STOVF_Pos           (25)                                              /*!< EADC_T::STATUS2: STOVF Position        */
#define EADC_STATUS2_STOVF_Msk           (0x1ul << EADC_STATUS2_STOVF_Pos)                 /*!< EADC_T::STATUS2: STOVF Mask            */

#define EADC_STATUS2_AVALID_Pos          (26)                                              /*!< EADC_T::STATUS2: AVALID Position       */
#define EADC_STATUS2_AVALID_Msk          (0x1ul << EADC_STATUS2_AVALID_Pos)                /*!< EADC_T::STATUS2: AVALID Mask           */

#define EADC_STATUS2_AOV_Pos             (27)                                              /*!< EADC_T::STATUS2: AOV Position          */
#define EADC_STATUS2_AOV_Msk             (0x1ul << EADC_STATUS2_AOV_Pos)                   /*!< EADC_T::STATUS2: AOV Mask              */

#define EADC_STATUS2_FFULL_Pos           (28)                                              /*!< EADC_T::STATUS2: FFULL Position        */
#define EADC_STATUS2_FFULL_Msk           (0x1ul << EADC_STATUS2_FFULL_Pos)                 /*!< EADC_T::STATUS2: FFULL Mask            */

#define EADC_STATUS2_FFTDF_Pos           (29)                                              /*!< EADC_T::STATUS2: FFTDF Position        */
#define EADC_STATUS2_FFTDF_Msk           (0x1ul << EADC_STATUS2_FFTDF_Pos)                 /*!< EADC_T::STATUS2: FFTDF Mask            */

#define EADC_STATUS3_CURSPL_Pos          (0)                                               /*!< EADC_T::STATUS3: CURSPL Position       */
#define EADC_STATUS3_CURSPL_Msk          (0x1ful << EADC_STATUS3_CURSPL_Pos)               /*!< EADC_T::STATUS3: CURSPL Mask           */

#define EADC_DDAT0_RESULT_Pos            (0)                                               /*!< EADC_T::DDAT0: RESULT Position         */
#define EADC_DDAT0_RESULT_Msk            (0xfffful << EADC_DDAT0_RESULT_Pos)               /*!< EADC_T::DDAT0: RESULT Mask             */

#define EADC_DDAT0_OV_Pos                (16)                                              /*!< EADC_T::DDAT0: OV Position             */
#define EADC_DDAT0_OV_Msk                (0x1ul << EADC_DDAT0_OV_Pos)                      /*!< EADC_T::DDAT0: OV Mask                 */

#define EADC_DDAT0_VALID_Pos             (17)                                              /*!< EADC_T::DDAT0: VALID Position          */
#define EADC_DDAT0_VALID_Msk             (0x1ul << EADC_DDAT0_VALID_Pos)                   /*!< EADC_T::DDAT0: VALID Mask              */

#define EADC_DDAT1_RESULT_Pos            (0)                                               /*!< EADC_T::DDAT1: RESULT Position         */
#define EADC_DDAT1_RESULT_Msk            (0xfffful << EADC_DDAT1_RESULT_Pos)               /*!< EADC_T::DDAT1: RESULT Mask             */

#define EADC_DDAT1_OV_Pos                (16)                                              /*!< EADC_T::DDAT1: OV Position             */
#define EADC_DDAT1_OV_Msk                (0x1ul << EADC_DDAT1_OV_Pos)                      /*!< EADC_T::DDAT1: OV Mask                 */

#define EADC_DDAT1_VALID_Pos             (17)                                              /*!< EADC_T::DDAT1: VALID Position          */
#define EADC_DDAT1_VALID_Msk             (0x1ul << EADC_DDAT1_VALID_Pos)                   /*!< EADC_T::DDAT1: VALID Mask              */

#define EADC_DDAT2_RESULT_Pos            (0)                                               /*!< EADC_T::DDAT2: RESULT Position         */
#define EADC_DDAT2_RESULT_Msk            (0xfffful << EADC_DDAT2_RESULT_Pos)               /*!< EADC_T::DDAT2: RESULT Mask             */

#define EADC_DDAT2_OV_Pos                (16)                                              /*!< EADC_T::DDAT2: OV Position             */
#define EADC_DDAT2_OV_Msk                (0x1ul << EADC_DDAT2_OV_Pos)                      /*!< EADC_T::DDAT2: OV Mask                 */

#define EADC_DDAT2_VALID_Pos             (17)                                              /*!< EADC_T::DDAT2: VALID Position          */
#define EADC_DDAT2_VALID_Msk             (0x1ul << EADC_DDAT2_VALID_Pos)                   /*!< EADC_T::DDAT2: VALID Mask              */

#define EADC_DDAT3_RESULT_Pos            (0)                                               /*!< EADC_T::DDAT3: RESULT Position         */
#define EADC_DDAT3_RESULT_Msk            (0xfffful << EADC_DDAT3_RESULT_Pos)               /*!< EADC_T::DDAT3: RESULT Mask             */

#define EADC_DDAT3_OV_Pos                (16)                                              /*!< EADC_T::DDAT3: OV Position             */
#define EADC_DDAT3_OV_Msk                (0x1ul << EADC_DDAT3_OV_Pos)                      /*!< EADC_T::DDAT3: OV Mask                 */

#define EADC_DDAT3_VALID_Pos             (17)                                              /*!< EADC_T::DDAT3: VALID Position          */
#define EADC_DDAT3_VALID_Msk             (0x1ul << EADC_DDAT3_VALID_Pos)                   /*!< EADC_T::DDAT3: VALID Mask              */

#define EADC_PWRM_PWUPRDY_Pos            (0)                                               /*!< EADC_T::PWRM: PWUPRDY Position         */
#define EADC_PWRM_PWUPRDY_Msk            (0x1ul << EADC_PWRM_PWUPRDY_Pos)                  /*!< EADC_T::PWRM: PWUPRDY Mask             */

#define EADC_PWRM_PWUCALEN_Pos           (1)                                               /*!< EADC_T::PWRM: PWUCALEN Position        */
#define EADC_PWRM_PWUCALEN_Msk           (0x1ul << EADC_PWRM_PWUCALEN_Pos)                 /*!< EADC_T::PWRM: PWUCALEN Mask            */

#define EADC_PWRM_PWDMOD_Pos             (2)                                               /*!< EADC_T::PWRM: PWDMOD Position          */
#define EADC_PWRM_PWDMOD_Msk             (0x3ul << EADC_PWRM_PWDMOD_Pos)                   /*!< EADC_T::PWRM: PWDMOD Mask              */

#define EADC_PWRM_PWAWARE_Pos            (4)                                               /*!< EADC_T::PWRM: PWAWARE Position         */
#define EADC_PWRM_PWAWARE_Msk            (0x1ul << EADC_PWRM_PWAWARE_Pos)                  /*!< EADC_T::PWRM: PWAWARE Mask             */

#define EADC_PWRM_IREFSUT_Pos            (8)                                               /*!< EADC_T::PWRM: IREFSUT Position         */
#define EADC_PWRM_IREFSUT_Msk            (0xffffful << EADC_PWRM_IREFSUT_Pos)              /*!< EADC_T::PWRM: IREFSUT Mask             */

#define EADC_CALCTL_CALSTART_Pos         (1)                                               /*!< EADC_T::CALCTL: CALSTART Position      */
#define EADC_CALCTL_CALSTART_Msk         (0x1ul << EADC_CALCTL_CALSTART_Pos)               /*!< EADC_T::CALCTL: CALSTART Mask          */

#define EADC_CALCTL_CALDONE_Pos          (2)                                               /*!< EADC_T::CALCTL: CALDONE Position       */
#define EADC_CALCTL_CALDONE_Msk          (0x1ul << EADC_CALCTL_CALDONE_Pos)                /*!< EADC_T::CALCTL: CALDONE Mask           */

#define EADC_CALCTL_CALSEL_Pos           (3)                                               /*!< EADC_T::CALCTL: CALSEL Position        */
#define EADC_CALCTL_CALSEL_Msk           (0x1ul << EADC_CALCTL_CALSEL_Pos)                 /*!< EADC_T::CALCTL: CALSEL Mask            */

#define EADC_PDMACTL_PDMATEN_Pos         (0)                                               /*!< EADC_T::PDMACTL: PDMATEN Position      */
#define EADC_PDMACTL_PDMATEN_Msk         (0x1fful << EADC_PDMACTL_PDMATEN_Pos)             /*!< EADC_T::PDMACTL: PDMATEN Mask          */

#define EADC_PDMACTL_FDRO_Pos            (24)                                              /*!< EADC_T::PDMACTL: FDRO Position         */
#define EADC_PDMACTL_FDRO_Msk            (0x1ul << EADC_PDMACTL_FDRO_Pos)                  /*!< EADC_T::PDMACTL: FDRO Mask             */

#define EADC_PDMACTL_FIFOEN_Pos          (30)                                              /*!< EADC_T::PDMACTL: FIFOEN Position       */
#define EADC_PDMACTL_FIFOEN_Msk          (0x1ul << EADC_PDMACTL_FIFOEN_Pos)                /*!< EADC_T::PDMACTL: FIFOEN Mask           */

#define EADC_PDMACTL_FIFORST_Pos         (31)                                              /*!< EADC_T::PDMACTL: FIFORST Position      */
#define EADC_PDMACTL_FIFORST_Msk         (0x1ul << EADC_PDMACTL_FIFORST_Pos)               /*!< EADC_T::PDMACTL: FIFORST Mask          */

#define EADC_FIFOSTS_FIFOWR_Pos          (0)                                               /*!< EADC_T::FIFOSTS: FIFOWR Position       */
#define EADC_FIFOSTS_FIFOWR_Msk          (0x1ful << EADC_FIFOSTS_FIFOWR_Pos)               /*!< EADC_T::FIFOSTS: FIFOWR Mask           */

#define EADC_FIFOSTS_FIFORD_Pos          (8)                                               /*!< EADC_T::FIFOSTS: FIFORD Position       */
#define EADC_FIFOSTS_FIFORD_Msk          (0x1ful << EADC_FIFOSTS_FIFORD_Pos)               /*!< EADC_T::FIFOSTS: FIFORD Mask           */

#define EADC_FIFOSTS_FIFOFULL_Pos        (30)                                              /*!< EADC_T::FIFOSTS: FIFOFULL Position     */
#define EADC_FIFOSTS_FIFOFULL_Msk        (0x1ul << EADC_FIFOSTS_FIFOFULL_Pos)              /*!< EADC_T::FIFOSTS: FIFOFULL Mask         */

#define EADC_FIFOSTS_FIFOEMPT_Pos        (31)                                              /*!< EADC_T::FIFOSTS: FIFOEMPT Position     */
#define EADC_FIFOSTS_FIFOEMPT_Msk        (0x1ul << EADC_FIFOSTS_FIFOEMPT_Pos)              /*!< EADC_T::FIFOSTS: FIFOEMPT Mask         */

#define EADC_FIFODEBUG_FIFODBUG_Pos      (0)                                               /*!< EADC_T::FIFODEBUG: FIFODBUG Position   */
#define EADC_FIFODEBUG_FIFODBUG_Msk      (0x1ul << EADC_FIFODEBUG_FIFODBUG_Pos)            /*!< EADC_T::FIFODEBUG: FIFODBUG Mask       */

#define EADC_SELSMP0_SELSMP0_Pos         (0)                                               /*!< EADC_T::SELSMP0: SELSMP0 Position      */
#define EADC_SELSMP0_SELSMP0_Msk         (0x3ul << EADC_SELSMP0_SELSMP0_Pos)               /*!< EADC_T::SELSMP0: SELSMP0 Mask          */

#define EADC_SELSMP0_SELSMP1_Pos         (4)                                               /*!< EADC_T::SELSMP0: SELSMP1 Position      */
#define EADC_SELSMP0_SELSMP1_Msk         (0x3ul << EADC_SELSMP0_SELSMP1_Pos)               /*!< EADC_T::SELSMP0: SELSMP1 Mask          */

#define EADC_SELSMP0_SELSMP2_Pos         (8)                                               /*!< EADC_T::SELSMP0: SELSMP2 Position      */
#define EADC_SELSMP0_SELSMP2_Msk         (0x3ul << EADC_SELSMP0_SELSMP2_Pos)               /*!< EADC_T::SELSMP0: SELSMP2 Mask          */

#define EADC_SELSMP0_SELSMP3_Pos         (12)                                              /*!< EADC_T::SELSMP0: SELSMP3 Position      */
#define EADC_SELSMP0_SELSMP3_Msk         (0x3ul << EADC_SELSMP0_SELSMP3_Pos)               /*!< EADC_T::SELSMP0: SELSMP3 Mask          */

#define EADC_SELSMP0_SELSMP4_Pos         (16)                                              /*!< EADC_T::SELSMP0: SELSMP4 Position      */
#define EADC_SELSMP0_SELSMP4_Msk         (0x3ul << EADC_SELSMP0_SELSMP4_Pos)               /*!< EADC_T::SELSMP0: SELSMP4 Mask          */

#define EADC_SELSMP0_SELSMP5_Pos         (20)                                              /*!< EADC_T::SELSMP0: SELSMP5 Position      */
#define EADC_SELSMP0_SELSMP5_Msk         (0x3ul << EADC_SELSMP0_SELSMP5_Pos)               /*!< EADC_T::SELSMP0: SELSMP5 Mask          */

#define EADC_SELSMP0_SELSMP6_Pos         (24)                                              /*!< EADC_T::SELSMP0: SELSMP6 Position      */
#define EADC_SELSMP0_SELSMP6_Msk         (0x3ul << EADC_SELSMP0_SELSMP6_Pos)               /*!< EADC_T::SELSMP0: SELSMP6 Mask          */

#define EADC_SELSMP0_SELSMP7_Pos         (28)                                              /*!< EADC_T::SELSMP0: SELSMP7 Position      */
#define EADC_SELSMP0_SELSMP7_Msk         (0x3ul << EADC_SELSMP0_SELSMP7_Pos)               /*!< EADC_T::SELSMP0: SELSMP7 Mask          */

#define EADC_SELSMP1_SELSMP8_Pos         (0)                                               /*!< EADC_T::SELSMP1: SELSMP8 Position      */
#define EADC_SELSMP1_SELSMP8_Msk         (0x3ul << EADC_SELSMP1_SELSMP8_Pos)               /*!< EADC_T::SELSMP1: SELSMP8 Mask          */

#define EADC_REFADJCTL_PDREF_Pos         (0)                                               /*!< EADC_T::REFADJCTL: PDREF Position      */
#define EADC_REFADJCTL_PDREF_Msk         (0x1ul << EADC_REFADJCTL_PDREF_Pos)               /*!< EADC_T::REFADJCTL: PDREF Mask          */

#define EADC_REFADJCTL_REFADJ_Pos        (1)                                               /*!< EADC_T::REFADJCTL: REFADJ Position     */
#define EADC_REFADJCTL_REFADJ_Msk        (0xful << EADC_REFADJCTL_REFADJ_Pos)              /*!< EADC_T::REFADJCTL: REFADJ Mask         */

#define EADC_SETCTL_EADCSET_Pos          (0)                                               /*!< EADC_T::SETCTL: EADCSET Position       */
#define EADC_SETCTL_EADCSET_Msk          (0xfful << EADC_SETCTL_EADCSET_Pos)               /*!< EADC_T::SETCTL: EADCSET Mask           */

#define EADC_WRBCTL_WRBSEL_Pos           (0)                                               /*!< EADC_T::WRBCTL: WRBSEL Position        */
#define EADC_WRBCTL_WRBSEL_Msk           (0x3ul << EADC_WRBCTL_WRBSEL_Pos)                 /*!< EADC_T::WRBCTL: WRBSEL Mask            */

#define EADC_SMCTL0_ALIGN_Pos            (0)                                               /*!< EADC_T::SMCTL0: ALIGN Position         */
#define EADC_SMCTL0_ALIGN_Msk            (0x1ul << EADC_SMCTL0_ALIGN_Pos)                  /*!< EADC_T::SMCTL0: ALIGN Mask             */

#define EADC_SMCTL0_AVG_Pos              (1)                                               /*!< EADC_T::SMCTL0: AVG Position           */
#define EADC_SMCTL0_AVG_Msk              (0x1ul << EADC_SMCTL0_AVG_Pos)                    /*!< EADC_T::SMCTL0: AVG Mask               */

#define EADC_SMCTL0_ACU_Pos              (4)                                               /*!< EADC_T::SMCTL0: ACU Position           */
#define EADC_SMCTL0_ACU_Msk              (0xful << EADC_SMCTL0_ACU_Pos)                    /*!< EADC_T::SMCTL0: ACU Mask               */

#define EADC_SMCTL1_ALIGN_Pos            (0)                                               /*!< EADC_T::SMCTL1: ALIGN Position         */
#define EADC_SMCTL1_ALIGN_Msk            (0x1ul << EADC_SMCTL1_ALIGN_Pos)                  /*!< EADC_T::SMCTL1: ALIGN Mask             */

#define EADC_SMCTL1_AVG_Pos              (1)                                               /*!< EADC_T::SMCTL1: AVG Position           */
#define EADC_SMCTL1_AVG_Msk              (0x1ul << EADC_SMCTL1_AVG_Pos)                    /*!< EADC_T::SMCTL1: AVG Mask               */

#define EADC_SMCTL1_ACU_Pos              (4)                                               /*!< EADC_T::SMCTL1: ACU Position           */
#define EADC_SMCTL1_ACU_Msk              (0xful << EADC_SMCTL1_ACU_Pos)                    /*!< EADC_T::SMCTL1: ACU Mask               */

#define EADC_SMCTL2_ALIGN_Pos            (0)                                               /*!< EADC_T::SMCTL2: ALIGN Position         */
#define EADC_SMCTL2_ALIGN_Msk            (0x1ul << EADC_SMCTL2_ALIGN_Pos)                  /*!< EADC_T::SMCTL2: ALIGN Mask             */

#define EADC_SMCTL2_AVG_Pos              (1)                                               /*!< EADC_T::SMCTL2: AVG Position           */
#define EADC_SMCTL2_AVG_Msk              (0x1ul << EADC_SMCTL2_AVG_Pos)                    /*!< EADC_T::SMCTL2: AVG Mask               */

#define EADC_SMCTL2_ACU_Pos              (4)                                               /*!< EADC_T::SMCTL2: ACU Position           */
#define EADC_SMCTL2_ACU_Msk              (0xful << EADC_SMCTL2_ACU_Pos)                    /*!< EADC_T::SMCTL2: ACU Mask               */

#define EADC_SMCTL3_ALIGN_Pos            (0)                                               /*!< EADC_T::SMCTL3: ALIGN Position         */
#define EADC_SMCTL3_ALIGN_Msk            (0x1ul << EADC_SMCTL3_ALIGN_Pos)                  /*!< EADC_T::SMCTL3: ALIGN Mask             */

#define EADC_SMCTL3_AVG_Pos              (1)                                               /*!< EADC_T::SMCTL3: AVG Position           */
#define EADC_SMCTL3_AVG_Msk              (0x1ul << EADC_SMCTL3_AVG_Pos)                    /*!< EADC_T::SMCTL3: AVG Mask               */

#define EADC_SMCTL3_ACU_Pos              (4)                                               /*!< EADC_T::SMCTL3: ACU Position           */
#define EADC_SMCTL3_ACU_Msk              (0xful << EADC_SMCTL3_ACU_Pos)                    /*!< EADC_T::SMCTL3: ACU Mask               */

#define EADC_SMCTL4_ALIGN_Pos            (0)                                               /*!< EADC_T::SMCTL4: ALIGN Position         */
#define EADC_SMCTL4_ALIGN_Msk            (0x1ul << EADC_SMCTL4_ALIGN_Pos)                  /*!< EADC_T::SMCTL4: ALIGN Mask             */

#define EADC_SMCTL4_AVG_Pos              (1)                                               /*!< EADC_T::SMCTL4: AVG Position           */
#define EADC_SMCTL4_AVG_Msk              (0x1ul << EADC_SMCTL4_AVG_Pos)                    /*!< EADC_T::SMCTL4: AVG Mask               */

#define EADC_SMCTL4_ACU_Pos              (4)                                               /*!< EADC_T::SMCTL4: ACU Position           */
#define EADC_SMCTL4_ACU_Msk              (0xful << EADC_SMCTL4_ACU_Pos)                    /*!< EADC_T::SMCTL4: ACU Mask               */

#define EADC_SMCTL5_ALIGN_Pos            (0)                                               /*!< EADC_T::SMCTL5: ALIGN Position         */
#define EADC_SMCTL5_ALIGN_Msk            (0x1ul << EADC_SMCTL5_ALIGN_Pos)                  /*!< EADC_T::SMCTL5: ALIGN Mask             */

#define EADC_SMCTL5_AVG_Pos              (1)                                               /*!< EADC_T::SMCTL5: AVG Position           */
#define EADC_SMCTL5_AVG_Msk              (0x1ul << EADC_SMCTL5_AVG_Pos)                    /*!< EADC_T::SMCTL5: AVG Mask               */

#define EADC_SMCTL5_ACU_Pos              (4)                                               /*!< EADC_T::SMCTL5: ACU Position           */
#define EADC_SMCTL5_ACU_Msk              (0xful << EADC_SMCTL5_ACU_Pos)                    /*!< EADC_T::SMCTL5: ACU Mask               */

#define EADC_SMCTL6_ALIGN_Pos            (0)                                               /*!< EADC_T::SMCTL6: ALIGN Position         */
#define EADC_SMCTL6_ALIGN_Msk            (0x1ul << EADC_SMCTL6_ALIGN_Pos)                  /*!< EADC_T::SMCTL6: ALIGN Mask             */

#define EADC_SMCTL6_AVG_Pos              (1)                                               /*!< EADC_T::SMCTL6: AVG Position           */
#define EADC_SMCTL6_AVG_Msk              (0x1ul << EADC_SMCTL6_AVG_Pos)                    /*!< EADC_T::SMCTL6: AVG Mask               */

#define EADC_SMCTL6_ACU_Pos              (4)                                               /*!< EADC_T::SMCTL6: ACU Position           */
#define EADC_SMCTL6_ACU_Msk              (0xful << EADC_SMCTL6_ACU_Pos)                    /*!< EADC_T::SMCTL6: ACU Mask               */

#define EADC_SMCTL7_ALIGN_Pos            (0)                                               /*!< EADC_T::SMCTL7: ALIGN Position         */
#define EADC_SMCTL7_ALIGN_Msk            (0x1ul << EADC_SMCTL7_ALIGN_Pos)                  /*!< EADC_T::SMCTL7: ALIGN Mask             */

#define EADC_SMCTL7_AVG_Pos              (1)                                               /*!< EADC_T::SMCTL7: AVG Position           */
#define EADC_SMCTL7_AVG_Msk              (0x1ul << EADC_SMCTL7_AVG_Pos)                    /*!< EADC_T::SMCTL7: AVG Mask               */

#define EADC_SMCTL7_ACU_Pos              (4)                                               /*!< EADC_T::SMCTL7: ACU Position           */
#define EADC_SMCTL7_ACU_Msk              (0xful << EADC_SMCTL7_ACU_Pos)                    /*!< EADC_T::SMCTL7: ACU Mask               */

#define EADC_TEST_PCHSEN_Pos             (0)                                               /*!< EADC_T::TEST: PCHSEN Position          */
#define EADC_TEST_PCHSEN_Msk             (0x1ul << EADC_TEST_PCHSEN_Pos)                   /*!< EADC_T::TEST: PCHSEN Mask              */

#define EADC_TEST_PCHSSEL_Pos            (4)                                               /*!< EADC_T::TEST: PCHSSEL Position         */
#define EADC_TEST_PCHSSEL_Msk            (0x7ul << EADC_TEST_PCHSSEL_Pos)                  /*!< EADC_T::TEST: PCHSSEL Mask             */

#define EADC_VERSION_MINOR_Pos           (0)                                               /*!< EADC_T::VERSION: MINOR Position        */
#define EADC_VERSION_MINOR_Msk           (0xfffful << EADC_VERSION_MINOR_Pos)              /*!< EADC_T::VERSION: MINOR Mask            */

#define EADC_VERSION_SUB_Pos             (16)                                              /*!< EADC_T::VERSION: SUB Position          */
#define EADC_VERSION_SUB_Msk             (0xfful << EADC_VERSION_SUB_Pos)                  /*!< EADC_T::VERSION: SUB Mask              */

#define EADC_VERSION_MAJOR_Pos           (24)                                              /*!< EADC_T::VERSION: MAJOR Position        */
#define EADC_VERSION_MAJOR_Msk           (0xfful << EADC_VERSION_MAJOR_Pos)                /*!< EADC_T::VERSION: MAJOR Mask            */

/**@}*/ /* EADC_CONST */
/**@}*/ /* end of EADC register group */

/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __EADC_REG_H__ */