/**************************************************************************//**
 * @file     clk.c
 * @brief    CLK Driver Source File
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2026 Nuvoton Technology Corp. All rights reserved.
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

    if (u32ModuleIdx == MII_MODULE)
    {
        CLK->DIVCTL8 = (CLK->DIVCTL8 & ~(CLK_DIVCTL8_MDCLKDIV_Msk)) | u32ClkDiv;
    }
    else if (u32ModuleIdx == CLKO_MODULE)
    {
        CLK->DIVCTL9 = (CLK->DIVCTL9 & ~(CLK_DIVCTL9_CKO_N_Msk)) | u32ClkDiv;
        CLK->DIVCTL9 = (CLK->DIVCTL9 & ~(CLK_DIVCTL9_CKO_S_Msk)) | u32ClkSrc;
        CLK->HCLKEN0 |= CLK_HCLKEN0_CLKOCKEN_Msk;
    }
    else if (u32ModuleIdx == I2S_MODULE)
    {
        CLK->DIVCTL1 = (CLK->DIVCTL1 & ~(CLK_DIVCTL1_I2S_N_Msk)) | u32ClkDiv;
        CLK->DIVCTL1 = (CLK->DIVCTL1 & ~(CLK_DIVCTL1_I2S_S_Msk)) | u32ClkSrc;
        CLK->HCLKEN1 |= CLK_HCLKEN1_I2SCKEN_Msk;
    }
    else if (u32ModuleIdx == SDH0_MODULE)
    {
        CLK->DIVCTL3 = (CLK->DIVCTL3 & ~(CLK_DIVCTL3_SD0_N_Msk)) | u32ClkDiv;
        CLK->DIVCTL3 = (CLK->DIVCTL3 & ~(CLK_DIVCTL3_SD0_S_Msk)) | u32ClkSrc;
        CLK->HCLKEN0 |= CLK_HCLKEN0_SDH0EN_Msk;
    }
    else if (u32ModuleIdx == SDH1_MODULE)
    {
        CLK->DIVCTL3 = (CLK->DIVCTL3 & ~(CLK_DIVCTL3_SD1_N_Msk)) | u32ClkDiv;
        CLK->DIVCTL3 = (CLK->DIVCTL3 & ~(CLK_DIVCTL3_SD1_S_Msk)) | u32ClkSrc;
        CLK->HCLKEN0 |= CLK_HCLKEN0_SDH1EN_Msk;
    }
    else if (u32ModuleIdx == ADC_MODULE)
    {
        CLK->DIVCTL7 = (CLK->DIVCTL7 & ~(CLK_DIVCTL7_ADC_N_Msk)) | u32ClkDiv;
        CLK->DIVCTL7 = (CLK->DIVCTL7 & ~(CLK_DIVCTL7_ADC_S_Msk)) | u32ClkSrc;
        CLK->PCLKEN1 |= CLK_PCLKEN1_ADCCKEN_Msk;
    }
    else
    {
        if (MODULE_CLKDIV_Msk(u32ModuleIdx) != MODULE_NoMsk)
        {
            /* Get clock divider control register address */
            u32div = (uint32_t)&CLK->DIVCTL0 + ((MODULE_CLKDIV(u32ModuleIdx)) * 4UL);
            /* Apply new divider */
            M32(u32div) = (M32(u32div) & (~(((1UL << MODULE_CLKDIV_Msk(u32ModuleIdx)) - 1) << MODULE_CLKDIV_Pos(u32ModuleIdx)))) | u32ClkDiv;
        }

        if (MODULE_CLKSEL_Msk(u32ModuleIdx) != MODULE_NoMsk)
        {
            /* Get clock select control register address */
            u32sel = (uint32_t)&CLK->DIVCTL0 + ((MODULE_CLKSEL(u32ModuleIdx)) * 4UL);
            /* Set new clock selection setting */
            M32(u32sel) = (M32(u32sel) & (~(((1UL << MODULE_CLKSEL_Msk(u32ModuleIdx)) - 1) << MODULE_CLKSEL_Pos(u32ModuleIdx)))) | u32ClkSrc;
        }
    }
}

/**
 * @brief      Get module clock source selection value
 *
 * @details
 * This function returns the clock source selection value (CLKSEL)
 * for modules that support clock source selection.
 * For modules without clock source selection, this function returns 0.
 *
 * @return
 * Raw CLKSEL field value, or 0 if the module does not support CLKSEL.
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
 * @brief      Get module clock divider setting
 *
 * @param[in]  u32ModuleIdx  Module index.
 *
 * @return     Raw clock divider register value (N).
 *
 * @details
 * This function returns the clock divider field value configured for the
 * specified module if the module supports clock divider configuration
 * (i.e. the module has a CLKDIV field).
 *
 * For modules that do not support clock divider configuration, this function
 * returns 0.
 *
 * @note
 * The returned value is the raw divider field value (N).
 * The effective clock division factor applied to the module clock is (N + 1).
 *
 * @note
 * This function does not indicate whether the module clock is enabled.
 * Please use CLK_EnableModuleClock() or CLK_DisableModuleClock() to control
 * the module clock enable state.
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
			u32div = (CLK->DIVCTL9 & CLK_DIVCTL9_CKO_N_Msk) >> CLK_DIVCTL9_CKO_N_Pos;
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
 *
 * @param[in]  u32ModuleIdx  Module index.
 *
 * @details
 * This function enables the clock of the specified module by setting
 * the corresponding clock enable bit in HCLKEN or PCLKEN registers.
 *
 * Only modules that provide a valid clock enable bit will be affected.
 * For modules without an associated clock enable control bit, calling
 * this function has no effect.
 *
 * @note
 * This function only controls the module clock enable state.
 * It does not configure clock source or clock divider.
 * Please use CLK_SetModuleClock() to configure clock source or divider
 * before enabling the module clock, if required.
 */
void CLK_EnableModuleClock(uint32_t u32ModuleIdx)
{
    uint32_t u32tmpVal  = 0UL;
    uint32_t u32tmpAddr = 0UL;

    /* Calculate enable bit mask */
    u32tmpVal = (1UL << MODULE_IP_EN_Pos(u32ModuleIdx));

    /* Get clock enable register base address */
    u32tmpAddr = (uint32_t)&CLK->HCLKEN0;
    u32tmpAddr += (MODULE_APBCLK(u32ModuleIdx) * 4UL);

    /* Enable module clock */
    *(volatile uint32_t *)u32tmpAddr |= u32tmpVal;
}

/**
 * @brief      Disable module clock
 *
 * @param[in]  u32ModuleIdx  Module index.
 *
 * @details
 * This function disables the clock of the specified module by clearing
 * the corresponding clock enable bit in the HCLKEN or PCLKEN registers.
 *
 * Only modules that provide a valid clock enable control bit will be affected.
 * For modules without an associated clock enable bit, calling this function
 * has no effect.
 *
 * @note
 * This function only controls the module clock enable state.
 * It does not modify clock source or clock divider settings.
 * Clock source and divider configuration will be kept unchanged.
 */
void CLK_DisableModuleClock(uint32_t u32ModuleIdx)
{
    uint32_t u32tmpVal  = 0UL;
    uint32_t u32tmpAddr = 0UL;

    /* Calculate disable bit mask */
    u32tmpVal = ~(1UL << MODULE_IP_EN_Pos(u32ModuleIdx));

    /* Get clock enable register base address */
    u32tmpAddr = (uint32_t)&CLK->HCLKEN0;
    u32tmpAddr += (MODULE_APBCLK(u32ModuleIdx) * 4UL);

    /* Disable module clock */
    *(volatile uint32_t *)u32tmpAddr &= u32tmpVal;
}

/**
 * @brief      Enable reference clock output (CKO)
 *
 * @param[in]  u32ClkSrc  Reference clock output source selection.
 *                        This parameter selects the clock source for CKO.
 *
 * @param[in]  u32ClkDiv  Reference clock output divider setting (N).
 *                        The valid value depends on the CKO divider width.
 *
 * @details
 * This function configures the reference clock output (CKO) by selecting
 * the clock source and setting the clock divider.
 * The reference clock output will be enabled after this function is called.
 *
 * The output clock frequency is calculated as:
 *
 *     CKO frequency = (CKO clock source frequency) / (u32ClkDiv + 1)
 *
 * @note
 * This function only configures and enables the CKO clock.
 * The corresponding CKO output pin function must be configured separately
 * by the user through the GPIO or pin-mux controller.
 */
void CLK_EnableCLKO(uint32_t u32ClkSrc, uint32_t u32ClkDiv)
{
    /* Configure and enable CKO clock */
    CLK_SetModuleClock(CLKO_MODULE, u32ClkSrc, u32ClkDiv);
}

/**
 * @brief      Disable reference clock output (CKO)
 *
 * @details
 * This function disables the reference clock output by clearing the
 * corresponding clock enable bit for the CKO module.
 *
 * Clock source selection and clock divider settings are not modified.
 *
 * @note
 * This function only disables the CKO clock generation.
 * The CKO output pin configuration is not affected.
 */
void CLK_DisableCLKO(void)
{
    /* Disable CKO clock output */
    CLK_DisableModuleClock(CLKO_MODULE);
}

/**
 * @brief      Get UPLL output clock frequency
 *
 * @return     UPLL clock frequency in Hz.
 *
 * @details
 * This function calculates and returns the UPLL output clock frequency
 * based on the current UPLL configuration settings.
 *
 * The calculation is performed according to the PLL formula:
 *
 *     Fout = Fin * (N + X) / (M * P)
 *
 * where:
 *   - Fin is the external crystal clock (HXT), assumed to be 12 MHz
 *   - N is the integer feedback divider
 *   - X is the fractional feedback divider
 *   - M is the input divider
 *   - P is the output divider
 *
 * If the UPLL is powered down or held in reset, this function returns 0.
 * If the UPLL is in bypass mode, this function returns the HXT frequency.
 *
 * @note
 * This function assumes the external crystal (HXT) frequency is 12 MHz.
 */
uint32_t CLK_GetUPLLClockFreq(void)
{
    uint32_t u32PLLCon;
    uint32_t u32M, u32N, u32P;
    uint32_t u32Frac;
    uint64_t u64Freq;

    u32PLLCon = CLK->UPLLCON;

    /* PLL powered down or in reset */
    if ((u32PLLCon & CLK_UPLLCON_PD_Msk) || !(u32PLLCon & CLK_UPLLCON_RESETN_Msk))
    {
        return 0U;
    }

    /* PLL bypass mode */
    if (u32PLLCon & CLK_UPLLCON_BYPASS_Msk)
    {
        return __HXT; /* HXT */
    }

    u32N    = ((u32PLLCon & CLK_UPLLCON_FB_DV_Msk)   >> CLK_UPLLCON_FB_DV_Pos)   + 1U;
    u32M    = ((u32PLLCon & CLK_UPLLCON_IN_DV_Msk)   >> CLK_UPLLCON_IN_DV_Pos)   + 1U;
    u32P    = ((u32PLLCon & CLK_UPLLCON_OUT_DV_Msk)  >> CLK_UPLLCON_OUT_DV_Pos)  + 1U;
    u32Frac = ((u32PLLCon & CLK_UPLLCON_FRAC_Msk)    >> CLK_UPLLCON_FRAC_Pos);

    /* Fractional part: X = FRAC / 2^12 */
    u64Freq = (uint64_t)__HXT * ((uint64_t)u32N * 4096ULL + u32Frac);
    u64Freq = u64Freq / (4096ULL * u32M * u32P);

    return (uint32_t)u64Freq;
}

/**
 * @brief      Get APLL output clock frequency
 *
 * @return     APLL clock frequency in Hz.
 *
 * @details
 * This function calculates and returns the APLL output clock frequency
 * based on the current APLL configuration settings.
 *
 * The calculation follows the PLL formula:
 *
 *     Fout = Fin * (N + X) / (M * P)
 *
 * where Fin is assumed to be 12 MHz (HXT).
 *
 * If the APLL is powered down or held in reset, this function returns 0.
 * If the APLL is in bypass mode, this function returns the HXT frequency.
 *
 * @note
 * This function assumes the external crystal (HXT) frequency is 12 MHz.
 */
uint32_t CLK_GetAPLLClockFreq(void)
{
    uint32_t u32PLLCon;
    uint32_t u32M, u32N, u32P;
    uint32_t u32Frac;
    uint64_t u64Freq;

    u32PLLCon = CLK->APLLCON;

    /* PLL powered down or in reset */
    if ((u32PLLCon & CLK_APLLCON_PD_Msk) || !(u32PLLCon & CLK_APLLCON_RESETN_Msk))
    {
        return 0U;
    }

    /* PLL bypass mode */
    if (u32PLLCon & CLK_APLLCON_BYPASS_Msk)
    {
        return __HXT; /* HXT */
    }

    u32N    = ((u32PLLCon & CLK_APLLCON_FB_DV_Msk)   >> CLK_APLLCON_FB_DV_Pos)   + 1U;
    u32M    = ((u32PLLCon & CLK_APLLCON_IN_DV_Msk)   >> CLK_APLLCON_IN_DV_Pos)   + 1U;
    u32P    = ((u32PLLCon & CLK_APLLCON_OUT_DV_Msk)  >> CLK_APLLCON_OUT_DV_Pos)  + 1U;
    u32Frac = ((u32PLLCon & CLK_APLLCON_FRAC_Msk)    >> CLK_APLLCON_FRAC_Pos);

    u64Freq = (uint64_t)__HXT * ((uint64_t)u32N * 4096ULL + u32Frac);
    u64Freq = u64Freq / (4096ULL * u32M * u32P);

    return (uint32_t)u64Freq;
}

/**
 * @brief      Get specified clock frequency
 *
 * @param[in]  clk  Clock type to query.
 *
 * @return     Clock frequency in Hz.
 *             Returns 0 if the clock source is disabled or undefined.
 *
 * @details
 * This function returns the current frequency of the specified clock
 * based on the system clock source selection and divider configuration.
 *
 * The following clocks are supported:
 *   - UPLL
 *   - APLL
 *   - SYSTEM (SYS_CLK)
 *   - HCLK
 *   - HCLK1
 *   - PCLK0
 *   - PCLK1
 *   - PCLK2
 *   - CPU
 *
 * The returned frequency is calculated according to the current clock
 * controller register settings.
 *
 * @note
 * This function assumes the external crystal clock (HXT) frequency is
 * 12 MHz.
 */
uint32_t CLK_GetClockFreq(CLOCK_Type clk)
{
    uint32_t clkfreq = 0U;
    uint32_t reg;
    uint32_t div;

    /* Get SYS_CLK source */
    reg = (CLK->DIVCTL0 & CLK_DIVCTL0_SYSTEM_S_Msk) >> CLK_DIVCTL0_SYSTEM_S_Pos;

    switch (reg)
    {
        case 0x0:  /* HXT */
            clkfreq = __HXT;
            break;

        case 0x2:  /* APLL */
            clkfreq = CLK_GetAPLLClockFreq();
            break;

        case 0x3:  /* UPLL */
            clkfreq = CLK_GetUPLLClockFreq();
            break;

        default:   /* Reserved or invalid */
            return 0U;
    }

    /* Return according to requested clock */
    switch (clk)
    {
        case CLK_UPLL:
            return CLK_GetUPLLClockFreq();

        case CLK_APLL:
            return CLK_GetAPLLClockFreq();

        case CLK_SYSTEM:
            return clkfreq;

        case CLK_CPU:
            div = ((CLK->DIVCTL0 & CLK_DIVCTL0_CPUDIV2EN_Msk) >>
                    CLK_DIVCTL0_CPUDIV2EN_Pos) + 1U;
            return clkfreq / div;

        case CLK_HCLK:
            /* HCLK = SYS_CLK / 2 */
            return clkfreq / 2U;

        case CLK_HCLK1:
            /* HCLK1 = HCLK / 2 */
            return clkfreq / 4U;

        case CLK_PCLK0:
            /* PCLK0 = HCLK */
            return clkfreq / 2U;

        case CLK_PCLK1:
            /* PCLK1 = HCLK */
            return clkfreq / 2U;

        case CLK_PCLK2:
            /* PCLK2 = HCLK / 2 */
            return clkfreq / 4U;

        default:
            return 0U;
    }
}

/**
 * @brief      Stop module clock
 *
 * @param[in]  req  Clock stop request selection.
 *
 * @details
 * This function requests to stop the clock of the specified CANFD module
 * by setting the corresponding STOPREQ bit and waits until the hardware
 * acknowledges that the clock has been stopped.
 *
 * The function blocks until the STOPACK status bit is set, indicating that
 * the module clock has been successfully stopped.
 *
 * @note
 * This function applies only to CANFD modules that support clock stop
 * request and acknowledge mechanism.
 * For other modules, clock stop is controlled by clock enable registers.
 */
void CLK_StopClock(CLK_Stop req)
{
    uint32_t timeout = 1000000U; /* simple timeout count */

    switch (req)
    {
        case STR_CANFD0:
            CLK->STOPREQ |= CLK_STOPREQ_CANFD0STR_Msk;
            while ((CLK->STOPACK & CLK_STOPACK_CANFD0STA_Msk) == 0U)
            {
                if (--timeout == 0U)
                    return;
            }
            break;

        case STR_CANFD1:
            CLK->STOPREQ |= CLK_STOPREQ_CANFD1STR_Msk;
            while ((CLK->STOPACK & CLK_STOPACK_CANFD1STA_Msk) == 0U)
            {
                if (--timeout == 0U)
                    return;
            }
            break;

        case STR_CANFD2:
            CLK->STOPREQ |= CLK_STOPREQ_CANFD2STR_Msk;
            while ((CLK->STOPACK & CLK_STOPACK_CANFD2STA_Msk) == 0U)
            {
                if (--timeout == 0U)
                    return;
            }
            break;

        case STR_CANFD3:
            CLK->STOPREQ |= CLK_STOPREQ_CANFD3STR_Msk;
            while ((CLK->STOPACK & CLK_STOPACK_CANFD3STA_Msk) == 0U)
            {
                if (--timeout == 0U)
                    return;
            }
            break;

        default:
            /* Invalid request, do nothing */
            break;
    }
}

/**
 * @brief      Start module clock
 *
 * @param[in]  req  Clock start request selection.
 *
 * @details
 * This function restarts the clock of the specified CANFD module by
 * clearing the corresponding STOPREQ bit and waits until the hardware
 * acknowledges that the clock has been resumed.
 *
 * The function blocks until the STOPACK status bit is cleared, indicating
 * that the module clock is running again.
 *
 * @note
 * This function applies only to CANFD modules that support the clock
 * stop/start request and acknowledge mechanism.
 * For other modules, clock control is managed by clock enable registers.
 */
void CLK_StartClock(CLK_Stop req)
{
    uint32_t timeout = 1000000U; /* simple timeout count */

    switch (req)
    {
        case STR_CANFD0:
            CLK->STOPREQ &= ~CLK_STOPREQ_CANFD0STR_Msk;
            while ((CLK->STOPACK & CLK_STOPACK_CANFD0STA_Msk) != 0U)
            {
                if (--timeout == 0U)
                    return;
            }
            break;

        case STR_CANFD1:
            CLK->STOPREQ &= ~CLK_STOPREQ_CANFD1STR_Msk;
            while ((CLK->STOPACK & CLK_STOPACK_CANFD1STA_Msk) != 0U)
            {
                if (--timeout == 0U)
                    return;
            }
            break;

        case STR_CANFD2:
            CLK->STOPREQ &= ~CLK_STOPREQ_CANFD2STR_Msk;
            while ((CLK->STOPACK & CLK_STOPACK_CANFD2STA_Msk) != 0U)
            {
                if (--timeout == 0U)
                    return;
            }
            break;

        case STR_CANFD3:
            CLK->STOPREQ &= ~CLK_STOPREQ_CANFD3STR_Msk;
            while ((CLK->STOPACK & CLK_STOPACK_CANFD3STA_Msk) != 0U)
            {
                if (--timeout == 0U)
                    return;
            }
            break;

        default:
            /* Invalid request, do nothing */
            break;
    }
}

/*@}*/ /* end of group CLK_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group CLK_Driver */

/*@}*/ /* end of group Standard_Driver */

