/**************************************************************************//**
 * @file     rtc_reg.h
 * @brief    RTC register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __RTC_REG_H__
#define __RTC_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/

/** @addtogroup REGISTER Control Register

  @{

*/

/*---------------------- Real Time Clock Controller -------------------------*/
/**
    @addtogroup RTC Real Time Clock Controller(RTC)
    Memory Mapped Structure for RTC Controller
@{ */

typedef struct
{

    /**
     * @var RTC_T::INIT
     * Offset: 0x00  RTC Initiation Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |Active    |RTC Active Status (Read Only)
     * |        |          |0 = RTC is at reset state.
     * |        |          |1 = RTC is at normal active state.
     * |[31:1]  |INIT      |RTC Initiation
     * |        |          |After RTC block is powered on, RTC is at reset state
     * |        |          |User has to write a number (0x a5eb1357) to INIT to make RTC leaving reset state
     * |        |          |Once the INIT is written as 0xa5eb1357, the RTC will be in un-reset state permanently.
     * |        |          |The INIT is a write-only field and read value will be always u201C0u201D.
     * @var RTC_T::RWEN
     * Offset: 0x04  RTC Access Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[15:0]  |RWENPASSWD|RTC Register Access Enable Password (Write Only)
     * |        |          |Writing 0xA965 to this field will enable RTC access and keep 1024 RTC clock.
     * |[16]    |RWENF     |RTC Register Access Enable Flag (Read Only)
     * |        |          |0 = RTC register read/write Disabled.
     * |        |          |1 = RTC register read/write Enabled.
     * |        |          |Note: This bit will be set after RWENPASSWD (RTC_RWEN[15:0]) register is load a 0xA965, and will be cleared automatically after 1024 RTC clock.
     * @var RTC_T::FREQADJ
     * Offset: 0x08  RTC Frequency Compensation Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[5:0]   |FRACTION  |Fraction Part
     * |        |          |Formula: FRACTION = (fraction part of detected value) X 60.
     * |        |          |Note: Digit in FCR must be expressed as hexadecimal number.
     * |[11:8]  |INTEGER   |Integer Part
     * |        |          |0000 = Integer part of detected value is 32761.
     * |        |          |0001 = Integer part of detected value is 32762.
     * |        |          |0010 = Integer part of detected value is 32763.
     * |        |          |0011 = Integer part of detected value is 32764.
     * |        |          |0100 = Integer part of detected value is 32765.
     * |        |          |0101 = Integer part of detected value is 32766.
     * |        |          |0110 = Integer part of detected value is 32767.
     * |        |          |0111 = Integer part of detected value is 32768.
     * |        |          |1000 = Integer part of detected value is 32769.
     * |        |          |1001 = Integer part of detected value is 32770.
     * |        |          |1010 = Integer part of detected value is 32771.
     * |        |          |1011 = Integer part of detected value is 32772.
     * |        |          |1100 = Integer part of detected value is 32773.
     * @var RTC_T::TIME
     * Offset: 0x0C  RTC Time Counter Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |SECOND    |1 Sec Time Digit (0 ~ 9)
     * |[6:4]   |TENSECOND |10 Sec Time Digit (0 ~ 5)
     * |[11:8]  |MINUTE    |1 Min Time Digit (0 ~ 9)
     * |[14:12] |TENMINUTE |10 Min Time Digit (0 ~ 5)
     * |[19:16] |HOUR      |1 Hour Time Digit (0 ~ 9)
     * |[21:20] |TENHOUR   |10 Hour Time Digit (0 ~ 2)
     * @var RTC_T::CAL
     * Offset: 0x10  RTC Calendar Counter Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |DAY       |1-Day Calendar Digit (0 ~ 9)
     * |[5:4]   |TENDAY    |10-Day Calendar Digit (0 ~ 3)
     * |[11:8]  |MONTH     |1-Month Calendar Digit (0 ~ 9)
     * |[12]    |TENMONTH  |10-Month Calendar Digit (0 ~ 1)
     * |[19:16] |YEAR      |1-Year Calendar Digit (0 ~ 9)
     * |[23:20] |TENYEAR   |10-Year Calendar Digit (0 ~ 9)
     * @var RTC_T::TIMEFMT
     * Offset: 0x14  RTC Time Format Selection Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |24HEN     |24-hour / 12-hour Mode Selection
     * |        |          |It indicate that TLR and TAR are in 24-hour mode or 12-hour mode
     * |        |          |0 = 12-hour time format with am and pm indication selected.
     * |        |          |1 = 24-hour time format selected.
     * @var RTC_T::WEEKDAY
     * Offset: 0x18  RTC Day of the Week Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[2:0]   |WEEKDAY   |Day of the Week
     * |        |          |0x0 = Sunday.
     * |        |          |0x1 = Monday.
     * |        |          |0x2 = Tuesday.
     * |        |          |0x3 = Wednesday.
     * |        |          |0x4 = Thursday.
     * |        |          |0x5 = Friday.
     * |        |          |0x6 = Saturday.
     * |        |          |Others = Reserved.
     * @var RTC_T::TALM
     * Offset: 0x1C  RTC Time Alarm Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |SECOND    |1 Sec Time Digit (0 ~ 9)
     * |[6:4]   |TENSECOND |10 Sec Time Digit (0 ~ 5)
     * |[11:8]  |MINUTE    |1 Min Time Digit (0 ~ 9)
     * |[14:12] |TENMINUTE |10 Min Time Digit (0 ~ 5)
     * |[19:16] |HOUR      |1 Hour Time Digit (0 ~ 9)
     * |[21:20] |TENHOUR   |10 Hour Time Digit (0 ~ 2)
     * |[28]    |SECALM_MSK|Minute Alarm Mask
     * |        |          |This bit controls if TENSECOND (RTC_TALM[6:4] and SECOND (RTC_TALM[3:0]) could trigger RTC timer alarm.
     * |        |          |0 = TENSECOND (RTC_TALM[6:4] and SECOND (RTC_TALM[3:0]) could trigger RTC time alarm.
     * |        |          |1 = TENSECOND (RTC_TALM[6:4] and SECOND (RTC_TALM[3:0]) couldnu2019t trigger RTC time alarm.
     * |[29]    |MINALM_MSK|Minute Alarm Mask
     * |        |          |This bit controls if TENMINUTE (RTC_TALM[14:12] and MINUTE (RTC_TALM[11:8]) could trigger RTC timer alarm.
     * |        |          |0 = TENMINUTE (RTC_TALM[14:12] and MINUTE (RTC_TALM[11:8]) could trigger RTC time alarm.
     * |        |          |1 = TENMINUTE (RTC_TALM[14:12] and MINUTE (RTC_TALM[11:8]) couldnu2019t trigger RTC time alarm.
     * |[30]    |HRALM_MSK |Hour Alarm Mask
     * |        |          |This bit controls if TENHOUR (RTC_TALM[21:20] and HOUR (RTC_TALM[19:16]) could trigger RTC timer alarm.
     * |        |          |0 = TENHOUR (RTC_TALM[21:20] and HOUR (RTC_TALM[19:16]) could trigger RTC time alarm.
     * |        |          |1 = TENHOUR (RTC_TALM[21:20] and HOUR (RTC_TALM[19:16]) couldnu2019t trigger RTC time alarm.
     * @var RTC_T::CALM
     * Offset: 0x20  RTC Calendar Alarm Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3:0]   |DAY       |1-Day Calendar Digit (0 ~ 9)
     * |[5:4]   |TENDAY    |10-Day Calendar Digit (0 ~ 3)
     * |[11:8]  |MONTH     |1-Month Calendar Digit (0 ~ 9)
     * |[12]    |TENMONTH  |10-Month Calendar Digit (0 ~ 1)
     * |[19:16] |YEAR      |1-Year Calendar Digit (0 ~ 9)
     * |[23:20] |TENYEAR   |10-Year Calendar Digit (0 ~ 9)
     * |[26:24] |WEEKDAY   |Day of the Week
     * |        |          |000 = Sunday.
     * |        |          |001 = Monday.
     * |        |          |010 = Tuesday.
     * |        |          |011 = Wednesday.
     * |        |          |100 = Thursday.
     * |        |          |101 = Friday.
     * |        |          |110 = Saturday.
     * |        |          |111 = Reserved.
     * |[28]    |DAYALM_MSK|Day Alarm Mask
     * |        |          |This bit controls if TENDAY (RTC_CALM[5:4]) and DAY (RTC_CALM[3:0]) could trigger RTC timer alarm.
     * |        |          |0 = TENDAY (RTC_CALM[5:4]) and DAY (RTC_CALM[3:0]) could trigger RTC time alarm.
     * |        |          |1 = TENDAY (RTC_CALM[5:4]) and DAY (RTC_CALM[3:0]) couldnu2019t trigger RTC time alarm.
     * |[29]    |MONALM_MSK|Month Alarm Mask
     * |        |          |This bit controls if TENMONTH (RTC_CALM[12]) and MONTH (RTC_CALM[11:8]) could trigger RTC timer alarm.
     * |        |          |0 = TENMONTH (RTC_CALM[12]) and MONTH (RTC_CALM[11:8]) could trigger RTC time alarm.
     * |        |          |1 = TENMONTH (RTC_CALM[12]) and MONTH (RTC_CALM[11:8]) couldnu2019t trigger RTC time alarm.
     * |[30]    |YRALM_MSK |Year Alarm Mask
     * |        |          |This bit controls if TENYEAR (RTC_CALM[23:20]) and YEAR (RTC_CALM[19:16]) could trigger RTC timer alarm.
     * |        |          |0 = TENYEAR (RTC_CALM[23:20]) and YEAR (RTC_CALM[19:16]) could trigger RTC time alarm.
     * |        |          |1 = TENYEAR (RTC_CALM[23:20]) and YEAR (RTC_CALM[19:16]) couldnu2019t trigger RTC time alarm.
     * |[31]    |WKDALM_MSK|Day of Week Alarm Mask
     * |        |          |This bit controls if WEEKDAY (RTC_CALM[26:24]) could trigger RTC timer alarm.
     * |        |          |0 = WEEKDAY (RTC_CALM[26:24]) could trigger RTC time alarm.
     * |        |          |1 = WEEKDAY (RTC_CALM[26:24]) couldnu2019t trigger RTC time alarm.
     * @var RTC_T::LEAPYEAR
     * Offset: 0x24  RTC Leap Year Indicator Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |LEAPYEAR  |Leap Year Indicator (Read Only)
     * |        |          |0 = It indicates that this year is not a leap year.
     * |        |          |1 = It indicates that this year is leap year.
     * @var RTC_T::INTEN
     * Offset: 0x28  RTC Interrupt Enable Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ALMIEN    |Alarm Interrupt Enable Bit
     * |        |          |0 = RTC Alarm Interrupt Disabled.
     * |        |          |1 = RTC Alarm Interrupt Enabled.
     * |[1]     |TICKIEN   |Tick Interrupt Enable Bit
     * |        |          |0 = RTC Time Tick Interrupt Disabled.
     * |        |          |1 = RTC Time Tick Interrupt Enabled.
     * |[4]     |RELALMIEN |Relative Alarm Interrupt Enable Bit
     * |        |          |0 = RTC Relative Alarm interrupt Disabled.
     * |        |          |1 = RTC Relative Alarm interrupt Enabled.
     * @var RTC_T::INTSTS
     * Offset: 0x2C  RTC Interrupt Status Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |ALMINT    |RTC Alarm Interrupt Indication REGISTER
     * |        |          |This bit indicates the RTC_TIME and RTC_CAL counter have counted to value configured in RTC_TALM and RTC_CALM
     * |        |          |User can write 1 to clear this bit.
     * |        |          |0 = It indicates that alarm interrupt has never occurred.
     * |        |          |1 = It indicates that RTC_TIME and RTC_CAL counter have counted to a specified time configured in RTC_TALM and RTC_CALM.
     * |[1]     |TICKINT   |RTC Time Tick Interrupt Indication REGISTER
     * |        |          |This bit indicates the RTC timer tick value configured in RTC_TICK has reached
     * |        |          |User can write 1 to clear this bit.
     * |        |          |0 = RTC timer tick value configured in RTC_TICK didnu2019t reach.
     * |        |          |1 = RTC timer tick value configured in RTC_TICK has reached.
     * |[2]     |WAKEUPINT |Wakeup Interrupt Status
     * |        |          |This bit indicates the RTC generates a wakeup event to wakeup system from Power-down mode
     * |        |          |In RTC, the wakeup source includes the RTC alarm and RTC related alarm
     * |        |          |User can write 1 to clear this bit.
     * |        |          |0 = RTC event to wakeup system has never occurred.
     * |        |          |1 = RTC event to wakeup system occurred.
     * |[4]     |RELALMINT |Relative Alarm Interrupt Status
     * |        |          |This bit high indicates the related timer have counted down to zero
     * |        |          |User can write 1 to clear this bit.
     * |        |          |0 = Related timer didnu2019t count down to zero.
     * |        |          |1 = Related timer counts down to zero.
     * |[31]    |REGWRBUSY |Register Write Operation Busy
     * |        |          |0 = The new register write operation is acceptable.
     * |        |          |1 = The last write operation is in progress and new register write operation prohibited.
     * @var RTC_T::TICK
     * Offset: 0x30  RTC Time Tick Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[2:0]   |TTR       |RTC Tick Time Interrupt Request Interval
     * |        |          |The TTR [2:0] is used to select tick time interrupt request interval
     * |        |          |The period of tick time interrupt is as follow:
     * |        |          |000 = 1 second.
     * |        |          |001 = 1/2 second.
     * |        |          |010 = 1/4 second.
     * |        |          |011 = 1/8 second.
     * |        |          |100 = 1/16 second.
     * |        |          |101 = 1/32 second.
     * |        |          |110 = 1/64 second.
     * |        |          |111 = 1/128 second.
     * @var RTC_T::PWRCTL
     * Offset: 0x34  RTC Power Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[3]     |ALM_EN    |Alarm Function Enable Bit
     * |        |          |Set this bit high would enable the alarm function
     * |        |          |When the alarm condition met, RTC would set ALMINT (RTC_INTSTS[0]) interrupt status to high.
     * |        |          |0 = Alarm function Disabled.
     * |        |          |1 = Alarm function Enabled.
     * |[4]     |RELALM_EN |Relative Alarm Function Enable Bit
     * |        |          |Set this bit high would enable the relative alarm function
     * |        |          |When the relative alarm condition met, RTC would set RELALMINT (RTC_INTSTS[4]) interrupt status to high.
     * |        |          |0 = Relative alarm function Disabled.
     * |        |          |1 = Relative alarm function Enabled.
     * |[27:16] |RELALM_TIME|Relative Alarm Time
     * |        |          |This field defines the relative alarm time period by unit second. The maximum value is 12u2019d1800.
     * @var RTC_T::PWRCNT
     * Offset: 0x38  RTC Power Control Counter Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[11:0]  |RELALM_CNT|Relative Alarm Counter Current Value (Read Only)
     * |        |          |This field shows the current value of relative alarm counter.
     * @var RTC_T::CLKCTL
     * Offset: 0x3C  RTC 32.768 kHz Clock Control Register
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[0]     |CLKEN     |32.768 kHz Clock Enable Bit
     * |        |          |0 = The 32.768 kHz clock macro Disabled.
     * |        |          |1 = The 32.768 kHz clock macro Enabled.
     * |[1]     |CLKMOD    |32.768 kHz Clock Mode Selection
     * |        |          |0 = The 32.768 kHz clock macro is operating in strong mode (8uA).
     * |        |          |1 = The 32.768 kHz clock macro is operating in weak mode (2uA).
     * @var RTC_T::SPR0
     * Offset: 0x40  RTC Spare Register 0
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     * @var RTC_T::SPR1
     * Offset: 0x44  RTC Spare Register 1
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     * @var RTC_T::SPR2
     * Offset: 0x48  RTC Spare Register 2
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     * @var RTC_T::SPR3
     * Offset: 0x4C  RTC Spare Register 3
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     * @var RTC_T::SPR4
     * Offset: 0x50  RTC Spare Register 4
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     * @var RTC_T::SPR5
     * Offset: 0x54  RTC Spare Register 5
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     * @var RTC_T::SPR6
     * Offset: 0x58  RTC Spare Register 6
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     * @var RTC_T::SPR7
     * Offset: 0x5C  RTC Spare Register 7
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     * @var RTC_T::SPR8
     * Offset: 0x60  RTC Spare Register 8
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     * @var RTC_T::SPR9
     * Offset: 0x64  RTC Spare Register 9
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     * @var RTC_T::SPR10
     * Offset: 0x68  RTC Spare Register 10
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     * @var RTC_T::SPR11
     * Offset: 0x6C  RTC Spare Register 11
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     * @var RTC_T::SPR12
     * Offset: 0x70  RTC Spare Register 12
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     * @var RTC_T::SPR13
     * Offset: 0x74  RTC Spare Register 13
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     * @var RTC_T::SPR14
     * Offset: 0x78  RTC Spare Register 14
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     * @var RTC_T::SPR15
     * Offset: 0x7C  RTC Spare Register 15
     * ---------------------------------------------------------------------------------------------------
     * |Bits    |Field     |Descriptions
     * | :----: | :----:   | :---- |
     * |[31:0]  |DATA      |Data
     * |        |          |This register is used to keep information written by user.
     */
    __IO uint32_t INIT;                  /*!< [0x0000] RTC Initiation Register                                          */
    __IO uint32_t RWEN;                  /*!< [0x0004] RTC Access Enable Register                                       */
    __IO uint32_t FREQADJ;               /*!< [0x0008] RTC Frequency Compensation Register                              */
    __IO uint32_t TIME;                  /*!< [0x000c] RTC Time Counter Register                                        */
    __IO uint32_t CAL;                   /*!< [0x0010] RTC Calendar Counter Register                                    */
    __IO uint32_t TIMEFMT;               /*!< [0x0014] RTC Time Format Selection Register                               */
    __IO uint32_t WEEKDAY;               /*!< [0x0018] RTC Day of the Week Register                                     */
    __IO uint32_t TALM;                  /*!< [0x001c] RTC Time Alarm Register                                          */
    __IO uint32_t CALM;                  /*!< [0x0020] RTC Calendar Alarm Register                                      */
    __I  uint32_t LEAPYEAR;              /*!< [0x0024] RTC Leap Year Indicator Register                                 */
    __IO uint32_t INTEN;                 /*!< [0x0028] RTC Interrupt Enable Register                                    */
    __IO uint32_t INTSTS;                /*!< [0x002c] RTC Interrupt Status Register                                    */
    __IO uint32_t TICK;                  /*!< [0x0030] RTC Time Tick Register                                           */
    __IO uint32_t PWRCTL;                /*!< [0x0034] RTC Power Control Register                                       */
    __I  uint32_t PWRCNT;                /*!< [0x0038] RTC Power Control Counter Register                               */
    __IO uint32_t CLKCTL;                /*!< [0x003c] RTC 32.768 kHz Clock Control Register                            */
    __IO uint32_t SPR0;                  /*!< [0x0040] RTC Spare Register 0                                             */
    __IO uint32_t SPR1;                  /*!< [0x0044] RTC Spare Register 1                                             */
    __IO uint32_t SPR2;                  /*!< [0x0048] RTC Spare Register 2                                             */
    __IO uint32_t SPR3;                  /*!< [0x004c] RTC Spare Register 3                                             */
    __IO uint32_t SPR4;                  /*!< [0x0050] RTC Spare Register 4                                             */
    __IO uint32_t SPR5;                  /*!< [0x0054] RTC Spare Register 5                                             */
    __IO uint32_t SPR6;                  /*!< [0x0058] RTC Spare Register 6                                             */
    __IO uint32_t SPR7;                  /*!< [0x005c] RTC Spare Register 7                                             */
    __IO uint32_t SPR8;                  /*!< [0x0060] RTC Spare Register 8                                             */
    __IO uint32_t SPR9;                  /*!< [0x0064] RTC Spare Register 9                                             */
    __IO uint32_t SPR10;                 /*!< [0x0068] RTC Spare Register 10                                            */
    __IO uint32_t SPR11;                 /*!< [0x006c] RTC Spare Register 11                                            */
    __IO uint32_t SPR12;                 /*!< [0x0070] RTC Spare Register 12                                            */
    __IO uint32_t SPR13;                 /*!< [0x0074] RTC Spare Register 13                                            */
    __IO uint32_t SPR14;                 /*!< [0x0078] RTC Spare Register 14                                            */
    __IO uint32_t SPR15;                 /*!< [0x007c] RTC Spare Register 15                                            */

} RTC_T;

/**
    @addtogroup RTC_CONST RTC Bit Field Definition
    Constant Definitions for RTC Controller
@{ */

#define RTC_INIT_Active_Pos              (0)                                               /*!< RTC_T::INIT: Active Position           */
#define RTC_INIT_Active_Msk              (0x1ul << RTC_INIT_Active_Pos)                    /*!< RTC_T::INIT: Active Mask               */

#define RTC_INIT_INIT_Pos                (1)                                               /*!< RTC_T::INIT: INIT Position             */
#define RTC_INIT_INIT_Msk                (0x7ffffffful << RTC_INIT_INIT_Pos)               /*!< RTC_T::INIT: INIT Mask                 */

#define RTC_RWEN_RWENPASSWD_Pos          (0)                                               /*!< RTC_T::RWEN: RWENPASSWD Position       */
#define RTC_RWEN_RWENPASSWD_Msk          (0xfffful << RTC_RWEN_RWENPASSWD_Pos)             /*!< RTC_T::RWEN: RWENPASSWD Mask           */

#define RTC_RWEN_RWENF_Pos               (16)                                              /*!< RTC_T::RWEN: RWENF Position            */
#define RTC_RWEN_RWENF_Msk               (0x1ul << RTC_RWEN_RWENF_Pos)                     /*!< RTC_T::RWEN: RWENF Mask                */

#define RTC_FREQADJ_FRACTION_Pos         (0)                                               /*!< RTC_T::FREQADJ: FRACTION Position      */
#define RTC_FREQADJ_FRACTION_Msk         (0x3ful << RTC_FREQADJ_FRACTION_Pos)              /*!< RTC_T::FREQADJ: FRACTION Mask          */

#define RTC_FREQADJ_INTEGER_Pos          (8)                                               /*!< RTC_T::FREQADJ: INTEGER Position       */
#define RTC_FREQADJ_INTEGER_Msk          (0xful << RTC_FREQADJ_INTEGER_Pos)                /*!< RTC_T::FREQADJ: INTEGER Mask           */

#define RTC_TIME_SECOND_Pos              (0)                                               /*!< RTC_T::TIME: SECOND Position           */
#define RTC_TIME_SECOND_Msk              (0xful << RTC_TIME_SECOND_Pos)                    /*!< RTC_T::TIME: SECOND Mask               */

#define RTC_TIME_TENSECOND_Pos           (4)                                               /*!< RTC_T::TIME: TENSECOND Position        */
#define RTC_TIME_TENSECOND_Msk           (0x7ul << RTC_TIME_TENSECOND_Pos)                 /*!< RTC_T::TIME: TENSECOND Mask            */

#define RTC_TIME_MINUTE_Pos              (8)                                               /*!< RTC_T::TIME: MINUTE Position           */
#define RTC_TIME_MINUTE_Msk              (0xful << RTC_TIME_MINUTE_Pos)                    /*!< RTC_T::TIME: MINUTE Mask               */

#define RTC_TIME_TENMINUTE_Pos           (12)                                              /*!< RTC_T::TIME: TENMINUTE Position        */
#define RTC_TIME_TENMINUTE_Msk           (0x7ul << RTC_TIME_TENMINUTE_Pos)                 /*!< RTC_T::TIME: TENMINUTE Mask            */

#define RTC_TIME_HOUR_Pos                (16)                                              /*!< RTC_T::TIME: HOUR Position             */
#define RTC_TIME_HOUR_Msk                (0xful << RTC_TIME_HOUR_Pos)                      /*!< RTC_T::TIME: HOUR Mask                 */

#define RTC_TIME_TENHOUR_Pos             (20)                                              /*!< RTC_T::TIME: TENHOUR Position          */
#define RTC_TIME_TENHOUR_Msk             (0x3ul << RTC_TIME_TENHOUR_Pos)                   /*!< RTC_T::TIME: TENHOUR Mask              */

#define RTC_CAL_DAY_Pos                  (0)                                               /*!< RTC_T::CAL: DAY Position               */
#define RTC_CAL_DAY_Msk                  (0xful << RTC_CAL_DAY_Pos)                        /*!< RTC_T::CAL: DAY Mask                   */

#define RTC_CAL_TENDAY_Pos               (4)                                               /*!< RTC_T::CAL: TENDAY Position            */
#define RTC_CAL_TENDAY_Msk               (0x3ul << RTC_CAL_TENDAY_Pos)                     /*!< RTC_T::CAL: TENDAY Mask                */

#define RTC_CAL_MONTH_Pos                (8)                                               /*!< RTC_T::CAL: MONTH Position             */
#define RTC_CAL_MONTH_Msk                (0xful << RTC_CAL_MONTH_Pos)                      /*!< RTC_T::CAL: MONTH Mask                 */

#define RTC_CAL_TENMONTH_Pos             (12)                                              /*!< RTC_T::CAL: TENMONTH Position          */
#define RTC_CAL_TENMONTH_Msk             (0x1ul << RTC_CAL_TENMONTH_Pos)                   /*!< RTC_T::CAL: TENMONTH Mask              */

#define RTC_CAL_YEAR_Pos                 (16)                                              /*!< RTC_T::CAL: YEAR Position              */
#define RTC_CAL_YEAR_Msk                 (0xful << RTC_CAL_YEAR_Pos)                       /*!< RTC_T::CAL: YEAR Mask                  */

#define RTC_CAL_TENYEAR_Pos              (20)                                              /*!< RTC_T::CAL: TENYEAR Position           */
#define RTC_CAL_TENYEAR_Msk              (0xful << RTC_CAL_TENYEAR_Pos)                    /*!< RTC_T::CAL: TENYEAR Mask               */

#define RTC_TIMEFMT_24HEN_Pos            (0)                                               /*!< RTC_T::TIMEFMT: 24HEN Position         */
#define RTC_TIMEFMT_24HEN_Msk            (0x1ul << RTC_TIMEFMT_24HEN_Pos)                  /*!< RTC_T::TIMEFMT: 24HEN Mask             */

#define RTC_WEEKDAY_WEEKDAY_Pos          (0)                                               /*!< RTC_T::WEEKDAY: WEEKDAY Position       */
#define RTC_WEEKDAY_WEEKDAY_Msk          (0x7ul << RTC_WEEKDAY_WEEKDAY_Pos)                /*!< RTC_T::WEEKDAY: WEEKDAY Mask           */

#define RTC_TALM_SECOND_Pos              (0)                                               /*!< RTC_T::TALM: SECOND Position           */
#define RTC_TALM_SECOND_Msk              (0xful << RTC_TALM_SECOND_Pos)                    /*!< RTC_T::TALM: SECOND Mask               */

#define RTC_TALM_TENSECOND_Pos           (4)                                               /*!< RTC_T::TALM: TENSECOND Position        */
#define RTC_TALM_TENSECOND_Msk           (0x7ul << RTC_TALM_TENSECOND_Pos)                 /*!< RTC_T::TALM: TENSECOND Mask            */

#define RTC_TALM_MINUTE_Pos              (8)                                               /*!< RTC_T::TALM: MINUTE Position           */
#define RTC_TALM_MINUTE_Msk              (0xful << RTC_TALM_MINUTE_Pos)                    /*!< RTC_T::TALM: MINUTE Mask               */

#define RTC_TALM_TENMINUTE_Pos           (12)                                              /*!< RTC_T::TALM: TENMINUTE Position        */
#define RTC_TALM_TENMINUTE_Msk           (0x7ul << RTC_TALM_TENMINUTE_Pos)                 /*!< RTC_T::TALM: TENMINUTE Mask            */

#define RTC_TALM_HOUR_Pos                (16)                                              /*!< RTC_T::TALM: HOUR Position             */
#define RTC_TALM_HOUR_Msk                (0xful << RTC_TALM_HOUR_Pos)                      /*!< RTC_T::TALM: HOUR Mask                 */

#define RTC_TALM_TENHOUR_Pos             (20)                                              /*!< RTC_T::TALM: TENHOUR Position          */
#define RTC_TALM_TENHOUR_Msk             (0x3ul << RTC_TALM_TENHOUR_Pos)                   /*!< RTC_T::TALM: TENHOUR Mask              */

#define RTC_TALM_SECALM_MSK_Pos          (28)                                              /*!< RTC_T::TALM: SECALM_MSK Position       */
#define RTC_TALM_SECALM_MSK_Msk          (0x1ul << RTC_TALM_SECALM_MSK_Pos)                /*!< RTC_T::TALM: SECALM_MSK Mask           */

#define RTC_TALM_MINALM_MSK_Pos          (29)                                              /*!< RTC_T::TALM: MINALM_MSK Position       */
#define RTC_TALM_MINALM_MSK_Msk          (0x1ul << RTC_TALM_MINALM_MSK_Pos)                /*!< RTC_T::TALM: MINALM_MSK Mask           */

#define RTC_TALM_HRALM_MSK_Pos           (30)                                              /*!< RTC_T::TALM: HRALM_MSK Position        */
#define RTC_TALM_HRALM_MSK_Msk           (0x1ul << RTC_TALM_HRALM_MSK_Pos)                 /*!< RTC_T::TALM: HRALM_MSK Mask            */

#define RTC_CALM_DAY_Pos                 (0)                                               /*!< RTC_T::CALM: DAY Position              */
#define RTC_CALM_DAY_Msk                 (0xful << RTC_CALM_DAY_Pos)                       /*!< RTC_T::CALM: DAY Mask                  */

#define RTC_CALM_TENDAY_Pos              (4)                                               /*!< RTC_T::CALM: TENDAY Position           */
#define RTC_CALM_TENDAY_Msk              (0x3ul << RTC_CALM_TENDAY_Pos)                    /*!< RTC_T::CALM: TENDAY Mask               */

#define RTC_CALM_MONTH_Pos               (8)                                               /*!< RTC_T::CALM: MONTH Position            */
#define RTC_CALM_MONTH_Msk               (0xful << RTC_CALM_MONTH_Pos)                     /*!< RTC_T::CALM: MONTH Mask                */

#define RTC_CALM_TENMONTH_Pos            (12)                                              /*!< RTC_T::CALM: TENMONTH Position         */
#define RTC_CALM_TENMONTH_Msk            (0x1ul << RTC_CALM_TENMONTH_Pos)                  /*!< RTC_T::CALM: TENMONTH Mask             */

#define RTC_CALM_YEAR_Pos                (16)                                              /*!< RTC_T::CALM: YEAR Position             */
#define RTC_CALM_YEAR_Msk                (0xful << RTC_CALM_YEAR_Pos)                      /*!< RTC_T::CALM: YEAR Mask                 */

#define RTC_CALM_TENYEAR_Pos             (20)                                              /*!< RTC_T::CALM: TENYEAR Position          */
#define RTC_CALM_TENYEAR_Msk             (0xful << RTC_CALM_TENYEAR_Pos)                   /*!< RTC_T::CALM: TENYEAR Mask              */

#define RTC_CALM_WEEKDAY_Pos             (24)                                              /*!< RTC_T::CALM: WEEKDAY Position          */
#define RTC_CALM_WEEKDAY_Msk             (0x7ul << RTC_CALM_WEEKDAY_Pos)                   /*!< RTC_T::CALM: WEEKDAY Mask              */

#define RTC_CALM_DAYALM_MSK_Pos          (28)                                              /*!< RTC_T::CALM: DAYALM_MSK Position       */
#define RTC_CALM_DAYALM_MSK_Msk          (0x1ul << RTC_CALM_DAYALM_MSK_Pos)                /*!< RTC_T::CALM: DAYALM_MSK Mask           */

#define RTC_CALM_MONALM_MSK_Pos          (29)                                              /*!< RTC_T::CALM: MONALM_MSK Position       */
#define RTC_CALM_MONALM_MSK_Msk          (0x1ul << RTC_CALM_MONALM_MSK_Pos)                /*!< RTC_T::CALM: MONALM_MSK Mask           */

#define RTC_CALM_YRALM_MSK_Pos           (30)                                              /*!< RTC_T::CALM: YRALM_MSK Position        */
#define RTC_CALM_YRALM_MSK_Msk           (0x1ul << RTC_CALM_YRALM_MSK_Pos)                 /*!< RTC_T::CALM: YRALM_MSK Mask            */

#define RTC_CALM_WKDALM_MSK_Pos          (31)                                              /*!< RTC_T::CALM: WKDALM_MSK Position       */
#define RTC_CALM_WKDALM_MSK_Msk          (0x1ul << RTC_CALM_WKDALM_MSK_Pos)                /*!< RTC_T::CALM: WKDALM_MSK Mask           */

#define RTC_LEAPYEAR_LEAPYEAR_Pos        (0)                                               /*!< RTC_T::LEAPYEAR: LEAPYEAR Position     */
#define RTC_LEAPYEAR_LEAPYEAR_Msk        (0x1ul << RTC_LEAPYEAR_LEAPYEAR_Pos)              /*!< RTC_T::LEAPYEAR: LEAPYEAR Mask         */

#define RTC_INTEN_ALMIEN_Pos             (0)                                               /*!< RTC_T::INTEN: ALMIEN Position          */
#define RTC_INTEN_ALMIEN_Msk             (0x1ul << RTC_INTEN_ALMIEN_Pos)                   /*!< RTC_T::INTEN: ALMIEN Mask              */

#define RTC_INTEN_TICKIEN_Pos            (1)                                               /*!< RTC_T::INTEN: TICKIEN Position         */
#define RTC_INTEN_TICKIEN_Msk            (0x1ul << RTC_INTEN_TICKIEN_Pos)                  /*!< RTC_T::INTEN: TICKIEN Mask             */

#define RTC_INTEN_RELALMIEN_Pos          (4)                                               /*!< RTC_T::INTEN: RELALMIEN Position       */
#define RTC_INTEN_RELALMIEN_Msk          (0x1ul << RTC_INTEN_RELALMIEN_Pos)                /*!< RTC_T::INTEN: RELALMIEN Mask           */

#define RTC_INTSTS_ALMINT_Pos            (0)                                               /*!< RTC_T::INTSTS: ALMINT Position         */
#define RTC_INTSTS_ALMINT_Msk            (0x1ul << RTC_INTSTS_ALMINT_Pos)                  /*!< RTC_T::INTSTS: ALMINT Mask             */

#define RTC_INTSTS_TICKINT_Pos           (1)                                               /*!< RTC_T::INTSTS: TICKINT Position        */
#define RTC_INTSTS_TICKINT_Msk           (0x1ul << RTC_INTSTS_TICKINT_Pos)                 /*!< RTC_T::INTSTS: TICKINT Mask            */

#define RTC_INTSTS_WAKEUPINT_Pos         (2)                                               /*!< RTC_T::INTSTS: WAKEUPINT Position      */
#define RTC_INTSTS_WAKEUPINT_Msk         (0x1ul << RTC_INTSTS_WAKEUPINT_Pos)               /*!< RTC_T::INTSTS: WAKEUPINT Mask          */

#define RTC_INTSTS_RELALMINT_Pos         (4)                                               /*!< RTC_T::INTSTS: RELALMINT Position      */
#define RTC_INTSTS_RELALMINT_Msk         (0x1ul << RTC_INTSTS_RELALMINT_Pos)               /*!< RTC_T::INTSTS: RELALMINT Mask          */

#define RTC_INTSTS_REGWRBUSY_Pos         (31)                                              /*!< RTC_T::INTSTS: REGWRBUSY Position      */
#define RTC_INTSTS_REGWRBUSY_Msk         (0x1ul << RTC_INTSTS_REGWRBUSY_Pos)               /*!< RTC_T::INTSTS: REGWRBUSY Mask          */

#define RTC_TICK_TTR_Pos                 (0)                                               /*!< RTC_T::TICK: TTR Position              */
#define RTC_TICK_TTR_Msk                 (0x7ul << RTC_TICK_TTR_Pos)                       /*!< RTC_T::TICK: TTR Mask                  */

#define RTC_PWRCTL_ALM_EN_Pos            (3)                                               /*!< RTC_T::PWRCTL: ALM_EN Position         */
#define RTC_PWRCTL_ALM_EN_Msk            (0x1ul << RTC_PWRCTL_ALM_EN_Pos)                  /*!< RTC_T::PWRCTL: ALM_EN Mask             */

#define RTC_PWRCTL_RELALM_EN_Pos         (4)                                               /*!< RTC_T::PWRCTL: RELALM_EN Position      */
#define RTC_PWRCTL_RELALM_EN_Msk         (0x1ul << RTC_PWRCTL_RELALM_EN_Pos)               /*!< RTC_T::PWRCTL: RELALM_EN Mask          */

#define RTC_PWRCTL_RELALM_TIME_Pos       (16)                                              /*!< RTC_T::PWRCTL: RELALM_TIME Position    */
#define RTC_PWRCTL_RELALM_TIME_Msk       (0xffful << RTC_PWRCTL_RELALM_TIME_Pos)           /*!< RTC_T::PWRCTL: RELALM_TIME Mask        */

#define RTC_PWRCNT_RELALM_CNT_Pos        (0)                                               /*!< RTC_T::PWRCNT: RELALM_CNT Position     */
#define RTC_PWRCNT_RELALM_CNT_Msk        (0xffful << RTC_PWRCNT_RELALM_CNT_Pos)            /*!< RTC_T::PWRCNT: RELALM_CNT Mask         */

#define RTC_CLKCTL_CLKEN_Pos             (0)                                               /*!< RTC_T::CLKCTL: CLKEN Position          */
#define RTC_CLKCTL_CLKEN_Msk             (0x1ul << RTC_CLKCTL_CLKEN_Pos)                   /*!< RTC_T::CLKCTL: CLKEN Mask              */

#define RTC_CLKCTL_CLKMOD_Pos            (1)                                               /*!< RTC_T::CLKCTL: CLKMOD Position         */
#define RTC_CLKCTL_CLKMOD_Msk            (0x1ul << RTC_CLKCTL_CLKMOD_Pos)                  /*!< RTC_T::CLKCTL: CLKMOD Mask             */

#define RTC_SPR0_DATA_Pos                (0)                                               /*!< RTC_T::SPR0: DATA Position             */
#define RTC_SPR0_DATA_Msk                (0xfffffffful << RTC_SPR0_DATA_Pos)               /*!< RTC_T::SPR0: DATA Mask                 */

#define RTC_SPR1_DATA_Pos                (0)                                               /*!< RTC_T::SPR1: DATA Position             */
#define RTC_SPR1_DATA_Msk                (0xfffffffful << RTC_SPR1_DATA_Pos)               /*!< RTC_T::SPR1: DATA Mask                 */

#define RTC_SPR2_DATA_Pos                (0)                                               /*!< RTC_T::SPR2: DATA Position             */
#define RTC_SPR2_DATA_Msk                (0xfffffffful << RTC_SPR2_DATA_Pos)               /*!< RTC_T::SPR2: DATA Mask                 */

#define RTC_SPR3_DATA_Pos                (0)                                               /*!< RTC_T::SPR3: DATA Position             */
#define RTC_SPR3_DATA_Msk                (0xfffffffful << RTC_SPR3_DATA_Pos)               /*!< RTC_T::SPR3: DATA Mask                 */

#define RTC_SPR4_DATA_Pos                (0)                                               /*!< RTC_T::SPR4: DATA Position             */
#define RTC_SPR4_DATA_Msk                (0xfffffffful << RTC_SPR4_DATA_Pos)               /*!< RTC_T::SPR4: DATA Mask                 */

#define RTC_SPR5_DATA_Pos                (0)                                               /*!< RTC_T::SPR5: DATA Position             */
#define RTC_SPR5_DATA_Msk                (0xfffffffful << RTC_SPR5_DATA_Pos)               /*!< RTC_T::SPR5: DATA Mask                 */

#define RTC_SPR6_DATA_Pos                (0)                                               /*!< RTC_T::SPR6: DATA Position             */
#define RTC_SPR6_DATA_Msk                (0xfffffffful << RTC_SPR6_DATA_Pos)               /*!< RTC_T::SPR6: DATA Mask                 */

#define RTC_SPR7_DATA_Pos                (0)                                               /*!< RTC_T::SPR7: DATA Position             */
#define RTC_SPR7_DATA_Msk                (0xfffffffful << RTC_SPR7_DATA_Pos)               /*!< RTC_T::SPR7: DATA Mask                 */

#define RTC_SPR8_DATA_Pos                (0)                                               /*!< RTC_T::SPR8: DATA Position             */
#define RTC_SPR8_DATA_Msk                (0xfffffffful << RTC_SPR8_DATA_Pos)               /*!< RTC_T::SPR8: DATA Mask                 */

#define RTC_SPR9_DATA_Pos                (0)                                               /*!< RTC_T::SPR9: DATA Position             */
#define RTC_SPR9_DATA_Msk                (0xfffffffful << RTC_SPR9_DATA_Pos)               /*!< RTC_T::SPR9: DATA Mask                 */

#define RTC_SPR10_DATA_Pos               (0)                                               /*!< RTC_T::SPR10: DATA Position            */
#define RTC_SPR10_DATA_Msk               (0xfffffffful << RTC_SPR10_DATA_Pos)              /*!< RTC_T::SPR10: DATA Mask                */

#define RTC_SPR11_DATA_Pos               (0)                                               /*!< RTC_T::SPR11: DATA Position            */
#define RTC_SPR11_DATA_Msk               (0xfffffffful << RTC_SPR11_DATA_Pos)              /*!< RTC_T::SPR11: DATA Mask                */

#define RTC_SPR12_DATA_Pos               (0)                                               /*!< RTC_T::SPR12: DATA Position            */
#define RTC_SPR12_DATA_Msk               (0xfffffffful << RTC_SPR12_DATA_Pos)              /*!< RTC_T::SPR12: DATA Mask                */

#define RTC_SPR13_DATA_Pos               (0)                                               /*!< RTC_T::SPR13: DATA Position            */
#define RTC_SPR13_DATA_Msk               (0xfffffffful << RTC_SPR13_DATA_Pos)              /*!< RTC_T::SPR13: DATA Mask                */

#define RTC_SPR14_DATA_Pos               (0)                                               /*!< RTC_T::SPR14: DATA Position            */
#define RTC_SPR14_DATA_Msk               (0xfffffffful << RTC_SPR14_DATA_Pos)              /*!< RTC_T::SPR14: DATA Mask                */

#define RTC_SPR15_DATA_Pos               (0)                                               /*!< RTC_T::SPR15: DATA Position            */
#define RTC_SPR15_DATA_Msk               (0xfffffffful << RTC_SPR15_DATA_Pos)              /*!< RTC_T::SPR15: DATA Mask                */

/**@}*/ /* RTC_CONST */
/**@}*/ /* end of RTC register group */

/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __RTC_REG_H__ */
