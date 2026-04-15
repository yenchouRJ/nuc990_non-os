/**************************************************************************//**
 * @file     sys.h
 * @brief    SYS driver header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __SYS_H__
#define __SYS_H__

#include "NuMicro.h"
#include "sys_reg.h"
#include "clk.h"


#ifdef __cplusplus
extern "C"
{
#endif

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup SYS_Driver SYS Driver
  @{
*/

/** @addtogroup SYS_EXPORTED_CONSTANTS SYS Exported Constants
  @{
*/

/* Define constants for use AIC in service parameters.  */
#define SYS_SWI                     0
#define SYS_D_ABORT                 1
#define SYS_I_ABORT                 2
#define SYS_UNDEFINE                3

/* The parameters for sysSetInterruptPriorityLevel() and
   sysInstallISR() use */
#define FIQ_LEVEL_0                 0    /*!< FIQ Level 0 */
#define IRQ_LEVEL_1                 1    /*!< IRQ Level 1 */
#define IRQ_LEVEL_2                 2    /*!< IRQ Level 2 */
#define IRQ_LEVEL_3                 3    /*!< IRQ Level 3 */
#define IRQ_LEVEL_4                 4    /*!< IRQ Level 4 */
#define IRQ_LEVEL_5                 5    /*!< IRQ Level 5 */
#define IRQ_LEVEL_6                 6    /*!< IRQ Level 6 */
#define IRQ_LEVEL_7                 7    /*!< IRQ Level 7 */

/* The parameters for sysSetLocalInterrupt() use */
#define ENABLE_IRQ                 0x7F  /*!< Enable I-bit of CP15  */
#define ENABLE_FIQ                 0xBF  /*!< Enable F-bit of CP15  */
#define ENABLE_FIQ_IRQ             0x3F  /*!< Enable I-bit and F-bit of CP15  */
#define DISABLE_IRQ                0x80  /*!< Disable I-bit of CP15  */
#define DISABLE_FIQ                0x40  /*!< Disable F-bit of CP15  */
#define DISABLE_FIQ_IRQ            0xC0  /*!< Disable I-bit and F-bit of CP15  */

/* Define Cache type  */
#define CACHE_WRITE_BACK           0     /*!< Cache Write-back mode  */
#define CACHE_WRITE_THROUGH        1     /*!< Cache Write-through mode  */
#define CACHE_DISABLE              -1    /*!< Cache Disable  */

/** \brief  Structure type of clock source
 */
typedef enum CLKn
{
    SYS_UPLL     = 1,   /*!< UPLL clock */
    SYS_APLL     = 2,   /*!< APLL clock */
    SYS_SYSTEM   = 3,   /*!< System clock */
    SYS_HCLK     = 4,   /*!< HCLK1 clock */
    SYS_PCLK01   = 5,   /*!< HCLK234 clock */
    SYS_PCLK2    = 6,   /*!< PCLK clock */
    SYS_CPU      = 7,   /*!< CPU clock */
}  CLK_Type;

/* The parameters for sysSetGlobalInterrupt() use */
#define ENABLE_ALL_INTERRUPTS      0
#define DISABLE_ALL_INTERRUPTS     1

#define MMU_DIRECT_MAPPING         0

/* Define constants for use Cache in service parameters.  */
#define I_CACHE                    6
#define D_CACHE                    7
#define I_D_CACHE                  8

#define DEF_CACHE_LINE_SIZE        32

/*---------------------------------------------------------------------------------------------------------*/
/*  Module Reset Control Resister constant definitions.                                                    */
/*---------------------------------------------------------------------------------------------------------*/

/****************************** AHBIPRST register ******************************/
#define CHIP_RST            ((0UL<<24) | SYS_AHBIPRST_CHIPRST_Pos)
#define CPU_RST             ((0UL<<24) | SYS_AHBIPRST_CPURST_Pos)
#define EBI_RST             ((0UL<<24) | SYS_AHBIPRST_EBIRST_Pos)
#define PDMA0_RST           ((0UL<<24) | SYS_AHBIPRST_PDMA0RST_Pos)
#define PDMA1_RST           ((0UL<<24) | SYS_AHBIPRST_PDMA1RST_Pos)
#define SDIC_RST            ((0UL<<24) | SYS_AHBIPRST_SDICRST_Pos)
#define GPIO_RST            ((0UL<<24) | SYS_AHBIPRST_GPIORST_Pos)
#define I2S_RST             ((0UL<<24) | SYS_AHBIPRST_I2SRST_Pos)
#define EMAC0_RST           ((0UL<<24) | SYS_AHBIPRST_EMAC0RST_Pos)
#define EMAC1_RST           ((0UL<<24) | SYS_AHBIPRST_EMAC1RST_Pos)
#define USBH_RST            ((0UL<<24) | SYS_AHBIPRST_HSUSBHRST_Pos)
#define USBD_RST            ((0UL<<24) | SYS_AHBIPRST_HSUSBDRST_Pos)
#define NAND_RST            ((0UL<<24) | SYS_AHBIPRST_NDNDRST_Pos)
#define KS_RST              ((0UL<<24) | SYS_AHBIPRST_KSRST_Pos)
#define OPT_RST             ((0UL<<24) | SYS_AHBIPRST_OTPRST_Pos)
#define CRYPTO_RST          ((0UL<<24) | SYS_AHBIPRST_CRYPTORST_Pos)
#define SHD0_RST            ((0UL<<24) | SYS_AHBIPRST_CRYPTORST_Pos)
#define SDH1_RST            ((0UL<<24) | SYS_AHBIPRST_SDH1RST_Pos)
#define CANFD0_RST          ((0UL<<24) | SYS_AHBIPRST_CANFD0_Pos)
#define CANFD1_RST          ((0UL<<24) | SYS_AHBIPRST_CANFD1_Pos)
#define CANFD2_RST          ((0UL<<24) | SYS_AHBIPRST_CANFD2_Pos)
#define CANFD3_RST          ((0UL<<24) | SYS_AHBIPRST_CANFD3_Pos)

/****************************** APBIPRST0 register *****************************/
#define AIC_RST             ((4UL<<24) | SYS_APBIPRST0_AICRST_Pos)
#define QSPI0_RST           ((4UL<<24) | SYS_APBIPRST0_QSPI0RST_Pos)
#define WWDT_RST            ((4UL<<24) | SYS_APBIPRST0_WWDTRST_Pos)
#define TIMER0_RST          ((4UL<<24) | SYS_APBIPRST0_TIMER0RST_Pos)
#define TIMER1_RST          ((4UL<<24) | SYS_APBIPRST0_TIMER1RST_Pos)
#define TIMER2_RST          ((4UL<<24) | SYS_APBIPRST0_TIMER2RST_Pos)
#define TIMER3_RST          ((4UL<<24) | SYS_APBIPRST0_TIMER3RST_Pos)
#define TIMER4_RST          ((4UL<<24) | SYS_APBIPRST0_TIMER4RST_Pos)
#define TIMER5_RST          ((4UL<<24) | SYS_APBIPRST0_TIMER5RST_Pos)
#define UART0_RST           ((4UL<<24) | SYS_APBIPRST0_UART0RST_Pos)
#define UART1_RST           ((4UL<<24) | SYS_APBIPRST0_UART1RST_Pos)
#define UART2_RST           ((4UL<<24) | SYS_APBIPRST0_UART2RST_Pos)
#define UART3_RST           ((4UL<<24) | SYS_APBIPRST0_UART3RST_Pos)
#define UART4_RST           ((4UL<<24) | SYS_APBIPRST0_UART4RST_Pos)
#define UART5_RST           ((4UL<<24) | SYS_APBIPRST0_UART5RST_Pos)
#define UART6_RST           ((4UL<<24) | SYS_APBIPRST0_UART6RST_Pos)
#define UART7_RST           ((4UL<<24) | SYS_APBIPRST0_UART7RST_Pos)
#define UART8_RST           ((4UL<<24) | SYS_APBIPRST0_UART8RST_Pos)
#define UART9_RST           ((4UL<<24) | SYS_APBIPRST0_UART9RST_Pos)

/****************************** APBIPRST1 register *****************************/
#define I2C0_RST             ((8UL<<24) | SYS_APBIPRST1_I2C0RST_Pos)
#define I2C1_RST             ((8UL<<24) | SYS_APBIPRST1_I2C1RST_Pos)
#define I2C2_RST             ((8UL<<24) | SYS_APBIPRST1_I2C2RST_Pos)
#define I2C3_RST             ((8UL<<24) | SYS_APBIPRST1_I2C3RST_Pos)
#define SPI0_RST             ((8UL<<24) | SYS_APBIPRST1_SPI0RST_Pos)
#define SPI1_RST             ((8UL<<24) | SYS_APBIPRST1_SPI1RST_Pos)
#define SPI2_RST             ((8UL<<24) | SYS_APBIPRST1_SPI2RST_Pos)
#define SPI3_RST             ((8UL<<24) | SYS_APBIPRST1_SPI3RST_Pos)
#define CAN0_RST             ((8UL<<24) | SYS_APBIPRST1_CAN0RST_Pos)
#define CAN1_RST             ((8UL<<24) | SYS_APBIPRST1_CAN1RST_Pos)
#define CAN2_RST             ((8UL<<24) | SYS_APBIPRST1_CAN2RST_Pos)
#define CAN3_RST             ((8UL<<24) | SYS_APBIPRST1_CAN3RST_Pos)
#define CAN4_RST             ((8UL<<24) | SYS_APBIPRST1_CAN4RST_Pos)
#define CAN5_RST             ((8UL<<24) | SYS_APBIPRST1_CAN5RST_Pos)
#define CAN6_RST             ((8UL<<24) | SYS_APBIPRST1_CAN6RST_Pos)
#define CAN7_RST             ((8UL<<24) | SYS_APBIPRST1_CAN7RST_Pos)
//#define CANFD0_RST           ((8UL<<24) | SYS_APBIPRST1_CANFD0RST_Pos)
//#define CANFD1_RST           ((8UL<<24) | SYS_APBIPRST1_CANFD1RST_Pos)
//#define CANFD2_RST           ((8UL<<24) | SYS_APBIPRST1_CANFD2RST_Pos)
//#define CANFD3_RST           ((8UL<<24) | SYS_APBIPRST1_CANFD3RST_Pos)
#define ADC_RST              ((8UL<<24) | SYS_APBIPRST1_ADCRST_Pos)
#define EADC_RST             ((8UL<<24) | SYS_APBIPRST1_EADCRST_Pos)
#define BPWM0_RST            ((8UL<<24) | SYS_APBIPRST1_BPWM0RST_Pos)
#define BPWM1_RST            ((8UL<<24) | SYS_APBIPRST1_BPWM1RST_Pos)
#define SMC0_RST             ((8UL<<24) | SYS_APBIPRST1_SMC0RST_Pos)
#define SMC1_RST             ((8UL<<24) | SYS_APBIPRST1_SMC1RST_Pos)

/*---------------------------------------------------------------------------------------------------------*/
/*  Multi-Function constant definitions.                                                                   */
/*---------------------------------------------------------------------------------------------------------*/

/* PA.0 MFP */
#define SYS_GPA_MFPL_PA0MFP_GPIO              (0x00UL<<SYS_GPA_MFPL_PA0MFP_Pos)  /*!< GPA_MFPL PA0 setting for GPIO              */
#define SYS_GPA_MFPL_PA0MFP_QSPI0_SS1         (0x01UL<<SYS_GPA_MFPL_PA0MFP_Pos)  /*!< GPA_MFPL PA0 setting for QSPI0_SS1         */
#define SYS_GPA_MFPL_PA0MFP_EBI_nWAIT         (0x02UL<<SYS_GPA_MFPL_PA0MFP_Pos)  /*!< GPA_MFPL PA0 setting for EBI_nWAIT         */
#define SYS_GPA_MFPL_PA0MFP_I2C0_SDA          (0x03UL<<SYS_GPA_MFPL_PA0MFP_Pos)  /*!< GPA_MFPL PA0 setting for I2C0_SDA          */
#define SYS_GPA_MFPL_PA0MFP_UART1_RXD         (0x04UL<<SYS_GPA_MFPL_PA0MFP_Pos)  /*!< GPA_MFPL PA0 setting for UART1_RXD         */
#define SYS_GPA_MFPL_PA0MFP_INT0              (0x05UL<<SYS_GPA_MFPL_PA0MFP_Pos)  /*!< GPA_MFPL PA0 setting for INT0              */
#define SYS_GPA_MFPL_PA0MFP_CAN3_RXD          (0x07UL<<SYS_GPA_MFPL_PA0MFP_Pos)  /*!< GPA_MFPL PA0 setting for CAN3_RXD          */

/* PA.1 MFP */
#define SYS_GPA_MFPL_PA1MFP_GPIO              (0x00UL<<SYS_GPA_MFPL_PA1MFP_Pos)  /*!< GPA_MFPL PA1 setting for GPIO              */
#define SYS_GPA_MFPL_PA1MFP_EBI_nCS2          (0x01UL<<SYS_GPA_MFPL_PA1MFP_Pos)  /*!< GPA_MFPL PA1 setting for EBI_nCS2          */
#define SYS_GPA_MFPL_PA1MFP_EBI_MCLK          (0x02UL<<SYS_GPA_MFPL_PA1MFP_Pos)  /*!< GPA_MFPL PA1 setting for EBI_MCLK          */
#define SYS_GPA_MFPL_PA1MFP_I2C0_SCL          (0x03UL<<SYS_GPA_MFPL_PA1MFP_Pos)  /*!< GPA_MFPL PA1 setting for I2C0_SCL          */
#define SYS_GPA_MFPL_PA1MFP_UART1_TXD         (0x04UL<<SYS_GPA_MFPL_PA1MFP_Pos)  /*!< GPA_MFPL PA1 setting for UART1_TXD         */
#define SYS_GPA_MFPL_PA1MFP_INT1              (0x05UL<<SYS_GPA_MFPL_PA1MFP_Pos)  /*!< GPA_MFPL PA1 setting for INT1              */
#define SYS_GPA_MFPL_PA1MFP_CAN3_TXD          (0x07UL<<SYS_GPA_MFPL_PA1MFP_Pos)  /*!< GPA_MFPL PA1 setting for CAN3_TXD          */
#define SYS_GPA_MFPL_PA1MFP_QSPI0_CLK         (0x09UL<<SYS_GPA_MFPL_PA1MFP_Pos)  /*!< GPA_MFPL PA1 setting for QSPI0_CLK         */

/* PA.2 MFP */
#define SYS_GPA_MFPL_PA2MFP_GPIO              (0x00UL<<SYS_GPA_MFPL_PA2MFP_Pos)  /*!< GPA_MFPL PA2 setting for GPIO              */
#define SYS_GPA_MFPL_PA2MFP_UART6_nCTS        (0x01UL<<SYS_GPA_MFPL_PA2MFP_Pos)  /*!< GPA_MFPL PA2 setting for UART6_nCTS        */
#define SYS_GPA_MFPL_PA2MFP_I2S_LRCK          (0x02UL<<SYS_GPA_MFPL_PA2MFP_Pos)  /*!< GPA_MFPL PA2 setting for I2S_LRCK          */
#define SYS_GPA_MFPL_PA2MFP_SC0_nCD           (0x03UL<<SYS_GPA_MFPL_PA2MFP_Pos)  /*!< GPA_MFPL PA2 setting for SC0_nCD           */
#define SYS_GPA_MFPL_PA2MFP_JTAG1_TDO         (0x04UL<<SYS_GPA_MFPL_PA2MFP_Pos)  /*!< GPA_MFPL PA2 setting for JTAG1_TDO         */
#define SYS_GPA_MFPL_PA2MFP_CANFD0_RXD        (0x06UL<<SYS_GPA_MFPL_PA2MFP_Pos)  /*!< GPA_MFPL PA2 setting for CANFD0_RXD        */
#define SYS_GPA_MFPL_PA2MFP_I2C0_SMBAL        (0x07UL<<SYS_GPA_MFPL_PA2MFP_Pos)  /*!< GPA_MFPL PA2 setting for I2C0_SMBAL        */
#define SYS_GPA_MFPL_PA2MFP_SPI2_SS1          (0x08UL<<SYS_GPA_MFPL_PA2MFP_Pos)  /*!< GPA_MFPL PA2 setting for SPI2_SS1          */
#define SYS_GPA_MFPL_PA2MFP_QSPI0_MOSI0       (0x09UL<<SYS_GPA_MFPL_PA2MFP_Pos)  /*!< GPA_MFPL PA2 setting for QSPI0_MOSI0       */

/* PA.3 MFP */
#define SYS_GPA_MFPL_PA3MFP_GPIO              (0x00UL<<SYS_GPA_MFPL_PA3MFP_Pos)  /*!< GPA_MFPL PA3 setting for GPIO              */
#define SYS_GPA_MFPL_PA3MFP_UART6_nRTS        (0x01UL<<SYS_GPA_MFPL_PA3MFP_Pos)  /*!< GPA_MFPL PA3 setting for UART6_nRTS        */
#define SYS_GPA_MFPL_PA3MFP_I2S_BCLK          (0x02UL<<SYS_GPA_MFPL_PA3MFP_Pos)  /*!< GPA_MFPL PA3 setting for I2S_BCLK          */
#define SYS_GPA_MFPL_PA3MFP_SC0_PWR           (0x03UL<<SYS_GPA_MFPL_PA3MFP_Pos)  /*!< GPA_MFPL PA3 setting for SC0_PWR           */
#define SYS_GPA_MFPL_PA3MFP_JTAG1_TCK         (0x04UL<<SYS_GPA_MFPL_PA3MFP_Pos)  /*!< GPA_MFPL PA3 setting for JTAG1_TCK         */
#define SYS_GPA_MFPL_PA3MFP_BPWM1_CH5         (0x05UL<<SYS_GPA_MFPL_PA3MFP_Pos)  /*!< GPA_MFPL PA3 setting for BPWM1_CH5         */
#define SYS_GPA_MFPL_PA3MFP_CANFD0_TXD        (0x06UL<<SYS_GPA_MFPL_PA3MFP_Pos)  /*!< GPA_MFPL PA3 setting for CANFD0_TXD        */
#define SYS_GPA_MFPL_PA3MFP_I2C0_SMBSUS       (0x07UL<<SYS_GPA_MFPL_PA3MFP_Pos)  /*!< GPA_MFPL PA3 setting for I2C0_SMBSUS       */
#define SYS_GPA_MFPL_PA3MFP_SPI2_SS0          (0x08UL<<SYS_GPA_MFPL_PA3MFP_Pos)  /*!< GPA_MFPL PA3 setting for SPI2_SS0          */
#define SYS_GPA_MFPL_PA3MFP_QSPI0_MISO0       (0x09UL<<SYS_GPA_MFPL_PA3MFP_Pos)  /*!< GPA_MFPL PA3 setting for QSPI0_MISO0       */

/* PA.4 MFP */
#define SYS_GPA_MFPL_PA4MFP_GPIO              (0x00UL<<SYS_GPA_MFPL_PA4MFP_Pos)  /*!< GPA_MFPL PA4 setting for GPIO              */
#define SYS_GPA_MFPL_PA4MFP_UART6_RXD         (0x01UL<<SYS_GPA_MFPL_PA4MFP_Pos)  /*!< GPA_MFPL PA4 setting for UART6_RXD         */
#define SYS_GPA_MFPL_PA4MFP_I2S_DI            (0x02UL<<SYS_GPA_MFPL_PA4MFP_Pos)  /*!< GPA_MFPL PA4 setting for I2S_DI            */
#define SYS_GPA_MFPL_PA4MFP_SC0_DAT           (0x03UL<<SYS_GPA_MFPL_PA4MFP_Pos)  /*!< GPA_MFPL PA4 setting for SC0_DAT           */
#define SYS_GPA_MFPL_PA4MFP_JTAG1_TMS         (0x04UL<<SYS_GPA_MFPL_PA4MFP_Pos)  /*!< GPA_MFPL PA4 setting for JTAG1_TMS         */
#define SYS_GPA_MFPL_PA4MFP_BPWM1_CH4         (0x05UL<<SYS_GPA_MFPL_PA4MFP_Pos)  /*!< GPA_MFPL PA4 setting for BPWM1_CH4         */
#define SYS_GPA_MFPL_PA4MFP_CANFD1_RXD        (0x06UL<<SYS_GPA_MFPL_PA4MFP_Pos)  /*!< GPA_MFPL PA4 setting for CANFD1_RXD        */
#define SYS_GPA_MFPL_PA4MFP_I2C1_SMBAL        (0x07UL<<SYS_GPA_MFPL_PA4MFP_Pos)  /*!< GPA_MFPL PA4 setting for I2C1_SMBAL        */
#define SYS_GPA_MFPL_PA4MFP_SPI2_MISO         (0x08UL<<SYS_GPA_MFPL_PA4MFP_Pos)  /*!< GPA_MFPL PA4 setting for SPI2_MISO         */
#define SYS_GPA_MFPL_PA4MFP_QSPI0_MOSI1       (0x09UL<<SYS_GPA_MFPL_PA4MFP_Pos)  /*!< GPA_MFPL PA4 setting for QSPI0_MOSI1       */

/* PA.5 MFP */
#define SYS_GPA_MFPL_PA5MFP_GPIO              (0x00UL<<SYS_GPA_MFPL_PA5MFP_Pos)  /*!< GPA_MFPL PA5 setting for GPIO              */
#define SYS_GPA_MFPL_PA5MFP_UART6_TXD         (0x01UL<<SYS_GPA_MFPL_PA5MFP_Pos)  /*!< GPA_MFPL PA5 setting for UART6_TXD         */
#define SYS_GPA_MFPL_PA5MFP_I2S_DO            (0x02UL<<SYS_GPA_MFPL_PA5MFP_Pos)  /*!< GPA_MFPL PA5 setting for I2S_DO            */
#define SYS_GPA_MFPL_PA5MFP_SC0_CLK           (0x03UL<<SYS_GPA_MFPL_PA5MFP_Pos)  /*!< GPA_MFPL PA5 setting for SC0_CLK           */
#define SYS_GPA_MFPL_PA5MFP_JTAG1_TDI         (0x04UL<<SYS_GPA_MFPL_PA5MFP_Pos)  /*!< GPA_MFPL PA5 setting for JTAG1_TDI         */
#define SYS_GPA_MFPL_PA5MFP_BPWM0_CH5         (0x05UL<<SYS_GPA_MFPL_PA5MFP_Pos)  /*!< GPA_MFPL PA5 setting for BPWM0_CH5         */
#define SYS_GPA_MFPL_PA5MFP_CANFD1_TXD        (0x06UL<<SYS_GPA_MFPL_PA5MFP_Pos)  /*!< GPA_MFPL PA5 setting for CANFD1_TXD        */
#define SYS_GPA_MFPL_PA5MFP_I2C1_SMBSUS       (0x07UL<<SYS_GPA_MFPL_PA5MFP_Pos)  /*!< GPA_MFPL PA5 setting for I2C1_SMBSUS       */
#define SYS_GPA_MFPL_PA5MFP_SPI2_MOSI         (0x08UL<<SYS_GPA_MFPL_PA5MFP_Pos)  /*!< GPA_MFPL PA5 setting for SPI2_MOSI         */
#define SYS_GPA_MFPL_PA5MFP_QSPI0_MISO1       (0x09UL<<SYS_GPA_MFPL_PA5MFP_Pos)  /*!< GPA_MFPL PA5 setting for QSPI0_MISO1       */

/* PA.6 MFP */
#define SYS_GPA_MFPL_PA6MFP_GPIO              (0x00UL<<SYS_GPA_MFPL_PA6MFP_Pos)  /*!< GPA_MFPL PA6 setting for GPIO              */
#define SYS_GPA_MFPL_PA6MFP_EBI_nCS1          (0x01UL<<SYS_GPA_MFPL_PA6MFP_Pos)  /*!< GPA_MFPL PA6 setting for EBI_nCS1          */
#define SYS_GPA_MFPL_PA6MFP_I2S_MCLK          (0x02UL<<SYS_GPA_MFPL_PA6MFP_Pos)  /*!< GPA_MFPL PA6 setting for I2S_MCLK          */
#define SYS_GPA_MFPL_PA6MFP_SC0_RST           (0x03UL<<SYS_GPA_MFPL_PA6MFP_Pos)  /*!< GPA_MFPL PA6 setting for SC0_RST           */
#define SYS_GPA_MFPL_PA6MFP_JTAG1_nTRST       (0x04UL<<SYS_GPA_MFPL_PA6MFP_Pos)  /*!< GPA_MFPL PA6 setting for JTAG1_nTRST       */
#define SYS_GPA_MFPL_PA6MFP_BPWM0_CH4         (0x05UL<<SYS_GPA_MFPL_PA6MFP_Pos)  /*!< GPA_MFPL PA6 setting for BPWM0_CH4         */
#define SYS_GPA_MFPL_PA6MFP_SPI2_CLK          (0x08UL<<SYS_GPA_MFPL_PA6MFP_Pos)  /*!< GPA_MFPL PA6 setting for SPI2_CLK          */
#define SYS_GPA_MFPL_PA6MFP_QSPI0_SS0         (0x09UL<<SYS_GPA_MFPL_PA6MFP_Pos)  /*!< GPA_MFPL PA6 setting for QSPI0_SS0         */

/* PA.7 MFP */
#define SYS_GPA_MFPL_PA7MFP_GPIO              (0x00UL<<SYS_GPA_MFPL_PA7MFP_Pos)  /*!< GPA_MFPL PA7 setting for GPIO              */
#define SYS_GPA_MFPL_PA7MFP_EBI_nWR           (0x01UL<<SYS_GPA_MFPL_PA7MFP_Pos)  /*!< GPA_MFPL PA7 setting for EBI_nWR           */
#define SYS_GPA_MFPL_PA7MFP_UART2_nCTS        (0x02UL<<SYS_GPA_MFPL_PA7MFP_Pos)  /*!< GPA_MFPL PA7 setting for UART2_nCTS        */
#define SYS_GPA_MFPL_PA7MFP_TM3_EXT           (0x03UL<<SYS_GPA_MFPL_PA7MFP_Pos)  /*!< GPA_MFPL PA7 setting for TM3_EXT           */
#define SYS_GPA_MFPL_PA7MFP_BPWM1_CH5         (0x05UL<<SYS_GPA_MFPL_PA7MFP_Pos)  /*!< GPA_MFPL PA7 setting for BPWM1_CH5         */

/* PA.8 MFP */
#define SYS_GPA_MFPH_PA8MFP_GPIO              (0x00UL<<SYS_GPA_MFPH_PA8MFP_Pos)  /*!< GPA_MFPH PA8 setting for GPIO              */
#define SYS_GPA_MFPH_PA8MFP_EBI_nRD           (0x01UL<<SYS_GPA_MFPH_PA8MFP_Pos)  /*!< GPA_MFPH PA8 setting for EBI_nRD           */
#define SYS_GPA_MFPH_PA8MFP_UART2_nRTS        (0x02UL<<SYS_GPA_MFPH_PA8MFP_Pos)  /*!< GPA_MFPH PA8 setting for UART2_nRTS        */
#define SYS_GPA_MFPH_PA8MFP_TM3               (0x03UL<<SYS_GPA_MFPH_PA8MFP_Pos)  /*!< GPA_MFPH PA8 setting for TM3               */
#define SYS_GPA_MFPH_PA8MFP_BPWM1_CH4         (0x05UL<<SYS_GPA_MFPH_PA8MFP_Pos)  /*!< GPA_MFPH PA8 setting for BPWM1_CH4         */

/* PA.9 MFP */
#define SYS_GPA_MFPH_PA9MFP_GPIO              (0x00UL<<SYS_GPA_MFPH_PA9MFP_Pos)  /*!< GPA_MFPH PA9 setting for GPIO              */
#define SYS_GPA_MFPH_PA9MFP_EBI_nCS0          (0x01UL<<SYS_GPA_MFPH_PA9MFP_Pos)  /*!< GPA_MFPH PA9 setting for EBI_nCS0          */
#define SYS_GPA_MFPH_PA9MFP_UART2_RXD         (0x02UL<<SYS_GPA_MFPH_PA9MFP_Pos)  /*!< GPA_MFPH PA9 setting for UART2_RXD         */
#define SYS_GPA_MFPH_PA9MFP_TM2_EXT           (0x03UL<<SYS_GPA_MFPH_PA9MFP_Pos)  /*!< GPA_MFPH PA9 setting for TM2_EXT           */
#define SYS_GPA_MFPH_PA9MFP_BPWM0_CH5         (0x05UL<<SYS_GPA_MFPH_PA9MFP_Pos)  /*!< GPA_MFPH PA9 setting for BPWM0_CH5         */

/* PA.10 MFP */
#define SYS_GPA_MFPH_PA10MFP_GPIO             (0x00UL<<SYS_GPA_MFPH_PA10MFP_Pos)  /*!< GPA_MFPH PA10 setting for GPIO             */
#define SYS_GPA_MFPH_PA10MFP_EBI_ADR10        (0x01UL<<SYS_GPA_MFPH_PA10MFP_Pos)  /*!< GPA_MFPH PA10 setting for EBI_ADR10        */
#define SYS_GPA_MFPH_PA10MFP_UART2_TXD        (0x02UL<<SYS_GPA_MFPH_PA10MFP_Pos)  /*!< GPA_MFPH PA10 setting for UART2_TXD        */
#define SYS_GPA_MFPH_PA10MFP_TM2              (0x03UL<<SYS_GPA_MFPH_PA10MFP_Pos)  /*!< GPA_MFPH PA10 setting for TM2              */
#define SYS_GPA_MFPH_PA10MFP_BPWM0_CH4        (0x05UL<<SYS_GPA_MFPH_PA10MFP_Pos)  /*!< GPA_MFPH PA10 setting for BPWM0_CH4        */

/* PA.11 MFP */
#define SYS_GPA_MFPH_PA11MFP_GPIO             (0x00UL<<SYS_GPA_MFPH_PA11MFP_Pos)  /*!< GPA_MFPH PA11 setting for GPIO             */
#define SYS_GPA_MFPH_PA11MFP_EBI_ADR9         (0x01UL<<SYS_GPA_MFPH_PA11MFP_Pos)  /*!< GPA_MFPH PA11 setting for EBI_ADR9         */
#define SYS_GPA_MFPH_PA11MFP_UART8_RXD        (0x02UL<<SYS_GPA_MFPH_PA11MFP_Pos)  /*!< GPA_MFPH PA11 setting for UART8_RXD        */
#define SYS_GPA_MFPH_PA11MFP_TM4_EXT          (0x03UL<<SYS_GPA_MFPH_PA11MFP_Pos)  /*!< GPA_MFPH PA11 setting for TM4_EXT          */
#define SYS_GPA_MFPH_PA11MFP_CANFD2_RXD       (0x04UL<<SYS_GPA_MFPH_PA11MFP_Pos)  /*!< GPA_MFPH PA11 setting for CANFD2_RXD       */

/* PA.12 MFP */
#define SYS_GPA_MFPH_PA12MFP_GPIO             (0x00UL<<SYS_GPA_MFPH_PA12MFP_Pos)  /*!< GPA_MFPH PA12 setting for GPIO             */
#define SYS_GPA_MFPH_PA12MFP_EBI_ADR8         (0x01UL<<SYS_GPA_MFPH_PA12MFP_Pos)  /*!< GPA_MFPH PA12 setting for EBI_ADR8         */
#define SYS_GPA_MFPH_PA12MFP_UART8_TXD        (0x02UL<<SYS_GPA_MFPH_PA12MFP_Pos)  /*!< GPA_MFPH PA12 setting for UART8_TXD        */
#define SYS_GPA_MFPH_PA12MFP_TM4              (0x03UL<<SYS_GPA_MFPH_PA12MFP_Pos)  /*!< GPA_MFPH PA12 setting for TM4              */
#define SYS_GPA_MFPH_PA12MFP_CANFD2_TXD       (0x04UL<<SYS_GPA_MFPH_PA12MFP_Pos)  /*!< GPA_MFPH PA12 setting for CANFD2_TXD       */

/* PA.13 MFP */
#define SYS_GPA_MFPH_PA13MFP_GPIO             (0x00UL<<SYS_GPA_MFPH_PA13MFP_Pos)  /*!< GPA_MFPH PA13 setting for GPIO             */
#define SYS_GPA_MFPH_PA13MFP_EBI_ADR13        (0x01UL<<SYS_GPA_MFPH_PA13MFP_Pos)  /*!< GPA_MFPH PA13 setting for EBI_ADR13        */
#define SYS_GPA_MFPH_PA13MFP_I2C1_SDA         (0x02UL<<SYS_GPA_MFPH_PA13MFP_Pos)  /*!< GPA_MFPH PA13 setting for I2C1_SDA         */
#define SYS_GPA_MFPH_PA13MFP_TM1_EXT          (0x03UL<<SYS_GPA_MFPH_PA13MFP_Pos)  /*!< GPA_MFPH PA13 setting for TM1_EXT          */
#define SYS_GPA_MFPH_PA13MFP_CAN1_RXD         (0x05UL<<SYS_GPA_MFPH_PA13MFP_Pos)  /*!< GPA_MFPH PA13 setting for CAN1_RXD         */
#define SYS_GPA_MFPH_PA13MFP_UART7_TXD        (0x06UL<<SYS_GPA_MFPH_PA13MFP_Pos)  /*!< GPA_MFPH PA13 setting for UART7_TXD        */
#define SYS_GPA_MFPH_PA13MFP_BPWM0_CH3        (0x07UL<<SYS_GPA_MFPH_PA13MFP_Pos)  /*!< GPA_MFPH PA13 setting for BPWM0_CH3        */
#define SYS_GPA_MFPH_PA13MFP_INT0             (0x08UL<<SYS_GPA_MFPH_PA13MFP_Pos)  /*!< GPA_MFPH PA13 setting for INT0             */

/* PA.14 MFP */
#define SYS_GPA_MFPH_PA14MFP_GPIO             (0x00UL<<SYS_GPA_MFPH_PA14MFP_Pos)  /*!< GPA_MFPH PA14 setting for GPIO             */
#define SYS_GPA_MFPH_PA14MFP_EBI_ADR14        (0x01UL<<SYS_GPA_MFPH_PA14MFP_Pos)  /*!< GPA_MFPH PA14 setting for EBI_ADR14        */
#define SYS_GPA_MFPH_PA14MFP_I2C1_SCL         (0x02UL<<SYS_GPA_MFPH_PA14MFP_Pos)  /*!< GPA_MFPH PA14 setting for I2C1_SCL         */
#define SYS_GPA_MFPH_PA14MFP_TM1              (0x03UL<<SYS_GPA_MFPH_PA14MFP_Pos)  /*!< GPA_MFPH PA14 setting for TM1              */
#define SYS_GPA_MFPH_PA14MFP_CAN1_TXD         (0x05UL<<SYS_GPA_MFPH_PA14MFP_Pos)  /*!< GPA_MFPH PA14 setting for CAN1_TXD         */
#define SYS_GPA_MFPH_PA14MFP_UART7_RXD        (0x06UL<<SYS_GPA_MFPH_PA14MFP_Pos)  /*!< GPA_MFPH PA14 setting for UART7_RXD        */
#define SYS_GPA_MFPH_PA14MFP_BPWM0_CH2        (0x07UL<<SYS_GPA_MFPH_PA14MFP_Pos)  /*!< GPA_MFPH PA14 setting for BPWM0_CH2        */
#define SYS_GPA_MFPH_PA14MFP_INT1             (0x08UL<<SYS_GPA_MFPH_PA14MFP_Pos)  /*!< GPA_MFPH PA14 setting for INT1             */

/* PA.15 MFP */
#define SYS_GPA_MFPH_PA15MFP_GPIO             (0x00UL<<SYS_GPA_MFPH_PA15MFP_Pos)  /*!< GPA_MFPH PA15 setting for GPIO             */
#define SYS_GPA_MFPH_PA15MFP_EBI_ADR19        (0x01UL<<SYS_GPA_MFPH_PA15MFP_Pos)  /*!< GPA_MFPH PA15 setting for EBI_ADR19        */
#define SYS_GPA_MFPH_PA15MFP_I2C0_SDA         (0x02UL<<SYS_GPA_MFPH_PA15MFP_Pos)  /*!< GPA_MFPH PA15 setting for I2C0_SDA         */
#define SYS_GPA_MFPH_PA15MFP_TM5_EXT          (0x03UL<<SYS_GPA_MFPH_PA15MFP_Pos)  /*!< GPA_MFPH PA15 setting for TM5_EXT          */
#define SYS_GPA_MFPH_PA15MFP_CAN2_RXD         (0x05UL<<SYS_GPA_MFPH_PA15MFP_Pos)  /*!< GPA_MFPH PA15 setting for CAN2_RXD         */
#define SYS_GPA_MFPH_PA15MFP_SPI1_SS0         (0x06UL<<SYS_GPA_MFPH_PA15MFP_Pos)  /*!< GPA_MFPH PA15 setting for SPI1_SS0         */
#define SYS_GPA_MFPH_PA15MFP_BPWM0_CH1        (0x07UL<<SYS_GPA_MFPH_PA15MFP_Pos)  /*!< GPA_MFPH PA15 setting for BPWM0_CH1        */
#define SYS_GPA_MFPH_PA15MFP_I2S_LRCK         (0x08UL<<SYS_GPA_MFPH_PA15MFP_Pos)  /*!< GPA_MFPH PA15 setting for I2S_LRCK         */

/* PB.0 MFP */
#define SYS_GPB_MFPL_PB0MFP_GPIO              (0x00UL<<SYS_GPB_MFPL_PB0MFP_Pos)  /*!< GPB_MFPL PB0 setting for GPIO              */
#define SYS_GPB_MFPL_PB0MFP_EBI_ADR12         (0x01UL<<SYS_GPB_MFPL_PB0MFP_Pos)  /*!< GPB_MFPL PB0 setting for EBI_ADR12         */
#define SYS_GPB_MFPL_PB0MFP_UART2_nCTS        (0x02UL<<SYS_GPB_MFPL_PB0MFP_Pos)  /*!< GPB_MFPL PB0 setting for UART2_nCTS        */
#define SYS_GPB_MFPL_PB0MFP_I2C2_SCL          (0x03UL<<SYS_GPB_MFPL_PB0MFP_Pos)  /*!< GPB_MFPL PB0 setting for I2C2_SCL          */
#define SYS_GPB_MFPL_PB0MFP_ADC0_CH0          (0x08UL<<SYS_GPB_MFPL_PB0MFP_Pos)  /*!< GPB_MFPL PB0 setting for ADC0_CH0          */

/* PB.1 MFP */
#define SYS_GPB_MFPL_PB1MFP_GPIO              (0x00UL<<SYS_GPB_MFPL_PB1MFP_Pos)  /*!< GPB_MFPL PB1 setting for GPIO              */
#define SYS_GPB_MFPL_PB1MFP_EBI_ADR17         (0x01UL<<SYS_GPB_MFPL_PB1MFP_Pos)  /*!< GPB_MFPL PB1 setting for EBI_ADR17         */
#define SYS_GPB_MFPL_PB1MFP_I2C3_SDA          (0x02UL<<SYS_GPB_MFPL_PB1MFP_Pos)  /*!< GPB_MFPL PB1 setting for I2C3_SDA          */
#define SYS_GPB_MFPL_PB1MFP_I2S_MCLK          (0x03UL<<SYS_GPB_MFPL_PB1MFP_Pos)  /*!< GPB_MFPL PB1 setting for I2S_MCLK          */
#define SYS_GPB_MFPL_PB1MFP_CAN2_RXD          (0x04UL<<SYS_GPB_MFPL_PB1MFP_Pos)  /*!< GPB_MFPL PB1 setting for CAN2_RXD          */
#define SYS_GPB_MFPL_PB1MFP_TM0_EXT           (0x05UL<<SYS_GPB_MFPL_PB1MFP_Pos)  /*!< GPB_MFPL PB1 setting for TM0_EXT           */
#define SYS_GPB_MFPL_PB1MFP_SPI1_SS1          (0x06UL<<SYS_GPB_MFPL_PB1MFP_Pos)  /*!< GPB_MFPL PB1 setting for SPI1_SS1          */
#define SYS_GPB_MFPL_PB1MFP_UART9_TXD         (0x07UL<<SYS_GPB_MFPL_PB1MFP_Pos)  /*!< GPB_MFPL PB1 setting for UART9_TXD         */
#define SYS_GPB_MFPL_PB1MFP_ADC0_CH1          (0x08UL<<SYS_GPB_MFPL_PB1MFP_Pos)  /*!< GPB_MFPL PB1 setting for ADC0_CH1          */

/* PB.2 MFP */
#define SYS_GPB_MFPL_PB2MFP_GPIO              (0x00UL<<SYS_GPB_MFPL_PB2MFP_Pos)  /*!< GPB_MFPL PB2 setting for GPIO              */
#define SYS_GPB_MFPL_PB2MFP_EBI_ADR2          (0x01UL<<SYS_GPB_MFPL_PB2MFP_Pos)  /*!< GPB_MFPL PB2 setting for EBI_ADR2          */
#define SYS_GPB_MFPL_PB2MFP_CANFD3_RXD        (0x02UL<<SYS_GPB_MFPL_PB2MFP_Pos)  /*!< GPB_MFPL PB2 setting for CANFD3_RXD        */
#define SYS_GPB_MFPL_PB2MFP_UART9_nRTS        (0x07UL<<SYS_GPB_MFPL_PB2MFP_Pos)  /*!< GPB_MFPL PB2 setting for UART9_nRTS        */
#define SYS_GPB_MFPL_PB2MFP_ADC0_CH2          (0x08UL<<SYS_GPB_MFPL_PB2MFP_Pos)  /*!< GPB_MFPL PB2 setting for ADC0_CH2          */

/* PB.3 MFP */
#define SYS_GPB_MFPL_PB3MFP_GPIO              (0x00UL<<SYS_GPB_MFPL_PB3MFP_Pos)  /*!< GPB_MFPL PB3 setting for GPIO              */
#define SYS_GPB_MFPL_PB3MFP_EBI_ADR18         (0x01UL<<SYS_GPB_MFPL_PB3MFP_Pos)  /*!< GPB_MFPL PB3 setting for EBI_ADR18         */
#define SYS_GPB_MFPL_PB3MFP_I2C3_SCL          (0x02UL<<SYS_GPB_MFPL_PB3MFP_Pos)  /*!< GPB_MFPL PB3 setting for I2C3_SCL          */
#define SYS_GPB_MFPL_PB3MFP_INT2              (0x03UL<<SYS_GPB_MFPL_PB3MFP_Pos)  /*!< GPB_MFPL PB3 setting for INT2              */
#define SYS_GPB_MFPL_PB3MFP_CAN2_TXD          (0x04UL<<SYS_GPB_MFPL_PB3MFP_Pos)  /*!< GPB_MFPL PB3 setting for CAN2_TXD          */
#define SYS_GPB_MFPL_PB3MFP_TM0               (0x05UL<<SYS_GPB_MFPL_PB3MFP_Pos)  /*!< GPB_MFPL PB3 setting for TM0               */
#define SYS_GPB_MFPL_PB3MFP_SPI0_SS1          (0x06UL<<SYS_GPB_MFPL_PB3MFP_Pos)  /*!< GPB_MFPL PB3 setting for SPI0_SS1          */
#define SYS_GPB_MFPL_PB3MFP_UART9_RXD         (0x07UL<<SYS_GPB_MFPL_PB3MFP_Pos)  /*!< GPB_MFPL PB3 setting for UART9_RXD         */
#define SYS_GPB_MFPL_PB3MFP_ADC0_CH3          (0x08UL<<SYS_GPB_MFPL_PB3MFP_Pos)  /*!< GPB_MFPL PB3 setting for ADC0_CH3          */

/* PB.4 MFP */
#define SYS_GPB_MFPL_PB4MFP_GPIO              (0x00UL<<SYS_GPB_MFPL_PB4MFP_Pos)  /*!< GPB_MFPL PB4 setting for GPIO              */
#define SYS_GPB_MFPL_PB4MFP_EBI_ADR14         (0x01UL<<SYS_GPB_MFPL_PB4MFP_Pos)  /*!< GPB_MFPL PB4 setting for EBI_ADR14         */
#define SYS_GPB_MFPL_PB4MFP_I2C1_SCL          (0x02UL<<SYS_GPB_MFPL_PB4MFP_Pos)  /*!< GPB_MFPL PB4 setting for I2C1_SCL          */
#define SYS_GPB_MFPL_PB4MFP_I2S_BCLK          (0x03UL<<SYS_GPB_MFPL_PB4MFP_Pos)  /*!< GPB_MFPL PB4 setting for I2S_BCLK          */
#define SYS_GPB_MFPL_PB4MFP_UART7_RXD         (0x05UL<<SYS_GPB_MFPL_PB4MFP_Pos)  /*!< GPB_MFPL PB4 setting for UART7_RXD         */
#define SYS_GPB_MFPL_PB4MFP_SPI1_CLK          (0x06UL<<SYS_GPB_MFPL_PB4MFP_Pos)  /*!< GPB_MFPL PB4 setting for SPI1_CLK          */
#define SYS_GPB_MFPL_PB4MFP_ADC0_CH4          (0x08UL<<SYS_GPB_MFPL_PB4MFP_Pos)  /*!< GPB_MFPL PB4 setting for ADC0_CH4          */

/* PB.5 MFP */
#define SYS_GPB_MFPL_PB5MFP_GPIO              (0x00UL<<SYS_GPB_MFPL_PB5MFP_Pos)  /*!< GPB_MFPL PB5 setting for GPIO              */
#define SYS_GPB_MFPL_PB5MFP_EBI_ADR16         (0x01UL<<SYS_GPB_MFPL_PB5MFP_Pos)  /*!< GPB_MFPL PB5 setting for EBI_ADR16         */
#define SYS_GPB_MFPL_PB5MFP_I2C2_SCL          (0x02UL<<SYS_GPB_MFPL_PB5MFP_Pos)  /*!< GPB_MFPL PB5 setting for I2C2_SCL          */
#define SYS_GPB_MFPL_PB5MFP_I2S_DO            (0x03UL<<SYS_GPB_MFPL_PB5MFP_Pos)  /*!< GPB_MFPL PB5 setting for I2S_DO            */
#define SYS_GPB_MFPL_PB5MFP_UART7_nRTS        (0x05UL<<SYS_GPB_MFPL_PB5MFP_Pos)  /*!< GPB_MFPL PB5 setting for UART7_nRTS        */
#define SYS_GPB_MFPL_PB5MFP_SPI1_MISO         (0x06UL<<SYS_GPB_MFPL_PB5MFP_Pos)  /*!< GPB_MFPL PB5 setting for SPI1_MISO         */
#define SYS_GPB_MFPL_PB5MFP_ADC0_CH5          (0x08UL<<SYS_GPB_MFPL_PB5MFP_Pos)  /*!< GPB_MFPL PB5 setting for ADC0_CH5          */

/* PB.6 MFP */
#define SYS_GPB_MFPL_PB6MFP_GPIO              (0x00UL<<SYS_GPB_MFPL_PB6MFP_Pos)  /*!< GPB_MFPL PB6 setting for GPIO              */
#define SYS_GPB_MFPL_PB6MFP_EBI_ADR13         (0x01UL<<SYS_GPB_MFPL_PB6MFP_Pos)  /*!< GPB_MFPL PB6 setting for EBI_ADR13         */
#define SYS_GPB_MFPL_PB6MFP_I2C1_SDA          (0x02UL<<SYS_GPB_MFPL_PB6MFP_Pos)  /*!< GPB_MFPL PB6 setting for I2C1_SDA          */
#define SYS_GPB_MFPL_PB6MFP_I2S_LRCK          (0x03UL<<SYS_GPB_MFPL_PB6MFP_Pos)  /*!< GPB_MFPL PB6 setting for I2S_LRCK          */
#define SYS_GPB_MFPL_PB6MFP_UART7_TXD         (0x05UL<<SYS_GPB_MFPL_PB6MFP_Pos)  /*!< GPB_MFPL PB6 setting for UART7_TXD         */
#define SYS_GPB_MFPL_PB6MFP_SPI1_SS0          (0x06UL<<SYS_GPB_MFPL_PB6MFP_Pos)  /*!< GPB_MFPL PB6 setting for SPI1_SS0          */
#define SYS_GPB_MFPL_PB6MFP_ADC0_CH6          (0x08UL<<SYS_GPB_MFPL_PB6MFP_Pos)  /*!< GPB_MFPL PB6 setting for ADC0_CH6          */

/* PB.7 MFP */
#define SYS_GPB_MFPL_PB7MFP_GPIO              (0x00UL<<SYS_GPB_MFPL_PB7MFP_Pos)  /*!< GPB_MFPL PB7 setting for GPIO              */
#define SYS_GPB_MFPL_PB7MFP_EBI_ADR15         (0x01UL<<SYS_GPB_MFPL_PB7MFP_Pos)  /*!< GPB_MFPL PB7 setting for EBI_ADR15         */
#define SYS_GPB_MFPL_PB7MFP_I2C2_SDA          (0x02UL<<SYS_GPB_MFPL_PB7MFP_Pos)  /*!< GPB_MFPL PB7 setting for I2C2_SDA          */
#define SYS_GPB_MFPL_PB7MFP_I2S_DI            (0x03UL<<SYS_GPB_MFPL_PB7MFP_Pos)  /*!< GPB_MFPL PB7 setting for I2S_DI            */
#define SYS_GPB_MFPL_PB7MFP_UART7_nCTS        (0x05UL<<SYS_GPB_MFPL_PB7MFP_Pos)  /*!< GPB_MFPL PB7 setting for UART7_nCTS        */
#define SYS_GPB_MFPL_PB7MFP_SPI1_MOSI         (0x06UL<<SYS_GPB_MFPL_PB7MFP_Pos)  /*!< GPB_MFPL PB7 setting for SPI1_MOSI         */
#define SYS_GPB_MFPL_PB7MFP_ADC0_CH7          (0x08UL<<SYS_GPB_MFPL_PB7MFP_Pos)  /*!< GPB_MFPL PB7 setting for ADC0_CH7          */

/* PB.8 MFP */
#define SYS_GPB_MFPH_PB8MFP_GPIO              (0x00UL<<SYS_GPB_MFPH_PB8MFP_Pos)  /*!< GPB_MFPH PB8 setting for GPIO              */
#define SYS_GPB_MFPH_PB8MFP_EBI_ADR11         (0x01UL<<SYS_GPB_MFPH_PB8MFP_Pos)  /*!< GPB_MFPH PB8 setting for EBI_ADR11         */
#define SYS_GPB_MFPH_PB8MFP_I2C2_SCL          (0x02UL<<SYS_GPB_MFPH_PB8MFP_Pos)  /*!< GPB_MFPH PB8 setting for I2C2_SCL          */
#define SYS_GPB_MFPH_PB8MFP_CAN2_RXD          (0x03UL<<SYS_GPB_MFPH_PB8MFP_Pos)  /*!< GPB_MFPH PB8 setting for CAN2_RXD          */
#define SYS_GPB_MFPH_PB8MFP_UART8_TXD         (0x04UL<<SYS_GPB_MFPH_PB8MFP_Pos)  /*!< GPB_MFPH PB8 setting for UART8_TXD         */
#define SYS_GPB_MFPH_PB8MFP_UART9_nCTS        (0x05UL<<SYS_GPB_MFPH_PB8MFP_Pos)  /*!< GPB_MFPH PB8 setting for UART9_nCTS        */
#define SYS_GPB_MFPH_PB8MFP_SD0_nCD           (0x06UL<<SYS_GPB_MFPH_PB8MFP_Pos)  /*!< GPB_MFPH PB8 setting for SD0_nCD           */
#define SYS_GPB_MFPH_PB8MFP_TM0_EXT           (0x07UL<<SYS_GPB_MFPH_PB8MFP_Pos)  /*!< GPB_MFPH PB8 setting for TM0_EXT           */

/* PB.9 MFP */
#define SYS_GPB_MFPH_PB9MFP_GPIO              (0x00UL<<SYS_GPB_MFPH_PB9MFP_Pos)  /*!< GPB_MFPH PB9 setting for GPIO              */
#define SYS_GPB_MFPH_PB9MFP_UART3_TXD         (0x01UL<<SYS_GPB_MFPH_PB9MFP_Pos)  /*!< GPB_MFPH PB9 setting for UART3_TXD         */
#define SYS_GPB_MFPH_PB9MFP_BPWM1_CH3         (0x02UL<<SYS_GPB_MFPH_PB9MFP_Pos)  /*!< GPB_MFPH PB9 setting for BPWM1_CH3         */
#define SYS_GPB_MFPH_PB9MFP_TM0               (0x03UL<<SYS_GPB_MFPH_PB9MFP_Pos)  /*!< GPB_MFPH PB9 setting for TM0               */
#define SYS_GPB_MFPH_PB9MFP_CANFD0_RXD        (0x04UL<<SYS_GPB_MFPH_PB9MFP_Pos)  /*!< GPB_MFPH PB9 setting for CANFD0_RXD        */
#define SYS_GPB_MFPH_PB9MFP_SPI1_SS0          (0x05UL<<SYS_GPB_MFPH_PB9MFP_Pos)  /*!< GPB_MFPH PB9 setting for SPI1_SS0          */
#define SYS_GPB_MFPH_PB9MFP_SD1_DAT0          (0x06UL<<SYS_GPB_MFPH_PB9MFP_Pos)  /*!< GPB_MFPH PB9 setting for SD1_DAT0          */
#define SYS_GPB_MFPH_PB9MFP_eMMC1_DAT0        (0x06UL<<SYS_GPB_MFPH_PB9MFP_Pos)  /*!< GPB_MFPH PB9 setting for eMMC1_DAT0        */

/* PB.10 MFP */
#define SYS_GPB_MFPH_PB10MFP_GPIO             (0x00UL<<SYS_GPB_MFPH_PB10MFP_Pos)  /*!< GPB_MFPH PB10 setting for GPIO             */
#define SYS_GPB_MFPH_PB10MFP_UART3_RXD        (0x01UL<<SYS_GPB_MFPH_PB10MFP_Pos)  /*!< GPB_MFPH PB10 setting for UART3_RXD        */
#define SYS_GPB_MFPH_PB10MFP_BPWM1_CH2        (0x02UL<<SYS_GPB_MFPH_PB10MFP_Pos)  /*!< GPB_MFPH PB10 setting for BPWM1_CH2        */
#define SYS_GPB_MFPH_PB10MFP_TM0_EXT          (0x03UL<<SYS_GPB_MFPH_PB10MFP_Pos)  /*!< GPB_MFPH PB10 setting for TM0_EXT          */
#define SYS_GPB_MFPH_PB10MFP_CANFD0_TXD       (0x04UL<<SYS_GPB_MFPH_PB10MFP_Pos)  /*!< GPB_MFPH PB10 setting for CANFD0_TXD       */
#define SYS_GPB_MFPH_PB10MFP_SPI1_CLK         (0x05UL<<SYS_GPB_MFPH_PB10MFP_Pos)  /*!< GPB_MFPH PB10 setting for SPI1_CLK         */
#define SYS_GPB_MFPH_PB10MFP_SD1_DAT1         (0x06UL<<SYS_GPB_MFPH_PB10MFP_Pos)  /*!< GPB_MFPH PB10 setting for SD1_DAT1         */
#define SYS_GPB_MFPH_PB10MFP_eMMC1_DAT1       (0x06UL<<SYS_GPB_MFPH_PB10MFP_Pos)  /*!< GPB_MFPH PB10 setting for eMMC1_DAT1       */

/* PB.11 MFP */
#define SYS_GPB_MFPH_PB11MFP_GPIO             (0x00UL<<SYS_GPB_MFPH_PB11MFP_Pos)  /*!< GPB_MFPH PB11 setting for GPIO             */
#define SYS_GPB_MFPH_PB11MFP_UART3_nRTS       (0x01UL<<SYS_GPB_MFPH_PB11MFP_Pos)  /*!< GPB_MFPH PB11 setting for UART3_nRTS       */
#define SYS_GPB_MFPH_PB11MFP_BPWM1_CH1        (0x02UL<<SYS_GPB_MFPH_PB11MFP_Pos)  /*!< GPB_MFPH PB11 setting for BPWM1_CH1        */
#define SYS_GPB_MFPH_PB11MFP_TM2_EXT          (0x03UL<<SYS_GPB_MFPH_PB11MFP_Pos)  /*!< GPB_MFPH PB11 setting for TM2_EXT          */
#define SYS_GPB_MFPH_PB11MFP_CANFD1_RXD       (0x04UL<<SYS_GPB_MFPH_PB11MFP_Pos)  /*!< GPB_MFPH PB11 setting for CANFD1_RXD       */
#define SYS_GPB_MFPH_PB11MFP_SPI1_MOSI        (0x05UL<<SYS_GPB_MFPH_PB11MFP_Pos)  /*!< GPB_MFPH PB11 setting for SPI1_MOSI        */
#define SYS_GPB_MFPH_PB11MFP_SD1_DAT2         (0x06UL<<SYS_GPB_MFPH_PB11MFP_Pos)  /*!< GPB_MFPH PB11 setting for SD1_DAT2         */
#define SYS_GPB_MFPH_PB11MFP_eMMC1_DAT2       (0x06UL<<SYS_GPB_MFPH_PB11MFP_Pos)  /*!< GPB_MFPH PB11 setting for eMMC1_DAT2       */
#define SYS_GPB_MFPH_PB11MFP_I2C3_SMBAL       (0x08UL<<SYS_GPB_MFPH_PB11MFP_Pos)  /*!< GPB_MFPH PB11 setting for I2C3_SMBAL       */

/* PB.12 MFP */
#define SYS_GPB_MFPH_PB12MFP_GPIO             (0x00UL<<SYS_GPB_MFPH_PB12MFP_Pos)  /*!< GPB_MFPH PB12 setting for GPIO             */
#define SYS_GPB_MFPH_PB12MFP_UART3_nCTS       (0x01UL<<SYS_GPB_MFPH_PB12MFP_Pos)  /*!< GPB_MFPH PB12 setting for UART3_nCTS       */
#define SYS_GPB_MFPH_PB12MFP_BPWM1_CH0        (0x02UL<<SYS_GPB_MFPH_PB12MFP_Pos)  /*!< GPB_MFPH PB12 setting for BPWM1_CH0        */
#define SYS_GPB_MFPH_PB12MFP_TM2              (0x03UL<<SYS_GPB_MFPH_PB12MFP_Pos)  /*!< GPB_MFPH PB12 setting for TM2              */
#define SYS_GPB_MFPH_PB12MFP_CANFD1_TXD       (0x04UL<<SYS_GPB_MFPH_PB12MFP_Pos)  /*!< GPB_MFPH PB12 setting for CANFD1_TXD       */
#define SYS_GPB_MFPH_PB12MFP_SPI1_MISO        (0x05UL<<SYS_GPB_MFPH_PB12MFP_Pos)  /*!< GPB_MFPH PB12 setting for SPI1_MISO        */
#define SYS_GPB_MFPH_PB12MFP_SD1_DAT3         (0x06UL<<SYS_GPB_MFPH_PB12MFP_Pos)  /*!< GPB_MFPH PB12 setting for SD1_DAT3         */
#define SYS_GPB_MFPH_PB12MFP_eMMC1_DAT3       (0x06UL<<SYS_GPB_MFPH_PB12MFP_Pos)  /*!< GPB_MFPH PB12 setting for eMMC1_DAT3       */
#define SYS_GPB_MFPH_PB12MFP_I2C3_SMBSUS      (0x08UL<<SYS_GPB_MFPH_PB12MFP_Pos)  /*!< GPB_MFPH PB12 setting for I2C3_SMBSUS      */

/* PB.13 MFP */
#define SYS_GPB_MFPH_PB13MFP_GPIO             (0x00UL<<SYS_GPB_MFPH_PB13MFP_Pos)  /*!< GPB_MFPH PB13 setting for GPIO             */
#define SYS_GPB_MFPH_PB13MFP_EMAC1_RMII_PPS   (0x01UL<<SYS_GPB_MFPH_PB13MFP_Pos)  /*!< GPB_MFPH PB13 setting for EMAC1_RMII_PPS   */
#define SYS_GPB_MFPH_PB13MFP_INT2             (0x02UL<<SYS_GPB_MFPH_PB13MFP_Pos)  /*!< GPB_MFPH PB13 setting for INT2             */
#define SYS_GPB_MFPH_PB13MFP_TM4              (0x03UL<<SYS_GPB_MFPH_PB13MFP_Pos)  /*!< GPB_MFPH PB13 setting for TM4              */
#define SYS_GPB_MFPH_PB13MFP_BPWM0_CH2        (0x04UL<<SYS_GPB_MFPH_PB13MFP_Pos)  /*!< GPB_MFPH PB13 setting for BPWM0_CH2        */
#define SYS_GPB_MFPH_PB13MFP_UART3_TXD        (0x05UL<<SYS_GPB_MFPH_PB13MFP_Pos)  /*!< GPB_MFPH PB13 setting for UART3_TXD        */
#define SYS_GPB_MFPH_PB13MFP_SPI2_SS1         (0x07UL<<SYS_GPB_MFPH_PB13MFP_Pos)  /*!< GPB_MFPH PB13 setting for SPI2_SS1         */
#define SYS_GPB_MFPH_PB13MFP_EBI_AD0          (0x08UL<<SYS_GPB_MFPH_PB13MFP_Pos)  /*!< GPB_MFPH PB13 setting for EBI_AD0          */

/* PC.0 MFP */
#define SYS_GPC_MFPL_PC0MFP_GPIO              (0x00UL<<SYS_GPC_MFPL_PC0MFP_Pos)  /*!< GPC_MFPL PC0 setting for GPIO              */
#define SYS_GPC_MFPL_PC0MFP_EBI_AD0           (0x01UL<<SYS_GPC_MFPL_PC0MFP_Pos)  /*!< GPC_MFPL PC0 setting for EBI_AD0           */
#define SYS_GPC_MFPL_PC0MFP_I2C2_SDA          (0x02UL<<SYS_GPC_MFPL_PC0MFP_Pos)  /*!< GPC_MFPL PC0 setting for I2C2_SDA          */
#define SYS_GPC_MFPL_PC0MFP_CAN2_TXD          (0x03UL<<SYS_GPC_MFPL_PC0MFP_Pos)  /*!< GPC_MFPL PC0 setting for CAN2_TXD          */
#define SYS_GPC_MFPL_PC0MFP_UART8_RXD         (0x04UL<<SYS_GPC_MFPL_PC0MFP_Pos)  /*!< GPC_MFPL PC0 setting for UART8_RXD         */
#define SYS_GPC_MFPL_PC0MFP_SPI0_SS1          (0x05UL<<SYS_GPC_MFPL_PC0MFP_Pos)  /*!< GPC_MFPL PC0 setting for SPI0_SS1          */
#define SYS_GPC_MFPL_PC0MFP_TM0               (0x07UL<<SYS_GPC_MFPL_PC0MFP_Pos)  /*!< GPC_MFPL PC0 setting for TM0               */
#define SYS_GPC_MFPL_PC0MFP_SPI3_SS0          (0x08UL<<SYS_GPC_MFPL_PC0MFP_Pos)  /*!< GPC_MFPL PC0 setting for SPI3_SS0          */

/* PC.1 MFP */
#define SYS_GPC_MFPL_PC1MFP_GPIO              (0x00UL<<SYS_GPC_MFPL_PC1MFP_Pos)  /*!< GPC_MFPL PC1 setting for GPIO              */
#define SYS_GPC_MFPL_PC1MFP_EBI_AD1           (0x01UL<<SYS_GPC_MFPL_PC1MFP_Pos)  /*!< GPC_MFPL PC1 setting for EBI_AD1           */
#define SYS_GPC_MFPL_PC1MFP_NAND_nCS          (0x03UL<<SYS_GPC_MFPL_PC1MFP_Pos)  /*!< GPC_MFPL PC1 setting for NAND_nCS          */
#define SYS_GPC_MFPL_PC1MFP_UART7_TXD         (0x04UL<<SYS_GPC_MFPL_PC1MFP_Pos)  /*!< GPC_MFPL PC1 setting for UART7_TXD         */
#define SYS_GPC_MFPL_PC1MFP_UART3_nCTS        (0x05UL<<SYS_GPC_MFPL_PC1MFP_Pos)  /*!< GPC_MFPL PC1 setting for UART3_nCTS        */
#define SYS_GPC_MFPL_PC1MFP_SPI3_CLK          (0x08UL<<SYS_GPC_MFPL_PC1MFP_Pos)  /*!< GPC_MFPL PC1 setting for SPI3_CLK          */

/* PC.2 MFP */
#define SYS_GPC_MFPL_PC2MFP_GPIO              (0x00UL<<SYS_GPC_MFPL_PC2MFP_Pos)  /*!< GPC_MFPL PC2 setting for GPIO              */
#define SYS_GPC_MFPL_PC2MFP_EBI_AD2           (0x01UL<<SYS_GPC_MFPL_PC2MFP_Pos)  /*!< GPC_MFPL PC2 setting for EBI_AD2           */
#define SYS_GPC_MFPL_PC2MFP_NAND_nWP          (0x03UL<<SYS_GPC_MFPL_PC2MFP_Pos)  /*!< GPC_MFPL PC2 setting for NAND_nWP          */
#define SYS_GPC_MFPL_PC2MFP_UART7_RXD         (0x04UL<<SYS_GPC_MFPL_PC2MFP_Pos)  /*!< GPC_MFPL PC2 setting for UART7_RXD         */
#define SYS_GPC_MFPL_PC2MFP_UART3_nRTS        (0x05UL<<SYS_GPC_MFPL_PC2MFP_Pos)  /*!< GPC_MFPL PC2 setting for UART3_nRTS        */
#define SYS_GPC_MFPL_PC2MFP_SPI3_MOSI         (0x08UL<<SYS_GPC_MFPL_PC2MFP_Pos)  /*!< GPC_MFPL PC2 setting for SPI3_MOSI         */

/* PC.3 MFP */
#define SYS_GPC_MFPL_PC3MFP_GPIO              (0x00UL<<SYS_GPC_MFPL_PC3MFP_Pos)  /*!< GPC_MFPL PC3 setting for GPIO              */
#define SYS_GPC_MFPL_PC3MFP_EBI_AD3           (0x01UL<<SYS_GPC_MFPL_PC3MFP_Pos)  /*!< GPC_MFPL PC3 setting for EBI_AD3           */
#define SYS_GPC_MFPL_PC3MFP_NAND_ALE          (0x03UL<<SYS_GPC_MFPL_PC3MFP_Pos)  /*!< GPC_MFPL PC3 setting for NAND_ALE          */
#define SYS_GPC_MFPL_PC3MFP_I2C1_SCL          (0x04UL<<SYS_GPC_MFPL_PC3MFP_Pos)  /*!< GPC_MFPL PC3 setting for I2C1_SCL          */
#define SYS_GPC_MFPL_PC3MFP_UART3_TXD         (0x05UL<<SYS_GPC_MFPL_PC3MFP_Pos)  /*!< GPC_MFPL PC3 setting for UART3_TXD         */
#define SYS_GPC_MFPL_PC3MFP_CAN0_RXD          (0x07UL<<SYS_GPC_MFPL_PC3MFP_Pos)  /*!< GPC_MFPL PC3 setting for CAN0_RXD          */
#define SYS_GPC_MFPL_PC3MFP_SPI3_MISO         (0x08UL<<SYS_GPC_MFPL_PC3MFP_Pos)  /*!< GPC_MFPL PC3 setting for SPI3_MISO         */

/* PC.4 MFP */
#define SYS_GPC_MFPL_PC4MFP_GPIO              (0x00UL<<SYS_GPC_MFPL_PC4MFP_Pos)  /*!< GPC_MFPL PC4 setting for GPIO              */
#define SYS_GPC_MFPL_PC4MFP_EBI_AD4           (0x01UL<<SYS_GPC_MFPL_PC4MFP_Pos)  /*!< GPC_MFPL PC4 setting for EBI_AD4           */
#define SYS_GPC_MFPL_PC4MFP_NAND_CLE          (0x03UL<<SYS_GPC_MFPL_PC4MFP_Pos)  /*!< GPC_MFPL PC4 setting for NAND_CLE          */
#define SYS_GPC_MFPL_PC4MFP_I2C1_SDA          (0x04UL<<SYS_GPC_MFPL_PC4MFP_Pos)  /*!< GPC_MFPL PC4 setting for I2C1_SDA          */
#define SYS_GPC_MFPL_PC4MFP_UART3_RXD         (0x05UL<<SYS_GPC_MFPL_PC4MFP_Pos)  /*!< GPC_MFPL PC4 setting for UART3_RXD         */
#define SYS_GPC_MFPL_PC4MFP_SPI0_MOSI         (0x06UL<<SYS_GPC_MFPL_PC4MFP_Pos)  /*!< GPC_MFPL PC4 setting for SPI0_MOSI         */
#define SYS_GPC_MFPL_PC4MFP_CAN0_TXD          (0x07UL<<SYS_GPC_MFPL_PC4MFP_Pos)  /*!< GPC_MFPL PC4 setting for CAN0_TXD          */

/* PC.5 MFP */
#define SYS_GPC_MFPL_PC5MFP_GPIO              (0x00UL<<SYS_GPC_MFPL_PC5MFP_Pos)  /*!< GPC_MFPL PC5 setting for GPIO              */
#define SYS_GPC_MFPL_PC5MFP_EBI_AD5           (0x01UL<<SYS_GPC_MFPL_PC5MFP_Pos)  /*!< GPC_MFPL PC5 setting for EBI_AD5           */
#define SYS_GPC_MFPL_PC5MFP_NAND_nWE          (0x03UL<<SYS_GPC_MFPL_PC5MFP_Pos)  /*!< GPC_MFPL PC5 setting for NAND_nWE          */
#define SYS_GPC_MFPL_PC5MFP_SPI0_SS0          (0x05UL<<SYS_GPC_MFPL_PC5MFP_Pos)  /*!< GPC_MFPL PC5 setting for SPI0_SS0          */
#define SYS_GPC_MFPL_PC5MFP_SD0_CMD           (0x06UL<<SYS_GPC_MFPL_PC5MFP_Pos)  /*!< GPC_MFPL PC5 setting for SD0_CMD           */
#define SYS_GPC_MFPL_PC5MFP_eMMC0_CMD         (0x06UL<<SYS_GPC_MFPL_PC5MFP_Pos)  /*!< GPC_MFPL PC5 setting for eMMC0_CMD         */
#define SYS_GPC_MFPL_PC5MFP_UART1_TXD         (0x07UL<<SYS_GPC_MFPL_PC5MFP_Pos)  /*!< GPC_MFPL PC5 setting for UART1_TXD         */
#define SYS_GPC_MFPL_PC5MFP_UART7_nCTS        (0x08UL<<SYS_GPC_MFPL_PC5MFP_Pos)  /*!< GPC_MFPL PC5 setting for UART7_nCTS        */

/* PC.6 MFP */
#define SYS_GPC_MFPL_PC6MFP_GPIO              (0x00UL<<SYS_GPC_MFPL_PC6MFP_Pos)  /*!< GPC_MFPL PC6 setting for GPIO              */
#define SYS_GPC_MFPL_PC6MFP_EBI_AD6           (0x01UL<<SYS_GPC_MFPL_PC6MFP_Pos)  /*!< GPC_MFPL PC6 setting for EBI_AD6           */
#define SYS_GPC_MFPL_PC6MFP_NAND_nRE          (0x03UL<<SYS_GPC_MFPL_PC6MFP_Pos)  /*!< GPC_MFPL PC6 setting for NAND_nRE          */
#define SYS_GPC_MFPL_PC6MFP_SC1_RST           (0x04UL<<SYS_GPC_MFPL_PC6MFP_Pos)  /*!< GPC_MFPL PC6 setting for SC1_RST           */
#define SYS_GPC_MFPL_PC6MFP_SPI0_CLK          (0x05UL<<SYS_GPC_MFPL_PC6MFP_Pos)  /*!< GPC_MFPL PC6 setting for SPI0_CLK          */
#define SYS_GPC_MFPL_PC6MFP_SD0_CLK           (0x06UL<<SYS_GPC_MFPL_PC6MFP_Pos)  /*!< GPC_MFPL PC6 setting for SD0_CLK           */
#define SYS_GPC_MFPL_PC6MFP_eMMC0_CLK         (0x06UL<<SYS_GPC_MFPL_PC6MFP_Pos)  /*!< GPC_MFPL PC6 setting for eMMC0_CLK         */
#define SYS_GPC_MFPL_PC6MFP_UART1_RXD         (0x07UL<<SYS_GPC_MFPL_PC6MFP_Pos)  /*!< GPC_MFPL PC6 setting for UART1_RXD         */

/* PC.7 MFP */
#define SYS_GPC_MFPL_PC7MFP_GPIO              (0x00UL<<SYS_GPC_MFPL_PC7MFP_Pos)  /*!< GPC_MFPL PC7 setting for GPIO              */
#define SYS_GPC_MFPL_PC7MFP_EBI_AD7           (0x01UL<<SYS_GPC_MFPL_PC7MFP_Pos)  /*!< GPC_MFPL PC7 setting for EBI_AD7           */
#define SYS_GPC_MFPL_PC7MFP_CANFD3_TXD        (0x02UL<<SYS_GPC_MFPL_PC7MFP_Pos)  /*!< GPC_MFPL PC7 setting for CANFD3_TXD        */
#define SYS_GPC_MFPL_PC7MFP_NAND_RDY          (0x03UL<<SYS_GPC_MFPL_PC7MFP_Pos)  /*!< GPC_MFPL PC7 setting for NAND_RDY          */
#define SYS_GPC_MFPL_PC7MFP_SC1_CLK           (0x04UL<<SYS_GPC_MFPL_PC7MFP_Pos)  /*!< GPC_MFPL PC7 setting for SC1_CLK           */
#define SYS_GPC_MFPL_PC7MFP_SPI0_MOSI         (0x05UL<<SYS_GPC_MFPL_PC7MFP_Pos)  /*!< GPC_MFPL PC7 setting for SPI0_MOSI         */
#define SYS_GPC_MFPL_PC7MFP_SD0_DAT0          (0x06UL<<SYS_GPC_MFPL_PC7MFP_Pos)  /*!< GPC_MFPL PC7 setting for SD0_DAT0          */
#define SYS_GPC_MFPL_PC7MFP_eMMC0_DAT0        (0x06UL<<SYS_GPC_MFPL_PC7MFP_Pos)  /*!< GPC_MFPL PC7 setting for eMMC0_DAT0        */
#define SYS_GPC_MFPL_PC7MFP_UART1_nRTS        (0x07UL<<SYS_GPC_MFPL_PC7MFP_Pos)  /*!< GPC_MFPL PC7 setting for UART1_nRTS        */

/* PC.8 MFP */
#define SYS_GPC_MFPH_PC8MFP_GPIO              (0x00UL<<SYS_GPC_MFPH_PC8MFP_Pos)  /*!< GPC_MFPH PC8 setting for GPIO              */
#define SYS_GPC_MFPH_PC8MFP_EBI_AD8           (0x01UL<<SYS_GPC_MFPH_PC8MFP_Pos)  /*!< GPC_MFPH PC8 setting for EBI_AD8           */
#define SYS_GPC_MFPH_PC8MFP_CANFD2_RXD        (0x02UL<<SYS_GPC_MFPH_PC8MFP_Pos)  /*!< GPC_MFPH PC8 setting for CANFD2_RXD        */
#define SYS_GPC_MFPH_PC8MFP_NAND_DATA0        (0x03UL<<SYS_GPC_MFPH_PC8MFP_Pos)  /*!< GPC_MFPH PC8 setting for NAND_DATA0        */
#define SYS_GPC_MFPH_PC8MFP_SC1_DAT           (0x04UL<<SYS_GPC_MFPH_PC8MFP_Pos)  /*!< GPC_MFPH PC8 setting for SC1_DAT           */
#define SYS_GPC_MFPH_PC8MFP_SPI0_MISO         (0x05UL<<SYS_GPC_MFPH_PC8MFP_Pos)  /*!< GPC_MFPH PC8 setting for SPI0_MISO         */
#define SYS_GPC_MFPH_PC8MFP_SD0_DAT1          (0x06UL<<SYS_GPC_MFPH_PC8MFP_Pos)  /*!< GPC_MFPH PC8 setting for SD0_DAT1          */
#define SYS_GPC_MFPH_PC8MFP_eMMC0_DAT1        (0x06UL<<SYS_GPC_MFPH_PC8MFP_Pos)  /*!< GPC_MFPH PC8 setting for eMMC0_DAT1        */
#define SYS_GPC_MFPH_PC8MFP_UART1_nCTS        (0x07UL<<SYS_GPC_MFPH_PC8MFP_Pos)  /*!< GPC_MFPH PC8 setting for UART1_nCTS        */

/* PC.9 MFP */
#define SYS_GPC_MFPH_PC9MFP_GPIO              (0x00UL<<SYS_GPC_MFPH_PC9MFP_Pos)  /*!< GPC_MFPH PC9 setting for GPIO              */
#define SYS_GPC_MFPH_PC9MFP_EBI_AD9           (0x01UL<<SYS_GPC_MFPH_PC9MFP_Pos)  /*!< GPC_MFPH PC9 setting for EBI_AD9           */
#define SYS_GPC_MFPH_PC9MFP_CANFD2_TXD        (0x02UL<<SYS_GPC_MFPH_PC9MFP_Pos)  /*!< GPC_MFPH PC9 setting for CANFD2_TXD        */
#define SYS_GPC_MFPH_PC9MFP_NAND_DATA1        (0x03UL<<SYS_GPC_MFPH_PC9MFP_Pos)  /*!< GPC_MFPH PC9 setting for NAND_DATA1        */
#define SYS_GPC_MFPH_PC9MFP_SC1_PWR           (0x04UL<<SYS_GPC_MFPH_PC9MFP_Pos)  /*!< GPC_MFPH PC9 setting for SC1_PWR           */
#define SYS_GPC_MFPH_PC9MFP_I2C0_SMBAL        (0x05UL<<SYS_GPC_MFPH_PC9MFP_Pos)  /*!< GPC_MFPH PC9 setting for I2C0_SMBAL        */
#define SYS_GPC_MFPH_PC9MFP_SD0_DAT2          (0x06UL<<SYS_GPC_MFPH_PC9MFP_Pos)  /*!< GPC_MFPH PC9 setting for SD0_DAT2          */
#define SYS_GPC_MFPH_PC9MFP_eMMC0_DAT2        (0x06UL<<SYS_GPC_MFPH_PC9MFP_Pos)  /*!< GPC_MFPH PC9 setting for eMMC0_DAT2        */
#define SYS_GPC_MFPH_PC9MFP_UART4_TXD         (0x07UL<<SYS_GPC_MFPH_PC9MFP_Pos)  /*!< GPC_MFPH PC9 setting for UART4_TXD         */

/* PC.10 MFP */
#define SYS_GPC_MFPH_PC10MFP_GPIO             (0x00UL<<SYS_GPC_MFPH_PC10MFP_Pos)  /*!< GPC_MFPH PC10 setting for GPIO             */
#define SYS_GPC_MFPH_PC10MFP_EBI_AD10         (0x01UL<<SYS_GPC_MFPH_PC10MFP_Pos)  /*!< GPC_MFPH PC10 setting for EBI_AD10         */
#define SYS_GPC_MFPH_PC10MFP_CANFD3_RXD       (0x02UL<<SYS_GPC_MFPH_PC10MFP_Pos)  /*!< GPC_MFPH PC10 setting for CANFD3_RXD       */
#define SYS_GPC_MFPH_PC10MFP_NAND_DATA2       (0x03UL<<SYS_GPC_MFPH_PC10MFP_Pos)  /*!< GPC_MFPH PC10 setting for NAND_DATA2       */
#define SYS_GPC_MFPH_PC10MFP_SC1_nCD          (0x04UL<<SYS_GPC_MFPH_PC10MFP_Pos)  /*!< GPC_MFPH PC10 setting for SC1_nCD          */
#define SYS_GPC_MFPH_PC10MFP_I2C0_SMBSUS      (0x05UL<<SYS_GPC_MFPH_PC10MFP_Pos)  /*!< GPC_MFPH PC10 setting for I2C0_SMBSUS      */
#define SYS_GPC_MFPH_PC10MFP_SD0_DAT3         (0x06UL<<SYS_GPC_MFPH_PC10MFP_Pos)  /*!< GPC_MFPH PC10 setting for SD0_DAT3         */
#define SYS_GPC_MFPH_PC10MFP_eMMC0_DAT3       (0x06UL<<SYS_GPC_MFPH_PC10MFP_Pos)  /*!< GPC_MFPH PC10 setting for eMMC0_DAT3       */
#define SYS_GPC_MFPH_PC10MFP_UART4_RXD        (0x07UL<<SYS_GPC_MFPH_PC10MFP_Pos)  /*!< GPC_MFPH PC10 setting for UART4_RXD        */
#define SYS_GPC_MFPH_PC10MFP_SPI3_SS0         (0x08UL<<SYS_GPC_MFPH_PC10MFP_Pos)  /*!< GPC_MFPH PC10 setting for SPI3_SS0         */

/* PC.11 MFP */
#define SYS_GPC_MFPH_PC11MFP_GPIO             (0x00UL<<SYS_GPC_MFPH_PC11MFP_Pos)  /*!< GPC_MFPH PC11 setting for GPIO             */
#define SYS_GPC_MFPH_PC11MFP_EBI_AD11         (0x01UL<<SYS_GPC_MFPH_PC11MFP_Pos)  /*!< GPC_MFPH PC11 setting for EBI_AD11         */
#define SYS_GPC_MFPH_PC11MFP_CANFD3_TXD       (0x02UL<<SYS_GPC_MFPH_PC11MFP_Pos)  /*!< GPC_MFPH PC11 setting for CANFD3_TXD       */
#define SYS_GPC_MFPH_PC11MFP_NAND_DATA3       (0x03UL<<SYS_GPC_MFPH_PC11MFP_Pos)  /*!< GPC_MFPH PC11 setting for NAND_DATA3       */
#define SYS_GPC_MFPH_PC11MFP_SC0_RST          (0x04UL<<SYS_GPC_MFPH_PC11MFP_Pos)  /*!< GPC_MFPH PC11 setting for SC0_RST          */
#define SYS_GPC_MFPH_PC11MFP_I2C1_SMBAL       (0x05UL<<SYS_GPC_MFPH_PC11MFP_Pos)  /*!< GPC_MFPH PC11 setting for I2C1_SMBAL       */
#define SYS_GPC_MFPH_PC11MFP_UART7_nRTS       (0x07UL<<SYS_GPC_MFPH_PC11MFP_Pos)  /*!< GPC_MFPH PC11 setting for UART7_nRTS       */
#define SYS_GPC_MFPH_PC11MFP_SPI3_CLK         (0x08UL<<SYS_GPC_MFPH_PC11MFP_Pos)  /*!< GPC_MFPH PC11 setting for SPI3_CLK         */

/* PC.12 MFP */
#define SYS_GPC_MFPH_PC12MFP_GPIO             (0x00UL<<SYS_GPC_MFPH_PC12MFP_Pos)  /*!< GPC_MFPH PC12 setting for GPIO             */
#define SYS_GPC_MFPH_PC12MFP_EBI_AD12         (0x01UL<<SYS_GPC_MFPH_PC12MFP_Pos)  /*!< GPC_MFPH PC12 setting for EBI_AD12         */
#define SYS_GPC_MFPH_PC12MFP_CANFD0_RXD       (0x02UL<<SYS_GPC_MFPH_PC12MFP_Pos)  /*!< GPC_MFPH PC12 setting for CANFD0_RXD       */
#define SYS_GPC_MFPH_PC12MFP_NAND_DATA4       (0x03UL<<SYS_GPC_MFPH_PC12MFP_Pos)  /*!< GPC_MFPH PC12 setting for NAND_DATA4       */
#define SYS_GPC_MFPH_PC12MFP_SC0_CLK          (0x04UL<<SYS_GPC_MFPH_PC12MFP_Pos)  /*!< GPC_MFPH PC12 setting for SC0_CLK          */
#define SYS_GPC_MFPH_PC12MFP_SD0_nCD          (0x06UL<<SYS_GPC_MFPH_PC12MFP_Pos)  /*!< GPC_MFPH PC12 setting for SD0_nCD          */
#define SYS_GPC_MFPH_PC12MFP_UART8_TXD        (0x07UL<<SYS_GPC_MFPH_PC12MFP_Pos)  /*!< GPC_MFPH PC12 setting for UART8_TXD        */
#define SYS_GPC_MFPH_PC12MFP_SPI3_MOSI        (0x08UL<<SYS_GPC_MFPH_PC12MFP_Pos)  /*!< GPC_MFPH PC12 setting for SPI3_MOSI        */

/* PC.13 MFP */
#define SYS_GPC_MFPH_PC13MFP_GPIO             (0x00UL<<SYS_GPC_MFPH_PC13MFP_Pos)  /*!< GPC_MFPH PC13 setting for GPIO             */
#define SYS_GPC_MFPH_PC13MFP_EBI_AD13         (0x01UL<<SYS_GPC_MFPH_PC13MFP_Pos)  /*!< GPC_MFPH PC13 setting for EBI_AD13         */
#define SYS_GPC_MFPH_PC13MFP_CANFD0_TXD       (0x02UL<<SYS_GPC_MFPH_PC13MFP_Pos)  /*!< GPC_MFPH PC13 setting for CANFD0_TXD       */
#define SYS_GPC_MFPH_PC13MFP_NAND_DATA5       (0x03UL<<SYS_GPC_MFPH_PC13MFP_Pos)  /*!< GPC_MFPH PC13 setting for NAND_DATA5       */
#define SYS_GPC_MFPH_PC13MFP_SC0_DAT          (0x04UL<<SYS_GPC_MFPH_PC13MFP_Pos)  /*!< GPC_MFPH PC13 setting for SC0_DAT          */
#define SYS_GPC_MFPH_PC13MFP_UART8_RXD        (0x07UL<<SYS_GPC_MFPH_PC13MFP_Pos)  /*!< GPC_MFPH PC13 setting for UART8_RXD        */
#define SYS_GPC_MFPH_PC13MFP_SPI3_MISO        (0x08UL<<SYS_GPC_MFPH_PC13MFP_Pos)  /*!< GPC_MFPH PC13 setting for SPI3_MISO        */

/* PC.14 MFP */
#define SYS_GPC_MFPH_PC14MFP_GPIO             (0x00UL<<SYS_GPC_MFPH_PC14MFP_Pos)  /*!< GPC_MFPH PC14 setting for GPIO             */
#define SYS_GPC_MFPH_PC14MFP_EBI_AD14         (0x01UL<<SYS_GPC_MFPH_PC14MFP_Pos)  /*!< GPC_MFPH PC14 setting for EBI_AD14         */
#define SYS_GPC_MFPH_PC14MFP_CANFD1_RXD       (0x02UL<<SYS_GPC_MFPH_PC14MFP_Pos)  /*!< GPC_MFPH PC14 setting for CANFD1_RXD       */
#define SYS_GPC_MFPH_PC14MFP_NAND_DATA6       (0x03UL<<SYS_GPC_MFPH_PC14MFP_Pos)  /*!< GPC_MFPH PC14 setting for NAND_DATA6       */
#define SYS_GPC_MFPH_PC14MFP_SC0_PWR          (0x04UL<<SYS_GPC_MFPH_PC14MFP_Pos)  /*!< GPC_MFPH PC14 setting for SC0_PWR          */
#define SYS_GPC_MFPH_PC14MFP_SPI0_MOSI        (0x05UL<<SYS_GPC_MFPH_PC14MFP_Pos)  /*!< GPC_MFPH PC14 setting for SPI0_MOSI        */
#define SYS_GPC_MFPH_PC14MFP_UART8_nRTS       (0x07UL<<SYS_GPC_MFPH_PC14MFP_Pos)  /*!< GPC_MFPH PC14 setting for UART8_nRTS       */

/* PC.15 MFP */
#define SYS_GPC_MFPH_PC15MFP_GPIO             (0x00UL<<SYS_GPC_MFPH_PC15MFP_Pos)  /*!< GPC_MFPH PC15 setting for GPIO             */
#define SYS_GPC_MFPH_PC15MFP_EBI_AD15         (0x01UL<<SYS_GPC_MFPH_PC15MFP_Pos)  /*!< GPC_MFPH PC15 setting for EBI_AD15         */
#define SYS_GPC_MFPH_PC15MFP_CANFD1_TXD       (0x02UL<<SYS_GPC_MFPH_PC15MFP_Pos)  /*!< GPC_MFPH PC15 setting for CANFD1_TXD       */
#define SYS_GPC_MFPH_PC15MFP_NAND_DATA7       (0x03UL<<SYS_GPC_MFPH_PC15MFP_Pos)  /*!< GPC_MFPH PC15 setting for NAND_DATA7       */
#define SYS_GPC_MFPH_PC15MFP_SC0_nCD          (0x04UL<<SYS_GPC_MFPH_PC15MFP_Pos)  /*!< GPC_MFPH PC15 setting for SC0_nCD          */
#define SYS_GPC_MFPH_PC15MFP_I2C1_SMBSUS      (0x05UL<<SYS_GPC_MFPH_PC15MFP_Pos)  /*!< GPC_MFPH PC15 setting for I2C1_SMBSUS      */
#define SYS_GPC_MFPH_PC15MFP_UART8_nCTS       (0x07UL<<SYS_GPC_MFPH_PC15MFP_Pos)  /*!< GPC_MFPH PC15 setting for UART8_nCTS       */
#define SYS_GPC_MFPH_PC15MFP_SPI3_SS1         (0x08UL<<SYS_GPC_MFPH_PC15MFP_Pos)  /*!< GPC_MFPH PC15 setting for SPI3_SS1         */

/* PD.0 MFP */
#define SYS_GPD_MFPL_PD0MFP_GPIO              (0x00UL<<SYS_GPD_MFPL_PD0MFP_Pos)  /*!< GPD_MFPL PD0 setting for GPIO              */
#define SYS_GPD_MFPL_PD0MFP_QSPI0_SS1         (0x01UL<<SYS_GPD_MFPL_PD0MFP_Pos)  /*!< GPD_MFPL PD0 setting for QSPI0_SS1         */
#define SYS_GPD_MFPL_PD0MFP_UART5_TXD         (0x02UL<<SYS_GPD_MFPL_PD0MFP_Pos)  /*!< GPD_MFPL PD0 setting for UART5_TXD         */
#define SYS_GPD_MFPL_PD0MFP_TM1               (0x03UL<<SYS_GPD_MFPL_PD0MFP_Pos)  /*!< GPD_MFPL PD0 setting for TM1               */
#define SYS_GPD_MFPL_PD0MFP_INT2              (0x04UL<<SYS_GPD_MFPL_PD0MFP_Pos)  /*!< GPD_MFPL PD0 setting for INT2              */
#define SYS_GPD_MFPL_PD0MFP_CANFD2_RXD        (0x06UL<<SYS_GPD_MFPL_PD0MFP_Pos)  /*!< GPD_MFPL PD0 setting for CANFD2_RXD        */
#define SYS_GPD_MFPL_PD0MFP_SPI2_SS0          (0x07UL<<SYS_GPD_MFPL_PD0MFP_Pos)  /*!< GPD_MFPL PD0 setting for SPI2_SS0          */
#define SYS_GPD_MFPL_PD0MFP_I2C2_SMBAL        (0x08UL<<SYS_GPD_MFPL_PD0MFP_Pos)  /*!< GPD_MFPL PD0 setting for I2C2_SMBAL        */

/* PD.1 MFP */
#define SYS_GPD_MFPL_PD1MFP_GPIO              (0x00UL<<SYS_GPD_MFPL_PD1MFP_Pos)  /*!< GPD_MFPL PD1 setting for GPIO              */
#define SYS_GPD_MFPL_PD1MFP_SPI0_SS1          (0x01UL<<SYS_GPD_MFPL_PD1MFP_Pos)  /*!< GPD_MFPL PD1 setting for SPI0_SS1          */
#define SYS_GPD_MFPL_PD1MFP_UART5_RXD         (0x02UL<<SYS_GPD_MFPL_PD1MFP_Pos)  /*!< GPD_MFPL PD1 setting for UART5_RXD         */
#define SYS_GPD_MFPL_PD1MFP_TM1_EXT           (0x03UL<<SYS_GPD_MFPL_PD1MFP_Pos)  /*!< GPD_MFPL PD1 setting for TM1_EXT           */
#define SYS_GPD_MFPL_PD1MFP_INT3              (0x04UL<<SYS_GPD_MFPL_PD1MFP_Pos)  /*!< GPD_MFPL PD1 setting for INT3              */
#define SYS_GPD_MFPL_PD1MFP_CANFD2_TXD        (0x06UL<<SYS_GPD_MFPL_PD1MFP_Pos)  /*!< GPD_MFPL PD1 setting for CANFD2_TXD        */
#define SYS_GPD_MFPL_PD1MFP_I2C2_SMBSUS       (0x08UL<<SYS_GPD_MFPL_PD1MFP_Pos)  /*!< GPD_MFPL PD1 setting for I2C2_SMBSUS       */

/* PD.2 MFP */
#define SYS_GPD_MFPL_PD2MFP_GPIO              (0x00UL<<SYS_GPD_MFPL_PD2MFP_Pos)  /*!< GPD_MFPL PD2 setting for GPIO              */
#define SYS_GPD_MFPL_PD2MFP_QSPI0_SS0         (0x01UL<<SYS_GPD_MFPL_PD2MFP_Pos)  /*!< GPD_MFPL PD2 setting for QSPI0_SS0         */
#define SYS_GPD_MFPL_PD2MFP_UART3_TXD         (0x02UL<<SYS_GPD_MFPL_PD2MFP_Pos)  /*!< GPD_MFPL PD2 setting for UART3_TXD         */
#define SYS_GPD_MFPL_PD2MFP_TM4_EXT           (0x03UL<<SYS_GPD_MFPL_PD2MFP_Pos)  /*!< GPD_MFPL PD2 setting for TM4_EXT           */

/* PD.3 MFP */
#define SYS_GPD_MFPL_PD3MFP_GPIO              (0x00UL<<SYS_GPD_MFPL_PD3MFP_Pos)  /*!< GPD_MFPL PD3 setting for GPIO              */
#define SYS_GPD_MFPL_PD3MFP_QSPI0_CLK         (0x01UL<<SYS_GPD_MFPL_PD3MFP_Pos)  /*!< GPD_MFPL PD3 setting for QSPI0_CLK         */
#define SYS_GPD_MFPL_PD3MFP_UART3_RXD         (0x02UL<<SYS_GPD_MFPL_PD3MFP_Pos)  /*!< GPD_MFPL PD3 setting for UART3_RXD         */
#define SYS_GPD_MFPL_PD3MFP_TM4               (0x03UL<<SYS_GPD_MFPL_PD3MFP_Pos)  /*!< GPD_MFPL PD3 setting for TM4               */

/* PD.4 MFP */
#define SYS_GPD_MFPL_PD4MFP_GPIO              (0x00UL<<SYS_GPD_MFPL_PD4MFP_Pos)  /*!< GPD_MFPL PD4 setting for GPIO              */
#define SYS_GPD_MFPL_PD4MFP_QSPI0_MOSI0       (0x01UL<<SYS_GPD_MFPL_PD4MFP_Pos)  /*!< GPD_MFPL PD4 setting for QSPI0_MOSI0       */
#define SYS_GPD_MFPL_PD4MFP_UART3_nRTS        (0x02UL<<SYS_GPD_MFPL_PD4MFP_Pos)  /*!< GPD_MFPL PD4 setting for UART3_nRTS        */
#define SYS_GPD_MFPL_PD4MFP_TM5_EXT           (0x03UL<<SYS_GPD_MFPL_PD4MFP_Pos)  /*!< GPD_MFPL PD4 setting for TM5_EXT           */
#define SYS_GPD_MFPL_PD4MFP_CANFD2_RXD        (0x06UL<<SYS_GPD_MFPL_PD4MFP_Pos)  /*!< GPD_MFPL PD4 setting for CANFD2_RXD        */

/* PD.5 MFP */
#define SYS_GPD_MFPL_PD5MFP_GPIO              (0x00UL<<SYS_GPD_MFPL_PD5MFP_Pos)  /*!< GPD_MFPL PD5 setting for GPIO              */
#define SYS_GPD_MFPL_PD5MFP_QSPI0_MISO0       (0x01UL<<SYS_GPD_MFPL_PD5MFP_Pos)  /*!< GPD_MFPL PD5 setting for QSPI0_MISO0       */
#define SYS_GPD_MFPL_PD5MFP_UART3_nCTS        (0x02UL<<SYS_GPD_MFPL_PD5MFP_Pos)  /*!< GPD_MFPL PD5 setting for UART3_nCTS        */
#define SYS_GPD_MFPL_PD5MFP_TM5               (0x03UL<<SYS_GPD_MFPL_PD5MFP_Pos)  /*!< GPD_MFPL PD5 setting for TM5               */
#define SYS_GPD_MFPL_PD5MFP_CANFD2_TXD        (0x06UL<<SYS_GPD_MFPL_PD5MFP_Pos)  /*!< GPD_MFPL PD5 setting for CANFD2_TXD        */

/* PD.6 MFP */
#define SYS_GPD_MFPL_PD6MFP_GPIO              (0x00UL<<SYS_GPD_MFPL_PD6MFP_Pos)  /*!< GPD_MFPL PD6 setting for GPIO              */
#define SYS_GPD_MFPL_PD6MFP_QSPI0_MOSI1       (0x01UL<<SYS_GPD_MFPL_PD6MFP_Pos)  /*!< GPD_MFPL PD6 setting for QSPI0_MOSI1       */
#define SYS_GPD_MFPL_PD6MFP_UART2_TXD         (0x02UL<<SYS_GPD_MFPL_PD6MFP_Pos)  /*!< GPD_MFPL PD6 setting for UART2_TXD         */
#define SYS_GPD_MFPL_PD6MFP_CAN0_RXD          (0x04UL<<SYS_GPD_MFPL_PD6MFP_Pos)  /*!< GPD_MFPL PD6 setting for CAN0_RXD          */

/* PD.7 MFP */
#define SYS_GPD_MFPL_PD7MFP_GPIO              (0x00UL<<SYS_GPD_MFPL_PD7MFP_Pos)  /*!< GPD_MFPL PD7 setting for GPIO              */
#define SYS_GPD_MFPL_PD7MFP_QSPI0_MISO1       (0x01UL<<SYS_GPD_MFPL_PD7MFP_Pos)  /*!< GPD_MFPL PD7 setting for QSPI0_MISO1       */
#define SYS_GPD_MFPL_PD7MFP_UART2_RXD         (0x02UL<<SYS_GPD_MFPL_PD7MFP_Pos)  /*!< GPD_MFPL PD7 setting for UART2_RXD         */
#define SYS_GPD_MFPL_PD7MFP_CAN0_TXD          (0x04UL<<SYS_GPD_MFPL_PD7MFP_Pos)  /*!< GPD_MFPL PD7 setting for CAN0_TXD          */

/* PD.8 MFP */
#define SYS_GPD_MFPH_PD8MFP_GPIO              (0x00UL<<SYS_GPD_MFPH_PD8MFP_Pos)  /*!< GPD_MFPH PD8 setting for GPIO              */
#define SYS_GPD_MFPH_PD8MFP_SPI0_SS0          (0x01UL<<SYS_GPD_MFPH_PD8MFP_Pos)  /*!< GPD_MFPH PD8 setting for SPI0_SS0          */
#define SYS_GPD_MFPH_PD8MFP_UART6_nCTS        (0x02UL<<SYS_GPD_MFPH_PD8MFP_Pos)  /*!< GPD_MFPH PD8 setting for UART6_nCTS        */
#define SYS_GPD_MFPH_PD8MFP_I2C0_SMBAL        (0x05UL<<SYS_GPD_MFPH_PD8MFP_Pos)  /*!< GPD_MFPH PD8 setting for I2C0_SMBAL        */
#define SYS_GPD_MFPH_PD8MFP_BPWM1_CH5         (0x06UL<<SYS_GPD_MFPH_PD8MFP_Pos)  /*!< GPD_MFPH PD8 setting for BPWM1_CH5         */

/* PD.9 MFP */
#define SYS_GPD_MFPH_PD9MFP_GPIO              (0x00UL<<SYS_GPD_MFPH_PD9MFP_Pos)  /*!< GPD_MFPH PD9 setting for GPIO              */
#define SYS_GPD_MFPH_PD9MFP_SPI0_CLK          (0x01UL<<SYS_GPD_MFPH_PD9MFP_Pos)  /*!< GPD_MFPH PD9 setting for SPI0_CLK          */
#define SYS_GPD_MFPH_PD9MFP_UART6_nRTS        (0x02UL<<SYS_GPD_MFPH_PD9MFP_Pos)  /*!< GPD_MFPH PD9 setting for UART6_nRTS        */
#define SYS_GPD_MFPH_PD9MFP_I2C0_SMBSUS       (0x05UL<<SYS_GPD_MFPH_PD9MFP_Pos)  /*!< GPD_MFPH PD9 setting for I2C0_SMBSUS       */
#define SYS_GPD_MFPH_PD9MFP_BPWM1_CH4         (0x06UL<<SYS_GPD_MFPH_PD9MFP_Pos)  /*!< GPD_MFPH PD9 setting for BPWM1_CH4         */

/* PD.10 MFP */
#define SYS_GPD_MFPH_PD10MFP_GPIO             (0x00UL<<SYS_GPD_MFPH_PD10MFP_Pos)  /*!< GPD_MFPH PD10 setting for GPIO             */
#define SYS_GPD_MFPH_PD10MFP_SPI0_MOSI        (0x01UL<<SYS_GPD_MFPH_PD10MFP_Pos)  /*!< GPD_MFPH PD10 setting for SPI0_MOSI        */
#define SYS_GPD_MFPH_PD10MFP_UART6_TXD        (0x02UL<<SYS_GPD_MFPH_PD10MFP_Pos)  /*!< GPD_MFPH PD10 setting for UART6_TXD        */
#define SYS_GPD_MFPH_PD10MFP_I2C1_SMBAL       (0x05UL<<SYS_GPD_MFPH_PD10MFP_Pos)  /*!< GPD_MFPH PD10 setting for I2C1_SMBAL       */
#define SYS_GPD_MFPH_PD10MFP_BPWM0_CH5        (0x06UL<<SYS_GPD_MFPH_PD10MFP_Pos)  /*!< GPD_MFPH PD10 setting for BPWM0_CH5        */

/* PD.11 MFP */
#define SYS_GPD_MFPH_PD11MFP_GPIO             (0x00UL<<SYS_GPD_MFPH_PD11MFP_Pos)  /*!< GPD_MFPH PD11 setting for GPIO             */
#define SYS_GPD_MFPH_PD11MFP_SPI0_MISO        (0x01UL<<SYS_GPD_MFPH_PD11MFP_Pos)  /*!< GPD_MFPH PD11 setting for SPI0_MISO        */
#define SYS_GPD_MFPH_PD11MFP_UART6_RXD        (0x02UL<<SYS_GPD_MFPH_PD11MFP_Pos)  /*!< GPD_MFPH PD11 setting for UART6_RXD        */
#define SYS_GPD_MFPH_PD11MFP_I2C1_SMBSUS      (0x05UL<<SYS_GPD_MFPH_PD11MFP_Pos)  /*!< GPD_MFPH PD11 setting for I2C1_SMBSUS      */
#define SYS_GPD_MFPH_PD11MFP_BPWM0_CH4        (0x06UL<<SYS_GPD_MFPH_PD11MFP_Pos)  /*!< GPD_MFPH PD11 setting for BPWM0_CH4        */

/* PD.12 MFP */
#define SYS_GPD_MFPH_PD12MFP_GPIO             (0x00UL<<SYS_GPD_MFPH_PD12MFP_Pos)  /*!< GPD_MFPH PD12 setting for GPIO             */
#define SYS_GPD_MFPH_PD12MFP_UART4_TXD        (0x01UL<<SYS_GPD_MFPH_PD12MFP_Pos)  /*!< GPD_MFPH PD12 setting for UART4_TXD        */
#define SYS_GPD_MFPH_PD12MFP_TM2              (0x02UL<<SYS_GPD_MFPH_PD12MFP_Pos)  /*!< GPD_MFPH PD12 setting for TM2              */
#define SYS_GPD_MFPH_PD12MFP_CAN2_RXD         (0x04UL<<SYS_GPD_MFPH_PD12MFP_Pos)  /*!< GPD_MFPH PD12 setting for CAN2_RXD         */
#define SYS_GPD_MFPH_PD12MFP_I2C3_SMBAL       (0x05UL<<SYS_GPD_MFPH_PD12MFP_Pos)  /*!< GPD_MFPH PD12 setting for I2C3_SMBAL       */
#define SYS_GPD_MFPH_PD12MFP_BPWM0_CH0        (0x06UL<<SYS_GPD_MFPH_PD12MFP_Pos)  /*!< GPD_MFPH PD12 setting for BPWM0_CH0        */
#define SYS_GPD_MFPH_PD12MFP_SPI2_SS1         (0x07UL<<SYS_GPD_MFPH_PD12MFP_Pos)  /*!< GPD_MFPH PD12 setting for SPI2_SS1         */
#define SYS_GPD_MFPH_PD12MFP_EBI_AD1          (0x08UL<<SYS_GPD_MFPH_PD12MFP_Pos)  /*!< GPD_MFPH PD12 setting for EBI_AD1          */

/* PD.13 MFP */
#define SYS_GPD_MFPH_PD13MFP_GPIO             (0x00UL<<SYS_GPD_MFPH_PD13MFP_Pos)  /*!< GPD_MFPH PD13 setting for GPIO             */
#define SYS_GPD_MFPH_PD13MFP_UART4_RXD        (0x01UL<<SYS_GPD_MFPH_PD13MFP_Pos)  /*!< GPD_MFPH PD13 setting for UART4_RXD        */
#define SYS_GPD_MFPH_PD13MFP_TM2_EXT          (0x02UL<<SYS_GPD_MFPH_PD13MFP_Pos)  /*!< GPD_MFPH PD13 setting for TM2_EXT          */
#define SYS_GPD_MFPH_PD13MFP_CAN2_TXD         (0x04UL<<SYS_GPD_MFPH_PD13MFP_Pos)  /*!< GPD_MFPH PD13 setting for CAN2_TXD         */
#define SYS_GPD_MFPH_PD13MFP_I2C3_SMBSUS      (0x05UL<<SYS_GPD_MFPH_PD13MFP_Pos)  /*!< GPD_MFPH PD13 setting for I2C3_SMBSUS      */
#define SYS_GPD_MFPH_PD13MFP_BPWM0_CH1        (0x06UL<<SYS_GPD_MFPH_PD13MFP_Pos)  /*!< GPD_MFPH PD13 setting for BPWM0_CH1        */
#define SYS_GPD_MFPH_PD13MFP_SPI2_CLK         (0x07UL<<SYS_GPD_MFPH_PD13MFP_Pos)  /*!< GPD_MFPH PD13 setting for SPI2_CLK         */
#define SYS_GPD_MFPH_PD13MFP_EBI_AD2          (0x08UL<<SYS_GPD_MFPH_PD13MFP_Pos)  /*!< GPD_MFPH PD13 setting for EBI_AD2          */

/* PD.14 MFP */
#define SYS_GPD_MFPH_PD14MFP_GPIO             (0x00UL<<SYS_GPD_MFPH_PD14MFP_Pos)  /*!< GPD_MFPH PD14 setting for GPIO             */
#define SYS_GPD_MFPH_PD14MFP_UART4_nRTS       (0x01UL<<SYS_GPD_MFPH_PD14MFP_Pos)  /*!< GPD_MFPH PD14 setting for UART4_nRTS       */
#define SYS_GPD_MFPH_PD14MFP_TM3              (0x02UL<<SYS_GPD_MFPH_PD14MFP_Pos)  /*!< GPD_MFPH PD14 setting for TM3              */
#define SYS_GPD_MFPH_PD14MFP_I2C3_SCL         (0x03UL<<SYS_GPD_MFPH_PD14MFP_Pos)  /*!< GPD_MFPH PD14 setting for I2C3_SCL         */
#define SYS_GPD_MFPH_PD14MFP_CAN1_RXD         (0x04UL<<SYS_GPD_MFPH_PD14MFP_Pos)  /*!< GPD_MFPH PD14 setting for CAN1_RXD         */
#define SYS_GPD_MFPH_PD14MFP_BPWM0_CH2        (0x06UL<<SYS_GPD_MFPH_PD14MFP_Pos)  /*!< GPD_MFPH PD14 setting for BPWM0_CH2        */
#define SYS_GPD_MFPH_PD14MFP_SPI2_MOSI        (0x07UL<<SYS_GPD_MFPH_PD14MFP_Pos)  /*!< GPD_MFPH PD14 setting for SPI2_MOSI        */
#define SYS_GPD_MFPH_PD14MFP_EBI_AD3          (0x08UL<<SYS_GPD_MFPH_PD14MFP_Pos)  /*!< GPD_MFPH PD14 setting for EBI_AD3          */

/* PD.15 MFP */
#define SYS_GPD_MFPH_PD15MFP_GPIO             (0x00UL<<SYS_GPD_MFPH_PD15MFP_Pos)  /*!< GPD_MFPH PD15 setting for GPIO             */
#define SYS_GPD_MFPH_PD15MFP_UART4_nCTS       (0x01UL<<SYS_GPD_MFPH_PD15MFP_Pos)  /*!< GPD_MFPH PD15 setting for UART4_nCTS       */
#define SYS_GPD_MFPH_PD15MFP_TM3_EXT          (0x02UL<<SYS_GPD_MFPH_PD15MFP_Pos)  /*!< GPD_MFPH PD15 setting for TM3_EXT          */
#define SYS_GPD_MFPH_PD15MFP_I2C3_SDA         (0x03UL<<SYS_GPD_MFPH_PD15MFP_Pos)  /*!< GPD_MFPH PD15 setting for I2C3_SDA         */
#define SYS_GPD_MFPH_PD15MFP_CAN1_TXD         (0x04UL<<SYS_GPD_MFPH_PD15MFP_Pos)  /*!< GPD_MFPH PD15 setting for CAN1_TXD         */
#define SYS_GPD_MFPH_PD15MFP_BPWM0_CH3        (0x06UL<<SYS_GPD_MFPH_PD15MFP_Pos)  /*!< GPD_MFPH PD15 setting for BPWM0_CH3        */
#define SYS_GPD_MFPH_PD15MFP_SPI2_MISO        (0x07UL<<SYS_GPD_MFPH_PD15MFP_Pos)  /*!< GPD_MFPH PD15 setting for SPI2_MISO        */
#define SYS_GPD_MFPH_PD15MFP_EBI_AD4          (0x08UL<<SYS_GPD_MFPH_PD15MFP_Pos)  /*!< GPD_MFPH PD15 setting for EBI_AD4          */

/* PE.0 MFP */
#define SYS_GPE_MFPL_PE0MFP_GPIO              (0x00UL<<SYS_GPE_MFPL_PE0MFP_Pos)  /*!< GPE_MFPL PE0 setting for GPIO              */
#define SYS_GPE_MFPL_PE0MFP_EMAC0_RMII_RXERR  (0x01UL<<SYS_GPE_MFPL_PE0MFP_Pos)  /*!< GPE_MFPL PE0 setting for EMAC0_RMII_RXERR  */
#define SYS_GPE_MFPL_PE0MFP_CAN0_RXD          (0x02UL<<SYS_GPE_MFPL_PE0MFP_Pos)  /*!< GPE_MFPL PE0 setting for CAN0_RXD          */
#define SYS_GPE_MFPL_PE0MFP_UART4_nCTS        (0x05UL<<SYS_GPE_MFPL_PE0MFP_Pos)  /*!< GPE_MFPL PE0 setting for UART4_nCTS        */
#define SYS_GPE_MFPL_PE0MFP_SPI3_SS1          (0x06UL<<SYS_GPE_MFPL_PE0MFP_Pos)  /*!< GPE_MFPL PE0 setting for SPI3_SS1          */
#define SYS_GPE_MFPL_PE0MFP_I2C2_SMBAL        (0x07UL<<SYS_GPE_MFPL_PE0MFP_Pos)  /*!< GPE_MFPL PE0 setting for I2C2_SMBAL        */

/* PE.1 MFP */
#define SYS_GPE_MFPL_PE1MFP_GPIO              (0x00UL<<SYS_GPE_MFPL_PE1MFP_Pos)  /*!< GPE_MFPL PE1 setting for GPIO              */
#define SYS_GPE_MFPL_PE1MFP_EMAC0_RMII_CRSDV  (0x01UL<<SYS_GPE_MFPL_PE1MFP_Pos)  /*!< GPE_MFPL PE1 setting for EMAC0_RMII_CRSDV  */
#define SYS_GPE_MFPL_PE1MFP_CAN0_TXD          (0x02UL<<SYS_GPE_MFPL_PE1MFP_Pos)  /*!< GPE_MFPL PE1 setting for CAN0_TXD          */
#define SYS_GPE_MFPL_PE1MFP_UART4_nRTS        (0x05UL<<SYS_GPE_MFPL_PE1MFP_Pos)  /*!< GPE_MFPL PE1 setting for UART4_nRTS        */
#define SYS_GPE_MFPL_PE1MFP_SPI3_CLK          (0x06UL<<SYS_GPE_MFPL_PE1MFP_Pos)  /*!< GPE_MFPL PE1 setting for SPI3_CLK          */
#define SYS_GPE_MFPL_PE1MFP_I2C2_SMBSUS       (0x07UL<<SYS_GPE_MFPL_PE1MFP_Pos)  /*!< GPE_MFPL PE1 setting for I2C2_SMBSUS       */

/* PE.2 MFP */
#define SYS_GPE_MFPL_PE2MFP_GPIO              (0x00UL<<SYS_GPE_MFPL_PE2MFP_Pos)  /*!< GPE_MFPL PE2 setting for GPIO              */
#define SYS_GPE_MFPL_PE2MFP_EMAC0_RMII_RXD1   (0x01UL<<SYS_GPE_MFPL_PE2MFP_Pos)  /*!< GPE_MFPL PE2 setting for EMAC0_RMII_RXD1   */
#define SYS_GPE_MFPL_PE2MFP_CAN1_RXD          (0x02UL<<SYS_GPE_MFPL_PE2MFP_Pos)  /*!< GPE_MFPL PE2 setting for CAN1_RXD          */
#define SYS_GPE_MFPL_PE2MFP_UART4_RXD         (0x05UL<<SYS_GPE_MFPL_PE2MFP_Pos)  /*!< GPE_MFPL PE2 setting for UART4_RXD         */
#define SYS_GPE_MFPL_PE2MFP_SPI3_MOSI         (0x06UL<<SYS_GPE_MFPL_PE2MFP_Pos)  /*!< GPE_MFPL PE2 setting for SPI3_MOSI         */
#define SYS_GPE_MFPL_PE2MFP_I2C1_SMBAL        (0x07UL<<SYS_GPE_MFPL_PE2MFP_Pos)  /*!< GPE_MFPL PE2 setting for I2C1_SMBAL        */

/* PE.3 MFP */
#define SYS_GPE_MFPL_PE3MFP_GPIO              (0x00UL<<SYS_GPE_MFPL_PE3MFP_Pos)  /*!< GPE_MFPL PE3 setting for GPIO              */
#define SYS_GPE_MFPL_PE3MFP_EMAC0_RMII_RXD0   (0x01UL<<SYS_GPE_MFPL_PE3MFP_Pos)  /*!< GPE_MFPL PE3 setting for EMAC0_RMII_RXD0   */
#define SYS_GPE_MFPL_PE3MFP_CAN1_TXD          (0x02UL<<SYS_GPE_MFPL_PE3MFP_Pos)  /*!< GPE_MFPL PE3 setting for CAN1_TXD          */
#define SYS_GPE_MFPL_PE3MFP_UART4_TXD         (0x05UL<<SYS_GPE_MFPL_PE3MFP_Pos)  /*!< GPE_MFPL PE3 setting for UART4_TXD         */
#define SYS_GPE_MFPL_PE3MFP_SPI3_MISO         (0x06UL<<SYS_GPE_MFPL_PE3MFP_Pos)  /*!< GPE_MFPL PE3 setting for SPI3_MISO         */
#define SYS_GPE_MFPL_PE3MFP_I2C1_SMBSUS       (0x07UL<<SYS_GPE_MFPL_PE3MFP_Pos)  /*!< GPE_MFPL PE3 setting for I2C1_SMBSUS       */

/* PE.4 MFP */
#define SYS_GPE_MFPL_PE4MFP_GPIO              (0x00UL<<SYS_GPE_MFPL_PE4MFP_Pos)  /*!< GPE_MFPL PE4 setting for GPIO              */
#define SYS_GPE_MFPL_PE4MFP_EMAC0_RMII_REFCLK (0x01UL<<SYS_GPE_MFPL_PE4MFP_Pos)  /*!< GPE_MFPL PE4 setting for EMAC0_RMII_REFCLK */
#define SYS_GPE_MFPL_PE4MFP_CAN2_RXD          (0x02UL<<SYS_GPE_MFPL_PE4MFP_Pos)  /*!< GPE_MFPL PE4 setting for CAN2_RXD          */
#define SYS_GPE_MFPL_PE4MFP_UART9_nCTS        (0x05UL<<SYS_GPE_MFPL_PE4MFP_Pos)  /*!< GPE_MFPL PE4 setting for UART9_nCTS        */
#define SYS_GPE_MFPL_PE4MFP_I2C3_SMBAL        (0x07UL<<SYS_GPE_MFPL_PE4MFP_Pos)  /*!< GPE_MFPL PE4 setting for I2C3_SMBAL        */

/* PE.5 MFP */
#define SYS_GPE_MFPL_PE5MFP_GPIO              (0x00UL<<SYS_GPE_MFPL_PE5MFP_Pos)  /*!< GPE_MFPL PE5 setting for GPIO              */
#define SYS_GPE_MFPL_PE5MFP_EMAC0_RMII_TXEN   (0x01UL<<SYS_GPE_MFPL_PE5MFP_Pos)  /*!< GPE_MFPL PE5 setting for EMAC0_RMII_TXEN   */
#define SYS_GPE_MFPL_PE5MFP_CAN2_TXD          (0x02UL<<SYS_GPE_MFPL_PE5MFP_Pos)  /*!< GPE_MFPL PE5 setting for CAN2_TXD          */
#define SYS_GPE_MFPL_PE5MFP_UART9_nRTS        (0x05UL<<SYS_GPE_MFPL_PE5MFP_Pos)  /*!< GPE_MFPL PE5 setting for UART9_nRTS        */
#define SYS_GPE_MFPL_PE5MFP_I2C3_SMBSUS       (0x07UL<<SYS_GPE_MFPL_PE5MFP_Pos)  /*!< GPE_MFPL PE5 setting for I2C3_SMBSUS       */

/* PE.6 MFP */
#define SYS_GPE_MFPL_PE6MFP_GPIO              (0x00UL<<SYS_GPE_MFPL_PE6MFP_Pos)  /*!< GPE_MFPL PE6 setting for GPIO              */
#define SYS_GPE_MFPL_PE6MFP_EMAC0_RMII_TXD1   (0x01UL<<SYS_GPE_MFPL_PE6MFP_Pos)  /*!< GPE_MFPL PE6 setting for EMAC0_RMII_TXD1   */
#define SYS_GPE_MFPL_PE6MFP_CAN3_RXD          (0x02UL<<SYS_GPE_MFPL_PE6MFP_Pos)  /*!< GPE_MFPL PE6 setting for CAN3_RXD          */
#define SYS_GPE_MFPL_PE6MFP_UART9_RXD         (0x05UL<<SYS_GPE_MFPL_PE6MFP_Pos)  /*!< GPE_MFPL PE6 setting for UART9_RXD         */
#define SYS_GPE_MFPL_PE6MFP_I2C2_SMBAL        (0x07UL<<SYS_GPE_MFPL_PE6MFP_Pos)  /*!< GPE_MFPL PE6 setting for I2C2_SMBAL        */

/* PE.7 MFP */
#define SYS_GPE_MFPL_PE7MFP_GPIO              (0x00UL<<SYS_GPE_MFPL_PE7MFP_Pos)  /*!< GPE_MFPL PE7 setting for GPIO              */
#define SYS_GPE_MFPL_PE7MFP_EMAC0_RMII_TXD0   (0x01UL<<SYS_GPE_MFPL_PE7MFP_Pos)  /*!< GPE_MFPL PE7 setting for EMAC0_RMII_TXD0   */
#define SYS_GPE_MFPL_PE7MFP_CAN3_TXD          (0x02UL<<SYS_GPE_MFPL_PE7MFP_Pos)  /*!< GPE_MFPL PE7 setting for CAN3_TXD          */
#define SYS_GPE_MFPL_PE7MFP_UART9_TXD         (0x05UL<<SYS_GPE_MFPL_PE7MFP_Pos)  /*!< GPE_MFPL PE7 setting for UART9_TXD         */
#define SYS_GPE_MFPL_PE7MFP_I2C2_SMBSUS       (0x07UL<<SYS_GPE_MFPL_PE7MFP_Pos)  /*!< GPE_MFPL PE7 setting for I2C2_SMBSUS       */

/* PE.8 MFP */
#define SYS_GPE_MFPH_PE8MFP_GPIO              (0x00UL<<SYS_GPE_MFPH_PE8MFP_Pos)  /*!< GPE_MFPH PE8 setting for GPIO              */
#define SYS_GPE_MFPH_PE8MFP_EMAC0_RMII_MDIO   (0x01UL<<SYS_GPE_MFPH_PE8MFP_Pos)  /*!< GPE_MFPH PE8 setting for EMAC0_RMII_MDIO   */
#define SYS_GPE_MFPH_PE8MFP_UART6_RXD         (0x05UL<<SYS_GPE_MFPH_PE8MFP_Pos)  /*!< GPE_MFPH PE8 setting for UART6_RXD         */
#define SYS_GPE_MFPH_PE8MFP_I2C0_SMBAL        (0x07UL<<SYS_GPE_MFPH_PE8MFP_Pos)  /*!< GPE_MFPH PE8 setting for I2C0_SMBAL        */
#define SYS_GPE_MFPH_PE8MFP_SPI2_SS0          (0x08UL<<SYS_GPE_MFPH_PE8MFP_Pos)  /*!< GPE_MFPH PE8 setting for SPI2_SS0          */

/* PE.9 MFP */
#define SYS_GPE_MFPH_PE9MFP_GPIO              (0x00UL<<SYS_GPE_MFPH_PE9MFP_Pos)  /*!< GPE_MFPH PE9 setting for GPIO              */
#define SYS_GPE_MFPH_PE9MFP_EMAC0_RMII_MDC    (0x01UL<<SYS_GPE_MFPH_PE9MFP_Pos)  /*!< GPE_MFPH PE9 setting for EMAC0_RMII_MDC    */
#define SYS_GPE_MFPH_PE9MFP_UART6_TXD         (0x05UL<<SYS_GPE_MFPH_PE9MFP_Pos)  /*!< GPE_MFPH PE9 setting for UART6_TXD         */
#define SYS_GPE_MFPH_PE9MFP_I2C0_SMBSUS       (0x07UL<<SYS_GPE_MFPH_PE9MFP_Pos)  /*!< GPE_MFPH PE9 setting for I2C0_SMBSUS       */
#define SYS_GPE_MFPH_PE9MFP_SPI2_CLK          (0x08UL<<SYS_GPE_MFPH_PE9MFP_Pos)  /*!< GPE_MFPH PE9 setting for SPI2_CLK          */

/* PE.10 MFP */
#define SYS_GPE_MFPH_PE10MFP_GPIO             (0x00UL<<SYS_GPE_MFPH_PE10MFP_Pos)  /*!< GPE_MFPH PE10 setting for GPIO             */
#define SYS_GPE_MFPH_PE10MFP_USB_OVC          (0x01UL<<SYS_GPE_MFPH_PE10MFP_Pos)  /*!< GPE_MFPH PE10 setting for USB_OVC          */
#define SYS_GPE_MFPH_PE10MFP_CAN3_RXD         (0x02UL<<SYS_GPE_MFPH_PE10MFP_Pos)  /*!< GPE_MFPH PE10 setting for CAN3_RXD         */
#define SYS_GPE_MFPH_PE10MFP_UART9_RXD        (0x03UL<<SYS_GPE_MFPH_PE10MFP_Pos)  /*!< GPE_MFPH PE10 setting for UART9_RXD        */
#define SYS_GPE_MFPH_PE10MFP_BPWM1_CH2        (0x04UL<<SYS_GPE_MFPH_PE10MFP_Pos)  /*!< GPE_MFPH PE10 setting for BPWM1_CH2        */
#define SYS_GPE_MFPH_PE10MFP_INT2             (0x05UL<<SYS_GPE_MFPH_PE10MFP_Pos)  /*!< GPE_MFPH PE10 setting for INT2             */
#define SYS_GPE_MFPH_PE10MFP_I2C0_SDA         (0x06UL<<SYS_GPE_MFPH_PE10MFP_Pos)  /*!< GPE_MFPH PE10 setting for I2C0_SDA         */
#define SYS_GPE_MFPH_PE10MFP_SPI2_MOSI        (0x08UL<<SYS_GPE_MFPH_PE10MFP_Pos)  /*!< GPE_MFPH PE10 setting for SPI2_MOSI        */

/* PE.11 MFP */
#define SYS_GPE_MFPH_PE11MFP_GPIO             (0x00UL<<SYS_GPE_MFPH_PE11MFP_Pos)  /*!< GPE_MFPH PE11 setting for GPIO             */
#define SYS_GPE_MFPH_PE11MFP_USB0_VBUSVLD     (0x01UL<<SYS_GPE_MFPH_PE11MFP_Pos)  /*!< GPE_MFPH PE11 setting for USB0_VBUSVLD     */

/* PE.12 MFP */
#define SYS_GPE_MFPH_PE12MFP_GPIO             (0x00UL<<SYS_GPE_MFPH_PE12MFP_Pos)  /*!< GPE_MFPH PE12 setting for GPIO             */
#define SYS_GPE_MFPH_PE12MFP_USBH_PWREN       (0x01UL<<SYS_GPE_MFPH_PE12MFP_Pos)  /*!< GPE_MFPH PE12 setting for USBH_PWREN       */
#define SYS_GPE_MFPH_PE12MFP_CAN3_TXD         (0x02UL<<SYS_GPE_MFPH_PE12MFP_Pos)  /*!< GPE_MFPH PE12 setting for CAN3_TXD         */
#define SYS_GPE_MFPH_PE12MFP_UART9_TXD        (0x03UL<<SYS_GPE_MFPH_PE12MFP_Pos)  /*!< GPE_MFPH PE12 setting for UART9_TXD        */
#define SYS_GPE_MFPH_PE12MFP_BPWM1_CH3        (0x04UL<<SYS_GPE_MFPH_PE12MFP_Pos)  /*!< GPE_MFPH PE12 setting for BPWM1_CH3        */
#define SYS_GPE_MFPH_PE12MFP_INT3             (0x05UL<<SYS_GPE_MFPH_PE12MFP_Pos)  /*!< GPE_MFPH PE12 setting for INT3             */
#define SYS_GPE_MFPH_PE12MFP_I2C0_SCL         (0x06UL<<SYS_GPE_MFPH_PE12MFP_Pos)  /*!< GPE_MFPH PE12 setting for I2C0_SCL         */
#define SYS_GPE_MFPH_PE12MFP_SPI2_MISO        (0x08UL<<SYS_GPE_MFPH_PE12MFP_Pos)  /*!< GPE_MFPH PE12 setting for SPI2_MISO        */

/* PF.0 MFP */
#define SYS_GPF_MFPL_PF0MFP_GPIO              (0x00UL<<SYS_GPF_MFPL_PF0MFP_Pos)  /*!< GPF_MFPL PF0 setting for GPIO              */
#define SYS_GPF_MFPL_PF0MFP_EMAC1_RMII_RXERR  (0x01UL<<SYS_GPF_MFPL_PF0MFP_Pos)  /*!< GPF_MFPL PF0 setting for EMAC1_RMII_RXERR  */
#define SYS_GPF_MFPL_PF0MFP_SD1_CMD           (0x02UL<<SYS_GPF_MFPL_PF0MFP_Pos)  /*!< GPF_MFPL PF0 setting for SD1_CMD           */
#define SYS_GPF_MFPL_PF0MFP_eMMC1_CMD         (0x02UL<<SYS_GPF_MFPL_PF0MFP_Pos)  /*!< GPF_MFPL PF0 setting for eMMC1_CMD         */
#define SYS_GPF_MFPL_PF0MFP_SC1_RST           (0x04UL<<SYS_GPF_MFPL_PF0MFP_Pos)  /*!< GPF_MFPL PF0 setting for SC1_RST           */
#define SYS_GPF_MFPL_PF0MFP_UART7_nCTS        (0x05UL<<SYS_GPF_MFPL_PF0MFP_Pos)  /*!< GPF_MFPL PF0 setting for UART7_nCTS        */
#define SYS_GPF_MFPL_PF0MFP_SPI3_SS0          (0x06UL<<SYS_GPF_MFPL_PF0MFP_Pos)  /*!< GPF_MFPL PF0 setting for SPI3_SS0          */
#define SYS_GPF_MFPL_PF0MFP_BPWM1_CH5         (0x07UL<<SYS_GPF_MFPL_PF0MFP_Pos)  /*!< GPF_MFPL PF0 setting for BPWM1_CH5         */
#define SYS_GPF_MFPL_PF0MFP_EBI_AD5           (0x08UL<<SYS_GPF_MFPL_PF0MFP_Pos)  /*!< GPF_MFPL PF0 setting for EBI_AD5           */

/* PF.1 MFP */
#define SYS_GPF_MFPL_PF1MFP_GPIO              (0x00UL<<SYS_GPF_MFPL_PF1MFP_Pos)  /*!< GPF_MFPL PF1 setting for GPIO              */
#define SYS_GPF_MFPL_PF1MFP_EMAC1_RMII_CRSDV  (0x01UL<<SYS_GPF_MFPL_PF1MFP_Pos)  /*!< GPF_MFPL PF1 setting for EMAC1_RMII_CRSDV  */
#define SYS_GPF_MFPL_PF1MFP_SD1_CLK           (0x02UL<<SYS_GPF_MFPL_PF1MFP_Pos)  /*!< GPF_MFPL PF1 setting for SD1_CLK           */
#define SYS_GPF_MFPL_PF1MFP_eMMC1_CLK         (0x02UL<<SYS_GPF_MFPL_PF1MFP_Pos)  /*!< GPF_MFPL PF1 setting for eMMC1_CLK         */
#define SYS_GPF_MFPL_PF1MFP_SC1_CLK           (0x04UL<<SYS_GPF_MFPL_PF1MFP_Pos)  /*!< GPF_MFPL PF1 setting for SC1_CLK           */
#define SYS_GPF_MFPL_PF1MFP_UART7_nRTS        (0x05UL<<SYS_GPF_MFPL_PF1MFP_Pos)  /*!< GPF_MFPL PF1 setting for UART7_nRTS        */
#define SYS_GPF_MFPL_PF1MFP_SPI3_CLK          (0x06UL<<SYS_GPF_MFPL_PF1MFP_Pos)  /*!< GPF_MFPL PF1 setting for SPI3_CLK          */
#define SYS_GPF_MFPL_PF1MFP_BPWM1_CH4         (0x07UL<<SYS_GPF_MFPL_PF1MFP_Pos)  /*!< GPF_MFPL PF1 setting for BPWM1_CH4         */
#define SYS_GPF_MFPL_PF1MFP_EBI_AD6           (0x08UL<<SYS_GPF_MFPL_PF1MFP_Pos)  /*!< GPF_MFPL PF1 setting for EBI_AD6           */

/* PF.2 MFP */
#define SYS_GPF_MFPL_PF2MFP_GPIO              (0x00UL<<SYS_GPF_MFPL_PF2MFP_Pos)  /*!< GPF_MFPL PF2 setting for GPIO              */
#define SYS_GPF_MFPL_PF2MFP_EMAC1_RMII_RXD1   (0x01UL<<SYS_GPF_MFPL_PF2MFP_Pos)  /*!< GPF_MFPL PF2 setting for EMAC1_RMII_RXD1   */
#define SYS_GPF_MFPL_PF2MFP_SD1_DAT0          (0x02UL<<SYS_GPF_MFPL_PF2MFP_Pos)  /*!< GPF_MFPL PF2 setting for SD1_DAT0          */
#define SYS_GPF_MFPL_PF2MFP_eMMC1_DAT0        (0x02UL<<SYS_GPF_MFPL_PF2MFP_Pos)  /*!< GPF_MFPL PF2 setting for eMMC1_DAT0        */
#define SYS_GPF_MFPL_PF2MFP_SC1_DAT           (0x04UL<<SYS_GPF_MFPL_PF2MFP_Pos)  /*!< GPF_MFPL PF2 setting for SC1_DAT           */
#define SYS_GPF_MFPL_PF2MFP_UART7_RXD         (0x05UL<<SYS_GPF_MFPL_PF2MFP_Pos)  /*!< GPF_MFPL PF2 setting for UART7_RXD         */
#define SYS_GPF_MFPL_PF2MFP_SPI3_MOSI         (0x06UL<<SYS_GPF_MFPL_PF2MFP_Pos)  /*!< GPF_MFPL PF2 setting for SPI3_MOSI         */
#define SYS_GPF_MFPL_PF2MFP_BPWM0_CH5         (0x07UL<<SYS_GPF_MFPL_PF2MFP_Pos)  /*!< GPF_MFPL PF2 setting for BPWM0_CH5         */
#define SYS_GPF_MFPL_PF2MFP_EBI_AD7           (0x08UL<<SYS_GPF_MFPL_PF2MFP_Pos)  /*!< GPF_MFPL PF2 setting for EBI_AD7           */

/* PF.3 MFP */
#define SYS_GPF_MFPL_PF3MFP_GPIO              (0x00UL<<SYS_GPF_MFPL_PF3MFP_Pos)  /*!< GPF_MFPL PF3 setting for GPIO              */
#define SYS_GPF_MFPL_PF3MFP_EMAC1_RMII_RXD0   (0x01UL<<SYS_GPF_MFPL_PF3MFP_Pos)  /*!< GPF_MFPL PF3 setting for EMAC1_RMII_RXD0   */
#define SYS_GPF_MFPL_PF3MFP_SD1_DAT1          (0x02UL<<SYS_GPF_MFPL_PF3MFP_Pos)  /*!< GPF_MFPL PF3 setting for SD1_DAT1          */
#define SYS_GPF_MFPL_PF3MFP_eMMC1_DAT1        (0x02UL<<SYS_GPF_MFPL_PF3MFP_Pos)  /*!< GPF_MFPL PF3 setting for eMMC1_DAT1        */
#define SYS_GPF_MFPL_PF3MFP_SC1_PWR           (0x04UL<<SYS_GPF_MFPL_PF3MFP_Pos)  /*!< GPF_MFPL PF3 setting for SC1_PWR           */
#define SYS_GPF_MFPL_PF3MFP_UART7_TXD         (0x05UL<<SYS_GPF_MFPL_PF3MFP_Pos)  /*!< GPF_MFPL PF3 setting for UART7_TXD         */
#define SYS_GPF_MFPL_PF3MFP_SPI3_MISO         (0x06UL<<SYS_GPF_MFPL_PF3MFP_Pos)  /*!< GPF_MFPL PF3 setting for SPI3_MISO         */
#define SYS_GPF_MFPL_PF3MFP_BPWM0_CH4         (0x07UL<<SYS_GPF_MFPL_PF3MFP_Pos)  /*!< GPF_MFPL PF3 setting for BPWM0_CH4         */
#define SYS_GPF_MFPL_PF3MFP_EBI_AD8           (0x08UL<<SYS_GPF_MFPL_PF3MFP_Pos)  /*!< GPF_MFPL PF3 setting for EBI_AD8           */

/* PF.4 MFP */
#define SYS_GPF_MFPL_PF4MFP_GPIO              (0x00UL<<SYS_GPF_MFPL_PF4MFP_Pos)  /*!< GPF_MFPL PF4 setting for GPIO              */
#define SYS_GPF_MFPL_PF4MFP_EMAC1_RMII_REFCLK (0x01UL<<SYS_GPF_MFPL_PF4MFP_Pos)  /*!< GPF_MFPL PF4 setting for EMAC1_RMII_REFCLK */
#define SYS_GPF_MFPL_PF4MFP_SD1_DAT2          (0x02UL<<SYS_GPF_MFPL_PF4MFP_Pos)  /*!< GPF_MFPL PF4 setting for SD1_DAT2          */
#define SYS_GPF_MFPL_PF4MFP_eMMC1_DAT2        (0x02UL<<SYS_GPF_MFPL_PF4MFP_Pos)  /*!< GPF_MFPL PF4 setting for eMMC1_DAT2        */
#define SYS_GPF_MFPL_PF4MFP_SC1_nCD           (0x04UL<<SYS_GPF_MFPL_PF4MFP_Pos)  /*!< GPF_MFPL PF4 setting for SC1_nCD           */
#define SYS_GPF_MFPL_PF4MFP_UART3_nCTS        (0x05UL<<SYS_GPF_MFPL_PF4MFP_Pos)  /*!< GPF_MFPL PF4 setting for UART3_nCTS        */
#define SYS_GPF_MFPL_PF4MFP_SPI2_SS0          (0x07UL<<SYS_GPF_MFPL_PF4MFP_Pos)  /*!< GPF_MFPL PF4 setting for SPI2_SS0          */
#define SYS_GPF_MFPL_PF4MFP_EBI_AD9           (0x08UL<<SYS_GPF_MFPL_PF4MFP_Pos)  /*!< GPF_MFPL PF4 setting for EBI_AD9           */

/* PF.5 MFP */
#define SYS_GPF_MFPL_PF5MFP_GPIO              (0x00UL<<SYS_GPF_MFPL_PF5MFP_Pos)  /*!< GPF_MFPL PF5 setting for GPIO              */
#define SYS_GPF_MFPL_PF5MFP_EMAC1_RMII_TXEN   (0x01UL<<SYS_GPF_MFPL_PF5MFP_Pos)  /*!< GPF_MFPL PF5 setting for EMAC1_RMII_TXEN   */
#define SYS_GPF_MFPL_PF5MFP_SD1_DAT3          (0x02UL<<SYS_GPF_MFPL_PF5MFP_Pos)  /*!< GPF_MFPL PF5 setting for SD1_DAT3          */
#define SYS_GPF_MFPL_PF5MFP_eMMC1_DAT3        (0x02UL<<SYS_GPF_MFPL_PF5MFP_Pos)  /*!< GPF_MFPL PF5 setting for eMMC1_DAT3        */
#define SYS_GPF_MFPL_PF5MFP_BPWM0_CH0         (0x04UL<<SYS_GPF_MFPL_PF5MFP_Pos)  /*!< GPF_MFPL PF5 setting for BPWM0_CH0         */
#define SYS_GPF_MFPL_PF5MFP_UART3_nRTS        (0x05UL<<SYS_GPF_MFPL_PF5MFP_Pos)  /*!< GPF_MFPL PF5 setting for UART3_nRTS        */
#define SYS_GPF_MFPL_PF5MFP_SPI2_CLK          (0x07UL<<SYS_GPF_MFPL_PF5MFP_Pos)  /*!< GPF_MFPL PF5 setting for SPI2_CLK          */
#define SYS_GPF_MFPL_PF5MFP_EBI_AD10          (0x08UL<<SYS_GPF_MFPL_PF5MFP_Pos)  /*!< GPF_MFPL PF5 setting for EBI_AD10          */

/* PF.6 MFP */
#define SYS_GPF_MFPL_PF6MFP_GPIO              (0x00UL<<SYS_GPF_MFPL_PF6MFP_Pos)  /*!< GPF_MFPL PF6 setting for GPIO              */
#define SYS_GPF_MFPL_PF6MFP_EMAC1_RMII_TXD1   (0x01UL<<SYS_GPF_MFPL_PF6MFP_Pos)  /*!< GPF_MFPL PF6 setting for EMAC1_RMII_TXD1   */
#define SYS_GPF_MFPL_PF6MFP_SD1_nCD           (0x02UL<<SYS_GPF_MFPL_PF6MFP_Pos)  /*!< GPF_MFPL PF6 setting for SD1_nCD           */
#define SYS_GPF_MFPL_PF6MFP_TM4_EXT           (0x03UL<<SYS_GPF_MFPL_PF6MFP_Pos)  /*!< GPF_MFPL PF6 setting for TM4_EXT           */
#define SYS_GPF_MFPL_PF6MFP_BPWM0_CH1         (0x04UL<<SYS_GPF_MFPL_PF6MFP_Pos)  /*!< GPF_MFPL PF6 setting for BPWM0_CH1         */
#define SYS_GPF_MFPL_PF6MFP_UART3_RXD         (0x05UL<<SYS_GPF_MFPL_PF6MFP_Pos)  /*!< GPF_MFPL PF6 setting for UART3_RXD         */
#define SYS_GPF_MFPL_PF6MFP_SPI2_MOSI         (0x07UL<<SYS_GPF_MFPL_PF6MFP_Pos)  /*!< GPF_MFPL PF6 setting for SPI2_MOSI         */
#define SYS_GPF_MFPL_PF6MFP_EBI_AD11          (0x08UL<<SYS_GPF_MFPL_PF6MFP_Pos)  /*!< GPF_MFPL PF6 setting for EBI_AD11          */

/* PF.7 MFP */
#define SYS_GPF_MFPL_PF7MFP_GPIO              (0x00UL<<SYS_GPF_MFPL_PF7MFP_Pos)  /*!< GPF_MFPL PF7 setting for GPIO              */
#define SYS_GPF_MFPL_PF7MFP_EMAC1_RMII_TXD0   (0x01UL<<SYS_GPF_MFPL_PF7MFP_Pos)  /*!< GPF_MFPL PF7 setting for EMAC1_RMII_TXD0   */
#define SYS_GPF_MFPL_PF7MFP_UART1_nCTS        (0x02UL<<SYS_GPF_MFPL_PF7MFP_Pos)  /*!< GPF_MFPL PF7 setting for UART1_nCTS        */
#define SYS_GPF_MFPL_PF7MFP_TM5_EXT           (0x03UL<<SYS_GPF_MFPL_PF7MFP_Pos)  /*!< GPF_MFPL PF7 setting for TM5_EXT           */
#define SYS_GPF_MFPL_PF7MFP_BPWM0_CH2         (0x04UL<<SYS_GPF_MFPL_PF7MFP_Pos)  /*!< GPF_MFPL PF7 setting for BPWM0_CH2         */
#define SYS_GPF_MFPL_PF7MFP_UART3_TXD         (0x05UL<<SYS_GPF_MFPL_PF7MFP_Pos)  /*!< GPF_MFPL PF7 setting for UART3_TXD         */
#define SYS_GPF_MFPL_PF7MFP_SPI2_MISO         (0x07UL<<SYS_GPF_MFPL_PF7MFP_Pos)  /*!< GPF_MFPL PF7 setting for SPI2_MISO         */
#define SYS_GPF_MFPL_PF7MFP_EBI_AD12          (0x08UL<<SYS_GPF_MFPL_PF7MFP_Pos)  /*!< GPF_MFPL PF7 setting for EBI_AD12          */

/* PF.8 MFP */
#define SYS_GPF_MFPH_PF8MFP_GPIO              (0x00UL<<SYS_GPF_MFPH_PF8MFP_Pos)  /*!< GPF_MFPH PF8 setting for GPIO              */
#define SYS_GPF_MFPH_PF8MFP_EMAC1_RMII_MDIO   (0x01UL<<SYS_GPF_MFPH_PF8MFP_Pos)  /*!< GPF_MFPH PF8 setting for EMAC1_RMII_MDIO   */
#define SYS_GPF_MFPH_PF8MFP_UART1_nRTS        (0x02UL<<SYS_GPF_MFPH_PF8MFP_Pos)  /*!< GPF_MFPH PF8 setting for UART1_nRTS        */
#define SYS_GPF_MFPH_PF8MFP_TM1               (0x03UL<<SYS_GPF_MFPH_PF8MFP_Pos)  /*!< GPF_MFPH PF8 setting for TM1               */
#define SYS_GPF_MFPH_PF8MFP_BPWM0_CH3         (0x04UL<<SYS_GPF_MFPH_PF8MFP_Pos)  /*!< GPF_MFPH PF8 setting for BPWM0_CH3         */
#define SYS_GPF_MFPH_PF8MFP_ICE_CLK           (0x05UL<<SYS_GPF_MFPH_PF8MFP_Pos)  /*!< GPF_MFPH PF8 setting for ICE_CLK           */
#define SYS_GPF_MFPH_PF8MFP_SPI3_SS1          (0x06UL<<SYS_GPF_MFPH_PF8MFP_Pos)  /*!< GPF_MFPH PF8 setting for SPI3_SS1          */
#define SYS_GPF_MFPH_PF8MFP_EBI_AD13          (0x08UL<<SYS_GPF_MFPH_PF8MFP_Pos)  /*!< GPF_MFPH PF8 setting for EBI_AD13          */

/* PF.9 MFP */
#define SYS_GPF_MFPH_PF9MFP_GPIO              (0x00UL<<SYS_GPF_MFPH_PF9MFP_Pos)  /*!< GPF_MFPH PF9 setting for GPIO              */
#define SYS_GPF_MFPH_PF9MFP_EMAC1_RMII_MDC    (0x01UL<<SYS_GPF_MFPH_PF9MFP_Pos)  /*!< GPF_MFPH PF9 setting for EMAC1_RMII_MDC    */
#define SYS_GPF_MFPH_PF9MFP_UART1_RXD         (0x02UL<<SYS_GPF_MFPH_PF9MFP_Pos)  /*!< GPF_MFPH PF9 setting for UART1_RXD         */
#define SYS_GPF_MFPH_PF9MFP_TM1_EXT           (0x03UL<<SYS_GPF_MFPH_PF9MFP_Pos)  /*!< GPF_MFPH PF9 setting for TM1_EXT           */
#define SYS_GPF_MFPH_PF9MFP_BPWM1_CH0         (0x04UL<<SYS_GPF_MFPH_PF9MFP_Pos)  /*!< GPF_MFPH PF9 setting for BPWM1_CH0         */
#define SYS_GPF_MFPH_PF9MFP_ICE_DAT           (0x05UL<<SYS_GPF_MFPH_PF9MFP_Pos)  /*!< GPF_MFPH PF9 setting for ICE_DAT           */
#define SYS_GPF_MFPH_PF9MFP_SPI3_SS0          (0x06UL<<SYS_GPF_MFPH_PF9MFP_Pos)  /*!< GPF_MFPH PF9 setting for SPI3_SS0          */
#define SYS_GPF_MFPH_PF9MFP_EBI_AD14          (0x08UL<<SYS_GPF_MFPH_PF9MFP_Pos)  /*!< GPF_MFPH PF9 setting for EBI_AD14          */

/* PF.10 MFP */
#define SYS_GPF_MFPH_PF10MFP_GPIO             (0x00UL<<SYS_GPF_MFPH_PF10MFP_Pos) /*!< GPF_MFPH PF10 setting for GPIO             */
#define SYS_GPF_MFPH_PF10MFP_EMAC0_RMII_PPS   (0x01UL<<SYS_GPF_MFPH_PF10MFP_Pos) /*!< GPF_MFPH PF10 setting for EMAC0_RMII_PPS   */
#define SYS_GPF_MFPH_PF10MFP_UART1_TXD        (0x02UL<<SYS_GPF_MFPH_PF10MFP_Pos) /*!< GPF_MFPH PF10 setting for UART1_TXD        */
#define SYS_GPF_MFPH_PF10MFP_TM5              (0x03UL<<SYS_GPF_MFPH_PF10MFP_Pos) /*!< GPF_MFPH PF10 setting for TM5              */
#define SYS_GPF_MFPH_PF10MFP_BPWM1_CH1        (0x04UL<<SYS_GPF_MFPH_PF10MFP_Pos) /*!< GPF_MFPH PF10 setting for BPWM1_CH1        */
#define SYS_GPF_MFPH_PF10MFP_CANFD3_TXD       (0x06UL<<SYS_GPF_MFPH_PF10MFP_Pos) /*!< GPF_MFPH PF10 setting for CANFD3_TXD       */
#define SYS_GPF_MFPH_PF10MFP_EBI_AD15         (0x08UL<<SYS_GPF_MFPH_PF10MFP_Pos) /*!< GPF_MFPH PF10 setting for EBI_AD15         */

/* PF.11 MFP */
#define SYS_GPF_MFPH_PF11MFP_GPIO             (0x00UL<<SYS_GPF_MFPH_PF11MFP_Pos) /*!< GPF_MFPH PF11 setting for GPIO             */
#define SYS_GPF_MFPH_PF11MFP_UART0_RXD        (0x01UL<<SYS_GPF_MFPH_PF11MFP_Pos) /*!< GPF_MFPH PF11 setting for UART0_RXD        */

/* PF.12 MFP */
#define SYS_GPF_MFPH_PF12MFP_GPIO             (0x00UL<<SYS_GPF_MFPH_PF12MFP_Pos) /*!< GPF_MFPH PF12 setting for GPIO             */
#define SYS_GPF_MFPH_PF12MFP_UART0_TXD        (0x01UL<<SYS_GPF_MFPH_PF12MFP_Pos) /*!< GPF_MFPH PF12 setting for UART0_TXD        */

/* PG.0 MFP */
#define SYS_GPG_MFPL_PG0MFP_GPIO              (0x00UL<<SYS_GPG_MFPL_PG0MFP_Pos)  /*!< GPG_MFPL PG0 setting for GPIO              */
#define SYS_GPG_MFPL_PG0MFP_EBI_ADR0          (0x01UL<<SYS_GPG_MFPL_PG0MFP_Pos)  /*!< GPG_MFPL PG0 setting for EBI_ADR0          */
#define SYS_GPG_MFPL_PG0MFP_UART2_RXD         (0x02UL<<SYS_GPG_MFPL_PG0MFP_Pos)  /*!< GPG_MFPL PG0 setting for UART2_RXD         */
#define SYS_GPG_MFPL_PG0MFP_CLK_OUT           (0x03UL<<SYS_GPG_MFPL_PG0MFP_Pos)  /*!< GPG_MFPL PG0 setting for CLK_OUT           */
#define SYS_GPG_MFPL_PG0MFP_BPWM0_CH0         (0x06UL<<SYS_GPG_MFPL_PG0MFP_Pos)  /*!< GPG_MFPL PG0 setting for BPWM0_CH0         */

/* PG.1 MFP */
#define SYS_GPG_MFPL_PG1MFP_GPIO              (0x00UL<<SYS_GPG_MFPL_PG1MFP_Pos)  /*!< GPG_MFPL PG1 setting for GPIO              */
#define SYS_GPG_MFPL_PG1MFP_EBI_ADR1          (0x01UL<<SYS_GPG_MFPL_PG1MFP_Pos)  /*!< GPG_MFPL PG1 setting for EBI_ADR1          */
#define SYS_GPG_MFPL_PG1MFP_UART2_TXD         (0x02UL<<SYS_GPG_MFPL_PG1MFP_Pos)  /*!< GPG_MFPL PG1 setting for UART2_TXD         */
#define SYS_GPG_MFPL_PG1MFP_BPWM0_CH1         (0x06UL<<SYS_GPG_MFPL_PG1MFP_Pos)  /*!< GPG_MFPL PG1 setting for BPWM0_CH1         */

/* PG.2 MFP */
#define SYS_GPG_MFPL_PG2MFP_GPIO              (0x00UL<<SYS_GPG_MFPL_PG2MFP_Pos)  /*!< GPG_MFPL PG2 setting for GPIO              */
#define SYS_GPG_MFPL_PG2MFP_EBI_ADR2          (0x01UL<<SYS_GPG_MFPL_PG2MFP_Pos)  /*!< GPG_MFPL PG2 setting for EBI_ADR2          */
#define SYS_GPG_MFPL_PG2MFP_UART2_nCTS        (0x02UL<<SYS_GPG_MFPL_PG2MFP_Pos)  /*!< GPG_MFPL PG2 setting for UART2_nCTS        */
#define SYS_GPG_MFPL_PG2MFP_CANFD3_TXD        (0x04UL<<SYS_GPG_MFPL_PG2MFP_Pos)  /*!< GPG_MFPL PG2 setting for CANFD3_TXD        */
#define SYS_GPG_MFPL_PG2MFP_BPWM0_CH2         (0x06UL<<SYS_GPG_MFPL_PG2MFP_Pos)  /*!< GPG_MFPL PG2 setting for BPWM0_CH2         */

/* PG.3 MFP */
#define SYS_GPG_MFPL_PG3MFP_GPIO              (0x00UL<<SYS_GPG_MFPL_PG3MFP_Pos)  /*!< GPG_MFPL PG3 setting for GPIO              */
#define SYS_GPG_MFPL_PG3MFP_EBI_ADR3          (0x01UL<<SYS_GPG_MFPL_PG3MFP_Pos)  /*!< GPG_MFPL PG3 setting for EBI_ADR3          */
#define SYS_GPG_MFPL_PG3MFP_UART2_nRTS        (0x02UL<<SYS_GPG_MFPL_PG3MFP_Pos)  /*!< GPG_MFPL PG3 setting for UART2_nRTS        */
#define SYS_GPG_MFPL_PG3MFP_UART5_nCTS        (0x03UL<<SYS_GPG_MFPL_PG3MFP_Pos)  /*!< GPG_MFPL PG3 setting for UART5_nCTS        */
#define SYS_GPG_MFPL_PG3MFP_BPWM0_CH3         (0x06UL<<SYS_GPG_MFPL_PG3MFP_Pos)  /*!< GPG_MFPL PG3 setting for BPWM0_CH3         */

/* PG.4 MFP */
#define SYS_GPG_MFPL_PG4MFP_GPIO              (0x00UL<<SYS_GPG_MFPL_PG4MFP_Pos)  /*!< GPG_MFPL PG4 setting for GPIO              */
#define SYS_GPG_MFPL_PG4MFP_EBI_ADR18         (0x01UL<<SYS_GPG_MFPL_PG4MFP_Pos)  /*!< GPG_MFPL PG4 setting for EBI_ADR18         */
#define SYS_GPG_MFPL_PG4MFP_UART5_nCTS        (0x02UL<<SYS_GPG_MFPL_PG4MFP_Pos)  /*!< GPG_MFPL PG4 setting for UART5_nCTS        */
#define SYS_GPG_MFPL_PG4MFP_CANFD3_RXD        (0x04UL<<SYS_GPG_MFPL_PG4MFP_Pos)  /*!< GPG_MFPL PG4 setting for CANFD3_RXD        */

/* PG.5 MFP */
#define SYS_GPG_MFPL_PG5MFP_GPIO              (0x00UL<<SYS_GPG_MFPL_PG5MFP_Pos)  /*!< GPG_MFPL PG5 setting for GPIO              */
#define SYS_GPG_MFPL_PG5MFP_EBI_ADR12         (0x01UL<<SYS_GPG_MFPL_PG5MFP_Pos)  /*!< GPG_MFPL PG5 setting for EBI_ADR12         */
#define SYS_GPG_MFPL_PG5MFP_UART5_nRTS        (0x02UL<<SYS_GPG_MFPL_PG5MFP_Pos)  /*!< GPG_MFPL PG5 setting for UART5_nRTS        */

/* PG.6 MFP */
#define SYS_GPG_MFPL_PG6MFP_GPIO              (0x00UL<<SYS_GPG_MFPL_PG6MFP_Pos)  /*!< GPG_MFPL PG6 setting for GPIO              */
#define SYS_GPG_MFPL_PG6MFP_EBI_ADR4          (0x01UL<<SYS_GPG_MFPL_PG6MFP_Pos)  /*!< GPG_MFPL PG6 setting for EBI_ADR4          */
#define SYS_GPG_MFPL_PG6MFP_UART5_RXD         (0x02UL<<SYS_GPG_MFPL_PG6MFP_Pos)  /*!< GPG_MFPL PG6 setting for UART5_RXD         */
#define SYS_GPG_MFPL_PG6MFP_CANFD1_TXD        (0x04UL<<SYS_GPG_MFPL_PG6MFP_Pos)  /*!< GPG_MFPL PG6 setting for CANFD1_TXD        */
#define SYS_GPG_MFPL_PG6MFP_BPWM1_CH0         (0x06UL<<SYS_GPG_MFPL_PG6MFP_Pos)  /*!< GPG_MFPL PG6 setting for BPWM1_CH0         */

/* PG.7 MFP */
#define SYS_GPG_MFPL_PG7MFP_GPIO              (0x00UL<<SYS_GPG_MFPL_PG7MFP_Pos)  /*!< GPG_MFPL PG7 setting for GPIO              */
#define SYS_GPG_MFPL_PG7MFP_EBI_ADR5          (0x01UL<<SYS_GPG_MFPL_PG7MFP_Pos)  /*!< GPG_MFPL PG7 setting for EBI_ADR5          */
#define SYS_GPG_MFPL_PG7MFP_UART5_TXD         (0x02UL<<SYS_GPG_MFPL_PG7MFP_Pos)  /*!< GPG_MFPL PG7 setting for UART5_TXD         */
#define SYS_GPG_MFPL_PG7MFP_CANFD1_RXD        (0x04UL<<SYS_GPG_MFPL_PG7MFP_Pos)  /*!< GPG_MFPL PG7 setting for CANFD1_RXD        */
#define SYS_GPG_MFPL_PG7MFP_BPWM1_CH1         (0x06UL<<SYS_GPG_MFPL_PG7MFP_Pos)  /*!< GPG_MFPL PG7 setting for BPWM1_CH1         */

/* PG.8 MFP */
#define SYS_GPG_MFPH_PG8MFP_GPIO              (0x00UL<<SYS_GPG_MFPH_PG8MFP_Pos)  /*!< GPG_MFPH PG8 setting for GPIO              */
#define SYS_GPG_MFPH_PG8MFP_EBI_ADR6          (0x01UL<<SYS_GPG_MFPH_PG8MFP_Pos)  /*!< GPG_MFPH PG8 setting for EBI_ADR6          */
#define SYS_GPG_MFPH_PG8MFP_UART8_nRTS        (0x02UL<<SYS_GPG_MFPH_PG8MFP_Pos)  /*!< GPG_MFPH PG8 setting for UART8_nRTS        */
#define SYS_GPG_MFPH_PG8MFP_CANFD0_TXD        (0x04UL<<SYS_GPG_MFPH_PG8MFP_Pos)  /*!< GPG_MFPH PG8 setting for CANFD0_TXD        */
#define SYS_GPG_MFPH_PG8MFP_BPWM1_CH2         (0x06UL<<SYS_GPG_MFPH_PG8MFP_Pos)  /*!< GPG_MFPH PG8 setting for BPWM1_CH2         */

/* PG.9 MFP */
#define SYS_GPG_MFPH_PG9MFP_GPIO              (0x00UL<<SYS_GPG_MFPH_PG9MFP_Pos)  /*!< GPG_MFPH PG9 setting for GPIO              */
#define SYS_GPG_MFPH_PG9MFP_EBI_ADR7          (0x01UL<<SYS_GPG_MFPH_PG9MFP_Pos)  /*!< GPG_MFPH PG9 setting for EBI_ADR7          */
#define SYS_GPG_MFPH_PG9MFP_UART8_nCTS        (0x02UL<<SYS_GPG_MFPH_PG9MFP_Pos)  /*!< GPG_MFPH PG9 setting for UART8_nCTS        */
#define SYS_GPG_MFPH_PG9MFP_CANFD0_RXD        (0x04UL<<SYS_GPG_MFPH_PG9MFP_Pos)  /*!< GPG_MFPH PG9 setting for CANFD0_RXD        */
#define SYS_GPG_MFPH_PG9MFP_BPWM1_CH3         (0x06UL<<SYS_GPG_MFPH_PG9MFP_Pos)  /*!< GPG_MFPH PG9 setting for BPWM1_CH3         */

/* PG.10 MFP */
#define SYS_GPG_MFPH_PG10MFP_GPIO             (0x00UL<<SYS_GPG_MFPH_PG10MFP_Pos)  /*!< GPG_MFPH PG10 setting for GPIO             */
#define SYS_GPG_MFPH_PG10MFP_EBI_AD0          (0x01UL<<SYS_GPG_MFPH_PG10MFP_Pos)  /*!< GPG_MFPH PG10 setting for EBI_AD0          */
#define SYS_GPG_MFPH_PG10MFP_I2C0_SCL         (0x02UL<<SYS_GPG_MFPH_PG10MFP_Pos)  /*!< GPG_MFPH PG10 setting for I2C0_SCL         */
#define SYS_GPG_MFPH_PG10MFP_TM5              (0x03UL<<SYS_GPG_MFPH_PG10MFP_Pos)  /*!< GPG_MFPH PG10 setting for TM5              */
#define SYS_GPG_MFPH_PG10MFP_CAN2_TXD         (0x05UL<<SYS_GPG_MFPH_PG10MFP_Pos)  /*!< GPG_MFPH PG10 setting for CAN2_TXD         */
#define SYS_GPG_MFPH_PG10MFP_SPI1_CLK         (0x06UL<<SYS_GPG_MFPH_PG10MFP_Pos)  /*!< GPG_MFPH PG10 setting for SPI1_CLK         */
#define SYS_GPG_MFPH_PG10MFP_BPWM0_CH0        (0x07UL<<SYS_GPG_MFPH_PG10MFP_Pos)  /*!< GPG_MFPH PG10 setting for BPWM0_CH0        */
#define SYS_GPG_MFPH_PG10MFP_I2S_BCLK         (0x08UL<<SYS_GPG_MFPH_PG10MFP_Pos)  /*!< GPG_MFPH PG10 setting for I2S_BCLK         */

/* PG.11 MFP */
#define SYS_GPG_MFPH_PG11MFP_GPIO             (0x00UL<<SYS_GPG_MFPH_PG11MFP_Pos)  /*!< GPG_MFPH PG11 setting for GPIO             */
#define SYS_GPG_MFPH_PG11MFP_SPI1_SS0         (0x02UL<<SYS_GPG_MFPH_PG11MFP_Pos)  /*!< GPG_MFPH PG11 setting for SPI1_SS0         */
#define SYS_GPG_MFPH_PG11MFP_TM1              (0x03UL<<SYS_GPG_MFPH_PG11MFP_Pos)  /*!< GPG_MFPH PG11 setting for TM1              */
#define SYS_GPG_MFPH_PG11MFP_CAN0_RXD         (0x04UL<<SYS_GPG_MFPH_PG11MFP_Pos)  /*!< GPG_MFPH PG11 setting for CAN0_RXD         */
#define SYS_GPG_MFPH_PG11MFP_UART5_nCTS       (0x05UL<<SYS_GPG_MFPH_PG11MFP_Pos)  /*!< GPG_MFPH PG11 setting for UART5_nCTS       */
#define SYS_GPG_MFPH_PG11MFP_BPWM1_CH0        (0x06UL<<SYS_GPG_MFPH_PG11MFP_Pos)  /*!< GPG_MFPH PG11 setting for BPWM1_CH0        */
#define SYS_GPG_MFPH_PG11MFP_JTAG0_TDO        (0x07UL<<SYS_GPG_MFPH_PG11MFP_Pos)  /*!< GPG_MFPH PG11 setting for JTAG0_TDO        */
#define SYS_GPG_MFPH_PG11MFP_I2C2_SMBAL       (0x08UL<<SYS_GPG_MFPH_PG11MFP_Pos)  /*!< GPG_MFPH PG11 setting for I2C2_SMBAL       */

/* PG.12 MFP */
#define SYS_GPG_MFPH_PG12MFP_GPIO             (0x00UL<<SYS_GPG_MFPH_PG12MFP_Pos)  /*!< GPG_MFPH PG12 setting for GPIO             */
#define SYS_GPG_MFPH_PG12MFP_SPI1_CLK         (0x02UL<<SYS_GPG_MFPH_PG12MFP_Pos)  /*!< GPG_MFPH PG12 setting for SPI1_CLK         */
#define SYS_GPG_MFPH_PG12MFP_TM1_EXT          (0x03UL<<SYS_GPG_MFPH_PG12MFP_Pos)  /*!< GPG_MFPH PG12 setting for TM1_EXT          */
#define SYS_GPG_MFPH_PG12MFP_CAN0_TXD         (0x04UL<<SYS_GPG_MFPH_PG12MFP_Pos)  /*!< GPG_MFPH PG12 setting for CAN0_TXD         */
#define SYS_GPG_MFPH_PG12MFP_UART5_nRTS       (0x05UL<<SYS_GPG_MFPH_PG12MFP_Pos)  /*!< GPG_MFPH PG12 setting for UART5_nRTS       */
#define SYS_GPG_MFPH_PG12MFP_BPWM1_CH1        (0x06UL<<SYS_GPG_MFPH_PG12MFP_Pos)  /*!< GPG_MFPH PG12 setting for BPWM1_CH1        */
#define SYS_GPG_MFPH_PG12MFP_JTAG0_TCK        (0x07UL<<SYS_GPG_MFPH_PG12MFP_Pos)  /*!< GPG_MFPH PG12 setting for JTAG0_TCK        */
#define SYS_GPG_MFPH_PG12MFP_I2C2_SMBSUS      (0x08UL<<SYS_GPG_MFPH_PG12MFP_Pos)  /*!< GPG_MFPH PG12 setting for I2C2_SMBSUS      */

/* PG.13 MFP */
#define SYS_GPG_MFPH_PG13MFP_GPIO             (0x00UL<<SYS_GPG_MFPH_PG13MFP_Pos)  /*!< GPG_MFPH PG13 setting for GPIO             */
#define SYS_GPG_MFPH_PG13MFP_SPI1_MOSI        (0x02UL<<SYS_GPG_MFPH_PG13MFP_Pos)  /*!< GPG_MFPH PG13 setting for SPI1_MOSI        */
#define SYS_GPG_MFPH_PG13MFP_CAN1_RXD         (0x04UL<<SYS_GPG_MFPH_PG13MFP_Pos)  /*!< GPG_MFPH PG13 setting for CAN1_RXD         */
#define SYS_GPG_MFPH_PG13MFP_UART5_RXD        (0x05UL<<SYS_GPG_MFPH_PG13MFP_Pos)  /*!< GPG_MFPH PG13 setting for UART5_RXD        */
#define SYS_GPG_MFPH_PG13MFP_BPWM1_CH2        (0x06UL<<SYS_GPG_MFPH_PG13MFP_Pos)  /*!< GPG_MFPH PG13 setting for BPWM1_CH2        */
#define SYS_GPG_MFPH_PG13MFP_JTAG0_TMS        (0x07UL<<SYS_GPG_MFPH_PG13MFP_Pos)  /*!< GPG_MFPH PG13 setting for JTAG0_TMS        */
#define SYS_GPG_MFPH_PG13MFP_I2C3_SMBAL       (0x08UL<<SYS_GPG_MFPH_PG13MFP_Pos)  /*!< GPG_MFPH PG13 setting for I2C3_SMBAL       */

/* PG.14 MFP */
#define SYS_GPG_MFPH_PG14MFP_GPIO             (0x00UL<<SYS_GPG_MFPH_PG14MFP_Pos)  /*!< GPG_MFPH PG14 setting for GPIO             */
#define SYS_GPG_MFPH_PG14MFP_SPI1_MISO        (0x02UL<<SYS_GPG_MFPH_PG14MFP_Pos)  /*!< GPG_MFPH PG14 setting for SPI1_MISO        */
#define SYS_GPG_MFPH_PG14MFP_CAN1_TXD         (0x04UL<<SYS_GPG_MFPH_PG14MFP_Pos)  /*!< GPG_MFPH PG14 setting for CAN1_TXD         */
#define SYS_GPG_MFPH_PG14MFP_UART5_TXD        (0x05UL<<SYS_GPG_MFPH_PG14MFP_Pos)  /*!< GPG_MFPH PG14 setting for UART5_TXD        */
#define SYS_GPG_MFPH_PG14MFP_BPWM1_CH3        (0x06UL<<SYS_GPG_MFPH_PG14MFP_Pos)  /*!< GPG_MFPH PG14 setting for BPWM1_CH3        */
#define SYS_GPG_MFPH_PG14MFP_JTAG0_TDI        (0x07UL<<SYS_GPG_MFPH_PG14MFP_Pos)  /*!< GPG_MFPH PG14 setting for JTAG0_TDI        */
#define SYS_GPG_MFPH_PG14MFP_I2C3_SMBSUS      (0x08UL<<SYS_GPG_MFPH_PG14MFP_Pos)  /*!< GPG_MFPH PG14 setting for I2C3_SMBSUS      */

/* PG.15 MFP */
#define SYS_GPG_MFPH_PG15MFP_GPIO             (0x00UL<<SYS_GPG_MFPH_PG15MFP_Pos)  /*!< GPG_MFPH PG15 setting for GPIO             */
#define SYS_GPG_MFPH_PG15MFP_SPI0_SS1         (0x01UL<<SYS_GPG_MFPH_PG15MFP_Pos)  /*!< GPG_MFPH PG15 setting for SPI0_SS1         */
#define SYS_GPG_MFPH_PG15MFP_SPI1_SS1         (0x02UL<<SYS_GPG_MFPH_PG15MFP_Pos)  /*!< GPG_MFPH PG15 setting for SPI1_SS1         */
#define SYS_GPG_MFPH_PG15MFP_INT3             (0x04UL<<SYS_GPG_MFPH_PG15MFP_Pos)  /*!< GPG_MFPH PG15 setting for INT3             */
#define SYS_GPG_MFPH_PG15MFP_SPI2_SS1         (0x05UL<<SYS_GPG_MFPH_PG15MFP_Pos)  /*!< GPG_MFPH PG15 setting for SPI2_SS1         */
#define SYS_GPG_MFPH_PG15MFP_CANFD3_RXD       (0x06UL<<SYS_GPG_MFPH_PG15MFP_Pos)  /*!< GPG_MFPH PG15 setting for CANFD3_RXD       */
#define SYS_GPG_MFPH_PG15MFP_JTAG0_nTRST      (0x07UL<<SYS_GPG_MFPH_PG15MFP_Pos)  /*!< GPG_MFPH PG15 setting for JTAG0_nTRST      */
#define SYS_GPG_MFPH_PG15MFP_SPI3_SS1         (0x08UL<<SYS_GPG_MFPH_PG15MFP_Pos)  /*!< GPG_MFPH PG15 setting for SPI3_SS1         */

/* PH.0 MFP */
#define SYS_GPH_MFPL_PH0MFP_GPIO              (0x00UL<<SYS_GPH_MFPL_PH0MFP_Pos)  /*!< GPH_MFPL PH0 setting for GPIO              */
#define SYS_GPH_MFPL_PH0MFP_UART1_TXD         (0x01UL<<SYS_GPH_MFPL_PH0MFP_Pos)  /*!< GPH_MFPL PH0 setting for UART1_TXD         */
#define SYS_GPH_MFPL_PH0MFP_UART2_nCTS        (0x02UL<<SYS_GPH_MFPL_PH0MFP_Pos)  /*!< GPH_MFPL PH0 setting for UART2_nCTS        */
#define SYS_GPH_MFPL_PH0MFP_INT0              (0x04UL<<SYS_GPH_MFPL_PH0MFP_Pos)  /*!< GPH_MFPL PH0 setting for INT0              */
#define SYS_GPH_MFPL_PH0MFP_SPI0_SS0          (0x05UL<<SYS_GPH_MFPL_PH0MFP_Pos)  /*!< GPH_MFPL PH0 setting for SPI0_SS0          */
#define SYS_GPH_MFPL_PH0MFP_SD0_nCD           (0x06UL<<SYS_GPH_MFPL_PH0MFP_Pos)  /*!< GPH_MFPL PH0 setting for SD0_nCD           */

/* PH.1 MFP */
#define SYS_GPH_MFPL_PH1MFP_GPIO              (0x00UL<<SYS_GPH_MFPL_PH1MFP_Pos)  /*!< GPH_MFPL PH1 setting for GPIO              */
#define SYS_GPH_MFPL_PH1MFP_UART1_RXD         (0x01UL<<SYS_GPH_MFPL_PH1MFP_Pos)  /*!< GPH_MFPL PH1 setting for UART1_RXD         */
#define SYS_GPH_MFPL_PH1MFP_UART2_nRTS        (0x02UL<<SYS_GPH_MFPL_PH1MFP_Pos)  /*!< GPH_MFPL PH1 setting for UART2_nRTS        */
#define SYS_GPH_MFPL_PH1MFP_TM3               (0x03UL<<SYS_GPH_MFPL_PH1MFP_Pos)  /*!< GPH_MFPL PH1 setting for TM3               */
#define SYS_GPH_MFPL_PH1MFP_SD0_DAT0          (0x06UL<<SYS_GPH_MFPL_PH1MFP_Pos)  /*!< GPH_MFPL PH1 setting for SD0_DAT0          */
#define SYS_GPH_MFPL_PH1MFP_eMMC0_DAT0        (0x06UL<<SYS_GPH_MFPL_PH1MFP_Pos)  /*!< GPH_MFPL PH1 setting for eMMC0_DAT0        */

/* PH.2 MFP */
#define SYS_GPH_MFPL_PH2MFP_GPIO              (0x00UL<<SYS_GPH_MFPL_PH2MFP_Pos)  /*!< GPH_MFPL PH2 setting for GPIO              */
#define SYS_GPH_MFPL_PH2MFP_UART1_nRTS        (0x01UL<<SYS_GPH_MFPL_PH2MFP_Pos)  /*!< GPH_MFPL PH2 setting for UART1_nRTS        */
#define SYS_GPH_MFPL_PH2MFP_CAN3_RXD          (0x02UL<<SYS_GPH_MFPL_PH2MFP_Pos)  /*!< GPH_MFPL PH2 setting for CAN3_RXD          */
#define SYS_GPH_MFPL_PH2MFP_TM3_EXT           (0x03UL<<SYS_GPH_MFPL_PH2MFP_Pos)  /*!< GPH_MFPL PH2 setting for TM3_EXT           */
#define SYS_GPH_MFPL_PH2MFP_SD0_DAT1          (0x06UL<<SYS_GPH_MFPL_PH2MFP_Pos)  /*!< GPH_MFPL PH2 setting for SD0_DAT1          */
#define SYS_GPH_MFPL_PH2MFP_eMMC0_DAT1        (0x06UL<<SYS_GPH_MFPL_PH2MFP_Pos)  /*!< GPH_MFPL PH2 setting for eMMC0_DAT1        */

/* PH.3 MFP */
#define SYS_GPH_MFPL_PH3MFP_GPIO              (0x00UL<<SYS_GPH_MFPL_PH3MFP_Pos)  /*!< GPH_MFPL PH3 setting for GPIO              */
#define SYS_GPH_MFPL_PH3MFP_UART1_nCTS        (0x01UL<<SYS_GPH_MFPL_PH3MFP_Pos)  /*!< GPH_MFPL PH3 setting for UART1_nCTS        */
#define SYS_GPH_MFPL_PH3MFP_CAN3_TXD          (0x02UL<<SYS_GPH_MFPL_PH3MFP_Pos)  /*!< GPH_MFPL PH3 setting for CAN3_TXD          */
#define SYS_GPH_MFPL_PH3MFP_I2C3_SDA          (0x03UL<<SYS_GPH_MFPL_PH3MFP_Pos)  /*!< GPH_MFPL PH3 setting for I2C3_SDA          */
#define SYS_GPH_MFPL_PH3MFP_SD0_DAT2          (0x06UL<<SYS_GPH_MFPL_PH3MFP_Pos)  /*!< GPH_MFPL PH3 setting for SD0_DAT2          */
#define SYS_GPH_MFPL_PH3MFP_eMMC0_DAT2        (0x06UL<<SYS_GPH_MFPL_PH3MFP_Pos)  /*!< GPH_MFPL PH3 setting for eMMC0_DAT2        */

/* PH.4 MFP */
#define SYS_GPH_MFPL_PH4MFP_GPIO              (0x00UL<<SYS_GPH_MFPL_PH4MFP_Pos)  /*!< GPH_MFPL PH4 setting for GPIO              */
#define SYS_GPH_MFPL_PH4MFP_UART9_TXD         (0x01UL<<SYS_GPH_MFPL_PH4MFP_Pos)  /*!< GPH_MFPL PH4 setting for UART9_TXD         */
#define SYS_GPH_MFPL_PH4MFP_UART8_nCTS        (0x02UL<<SYS_GPH_MFPL_PH4MFP_Pos)  /*!< GPH_MFPL PH4 setting for UART8_nCTS        */
#define SYS_GPH_MFPL_PH4MFP_I2C3_SCL          (0x03UL<<SYS_GPH_MFPL_PH4MFP_Pos)  /*!< GPH_MFPL PH4 setting for I2C3_SCL          */
#define SYS_GPH_MFPL_PH4MFP_SD0_DAT3          (0x06UL<<SYS_GPH_MFPL_PH4MFP_Pos)  /*!< GPH_MFPL PH4 setting for SD0_DAT3          */
#define SYS_GPH_MFPL_PH4MFP_eMMC0_DAT3        (0x06UL<<SYS_GPH_MFPL_PH4MFP_Pos)  /*!< GPH_MFPL PH4 setting for eMMC0_DAT3        */

/* PH.5 MFP */
#define SYS_GPH_MFPL_PH5MFP_GPIO              (0x00UL<<SYS_GPH_MFPL_PH5MFP_Pos)  /*!< GPH_MFPL PH5 setting for GPIO              */
#define SYS_GPH_MFPL_PH5MFP_UART9_RXD         (0x01UL<<SYS_GPH_MFPL_PH5MFP_Pos)  /*!< GPH_MFPL PH5 setting for UART9_RXD         */
#define SYS_GPH_MFPL_PH5MFP_UART8_nRTS        (0x02UL<<SYS_GPH_MFPL_PH5MFP_Pos)  /*!< GPH_MFPL PH5 setting for UART8_nRTS        */
#define SYS_GPH_MFPL_PH5MFP_INT1              (0x04UL<<SYS_GPH_MFPL_PH5MFP_Pos)  /*!< GPH_MFPL PH5 setting for INT1              */
#define SYS_GPH_MFPL_PH5MFP_SPI0_MISO         (0x05UL<<SYS_GPH_MFPL_PH5MFP_Pos)  /*!< GPH_MFPL PH5 setting for SPI0_MISO         */
#define SYS_GPH_MFPL_PH5MFP_SD0_CMD           (0x06UL<<SYS_GPH_MFPL_PH5MFP_Pos)  /*!< GPH_MFPL PH5 setting for SD0_CMD           */
#define SYS_GPH_MFPL_PH5MFP_eMMC0_CMD         (0x06UL<<SYS_GPH_MFPL_PH5MFP_Pos)  /*!< GPH_MFPL PH5 setting for eMMC0_CMD         */

/* PH.6 MFP */
#define SYS_GPH_MFPL_PH6MFP_GPIO              (0x00UL<<SYS_GPH_MFPL_PH6MFP_Pos)  /*!< GPH_MFPL PH6 setting for GPIO              */
#define SYS_GPH_MFPL_PH6MFP_UART9_nRTS        (0x01UL<<SYS_GPH_MFPL_PH6MFP_Pos)  /*!< GPH_MFPL PH6 setting for UART9_nRTS        */
#define SYS_GPH_MFPL_PH6MFP_SPI0_CLK          (0x05UL<<SYS_GPH_MFPL_PH6MFP_Pos)  /*!< GPH_MFPL PH6 setting for SPI0_CLK          */
#define SYS_GPH_MFPL_PH6MFP_SD0_CLK           (0x06UL<<SYS_GPH_MFPL_PH6MFP_Pos)  /*!< GPH_MFPL PH6 setting for SD0_CLK           */
#define SYS_GPH_MFPL_PH6MFP_eMMC0_CLK         (0x06UL<<SYS_GPH_MFPL_PH6MFP_Pos)  /*!< GPH_MFPL PH6 setting for eMMC0_CLK         */

/* PH.7 MFP */
#define SYS_GPH_MFPL_PH7MFP_GPIO              (0x00UL<<SYS_GPH_MFPL_PH7MFP_Pos)  /*!< GPH_MFPL PH7 setting for GPIO              */
#define SYS_GPH_MFPL_PH7MFP_UART9_nCTS        (0x01UL<<SYS_GPH_MFPL_PH7MFP_Pos)  /*!< GPH_MFPL PH7 setting for UART9_nCTS        */
#define SYS_GPH_MFPL_PH7MFP_I2C2_SDA          (0x03UL<<SYS_GPH_MFPL_PH7MFP_Pos)  /*!< GPH_MFPL PH7 setting for I2C2_SDA          */
#define SYS_GPH_MFPL_PH7MFP_INT1              (0x04UL<<SYS_GPH_MFPL_PH7MFP_Pos)  /*!< GPH_MFPL PH7 setting for INT1              */
#define SYS_GPH_MFPL_PH7MFP_SPI1_SS1          (0x05UL<<SYS_GPH_MFPL_PH7MFP_Pos)  /*!< GPH_MFPL PH7 setting for SPI1_SS1          */
#define SYS_GPH_MFPL_PH7MFP_SD1_nCD           (0x06UL<<SYS_GPH_MFPL_PH7MFP_Pos)  /*!< GPH_MFPL PH7 setting for SD1_nCD           */

/* PH.8 MFP */
#define SYS_GPH_MFPH_PH8MFP_GPIO              (0x00UL<<SYS_GPH_MFPH_PH8MFP_Pos)  /*!< GPH_MFPH PH8 setting for GPIO              */
#define SYS_GPH_MFPH_PH8MFP_UART2_TXD         (0x01UL<<SYS_GPH_MFPH_PH8MFP_Pos)  /*!< GPH_MFPH PH8 setting for UART2_TXD         */
#define SYS_GPH_MFPH_PH8MFP_UART6_nCTS        (0x02UL<<SYS_GPH_MFPH_PH8MFP_Pos)  /*!< GPH_MFPH PH8 setting for UART6_nCTS        */
#define SYS_GPH_MFPH_PH8MFP_I2C2_SCL          (0x03UL<<SYS_GPH_MFPH_PH8MFP_Pos)  /*!< GPH_MFPH PH8 setting for I2C2_SCL          */
#define SYS_GPH_MFPH_PH8MFP_INT0              (0x04UL<<SYS_GPH_MFPH_PH8MFP_Pos)  /*!< GPH_MFPH PH8 setting for INT0              */
#define SYS_GPH_MFPH_PH8MFP_SD1_CMD           (0x06UL<<SYS_GPH_MFPH_PH8MFP_Pos)  /*!< GPH_MFPH PH8 setting for SD1_CMD           */
#define SYS_GPH_MFPH_PH8MFP_eMMC1_CMD         (0x06UL<<SYS_GPH_MFPH_PH8MFP_Pos)  /*!< GPH_MFPH PH8 setting for eMMC1_CMD         */

/* PH.9 MFP */
#define SYS_GPH_MFPH_PH9MFP_GPIO              (0x00UL<<SYS_GPH_MFPH_PH9MFP_Pos)  /*!< GPH_MFPH PH9 setting for GPIO              */
#define SYS_GPH_MFPH_PH9MFP_UART2_RXD         (0x01UL<<SYS_GPH_MFPH_PH9MFP_Pos)  /*!< GPH_MFPH PH9 setting for UART2_RXD         */
#define SYS_GPH_MFPH_PH9MFP_UART6_nRTS        (0x02UL<<SYS_GPH_MFPH_PH9MFP_Pos)  /*!< GPH_MFPH PH9 setting for UART6_nRTS        */
#define SYS_GPH_MFPH_PH9MFP_SD1_CLK           (0x06UL<<SYS_GPH_MFPH_PH9MFP_Pos)  /*!< GPH_MFPH PH9 setting for SD1_CLK           */
#define SYS_GPH_MFPH_PH9MFP_eMMC1_CLK         (0x06UL<<SYS_GPH_MFPH_PH9MFP_Pos)  /*!< GPH_MFPH PH9 setting for eMMC1_CLK         */


/*! @}*/ /* end of group SYS_EXPORTED_CONSTANTS */

/** @addtogroup SYS_EXPORTED_FUNCTIONS SYS Exported Functions
  @{
*/

/*---------------------------------------------------------------------------------------------------------*/
/*  Multi-Function macro definitions.                                                                      */
/*---------------------------------------------------------------------------------------------------------*/


/* GPIO */
#define SET_GPIO_PA0()             SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA0MFP_Msk) | SYS_GPA_MFPL_PA0MFP_GPIO)        /*!< Set PA0 function to GPIO            */
#define SET_GPIO_PA1()             SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA1MFP_Msk) | SYS_GPA_MFPL_PA1MFP_GPIO)        /*!< Set PA1 function to GPIO            */
#define SET_GPIO_PA2()             SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA2MFP_Msk) | SYS_GPA_MFPL_PA2MFP_GPIO)        /*!< Set PA2 function to GPIO            */
#define SET_GPIO_PA3()             SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA3MFP_Msk) | SYS_GPA_MFPL_PA3MFP_GPIO)        /*!< Set PA3 function to GPIO            */
#define SET_GPIO_PA4()             SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA4MFP_Msk) | SYS_GPA_MFPL_PA4MFP_GPIO)        /*!< Set PA4 function to GPIO            */
#define SET_GPIO_PA5()             SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA5MFP_Msk) | SYS_GPA_MFPL_PA5MFP_GPIO)        /*!< Set PA5 function to GPIO            */
#define SET_GPIO_PA6()             SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA6MFP_Msk) | SYS_GPA_MFPL_PA6MFP_GPIO)        /*!< Set PA6 function to GPIO            */
#define SET_GPIO_PA7()             SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA7MFP_Msk) | SYS_GPA_MFPL_PA7MFP_GPIO)        /*!< Set PA7 function to GPIO            */
#define SET_GPIO_PA8()             SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA8MFP_Msk) | SYS_GPA_MFPH_PA8MFP_GPIO)        /*!< Set PA8 function to GPIO            */
#define SET_GPIO_PA9()             SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA9MFP_Msk) | SYS_GPA_MFPH_PA9MFP_GPIO)        /*!< Set PA9 function to GPIO            */
#define SET_GPIO_PA10()            SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA10MFP_Msk) | SYS_GPA_MFPH_PA10MFP_GPIO)      /*!< Set PA10 function to GPIO           */
#define SET_GPIO_PA11()            SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA11MFP_Msk) | SYS_GPA_MFPH_PA11MFP_GPIO)      /*!< Set PA11 function to GPIO           */
#define SET_GPIO_PA12()            SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA12MFP_Msk) | SYS_GPA_MFPH_PA12MFP_GPIO)      /*!< Set PA12 function to GPIO           */
#define SET_GPIO_PA13()            SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA13MFP_Msk) | SYS_GPA_MFPH_PA13MFP_GPIO)      /*!< Set PA13 function to GPIO           */
#define SET_GPIO_PA14()            SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA14MFP_Msk) | SYS_GPA_MFPH_PA14MFP_GPIO)      /*!< Set PA14 function to GPIO           */
#define SET_GPIO_PA15()            SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA15MFP_Msk) | SYS_GPA_MFPH_PA15MFP_GPIO)      /*!< Set PA15 function to GPIO           */

#define SET_GPIO_PB0()             SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB0MFP_Msk) | SYS_GPB_MFPL_PB0MFP_GPIO)        /*!< Set PB0 function to GPIO            */
#define SET_GPIO_PB1()             SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB1MFP_Msk) | SYS_GPB_MFPL_PB1MFP_GPIO)        /*!< Set PB1 function to GPIO            */
#define SET_GPIO_PB2()             SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB2MFP_Msk) | SYS_GPB_MFPL_PB2MFP_GPIO)        /*!< Set PB2 function to GPIO            */
#define SET_GPIO_PB3()             SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB3MFP_Msk) | SYS_GPB_MFPL_PB3MFP_GPIO)        /*!< Set PB3 function to GPIO            */
#define SET_GPIO_PB4()             SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB4MFP_Msk) | SYS_GPB_MFPL_PB4MFP_GPIO)        /*!< Set PB4 function to GPIO            */
#define SET_GPIO_PB5()             SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB5MFP_Msk) | SYS_GPB_MFPL_PB5MFP_GPIO)        /*!< Set PB5 function to GPIO            */
#define SET_GPIO_PB6()             SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB6MFP_Msk) | SYS_GPB_MFPL_PB6MFP_GPIO)        /*!< Set PB6 function to GPIO            */
#define SET_GPIO_PB7()             SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB7MFP_Msk) | SYS_GPB_MFPL_PB7MFP_GPIO)        /*!< Set PB7 function to GPIO            */
#define SET_GPIO_PB8()             SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB8MFP_Msk) | SYS_GPB_MFPH_PB8MFP_GPIO)        /*!< Set PB8 function to GPIO            */
#define SET_GPIO_PB9()             SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB9MFP_Msk) | SYS_GPB_MFPH_PB9MFP_GPIO)        /*!< Set PB9 function to GPIO            */
#define SET_GPIO_PB10()            SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB10MFP_Msk) | SYS_GPB_MFPH_PB10MFP_GPIO)      /*!< Set PB10 function to GPIO           */
#define SET_GPIO_PB11()            SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB11MFP_Msk) | SYS_GPB_MFPH_PB11MFP_GPIO)      /*!< Set PB11 function to GPIO           */
#define SET_GPIO_PB12()            SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB12MFP_Msk) | SYS_GPB_MFPH_PB12MFP_GPIO)      /*!< Set PB12 function to GPIO           */
#define SET_GPIO_PB13()            SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB13MFP_Msk) | SYS_GPB_MFPH_PB13MFP_GPIO)      /*!< Set PB13 function to GPIO           */

#define SET_GPIO_PC0()             SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC0MFP_Msk) | SYS_GPC_MFPL_PC0MFP_GPIO)        /*!< Set PC0 function to GPIO            */
#define SET_GPIO_PC1()             SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC1MFP_Msk) | SYS_GPC_MFPL_PC1MFP_GPIO)        /*!< Set PC1 function to GPIO            */
#define SET_GPIO_PC2()             SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC2MFP_Msk) | SYS_GPC_MFPL_PC2MFP_GPIO)        /*!< Set PC2 function to GPIO            */
#define SET_GPIO_PC3()             SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC3MFP_Msk) | SYS_GPC_MFPL_PC3MFP_GPIO)        /*!< Set PC3 function to GPIO            */
#define SET_GPIO_PC4()             SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC4MFP_Msk) | SYS_GPC_MFPL_PC4MFP_GPIO)        /*!< Set PC4 function to GPIO            */
#define SET_GPIO_PC5()             SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC5MFP_Msk) | SYS_GPC_MFPL_PC5MFP_GPIO)        /*!< Set PC5 function to GPIO            */
#define SET_GPIO_PC6()             SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC6MFP_Msk) | SYS_GPC_MFPL_PC6MFP_GPIO)        /*!< Set PC6 function to GPIO            */
#define SET_GPIO_PC7()             SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC7MFP_Msk) | SYS_GPC_MFPL_PC7MFP_GPIO)        /*!< Set PC7 function to GPIO            */
#define SET_GPIO_PC8()             SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC8MFP_Msk) | SYS_GPC_MFPH_PC8MFP_GPIO)        /*!< Set PC8 function to GPIO            */
#define SET_GPIO_PC9()             SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC9MFP_Msk) | SYS_GPC_MFPH_PC9MFP_GPIO)        /*!< Set PC9 function to GPIO            */
#define SET_GPIO_PC10()            SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC10MFP_Msk) | SYS_GPC_MFPH_PC10MFP_GPIO)      /*!< Set PC10 function to GPIO           */
#define SET_GPIO_PC11()            SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC11MFP_Msk) | SYS_GPC_MFPH_PC11MFP_GPIO)      /*!< Set PC11 function to GPIO           */
#define SET_GPIO_PC12()            SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC12MFP_Msk) | SYS_GPC_MFPH_PC12MFP_GPIO)      /*!< Set PC12 function to GPIO           */
#define SET_GPIO_PC13()            SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC13MFP_Msk) | SYS_GPC_MFPH_PC13MFP_GPIO)      /*!< Set PC13 function to GPIO           */
#define SET_GPIO_PC14()            SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC14MFP_Msk) | SYS_GPC_MFPH_PC14MFP_GPIO)      /*!< Set PC14 function to GPIO           */
#define SET_GPIO_PC15()            SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC15MFP_Msk) | SYS_GPC_MFPH_PC15MFP_GPIO)      /*!< Set PC15 function to GPIO           */

#define SET_GPIO_PD0()             SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD0MFP_Msk) | SYS_GPD_MFPL_PD0MFP_GPIO)        /*!< Set PD0 function to GPIO            */
#define SET_GPIO_PD1()             SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD1MFP_Msk) | SYS_GPD_MFPL_PD1MFP_GPIO)        /*!< Set PD1 function to GPIO            */
#define SET_GPIO_PD2()             SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD2MFP_Msk) | SYS_GPD_MFPL_PD2MFP_GPIO)        /*!< Set PD2 function to GPIO            */
#define SET_GPIO_PD3()             SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD3MFP_Msk) | SYS_GPD_MFPL_PD3MFP_GPIO)        /*!< Set PD3 function to GPIO            */
#define SET_GPIO_PD4()             SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD4MFP_Msk) | SYS_GPD_MFPL_PD4MFP_GPIO)        /*!< Set PD4 function to GPIO            */
#define SET_GPIO_PD5()             SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD5MFP_Msk) | SYS_GPD_MFPL_PD5MFP_GPIO)        /*!< Set PD5 function to GPIO            */
#define SET_GPIO_PD6()             SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD6MFP_Msk) | SYS_GPD_MFPL_PD6MFP_GPIO)        /*!< Set PD6 function to GPIO            */
#define SET_GPIO_PD7()             SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD7MFP_Msk) | SYS_GPD_MFPL_PD7MFP_GPIO)        /*!< Set PD7 function to GPIO            */
#define SET_GPIO_PD8()             SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD8MFP_Msk) | SYS_GPD_MFPH_PD8MFP_GPIO)        /*!< Set PD8 function to GPIO            */
#define SET_GPIO_PD9()             SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD9MFP_Msk) | SYS_GPD_MFPH_PD9MFP_GPIO)        /*!< Set PD9 function to GPIO            */
#define SET_GPIO_PD10()            SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD10MFP_Msk) | SYS_GPD_MFPH_PD10MFP_GPIO)      /*!< Set PD10 function to GPIO           */
#define SET_GPIO_PD11()            SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD11MFP_Msk) | SYS_GPD_MFPH_PD11MFP_GPIO)      /*!< Set PD11 function to GPIO           */
#define SET_GPIO_PD12()            SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD12MFP_Msk) | SYS_GPD_MFPH_PD12MFP_GPIO)      /*!< Set PD12 function to GPIO           */
#define SET_GPIO_PD13()            SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD13MFP_Msk) | SYS_GPD_MFPH_PD13MFP_GPIO)      /*!< Set PD13 function to GPIO           */
#define SET_GPIO_PD14()            SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD14MFP_Msk) | SYS_GPD_MFPH_PD14MFP_GPIO)      /*!< Set PD14 function to GPIO           */
#define SET_GPIO_PD15()            SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD15MFP_Msk) | SYS_GPD_MFPH_PD15MFP_GPIO)      /*!< Set PD15 function to GPIO           */

#define SET_GPIO_PE0()             SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE0MFP_Msk) | SYS_GPE_MFPL_PE0MFP_GPIO)        /*!< Set PE0 function to GPIO            */
#define SET_GPIO_PE1()             SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE1MFP_Msk) | SYS_GPE_MFPL_PE1MFP_GPIO)        /*!< Set PE1 function to GPIO            */
#define SET_GPIO_PE2()             SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE2MFP_Msk) | SYS_GPE_MFPL_PE2MFP_GPIO)        /*!< Set PE2 function to GPIO            */
#define SET_GPIO_PE3()             SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE3MFP_Msk) | SYS_GPE_MFPL_PE3MFP_GPIO)        /*!< Set PE3 function to GPIO            */
#define SET_GPIO_PE4()             SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE4MFP_Msk) | SYS_GPE_MFPL_PE4MFP_GPIO)        /*!< Set PE4 function to GPIO            */
#define SET_GPIO_PE5()             SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE5MFP_Msk) | SYS_GPE_MFPL_PE5MFP_GPIO)        /*!< Set PE5 function to GPIO            */
#define SET_GPIO_PE6()             SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE6MFP_Msk) | SYS_GPE_MFPL_PE6MFP_GPIO)        /*!< Set PE6 function to GPIO            */
#define SET_GPIO_PE7()             SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE7MFP_Msk) | SYS_GPE_MFPL_PE7MFP_GPIO)        /*!< Set PE7 function to GPIO            */
#define SET_GPIO_PE8()             SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE8MFP_Msk) | SYS_GPE_MFPH_PE8MFP_GPIO)        /*!< Set PE8 function to GPIO            */
#define SET_GPIO_PE9()             SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE9MFP_Msk) | SYS_GPE_MFPH_PE9MFP_GPIO)        /*!< Set PE9 function to GPIO            */
#define SET_GPIO_PE10()            SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE10MFP_Msk) | SYS_GPE_MFPH_PE10MFP_GPIO)      /*!< Set PE10 function to GPIO           */
#define SET_GPIO_PE11()            SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE11MFP_Msk) | SYS_GPE_MFPH_PE11MFP_GPIO)      /*!< Set PE11 function to GPIO           */
#define SET_GPIO_PE12()            SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE12MFP_Msk) | SYS_GPE_MFPH_PE12MFP_GPIO)      /*!< Set PE12 function to GPIO           */

#define SET_GPIO_PF0()             SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF0MFP_Msk) | SYS_GPF_MFPL_PF0MFP_GPIO)        /*!< Set PF0 function to GPIO            */
#define SET_GPIO_PF1()             SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF1MFP_Msk) | SYS_GPF_MFPL_PF1MFP_GPIO)        /*!< Set PF1 function to GPIO            */
#define SET_GPIO_PF2()             SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF2MFP_Msk) | SYS_GPF_MFPL_PF2MFP_GPIO)        /*!< Set PF2 function to GPIO            */
#define SET_GPIO_PF3()             SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF3MFP_Msk) | SYS_GPF_MFPL_PF3MFP_GPIO)        /*!< Set PF3 function to GPIO            */
#define SET_GPIO_PF4()             SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF4MFP_Msk) | SYS_GPF_MFPL_PF4MFP_GPIO)        /*!< Set PF4 function to GPIO            */
#define SET_GPIO_PF5()             SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF5MFP_Msk) | SYS_GPF_MFPL_PF5MFP_GPIO)        /*!< Set PF5 function to GPIO            */
#define SET_GPIO_PF6()             SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF6MFP_Msk) | SYS_GPF_MFPL_PF6MFP_GPIO)        /*!< Set PF6 function to GPIO            */
#define SET_GPIO_PF7()             SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF7MFP_Msk) | SYS_GPF_MFPL_PF7MFP_GPIO)        /*!< Set PF7 function to GPIO            */
#define SET_GPIO_PF8()             SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF8MFP_Msk) | SYS_GPF_MFPH_PF8MFP_GPIO)        /*!< Set PF8 function to GPIO            */
#define SET_GPIO_PF9()             SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF9MFP_Msk) | SYS_GPF_MFPH_PF9MFP_GPIO)        /*!< Set PF9 function to GPIO            */
#define SET_GPIO_PF10()            SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF10MFP_Msk) | SYS_GPF_MFPH_PF10MFP_GPIO)      /*!< Set PF10 function to GPIO           */
#define SET_GPIO_PF11()            SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF11MFP_Msk) | SYS_GPF_MFPH_PF11MFP_GPIO)      /*!< Set PF11 function to GPIO           */
#define SET_GPIO_PF12()            SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF12MFP_Msk) | SYS_GPF_MFPH_PF12MFP_GPIO)      /*!< Set PF12 function to GPIO           */

#define SET_GPIO_PG0()             SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG0MFP_Msk) | SYS_GPG_MFPL_PG0MFP_GPIO)        /*!< Set PG0 function to GPIO            */
#define SET_GPIO_PG1()             SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG1MFP_Msk) | SYS_GPG_MFPL_PG1MFP_GPIO)        /*!< Set PG1 function to GPIO            */
#define SET_GPIO_PG2()             SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG2MFP_Msk) | SYS_GPG_MFPL_PG2MFP_GPIO)        /*!< Set PG2 function to GPIO            */
#define SET_GPIO_PG3()             SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG3MFP_Msk) | SYS_GPG_MFPL_PG3MFP_GPIO)        /*!< Set PG3 function to GPIO            */
#define SET_GPIO_PG4()             SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG4MFP_Msk) | SYS_GPG_MFPL_PG4MFP_GPIO)        /*!< Set PG4 function to GPIO            */
#define SET_GPIO_PG5()             SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG5MFP_Msk) | SYS_GPG_MFPL_PG5MFP_GPIO)        /*!< Set PG5 function to GPIO            */
#define SET_GPIO_PG6()             SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG6MFP_Msk) | SYS_GPG_MFPL_PG6MFP_GPIO)        /*!< Set PG6 function to GPIO            */
#define SET_GPIO_PG7()             SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG7MFP_Msk) | SYS_GPG_MFPL_PG7MFP_GPIO)        /*!< Set PG7 function to GPIO            */
#define SET_GPIO_PG8()             SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG8MFP_Msk) | SYS_GPG_MFPH_PG8MFP_GPIO)        /*!< Set PG8 function to GPIO            */
#define SET_GPIO_PG9()             SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG9MFP_Msk) | SYS_GPG_MFPH_PG9MFP_GPIO)        /*!< Set PG9 function to GPIO            */
#define SET_GPIO_PG10()            SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG10MFP_Msk) | SYS_GPG_MFPH_PG10MFP_GPIO)       /*!< Set PG10 function to GPIO           */
#define SET_GPIO_PG11()            SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG11MFP_Msk) | SYS_GPG_MFPH_PG11MFP_GPIO)       /*!< Set PG11 function to GPIO           */
#define SET_GPIO_PG12()            SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG12MFP_Msk) | SYS_GPG_MFPH_PG12MFP_GPIO)       /*!< Set PG12 function to GPIO           */
#define SET_GPIO_PG13()            SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG13MFP_Msk) | SYS_GPG_MFPH_PG13MFP_GPIO)       /*!< Set PG13 function to GPIO           */
#define SET_GPIO_PG14()            SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG14MFP_Msk) | SYS_GPG_MFPH_PG14MFP_GPIO)       /*!< Set PG14 function to GPIO           */
#define SET_GPIO_PG15()            SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG15MFP_Msk) | SYS_GPG_MFPH_PG15MFP_GPIO)       /*!< Set PG15 function to GPIO           */

#define SET_GPIO_PH0()             SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH0MFP_Msk) | SYS_GPH_MFPL_PH0MFP_GPIO)        /*!< Set PH0 function to GPIO            */
#define SET_GPIO_PH1()             SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH1MFP_Msk) | SYS_GPH_MFPL_PH1MFP_GPIO)        /*!< Set PH1 function to GPIO            */
#define SET_GPIO_PH2()             SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH2MFP_Msk) | SYS_GPH_MFPL_PH2MFP_GPIO)        /*!< Set PH2 function to GPIO            */
#define SET_GPIO_PH3()             SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH3MFP_Msk) | SYS_GPH_MFPL_PH3MFP_GPIO)        /*!< Set PH3 function to GPIO            */
#define SET_GPIO_PH4()             SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH4MFP_Msk) | SYS_GPH_MFPL_PH4MFP_GPIO)        /*!< Set PH4 function to GPIO            */
#define SET_GPIO_PH5()             SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH5MFP_Msk) | SYS_GPH_MFPL_PH5MFP_GPIO)        /*!< Set PH5 function to GPIO            */
#define SET_GPIO_PH6()             SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH6MFP_Msk) | SYS_GPH_MFPL_PH6MFP_GPIO)        /*!< Set PH6 function to GPIO            */
#define SET_GPIO_PH7()             SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH7MFP_Msk) | SYS_GPH_MFPL_PH7MFP_GPIO)        /*!< Set PH7 function to GPIO            */
#define SET_GPIO_PH8()             SYS->GPH_MFPH = ((SYS->GPH_MFPH & ~SYS_GPH_MFPH_PH8MFP_Msk) | SYS_GPH_MFPH_PH8MFP_GPIO)        /*!< Set PH8 function to GPIO            */
#define SET_GPIO_PH9()             SYS->GPH_MFPH = ((SYS->GPH_MFPH & ~SYS_GPH_MFPH_PH9MFP_Msk) | SYS_GPH_MFPH_PH9MFP_GPIO)        /*!< Set PH9 function to GPIO            */

/* ADC0 */
#define SET_ADC0_CH0_PB0()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB0MFP_Msk) | SYS_GPB_MFPL_PB0MFP_ADC0_CH0)  /*!< Set PB0 function to ADC0_CH0        */
#define SET_ADC0_CH1_PB1()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB1MFP_Msk) | SYS_GPB_MFPL_PB1MFP_ADC0_CH1)  /*!< Set PB1 function to ADC0_CH1        */
#define SET_ADC0_CH2_PB2()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB2MFP_Msk) | SYS_GPB_MFPL_PB2MFP_ADC0_CH2)  /*!< Set PB2 function to ADC0_CH2        */
#define SET_ADC0_CH3_PB3()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB3MFP_Msk) | SYS_GPB_MFPL_PB3MFP_ADC0_CH3)  /*!< Set PB3 function to ADC0_CH3        */
#define SET_ADC0_CH4_PB4()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB4MFP_Msk) | SYS_GPB_MFPL_PB4MFP_ADC0_CH4)  /*!< Set PB4 function to ADC0_CH4        */
#define SET_ADC0_CH5_PB5()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB5MFP_Msk) | SYS_GPB_MFPL_PB5MFP_ADC0_CH5)  /*!< Set PB5 function to ADC0_CH5        */
#define SET_ADC0_CH6_PB6()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB6MFP_Msk) | SYS_GPB_MFPL_PB6MFP_ADC0_CH6)  /*!< Set PB6 function to ADC0_CH6        */
#define SET_ADC0_CH7_PB7()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB7MFP_Msk) | SYS_GPB_MFPL_PB7MFP_ADC0_CH7)  /*!< Set PB7 function to ADC0_CH7        */

/* BPWM0 */
#define SET_BPWM0_CH0_PD12()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD12MFP_Msk) | SYS_GPD_MFPH_PD12MFP_BPWM0_CH0)/*!< Set PD12 function to BPWM0_CH0     */
#define SET_BPWM0_CH0_PF5()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF5MFP_Msk) | SYS_GPF_MFPL_PF5MFP_BPWM0_CH0) /*!< Set PF5 function to BPWM0_CH0       */
#define SET_BPWM0_CH0_PG0()        SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG0MFP_Msk) | SYS_GPG_MFPL_PG0MFP_BPWM0_CH0) /*!< Set PG0 function to BPWM0_CH0       */
#define SET_BPWM0_CH0_PG10()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG10MFP_Msk) | SYS_GPG_MFPH_PG10MFP_BPWM0_CH0)/*!< Set PG10 function to BPWM0_CH0     */
#define SET_BPWM0_CH1_PA15()       SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA15MFP_Msk) | SYS_GPA_MFPH_PA15MFP_BPWM0_CH1)/*!< Set PA15 function to BPWM0_CH1     */
#define SET_BPWM0_CH1_PD13()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD13MFP_Msk) | SYS_GPD_MFPH_PD13MFP_BPWM0_CH1)/*!< Set PD13 function to BPWM0_CH1     */
#define SET_BPWM0_CH1_PF6()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF6MFP_Msk) | SYS_GPF_MFPL_PF6MFP_BPWM0_CH1) /*!< Set PF6 function to BPWM0_CH1       */
#define SET_BPWM0_CH1_PG1()        SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG1MFP_Msk) | SYS_GPG_MFPL_PG1MFP_BPWM0_CH1) /*!< Set PG1 function to BPWM0_CH1       */
#define SET_BPWM0_CH2_PA14()       SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA14MFP_Msk) | SYS_GPA_MFPH_PA14MFP_BPWM0_CH2)/*!< Set PA14 function to BPWM0_CH2     */
#define SET_BPWM0_CH2_PB13()       SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB13MFP_Msk) | SYS_GPB_MFPH_PB13MFP_BPWM0_CH2)/*!< Set PB13 function to BPWM0_CH2     */
#define SET_BPWM0_CH2_PD14()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD14MFP_Msk) | SYS_GPD_MFPH_PD14MFP_BPWM0_CH2)/*!< Set PD14 function to BPWM0_CH2     */
#define SET_BPWM0_CH2_PF7()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF7MFP_Msk) | SYS_GPF_MFPL_PF7MFP_BPWM0_CH2) /*!< Set PF7 function to BPWM0_CH2       */
#define SET_BPWM0_CH2_PG2()        SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG2MFP_Msk) | SYS_GPG_MFPL_PG2MFP_BPWM0_CH2) /*!< Set PG2 function to BPWM0_CH2       */
#define SET_BPWM0_CH3_PA13()       SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA13MFP_Msk) | SYS_GPA_MFPH_PA13MFP_BPWM0_CH3)/*!< Set PA13 function to BPWM0_CH3     */
#define SET_BPWM0_CH3_PD15()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD15MFP_Msk) | SYS_GPD_MFPH_PD15MFP_BPWM0_CH3)/*!< Set PD15 function to BPWM0_CH3     */
#define SET_BPWM0_CH3_PF8()        SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF8MFP_Msk) | SYS_GPF_MFPH_PF8MFP_BPWM0_CH3) /*!< Set PF8 function to BPWM0_CH3       */
#define SET_BPWM0_CH3_PG3()        SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG3MFP_Msk) | SYS_GPG_MFPL_PG3MFP_BPWM0_CH3) /*!< Set PG3 function to BPWM0_CH3       */
#define SET_BPWM0_CH4_PA6()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA6MFP_Msk) | SYS_GPA_MFPL_PA6MFP_BPWM0_CH4) /*!< Set PA6 function to BPWM0_CH4       */
#define SET_BPWM0_CH4_PA10()       SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA10MFP_Msk) | SYS_GPA_MFPH_PA10MFP_BPWM0_CH4)/*!< Set PA10 function to BPWM0_CH4     */
#define SET_BPWM0_CH4_PD11()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD11MFP_Msk) | SYS_GPD_MFPH_PD11MFP_BPWM0_CH4)/*!< Set PD11 function to BPWM0_CH4     */
#define SET_BPWM0_CH4_PF3()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF3MFP_Msk) | SYS_GPF_MFPL_PF3MFP_BPWM0_CH4) /*!< Set PF3 function to BPWM0_CH4       */
#define SET_BPWM0_CH5_PA5()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA5MFP_Msk) | SYS_GPA_MFPL_PA5MFP_BPWM0_CH5) /*!< Set PA5 function to BPWM0_CH5       */
#define SET_BPWM0_CH5_PA9()        SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA9MFP_Msk) | SYS_GPA_MFPH_PA9MFP_BPWM0_CH5) /*!< Set PA9 function to BPWM0_CH5       */
#define SET_BPWM0_CH5_PD10()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD10MFP_Msk) | SYS_GPD_MFPH_PD10MFP_BPWM0_CH5)/*!< Set PD10 function to BPWM0_CH5     */
#define SET_BPWM0_CH5_PF2()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF2MFP_Msk) | SYS_GPF_MFPL_PF2MFP_BPWM0_CH5) /*!< Set PF2 function to BPWM0_CH5       */

/* BPWM1 */
#define SET_BPWM1_CH0_PB12()       SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB12MFP_Msk) | SYS_GPB_MFPH_PB12MFP_BPWM1_CH0)/*!< Set PB12 function to BPWM1_CH0     */
#define SET_BPWM1_CH0_PF9()        SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF9MFP_Msk) | SYS_GPF_MFPH_PF9MFP_BPWM1_CH0) /*!< Set PF9 function to BPWM1_CH0       */
#define SET_BPWM1_CH0_PG6()        SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG6MFP_Msk) | SYS_GPG_MFPL_PG6MFP_BPWM1_CH0) /*!< Set PG6 function to BPWM1_CH0       */
#define SET_BPWM1_CH0_PG11()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG11MFP_Msk) | SYS_GPG_MFPH_PG11MFP_BPWM1_CH0)/*!< Set PG11 function to BPWM1_CH0     */
#define SET_BPWM1_CH1_PB11()       SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB11MFP_Msk) | SYS_GPB_MFPH_PB11MFP_BPWM1_CH1)/*!< Set PB11 function to BPWM1_CH1     */
#define SET_BPWM1_CH1_PF10()       SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF10MFP_Msk) | SYS_GPF_MFPH_PF10MFP_BPWM1_CH1)/*!< Set PF10 function to BPWM1_CH1     */
#define SET_BPWM1_CH1_PG7()        SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG7MFP_Msk) | SYS_GPG_MFPL_PG7MFP_BPWM1_CH1) /*!< Set PG7 function to BPWM1_CH1       */
#define SET_BPWM1_CH1_PG12()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG12MFP_Msk) | SYS_GPG_MFPH_PG12MFP_BPWM1_CH1)/*!< Set PG12 function to BPWM1_CH1     */
#define SET_BPWM1_CH2_PB10()       SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB10MFP_Msk) | SYS_GPB_MFPH_PB10MFP_BPWM1_CH2)/*!< Set PB10 function to BPWM1_CH2     */
#define SET_BPWM1_CH2_PE10()       SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE10MFP_Msk) | SYS_GPE_MFPH_PE10MFP_BPWM1_CH2)/*!< Set PE10 function to BPWM1_CH2     */
#define SET_BPWM1_CH2_PG8()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG8MFP_Msk) | SYS_GPG_MFPH_PG8MFP_BPWM1_CH2) /*!< Set PG8 function to BPWM1_CH2       */
#define SET_BPWM1_CH2_PG13()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG13MFP_Msk) | SYS_GPG_MFPH_PG13MFP_BPWM1_CH2)/*!< Set PG13 function to BPWM1_CH2     */
#define SET_BPWM1_CH3_PB9()        SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB9MFP_Msk) | SYS_GPB_MFPH_PB9MFP_BPWM1_CH3) /*!< Set PB9 function to BPWM1_CH3       */
#define SET_BPWM1_CH3_PE12()       SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE12MFP_Msk) | SYS_GPE_MFPH_PE12MFP_BPWM1_CH3)/*!< Set PE12 function to BPWM1_CH3     */
#define SET_BPWM1_CH3_PG9()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG9MFP_Msk) | SYS_GPG_MFPH_PG9MFP_BPWM1_CH3) /*!< Set PG9 function to BPWM1_CH3       */
#define SET_BPWM1_CH3_PG14()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG14MFP_Msk) | SYS_GPG_MFPH_PG14MFP_BPWM1_CH3)/*!< Set PG14 function to BPWM1_CH3     */
#define SET_BPWM1_CH4_PA4()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA4MFP_Msk) | SYS_GPA_MFPL_PA4MFP_BPWM1_CH4) /*!< Set PA4 function to BPWM1_CH4       */
#define SET_BPWM1_CH4_PA8()        SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA8MFP_Msk) | SYS_GPA_MFPH_PA8MFP_BPWM1_CH4) /*!< Set PA8 function to BPWM1_CH4       */
#define SET_BPWM1_CH4_PD9()        SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD9MFP_Msk) | SYS_GPD_MFPH_PD9MFP_BPWM1_CH4) /*!< Set PD9 function to BPWM1_CH4       */
#define SET_BPWM1_CH4_PF1()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF1MFP_Msk) | SYS_GPF_MFPL_PF1MFP_BPWM1_CH4) /*!< Set PF1 function to BPWM1_CH4       */
#define SET_BPWM1_CH5_PA3()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA3MFP_Msk) | SYS_GPA_MFPL_PA3MFP_BPWM1_CH5) /*!< Set PA3 function to BPWM1_CH5       */
#define SET_BPWM1_CH5_PA7()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA7MFP_Msk) | SYS_GPA_MFPL_PA7MFP_BPWM1_CH5) /*!< Set PA7 function to BPWM1_CH5       */
#define SET_BPWM1_CH5_PD8()        SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD8MFP_Msk) | SYS_GPD_MFPH_PD8MFP_BPWM1_CH5) /*!< Set PD8 function to BPWM1_CH5       */
#define SET_BPWM1_CH5_PF0()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF0MFP_Msk) | SYS_GPF_MFPL_PF0MFP_BPWM1_CH5) /*!< Set PF0 function to BPWM1_CH5       */

/* CAN0 */
#define SET_CAN0_RXD_PC3()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC3MFP_Msk) | SYS_GPC_MFPL_PC3MFP_CAN0_RXD)  /*!< Set PC3 function to CAN0_RXD        */
#define SET_CAN0_RXD_PD6()         SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD6MFP_Msk) | SYS_GPD_MFPL_PD6MFP_CAN0_RXD)  /*!< Set PD6 function to CAN0_RXD        */
#define SET_CAN0_RXD_PE0()         SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE0MFP_Msk) | SYS_GPE_MFPL_PE0MFP_CAN0_RXD)  /*!< Set PE0 function to CAN0_RXD        */
#define SET_CAN0_RXD_PG11()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG11MFP_Msk) | SYS_GPG_MFPH_PG11MFP_CAN0_RXD)/*!< Set PG11 function to CAN0_RXD       */
#define SET_CAN0_TXD_PC4()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC4MFP_Msk) | SYS_GPC_MFPL_PC4MFP_CAN0_TXD)  /*!< Set PC4 function to CAN0_TXD        */
#define SET_CAN0_TXD_PD7()         SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD7MFP_Msk) | SYS_GPD_MFPL_PD7MFP_CAN0_TXD)  /*!< Set PD7 function to CAN0_TXD        */
#define SET_CAN0_TXD_PE1()         SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE1MFP_Msk) | SYS_GPE_MFPL_PE1MFP_CAN0_TXD)  /*!< Set PE1 function to CAN0_TXD        */
#define SET_CAN0_TXD_PG12()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG12MFP_Msk) | SYS_GPG_MFPH_PG12MFP_CAN0_TXD)/*!< Set PG12 function to CAN0_TXD       */

/* CAN1 */
#define SET_CAN1_RXD_PA13()        SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA13MFP_Msk) | SYS_GPA_MFPH_PA13MFP_CAN1_RXD)/*!< Set PA13 function to CAN1_RXD       */
#define SET_CAN1_RXD_PD14()        SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD14MFP_Msk) | SYS_GPD_MFPH_PD14MFP_CAN1_RXD)/*!< Set PD14 function to CAN1_RXD       */
#define SET_CAN1_RXD_PE2()         SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE2MFP_Msk) | SYS_GPE_MFPL_PE2MFP_CAN1_RXD)  /*!< Set PE2 function to CAN1_RXD        */
#define SET_CAN1_RXD_PG13()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG13MFP_Msk) | SYS_GPG_MFPH_PG13MFP_CAN1_RXD)/*!< Set PG13 function to CAN1_RXD       */
#define SET_CAN1_TXD_PA14()        SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA14MFP_Msk) | SYS_GPA_MFPH_PA14MFP_CAN1_TXD)/*!< Set PA14 function to CAN1_TXD       */
#define SET_CAN1_TXD_PD15()        SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD15MFP_Msk) | SYS_GPD_MFPH_PD15MFP_CAN1_TXD)/*!< Set PD15 function to CAN1_TXD       */
#define SET_CAN1_TXD_PE3()         SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE3MFP_Msk) | SYS_GPE_MFPL_PE3MFP_CAN1_TXD)  /*!< Set PE3 function to CAN1_TXD        */
#define SET_CAN1_TXD_PG14()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG14MFP_Msk) | SYS_GPG_MFPH_PG14MFP_CAN1_TXD)/*!< Set PG14 function to CAN1_TXD       */

/* CAN2 */
#define SET_CAN2_RXD_PA15()        SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA15MFP_Msk) | SYS_GPA_MFPH_PA15MFP_CAN2_RXD)/*!< Set PA15 function to CAN2_RXD       */
#define SET_CAN2_RXD_PB1()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB1MFP_Msk) | SYS_GPB_MFPL_PB1MFP_CAN2_RXD)  /*!< Set PB1 function to CAN2_RXD        */
#define SET_CAN2_RXD_PB8()         SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB8MFP_Msk) | SYS_GPB_MFPH_PB8MFP_CAN2_RXD)  /*!< Set PB8 function to CAN2_RXD        */
#define SET_CAN2_RXD_PD12()        SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD12MFP_Msk) | SYS_GPD_MFPH_PD12MFP_CAN2_RXD)/*!< Set PD12 function to CAN2_RXD       */
#define SET_CAN2_RXD_PE4()         SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE4MFP_Msk) | SYS_GPE_MFPL_PE4MFP_CAN2_RXD)  /*!< Set PE4 function to CAN2_RXD        */
#define SET_CAN2_TXD_PB3()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB3MFP_Msk) | SYS_GPB_MFPL_PB3MFP_CAN2_TXD)  /*!< Set PB3 function to CAN2_TXD        */
#define SET_CAN2_TXD_PC0()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC0MFP_Msk) | SYS_GPC_MFPL_PC0MFP_CAN2_TXD)  /*!< Set PC0 function to CAN2_TXD        */
#define SET_CAN2_TXD_PD13()        SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD13MFP_Msk) | SYS_GPD_MFPH_PD13MFP_CAN2_TXD)/*!< Set PD13 function to CAN2_TXD       */
#define SET_CAN2_TXD_PE5()         SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE5MFP_Msk) | SYS_GPE_MFPL_PE5MFP_CAN2_TXD)  /*!< Set PE5 function to CAN2_TXD        */
#define SET_CAN2_TXD_PG10()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG10MFP_Msk) | SYS_GPG_MFPH_PG10MFP_CAN2_TXD)/*!< Set PG10 function to CAN2_TXD       */

/* CAN3 */
#define SET_CAN3_RXD_PA0()         SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA0MFP_Msk) | SYS_GPA_MFPL_PA0MFP_CAN3_RXD)  /*!< Set PA0 function to CAN3_RXD        */
#define SET_CAN3_RXD_PE6()         SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE6MFP_Msk) | SYS_GPE_MFPL_PE6MFP_CAN3_RXD)  /*!< Set PE6 function to CAN3_RXD        */
#define SET_CAN3_RXD_PE10()        SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE10MFP_Msk) | SYS_GPE_MFPH_PE10MFP_CAN3_RXD)/*!< Set PE10 function to CAN3_RXD       */
#define SET_CAN3_RXD_PH2()         SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH2MFP_Msk) | SYS_GPH_MFPL_PH2MFP_CAN3_RXD)  /*!< Set PH2 function to CAN3_RXD        */
#define SET_CAN3_TXD_PA1()         SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA1MFP_Msk) | SYS_GPA_MFPL_PA1MFP_CAN3_TXD)  /*!< Set PA1 function to CAN3_TXD        */
#define SET_CAN3_TXD_PE7()         SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE7MFP_Msk) | SYS_GPE_MFPL_PE7MFP_CAN3_TXD)  /*!< Set PE7 function to CAN3_TXD        */
#define SET_CAN3_TXD_PE12()        SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE12MFP_Msk) | SYS_GPE_MFPH_PE12MFP_CAN3_TXD)/*!< Set PE12 function to CAN3_TXD       */
#define SET_CAN3_TXD_PH3()         SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH3MFP_Msk) | SYS_GPH_MFPL_PH3MFP_CAN3_TXD)  /*!< Set PH3 function to CAN3_TXD        */

/* CANFD0 */
#define SET_CANFD0_RXD_PA2()       SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA2MFP_Msk) | SYS_GPA_MFPL_PA2MFP_CANFD0_RXD)/*!< Set PA2 function to CANFD0_RXD      */
#define SET_CANFD0_RXD_PB9()       SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB9MFP_Msk) | SYS_GPB_MFPH_PB9MFP_CANFD0_RXD)/*!< Set PB9 function to CANFD0_RXD      */
#define SET_CANFD0_RXD_PC12()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC12MFP_Msk) | SYS_GPC_MFPH_PC12MFP_CANFD0_RXD)/*!< Set PC12 function to CANFD0_RXD   */
#define SET_CANFD0_RXD_PG9()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG9MFP_Msk) | SYS_GPG_MFPH_PG9MFP_CANFD0_RXD)/*!< Set PG9 function to CANFD0_RXD      */
#define SET_CANFD0_TXD_PA3()       SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA3MFP_Msk) | SYS_GPA_MFPL_PA3MFP_CANFD0_TXD)/*!< Set PA3 function to CANFD0_TXD      */
#define SET_CANFD0_TXD_PB10()      SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB10MFP_Msk) | SYS_GPB_MFPH_PB10MFP_CANFD0_TXD)/*!< Set PB10 function to CANFD0_TXD   */
#define SET_CANFD0_TXD_PC13()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC13MFP_Msk) | SYS_GPC_MFPH_PC13MFP_CANFD0_TXD)/*!< Set PC13 function to CANFD0_TXD   */
#define SET_CANFD0_TXD_PG8()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG8MFP_Msk) | SYS_GPG_MFPH_PG8MFP_CANFD0_TXD)/*!< Set PG8 function to CANFD0_TXD      */

/* CANFD1 */
#define SET_CANFD1_RXD_PA4()       SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA4MFP_Msk) | SYS_GPA_MFPL_PA4MFP_CANFD1_RXD)/*!< Set PA4 function to CANFD1_RXD      */
#define SET_CANFD1_RXD_PB11()      SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB11MFP_Msk) | SYS_GPB_MFPH_PB11MFP_CANFD1_RXD)/*!< Set PB11 function to CANFD1_RXD   */
#define SET_CANFD1_RXD_PC14()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC14MFP_Msk) | SYS_GPC_MFPH_PC14MFP_CANFD1_RXD)/*!< Set PC14 function to CANFD1_RXD   */
#define SET_CANFD1_RXD_PG7()       SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG7MFP_Msk) | SYS_GPG_MFPL_PG7MFP_CANFD1_RXD)/*!< Set PG7 function to CANFD1_RXD      */
#define SET_CANFD1_TXD_PA5()       SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA5MFP_Msk) | SYS_GPA_MFPL_PA5MFP_CANFD1_TXD)/*!< Set PA5 function to CANFD1_TXD      */
#define SET_CANFD1_TXD_PB12()      SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB12MFP_Msk) | SYS_GPB_MFPH_PB12MFP_CANFD1_TXD)/*!< Set PB12 function to CANFD1_TXD   */
#define SET_CANFD1_TXD_PC15()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC15MFP_Msk) | SYS_GPC_MFPH_PC15MFP_CANFD1_TXD)/*!< Set PC15 function to CANFD1_TXD   */
#define SET_CANFD1_TXD_PG6()       SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG6MFP_Msk) | SYS_GPG_MFPL_PG6MFP_CANFD1_TXD)/*!< Set PG6 function to CANFD1_TXD      */

/* CANFD2 */
#define SET_CANFD2_RXD_PA11()      SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA11MFP_Msk) | SYS_GPA_MFPH_PA11MFP_CANFD2_RXD)/*!< Set PA11 function to CANFD2_RXD   */
#define SET_CANFD2_RXD_PC8()       SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC8MFP_Msk) | SYS_GPC_MFPH_PC8MFP_CANFD2_RXD)/*!< Set PC8 function to CANFD2_RXD      */
#define SET_CANFD2_RXD_PD0()       SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD0MFP_Msk) | SYS_GPD_MFPL_PD0MFP_CANFD2_RXD)/*!< Set PD0 function to CANFD2_RXD      */
#define SET_CANFD2_RXD_PD4()       SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD4MFP_Msk) | SYS_GPD_MFPL_PD4MFP_CANFD2_RXD)/*!< Set PD4 function to CANFD2_RXD      */
#define SET_CANFD2_TXD_PA12()      SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA12MFP_Msk) | SYS_GPA_MFPH_PA12MFP_CANFD2_TXD)/*!< Set PA12 function to CANFD2_TXD   */
#define SET_CANFD2_TXD_PC9()       SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC9MFP_Msk) | SYS_GPC_MFPH_PC9MFP_CANFD2_TXD)/*!< Set PC9 function to CANFD2_TXD      */
#define SET_CANFD2_TXD_PD1()       SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD1MFP_Msk) | SYS_GPD_MFPL_PD1MFP_CANFD2_TXD)/*!< Set PD1 function to CANFD2_TXD      */
#define SET_CANFD2_TXD_PD5()       SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD5MFP_Msk) | SYS_GPD_MFPL_PD5MFP_CANFD2_TXD)/*!< Set PD5 function to CANFD2_TXD      */

/* CANFD3 */
#define SET_CANFD3_RXD_PB2()       SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB2MFP_Msk) | SYS_GPB_MFPL_PB2MFP_CANFD3_RXD)/*!< Set PB2 function to CANFD3_RXD      */
#define SET_CANFD3_RXD_PC10()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC10MFP_Msk) | SYS_GPC_MFPH_PC10MFP_CANFD3_RXD)/*!< Set PC10 function to CANFD3_RXD   */
#define SET_CANFD3_RXD_PG4()       SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG4MFP_Msk) | SYS_GPG_MFPL_PG4MFP_CANFD3_RXD)/*!< Set PG4 function to CANFD3_RXD      */
#define SET_CANFD3_RXD_PG15()      SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG15MFP_Msk) | SYS_GPG_MFPH_PG15MFP_CANFD3_RXD)/*!< Set PG15 function to CANFD3_RXD   */
#define SET_CANFD3_TXD_PC7()       SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC7MFP_Msk) | SYS_GPC_MFPL_PC7MFP_CANFD3_TXD)/*!< Set PC7 function to CANFD3_TXD      */
#define SET_CANFD3_TXD_PC11()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC11MFP_Msk) | SYS_GPC_MFPH_PC11MFP_CANFD3_TXD)/*!< Set PC11 function to CANFD3_TXD   */
#define SET_CANFD3_TXD_PF10()      SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF10MFP_Msk) | SYS_GPF_MFPH_PF10MFP_CANFD3_TXD)/*!< Set PF10 function to CANFD3_TXD   */
#define SET_CANFD3_TXD_PG2()       SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG2MFP_Msk) | SYS_GPG_MFPL_PG2MFP_CANFD3_TXD)/*!< Set PG2 function to CANFD3_TXD      */

/* CLK */
#define SET_CLK_OUT_PG0()          SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG0MFP_Msk) | SYS_GPG_MFPL_PG0MFP_CLK_OUT)   /*!< Set PG0 function to CLK_OUT         */

/* EBI */
#define SET_EBI_AD0_PB13()         SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB13MFP_Msk) | SYS_GPB_MFPH_PB13MFP_EBI_AD0) /*!< Set PB13 function to EBI_AD0        */
#define SET_EBI_AD0_PC0()          SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC0MFP_Msk) | SYS_GPC_MFPL_PC0MFP_EBI_AD0)   /*!< Set PC0 function to EBI_AD0         */
#define SET_EBI_AD0_PG10()         SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG10MFP_Msk) | SYS_GPG_MFPH_PG10MFP_EBI_AD0) /*!< Set PG10 function to EBI_AD0        */
#define SET_EBI_AD1_PC1()          SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC1MFP_Msk) | SYS_GPC_MFPL_PC1MFP_EBI_AD1)   /*!< Set PC1 function to EBI_AD1         */
#define SET_EBI_AD1_PD12()         SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD12MFP_Msk) | SYS_GPD_MFPH_PD12MFP_EBI_AD1) /*!< Set PD12 function to EBI_AD1        */
#define SET_EBI_AD10_PC10()        SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC10MFP_Msk) | SYS_GPC_MFPH_PC10MFP_EBI_AD10)/*!< Set PC10 function to EBI_AD10       */
#define SET_EBI_AD10_PF5()         SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF5MFP_Msk) | SYS_GPF_MFPL_PF5MFP_EBI_AD10)  /*!< Set PF5 function to EBI_AD10        */
#define SET_EBI_AD11_PC11()        SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC11MFP_Msk) | SYS_GPC_MFPH_PC11MFP_EBI_AD11)/*!< Set PC11 function to EBI_AD11       */
#define SET_EBI_AD11_PF6()         SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF6MFP_Msk) | SYS_GPF_MFPL_PF6MFP_EBI_AD11)  /*!< Set PF6 function to EBI_AD11        */
#define SET_EBI_AD12_PC12()        SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC12MFP_Msk) | SYS_GPC_MFPH_PC12MFP_EBI_AD12)/*!< Set PC12 function to EBI_AD12       */
#define SET_EBI_AD12_PF7()         SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF7MFP_Msk) | SYS_GPF_MFPL_PF7MFP_EBI_AD12)  /*!< Set PF7 function to EBI_AD12        */
#define SET_EBI_AD13_PC13()        SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC13MFP_Msk) | SYS_GPC_MFPH_PC13MFP_EBI_AD13)/*!< Set PC13 function to EBI_AD13       */
#define SET_EBI_AD13_PF8()         SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF8MFP_Msk) | SYS_GPF_MFPH_PF8MFP_EBI_AD13)  /*!< Set PF8 function to EBI_AD13        */
#define SET_EBI_AD14_PC14()        SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC14MFP_Msk) | SYS_GPC_MFPH_PC14MFP_EBI_AD14)/*!< Set PC14 function to EBI_AD14       */
#define SET_EBI_AD14_PF9()         SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF9MFP_Msk) | SYS_GPF_MFPH_PF9MFP_EBI_AD14)  /*!< Set PF9 function to EBI_AD14        */
#define SET_EBI_AD15_PC15()        SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC15MFP_Msk) | SYS_GPC_MFPH_PC15MFP_EBI_AD15)/*!< Set PC15 function to EBI_AD15       */
#define SET_EBI_AD15_PF10()        SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF10MFP_Msk) | SYS_GPF_MFPH_PF10MFP_EBI_AD15)/*!< Set PF10 function to EBI_AD15       */

#define SET_EBI_AD2_PC2()          SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC2MFP_Msk) | SYS_GPC_MFPL_PC2MFP_EBI_AD2)   /*!< Set PC2 function to EBI_AD2         */
#define SET_EBI_AD2_PD13()         SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD13MFP_Msk) | SYS_GPD_MFPH_PD13MFP_EBI_AD2) /*!< Set PD13 function to EBI_AD2        */
#define SET_EBI_AD3_PC3()          SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC3MFP_Msk) | SYS_GPC_MFPL_PC3MFP_EBI_AD3)   /*!< Set PC3 function to EBI_AD3         */
#define SET_EBI_AD3_PD14()         SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD14MFP_Msk) | SYS_GPD_MFPH_PD14MFP_EBI_AD3) /*!< Set PD14 function to EBI_AD3        */
#define SET_EBI_AD4_PC4()          SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC4MFP_Msk) | SYS_GPC_MFPL_PC4MFP_EBI_AD4)   /*!< Set PC4 function to EBI_AD4         */
#define SET_EBI_AD4_PD15()         SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD15MFP_Msk) | SYS_GPD_MFPH_PD15MFP_EBI_AD4) /*!< Set PD15 function to EBI_AD4        */
#define SET_EBI_AD5_PC5()          SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC5MFP_Msk) | SYS_GPC_MFPL_PC5MFP_EBI_AD5)   /*!< Set PC5 function to EBI_AD5         */
#define SET_EBI_AD5_PF0()          SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF0MFP_Msk) | SYS_GPF_MFPL_PF0MFP_EBI_AD5)   /*!< Set PF0 function to EBI_AD5         */
#define SET_EBI_AD6_PC6()          SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC6MFP_Msk) | SYS_GPC_MFPL_PC6MFP_EBI_AD6)   /*!< Set PC6 function to EBI_AD6         */
#define SET_EBI_AD6_PF1()          SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF1MFP_Msk) | SYS_GPF_MFPL_PF1MFP_EBI_AD6)   /*!< Set PF1 function to EBI_AD6         */
#define SET_EBI_AD7_PC7()          SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC7MFP_Msk) | SYS_GPC_MFPL_PC7MFP_EBI_AD7)   /*!< Set PC7 function to EBI_AD7         */
#define SET_EBI_AD7_PF2()          SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF2MFP_Msk) | SYS_GPF_MFPL_PF2MFP_EBI_AD7)   /*!< Set PF2 function to EBI_AD7         */
#define SET_EBI_AD8_PC8()          SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC8MFP_Msk) | SYS_GPC_MFPH_PC8MFP_EBI_AD8)   /*!< Set PC8 function to EBI_AD8         */
#define SET_EBI_AD8_PF3()          SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF3MFP_Msk) | SYS_GPF_MFPL_PF3MFP_EBI_AD8)   /*!< Set PF3 function to EBI_AD8         */
#define SET_EBI_AD9_PC9()          SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC9MFP_Msk) | SYS_GPC_MFPH_PC9MFP_EBI_AD9)   /*!< Set PC9 function to EBI_AD9         */
#define SET_EBI_AD9_PF4()          SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF4MFP_Msk) | SYS_GPF_MFPL_PF4MFP_EBI_AD9)   /*!< Set PF4 function to EBI_AD9         */
#define SET_EBI_ADR0_PG0()         SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG0MFP_Msk) | SYS_GPG_MFPL_PG0MFP_EBI_ADR0)  /*!< Set PG0 function to EBI_ADR0        */
#define SET_EBI_ADR1_PG1()         SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG1MFP_Msk) | SYS_GPG_MFPL_PG1MFP_EBI_ADR1)  /*!< Set PG1 function to EBI_ADR1        */
#define SET_EBI_ADR10_PA10()       SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA10MFP_Msk) | SYS_GPA_MFPH_PA10MFP_EBI_ADR10)/*!< Set PA10 function to EBI_ADR10     */
#define SET_EBI_ADR11_PB8()        SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB8MFP_Msk) | SYS_GPB_MFPH_PB8MFP_EBI_ADR11) /*!< Set PB8 function to EBI_ADR11       */
#define SET_EBI_ADR12_PB0()        SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB0MFP_Msk) | SYS_GPB_MFPL_PB0MFP_EBI_ADR12) /*!< Set PB0 function to EBI_ADR12       */
#define SET_EBI_ADR12_PG5()        SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG5MFP_Msk) | SYS_GPG_MFPL_PG5MFP_EBI_ADR12) /*!< Set PG5 function to EBI_ADR12       */
#define SET_EBI_ADR13_PA13()       SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA13MFP_Msk) | SYS_GPA_MFPH_PA13MFP_EBI_ADR13)/*!< Set PA13 function to EBI_ADR13     */
#define SET_EBI_ADR13_PB6()        SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB6MFP_Msk) | SYS_GPB_MFPL_PB6MFP_EBI_ADR13) /*!< Set PB6 function to EBI_ADR13       */
#define SET_EBI_ADR14_PA14()       SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA14MFP_Msk) | SYS_GPA_MFPH_PA14MFP_EBI_ADR14)/*!< Set PA14 function to EBI_ADR14     */
#define SET_EBI_ADR14_PB4()        SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB4MFP_Msk) | SYS_GPB_MFPL_PB4MFP_EBI_ADR14) /*!< Set PB4 function to EBI_ADR14       */
#define SET_EBI_ADR15_PB7()        SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB7MFP_Msk) | SYS_GPB_MFPL_PB7MFP_EBI_ADR15) /*!< Set PB7 function to EBI_ADR15       */
#define SET_EBI_ADR16_PB5()        SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB5MFP_Msk) | SYS_GPB_MFPL_PB5MFP_EBI_ADR16) /*!< Set PB5 function to EBI_ADR16       */
#define SET_EBI_ADR17_PB1()        SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB1MFP_Msk) | SYS_GPB_MFPL_PB1MFP_EBI_ADR17) /*!< Set PB1 function to EBI_ADR17       */
#define SET_EBI_ADR18_PB3()        SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB3MFP_Msk) | SYS_GPB_MFPL_PB3MFP_EBI_ADR18) /*!< Set PB3 function to EBI_ADR18       */
#define SET_EBI_ADR18_PG4()        SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG4MFP_Msk) | SYS_GPG_MFPL_PG4MFP_EBI_ADR18) /*!< Set PG4 function to EBI_ADR18       */
#define SET_EBI_ADR19_PA15()       SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA15MFP_Msk) | SYS_GPA_MFPH_PA15MFP_EBI_ADR19)/*!< Set PA15 function to EBI_ADR19     */
#define SET_EBI_ADR2_PB2()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB2MFP_Msk) | SYS_GPB_MFPL_PB2MFP_EBI_ADR2)  /*!< Set PB2 function to EBI_ADR2        */
#define SET_EBI_ADR2_PG2()         SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG2MFP_Msk) | SYS_GPG_MFPL_PG2MFP_EBI_ADR2)  /*!< Set PG2 function to EBI_ADR2        */
#define SET_EBI_ADR3_PG3()         SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG3MFP_Msk) | SYS_GPG_MFPL_PG3MFP_EBI_ADR3)  /*!< Set PG3 function to EBI_ADR3        */
#define SET_EBI_ADR4_PG6()         SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG6MFP_Msk) | SYS_GPG_MFPL_PG6MFP_EBI_ADR4)  /*!< Set PG6 function to EBI_ADR4        */
#define SET_EBI_ADR5_PG7()         SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG7MFP_Msk) | SYS_GPG_MFPL_PG7MFP_EBI_ADR5)  /*!< Set PG7 function to EBI_ADR5        */
#define SET_EBI_ADR6_PG8()         SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG8MFP_Msk) | SYS_GPG_MFPH_PG8MFP_EBI_ADR6)  /*!< Set PG8 function to EBI_ADR6        */
#define SET_EBI_ADR7_PG9()         SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG9MFP_Msk) | SYS_GPG_MFPH_PG9MFP_EBI_ADR7)  /*!< Set PG9 function to EBI_ADR7        */
#define SET_EBI_ADR8_PA12()        SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA12MFP_Msk) | SYS_GPA_MFPH_PA12MFP_EBI_ADR8)/*!< Set PA12 function to EBI_ADR8       */
#define SET_EBI_ADR9_PA11()        SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA11MFP_Msk) | SYS_GPA_MFPH_PA11MFP_EBI_ADR9)/*!< Set PA11 function to EBI_ADR9       */
#define SET_EBI_MCLK_PA1()         SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA1MFP_Msk) | SYS_GPA_MFPL_PA1MFP_EBI_MCLK)  /*!< Set PA1 function to EBI_MCLK        */
#define SET_EBI_nCS0_PA9()         SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA9MFP_Msk) | SYS_GPA_MFPH_PA9MFP_EBI_nCS0)  /*!< Set PA9 function to EBI_nCS0        */
#define SET_EBI_nCS1_PA6()         SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA6MFP_Msk) | SYS_GPA_MFPL_PA6MFP_EBI_nCS1)  /*!< Set PA6 function to EBI_nCS1        */
#define SET_EBI_nCS2_PA1()         SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA1MFP_Msk) | SYS_GPA_MFPL_PA1MFP_EBI_nCS2)  /*!< Set PA1 function to EBI_nCS2        */
#define SET_EBI_nRD_PA8()          SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA8MFP_Msk) | SYS_GPA_MFPH_PA8MFP_EBI_nRD)   /*!< Set PA8 function to EBI_nRD         */
#define SET_EBI_nWAIT_PA0()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA0MFP_Msk) | SYS_GPA_MFPL_PA0MFP_EBI_nWAIT) /*!< Set PA0 function to EBI_nWAIT       */
#define SET_EBI_nWR_PA7()          SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA7MFP_Msk) | SYS_GPA_MFPL_PA7MFP_EBI_nWR)   /*!< Set PA7 function to EBI_nWR         */

/* EMAC0 */
#define SET_EMAC0_RMII_CRSDV_PE1() SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE1MFP_Msk) | SYS_GPE_MFPL_PE1MFP_EMAC0_RMII_CRSDV)/*!< Set PE1 function to EMAC0_RMII_CRSDV  */
#define SET_EMAC0_RMII_MDC_PE9()   SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE9MFP_Msk) | SYS_GPE_MFPH_PE9MFP_EMAC0_RMII_MDC)  /*!< Set PE9 function to EMAC0_RMII_MDC    */
#define SET_EMAC0_RMII_MDIO_PE8()  SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE8MFP_Msk) | SYS_GPE_MFPH_PE8MFP_EMAC0_RMII_MDIO) /*!< Set PE8 function to EMAC0_RMII_MDIO   */
#define SET_EMAC0_RMII_PPS_PF10()  SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF10MFP_Msk) | SYS_GPF_MFPH_PF10MFP_EMAC0_RMII_PPS)/*!< Set PF10 function to EMAC0_RMII_PPS   */
#define SET_EMAC0_RMII_REFCLK_PE4() SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE4MFP_Msk) | SYS_GPE_MFPL_PE4MFP_EMAC0_RMII_REFCLK)/*!< Set PE4 function to EMAC0_RMII_REFCLK */
#define SET_EMAC0_RMII_RXD0_PE3()  SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE3MFP_Msk) | SYS_GPE_MFPL_PE3MFP_EMAC0_RMII_RXD0)  /*!< Set PE3 function to EMAC0_RMII_RXD0   */
#define SET_EMAC0_RMII_RXD1_PE2()  SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE2MFP_Msk) | SYS_GPE_MFPL_PE2MFP_EMAC0_RMII_RXD1)  /*!< Set PE2 function to EMAC0_RMII_RXD1   */
#define SET_EMAC0_RMII_RXERR_PE0() SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE0MFP_Msk) | SYS_GPE_MFPL_PE0MFP_EMAC0_RMII_RXERR) /*!< Set PE0 function to EMAC0_RMII_RXERR  */
#define SET_EMAC0_RMII_TXD0_PE7()  SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE7MFP_Msk) | SYS_GPE_MFPL_PE7MFP_EMAC0_RMII_TXD0)  /*!< Set PE7 function to EMAC0_RMII_TXD0   */
#define SET_EMAC0_RMII_TXD1_PE6()  SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE6MFP_Msk) | SYS_GPE_MFPL_PE6MFP_EMAC0_RMII_TXD1)  /*!< Set PE6 function to EMAC0_RMII_TXD1   */
#define SET_EMAC0_RMII_TXEN_PE5()  SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE5MFP_Msk) | SYS_GPE_MFPL_PE5MFP_EMAC0_RMII_TXEN)  /*!< Set PE5 function to EMAC0_RMII_TXEN   */

/* EMAC1 */
#define SET_EMAC1_RMII_CRSDV_PF1() SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF1MFP_Msk) | SYS_GPF_MFPL_PF1MFP_EMAC1_RMII_CRSDV)/*!< Set PF1 function to EMAC1_RMII_CRSDV  */
#define SET_EMAC1_RMII_MDC_PF9()   SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF9MFP_Msk) | SYS_GPF_MFPH_PF9MFP_EMAC1_RMII_MDC)  /*!< Set PF9 function to EMAC1_RMII_MDC    */
#define SET_EMAC1_RMII_MDIO_PF8()  SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF8MFP_Msk) | SYS_GPF_MFPH_PF8MFP_EMAC1_RMII_MDIO) /*!< Set PF8 function to EMAC1_RMII_MDIO   */
#define SET_EMAC1_RMII_PPS_PB13()  SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB13MFP_Msk) | SYS_GPB_MFPH_PB13MFP_EMAC1_RMII_PPS)/*!< Set PB13 function to EMAC1_RMII_PPS   */
#define SET_EMAC1_RMII_REFCLK_PF4() SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF4MFP_Msk) | SYS_GPF_MFPL_PF4MFP_EMAC1_RMII_REFCLK)/*!< Set PF4 function to EMAC1_RMII_REFCLK */
#define SET_EMAC1_RMII_RXD0_PF3()  SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF3MFP_Msk) | SYS_GPF_MFPL_PF3MFP_EMAC1_RMII_RXD0)  /*!< Set PF3 function to EMAC1_RMII_RXD0   */
#define SET_EMAC1_RMII_RXD1_PF2()  SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF2MFP_Msk) | SYS_GPF_MFPL_PF2MFP_EMAC1_RMII_RXD1)  /*!< Set PF2 function to EMAC1_RMII_RXD1   */
#define SET_EMAC1_RMII_RXERR_PF0() SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF0MFP_Msk) | SYS_GPF_MFPL_PF0MFP_EMAC1_RMII_RXERR) /*!< Set PF0 function to EMAC1_RMII_RXERR  */
#define SET_EMAC1_RMII_TXD0_PF7()  SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF7MFP_Msk) | SYS_GPF_MFPL_PF7MFP_EMAC1_RMII_TXD0)  /*!< Set PF7 function to EMAC1_RMII_TXD0   */
#define SET_EMAC1_RMII_TXD1_PF6()  SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF6MFP_Msk) | SYS_GPF_MFPL_PF6MFP_EMAC1_RMII_TXD1)  /*!< Set PF6 function to EMAC1_RMII_TXD1   */
#define SET_EMAC1_RMII_TXEN_PF5()  SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF5MFP_Msk) | SYS_GPF_MFPL_PF5MFP_EMAC1_RMII_TXEN)  /*!< Set PF5 function to EMAC1_RMII_TXEN   */

/* I2C0 */
#define SET_I2C0_SCL_PA1()         SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA1MFP_Msk) | SYS_GPA_MFPL_PA1MFP_I2C0_SCL)  /*!< Set PA1 function to I2C0_SCL        */
#define SET_I2C0_SCL_PE12()        SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE12MFP_Msk) | SYS_GPE_MFPH_PE12MFP_I2C0_SCL)/*!< Set PE12 function to I2C0_SCL       */
#define SET_I2C0_SCL_PG10()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG10MFP_Msk) | SYS_GPG_MFPH_PG10MFP_I2C0_SCL)/*!< Set PG10 function to I2C0_SCL       */
#define SET_I2C0_SDA_PA0()         SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA0MFP_Msk) | SYS_GPA_MFPL_PA0MFP_I2C0_SDA)  /*!< Set PA0 function to I2C0_SDA        */
#define SET_I2C0_SDA_PA15()        SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA15MFP_Msk) | SYS_GPA_MFPH_PA15MFP_I2C0_SDA)/*!< Set PA15 function to I2C0_SDA       */
#define SET_I2C0_SDA_PE10()        SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE10MFP_Msk) | SYS_GPE_MFPH_PE10MFP_I2C0_SDA)/*!< Set PE10 function to I2C0_SDA       */
#define SET_I2C0_SMBAL_PA2()       SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA2MFP_Msk) | SYS_GPA_MFPL_PA2MFP_I2C0_SMBAL)/*!< Set PA2 function to I2C0_SMBAL      */
#define SET_I2C0_SMBAL_PC9()       SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC9MFP_Msk) | SYS_GPC_MFPH_PC9MFP_I2C0_SMBAL)/*!< Set PC9 function to I2C0_SMBAL      */
#define SET_I2C0_SMBAL_PD8()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD8MFP_Msk) | SYS_GPD_MFPH_PD8MFP_I2C0_SMBAL)/*!< Set PD8 function to I2C0_SMBAL      */
#define SET_I2C0_SMBAL_PE8()       SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE8MFP_Msk) | SYS_GPE_MFPH_PE8MFP_I2C0_SMBAL)/*!< Set PE8 function to I2C0_SMBAL      */
#define SET_I2C0_SMBSUS_PA3()      SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA3MFP_Msk) | SYS_GPA_MFPL_PA3MFP_I2C0_SMBSUS)/*!< Set PA3 function to I2C0_SMBSUS    */
#define SET_I2C0_SMBSUS_PC10()     SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC10MFP_Msk) | SYS_GPC_MFPH_PC10MFP_I2C0_SMBSUS)/*!< Set PC10 function to I2C0_SMBSUS  */
#define SET_I2C0_SMBSUS_PD9()      SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD9MFP_Msk) | SYS_GPD_MFPH_PD9MFP_I2C0_SMBSUS)/*!< Set PD9 function to I2C0_SMBSUS    */
#define SET_I2C0_SMBSUS_PE9()      SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE9MFP_Msk) | SYS_GPE_MFPH_PE9MFP_I2C0_SMBSUS)/*!< Set PE9 function to I2C0_SMBSUS    */

/* I2C1 */
#define SET_I2C1_SCL_PA14()        SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA14MFP_Msk) | SYS_GPA_MFPH_PA14MFP_I2C1_SCL)/*!< Set PA14 function to I2C1_SCL       */
#define SET_I2C1_SCL_PB4()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB4MFP_Msk) | SYS_GPB_MFPL_PB4MFP_I2C1_SCL)  /*!< Set PB4 function to I2C1_SCL        */
#define SET_I2C1_SCL_PC3()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC3MFP_Msk) | SYS_GPC_MFPL_PC3MFP_I2C1_SCL)  /*!< Set PC3 function to I2C1_SCL        */
#define SET_I2C1_SDA_PA13()        SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA13MFP_Msk) | SYS_GPA_MFPH_PA13MFP_I2C1_SDA)/*!< Set PA13 function to I2C1_SDA       */
#define SET_I2C1_SDA_PB6()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB6MFP_Msk) | SYS_GPB_MFPL_PB6MFP_I2C1_SDA)  /*!< Set PB6 function to I2C1_SDA        */
#define SET_I2C1_SDA_PC4()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC4MFP_Msk) | SYS_GPC_MFPL_PC4MFP_I2C1_SDA)  /*!< Set PC4 function to I2C1_SDA        */
#define SET_I2C1_SMBAL_PA4()       SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA4MFP_Msk) | SYS_GPA_MFPL_PA4MFP_I2C1_SMBAL)/*!< Set PA4 function to I2C1_SMBAL      */
#define SET_I2C1_SMBAL_PC11()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC11MFP_Msk) | SYS_GPC_MFPH_PC11MFP_I2C1_SMBAL)/*!< Set PC11 function to I2C1_SMBAL   */
#define SET_I2C1_SMBAL_PD10()      SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD10MFP_Msk) | SYS_GPD_MFPH_PD10MFP_I2C1_SMBAL)/*!< Set PD10 function to I2C1_SMBAL   */
#define SET_I2C1_SMBAL_PE2()       SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE2MFP_Msk) | SYS_GPE_MFPL_PE2MFP_I2C1_SMBAL)/*!< Set PE2 function to I2C1_SMBAL      */
#define SET_I2C1_SMBSUS_PA5()      SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA5MFP_Msk) | SYS_GPA_MFPL_PA5MFP_I2C1_SMBSUS)/*!< Set PA5 function to I2C1_SMBSUS    */
#define SET_I2C1_SMBSUS_PC15()     SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC15MFP_Msk) | SYS_GPC_MFPH_PC15MFP_I2C1_SMBSUS)/*!< Set PC15 function to I2C1_SMBSUS  */
#define SET_I2C1_SMBSUS_PD11()     SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD11MFP_Msk) | SYS_GPD_MFPH_PD11MFP_I2C1_SMBSUS)/*!< Set PD11 function to I2C1_SMBSUS  */
#define SET_I2C1_SMBSUS_PE3()      SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE3MFP_Msk) | SYS_GPE_MFPL_PE3MFP_I2C1_SMBSUS)/*!< Set PE3 function to I2C1_SMBSUS    */

/* I2C2 */
#define SET_I2C2_SCL_PB0()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB0MFP_Msk) | SYS_GPB_MFPL_PB0MFP_I2C2_SCL)  /*!< Set PB0 function to I2C2_SCL        */
#define SET_I2C2_SCL_PB5()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB5MFP_Msk) | SYS_GPB_MFPL_PB5MFP_I2C2_SCL)  /*!< Set PB5 function to I2C2_SCL        */
#define SET_I2C2_SCL_PB8()         SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB8MFP_Msk) | SYS_GPB_MFPH_PB8MFP_I2C2_SCL)  /*!< Set PB8 function to I2C2_SCL        */
#define SET_I2C2_SCL_PH8()         SYS->GPH_MFPH = ((SYS->GPH_MFPH & ~SYS_GPH_MFPH_PH8MFP_Msk) | SYS_GPH_MFPH_PH8MFP_I2C2_SCL)  /*!< Set PH8 function to I2C2_SCL        */
#define SET_I2C2_SDA_PB7()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB7MFP_Msk) | SYS_GPB_MFPL_PB7MFP_I2C2_SDA)  /*!< Set PB7 function to I2C2_SDA        */
#define SET_I2C2_SDA_PC0()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC0MFP_Msk) | SYS_GPC_MFPL_PC0MFP_I2C2_SDA)  /*!< Set PC0 function to I2C2_SDA        */
#define SET_I2C2_SDA_PH7()         SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH7MFP_Msk) | SYS_GPH_MFPL_PH7MFP_I2C2_SDA)  /*!< Set PH7 function to I2C2_SDA        */
#define SET_I2C2_SMBAL_PD0()       SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD0MFP_Msk) | SYS_GPD_MFPL_PD0MFP_I2C2_SMBAL)/*!< Set PD0 function to I2C2_SMBAL      */
#define SET_I2C2_SMBAL_PE0()       SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE0MFP_Msk) | SYS_GPE_MFPL_PE0MFP_I2C2_SMBAL)/*!< Set PE0 function to I2C2_SMBAL      */
#define SET_I2C2_SMBAL_PE6()       SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE6MFP_Msk) | SYS_GPE_MFPL_PE6MFP_I2C2_SMBAL)/*!< Set PE6 function to I2C2_SMBAL      */
#define SET_I2C2_SMBAL_PG11()      SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG11MFP_Msk) | SYS_GPG_MFPH_PG11MFP_I2C2_SMBAL)/*!< Set PG11 function to I2C2_SMBAL   */
#define SET_I2C2_SMBSUS_PD1()      SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD1MFP_Msk) | SYS_GPD_MFPL_PD1MFP_I2C2_SMBSUS)/*!< Set PD1 function to I2C2_SMBSUS    */
#define SET_I2C2_SMBSUS_PE1()      SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE1MFP_Msk) | SYS_GPE_MFPL_PE1MFP_I2C2_SMBSUS)/*!< Set PE1 function to I2C2_SMBSUS    */
#define SET_I2C2_SMBSUS_PE7()      SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE7MFP_Msk) | SYS_GPE_MFPL_PE7MFP_I2C2_SMBSUS)/*!< Set PE7 function to I2C2_SMBSUS    */
#define SET_I2C2_SMBSUS_PG12()     SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG12MFP_Msk) | SYS_GPG_MFPH_PG12MFP_I2C2_SMBSUS)/*!< Set PG12 function to I2C2_SMBSUS  */

/* I2C3 */
#define SET_I2C3_SCL_PB3()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB3MFP_Msk) | SYS_GPB_MFPL_PB3MFP_I2C3_SCL)  /*!< Set PB3 function to I2C3_SCL        */
#define SET_I2C3_SCL_PD14()        SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD14MFP_Msk) | SYS_GPD_MFPH_PD14MFP_I2C3_SCL)/*!< Set PD14 function to I2C3_SCL       */
#define SET_I2C3_SCL_PH4()         SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH4MFP_Msk) | SYS_GPH_MFPL_PH4MFP_I2C3_SCL)  /*!< Set PH4 function to I2C3_SCL        */
#define SET_I2C3_SDA_PB1()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB1MFP_Msk) | SYS_GPB_MFPL_PB1MFP_I2C3_SDA)  /*!< Set PB1 function to I2C3_SDA        */
#define SET_I2C3_SDA_PD15()        SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD15MFP_Msk) | SYS_GPD_MFPH_PD15MFP_I2C3_SDA)/*!< Set PD15 function to I2C3_SDA       */
#define SET_I2C3_SDA_PH3()         SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH3MFP_Msk) | SYS_GPH_MFPL_PH3MFP_I2C3_SDA)  /*!< Set PH3 function to I2C3_SDA        */
#define SET_I2C3_SMBAL_PB11()      SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB11MFP_Msk) | SYS_GPB_MFPH_PB11MFP_I2C3_SMBAL)/*!< Set PB11 function to I2C3_SMBAL   */
#define SET_I2C3_SMBAL_PD12()      SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD12MFP_Msk) | SYS_GPD_MFPH_PD12MFP_I2C3_SMBAL)/*!< Set PD12 function to I2C3_SMBAL   */
#define SET_I2C3_SMBAL_PE4()       SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE4MFP_Msk) | SYS_GPE_MFPL_PE4MFP_I2C3_SMBAL)/*!< Set PE4 function to I2C3_SMBAL      */
#define SET_I2C3_SMBAL_PG13()      SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG13MFP_Msk) | SYS_GPG_MFPH_PG13MFP_I2C3_SMBAL)/*!< Set PG13 function to I2C3_SMBAL   */
#define SET_I2C3_SMBSUS_PB12()     SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB12MFP_Msk) | SYS_GPB_MFPH_PB12MFP_I2C3_SMBSUS)/*!< Set PB12 function to I2C3_SMBSUS  */
#define SET_I2C3_SMBSUS_PD13()     SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD13MFP_Msk) | SYS_GPD_MFPH_PD13MFP_I2C3_SMBSUS)/*!< Set PD13 function to I2C3_SMBSUS  */
#define SET_I2C3_SMBSUS_PE5()      SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE5MFP_Msk) | SYS_GPE_MFPL_PE5MFP_I2C3_SMBSUS)/*!< Set PE5 function to I2C3_SMBSUS    */
#define SET_I2C3_SMBSUS_PG14()     SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG14MFP_Msk) | SYS_GPG_MFPH_PG14MFP_I2C3_SMBSUS)/*!< Set PG14 function to I2C3_SMBSUS  */

/* I2S */
#define SET_I2S_BCLK_PA3()         SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA3MFP_Msk) | SYS_GPA_MFPL_PA3MFP_I2S_BCLK)  /*!< Set PA3 function to I2S_BCLK        */
#define SET_I2S_BCLK_PB4()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB4MFP_Msk) | SYS_GPB_MFPL_PB4MFP_I2S_BCLK)  /*!< Set PB4 function to I2S_BCLK        */
#define SET_I2S_BCLK_PG10()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG10MFP_Msk) | SYS_GPG_MFPH_PG10MFP_I2S_BCLK)/*!< Set PG10 function to I2S_BCLK       */
#define SET_I2S_DI_PA4()           SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA4MFP_Msk) | SYS_GPA_MFPL_PA4MFP_I2S_DI)    /*!< Set PA4 function to I2S_DI          */
#define SET_I2S_DI_PB7()           SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB7MFP_Msk) | SYS_GPB_MFPL_PB7MFP_I2S_DI)    /*!< Set PB7 function to I2S_DI          */
#define SET_I2S_DO_PA5()           SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA5MFP_Msk) | SYS_GPA_MFPL_PA5MFP_I2S_DO)    /*!< Set PA5 function to I2S_DO          */
#define SET_I2S_DO_PB5()           SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB5MFP_Msk) | SYS_GPB_MFPL_PB5MFP_I2S_DO)    /*!< Set PB5 function to I2S_DO          */
#define SET_I2S_LRCK_PA2()         SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA2MFP_Msk) | SYS_GPA_MFPL_PA2MFP_I2S_LRCK)  /*!< Set PA2 function to I2S_LRCK        */
#define SET_I2S_LRCK_PA15()        SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA15MFP_Msk) | SYS_GPA_MFPH_PA15MFP_I2S_LRCK)/*!< Set PA15 function to I2S_LRCK       */
#define SET_I2S_LRCK_PB6()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB6MFP_Msk) | SYS_GPB_MFPL_PB6MFP_I2S_LRCK)  /*!< Set PB6 function to I2S_LRCK        */
#define SET_I2S_MCLK_PA6()         SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA6MFP_Msk) | SYS_GPA_MFPL_PA6MFP_I2S_MCLK)  /*!< Set PA6 function to I2S_MCLK        */
#define SET_I2S_MCLK_PB1()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB1MFP_Msk) | SYS_GPB_MFPL_PB1MFP_I2S_MCLK)  /*!< Set PB1 function to I2S_MCLK        */

/* ICE */
#define SET_ICE_CLK_PF8()          SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF8MFP_Msk) | SYS_GPF_MFPH_PF8MFP_ICE_CLK)   /*!< Set PF8 function to ICE_CLK         */
#define SET_ICE_DAT_PF9()          SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF9MFP_Msk) | SYS_GPF_MFPH_PF9MFP_ICE_DAT)   /*!< Set PF9 function to ICE_DAT         */

/* INT0 */
#define SET_INT0_PA0()             SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA0MFP_Msk) | SYS_GPA_MFPL_PA0MFP_INT0)      /*!< Set PA0 function to INT0            */
#define SET_INT0_PA13()            SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA13MFP_Msk) | SYS_GPA_MFPH_PA13MFP_INT0)    /*!< Set PA13 function to INT0           */
#define SET_INT0_PH0()             SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH0MFP_Msk) | SYS_GPH_MFPL_PH0MFP_INT0)      /*!< Set PH0 function to INT0            */
#define SET_INT0_PH8()             SYS->GPH_MFPH = ((SYS->GPH_MFPH & ~SYS_GPH_MFPH_PH8MFP_Msk) | SYS_GPH_MFPH_PH8MFP_INT0)      /*!< Set PH8 function to INT0            */

/* INT1 */
#define SET_INT1_PA1()             SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA1MFP_Msk) | SYS_GPA_MFPL_PA1MFP_INT1)      /*!< Set PA1 function to INT1            */
#define SET_INT1_PA14()            SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA14MFP_Msk) | SYS_GPA_MFPH_PA14MFP_INT1)    /*!< Set PA14 function to INT1           */
#define SET_INT1_PH5()             SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH5MFP_Msk) | SYS_GPH_MFPL_PH5MFP_INT1)      /*!< Set PH5 function to INT1            */
#define SET_INT1_PH7()             SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH7MFP_Msk) | SYS_GPH_MFPL_PH7MFP_INT1)      /*!< Set PH7 function to INT1            */

/* INT2 */
#define SET_INT2_PB3()             SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB3MFP_Msk) | SYS_GPB_MFPL_PB3MFP_INT2)      /*!< Set PB3 function to INT2            */
#define SET_INT2_PB13()            SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB13MFP_Msk) | SYS_GPB_MFPH_PB13MFP_INT2)    /*!< Set PB13 function to INT2           */
#define SET_INT2_PD0()             SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD0MFP_Msk) | SYS_GPD_MFPL_PD0MFP_INT2)      /*!< Set PD0 function to INT2            */
#define SET_INT2_PE10()            SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE10MFP_Msk) | SYS_GPE_MFPH_PE10MFP_INT2)    /*!< Set PE10 function to INT2           */

/* INT3 */
#define SET_INT3_PD1()             SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD1MFP_Msk) | SYS_GPD_MFPL_PD1MFP_INT3)      /*!< Set PD1 function to INT3            */
#define SET_INT3_PE12()            SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE12MFP_Msk) | SYS_GPE_MFPH_PE12MFP_INT3)    /*!< Set PE12 function to INT3           */
#define SET_INT3_PG15()            SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG15MFP_Msk) | SYS_GPG_MFPH_PG15MFP_INT3)    /*!< Set PG15 function to INT3           */

/* JTAG0 */
#define SET_JTAG0_TCK_PG12()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG12MFP_Msk) | SYS_GPG_MFPH_PG12MFP_JTAG0_TCK)/*!< Set PG12 function to JTAG0_TCK     */
#define SET_JTAG0_TDI_PG14()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG14MFP_Msk) | SYS_GPG_MFPH_PG14MFP_JTAG0_TDI)/*!< Set PG14 function to JTAG0_TDI     */
#define SET_JTAG0_TDO_PG11()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG11MFP_Msk) | SYS_GPG_MFPH_PG11MFP_JTAG0_TDO)/*!< Set PG11 function to JTAG0_TDO     */
#define SET_JTAG0_TMS_PG13()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG13MFP_Msk) | SYS_GPG_MFPH_PG13MFP_JTAG0_TMS)/*!< Set PG13 function to JTAG0_TMS     */
#define SET_JTAG0_nTRST_PG15()     SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG15MFP_Msk) | SYS_GPG_MFPH_PG15MFP_JTAG0_nTRST)/*!< Set PG15 function to JTAG0_nTRST  */

/* JTAG1 */
#define SET_JTAG1_TCK_PA3()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA3MFP_Msk) | SYS_GPA_MFPL_PA3MFP_JTAG1_TCK) /*!< Set PA3 function to JTAG1_TCK       */
#define SET_JTAG1_TDI_PA5()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA5MFP_Msk) | SYS_GPA_MFPL_PA5MFP_JTAG1_TDI) /*!< Set PA5 function to JTAG1_TDI       */
#define SET_JTAG1_TDO_PA2()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA2MFP_Msk) | SYS_GPA_MFPL_PA2MFP_JTAG1_TDO) /*!< Set PA2 function to JTAG1_TDO       */
#define SET_JTAG1_TMS_PA4()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA4MFP_Msk) | SYS_GPA_MFPL_PA4MFP_JTAG1_TMS) /*!< Set PA4 function to JTAG1_TMS       */
#define SET_JTAG1_nTRST_PA6()      SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA6MFP_Msk) | SYS_GPA_MFPL_PA6MFP_JTAG1_nTRST)/*!< Set PA6 function to JTAG1_nTRST    */

/* NAND */
#define SET_NAND_ALE_PC3()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC3MFP_Msk) | SYS_GPC_MFPL_PC3MFP_NAND_ALE)  /*!< Set PC3 function to NAND_ALE        */
#define SET_NAND_CLE_PC4()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC4MFP_Msk) | SYS_GPC_MFPL_PC4MFP_NAND_CLE)  /*!< Set PC4 function to NAND_CLE        */
#define SET_NAND_DATA0_PC8()       SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC8MFP_Msk) | SYS_GPC_MFPH_PC8MFP_NAND_DATA0)/*!< Set PC8 function to NAND_DATA0      */
#define SET_NAND_DATA1_PC9()       SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC9MFP_Msk) | SYS_GPC_MFPH_PC9MFP_NAND_DATA1)/*!< Set PC9 function to NAND_DATA1      */
#define SET_NAND_DATA2_PC10()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC10MFP_Msk) | SYS_GPC_MFPH_PC10MFP_NAND_DATA2)/*!< Set PC10 function to NAND_DATA2   */
#define SET_NAND_DATA3_PC11()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC11MFP_Msk) | SYS_GPC_MFPH_PC11MFP_NAND_DATA3)/*!< Set PC11 function to NAND_DATA3   */
#define SET_NAND_DATA4_PC12()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC12MFP_Msk) | SYS_GPC_MFPH_PC12MFP_NAND_DATA4)/*!< Set PC12 function to NAND_DATA4   */
#define SET_NAND_DATA5_PC13()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC13MFP_Msk) | SYS_GPC_MFPH_PC13MFP_NAND_DATA5)/*!< Set PC13 function to NAND_DATA5   */
#define SET_NAND_DATA6_PC14()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC14MFP_Msk) | SYS_GPC_MFPH_PC14MFP_NAND_DATA6)/*!< Set PC14 function to NAND_DATA6   */
#define SET_NAND_DATA7_PC15()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC15MFP_Msk) | SYS_GPC_MFPH_PC15MFP_NAND_DATA7)/*!< Set PC15 function to NAND_DATA7   */
#define SET_NAND_RDY_PC7()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC7MFP_Msk) | SYS_GPC_MFPL_PC7MFP_NAND_RDY)  /*!< Set PC7 function to NAND_RDY        */
#define SET_NAND_nCS_PC1()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC1MFP_Msk) | SYS_GPC_MFPL_PC1MFP_NAND_nCS)  /*!< Set PC1 function to NAND_nCS        */
#define SET_NAND_nRE_PC6()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC6MFP_Msk) | SYS_GPC_MFPL_PC6MFP_NAND_nRE)  /*!< Set PC6 function to NAND_nRE        */
#define SET_NAND_nWE_PC5()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC5MFP_Msk) | SYS_GPC_MFPL_PC5MFP_NAND_nWE)  /*!< Set PC5 function to NAND_nWE        */
#define SET_NAND_nWP_PC2()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC2MFP_Msk) | SYS_GPC_MFPL_PC2MFP_NAND_nWP)  /*!< Set PC2 function to NAND_nWP        */

/* QSPI0 */
#define SET_QSPI0_CLK_PA1()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA1MFP_Msk) | SYS_GPA_MFPL_PA1MFP_QSPI0_CLK) /*!< Set PA1 function to QSPI0_CLK        */
#define SET_QSPI0_CLK_PD3()        SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD3MFP_Msk) | SYS_GPD_MFPL_PD3MFP_QSPI0_CLK) /*!< Set PD3 function to QSPI0_CLK        */
#define SET_QSPI0_MISO0_PA3()      SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA3MFP_Msk) | SYS_GPA_MFPL_PA3MFP_QSPI0_MISO0)/*!< Set PA3 function to QSPI0_MISO0    */
#define SET_QSPI0_MISO0_PD5()      SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD5MFP_Msk) | SYS_GPD_MFPL_PD5MFP_QSPI0_MISO0)/*!< Set PD5 function to QSPI0_MISO0    */
#define SET_QSPI0_MISO1_PA5()      SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA5MFP_Msk) | SYS_GPA_MFPL_PA5MFP_QSPI0_MISO1)/*!< Set PA5 function to QSPI0_MISO1    */
#define SET_QSPI0_MISO1_PD7()      SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD7MFP_Msk) | SYS_GPD_MFPL_PD7MFP_QSPI0_MISO1)/*!< Set PD7 function to QSPI0_MISO1    */
#define SET_QSPI0_MOSI0_PA2()      SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA2MFP_Msk) | SYS_GPA_MFPL_PA2MFP_QSPI0_MOSI0)/*!< Set PA2 function to QSPI0_MOSI0    */
#define SET_QSPI0_MOSI0_PD4()      SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD4MFP_Msk) | SYS_GPD_MFPL_PD4MFP_QSPI0_MOSI0)/*!< Set PD4 function to QSPI0_MOSI0    */
#define SET_QSPI0_MOSI1_PA4()      SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA4MFP_Msk) | SYS_GPA_MFPL_PA4MFP_QSPI0_MOSI1)/*!< Set PA4 function to QSPI0_MOSI1    */
#define SET_QSPI0_MOSI1_PD6()      SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD6MFP_Msk) | SYS_GPD_MFPL_PD6MFP_QSPI0_MOSI1)/*!< Set PD6 function to QSPI0_MOSI1    */
#define SET_QSPI0_SS0_PA6()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA6MFP_Msk) | SYS_GPA_MFPL_PA6MFP_QSPI0_SS0) /*!< Set PA6 function to QSPI0_SS0        */
#define SET_QSPI0_SS0_PD2()        SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD2MFP_Msk) | SYS_GPD_MFPL_PD2MFP_QSPI0_SS0) /*!< Set PD2 function to QSPI0_SS0        */
#define SET_QSPI0_SS1_PA0()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA0MFP_Msk) | SYS_GPA_MFPL_PA0MFP_QSPI0_SS1) /*!< Set PA0 function to QSPI0_SS1        */
#define SET_QSPI0_SS1_PD0()        SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD0MFP_Msk) | SYS_GPD_MFPL_PD0MFP_QSPI0_SS1) /*!< Set PD0 function to QSPI0_SS1        */

/* SC0 */
#define SET_SC0_CLK_PA5()          SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA5MFP_Msk) | SYS_GPA_MFPL_PA5MFP_SC0_CLK)   /*!< Set PA5 function to SC0_CLK         */
#define SET_SC0_CLK_PC12()         SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC12MFP_Msk) | SYS_GPC_MFPH_PC12MFP_SC0_CLK) /*!< Set PC12 function to SC0_CLK        */
#define SET_SC0_DAT_PA4()          SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA4MFP_Msk) | SYS_GPA_MFPL_PA4MFP_SC0_DAT)   /*!< Set PA4 function to SC0_DAT         */
#define SET_SC0_DAT_PC13()         SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC13MFP_Msk) | SYS_GPC_MFPH_PC13MFP_SC0_DAT) /*!< Set PC13 function to SC0_DAT        */
#define SET_SC0_PWR_PA3()          SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA3MFP_Msk) | SYS_GPA_MFPL_PA3MFP_SC0_PWR)   /*!< Set PA3 function to SC0_PWR         */
#define SET_SC0_PWR_PC14()         SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC14MFP_Msk) | SYS_GPC_MFPH_PC14MFP_SC0_PWR) /*!< Set PC14 function to SC0_PWR        */
#define SET_SC0_RST_PA6()          SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA6MFP_Msk) | SYS_GPA_MFPL_PA6MFP_SC0_RST)   /*!< Set PA6 function to SC0_RST         */
#define SET_SC0_RST_PC11()         SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC11MFP_Msk) | SYS_GPC_MFPH_PC11MFP_SC0_RST) /*!< Set PC11 function to SC0_RST        */
#define SET_SC0_nCD_PA2()          SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA2MFP_Msk) | SYS_GPA_MFPL_PA2MFP_SC0_nCD)   /*!< Set PA2 function to SC0_nCD         */
#define SET_SC0_nCD_PC15()         SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC15MFP_Msk) | SYS_GPC_MFPH_PC15MFP_SC0_nCD) /*!< Set PC15 function to SC0_nCD        */

/* SC1 */
#define SET_SC1_CLK_PC7()          SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC7MFP_Msk) | SYS_GPC_MFPL_PC7MFP_SC1_CLK)   /*!< Set PC7 function to SC1_CLK         */
#define SET_SC1_CLK_PF1()          SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF1MFP_Msk) | SYS_GPF_MFPL_PF1MFP_SC1_CLK)   /*!< Set PF1 function to SC1_CLK         */
#define SET_SC1_DAT_PC8()          SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC8MFP_Msk) | SYS_GPC_MFPH_PC8MFP_SC1_DAT)   /*!< Set PC8 function to SC1_DAT         */
#define SET_SC1_DAT_PF2()          SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF2MFP_Msk) | SYS_GPF_MFPL_PF2MFP_SC1_DAT)   /*!< Set PF2 function to SC1_DAT         */
#define SET_SC1_PWR_PC9()          SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC9MFP_Msk) | SYS_GPC_MFPH_PC9MFP_SC1_PWR)   /*!< Set PC9 function to SC1_PWR         */
#define SET_SC1_PWR_PF3()          SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF3MFP_Msk) | SYS_GPF_MFPL_PF3MFP_SC1_PWR)   /*!< Set PF3 function to SC1_PWR         */
#define SET_SC1_RST_PC6()          SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC6MFP_Msk) | SYS_GPC_MFPL_PC6MFP_SC1_RST)   /*!< Set PC6 function to SC1_RST         */
#define SET_SC1_RST_PF0()          SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF0MFP_Msk) | SYS_GPF_MFPL_PF0MFP_SC1_RST)   /*!< Set PF0 function to SC1_RST         */
#define SET_SC1_nCD_PC10()         SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC10MFP_Msk) | SYS_GPC_MFPH_PC10MFP_SC1_nCD) /*!< Set PC10 function to SC1_nCD        */
#define SET_SC1_nCD_PF4()          SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF4MFP_Msk) | SYS_GPF_MFPL_PF4MFP_SC1_nCD)   /*!< Set PF4 function to SC1_nCD         */

/* SD0 */
#define SET_SD0_CLK_PC6()          SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC6MFP_Msk) | SYS_GPC_MFPL_PC6MFP_SD0_CLK)   /*!< Set PC6 function to SD0_CLK         */
#define SET_SD0_CLK_PH6()          SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH6MFP_Msk) | SYS_GPH_MFPL_PH6MFP_SD0_CLK)   /*!< Set PH6 function to SD0_CLK         */
#define SET_SD0_CMD_PC5()          SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC5MFP_Msk) | SYS_GPC_MFPL_PC5MFP_SD0_CMD)   /*!< Set PC5 function to SD0_CMD         */
#define SET_SD0_CMD_PH5()          SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH5MFP_Msk) | SYS_GPH_MFPL_PH5MFP_SD0_CMD)   /*!< Set PH5 function to SD0_CMD         */
#define SET_SD0_DAT0_PC7()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC7MFP_Msk) | SYS_GPC_MFPL_PC7MFP_SD0_DAT0)  /*!< Set PC7 function to SD0_DAT0        */
#define SET_SD0_DAT0_PH1()         SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH1MFP_Msk) | SYS_GPH_MFPL_PH1MFP_SD0_DAT0)  /*!< Set PH1 function to SD0_DAT0        */
#define SET_SD0_DAT1_PC8()         SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC8MFP_Msk) | SYS_GPC_MFPH_PC8MFP_SD0_DAT1)  /*!< Set PC8 function to SD0_DAT1        */
#define SET_SD0_DAT1_PH2()         SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH2MFP_Msk) | SYS_GPH_MFPL_PH2MFP_SD0_DAT1)  /*!< Set PH2 function to SD0_DAT1        */
#define SET_SD0_DAT2_PC9()         SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC9MFP_Msk) | SYS_GPC_MFPH_PC9MFP_SD0_DAT2)  /*!< Set PC9 function to SD0_DAT2        */
#define SET_SD0_DAT2_PH3()         SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH3MFP_Msk) | SYS_GPH_MFPL_PH3MFP_SD0_DAT2)  /*!< Set PH3 function to SD0_DAT2        */
#define SET_SD0_DAT3_PC10()        SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC10MFP_Msk) | SYS_GPC_MFPH_PC10MFP_SD0_DAT3)/*!< Set PC10 function to SD0_DAT3       */
#define SET_SD0_DAT3_PH4()         SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH4MFP_Msk) | SYS_GPH_MFPL_PH4MFP_SD0_DAT3)  /*!< Set PH4 function to SD0_DAT3        */
#define SET_SD0_nCD_PB8()          SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB8MFP_Msk) | SYS_GPB_MFPH_PB8MFP_SD0_nCD)   /*!< Set PB8 function to SD0_nCD         */
#define SET_SD0_nCD_PC12()         SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC12MFP_Msk) | SYS_GPC_MFPH_PC12MFP_SD0_nCD) /*!< Set PC12 function to SD0_nCD        */
#define SET_SD0_nCD_PH0()          SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH0MFP_Msk) | SYS_GPH_MFPL_PH0MFP_SD0_nCD)   /*!< Set PH0 function to SD0_nCD         */

/* eMMC0 */
#define SET_eMMC0_CLK_PC6()        SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC6MFP_Msk) | SYS_GPC_MFPL_PC6MFP_eMMC0_CLK) /*!< Set PC6 function to eMMC0_CLK        */
#define SET_eMMC0_CLK_PH6()        SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH6MFP_Msk) | SYS_GPH_MFPL_PH6MFP_eMMC0_CLK) /*!< Set PH6 function to eMMC0_CLK        */
#define SET_eMMC0_CMD_PC5()        SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC5MFP_Msk) | SYS_GPC_MFPL_PC5MFP_eMMC0_CMD) /*!< Set PC5 function to eMMC0_CMD        */
#define SET_eMMC0_CMD_PH5()        SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH5MFP_Msk) | SYS_GPH_MFPL_PH5MFP_eMMC0_CMD) /*!< Set PH5 function to eMMC0_CMD        */
#define SET_eMMC0_DAT0_PC7()       SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC7MFP_Msk) | SYS_GPC_MFPL_PC7MFP_eMMC0_DAT0)/*!< Set PC7 function to eMMC0_DAT0       */
#define SET_eMMC0_DAT0_PH1()       SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH1MFP_Msk) | SYS_GPH_MFPL_PH1MFP_eMMC0_DAT0)/*!< Set PH1 function to eMMC0_DAT0       */
#define SET_eMMC0_DAT1_PC8()       SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC8MFP_Msk) | SYS_GPC_MFPH_PC8MFP_eMMC0_DAT1)/*!< Set PC8 function to eMMC0_DAT1       */
#define SET_eMMC0_DAT1_PH2()       SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH2MFP_Msk) | SYS_GPH_MFPL_PH2MFP_eMMC0_DAT1)/*!< Set PH2 function to eMMC0_DAT1       */
#define SET_eMMC0_DAT2_PC9()       SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC9MFP_Msk) | SYS_GPC_MFPH_PC9MFP_eMMC0_DAT2)/*!< Set PC9 function to eMMC0_DAT2       */
#define SET_eMMC0_DAT2_PH3()       SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH3MFP_Msk) | SYS_GPH_MFPL_PH3MFP_eMMC0_DAT2)/*!< Set PH3 function to eMMC0_DAT2       */
#define SET_eMMC0_DAT3_PC10()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC10MFP_Msk) | SYS_GPC_MFPH_PC10MFP_eMMC0_DAT3)/*!< Set PC10 function to eMMC0_DAT3    */
#define SET_eMMC0_DAT3_PH4()       SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH4MFP_Msk) | SYS_GPH_MFPL_PH4MFP_eMMC0_DAT3)/*!< Set PH4 function to eMMC0_DAT3       */

/* SD1 */
#define SET_SD1_CLK_PF1()          SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF1MFP_Msk) | SYS_GPF_MFPL_PF1MFP_SD1_CLK)   /*!< Set PF1 function to SD1_CLK         */
#define SET_SD1_CLK_PH9()          SYS->GPH_MFPH = ((SYS->GPH_MFPH & ~SYS_GPH_MFPH_PH9MFP_Msk) | SYS_GPH_MFPH_PH9MFP_SD1_CLK)   /*!< Set PH9 function to SD1_CLK         */
#define SET_SD1_CMD_PF0()          SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF0MFP_Msk) | SYS_GPF_MFPL_PF0MFP_SD1_CMD)   /*!< Set PF0 function to SD1_CMD         */
#define SET_SD1_CMD_PH8()          SYS->GPH_MFPH = ((SYS->GPH_MFPH & ~SYS_GPH_MFPH_PH8MFP_Msk) | SYS_GPH_MFPH_PH8MFP_SD1_CMD)   /*!< Set PH8 function to SD1_CMD         */
#define SET_SD1_DAT0_PB9()         SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB9MFP_Msk) | SYS_GPB_MFPH_PB9MFP_SD1_DAT0)  /*!< Set PB9 function to SD1_DAT0        */
#define SET_SD1_DAT0_PF2()         SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF2MFP_Msk) | SYS_GPF_MFPL_PF2MFP_SD1_DAT0)  /*!< Set PF2 function to SD1_DAT0        */
#define SET_SD1_DAT1_PB10()        SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB10MFP_Msk) | SYS_GPB_MFPH_PB10MFP_SD1_DAT1)/*!< Set PB10 function to SD1_DAT1       */
#define SET_SD1_DAT1_PF3()         SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF3MFP_Msk) | SYS_GPF_MFPL_PF3MFP_SD1_DAT1)  /*!< Set PF3 function to SD1_DAT1        */
#define SET_SD1_DAT2_PB11()        SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB11MFP_Msk) | SYS_GPB_MFPH_PB11MFP_SD1_DAT2)/*!< Set PB11 function to SD1_DAT2       */
#define SET_SD1_DAT2_PF4()         SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF4MFP_Msk) | SYS_GPF_MFPL_PF4MFP_SD1_DAT2)  /*!< Set PF4 function to SD1_DAT2        */
#define SET_SD1_DAT3_PB12()        SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB12MFP_Msk) | SYS_GPB_MFPH_PB12MFP_SD1_DAT3)/*!< Set PB12 function to SD1_DAT3       */
#define SET_SD1_DAT3_PF5()         SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF5MFP_Msk) | SYS_GPF_MFPL_PF5MFP_SD1_DAT3)  /*!< Set PF5 function to SD1_DAT3        */
#define SET_SD1_nCD_PF6()          SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF6MFP_Msk) | SYS_GPF_MFPL_PF6MFP_SD1_nCD)   /*!< Set PF6 function to SD1_nCD         */
#define SET_SD1_nCD_PH7()          SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH7MFP_Msk) | SYS_GPH_MFPL_PH7MFP_SD1_nCD)   /*!< Set PH7 function to SD1_nCD         */

/* eMMC1 */
#define SET_eMMC1_CLK_PF1()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF1MFP_Msk) | SYS_GPF_MFPL_PF1MFP_eMMC1_CLK) /*!< Set PF1 function to eMMC1_CLK        */
#define SET_eMMC1_CLK_PH9()        SYS->GPH_MFPH = ((SYS->GPH_MFPH & ~SYS_GPH_MFPH_PH9MFP_Msk) | SYS_GPH_MFPH_PH9MFP_eMMC1_CLK) /*!< Set PH9 function to eMMC1_CLK        */
#define SET_eMMC1_CMD_PF0()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF0MFP_Msk) | SYS_GPF_MFPL_PF0MFP_eMMC1_CMD) /*!< Set PF0 function to eMMC1_CMD        */
#define SET_eMMC1_CMD_PH8()        SYS->GPH_MFPH = ((SYS->GPH_MFPH & ~SYS_GPH_MFPH_PH8MFP_Msk) | SYS_GPH_MFPH_PH8MFP_eMMC1_CMD) /*!< Set PH8 function to eMMC1_CMD        */

#define SET_eMMC1_DAT0_PB9()       SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB9MFP_Msk) | SYS_GPB_MFPH_PB9MFP_eMMC1_DAT0)/*!< Set PB9 function to eMMC1_DAT0       */
#define SET_eMMC1_DAT0_PF2()       SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF2MFP_Msk) | SYS_GPF_MFPL_PF2MFP_eMMC1_DAT0)/*!< Set PF2 function to eMMC1_DAT0       */
#define SET_eMMC1_DAT1_PB10()      SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB10MFP_Msk) | SYS_GPB_MFPH_PB10MFP_eMMC1_DAT1)/*!< Set PB10 function to eMMC1_DAT1    */
#define SET_eMMC1_DAT1_PF3()       SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF3MFP_Msk) | SYS_GPF_MFPL_PF3MFP_eMMC1_DAT1)/*!< Set PF3 function to eMMC1_DAT1       */
#define SET_eMMC1_DAT2_PB11()      SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB11MFP_Msk) | SYS_GPB_MFPH_PB11MFP_eMMC1_DAT2)/*!< Set PB11 function to eMMC1_DAT2    */
#define SET_eMMC1_DAT2_PF4()       SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF4MFP_Msk) | SYS_GPF_MFPL_PF4MFP_eMMC1_DAT2)/*!< Set PF4 function to eMMC1_DAT2       */
#define SET_eMMC1_DAT3_PB12()      SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB12MFP_Msk) | SYS_GPB_MFPH_PB12MFP_eMMC1_DAT3)/*!< Set PB12 function to eMMC1_DAT3    */
#define SET_eMMC1_DAT3_PF5()       SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF5MFP_Msk) | SYS_GPF_MFPL_PF5MFP_eMMC1_DAT3)/*!< Set PF5 function to eMMC1_DAT3       */

/* SPI0 */
#define SET_SPI0_CLK_PC6()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC6MFP_Msk) | SYS_GPC_MFPL_PC6MFP_SPI0_CLK)  /*!< Set PC6 function to SPI0_CLK        */
#define SET_SPI0_CLK_PD9()         SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD9MFP_Msk) | SYS_GPD_MFPH_PD9MFP_SPI0_CLK)  /*!< Set PD9 function to SPI0_CLK        */
#define SET_SPI0_CLK_PH6()         SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH6MFP_Msk) | SYS_GPH_MFPL_PH6MFP_SPI0_CLK)  /*!< Set PH6 function to SPI0_CLK        */
#define SET_SPI0_MISO_PC8()        SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC8MFP_Msk) | SYS_GPC_MFPH_PC8MFP_SPI0_MISO) /*!< Set PC8 function to SPI0_MISO       */
#define SET_SPI0_MISO_PD11()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD11MFP_Msk) | SYS_GPD_MFPH_PD11MFP_SPI0_MISO)/*!< Set PD11 function to SPI0_MISO     */
#define SET_SPI0_MISO_PH5()        SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH5MFP_Msk) | SYS_GPH_MFPL_PH5MFP_SPI0_MISO) /*!< Set PH5 function to SPI0_MISO       */
#define SET_SPI0_MOSI_PC4()        SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC4MFP_Msk) | SYS_GPC_MFPL_PC4MFP_SPI0_MOSI) /*!< Set PC4 function to SPI0_MOSI       */
#define SET_SPI0_MOSI_PC7()        SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC7MFP_Msk) | SYS_GPC_MFPL_PC7MFP_SPI0_MOSI) /*!< Set PC7 function to SPI0_MOSI       */
#define SET_SPI0_MOSI_PC14()       SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC14MFP_Msk) | SYS_GPC_MFPH_PC14MFP_SPI0_MOSI)/*!< Set PC14 function to SPI0_MOSI     */
#define SET_SPI0_MOSI_PD10()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD10MFP_Msk) | SYS_GPD_MFPH_PD10MFP_SPI0_MOSI)/*!< Set PD10 function to SPI0_MOSI     */
#define SET_SPI0_SS0_PC5()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC5MFP_Msk) | SYS_GPC_MFPL_PC5MFP_SPI0_SS0)   /*!< Set PC5 function to SPI0_SS0        */
#define SET_SPI0_SS0_PD8()         SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD8MFP_Msk) | SYS_GPD_MFPH_PD8MFP_SPI0_SS0)   /*!< Set PD8 function to SPI0_SS0        */
#define SET_SPI0_SS0_PH0()         SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH0MFP_Msk) | SYS_GPH_MFPL_PH0MFP_SPI0_SS0)   /*!< Set PH0 function to SPI0_SS0        */
#define SET_SPI0_SS1_PB3()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB3MFP_Msk) | SYS_GPB_MFPL_PB3MFP_SPI0_SS1)   /*!< Set PB3 function to SPI0_SS1        */
#define SET_SPI0_SS1_PC0()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC0MFP_Msk) | SYS_GPC_MFPL_PC0MFP_SPI0_SS1)   /*!< Set PC0 function to SPI0_SS1        */
#define SET_SPI0_SS1_PD1()         SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD1MFP_Msk) | SYS_GPD_MFPL_PD1MFP_SPI0_SS1)   /*!< Set PD1 function to SPI0_SS1        */
#define SET_SPI0_SS1_PG15()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG15MFP_Msk) | SYS_GPG_MFPH_PG15MFP_SPI0_SS1)/*!< Set PG15 function to SPI0_SS1       */

/* SPI1 */
#define SET_SPI1_CLK_PB4()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB4MFP_Msk) | SYS_GPB_MFPL_PB4MFP_SPI1_CLK)  /*!< Set PB4 function to SPI1_CLK        */
#define SET_SPI1_CLK_PB10()        SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB10MFP_Msk) | SYS_GPB_MFPH_PB10MFP_SPI1_CLK)/*!< Set PB10 function to SPI1_CLK       */
#define SET_SPI1_CLK_PG10()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG10MFP_Msk) | SYS_GPG_MFPH_PG10MFP_SPI1_CLK)/*!< Set PG10 function to SPI1_CLK       */
#define SET_SPI1_CLK_PG12()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG12MFP_Msk) | SYS_GPG_MFPH_PG12MFP_SPI1_CLK)/*!< Set PG12 function to SPI1_CLK       */
#define SET_SPI1_MISO_PB5()        SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB5MFP_Msk) | SYS_GPB_MFPL_PB5MFP_SPI1_MISO) /*!< Set PB5 function to SPI1_MISO       */
#define SET_SPI1_MISO_PB12()       SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB12MFP_Msk) | SYS_GPB_MFPH_PB12MFP_SPI1_MISO)/*!< Set PB12 function to SPI1_MISO     */
#define SET_SPI1_MISO_PG14()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG14MFP_Msk) | SYS_GPG_MFPH_PG14MFP_SPI1_MISO)/*!< Set PG14 function to SPI1_MISO     */
#define SET_SPI1_MOSI_PB7()        SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB7MFP_Msk) | SYS_GPB_MFPL_PB7MFP_SPI1_MOSI) /*!< Set PB7 function to SPI1_MOSI       */
#define SET_SPI1_MOSI_PB11()       SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB11MFP_Msk) | SYS_GPB_MFPH_PB11MFP_SPI1_MOSI)/*!< Set PB11 function to SPI1_MOSI     */
#define SET_SPI1_MOSI_PG13()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG13MFP_Msk) | SYS_GPG_MFPH_PG13MFP_SPI1_MOSI)/*!< Set PG13 function to SPI1_MOSI     */
#define SET_SPI1_SS0_PA15()        SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA15MFP_Msk) | SYS_GPA_MFPH_PA15MFP_SPI1_SS0)/*!< Set PA15 function to SPI1_SS0       */
#define SET_SPI1_SS0_PB6()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB6MFP_Msk) | SYS_GPB_MFPL_PB6MFP_SPI1_SS0)   /*!< Set PB6 function to SPI1_SS0        */
#define SET_SPI1_SS0_PB9()         SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB9MFP_Msk) | SYS_GPB_MFPH_PB9MFP_SPI1_SS0)   /*!< Set PB9 function to SPI1_SS0        */
#define SET_SPI1_SS0_PG11()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG11MFP_Msk) | SYS_GPG_MFPH_PG11MFP_SPI1_SS0)/*!< Set PG11 function to SPI1_SS0       */
#define SET_SPI1_SS1_PB1()         SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB1MFP_Msk) | SYS_GPB_MFPL_PB1MFP_SPI1_SS1)   /*!< Set PB1 function to SPI1_SS1        */
#define SET_SPI1_SS1_PG15()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG15MFP_Msk) | SYS_GPG_MFPH_PG15MFP_SPI1_SS1)/*!< Set PG15 function to SPI1_SS1       */
#define SET_SPI1_SS1_PH7()         SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH7MFP_Msk) | SYS_GPH_MFPL_PH7MFP_SPI1_SS1)   /*!< Set PH7 function to SPI1_SS1        */

/* SPI2 */
#define SET_SPI2_CLK_PA6()         SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA6MFP_Msk) | SYS_GPA_MFPL_PA6MFP_SPI2_CLK)  /*!< Set PA6 function to SPI2_CLK        */
#define SET_SPI2_CLK_PD13()        SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD13MFP_Msk) | SYS_GPD_MFPH_PD13MFP_SPI2_CLK)/*!< Set PD13 function to SPI2_CLK       */
#define SET_SPI2_CLK_PE9()         SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE9MFP_Msk) | SYS_GPE_MFPH_PE9MFP_SPI2_CLK)  /*!< Set PE9 function to SPI2_CLK        */
#define SET_SPI2_CLK_PF5()         SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF5MFP_Msk) | SYS_GPF_MFPL_PF5MFP_SPI2_CLK)  /*!< Set PF5 function to SPI2_CLK        */
#define SET_SPI2_MISO_PA4()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA4MFP_Msk) | SYS_GPA_MFPL_PA4MFP_SPI2_MISO) /*!< Set PA4 function to SPI2_MISO       */
#define SET_SPI2_MISO_PD15()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD15MFP_Msk) | SYS_GPD_MFPH_PD15MFP_SPI2_MISO)/*!< Set PD15 function to SPI2_MISO     */
#define SET_SPI2_MISO_PE12()       SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE12MFP_Msk) | SYS_GPE_MFPH_PE12MFP_SPI2_MISO)/*!< Set PE12 function to SPI2_MISO     */
#define SET_SPI2_MISO_PF7()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF7MFP_Msk) | SYS_GPF_MFPL_PF7MFP_SPI2_MISO) /*!< Set PF7 function to SPI2_MISO       */
#define SET_SPI2_MOSI_PA5()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA5MFP_Msk) | SYS_GPA_MFPL_PA5MFP_SPI2_MOSI) /*!< Set PA5 function to SPI2_MOSI       */
#define SET_SPI2_MOSI_PD14()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD14MFP_Msk) | SYS_GPD_MFPH_PD14MFP_SPI2_MOSI)/*!< Set PD14 function to SPI2_MOSI     */
#define SET_SPI2_MOSI_PE10()       SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE10MFP_Msk) | SYS_GPE_MFPH_PE10MFP_SPI2_MOSI)/*!< Set PE10 function to SPI2_MOSI     */
#define SET_SPI2_MOSI_PF6()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF6MFP_Msk) | SYS_GPF_MFPL_PF6MFP_SPI2_MOSI) /*!< Set PF6 function to SPI2_MOSI       */
#define SET_SPI2_SS0_PA3()         SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA3MFP_Msk) | SYS_GPA_MFPL_PA3MFP_SPI2_SS0)   /*!< Set PA3 function to SPI2_SS0        */
#define SET_SPI2_SS0_PD0()         SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD0MFP_Msk) | SYS_GPD_MFPL_PD0MFP_SPI2_SS0)   /*!< Set PD0 function to SPI2_SS0        */
#define SET_SPI2_SS0_PE8()         SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE8MFP_Msk) | SYS_GPE_MFPH_PE8MFP_SPI2_SS0)   /*!< Set PE8 function to SPI2_SS0        */
#define SET_SPI2_SS0_PF4()         SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF4MFP_Msk) | SYS_GPF_MFPL_PF4MFP_SPI2_SS0)   /*!< Set PF4 function to SPI2_SS0        */
#define SET_SPI2_SS1_PA2()         SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA2MFP_Msk) | SYS_GPA_MFPL_PA2MFP_SPI2_SS1)   /*!< Set PA2 function to SPI2_SS1        */
#define SET_SPI2_SS1_PB13()        SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB13MFP_Msk) | SYS_GPB_MFPH_PB13MFP_SPI2_SS1)/*!< Set PB13 function to SPI2_SS1       */
#define SET_SPI2_SS1_PD12()        SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD12MFP_Msk) | SYS_GPD_MFPH_PD12MFP_SPI2_SS1)/*!< Set PD12 function to SPI2_SS1       */
#define SET_SPI2_SS1_PG15()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG15MFP_Msk) | SYS_GPG_MFPH_PG15MFP_SPI2_SS1)/*!< Set PG15 function to SPI2_SS1       */

/* SPI3 */
#define SET_SPI3_CLK_PC1()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC1MFP_Msk) | SYS_GPC_MFPL_PC1MFP_SPI3_CLK)  /*!< Set PC1 function to SPI3_CLK        */
#define SET_SPI3_CLK_PC11()        SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC11MFP_Msk) | SYS_GPC_MFPH_PC11MFP_SPI3_CLK)/*!< Set PC11 function to SPI3_CLK       */
#define SET_SPI3_CLK_PE1()         SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE1MFP_Msk) | SYS_GPE_MFPL_PE1MFP_SPI3_CLK)  /*!< Set PE1 function to SPI3_CLK        */
#define SET_SPI3_CLK_PF1()         SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF1MFP_Msk) | SYS_GPF_MFPL_PF1MFP_SPI3_CLK)  /*!< Set PF1 function to SPI3_CLK        */
#define SET_SPI3_MISO_PC3()        SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC3MFP_Msk) | SYS_GPC_MFPL_PC3MFP_SPI3_MISO) /*!< Set PC3 function to SPI3_MISO       */
#define SET_SPI3_MISO_PC13()       SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC13MFP_Msk) | SYS_GPC_MFPH_PC13MFP_SPI3_MISO)/*!< Set PC13 function to SPI3_MISO     */
#define SET_SPI3_MISO_PE3()        SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE3MFP_Msk) | SYS_GPE_MFPL_PE3MFP_SPI3_MISO) /*!< Set PE3 function to SPI3_MISO       */
#define SET_SPI3_MISO_PF3()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF3MFP_Msk) | SYS_GPF_MFPL_PF3MFP_SPI3_MISO) /*!< Set PF3 function to SPI3_MISO       */
#define SET_SPI3_MOSI_PC2()        SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC2MFP_Msk) | SYS_GPC_MFPL_PC2MFP_SPI3_MOSI) /*!< Set PC2 function to SPI3_MOSI       */
#define SET_SPI3_MOSI_PC12()       SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC12MFP_Msk) | SYS_GPC_MFPH_PC12MFP_SPI3_MOSI)/*!< Set PC12 function to SPI3_MOSI     */
#define SET_SPI3_MOSI_PE2()        SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE2MFP_Msk) | SYS_GPE_MFPL_PE2MFP_SPI3_MOSI) /*!< Set PE2 function to SPI3_MOSI       */
#define SET_SPI3_MOSI_PF2()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF2MFP_Msk) | SYS_GPF_MFPL_PF2MFP_SPI3_MOSI) /*!< Set PF2 function to SPI3_MOSI       */
#define SET_SPI3_SS0_PC0()         SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC0MFP_Msk) | SYS_GPC_MFPL_PC0MFP_SPI3_SS0)   /*!< Set PC0 function to SPI3_SS0        */
#define SET_SPI3_SS0_PC10()        SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC10MFP_Msk) | SYS_GPC_MFPH_PC10MFP_SPI3_SS0)/*!< Set PC10 function to SPI3_SS0       */
#define SET_SPI3_SS0_PF0()         SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF0MFP_Msk) | SYS_GPF_MFPL_PF0MFP_SPI3_SS0)   /*!< Set PF0 function to SPI3_SS0        */
#define SET_SPI3_SS0_PF9()         SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF9MFP_Msk) | SYS_GPF_MFPH_PF9MFP_SPI3_SS0)   /*!< Set PF9 function to SPI3_SS0        */
#define SET_SPI3_SS1_PC15()        SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC15MFP_Msk) | SYS_GPC_MFPH_PC15MFP_SPI3_SS1)/*!< Set PC15 function to SPI3_SS1       */
#define SET_SPI3_SS1_PE0()         SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE0MFP_Msk) | SYS_GPE_MFPL_PE0MFP_SPI3_SS1)   /*!< Set PE0 function to SPI3_SS1        */
#define SET_SPI3_SS1_PF8()         SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF8MFP_Msk) | SYS_GPF_MFPH_PF8MFP_SPI3_SS1)   /*!< Set PF8 function to SPI3_SS1        */
#define SET_SPI3_SS1_PG15()        SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG15MFP_Msk) | SYS_GPG_MFPH_PG15MFP_SPI3_SS1)/*!< Set PG15 function to SPI3_SS1       */

/* TM0 */
#define SET_TM0_PB3()              SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB3MFP_Msk) | SYS_GPB_MFPL_PB3MFP_TM0)        /*!< Set PB3 function to TM0             */
#define SET_TM0_PB9()              SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB9MFP_Msk) | SYS_GPB_MFPH_PB9MFP_TM0)        /*!< Set PB9 function to TM0             */
#define SET_TM0_PC0()              SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC0MFP_Msk) | SYS_GPC_MFPL_PC0MFP_TM0)        /*!< Set PC0 function to TM0             */
#define SET_TM0_EXT_PB1()          SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB1MFP_Msk) | SYS_GPB_MFPL_PB1MFP_TM0_EXT)    /*!< Set PB1 function to TM0_EXT         */
#define SET_TM0_EXT_PB8()          SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB8MFP_Msk) | SYS_GPB_MFPH_PB8MFP_TM0_EXT)    /*!< Set PB8 function to TM0_EXT         */
#define SET_TM0_EXT_PB10()         SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB10MFP_Msk) | SYS_GPB_MFPH_PB10MFP_TM0_EXT)  /*!< Set PB10 function to TM0_EXT        */

/* TM1 */
#define SET_TM1_PA14()             SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA14MFP_Msk) | SYS_GPA_MFPH_PA14MFP_TM1)      /*!< Set PA14 function to TM1            */
#define SET_TM1_PD0()              SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD0MFP_Msk) | SYS_GPD_MFPL_PD0MFP_TM1)        /*!< Set PD0 function to TM1             */
#define SET_TM1_PF8()              SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF8MFP_Msk) | SYS_GPF_MFPH_PF8MFP_TM1)        /*!< Set PF8 function to TM1             */
#define SET_TM1_PG11()             SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG11MFP_Msk) | SYS_GPG_MFPH_PG11MFP_TM1)      /*!< Set PG11 function to TM1            */
#define SET_TM1_EXT_PA13()         SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA13MFP_Msk) | SYS_GPA_MFPH_PA13MFP_TM1_EXT)  /*!< Set PA13 function to TM1_EXT        */
#define SET_TM1_EXT_PD1()          SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD1MFP_Msk) | SYS_GPD_MFPL_PD1MFP_TM1_EXT)    /*!< Set PD1 function to TM1_EXT         */
#define SET_TM1_EXT_PF9()          SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF9MFP_Msk) | SYS_GPF_MFPH_PF9MFP_TM1_EXT)    /*!< Set PF9 function to TM1_EXT         */
#define SET_TM1_EXT_PG12()         SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG12MFP_Msk) | SYS_GPG_MFPH_PG12MFP_TM1_EXT)  /*!< Set PG12 function to TM1_EXT        */

/* TM2 */
#define SET_TM2_PA10()             SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA10MFP_Msk) | SYS_GPA_MFPH_PA10MFP_TM2)      /*!< Set PA10 function to TM2            */
#define SET_TM2_PB12()             SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB12MFP_Msk) | SYS_GPB_MFPH_PB12MFP_TM2)      /*!< Set PB12 function to TM2            */
#define SET_TM2_PD12()             SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD12MFP_Msk) | SYS_GPD_MFPH_PD12MFP_TM2)      /*!< Set PD12 function to TM2            */
#define SET_TM2_EXT_PA9()          SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA9MFP_Msk) | SYS_GPA_MFPH_PA9MFP_TM2_EXT)    /*!< Set PA9 function to TM2_EXT         */
#define SET_TM2_EXT_PB11()         SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB11MFP_Msk) | SYS_GPB_MFPH_PB11MFP_TM2_EXT)  /*!< Set PB11 function to TM2_EXT        */
#define SET_TM2_EXT_PD13()         SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD13MFP_Msk) | SYS_GPD_MFPH_PD13MFP_TM2_EXT)  /*!< Set PD13 function to TM2_EXT        */

/* TM3 */
#define SET_TM3_PA8()              SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA8MFP_Msk) | SYS_GPA_MFPH_PA8MFP_TM3)        /*!< Set PA8 function to TM3             */
#define SET_TM3_PD14()             SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD14MFP_Msk) | SYS_GPD_MFPH_PD14MFP_TM3)      /*!< Set PD14 function to TM3            */
#define SET_TM3_PH1()              SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH1MFP_Msk) | SYS_GPH_MFPL_PH1MFP_TM3)        /*!< Set PH1 function to TM3             */
#define SET_TM3_EXT_PA7()          SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA7MFP_Msk) | SYS_GPA_MFPL_PA7MFP_TM3_EXT)    /*!< Set PA7 function to TM3_EXT         */
#define SET_TM3_EXT_PD15()         SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD15MFP_Msk) | SYS_GPD_MFPH_PD15MFP_TM3_EXT)  /*!< Set PD15 function to TM3_EXT        */
#define SET_TM3_EXT_PH2()          SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH2MFP_Msk) | SYS_GPH_MFPL_PH2MFP_TM3_EXT)    /*!< Set PH2 function to TM3_EXT         */

/* TM4 */
#define SET_TM4_PA12()             SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA12MFP_Msk) | SYS_GPA_MFPH_PA12MFP_TM4)      /*!< Set PA12 function to TM4            */
#define SET_TM4_PB13()             SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB13MFP_Msk) | SYS_GPB_MFPH_PB13MFP_TM4)      /*!< Set PB13 function to TM4            */
#define SET_TM4_PD3()              SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD3MFP_Msk) | SYS_GPD_MFPL_PD3MFP_TM4)        /*!< Set PD3 function to TM4             */
#define SET_TM4_EXT_PA11()         SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA11MFP_Msk) | SYS_GPA_MFPH_PA11MFP_TM4_EXT)  /*!< Set PA11 function to TM4_EXT        */
#define SET_TM4_EXT_PD2()          SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD2MFP_Msk) | SYS_GPD_MFPL_PD2MFP_TM4_EXT)    /*!< Set PD2 function to TM4_EXT         */
#define SET_TM4_EXT_PF6()          SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF6MFP_Msk) | SYS_GPF_MFPL_PF6MFP_TM4_EXT)    /*!< Set PF6 function to TM4_EXT         */

/* TM5 */
#define SET_TM5_PD5()              SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD5MFP_Msk) | SYS_GPD_MFPL_PD5MFP_TM5)        /*!< Set PD5 function to TM5             */
#define SET_TM5_PF10()             SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF10MFP_Msk) | SYS_GPF_MFPH_PF10MFP_TM5)      /*!< Set PF10 function to TM5            */
#define SET_TM5_PG10()             SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG10MFP_Msk) | SYS_GPG_MFPH_PG10MFP_TM5)      /*!< Set PG10 function to TM5            */
#define SET_TM5_EXT_PA15()         SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA15MFP_Msk) | SYS_GPA_MFPH_PA15MFP_TM5_EXT)  /*!< Set PA15 function to TM5_EXT        */
#define SET_TM5_EXT_PD4()          SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD4MFP_Msk) | SYS_GPD_MFPL_PD4MFP_TM5_EXT)    /*!< Set PD4 function to TM5_EXT         */
#define SET_TM5_EXT_PF7()          SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF7MFP_Msk) | SYS_GPF_MFPL_PF7MFP_TM5_EXT)    /*!< Set PF7 function to TM5_EXT         */

/* UART0 */
#define SET_UART0_RXD_PF11()       SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF11MFP_Msk) | SYS_GPF_MFPH_PF11MFP_UART0_RXD)/*!< Set PF11 function to UART0_RXD     */
#define SET_UART0_TXD_PF12()       SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF12MFP_Msk) | SYS_GPF_MFPH_PF12MFP_UART0_TXD)/*!< Set PF12 function to UART0_TXD     */

/* UART1 */
#define SET_UART1_RXD_PA0()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA0MFP_Msk) | SYS_GPA_MFPL_PA0MFP_UART1_RXD)  /*!< Set PA0 function to UART1_RXD       */
#define SET_UART1_RXD_PC6()        SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC6MFP_Msk) | SYS_GPC_MFPL_PC6MFP_UART1_RXD)  /*!< Set PC6 function to UART1_RXD       */
#define SET_UART1_RXD_PF9()        SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF9MFP_Msk) | SYS_GPF_MFPH_PF9MFP_UART1_RXD)  /*!< Set PF9 function to UART1_RXD       */
#define SET_UART1_RXD_PH1()        SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH1MFP_Msk) | SYS_GPH_MFPL_PH1MFP_UART1_RXD)  /*!< Set PH1 function to UART1_RXD       */
#define SET_UART1_TXD_PA1()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA1MFP_Msk) | SYS_GPA_MFPL_PA1MFP_UART1_TXD)  /*!< Set PA1 function to UART1_TXD       */
#define SET_UART1_TXD_PC5()        SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC5MFP_Msk) | SYS_GPC_MFPL_PC5MFP_UART1_TXD)  /*!< Set PC5 function to UART1_TXD       */
#define SET_UART1_TXD_PF10()       SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF10MFP_Msk) | SYS_GPF_MFPH_PF10MFP_UART1_TXD)/*!< Set PF10 function to UART1_TXD     */
#define SET_UART1_TXD_PH0()        SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH0MFP_Msk) | SYS_GPH_MFPL_PH0MFP_UART1_TXD)  /*!< Set PH0 function to UART1_TXD       */
#define SET_UART1_nCTS_PC8()       SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC8MFP_Msk) | SYS_GPC_MFPH_PC8MFP_UART1_nCTS) /*!< Set PC8 function to UART1_nCTS      */
#define SET_UART1_nCTS_PF7()       SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF7MFP_Msk) | SYS_GPF_MFPL_PF7MFP_UART1_nCTS) /*!< Set PF7 function to UART1_nCTS      */
#define SET_UART1_nCTS_PH3()       SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH3MFP_Msk) | SYS_GPH_MFPL_PH3MFP_UART1_nCTS) /*!< Set PH3 function to UART1_nCTS      */
#define SET_UART1_nRTS_PC7()       SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC7MFP_Msk) | SYS_GPC_MFPL_PC7MFP_UART1_nRTS) /*!< Set PC7 function to UART1_nRTS      */
#define SET_UART1_nRTS_PF8()       SYS->GPF_MFPH = ((SYS->GPF_MFPH & ~SYS_GPF_MFPH_PF8MFP_Msk) | SYS_GPF_MFPH_PF8MFP_UART1_nRTS) /*!< Set PF8 function to UART1_nRTS      */
#define SET_UART1_nRTS_PH2()       SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH2MFP_Msk) | SYS_GPH_MFPL_PH2MFP_UART1_nRTS) /*!< Set PH2 function to UART1_nRTS      */

/* UART2 */
#define SET_UART2_RXD_PA9()        SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA9MFP_Msk) | SYS_GPA_MFPH_PA9MFP_UART2_RXD) /*!< Set PA9 function to UART2_RXD        */
#define SET_UART2_RXD_PD7()        SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD7MFP_Msk) | SYS_GPD_MFPL_PD7MFP_UART2_RXD) /*!< Set PD7 function to UART2_RXD        */
#define SET_UART2_RXD_PG0()        SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG0MFP_Msk) | SYS_GPG_MFPL_PG0MFP_UART2_RXD) /*!< Set PG0 function to UART2_RXD        */
#define SET_UART2_RXD_PH9()        SYS->GPH_MFPH = ((SYS->GPH_MFPH & ~SYS_GPH_MFPH_PH9MFP_Msk) | SYS_GPH_MFPH_PH9MFP_UART2_RXD) /*!< Set PH9 function to UART2_RXD        */
#define SET_UART2_TXD_PA10()       SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA10MFP_Msk) | SYS_GPA_MFPH_PA10MFP_UART2_TXD)/*!< Set PA10 function to UART2_TXD     */
#define SET_UART2_TXD_PD6()        SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD6MFP_Msk) | SYS_GPD_MFPL_PD6MFP_UART2_TXD) /*!< Set PD6 function to UART2_TXD        */
#define SET_UART2_TXD_PG1()        SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG1MFP_Msk) | SYS_GPG_MFPL_PG1MFP_UART2_TXD) /*!< Set PG1 function to UART2_TXD        */
#define SET_UART2_TXD_PH8()        SYS->GPH_MFPH = ((SYS->GPH_MFPH & ~SYS_GPH_MFPH_PH8MFP_Msk) | SYS_GPH_MFPH_PH8MFP_UART2_TXD) /*!< Set PH8 function to UART2_TXD        */
#define SET_UART2_nCTS_PA7()       SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA7MFP_Msk) | SYS_GPA_MFPL_PA7MFP_UART2_nCTS)/*!< Set PA7 function to UART2_nCTS      */
#define SET_UART2_nCTS_PB0()       SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB0MFP_Msk) | SYS_GPB_MFPL_PB0MFP_UART2_nCTS)/*!< Set PB0 function to UART2_nCTS      */
#define SET_UART2_nCTS_PG2()       SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG2MFP_Msk) | SYS_GPG_MFPL_PG2MFP_UART2_nCTS)/*!< Set PG2 function to UART2_nCTS      */
#define SET_UART2_nCTS_PH0()       SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH0MFP_Msk) | SYS_GPH_MFPL_PH0MFP_UART2_nCTS)/*!< Set PH0 function to UART2_nCTS      */
#define SET_UART2_nRTS_PA8()       SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA8MFP_Msk) | SYS_GPA_MFPH_PA8MFP_UART2_nRTS)/*!< Set PA8 function to UART2_nRTS      */
#define SET_UART2_nRTS_PG3()       SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG3MFP_Msk) | SYS_GPG_MFPL_PG3MFP_UART2_nRTS)/*!< Set PG3 function to UART2_nRTS      */
#define SET_UART2_nRTS_PH1()       SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH1MFP_Msk) | SYS_GPH_MFPL_PH1MFP_UART2_nRTS)/*!< Set PH1 function to UART2_nRTS      */

/* UART3 */
#define SET_UART3_RXD_PB10()       SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB10MFP_Msk) | SYS_GPB_MFPH_PB10MFP_UART3_RXD)/*!< Set PB10 function to UART3_RXD     */
#define SET_UART3_RXD_PC4()        SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC4MFP_Msk) | SYS_GPC_MFPL_PC4MFP_UART3_RXD)  /*!< Set PC4 function to UART3_RXD       */
#define SET_UART3_RXD_PD3()        SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD3MFP_Msk) | SYS_GPD_MFPL_PD3MFP_UART3_RXD)  /*!< Set PD3 function to UART3_RXD       */
#define SET_UART3_RXD_PF6()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF6MFP_Msk) | SYS_GPF_MFPL_PF6MFP_UART3_RXD)  /*!< Set PF6 function to UART3_RXD       */
#define SET_UART3_TXD_PB9()        SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB9MFP_Msk) | SYS_GPB_MFPH_PB9MFP_UART3_TXD)  /*!< Set PB9 function to UART3_TXD       */
#define SET_UART3_TXD_PB13()       SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB13MFP_Msk) | SYS_GPB_MFPH_PB13MFP_UART3_TXD)/*!< Set PB13 function to UART3_TXD     */
#define SET_UART3_TXD_PC3()        SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC3MFP_Msk) | SYS_GPC_MFPL_PC3MFP_UART3_TXD)  /*!< Set PC3 function to UART3_TXD       */
#define SET_UART3_TXD_PD2()        SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD2MFP_Msk) | SYS_GPD_MFPL_PD2MFP_UART3_TXD)  /*!< Set PD2 function to UART3_TXD       */
#define SET_UART3_TXD_PF7()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF7MFP_Msk) | SYS_GPF_MFPL_PF7MFP_UART3_TXD)  /*!< Set PF7 function to UART3_TXD       */
#define SET_UART3_nCTS_PB12()      SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB12MFP_Msk) | SYS_GPB_MFPH_PB12MFP_UART3_nCTS)/*!< Set PB12 function to UART3_nCTS   */
#define SET_UART3_nCTS_PC1()       SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC1MFP_Msk) | SYS_GPC_MFPL_PC1MFP_UART3_nCTS) /*!< Set PC1 function to UART3_nCTS      */
#define SET_UART3_nCTS_PD5()       SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD5MFP_Msk) | SYS_GPD_MFPL_PD5MFP_UART3_nCTS) /*!< Set PD5 function to UART3_nCTS      */
#define SET_UART3_nCTS_PF4()       SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF4MFP_Msk) | SYS_GPF_MFPL_PF4MFP_UART3_nCTS) /*!< Set PF4 function to UART3_nCTS      */
#define SET_UART3_nRTS_PB11()      SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB11MFP_Msk) | SYS_GPB_MFPH_PB11MFP_UART3_nRTS)/*!< Set PB11 function to UART3_nRTS   */
#define SET_UART3_nRTS_PC2()       SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC2MFP_Msk) | SYS_GPC_MFPL_PC2MFP_UART3_nRTS) /*!< Set PC2 function to UART3_nRTS      */
#define SET_UART3_nRTS_PD4()       SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD4MFP_Msk) | SYS_GPD_MFPL_PD4MFP_UART3_nRTS) /*!< Set PD4 function to UART3_nRTS      */
#define SET_UART3_nRTS_PF5()       SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF5MFP_Msk) | SYS_GPF_MFPL_PF5MFP_UART3_nRTS) /*!< Set PF5 function to UART3_nRTS      */

/* UART4 */
#define SET_UART4_RXD_PC10()       SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC10MFP_Msk) | SYS_GPC_MFPH_PC10MFP_UART4_RXD)/*!< Set PC10 function to UART4_RXD     */
#define SET_UART4_RXD_PD13()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD13MFP_Msk) | SYS_GPD_MFPH_PD13MFP_UART4_RXD)/*!< Set PD13 function to UART4_RXD     */
#define SET_UART4_RXD_PE2()        SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE2MFP_Msk) | SYS_GPE_MFPL_PE2MFP_UART4_RXD)  /*!< Set PE2 function to UART4_RXD       */
#define SET_UART4_TXD_PC9()        SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC9MFP_Msk) | SYS_GPC_MFPH_PC9MFP_UART4_TXD)  /*!< Set PC9 function to UART4_TXD       */
#define SET_UART4_TXD_PD12()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD12MFP_Msk) | SYS_GPD_MFPH_PD12MFP_UART4_TXD)/*!< Set PD12 function to UART4_TXD     */
#define SET_UART4_TXD_PE3()        SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE3MFP_Msk) | SYS_GPE_MFPL_PE3MFP_UART4_TXD)  /*!< Set PE3 function to UART4_TXD       */
#define SET_UART4_nCTS_PD15()      SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD15MFP_Msk) | SYS_GPD_MFPH_PD15MFP_UART4_nCTS)/*!< Set PD15 function to UART4_nCTS   */
#define SET_UART4_nCTS_PE0()       SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE0MFP_Msk) | SYS_GPE_MFPL_PE0MFP_UART4_nCTS) /*!< Set PE0 function to UART4_nCTS      */
#define SET_UART4_nRTS_PD14()      SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD14MFP_Msk) | SYS_GPD_MFPH_PD14MFP_UART4_nRTS)/*!< Set PD14 function to UART4_nRTS   */
#define SET_UART4_nRTS_PE1()       SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE1MFP_Msk) | SYS_GPE_MFPL_PE1MFP_UART4_nRTS) /*!< Set PE1 function to UART4_nRTS      */

/* UART5 */
#define SET_UART5_RXD_PD1()        SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD1MFP_Msk) | SYS_GPD_MFPL_PD1MFP_UART5_RXD) /*!< Set PD1 function to UART5_RXD        */
#define SET_UART5_RXD_PG6()        SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG6MFP_Msk) | SYS_GPG_MFPL_PG6MFP_UART5_RXD) /*!< Set PG6 function to UART5_RXD        */
#define SET_UART5_RXD_PG13()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG13MFP_Msk) | SYS_GPG_MFPH_PG13MFP_UART5_RXD)/*!< Set PG13 function to UART5_RXD     */
#define SET_UART5_TXD_PD0()        SYS->GPD_MFPL = ((SYS->GPD_MFPL & ~SYS_GPD_MFPL_PD0MFP_Msk) | SYS_GPD_MFPL_PD0MFP_UART5_TXD) /*!< Set PD0 function to UART5_TXD        */
#define SET_UART5_TXD_PG7()        SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG7MFP_Msk) | SYS_GPG_MFPL_PG7MFP_UART5_TXD) /*!< Set PG7 function to UART5_TXD        */
#define SET_UART5_TXD_PG14()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG14MFP_Msk) | SYS_GPG_MFPH_PG14MFP_UART5_TXD)/*!< Set PG14 function to UART5_TXD     */
#define SET_UART5_nCTS_PG3()       SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG3MFP_Msk) | SYS_GPG_MFPL_PG3MFP_UART5_nCTS)/*!< Set PG3 function to UART5_nCTS      */
#define SET_UART5_nCTS_PG4()       SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG4MFP_Msk) | SYS_GPG_MFPL_PG4MFP_UART5_nCTS)/*!< Set PG4 function to UART5_nCTS      */
#define SET_UART5_nCTS_PG11()      SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG11MFP_Msk) | SYS_GPG_MFPH_PG11MFP_UART5_nCTS)/*!< Set PG11 function to UART5_nCTS   */
#define SET_UART5_nRTS_PG5()       SYS->GPG_MFPL = ((SYS->GPG_MFPL & ~SYS_GPG_MFPL_PG5MFP_Msk) | SYS_GPG_MFPL_PG5MFP_UART5_nRTS)/*!< Set PG5 function to UART5_nRTS      */
#define SET_UART5_nRTS_PG12()      SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG12MFP_Msk) | SYS_GPG_MFPH_PG12MFP_UART5_nRTS)/*!< Set PG12 function to UART5_nRTS   */

/* UART6 */
#define SET_UART6_RXD_PA4()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA4MFP_Msk) | SYS_GPA_MFPL_PA4MFP_UART6_RXD)  /*!< Set PA4 function to UART6_RXD       */
#define SET_UART6_RXD_PD11()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD11MFP_Msk) | SYS_GPD_MFPH_PD11MFP_UART6_RXD)/*!< Set PD11 function to UART6_RXD     */
#define SET_UART6_RXD_PE8()        SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE8MFP_Msk) | SYS_GPE_MFPH_PE8MFP_UART6_RXD)  /*!< Set PE8 function to UART6_RXD       */
#define SET_UART6_TXD_PA5()        SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA5MFP_Msk) | SYS_GPA_MFPL_PA5MFP_UART6_TXD)  /*!< Set PA5 function to UART6_TXD       */
#define SET_UART6_TXD_PD10()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD10MFP_Msk) | SYS_GPD_MFPH_PD10MFP_UART6_TXD)/*!< Set PD10 function to UART6_TXD     */
#define SET_UART6_TXD_PE9()        SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE9MFP_Msk) | SYS_GPE_MFPH_PE9MFP_UART6_TXD)  /*!< Set PE9 function to UART6_TXD       */
#define SET_UART6_nCTS_PA2()       SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA2MFP_Msk) | SYS_GPA_MFPL_PA2MFP_UART6_nCTS)/*!< Set PA2 function to UART6_nCTS      */
#define SET_UART6_nCTS_PD8()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD8MFP_Msk) | SYS_GPD_MFPH_PD8MFP_UART6_nCTS)/*!< Set PD8 function to UART6_nCTS      */
#define SET_UART6_nCTS_PH8()       SYS->GPH_MFPH = ((SYS->GPH_MFPH & ~SYS_GPH_MFPH_PH8MFP_Msk) | SYS_GPH_MFPH_PH8MFP_UART6_nCTS)/*!< Set PH8 function to UART6_nCTS      */
#define SET_UART6_nRTS_PA3()       SYS->GPA_MFPL = ((SYS->GPA_MFPL & ~SYS_GPA_MFPL_PA3MFP_Msk) | SYS_GPA_MFPL_PA3MFP_UART6_nRTS)/*!< Set PA3 function to UART6_nRTS      */
#define SET_UART6_nRTS_PD9()       SYS->GPD_MFPH = ((SYS->GPD_MFPH & ~SYS_GPD_MFPH_PD9MFP_Msk) | SYS_GPD_MFPH_PD9MFP_UART6_nRTS)/*!< Set PD9 function to UART6_nRTS      */
#define SET_UART6_nRTS_PH9()       SYS->GPH_MFPH = ((SYS->GPH_MFPH & ~SYS_GPH_MFPH_PH9MFP_Msk) | SYS_GPH_MFPH_PH9MFP_UART6_nRTS)/*!< Set PH9 function to UART6_nRTS      */

/* UART7 */
#define SET_UART7_RXD_PA14()       SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA14MFP_Msk) | SYS_GPA_MFPH_PA14MFP_UART7_RXD)/*!< Set PA14 function to UART7_RXD     */
#define SET_UART7_RXD_PB4()        SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB4MFP_Msk) | SYS_GPB_MFPL_PB4MFP_UART7_RXD)  /*!< Set PB4 function to UART7_RXD       */
#define SET_UART7_RXD_PC2()        SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC2MFP_Msk) | SYS_GPC_MFPL_PC2MFP_UART7_RXD)  /*!< Set PC2 function to UART7_RXD       */
#define SET_UART7_RXD_PF2()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF2MFP_Msk) | SYS_GPF_MFPL_PF2MFP_UART7_RXD)  /*!< Set PF2 function to UART7_RXD       */
#define SET_UART7_TXD_PA13()       SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA13MFP_Msk) | SYS_GPA_MFPH_PA13MFP_UART7_TXD)/*!< Set PA13 function to UART7_TXD     */
#define SET_UART7_TXD_PB6()        SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB6MFP_Msk) | SYS_GPB_MFPL_PB6MFP_UART7_TXD)  /*!< Set PB6 function to UART7_TXD       */
#define SET_UART7_TXD_PC1()        SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC1MFP_Msk) | SYS_GPC_MFPL_PC1MFP_UART7_TXD)  /*!< Set PC1 function to UART7_TXD       */
#define SET_UART7_TXD_PF3()        SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF3MFP_Msk) | SYS_GPF_MFPL_PF3MFP_UART7_TXD)  /*!< Set PF3 function to UART7_TXD       */
#define SET_UART7_nCTS_PB7()       SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB7MFP_Msk) | SYS_GPB_MFPL_PB7MFP_UART7_nCTS) /*!< Set PB7 function to UART7_nCTS      */
#define SET_UART7_nCTS_PC5()       SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC5MFP_Msk) | SYS_GPC_MFPL_PC5MFP_UART7_nCTS) /*!< Set PC5 function to UART7_nCTS      */
#define SET_UART7_nCTS_PF0()       SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF0MFP_Msk) | SYS_GPF_MFPL_PF0MFP_UART7_nCTS) /*!< Set PF0 function to UART7_nCTS      */
#define SET_UART7_nRTS_PB5()       SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB5MFP_Msk) | SYS_GPB_MFPL_PB5MFP_UART7_nRTS) /*!< Set PB5 function to UART7_nRTS      */
#define SET_UART7_nRTS_PC11()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC11MFP_Msk) | SYS_GPC_MFPH_PC11MFP_UART7_nRTS)/*!< Set PC11 function to UART7_nRTS    */
#define SET_UART7_nRTS_PF1()       SYS->GPF_MFPL = ((SYS->GPF_MFPL & ~SYS_GPF_MFPL_PF1MFP_Msk) | SYS_GPF_MFPL_PF1MFP_UART7_nRTS) /*!< Set PF1 function to UART7_nRTS      */

/* UART8 */
#define SET_UART8_RXD_PA11()       SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA11MFP_Msk) | SYS_GPA_MFPH_PA11MFP_UART8_RXD)/*!< Set PA11 function to UART8_RXD     */
#define SET_UART8_RXD_PC0()        SYS->GPC_MFPL = ((SYS->GPC_MFPL & ~SYS_GPC_MFPL_PC0MFP_Msk) | SYS_GPC_MFPL_PC0MFP_UART8_RXD)  /*!< Set PC0 function to UART8_RXD       */
#define SET_UART8_RXD_PC13()       SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC13MFP_Msk) | SYS_GPC_MFPH_PC13MFP_UART8_RXD)/*!< Set PC13 function to UART8_RXD     */
#define SET_UART8_TXD_PA12()       SYS->GPA_MFPH = ((SYS->GPA_MFPH & ~SYS_GPA_MFPH_PA12MFP_Msk) | SYS_GPA_MFPH_PA12MFP_UART8_TXD)/*!< Set PA12 function to UART8_TXD     */
#define SET_UART8_TXD_PB8()        SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB8MFP_Msk) | SYS_GPB_MFPH_PB8MFP_UART8_TXD)  /*!< Set PB8 function to UART8_TXD       */
#define SET_UART8_TXD_PC12()       SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC12MFP_Msk) | SYS_GPC_MFPH_PC12MFP_UART8_TXD)/*!< Set PC12 function to UART8_TXD     */
#define SET_UART8_nCTS_PC15()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC15MFP_Msk) | SYS_GPC_MFPH_PC15MFP_UART8_nCTS)/*!< Set PC15 function to UART8_nCTS    */
#define SET_UART8_nCTS_PG9()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG9MFP_Msk) | SYS_GPG_MFPH_PG9MFP_UART8_nCTS) /*!< Set PG9 function to UART8_nCTS      */
#define SET_UART8_nCTS_PH4()       SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH4MFP_Msk) | SYS_GPH_MFPL_PH4MFP_UART8_nCTS) /*!< Set PH4 function to UART8_nCTS      */
#define SET_UART8_nRTS_PC14()      SYS->GPC_MFPH = ((SYS->GPC_MFPH & ~SYS_GPC_MFPH_PC14MFP_Msk) | SYS_GPC_MFPH_PC14MFP_UART8_nRTS)/*!< Set PC14 function to UART8_nRTS    */
#define SET_UART8_nRTS_PG8()       SYS->GPG_MFPH = ((SYS->GPG_MFPH & ~SYS_GPG_MFPH_PG8MFP_Msk) | SYS_GPG_MFPH_PG8MFP_UART8_nRTS) /*!< Set PG8 function to UART8_nRTS      */
#define SET_UART8_nRTS_PH5()       SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH5MFP_Msk) | SYS_GPH_MFPL_PH5MFP_UART8_nRTS) /*!< Set PH5 function to UART8_nRTS      */

/* UART9 */
#define SET_UART9_RXD_PB3()        SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB3MFP_Msk) | SYS_GPB_MFPL_PB3MFP_UART9_RXD)  /*!< Set PB3 function to UART9_RXD       */
#define SET_UART9_RXD_PE6()        SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE6MFP_Msk) | SYS_GPE_MFPL_PE6MFP_UART9_RXD)  /*!< Set PE6 function to UART9_RXD       */
#define SET_UART9_RXD_PE10()       SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE10MFP_Msk) | SYS_GPE_MFPH_PE10MFP_UART9_RXD)/*!< Set PE10 function to UART9_RXD     */
#define SET_UART9_RXD_PH5()        SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH5MFP_Msk) | SYS_GPH_MFPL_PH5MFP_UART9_RXD)  /*!< Set PH5 function to UART9_RXD       */
#define SET_UART9_TXD_PB1()        SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB1MFP_Msk) | SYS_GPB_MFPL_PB1MFP_UART9_TXD)  /*!< Set PB1 function to UART9_TXD       */
#define SET_UART9_TXD_PE7()        SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE7MFP_Msk) | SYS_GPE_MFPL_PE7MFP_UART9_TXD)  /*!< Set PE7 function to UART9_TXD       */
#define SET_UART9_TXD_PE12()       SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE12MFP_Msk) | SYS_GPE_MFPH_PE12MFP_UART9_TXD)/*!< Set PE12 function to UART9_TXD     */
#define SET_UART9_TXD_PH4()        SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH4MFP_Msk) | SYS_GPH_MFPL_PH4MFP_UART9_TXD)  /*!< Set PH4 function to UART9_TXD       */
#define SET_UART9_nCTS_PB8()       SYS->GPB_MFPH = ((SYS->GPB_MFPH & ~SYS_GPB_MFPH_PB8MFP_Msk) | SYS_GPB_MFPH_PB8MFP_UART9_nCTS) /*!< Set PB8 function to UART9_nCTS      */
#define SET_UART9_nCTS_PE4()       SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE4MFP_Msk) | SYS_GPE_MFPL_PE4MFP_UART9_nCTS) /*!< Set PE4 function to UART9_nCTS      */
#define SET_UART9_nCTS_PH7()       SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH7MFP_Msk) | SYS_GPH_MFPL_PH7MFP_UART9_nCTS) /*!< Set PH7 function to UART9_nCTS      */
#define SET_UART9_nRTS_PB2()       SYS->GPB_MFPL = ((SYS->GPB_MFPL & ~SYS_GPB_MFPL_PB2MFP_Msk) | SYS_GPB_MFPL_PB2MFP_UART9_nRTS) /*!< Set PB2 function to UART9_nRTS      */
#define SET_UART9_nRTS_PE5()       SYS->GPE_MFPL = ((SYS->GPE_MFPL & ~SYS_GPE_MFPL_PE5MFP_Msk) | SYS_GPE_MFPL_PE5MFP_UART9_nRTS) /*!< Set PE5 function to UART9_nRTS      */
#define SET_UART9_nRTS_PH6()       SYS->GPH_MFPL = ((SYS->GPH_MFPL & ~SYS_GPH_MFPL_PH6MFP_Msk) | SYS_GPH_MFPL_PH6MFP_UART9_nRTS) /*!< Set PH6 function to UART9_nRTS      */

/* USB */
#define SET_USB_OVC_PE10()         SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE10MFP_Msk) | SYS_GPE_MFPH_PE10MFP_USB_OVC) /*!< Set PE10 function to USB_OVC        */

/* USB0 */
#define SET_USB0_VBUSVLD_PE11()    SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE11MFP_Msk) | SYS_GPE_MFPH_PE11MFP_USB0_VBUSVLD)/*!< Set PE11 function to USB0_VBUSVLD  */

/* USBH */
#define SET_USBH_PWREN_PE12()      SYS->GPE_MFPH = ((SYS->GPE_MFPH & ~SYS_GPE_MFPH_PE12MFP_Msk) | SYS_GPE_MFPH_PE12MFP_USBH_PWREN)/*!< Set PE12 function to USBH_PWREN   */

/*---------------------------------------------------------------------------------------------------------*/
/* static inline functions                                                                                 */
/*---------------------------------------------------------------------------------------------------------*/

/* Declare these inline functions here to avoid MISRA C 2004 rule 8.1 error */
static __inline void SYS_UnlockReg(void);
static __inline void SYS_LockReg(void);
static __inline void Reset_SPI(void);

/**
  * @brief      Disable register write-protection function
  * @param      None
  * @return     None
  * @details    This function disable register write-protection function.
  *             To unlock the protected register to allow write access.
  */
static __inline void SYS_UnlockReg(void)
{
    do
    {
        SYS->REGLKCTL = 0x59UL;
        SYS->REGLKCTL = 0x16UL;
        SYS->REGLKCTL = 0x88UL;
    }
    while(SYS->REGLKCTL == 0UL);
}

/**
  * @brief      Enable register write-protection function
  * @param      None
  * @return     None
  * @details    This function is used to enable register write-protection function.
  *             To lock the protected register to forbid write access.
  */
static __inline void SYS_LockReg(void)
{
    SYS->REGLKCTL = 0UL;
}

// TODO .....
//Reset SPI0/1/2
static __inline void Reset_SPI(void)
{
    SYS->APBIPRST1 |= 0x00000070;
    SYS->APBIPRST1 &= (~0x00000070);
}

/* Define system library AIC functions */
BOOL  sysGetIBitState(void);
INT32 sysSetLocalInterrupt(INT32 nIntState);
INT32 sysDisableInterrupt(IRQn_Type eIntNo);
INT32 sysEnableInterrupt(IRQn_Type eIntNo);
INT32 sysGetInterruptEnableState(IRQn_Type eIntNo);
INT32 sysGetInterruptStatus(IRQn_Type eIntNo);
PVOID sysInstallExceptionHandler(INT32 nExceptType, PVOID pvNewHandler);
PVOID sysInstallFiqHandler(PVOID pvNewISR);
PVOID sysInstallIrqHandler(PVOID pvNewISR);
PVOID sysInstallISR(INT32 nIntTypeLevel, IRQn_Type eIntNo, PVOID pvNewISR);
INT32 sysSetGlobalInterrupt(INT32 nIntState);
INT32 sysSetInterruptPriorityLevel(IRQn_Type eIntNo, UINT32 uIntLevel);

#ifdef _POWER_MANAGEMENT_
void sysEnterPowerDown(void);
void sysEnterIdle(void);
#endif

void sysResetModule(uint32_t u32ModuleIndex);

/* Define system library Cache functions */
void    sysDisableCache(void);
INT32   sysEnableCache(UINT32 uCacheOpMode);
void    sysFlushCache(INT32 nCacheType);
BOOL    sysGetCacheState(void);
INT32   sysGetSdramSizebyMB(void);
void    sysInvalidCache(void);

INT32 sysGetPLL(UINT32 reg);
UINT32 sysGetClock(CLK_Type clk);

void sysCleanInvalidatedDcache(UINT32 buffer, UINT32 size);
void sysCleanDcache(UINT32 buffer, UINT32 size);
void sysInvalidateDcache(UINT32 buffer, UINT32 size);
void sysInvalidateDcacheAll(void);

int kbhit(void);
int recvchar(void);
int sysGetChar(void);
int sendchar(int ch);

typedef void (*sys_pvFunPtr)();   /* function pointer */

extern sys_pvFunPtr IrqHandlerTable[];
extern sys_pvFunPtr FiqHandlerTable[];
extern UINT32 volatile _sys_bIsAICInitial;

#if defined ( __GNUC__ ) && !(__CC_ARM)
void __wfi(void);
#else
__asm void __wfi(void);
#endif


#ifdef __cplusplus
}
#endif

/*@}*/ /* end of group SYS_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group SYS_Driver */

/*@}*/ /* end of group Standard_Driver */

#endif //__SYS_H__

/*** (C) COPYRIGHT 2025 Nuvoton Technology Corp. ***/
