/**************************************************************************//**
 * @file     clk.c
 * @brief    CLK Driver Source File
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#include "NuMicro.h"
#include "clk.h"

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup CLK_Driver CLK Driver
  @{
*/

/** @addtogroup CLK_EXPORTED_FUNCTIONS CLK Exported Functions
  @{
*/

/**
  * @brief      This function set selected module clock source and module clock divider
  * @param[in]  u32ModuleIdx is module index.
  * @param[in]  u32ClkSrc is module clock source.
  * @param[in]  u32ClkDiv is module clock divider.
  * @details    Valid parameter combinations listed in following table:
  *
  * |Module index          |Clock source                            |Divider                    |
  * | :----------------    | :------------------------------------  | :----------------------   |
  * |\ref CA35_MODULE      |\ref CLK_CLKSEL0_CA35CKSEL_HXT          | x                         |
  * |\ref CA35_MODULE      |\ref CLK_CLKSEL0_CA35CKSEL_CAPLL        | x                         |
  * |\ref CA35_MODULE      |\ref CLK_CLKSEL0_CA35CKSEL_DDRPLL       | x                         |
  * |\ref SYSCK0_MODULE    |\ref CLK_CLKSEL0_SYSCK0SEL_SYSPLL       | x                         |
  * |\ref SYSCK0_MODULE    |\ref CLK_CLKSEL0_SYSCK0SEL_EPLL_DIV2    | x                         |
  * |\ref LVRDB_MODULE     |\ref CLK_CLKSEL0_LVRDBSEL_LIRC          | x                         |
  * |\ref LVRDB_MODULE     |\ref CLK_CLKSEL0_LVRDBSEL_HIRC          | x                         |
  * |\ref SYSCK1_MODULE    |\ref CLK_CLKSEL0_SYSCK1SEL_HXT          | x                         |
  * |\ref SYSCK1_MODULE    |\ref CLK_CLKSEL0_SYSCK1SEL_SYSPLL       | x                         |
  * |\ref RTPST_MODULE     |\ref CLK_CLKSEL0_RTPSTSEL_HXT           | x                         |
  * |\ref RTPST_MODULE     |\ref CLK_CLKSEL0_RTPSTSEL_LXT           | x                         |
  * |\ref RTPST_MODULE     |\ref CLK_CLKSEL0_RTPSTSEL_HXT_DIV2      | x                         |
  * |\ref RTPST_MODULE     |\ref CLK_CLKSEL0_RTPSTSEL_SYSCLK1_DIV2  | x                         |
  * |\ref RTPST_MODULE     |\ref CLK_CLKSEL0_RTPSTSEL_HIRC          | x                         |
  * |\ref CCAP0_MODULE     |\ref CLK_CLKSEL0_CCAP0SEL_HXT           |\ref CLK_CLKDIV1_CCAP0(x)  |
  * |\ref CCAP0_MODULE     |\ref CLK_CLKSEL0_CCAP0SEL_SYSPLL        |\ref CLK_CLKDIV1_CCAP0(x)  |
  * |\ref CCAP0_MODULE     |\ref CLK_CLKSEL0_CCAP0SEL_APLL          |\ref CLK_CLKDIV1_CCAP0(x)  |
  * |\ref CCAP0_MODULE     |\ref CLK_CLKSEL0_CCAP0SEL_VPLL          |\ref CLK_CLKDIV1_CCAP0(x)  |
  * |\ref CCAP1_MODULE     |\ref CLK_CLKSEL0_CCAP1SEL_HXT           |\ref CLK_CLKDIV1_CCAP1(x)  |
  * |\ref CCAP1_MODULE     |\ref CLK_CLKSEL0_CCAP1SEL_SYSPLL        |\ref CLK_CLKDIV1_CCAP1(x)  |
  * |\ref CCAP1_MODULE     |\ref CLK_CLKSEL0_CCAP1SEL_APLL          |\ref CLK_CLKDIV1_CCAP1(x)  |
  * |\ref CCAP1_MODULE     |\ref CLK_CLKSEL0_CCAP1SEL_VPLL          |\ref CLK_CLKDIV1_CCAP1(x)  |
  * |\ref SDH0_MODULE      |\ref CLK_CLKSEL0_SD0SEL_SYSPLL          | x                         |
  * |\ref SDH0_MODULE      |\ref CLK_CLKSEL0_SD0SEL_APLL            | x                         |
  * |\ref SDH1_MODULE      |\ref CLK_CLKSEL0_SD1SEL_SYSPLL          | x                         |
  * |\ref SDH1_MODULE      |\ref CLK_CLKSEL0_SD1SEL_APLL            | x                         |
  * |\ref DCU_MODULE       |\ref CLK_CLKSEL0_DCUSEL_EPLL_DIV2       | x                         |
  * |\ref DCU_MODULE       |\ref CLK_CLKSEL0_DCUSEL_SYSPLL          | x                         |
  * |\ref DCUP_MODULE      | x                                      |\ref CLK_CLKDIV0_DCUP(x)   |
  * |\ref GFX_MODULE       |\ref CLK_CLKSEL0_GFXSEL_SYSPLL          | x                         |
  * |\ref GFX_MODULE       |\ref CLK_CLKSEL0_GFXSEL_EPLL            | x                         |
  * |\ref TMR0_MODULE      |\ref CLK_CLKSEL1_TMR0SEL_HXT            | x                         |
  * |\ref TMR0_MODULE      |\ref CLK_CLKSEL1_TMR0SEL_LXT            | x                         |
  * |\ref TMR0_MODULE      |\ref CLK_CLKSEL1_TMR0SEL_LIRC           | x                         |
  * |\ref TMR0_MODULE      |\ref CLK_CLKSEL1_TMR0SEL_HIRC           | x                         |
  * |\ref TMR0_MODULE      |\ref CLK_CLKSEL1_TMR0SEL_PCLK0          | x                         |
  * |\ref TMR0_MODULE      |\ref CLK_CLKSEL1_TMR0SEL_EXT            | x                         |
  * |\ref TMR1_MODULE      |\ref CLK_CLKSEL1_TMR1SEL_HXT            | x                         |
  * |\ref TMR1_MODULE      |\ref CLK_CLKSEL1_TMR1SEL_LXT            | x                         |
  * |\ref TMR1_MODULE      |\ref CLK_CLKSEL1_TMR1SEL_LIRC           | x                         |
  * |\ref TMR1_MODULE      |\ref CLK_CLKSEL1_TMR1SEL_HIRC           | x                         |
  * |\ref TMR1_MODULE      |\ref CLK_CLKSEL1_TMR1SEL_PCLK0          | x                         |
  * |\ref TMR1_MODULE      |\ref CLK_CLKSEL1_TMR1SEL_EXT            | x                         |
  * |\ref TMR2_MODULE      |\ref CLK_CLKSEL1_TMR2SEL_HXT            | x                         |
  * |\ref TMR2_MODULE      |\ref CLK_CLKSEL1_TMR2SEL_LXT            | x                         |
  * |\ref TMR2_MODULE      |\ref CLK_CLKSEL1_TMR2SEL_LIRC           | x                         |
  * |\ref TMR2_MODULE      |\ref CLK_CLKSEL1_TMR2SEL_HIRC           | x                         |
  * |\ref TMR2_MODULE      |\ref CLK_CLKSEL1_TMR2SEL_PCLK1          | x                         |
  * |\ref TMR2_MODULE      |\ref CLK_CLKSEL1_TMR2SEL_EXT            | x                         |
  * |\ref TMR3_MODULE      |\ref CLK_CLKSEL1_TMR3SEL_HXT            | x                         |
  * |\ref TMR3_MODULE      |\ref CLK_CLKSEL1_TMR3SEL_LXT            | x                         |
  * |\ref TMR3_MODULE      |\ref CLK_CLKSEL1_TMR3SEL_LIRC           | x                         |
  * |\ref TMR3_MODULE      |\ref CLK_CLKSEL1_TMR3SEL_HIRC           | x                         |
  * |\ref TMR3_MODULE      |\ref CLK_CLKSEL1_TMR3SEL_PCLK1          | x                         |
  * |\ref TMR3_MODULE      |\ref CLK_CLKSEL1_TMR3SEL_EXT            | x                         |
  * |\ref TMR4_MODULE      |\ref CLK_CLKSEL1_TMR4SEL_HXT            | x                         |
  * |\ref TMR4_MODULE      |\ref CLK_CLKSEL1_TMR4SEL_LXT            | x                         |
  * |\ref TMR4_MODULE      |\ref CLK_CLKSEL1_TMR4SEL_LIRC           | x                         |
  * |\ref TMR4_MODULE      |\ref CLK_CLKSEL1_TMR4SEL_HIRC           | x                         |
  * |\ref TMR4_MODULE      |\ref CLK_CLKSEL1_TMR4SEL_EXT            | x                         |
  * |\ref TMR4_MODULE      |\ref CLK_CLKSEL1_TMR4SEL_PCLK2          | x                         |
  * |\ref TMR5_MODULE      |\ref CLK_CLKSEL1_TMR5SEL_HXT            | x                         |
  * |\ref TMR5_MODULE      |\ref CLK_CLKSEL1_TMR5SEL_LXT            | x                         |
  * |\ref TMR5_MODULE      |\ref CLK_CLKSEL1_TMR5SEL_LIRC           | x                         |
  * |\ref TMR5_MODULE      |\ref CLK_CLKSEL1_TMR5SEL_HIRC           | x                         |
  * |\ref TMR5_MODULE      |\ref CLK_CLKSEL1_TMR5SEL_EXT            | x                         |
  * |\ref TMR5_MODULE      |\ref CLK_CLKSEL1_TMR5SEL_PCLK2          | x                         |
  * |\ref TMR6_MODULE      |\ref CLK_CLKSEL1_TMR6SEL_HXT            | x                         |
  * |\ref TMR6_MODULE      |\ref CLK_CLKSEL1_TMR6SEL_LXT            | x                         |
  * |\ref TMR6_MODULE      |\ref CLK_CLKSEL1_TMR6SEL_LIRC           | x                         |
  * |\ref TMR6_MODULE      |\ref CLK_CLKSEL1_TMR6SEL_HIRC           | x                         |
  * |\ref TMR6_MODULE      |\ref CLK_CLKSEL1_TMR6SEL_PCLK0          | x                         |
  * |\ref TMR6_MODULE      |\ref CLK_CLKSEL1_TMR6SEL_EXT            | x                         |
  * |\ref TMR7_MODULE      |\ref CLK_CLKSEL1_TMR7SEL_HXT            | x                         |
  * |\ref TMR7_MODULE      |\ref CLK_CLKSEL1_TMR7SEL_LXT            | x                         |
  * |\ref TMR7_MODULE      |\ref CLK_CLKSEL1_TMR7SEL_LIRC           | x                         |
  * |\ref TMR7_MODULE      |\ref CLK_CLKSEL1_TMR7SEL_HIRC           | x                         |
  * |\ref TMR7_MODULE      |\ref CLK_CLKSEL1_TMR7SEL_PCLK0          | x                         |
  * |\ref TMR7_MODULE      |\ref CLK_CLKSEL1_TMR7SEL_EXT            | x                         |
  * |\ref TMR8_MODULE      |\ref CLK_CLKSEL2_TMR8SEL_HXT            | x                         |
  * |\ref TMR8_MODULE      |\ref CLK_CLKSEL2_TMR8SEL_LXT            | x                         |
  * |\ref TMR8_MODULE      |\ref CLK_CLKSEL2_TMR8SEL_LIRC           | x                         |
  * |\ref TMR8_MODULE      |\ref CLK_CLKSEL2_TMR8SEL_HIRC           | x                         |
  * |\ref TMR8_MODULE      |\ref CLK_CLKSEL2_TMR8SEL_PCLK1          | x                         |
  * |\ref TMR8_MODULE      |\ref CLK_CLKSEL2_TMR8SEL_EXT            | x                         |
  * |\ref TMR9_MODULE      |\ref CLK_CLKSEL2_TMR9SEL_HXT            | x                         |
  * |\ref TMR9_MODULE      |\ref CLK_CLKSEL2_TMR9SEL_LXT            | x                         |
  * |\ref TMR9_MODULE      |\ref CLK_CLKSEL2_TMR9SEL_LIRC           | x                         |
  * |\ref TMR9_MODULE      |\ref CLK_CLKSEL2_TMR9SEL_HIRC           | x                         |
  * |\ref TMR9_MODULE      |\ref CLK_CLKSEL2_TMR9SEL_PCLK1          | x                         |
  * |\ref TMR9_MODULE      |\ref CLK_CLKSEL2_TMR9SEL_EXT            | x                         |
  * |\ref TMR10_MODULE     |\ref CLK_CLKSEL2_TMR10SEL_HXT           | x                         |
  * |\ref TMR10_MODULE     |\ref CLK_CLKSEL2_TMR10SEL_LXT           | x                         |
  * |\ref TMR10_MODULE     |\ref CLK_CLKSEL2_TMR10SEL_LIRC          | x                         |
  * |\ref TMR10_MODULE     |\ref CLK_CLKSEL2_TMR10SEL_HIRC          | x                         |
  * |\ref TMR10_MODULE     |\ref CLK_CLKSEL2_TMR10SEL_EXT           | x                         |
  * |\ref TMR10_MODULE     |\ref CLK_CLKSEL2_TMR10SEL_PCLK2         | x                         |
  * |\ref TMR11_MODULE     |\ref CLK_CLKSEL2_TMR11SEL_HXT           | x                         |
  * |\ref TMR11_MODULE     |\ref CLK_CLKSEL2_TMR11SEL_LXT           | x                         |
  * |\ref TMR11_MODULE     |\ref CLK_CLKSEL2_TMR11SEL_LIRC          | x                         |
  * |\ref TMR11_MODULE     |\ref CLK_CLKSEL2_TMR11SEL_HIRC          | x                         |
  * |\ref TMR11_MODULE     |\ref CLK_CLKSEL2_TMR11SEL_EXT           | x                         |
  * |\ref TMR11_MODULE     |\ref CLK_CLKSEL2_TMR11SEL_PCLK2         | x                         |
  * |\ref UART0_MODULE     |\ref CLK_CLKSEL2_UART0SEL_HXT           |\ref CLK_CLKDIV1_UART0(x)  |
  * |\ref UART0_MODULE     |\ref CLK_CLKSEL2_UART0SEL_SYSCLK1_DIV2  |\ref CLK_CLKDIV1_UART0(x)  |
  * |\ref UART1_MODULE     |\ref CLK_CLKSEL2_UART1SEL_HXT           |\ref CLK_CLKDIV1_UART1(x)  |
  * |\ref UART1_MODULE     |\ref CLK_CLKSEL2_UART1SEL_SYSCLK1_DIV2  |\ref CLK_CLKDIV1_UART1(x)  |
  * |\ref UART2_MODULE     |\ref CLK_CLKSEL2_UART2SEL_HXT           |\ref CLK_CLKDIV1_UART2(x)  |
  * |\ref UART2_MODULE     |\ref CLK_CLKSEL2_UART2SEL_SYSCLK1_DIV2  |\ref CLK_CLKDIV1_UART2(x)  |
  * |\ref UART3_MODULE     |\ref CLK_CLKSEL2_UART3SEL_HXT           |\ref CLK_CLKDIV1_UART3(x)  |
  * |\ref UART3_MODULE     |\ref CLK_CLKSEL2_UART3SEL_SYSCLK1_DIV2  |\ref CLK_CLKDIV1_UART3(x)  |
  * |\ref UART4_MODULE     |\ref CLK_CLKSEL2_UART4SEL_HXT           |\ref CLK_CLKDIV2_UART4(x)  |
  * |\ref UART4_MODULE     |\ref CLK_CLKSEL2_UART4SEL_SYSCLK1_DIV2  |\ref CLK_CLKDIV2_UART4(x)  |
  * |\ref UART5_MODULE     |\ref CLK_CLKSEL2_UART5SEL_HXT           |\ref CLK_CLKDIV2_UART5(x)  |
  * |\ref UART5_MODULE     |\ref CLK_CLKSEL2_UART5SEL_SYSCLK1_DIV2  |\ref CLK_CLKDIV2_UART5(x)  |
  * |\ref UART6_MODULE     |\ref CLK_CLKSEL2_UART6SEL_HXT           |\ref CLK_CLKDIV2_UART6(x)  |
  * |\ref UART6_MODULE     |\ref CLK_CLKSEL2_UART6SEL_SYSCLK1_DIV2  |\ref CLK_CLKDIV2_UART6(x)  |
  * |\ref UART7_MODULE     |\ref CLK_CLKSEL2_UART7SEL_HXT           |\ref CLK_CLKDIV2_UART7(x)  |
  * |\ref UART7_MODULE     |\ref CLK_CLKSEL2_UART7SEL_SYSCLK1_DIV2  |\ref CLK_CLKDIV2_UART7(x)  |
  * |\ref UART8_MODULE     |\ref CLK_CLKSEL3_UART8SEL_HXT           |\ref CLK_CLKDIV2_UART8(x)  |
  * |\ref UART8_MODULE     |\ref CLK_CLKSEL3_UART8SEL_SYSCLK1_DIV2  |\ref CLK_CLKDIV2_UART8(x)  |
  * |\ref UART9_MODULE     |\ref CLK_CLKSEL3_UART9SEL_HXT           |\ref CLK_CLKDIV2_UART9(x)  |
  * |\ref UART9_MODULE     |\ref CLK_CLKSEL3_UART9SEL_SYSCLK1_DIV2  |\ref CLK_CLKDIV2_UART9(x)  |
  * |\ref UART10_MODULE    |\ref CLK_CLKSEL3_UART10SEL_HXT          |\ref CLK_CLKDIV2_UART10(x) |
  * |\ref UART10_MODULE    |\ref CLK_CLKSEL3_UART10SEL_SYSCLK1_DIV2 |\ref CLK_CLKDIV2_UART10(x) |
  * |\ref UART11_MODULE    |\ref CLK_CLKSEL3_UART11SEL_HXT          |\ref CLK_CLKDIV2_UART11(x) |
  * |\ref UART11_MODULE    |\ref CLK_CLKSEL3_UART11SEL_SYSCLK1_DIV2 |\ref CLK_CLKDIV2_UART11(x) |
  * |\ref UART12_MODULE    |\ref CLK_CLKSEL3_UART12SEL_HXT          |\ref CLK_CLKDIV3_UART12(x) |
  * |\ref UART12_MODULE    |\ref CLK_CLKSEL3_UART12SEL_SYSCLK1_DIV2 |\ref CLK_CLKDIV3_UART12(x) |
  * |\ref UART13_MODULE    |\ref CLK_CLKSEL3_UART13SEL_HXT          |\ref CLK_CLKDIV3_UART13(x) |
  * |\ref UART13_MODULE    |\ref CLK_CLKSEL3_UART13SEL_SYSCLK1_DIV2 |\ref CLK_CLKDIV3_UART13(x) |
  * |\ref UART14_MODULE    |\ref CLK_CLKSEL3_UART14SEL_HXT          |\ref CLK_CLKDIV3_UART14(x) |
  * |\ref UART14_MODULE    |\ref CLK_CLKSEL3_UART14SEL_SYSCLK1_DIV2 |\ref CLK_CLKDIV3_UART14(x) |
  * |\ref UART15_MODULE    |\ref CLK_CLKSEL3_UART15SEL_HXT          |\ref CLK_CLKDIV3_UART15(x) |
  * |\ref UART15_MODULE    |\ref CLK_CLKSEL3_UART15SEL_SYSCLK1_DIV2 |\ref CLK_CLKDIV3_UART15(x) |
  * |\ref UART16_MODULE    |\ref CLK_CLKSEL3_UART16SEL_HXT          |\ref CLK_CLKDIV3_UART16(x) |
  * |\ref UART16_MODULE    |\ref CLK_CLKSEL3_UART16SEL_SYSCLK1_DIV2 |\ref CLK_CLKDIV3_UART16(x) |
  * |\ref WDT0_MODULE      |\ref CLK_CLKSEL3_WDT0SEL_LXT            | x                         |
  * |\ref WDT0_MODULE      |\ref CLK_CLKSEL3_WDT0SEL_LIRC           | x                         |
  * |\ref WDT0_MODULE      |\ref CLK_CLKSEL3_WDT0SEL_PCLK3_DIV4096  | x                         |
  * |\ref WWDT0_MODULE     |\ref CLK_CLKSEL3_WWDT0SEL_LIRC          | x                         |
  * |\ref WWDT0_MODULE     |\ref CLK_CLKSEL3_WWDT0SEL_PCLK3_DIV4096 | x                         |
  * |\ref WDT1_MODULE      |\ref CLK_CLKSEL3_WDT1SEL_LXT            | x                         |
  * |\ref WDT1_MODULE      |\ref CLK_CLKSEL3_WDT1SEL_LIRC           | x                         |
  * |\ref WDT1_MODULE      |\ref CLK_CLKSEL3_WDT1SEL_PCLK3_DIV4096  | x                         |
  * |\ref WWDT1_MODULE     |\ref CLK_CLKSEL3_WWDT1SEL_LIRC          | x                         |
  * |\ref WWDT1_MODULE     |\ref CLK_CLKSEL3_WWDT1SEL_PCLK3_DIV4096 | x                         |
  * |\ref WDT2_MODULE      |\ref CLK_CLKSEL3_WDT2SEL_LXT            | x                         |
  * |\ref WDT2_MODULE      |\ref CLK_CLKSEL3_WDT2SEL_LIRC           | x                         |
  * |\ref WDT2_MODULE      |\ref CLK_CLKSEL3_WDT2SEL_PCLK4_DIV4096  | x                         |
  * |\ref WWDT2_MODULE     |\ref CLK_CLKSEL3_WWDT2SEL_LIRC          | x                         |
  * |\ref WWDT2_MODULE     |\ref CLK_CLKSEL3_WWDT2SEL_PCLK4_DIV4096 | x                         |
  * |\ref SPI0_MODULE      |\ref CLK_CLKSEL4_SPI0SEL_PCLK1          | x                         |
  * |\ref SPI0_MODULE      |\ref CLK_CLKSEL4_SPI0SEL_APLL           | x                         |
  * |\ref SPI1_MODULE      |\ref CLK_CLKSEL4_SPI1SEL_PCLK2          | x                         |
  * |\ref SPI1_MODULE      |\ref CLK_CLKSEL4_SPI1SEL_APLL           | x                         |
  * |\ref SPI2_MODULE      |\ref CLK_CLKSEL4_SPI2SEL_PCLK1          | x                         |
  * |\ref SPI2_MODULE      |\ref CLK_CLKSEL4_SPI2SEL_APLL           | x                         |
  * |\ref SPI3_MODULE      |\ref CLK_CLKSEL4_SPI3SEL_PCLK2          | x                         |
  * |\ref SPI3_MODULE      |\ref CLK_CLKSEL4_SPI3SEL_APLL           | x                         |
  * |\ref QSPI0_MODULE     |\ref CLK_CLKSEL4_QSPI0SEL_PCLK0         | x                         |
  * |\ref QSPI0_MODULE     |\ref CLK_CLKSEL4_QSPI0SEL_APLL          | x                         |
  * |\ref QSPI1_MODULE     |\ref CLK_CLKSEL4_QSPI1SEL_PCLK0         | x                         |
  * |\ref QSPI1_MODULE     |\ref CLK_CLKSEL4_QSPI1SEL_APLL          | x                         |
  * |\ref I2S0_MODULE      |\ref CLK_CLKSEL4_I2S0SEL_APLL           | x                         |
  * |\ref I2S0_MODULE      |\ref CLK_CLKSEL4_I2S0SEL_SYSCLK1_DIV2   | x                         |
  * |\ref I2S1_MODULE      |\ref CLK_CLKSEL4_I2S1SEL_APLL           | x                         |
  * |\ref I2S1_MODULE      |\ref CLK_CLKSEL4_I2S1SEL_SYSCLK1_DIV2   | x                         |
  * |\ref CANFD0_MODULE    |\ref CLK_CLKSEL4_CANFD0SEL_APLL         |\ref CLK_CLKDIV0_CANFD0(x) |
  * |\ref CANFD0_MODULE    |\ref CLK_CLKSEL4_CANFD0SEL_VPLL         |\ref CLK_CLKDIV0_CANFD0(x) |
  * |\ref CANFD1_MODULE    |\ref CLK_CLKSEL4_CANFD1SEL_APLL         |\ref CLK_CLKDIV0_CANFD1(x) |
  * |\ref CANFD1_MODULE    |\ref CLK_CLKSEL4_CANFD1SEL_VPLL         |\ref CLK_CLKDIV0_CANFD1(x) |
  * |\ref CANFD2_MODULE    |\ref CLK_CLKSEL4_CANFD2SEL_APLL         |\ref CLK_CLKDIV0_CANFD2(x) |
  * |\ref CANFD2_MODULE    |\ref CLK_CLKSEL4_CANFD2SEL_VPLL         |\ref CLK_CLKDIV0_CANFD2(x) |
  * |\ref CANFD3_MODULE    |\ref CLK_CLKSEL4_CANFD3SEL_APLL         |\ref CLK_CLKDIV0_CANFD3(x) |
  * |\ref CANFD3_MODULE    |\ref CLK_CLKSEL4_CANFD3SEL_VPLL         |\ref CLK_CLKDIV0_CANFD3(x) |
  * |\ref CLKO_MODULE      |\ref CLK_CLKSEL4_CKOSEL_HXT             | x                         |
  * |\ref CLKO_MODULE      |\ref CLK_CLKSEL4_CKOSEL_LXT             | x                         |
  * |\ref CLKO_MODULE      |\ref CLK_CLKSEL4_CKOSEL_LIRC            | x                         |
  * |\ref CLKO_MODULE      |\ref CLK_CLKSEL4_CKOSEL_HIRC            | x                         |
  * |\ref CLKO_MODULE      |\ref CLK_CLKSEL4_CKOSEL_CAPLL_DIV4      | x                         |
  * |\ref CLKO_MODULE      |\ref CLK_CLKSEL4_CKOSEL_SYSPLL          | x                         |
  * |\ref CLKO_MODULE      |\ref CLK_CLKSEL4_CKOSEL_DDRPLL          | x                         |
  * |\ref CLKO_MODULE      |\ref CLK_CLKSEL4_CKOSEL_EPLL_DIV2       | x                         |
  * |\ref CLKO_MODULE      |\ref CLK_CLKSEL4_CKOSEL_APLL            | x                         |
  * |\ref CLKO_MODULE      |\ref CLK_CLKSEL4_CKOSEL_VPLL            | x                         |
  * |\ref SC0_MODULE       |\ref CLK_CLKSEL4_SC0SEL_HXT             |\ref CLK_CLKDIV1_SC0(x)    |
  * |\ref SC0_MODULE       |\ref CLK_CLKSEL4_SC0SEL_PCLK4           |\ref CLK_CLKDIV1_SC0(x)    |
  * |\ref SC1_MODULE       |\ref CLK_CLKSEL4_SC1SEL_HXT             |\ref CLK_CLKDIV1_SC1(x)    |
  * |\ref SC1_MODULE       |\ref CLK_CLKSEL4_SC1SEL_PCLK4           |\ref CLK_CLKDIV1_SC1(x)    |
  * |\ref KPI_MODULE       |\ref CLK_CLKSEL4_KPISEL_HXT             |\ref CLK_CLKDIV4_KPI(x)    |
  * |\ref KPI_MODULE       |\ref CLK_CLKSEL4_KPISEL_LXT             |\ref CLK_CLKDIV4_KPI(x)    |
  * |\ref ADC_MODULE       | x                                      |\ref CLK_CLKDIV4_ADC(x)    |
  * |\ref EADC_MODULE      | x                                      |\ref CLK_CLKDIV4_EADC(x)   |
  *
  */
void CLK_SetModuleClock(uint32_t u32ModuleIdx, uint32_t u32ClkSrc, uint32_t u32ClkDiv)
{
    uint32_t u32sel = 0UL, u32div = 0UL;

	// For clock divider over 8-bit cases
    if (u32ModuleIdx == MII_MODULE)
    {
        CLK->DIVCTL8 = (CLK->DIVCTL8 & ~(CLK_DIVCTL8_MDCLKDIV_Msk)) | u32ClkDiv;
        //printf("Div = 0x%08x\n", (0xFFFFFFFF & ~(CLK_DIVCTL8_MDCLKDIV_Msk)) | u32ClkDiv);
    }
    else if (u32ModuleIdx == CLKO_MODULE)
    {
        CLK->DIVCTL9 = (CLK->DIVCTL9 & ~(CLK_DIVCTL9_CLKO_N_Msk)) | u32ClkDiv;
        CLK->DIVCTL9 = (CLK->DIVCTL9 & ~(CLK_DIVCTL9_CLKO_S_Msk)) | u32ClkSrc;
        CLK->HCLKEN0 = (CLK->HCLKEN0 & ~(CLK_HCLKEN0_CLKOCKEN_Msk)) | CLK_HCLKEN0_CLKOCKEN_Msk;
        //printf("Div = 0x%08x\n", (0xFFFFFFFF & ~(CLK_DIVCTL9_CKO_N_Msk)) | u32ClkDiv);
        //printf("Sel = 0x%08x\n", (0xFFFFFFFF & ~(CLK_DIVCTL9_CKO_S_Msk)) | u32ClkSrc);
    }
    else if (u32ModuleIdx == I2S_MODULE)
    {
        CLK->DIVCTL1 = (CLK->DIVCTL1 & ~(CLK_DIVCTL1_I2S_N_Msk)) | u32ClkDiv;
        CLK->DIVCTL1 = (CLK->DIVCTL1 & ~(CLK_DIVCTL1_I2S_S_Msk)) | u32ClkSrc;
        CLK->HCLKEN1 = (CLK->HCLKEN1 & ~(CLK_HCLKEN1_I2S_Msk)) | CLK_HCLKEN1_I2S_Msk;
        //printf("Div = 0x%08x\n", (0xFFFFFFFF & ~(CLK_DIVCTL1_I2S_N_Msk)) | u32ClkDiv);
        //printf("Sel = 0x%08x\n", (0xFFFFFFFF & ~(CLK_DIVCTL1_I2S_S_Msk)) | u32ClkSrc);
    }
    else if (u32ModuleIdx == SDH0_MODULE)
    {
        CLK->DIVCTL3 = (CLK->DIVCTL3 & ~(CLK_DIVCTL3_SD0_N_Msk)) | u32ClkDiv;
        CLK->DIVCTL3 = (CLK->DIVCTL3 & ~(CLK_DIVCTL3_SD0_S_Msk)) | u32ClkSrc;
        CLK->HCLKEN0 = (CLK->HCLKEN0 & ~(CLK_HCLKEN0_SDH0_Msk)) | CLK_HCLKEN0_SDH0_Msk;
        //printf("Div = 0x%08x\n", (0xFFFFFFFF & ~(CLK_DIVCTL3_SD0_N_Msk)) | u32ClkDiv);
        //printf("Sel = 0x%08x\n", (0xFFFFFFFF & ~(CLK_DIVCTL3_SD0_S_Msk)) | u32ClkSrc);
    }
    else if (u32ModuleIdx == SDH1_MODULE)
    {
        CLK->DIVCTL3 = (CLK->DIVCTL3 & ~(CLK_DIVCTL3_SD1_N_Msk)) | u32ClkDiv;
        CLK->DIVCTL3 = (CLK->DIVCTL3 & ~(CLK_DIVCTL3_SD1_S_Msk)) | u32ClkSrc;
        CLK->HCLKEN0 = (CLK->HCLKEN0 & ~(CLK_HCLKEN0_SDH1_Msk)) | CLK_HCLKEN0_SDH1_Msk;
        //printf("Div = 0x%08x\n", (0xFFFFFFFF & ~(CLK_DIVCTL3_SD1_N_Msk)) | u32ClkDiv);
        //printf("Sel = 0x%08x\n", (0xFFFFFFFF & ~(CLK_DIVCTL3_SD1_S_Msk)) | u32ClkSrc);
    }
    else if (u32ModuleIdx == ADC_MODULE)
    {
        CLK->DIVCTL7 = (CLK->DIVCTL7 & ~(CLK_DIVCTL7_ADC_N_Msk)) | u32ClkDiv;
        CLK->DIVCTL7 = (CLK->DIVCTL7 & ~(CLK_DIVCTL7_ADC_S_Msk)) | u32ClkSrc;
        CLK->PCLKEN1 = (CLK->PCLKEN1 & ~(CLK_PCLKEN1_ADCCKEN_Msk)) | CLK_PCLKEN1_ADCCKEN_Msk;
        //printf("Div = 0x%08x\n", (0xFFFFFFFF & ~(CLK_DIVCTL7_ADC_N_Msk)) | u32ClkDiv);
        //printf("Sel = 0x%08x\n", (0xFFFFFFFF & ~(CLK_DIVCTL7_ADC_S_Msk)) | u32ClkSrc);
    }
    else
    {
        if (MODULE_CLKDIV_Msk(u32ModuleIdx) != MODULE_NoMsk)
        {
            /* Get clock divider control register address */
            u32div = (uint32_t)&CLK->DIVCTL0 + ((MODULE_CLKDIV(u32ModuleIdx)) * 4UL);
            /* Apply new divider */
            M32(u32div) = (M32(u32div) & (~(((1UL << MODULE_CLKDIV_Msk(u32ModuleIdx)) - 1) << MODULE_CLKDIV_Pos(u32ModuleIdx)))) | u32ClkDiv;
            //printf("Div Addr = 0x%08x\n", u32div);
            //printf("Div Val  = 0x%08x\n", (0xFFFFFFFF & (~(((1U << MODULE_CLKDIV_Msk(u32ModuleIdx)) - 1) << MODULE_CLKDIV_Pos(u32ModuleIdx)))) | u32ClkDiv);
        }

        if (MODULE_CLKSEL_Msk(u32ModuleIdx) != MODULE_NoMsk)
        {
            /* Get clock select control register address */
            u32sel = (uint32_t)&CLK->DIVCTL0 + ((MODULE_CLKSEL(u32ModuleIdx)) * 4UL);
            /* Set new clock selection setting */
            M32(u32sel) = (M32(u32sel) & (~(((1UL << MODULE_CLKSEL_Msk(u32ModuleIdx)) - 1) << MODULE_CLKSEL_Pos(u32ModuleIdx)))) | u32ClkSrc;
            //printf("Sel Addr = 0x%08x\n", u32sel);
            //printf("Sel Val  = 0x%08x\n", (0xFFFFFFFF & (~(((1U << MODULE_CLKSEL_Msk(u32ModuleIdx)) - 1) << MODULE_CLKSEL_Pos(u32ModuleIdx)))) | u32ClkSrc);
        }
    }
}

/**
  * @brief      Get selected module clock source
  * @param[in]  u32ModuleIdx is module index.
  *             - \ref PDMA0_MODULE
  *             - \ref PDMA1_MODULE
  *             - \ref PDMA2_MODULE
  *             - \ref PDMA3_MODULE
  *             - \ref WH0_MODULE
  *             - \ref WH1_MODULE
  *             - \ref HWS_MODULE
  *             - \ref EBI_MODULE
  *             - \ref SRAM0_MODULE
  *             - \ref SRAM1_MODULE
  *             - \ref ROM_MODULE
  *             - \ref TRA_MODULE
  *             - \ref DBG_MODULE
  *             - \ref CLKO_MODULE
  *             - \ref GTMR_MODULE
  *             - \ref GPA_MODULE
  *             - \ref GPB_MODULE
  *             - \ref GPC_MODULE
  *             - \ref GPD_MODULE
  *             - \ref GPE_MODULE
  *             - \ref GPF_MODULE
  *             - \ref GPG_MODULE
  *             - \ref GPH_MODULE
  *             - \ref GPI_MODULE
  *             - \ref GPJ_MODULE
  *             - \ref GPK_MODULE
  *             - \ref GPL_MODULE
  *             - \ref GPM_MODULE
  *             - \ref GPN_MODULE
  *             - \ref CA35_MODULE
  *             - \ref SYSCK0_MODULE
  *             - \ref SYSCK1_MODULE
  *             - \ref RTPST_MODULE
  *             - \ref LVRDB_MODULE
  *             - \ref DDR0_MODULE
  *             - \ref DDR6_MODULE
  *             - \ref CANFD0_MODULE
  *             - \ref CANFD1_MODULE
  *             - \ref CANFD2_MODULE
  *             - \ref CANFD3_MODULE
  *             - \ref SDH0_MODULE
  *             - \ref SDH1_MODULE
  *             - \ref NAND_MODULE
  *             - \ref USBD_MODULE
  *             - \ref USBH_MODULE
  *             - \ref HUSBH0_MODULE
  *             - \ref HUSBH1_MODULE
  *             - \ref GFX_MODULE
  *             - \ref VDEC_MODULE
  *             - \ref DCU_MODULE
  *             - \ref DCUP_MODULE
  *             - \ref GMAC0_MODULE
  *             - \ref GMAC1_MODULE
  *             - \ref CCAP0_MODULE
  *             - \ref CCAP1_MODULE
  *             - \ref TMR0_MODULE
  *             - \ref TMR1_MODULE
  *             - \ref TMR2_MODULE
  *             - \ref TMR3_MODULE
  *             - \ref TMR4_MODULE
  *             - \ref TMR5_MODULE
  *             - \ref TMR6_MODULE
  *             - \ref TMR7_MODULE
  *             - \ref TMR8_MODULE
  *             - \ref TMR9_MODULE
  *             - \ref TMR10_MODULE
  *             - \ref TMR11_MODULE
  *             - \ref UART0_MODULE
  *             - \ref UART1_MODULE
  *             - \ref UART2_MODULE
  *             - \ref UART3_MODULE
  *             - \ref UART4_MODULE
  *             - \ref UART5_MODULE
  *             - \ref UART6_MODULE
  *             - \ref UART7_MODULE
  *             - \ref UART8_MODULE
  *             - \ref UART9_MODULE
  *             - \ref UART10_MODULE
  *             - \ref UART11_MODULE
  *             - \ref UART12_MODULE
  *             - \ref UART13_MODULE
  *             - \ref UART14_MODULE
  *             - \ref UART15_MODULE
  *             - \ref UART16_MODULE
  *             - \ref RTC_MODULE
  *             - \ref DDRP_MODULE
  *             - \ref KPI_MODULE
  *             - \ref I2C0_MODULE
  *             - \ref I2C1_MODULE
  *             - \ref I2C2_MODULE
  *             - \ref I2C3_MODULE
  *             - \ref I2C4_MODULE
  *             - \ref I2C5_MODULE
  *             - \ref QSPI0_MODULE
  *             - \ref QSPI1_MODULE
  *             - \ref SC0_MODULE
  *             - \ref SC1_MODULE
  *             - \ref WDT0_MODULE
  *             - \ref WDT1_MODULE
  *             - \ref WDT2_MODULE
  *             - \ref WWDT0_MODULE
  *             - \ref WWDT1_MODULE
  *             - \ref WWDT2_MODULE
  *             - \ref EPWM0_MODULE
  *             - \ref EPWM1_MODULE
  *             - \ref EPWM2_MODULE
  *             - \ref I2S0_MODULE
  *             - \ref I2S1_MODULE
  *             - \ref SSMCC_MODULE
  *             - \ref SSPCC_MODULE
  *             - \ref SPI0_MODULE
  *             - \ref SPI1_MODULE
  *             - \ref SPI2_MODULE
  *             - \ref SPI3_MODULE
  *             - \ref ECAP0_MODULE
  *             - \ref ECAP1_MODULE
  *             - \ref ECAP2_MODULE
  *             - \ref QEI0_MODULE
  *             - \ref QEI1_MODULE
  *             - \ref QEI2_MODULE
  *             - \ref ADC_MODULE
  *             - \ref EADC_MODULE
  * @return     Selected module clock source setting
  * @details    This function get selected module clock source.
  */
uint32_t CLK_GetModuleClockSource(uint32_t u32ModuleIdx)
{
    uint32_t u32sel = 0;

    /* Get clock source selection setting */
    if (MODULE_CLKSEL_Msk(u32ModuleIdx) != MODULE_NoMsk)
    {
        /* Get clock select control register address */
        u32sel = (uint32_t)&CLK->DIVCTL0 + ((MODULE_CLKSEL(u32ModuleIdx)) * 4UL);
        /* Get clock source selection setting */
        return ((M32(u32sel) & (((1UL << MODULE_CLKSEL_Msk(u32ModuleIdx)) - 1) << MODULE_CLKSEL_Pos(u32ModuleIdx))) >> MODULE_CLKSEL_Pos(u32ModuleIdx));
    }
    else
        return 0;
}

/**
  * @brief      Get selected module clock divider number
  * @param[in]  u32ModuleIdx is module index.
  *             - \ref PDMA0_MODULE
  *             - \ref PDMA1_MODULE
  *             - \ref PDMA2_MODULE
  *             - \ref PDMA3_MODULE
  *             - \ref WH0_MODULE
  *             - \ref WH1_MODULE
  *             - \ref HWS_MODULE
  *             - \ref EBI_MODULE
  *             - \ref SRAM0_MODULE
  *             - \ref SRAM1_MODULE
  *             - \ref ROM_MODULE
  *             - \ref TRA_MODULE
  *             - \ref DBG_MODULE
  *             - \ref CLKO_MODULE
  *             - \ref GTMR_MODULE
  *             - \ref GPA_MODULE
  *             - \ref GPB_MODULE
  *             - \ref GPC_MODULE
  *             - \ref GPD_MODULE
  *             - \ref GPE_MODULE
  *             - \ref GPF_MODULE
  *             - \ref GPG_MODULE
  *             - \ref GPH_MODULE
  *             - \ref GPI_MODULE
  *             - \ref GPJ_MODULE
  *             - \ref GPK_MODULE
  *             - \ref GPL_MODULE
  *             - \ref GPM_MODULE
  *             - \ref GPN_MODULE
  *             - \ref CA35_MODULE
  *             - \ref SYSCK0_MODULE
  *             - \ref SYSCK1_MODULE
  *             - \ref RTPST_MODULE
  *             - \ref LVRDB_MODULE
  *             - \ref DDR0_MODULE
  *             - \ref DDR6_MODULE
  *             - \ref CANFD0_MODULE
  *             - \ref CANFD1_MODULE
  *             - \ref CANFD2_MODULE
  *             - \ref CANFD3_MODULE
  *             - \ref SDH0_MODULE
  *             - \ref SDH1_MODULE
  *             - \ref NAND_MODULE
  *             - \ref USBD_MODULE
  *             - \ref USBH_MODULE
  *             - \ref HUSBH0_MODULE
  *             - \ref HUSBH1_MODULE
  *             - \ref GFX_MODULE
  *             - \ref VDEC_MODULE
  *             - \ref DCU_MODULE
  *             - \ref DCUP_MODULE
  *             - \ref GMAC0_MODULE
  *             - \ref GMAC1_MODULE
  *             - \ref CCAP0_MODULE
  *             - \ref CCAP1_MODULE
  *             - \ref TMR0_MODULE
  *             - \ref TMR1_MODULE
  *             - \ref TMR2_MODULE
  *             - \ref TMR3_MODULE
  *             - \ref TMR4_MODULE
  *             - \ref TMR5_MODULE
  *             - \ref TMR6_MODULE
  *             - \ref TMR7_MODULE
  *             - \ref TMR8_MODULE
  *             - \ref TMR9_MODULE
  *             - \ref TMR10_MODULE
  *             - \ref TMR11_MODULE
  *             - \ref UART0_MODULE
  *             - \ref UART1_MODULE
  *             - \ref UART2_MODULE
  *             - \ref UART3_MODULE
  *             - \ref UART4_MODULE
  *             - \ref UART5_MODULE
  *             - \ref UART6_MODULE
  *             - \ref UART7_MODULE
  *             - \ref UART8_MODULE
  *             - \ref UART9_MODULE
  *             - \ref UART10_MODULE
  *             - \ref UART11_MODULE
  *             - \ref UART12_MODULE
  *             - \ref UART13_MODULE
  *             - \ref UART14_MODULE
  *             - \ref UART15_MODULE
  *             - \ref UART16_MODULE
  *             - \ref RTC_MODULE
  *             - \ref DDRP_MODULE
  *             - \ref KPI_MODULE
  *             - \ref I2C0_MODULE
  *             - \ref I2C1_MODULE
  *             - \ref I2C2_MODULE
  *             - \ref I2C3_MODULE
  *             - \ref I2C4_MODULE
  *             - \ref I2C5_MODULE
  *             - \ref QSPI0_MODULE
  *             - \ref QSPI1_MODULE
  *             - \ref SC0_MODULE
  *             - \ref SC1_MODULE
  *             - \ref WDT0_MODULE
  *             - \ref WDT1_MODULE
  *             - \ref WDT2_MODULE
  *             - \ref WWDT0_MODULE
  *             - \ref WWDT1_MODULE
  *             - \ref WWDT2_MODULE
  *             - \ref EPWM0_MODULE
  *             - \ref EPWM1_MODULE
  *             - \ref EPWM2_MODULE
  *             - \ref I2S0_MODULE
  *             - \ref I2S1_MODULE
  *             - \ref SSMCC_MODULE
  *             - \ref SSPCC_MODULE
  *             - \ref SPI0_MODULE
  *             - \ref SPI1_MODULE
  *             - \ref SPI2_MODULE
  *             - \ref SPI3_MODULE
  *             - \ref ECAP0_MODULE
  *             - \ref ECAP1_MODULE
  *             - \ref ECAP2_MODULE
  *             - \ref QEI0_MODULE
  *             - \ref QEI1_MODULE
  *             - \ref QEI2_MODULE
  *             - \ref ADC_MODULE
  *             - \ref EADC_MODULE
  * @return     Selected module clock divider number setting
  * @details    This function get selected module clock divider number.
  */
uint32_t CLK_GetModuleClockDivider(uint32_t u32ModuleIdx)
{
    uint32_t u32div = 0;

    if (MODULE_CLKDIV_Msk(u32ModuleIdx) != MODULE_NoMsk)
    {
        if (u32ModuleIdx == MII_MODULE)
		{
			u32div = (CLK->DIVCTL8 & CLK_DIVCTL8_MDCLKDIV_Msk) >> CLK_DIVCTL8_MDCLKDIV_Pos;
			return u32div;
		}
		else if (u32ModuleIdx == CLKO_MODULE)
		{
			u32div = (CLK->DIVCTL9 & CLK_DIVCTL9_CLKO_N_Msk) >> CLK_DIVCTL9_CLKO_N_Pos;
			return u32div;
		}
		else if (u32ModuleIdx == I2S_MODULE)
		{
			u32div = (CLK->DIVCTL1 & CLK_DIVCTL1_I2S_N_Msk) >> CLK_DIVCTL1_I2S_N_Pos;
			return u32div;
		}
		else if (u32ModuleIdx == SDH0_MODULE)
		{
			u32div = (CLK->DIVCTL3 & CLK_DIVCTL3_SD0_N_Msk) >> CLK_DIVCTL3_SD0_N_Pos;
			return u32div;
		}
		else if (u32ModuleIdx == SDH1_MODULE)
		{
			u32div = (CLK->DIVCTL3 & CLK_DIVCTL3_SD1_N_Msk) >> CLK_DIVCTL3_SD1_N_Pos;
			return u32div;
		}
		else if (u32ModuleIdx == ADC_MODULE)
		{
			u32div = (CLK->DIVCTL7 & CLK_DIVCTL7_ADC_N_Msk) >> CLK_DIVCTL7_ADC_N_Pos;
			return u32div;
		}
        else
        {
            /* Get clock divider control register address */
            u32div = (uint32_t)&CLK->DIVCTL0 + (MODULE_CLKDIV(u32ModuleIdx) * 4UL);
            /* Get clock divider number setting */
            return ((M32(u32div) & (((1UL << MODULE_CLKDIV_Msk(u32ModuleIdx)) - 1) << MODULE_CLKDIV_Pos(u32ModuleIdx))) >> MODULE_CLKDIV_Pos(u32ModuleIdx));
        }
    }
    else
        return 0;
}

/**
  * @brief      Enable module clock
  * @param[in]  u32ModuleIdx is module index. Including :
  *             - \ref PDMA0_MODULE
  *             - \ref PDMA1_MODULE
  *             - \ref PDMA2_MODULE
  *             - \ref PDMA3_MODULE
  *             - \ref WH0_MODULE
  *             - \ref WH1_MODULE
  *             - \ref HWS_MODULE
  *             - \ref EBI_MODULE
  *             - \ref SRAM0_MODULE
  *             - \ref SRAM1_MODULE
  *             - \ref ROM_MODULE
  *             - \ref TRA_MODULE
  *             - \ref DBG_MODULE
  *             - \ref CLKO_MODULE
  *             - \ref GTMR_MODULE
  *             - \ref GPA_MODULE
  *             - \ref GPB_MODULE
  *             - \ref GPC_MODULE
  *             - \ref GPD_MODULE
  *             - \ref GPE_MODULE
  *             - \ref GPF_MODULE
  *             - \ref GPG_MODULE
  *             - \ref GPH_MODULE
  *             - \ref GPI_MODULE
  *             - \ref GPJ_MODULE
  *             - \ref GPK_MODULE
  *             - \ref GPL_MODULE
  *             - \ref GPM_MODULE
  *             - \ref GPN_MODULE
  *             - \ref CA35_MODULE
  *             - \ref SYSCK0_MODULE
  *             - \ref SYSCK1_MODULE
  *             - \ref RTPST_MODULE
  *             - \ref LVRDB_MODULE
  *             - \ref DDR0_MODULE
  *             - \ref DDR6_MODULE
  *             - \ref CANFD0_MODULE
  *             - \ref CANFD1_MODULE
  *             - \ref CANFD2_MODULE
  *             - \ref CANFD3_MODULE
  *             - \ref SDH0_MODULE
  *             - \ref SDH1_MODULE
  *             - \ref NAND_MODULE
  *             - \ref USBD_MODULE
  *             - \ref USBH_MODULE
  *             - \ref HUSBH0_MODULE
  *             - \ref HUSBH1_MODULE
  *             - \ref GFX_MODULE
  *             - \ref VDEC_MODULE
  *             - \ref DCU_MODULE
  *             - \ref DCUP_MODULE
  *             - \ref GMAC0_MODULE
  *             - \ref GMAC1_MODULE
  *             - \ref CCAP0_MODULE
  *             - \ref CCAP1_MODULE
  *             - \ref TMR0_MODULE
  *             - \ref TMR1_MODULE
  *             - \ref TMR2_MODULE
  *             - \ref TMR3_MODULE
  *             - \ref TMR4_MODULE
  *             - \ref TMR5_MODULE
  *             - \ref TMR6_MODULE
  *             - \ref TMR7_MODULE
  *             - \ref TMR8_MODULE
  *             - \ref TMR9_MODULE
  *             - \ref TMR10_MODULE
  *             - \ref TMR11_MODULE
  *             - \ref UART0_MODULE
  *             - \ref UART1_MODULE
  *             - \ref UART2_MODULE
  *             - \ref UART3_MODULE
  *             - \ref UART4_MODULE
  *             - \ref UART5_MODULE
  *             - \ref UART6_MODULE
  *             - \ref UART7_MODULE
  *             - \ref UART8_MODULE
  *             - \ref UART9_MODULE
  *             - \ref UART10_MODULE
  *             - \ref UART11_MODULE
  *             - \ref UART12_MODULE
  *             - \ref UART13_MODULE
  *             - \ref UART14_MODULE
  *             - \ref UART15_MODULE
  *             - \ref UART16_MODULE
  *             - \ref RTC_MODULE
  *             - \ref DDRP_MODULE
  *             - \ref KPI_MODULE
  *             - \ref I2C0_MODULE
  *             - \ref I2C1_MODULE
  *             - \ref I2C2_MODULE
  *             - \ref I2C3_MODULE
  *             - \ref I2C4_MODULE
  *             - \ref I2C5_MODULE
  *             - \ref QSPI0_MODULE
  *             - \ref QSPI1_MODULE
  *             - \ref SC0_MODULE
  *             - \ref SC1_MODULE
  *             - \ref WDT0_MODULE
  *             - \ref WDT1_MODULE
  *             - \ref WDT2_MODULE
  *             - \ref WWDT0_MODULE
  *             - \ref WWDT1_MODULE
  *             - \ref WWDT2_MODULE
  *             - \ref EPWM0_MODULE
  *             - \ref EPWM1_MODULE
  *             - \ref EPWM2_MODULE
  *             - \ref I2S0_MODULE
  *             - \ref I2S1_MODULE
  *             - \ref SSMCC_MODULE
  *             - \ref SSPCC_MODULE
  *             - \ref SPI0_MODULE
  *             - \ref SPI1_MODULE
  *             - \ref SPI2_MODULE
  *             - \ref SPI3_MODULE
  *             - \ref ECAP0_MODULE
  *             - \ref ECAP1_MODULE
  *             - \ref ECAP2_MODULE
  *             - \ref QEI0_MODULE
  *             - \ref QEI1_MODULE
  *             - \ref QEI2_MODULE
  *             - \ref ADC_MODULE
  *             - \ref EADC_MODULE
  * @details    This function is used to enable module clock.
  */
void CLK_EnableModuleClock(uint32_t u32ModuleIdx)
{
    uint32_t u32tmpVal = 0UL, u32tmpAddr = 0UL;

    u32tmpVal = (1UL << MODULE_IP_EN_Pos(u32ModuleIdx));
    u32tmpAddr = (uint32_t)&CLK->HCLKEN0;
    u32tmpAddr += ((MODULE_APBCLK(u32ModuleIdx) * 4UL));

    *(volatile uint32_t *)u32tmpAddr |= u32tmpVal;
}

/**
  * @brief      Disable module clock
  * @param[in]  u32ModuleIdx is module index. Including :
  *             - \ref PDMA0_MODULE
  *             - \ref PDMA1_MODULE
  *             - \ref PDMA2_MODULE
  *             - \ref PDMA3_MODULE
  *             - \ref WH0_MODULE
  *             - \ref WH1_MODULE
  *             - \ref HWS_MODULE
  *             - \ref EBI_MODULE
  *             - \ref SRAM0_MODULE
  *             - \ref SRAM1_MODULE
  *             - \ref ROM_MODULE
  *             - \ref TRA_MODULE
  *             - \ref DBG_MODULE
  *             - \ref CLKO_MODULE
  *             - \ref GTMR_MODULE
  *             - \ref GPA_MODULE
  *             - \ref GPB_MODULE
  *             - \ref GPC_MODULE
  *             - \ref GPD_MODULE
  *             - \ref GPE_MODULE
  *             - \ref GPF_MODULE
  *             - \ref GPG_MODULE
  *             - \ref GPH_MODULE
  *             - \ref GPI_MODULE
  *             - \ref GPJ_MODULE
  *             - \ref GPK_MODULE
  *             - \ref GPL_MODULE
  *             - \ref GPM_MODULE
  *             - \ref GPN_MODULE
  *             - \ref CA35_MODULE
  *             - \ref SYSCK0_MODULE
  *             - \ref SYSCK1_MODULE
  *             - \ref RTPST_MODULE
  *             - \ref LVRDB_MODULE
  *             - \ref DDR0_MODULE
  *             - \ref DDR6_MODULE
  *             - \ref CANFD0_MODULE
  *             - \ref CANFD1_MODULE
  *             - \ref CANFD2_MODULE
  *             - \ref CANFD3_MODULE
  *             - \ref SDH0_MODULE
  *             - \ref SDH1_MODULE
  *             - \ref NAND_MODULE
  *             - \ref USBD_MODULE
  *             - \ref USBH_MODULE
  *             - \ref HUSBH0_MODULE
  *             - \ref HUSBH1_MODULE
  *             - \ref GFX_MODULE
  *             - \ref VDEC_MODULE
  *             - \ref DCU_MODULE
  *             - \ref DCUP_MODULE
  *             - \ref GMAC0_MODULE
  *             - \ref GMAC1_MODULE
  *             - \ref CCAP0_MODULE
  *             - \ref CCAP1_MODULE
  *             - \ref TMR0_MODULE
  *             - \ref TMR1_MODULE
  *             - \ref TMR2_MODULE
  *             - \ref TMR3_MODULE
  *             - \ref TMR4_MODULE
  *             - \ref TMR5_MODULE
  *             - \ref TMR6_MODULE
  *             - \ref TMR7_MODULE
  *             - \ref TMR8_MODULE
  *             - \ref TMR9_MODULE
  *             - \ref TMR10_MODULE
  *             - \ref TMR11_MODULE
  *             - \ref UART0_MODULE
  *             - \ref UART1_MODULE
  *             - \ref UART2_MODULE
  *             - \ref UART3_MODULE
  *             - \ref UART4_MODULE
  *             - \ref UART5_MODULE
  *             - \ref UART6_MODULE
  *             - \ref UART7_MODULE
  *             - \ref UART8_MODULE
  *             - \ref UART9_MODULE
  *             - \ref UART10_MODULE
  *             - \ref UART11_MODULE
  *             - \ref UART12_MODULE
  *             - \ref UART13_MODULE
  *             - \ref UART14_MODULE
  *             - \ref UART15_MODULE
  *             - \ref UART16_MODULE
  *             - \ref RTC_MODULE
  *             - \ref DDRP_MODULE
  *             - \ref KPI_MODULE
  *             - \ref I2C0_MODULE
  *             - \ref I2C1_MODULE
  *             - \ref I2C2_MODULE
  *             - \ref I2C3_MODULE
  *             - \ref I2C4_MODULE
  *             - \ref I2C5_MODULE
  *             - \ref QSPI0_MODULE
  *             - \ref QSPI1_MODULE
  *             - \ref SC0_MODULE
  *             - \ref SC1_MODULE
  *             - \ref WDT0_MODULE
  *             - \ref WDT1_MODULE
  *             - \ref WDT2_MODULE
  *             - \ref WWDT0_MODULE
  *             - \ref WWDT1_MODULE
  *             - \ref WWDT2_MODULE
  *             - \ref EPWM0_MODULE
  *             - \ref EPWM1_MODULE
  *             - \ref EPWM2_MODULE
  *             - \ref I2S0_MODULE
  *             - \ref I2S1_MODULE
  *             - \ref SSMCC_MODULE
  *             - \ref SSPCC_MODULE
  *             - \ref SPI0_MODULE
  *             - \ref SPI1_MODULE
  *             - \ref SPI2_MODULE
  *             - \ref SPI3_MODULE
  *             - \ref ECAP0_MODULE
  *             - \ref ECAP1_MODULE
  *             - \ref ECAP2_MODULE
  *             - \ref QEI0_MODULE
  *             - \ref QEI1_MODULE
  *             - \ref QEI2_MODULE
  *             - \ref ADC_MODULE
  *             - \ref EADC_MODULE
  * @details    This function is used to disable module clock.
  */
void CLK_DisableModuleClock(uint32_t u32ModuleIdx)
{
    uint32_t u32tmpVal = 0UL, u32tmpAddr = 0UL;

    u32tmpVal = ~(1UL << MODULE_IP_EN_Pos(u32ModuleIdx));
    u32tmpAddr = (uint32_t)&CLK->HCLKEN0;
    u32tmpAddr += ((MODULE_APBCLK(u32ModuleIdx) * 4UL));

    *(volatile uint32_t *)u32tmpAddr &= u32tmpVal;
}

/**
  * @brief      This function enable clock divider output module clock,
  *             enable clock divider output function and set frequency selection.
  * @param[in]  u32ClkSrc is frequency divider function clock source. Including :
  *             - \ref CLK_CLKSEL4_CKOSEL_HXT
  *             - \ref CLK_CLKSEL4_CKOSEL_LXT
  *             - \ref CLK_CLKSEL4_CKOSEL_LIRC
  *             - \ref CLK_CLKSEL4_CKOSEL_HIRC
  *             - \ref CLK_CLKSEL4_CKOSEL_CAPLL_DIV4
  *             - \ref CLK_CLKSEL4_CKOSEL_SYSPLL
  *             - \ref CLK_CLKSEL4_CKOSEL_APLL
  *             - \ref CLK_CLKSEL4_CKOSEL_EPLL_DIV2
  *             - \ref CLK_CLKSEL4_CKOSEL_VPLL
  * @param[in]  u32ClkDiv is divider output frequency selection. It could be 0~15.
  * @param[in]  u32ClkDivBy1En is clock divided by one enabled.
  * @details    Output selected clock to CKO. The output clock frequency is divided by u32ClkDiv. \n
  *             The formula is: \n
  *                 CKO frequency = (Clock source frequency) / 2^(u32ClkDiv + 1) \n
  *             This function is just used to set CKO clock.
  *             User must enable I/O for CKO clock output pin by themselves. \n
  */
void CLK_EnableCLKO(uint32_t u32ClkSrc, uint32_t u32ClkDiv)
{
    /* Select CLKO clock source & enable clock */
    CLK_SetModuleClock(CLKO_MODULE, u32ClkSrc, u32ClkDiv);
}

/**
  * @brief      Disable clock divider output function
  * @param      None
  * @return     None
  * @details    This function disable clock divider output function.
  */
void CLK_DisableCLKO(void)
{
    /* Disable CLKO clock source */
    CLK_DisableModuleClock(CLKO_MODULE);
}

uint32_t CLK_GetUPLLClockFreq(void)
{
	uint32_t u32M, u32N, u32P;
	uint32_t u32PLLCon;

	u32PLLCon = CLK->UPLLCON;
	u32N = ((u32PLLCon & 0x007F) >> 0)  + 1;  // FB_DV
    u32M = ((u32PLLCon & 0x1F80) >> 7)  + 1;  // IN_DV
    u32P = ((u32PLLCon & 0xE000) >> 13) + 1;  // OUT_DV

	return (12 * u32N / (u32M * u32P));    /* 12MHz HXT */
}

uint32_t CLK_GetAPLLClockFreq(void)
{
	uint32_t u32M, u32N, u32P;
	uint32_t u32PLLCon;

	u32PLLCon = CLK->APLLCON;
	u32N = ((u32PLLCon & 0x007F) >> 0)  + 1;  // FB_DV
    u32M = ((u32PLLCon & 0x1F80) >> 7)  + 1;  // IN_DV
    u32P = ((u32PLLCon & 0xE000) >> 13) + 1;  // OUT_DV

	return (12 * u32N / (u32M * u32P));    /* 12MHz HXT */
}

uint32_t CLK_GetClockFreq(CLOCK_Type clk)
{
    uint32_t clkfreq = 0;
    uint32_t divN, reg;

    reg = ((CLK->DIVCTL0) & CLK_DIVCTL0_SYSTEM_S_Msk) >> CLK_DIVCTL0_SYSTEM_S_Pos;
    switch (reg)
    {
        case 0x0:  /* HXT */
            clkfreq = 12;
            break;
        case 0x2:  /* APLL */
            clkfreq = CLK_GetAPLLClockFreq();
            break;
        case 0x3:  /* UPLL */
            clkfreq = CLK_GetUPLLClockFreq();
            break;
    }

    switch (clk)
    {
		case CLK_UPLL:
			clkfreq = CLK_GetUPLLClockFreq();
            break;

		case CLK_APLL:
			clkfreq = CLK_GetAPLLClockFreq();
            break;

		case CLK_SYSTEM:
			break;  // clkfreq

		case CLK_HCLK:
			clkfreq = clkfreq / 2;
            break;

        case CLK_HCLK1:
			clkfreq = clkfreq / 2 / 2;
            break;

		case CLK_PCLK0:
        case CLK_PCLK1:
			clkfreq = clkfreq / 2;
            break;

		case CLK_PCLK2:
            clkfreq = clkfreq / 2 / 2;
            break;

        case CLK_CPU:
		    reg = ((CLK->DIVCTL0) & CLK_DIVCTL0_CPUDIV2EN_Msk) >> CLK_DIVCTL0_CPUDIV2EN_Pos;
			divN = reg + 1;
			clkfreq = clkfreq / divN;
            break;

		default:
			;
    }

    return clkfreq;
}

/**
  * @brief      Enable clock source
  * @param[in]  u32ClkMask is clock source mask. Including :
  *             - \ref CLK_PWRCTL_HXTEN_Msk
  *             - \ref CLK_PWRCTL_LXTEN_Msk
  *             - \ref CLK_PWRCTL_HIRCEN_Msk
  *             - \ref CLK_PWRCTL_LIRCEN_Msk
  * @return     None
  * @details    This function enable clock source. \n
  *             The register write-protection function should be disabled before using this function.
  */
void CLK_EnableXtalRC(void)
{
    CLK->PMCON |= CLK_PMCON_XTAL_EN_Msk;  // Normal operation mode
}

/**
  * @brief      Disable clock source
  * @details    This function disable clock source. \n
  *             The register write-protection function should be disabled before using this function.
  */
void CLK_DisableXtalRC(void)
{
    CLK->PMCON &= ~CLK_PMCON_XTAL_EN_Msk;  // Power-down mode (XTAL_EN is write only bit)
}

void CLK_StopClock(CLK_Stop req)
{

	switch(req)
	{
		case STR_CANFD0:
			CLK->STOPREQ |= CLK_STOPREQ_CANFD0STR_Msk;
			while ((CLK->STOPACK & CLK_STOPACK_CANFD0STA_Msk) != CLK_STOPACK_CANFD0STA_Msk);
			break;

		case STR_CANFD1:
			CLK->STOPREQ |= CLK_STOPREQ_CANFD1STR_Msk;
			while ((CLK->STOPACK & CLK_STOPACK_CANFD1STA_Msk) != CLK_STOPACK_CANFD1STA_Msk);
			break;

		case STR_CANFD2:
			CLK->STOPREQ |= CLK_STOPREQ_CANFD2STR_Msk;
			while ((CLK->STOPACK & CLK_STOPACK_CANFD2STA_Msk) != CLK_STOPACK_CANFD2STA_Msk);
			break;

		case STR_CANFD3:
			CLK->STOPREQ |= CLK_STOPREQ_CANFD3STR_Msk;
			while ((CLK->STOPACK & CLK_STOPACK_CANFD3STA_Msk) != CLK_STOPACK_CANFD3STA_Msk);
			break;
	}
}

void CLK_StartClock(CLK_Stop req)
{
	switch(req)
	{
		case STR_CANFD0:
			CLK->STOPREQ &= ~CLK_STOPREQ_CANFD0STR_Msk;
			break;

		case STR_CANFD1:
			CLK->STOPREQ &= ~CLK_STOPREQ_CANFD1STR_Msk;
			break;

		case STR_CANFD2:
			CLK->STOPREQ &= ~CLK_STOPREQ_CANFD2STR_Msk;
			break;

		case STR_CANFD3:
			CLK->STOPREQ &= ~CLK_STOPREQ_CANFD3STR_Msk;
			break;
	}
}

/*@}*/ /* end of group CLK_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group CLK_Driver */

/*@}*/ /* end of group Standard_Driver */

