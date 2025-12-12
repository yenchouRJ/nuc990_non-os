/**************************************************************************//**
 * @file     sys_reg.h
 * @version  V1.00
 * @brief    SYS register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __SYS_REG_H__
#define __SYS_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/** @addtogroup REGISTER Control Register

  @{

*/


/*---------------------- System Manger Controller -------------------------*/
/**
    @addtogroup SYS System Manger Controller(SYS)
    Memory Mapped Structure for SYS Controller
@{ */

typedef struct
{


/**
 * @var SYS_T::PDID
 * Offset: 0x00  Product and Device Identifier Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[7:0]   |PID       |Product ID
 * |        |          |This field stores the 8-bit Product ID loaded from OTP memory.
 * |[27:24] |DID       |Device ID
 * |        |          |This field stores the 4-bit Device ID loaded from OTP memory.
 * @var SYS_T::PWRON
 * Offset: 0x04  Power-on Setting Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[1:0]   |BTSSEL    |Boot Source Selection (Read Only)
 * |        |          |When pin nRESET transited from low to high, the value of pin PG[1:0] latched to BTSSEL.
 * |        |          |00= Boot from USB.
 * |        |          |01= Boot from SD/eMMC.
 * |        |          |10= Boot from NAND Flash.
 * |        |          |11= Boot from SPI Flash.
 * |[2]     |PINSECBTEN|Secure Boot Enabled/Disable Selection by Pin PG.2 (Read Only)
 * |        |          |When {SECBTDEVMD, SECBTEN} is 01, the value of pin PG.2 latched to PINSECBTEN during pin nRESET transited from low to high.
 * |        |          |0 = Secure Boot Enabled.
 * |        |          |1 = Secure Boot Disabled.
 * |[3]     |WDTON     |Watchdog Timer ON/OFF Selection (Read Only)
 * |        |          |When pin nRESET transited from low to high, the value of pin PG.3 latched to WDTON.
 * |        |          |0 = After power-on, WDT Disabled.
 * |        |          |1 = After power-on WDT Enabled.
 * |[4]     |JTAGSEL   |JTAG Interface Selection (Read Only)
 * |        |          |When pin nRESET transited from low to high, the value of pin PG.4 latched to JTAGSEL.
 * |        |          |0 = Pin PA[6:2] used as JTAG interface.
 * |        |          |1 = Pin PG[15:11] used as JTAG interface.
 * |[5]     |URDBGON   |UART 0 Debug Message Output ON/OFF Selection (Read Only)
 * |        |          |When pin nRESET transited from low to high, the value of pin PG.5 latched to URDBGON.
 * |        |          |0= UART 0 debug message output ON and pin PF[12:11] used as the UART0 functionality.
 * |        |          |1= UART 0 debug message output OFF.
 * |[7:6]   |NPAGESEL  |NAND Flash Page Size Selection (Read Only)
 * |        |          |When pin nRESET transited from low to high, the value of pin PG[7:6] latched to NPAGESEL.
 * |        |          |00= NAND Flash page size is 2KB.
 * |        |          |01= NAND Flash page size is 4KB.
 * |        |          |10= NAND Flash page size is 8KB.
 * |        |          |11= Ignore power-on setting.
 * |[9:8]   |MISCCFG   |Miscellaneous Configuration (Read Only)
 * |        |          |When pin nRESET transited from low to high, the value of pin PG[9:8] latched to MISCCFG.
 * |        |          |When BTSSEL = 01, Boot from SD/eMMC, the MISCCFG defines the SD0/eMMC0 or SD1/eMMC1 used as the booting source.
 * |        |          |00 = SD1/eMMC1 (GPB group) used as the booting source.
 * |        |          |01 = SD1/eMMC1 (GPF group) used as the booting source.
 * |        |          |10 = SD0/eMMC0 (GPH group) used as the booting source.
 * |        |          |11 = SD0/eMMC0 (GPC group) used as the booting source.
 * |        |          |When BTSSEL = 10, Boot from NAND Flash, the MISCCFG defines the ECC type.
 * |        |          |00 = No ECC.
 * |        |          |01 = ECC is BCH T12.
 * |        |          |10 = ECC is BCH T24.
 * |        |          |11 = Ignore power-on setting.
 * |        |          |When BTSEL = 11, Boot from SPI Flash, the MISCCFG defines the SPI Flash type and data width.
 * |        |          |00 = SPI-NAND Flash with 4-bit mode.
 * |        |          |01 = SPI-NAND Flash with 1-bit mode.
 * |        |          |10 = SPI-NOR Flash with 4-bit mode.
 * |        |          |11 = SPI-NOR Flash with 1-bit mode.
 * |[10]    |SECBTEN   |Secure Boot Enabled/Disable Control Bit (Read Only)
 * |        |          |This bit works with SECBTDEVMD to Enable/Disable secure boot.
 * |        |          |{SECBTDEVMD, SECBTEN}
 * |        |          |00 = Secure Boot Disabled.
 * |        |          |01 = Secure Boot Enabled/Disabled controlled by pin PG[2].
 * |        |          |10 = Secure Boot Disabled.
 * |        |          |11 = Secure Boot Enabled.
 * |[11]    |SECBTDEVMD|Secure Boot Development Mode Control Bit (Read Only)
 * |        |          |This bit works with SECBTEN to Enable/Disable secure boot.
 * |        |          |{SECBTDEVMD, SECBTEN}
 * |        |          |00 = Secure Boot Disabled.
 * |        |          |01 = Secure Boot Enabled/Disabled controlled by pin PG[2].
 * |        |          |10 = Secure Boot Disabled.
 * |        |          |11 = Secure Boot Enabled.
 * |[15]    |PWRONSRC  |Power On Setting Source Selelection Control Bit (Read Only)
 * |        |          |This bit control the power on setting value comes from power on setting pin or OTP content.
 * |        |          |0 = Power on setting values come from pin. (Default)
 * |        |          |1 = Power on setting values come from OTP.
 * |[16]    |USBID     |USB ID Pin Status
 * |        |          |0 = USB port 0 used as a USB device.
 * |        |          |1 = USB port 0 used as a USB host.
 * |[31:28] |BTDELAY   |BOOT Delay (Read Only)
 * |        |          |0000 = no delay.
 * |        |          |0001 = 10 ms.
 * |        |          |0010 = 25 ms.
 * |        |          |0011 = 50 ms.
 * |        |          |0100 = 80 ms.
 * |        |          |0101 = 125 ms.
 * |        |          |0110 = 160 ms.
 * |        |          |0111 = 200 ms.
 * |        |          |1000 = 300 ms.
 * |        |          |1001 = 500 ms.
 * |        |          |1010 = 750 ms.
 * |        |          |1011 = 1000 ms.
 * |        |          |1100 = 1500 ms.
 * |        |          |1101 = 2000 ms.
 * |        |          |1110 = 2500 ms.
 * |        |          |1111 = 3500 ms.
 * @var SYS_T::LVRDCR
 * Offset: 0x20  Low Voltage Reset & Detect Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |LVR_EN    |Low Voltage Reset Enable Bit
 * |        |          |0 = Low voltage reset function Disabled.
 * |        |          |1 = Low voltage reset function Enabled.
 * |[8]     |LVD_EN    |Low Voltage Detect Enable Bit
 * |        |          |0 = Low voltage detect function Disabled.
 * |        |          |1 = Low voltage detect function Enabled.
 * |[9]     |LVD_SEL   |Low Voltage Detect Threshold Selection
 * |        |          |0 = Low voltage detection level is 2.6V.
 * |        |          |1 = Low voltage detection level is 2.8V.
 * @var SYS_T::MISCFCR
 * Offset: 0x30  Miscellaneous Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[4]     |IBRACCEN  |ARM926EJ-S Core IBR Access Enable (Read Only)
 * |        |          |When IBRACCEN1=1, the ARM926EJ-S core read IBR (Internal Boot ROM) is enabled while IBRACCEN1=0, the ARM926EJ-S core read IBR (Internal Boot ROM) is disabled.
 * |        |          |0 = ARM926EJ-S core booting sequence completed and read IBR Disabled.
 * |        |          |1 = ARM926EJ-S core booting sequence is on-going and read IBR Enabled..
 * |[5]     |BOOTISRC  |Boot Image Source (Read Only)
 * |        |          |0 = Boot from header 0.
 * |        |          |1 = Boot from header 1.
 * |[8]     |WDTRSTEN  |WatchDog Timer Reset Connection Enable Bit
 * |        |          |This bit is use to enable the function that connect watch-dog timer reset to nRESET pin
 * |        |          |If this bit is enabled, the watch-dog timer reset is connected to nRESET pin internally
 * |        |          |0 = Watch-dog timer reset not connected to nRESET pin internally.
 * |        |          |1 = Watch-dog timer reset connected to nRESET pin internally.
 * |[9]     |HDSPUEN   |HDS Pin Internal Pull-up Enable Bit
 * |        |          |0 = HDS pin internal pull-up resister Disabled.
 * |        |          |1 = HDS pin internal pull-up resister Enabled.
 * |[10]    |EADCFUNCEN|EADC Controller Function Enable Bit
 * |        |          |0 = EADC controller function Disabled and SAR-ADC controlled by ADC controller.
 * |        |          |1 = EADC controller function Enabled and SAR-ADC controlled by EADC controller.
 * |[11]    |USRHDSEN  |User Configurable USB Host Device Role Selection Enable Bit
 * |        |          |0 = USB host/device role selection decided by HDS pin.
 * |        |          |1 = USB host/device role selection decided by USBID (SYS_PWRON[16]).
 * |[12]    |GPIOLBEN  |GPIO Pin Loop-back Enable Bit
 * |        |          |0 = GPIO input status didnu2019t reflect pin status if the GPIO configured as functional pin.
 * |        |          |1 = GPIO input status did reflect pin status even if the GPIO configured as functional pin.
 * |[13]    |SELFTEST  |Self-test Mode Enable Bit
 * |        |          |0 = Self-Test mode Disabled.
 * |        |          |1 = Self-Test mode Enabled.
 * @var SYS_T::MISCIER
 * Offset: 0x40  Miscellaneous Interrupt Enable Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |LVD_IEN   |Low Voltage Detect Interrupt Enable Bit
 * |        |          |0 = Low voltage detect interrupt Disabled.
 * |        |          |1 = Low voltage detect interrupt Enabled.
 * |[1]     |USBIDC_IEN|USB0_ID Pin Status Change Interrupt Enable Bit
 * |        |          |0 = HDS status change interrupt Disabled.
 * |        |          |1 = HDS status change interrupt Enabled.
 * @var SYS_T::MISCISR
 * Offset: 0x44  Miscellaneous Interrupt Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |LVD_IS    |Low Voltage Detect Interrupt Status
 * |        |          |0 = No low voltage event.
 * |        |          |1 = Low voltage event detected.
 * |[1]     |USBIDC_IS |USB0_ID Pin State Change Interrupt Status
 * |        |          |0 = USB0_ID state didnu2019t change.
 * |        |          |1 = USB0_ID state changed from low to high or from high to low.
 * |[17]    |USB0_IDS  |USB0_ID Status
 * |        |          |0 = USB port 0 used as a USB device port.
 * |        |          |1 = USB port 0 used as a USB host port.
 * @var SYS_T::AHBIPRST
 * Offset: 0x60  AHB IP Reset Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |CHIPRST   |Chip On-Shot Reset Enable Bit (Write Protect)
 * |        |          |This bit is used to generate a whole chip reset pulse.
 * |        |          |When set this bit high, reset controller generates a 6 system clock long reset pulse to rseet whole chip
 * |        |          |After the reset completed, this bit will be clear to low automatically.
 * |        |          |0 = Chip one-shot reset Disabled.
 * |        |          |1 = Chip one-shot reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[2]     |CPURST    |CPU Pulse Reset Enable Bit (Write Protect)
 * |        |          |This bit is used to generate a reset pulse to Arm926EJ-S CPU.
 * |        |          |When set this bit high, reset controller generates a 6 system clock long reset pulse to Arm926EJ-S CPU
 * |        |          |After the reset completed, this bit will be clear to low automatically.
 * |        |          |0 = CPU pulse reset Disabled.
 * |        |          |1 = CPU pulse reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[3]     |EBIRST    |EBI Reset Enable Bit (Write Protect)
 * |        |          |Set this bit to 1 will generate a reset signal to the EBI controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = EBI reset Disabled.
 * |        |          |1 = EBI reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[4]     |PDMA0RST  |PDMA0 Reset Enable Bit (Write Protect)
 * |        |          |Set this bit to 1 will generate a reset signal to the PDMA 0 controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = PDMA 0 reset Disabled.
 * |        |          |1 = PDMA 0 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[5]     |PDMA1RST  |PDMA1 Reset Enable Bit (Write Protect)
 * |        |          |Set this bit to 1 will generate a reset signal to the PDMA 1 controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = PDMA 1 reset Disabled.
 * |        |          |1 = PDMA 1 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[6]     |SDICRST   |SDRAM Controller Reset Enable Bit (Write Protect)
 * |        |          |Set this bit to 1 will generate a reset signal to the SDRAM controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = SDRAM controller reset Disabled.
 * |        |          |1 = SDRAM Controller reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[7]     |GPIORST   |GPIO Reset Enable Bit (Write Protect)
 * |        |          |Set this bit to 1 will generate a reset signal to the GPIO controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = GPIO reset Disabled.
 * |        |          |1 = GPIO reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[8]     |I2SRST    |I2S Controller Reset Enable Bit (Write Protect)
 * |        |          |Set this bit to 1 will generate a reset signal to the I2S controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = I2S controller reset Disabled.
 * |        |          |1 = I2S controller reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[16]    |EMAC0RST  |Ethernet MAC 0 Reset Enable Bit (Write Protect)
 * |        |          |Set this bit to 1 will generate a reset signal to the Ethernet MAC 0 controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = Ethernet MAC 0 reset Disabled.
 * |        |          |1 = Ethernet MAC 0 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[17]    |EMAC1RST  |Ethernet MAC 1 Reset Enable Bit (Write Protect)
 * |        |          |Set this bit to 1 will generate a reset signal to the Ethernet MAC 1 controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = Ethernet MAC 1 reset Disabled.
 * |        |          |1 = Ethernet MAC 1 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[18]    |HSUSBHRST |High-Speed USB Host Controller Reset Enable Bit (Write Protect)
 * |        |          |Set this bit to 1 will generate a reset signal to the High-Speed USB host controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = High-Speed USB host controller (EHCI/OHCI) reset Disabled.
 * |        |          |1 = High-Speed USB host controller (EHCI/OHCI) reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[19]    |HSUSBDRST |High-Speed USB Device Controller Reset Enable Bit (Write Protect)
 * |        |          |Set this bit to 1 will generate a reset signal to the High-Speed USB device controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = High-Speed USB device controller reset Disabled.
 * |        |          |1 = High-Speed USB device controller reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[20]    |NDNDRST   |NAND Flash Controller Reset Enable Bit (Write Protect)
 * |        |          |Set this bit to 1 will generate a reset signal to the NAND Flash controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = NAND Flash controller reset Disabled.
 * |        |          |1 = NAND Flash controller reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[21]    |KSRST     |KSRST Controller Reset (Write Protect)
 * |        |          |Set this bit to 1 will generate a reset signal to the KeyStore controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = KSRST controller normal operation.
 * |        |          |1 = KSRST controller reset.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[22]    |OTPRST    |OTPRST Controller Reset (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the OTP controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = OTPRST controller normal operation.
 * |        |          |1 = OTPRST controller reset.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[23]    |CRYPTORST |Cryptographic Accelerator Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the Cryptographic Accelerator
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = Cryptographic Accelerator reset Disabled.
 * |        |          |1 = Cryptographic Accelerator reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[24]    |SDH0RST   |SDIO Controller 0 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the SDIO 0 controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = SDIO controller 0 reset Disabled.
 * |        |          |1 = SDIO controller 0 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[25]    |SDH1RST   |SDIO Controller 1 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the SDIO 1 controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = SDIO controller 1 reset Disabled.
 * |        |          |1 = SDIO controller 1 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[28]    |CANFD0RST |CAN FD 0 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the CAN FD 0
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = CAN FD 0 reset Disabled.
 * |        |          |1 = CAN FD 0 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[29]    |CANFD1RST |CAN FD 1 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the CAN FD 1
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = CAN FD 1 reset Disabled.
 * |        |          |1 = CAN FD 1 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[30]    |CANFD2RST |CAN FD 2 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the CAN FD 2
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = CAN FD 2 reset Disabled.
 * |        |          |1 = CAN FD 2 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[31]    |CANFD3RST |CAN FD 3 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the CAN FD 3
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = CAN FD 3 reset Disabled.
 * |        |          |1 = CAN FD 3 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * @var SYS_T::APBIPRST0
 * Offset: 0x64  APB IP Reset Control Register 0
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[11]    |TIMER3RST |TIMER 3 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the TIMER 3
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = TIMER 3 reset Disabled.
 * |        |          |1 = TIMER 3 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[12]    |TIMER4RST |TIMER 4 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the TIMER 4
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = TIMER 4 reset Disabled.
 * |        |          |1 = TIMER 4 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[13]    |TIMER5RST |TIMER 5 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the TIMER 5
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = TIMER 5 reset Disabled.
 * |        |          |1 = TIMER 5 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[16]    |UART0RST  |UART 0 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the UART 0
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = UART 0 reset Disabled.
 * |        |          |1 = UART 0 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[17]    |UART1RST  |UART 1 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the UART 1
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = UART 1 reset Disabled.
 * |        |          |1 = UART 1 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[18]    |UART2RST  |UART 2 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the UART 2
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = UART 2 reset Disabled.
 * |        |          |1 = UART 2 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[19]    |UART3RST  |UART 3 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the UART 3
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = UART 3 reset Disabled.
 * |        |          |1 = UART 3 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[20]    |UART4RST  |UART 4 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the UART 4
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = UART 4 reset Disabled.
 * |        |          |1 = UART 4 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[21]    |UART5RST  |UART 5 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the UART 5
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = UART 5 reset Disabled.
 * |        |          |1 = UART 5 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[22]    |UART6RST  |UART 6 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the UART 6
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = UART 6 reset Disabled.
 * |        |          |1 = UART 6 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[23]    |UART7RST  |UART 7 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the UART 7
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = UART 7 reset Disabled.
 * |        |          |1 = UART 7 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[24]    |UART8RST  |UART 8 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the UART 9
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = UART 8 reset Disabled.
 * |        |          |1 = UART 8 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[25]    |UART9RST  |UART 9 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the UART 9
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = UART 9 reset Disabled.
 * |        |          |1 = UART 9 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * @var SYS_T::APBIPRST1
 * Offset: 0x68  APB IP Reset Control Register 1
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |I2C0RST   |I2C 0 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the I2C 0
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = I2C 0 reset Disabled.
 * |        |          |1 = I2C 0 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[1]     |I2C1RST   |I2C 1 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the I2C 1
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = I2C 1 reset Disabled.
 * |        |          |1 = I2C 1 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[2]     |I2C2RST   |I2C 1 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the I2C 2
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = I2C 2 reset Disabled.
 * |        |          |1 = I2C 2 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[3]     |I2C3RST   |I2C 3 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the I2C 3
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = I2C 3 reset Disabled.
 * |        |          |1 = I2C 3 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[4]     |SPI0RST   |SPI 1 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the SPI 0
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = SPI 0 reset Disabled.
 * |        |          |1 = SPI 0 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[5]     |SPI1RST   |SPI 1 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the SPI 1
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = SPI 1 reset Disabled.
 * |        |          |1 = SPI 1 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[6]     |SPI2RST   |SPI 2 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the SPI 2
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = SPI 2 reset Disabled.
 * |        |          |1 = SPI 2 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[7]     |SPI3RST   |SPI 3 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the SPI 3
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = SPI 3 reset Disabled.
 * |        |          |1 = SPI 3 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[8]     |CAN0RST   |CAN 0 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the CAN 0
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = CAN 0 reset Disabled.
 * |        |          |1 = CAN 0 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[9]     |CAN1RST   |CAN 1 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the CAN 1
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = CAN 1 reset Disabled.
 * |        |          |1 = CAN 1 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[10]    |CAN2RST   |CAN 2 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the CAN 2
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = CAN 2 reset Disabled.
 * |        |          |1 = CAN 2 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[11]    |CAN3RST   |CAN 3 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the CAN 3
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = CAN 3 reset Disabled.
 * |        |          |1 = CAN 3 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[24]    |ADCRST    |ADC Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the ADC controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = ADC reset Disabled.
 * |        |          |1 = ADC reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[25]    |EADCRST   |EADC Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the EADC controller
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = EADC reset Disabled.
 * |        |          |1 = EADC reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[26]    |BPWM0RST  |BPWM0 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the BPWM 0
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = BPWM 0 reset Disabled.
 * |        |          |1 = BPWM 0 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[27]    |BPWM1RST  |BPWM1 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the BPWM 1
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = BPWM 1 reset Disabled.
 * |        |          |1 = BPWM 1 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[30]    |SMC0RST   |SMC 0 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the SMC 0
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = SMC 0 reset Disabled.
 * |        |          |1 = SMC 0 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * |[31]    |SMC1RST   |SMC 1 Reset Enable Bit (Write Protect)
 * |        |          |Setting this bit to 1 will generate a reset signal to the SMC 1
 * |        |          |User needs to set this bit to 0 to release from the reset state.
 * |        |          |0 = SMC 1 reset Disabled.
 * |        |          |1 = SMC 1 reset Enabled.
 * |        |          |Note: This bit is write protected. Refer to the SYS_REGLKCTL register.
 * @var SYS_T::RSTSTS
 * Offset: 0x6C  Reset Source Active Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |PORRSTS   |Chip Reset by POR Status
 * |        |          |0 = No reset from POR.
 * |        |          |1 = POR had issued reset signal to reset the chip.
 * |[1]     |PINRSTS   |Chip Reset by NRESET Pin Status
 * |        |          |0 = No reset from nRESET pin.
 * |        |          |1 = nRESET pin had issued reset signal to reset the chip.
 * |[2]     |LVRRSTS   |Chip Reset by LVRD Status
 * |        |          |0 = No reset from LVRD.
 * |        |          |1 = LVRD had issued reset signal to reset the chip.
 * |[3]     |CHIPRSTS  |Chip Reset by CHIP Status
 * |        |          |0 = No reset from CHIP (AHBIPRST[0]).
 * |        |          |1 = CHIP (AHBIPRST[0]) has been high to reset CPU.
 * |[4]     |CPURSTS   |CPU Reset by CPU_LVL or CPU_PLS Status
 * |        |          |0 = No CPU reset from CPU_LVL (AHBIPRST[1]) or CPU_PLS (AHBIPRST[2]).
 * |        |          |1 = CPU_LVL (AHBIPRST[1]) or CPU_PLS (AHBIPRST[2]) has been high to reset the CPU.
 * |[5]     |WDTRSTS   |Chip Reset by Watchdog Timer Status
 * |        |          |0 = No reset from watchdog timer.
 * |        |          |1 = Watchdog timer had issued reset signal to reset the chip.
 * |[6]     |WWDTRSTS  |Chip Reset by Window-Watchdog Timer Status
 * |        |          |0 = No reset from window watchdog timer.
 * |        |          |1 = Window watchdog timer had issued reset signal to reset the chip.
 * @var SYS_T::GPA_MFPL
 * Offset: 0x70  GPIOA Low Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPA0  |Pin PA.0 Multi-function Pin Selection
 * |[7:4]   |MFP_GPA1  |Pin PA.1 Multi-function Pin Selection
 * |[11:8]  |MFP_GPA2  |Pin PA.2 Multi-function Pin Selection
 * |[15:12] |MFP_GPA3  |Pin PA.3 Multi-function Pin Selection
 * |[19:16] |MFP_GPA4  |Pin PA.4 Multi-function Pin Selection
 * |[23:20] |MFP_GPA5  |Pin PA.5 Multi-function Pin Selection
 * |[27:24] |MFP_GPA6  |Pin PA.6 Multi-function Pin Selection
 * |[31:28] |MFP_GPA7  |Pin PA.7 Multi-function Pin Selection
 * @var SYS_T::GPA_MFPH
 * Offset: 0x74  GPIOA High Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPA8  |Pin PA.8 Multi-function Pin Selection
 * |[7:4]   |MFP_GPA9  |Pin PA.9 Multi-function Pin Selection
 * |[11:8]  |MFP_GPA10 |Pin PA.10 Multi-function Pin Selection
 * |[15:12] |MFP_GPA11 |Pin PA.11 Multi-function Pin Selection
 * |[19:16] |MFP_GPA12 |Pin PA.12 Multi-function Pin Selection
 * |[23:20] |MFP_GPA13 |Pin PA.13 Multi-function Pin Selection
 * |[27:24] |MFP_GPA14 |Pin PA.14 Multi-function Pin Selection
 * |[31:28] |MFP_GPA15 |Pin PA.15 Multi-function Pin Selection
 * @var SYS_T::GPB_MFPL
 * Offset: 0x78  GPIOB Low Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPB0  |Pin PB.0 Multi-function Pin Selection
 * |[7:4]   |MFP_GPB1  |Pin PB.1 Multi-function Pin Selection
 * |[11:8]  |MFP_GPB2  |Pin PB.2 Multi-function Pin Selection
 * |[15:12] |MFP_GPB3  |Pin PB.3 Multi-function Pin Selection
 * |[19:16] |MFP_GPB4  |Pin PB.4 Multi-function Pin Selection
 * |[23:20] |MFP_GPB5  |Pin PB.5 Multi-function Pin Selection
 * |[27:24] |MFP_GPB6  |Pin PB.6 Multi-function Pin Selection
 * |[31:28] |MFP_GPB7  |Pin PB.7 Multi-function Pin Selection
 * @var SYS_T::GPB_MFPH
 * Offset: 0x7C  GPIOB High Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPB8  |Pin PB.8 Multi-function Pin Selection
 * |[7:4]   |MFP_GPB9  |Pin PB.9 Multi-function Pin Selection
 * |[11:8]  |MFP_GPB10 |Pin PB.10 Multi-function Pin Selection
 * |[15:12] |MFP_GPB11 |Pin PB.11 Multi-function Pin Selection
 * |[19:16] |MFP_GPB12 |Pin PB.12 Multi-function Pin Selection
 * |[23:20] |MFP_GPB13 |Pin PB.13 Multi-function Pin Selection
 * @var SYS_T::GPC_MFPL
 * Offset: 0x80  GPIOC Low Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPC0  |Pin PC.0 Multi-function Pin Selection
 * |[7:4]   |MFP_GPC1  |Pin PC.1 Multi-function Pin Selection
 * |[11:8]  |MFP_GPC2  |Pin PC.2 Multi-function Pin Selection
 * |[15:12] |MFP_GPC3  |Pin PC.3 Multi-function Pin Selection
 * |[19:16] |MFP_GPC4  |Pin PC.4 Multi-function Pin Selection
 * |[23:20] |MFP_GPC5  |Pin PC.5 Multi-function Pin Selection
 * |[27:24] |MFP_GPC6  |Pin PC.6 Multi-function Pin Selection
 * |[31:28] |MFP_GPC7  |Pin PC.7 Multi-function Pin Selection
 * @var SYS_T::GPC_MFPH
 * Offset: 0x84  GPIOC High Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPC8  |Pin PC.8 Multi-function Pin Selection
 * |[7:4]   |MFP_GPC9  |Pin PC.9 Multi-function Pin Selection
 * |[11:8]  |MFP_GPC10 |Pin PC.10 Multi-function Pin Selection
 * |[15:12] |MFP_GPC11 |Pin PC.11 Multi-function Pin Selection
 * |[19:16] |MFP_GPC12 |Pin PC.12 Multi-function Pin Selection
 * |[23:20] |MFP_GPC13 |Pin PC.13 Multi-function Pin Selection
 * |[27:24] |MFP_GPC14 |Pin PC.14 Multi-function Pin Selection
 * |[31:28] |MFP_GPC15 |Pin PC.15 Multi-function Pin Selection
 * @var SYS_T::GPD_MFPL
 * Offset: 0x88  GPIOD Low Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPD0  |Pin PD.0 Multi-function Pin Selection
 * |[7:4]   |MFP_GPD1  |Pin PD.1 Multi-function Pin Selection
 * |[11:8]  |MFP_GPD2  |Pin PD.2 Multi-function Pin Selection
 * |[15:12] |MFP_GPD3  |Pin PD.3 Multi-function Pin Selection
 * |[19:16] |MFP_GPD4  |Pin PD.4 Multi-function Pin Selection
 * |[23:20] |MFP_GPD5  |Pin PD.5 Multi-function Pin Selection
 * |[27:24] |MFP_GPD6  |Pin PD.6 Multi-function Pin Selection
 * |[31:28] |MFP_GPD7  |Pin PD.7 Multi-function Pin Selection
 * @var SYS_T::GPD_MFPH
 * Offset: 0x8C  GPIOD High Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPD8  |Pin PD.8 Multi-function Pin Selection
 * |[7:4]   |MFP_GPD9  |Pin PD.9 Multi-function Pin Selection
 * |[11:8]  |MFP_GPD10 |Pin PD.10 Multi-function Pin Selection
 * |[15:12] |MFP_GPD11 |Pin PD.11 Multi-function Pin Selection
 * |[19:16] |MFP_GPD12 |Pin PD.12 Multi-function Pin Selection
 * |[23:20] |MFP_GPD13 |Pin PD.13 Multi-function Pin Selection
 * |[27:24] |MFP_GPD14 |Pin PD.14 Multi-function Pin Selection
 * |[31:28] |MFP_GPD15 |Pin PD.15 Multi-function Pin Selection
 * @var SYS_T::GPE_MFPL
 * Offset: 0x90  GPIOE Low Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPE0  |Pin PE.0 Multi-function Pin Selection
 * |[7:4]   |MFP_GPE1  |Pin PE.1 Multi-function Pin Selection
 * |[11:8]  |MFP_GPE2  |Pin PE.2 Multi-function Pin Selection
 * |[15:12] |MFP_GPE3  |Pin PE.3 Multi-function Pin Selection
 * |[19:16] |MFP_GPE4  |Pin PE.4 Multi-function Pin Selection
 * |[23:20] |MFP_GPE5  |Pin PE.5 Multi-function Pin Selection
 * |[27:24] |MFP_GPE6  |Pin PE.6 Multi-function Pin Selection
 * |[31:28] |MFP_GPE7  |Pin PE.7 Multi-function Pin Selection
 * @var SYS_T::GPE_MFPH
 * Offset: 0x94  GPIOE High Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPE8  |Pin PE.8 Multi-function Pin Selection
 * |[7:4]   |MFP_GPE9  |Pin PE.9 Multi-function Pin Selection
 * |[11:8]  |MFP_GPE10 |Pin PE.10 Multi-function Pin Selection
 * |[15:12] |MFP_GPE11 |Pin PE.11 Multi-function Pin Selection
 * |[19:16] |MFP_GPE12 |Pin PE.12 Multi-function Pin Selection
 * @var SYS_T::GPF_MFPL
 * Offset: 0x98  GPIOF Low Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPF0  |Pin PF.0 Multi-function Pin Selection
 * |[7:4]   |MFP_GPF1  |Pin PF.1 Multi-function Pin Selection
 * |[11:8]  |MFP_GPF2  |Pin PF.2 Multi-function Pin Selection
 * |[15:12] |MFP_GPF3  |Pin PF.3 Multi-function Pin Selection
 * |[19:16] |MFP_GPF4  |Pin PF.4 Multi-function Pin Selection
 * |[23:20] |MFP_GPF5  |Pin PF.5 Multi-function Pin Selection
 * |[27:24] |MFP_GPF6  |Pin PF.6 Multi-function Pin Selection
 * |[31:28] |MFP_GPF7  |Pin PF.7 Multi-function Pin Selection
 * @var SYS_T::GPF_MFPH
 * Offset: 0x9C  GPIOF High Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPF8  |Pin PF.8 Multi-function Pin Selection
 * |[7:4]   |MFP_GPF9  |Pin PF.9 Multi-function Pin Selection
 * |[11:8]  |MFP_GPF10 |Pin PF.10 Multi-function Pin Selection
 * |[15:12] |MFP_GPF11 |Pin PF.11 Multi-function Pin Selection
 * |[19:16] |MFP_GPF12 |Pin PF.12 Multi-function Pin Selection
 * @var SYS_T::GPG_MFPL
 * Offset: 0xA0  GPIOG Low Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPG0  |Pin PG.0 Multi-function Pin Selection
 * |[7:4]   |MFP_GPG1  |Pin PG.1 Multi-function Pin Selection
 * |[11:8]  |MFP_GPG2  |Pin PG.2 Multi-function Pin Selection
 * |[15:12] |MFP_GPG3  |Pin PG.3 Multi-function Pin Selection
 * |[19:16] |MFP_GPG4  |Pin PG.4 Multi-function Pin Selection
 * |[23:20] |MFP_GPG5  |Pin PG.5 Multi-function Pin Selection
 * |[27:24] |MFP_GPG6  |Pin PG.6 Multi-function Pin Selection
 * |[31:28] |MFP_GPG7  |Pin PG.7 Multi-function Pin Selection
 * @var SYS_T::GPG_MFPH
 * Offset: 0xA4  GPIOG High Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPG8  |Pin PG.8 Multi-function Pin Selection
 * |[7:4]   |MFP_GPG9  |Pin PG.9 Multi-function Pin Selection
 * |[11:8]  |MFP_GPG10 |Pin PG.10 Multi-function Pin Selection
 * |[15:12] |MFP_GPG11 |Pin PG.11 Multi-function Pin Selection
 * |[19:16] |MFP_GPG12 |Pin PG.12 Multi-function Pin Selection
 * |[23:20] |MFP_GPG13 |Pin PG.13 Multi-function Pin Selection
 * |[27:24] |MFP_GPG14 |Pin PG.14 Multi-function Pin Selection
 * |[31:28] |MFP_GPG15 |Pin PG.15 Multi-function Pin Selection
 * @var SYS_T::GPH_MFPL
 * Offset: 0xA8  GPIOH Low Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPH0  |Pin PH.0 Multi-function Pin Selection
 * |[7:4]   |MFP_GPH1  |Pin PH.1 Multi-function Pin Selection
 * |[11:8]  |MFP_GPH2  |Pin PH.2 Multi-function Pin Selection
 * |[15:12] |MFP_GPH3  |Pin PH.3 Multi-function Pin Selection
 * |[19:16] |MFP_GPH4  |Pin PH.4 Multi-function Pin Selection
 * |[23:20] |MFP_GPH5  |Pin PH.5 Multi-function Pin Selection
 * |[27:24] |MFP_GPH6  |Pin PH.6 Multi-function Pin Selection
 * |[31:28] |MFP_GPH7  |Pin PH.7 Multi-function Pin Selection
 * @var SYS_T::GPH_MFPH
 * Offset: 0xAC  GPIOH High Byte Multiple Function Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |MFP_GPH8  |Pin PH.8 Multi-function Pin Selection
 * |[7:4]   |MFP_GPH9  |Pin PH.9 Multi-function Pin Selection
 * @var SYS_T::DDR_DSCTL
 * Offset: 0xF0  DDR I/O Driving Strength Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[1:0]   |CLK_DS    |DDR Clock I/O Driving Strength Selection
 * |        |          |This bit controls the driving strength for DDR I/O used as clock.
 * |        |          |00 = Reserved.
 * |        |          |01 = Reduced Strength.
 * |        |          |10 = Reserved.
 * |        |          |11 = Full Strength.
 * |[3:2]   |CTRL_DS   |DDR Control I/O Driving Strength Selection
 * |        |          |This bit controls the driving strength for DDR I/O used as control signals.
 * |        |          |00 = Reserved.
 * |        |          |01 = Reduced Strength.
 * |        |          |10 = Reserved.
 * |        |          |11 = Full Strength.
 * |[5:4]   |ADDR_DS   |DDR Address I/O Driving Strength Selection
 * |        |          |This bit controls the driving strength for DDR I/O used as address.
 * |        |          |00 = Reserved.
 * |        |          |01 = Reduced Strength.
 * |        |          |10 = Reserved.
 * |        |          |11 = Full Strength.
 * |[7:6]   |DATA_DS   |DDR Data I/O Driving Strength Selection
 * |        |          |This bit controls the driving strength for DDR I/O used as data.
 * |        |          |00 = Reserved.
 * |        |          |01 = Reduced Strength.
 * |        |          |10 = Reserved.
 * |        |          |11 = Full Strength.
 * @var SYS_T::GPBL_DSCTL
 * Offset: 0xF4  GPIOB Low Byte Driving Strength Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |DS_GPB0   |Pin PB.0 Driving Strength Selection
 * |        |          |This field controls the pin PB.0 driving strength
 * |        |          |000 = Pin PB.0 driving strength is 2.2mA.
 * |        |          |001 = Pin PB.0 driving strength is 6.5mA.
 * |        |          |010 = Pin PB.0 driving strength is 8.7mA.
 * |        |          |011 = Pin PB.0 driving strength is 13.0mA.
 * |        |          |100 = Pin PB.0 driving strength is 15.2mA.
 * |        |          |101 = Pin PB.0 driving strength is 19.5mA.
 * |        |          |110 = Pin PB.0 driving strength is 21.7mA.
 * |        |          |111 = Pin PB.0 driving strength is 26.1mA.
 * |        |          |Others = Reserved.
 * |[7:4]   |DS_GPB1   |Pin PB.1 Driving Strength Selection
 * |        |          |This field controls the pin PB.1 driving strength
 * |        |          |000 = Pin PB.1 driving strength is 2.2mA.
 * |        |          |001 = Pin PB.1 driving strength is 6.5mA.
 * |        |          |010 = Pin PB.1 driving strength is 8.7mA.
 * |        |          |011 = Pin PB.1 driving strength is 13.0mA.
 * |        |          |100 = Pin PB.1 driving strength is 15.2mA.
 * |        |          |101 = Pin PB.1 driving strength is 19.5mA.
 * |        |          |110 = Pin PB.1 driving strength is 21.7mA.
 * |        |          |111 = Pin PB.1 driving strength is 26.1mA.
 * |        |          |Others = Reserved.
 * |[11:8]  |DS_GPB2   |Pin PB.2 Driving Strength Selection
 * |        |          |This field controls the pin PB.2 driving strength
 * |        |          |000 = Pin PB.2 driving strength is 2.2mA.
 * |        |          |001 = Pin PB.2 driving strength is 6.5mA.
 * |        |          |010 = Pin PB.2 driving strength is 8.7mA.
 * |        |          |011 = Pin PB.2 driving strength is 13.0mA.
 * |        |          |100 = Pin PB.2 driving strength is 15.2mA.
 * |        |          |101 = Pin PB.2 driving strength is 19.5mA.
 * |        |          |110 = Pin PB.2 driving strength is 21.7mA.
 * |        |          |111 = Pin PB.2 driving strength is 26.1mA.
 * |        |          |Others = Reserved.
 * |[15:12] |DS_GPB3   |Pin PB.3 Driving Strength Selection
 * |        |          |This field controls the pin PB.3 driving strength
 * |        |          |000 = Pin PB.3 driving strength is 2.2mA.
 * |        |          |001 = Pin PB.3 driving strength is 6.5mA.
 * |        |          |010 = Pin PB.3 driving strength is 8.7mA.
 * |        |          |011 = Pin PB.3 driving strength is 13.0mA.
 * |        |          |100 = Pin PB.3 driving strength is 15.2mA.
 * |        |          |101 = Pin PB.3 driving strength is 19.5mA.
 * |        |          |110 = Pin PB.3 driving strength is 21.7mA.
 * |        |          |111 = Pin PB.3 driving strength is 26.1mA.
 * |        |          |Others = Reserved.
 * |[19:16] |DS_GPB4   |Pin PB.4 Driving Strength Selection
 * |        |          |This field controls the pin PB.4 driving strength
 * |        |          |000 = Pin PB.4 driving strength is 2.2mA.
 * |        |          |001 = Pin PB.4 driving strength is 6.5mA.
 * |        |          |010 = Pin PB.4 driving strength is 8.7mA.
 * |        |          |011 = Pin PB.4 driving strength is 13.0mA.
 * |        |          |100 = Pin PB.4 driving strength is 15.2mA.
 * |        |          |101 = Pin PB.4 driving strength is 19.5mA.
 * |        |          |110 = Pin PB.4 driving strength is 21.7mA.
 * |        |          |111 = Pin PB.4 driving strength is 26.1mA.
 * |        |          |Others = Reserved.
 * |[23:20] |DS_GPB5   |Pin PB.5 Driving Strength Selection
 * |        |          |This field controls the pin PB.5 driving strength
 * |        |          |000 = Pin PB.5 driving strength is 2.2mA.
 * |        |          |001 = Pin PB.5 driving strength is 6.5mA.
 * |        |          |010 = Pin PB.5 driving strength is 8.7mA.
 * |        |          |011 = Pin PB.5 driving strength is 13.0mA.
 * |        |          |100 = Pin PB.5 driving strength is 15.2mA.
 * |        |          |101 = Pin PB.5 driving strength is 19.5mA.
 * |        |          |110 = Pin PB.5 driving strength is 21.7mA.
 * |        |          |111 = Pin PB.5 driving strength is 26.1mA.
 * |        |          |Others = Reserved.
 * |[27:24] |DS_GPB6   |Pin PB.6 Driving Strength Selection
 * |        |          |This field controls the pin PB.6 driving strength
 * |        |          |000 = Pin PB.6 driving strength is 2.2mA.
 * |        |          |001 = Pin PB.6 driving strength is 6.5mA.
 * |        |          |010 = Pin PB.6 driving strength is 8.7mA.
 * |        |          |011 = Pin PB.6 driving strength is 13.0mA.
 * |        |          |100 = Pin PB.6 driving strength is 15.2mA.
 * |        |          |101 = Pin PB.6 driving strength is 19.5mA.
 * |        |          |110 = Pin PB.6 driving strength is 21.7mA.
 * |        |          |111 = Pin PB.6 driving strength is 26.1mA.
 * |        |          |Others = Reserved.
 * |[31:28] |DS_GPB7   |Pin PB.7 Driving Strength Selection
 * |        |          |This field controls the pin PB.7 driving strength
 * |        |          |000 = Pin PB.7 driving strength is 2.2mA.
 * |        |          |001 = Pin PB.7 driving strength is 6.5mA.
 * |        |          |010 = Pin PB.7 driving strength is 8.7mA.
 * |        |          |011 = Pin PB.7 driving strength is 13.0mA.
 * |        |          |100 = Pin PB.7 driving strength is 15.2mA.
 * |        |          |101 = Pin PB.7 driving strength is 19.5mA.
 * |        |          |110 = Pin PB.7 driving strength is 21.7mA.
 * |        |          |111 = Pin PB.7 driving strength is 26.1mA.
 * |        |          |Others = Reserved.
 * @var SYS_T::PORDISCR
 * Offset: 0x100  Power-On-reset Disable Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[15:0]  |POR_DIS_CODE|Power-on-reset Disable Code (Write Protect)
 * |        |          |When powered on, the Power-On-Reset (POR) circuit generates a reset signal to reset whole chip function
 * |        |          |However, after power is ready, the POR circuit would consume a few power
 * |        |          |To minimize the POR circuit power consumption, user to disable POR circuit by writing 0x5AA5 to this field.
 * |        |          |The POR circuit will become active again when this field is set to other value or chip is reset by other reset source, including /RESET pin, Watchdog, LVR reset and the software chip reset function.
 * |        |          |This field is protected
 * |        |          |It means that before programming it, user has to write u201C59hu201D, u201C16hu201D and u201C88hu201D to address 0xB000_01A0 continuously to disable the register protection
 * |        |          |Refer to the register SYS_REGLKCTL at address SYS_BA+0x1A0 for detail.
 * @var SYS_T::RSTDEBCTL
 * Offset: 0x10C  Reset Pin De-bounce Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[15:0]  |DEBCNT    |Reset Pin De-bounce Counter
 * |        |          |This 16-bit external RESET De-bounce Counter can specify the external RESET de-bounce time up to around 5.46ms (0xFFFF) @ XIN=12 MHz.
 * |        |          |The default external RESET de-bounce time is 0.1ms (0x04B0) @ XIN = 12 MHz.
 * |[31]    |RSTDEBEN  |Reset Pin De-bounce Enable Bit
 * |        |          |0 = Reset pin de-bounce Disabled. (Default)
 * |        |          |1 = Reset pin de-bounce Enabled.
 * @var SYS_T::MACAD0LSR
 * Offset: 0x110  MAC Address 0 Low Significant Word Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |MACADRLSR |MAC Address Low Significant Word Register
 * @var SYS_T::MACAD0HSR
 * Offset: 0x114  MAC Address 0 High Significant Word Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[15:0]  |MACADRHSR |MAC Address High Significant Word Register
 * @var SYS_T::MACAD1LSR
 * Offset: 0x118  MAC Address 1 Low Significant Word Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |MACADRLSR |MAC Address Low Significant Word Register
 * @var SYS_T::MACAD1HSR
 * Offset: 0x11C  MAC Address 1 High Significant Word Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[15:0]  |MACADRHSR |MAC Address High Significant Word Register
 * @var SYS_T::UID0
 * Offset: 0x180  Unique Identifier Word 0 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |UID       |Unique ID
 * |        |          |Unique identify number of the chip.
 * |        |          |Loaded from OTP automatically during chip power on.
 * @var SYS_T::UID1
 * Offset: 0x184  Unique Identifier Word 1 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |UID       |Unique ID
 * |        |          |Unique identify number of the chip.
 * |        |          |Loaded from OTP automatically during chip power on.
 * @var SYS_T::UID2
 * Offset: 0x188  Unique Identifier Word 2 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |UID       |Unique ID
 * |        |          |Unique identify number of the chip.
 * |        |          |Loaded from OTP automatically during chip power on.
 * @var SYS_T::UCID0
 * Offset: 0x190  Unique Customer Identifier Word 0 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |UCID      |Unique Customer ID
 * |        |          |Unique customer identifier number of the chip.
 * |        |          |Loaded from OTP automatically during chip power on.
 * @var SYS_T::UCID1
 * Offset: 0x194  Unique Customer Identifier Word 1 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |UCID      |Unique Customer ID
 * |        |          |Unique customer identifier number of the chip.
 * |        |          |Loaded from OTP automatically during chip power on.
 * @var SYS_T::UCID2
 * Offset: 0x198  Unique Customer Identifier Word 2 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |UCID      |Unique Customer ID
 * |        |          |Unique customer identifier number of the chip.
 * |        |          |Loaded from OTP automatically during chip power on.
 * @var SYS_T::REGLKCTL
 * Offset: 0x1A0  Register Lock Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[7:0]   |REGLCTL   |Register Lock Control Code (Write Only)
 * |        |          |Some registers have write-protection function
 * |        |          |Writing these registers have to disable the protected function by writing the sequence value u201C59hu201D, u201C16hu201D, u201C88hu201D to this field
 * |        |          |After this sequence is completed, the REGLCTL bit will be set to 1 and write-protection registers can be normal write.
 * |        |          |REGLCTL[0]
 * |        |          |Register Lock Control Disable Index (Read Only)
 * |        |          |0 = Write-protection Enabled for writing protected registers
 * |        |          |Any write to the protected register is ignored.
 * |        |          |1 = Write-protection Disabled for writing protected registers.
 * @var SYS_T::DPLPASWD
 * Offset: 0x1B0  Deployed Password Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |DPLPASWD  |Deployed Password
 * |        |          |The DPLPASWD loaded from OTP during chip power on and used for authentication when user want to modify PLM (Product Life-cycle Management) from Deployed stage to RMA stage
 * @var SYS_T::OTPCHKER
 * Offset: 0x1B4  OTP Checker Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |OTPCHKER  |OTP Checker
 * |        |          |The OTPCHKER loaded from OTP during chip power on and used to know if the OTP checker is correct.
 * @var SYS_T::PLMSTS
 * Offset: 0x1B8  Product Life-Cycle Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[2:0]   |STAGE     |Current Product Life-Cycle Stage (Read Only)
 * |        |          |000 = Vender Stage.
 * |        |          |001 = Develop Stage.
 * |        |          |01x = Deployed Stage.
 * |        |          |1xx = RMA Stage.
 * |[31:24] |RVCODE    |Read Verify Code (Read Only)
 * |        |          |Read verify code should be 0xA5.
 * @var SYS_T::PNUMREVR
 * Offset: 0x1F0  Product Number and Revision Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[3:0]   |PRDNUML1  |Product Number Letter 1
 * |        |          |0x4
 * |[7:4]   |PRDNUML2  |Product Number Letter 2
 * |        |          |0x3
 * |[11:8]  |PRDNUML3  |Product Number Letter 3
 * |        |          |0x0
 * |[15:12] |PRDNUML4  |Product Number Letter 4
 * |        |          |0xD
 * |[19:16] |PRDNUML5  |Product Number Letter 5
 * |        |          |0 = A.
 * |[23:20] |PRDNUML6  |Product Number Letter 6
 * |        |          |0 = D (250nm).
 * |        |          |1 = F (180nm).
 * |        |          |2 = G (130nm).
 * |        |          |3 = H (110nm).
 * |        |          |4 = K (90nm).
 * |        |          |5 = L (55nm).
 * |        |          |6 = M (40nm).
 * |[27:24] |REV       |Chip Revision
 * |        |          |0 = Revision A.
 * |        |          |1 = Revision B.
 * |[31:28] |Foundry   |Foundry Code
 * |        |          |0 = TSMC.
 * |        |          |1 = SMIC.
 * @var SYS_T::CHIPCFG
 * Offset: 0x1F4  Chip Configuration Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[4]     |CANFD0DIS |CAN FD 0 Function Disable Bit
 * |        |          |0 = CAN FD 0 Function Enabled. (Default)
 * |        |          |1 = CAN FD 0 Function Disabled.
 * |[5]     |CANFD1DIS |CAN FD 1 Function Disable Bit
 * |        |          |0 = CAN FD 1 Function Enabled. (Default)
 * |        |          |1 = CAN FD 1 Function Disabled.
 * |[6]     |CANFD2DIS |CAN FD 2 Function Disable Bit
 * |        |          |0 = CAN FD 2 Function Enabled. (Default)
 * |        |          |1 = CAN FD 2 Function Disabled.
 * |[7]     |CANFD3DIS |CAN FD 3 Function Disable Bit
 * |        |          |0 = CAN FD 3 Function Enabled. (Default)
 * |        |          |1 = CAN FD 3 Function Disabled.
 * |[15:14] |DDRTYPE   |DDR SDRAM Type
 * |        |          |00 = SDRAM type is SDR (Single Data Rate SDRAM).
 * |        |          |01 = Reserved.
 * |        |          |10 = SDRAM type is DDR SDRAM (Double Data Rate SDRAM).
 * |        |          |11 = SDRAM type is DDR2 SDRAM. (default)
 * |[19:16] |DRAMSIZE  |DDR SDRAM Size
 * |        |          |0000 = Non MCP.
 * |        |          |0001 = 2M Bytes.
 * |        |          |0010 = 4M Bytes.
 * |        |          |0011 = 8M Bytes.
 * |        |          |0100 = 16M Bytes.
 * |        |          |0101 = 32M Bytes.
 * |        |          |0110 = 64M Bytes. (default)
 * |        |          |0111 = 128M Bytes.
 * |        |          |1000 = 256M Bytes.
 * |        |          |Others = Reserved.
 * |[21:20] |DDRVENDR  |DDR SDRAM Vendor
 * |        |          |00 = Winbond.
 * |        |          |01 = Reserved.
 * |        |          |10 = Reserved.
 * |        |          |11 = Reserved.
 * |[23:22] |DDRPRCES  |DDR SDRAM Process Node
 * |        |          |00 = 25nm.
 * |        |          |01 = Reserved.
 * |        |          |10 = Reserved.
 * |        |          |11 = Reserved.
 * |[31:24] |APPID     |Application ID
 * @var SYS_T::IBRAENCLR
 * Offset: 0x1FC  IBR Access Enable Clear Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |IBRACCENCLR|IBR Access Enable Clear (Read Only)
 * |        |          |ARM926EJ-S core read this register to clear IBRACCEN (SYS_MISCFCR[4]).
 */
    __I  uint32_t PDID;                  /*!< [0x0000] Product and Device Identifier Register                           */
    __IO uint32_t PWRON;                 /*!< [0x0004] Power-on Setting Register                                        */
    __I  uint32_t RESERVE0[6];
    __IO uint32_t LVRDCR;                /*!< [0x0020] Low Voltage Reset & Detect Control Register                      */
    __I  uint32_t RESERVE1[3];
    __IO uint32_t MISCFCR;               /*!< [0x0030] Miscellaneous Function Control Register                          */
    __I  uint32_t RESERVE2[3];
    __IO uint32_t MISCIER;               /*!< [0x0040] Miscellaneous Interrupt Enable Register                          */
    __IO uint32_t MISCISR;               /*!< [0x0044] Miscellaneous Interrupt Status Register                          */
    __I  uint32_t RESERVE3[6];
    __IO uint32_t AHBIPRST;              /*!< [0x0060] AHB IP Reset Control Register                                    */
    __IO uint32_t APBIPRST0;             /*!< [0x0064] APB IP Reset Control Register 0                                  */
    __IO uint32_t APBIPRST1;             /*!< [0x0068] APB IP Reset Control Register 1                                  */
    __IO uint32_t RSTSTS;                /*!< [0x006c] Reset Source Active Status Register                              */
    __IO uint32_t GPA_MFPL;              /*!< [0x0070] GPIOA Low Byte Multiple Function Control Register                */
    __IO uint32_t GPA_MFPH;              /*!< [0x0074] GPIOA High Byte Multiple Function Control Register               */
    __IO uint32_t GPB_MFPL;              /*!< [0x0078] GPIOB Low Byte Multiple Function Control Register                */
    __IO uint32_t GPB_MFPH;              /*!< [0x007c] GPIOB High Byte Multiple Function Control Register               */
    __IO uint32_t GPC_MFPL;              /*!< [0x0080] GPIOC Low Byte Multiple Function Control Register                */
    __IO uint32_t GPC_MFPH;              /*!< [0x0084] GPIOC High Byte Multiple Function Control Register               */
    __IO uint32_t GPD_MFPL;              /*!< [0x0088] GPIOD Low Byte Multiple Function Control Register                */
    __IO uint32_t GPD_MFPH;              /*!< [0x008c] GPIOD High Byte Multiple Function Control Register               */
    __IO uint32_t GPE_MFPL;              /*!< [0x0090] GPIOE Low Byte Multiple Function Control Register                */
    __IO uint32_t GPE_MFPH;              /*!< [0x0094] GPIOE High Byte Multiple Function Control Register               */
    __IO uint32_t GPF_MFPL;              /*!< [0x0098] GPIOF Low Byte Multiple Function Control Register                */
    __IO uint32_t GPF_MFPH;              /*!< [0x009c] GPIOF High Byte Multiple Function Control Register               */
    __IO uint32_t GPG_MFPL;              /*!< [0x00a0] GPIOG Low Byte Multiple Function Control Register                */
    __IO uint32_t GPG_MFPH;              /*!< [0x00a4] GPIOG High Byte Multiple Function Control Register               */
    __IO uint32_t GPH_MFPL;              /*!< [0x00a8] GPIOH Low Byte Multiple Function Control Register                */
    __IO uint32_t GPH_MFPH;              /*!< [0x00ac] GPIOH High Byte Multiple Function Control Register               */
    __I  uint32_t RESERVE4[16];
    __IO uint32_t DDR_DSCTL;             /*!< [0x00f0] DDR I/O Driving Strength Control Register                        */
    __IO uint32_t GPBL_DSCTL;            /*!< [0x00f4] GPIOB Low Byte Driving Strength Control Register                 */
    __I  uint32_t RESERVE5[2];
    __IO uint32_t PORDISCR;              /*!< [0x0100] Power-On-reset Disable Control Register                          */
    __I  uint32_t RESERVE6[2];
    __IO uint32_t RSTDEBCTL;             /*!< [0x010c] Reset Pin De-bounce Control Register                             */
    __I  uint32_t MACAD0LSR;             /*!< [0x0110] MAC Address 0 Low Significant Word Register                      */
    __I  uint32_t MACAD0HSR;             /*!< [0x0114] MAC Address 0 High Significant Word Register                     */
    __I  uint32_t MACAD1LSR;             /*!< [0x0118] MAC Address 1 Low Significant Word Register                      */
    __I  uint32_t MACAD1HSR;             /*!< [0x011c] MAC Address 1 High Significant Word Register                     */
    __I  uint32_t RESERVE7[24];
    __I  uint32_t UID0;                  /*!< [0x0180] Unique Identifier Word 0 Register                                */
    __I  uint32_t UID1;                  /*!< [0x0184] Unique Identifier Word 1 Register                                */
    __I  uint32_t UID2;                  /*!< [0x0188] Unique Identifier Word 2 Register                                */
    __I  uint32_t RESERVE8[1];
    __I  uint32_t UCID0;                 /*!< [0x0190] Unique Customer Identifier Word 0 Register                       */
    __I  uint32_t UCID1;                 /*!< [0x0194] Unique Customer Identifier Word 1 Register                       */
    __I  uint32_t UCID2;                 /*!< [0x0198] Unique Customer Identifier Word 2 Register                       */
    __I  uint32_t RESERVE9[1];
    __O  uint32_t REGLKCTL;              /*!< [0x01a0] Register Lock Control Register                                   */
    __I  uint32_t RESERVE10[3];
    __I  uint32_t DPLPASWD;              /*!< [0x01b0] Deployed Password Register                                       */
    __I  uint32_t OTPCHKER;              /*!< [0x01b4] OTP Checker Register                                             */
    __I  uint32_t PLMSTS;                /*!< [0x01b8] Product Life-Cycle Status Register                               */
    __I  uint32_t RESERVE11[13];
    __I  uint32_t PNUMREVR;              /*!< [0x01f0] Product Number and Revision Register                             */
    __I  uint32_t CHIPCFG;               /*!< [0x01f4] Chip Configuration Register                                      */
    __I  uint32_t RESERVE12[1];
    __I  uint32_t IBRAENCLR;             /*!< [0x01fc] IBR Access Enable Clear Register                                 */

} SYS_T;

/**
    @addtogroup SYS_CONST SYS Bit Field Definition
    Constant Definitions for SYS Controller
@{ */

#define SYS_PDID_PID_Pos                 (0)                                               /*!< SYS_T::PDID: PID Position              */
#define SYS_PDID_PID_Msk                 (0xfful << SYS_PDID_PID_Pos)                      /*!< SYS_T::PDID: PID Mask                  */

#define SYS_PDID_DID_Pos                 (24)                                              /*!< SYS_T::PDID: DID Position              */
#define SYS_PDID_DID_Msk                 (0xful << SYS_PDID_DID_Pos)                       /*!< SYS_T::PDID: DID Mask                  */

#define SYS_PWRON_BTSSEL_Pos             (0)                                               /*!< SYS_T::PWRON: BTSSEL Position          */
#define SYS_PWRON_BTSSEL_Msk             (0x3ul << SYS_PWRON_BTSSEL_Pos)                   /*!< SYS_T::PWRON: BTSSEL Mask              */

#define SYS_PWRON_PINSECBTEN_Pos         (2)                                               /*!< SYS_T::PWRON: PINSECBTEN Position      */
#define SYS_PWRON_PINSECBTEN_Msk         (0x1ul << SYS_PWRON_PINSECBTEN_Pos)               /*!< SYS_T::PWRON: PINSECBTEN Mask          */

#define SYS_PWRON_WDTON_Pos              (3)                                               /*!< SYS_T::PWRON: WDTON Position           */
#define SYS_PWRON_WDTON_Msk              (0x1ul << SYS_PWRON_WDTON_Pos)                    /*!< SYS_T::PWRON: WDTON Mask               */

#define SYS_PWRON_JTAGSEL_Pos            (4)                                               /*!< SYS_T::PWRON: JTAGSEL Position         */
#define SYS_PWRON_JTAGSEL_Msk            (0x1ul << SYS_PWRON_JTAGSEL_Pos)                  /*!< SYS_T::PWRON: JTAGSEL Mask             */

#define SYS_PWRON_URDBGON_Pos            (5)                                               /*!< SYS_T::PWRON: URDBGON Position         */
#define SYS_PWRON_URDBGON_Msk            (0x1ul << SYS_PWRON_URDBGON_Pos)                  /*!< SYS_T::PWRON: URDBGON Mask             */

#define SYS_PWRON_NPAGESEL_Pos           (6)                                               /*!< SYS_T::PWRON: NPAGESEL Position        */
#define SYS_PWRON_NPAGESEL_Msk           (0x3ul << SYS_PWRON_NPAGESEL_Pos)                 /*!< SYS_T::PWRON: NPAGESEL Mask            */

#define SYS_PWRON_MISCCFG_Pos            (8)                                               /*!< SYS_T::PWRON: MISCCFG Position         */
#define SYS_PWRON_MISCCFG_Msk            (0x3ul << SYS_PWRON_MISCCFG_Pos)                  /*!< SYS_T::PWRON: MISCCFG Mask             */

#define SYS_PWRON_SECBTEN_Pos            (10)                                              /*!< SYS_T::PWRON: SECBTEN Position         */
#define SYS_PWRON_SECBTEN_Msk            (0x1ul << SYS_PWRON_SECBTEN_Pos)                  /*!< SYS_T::PWRON: SECBTEN Mask             */

#define SYS_PWRON_SECBTDEVMD_Pos         (11)                                              /*!< SYS_T::PWRON: SECBTDEVMD Position      */
#define SYS_PWRON_SECBTDEVMD_Msk         (0x1ul << SYS_PWRON_SECBTDEVMD_Pos)               /*!< SYS_T::PWRON: SECBTDEVMD Mask          */

#define SYS_PWRON_PWRONSRC_Pos           (15)                                              /*!< SYS_T::PWRON: PWRONSRC Position        */
#define SYS_PWRON_PWRONSRC_Msk           (0x1ul << SYS_PWRON_PWRONSRC_Pos)                 /*!< SYS_T::PWRON: PWRONSRC Mask            */

#define SYS_PWRON_USBID_Pos              (16)                                              /*!< SYS_T::PWRON: USBID Position           */
#define SYS_PWRON_USBID_Msk              (0x1ul << SYS_PWRON_USBID_Pos)                    /*!< SYS_T::PWRON: USBID Mask               */

#define SYS_PWRON_BTDELAY_Pos            (28)                                              /*!< SYS_T::PWRON: BTDELAY Position         */
#define SYS_PWRON_BTDELAY_Msk            (0xful << SYS_PWRON_BTDELAY_Pos)                  /*!< SYS_T::PWRON: BTDELAY Mask             */

#define SYS_LVRDCR_LVR_EN_Pos            (0)                                               /*!< SYS_T::LVRDCR: LVR_EN Position         */
#define SYS_LVRDCR_LVR_EN_Msk            (0x1ul << SYS_LVRDCR_LVR_EN_Pos)                  /*!< SYS_T::LVRDCR: LVR_EN Mask             */

#define SYS_LVRDCR_LVD_EN_Pos            (8)                                               /*!< SYS_T::LVRDCR: LVD_EN Position         */
#define SYS_LVRDCR_LVD_EN_Msk            (0x1ul << SYS_LVRDCR_LVD_EN_Pos)                  /*!< SYS_T::LVRDCR: LVD_EN Mask             */

#define SYS_LVRDCR_LVD_SEL_Pos           (9)                                               /*!< SYS_T::LVRDCR: LVD_SEL Position        */
#define SYS_LVRDCR_LVD_SEL_Msk           (0x1ul << SYS_LVRDCR_LVD_SEL_Pos)                 /*!< SYS_T::LVRDCR: LVD_SEL Mask            */

#define SYS_MISCFCR_IBRACCEN_Pos         (4)                                               /*!< SYS_T::MISCFCR: IBRACCEN Position      */
#define SYS_MISCFCR_IBRACCEN_Msk         (0x1ul << SYS_MISCFCR_IBRACCEN_Pos)               /*!< SYS_T::MISCFCR: IBRACCEN Mask          */

#define SYS_MISCFCR_BOOTISRC_Pos         (5)                                               /*!< SYS_T::MISCFCR: BOOTISRC Position      */
#define SYS_MISCFCR_BOOTISRC_Msk         (0x1ul << SYS_MISCFCR_BOOTISRC_Pos)               /*!< SYS_T::MISCFCR: BOOTISRC Mask          */

#define SYS_MISCFCR_WDTRSTEN_Pos         (8)                                               /*!< SYS_T::MISCFCR: WDTRSTEN Position      */
#define SYS_MISCFCR_WDTRSTEN_Msk         (0x1ul << SYS_MISCFCR_WDTRSTEN_Pos)               /*!< SYS_T::MISCFCR: WDTRSTEN Mask          */

#define SYS_MISCFCR_HDSPUEN_Pos          (9)                                               /*!< SYS_T::MISCFCR: HDSPUEN Position       */
#define SYS_MISCFCR_HDSPUEN_Msk          (0x1ul << SYS_MISCFCR_HDSPUEN_Pos)                /*!< SYS_T::MISCFCR: HDSPUEN Mask           */

#define SYS_MISCFCR_EADCFUNCEN_Pos       (10)                                              /*!< SYS_T::MISCFCR: EADCFUNCEN Position    */
#define SYS_MISCFCR_EADCFUNCEN_Msk       (0x1ul << SYS_MISCFCR_EADCFUNCEN_Pos)             /*!< SYS_T::MISCFCR: EADCFUNCEN Mask        */

#define SYS_MISCFCR_USRHDSEN_Pos         (11)                                              /*!< SYS_T::MISCFCR: USRHDSEN Position      */
#define SYS_MISCFCR_USRHDSEN_Msk         (0x1ul << SYS_MISCFCR_USRHDSEN_Pos)               /*!< SYS_T::MISCFCR: USRHDSEN Mask          */

#define SYS_MISCFCR_GPIOLBEN_Pos         (12)                                              /*!< SYS_T::MISCFCR: GPIOLBEN Position      */
#define SYS_MISCFCR_GPIOLBEN_Msk         (0x1ul << SYS_MISCFCR_GPIOLBEN_Pos)               /*!< SYS_T::MISCFCR: GPIOLBEN Mask          */

#define SYS_MISCFCR_SELFTEST_Pos         (13)                                              /*!< SYS_T::MISCFCR: SELFTEST Position      */
#define SYS_MISCFCR_SELFTEST_Msk         (0x1ul << SYS_MISCFCR_SELFTEST_Pos)               /*!< SYS_T::MISCFCR: SELFTEST Mask          */

#define SYS_MISCIER_LVD_IEN_Pos          (0)                                               /*!< SYS_T::MISCIER: LVD_IEN Position       */
#define SYS_MISCIER_LVD_IEN_Msk          (0x1ul << SYS_MISCIER_LVD_IEN_Pos)                /*!< SYS_T::MISCIER: LVD_IEN Mask           */

#define SYS_MISCIER_USBIDC_IEN_Pos       (1)                                               /*!< SYS_T::MISCIER: USBIDC_IEN Position    */
#define SYS_MISCIER_USBIDC_IEN_Msk       (0x1ul << SYS_MISCIER_USBIDC_IEN_Pos)             /*!< SYS_T::MISCIER: USBIDC_IEN Mask        */

#define SYS_MISCISR_LVD_IS_Pos           (0)                                               /*!< SYS_T::MISCISR: LVD_IS Position        */
#define SYS_MISCISR_LVD_IS_Msk           (0x1ul << SYS_MISCISR_LVD_IS_Pos)                 /*!< SYS_T::MISCISR: LVD_IS Mask            */

#define SYS_MISCISR_USBIDC_IS_Pos        (1)                                               /*!< SYS_T::MISCISR: USBIDC_IS Position     */
#define SYS_MISCISR_USBIDC_IS_Msk        (0x1ul << SYS_MISCISR_USBIDC_IS_Pos)              /*!< SYS_T::MISCISR: USBIDC_IS Mask         */

#define SYS_MISCISR_USB0_IDS_Pos         (17)                                              /*!< SYS_T::MISCISR: USB0_IDS Position      */
#define SYS_MISCISR_USB0_IDS_Msk         (0x1ul << SYS_MISCISR_USB0_IDS_Pos)               /*!< SYS_T::MISCISR: USB0_IDS Mask          */

#define SYS_AHBIPRST_CHIPRST_Pos         (0)                                               /*!< SYS_T::AHBIPRST: CHIPRST Position      */
#define SYS_AHBIPRST_CHIPRST_Msk         (0x1ul << SYS_AHBIPRST_CHIPRST_Pos)               /*!< SYS_T::AHBIPRST: CHIPRST Mask          */

#define SYS_AHBIPRST_CPURST_Pos          (2)                                               /*!< SYS_T::AHBIPRST: CPURST Position       */
#define SYS_AHBIPRST_CPURST_Msk          (0x1ul << SYS_AHBIPRST_CPURST_Pos)                /*!< SYS_T::AHBIPRST: CPURST Mask           */

#define SYS_AHBIPRST_EBIRST_Pos          (3)                                               /*!< SYS_T::AHBIPRST: EBIRST Position       */
#define SYS_AHBIPRST_EBIRST_Msk          (0x1ul << SYS_AHBIPRST_EBIRST_Pos)                /*!< SYS_T::AHBIPRST: EBIRST Mask           */

#define SYS_AHBIPRST_PDMA0RST_Pos        (4)                                               /*!< SYS_T::AHBIPRST: PDMA0RST Position     */
#define SYS_AHBIPRST_PDMA0RST_Msk        (0x1ul << SYS_AHBIPRST_PDMA0RST_Pos)              /*!< SYS_T::AHBIPRST: PDMA0RST Mask         */

#define SYS_AHBIPRST_PDMA1RST_Pos        (5)                                               /*!< SYS_T::AHBIPRST: PDMA1RST Position     */
#define SYS_AHBIPRST_PDMA1RST_Msk        (0x1ul << SYS_AHBIPRST_PDMA1RST_Pos)              /*!< SYS_T::AHBIPRST: PDMA1RST Mask         */

#define SYS_AHBIPRST_SDICRST_Pos         (6)                                               /*!< SYS_T::AHBIPRST: SDICRST Position      */
#define SYS_AHBIPRST_SDICRST_Msk         (0x1ul << SYS_AHBIPRST_SDICRST_Pos)               /*!< SYS_T::AHBIPRST: SDICRST Mask          */

#define SYS_AHBIPRST_GPIORST_Pos         (7)                                               /*!< SYS_T::AHBIPRST: GPIORST Position      */
#define SYS_AHBIPRST_GPIORST_Msk         (0x1ul << SYS_AHBIPRST_GPIORST_Pos)               /*!< SYS_T::AHBIPRST: GPIORST Mask          */

#define SYS_AHBIPRST_I2SRST_Pos          (8)                                               /*!< SYS_T::AHBIPRST: I2SRST Position       */
#define SYS_AHBIPRST_I2SRST_Msk          (0x1ul << SYS_AHBIPRST_I2SRST_Pos)                /*!< SYS_T::AHBIPRST: I2SRST Mask           */

#define SYS_AHBIPRST_EMAC0RST_Pos        (16)                                              /*!< SYS_T::AHBIPRST: EMAC0RST Position     */
#define SYS_AHBIPRST_EMAC0RST_Msk        (0x1ul << SYS_AHBIPRST_EMAC0RST_Pos)              /*!< SYS_T::AHBIPRST: EMAC0RST Mask         */

#define SYS_AHBIPRST_EMAC1RST_Pos        (17)                                              /*!< SYS_T::AHBIPRST: EMAC1RST Position     */
#define SYS_AHBIPRST_EMAC1RST_Msk        (0x1ul << SYS_AHBIPRST_EMAC1RST_Pos)              /*!< SYS_T::AHBIPRST: EMAC1RST Mask         */

#define SYS_AHBIPRST_HSUSBHRST_Pos       (18)                                              /*!< SYS_T::AHBIPRST: HSUSBHRST Position    */
#define SYS_AHBIPRST_HSUSBHRST_Msk       (0x1ul << SYS_AHBIPRST_HSUSBHRST_Pos)             /*!< SYS_T::AHBIPRST: HSUSBHRST Mask        */

#define SYS_AHBIPRST_HSUSBDRST_Pos       (19)                                              /*!< SYS_T::AHBIPRST: HSUSBDRST Position    */
#define SYS_AHBIPRST_HSUSBDRST_Msk       (0x1ul << SYS_AHBIPRST_HSUSBDRST_Pos)             /*!< SYS_T::AHBIPRST: HSUSBDRST Mask        */

#define SYS_AHBIPRST_NDNDRST_Pos         (20)                                              /*!< SYS_T::AHBIPRST: NDNDRST Position      */
#define SYS_AHBIPRST_NDNDRST_Msk         (0x1ul << SYS_AHBIPRST_NDNDRST_Pos)               /*!< SYS_T::AHBIPRST: NDNDRST Mask          */

#define SYS_AHBIPRST_KSRST_Pos           (21)                                              /*!< SYS_T::AHBIPRST: KSRST Position        */
#define SYS_AHBIPRST_KSRST_Msk           (0x1ul << SYS_AHBIPRST_KSRST_Pos)                 /*!< SYS_T::AHBIPRST: KSRST Mask            */

#define SYS_AHBIPRST_OTPRST_Pos          (22)                                              /*!< SYS_T::AHBIPRST: OTPRST Position       */
#define SYS_AHBIPRST_OTPRST_Msk          (0x1ul << SYS_AHBIPRST_OTPRST_Pos)                /*!< SYS_T::AHBIPRST: OTPRST Mask           */

#define SYS_AHBIPRST_CRYPTORST_Pos       (23)                                              /*!< SYS_T::AHBIPRST: CRYPTORST Position    */
#define SYS_AHBIPRST_CRYPTORST_Msk       (0x1ul << SYS_AHBIPRST_CRYPTORST_Pos)             /*!< SYS_T::AHBIPRST: CRYPTORST Mask        */

#define SYS_AHBIPRST_SDH0RST_Pos         (24)                                              /*!< SYS_T::AHBIPRST: SDH0RST Position      */
#define SYS_AHBIPRST_SDH0RST_Msk         (0x1ul << SYS_AHBIPRST_SDH0RST_Pos)               /*!< SYS_T::AHBIPRST: SDH0RST Mask          */

#define SYS_AHBIPRST_SDH1RST_Pos         (25)                                              /*!< SYS_T::AHBIPRST: SDH1RST Position      */
#define SYS_AHBIPRST_SDH1RST_Msk         (0x1ul << SYS_AHBIPRST_SDH1RST_Pos)               /*!< SYS_T::AHBIPRST: SDH1RST Mask          */

#define SYS_AHBIPRST_CANFD0RST_Pos       (28)                                              /*!< SYS_T::AHBIPRST: CANFD0RST Position    */
#define SYS_AHBIPRST_CANFD0RST_Msk       (0x1ul << SYS_AHBIPRST_CANFD0RST_Pos)             /*!< SYS_T::AHBIPRST: CANFD0RST Mask        */

#define SYS_AHBIPRST_CANFD1RST_Pos       (29)                                              /*!< SYS_T::AHBIPRST: CANFD1RST Position    */
#define SYS_AHBIPRST_CANFD1RST_Msk       (0x1ul << SYS_AHBIPRST_CANFD1RST_Pos)             /*!< SYS_T::AHBIPRST: CANFD1RST Mask        */

#define SYS_AHBIPRST_CANFD2RST_Pos       (30)                                              /*!< SYS_T::AHBIPRST: CANFD2RST Position    */
#define SYS_AHBIPRST_CANFD2RST_Msk       (0x1ul << SYS_AHBIPRST_CANFD2RST_Pos)             /*!< SYS_T::AHBIPRST: CANFD2RST Mask        */

#define SYS_AHBIPRST_CANFD3RST_Pos       (31)                                              /*!< SYS_T::AHBIPRST: CANFD3RST Position    */
#define SYS_AHBIPRST_CANFD3RST_Msk       (0x1ul << SYS_AHBIPRST_CANFD3RST_Pos)             /*!< SYS_T::AHBIPRST: CANFD3RST Mask        */

#define SYS_APBIPRST0_TIMER3RST_Pos      (11)                                              /*!< SYS_T::APBIPRST0: TIMER3RST Position   */
#define SYS_APBIPRST0_TIMER3RST_Msk      (0x1ul << SYS_APBIPRST0_TIMER3RST_Pos)            /*!< SYS_T::APBIPRST0: TIMER3RST Mask       */

#define SYS_APBIPRST0_TIMER4RST_Pos      (12)                                              /*!< SYS_T::APBIPRST0: TIMER4RST Position   */
#define SYS_APBIPRST0_TIMER4RST_Msk      (0x1ul << SYS_APBIPRST0_TIMER4RST_Pos)            /*!< SYS_T::APBIPRST0: TIMER4RST Mask       */

#define SYS_APBIPRST0_TIMER5RST_Pos      (13)                                              /*!< SYS_T::APBIPRST0: TIMER5RST Position   */
#define SYS_APBIPRST0_TIMER5RST_Msk      (0x1ul << SYS_APBIPRST0_TIMER5RST_Pos)            /*!< SYS_T::APBIPRST0: TIMER5RST Mask       */

#define SYS_APBIPRST0_UART0RST_Pos       (16)                                              /*!< SYS_T::APBIPRST0: UART0RST Position    */
#define SYS_APBIPRST0_UART0RST_Msk       (0x1ul << SYS_APBIPRST0_UART0RST_Pos)             /*!< SYS_T::APBIPRST0: UART0RST Mask        */

#define SYS_APBIPRST0_UART1RST_Pos       (17)                                              /*!< SYS_T::APBIPRST0: UART1RST Position    */
#define SYS_APBIPRST0_UART1RST_Msk       (0x1ul << SYS_APBIPRST0_UART1RST_Pos)             /*!< SYS_T::APBIPRST0: UART1RST Mask        */

#define SYS_APBIPRST0_UART2RST_Pos       (18)                                              /*!< SYS_T::APBIPRST0: UART2RST Position    */
#define SYS_APBIPRST0_UART2RST_Msk       (0x1ul << SYS_APBIPRST0_UART2RST_Pos)             /*!< SYS_T::APBIPRST0: UART2RST Mask        */

#define SYS_APBIPRST0_UART3RST_Pos       (19)                                              /*!< SYS_T::APBIPRST0: UART3RST Position    */
#define SYS_APBIPRST0_UART3RST_Msk       (0x1ul << SYS_APBIPRST0_UART3RST_Pos)             /*!< SYS_T::APBIPRST0: UART3RST Mask        */

#define SYS_APBIPRST0_UART4RST_Pos       (20)                                              /*!< SYS_T::APBIPRST0: UART4RST Position    */
#define SYS_APBIPRST0_UART4RST_Msk       (0x1ul << SYS_APBIPRST0_UART4RST_Pos)             /*!< SYS_T::APBIPRST0: UART4RST Mask        */

#define SYS_APBIPRST0_UART5RST_Pos       (21)                                              /*!< SYS_T::APBIPRST0: UART5RST Position    */
#define SYS_APBIPRST0_UART5RST_Msk       (0x1ul << SYS_APBIPRST0_UART5RST_Pos)             /*!< SYS_T::APBIPRST0: UART5RST Mask        */

#define SYS_APBIPRST0_UART6RST_Pos       (22)                                              /*!< SYS_T::APBIPRST0: UART6RST Position    */
#define SYS_APBIPRST0_UART6RST_Msk       (0x1ul << SYS_APBIPRST0_UART6RST_Pos)             /*!< SYS_T::APBIPRST0: UART6RST Mask        */

#define SYS_APBIPRST0_UART7RST_Pos       (23)                                              /*!< SYS_T::APBIPRST0: UART7RST Position    */
#define SYS_APBIPRST0_UART7RST_Msk       (0x1ul << SYS_APBIPRST0_UART7RST_Pos)             /*!< SYS_T::APBIPRST0: UART7RST Mask        */

#define SYS_APBIPRST0_UART8RST_Pos       (24)                                              /*!< SYS_T::APBIPRST0: UART8RST Position    */
#define SYS_APBIPRST0_UART8RST_Msk       (0x1ul << SYS_APBIPRST0_UART8RST_Pos)             /*!< SYS_T::APBIPRST0: UART8RST Mask        */

#define SYS_APBIPRST0_UART9RST_Pos       (25)                                              /*!< SYS_T::APBIPRST0: UART9RST Position    */
#define SYS_APBIPRST0_UART9RST_Msk       (0x1ul << SYS_APBIPRST0_UART9RST_Pos)             /*!< SYS_T::APBIPRST0: UART9RST Mask        */

#define SYS_APBIPRST1_I2C0RST_Pos        (0)                                               /*!< SYS_T::APBIPRST1: I2C0RST Position     */
#define SYS_APBIPRST1_I2C0RST_Msk        (0x1ul << SYS_APBIPRST1_I2C0RST_Pos)              /*!< SYS_T::APBIPRST1: I2C0RST Mask         */

#define SYS_APBIPRST1_I2C1RST_Pos        (1)                                               /*!< SYS_T::APBIPRST1: I2C1RST Position     */
#define SYS_APBIPRST1_I2C1RST_Msk        (0x1ul << SYS_APBIPRST1_I2C1RST_Pos)              /*!< SYS_T::APBIPRST1: I2C1RST Mask         */

#define SYS_APBIPRST1_I2C2RST_Pos        (2)                                               /*!< SYS_T::APBIPRST1: I2C2RST Position     */
#define SYS_APBIPRST1_I2C2RST_Msk        (0x1ul << SYS_APBIPRST1_I2C2RST_Pos)              /*!< SYS_T::APBIPRST1: I2C2RST Mask         */

#define SYS_APBIPRST1_I2C3RST_Pos        (3)                                               /*!< SYS_T::APBIPRST1: I2C3RST Position     */
#define SYS_APBIPRST1_I2C3RST_Msk        (0x1ul << SYS_APBIPRST1_I2C3RST_Pos)              /*!< SYS_T::APBIPRST1: I2C3RST Mask         */

#define SYS_APBIPRST1_SPI0RST_Pos        (4)                                               /*!< SYS_T::APBIPRST1: SPI0RST Position     */
#define SYS_APBIPRST1_SPI0RST_Msk        (0x1ul << SYS_APBIPRST1_SPI0RST_Pos)              /*!< SYS_T::APBIPRST1: SPI0RST Mask         */

#define SYS_APBIPRST1_SPI1RST_Pos        (5)                                               /*!< SYS_T::APBIPRST1: SPI1RST Position     */
#define SYS_APBIPRST1_SPI1RST_Msk        (0x1ul << SYS_APBIPRST1_SPI1RST_Pos)              /*!< SYS_T::APBIPRST1: SPI1RST Mask         */

#define SYS_APBIPRST1_SPI2RST_Pos        (6)                                               /*!< SYS_T::APBIPRST1: SPI2RST Position     */
#define SYS_APBIPRST1_SPI2RST_Msk        (0x1ul << SYS_APBIPRST1_SPI2RST_Pos)              /*!< SYS_T::APBIPRST1: SPI2RST Mask         */

#define SYS_APBIPRST1_SPI3RST_Pos        (7)                                               /*!< SYS_T::APBIPRST1: SPI3RST Position     */
#define SYS_APBIPRST1_SPI3RST_Msk        (0x1ul << SYS_APBIPRST1_SPI3RST_Pos)              /*!< SYS_T::APBIPRST1: SPI3RST Mask         */

#define SYS_APBIPRST1_CAN0RST_Pos        (8)                                               /*!< SYS_T::APBIPRST1: CAN0RST Position     */
#define SYS_APBIPRST1_CAN0RST_Msk        (0x1ul << SYS_APBIPRST1_CAN0RST_Pos)              /*!< SYS_T::APBIPRST1: CAN0RST Mask         */

#define SYS_APBIPRST1_CAN1RST_Pos        (9)                                               /*!< SYS_T::APBIPRST1: CAN1RST Position     */
#define SYS_APBIPRST1_CAN1RST_Msk        (0x1ul << SYS_APBIPRST1_CAN1RST_Pos)              /*!< SYS_T::APBIPRST1: CAN1RST Mask         */

#define SYS_APBIPRST1_CAN2RST_Pos        (10)                                              /*!< SYS_T::APBIPRST1: CAN2RST Position     */
#define SYS_APBIPRST1_CAN2RST_Msk        (0x1ul << SYS_APBIPRST1_CAN2RST_Pos)              /*!< SYS_T::APBIPRST1: CAN2RST Mask         */

#define SYS_APBIPRST1_CAN3RST_Pos        (11)                                              /*!< SYS_T::APBIPRST1: CAN3RST Position     */
#define SYS_APBIPRST1_CAN3RST_Msk        (0x1ul << SYS_APBIPRST1_CAN3RST_Pos)              /*!< SYS_T::APBIPRST1: CAN3RST Mask         */

#define SYS_APBIPRST1_ADCRST_Pos         (24)                                              /*!< SYS_T::APBIPRST1: ADCRST Position      */
#define SYS_APBIPRST1_ADCRST_Msk         (0x1ul << SYS_APBIPRST1_ADCRST_Pos)               /*!< SYS_T::APBIPRST1: ADCRST Mask          */

#define SYS_APBIPRST1_EADCRST_Pos        (25)                                              /*!< SYS_T::APBIPRST1: EADCRST Position     */
#define SYS_APBIPRST1_EADCRST_Msk        (0x1ul << SYS_APBIPRST1_EADCRST_Pos)              /*!< SYS_T::APBIPRST1: EADCRST Mask         */

#define SYS_APBIPRST1_BPWM0RST_Pos       (26)                                              /*!< SYS_T::APBIPRST1: BPWM0RST Position    */
#define SYS_APBIPRST1_BPWM0RST_Msk       (0x1ul << SYS_APBIPRST1_BPWM0RST_Pos)             /*!< SYS_T::APBIPRST1: BPWM0RST Mask        */

#define SYS_APBIPRST1_BPWM1RST_Pos       (27)                                              /*!< SYS_T::APBIPRST1: BPWM1RST Position    */
#define SYS_APBIPRST1_BPWM1RST_Msk       (0x1ul << SYS_APBIPRST1_BPWM1RST_Pos)             /*!< SYS_T::APBIPRST1: BPWM1RST Mask        */

#define SYS_APBIPRST1_SMC0RST_Pos        (30)                                              /*!< SYS_T::APBIPRST1: SMC0RST Position     */
#define SYS_APBIPRST1_SMC0RST_Msk        (0x1ul << SYS_APBIPRST1_SMC0RST_Pos)              /*!< SYS_T::APBIPRST1: SMC0RST Mask         */

#define SYS_APBIPRST1_SMC1RST_Pos        (31)                                              /*!< SYS_T::APBIPRST1: SMC1RST Position     */
#define SYS_APBIPRST1_SMC1RST_Msk        (0x1ul << SYS_APBIPRST1_SMC1RST_Pos)              /*!< SYS_T::APBIPRST1: SMC1RST Mask         */

#define SYS_RSTSTS_PORRSTS_Pos           (0)                                               /*!< SYS_T::RSTSTS: PORRSTS Position        */
#define SYS_RSTSTS_PORRSTS_Msk           (0x1ul << SYS_RSTSTS_PORRSTS_Pos)                 /*!< SYS_T::RSTSTS: PORRSTS Mask            */

#define SYS_RSTSTS_PINRSTS_Pos           (1)                                               /*!< SYS_T::RSTSTS: PINRSTS Position        */
#define SYS_RSTSTS_PINRSTS_Msk           (0x1ul << SYS_RSTSTS_PINRSTS_Pos)                 /*!< SYS_T::RSTSTS: PINRSTS Mask            */

#define SYS_RSTSTS_LVRRSTS_Pos           (2)                                               /*!< SYS_T::RSTSTS: LVRRSTS Position        */
#define SYS_RSTSTS_LVRRSTS_Msk           (0x1ul << SYS_RSTSTS_LVRRSTS_Pos)                 /*!< SYS_T::RSTSTS: LVRRSTS Mask            */

#define SYS_RSTSTS_CHIPRSTS_Pos          (3)                                               /*!< SYS_T::RSTSTS: CHIPRSTS Position       */
#define SYS_RSTSTS_CHIPRSTS_Msk          (0x1ul << SYS_RSTSTS_CHIPRSTS_Pos)                /*!< SYS_T::RSTSTS: CHIPRSTS Mask           */

#define SYS_RSTSTS_CPURSTS_Pos           (4)                                               /*!< SYS_T::RSTSTS: CPURSTS Position        */
#define SYS_RSTSTS_CPURSTS_Msk           (0x1ul << SYS_RSTSTS_CPURSTS_Pos)                 /*!< SYS_T::RSTSTS: CPURSTS Mask            */

#define SYS_RSTSTS_WDTRSTS_Pos           (5)                                               /*!< SYS_T::RSTSTS: WDTRSTS Position        */
#define SYS_RSTSTS_WDTRSTS_Msk           (0x1ul << SYS_RSTSTS_WDTRSTS_Pos)                 /*!< SYS_T::RSTSTS: WDTRSTS Mask            */

#define SYS_RSTSTS_WWDTRSTS_Pos          (6)                                               /*!< SYS_T::RSTSTS: WWDTRSTS Position       */
#define SYS_RSTSTS_WWDTRSTS_Msk          (0x1ul << SYS_RSTSTS_WWDTRSTS_Pos)                /*!< SYS_T::RSTSTS: WWDTRSTS Mask           */

#define SYS_GPA_MFPL_MFP_GPA0_Pos        (0)                                               /*!< SYS_T::GPA_MFPL: MFP_GPA0 Position     */
#define SYS_GPA_MFPL_MFP_GPA0_Msk        (0xful << SYS_GPA_MFPL_MFP_GPA0_Pos)              /*!< SYS_T::GPA_MFPL: MFP_GPA0 Mask         */

#define SYS_GPA_MFPL_MFP_GPA1_Pos        (4)                                               /*!< SYS_T::GPA_MFPL: MFP_GPA1 Position     */
#define SYS_GPA_MFPL_MFP_GPA1_Msk        (0xful << SYS_GPA_MFPL_MFP_GPA1_Pos)              /*!< SYS_T::GPA_MFPL: MFP_GPA1 Mask         */

#define SYS_GPA_MFPL_MFP_GPA2_Pos        (8)                                               /*!< SYS_T::GPA_MFPL: MFP_GPA2 Position     */
#define SYS_GPA_MFPL_MFP_GPA2_Msk        (0xful << SYS_GPA_MFPL_MFP_GPA2_Pos)              /*!< SYS_T::GPA_MFPL: MFP_GPA2 Mask         */

#define SYS_GPA_MFPL_MFP_GPA3_Pos        (12)                                              /*!< SYS_T::GPA_MFPL: MFP_GPA3 Position     */
#define SYS_GPA_MFPL_MFP_GPA3_Msk        (0xful << SYS_GPA_MFPL_MFP_GPA3_Pos)              /*!< SYS_T::GPA_MFPL: MFP_GPA3 Mask         */

#define SYS_GPA_MFPL_MFP_GPA4_Pos        (16)                                              /*!< SYS_T::GPA_MFPL: MFP_GPA4 Position     */
#define SYS_GPA_MFPL_MFP_GPA4_Msk        (0xful << SYS_GPA_MFPL_MFP_GPA4_Pos)              /*!< SYS_T::GPA_MFPL: MFP_GPA4 Mask         */

#define SYS_GPA_MFPL_MFP_GPA5_Pos        (20)                                              /*!< SYS_T::GPA_MFPL: MFP_GPA5 Position     */
#define SYS_GPA_MFPL_MFP_GPA5_Msk        (0xful << SYS_GPA_MFPL_MFP_GPA5_Pos)              /*!< SYS_T::GPA_MFPL: MFP_GPA5 Mask         */

#define SYS_GPA_MFPL_MFP_GPA6_Pos        (24)                                              /*!< SYS_T::GPA_MFPL: MFP_GPA6 Position     */
#define SYS_GPA_MFPL_MFP_GPA6_Msk        (0xful << SYS_GPA_MFPL_MFP_GPA6_Pos)              /*!< SYS_T::GPA_MFPL: MFP_GPA6 Mask         */

#define SYS_GPA_MFPL_MFP_GPA7_Pos        (28)                                              /*!< SYS_T::GPA_MFPL: MFP_GPA7 Position     */
#define SYS_GPA_MFPL_MFP_GPA7_Msk        (0xful << SYS_GPA_MFPL_MFP_GPA7_Pos)              /*!< SYS_T::GPA_MFPL: MFP_GPA7 Mask         */

#define SYS_GPA_MFPH_MFP_GPA8_Pos        (0)                                               /*!< SYS_T::GPA_MFPH: MFP_GPA8 Position     */
#define SYS_GPA_MFPH_MFP_GPA8_Msk        (0xful << SYS_GPA_MFPH_MFP_GPA8_Pos)              /*!< SYS_T::GPA_MFPH: MFP_GPA8 Mask         */

#define SYS_GPA_MFPH_MFP_GPA9_Pos        (4)                                               /*!< SYS_T::GPA_MFPH: MFP_GPA9 Position     */
#define SYS_GPA_MFPH_MFP_GPA9_Msk        (0xful << SYS_GPA_MFPH_MFP_GPA9_Pos)              /*!< SYS_T::GPA_MFPH: MFP_GPA9 Mask         */

#define SYS_GPA_MFPH_MFP_GPA10_Pos       (8)                                               /*!< SYS_T::GPA_MFPH: MFP_GPA10 Position    */
#define SYS_GPA_MFPH_MFP_GPA10_Msk       (0xful << SYS_GPA_MFPH_MFP_GPA10_Pos)             /*!< SYS_T::GPA_MFPH: MFP_GPA10 Mask        */

#define SYS_GPA_MFPH_MFP_GPA11_Pos       (12)                                              /*!< SYS_T::GPA_MFPH: MFP_GPA11 Position    */
#define SYS_GPA_MFPH_MFP_GPA11_Msk       (0xful << SYS_GPA_MFPH_MFP_GPA11_Pos)             /*!< SYS_T::GPA_MFPH: MFP_GPA11 Mask        */

#define SYS_GPA_MFPH_MFP_GPA12_Pos       (16)                                              /*!< SYS_T::GPA_MFPH: MFP_GPA12 Position    */
#define SYS_GPA_MFPH_MFP_GPA12_Msk       (0xful << SYS_GPA_MFPH_MFP_GPA12_Pos)             /*!< SYS_T::GPA_MFPH: MFP_GPA12 Mask        */

#define SYS_GPA_MFPH_MFP_GPA13_Pos       (20)                                              /*!< SYS_T::GPA_MFPH: MFP_GPA13 Position    */
#define SYS_GPA_MFPH_MFP_GPA13_Msk       (0xful << SYS_GPA_MFPH_MFP_GPA13_Pos)             /*!< SYS_T::GPA_MFPH: MFP_GPA13 Mask        */

#define SYS_GPA_MFPH_MFP_GPA14_Pos       (24)                                              /*!< SYS_T::GPA_MFPH: MFP_GPA14 Position    */
#define SYS_GPA_MFPH_MFP_GPA14_Msk       (0xful << SYS_GPA_MFPH_MFP_GPA14_Pos)             /*!< SYS_T::GPA_MFPH: MFP_GPA14 Mask        */

#define SYS_GPA_MFPH_MFP_GPA15_Pos       (28)                                              /*!< SYS_T::GPA_MFPH: MFP_GPA15 Position    */
#define SYS_GPA_MFPH_MFP_GPA15_Msk       (0xful << SYS_GPA_MFPH_MFP_GPA15_Pos)             /*!< SYS_T::GPA_MFPH: MFP_GPA15 Mask        */

#define SYS_GPB_MFPL_MFP_GPB0_Pos        (0)                                               /*!< SYS_T::GPB_MFPL: MFP_GPB0 Position     */
#define SYS_GPB_MFPL_MFP_GPB0_Msk        (0xful << SYS_GPB_MFPL_MFP_GPB0_Pos)              /*!< SYS_T::GPB_MFPL: MFP_GPB0 Mask         */

#define SYS_GPB_MFPL_MFP_GPB1_Pos        (4)                                               /*!< SYS_T::GPB_MFPL: MFP_GPB1 Position     */
#define SYS_GPB_MFPL_MFP_GPB1_Msk        (0xful << SYS_GPB_MFPL_MFP_GPB1_Pos)              /*!< SYS_T::GPB_MFPL: MFP_GPB1 Mask         */

#define SYS_GPB_MFPL_MFP_GPB2_Pos        (8)                                               /*!< SYS_T::GPB_MFPL: MFP_GPB2 Position     */
#define SYS_GPB_MFPL_MFP_GPB2_Msk        (0xful << SYS_GPB_MFPL_MFP_GPB2_Pos)              /*!< SYS_T::GPB_MFPL: MFP_GPB2 Mask         */

#define SYS_GPB_MFPL_MFP_GPB3_Pos        (12)                                              /*!< SYS_T::GPB_MFPL: MFP_GPB3 Position     */
#define SYS_GPB_MFPL_MFP_GPB3_Msk        (0xful << SYS_GPB_MFPL_MFP_GPB3_Pos)              /*!< SYS_T::GPB_MFPL: MFP_GPB3 Mask         */

#define SYS_GPB_MFPL_MFP_GPB4_Pos        (16)                                              /*!< SYS_T::GPB_MFPL: MFP_GPB4 Position     */
#define SYS_GPB_MFPL_MFP_GPB4_Msk        (0xful << SYS_GPB_MFPL_MFP_GPB4_Pos)              /*!< SYS_T::GPB_MFPL: MFP_GPB4 Mask         */

#define SYS_GPB_MFPL_MFP_GPB5_Pos        (20)                                              /*!< SYS_T::GPB_MFPL: MFP_GPB5 Position     */
#define SYS_GPB_MFPL_MFP_GPB5_Msk        (0xful << SYS_GPB_MFPL_MFP_GPB5_Pos)              /*!< SYS_T::GPB_MFPL: MFP_GPB5 Mask         */

#define SYS_GPB_MFPL_MFP_GPB6_Pos        (24)                                              /*!< SYS_T::GPB_MFPL: MFP_GPB6 Position     */
#define SYS_GPB_MFPL_MFP_GPB6_Msk        (0xful << SYS_GPB_MFPL_MFP_GPB6_Pos)              /*!< SYS_T::GPB_MFPL: MFP_GPB6 Mask         */

#define SYS_GPB_MFPL_MFP_GPB7_Pos        (28)                                              /*!< SYS_T::GPB_MFPL: MFP_GPB7 Position     */
#define SYS_GPB_MFPL_MFP_GPB7_Msk        (0xful << SYS_GPB_MFPL_MFP_GPB7_Pos)              /*!< SYS_T::GPB_MFPL: MFP_GPB7 Mask         */

#define SYS_GPB_MFPH_MFP_GPB8_Pos        (0)                                               /*!< SYS_T::GPB_MFPH: MFP_GPB8 Position     */
#define SYS_GPB_MFPH_MFP_GPB8_Msk        (0xful << SYS_GPB_MFPH_MFP_GPB8_Pos)              /*!< SYS_T::GPB_MFPH: MFP_GPB8 Mask         */

#define SYS_GPB_MFPH_MFP_GPB9_Pos        (4)                                               /*!< SYS_T::GPB_MFPH: MFP_GPB9 Position     */
#define SYS_GPB_MFPH_MFP_GPB9_Msk        (0xful << SYS_GPB_MFPH_MFP_GPB9_Pos)              /*!< SYS_T::GPB_MFPH: MFP_GPB9 Mask         */

#define SYS_GPB_MFPH_MFP_GPB10_Pos       (8)                                               /*!< SYS_T::GPB_MFPH: MFP_GPB10 Position    */
#define SYS_GPB_MFPH_MFP_GPB10_Msk       (0xful << SYS_GPB_MFPH_MFP_GPB10_Pos)             /*!< SYS_T::GPB_MFPH: MFP_GPB10 Mask        */

#define SYS_GPB_MFPH_MFP_GPB11_Pos       (12)                                              /*!< SYS_T::GPB_MFPH: MFP_GPB11 Position    */
#define SYS_GPB_MFPH_MFP_GPB11_Msk       (0xful << SYS_GPB_MFPH_MFP_GPB11_Pos)             /*!< SYS_T::GPB_MFPH: MFP_GPB11 Mask        */

#define SYS_GPB_MFPH_MFP_GPB12_Pos       (16)                                              /*!< SYS_T::GPB_MFPH: MFP_GPB12 Position    */
#define SYS_GPB_MFPH_MFP_GPB12_Msk       (0xful << SYS_GPB_MFPH_MFP_GPB12_Pos)             /*!< SYS_T::GPB_MFPH: MFP_GPB12 Mask        */

#define SYS_GPB_MFPH_MFP_GPB13_Pos       (20)                                              /*!< SYS_T::GPB_MFPH: MFP_GPB13 Position    */
#define SYS_GPB_MFPH_MFP_GPB13_Msk       (0xful << SYS_GPB_MFPH_MFP_GPB13_Pos)             /*!< SYS_T::GPB_MFPH: MFP_GPB13 Mask        */

#define SYS_GPC_MFPL_MFP_GPC0_Pos        (0)                                               /*!< SYS_T::GPC_MFPL: MFP_GPC0 Position     */
#define SYS_GPC_MFPL_MFP_GPC0_Msk        (0xful << SYS_GPC_MFPL_MFP_GPC0_Pos)              /*!< SYS_T::GPC_MFPL: MFP_GPC0 Mask         */

#define SYS_GPC_MFPL_MFP_GPC1_Pos        (4)                                               /*!< SYS_T::GPC_MFPL: MFP_GPC1 Position     */
#define SYS_GPC_MFPL_MFP_GPC1_Msk        (0xful << SYS_GPC_MFPL_MFP_GPC1_Pos)              /*!< SYS_T::GPC_MFPL: MFP_GPC1 Mask         */

#define SYS_GPC_MFPL_MFP_GPC2_Pos        (8)                                               /*!< SYS_T::GPC_MFPL: MFP_GPC2 Position     */
#define SYS_GPC_MFPL_MFP_GPC2_Msk        (0xful << SYS_GPC_MFPL_MFP_GPC2_Pos)              /*!< SYS_T::GPC_MFPL: MFP_GPC2 Mask         */

#define SYS_GPC_MFPL_MFP_GPC3_Pos        (12)                                              /*!< SYS_T::GPC_MFPL: MFP_GPC3 Position     */
#define SYS_GPC_MFPL_MFP_GPC3_Msk        (0xful << SYS_GPC_MFPL_MFP_GPC3_Pos)              /*!< SYS_T::GPC_MFPL: MFP_GPC3 Mask         */

#define SYS_GPC_MFPL_MFP_GPC4_Pos        (16)                                              /*!< SYS_T::GPC_MFPL: MFP_GPC4 Position     */
#define SYS_GPC_MFPL_MFP_GPC4_Msk        (0xful << SYS_GPC_MFPL_MFP_GPC4_Pos)              /*!< SYS_T::GPC_MFPL: MFP_GPC4 Mask         */

#define SYS_GPC_MFPL_MFP_GPC5_Pos        (20)                                              /*!< SYS_T::GPC_MFPL: MFP_GPC5 Position     */
#define SYS_GPC_MFPL_MFP_GPC5_Msk        (0xful << SYS_GPC_MFPL_MFP_GPC5_Pos)              /*!< SYS_T::GPC_MFPL: MFP_GPC5 Mask         */

#define SYS_GPC_MFPL_MFP_GPC6_Pos        (24)                                              /*!< SYS_T::GPC_MFPL: MFP_GPC6 Position     */
#define SYS_GPC_MFPL_MFP_GPC6_Msk        (0xful << SYS_GPC_MFPL_MFP_GPC6_Pos)              /*!< SYS_T::GPC_MFPL: MFP_GPC6 Mask         */

#define SYS_GPC_MFPL_MFP_GPC7_Pos        (28)                                              /*!< SYS_T::GPC_MFPL: MFP_GPC7 Position     */
#define SYS_GPC_MFPL_MFP_GPC7_Msk        (0xful << SYS_GPC_MFPL_MFP_GPC7_Pos)              /*!< SYS_T::GPC_MFPL: MFP_GPC7 Mask         */

#define SYS_GPC_MFPH_MFP_GPC8_Pos        (0)                                               /*!< SYS_T::GPC_MFPH: MFP_GPC8 Position     */
#define SYS_GPC_MFPH_MFP_GPC8_Msk        (0xful << SYS_GPC_MFPH_MFP_GPC8_Pos)              /*!< SYS_T::GPC_MFPH: MFP_GPC8 Mask         */

#define SYS_GPC_MFPH_MFP_GPC9_Pos        (4)                                               /*!< SYS_T::GPC_MFPH: MFP_GPC9 Position     */
#define SYS_GPC_MFPH_MFP_GPC9_Msk        (0xful << SYS_GPC_MFPH_MFP_GPC9_Pos)              /*!< SYS_T::GPC_MFPH: MFP_GPC9 Mask         */

#define SYS_GPC_MFPH_MFP_GPC10_Pos       (8)                                               /*!< SYS_T::GPC_MFPH: MFP_GPC10 Position    */
#define SYS_GPC_MFPH_MFP_GPC10_Msk       (0xful << SYS_GPC_MFPH_MFP_GPC10_Pos)             /*!< SYS_T::GPC_MFPH: MFP_GPC10 Mask        */

#define SYS_GPC_MFPH_MFP_GPC11_Pos       (12)                                              /*!< SYS_T::GPC_MFPH: MFP_GPC11 Position    */
#define SYS_GPC_MFPH_MFP_GPC11_Msk       (0xful << SYS_GPC_MFPH_MFP_GPC11_Pos)             /*!< SYS_T::GPC_MFPH: MFP_GPC11 Mask        */

#define SYS_GPC_MFPH_MFP_GPC12_Pos       (16)                                              /*!< SYS_T::GPC_MFPH: MFP_GPC12 Position    */
#define SYS_GPC_MFPH_MFP_GPC12_Msk       (0xful << SYS_GPC_MFPH_MFP_GPC12_Pos)             /*!< SYS_T::GPC_MFPH: MFP_GPC12 Mask        */

#define SYS_GPC_MFPH_MFP_GPC13_Pos       (20)                                              /*!< SYS_T::GPC_MFPH: MFP_GPC13 Position    */
#define SYS_GPC_MFPH_MFP_GPC13_Msk       (0xful << SYS_GPC_MFPH_MFP_GPC13_Pos)             /*!< SYS_T::GPC_MFPH: MFP_GPC13 Mask        */

#define SYS_GPC_MFPH_MFP_GPC14_Pos       (24)                                              /*!< SYS_T::GPC_MFPH: MFP_GPC14 Position    */
#define SYS_GPC_MFPH_MFP_GPC14_Msk       (0xful << SYS_GPC_MFPH_MFP_GPC14_Pos)             /*!< SYS_T::GPC_MFPH: MFP_GPC14 Mask        */

#define SYS_GPC_MFPH_MFP_GPC15_Pos       (28)                                              /*!< SYS_T::GPC_MFPH: MFP_GPC15 Position    */
#define SYS_GPC_MFPH_MFP_GPC15_Msk       (0xful << SYS_GPC_MFPH_MFP_GPC15_Pos)             /*!< SYS_T::GPC_MFPH: MFP_GPC15 Mask        */

#define SYS_GPD_MFPL_MFP_GPD0_Pos        (0)                                               /*!< SYS_T::GPD_MFPL: MFP_GPD0 Position     */
#define SYS_GPD_MFPL_MFP_GPD0_Msk        (0xful << SYS_GPD_MFPL_MFP_GPD0_Pos)              /*!< SYS_T::GPD_MFPL: MFP_GPD0 Mask         */

#define SYS_GPD_MFPL_MFP_GPD1_Pos        (4)                                               /*!< SYS_T::GPD_MFPL: MFP_GPD1 Position     */
#define SYS_GPD_MFPL_MFP_GPD1_Msk        (0xful << SYS_GPD_MFPL_MFP_GPD1_Pos)              /*!< SYS_T::GPD_MFPL: MFP_GPD1 Mask         */

#define SYS_GPD_MFPL_MFP_GPD2_Pos        (8)                                               /*!< SYS_T::GPD_MFPL: MFP_GPD2 Position     */
#define SYS_GPD_MFPL_MFP_GPD2_Msk        (0xful << SYS_GPD_MFPL_MFP_GPD2_Pos)              /*!< SYS_T::GPD_MFPL: MFP_GPD2 Mask         */

#define SYS_GPD_MFPL_MFP_GPD3_Pos        (12)                                              /*!< SYS_T::GPD_MFPL: MFP_GPD3 Position     */
#define SYS_GPD_MFPL_MFP_GPD3_Msk        (0xful << SYS_GPD_MFPL_MFP_GPD3_Pos)              /*!< SYS_T::GPD_MFPL: MFP_GPD3 Mask         */

#define SYS_GPD_MFPL_MFP_GPD4_Pos        (16)                                              /*!< SYS_T::GPD_MFPL: MFP_GPD4 Position     */
#define SYS_GPD_MFPL_MFP_GPD4_Msk        (0xful << SYS_GPD_MFPL_MFP_GPD4_Pos)              /*!< SYS_T::GPD_MFPL: MFP_GPD4 Mask         */

#define SYS_GPD_MFPL_MFP_GPD5_Pos        (20)                                              /*!< SYS_T::GPD_MFPL: MFP_GPD5 Position     */
#define SYS_GPD_MFPL_MFP_GPD5_Msk        (0xful << SYS_GPD_MFPL_MFP_GPD5_Pos)              /*!< SYS_T::GPD_MFPL: MFP_GPD5 Mask         */

#define SYS_GPD_MFPL_MFP_GPD6_Pos        (24)                                              /*!< SYS_T::GPD_MFPL: MFP_GPD6 Position     */
#define SYS_GPD_MFPL_MFP_GPD6_Msk        (0xful << SYS_GPD_MFPL_MFP_GPD6_Pos)              /*!< SYS_T::GPD_MFPL: MFP_GPD6 Mask         */

#define SYS_GPD_MFPL_MFP_GPD7_Pos        (28)                                              /*!< SYS_T::GPD_MFPL: MFP_GPD7 Position     */
#define SYS_GPD_MFPL_MFP_GPD7_Msk        (0xful << SYS_GPD_MFPL_MFP_GPD7_Pos)              /*!< SYS_T::GPD_MFPL: MFP_GPD7 Mask         */

#define SYS_GPD_MFPH_MFP_GPD8_Pos        (0)                                               /*!< SYS_T::GPD_MFPH: MFP_GPD8 Position     */
#define SYS_GPD_MFPH_MFP_GPD8_Msk        (0xful << SYS_GPD_MFPH_MFP_GPD8_Pos)              /*!< SYS_T::GPD_MFPH: MFP_GPD8 Mask         */

#define SYS_GPD_MFPH_MFP_GPD9_Pos        (4)                                               /*!< SYS_T::GPD_MFPH: MFP_GPD9 Position     */
#define SYS_GPD_MFPH_MFP_GPD9_Msk        (0xful << SYS_GPD_MFPH_MFP_GPD9_Pos)              /*!< SYS_T::GPD_MFPH: MFP_GPD9 Mask         */

#define SYS_GPD_MFPH_MFP_GPD10_Pos       (8)                                               /*!< SYS_T::GPD_MFPH: MFP_GPD10 Position    */
#define SYS_GPD_MFPH_MFP_GPD10_Msk       (0xful << SYS_GPD_MFPH_MFP_GPD10_Pos)             /*!< SYS_T::GPD_MFPH: MFP_GPD10 Mask        */

#define SYS_GPD_MFPH_MFP_GPD11_Pos       (12)                                              /*!< SYS_T::GPD_MFPH: MFP_GPD11 Position    */
#define SYS_GPD_MFPH_MFP_GPD11_Msk       (0xful << SYS_GPD_MFPH_MFP_GPD11_Pos)             /*!< SYS_T::GPD_MFPH: MFP_GPD11 Mask        */

#define SYS_GPD_MFPH_MFP_GPD12_Pos       (16)                                              /*!< SYS_T::GPD_MFPH: MFP_GPD12 Position    */
#define SYS_GPD_MFPH_MFP_GPD12_Msk       (0xful << SYS_GPD_MFPH_MFP_GPD12_Pos)             /*!< SYS_T::GPD_MFPH: MFP_GPD12 Mask        */

#define SYS_GPD_MFPH_MFP_GPD13_Pos       (20)                                              /*!< SYS_T::GPD_MFPH: MFP_GPD13 Position    */
#define SYS_GPD_MFPH_MFP_GPD13_Msk       (0xful << SYS_GPD_MFPH_MFP_GPD13_Pos)             /*!< SYS_T::GPD_MFPH: MFP_GPD13 Mask        */

#define SYS_GPD_MFPH_MFP_GPD14_Pos       (24)                                              /*!< SYS_T::GPD_MFPH: MFP_GPD14 Position    */
#define SYS_GPD_MFPH_MFP_GPD14_Msk       (0xful << SYS_GPD_MFPH_MFP_GPD14_Pos)             /*!< SYS_T::GPD_MFPH: MFP_GPD14 Mask        */

#define SYS_GPD_MFPH_MFP_GPD15_Pos       (28)                                              /*!< SYS_T::GPD_MFPH: MFP_GPD15 Position    */
#define SYS_GPD_MFPH_MFP_GPD15_Msk       (0xful << SYS_GPD_MFPH_MFP_GPD15_Pos)             /*!< SYS_T::GPD_MFPH: MFP_GPD15 Mask        */

#define SYS_GPE_MFPL_MFP_GPE0_Pos        (0)                                               /*!< SYS_T::GPE_MFPL: MFP_GPE0 Position     */
#define SYS_GPE_MFPL_MFP_GPE0_Msk        (0xful << SYS_GPE_MFPL_MFP_GPE0_Pos)              /*!< SYS_T::GPE_MFPL: MFP_GPE0 Mask         */

#define SYS_GPE_MFPL_MFP_GPE1_Pos        (4)                                               /*!< SYS_T::GPE_MFPL: MFP_GPE1 Position     */
#define SYS_GPE_MFPL_MFP_GPE1_Msk        (0xful << SYS_GPE_MFPL_MFP_GPE1_Pos)              /*!< SYS_T::GPE_MFPL: MFP_GPE1 Mask         */

#define SYS_GPE_MFPL_MFP_GPE2_Pos        (8)                                               /*!< SYS_T::GPE_MFPL: MFP_GPE2 Position     */
#define SYS_GPE_MFPL_MFP_GPE2_Msk        (0xful << SYS_GPE_MFPL_MFP_GPE2_Pos)              /*!< SYS_T::GPE_MFPL: MFP_GPE2 Mask         */

#define SYS_GPE_MFPL_MFP_GPE3_Pos        (12)                                              /*!< SYS_T::GPE_MFPL: MFP_GPE3 Position     */
#define SYS_GPE_MFPL_MFP_GPE3_Msk        (0xful << SYS_GPE_MFPL_MFP_GPE3_Pos)              /*!< SYS_T::GPE_MFPL: MFP_GPE3 Mask         */

#define SYS_GPE_MFPL_MFP_GPE4_Pos        (16)                                              /*!< SYS_T::GPE_MFPL: MFP_GPE4 Position     */
#define SYS_GPE_MFPL_MFP_GPE4_Msk        (0xful << SYS_GPE_MFPL_MFP_GPE4_Pos)              /*!< SYS_T::GPE_MFPL: MFP_GPE4 Mask         */

#define SYS_GPE_MFPL_MFP_GPE5_Pos        (20)                                              /*!< SYS_T::GPE_MFPL: MFP_GPE5 Position     */
#define SYS_GPE_MFPL_MFP_GPE5_Msk        (0xful << SYS_GPE_MFPL_MFP_GPE5_Pos)              /*!< SYS_T::GPE_MFPL: MFP_GPE5 Mask         */

#define SYS_GPE_MFPL_MFP_GPE6_Pos        (24)                                              /*!< SYS_T::GPE_MFPL: MFP_GPE6 Position     */
#define SYS_GPE_MFPL_MFP_GPE6_Msk        (0xful << SYS_GPE_MFPL_MFP_GPE6_Pos)              /*!< SYS_T::GPE_MFPL: MFP_GPE6 Mask         */

#define SYS_GPE_MFPL_MFP_GPE7_Pos        (28)                                              /*!< SYS_T::GPE_MFPL: MFP_GPE7 Position     */
#define SYS_GPE_MFPL_MFP_GPE7_Msk        (0xful << SYS_GPE_MFPL_MFP_GPE7_Pos)              /*!< SYS_T::GPE_MFPL: MFP_GPE7 Mask         */

#define SYS_GPE_MFPH_MFP_GPE8_Pos        (0)                                               /*!< SYS_T::GPE_MFPH: MFP_GPE8 Position     */
#define SYS_GPE_MFPH_MFP_GPE8_Msk        (0xful << SYS_GPE_MFPH_MFP_GPE8_Pos)              /*!< SYS_T::GPE_MFPH: MFP_GPE8 Mask         */

#define SYS_GPE_MFPH_MFP_GPE9_Pos        (4)                                               /*!< SYS_T::GPE_MFPH: MFP_GPE9 Position     */
#define SYS_GPE_MFPH_MFP_GPE9_Msk        (0xful << SYS_GPE_MFPH_MFP_GPE9_Pos)              /*!< SYS_T::GPE_MFPH: MFP_GPE9 Mask         */

#define SYS_GPE_MFPH_MFP_GPE10_Pos       (8)                                               /*!< SYS_T::GPE_MFPH: MFP_GPE10 Position    */
#define SYS_GPE_MFPH_MFP_GPE10_Msk       (0xful << SYS_GPE_MFPH_MFP_GPE10_Pos)             /*!< SYS_T::GPE_MFPH: MFP_GPE10 Mask        */

#define SYS_GPE_MFPH_MFP_GPE11_Pos       (12)                                              /*!< SYS_T::GPE_MFPH: MFP_GPE11 Position    */
#define SYS_GPE_MFPH_MFP_GPE11_Msk       (0xful << SYS_GPE_MFPH_MFP_GPE11_Pos)             /*!< SYS_T::GPE_MFPH: MFP_GPE11 Mask        */

#define SYS_GPE_MFPH_MFP_GPE12_Pos       (16)                                              /*!< SYS_T::GPE_MFPH: MFP_GPE12 Position    */
#define SYS_GPE_MFPH_MFP_GPE12_Msk       (0xful << SYS_GPE_MFPH_MFP_GPE12_Pos)             /*!< SYS_T::GPE_MFPH: MFP_GPE12 Mask        */

#define SYS_GPF_MFPL_MFP_GPF0_Pos        (0)                                               /*!< SYS_T::GPF_MFPL: MFP_GPF0 Position     */
#define SYS_GPF_MFPL_MFP_GPF0_Msk        (0xful << SYS_GPF_MFPL_MFP_GPF0_Pos)              /*!< SYS_T::GPF_MFPL: MFP_GPF0 Mask         */

#define SYS_GPF_MFPL_MFP_GPF1_Pos        (4)                                               /*!< SYS_T::GPF_MFPL: MFP_GPF1 Position     */
#define SYS_GPF_MFPL_MFP_GPF1_Msk        (0xful << SYS_GPF_MFPL_MFP_GPF1_Pos)              /*!< SYS_T::GPF_MFPL: MFP_GPF1 Mask         */

#define SYS_GPF_MFPL_MFP_GPF2_Pos        (8)                                               /*!< SYS_T::GPF_MFPL: MFP_GPF2 Position     */
#define SYS_GPF_MFPL_MFP_GPF2_Msk        (0xful << SYS_GPF_MFPL_MFP_GPF2_Pos)              /*!< SYS_T::GPF_MFPL: MFP_GPF2 Mask         */

#define SYS_GPF_MFPL_MFP_GPF3_Pos        (12)                                              /*!< SYS_T::GPF_MFPL: MFP_GPF3 Position     */
#define SYS_GPF_MFPL_MFP_GPF3_Msk        (0xful << SYS_GPF_MFPL_MFP_GPF3_Pos)              /*!< SYS_T::GPF_MFPL: MFP_GPF3 Mask         */

#define SYS_GPF_MFPL_MFP_GPF4_Pos        (16)                                              /*!< SYS_T::GPF_MFPL: MFP_GPF4 Position     */
#define SYS_GPF_MFPL_MFP_GPF4_Msk        (0xful << SYS_GPF_MFPL_MFP_GPF4_Pos)              /*!< SYS_T::GPF_MFPL: MFP_GPF4 Mask         */

#define SYS_GPF_MFPL_MFP_GPF5_Pos        (20)                                              /*!< SYS_T::GPF_MFPL: MFP_GPF5 Position     */
#define SYS_GPF_MFPL_MFP_GPF5_Msk        (0xful << SYS_GPF_MFPL_MFP_GPF5_Pos)              /*!< SYS_T::GPF_MFPL: MFP_GPF5 Mask         */

#define SYS_GPF_MFPL_MFP_GPF6_Pos        (24)                                              /*!< SYS_T::GPF_MFPL: MFP_GPF6 Position     */
#define SYS_GPF_MFPL_MFP_GPF6_Msk        (0xful << SYS_GPF_MFPL_MFP_GPF6_Pos)              /*!< SYS_T::GPF_MFPL: MFP_GPF6 Mask         */

#define SYS_GPF_MFPL_MFP_GPF7_Pos        (28)                                              /*!< SYS_T::GPF_MFPL: MFP_GPF7 Position     */
#define SYS_GPF_MFPL_MFP_GPF7_Msk        (0xful << SYS_GPF_MFPL_MFP_GPF7_Pos)              /*!< SYS_T::GPF_MFPL: MFP_GPF7 Mask         */

#define SYS_GPF_MFPH_MFP_GPF8_Pos        (0)                                               /*!< SYS_T::GPF_MFPH: MFP_GPF8 Position     */
#define SYS_GPF_MFPH_MFP_GPF8_Msk        (0xful << SYS_GPF_MFPH_MFP_GPF8_Pos)              /*!< SYS_T::GPF_MFPH: MFP_GPF8 Mask         */

#define SYS_GPF_MFPH_MFP_GPF9_Pos        (4)                                               /*!< SYS_T::GPF_MFPH: MFP_GPF9 Position     */
#define SYS_GPF_MFPH_MFP_GPF9_Msk        (0xful << SYS_GPF_MFPH_MFP_GPF9_Pos)              /*!< SYS_T::GPF_MFPH: MFP_GPF9 Mask         */

#define SYS_GPF_MFPH_MFP_GPF10_Pos       (8)                                               /*!< SYS_T::GPF_MFPH: MFP_GPF10 Position    */
#define SYS_GPF_MFPH_MFP_GPF10_Msk       (0xful << SYS_GPF_MFPH_MFP_GPF10_Pos)             /*!< SYS_T::GPF_MFPH: MFP_GPF10 Mask        */

#define SYS_GPF_MFPH_MFP_GPF11_Pos       (12)                                              /*!< SYS_T::GPF_MFPH: MFP_GPF11 Position    */
#define SYS_GPF_MFPH_MFP_GPF11_Msk       (0xful << SYS_GPF_MFPH_MFP_GPF11_Pos)             /*!< SYS_T::GPF_MFPH: MFP_GPF11 Mask        */

#define SYS_GPF_MFPH_MFP_GPF12_Pos       (16)                                              /*!< SYS_T::GPF_MFPH: MFP_GPF12 Position    */
#define SYS_GPF_MFPH_MFP_GPF12_Msk       (0xful << SYS_GPF_MFPH_MFP_GPF12_Pos)             /*!< SYS_T::GPF_MFPH: MFP_GPF12 Mask        */

#define SYS_GPG_MFPL_MFP_GPG0_Pos        (0)                                               /*!< SYS_T::GPG_MFPL: MFP_GPG0 Position     */
#define SYS_GPG_MFPL_MFP_GPG0_Msk        (0xful << SYS_GPG_MFPL_MFP_GPG0_Pos)              /*!< SYS_T::GPG_MFPL: MFP_GPG0 Mask         */

#define SYS_GPG_MFPL_MFP_GPG1_Pos        (4)                                               /*!< SYS_T::GPG_MFPL: MFP_GPG1 Position     */
#define SYS_GPG_MFPL_MFP_GPG1_Msk        (0xful << SYS_GPG_MFPL_MFP_GPG1_Pos)              /*!< SYS_T::GPG_MFPL: MFP_GPG1 Mask         */

#define SYS_GPG_MFPL_MFP_GPG2_Pos        (8)                                               /*!< SYS_T::GPG_MFPL: MFP_GPG2 Position     */
#define SYS_GPG_MFPL_MFP_GPG2_Msk        (0xful << SYS_GPG_MFPL_MFP_GPG2_Pos)              /*!< SYS_T::GPG_MFPL: MFP_GPG2 Mask         */

#define SYS_GPG_MFPL_MFP_GPG3_Pos        (12)                                              /*!< SYS_T::GPG_MFPL: MFP_GPG3 Position     */
#define SYS_GPG_MFPL_MFP_GPG3_Msk        (0xful << SYS_GPG_MFPL_MFP_GPG3_Pos)              /*!< SYS_T::GPG_MFPL: MFP_GPG3 Mask         */

#define SYS_GPG_MFPL_MFP_GPG4_Pos        (16)                                              /*!< SYS_T::GPG_MFPL: MFP_GPG4 Position     */
#define SYS_GPG_MFPL_MFP_GPG4_Msk        (0xful << SYS_GPG_MFPL_MFP_GPG4_Pos)              /*!< SYS_T::GPG_MFPL: MFP_GPG4 Mask         */

#define SYS_GPG_MFPL_MFP_GPG5_Pos        (20)                                              /*!< SYS_T::GPG_MFPL: MFP_GPG5 Position     */
#define SYS_GPG_MFPL_MFP_GPG5_Msk        (0xful << SYS_GPG_MFPL_MFP_GPG5_Pos)              /*!< SYS_T::GPG_MFPL: MFP_GPG5 Mask         */

#define SYS_GPG_MFPL_MFP_GPG6_Pos        (24)                                              /*!< SYS_T::GPG_MFPL: MFP_GPG6 Position     */
#define SYS_GPG_MFPL_MFP_GPG6_Msk        (0xful << SYS_GPG_MFPL_MFP_GPG6_Pos)              /*!< SYS_T::GPG_MFPL: MFP_GPG6 Mask         */

#define SYS_GPG_MFPL_MFP_GPG7_Pos        (28)                                              /*!< SYS_T::GPG_MFPL: MFP_GPG7 Position     */
#define SYS_GPG_MFPL_MFP_GPG7_Msk        (0xful << SYS_GPG_MFPL_MFP_GPG7_Pos)              /*!< SYS_T::GPG_MFPL: MFP_GPG7 Mask         */

#define SYS_GPG_MFPH_MFP_GPG8_Pos        (0)                                               /*!< SYS_T::GPG_MFPH: MFP_GPG8 Position     */
#define SYS_GPG_MFPH_MFP_GPG8_Msk        (0xful << SYS_GPG_MFPH_MFP_GPG8_Pos)              /*!< SYS_T::GPG_MFPH: MFP_GPG8 Mask         */

#define SYS_GPG_MFPH_MFP_GPG9_Pos        (4)                                               /*!< SYS_T::GPG_MFPH: MFP_GPG9 Position     */
#define SYS_GPG_MFPH_MFP_GPG9_Msk        (0xful << SYS_GPG_MFPH_MFP_GPG9_Pos)              /*!< SYS_T::GPG_MFPH: MFP_GPG9 Mask         */

#define SYS_GPG_MFPH_MFP_GPG10_Pos       (8)                                               /*!< SYS_T::GPG_MFPH: MFP_GPG10 Position    */
#define SYS_GPG_MFPH_MFP_GPG10_Msk       (0xful << SYS_GPG_MFPH_MFP_GPG10_Pos)             /*!< SYS_T::GPG_MFPH: MFP_GPG10 Mask        */

#define SYS_GPG_MFPH_MFP_GPG11_Pos       (12)                                              /*!< SYS_T::GPG_MFPH: MFP_GPG11 Position    */
#define SYS_GPG_MFPH_MFP_GPG11_Msk       (0xful << SYS_GPG_MFPH_MFP_GPG11_Pos)             /*!< SYS_T::GPG_MFPH: MFP_GPG11 Mask        */

#define SYS_GPG_MFPH_MFP_GPG12_Pos       (16)                                              /*!< SYS_T::GPG_MFPH: MFP_GPG12 Position    */
#define SYS_GPG_MFPH_MFP_GPG12_Msk       (0xful << SYS_GPG_MFPH_MFP_GPG12_Pos)             /*!< SYS_T::GPG_MFPH: MFP_GPG12 Mask        */

#define SYS_GPG_MFPH_MFP_GPG13_Pos       (20)                                              /*!< SYS_T::GPG_MFPH: MFP_GPG13 Position    */
#define SYS_GPG_MFPH_MFP_GPG13_Msk       (0xful << SYS_GPG_MFPH_MFP_GPG13_Pos)             /*!< SYS_T::GPG_MFPH: MFP_GPG13 Mask        */

#define SYS_GPG_MFPH_MFP_GPG14_Pos       (24)                                              /*!< SYS_T::GPG_MFPH: MFP_GPG14 Position    */
#define SYS_GPG_MFPH_MFP_GPG14_Msk       (0xful << SYS_GPG_MFPH_MFP_GPG14_Pos)             /*!< SYS_T::GPG_MFPH: MFP_GPG14 Mask        */

#define SYS_GPG_MFPH_MFP_GPG15_Pos       (28)                                              /*!< SYS_T::GPG_MFPH: MFP_GPG15 Position    */
#define SYS_GPG_MFPH_MFP_GPG15_Msk       (0xful << SYS_GPG_MFPH_MFP_GPG15_Pos)             /*!< SYS_T::GPG_MFPH: MFP_GPG15 Mask        */

#define SYS_GPH_MFPL_MFP_GPH0_Pos        (0)                                               /*!< SYS_T::GPH_MFPL: MFP_GPH0 Position     */
#define SYS_GPH_MFPL_MFP_GPH0_Msk        (0xful << SYS_GPH_MFPL_MFP_GPH0_Pos)              /*!< SYS_T::GPH_MFPL: MFP_GPH0 Mask         */

#define SYS_GPH_MFPL_MFP_GPH1_Pos        (4)                                               /*!< SYS_T::GPH_MFPL: MFP_GPH1 Position     */
#define SYS_GPH_MFPL_MFP_GPH1_Msk        (0xful << SYS_GPH_MFPL_MFP_GPH1_Pos)              /*!< SYS_T::GPH_MFPL: MFP_GPH1 Mask         */

#define SYS_GPH_MFPL_MFP_GPH2_Pos        (8)                                               /*!< SYS_T::GPH_MFPL: MFP_GPH2 Position     */
#define SYS_GPH_MFPL_MFP_GPH2_Msk        (0xful << SYS_GPH_MFPL_MFP_GPH2_Pos)              /*!< SYS_T::GPH_MFPL: MFP_GPH2 Mask         */

#define SYS_GPH_MFPL_MFP_GPH3_Pos        (12)                                              /*!< SYS_T::GPH_MFPL: MFP_GPH3 Position     */
#define SYS_GPH_MFPL_MFP_GPH3_Msk        (0xful << SYS_GPH_MFPL_MFP_GPH3_Pos)              /*!< SYS_T::GPH_MFPL: MFP_GPH3 Mask         */

#define SYS_GPH_MFPL_MFP_GPH4_Pos        (16)                                              /*!< SYS_T::GPH_MFPL: MFP_GPH4 Position     */
#define SYS_GPH_MFPL_MFP_GPH4_Msk        (0xful << SYS_GPH_MFPL_MFP_GPH4_Pos)              /*!< SYS_T::GPH_MFPL: MFP_GPH4 Mask         */

#define SYS_GPH_MFPL_MFP_GPH5_Pos        (20)                                              /*!< SYS_T::GPH_MFPL: MFP_GPH5 Position     */
#define SYS_GPH_MFPL_MFP_GPH5_Msk        (0xful << SYS_GPH_MFPL_MFP_GPH5_Pos)              /*!< SYS_T::GPH_MFPL: MFP_GPH5 Mask         */

#define SYS_GPH_MFPL_MFP_GPH6_Pos        (24)                                              /*!< SYS_T::GPH_MFPL: MFP_GPH6 Position     */
#define SYS_GPH_MFPL_MFP_GPH6_Msk        (0xful << SYS_GPH_MFPL_MFP_GPH6_Pos)              /*!< SYS_T::GPH_MFPL: MFP_GPH6 Mask         */

#define SYS_GPH_MFPL_MFP_GPH7_Pos        (28)                                              /*!< SYS_T::GPH_MFPL: MFP_GPH7 Position     */
#define SYS_GPH_MFPL_MFP_GPH7_Msk        (0xful << SYS_GPH_MFPL_MFP_GPH7_Pos)              /*!< SYS_T::GPH_MFPL: MFP_GPH7 Mask         */

#define SYS_GPH_MFPH_MFP_GPH8_Pos        (0)                                               /*!< SYS_T::GPH_MFPH: MFP_GPH8 Position     */
#define SYS_GPH_MFPH_MFP_GPH8_Msk        (0xful << SYS_GPH_MFPH_MFP_GPH8_Pos)              /*!< SYS_T::GPH_MFPH: MFP_GPH8 Mask         */

#define SYS_GPH_MFPH_MFP_GPH9_Pos        (4)                                               /*!< SYS_T::GPH_MFPH: MFP_GPH9 Position     */
#define SYS_GPH_MFPH_MFP_GPH9_Msk        (0xful << SYS_GPH_MFPH_MFP_GPH9_Pos)              /*!< SYS_T::GPH_MFPH: MFP_GPH9 Mask         */

#define SYS_DDR_DSCTL_CLK_DS_Pos         (0)                                               /*!< SYS_T::DDR_DSCTL: CLK_DS Position      */
#define SYS_DDR_DSCTL_CLK_DS_Msk         (0x3ul << SYS_DDR_DSCTL_CLK_DS_Pos)               /*!< SYS_T::DDR_DSCTL: CLK_DS Mask          */

#define SYS_DDR_DSCTL_CTRL_DS_Pos        (2)                                               /*!< SYS_T::DDR_DSCTL: CTRL_DS Position     */
#define SYS_DDR_DSCTL_CTRL_DS_Msk        (0x3ul << SYS_DDR_DSCTL_CTRL_DS_Pos)              /*!< SYS_T::DDR_DSCTL: CTRL_DS Mask         */

#define SYS_DDR_DSCTL_ADDR_DS_Pos        (4)                                               /*!< SYS_T::DDR_DSCTL: ADDR_DS Position     */
#define SYS_DDR_DSCTL_ADDR_DS_Msk        (0x3ul << SYS_DDR_DSCTL_ADDR_DS_Pos)              /*!< SYS_T::DDR_DSCTL: ADDR_DS Mask         */

#define SYS_DDR_DSCTL_DATA_DS_Pos        (6)                                               /*!< SYS_T::DDR_DSCTL: DATA_DS Position     */
#define SYS_DDR_DSCTL_DATA_DS_Msk        (0x3ul << SYS_DDR_DSCTL_DATA_DS_Pos)              /*!< SYS_T::DDR_DSCTL: DATA_DS Mask         */

#define SYS_GPBL_DSCTL_DS_GPB0_Pos       (0)                                               /*!< SYS_T::GPBL_DSCTL: DS_GPB0 Position    */
#define SYS_GPBL_DSCTL_DS_GPB0_Msk       (0xful << SYS_GPBL_DSCTL_DS_GPB0_Pos)             /*!< SYS_T::GPBL_DSCTL: DS_GPB0 Mask        */

#define SYS_GPBL_DSCTL_DS_GPB1_Pos       (4)                                               /*!< SYS_T::GPBL_DSCTL: DS_GPB1 Position    */
#define SYS_GPBL_DSCTL_DS_GPB1_Msk       (0xful << SYS_GPBL_DSCTL_DS_GPB1_Pos)             /*!< SYS_T::GPBL_DSCTL: DS_GPB1 Mask        */

#define SYS_GPBL_DSCTL_DS_GPB2_Pos       (8)                                               /*!< SYS_T::GPBL_DSCTL: DS_GPB2 Position    */
#define SYS_GPBL_DSCTL_DS_GPB2_Msk       (0xful << SYS_GPBL_DSCTL_DS_GPB2_Pos)             /*!< SYS_T::GPBL_DSCTL: DS_GPB2 Mask        */

#define SYS_GPBL_DSCTL_DS_GPB3_Pos       (12)                                              /*!< SYS_T::GPBL_DSCTL: DS_GPB3 Position    */
#define SYS_GPBL_DSCTL_DS_GPB3_Msk       (0xful << SYS_GPBL_DSCTL_DS_GPB3_Pos)             /*!< SYS_T::GPBL_DSCTL: DS_GPB3 Mask        */

#define SYS_GPBL_DSCTL_DS_GPB4_Pos       (16)                                              /*!< SYS_T::GPBL_DSCTL: DS_GPB4 Position    */
#define SYS_GPBL_DSCTL_DS_GPB4_Msk       (0xful << SYS_GPBL_DSCTL_DS_GPB4_Pos)             /*!< SYS_T::GPBL_DSCTL: DS_GPB4 Mask        */

#define SYS_GPBL_DSCTL_DS_GPB5_Pos       (20)                                              /*!< SYS_T::GPBL_DSCTL: DS_GPB5 Position    */
#define SYS_GPBL_DSCTL_DS_GPB5_Msk       (0xful << SYS_GPBL_DSCTL_DS_GPB5_Pos)             /*!< SYS_T::GPBL_DSCTL: DS_GPB5 Mask        */

#define SYS_GPBL_DSCTL_DS_GPB6_Pos       (24)                                              /*!< SYS_T::GPBL_DSCTL: DS_GPB6 Position    */
#define SYS_GPBL_DSCTL_DS_GPB6_Msk       (0xful << SYS_GPBL_DSCTL_DS_GPB6_Pos)             /*!< SYS_T::GPBL_DSCTL: DS_GPB6 Mask        */

#define SYS_GPBL_DSCTL_DS_GPB7_Pos       (28)                                              /*!< SYS_T::GPBL_DSCTL: DS_GPB7 Position    */
#define SYS_GPBL_DSCTL_DS_GPB7_Msk       (0xful << SYS_GPBL_DSCTL_DS_GPB7_Pos)             /*!< SYS_T::GPBL_DSCTL: DS_GPB7 Mask        */

#define SYS_PORDISCR_POR_DIS_CODE_Pos    (0)                                               /*!< SYS_T::PORDISCR: POR_DIS_CODE Position */
#define SYS_PORDISCR_POR_DIS_CODE_Msk    (0xfffful << SYS_PORDISCR_POR_DIS_CODE_Pos)       /*!< SYS_T::PORDISCR: POR_DIS_CODE Mask     */

#define SYS_RSTDEBCTL_DEBCNT_Pos         (0)                                               /*!< SYS_T::RSTDEBCTL: DEBCNT Position      */
#define SYS_RSTDEBCTL_DEBCNT_Msk         (0xfffful << SYS_RSTDEBCTL_DEBCNT_Pos)            /*!< SYS_T::RSTDEBCTL: DEBCNT Mask          */

#define SYS_RSTDEBCTL_RSTDEBEN_Pos       (31)                                              /*!< SYS_T::RSTDEBCTL: RSTDEBEN Position    */
#define SYS_RSTDEBCTL_RSTDEBEN_Msk       (0x1ul << SYS_RSTDEBCTL_RSTDEBEN_Pos)             /*!< SYS_T::RSTDEBCTL: RSTDEBEN Mask        */

#define SYS_MACAD0LSR_MACADRLSR_Pos      (0)                                               /*!< SYS_T::MACAD0LSR: MACADRLSR Position   */
#define SYS_MACAD0LSR_MACADRLSR_Msk      (0xfffffffful << SYS_MACAD0LSR_MACADRLSR_Pos)     /*!< SYS_T::MACAD0LSR: MACADRLSR Mask       */

#define SYS_MACAD0HSR_MACADRHSR_Pos      (0)                                               /*!< SYS_T::MACAD0HSR: MACADRHSR Position   */
#define SYS_MACAD0HSR_MACADRHSR_Msk      (0xfffful << SYS_MACAD0HSR_MACADRHSR_Pos)         /*!< SYS_T::MACAD0HSR: MACADRHSR Mask       */

#define SYS_MACAD1LSR_MACADRLSR_Pos      (0)                                               /*!< SYS_T::MACAD1LSR: MACADRLSR Position   */
#define SYS_MACAD1LSR_MACADRLSR_Msk      (0xfffffffful << SYS_MACAD1LSR_MACADRLSR_Pos)     /*!< SYS_T::MACAD1LSR: MACADRLSR Mask       */

#define SYS_MACAD1HSR_MACADRHSR_Pos      (0)                                               /*!< SYS_T::MACAD1HSR: MACADRHSR Position   */
#define SYS_MACAD1HSR_MACADRHSR_Msk      (0xfffful << SYS_MACAD1HSR_MACADRHSR_Pos)         /*!< SYS_T::MACAD1HSR: MACADRHSR Mask       */

#define SYS_UID0_UID_Pos                 (0)                                               /*!< SYS_T::UID0: UID Position              */
#define SYS_UID0_UID_Msk                 (0xfffffffful << SYS_UID0_UID_Pos)                /*!< SYS_T::UID0: UID Mask                  */

#define SYS_UID1_UID_Pos                 (0)                                               /*!< SYS_T::UID1: UID Position              */
#define SYS_UID1_UID_Msk                 (0xfffffffful << SYS_UID1_UID_Pos)                /*!< SYS_T::UID1: UID Mask                  */

#define SYS_UID2_UID_Pos                 (0)                                               /*!< SYS_T::UID2: UID Position              */
#define SYS_UID2_UID_Msk                 (0xfffffffful << SYS_UID2_UID_Pos)                /*!< SYS_T::UID2: UID Mask                  */

#define SYS_UCID0_UCID_Pos               (0)                                               /*!< SYS_T::UCID0: UCID Position            */
#define SYS_UCID0_UCID_Msk               (0xfffffffful << SYS_UCID0_UCID_Pos)              /*!< SYS_T::UCID0: UCID Mask                */

#define SYS_UCID1_UCID_Pos               (0)                                               /*!< SYS_T::UCID1: UCID Position            */
#define SYS_UCID1_UCID_Msk               (0xfffffffful << SYS_UCID1_UCID_Pos)              /*!< SYS_T::UCID1: UCID Mask                */

#define SYS_UCID2_UCID_Pos               (0)                                               /*!< SYS_T::UCID2: UCID Position            */
#define SYS_UCID2_UCID_Msk               (0xfffffffful << SYS_UCID2_UCID_Pos)              /*!< SYS_T::UCID2: UCID Mask                */

#define SYS_REGLKCTL_REGLCTL_Pos         (0)                                               /*!< SYS_T::REGLKCTL: REGLCTL Position      */
#define SYS_REGLKCTL_REGLCTL_Msk         (0xfful << SYS_REGLKCTL_REGLCTL_Pos)              /*!< SYS_T::REGLKCTL: REGLCTL Mask          */

#define SYS_DPLPASWD_DPLPASWD_Pos        (0)                                               /*!< SYS_T::DPLPASWD: DPLPASWD Position     */
#define SYS_DPLPASWD_DPLPASWD_Msk        (0xfffffffful << SYS_DPLPASWD_DPLPASWD_Pos)       /*!< SYS_T::DPLPASWD: DPLPASWD Mask         */

#define SYS_OTPCHKER_OTPCHKER_Pos        (0)                                               /*!< SYS_T::OTPCHKER: OTPCHKER Position     */
#define SYS_OTPCHKER_OTPCHKER_Msk        (0xfffffffful << SYS_OTPCHKER_OTPCHKER_Pos)       /*!< SYS_T::OTPCHKER: OTPCHKER Mask         */

#define SYS_PLMSTS_STAGE_Pos             (0)                                               /*!< SYS_T::PLMSTS: STAGE Position          */
#define SYS_PLMSTS_STAGE_Msk             (0x7ul << SYS_PLMSTS_STAGE_Pos)                   /*!< SYS_T::PLMSTS: STAGE Mask              */

#define SYS_PLMSTS_RVCODE_Pos            (24)                                              /*!< SYS_T::PLMSTS: RVCODE Position         */
#define SYS_PLMSTS_RVCODE_Msk            (0xfful << SYS_PLMSTS_RVCODE_Pos)                 /*!< SYS_T::PLMSTS: RVCODE Mask             */

#define SYS_PNUMREVR_PRDNUML1_Pos        (0)                                               /*!< SYS_T::PNUMREVR: PRDNUML1 Position     */
#define SYS_PNUMREVR_PRDNUML1_Msk        (0xful << SYS_PNUMREVR_PRDNUML1_Pos)              /*!< SYS_T::PNUMREVR: PRDNUML1 Mask         */

#define SYS_PNUMREVR_PRDNUML2_Pos        (4)                                               /*!< SYS_T::PNUMREVR: PRDNUML2 Position     */
#define SYS_PNUMREVR_PRDNUML2_Msk        (0xful << SYS_PNUMREVR_PRDNUML2_Pos)              /*!< SYS_T::PNUMREVR: PRDNUML2 Mask         */

#define SYS_PNUMREVR_PRDNUML3_Pos        (8)                                               /*!< SYS_T::PNUMREVR: PRDNUML3 Position     */
#define SYS_PNUMREVR_PRDNUML3_Msk        (0xful << SYS_PNUMREVR_PRDNUML3_Pos)              /*!< SYS_T::PNUMREVR: PRDNUML3 Mask         */

#define SYS_PNUMREVR_PRDNUML4_Pos        (12)                                              /*!< SYS_T::PNUMREVR: PRDNUML4 Position     */
#define SYS_PNUMREVR_PRDNUML4_Msk        (0xful << SYS_PNUMREVR_PRDNUML4_Pos)              /*!< SYS_T::PNUMREVR: PRDNUML4 Mask         */

#define SYS_PNUMREVR_PRDNUML5_Pos        (16)                                              /*!< SYS_T::PNUMREVR: PRDNUML5 Position     */
#define SYS_PNUMREVR_PRDNUML5_Msk        (0xful << SYS_PNUMREVR_PRDNUML5_Pos)              /*!< SYS_T::PNUMREVR: PRDNUML5 Mask         */

#define SYS_PNUMREVR_PRDNUML6_Pos        (20)                                              /*!< SYS_T::PNUMREVR: PRDNUML6 Position     */
#define SYS_PNUMREVR_PRDNUML6_Msk        (0xful << SYS_PNUMREVR_PRDNUML6_Pos)              /*!< SYS_T::PNUMREVR: PRDNUML6 Mask         */

#define SYS_PNUMREVR_REV_Pos             (24)                                              /*!< SYS_T::PNUMREVR: REV Position          */
#define SYS_PNUMREVR_REV_Msk             (0xful << SYS_PNUMREVR_REV_Pos)                   /*!< SYS_T::PNUMREVR: REV Mask              */

#define SYS_PNUMREVR_Foundry_Pos         (28)                                              /*!< SYS_T::PNUMREVR: Foundry Position      */
#define SYS_PNUMREVR_Foundry_Msk         (0xful << SYS_PNUMREVR_Foundry_Pos)               /*!< SYS_T::PNUMREVR: Foundry Mask          */

#define SYS_CHIPCFG_CANFD0DIS_Pos        (4)                                               /*!< SYS_T::CHIPCFG: CANFD0DIS Position     */
#define SYS_CHIPCFG_CANFD0DIS_Msk        (0x1ul << SYS_CHIPCFG_CANFD0DIS_Pos)              /*!< SYS_T::CHIPCFG: CANFD0DIS Mask         */

#define SYS_CHIPCFG_CANFD1DIS_Pos        (5)                                               /*!< SYS_T::CHIPCFG: CANFD1DIS Position     */
#define SYS_CHIPCFG_CANFD1DIS_Msk        (0x1ul << SYS_CHIPCFG_CANFD1DIS_Pos)              /*!< SYS_T::CHIPCFG: CANFD1DIS Mask         */

#define SYS_CHIPCFG_CANFD2DIS_Pos        (6)                                               /*!< SYS_T::CHIPCFG: CANFD2DIS Position     */
#define SYS_CHIPCFG_CANFD2DIS_Msk        (0x1ul << SYS_CHIPCFG_CANFD2DIS_Pos)              /*!< SYS_T::CHIPCFG: CANFD2DIS Mask         */

#define SYS_CHIPCFG_CANFD3DIS_Pos        (7)                                               /*!< SYS_T::CHIPCFG: CANFD3DIS Position     */
#define SYS_CHIPCFG_CANFD3DIS_Msk        (0x1ul << SYS_CHIPCFG_CANFD3DIS_Pos)              /*!< SYS_T::CHIPCFG: CANFD3DIS Mask         */

#define SYS_CHIPCFG_DDRTYPE_Pos          (14)                                              /*!< SYS_T::CHIPCFG: DDRTYPE Position       */
#define SYS_CHIPCFG_DDRTYPE_Msk          (0x3ul << SYS_CHIPCFG_DDRTYPE_Pos)                /*!< SYS_T::CHIPCFG: DDRTYPE Mask           */

#define SYS_CHIPCFG_DRAMSIZE_Pos         (16)                                              /*!< SYS_T::CHIPCFG: DRAMSIZE Position      */
#define SYS_CHIPCFG_DRAMSIZE_Msk         (0xful << SYS_CHIPCFG_DRAMSIZE_Pos)               /*!< SYS_T::CHIPCFG: DRAMSIZE Mask          */

#define SYS_CHIPCFG_DDRVENDR_Pos         (20)                                              /*!< SYS_T::CHIPCFG: DDRVENDR Position      */
#define SYS_CHIPCFG_DDRVENDR_Msk         (0x3ul << SYS_CHIPCFG_DDRVENDR_Pos)               /*!< SYS_T::CHIPCFG: DDRVENDR Mask          */

#define SYS_CHIPCFG_DDRPRCES_Pos         (22)                                              /*!< SYS_T::CHIPCFG: DDRPRCES Position      */
#define SYS_CHIPCFG_DDRPRCES_Msk         (0x3ul << SYS_CHIPCFG_DDRPRCES_Pos)               /*!< SYS_T::CHIPCFG: DDRPRCES Mask          */

#define SYS_CHIPCFG_APPID_Pos            (24)                                              /*!< SYS_T::CHIPCFG: APPID Position         */
#define SYS_CHIPCFG_APPID_Msk            (0xfful << SYS_CHIPCFG_APPID_Pos)                 /*!< SYS_T::CHIPCFG: APPID Mask             */

#define SYS_IBRAENCLR_IBRACCENCLR_Pos    (0)                                               /*!< SYS_T::IBRAENCLR: IBRACCENCLR Position */
#define SYS_IBRAENCLR_IBRACCENCLR_Msk    (0xfffffffful << SYS_IBRAENCLR_IBRACCENCLR_Pos)   /*!< SYS_T::IBRAENCLR: IBRACCENCLR Mask     */

/**@}*/ /* SYS_CONST */
/**@}*/ /* end of SYS register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __SYS_REG_H__ */