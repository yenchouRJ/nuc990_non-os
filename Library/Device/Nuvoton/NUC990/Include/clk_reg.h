/**************************************************************************//**
 * @file     clk_reg.h
 * @version  V1.00
 * @brief    CLK register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __CLK_REG_H__
#define __CLK_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/** @addtogroup REGISTER Control Register

  @{

*/


/*---------------------- System Clock Controller -------------------------*/
/**
    @addtogroup CLK System Clock Controller(CLK)
    Memory Mapped Structure for CLK Controller
@{ */

typedef struct
{


/**
 * @var CLK_T::PMCON
 * Offset: 0x00  Power Management Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |HXT_EN    |HXT Crystal Power-down Control
 * |        |          |0 = HXT Crystal off (Power-down mode).
 * |        |          |1 = HXT Crystal on (Normal operating mode).
 * |[1]     |HXT_CTL   |Pre-scalar Counter Enable Bit
 * |        |          |Crystal pre-divide control for Wake-up from Power-down mode The chip will delay 256 x pre-scalar cycles after the reset signal to wait the Crystal to stable
 * |        |          |0 = The pre-scalar counter Disabled (assume the crystal is stable).
 * |        |          |1 = The pre-scalar counter Enabled.
 * |[23:8]  |PRESCALE  |Pre-scalar Counter
 * |        |          |Assume the crystal is stable after the Pre-Scalar x 256 crystal cycles
 * |        |          |Clock controller wouldnu2019t output clock to system before the counter reaching (pre-scalar x 256).
 * @var CLK_T::HCLKEN0
 * Offset: 0x10  AHB Devices Clock Enable Control Register 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |CPUCKEN   |Arm926EJ-S CPU Clock Enable Bit
 * |        |          |0 = Arm926EJ-S CPU clock Disabled.
 * |        |          |1 = Arm926EJ-S CPU clock Enabled.
 * |[1]     |HCLKCKEN  |Internal AHB Bus Clock Enable Bit
 * |        |          |0 = Internal AHB bus clock Disabled.
 * |        |          |1 = Internal AHB bus clock Enabled.
 * |[2]     |HCLK1CKEN |Internal AHB-1 Bus Clock Enable Bit
 * |        |          |0 = Internal AHB-1 bus clock Disabled.
 * |        |          |1 = Internal AHB-1 bus clock Enabled.
 * |[6]     |CLKOCKEN  |Reference Clock Output Enable Bit
 * |        |          |0 = Reference clock output Disabled.
 * |        |          |1 = Reference clock output Enabled.
 * |[8]     |SRAMCKEN  |SRAM Controller Clock Enable Bit
 * |        |          |0 = SRAM controller clock Disabled.
 * |        |          |1 = SRAM controller clock Enabled.
 * |[9]     |EBICKEN   |EBI Controller Clock Enable Bit
 * |        |          |0 = EBI controller clock Disabled.
 * |        |          |1 = EBI controller clock Enabled.
 * |[10]    |SDICCKEN  |SDIC Clock Enable Bit
 * |        |          |0 = DDR clock Disabled.
 * |        |          |1 = DDR clock Enabled.
 * |[11]    |GPIOCKEN  |GPIO Clock Enable Bit
 * |        |          |0 = GPIO clock Disabled.
 * |        |          |1 = GPIO clock Enabled.
 * |[12]    |PCLK0CKEN |Internal APB-0 Bus Clock Enable Bit
 * |        |          |0 = Internal APB-1 bus clock Disabled.
 * |        |          |1 = Internal APB-1 bus clock Enabled.
 * |[13]    |PCLK1CKEN |Internal APB-1 Bus Clock Enable Bit
 * |        |          |0 = Internal APB-1 bus clock Disabled.
 * |        |          |1 = Internal APB-1 bus clock Enabled.
 * |[14]    |PCLK2CKEN |Internal APB-2 Bus Clock Enable Bit
 * |        |          |0 = Internal APB-2 bus clock Disabled.
 * |        |          |1 = Internal APB-2 bus clock Enabled.
 * |[15]    |PCLK3CKEN |Internal APB-3 Bus Clock Enable Bit
 * |        |          |0 = Internal APB-3 bus clock Disabled.
 * |        |          |1 = Internal APB-3 bus clock Enabled.
 * |[16]    |PDMA0EN   |PDMA 0 Clock Enable Bit
 * |        |          |0 = PDMA 0 clock Disabled.
 * |        |          |1 = PDMA 0 clock Enabled.
 * |[17]    |PDMA1EN   |PDMA 1 Clock Enable Bit
 * |        |          |0 = PDMA 1 clock Disabled.
 * |        |          |1 = PDMA 1 clock Enabled.
 * |[18]    |EMAC0EN   |Ethernet MAC Controller 0 Clock Enable Bit
 * |        |          |0 = Ethernet MAC controller 0 clock Disabled.
 * |        |          |1 = Ethernet MAC controller 0 clock Enabled.
 * |[19]    |EMAC1EN   |Ethernet MAC Controller 1 Clock Enable Bit
 * |        |          |0 = Ethernet MAC controller 1 clock Disabled.
 * |        |          |1 = Ethernet MAC controller 1 clock Enabled.
 * |[21]    |NANDEN    |NAND Engine Clock Enable Bit
 * |        |          |0 = NAND controller clock Disabled.
 * |        |          |1 = NAND controller clock Enabled.
 * |[22]    |SDH0EN    |SD Card Controller 0 Clock Enable Bit
 * |        |          |0 = SD card controller 0 clock Disabled.
 * |        |          |1 = SD card controller 0 clock Enabled.
 * |[23]    |SDH1EN    |SD Card Controller 1 Clock Enable Bit
 * |        |          |0 = SD card controller 1 clock Disabled.
 * |        |          |1 = SD card controller 1 clock Enabled.
 * |[24]    |USBHEN    |USB Host Controller Clock Enable Bit
 * |        |          |0 = USB host controller clock Disabled.
 * |        |          |1 = USB host controller clock Enabled.
 * |[25]    |USBDEN    |USB Device Controller Clock Enable Bit
 * |        |          |0 = USB device controller clock Disabled.
 * |        |          |1 = USB device controller clock Enabled.
 * @var CLK_T::HCLKEN1
 * Offset: 0x14  AHB Devices Clock Enable Control Register 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |I2SCKEN   |I2S Controller Clock Enable Bit
 * |        |          |0 = I2S controller clock Disabled.
 * |        |          |1 = I2S controller clock Enabled.
 * |[1]     |CRPTCKEN  |Cryptographic Accelerator Clock Enable Bit
 * |        |          |0 = Cryptographic Accelerator clock Disabled.
 * |        |          |1 = Cryptographic Accelerator clock Enabled.
 * |[2]     |KSCKEN    |Key Store Clock Enable Bit
 * |        |          |0 = Key store clock Disabled.
 * |        |          |1 = Key store clock Enabled.
 * |[3]     |OTPIDLE   |OTP Clock Enable Bit
 * |        |          |0 = OTP clock Disabled when chip is under IDLE mode.
 * |        |          |1 = OTP clock Enabled when chip is under IDLE mode.
 * |[8]     |CANF0CKEN |CANFD0 Clock Enable Bit
 * |        |          |0 = CANFD0 clock Disabled.
 * |        |          |1 = CANFD0 clock Enabled.
 * |[9]     |CANF1CKEN |CANFD1 Clock Enable Bit
 * |        |          |0 = CANFD1 clock Disabled.
 * |        |          |1 = CANFD1 clock Enabled.
 * |[10]    |CANF2CKEN |CANFD2 Clock Enable Bit
 * |        |          |0 = CANFD2 clock Disabled.
 * |        |          |1 = CANFD2 clock Enabled.
 * |[11]    |CANF3CKEN |CANFD3 Clock Enable Bit
 * |        |          |0 = CANFD3 clock Disabled.
 * |        |          |1 = CANFD3 clock Enabled.
 * |[16]    |CANRAM0EN |CANFD0 Message SRAM Clock Enable Bit
 * |        |          |0 = CANFD0 Message SRAM clock Disabled.
 * |        |          |1 = CANFD0 Message SRAM clock Enabled.
 * |[17]    |CANRAM1EN |CANFD1 Message SRAM Clock Enable Bit
 * |        |          |0 = CANFD1 Message SRAM clock Disabled.
 * |        |          |1 = CANFD1 Message SRAM clock Enabled.
 * |[18]    |CANRAM2EN |CANFD2 Message SRAM Clock Enable Bit
 * |        |          |0 = CANFD0 Message SRAM clock Disabled.
 * |        |          |1 = CANFD0 Message SRAM clock Enabled.
 * |[19]    |CANRAM3EN |CANFD3 Message SRAM Clock Enable Bit
 * |        |          |0 = CANFD3 Message SRAM clock Disabled.
 * |        |          |1 = CANFD3 Message SRAM clock Enabled.
 * @var CLK_T::PCLKEN0
 * Offset: 0x18  APB Devices Clock Enable Control Register 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |WDTCKEN   |Watch-dog Clock Enable Bit
 * |        |          |0 = Watch-dog clock Disabled.
 * |        |          |1 = Watch-dog clock Enabled.
 * |        |          |Note: If WDT default Enabled (WDTON(SYS_PWRON[3])=1), this bit is read-only and read back value is always 1.
 * |[1]     |WWDTCKEN  |Windowed Watch-dog Clock Enable Bit
 * |        |          |0 = Windowed Watch-dog clock Disabled.
 * |        |          |1 = Windowed Watch-dog clock Enabled.
 * |[2]     |RTCCKEN   |RTC Clock Enable Bit
 * |        |          |0 = RTC clock Disabled.
 * |        |          |1 =RTC clock Enabled.
 * |[3]     |AICCKEN   |Advanced Interrupt Controller Clock Enable Bit
 * |        |          |0 = AIC clock Disabled.
 * |        |          |1 = AIC clock Enabled.
 * |[8]     |TMR0CKEN  |Timer 0 Clock Enable Bit
 * |        |          |0 = Timer 0 clock Disabled.
 * |        |          |1 = Timer 0 clock Enabled.
 * |[9]     |TMR1CKEN  |Timer 1 Clock Enable Bit
 * |        |          |0 = Timer 1 clock Disabled.
 * |        |          |1 = Timer 1 clock Enabled.
 * |[10]    |TMR2CKEN  |Timer 2 Clock Enable Bit
 * |        |          |0 = Timer 2 clock Disabled.
 * |        |          |1 = Timer 2 clock Enabled.
 * |[11]    |TMR3CKEN  |Timer 3 Clock Enable Bit
 * |        |          |0 = Timer 3 clock Disabled.
 * |        |          |1 = Timer 3 clock Enabled.
 * |[12]    |TMR4CKEN  |Timer 4 Clock Enable Bit
 * |        |          |0 = Timer 4 clock Disabled.
 * |        |          |1 = Timer 4 clock Enabled.
 * |[13]    |TMR5CKEN  |Timer 5 Clock Enable Bit
 * |        |          |0 = Timer 5 clock Disabled.
 * |        |          |1 = Timer 5 clock Enabled.
 * |[16]    |UART0CKEN |UART 0 Clock Enable Bit
 * |        |          |0 = UART 0 clock Disabled.
 * |        |          |1 = UART 0 clock Enabled.
 * |[17]    |UART1CKEN |UART 1 Clock Enable Bit
 * |        |          |0 = UART 1 clock Disabled.
 * |        |          |1 = UART 1 clock Enabled.
 * |[18]    |UART2CKEN |UART 2 Clock Enable Bit
 * |        |          |0 = UART 2 clock Disabled.
 * |        |          |1 = UART 2 clock Enabled.
 * |[19]    |UART3CKEN |UART 3 Clock Enable Bit
 * |        |          |0 = UART 3 clock Disabled.
 * |        |          |1 = UART 3 clock Enabled.
 * |[20]    |UART4CKEN |UART 4 Clock Enable Bit
 * |        |          |0 = UART 4 clock Disabled.
 * |        |          |1 = UART 4 clock Enabled.
 * |[21]    |UART5CKEN |UART 5 Clock Enable Bit
 * |        |          |0 = UART 5 clock Disabled.
 * |        |          |1 = UART 5 clock Enabled.
 * |[22]    |UART6CKEN |UART 6 Clock Enable Bit
 * |        |          |0 = UART 6 clock Disabled.
 * |        |          |1 = UART 6 clock Enabled.
 * |[23]    |UART7CKEN |UART 7 Clock Enable Bit
 * |        |          |0 = UART 7 clock Disabled.
 * |        |          |1 = UART 7 clock Enabled.
 * |[24]    |UART8CKEN |UART 8 Clock Enable Bit
 * |        |          |0 = UART 8 clock Disabled.
 * |        |          |1 = UART 8 clock Enabled.
 * |[25]    |UART9CKEN |UART 9 Clock Enable Bit
 * |        |          |0 = UART 9 clock Disabled.
 * |        |          |1 = UART 9 clock Enabled.
 * @var CLK_T::PCLKEN1
 * Offset: 0x1C  APB Devices Clock Enable Control Register 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |I2C0CKEN  |I2C 0 Clock Enable Bit
 * |        |          |0 = I2C 0 clock Disabled.
 * |        |          |1 = I2C 0 clock Enabled.
 * |[1]     |I2C1CKEN  |I2C 1 Clock Enable Bit
 * |        |          |0 = I2C 1 clock Disabled.
 * |        |          |1 = I2C 1 clock Enabled.
 * |[2]     |I2C2CKEN  |I2C 2 Clock Enable Bit
 * |        |          |0 = I2C 2 clock Disabled.
 * |        |          |1 = I2C 2 clock Enabled.
 * |[3]     |I2C3CKEN  |I2C 3 Clock Enable Bit
 * |        |          |0 = I2C 3 clock Disabled.
 * |        |          |1 = I2C 3 clock Enabled.
 * |[4]     |SPI0CKEN  |SPI 0 Clock Enable Bit
 * |        |          |0 = SPI 0 clock Disabled.
 * |        |          |1 = SPI 0 clock Enabled.
 * |[5]     |SPI1CKEN  |SPI 1 Clock Enable Bit
 * |        |          |0 = SPI 1 clock Disabled.
 * |        |          |1 = SPI 1 clock Enabled.
 * |[6]     |SPI2CKEN  |SPI 2 Clock Enable Bit
 * |        |          |0 = SPI 2 clock Disabled.
 * |        |          |1 = SPI 2 clock Enabled.
 * |[7]     |SPI3CKEN  |SPI 3 Clock Enable Bit
 * |        |          |0 = SPI 3 clock Disabled.
 * |        |          |1 = SPI 3 clock Enabled.
 * |[8]     |CAN0CKEN  |CAN 0 Clock Enable Bit
 * |        |          |0 = CAN 0 clock Disabled.
 * |        |          |1 = CAN 0 clock Enabled.
 * |[9]     |CAN1CKEN  |CAN 1 Clock Enable Bit
 * |        |          |0 = CAN 1 clock Disabled.
 * |        |          |1 = CAN 1 clock Enabled.
 * |[10]    |CAN2CKEN  |CAN 2 Clock Enable Bit
 * |        |          |0 = CAN 2 clock Disabled.
 * |        |          |1 = CAN 2 clock Enabled.
 * |[11]    |CAN3CKEN  |CAN 3 Clock Enable Bit
 * |        |          |0 = CAN 3 clock Disabled.
 * |        |          |1 = CAN 3 clock Enabled.
 * |[16]    |SMC0CKEN  |Smart Card Interface 0 Clock Enable Bit
 * |        |          |0 = Smart Card interface 0 clock Disabled.
 * |        |          |1 = Smart Card interface 0 clock Enabled.
 * |[17]    |SMC1CKEN  |Smart Card Interface 1 Clock Enable Bit
 * |        |          |0 = Smart Card interface 1 clock Disabled.
 * |        |          |1 = Smart Card interface 1 clock Enabled.
 * |[20]    |QSPI0CKEN |QSPI 0 Clock Enable Bit
 * |        |          |0 = QSPI 0 clock Disabled.
 * |        |          |1 = QSPI 0 clock Enabled.
 * |[24]    |ADCCKEN   |ADC Controller Clock Enable Bit
 * |        |          |0 = ADC controller clock Disabled.
 * |        |          |1 = ADC controller clock Enabled.
 * |[25]    |EADCCKEN  |EADC Controller Clock Enable Bit
 * |        |          |0 = EADC controller clock Disabled.
 * |        |          |1 = EADC controller clock Enabled.
 * |[26]    |BPWM0CKEN |BPWM 0 Clock Enable Bit
 * |        |          |0 = BPWM 0 clock Disabled.
 * |        |          |1 = BPWM 0 clock Enabled.
 * |[27]    |BPWM1CKEN |BPWM 1 Clock Enable Bit
 * |        |          |0 = BPWM 1 clock Disabled.
 * |        |          |1 = BPWM 1 clock Enabled.
 * @var CLK_T::DIVCTL0
 * Offset: 0x20  Clock Divider Control Register 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[4:3]   |SYSTEM_S  |System Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of system clock SYS_CLK.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Reserved.
 * |        |          |10 = Clock source from APLL.
 * |        |          |11 = Clock source from UPLL.
 * |[8]     |CPUDIV2EN |CPU Clock Divided by 2 Enable Bit
 * |        |          |This field defines if CPUCLK for Arm926EJ-S CPU is SYS_CLK devided by 2 or not.
 * |        |          |0 = The frequency of CPUCLK is SYS_CLK.
 * |        |          |1 = The frequency of CPUCLK is SYS_CLK /2.
 * |[18:16] |PCLK3DIV  |PCLK3 Clock Divider
 * |        |          |APB3 clock can be divided from the PCLK3 clock source.
 * |        |          |000 = PCLK3 frequency is PCLK3 clock source frequency.
 * |        |          |001 = PCLK3 frequency is (PCLK3 clock source frequency) /2.
 * |        |          |010 = PCLK3 frequency is (PCLK3 clock source frequency) /4.
 * |        |          |011 = PCLK3 frequency is (PCLK3 clock source frequency) /8.
 * |        |          |100 = PCLK3 frequency is (PCLK3 clock source frequency) /16.
 * |        |          |101 = PCLK3 frequency is (PCLK3 clock source frequency) /32.
 * |        |          |110 = PCLK3 frequency is (PCLK3 clock source frequency) /64.
 * |        |          |Others = Reserved.
 * |[20:19] |PCLK3_S   |PCLK3 Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of PCLK3.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from HCLK.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * @var CLK_T::DIVCTL1
 * Offset: 0x24  Clock Divider Control Register 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[20:19] |I2S_S     |I2S Controller Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for I2S controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Reserved.
 * |        |          |10 = Clock source from APLL.
 * |        |          |11 = Clock source from UPLL/2.
 * |[31:24] |I2S_N     |I2S Controller Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for I2S controller.
 * |        |          |I2S clock frequency = (I2S clock source frequency) / (I2S_N + 1).
 * @var CLK_T::DIVCTL2
 * Offset: 0x28  Clock Divider Control Register 2
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |CANFD0_S  |CANFD 0 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for CANFD0.
 * |        |          |0 = Clock source from APLL/2.
 * |        |          |1 = Clock source from UPLL/2.
 * |[1]     |CANFD1_S  |CANFD 1 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for CANFD1.
 * |        |          |0 = Clock source from APLL/2.
 * |        |          |1 = Clock source from UPLL/2.
 * |[2]     |CANFD2_S  |CANFD 2 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for CANFD2.
 * |        |          |0 = Clock source from APLL/2.
 * |        |          |1 = Clock source from UPLL/2.
 * |[3]     |CANFD3_S  |CANFD 3 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for CANFD3.
 * |        |          |0 = Clock source from APLL/2.
 * |        |          |1 = Clock source from UPLL/2.
 * |[9:8]   |QSPI0_S   |QSPI 0 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for QSPI0.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from PCLK0.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[11:10] |SPI0_S    |SPI 0 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for SPI0.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from PCLK0.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[13:12] |SPI1_S    |SPI 1 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for SPI1.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from PCLK1.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[15:14] |SPI2_S    |SPI 2 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for SPI2.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from PCLK0.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[17:16] |SPI3_S    |SPI 3 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for SPI3.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from PCLK1.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * @var CLK_T::DIVCTL3
 * Offset: 0x2C  Clock Divider Control Register 3
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[4:3]   |SD0_S     |SD Card Controller 0 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for SD card controller 0.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Reserved.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[15:5]  |SD0_N     |SD Card Controller 0 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for SD card controller 0.
 * |        |          |SD0 clock frequency = (SD0 clock source frequency) / (SD0_N + 1).
 * |[20:19] |SD1_S     |SD Card Controller 1 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for SD card controller 1.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Reserved.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[31:21] |SD1_N     |SD Card Controller 1 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for SD card controller 1.
 * |        |          |SD1 clock frequency = (SD1 clock source frequency) / (SD1_N + 1).
 * @var CLK_T::DIVCTL4
 * Offset: 0x30  Clock Divider Control Register 4
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[4:3]   |UART0_S   |UART0 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for UART0 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from LXT.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[7:5]   |UART0_N   |UART0 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for UART0.
 * |        |          |UART0 clock frequency = (UART0 clock source frequency) / (UART0_N + 1).
 * |[12:11] |UART1_S   |UART1 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for UART1 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from LXT.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[15:13] |UART1_N   |UART1 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for UART1.
 * |        |          |UART1 clock frequency = (UART1 clock source frequency) / (UART1_N + 1).
 * |[20:19] |UART2_S   |UART2 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for UART2 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from LXT.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[23:21] |UART2_N   |UART2 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for UART2.
 * |        |          |UART2 clock frequency = (UART2 clock source frequency) / (UART2_N + 1).
 * |[28:27] |UART3_S   |UART3 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for UART3 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from LXT.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[31:29] |UART3_N   |UART3 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for UART3.
 * |        |          |UART3 clock frequency = (UART3 clock source frequency) / (UART3_N + 1).
 * @var CLK_T::DIVCTL5
 * Offset: 0x34  Clock Divider Control Register 5
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[4:3]   |UART4_S   |UART4 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for UART4 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from LXT.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[7:5]   |UART4_N   |UART4 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for UART4.
 * |        |          |UART4 clock frequency = (UART4 clock source frequency) / (UART4_N + 1).
 * |[12:11] |UART5_S   |UART5 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for UART5 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from LXT.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[15:13] |UART5_N   |UART5 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for UART5.
 * |        |          |UART5 clock frequency = (UART5 clock source frequency) / (UART5_N + 1).
 * |[20:19] |UART6_S   |UART6 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for UART6 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from LXT.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[23:21] |UART6_N   |UART6 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for UART6.
 * |        |          |UART6 clock frequency = (UART6 clock source frequency) / (UART6_N + 1).
 * |[28:27] |UART7_S   |UART7 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for UART7 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from LXT.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[31:29] |UART7_N   |UART7 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for UART7.
 * |        |          |UART7 clock frequency = (UART7 clock source frequency) / (UART7_N + 1).
 * @var CLK_T::DIVCTL6
 * Offset: 0x38  Clock Divider Control Register 6
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[4:3]   |UART8_S   |UART8 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for UART8 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from LXT.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[7:5]   |UART8_N   |UART8 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for UART8.
 * |        |          |UART8 clock frequency = (UART8 clock source frequency) / (UART8_N + 1).
 * |[12:11] |UART9_S   |UART9 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for UART9 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from LXT.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[15:13] |UART9_N   |UART9 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for UART9.
 * |        |          |UART9 clock frequency = (UART9 clock source frequency) / (UART9_N + 1).
 * |[23:16] |EADC_N    |EADC Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for EADC.
 * |        |          |EADC clock frequency = (EADC clock source frequency) / (EADC_N + 1).
 * |[27:24] |SMC0_N    |Smart Card 0 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for Smart card controller.
 * |        |          |SMC0 clock frequency = (SMC0 clock source frequency) / (SMC0_N + 1).
 * |[31:28] |SMC1_N    |Smart Card 1 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for Smart card controller.
 * |        |          |SMC1 clock frequency = (SMC1 clock source frequency) / (SMC1_N + 1).
 * @var CLK_T::DIVCTL7
 * Offset: 0x3C  Clock Divider Control Register 7
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |CANFD0_N  |CANFD0 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for CANFD0.
 * |        |          |CANFD0 clock frequency = (CANFD0 clock source frequency) / (CANFD0_N + 1).
 * |[7:4]   |CANFD1_N  |CANFD1 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for CANFD1.
 * |        |          |CANFD1 clock frequency = (CANFD1 clock source frequency) / (CANFD1_N + 1).
 * |[11:8]  |CANFD2_N  |CANFD2 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for CANFD2.
 * |        |          |CANFD2 clock frequency = (CANFD2 clock source frequency) / (CANFD2_N + 1).
 * |[15:12] |CANFD3_N  |CANFD3 Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for CANFD3.
 * |        |          |CANFD3 clock frequency = (CANFD3 clock source frequency) / (CANFD3_N + 1).
 * |[21:20] |ADC_S     |ADC Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for ADC controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Reserved.
 * |        |          |10 = Clock source from APLL/2.
 * |        |          |11 = Clock source from UPLL/2.
 * |[31:24] |ADC_N     |ADC Engine Clock Divider
 * |        |          |This field defines the clock divide number for clock divider to generate the engine clock for ADC.
 * |        |          |ADC clock frequency = (ADC clock source frequency) / (ADC_N + 1).
 * @var CLK_T::DIVCTL8
 * Offset: 0x40  Clock Divider Control Register 8
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[7:0]   |MDCLKDIV  |MII Management Interface Clock
 * |        |          |This field defines the clock divide number for clock divider to generate the clock for MII management interface.
 * |        |          |MDCLK clock frequency = HCLK / (MDCLK_N + 1).
 * |[9:8]   |WDTSEL    |WDT Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for WDT controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from HXT/512.
 * |        |          |10 = Clock source from PCLK2/4096.
 * |        |          |11 = Clock source from 32.768 kHz.
 * |[11:10] |WWDTSEL   |WWDT Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for WWDT controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from HXT/512.
 * |        |          |10 = Clock source from PCLK2/4096.
 * |        |          |11 = Clock source from 32.768 kHz.
 * |[17:16] |TMR0SEL   |Timer 0 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for Timer 0 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from PCLK0/2.
 * |        |          |10 = Clock source from PCLK0/4096.
 * |        |          |11 = Clock source from 32.768 kHz.
 * |[19:18] |TMR1SEL   |Timer 1 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for Timer 1 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from PCLK0/2.
 * |        |          |10 = Clock source from PCLK0/4096.
 * |        |          |11 = Clock source from 32.768 kHz.
 * |[21:20] |TMR2SEL   |Timer 2 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for Timer 2 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from PCLK1/2.
 * |        |          |10 = Clock source from PCLK1/4096.
 * |        |          |11 = Clock source from 32.768 kHz.
 * |[23:22] |TMR3SEL   |Timer 3 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for Timer 3 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from PCLK1/2.
 * |        |          |10 = Clock source from PCLK1/4096.
 * |        |          |11 = Clock source from 32.768 kHz.
 * |[25:24] |TMR4SEL   |Timer 4 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for Timer 4 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from PCLK0/2.
 * |        |          |10 = Clock source from PCLK0/4096.
 * |        |          |11 = Clock source from 32.768 kHz.
 * |[27:26] |TMR5SEL   |Timer 5 Engine Clock Source Selection
 * |        |          |This field selects which clock is used to be the source of engine clock for Timer 5 controller.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from PCLK0/2.
 * |        |          |10 = Clock source from PCLK0/4096.
 * |        |          |11 = Clock source from 32.768 kHz.
 * @var CLK_T::DIVCTL9
 * Offset: 0x44  Clock Divider Control Register 9
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[20:19] |CKO_S     |Reference Clock Out Source Selection
 * |        |          |This field selects which clock is used to be the source of reference clock output.
 * |        |          |00 = Clock source from HXT.
 * |        |          |01 = Clock source from LXT.
 * |        |          |10 = Clock source from APLL.
 * |        |          |11 = Clock source from UPLL.
 * |[31:24] |CKO_N     |Reference Clock Out Divide
 * |        |          |This field defines the clock divide number for clock divider to generate the reference clock output
 * |        |          |CKO clock frequency = (CKO clock source frequency) / (CKO_N + 1).
 * @var CLK_T::APLLCON
 * Offset: 0x60  APLL Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[6:0]   |FB_DV     |PLL VCO Output Clock Feedback Divider Integer Part
 * |        |          |Set the feedback divider factor (N) from 1 to 128.
 * |        |          |The N = FB_DV[6:0] + 1.
 * |[12:7]  |IN_DV     |Reference Input Divider
 * |        |          |Set the reference divider factor (M) from 1 to 64.
 * |        |          |The M = IN_DV[5:0] + 1.
 * |[15:13] |OUT_DV    |PLL Output Divider
 * |        |          |Set the output divider factor (P) from 1 to 8.
 * |        |          |The P = OUT_DV[2:0] + 1.
 * |[27:16] |FRAC      |PLL VCO Output Clock Feedback Divider Fraction Part
 * |        |          |Set the fraction part (X) of feedback divider factor.
 * |        |          |Write a non-zero value to this field enables the fraction mode automatically
 * |        |          |Please keep this field in 0x0 if donu2019t want to use the PLL fraction mode.
 * |        |          |The X = FRAC[11:0] / 212.
 * |[28]    |PD        |Power-down mode Enable Bit
 * |        |          |0 = PLL is in normal operation mode.
 * |        |          |1 = PLL is in Power-down mode (Default).
 * |[29]    |BYPASS    |Bypass Mode Enable Bit
 * |        |          |0 = PLL is in normal operation mode (Default).
 * |        |          |1 = PLL is in bypass mode.
 * |[30]    |RESETN    |Reset Mode Enable Bit
 * |        |          |0 = PLL is in reset mode.
 * |        |          |1 = PLL is in normal operation mode (Default).
 * |[31]    |PLL_STB   |PLL Stable Flag
 * |        |          |0 = PLL is not stable.
 * |        |          |1 = PLL is stable (500us after PLL setting changed).
 * @var CLK_T::UPLLCON
 * Offset: 0x64  UPLL Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[6:0]   |FB_DV     |PLL VCO Output Clock Feedback Divider Integer Part
 * |        |          |Set the feedback divider factor (N) from 1 to 128.
 * |        |          |The N = FB_DV[6:0] + 1.
 * |[12:7]  |IN_DV     |Reference Input Divider
 * |        |          |Set the reference divider factor (M) from 1 to 64.
 * |        |          |The M = IN_DV[5:0] + 1.
 * |[15:13] |OUT_DV    |PLL Output Divider
 * |        |          |Set the output divider factor (P) from 1 to 8.
 * |        |          |The P = OUT_DV[2:0] + 1.
 * |[27:16] |FRAC      |PLL VCO Output Clock Feedback Divider Fraction Part
 * |        |          |Set the fraction part (X) of feedback divider factor.
 * |        |          |Write a non-zero value to this field enables the fraction mode automatically
 * |        |          |Please keep this field in 0x0 if donu2019t want to use the PLL fraction mode.
 * |        |          |The X = FRAC[11:0] / 212.
 * |[28]    |PD        |Power-down mode Enable Bit
 * |        |          |0 = PLL is in normal operation mode.
 * |        |          |1 = PLL is in Power-down mode (Default).
 * |[29]    |BYPASS    |Bypass Mode Enable Bit
 * |        |          |0 = PLL is in normal operation mode (Default).
 * |        |          |1 = PLL is in bypass mode.
 * |[30]    |RESETN    |Reset Mode Enable Bit
 * |        |          |0 = PLL is in reset mode.
 * |        |          |1 = PLL is in normal operation mode (Default).
 * |[31]    |PLL_STB   |PLL Stable Flag
 * |        |          |0 = PLL is not stable.
 * |        |          |1 = PLL is stable (500us after PLL setting changed).
 * @var CLK_T::PLLSTBCNTR
 * Offset: 0x80  PLL Stable Counter and Test Clock Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[15:0]  |PLLSTBCNT |PLL Stable Counter
 * |        |          |The PLL stable time is set by PLLSTBCNT[15:0]
 * |        |          |The stable time is determined by the number of PLLSTBCNT[15:0] cycles of the PLL source clock.
 * @var CLK_T::STOPREQ
 * Offset: 0x90  Clock Stop Request Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |CANFD0STR |CANFD0 Clock Stop Request
 * |        |          |This bit is used to stop CANFD0 clock.
 * |        |          |0 = CANFD0 clock is not stopped by this bit. (default)
 * |        |          |1 = Set this bit and check the CANFD0STA(CLK_STOPACK[0]) is 1, then CANFD0 clock stop.
 * |[1]     |CANFD1STR |CANFD1 Clock Stop Request
 * |        |          |This bit is used to stop CANFD1 clock.
 * |        |          |0 = CANFD1 clock is not stopped by this bit. (default)
 * |        |          |1 = Set this bit and check the CANFD1STA(CLK_STOPACK[1]) is 1, then CANFD1 clock stop.
 * |[2]     |CANFD2STR |CANFD2 Clock Stop Request
 * |        |          |This bit is used to stop CANFD2 clock.
 * |        |          |0 = CANFD2 clock is not stopped by this bit. (default)
 * |        |          |1 = Set this bit and check the CANFD2STA(CLK_STOPACK[2]) is 1, then CANFD2 clock stop.
 * |[3]     |CANFD3STR |CANFD3 Clock Stop Request
 * |        |          |This bit is used to stop CANFD3 clock.
 * |        |          |0 = CANFD3 clock is not stopped by this bit. (default)
 * |        |          |1 = Set this bit and check the CANFD3STA(CLK_STOPACK[3]) is 1, then CANFD3 clock stop.
 * @var CLK_T::STOPACK
 * Offset: 0x94  Clock Stop Acknowledge Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |CANFD0STA |CANFD0 Clock Stop Acknowledge (Read Only)
 * |        |          |This bit is used to check CANFD0 clock stop by setting CANFD0STR(CLK_STOPREQ[0]).
 * |        |          |0 = CANFD0 clock not stopped.
 * |        |          |1 = CANFD0 clock stopped.
 * |[1]     |CANFD1STA |CANFD1 Clock Stop Acknowledge (Read Only)
 * |        |          |This bit is used to check CANFD1 clock stop by setting CANFD1STR(CLK_STOPREQ[1]).
 * |        |          |0 = CANFD1 clock not stopped.
 * |        |          |1 = CANFD1 clock stopped.
 * |[2]     |CANFD2STA |CANFD2 Clock Stop Acknowledge (Read Only)
 * |        |          |This bit is used to check CANFD2 clock stop by setting CANFD2STR(CLK_STOPREQ[2]).
 * |        |          |0 = CANFD2 clock not stopped.
 * |        |          |1 = CANFD2 clock stopped.
 * |[3]     |CANFD3STA |CANFD3 Clock Stop Acknowledge (Read Only)
 * |        |          |This bit is used to check CANFD3 clock stop by setting CANFD3STR(CLK_STOPREQ[3]).
 * |        |          |0 = CANFD3 clock not stopped.
 * |        |          |1 = CANFD3 clock stopped.
 */
    __IO uint32_t PMCON;                 /*!< [0x0000] Power Management Control Register                                */
    __I  uint32_t RESERVE0[3];
    __IO uint32_t HCLKEN0;               /*!< [0x0010] AHB Devices Clock Enable Control Register 0                      */
    __IO uint32_t HCLKEN1;               /*!< [0x0014] AHB Devices Clock Enable Control Register 1                      */
    __IO uint32_t PCLKEN0;               /*!< [0x0018] APB Devices Clock Enable Control Register 0                      */
    __IO uint32_t PCLKEN1;               /*!< [0x001c] APB Devices Clock Enable Control Register 1                      */
    __IO uint32_t DIVCTL0;               /*!< [0x0020] Clock Divider Control Register 0                                 */
    __IO uint32_t DIVCTL1;               /*!< [0x0024] Clock Divider Control Register 1                                 */
    __IO uint32_t DIVCTL2;               /*!< [0x0028] Clock Divider Control Register 2                                 */
    __IO uint32_t DIVCTL3;               /*!< [0x002c] Clock Divider Control Register 3                                 */
    __IO uint32_t DIVCTL4;               /*!< [0x0030] Clock Divider Control Register 4                                 */
    __IO uint32_t DIVCTL5;               /*!< [0x0034] Clock Divider Control Register 5                                 */
    __IO uint32_t DIVCTL6;               /*!< [0x0038] Clock Divider Control Register 6                                 */
    __IO uint32_t DIVCTL7;               /*!< [0x003c] Clock Divider Control Register 7                                 */
    __IO uint32_t DIVCTL8;               /*!< [0x0040] Clock Divider Control Register 8                                 */
    __IO uint32_t DIVCTL9;               /*!< [0x0044] Clock Divider Control Register 9                                 */
    __I  uint32_t RESERVE1[6];
    __IO uint32_t APLLCON;               /*!< [0x0060] APLL Control Register                                            */
    __IO uint32_t UPLLCON;               /*!< [0x0064] UPLL Control Register                                            */
    __I  uint32_t RESERVE2[6];
    __IO uint32_t PLLSTBCNTR;            /*!< [0x0080] PLL Stable Counter and Test Clock Control Register               */
    __I  uint32_t RESERVE3[3];
    __IO uint32_t STOPREQ;               /*!< [0x0090] Clock Stop Request Register                                      */
    __I  uint32_t STOPACK;               /*!< [0x0094] Clock Stop Acknowledge Register                                  */

} CLK_T;

/**
    @addtogroup CLK_CONST CLK Bit Field Definition
    Constant Definitions for CLK Controller
@{ */

#define CLK_PMCON_HXT_EN_Pos             (0)                                               /*!< CLK_T::PMCON: HXT_EN Position          */
#define CLK_PMCON_HXT_EN_Msk             (0x1ul << CLK_PMCON_HXT_EN_Pos)                   /*!< CLK_T::PMCON: HXT_EN Mask              */

#define CLK_PMCON_HXT_CTL_Pos            (1)                                               /*!< CLK_T::PMCON: HXT_CTL Position         */
#define CLK_PMCON_HXT_CTL_Msk            (0x1ul << CLK_PMCON_HXT_CTL_Pos)                  /*!< CLK_T::PMCON: HXT_CTL Mask             */

#define CLK_PMCON_PRESCALE_Pos           (8)                                               /*!< CLK_T::PMCON: PRESCALE Position        */
#define CLK_PMCON_PRESCALE_Msk           (0xfffful << CLK_PMCON_PRESCALE_Pos)              /*!< CLK_T::PMCON: PRESCALE Mask            */

#define CLK_HCLKEN0_CPUCKEN_Pos          (0)                                               /*!< CLK_T::HCLKEN0: CPUCKEN Position       */
#define CLK_HCLKEN0_CPUCKEN_Msk          (0x1ul << CLK_HCLKEN0_CPUCKEN_Pos)                /*!< CLK_T::HCLKEN0: CPUCKEN Mask           */

#define CLK_HCLKEN0_HCLKCKEN_Pos         (1)                                               /*!< CLK_T::HCLKEN0: HCLKCKEN Position      */
#define CLK_HCLKEN0_HCLKCKEN_Msk         (0x1ul << CLK_HCLKEN0_HCLKCKEN_Pos)               /*!< CLK_T::HCLKEN0: HCLKCKEN Mask          */

#define CLK_HCLKEN0_HCLK1CKEN_Pos        (2)                                               /*!< CLK_T::HCLKEN0: HCLK1CKEN Position     */
#define CLK_HCLKEN0_HCLK1CKEN_Msk        (0x1ul << CLK_HCLKEN0_HCLK1CKEN_Pos)              /*!< CLK_T::HCLKEN0: HCLK1CKEN Mask         */

#define CLK_HCLKEN0_CLKOCKEN_Pos         (6)                                               /*!< CLK_T::HCLKEN0: CLKOCKEN Position      */
#define CLK_HCLKEN0_CLKOCKEN_Msk         (0x1ul << CLK_HCLKEN0_CLKOCKEN_Pos)               /*!< CLK_T::HCLKEN0: CLKOCKEN Mask          */

#define CLK_HCLKEN0_SRAMCKEN_Pos         (8)                                               /*!< CLK_T::HCLKEN0: SRAMCKEN Position      */
#define CLK_HCLKEN0_SRAMCKEN_Msk         (0x1ul << CLK_HCLKEN0_SRAMCKEN_Pos)               /*!< CLK_T::HCLKEN0: SRAMCKEN Mask          */

#define CLK_HCLKEN0_EBICKEN_Pos          (9)                                               /*!< CLK_T::HCLKEN0: EBICKEN Position       */
#define CLK_HCLKEN0_EBICKEN_Msk          (0x1ul << CLK_HCLKEN0_EBICKEN_Pos)                /*!< CLK_T::HCLKEN0: EBICKEN Mask           */

#define CLK_HCLKEN0_SDICCKEN_Pos         (10)                                              /*!< CLK_T::HCLKEN0: SDICCKEN Position      */
#define CLK_HCLKEN0_SDICCKEN_Msk         (0x1ul << CLK_HCLKEN0_SDICCKEN_Pos)               /*!< CLK_T::HCLKEN0: SDICCKEN Mask          */

#define CLK_HCLKEN0_GPIOCKEN_Pos         (11)                                              /*!< CLK_T::HCLKEN0: GPIOCKEN Position      */
#define CLK_HCLKEN0_GPIOCKEN_Msk         (0x1ul << CLK_HCLKEN0_GPIOCKEN_Pos)               /*!< CLK_T::HCLKEN0: GPIOCKEN Mask          */

#define CLK_HCLKEN0_PCLK0CKEN_Pos        (12)                                              /*!< CLK_T::HCLKEN0: PCLK0CKEN Position     */
#define CLK_HCLKEN0_PCLK0CKEN_Msk        (0x1ul << CLK_HCLKEN0_PCLK0CKEN_Pos)              /*!< CLK_T::HCLKEN0: PCLK0CKEN Mask         */

#define CLK_HCLKEN0_PCLK1CKEN_Pos        (13)                                              /*!< CLK_T::HCLKEN0: PCLK1CKEN Position     */
#define CLK_HCLKEN0_PCLK1CKEN_Msk        (0x1ul << CLK_HCLKEN0_PCLK1CKEN_Pos)              /*!< CLK_T::HCLKEN0: PCLK1CKEN Mask         */

#define CLK_HCLKEN0_PCLK2CKEN_Pos        (14)                                              /*!< CLK_T::HCLKEN0: PCLK2CKEN Position     */
#define CLK_HCLKEN0_PCLK2CKEN_Msk        (0x1ul << CLK_HCLKEN0_PCLK2CKEN_Pos)              /*!< CLK_T::HCLKEN0: PCLK2CKEN Mask         */

#define CLK_HCLKEN0_PCLK3CKEN_Pos        (15)                                              /*!< CLK_T::HCLKEN0: PCLK3CKEN Position     */
#define CLK_HCLKEN0_PCLK3CKEN_Msk        (0x1ul << CLK_HCLKEN0_PCLK3CKEN_Pos)              /*!< CLK_T::HCLKEN0: PCLK3CKEN Mask         */

#define CLK_HCLKEN0_PDMA0EN_Pos          (16)                                              /*!< CLK_T::HCLKEN0: PDMA0EN Position       */
#define CLK_HCLKEN0_PDMA0EN_Msk          (0x1ul << CLK_HCLKEN0_PDMA0EN_Pos)                /*!< CLK_T::HCLKEN0: PDMA0EN Mask           */

#define CLK_HCLKEN0_PDMA1EN_Pos          (17)                                              /*!< CLK_T::HCLKEN0: PDMA1EN Position       */
#define CLK_HCLKEN0_PDMA1EN_Msk          (0x1ul << CLK_HCLKEN0_PDMA1EN_Pos)                /*!< CLK_T::HCLKEN0: PDMA1EN Mask           */

#define CLK_HCLKEN0_EMAC0EN_Pos          (18)                                              /*!< CLK_T::HCLKEN0: EMAC0EN Position       */
#define CLK_HCLKEN0_EMAC0EN_Msk          (0x1ul << CLK_HCLKEN0_EMAC0EN_Pos)                /*!< CLK_T::HCLKEN0: EMAC0EN Mask           */

#define CLK_HCLKEN0_EMAC1EN_Pos          (19)                                              /*!< CLK_T::HCLKEN0: EMAC1EN Position       */
#define CLK_HCLKEN0_EMAC1EN_Msk          (0x1ul << CLK_HCLKEN0_EMAC1EN_Pos)                /*!< CLK_T::HCLKEN0: EMAC1EN Mask           */

#define CLK_HCLKEN0_NANDEN_Pos           (21)                                              /*!< CLK_T::HCLKEN0: NANDEN Position        */
#define CLK_HCLKEN0_NANDEN_Msk           (0x1ul << CLK_HCLKEN0_NANDEN_Pos)                 /*!< CLK_T::HCLKEN0: NANDEN Mask            */

#define CLK_HCLKEN0_SDH0EN_Pos           (22)                                              /*!< CLK_T::HCLKEN0: SDH0EN Position        */
#define CLK_HCLKEN0_SDH0EN_Msk           (0x1ul << CLK_HCLKEN0_SDH0EN_Pos)                 /*!< CLK_T::HCLKEN0: SDH0EN Mask            */

#define CLK_HCLKEN0_SDH1EN_Pos           (23)                                              /*!< CLK_T::HCLKEN0: SDH1EN Position        */
#define CLK_HCLKEN0_SDH1EN_Msk           (0x1ul << CLK_HCLKEN0_SDH1EN_Pos)                 /*!< CLK_T::HCLKEN0: SDH1EN Mask            */

#define CLK_HCLKEN0_USBHEN_Pos           (24)                                              /*!< CLK_T::HCLKEN0: USBHEN Position        */
#define CLK_HCLKEN0_USBHEN_Msk           (0x1ul << CLK_HCLKEN0_USBHEN_Pos)                 /*!< CLK_T::HCLKEN0: USBHEN Mask            */

#define CLK_HCLKEN0_USBDEN_Pos           (25)                                              /*!< CLK_T::HCLKEN0: USBDEN Position        */
#define CLK_HCLKEN0_USBDEN_Msk           (0x1ul << CLK_HCLKEN0_USBDEN_Pos)                 /*!< CLK_T::HCLKEN0: USBDEN Mask            */

#define CLK_HCLKEN1_I2SCKEN_Pos          (0)                                               /*!< CLK_T::HCLKEN1: I2SCKEN Position       */
#define CLK_HCLKEN1_I2SCKEN_Msk          (0x1ul << CLK_HCLKEN1_I2SCKEN_Pos)                /*!< CLK_T::HCLKEN1: I2SCKEN Mask           */

#define CLK_HCLKEN1_CRPTCKEN_Pos         (1)                                               /*!< CLK_T::HCLKEN1: CRPTCKEN Position      */
#define CLK_HCLKEN1_CRPTCKEN_Msk         (0x1ul << CLK_HCLKEN1_CRPTCKEN_Pos)               /*!< CLK_T::HCLKEN1: CRPTCKEN Mask          */

#define CLK_HCLKEN1_KSCKEN_Pos           (2)                                               /*!< CLK_T::HCLKEN1: KSCKEN Position        */
#define CLK_HCLKEN1_KSCKEN_Msk           (0x1ul << CLK_HCLKEN1_KSCKEN_Pos)                 /*!< CLK_T::HCLKEN1: KSCKEN Mask            */

#define CLK_HCLKEN1_OTPIDLE_Pos          (3)                                               /*!< CLK_T::HCLKEN1: OTPIDLE Position       */
#define CLK_HCLKEN1_OTPIDLE_Msk          (0x1ul << CLK_HCLKEN1_OTPIDLE_Pos)                /*!< CLK_T::HCLKEN1: OTPIDLE Mask           */

#define CLK_HCLKEN1_CANF0CKEN_Pos        (8)                                               /*!< CLK_T::HCLKEN1: CANF0CKEN Position     */
#define CLK_HCLKEN1_CANF0CKEN_Msk        (0x1ul << CLK_HCLKEN1_CANF0CKEN_Pos)              /*!< CLK_T::HCLKEN1: CANF0CKEN Mask         */

#define CLK_HCLKEN1_CANF1CKEN_Pos        (9)                                               /*!< CLK_T::HCLKEN1: CANF1CKEN Position     */
#define CLK_HCLKEN1_CANF1CKEN_Msk        (0x1ul << CLK_HCLKEN1_CANF1CKEN_Pos)              /*!< CLK_T::HCLKEN1: CANF1CKEN Mask         */

#define CLK_HCLKEN1_CANF2CKEN_Pos        (10)                                              /*!< CLK_T::HCLKEN1: CANF2CKEN Position     */
#define CLK_HCLKEN1_CANF2CKEN_Msk        (0x1ul << CLK_HCLKEN1_CANF2CKEN_Pos)              /*!< CLK_T::HCLKEN1: CANF2CKEN Mask         */

#define CLK_HCLKEN1_CANF3CKEN_Pos        (11)                                              /*!< CLK_T::HCLKEN1: CANF3CKEN Position     */
#define CLK_HCLKEN1_CANF3CKEN_Msk        (0x1ul << CLK_HCLKEN1_CANF3CKEN_Pos)              /*!< CLK_T::HCLKEN1: CANF3CKEN Mask         */

#define CLK_HCLKEN1_CANRAM0EN_Pos        (16)                                              /*!< CLK_T::HCLKEN1: CANRAM0EN Position     */
#define CLK_HCLKEN1_CANRAM0EN_Msk        (0x1ul << CLK_HCLKEN1_CANRAM0EN_Pos)              /*!< CLK_T::HCLKEN1: CANRAM0EN Mask         */

#define CLK_HCLKEN1_CANRAM1EN_Pos        (17)                                              /*!< CLK_T::HCLKEN1: CANRAM1EN Position     */
#define CLK_HCLKEN1_CANRAM1EN_Msk        (0x1ul << CLK_HCLKEN1_CANRAM1EN_Pos)              /*!< CLK_T::HCLKEN1: CANRAM1EN Mask         */

#define CLK_HCLKEN1_CANRAM2EN_Pos        (18)                                              /*!< CLK_T::HCLKEN1: CANRAM2EN Position     */
#define CLK_HCLKEN1_CANRAM2EN_Msk        (0x1ul << CLK_HCLKEN1_CANRAM2EN_Pos)              /*!< CLK_T::HCLKEN1: CANRAM2EN Mask         */

#define CLK_HCLKEN1_CANRAM3EN_Pos        (19)                                              /*!< CLK_T::HCLKEN1: CANRAM3EN Position     */
#define CLK_HCLKEN1_CANRAM3EN_Msk        (0x1ul << CLK_HCLKEN1_CANRAM3EN_Pos)              /*!< CLK_T::HCLKEN1: CANRAM3EN Mask         */

#define CLK_PCLKEN0_WDTCKEN_Pos          (0)                                               /*!< CLK_T::PCLKEN0: WDTCKEN Position       */
#define CLK_PCLKEN0_WDTCKEN_Msk          (0x1ul << CLK_PCLKEN0_WDTCKEN_Pos)                /*!< CLK_T::PCLKEN0: WDTCKEN Mask           */

#define CLK_PCLKEN0_WWDTCKEN_Pos         (1)                                               /*!< CLK_T::PCLKEN0: WWDTCKEN Position      */
#define CLK_PCLKEN0_WWDTCKEN_Msk         (0x1ul << CLK_PCLKEN0_WWDTCKEN_Pos)               /*!< CLK_T::PCLKEN0: WWDTCKEN Mask          */

#define CLK_PCLKEN0_RTCCKEN_Pos          (2)                                               /*!< CLK_T::PCLKEN0: RTCCKEN Position       */
#define CLK_PCLKEN0_RTCCKEN_Msk          (0x1ul << CLK_PCLKEN0_RTCCKEN_Pos)                /*!< CLK_T::PCLKEN0: RTCCKEN Mask           */

#define CLK_PCLKEN0_AICCKEN_Pos          (3)                                               /*!< CLK_T::PCLKEN0: AICCKEN Position       */
#define CLK_PCLKEN0_AICCKEN_Msk          (0x1ul << CLK_PCLKEN0_AICCKEN_Pos)                /*!< CLK_T::PCLKEN0: AICCKEN Mask           */

#define CLK_PCLKEN0_TMR0CKEN_Pos         (8)                                               /*!< CLK_T::PCLKEN0: TMR0CKEN Position      */
#define CLK_PCLKEN0_TMR0CKEN_Msk         (0x1ul << CLK_PCLKEN0_TMR0CKEN_Pos)               /*!< CLK_T::PCLKEN0: TMR0CKEN Mask          */

#define CLK_PCLKEN0_TMR1CKEN_Pos         (9)                                               /*!< CLK_T::PCLKEN0: TMR1CKEN Position      */
#define CLK_PCLKEN0_TMR1CKEN_Msk         (0x1ul << CLK_PCLKEN0_TMR1CKEN_Pos)               /*!< CLK_T::PCLKEN0: TMR1CKEN Mask          */

#define CLK_PCLKEN0_TMR2CKEN_Pos         (10)                                              /*!< CLK_T::PCLKEN0: TMR2CKEN Position      */
#define CLK_PCLKEN0_TMR2CKEN_Msk         (0x1ul << CLK_PCLKEN0_TMR2CKEN_Pos)               /*!< CLK_T::PCLKEN0: TMR2CKEN Mask          */

#define CLK_PCLKEN0_TMR3CKEN_Pos         (11)                                              /*!< CLK_T::PCLKEN0: TMR3CKEN Position      */
#define CLK_PCLKEN0_TMR3CKEN_Msk         (0x1ul << CLK_PCLKEN0_TMR3CKEN_Pos)               /*!< CLK_T::PCLKEN0: TMR3CKEN Mask          */

#define CLK_PCLKEN0_TMR4CKEN_Pos         (12)                                              /*!< CLK_T::PCLKEN0: TMR4CKEN Position      */
#define CLK_PCLKEN0_TMR4CKEN_Msk         (0x1ul << CLK_PCLKEN0_TMR4CKEN_Pos)               /*!< CLK_T::PCLKEN0: TMR4CKEN Mask          */

#define CLK_PCLKEN0_TMR5CKEN_Pos         (13)                                              /*!< CLK_T::PCLKEN0: TMR5CKEN Position      */
#define CLK_PCLKEN0_TMR5CKEN_Msk         (0x1ul << CLK_PCLKEN0_TMR5CKEN_Pos)               /*!< CLK_T::PCLKEN0: TMR5CKEN Mask          */

#define CLK_PCLKEN0_UART0CKEN_Pos        (16)                                              /*!< CLK_T::PCLKEN0: UART0CKEN Position     */
#define CLK_PCLKEN0_UART0CKEN_Msk        (0x1ul << CLK_PCLKEN0_UART0CKEN_Pos)              /*!< CLK_T::PCLKEN0: UART0CKEN Mask         */

#define CLK_PCLKEN0_UART1CKEN_Pos        (17)                                              /*!< CLK_T::PCLKEN0: UART1CKEN Position     */
#define CLK_PCLKEN0_UART1CKEN_Msk        (0x1ul << CLK_PCLKEN0_UART1CKEN_Pos)              /*!< CLK_T::PCLKEN0: UART1CKEN Mask         */

#define CLK_PCLKEN0_UART2CKEN_Pos        (18)                                              /*!< CLK_T::PCLKEN0: UART2CKEN Position     */
#define CLK_PCLKEN0_UART2CKEN_Msk        (0x1ul << CLK_PCLKEN0_UART2CKEN_Pos)              /*!< CLK_T::PCLKEN0: UART2CKEN Mask         */

#define CLK_PCLKEN0_UART3CKEN_Pos        (19)                                              /*!< CLK_T::PCLKEN0: UART3CKEN Position     */
#define CLK_PCLKEN0_UART3CKEN_Msk        (0x1ul << CLK_PCLKEN0_UART3CKEN_Pos)              /*!< CLK_T::PCLKEN0: UART3CKEN Mask         */

#define CLK_PCLKEN0_UART4CKEN_Pos        (20)                                              /*!< CLK_T::PCLKEN0: UART4CKEN Position     */
#define CLK_PCLKEN0_UART4CKEN_Msk        (0x1ul << CLK_PCLKEN0_UART4CKEN_Pos)              /*!< CLK_T::PCLKEN0: UART4CKEN Mask         */

#define CLK_PCLKEN0_UART5CKEN_Pos        (21)                                              /*!< CLK_T::PCLKEN0: UART5CKEN Position     */
#define CLK_PCLKEN0_UART5CKEN_Msk        (0x1ul << CLK_PCLKEN0_UART5CKEN_Pos)              /*!< CLK_T::PCLKEN0: UART5CKEN Mask         */

#define CLK_PCLKEN0_UART6CKEN_Pos        (22)                                              /*!< CLK_T::PCLKEN0: UART6CKEN Position     */
#define CLK_PCLKEN0_UART6CKEN_Msk        (0x1ul << CLK_PCLKEN0_UART6CKEN_Pos)              /*!< CLK_T::PCLKEN0: UART6CKEN Mask         */

#define CLK_PCLKEN0_UART7CKEN_Pos        (23)                                              /*!< CLK_T::PCLKEN0: UART7CKEN Position     */
#define CLK_PCLKEN0_UART7CKEN_Msk        (0x1ul << CLK_PCLKEN0_UART7CKEN_Pos)              /*!< CLK_T::PCLKEN0: UART7CKEN Mask         */

#define CLK_PCLKEN0_UART8CKEN_Pos        (24)                                              /*!< CLK_T::PCLKEN0: UART8CKEN Position     */
#define CLK_PCLKEN0_UART8CKEN_Msk        (0x1ul << CLK_PCLKEN0_UART8CKEN_Pos)              /*!< CLK_T::PCLKEN0: UART8CKEN Mask         */

#define CLK_PCLKEN0_UART9CKEN_Pos        (25)                                              /*!< CLK_T::PCLKEN0: UART9CKEN Position     */
#define CLK_PCLKEN0_UART9CKEN_Msk        (0x1ul << CLK_PCLKEN0_UART9CKEN_Pos)              /*!< CLK_T::PCLKEN0: UART9CKEN Mask         */

#define CLK_PCLKEN1_I2C0CKEN_Pos         (0)                                               /*!< CLK_T::PCLKEN1: I2C0CKEN Position      */
#define CLK_PCLKEN1_I2C0CKEN_Msk         (0x1ul << CLK_PCLKEN1_I2C0CKEN_Pos)               /*!< CLK_T::PCLKEN1: I2C0CKEN Mask          */

#define CLK_PCLKEN1_I2C1CKEN_Pos         (1)                                               /*!< CLK_T::PCLKEN1: I2C1CKEN Position      */
#define CLK_PCLKEN1_I2C1CKEN_Msk         (0x1ul << CLK_PCLKEN1_I2C1CKEN_Pos)               /*!< CLK_T::PCLKEN1: I2C1CKEN Mask          */

#define CLK_PCLKEN1_I2C2CKEN_Pos         (2)                                               /*!< CLK_T::PCLKEN1: I2C2CKEN Position      */
#define CLK_PCLKEN1_I2C2CKEN_Msk         (0x1ul << CLK_PCLKEN1_I2C2CKEN_Pos)               /*!< CLK_T::PCLKEN1: I2C2CKEN Mask          */

#define CLK_PCLKEN1_I2C3CKEN_Pos         (3)                                               /*!< CLK_T::PCLKEN1: I2C3CKEN Position      */
#define CLK_PCLKEN1_I2C3CKEN_Msk         (0x1ul << CLK_PCLKEN1_I2C3CKEN_Pos)               /*!< CLK_T::PCLKEN1: I2C3CKEN Mask          */

#define CLK_PCLKEN1_SPI0CKEN_Pos         (4)                                               /*!< CLK_T::PCLKEN1: SPI0CKEN Position      */
#define CLK_PCLKEN1_SPI0CKEN_Msk         (0x1ul << CLK_PCLKEN1_SPI0CKEN_Pos)               /*!< CLK_T::PCLKEN1: SPI0CKEN Mask          */

#define CLK_PCLKEN1_SPI1CKEN_Pos         (5)                                               /*!< CLK_T::PCLKEN1: SPI1CKEN Position      */
#define CLK_PCLKEN1_SPI1CKEN_Msk         (0x1ul << CLK_PCLKEN1_SPI1CKEN_Pos)               /*!< CLK_T::PCLKEN1: SPI1CKEN Mask          */

#define CLK_PCLKEN1_SPI2CKEN_Pos         (6)                                               /*!< CLK_T::PCLKEN1: SPI2CKEN Position      */
#define CLK_PCLKEN1_SPI2CKEN_Msk         (0x1ul << CLK_PCLKEN1_SPI2CKEN_Pos)               /*!< CLK_T::PCLKEN1: SPI2CKEN Mask          */

#define CLK_PCLKEN1_SPI3CKEN_Pos         (7)                                               /*!< CLK_T::PCLKEN1: SPI3CKEN Position      */
#define CLK_PCLKEN1_SPI3CKEN_Msk         (0x1ul << CLK_PCLKEN1_SPI3CKEN_Pos)               /*!< CLK_T::PCLKEN1: SPI3CKEN Mask          */

#define CLK_PCLKEN1_CAN0CKEN_Pos         (8)                                               /*!< CLK_T::PCLKEN1: CAN0CKEN Position      */
#define CLK_PCLKEN1_CAN0CKEN_Msk         (0x1ul << CLK_PCLKEN1_CAN0CKEN_Pos)               /*!< CLK_T::PCLKEN1: CAN0CKEN Mask          */

#define CLK_PCLKEN1_CAN1CKEN_Pos         (9)                                               /*!< CLK_T::PCLKEN1: CAN1CKEN Position      */
#define CLK_PCLKEN1_CAN1CKEN_Msk         (0x1ul << CLK_PCLKEN1_CAN1CKEN_Pos)               /*!< CLK_T::PCLKEN1: CAN1CKEN Mask          */

#define CLK_PCLKEN1_CAN2CKEN_Pos         (10)                                              /*!< CLK_T::PCLKEN1: CAN2CKEN Position      */
#define CLK_PCLKEN1_CAN2CKEN_Msk         (0x1ul << CLK_PCLKEN1_CAN2CKEN_Pos)               /*!< CLK_T::PCLKEN1: CAN2CKEN Mask          */

#define CLK_PCLKEN1_CAN3CKEN_Pos         (11)                                              /*!< CLK_T::PCLKEN1: CAN3CKEN Position      */
#define CLK_PCLKEN1_CAN3CKEN_Msk         (0x1ul << CLK_PCLKEN1_CAN3CKEN_Pos)               /*!< CLK_T::PCLKEN1: CAN3CKEN Mask          */

#define CLK_PCLKEN1_SMC0CKEN_Pos         (16)                                              /*!< CLK_T::PCLKEN1: SMC0CKEN Position      */
#define CLK_PCLKEN1_SMC0CKEN_Msk         (0x1ul << CLK_PCLKEN1_SMC0CKEN_Pos)               /*!< CLK_T::PCLKEN1: SMC0CKEN Mask          */

#define CLK_PCLKEN1_SMC1CKEN_Pos         (17)                                              /*!< CLK_T::PCLKEN1: SMC1CKEN Position      */
#define CLK_PCLKEN1_SMC1CKEN_Msk         (0x1ul << CLK_PCLKEN1_SMC1CKEN_Pos)               /*!< CLK_T::PCLKEN1: SMC1CKEN Mask          */

#define CLK_PCLKEN1_QSPI0CKEN_Pos        (20)                                              /*!< CLK_T::PCLKEN1: QSPI0CKEN Position     */
#define CLK_PCLKEN1_QSPI0CKEN_Msk        (0x1ul << CLK_PCLKEN1_QSPI0CKEN_Pos)              /*!< CLK_T::PCLKEN1: QSPI0CKEN Mask         */

#define CLK_PCLKEN1_ADCCKEN_Pos          (24)                                              /*!< CLK_T::PCLKEN1: ADCCKEN Position       */
#define CLK_PCLKEN1_ADCCKEN_Msk          (0x1ul << CLK_PCLKEN1_ADCCKEN_Pos)                /*!< CLK_T::PCLKEN1: ADCCKEN Mask           */

#define CLK_PCLKEN1_EADCCKEN_Pos         (25)                                              /*!< CLK_T::PCLKEN1: EADCCKEN Position      */
#define CLK_PCLKEN1_EADCCKEN_Msk         (0x1ul << CLK_PCLKEN1_EADCCKEN_Pos)               /*!< CLK_T::PCLKEN1: EADCCKEN Mask          */

#define CLK_PCLKEN1_BPWM0CKEN_Pos        (26)                                              /*!< CLK_T::PCLKEN1: BPWM0CKEN Position     */
#define CLK_PCLKEN1_BPWM0CKEN_Msk        (0x1ul << CLK_PCLKEN1_BPWM0CKEN_Pos)              /*!< CLK_T::PCLKEN1: BPWM0CKEN Mask         */

#define CLK_PCLKEN1_BPWM1CKEN_Pos        (27)                                              /*!< CLK_T::PCLKEN1: BPWM1CKEN Position     */
#define CLK_PCLKEN1_BPWM1CKEN_Msk        (0x1ul << CLK_PCLKEN1_BPWM1CKEN_Pos)              /*!< CLK_T::PCLKEN1: BPWM1CKEN Mask         */

#define CLK_DIVCTL0_SYSTEM_S_Pos         (3)                                               /*!< CLK_T::DIVCTL0: SYSTEM_S Position      */
#define CLK_DIVCTL0_SYSTEM_S_Msk         (0x3ul << CLK_DIVCTL0_SYSTEM_S_Pos)               /*!< CLK_T::DIVCTL0: SYSTEM_S Mask          */

#define CLK_DIVCTL0_CPUDIV2EN_Pos        (8)                                               /*!< CLK_T::DIVCTL0: CPUDIV2EN Position     */
#define CLK_DIVCTL0_CPUDIV2EN_Msk        (0x1ul << CLK_DIVCTL0_CPUDIV2EN_Pos)              /*!< CLK_T::DIVCTL0: CPUDIV2EN Mask         */

#define CLK_DIVCTL0_PCLK3DIV_Pos         (16)                                              /*!< CLK_T::DIVCTL0: PCLK3DIV Position      */
#define CLK_DIVCTL0_PCLK3DIV_Msk         (0x7ul << CLK_DIVCTL0_PCLK3DIV_Pos)               /*!< CLK_T::DIVCTL0: PCLK3DIV Mask          */

#define CLK_DIVCTL0_PCLK3_S_Pos          (19)                                              /*!< CLK_T::DIVCTL0: PCLK3_S Position       */
#define CLK_DIVCTL0_PCLK3_S_Msk          (0x3ul << CLK_DIVCTL0_PCLK3_S_Pos)                /*!< CLK_T::DIVCTL0: PCLK3_S Mask           */

#define CLK_DIVCTL1_I2S_S_Pos            (19)                                              /*!< CLK_T::DIVCTL1: I2S_S Position         */
#define CLK_DIVCTL1_I2S_S_Msk            (0x3ul << CLK_DIVCTL1_I2S_S_Pos)                  /*!< CLK_T::DIVCTL1: I2S_S Mask             */

#define CLK_DIVCTL1_I2S_N_Pos            (24)                                              /*!< CLK_T::DIVCTL1: I2S_N Position         */
#define CLK_DIVCTL1_I2S_N_Msk            (0xfful << CLK_DIVCTL1_I2S_N_Pos)                 /*!< CLK_T::DIVCTL1: I2S_N Mask             */

#define CLK_DIVCTL2_CANFD0_S_Pos         (0)                                               /*!< CLK_T::DIVCTL2: CANFD0_S Position      */
#define CLK_DIVCTL2_CANFD0_S_Msk         (0x1ul << CLK_DIVCTL2_CANFD0_S_Pos)               /*!< CLK_T::DIVCTL2: CANFD0_S Mask          */

#define CLK_DIVCTL2_CANFD1_S_Pos         (1)                                               /*!< CLK_T::DIVCTL2: CANFD1_S Position      */
#define CLK_DIVCTL2_CANFD1_S_Msk         (0x1ul << CLK_DIVCTL2_CANFD1_S_Pos)               /*!< CLK_T::DIVCTL2: CANFD1_S Mask          */

#define CLK_DIVCTL2_CANFD2_S_Pos         (2)                                               /*!< CLK_T::DIVCTL2: CANFD2_S Position      */
#define CLK_DIVCTL2_CANFD2_S_Msk         (0x1ul << CLK_DIVCTL2_CANFD2_S_Pos)               /*!< CLK_T::DIVCTL2: CANFD2_S Mask          */

#define CLK_DIVCTL2_CANFD3_S_Pos         (3)                                               /*!< CLK_T::DIVCTL2: CANFD3_S Position      */
#define CLK_DIVCTL2_CANFD3_S_Msk         (0x1ul << CLK_DIVCTL2_CANFD3_S_Pos)               /*!< CLK_T::DIVCTL2: CANFD3_S Mask          */

#define CLK_DIVCTL2_QSPI0_S_Pos          (8)                                               /*!< CLK_T::DIVCTL2: QSPI0_S Position       */
#define CLK_DIVCTL2_QSPI0_S_Msk          (0x3ul << CLK_DIVCTL2_QSPI0_S_Pos)                /*!< CLK_T::DIVCTL2: QSPI0_S Mask           */

#define CLK_DIVCTL2_SPI0_S_Pos           (10)                                              /*!< CLK_T::DIVCTL2: SPI0_S Position        */
#define CLK_DIVCTL2_SPI0_S_Msk           (0x3ul << CLK_DIVCTL2_SPI0_S_Pos)                 /*!< CLK_T::DIVCTL2: SPI0_S Mask            */

#define CLK_DIVCTL2_SPI1_S_Pos           (12)                                              /*!< CLK_T::DIVCTL2: SPI1_S Position        */
#define CLK_DIVCTL2_SPI1_S_Msk           (0x3ul << CLK_DIVCTL2_SPI1_S_Pos)                 /*!< CLK_T::DIVCTL2: SPI1_S Mask            */

#define CLK_DIVCTL2_SPI2_S_Pos           (14)                                              /*!< CLK_T::DIVCTL2: SPI2_S Position        */
#define CLK_DIVCTL2_SPI2_S_Msk           (0x3ul << CLK_DIVCTL2_SPI2_S_Pos)                 /*!< CLK_T::DIVCTL2: SPI2_S Mask            */

#define CLK_DIVCTL2_SPI3_S_Pos           (16)                                              /*!< CLK_T::DIVCTL2: SPI3_S Position        */
#define CLK_DIVCTL2_SPI3_S_Msk           (0x3ul << CLK_DIVCTL2_SPI3_S_Pos)                 /*!< CLK_T::DIVCTL2: SPI3_S Mask            */

#define CLK_DIVCTL3_SD0_S_Pos            (3)                                               /*!< CLK_T::DIVCTL3: SD0_S Position         */
#define CLK_DIVCTL3_SD0_S_Msk            (0x3ul << CLK_DIVCTL3_SD0_S_Pos)                  /*!< CLK_T::DIVCTL3: SD0_S Mask             */

#define CLK_DIVCTL3_SD0_N_Pos            (5)                                               /*!< CLK_T::DIVCTL3: SD0_N Position         */
#define CLK_DIVCTL3_SD0_N_Msk            (0x7fful << CLK_DIVCTL3_SD0_N_Pos)                /*!< CLK_T::DIVCTL3: SD0_N Mask             */

#define CLK_DIVCTL3_SD1_S_Pos            (19)                                              /*!< CLK_T::DIVCTL3: SD1_S Position         */
#define CLK_DIVCTL3_SD1_S_Msk            (0x3ul << CLK_DIVCTL3_SD1_S_Pos)                  /*!< CLK_T::DIVCTL3: SD1_S Mask             */

#define CLK_DIVCTL3_SD1_N_Pos            (21)                                              /*!< CLK_T::DIVCTL3: SD1_N Position         */
#define CLK_DIVCTL3_SD1_N_Msk            (0x7fful << CLK_DIVCTL3_SD1_N_Pos)                /*!< CLK_T::DIVCTL3: SD1_N Mask             */

#define CLK_DIVCTL4_UART0_S_Pos          (3)                                               /*!< CLK_T::DIVCTL4: UART0_S Position       */
#define CLK_DIVCTL4_UART0_S_Msk          (0x3ul << CLK_DIVCTL4_UART0_S_Pos)                /*!< CLK_T::DIVCTL4: UART0_S Mask           */

#define CLK_DIVCTL4_UART0_N_Pos          (5)                                               /*!< CLK_T::DIVCTL4: UART0_N Position       */
#define CLK_DIVCTL4_UART0_N_Msk          (0x7ul << CLK_DIVCTL4_UART0_N_Pos)                /*!< CLK_T::DIVCTL4: UART0_N Mask           */

#define CLK_DIVCTL4_UART1_S_Pos          (11)                                              /*!< CLK_T::DIVCTL4: UART1_S Position       */
#define CLK_DIVCTL4_UART1_S_Msk          (0x3ul << CLK_DIVCTL4_UART1_S_Pos)                /*!< CLK_T::DIVCTL4: UART1_S Mask           */

#define CLK_DIVCTL4_UART1_N_Pos          (13)                                              /*!< CLK_T::DIVCTL4: UART1_N Position       */
#define CLK_DIVCTL4_UART1_N_Msk          (0x7ul << CLK_DIVCTL4_UART1_N_Pos)                /*!< CLK_T::DIVCTL4: UART1_N Mask           */

#define CLK_DIVCTL4_UART2_S_Pos          (19)                                              /*!< CLK_T::DIVCTL4: UART2_S Position       */
#define CLK_DIVCTL4_UART2_S_Msk          (0x3ul << CLK_DIVCTL4_UART2_S_Pos)                /*!< CLK_T::DIVCTL4: UART2_S Mask           */

#define CLK_DIVCTL4_UART2_N_Pos          (21)                                              /*!< CLK_T::DIVCTL4: UART2_N Position       */
#define CLK_DIVCTL4_UART2_N_Msk          (0x7ul << CLK_DIVCTL4_UART2_N_Pos)                /*!< CLK_T::DIVCTL4: UART2_N Mask           */

#define CLK_DIVCTL4_UART3_S_Pos          (27)                                              /*!< CLK_T::DIVCTL4: UART3_S Position       */
#define CLK_DIVCTL4_UART3_S_Msk          (0x3ul << CLK_DIVCTL4_UART3_S_Pos)                /*!< CLK_T::DIVCTL4: UART3_S Mask           */

#define CLK_DIVCTL4_UART3_N_Pos          (29)                                              /*!< CLK_T::DIVCTL4: UART3_N Position       */
#define CLK_DIVCTL4_UART3_N_Msk          (0x7ul << CLK_DIVCTL4_UART3_N_Pos)                /*!< CLK_T::DIVCTL4: UART3_N Mask           */

#define CLK_DIVCTL5_UART4_S_Pos          (3)                                               /*!< CLK_T::DIVCTL5: UART4_S Position       */
#define CLK_DIVCTL5_UART4_S_Msk          (0x3ul << CLK_DIVCTL5_UART4_S_Pos)                /*!< CLK_T::DIVCTL5: UART4_S Mask           */

#define CLK_DIVCTL5_UART4_N_Pos          (5)                                               /*!< CLK_T::DIVCTL5: UART4_N Position       */
#define CLK_DIVCTL5_UART4_N_Msk          (0x7ul << CLK_DIVCTL5_UART4_N_Pos)                /*!< CLK_T::DIVCTL5: UART4_N Mask           */

#define CLK_DIVCTL5_UART5_S_Pos          (11)                                              /*!< CLK_T::DIVCTL5: UART5_S Position       */
#define CLK_DIVCTL5_UART5_S_Msk          (0x3ul << CLK_DIVCTL5_UART5_S_Pos)                /*!< CLK_T::DIVCTL5: UART5_S Mask           */

#define CLK_DIVCTL5_UART5_N_Pos          (13)                                              /*!< CLK_T::DIVCTL5: UART5_N Position       */
#define CLK_DIVCTL5_UART5_N_Msk          (0x7ul << CLK_DIVCTL5_UART5_N_Pos)                /*!< CLK_T::DIVCTL5: UART5_N Mask           */

#define CLK_DIVCTL5_UART6_S_Pos          (19)                                              /*!< CLK_T::DIVCTL5: UART6_S Position       */
#define CLK_DIVCTL5_UART6_S_Msk          (0x3ul << CLK_DIVCTL5_UART6_S_Pos)                /*!< CLK_T::DIVCTL5: UART6_S Mask           */

#define CLK_DIVCTL5_UART6_N_Pos          (21)                                              /*!< CLK_T::DIVCTL5: UART6_N Position       */
#define CLK_DIVCTL5_UART6_N_Msk          (0x7ul << CLK_DIVCTL5_UART6_N_Pos)                /*!< CLK_T::DIVCTL5: UART6_N Mask           */

#define CLK_DIVCTL5_UART7_S_Pos          (27)                                              /*!< CLK_T::DIVCTL5: UART7_S Position       */
#define CLK_DIVCTL5_UART7_S_Msk          (0x3ul << CLK_DIVCTL5_UART7_S_Pos)                /*!< CLK_T::DIVCTL5: UART7_S Mask           */

#define CLK_DIVCTL5_UART7_N_Pos          (29)                                              /*!< CLK_T::DIVCTL5: UART7_N Position       */
#define CLK_DIVCTL5_UART7_N_Msk          (0x7ul << CLK_DIVCTL5_UART7_N_Pos)                /*!< CLK_T::DIVCTL5: UART7_N Mask           */

#define CLK_DIVCTL6_UART8_S_Pos          (3)                                               /*!< CLK_T::DIVCTL6: UART8_S Position       */
#define CLK_DIVCTL6_UART8_S_Msk          (0x3ul << CLK_DIVCTL6_UART8_S_Pos)                /*!< CLK_T::DIVCTL6: UART8_S Mask           */

#define CLK_DIVCTL6_UART8_N_Pos          (5)                                               /*!< CLK_T::DIVCTL6: UART8_N Position       */
#define CLK_DIVCTL6_UART8_N_Msk          (0x7ul << CLK_DIVCTL6_UART8_N_Pos)                /*!< CLK_T::DIVCTL6: UART8_N Mask           */

#define CLK_DIVCTL6_UART9_S_Pos          (11)                                              /*!< CLK_T::DIVCTL6: UART9_S Position       */
#define CLK_DIVCTL6_UART9_S_Msk          (0x3ul << CLK_DIVCTL6_UART9_S_Pos)                /*!< CLK_T::DIVCTL6: UART9_S Mask           */

#define CLK_DIVCTL6_UART9_N_Pos          (13)                                              /*!< CLK_T::DIVCTL6: UART9_N Position       */
#define CLK_DIVCTL6_UART9_N_Msk          (0x7ul << CLK_DIVCTL6_UART9_N_Pos)                /*!< CLK_T::DIVCTL6: UART9_N Mask           */

#define CLK_DIVCTL6_EADC_N_Pos           (16)                                              /*!< CLK_T::DIVCTL6: EADC_N Position        */
#define CLK_DIVCTL6_EADC_N_Msk           (0xfful << CLK_DIVCTL6_EADC_N_Pos)                /*!< CLK_T::DIVCTL6: EADC_N Mask            */

#define CLK_DIVCTL6_SMC0_N_Pos           (24)                                              /*!< CLK_T::DIVCTL6: SMC0_N Position        */
#define CLK_DIVCTL6_SMC0_N_Msk           (0xful << CLK_DIVCTL6_SMC0_N_Pos)                 /*!< CLK_T::DIVCTL6: SMC0_N Mask            */

#define CLK_DIVCTL6_SMC1_N_Pos           (28)                                              /*!< CLK_T::DIVCTL6: SMC1_N Position        */
#define CLK_DIVCTL6_SMC1_N_Msk           (0xful << CLK_DIVCTL6_SMC1_N_Pos)                 /*!< CLK_T::DIVCTL6: SMC1_N Mask            */

#define CLK_DIVCTL7_CANFD0_N_Pos         (0)                                               /*!< CLK_T::DIVCTL7: CANFD0_N Position      */
#define CLK_DIVCTL7_CANFD0_N_Msk         (0xful << CLK_DIVCTL7_CANFD0_N_Pos)               /*!< CLK_T::DIVCTL7: CANFD0_N Mask          */

#define CLK_DIVCTL7_CANFD1_N_Pos         (4)                                               /*!< CLK_T::DIVCTL7: CANFD1_N Position      */
#define CLK_DIVCTL7_CANFD1_N_Msk         (0xful << CLK_DIVCTL7_CANFD1_N_Pos)               /*!< CLK_T::DIVCTL7: CANFD1_N Mask          */

#define CLK_DIVCTL7_CANFD2_N_Pos         (8)                                               /*!< CLK_T::DIVCTL7: CANFD2_N Position      */
#define CLK_DIVCTL7_CANFD2_N_Msk         (0xful << CLK_DIVCTL7_CANFD2_N_Pos)               /*!< CLK_T::DIVCTL7: CANFD2_N Mask          */

#define CLK_DIVCTL7_CANFD3_N_Pos         (12)                                              /*!< CLK_T::DIVCTL7: CANFD3_N Position      */
#define CLK_DIVCTL7_CANFD3_N_Msk         (0xful << CLK_DIVCTL7_CANFD3_N_Pos)               /*!< CLK_T::DIVCTL7: CANFD3_N Mask          */

#define CLK_DIVCTL7_ADC_S_Pos            (20)                                              /*!< CLK_T::DIVCTL7: ADC_S Position         */
#define CLK_DIVCTL7_ADC_S_Msk            (0x3ul << CLK_DIVCTL7_ADC_S_Pos)                  /*!< CLK_T::DIVCTL7: ADC_S Mask             */

#define CLK_DIVCTL7_ADC_N_Pos            (24)                                              /*!< CLK_T::DIVCTL7: ADC_N Position         */
#define CLK_DIVCTL7_ADC_N_Msk            (0xfful << CLK_DIVCTL7_ADC_N_Pos)                 /*!< CLK_T::DIVCTL7: ADC_N Mask             */

#define CLK_DIVCTL8_MDCLKDIV_Pos         (0)                                               /*!< CLK_T::DIVCTL8: MDCLKDIV Position      */
#define CLK_DIVCTL8_MDCLKDIV_Msk         (0xfful << CLK_DIVCTL8_MDCLKDIV_Pos)              /*!< CLK_T::DIVCTL8: MDCLKDIV Mask          */

#define CLK_DIVCTL8_WDTSEL_Pos           (8)                                               /*!< CLK_T::DIVCTL8: WDTSEL Position        */
#define CLK_DIVCTL8_WDTSEL_Msk           (0x3ul << CLK_DIVCTL8_WDTSEL_Pos)                 /*!< CLK_T::DIVCTL8: WDTSEL Mask            */

#define CLK_DIVCTL8_WWDTSEL_Pos          (10)                                              /*!< CLK_T::DIVCTL8: WWDTSEL Position       */
#define CLK_DIVCTL8_WWDTSEL_Msk          (0x3ul << CLK_DIVCTL8_WWDTSEL_Pos)                /*!< CLK_T::DIVCTL8: WWDTSEL Mask           */

#define CLK_DIVCTL8_TMR0SEL_Pos          (16)                                              /*!< CLK_T::DIVCTL8: TMR0SEL Position       */
#define CLK_DIVCTL8_TMR0SEL_Msk          (0x3ul << CLK_DIVCTL8_TMR0SEL_Pos)                /*!< CLK_T::DIVCTL8: TMR0SEL Mask           */

#define CLK_DIVCTL8_TMR1SEL_Pos          (18)                                              /*!< CLK_T::DIVCTL8: TMR1SEL Position       */
#define CLK_DIVCTL8_TMR1SEL_Msk          (0x3ul << CLK_DIVCTL8_TMR1SEL_Pos)                /*!< CLK_T::DIVCTL8: TMR1SEL Mask           */

#define CLK_DIVCTL8_TMR2SEL_Pos          (20)                                              /*!< CLK_T::DIVCTL8: TMR2SEL Position       */
#define CLK_DIVCTL8_TMR2SEL_Msk          (0x3ul << CLK_DIVCTL8_TMR2SEL_Pos)                /*!< CLK_T::DIVCTL8: TMR2SEL Mask           */

#define CLK_DIVCTL8_TMR3SEL_Pos          (22)                                              /*!< CLK_T::DIVCTL8: TMR3SEL Position       */
#define CLK_DIVCTL8_TMR3SEL_Msk          (0x3ul << CLK_DIVCTL8_TMR3SEL_Pos)                /*!< CLK_T::DIVCTL8: TMR3SEL Mask           */

#define CLK_DIVCTL8_TMR4SEL_Pos          (24)                                              /*!< CLK_T::DIVCTL8: TMR4SEL Position       */
#define CLK_DIVCTL8_TMR4SEL_Msk          (0x3ul << CLK_DIVCTL8_TMR4SEL_Pos)                /*!< CLK_T::DIVCTL8: TMR4SEL Mask           */

#define CLK_DIVCTL8_TMR5SEL_Pos          (26)                                              /*!< CLK_T::DIVCTL8: TMR5SEL Position       */
#define CLK_DIVCTL8_TMR5SEL_Msk          (0x3ul << CLK_DIVCTL8_TMR5SEL_Pos)                /*!< CLK_T::DIVCTL8: TMR5SEL Mask           */

#define CLK_DIVCTL9_CKO_S_Pos            (19)                                              /*!< CLK_T::DIVCTL9: CKO_S Position         */
#define CLK_DIVCTL9_CKO_S_Msk            (0x3ul << CLK_DIVCTL9_CKO_S_Pos)                  /*!< CLK_T::DIVCTL9: CKO_S Mask             */

#define CLK_DIVCTL9_CKO_N_Pos            (24)                                              /*!< CLK_T::DIVCTL9: CKO_N Position         */
#define CLK_DIVCTL9_CKO_N_Msk            (0xfful << CLK_DIVCTL9_CKO_N_Pos)                 /*!< CLK_T::DIVCTL9: CKO_N Mask             */

#define CLK_APLLCON_FB_DV_Pos            (0)                                               /*!< CLK_T::APLLCON: FB_DV Position         */
#define CLK_APLLCON_FB_DV_Msk            (0x7ful << CLK_APLLCON_FB_DV_Pos)                 /*!< CLK_T::APLLCON: FB_DV Mask             */

#define CLK_APLLCON_IN_DV_Pos            (7)                                               /*!< CLK_T::APLLCON: IN_DV Position         */
#define CLK_APLLCON_IN_DV_Msk            (0x3ful << CLK_APLLCON_IN_DV_Pos)                 /*!< CLK_T::APLLCON: IN_DV Mask             */

#define CLK_APLLCON_OUT_DV_Pos           (13)                                              /*!< CLK_T::APLLCON: OUT_DV Position        */
#define CLK_APLLCON_OUT_DV_Msk           (0x7ul << CLK_APLLCON_OUT_DV_Pos)                 /*!< CLK_T::APLLCON: OUT_DV Mask            */

#define CLK_APLLCON_FRAC_Pos             (16)                                              /*!< CLK_T::APLLCON: FRAC Position          */
#define CLK_APLLCON_FRAC_Msk             (0xffful << CLK_APLLCON_FRAC_Pos)                 /*!< CLK_T::APLLCON: FRAC Mask              */

#define CLK_APLLCON_PD_Pos               (28)                                              /*!< CLK_T::APLLCON: PD Position            */
#define CLK_APLLCON_PD_Msk               (0x1ul << CLK_APLLCON_PD_Pos)                     /*!< CLK_T::APLLCON: PD Mask                */

#define CLK_APLLCON_BYPASS_Pos           (29)                                              /*!< CLK_T::APLLCON: BYPASS Position        */
#define CLK_APLLCON_BYPASS_Msk           (0x1ul << CLK_APLLCON_BYPASS_Pos)                 /*!< CLK_T::APLLCON: BYPASS Mask            */

#define CLK_APLLCON_RESETN_Pos           (30)                                              /*!< CLK_T::APLLCON: RESETN Position        */
#define CLK_APLLCON_RESETN_Msk           (0x1ul << CLK_APLLCON_RESETN_Pos)                 /*!< CLK_T::APLLCON: RESETN Mask            */

#define CLK_APLLCON_PLL_STB_Pos          (31)                                              /*!< CLK_T::APLLCON: PLL_STB Position       */
#define CLK_APLLCON_PLL_STB_Msk          (0x1ul << CLK_APLLCON_PLL_STB_Pos)                /*!< CLK_T::APLLCON: PLL_STB Mask           */

#define CLK_UPLLCON_FB_DV_Pos            (0)                                               /*!< CLK_T::UPLLCON: FB_DV Position         */
#define CLK_UPLLCON_FB_DV_Msk            (0x7ful << CLK_UPLLCON_FB_DV_Pos)                 /*!< CLK_T::UPLLCON: FB_DV Mask             */

#define CLK_UPLLCON_IN_DV_Pos            (7)                                               /*!< CLK_T::UPLLCON: IN_DV Position         */
#define CLK_UPLLCON_IN_DV_Msk            (0x3ful << CLK_UPLLCON_IN_DV_Pos)                 /*!< CLK_T::UPLLCON: IN_DV Mask             */

#define CLK_UPLLCON_OUT_DV_Pos           (13)                                              /*!< CLK_T::UPLLCON: OUT_DV Position        */
#define CLK_UPLLCON_OUT_DV_Msk           (0x7ul << CLK_UPLLCON_OUT_DV_Pos)                 /*!< CLK_T::UPLLCON: OUT_DV Mask            */

#define CLK_UPLLCON_FRAC_Pos             (16)                                              /*!< CLK_T::UPLLCON: FRAC Position          */
#define CLK_UPLLCON_FRAC_Msk             (0xffful << CLK_UPLLCON_FRAC_Pos)                 /*!< CLK_T::UPLLCON: FRAC Mask              */

#define CLK_UPLLCON_PD_Pos               (28)                                              /*!< CLK_T::UPLLCON: PD Position            */
#define CLK_UPLLCON_PD_Msk               (0x1ul << CLK_UPLLCON_PD_Pos)                     /*!< CLK_T::UPLLCON: PD Mask                */

#define CLK_UPLLCON_BYPASS_Pos           (29)                                              /*!< CLK_T::UPLLCON: BYPASS Position        */
#define CLK_UPLLCON_BYPASS_Msk           (0x1ul << CLK_UPLLCON_BYPASS_Pos)                 /*!< CLK_T::UPLLCON: BYPASS Mask            */

#define CLK_UPLLCON_RESETN_Pos           (30)                                              /*!< CLK_T::UPLLCON: RESETN Position        */
#define CLK_UPLLCON_RESETN_Msk           (0x1ul << CLK_UPLLCON_RESETN_Pos)                 /*!< CLK_T::UPLLCON: RESETN Mask            */

#define CLK_UPLLCON_PLL_STB_Pos          (31)                                              /*!< CLK_T::UPLLCON: PLL_STB Position       */
#define CLK_UPLLCON_PLL_STB_Msk          (0x1ul << CLK_UPLLCON_PLL_STB_Pos)                /*!< CLK_T::UPLLCON: PLL_STB Mask           */

#define CLK_PLLSTBCNTR_PLLSTBCNT_Pos     (0)                                               /*!< CLK_T::PLLSTBCNTR: PLLSTBCNT Position  */
#define CLK_PLLSTBCNTR_PLLSTBCNT_Msk     (0xfffful << CLK_PLLSTBCNTR_PLLSTBCNT_Pos)        /*!< CLK_T::PLLSTBCNTR: PLLSTBCNT Mask      */

#define CLK_STOPREQ_CANFD0STR_Pos        (0)                                               /*!< CLK_T::STOPREQ: CANFD0STR Position     */
#define CLK_STOPREQ_CANFD0STR_Msk        (0x1ul << CLK_STOPREQ_CANFD0STR_Pos)              /*!< CLK_T::STOPREQ: CANFD0STR Mask         */

#define CLK_STOPREQ_CANFD1STR_Pos        (1)                                               /*!< CLK_T::STOPREQ: CANFD1STR Position     */
#define CLK_STOPREQ_CANFD1STR_Msk        (0x1ul << CLK_STOPREQ_CANFD1STR_Pos)              /*!< CLK_T::STOPREQ: CANFD1STR Mask         */

#define CLK_STOPREQ_CANFD2STR_Pos        (2)                                               /*!< CLK_T::STOPREQ: CANFD2STR Position     */
#define CLK_STOPREQ_CANFD2STR_Msk        (0x1ul << CLK_STOPREQ_CANFD2STR_Pos)              /*!< CLK_T::STOPREQ: CANFD2STR Mask         */

#define CLK_STOPREQ_CANFD3STR_Pos        (3)                                               /*!< CLK_T::STOPREQ: CANFD3STR Position     */
#define CLK_STOPREQ_CANFD3STR_Msk        (0x1ul << CLK_STOPREQ_CANFD3STR_Pos)              /*!< CLK_T::STOPREQ: CANFD3STR Mask         */

#define CLK_STOPACK_CANFD0STA_Pos        (0)                                               /*!< CLK_T::STOPACK: CANFD0STA Position     */
#define CLK_STOPACK_CANFD0STA_Msk        (0x1ul << CLK_STOPACK_CANFD0STA_Pos)              /*!< CLK_T::STOPACK: CANFD0STA Mask         */

#define CLK_STOPACK_CANFD1STA_Pos        (1)                                               /*!< CLK_T::STOPACK: CANFD1STA Position     */
#define CLK_STOPACK_CANFD1STA_Msk        (0x1ul << CLK_STOPACK_CANFD1STA_Pos)              /*!< CLK_T::STOPACK: CANFD1STA Mask         */

#define CLK_STOPACK_CANFD2STA_Pos        (2)                                               /*!< CLK_T::STOPACK: CANFD2STA Position     */
#define CLK_STOPACK_CANFD2STA_Msk        (0x1ul << CLK_STOPACK_CANFD2STA_Pos)              /*!< CLK_T::STOPACK: CANFD2STA Mask         */

#define CLK_STOPACK_CANFD3STA_Pos        (3)                                               /*!< CLK_T::STOPACK: CANFD3STA Position     */
#define CLK_STOPACK_CANFD3STA_Msk        (0x1ul << CLK_STOPACK_CANFD3STA_Pos)              /*!< CLK_T::STOPACK: CANFD3STA Mask         */

/**@}*/ /* CLK_CONST */
/**@}*/ /* end of CLK register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __CLK_REG_H__ */
