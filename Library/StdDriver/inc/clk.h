/**************************************************************************//**
 * @file     clk.h
 * @brief    CLK Driver Header File
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#ifndef __CLK_H__
#define __CLK_H__

#ifdef __cplusplus
extern "C"
{
#endif


/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup CLK_Driver CLK Driver
  @{
*/

/** @addtogroup CLK_EXPORTED_CONSTANTS CLK Exported Constants
  @{
*/


//#define FREQ_180MHZ        180000000UL  /*!< 180  MHz \hideinitializer */

//#define CAPLL    (0x0UL)
//#define SYSPLL   (0x1UL)
//#define DDRPLL   (0x2UL)
//#define APLL     (0x3UL)
//#define EPLL     (0x4UL)
//#define VPLL     (0x5UL)

/** \brief  Structure type of clock source
 */
typedef enum CLOCKn
{
    CLK_UPLL     = 1,   /*!< UPLL clock */
    CLK_APLL     = 2,   /*!< APLL clock */
    CLK_SYSTEM   = 3,   /*!< System clock */
    CLK_HCLK     = 4,   /*!< HCLK clock */
    CLK_HCLK1    = 5,   /*!< HCLK1 clock */
    CLK_PCLK0    = 6,   /*!< PCLK0 clock */
    CLK_PCLK1    = 7,   /*!< PCLK1 clock */
    CLK_PCLK2    = 8,   /*!< PCLK2 clock */
    CLK_CPU      = 9,   /*!< CPU clock */
} CLOCK_Type;

typedef enum REQn
{
	STR_CANFD0 = 1,
	STR_CANFD1 = 2,
	STR_CANFD2 = 3,
	STR_CANFD3 = 4,
} CLK_Stop;

/*---------------------------------------------------------------------------------------------------------*/
/*  DIVCTL0 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_DIV0_SYSCKSEL_HXT              (0x0UL << CLK_DIVCTL0_SYSTEM_S_Pos)
#define CLK_DIV0_SYSCKSEL_APLL             (0x2UL << CLK_DIVCTL0_SYSTEM_S_Pos)
#define CLK_DIV0_SYSCKSEL_UPLL             (0x3UL << CLK_DIVCTL0_SYSTEM_S_Pos)

#define CLK_DIV0_PCLK3SEL_HXT              (0x0UL << CLK_DIVCTL0_PCLK3_S_Pos)
#define CLK_DIV0_PCLK3SEL_HCLK             (0x1UL << CLK_DIVCTL0_PCLK3_S_Pos)
#define CLK_DIV0_PCLK3SEL_APLL             (0x2UL << CLK_DIVCTL0_PCLK3_S_Pos)
#define CLK_DIV0_PCLK3SEL_UPLL             (0x3UL << CLK_DIVCTL0_PCLK3_S_Pos)

#define CLK_DIV0_CPUDIV2(x)                (((x) - 1UL) << CLK_DIVCTL0_CPUDIV2EN_Pos)  /*!< DIVCTL0 Setting for CPU clock divided by 2. It could be 1~2 \hideinitializer */
#define CLK_DIV0_PCLK3(x)                  (((x) - 1UL) << CLK_DIVCTL0_PCLK3DIV_Pos)   /*!< DIVCTL0 Setting for PCLK3 clock divider. It could be 1~7 \hideinitializer */

/*---------------------------------------------------------------------------------------------------------*/
/*  DIVCTL1 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_DIV1_I2SSEL_HXT                (0x0UL << CLK_DIVCTL1_I2S_S_Pos)
#define CLK_DIV1_I2SSEL_APLL               (0x2UL << CLK_DIVCTL1_I2S_S_Pos)
#define CLK_DIV1_I2SSEL_UPLL               (0x3UL << CLK_DIVCTL1_I2S_S_Pos)

#define CLK_DIV1_I2S(x)                    (((x) - 1UL) << CLK_DIVCTL1_I2S_N_Pos)

/*---------------------------------------------------------------------------------------------------------*/
/*  DIVCTL2 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_DIV2_CANFD0SEL_APLL            (0x0UL << CLK_DIVCTL2_CANFD0_S_Pos)
#define CLK_DIV2_CANFD0SEL_UPLL            (0x1UL << CLK_DIVCTL2_CANFD0_S_Pos)
#define CLK_DIV2_CANFD1SEL_APLL            (0x0UL << CLK_DIVCTL2_CANFD1_S_Pos)
#define CLK_DIV2_CANFD1SEL_UPLL            (0x1UL << CLK_DIVCTL2_CANFD1_S_Pos)
#define CLK_DIV2_CANFD2SEL_APLL            (0x0UL << CLK_DIVCTL2_CANFD2_S_Pos)
#define CLK_DIV2_CANFD2SEL_UPLL            (0x1UL << CLK_DIVCTL2_CANFD2_S_Pos)
#define CLK_DIV2_CANFD3SEL_APLL            (0x0UL << CLK_DIVCTL2_CANFD3_S_Pos)
#define CLK_DIV2_CANFD3SEL_UPLL            (0x1UL << CLK_DIVCTL2_CANFD3_S_Pos)
//#define CLK_DIV2_USBHSEL_PHY0              (0x0UL << CLK_DIVCTL2_USBH_S_Pos)
//#define CLK_DIV2_USBHSEL_PHY1              (0x1UL << CLK_DIVCTL2_USBH_S_Pos)
#define CLK_DIV2_QSPI0SEL_HXT              (0x0UL << CLK_DIVCTL2_QSPI0_S_Pos)
#define CLK_DIV2_QSPI0SEL_PCLK0            (0x1UL << CLK_DIVCTL2_QSPI0_S_Pos)
#define CLK_DIV2_QSPI0SEL_APLL             (0x2UL << CLK_DIVCTL2_QSPI0_S_Pos)
#define CLK_DIV2_QSPI0SEL_UPLL             (0x3UL << CLK_DIVCTL2_QSPI0_S_Pos)
#define CLK_DIV2_SPI0SEL_HXT               (0x0UL << CLK_DIVCTL2_SPI0_S_Pos)
#define CLK_DIV2_SPI0SEL_PCLK0             (0x1UL << CLK_DIVCTL2_SPI0_S_Pos)
#define CLK_DIV2_SPI0SEL_APLL              (0x2UL << CLK_DIVCTL2_SPI0_S_Pos)
#define CLK_DIV2_SPI0SEL_UPLL              (0x3UL << CLK_DIVCTL2_SPI0_S_Pos)
#define CLK_DIV2_SPI1SEL_HXT               (0x0UL << CLK_DIVCTL2_SPI1_S_Pos)
#define CLK_DIV2_SPI1SEL_PCLK1             (0x1UL << CLK_DIVCTL2_SPI1_S_Pos)
#define CLK_DIV2_SPI1SEL_APLL              (0x2UL << CLK_DIVCTL2_SPI1_S_Pos)
#define CLK_DIV2_SPI1SEL_UPLL              (0x3UL << CLK_DIVCTL2_SPI1_S_Pos)
#define CLK_DIV2_SPI2SEL_HXT               (0x0UL << CLK_DIVCTL2_SPI2_S_Pos)
#define CLK_DIV2_SPI2SEL_PCLK0             (0x1UL << CLK_DIVCTL2_SPI2_S_Pos)
#define CLK_DIV2_SPI2SEL_APLL              (0x2UL << CLK_DIVCTL2_SPI2_S_Pos)
#define CLK_DIV2_SPI2SEL_UPLL              (0x3UL << CLK_DIVCTL2_SPI2_S_Pos)
#define CLK_DIV2_SPI3SEL_HXT               (0x0UL << CLK_DIVCTL2_SPI3_S_Pos)
#define CLK_DIV2_SPI3SEL_PCLK1             (0x1UL << CLK_DIVCTL2_SPI3_S_Pos)
#define CLK_DIV2_SPI3SEL_APLL              (0x2UL << CLK_DIVCTL2_SPI3_S_Pos)
#define CLK_DIV2_SPI3SEL_UPLL              (0x3UL << CLK_DIVCTL2_SPI3_S_Pos)
//#define CLK_DIV2_BPWM0SEL_HXT              (0x0UL << CLK_DIVCTL2_BPWM0_S_Pos)
//#define CLK_DIV2_BPWM0SEL_PCLK0            (0x1UL << CLK_DIVCTL2_BPWM0_S_Pos)
//#define CLK_DIV2_BPWM0SEL_HCLK             (0x2UL << CLK_DIVCTL2_BPWM0_S_Pos)
//#define CLK_DIV2_BPWM1SEL_HXT              (0x0UL << CLK_DIVCTL2_BPWM1_S_Pos)
//#define CLK_DIV2_BPWM1SEL_PCLK1            (0x1UL << CLK_DIVCTL2_BPWM1_S_Pos)
//#define CLK_DIV2_BPWM1SEL_HCLK             (0x2UL << CLK_DIVCTL2_BPWM1_S_Pos)

/*---------------------------------------------------------------------------------------------------------*/
/*  DIVCTL3 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_DIV3_SD0SEL_HXT                (0x0UL << CLK_DIVCTL3_SD0_S_Pos)
#define CLK_DIV3_SD0SEL_APLL               (0x2UL << CLK_DIVCTL3_SD0_S_Pos)
#define CLK_DIV3_SD0SEL_UPLL               (0x3UL << CLK_DIVCTL3_SD0_S_Pos)
#define CLK_DIV3_SD1SEL_HXT                (0x0UL << CLK_DIVCTL3_SD1_S_Pos)
#define CLK_DIV3_SD1SEL_APLL               (0x2UL << CLK_DIVCTL3_SD1_S_Pos)
#define CLK_DIV3_SD1SEL_UPLL               (0x3UL << CLK_DIVCTL3_SD1_S_Pos)

#define CLK_DIV3_SD0(x)                    (((x) - 1UL) << CLK_DIVCTL3_SD0_N_Pos)
#define CLK_DIV3_SD1(x)                    (((x) - 1UL) << CLK_DIVCTL3_SD1_N_Pos)

/*---------------------------------------------------------------------------------------------------------*/
/*  DIVCTL4 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_DIV4_UART0SEL_HXT              (0x0UL << CLK_DIVCTL4_UART0_S_Pos)
#define CLK_DIV4_UART0SEL_LXT              (0x1UL << CLK_DIVCTL4_UART0_S_Pos)
#define CLK_DIV4_UART0SEL_APLL             (0x2UL << CLK_DIVCTL4_UART0_S_Pos)
#define CLK_DIV4_UART0SEL_UPLL             (0x3UL << CLK_DIVCTL4_UART0_S_Pos)
#define CLK_DIV4_UART1SEL_HXT              (0x0UL << CLK_DIVCTL4_UART1_S_Pos)
#define CLK_DIV4_UART1SEL_LXT              (0x1UL << CLK_DIVCTL4_UART1_S_Pos)
#define CLK_DIV4_UART1SEL_APLL             (0x2UL << CLK_DIVCTL4_UART1_S_Pos)
#define CLK_DIV4_UART1SEL_UPLL             (0x3UL << CLK_DIVCTL4_UART1_S_Pos)
#define CLK_DIV4_UART2SEL_HXT              (0x0UL << CLK_DIVCTL4_UART2_S_Pos)
#define CLK_DIV4_UART2SEL_LXT              (0x1UL << CLK_DIVCTL4_UART2_S_Pos)
#define CLK_DIV4_UART2SEL_APLL             (0x2UL << CLK_DIVCTL4_UART2_S_Pos)
#define CLK_DIV4_UART2SEL_UPLL             (0x3UL << CLK_DIVCTL4_UART2_S_Pos)
#define CLK_DIV4_UART3SEL_HXT              (0x0UL << CLK_DIVCTL4_UART3_S_Pos)
#define CLK_DIV4_UART3SEL_LXT              (0x1UL << CLK_DIVCTL4_UART3_S_Pos)
#define CLK_DIV4_UART3SEL_APLL             (0x2UL << CLK_DIVCTL4_UART3_S_Pos)
#define CLK_DIV4_UART3SEL_UPLL             (0x3UL << CLK_DIVCTL4_UART3_S_Pos)

#define CLK_DIV4_UART0(x)                  (((x) - 1UL) << CLK_DIVCTL4_UART0_N_Pos)
#define CLK_DIV4_UART1(x)                  (((x) - 1UL) << CLK_DIVCTL4_UART1_N_Pos)
#define CLK_DIV4_UART2(x)                  (((x) - 1UL) << CLK_DIVCTL4_UART2_N_Pos)
#define CLK_DIV4_UART3(x)                  (((x) - 1UL) << CLK_DIVCTL4_UART3_N_Pos)

/*---------------------------------------------------------------------------------------------------------*/
/*  DIVCTL5 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_DIV5_UART4SEL_HXT              (0x0UL << CLK_DIVCTL5_UART4_S_Pos)
#define CLK_DIV5_UART4SEL_LXT              (0x1UL << CLK_DIVCTL5_UART4_S_Pos)
#define CLK_DIV5_UART4SEL_APLL             (0x2UL << CLK_DIVCTL5_UART4_S_Pos)
#define CLK_DIV5_UART4SEL_UPLL             (0x3UL << CLK_DIVCTL5_UART4_S_Pos)
#define CLK_DIV5_UART5SEL_HXT              (0x0UL << CLK_DIVCTL5_UART5_S_Pos)
#define CLK_DIV5_UART5SEL_LXT              (0x1UL << CLK_DIVCTL5_UART5_S_Pos)
#define CLK_DIV5_UART5SEL_APLL             (0x2UL << CLK_DIVCTL5_UART5_S_Pos)
#define CLK_DIV5_UART5SEL_UPLL             (0x3UL << CLK_DIVCTL5_UART5_S_Pos)
#define CLK_DIV5_UART6SEL_HXT              (0x0UL << CLK_DIVCTL5_UART6_S_Pos)
#define CLK_DIV5_UART6SEL_LXT              (0x1UL << CLK_DIVCTL5_UART6_S_Pos)
#define CLK_DIV5_UART6SEL_APLL             (0x2UL << CLK_DIVCTL5_UART6_S_Pos)
#define CLK_DIV5_UART6SEL_UPLL             (0x3UL << CLK_DIVCTL5_UART6_S_Pos)
#define CLK_DIV5_UART7SEL_HXT              (0x0UL << CLK_DIVCTL5_UART7_S_Pos)
#define CLK_DIV5_UART7SEL_LXT              (0x1UL << CLK_DIVCTL5_UART7_S_Pos)
#define CLK_DIV5_UART7SEL_APLL             (0x2UL << CLK_DIVCTL5_UART7_S_Pos)
#define CLK_DIV5_UART7SEL_UPLL             (0x3UL << CLK_DIVCTL5_UART7_S_Pos)

#define CLK_DIV5_UART4(x)                  (((x) - 1UL) << CLK_DIVCTL5_UART4_N_Pos)
#define CLK_DIV5_UART5(x)                  (((x) - 1UL) << CLK_DIVCTL5_UART5_N_Pos)
#define CLK_DIV5_UART6(x)                  (((x) - 1UL) << CLK_DIVCTL5_UART6_N_Pos)
#define CLK_DIV5_UART7(x)                  (((x) - 1UL) << CLK_DIVCTL5_UART7_N_Pos)

/*---------------------------------------------------------------------------------------------------------*/
/*  DIVCTL6 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_DIV6_UART8SEL_HXT              (0x0UL << CLK_DIVCTL6_UART8_S_Pos)
#define CLK_DIV6_UART8SEL_LXT              (0x1UL << CLK_DIVCTL6_UART8_S_Pos)
#define CLK_DIV6_UART8SEL_APLL             (0x2UL << CLK_DIVCTL6_UART8_S_Pos)
#define CLK_DIV6_UART8SEL_UPLL             (0x3UL << CLK_DIVCTL6_UART8_S_Pos)
#define CLK_DIV6_UART9SEL_HXT              (0x0UL << CLK_DIVCTL6_UART9_S_Pos)
#define CLK_DIV6_UART9SEL_LXT              (0x1UL << CLK_DIVCTL6_UART9_S_Pos)
#define CLK_DIV6_UART9SEL_APLL             (0x2UL << CLK_DIVCTL6_UART9_S_Pos)
#define CLK_DIV6_UART9SEL_UPLL             (0x3UL << CLK_DIVCTL6_UART9_S_Pos)

#define CLK_DIV6_UART8(x)                  (((x) - 1UL) << CLK_DIVCTL6_UART8_N_Pos)
#define CLK_DIV6_UART9(x)                  (((x) - 1UL) << CLK_DIVCTL6_UART9_N_Pos)
#define CLK_DIV6_SMC0(x)                   (((x) - 1UL) << CLK_DIVCTL6_SMC0_N_Pos)
#define CLK_DIV6_SMC1(x)                   (((x) - 1UL) << CLK_DIVCTL6_SMC1_N_Pos)

/*---------------------------------------------------------------------------------------------------------*/
/*  DIVCTL7 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_DIV7_ADCSEL_HXT                (0x0UL << CLK_DIVCTL7_ADC_S_Pos)
#define CLK_DIV7_ADCSEL_APLL               (0x2UL << CLK_DIVCTL7_ADC_S_Pos)
#define CLK_DIV7_ADCSEL_UPLL               (0x3UL << CLK_DIVCTL7_ADC_S_Pos)

#define CLK_DIV7_CANFD0(x)                 (((x) - 1UL) << CLK_DIVCTL7_CANFD0_N_Pos)
#define CLK_DIV7_CANFD1(x)                 (((x) - 1UL) << CLK_DIVCTL7_CANFD1_N_Pos)
#define CLK_DIV7_CANFD2(x)                 (((x) - 1UL) << CLK_DIVCTL7_CANFD2_N_Pos)
#define CLK_DIV7_CANFD3(x)                 (((x) - 1UL) << CLK_DIVCTL7_CANFD3_N_Pos)
#define CLK_DIV7_EADC(x)                   (((x) - 1UL) << CLK_DIVCTL7_EADC_N_Pos)
#define CLK_DIV7_ADC(x)                    (((x) - 1UL) << CLK_DIVCTL7_ADC_N_Pos)

/*---------------------------------------------------------------------------------------------------------*/
/*  DIVCTL8 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_DIV8_WDTSEL_HXT                (0x0UL << CLK_DIVCTL8_WDTSEL_Pos)
#define CLK_DIV8_WDTSEL_HXT_DIV512         (0x1UL << CLK_DIVCTL8_WDTSEL_Pos)
#define CLK_DIV8_WDTSEL_PLCK2_DIV4096      (0x2UL << CLK_DIVCTL8_WDTSEL_Pos)
#define CLK_DIV8_WDTSEL_LXT                (0x3UL << CLK_DIVCTL8_WDTSEL_Pos)

#define CLK_DIV8_WWDTSEL_HXT               (0x0UL << CLK_DIVCTL8_WWDTSEL_Pos)
#define CLK_DIV8_WWDTSEL_HXT_DIV512        (0x1UL << CLK_DIVCTL8_WWDTSEL_Pos)
#define CLK_DIV8_WWDTSEL_PLCK2_DIV4096     (0x2UL << CLK_DIVCTL8_WWDTSEL_Pos)
#define CLK_DIV8_WWDTSEL_LXT               (0x3UL << CLK_DIVCTL8_WWDTSEL_Pos)

#define CLK_DIV8_TMR0SEL_HXT               (0x0UL << CLK_DIVCTL8_TMR0SEL_Pos)
#define CLK_DIV8_TMR0SEL_PCLK0             (0x1UL << CLK_DIVCTL8_TMR0SEL_Pos)
#define CLK_DIV8_TMR0SEL_PCLK0_DIV4096     (0x2UL << CLK_DIVCTL8_TMR0SEL_Pos)
#define CLK_DIV8_TMR0SEL_LXT               (0x3UL << CLK_DIVCTL8_TMR0SEL_Pos)
#define CLK_DIV8_TMR1SEL_HXT               (0x0UL << CLK_DIVCTL8_TMR1SEL_Pos)
#define CLK_DIV8_TMR1SEL_PCLK0             (0x1UL << CLK_DIVCTL8_TMR1SEL_Pos)
#define CLK_DIV8_TMR1SEL_PCLK0_DIV4096     (0x2UL << CLK_DIVCTL8_TMR1SEL_Pos)
#define CLK_DIV8_TMR1SEL_LXT               (0x3UL << CLK_DIVCTL8_TMR1SEL_Pos)
#define CLK_DIV8_TMR2SEL_HXT               (0x0UL << CLK_DIVCTL8_TMR2SEL_Pos)
#define CLK_DIV8_TMR2SEL_PCLK1             (0x1UL << CLK_DIVCTL8_TMR2SEL_Pos)
#define CLK_DIV8_TMR2SEL_PCLK1_DIV4096     (0x2UL << CLK_DIVCTL8_TMR2SEL_Pos)
#define CLK_DIV8_TMR2SEL_LXT               (0x3UL << CLK_DIVCTL8_TMR2SEL_Pos)
#define CLK_DIV8_TMR3SEL_HXT               (0x0UL << CLK_DIVCTL8_TMR3SEL_Pos)
#define CLK_DIV8_TMR3SEL_PCLK1             (0x1UL << CLK_DIVCTL8_TMR3SEL_Pos)
#define CLK_DIV8_TMR3SEL_PCLK1_DIV4096     (0x2UL << CLK_DIVCTL8_TMR3SEL_Pos)
#define CLK_DIV8_TMR3SEL_LXT               (0x3UL << CLK_DIVCTL8_TMR3SEL_Pos)
#define CLK_DIV8_TMR4SEL_HXT               (0x0UL << CLK_DIVCTL8_TMR4SEL_Pos)
#define CLK_DIV8_TMR4SEL_PCLK0             (0x1UL << CLK_DIVCTL8_TMR4SEL_Pos)
#define CLK_DIV8_TMR4SEL_PCLK0_DIV4096     (0x2UL << CLK_DIVCTL8_TMR4SEL_Pos)
#define CLK_DIV8_TMR4SEL_LXT               (0x3UL << CLK_DIVCTL8_TMR4SEL_Pos)
#define CLK_DIV8_TMR5SEL_HXT               (0x0UL << CLK_DIVCTL8_TMR5SEL_Pos)
#define CLK_DIV8_TMR5SEL_PCLK0             (0x1UL << CLK_DIVCTL8_TMR5SEL_Pos)
#define CLK_DIV8_TMR5SEL_PCLK0_DIV4096     (0x2UL << CLK_DIVCTL8_TMR5SEL_Pos)
#define CLK_DIV8_TMR5SEL_LXT               (0x3UL << CLK_DIVCTL8_TMR5SEL_Pos)

#define CLK_DIV8_MII(x)                    (((x) - 1UL) << CLK_DIVCTL8_MDCLKDIV_Pos)

/*---------------------------------------------------------------------------------------------------------*/
/*  DIVCTL9 constant definitions.                                                                          */
/*---------------------------------------------------------------------------------------------------------*/
#define CLK_DIV9_CLKOSEL_HXT               (0x0UL << CLK_DIVCTL9_CLKO_S_Pos)
#define CLK_DIV9_CLKOSEL_LXT               (0x1UL << CLK_DIVCTL9_CLKO_S_Pos)
#define CLK_DIV9_CLKOSEL_APLL              (0x2UL << CLK_DIVCTL9_CLKO_S_Pos)
#define CLK_DIV9_CLKOSEL_UPLL              (0x3UL << CLK_DIVCTL9_CLKO_S_Pos)

#define CLK_DIV9_CLKO(x)                   (((x) - 1UL) << CLK_DIVCTL9_CLKO_N_Pos)

/*---------------------------------------------------------------------------------------------------------*/
/*  MODULE constant combination definitions.                                                               */
/*---------------------------------------------------------------------------------------------------------*/
#define MODULE_HCLKEN0    (0x0UL)
#define MODULE_HCLKEN1    (0x1UL)
#define MODULE_PCLKEN0    (0x2UL)
#define MODULE_PCLKEN1    (0x3UL)

/* APBCLK(31:29) | CLKSEL(28:25) | CLKSEL_Msk(24:22) | CLKSEL_Pos(21:17) | CLKDIV(16:13) | CLKDIV_Msk(12:10) | CLKDIV_Pos(9:5) | IP_EN_Pos(4:0) */
/*      3-bit          4-bit              3-bit               5-bit            4-bit             3-bit                5-bit           5-bit     */
/*               |_______________________________________________________|_____________________________________________________|                */

/*
    APBCLK(31:29)  : sum of HCLKENx and PCLKENx, should be 0 ~ 3
    IP_EN_Pos(4:0) : position of IP clock enable bit, should be 0 ~ 31

    CLKSEL(28:25)     : number of DIVCTLx, should be 0 ~ 9
    CLKSEL_Msk(24:22) : number of clock source selection control bits, should be 1 ~ 7
    CLKSEL_Pos(21:17) : position of clock source selection control field, should be 0 ~ 31

    CLKDIV(16:13)     : number of DIVCTLx, should be 0 ~ 9
    CLKDIV_Msk(12:10) : number of clock divider control bits, should be 1 ~ 7
                        (Note: Value 8 is a special case that needs additional processing, but it is still 7 in order to comply with the definition here.)
    CLKDIV_Pos(9:5)   : position of clock divider control field, should be 0 ~ 31
*/

#define MODULE_APBCLK(x)            (((x) >>29) & 0x7UL)    /*!< Calculate SYSCLK/APBCLK offset on MODULE index, 0x0:SYSCLK0, 0x1:SYSCLK1, 0x2:APBCLK0, 0x3:APBCLK1, 0x4:APBCLK2 \hideinitializer */
#define MODULE_CLKSEL(x)            (((x) >>25) & 0xfUL)    /*!< Calculate CLKSEL offset on MODULE index, 0x0:CLKSEL0, 0x1:CLKSEL1, 0x2:CLKSEL2, 0x3:CLKSEL3, 0x4:CLKSEL4 \hideinitializer */
#define MODULE_CLKSEL_Msk(x)        (((x) >>22) & 0x7UL)    /*!< Calculate CLKSEL mask offset on MODULE index \hideinitializer */
#define MODULE_CLKSEL_Pos(x)        (((x) >>17) & 0x1fUL)   /*!< Calculate CLKSEL position offset on MODULE index \hideinitializer */
#define MODULE_CLKDIV(x)            (((x) >>13) & 0xfUL)    /*!< Calculate APBCLK CLKDIV on MODULE index, 0x0:CLKDIV0, 0x1:CLKDIV1, 0x2:CLKDIV2, 0x3:CLKDIV3, 0x4:CLKDIV4 \hideinitializer */
#define MODULE_CLKDIV_Msk(x)        (((x) >>10) & 0x7UL)    /*!< Calculate CLKDIV mask offset on MODULE index \hideinitializer */
#define MODULE_CLKDIV_Pos(x)        (((x) >>5 ) & 0x1fUL)   /*!< Calculate CLKDIV position offset on MODULE index \hideinitializer */
#define MODULE_IP_EN_Pos(x)         (((x) >>0 ) & 0x1fUL)   /*!< Calculate APBCLK offset on MODULE index \hideinitializer */
#define MODULE_NoMsk                0x0UL                   /*!< Not mask on MODULE index \hideinitializer */
#define NA                          MODULE_NoMsk            /*!< Not Available \hideinitializer */

#define MODULE_APBCLK_ENC(x)        (((x) & 0x07UL) << 29)  /*!< MODULE index, 0x0:SYSCLK0, 0x1:SYSCLK1, 0x2:APBCLK0, 0x3:APBCLK1, 0x4:APBCLK2 \hideinitializer */
#define MODULE_CLKSEL_ENC(x)        (((x) & 0x0fUL) << 25)  /*!< CLKSEL offset on MODULE index, 0x0:CLKSEL0, 0x1:CLKSEL1, 0x2:CLKSEL2, 0x3:CLKSEL3, 0x4:CLKSEL4 \hideinitializer */
#define MODULE_CLKSEL_Msk_ENC(x)    (((x) & 0x07UL) << 22)  /*!< CLKSEL mask offset on MODULE index \hideinitializer */
#define MODULE_CLKSEL_Pos_ENC(x)    (((x) & 0x1fUL) << 17)  /*!< CLKSEL position offset on MODULE index \hideinitializer */
#define MODULE_CLKDIV_ENC(x)        (((x) & 0x0fUL) << 13)  /*!< APBCLK CLKDIV on MODULE index, 0x0:CLKDIV0, 0x1:CLKDIV1, 0x2:CLKDIV2, 0x3:CLKDIV3, 0x4:CLKDIV4 \hideinitializer */
#define MODULE_CLKDIV_Msk_ENC(x)    (((x) & 0x07UL) << 10)  /*!< CLKDIV mask offset on MODULE index \hideinitializer */
#define MODULE_CLKDIV_Pos_ENC(x)    (((x) & 0x1fUL) << 5 )  /*!< CLKDIV position offset on MODULE index \hideinitializer */
#define MODULE_IP_EN_Pos_ENC(x)     (((x) & 0x1fUL) << 0 )  /*!< AHBCLK/APBCLK offset on MODULE index \hideinitializer */

#define SYS_MODULE       ((MODULE_NoMsk<<29)  |(0UL<<25)         |(2UL<<22)         |(3UL<<17)         |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(MODULE_NoMsk<<0))
#define MII_MODULE       ((MODULE_NoMsk<<29)  |(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(8UL<<13)         |(7UL<<10)         |(0UL<<5)         |(MODULE_NoMsk<<0))

/* HCLKEN0 */
#define CPU_MODULE       ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(0UL<<13)         |(1UL<<10)         |(8UL<<5)         |(0UL<<0))
#define HCLK_MODULE      ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(1UL<<0))
#define HCLK1_MODULE     ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(2UL<<0))
#define CLKO_MODULE      ((MODULE_HCLKEN0<<29)|(9UL<<25)         |(2UL<<22)         |(19UL<<17)        |(9UL<<13)         |(7UL<<10)         |(24UL<<5)        |(6UL<<0))

#define SRAM_MODULE      ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(8UL<<0))
#define EBI_MODULE       ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(9UL<<0))
#define SDIC_MODULE      ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(10UL<<0))
#define GPIO_MODULE      ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(11UL<<0))
#define PCLK0_MODULE     ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(12UL<<0))
#define PCLK1_MODULE     ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(13UL<<0))
#define PCLK2_MODULE     ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(14UL<<0))
#define PCLK3_MODULE     ((MODULE_HCLKEN0<<29)|(0UL<<25)         |(2UL<<22)         |(19UL<<17)        |(0UL<<13)         |(3UL<<10)         |(16UL<<5)        |(15UL<<0))

#define PDMA0_MODULE     ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(16UL<<0))
#define PDMA1_MODULE     ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(17UL<<0))
#define EMAC0_MODULE     ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(18UL<<0))
#define EMAC1_MODULE     ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(19UL<<0))
#define FMI_MODULE       ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(20UL<<0))
#define NAND_MODULE      ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(21UL<<0))
#define SDH0_MODULE      ((MODULE_HCLKEN0<<29)|(3UL<<25)         |(2UL<<22)         |(3UL<<17)         |(3UL<<13)         |(7UL<<10)         |(5UL<<5)         |(22UL<<0))
#define SDH1_MODULE      ((MODULE_HCLKEN0<<29)|(3UL<<25)         |(2UL<<22)         |(19UL<<17)        |(3UL<<13)         |(7UL<<10)         |(21UL<<5)        |(23UL<<0))

#define USBH_MODULE      ((MODULE_HCLKEN0<<29)|(2UL<<25)         |(1UL<<22)         |(4UL<<17)         |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(24UL<<0))
#define USBD_MODULE      ((MODULE_HCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(25UL<<0))

/* HCLKEN1 */
#define I2S_MODULE       ((MODULE_HCLKEN1<<29)|(1UL<<25)         |(2UL<<22)         |(19UL<<17)        |(1UL<<13)         |(7UL<<10)         |(24UL<<5)        |(0UL<<0))
#define CRPT_MODULE      ((MODULE_HCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(1UL<<0))
#define KS_MODULE        ((MODULE_HCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(2UL<<0))
#define OPT_MODULE       ((MODULE_HCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(3UL<<0))
#define IBR_MODULE       ((MODULE_HCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(4UL<<0))

#define CANFD0_MODULE    ((MODULE_HCLKEN1<<29)|(2UL<<25)         |(1UL<<22)         |(0UL<<17)         |(7UL<<13)         |(4UL<<10)         |(0UL<<5)         |(8UL<<0))
#define CANFD1_MODULE    ((MODULE_HCLKEN1<<29)|(2UL<<25)         |(1UL<<22)         |(1UL<<17)         |(7UL<<13)         |(4UL<<10)         |(4UL<<5)         |(9UL<<0))
#define CANFD2_MODULE    ((MODULE_HCLKEN1<<29)|(2UL<<25)         |(1UL<<22)         |(2UL<<17)         |(7UL<<13)         |(4UL<<10)         |(8UL<<5)         |(10UL<<0))
#define CANFD3_MODULE    ((MODULE_HCLKEN1<<29)|(2UL<<25)         |(1UL<<22)         |(3UL<<17)         |(7UL<<13)         |(4UL<<10)         |(12UL<<5)        |(11UL<<0))

/* PCLKEN0 */
#define WDT_MODULE       ((MODULE_PCLKEN0<<29)|(8UL<<25)         |(2UL<<22)         |(8UL<<17)         |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(0UL<<0))
#define WWDT_MODULE      ((MODULE_PCLKEN0<<29)|(8UL<<25)         |(2UL<<22)         |(10UL<<17)        |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(1UL<<0))
#define RTC_MODULE       ((MODULE_PCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(2UL<<0))
#define AIC_MODULE       ((MODULE_PCLKEN0<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(3UL<<0))

#define TMR0_MODULE      ((MODULE_PCLKEN0<<29)|(8UL<<25)         |(2UL<<22)         |(16UL<<17)        |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(8UL<<0))
#define TMR1_MODULE      ((MODULE_PCLKEN0<<29)|(8UL<<25)         |(2UL<<22)         |(18UL<<17)        |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(9UL<<0))
#define TMR2_MODULE      ((MODULE_PCLKEN0<<29)|(8UL<<25)         |(2UL<<22)         |(20UL<<17)        |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(10UL<<0))
#define TMR3_MODULE      ((MODULE_PCLKEN0<<29)|(8UL<<25)         |(2UL<<22)         |(22UL<<17)        |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(11UL<<0))
#define TMR4_MODULE      ((MODULE_PCLKEN0<<29)|(8UL<<25)         |(2UL<<22)         |(24UL<<17)        |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(12UL<<0))
#define TMR5_MODULE      ((MODULE_PCLKEN0<<29)|(8UL<<25)         |(2UL<<22)         |(26UL<<17)        |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(13UL<<0))

#define UART0_MODULE     ((MODULE_PCLKEN0<<29)|(4UL<<25)         |(2UL<<22)         |(3UL<<17)         |(4UL<<13)         |(3UL<<10)         |(5UL<<5)         |(16UL<<0))
#define UART1_MODULE     ((MODULE_PCLKEN0<<29)|(4UL<<25)         |(2UL<<22)         |(11UL<<17)        |(4UL<<13)         |(3UL<<10)         |(13UL<<5)        |(17UL<<0))
#define UART2_MODULE     ((MODULE_PCLKEN0<<29)|(4UL<<25)         |(2UL<<22)         |(19UL<<17)        |(4UL<<13)         |(3UL<<10)         |(21UL<<5)        |(18UL<<0))
#define UART3_MODULE     ((MODULE_PCLKEN0<<29)|(4UL<<25)         |(2UL<<22)         |(27UL<<17)        |(4UL<<13)         |(3UL<<10)         |(29UL<<5)        |(19UL<<0))
#define UART4_MODULE     ((MODULE_PCLKEN0<<29)|(5UL<<25)         |(2UL<<22)         |(3UL<<17)         |(5UL<<13)         |(3UL<<10)         |(5UL<<5)         |(20UL<<0))
#define UART5_MODULE     ((MODULE_PCLKEN0<<29)|(5UL<<25)         |(2UL<<22)         |(11UL<<17)        |(5UL<<13)         |(3UL<<10)         |(13UL<<5)        |(21UL<<0))
#define UART6_MODULE     ((MODULE_PCLKEN0<<29)|(5UL<<25)         |(2UL<<22)         |(19UL<<17)        |(5UL<<13)         |(3UL<<10)         |(21UL<<5)        |(22UL<<0))
#define UART7_MODULE     ((MODULE_PCLKEN0<<29)|(5UL<<25)         |(2UL<<22)         |(27UL<<17)        |(5UL<<13)         |(3UL<<10)         |(29UL<<5)        |(23UL<<0))

#define UART8_MODULE     ((MODULE_PCLKEN0<<29)|(6UL<<25)         |(2UL<<22)         |(3UL<<17)         |(6UL<<13)         |(3UL<<10)         |(5UL<<5)         |(24UL<<0))
#define UART9_MODULE     ((MODULE_PCLKEN0<<29)|(6UL<<25)         |(2UL<<22)         |(11UL<<17)        |(6UL<<13)         |(3UL<<10)         |(13UL<<5)        |(25UL<<0))

/* PCLKEN1 */
#define I2C0_MODULE      ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(0UL<<0))
#define I2C1_MODULE      ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(1UL<<0))
#define I2C2_MODULE      ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(2UL<<0))
#define I2C3_MODULE      ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(3UL<<0))
#define SPI0_MODULE      ((MODULE_PCLKEN1<<29)|(2UL<<25)         |(2UL<<22)         |(10UL<<17)        |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(4UL<<0))
#define SPI1_MODULE      ((MODULE_PCLKEN1<<29)|(2UL<<25)         |(2UL<<22)         |(12UL<<17)        |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(5UL<<0))
#define SPI2_MODULE      ((MODULE_PCLKEN1<<29)|(2UL<<25)         |(2UL<<22)         |(14UL<<17)        |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(6UL<<0))
#define SPI3_MODULE      ((MODULE_PCLKEN1<<29)|(2UL<<25)         |(2UL<<22)         |(16UL<<17)        |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(7UL<<0))

#define CAN0_MODULE      ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(8UL<<0))
#define CAN1_MODULE      ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(9UL<<0))
#define CAN2_MODULE      ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(10UL<<0))
#define CAN3_MODULE      ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(11UL<<0))
#define CAN4_MODULE      ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(12UL<<0))
#define CAN5_MODULE      ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(13UL<<0))
#define CAN6_MODULE      ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(14UL<<0))
#define CAN7_MODULE      ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(15UL<<0))

#define SMC0_MODULE      ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(6UL<<13)         |(4UL<<10)         |(24UL<<5)        |(16UL<<0))
#define SMC1_MODULE      ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(6UL<<13)         |(4UL<<10)         |(28UL<<5)        |(17UL<<0))
#define QSPI0_MODULE     ((MODULE_PCLKEN1<<29)|(2UL<<25)         |(2UL<<22)         |(8UL<<17)         |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(20UL<<0))
#define ADC_MODULE       ((MODULE_PCLKEN1<<29)|(7UL<<25)         |(2UL<<22)         |(20UL<<17)        |(7UL<<13)         |(7UL<<10)         |(24UL<<5)        |(24UL<<0))
#define EADC_MODULE      ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(7UL<<13)         |(4UL<<10)         |(16UL<<5)        |(25UL<<0))
//#define BPWM0_MODULE   ((MODULE_PCLKEN1<<29)|(2UL<<25)         |(2UL<<22)         |(24UL<<17)        |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(26UL<<0))
#define BPWM0_MODULE     ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(26UL<<0))
//#define BPWM1_MODULE   ((MODULE_PCLKEN1<<29)|(2UL<<25)         |(2UL<<22)         |(26UL<<17)        |(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(27UL<<0))
#define BPWM1_MODULE     ((MODULE_PCLKEN1<<29)|(MODULE_NoMsk<<25)|(MODULE_NoMsk<<22)|(MODULE_NoMsk<<17)|(MODULE_NoMsk<<13)|(MODULE_NoMsk<<10)|(MODULE_NoMsk<<5)|(27UL<<0))

/*@}*/ /* end of group CLK_EXPORTED_CONSTANTS */


/** @addtogroup CLK_EXPORTED_FUNCTIONS CLK Exported Functions
  @{
*/

void CLK_SetModuleClock(uint32_t u32ModuleIdx, uint32_t u32ClkSrc, uint32_t u32ClkDiv);
uint32_t CLK_GetModuleClockSource(uint32_t u32ModuleIdx);
uint32_t CLK_GetModuleClockDivider(uint32_t u32ModuleIdx);
void CLK_EnableModuleClock(uint32_t u32ModuleIdx);
void CLK_DisableModuleClock(uint32_t u32ModuleIdx);
void CLK_EnableCLKO(uint32_t u32ClkSrc, uint32_t u32ClkDiv);
void CLK_DisableCLKO(void);
uint32_t CLK_GetUPLLClockFreq(void);
uint32_t CLK_GetAPLLClockFreq(void);
uint32_t CLK_GetClockFreq(CLOCK_Type clk);
void CLK_EnableXtalRC(void);
void CLK_DisableXtalRC(void);
void CLK_EnterPowerDown(void);
void CLK_EnterIdle(void);
void CLK_StopClock(CLK_Stop req);
void CLK_StartClock(CLK_Stop req);

/*@}*/ /* end of group CLK_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group CLK_Driver */

/*@}*/ /* end of group Standard_Driver */

#ifdef __cplusplus
}
#endif

#endif  /* __CLK_H__ */

