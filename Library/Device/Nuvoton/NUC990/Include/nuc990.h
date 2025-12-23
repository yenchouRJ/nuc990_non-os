/**************************************************************************//**
 * @file     nuc990.h
 * @brief    NUC990 peripheral access layer header file.
 *           This file contains all the peripheral register's definitions
 *           and memory mapping for NuMicro NUC990 MPU.
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
/**
   \mainpage NuMicro NUC990 Family Driver Reference Guide
   *
   * <b>Introduction</b>
   *
   * This user manual describes the usage of NUC990 family device driver
   *
   * <b>Disclaimer</b>
   *
   * The Software is furnished "AS IS", without warranty as to performance or results, and
   * the entire risk as to performance or results is assumed by YOU. Nuvoton disclaims all
   * warranties, express, implied or otherwise, with regard to the Software, its use, or
   * operation, including without limitation any and all warranties of merchantability, fitness
   * for a particular purpose, and non-infringement of intellectual property rights.
   *
   * <b>Important Notice</b>
   *
   * Nuvoton Products are neither intended nor warranted for usage in systems or equipment,
   * any malfunction or failure of which may cause loss of human life, bodily injury or severe
   * property damage. Such applications are deemed, "Insecure Usage".
   *
   * Insecure usage includes, but is not limited to: equipment for surgical implementation,
   * atomic energy control instruments, airplane or spaceship instruments, the control or
   * operation of dynamic, brake or safety systems designed for vehicular use, traffic signal
   * instruments, all types of safety devices, and other applications intended to support or
   * sustain life.
   *
   * All Insecure Usage shall be made at customer's risk, and in the event that third parties
   * lay claims to Nuvoton as a result of customer's Insecure Usage, customer shall indemnify
   * the damages and liabilities thus incurred by Nuvoton.
   *
   * Please note that all data and specifications are subject to change without notice. All the
   * trademarks of products and companies mentioned in this document belong to their respective
   * owners.
   *
   * <b>Copyright Notice</b>
   *
   * Copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
   */

#ifndef __NUC990_H__
#define __NUC990_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @details  Interrupt Number Definition.
 */
typedef enum IRQn
{
    WDT_IRQn             = 1,      /*! Watchdog Timer Interrupt                 */
    WWDT_IRQn            = 2,      /*! Windowed WDT Interrupt                   */
    LVD_IRQn             = 3,      /*! Low Voltage Detect Interrupt             */
    EXTI0_IRQn           = 4,      /*! External Interrupt 0                     */
    EXTI1_IRQn           = 5,      /*! External Interrupt 1                     */
    EXTI2_IRQn           = 6,      /*! External Interrupt 2                     */
    EXTI3_IRQn           = 7,      /*! External Interrupt 3                     */
    GPA_IRQn             = 8,      /*! GPIO A Interrupt                         */
    GPB_IRQn             = 9,      /*! GPIO B Interrupt                         */
    GPC_IRQn             = 10,     /*! GPIO C Interrupt                         */
    GPD_IRQn             = 11,     /*! GPIO D Interrupt                         */
    GPE_IRQn             = 12,     /*! GPIO E Interrupt                         */
    GPF_IRQn             = 13,     /*! GPIO F Interrupt                         */
    GPG_IRQn             = 14,     /*! GPIO G Interrupt                         */
    GPH_IRQn             = 15,     /*! GPIO H Interrupt                         */
    I2S_IRQn             = 16,     /*! I2S Interrupt                            */
    RTC_IRQn             = 17,     /*! RTC Interrupt                            */
    TIMER0_IRQn          = 18,     /*! Timer 0 interrupt                        */
    TIMER1_IRQn          = 19,     /*! Timer 1 interrupt                        */
    TIMER2_IRQn          = 20,     /*! Timer 2 interrupt                        */
    TIMER3_IRQn          = 21,     /*! Timer 3 interrupt                        */
    TIMER4_IRQn          = 22,     /*! Timer 4 interrupt                        */
    TIMER5_IRQn          = 23,     /*! Timer 5 interrupt                        */
    I2C0_IRQn            = 24,     /*! I2C 0 interrupt                          */
    I2C1_IRQn            = 25,     /*! I2C 1 interrupt                          */
    I2C2_IRQn            = 26,     /*! I2C 2 interrupt                          */
    I2C3_IRQn            = 27,     /*! I2C 3 interrupt                          */
    SMC0_IRQn            = 28,     /*! Smart Card 0 interrupt                   */
    SMC1_IRQn            = 29,     /*! Smart Card 1 interrupt                   */
    BPWM0_IRQn           = 30,     /*! BPWM0 interrupt                          */
    BPWM1_IRQn           = 31,     /*! BPWM1 interrupt                          */
    UART0_IRQn           = 32,     /*! UART 0 interrupt                         */
    UART1_IRQn           = 33,     /*! UART 1 interrupt                         */
    UART2_IRQn           = 34,     /*! UART 2 interrupt                         */
    UART3_IRQn           = 35,     /*! UART 3 interrupt                         */
    UART4_IRQn           = 36,     /*! UART 4 interrupt                         */
    UART5_IRQn           = 37,     /*! UART 5 interrupt                         */
    UART6_IRQn           = 38,     /*! UART 6 interrupt                         */
    UART7_IRQn           = 39,     /*! UART 7 interrupt                         */
    UART8_IRQn           = 40,     /*! UART 8 interrupt                         */
    UART9_IRQn           = 41,     /*! UART 9 interrupt                         */
    ADC_IRQn             = 42,     /*! ADC interrupt                            */
    EADC00_IRQn          = 43,     /*! EADC interrupt 0                         */
    EADC01_IRQn          = 44,     /*! EADC interrupt 1                         */
    EADC02_IRQn          = 45,     /*! EADC interrupt 2                         */
    EADC03_IRQn          = 46,     /*! EADC interrupt 3                         */
    QSPI0_IRQn           = 47,     /*! QSPI 0 interrupt                         */
    SPI0_IRQn            = 48,     /*! SPI 0 interrupt                          */
    SPI1_IRQn            = 49,     /*! SPI 1 interrupt                          */
    SPI2_IRQn            = 50,     /*! SPI 2 interrupt                          */
    SPI3_IRQn            = 51,     /*! SPI 3 interrupt                          */
    PDMA0_IRQn           = 52,     /*! PDMA Channel Interrupt                   */
    PDMA1_IRQn           = 53,     /*! PDMA Channel Interrupt                   */
    EHCI_IRQn            = 54,     /*! USB 2.0 Host Controller Interrupt        */
    OHCI_IRQn            = 55,     /*! USB 1.1 Host Controller Interrupt        */
    UDC_IRQn             = 56,     /*! USB Device Controller Interrupt          */
    SDH0_IRQn            = 57,     /*! SD/SDIO Host 0 Interrupt                 */
    SDH1_IRQn            = 58,     /*! SD/SDIO Host 1 Interrupt                 */
    NAND_IRQn            = 59,     /*! NAND Flash Controller Interrupt          */
    EMAC0_RX_IRQn        = 60,     /*! EMAC 0 RX Interrupt                      */
    EMAC0_TX_IRQn        = 61,     /*! EMAC 0 TX Interrupt                      */
    EMAC1_RX_IRQn        = 62,     /*! EMAC 1 RX Interrupt                      */
    EMAC1_TX_IRQn        = 63,     /*! EMAC 1 TX Interrupt                      */
    CAN0_IRQn            = 64,     /*! CAN 0 Interrupt                          */
    CAN1_IRQn            = 65,     /*! CAN 1 Interrupt                          */
    CAN2_IRQn            = 66,     /*! CAN 2 Interrupt                          */
    CAN3_IRQn            = 67,     /*! CAN 3 Interrupt                          */
    CANFD00_IRQn         = 72,     /*! CAN FD 0 Interrupt 0                     */
    CANFD01_IRQn         = 73,     /*! CAN FD 0 Interrupt 1                     */
    CANFD10_IRQn         = 74,     /*! CAN FD 1 Interrupt 0                     */
    CANFD11_IRQn         = 75,     /*! CAN FD 1 Interrupt 1                     */
    CANFD20_IRQn         = 76,     /*! CAN FD 2 Interrupt 0                     */
    CANFD21_IRQn         = 77,     /*! CAN FD 2 Interrupt 1                     */
    CANFD30_IRQn         = 78,     /*! CAN FD 3 Interrupt 0                     */
    CANFD31_IRQn         = 79,     /*! CAN FD 3 Interrupt 1                     */
    CRYPTO_IRQn          = 80,     /*! CRYPTO Engine Interrupt                  */
    KS_IRQn              = 81,     /*! Key Store Interrupt                      */
} IRQn_Type;

/******************************************************************************/
/*                            Register definitions                            */
/******************************************************************************/
#include "adc_reg.h"
#include "aic_reg.h"
#include "bpwm_reg.h"
#include "can_reg.h"
#include "canfd_reg.h"
#include "clk_reg.h"
#include "crypto_reg.h"
#include "ebi_reg.h"
#include "emac_reg.h"
#include "gpio_reg.h"
#include "hsusbh_reg.h"
#include "i2c_reg.h"
#include "i2s_reg.h"
#include "nfi_reg.h"
#include "keystore_reg.h"
#include "otp_reg.h"
#include "pdma_reg.h"
#include "qspi_reg.h"
#include "rtc_reg.h"
#include "sc_reg.h"
#include "sdh_reg.h"
#include "sys_reg.h"
#include "timer_reg.h"
#include "uart_reg.h"
#include "usbd_reg.h"
#include "usbh_reg.h"
#include "wdt_reg.h"
#include "wwdt_reg.h"

/** @addtogroup NUC990_PERIPHERAL_MEM_MAP Peripheral Memory Base
  Memory Mapped Structure for NUC990 Peripheral
  @{
 */

/*!< AHB peripherals */
#define SYS_BASE         0xB0000000
#define CLK_BASE         0xB0000200
#define SDIC_BASE        0xB0002000
#define GPIO_BASE        0xB0004000
#define PDMA0_BASE       0xB0008000
#define PDMA1_BASE       0xB0009000
#define EBI_BASE         0xB0010000
#define EMAC0_BASE       0xB0012000
#define EMAC1_BASE       0xB0022000
#define OTP_BASE         0xB0025000
#define HSUSBH_BASE      0xB0015000
#define USBD_BASE        0xB0016000
#define USBH_BASE        0xB0017000
#define SDH0_BASE        0xB001A000
#define SDH1_BASE        0xB0018000
#define NFI_BASE         0xB0019000
#define SDH0_BASE        0xB001A000
#define CRYPTO_BASE      0xB001C000
#define KEYSTORE_BASE    0xB001F000
#define I2S_BASE         0xB0020000

#define PA_BASE          0xB0004000
#define PB_BASE          0xB0004040
#define PC_BASE          0xB0004080
#define PD_BASE          0xB00040C0
#define PE_BASE          0xB0004100
#define PF_BASE          0xB0004140
#define PG_BASE          0xB0004180
#define PH_BASE          0xB00041C0

/*!< APB peripherals */

#define WDT_BASE         0xB0040000
#define WWDT_BASE        0xB0040100
#define RTC_BASE         0xB0041000
#define AIC_BASE         0xB0042000
#define ADC_BASE         0xB0043000
#define TIMER01_BASE     0xB0050000
#define TIMER0_BASE      0xB0050000
#define TIMER1_BASE      0xB0050100
#define TIMER23_BASE     0xB0051000
#define TIMER2_BASE      0xB0051000
#define TIMER3_BASE      0xB0051100
#define TIMER45_BASE     0xB0052000
#define TIMER4_BASE      0xB0052000
#define TIMER5_BASE      0xB0052100
#define PWM0_BASE        0xB0058000
#define PWM1_BASE        0xB0059000
#define BPWM0_BASE       0xB0058000
#define BPWM1_BASE       0xB0059000
#define QSPI0_BASE       0xB0060000
#define SPI0_BASE        0xB0061000
#define SPI1_BASE        0xB0062000
#define SPI2_BASE        0xB0063000
#define SPI3_BASE        0xB0064000
#define UART0_BASE       0xB0070000
#define UART1_BASE       0xB0071000
#define UART2_BASE       0xB0072000
#define UART3_BASE       0xB0073000
#define UART4_BASE       0xB0074000
#define UART5_BASE       0xB0075000
#define UART6_BASE       0xB0076000
#define UART7_BASE       0xB0077000
#define UART8_BASE       0xB0078000
#define UART9_BASE       0xB0079000
#define I2C0_BASE        0xB0080000
#define I2C1_BASE        0xB0081000
#define I2C2_BASE        0xB0082000
#define I2C3_BASE        0xB0083000
#define SC0_BASE         0xB0090000
#define SC1_BASE         0xB0091000
#define CAN0_BASE        0xB00A0000
#define CAN1_BASE        0xB00A1000
#define CAN2_BASE        0xB00A2000
#define CAN3_BASE        0xB00A3000
#define CAN4_BASE        0xB00A4000
#define CAN5_BASE        0xB00A5000
#define CAN6_BASE        0xB00A6000
#define CAN7_BASE        0xB00A7000
#define CANFD0_BASE      0xB0100000
#define CANFD1_BASE      0xB0110000
#define CANFD2_BASE      0xB0120000
#define CANFD3_BASE      0xB0130000

/*@}*/ /* end of group NUC990_PERIPHERAL_MEM_MAP */

/******************************************************************************/
/*                         Peripheral Declaration                             */
/******************************************************************************/

/** @addtogroup PERIPHERAL_DECLARATION Peripheral Pointer
  The Declaration of Peripheral Pointer
  @{
 */
#define SYS              ((SYS_T *)          SYS_BASE)
#define CLK              ((CLK_T *)          CLK_BASE)
#define SDIC             ((SDIC_T *)         SDIC_BASE)
#define GPIO             ((GPIO_DBCTL_T *)   GPIO_DBCTL_BASE)
#define PDMA0            ((PDMA_T *)         PDMA0_BASE)
#define PDMA1            ((PDMA_T *)         PDMA1_BASE)
#define EBI              ((EBI_T *)          EBI_BASE)
#define EMAC0            ((EMAC_T *)         EMAC0_BASE)
#define EMAC1            ((EMAC_T *)         EMAC1_BASE)
#define USBD             ((USBD_T *)         USBD_BASE)
#define OTP              ((OTP_T *)          OTP_BASE)
#define USBH             ((USBH_T *)         USBH_BASE)
#define HSUSBH           ((HSUSBH_T *)       HSUSBH_BASE)
#define SDH0             ((SDH_T *)          SDH0_BASE)
#define SDH1             ((SDH_T *)          SDH1_BASE)
#define NFI              ((NFI_T *)          NFI_BASE)
#define CRYPTO           ((CRYPTO_T *)       CRYPTO_BASE)
#define I2S              ((I2S_T *)          I2S_BASE)
#define KS               ((KS_T *)           KEYSTORE_BASE)
#define PA               ((GPIO_T *)         PA_BASE)
#define PB               ((GPIO_T *)         PB_BASE)
#define PC               ((GPIO_T *)         PC_BASE)
#define PD               ((GPIO_T *)         PD_BASE)
#define PE               ((GPIO_T *)         PE_BASE)
#define PF               ((GPIO_T *)         PF_BASE)
#define PG               ((GPIO_T *)         PG_BASE)
#define PH               ((GPIO_T *)         PH_BASE)
#define WDT              ((WDT_T *)          WDT_BASE)
#define WWDT             ((WWDT_T *)         WWDT_BASE)
#define RTC              ((RTC_T *)          RTC_BASE)
#define AIC              ((AIC_T *)          AIC_BASE)
#define ADC              ((ADC_T *)          ADC_BASE)
#define TIMER0           ((TIMER_T *)        TIMER0_BASE)
#define TIMER1           ((TIMER_T *)        TIMER1_BASE)
#define TIMER2           ((TIMER_T *)        TIMER2_BASE)
#define TIMER3           ((TIMER_T *)        TIMER3_BASE)
#define TIMER4           ((TIMER_T *)        TIMER4_BASE)
#define TIMER5           ((TIMER_T *)        TIMER5_BASE)
#define PWM0             ((PWM_T *)          PWM0_BASE)
#define PWM1             ((PWM_T *)          PWM1_BASE)
#define BPWM0            ((BPWM_T *)         BPWM0_BASE)
#define BPWM1            ((BPWM_T *)         BPWM1_BASE)
#define QSPI0            ((QSPI_T *)         QSPI0_BASE)
#define SPI0             ((SPI_T *)          SPI0_BASE)
#define SPI1             ((SPI_T *)          SPI1_BASE)
#define SPI2             ((SPI_T *)          SPI2_BASE)
#define SPI3             ((SPI_T *)          SPI3_BASE)
#define UART0            ((UART_T *)         UART0_BASE)
#define UART1            ((UART_T *)         UART1_BASE)
#define UART2            ((UART_T *)         UART2_BASE)
#define UART3            ((UART_T *)         UART3_BASE)
#define UART4            ((UART_T *)         UART4_BASE)
#define UART5            ((UART_T *)         UART5_BASE)
#define UART6            ((UART_T *)         UART6_BASE)
#define UART7            ((UART_T *)         UART7_BASE)
#define UART8            ((UART_T *)         UART8_BASE)
#define UART9            ((UART_T *)         UART9_BASE)
#define I2C0             ((I2C_T *)          I2C0_BASE)
#define I2C1             ((I2C_T *)          I2C1_BASE)
#define I2C2             ((I2C_T *)          I2C2_BASE)
#define I2C3             ((I2C_T *)          I2C3_BASE)
#define SC0              ((SC_T *)           SC0_BASE)
#define SC1              ((SC_T *)           SC1_BASE)
#define CAN0             ((CAN_T *)          CAN0_BASE)
#define CAN1             ((CAN_T *)          CAN1_BASE)
#define CAN2             ((CAN_T *)          CAN2_BASE)
#define CAN3             ((CAN_T *)          CAN3_BASE)
#define CANFD0           ((CANFD_T *)        CANFD0_BASE)
#define CANFD1           ((CANFD_T *)        CANFD1_BASE)
#define CANFD2           ((CANFD_T *)        CANFD2_BASE)
#define CANFD3           ((CANFD_T *)        CANFD3_BASE)

/*@}*/ /* end of group PERIPHERAL_DECLARATION */

/** @addtogroup IO_ROUTINE  I/O Routines
  The Declaration of NUC990 I/O Routines
  @{
 */

typedef volatile unsigned char  vu8;   /*!< Define 8-bit unsigned volatile data type    */
typedef volatile unsigned short vu16;  /*!< Define 16-bit unsigned volatile data type   */
typedef volatile unsigned long  vu32;  /*!< Define 32-bit unsigned volatile data type   */

/**
  * @brief Get a 8-bit unsigned value from specified address
  * @param[in] addr Address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified address
  */
#define M8(addr)  (*((vu8  *) (addr)))

/**
  * @brief Get a 16-bit unsigned value from specified address
  * @param[in] addr Address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified address
  * @note The input address must be 16-bit aligned
  */
#define M16(addr) (*((vu16 *) (addr)))

/**
  * @brief Get a 32-bit unsigned value from specified address
  * @param[in] addr Address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified address
  * @note The input address must be 32-bit aligned
  */
#define M32(addr) (*((vu32 *) (addr)))

/**
  * @brief Set a 32-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 32-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 32-bit aligned
  */
#define outpw(port,value)     *((volatile unsigned int *)(port)) = value

/**
  * @brief Get a 32-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified I/O port
  * @note The input port must be 32-bit aligned
  */
#define inpw(port)            (*((volatile unsigned int *)(port)))

/**
  * @brief Set a 16-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 16-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 16-bit aligned
  */
#define outps(port,value)     *((volatile unsigned short *)(port)) = value

/**
  * @brief Get a 16-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified I/O port
  * @note The input port must be 16-bit aligned
  */
#define inps(port)            (*((volatile unsigned short *)(port)))

/**
  * @brief Set a 8-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 8-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  */
#define outpb(port,value)     *((volatile unsigned char *)(port)) = value

/**
  * @brief Get a 8-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified I/O port
  */
#define inpb(port)            (*((volatile unsigned char *)(port)))

/**
  * @brief Set a 32-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 32-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 32-bit aligned
  */
#define outp32(port,value)    *((volatile unsigned int *)(port)) = value

/**
  * @brief Get a 32-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified I/O port
  * @note The input port must be 32-bit aligned
  */
#define inp32(port)           (*((volatile unsigned int *)(port)))

/**
  * @brief Set a 16-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 16-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 16-bit aligned
  */
#define outp16(port,value)    *((volatile unsigned short *)(port)) = value

/**
  * @brief Get a 16-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified I/O port
  * @note The input port must be 16-bit aligned
  */
#define inp16(port)           (*((volatile unsigned short *)(port)))

/**
  * @brief Set a 8-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 8-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  */
#define outp8(port,value)     *((volatile unsigned char *)(port)) = value

/**
  * @brief Get a 8-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified I/O port
  */
#define inp8(port)            (*((volatile unsigned char *)(port)))

/*@}*/ /* end of group IO_ROUTINE */

/******************************************************************************/
/*                Legacy Constants                                            */
/******************************************************************************/
/** @addtogroup Legacy_Constants Legacy Constants
  NUC990 Legacy Constants
  @{
*/
typedef void *                 PVOID;   /*!< Define void pointer data type              */
typedef void                   VOID;    /*!< Define void data type                      */
typedef char                   BOOL;    /*!< Define bool data type                      */
typedef char *                 PBOOL;   /*!< Define bool pointer data type              */

typedef char                   INT8;    /*!< Define 8-bit singed data type              */
typedef char                   CHAR;    /*!< Define char data type                      */
typedef char *                 PINT8;   /*!< Define 8-bit singed pointer data type      */
typedef char *                 PCHAR;   /*!< Define char pointer data type              */
typedef unsigned char          UINT8;   /*!< Define 8-bit unsigned data type            */
typedef unsigned char          UCHAR;   /*!< Define char unsigned data type             */
typedef unsigned char *        PUINT8;  /*!< Define 8-bit unsigned pointer data type    */
typedef unsigned char *        PUCHAR;  /*!< Define char unsigned pointer data type     */
typedef char *                 PSTR;    /*!< Define string pointer data type            */
typedef const char *           PCSTR;   /*!< Define constant string pointer data type   */

typedef short                  SHORT;   /*!< Define short signed data type              */
typedef short *                PSHORT;  /*!< Define short signed pointer data type      */
typedef unsigned short         USHORT;  /*!< Define short unsigned data type            */
typedef unsigned short *       PUSHORT; /*!< Define short unsigned pointer data type    */

typedef short                  INT16;   /*!< Define 16-bit signed data type             */
typedef short *                PINT16;  /*!< Define 16-bit signed pointer data type     */
typedef unsigned short         UINT16;  /*!< Define 16-bit unsigned data type           */
typedef unsigned short *       PUINT16; /*!< Define 16-bit unsigned pointer data type   */

typedef int                    INT;     /*!< Define integer signed data type            */
typedef int *                  PINT;    /*!< Define integer signed pointer data type    */
typedef unsigned int           UINT;    /*!< Define integer unsigned data type          */
typedef unsigned int *         PUINT;   /*!< Define integer unsigned pointer data type  */

typedef int                    INT32;   /*!< Define 32-bit signed data type             */
typedef int *                  PINT32;  /*!< Define 32-bit signed pointer data type     */
typedef unsigned int           UINT32;  /*!< Define 32-bit unsigned data type           */
typedef unsigned int *         PUINT32; /*!< Define 32-bit unsigned pointer data type   */

#if defined (__GNUC__) && !(__CC_ARM)
typedef long long           INT64;
typedef unsigned long long  UINT64;
#else
typedef __int64                INT64;   /*!< Define 64-bit signed data type             */
typedef unsigned __int64       UINT64;  /*!< Define 64-bit unsigned data type           */
#endif

typedef float                  FLOAT;   /*!< Define float data type                     */
typedef float *                PFLOAT;  /*!< Define float pointer data type             */

typedef double                 DOUBLE;  /*!< Define double data type                    */
typedef double *               PDOUBLE; /*!< Define double pointer data type            */

typedef int                    SIZE_T;  /*!< Define size of data type                   */

typedef unsigned char          REG8;    /*!< Define 8-bit register data type            */
typedef unsigned short         REG16;   /*!< Define 16-bit register data type           */
typedef unsigned int           REG32;   /*!< Define 32-bit register data type           */


#ifndef NULL
#define NULL                   (0)      /*!< NULL pointer                               */
#endif

#define TRUE                   (1)      /*!< Boolean true, define to use in API parameters or return value  */
#define FALSE                  (0)      /*!< Boolean false, define to use in API parameters or return value */

#define ENABLE                 (1)      /*!< Enable, define to use in API parameters    */
#define DISABLE                (0)      /*!< Disable, define to use in API parameters   */


#define Successful             0        /*!< Function return value success              */
#define Fail                   1        /*!< Function return value failed               */

/* Define one bit mask */
#define BIT0                   (0x00000001)  /*!< Bit 0 mask of an 32 bit integer       */
#define BIT1                   (0x00000002)  /*!< Bit 1 mask of an 32 bit integer       */
#define BIT2                   (0x00000004)  /*!< Bit 2 mask of an 32 bit integer       */
#define BIT3                   (0x00000008)  /*!< Bit 3 mask of an 32 bit integer       */
#define BIT4                   (0x00000010)  /*!< Bit 4 mask of an 32 bit integer       */
#define BIT5                   (0x00000020)  /*!< Bit 5 mask of an 32 bit integer       */
#define BIT6                   (0x00000040)  /*!< Bit 6 mask of an 32 bit integer       */
#define BIT7                   (0x00000080)  /*!< Bit 7 mask of an 32 bit integer       */
#define BIT8                   (0x00000100)  /*!< Bit 8 mask of an 32 bit integer       */
#define BIT9                   (0x00000200)  /*!< Bit 9 mask of an 32 bit integer       */
#define BIT10                  (0x00000400)  /*!< Bit 10 mask of an 32 bit integer      */
#define BIT11                  (0x00000800)  /*!< Bit 11 mask of an 32 bit integer      */
#define BIT12                  (0x00001000)  /*!< Bit 12 mask of an 32 bit integer      */
#define BIT13                  (0x00002000)  /*!< Bit 13 mask of an 32 bit integer      */
#define BIT14                  (0x00004000)  /*!< Bit 14 mask of an 32 bit integer      */
#define BIT15                  (0x00008000)  /*!< Bit 15 mask of an 32 bit integer      */
#define BIT16                  (0x00010000)  /*!< Bit 16 mask of an 32 bit integer      */
#define BIT17                  (0x00020000)  /*!< Bit 17 mask of an 32 bit integer      */
#define BIT18                  (0x00040000)  /*!< Bit 18 mask of an 32 bit integer      */
#define BIT19                  (0x00080000)  /*!< Bit 19 mask of an 32 bit integer      */
#define BIT20                  (0x00100000)  /*!< Bit 20 mask of an 32 bit integer      */
#define BIT21                  (0x00200000)  /*!< Bit 21 mask of an 32 bit integer      */
#define BIT22                  (0x00400000)  /*!< Bit 22 mask of an 32 bit integer      */
#define BIT23                  (0x00800000)  /*!< Bit 23 mask of an 32 bit integer      */
#define BIT24                  (0x01000000)  /*!< Bit 24 mask of an 32 bit integer      */
#define BIT25                  (0x02000000)  /*!< Bit 25 mask of an 32 bit integer      */
#define BIT26                  (0x04000000)  /*!< Bit 26 mask of an 32 bit integer      */
#define BIT27                  (0x08000000)  /*!< Bit 27 mask of an 32 bit integer      */
#define BIT28                  (0x10000000)  /*!< Bit 28 mask of an 32 bit integer      */
#define BIT29                  (0x20000000)  /*!< Bit 29 mask of an 32 bit integer      */
#define BIT30                  (0x40000000)  /*!< Bit 30 mask of an 32 bit integer      */
#define BIT31                  (0x80000000)  /*!< Bit 31 mask of an 32 bit integer      */

/* Byte Mask Definitions */
#define BYTE0_Msk              (0x000000FF)  /*!< Mask to get bit0~bit7 from a 32 bit integer   */
#define BYTE1_Msk              (0x0000FF00)  /*!< Mask to get bit8~bit15 from a 32 bit integer  */
#define BYTE2_Msk              (0x00FF0000)  /*!< Mask to get bit16~bit23 from a 32 bit integer */
#define BYTE3_Msk              (0xFF000000)  /*!< Mask to get bit24~bit31 from a 32 bit integer */

#define GET_BYTE0(u32Param)    ((u32Param & BYTE0_Msk)      )  /*!< Extract Byte 0 (Bit  0~ 7) from parameter u32Param */
#define GET_BYTE1(u32Param)    ((u32Param & BYTE1_Msk) >>  8)  /*!< Extract Byte 1 (Bit  8~15) from parameter u32Param */
#define GET_BYTE2(u32Param)    ((u32Param & BYTE2_Msk) >> 16)  /*!< Extract Byte 2 (Bit 16~23) from parameter u32Param */
#define GET_BYTE3(u32Param)    ((u32Param & BYTE3_Msk) >> 24)  /*!< Extract Byte 3 (Bit 24~31) from parameter u32Param */

#ifdef __cplusplus
#define __I     volatile       /*!< Defines 'read only' permissions                     */
#else
#define __I     volatile const /*!< Defines 'read only' permissions                     */
#endif
#define __O     volatile       /*!< Defines 'write only' permissions                    */
#define __IO    volatile       /*!< Defines 'read / write' permissions                  */

#define NON_CACHE_MASK         (0x80000000U)

#define __HXT                  (12000000UL)    /*!< External Crystal Clock Frequency     */
#define __LXT                  (32768UL)       /*!< External Crystal Clock Frequency 32.768KHz */

/******************************************************************************/
/*                         Peripheral header files                            */
/******************************************************************************/
#include "adc.h"
#include "aic.h"
#include "bpwm.h"
#include "can.h"
#include "canfd.h"
#include "clk.h"
#include "crypto.h"
#include "ebi.h"
#include "emac.h"
#include "gpio.h"
#include "hsusbh.h"
#include "i2c.h"
#include "i2s.h"
#include "nfi.h"
#include "keystore.h"
#include "otp.h"
#include "pdma.h"
#include "qspi.h"
#include "rtc.h"
#include "sc.h"
#include "sdh.h"
#include "sys.h"
#include "timer.h"
#include "uart.h"
#include "usbd.h"
#include "usbh.h"
#include "wdt.h"
#include "wwdt.h"

/*@}*/ /* end of group Legacy_Constants */

#ifdef __cplusplus
}
#endif

#endif /* __NUC990_H__ */
