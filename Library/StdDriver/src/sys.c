/**************************************************************************//**
 * @file     sys.c
 * @brief    SYS driver source file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#include <stdio.h>
#include "NuMicro.h"
#include "sys.h"

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup SYS_Driver SYS Driver
  @{
*/

/** @addtogroup SYS_EXPORTED_CONSTANTS SYS Exported Constants
  @{
*/

#define AIC_MIN_INT_SOURCE       1
#define AIC_MAX_INT_SOURCE       82
#define AIC_NUM_OF_AICREG        16  // ..... check

/* Global variables */
UINT32 volatile _sys_bIsAICInitial = 0;

/* declaration the function prototype */
void IRQ_Shell(void);
void FIQ_Shell(void);

/* Interrupt Handler Table */
sys_pvFunPtr IrqHandlerTable[AIC_MAX_INT_SOURCE+1] = {
                                      0,           /* 0, Reserved */
                                      IRQ_Shell,   /* 1 */
                                      IRQ_Shell,   /* 2 */
                                      IRQ_Shell,   /* 3 */
                                      IRQ_Shell,   /* 4 */
                                      IRQ_Shell,   /* 5 */
                                      IRQ_Shell,   /* 6 */
                                      IRQ_Shell,   /* 7 */
                                      IRQ_Shell,   /* 8 */
                                      IRQ_Shell,   /* 9 */
                                      IRQ_Shell,   /* 10 */
                                      IRQ_Shell,   /* 11 */
                                      IRQ_Shell,   /* 12 */
                                      IRQ_Shell,   /* 13 */
                                      IRQ_Shell,   /* 14 */
                                      IRQ_Shell,   /* 15 */
                                      IRQ_Shell,   /* 16 */
                                      IRQ_Shell,   /* 17 */
                                      IRQ_Shell,   /* 18 */
                                      IRQ_Shell,   /* 19 */
                                      IRQ_Shell,   /* 20 */
                                      IRQ_Shell,   /* 21 */
                                      IRQ_Shell,   /* 22 */
                                      IRQ_Shell,   /* 23 */
                                      IRQ_Shell,   /* 24 */
                                      IRQ_Shell,   /* 25 */
                                      IRQ_Shell,   /* 26 */
                                      IRQ_Shell,   /* 27 */
                                      IRQ_Shell,   /* 28 */
                                      IRQ_Shell,   /* 29 */
                                      IRQ_Shell,   /* 30 */
                                      IRQ_Shell,   /* 31 */
                                      IRQ_Shell,   /* 32 */
                                      IRQ_Shell,   /* 33 */
                                      IRQ_Shell,   /* 34 */
                                      IRQ_Shell,   /* 35 */
                                      IRQ_Shell,   /* 36 */
                                      IRQ_Shell,   /* 37 */
                                      IRQ_Shell,   /* 38 */
                                      IRQ_Shell,   /* 39 */
                                      IRQ_Shell,   /* 40 */
                                      IRQ_Shell,   /* 41 */
                                      IRQ_Shell,   /* 42 */
                                      IRQ_Shell,   /* 43 */
                                      IRQ_Shell,   /* 44 */
                                      IRQ_Shell,   /* 45 */
                                      IRQ_Shell,   /* 46 */
                                      IRQ_Shell,   /* 47 */
                                      IRQ_Shell,   /* 48 */
                                      IRQ_Shell,   /* 49 */
                                      IRQ_Shell,   /* 50 */
                                      IRQ_Shell,   /* 51 */
                                      IRQ_Shell,   /* 52 */
                                      IRQ_Shell,   /* 53 */
                                      IRQ_Shell,   /* 54 */
                                      IRQ_Shell,   /* 55 */
                                      IRQ_Shell,   /* 56 */
                                      IRQ_Shell,   /* 57 */
                                      IRQ_Shell,   /* 58 */
                                      IRQ_Shell,   /* 59 */
                                      IRQ_Shell,   /* 60 */
                                      IRQ_Shell,   /* 61 */
                                      IRQ_Shell,   /* 62 */
                                      IRQ_Shell,   /* 63 */
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell,
									  IRQ_Shell    /* 82 */
                                    };

sys_pvFunPtr FiqHandlerTable[AIC_MAX_INT_SOURCE+1] = {
                                      0,           /* 0, Reserved */
                                      FIQ_Shell,   /* 1 */
                                      FIQ_Shell,   /* 2 */
                                      FIQ_Shell,   /* 3 */
                                      FIQ_Shell,   /* 4 */
                                      FIQ_Shell,   /* 5 */
                                      FIQ_Shell,   /* 6 */
                                      FIQ_Shell,   /* 7 */
                                      FIQ_Shell,   /* 8 */
                                      FIQ_Shell,   /* 9 */
                                      FIQ_Shell,   /* 10 */
                                      FIQ_Shell,   /* 11 */
                                      FIQ_Shell,   /* 12 */
                                      FIQ_Shell,   /* 13 */
                                      FIQ_Shell,   /* 14 */
                                      FIQ_Shell,   /* 15 */
                                      FIQ_Shell,   /* 16 */
                                      FIQ_Shell,   /* 17 */
                                      FIQ_Shell,   /* 18 */
                                      FIQ_Shell,   /* 19 */
                                      FIQ_Shell,   /* 20 */
                                      FIQ_Shell,   /* 21 */
                                      FIQ_Shell,   /* 22 */
                                      FIQ_Shell,   /* 23 */
                                      FIQ_Shell,   /* 24 */
                                      FIQ_Shell,   /* 25 */
                                      FIQ_Shell,   /* 26 */
                                      FIQ_Shell,   /* 27 */
                                      FIQ_Shell,   /* 28 */
                                      FIQ_Shell,   /* 29 */
                                      FIQ_Shell,   /* 30 */
                                      FIQ_Shell,   /* 31 */
                                      FIQ_Shell,   /* 32 */
                                      FIQ_Shell,   /* 33 */
                                      FIQ_Shell,   /* 34 */
                                      FIQ_Shell,   /* 35 */
                                      FIQ_Shell,   /* 36 */
                                      FIQ_Shell,   /* 37 */
                                      FIQ_Shell,   /* 38 */
                                      FIQ_Shell,   /* 39 */
                                      FIQ_Shell,   /* 40 */
                                      FIQ_Shell,   /* 41 */
                                      FIQ_Shell,   /* 42 */
                                      FIQ_Shell,   /* 43 */
                                      FIQ_Shell,   /* 44 */
                                      FIQ_Shell,   /* 45 */
                                      FIQ_Shell,   /* 46 */
                                      FIQ_Shell,   /* 47 */
                                      FIQ_Shell,   /* 48 */
                                      FIQ_Shell,   /* 49 */
                                      FIQ_Shell,   /* 50 */
                                      FIQ_Shell,   /* 51 */
                                      FIQ_Shell,   /* 52 */
                                      FIQ_Shell,   /* 53 */
                                      FIQ_Shell,   /* 54 */
                                      FIQ_Shell,   /* 55 */
                                      FIQ_Shell,   /* 56 */
                                      FIQ_Shell,   /* 57 */
                                      FIQ_Shell,   /* 58 */
                                      FIQ_Shell,   /* 59 */
                                      FIQ_Shell,   /* 60 */
                                      FIQ_Shell,   /* 61 */
                                      FIQ_Shell,   /* 62 */
                                      FIQ_Shell,   /* 63 */
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell,
									  FIQ_Shell    /* 82 */
                                    };

/* Interrupt Handler */
#if defined (__GNUC__) && !(__CC_ARM)
static void __attribute__ ((interrupt("IRQ"))) IrqHandler(void)
#else
__irq void IrqHandler()
#endif
{
    UINT32 volatile num;

    num = AIC->IRQ;
    if (num != 0)
        (*IrqHandlerTable[num])();

    AIC->IRQRST = 1;
}

#if defined (__GNUC__) && !(__CC_ARM)
static void __attribute__ ((interrupt("FIQ"))) FiqHandler(void)
#else
__irq void FiqHandler()
#endif
{
    UINT32 volatile num;

    num = AIC->FIQ;
    if (num != 0)
        (*FiqHandlerTable[num])();

    AIC->FIQRST = 1;
}

void IRQ_Shell(void)
{
    printf("ISR not found! IRQ_Num=%d\n", AIC->IRQ);
}

void FIQ_Shell(void)
{
    printf("ISR not found! FIQ_Num=%d\n", AIC->FIQ);
}

void sysInitializeAIC()
{
    *(unsigned int volatile *)0x38 = (unsigned int)IrqHandler;
    *(unsigned int volatile *)0x3C = (unsigned int)FiqHandler;
}

/*@}*/ /* end of group SYS_EXPORTED_CONSTANTS */


/** @addtogroup SYS_EXPORTED_FUNCTIONS SYS Exported Functions
  @{
*/

/* Interrupt library functions */
/**
 *  @brief  system AIC - disable interrupt
 *
 *  @param[in]  eIntNo  Select interrupt source.  \ref IRQn_Type
 *
 *  @return   0
 */
INT32 sysDisableInterrupt(IRQn_Type eIntNo)
{
    if ((eIntNo > AIC_MAX_INT_SOURCE) || (eIntNo < AIC_MIN_INT_SOURCE))
        return Fail;

    AIC->IDIS[eIntNo / 32] = 1UL << (eIntNo % 32UL);

    return Successful;
}

/**
 *  @brief  system AIC - enable interrupt
 *
 *  @param[in]  eIntNo  Select interrupt source.  \ref IRQn_Type
 *
 *  @return   0
 */
INT32 sysEnableInterrupt(IRQn_Type eIntNo)
{
    if ((eIntNo > AIC_MAX_INT_SOURCE) || (eIntNo < AIC_MIN_INT_SOURCE))
        return Fail;

    AIC->IEN[eIntNo / 32] = 1UL << (eIntNo % 32UL);

    return Successful;
}

/**
 *  @brief  system AIC - install exception handler
 *
 *  @param[in]  nExceptType  exception type. ( \ref SYS_SWI / \ref SYS_D_ABORT / \ref SYS_I_ABORT / \ref SYS_UNDEFINE)
 *  @param[in]  pvNewHandler  own exception handler
 *
 *  @return   old handler
 */
PVOID sysInstallExceptionHandler(INT32 nExceptType, PVOID pvNewHandler)
{
    PVOID _mOldVect = NULL;

    switch (nExceptType)
    {
		case SYS_SWI:
			_mOldVect = *(PVOID volatile *)0x28;
			*(PVOID volatile *)0x28 = pvNewHandler;
			break;

		case SYS_D_ABORT:
			_mOldVect = *(PVOID volatile *)0x30;
			*(PVOID volatile *)0x30 = pvNewHandler;
			break;

		case SYS_I_ABORT:
			_mOldVect = *(PVOID volatile *)0x2C;
			*(PVOID volatile *)0x2C = pvNewHandler;
			break;

		case SYS_UNDEFINE:
			_mOldVect = *(PVOID volatile *)0x24;
			*(PVOID volatile *)0x24 = pvNewHandler;
			break;

		default:
			;
    }
    return _mOldVect;
}

/**
 *  @brief  system AIC - install FIQ handler
 *
 *  @param[in]  pvNewISR  own fiq handler
 *
 *  @return   old handler
 */
PVOID sysInstallFiqHandler(PVOID pvNewISR)
{
    PVOID _mOldVect;

    _mOldVect = *(PVOID volatile *)0x3C;
    *(PVOID volatile *)0x3C = pvNewISR;
    return _mOldVect;
}

/**
 *  @brief  system AIC - install IRQ handler
 *
 *  @param[in]  pvNewISR  own irq handler
 *
 *  @return   old handler
 */
PVOID sysInstallIrqHandler(PVOID pvNewISR)
{
    PVOID _mOldVect;

    _mOldVect = *(PVOID volatile *)0x38;
    *(PVOID volatile *)0x38 = pvNewISR;
    return _mOldVect;
}

/**
 *  @brief  system AIC - install Own IRQ service routine
 *
 *  @param[in]  nIntTypeLevel   Interrupt Level. ( \ref FIQ_LEVEL_0 / \ref IRQ_LEVEL_1 / \ref IRQ_LEVEL_2 / \ref IRQ_LEVEL_3 /
 *                                                 \ref IRQ_LEVEL_4 / \ref IRQ_LEVEL_5 / \ref IRQ_LEVEL_6 / \ref IRQ_LEVEL_7 )
 *  @param[in]  eIntNo  Interrupt number. \ref IRQn_Type
 *  @param[in]  pvNewISR  own IRQ handler
 *
 *  @return   old handler
 */
PVOID sysInstallISR(INT32 nIntTypeLevel, IRQn_Type eIntNo, PVOID pvNewISR)
{
    PVOID   _mOldVect;
    INT     idx, shift;

    if (!_sys_bIsAICInitial)
    {
        CLK->PCLKEN0 |= CLK_PCLKEN0_AICCKEN_Msk;
        sysInitializeAIC();
        _sys_bIsAICInitial = 1;
    }

    idx = eIntNo / 4;
    shift = (eIntNo % 4) * 8;
    nIntTypeLevel &= 0x7;

    AIC->SRC[idx] = (AIC->SRC[idx] & ~(0x7 << shift)) | (nIntTypeLevel << shift);

    if ((nIntTypeLevel & 0x7) == FIQ_LEVEL_0)
    {
        _mOldVect = (PVOID) FiqHandlerTable[eIntNo];
        FiqHandlerTable[eIntNo] = (sys_pvFunPtr)pvNewISR;
    }
    else
    {
        _mOldVect = (PVOID) IrqHandlerTable[eIntNo];
        IrqHandlerTable[eIntNo] = (sys_pvFunPtr)pvNewISR;
    }
    return _mOldVect;
}

INT32 sysSetGlobalInterrupt(INT32 nIntState)
{
    switch (nIntState)
    {
		case ENABLE_ALL_INTERRUPTS:
			AIC->IEN[0] = 0xFFFFFFFF;
			AIC->IEN[1] = 0xFFFFFFFF;
			AIC->IEN[2] = 0xFFFFFFFF;
			break;

		case DISABLE_ALL_INTERRUPTS:
			AIC->IDIS[0] = 0xFFFFFFFF;
			AIC->IDIS[1] = 0xFFFFFFFF;
			AIC->IDIS[2] = 0xFFFFFFFF;
			break;

		default:
			;
    }
    return Successful;
}

/**
 *  @brief  system AIC - Change interrupt level
 *
 *  @param[in]  eIntNo  Interrupt number. \ref IRQn_Type
 *  @param[in]  uIntLevel   Interrupt Level. ( \ref FIQ_LEVEL_0 / \ref IRQ_LEVEL_1 / \ref IRQ_LEVEL_2 / \ref IRQ_LEVEL_3 /
 *                                             \ref IRQ_LEVEL_4 / \ref IRQ_LEVEL_5 / \ref IRQ_LEVEL_6 / \ref IRQ_LEVEL_7 )
 *
 *  @return   0
 */
INT32 sysSetInterruptPriorityLevel(IRQn_Type eIntNo, UINT32 uIntLevel)
{
    INT idx, shift;

    if ((eIntNo > AIC_MAX_INT_SOURCE) || (eIntNo < AIC_MIN_INT_SOURCE))
        return Fail;

    idx = eIntNo / 4;
    shift = (eIntNo % 4) * 8;
    uIntLevel &= 0x7;

    AIC->SRC[idx] = (AIC->SRC[idx] & ~(0x7 << shift)) | (uIntLevel << shift);

    return Successful;
}

/**
 *  @brief  system AIC - Set CP15 Interrupt Type
 *
 *  @param[in]  nIntState   Interrupt state. ( \ref ENABLE_IRQ / \ref ENABLE_FIQ / \ref ENABLE_FIQ_IRQ /
 *                                             \ref DISABLE_IRQ / \ref DISABLE_FIQ / \ref DISABLE_FIQ_IRQ)
 *
 *  @return   0
 */
INT32 sysSetLocalInterrupt(INT32 nIntState)
{
#if defined (__GNUC__) && !(__CC_ARM)
#else
    INT32 temp;
#endif

    switch (nIntState)
    {
        case ENABLE_IRQ:
        case ENABLE_FIQ:
        case ENABLE_FIQ_IRQ:
#if defined (__GNUC__) && !(__CC_ARM)
        asm
            (
                "mrs    r0, CPSR  \n"
                "bic    r0, r0, #0x80  \n"
                "msr    CPSR_c, r0  \n"
            );
#else
            __asm
            {
                MRS    temp, CPSR
                AND    temp, temp, nIntState
                MSR    CPSR_c, temp
            }
#endif
            break;

            case DISABLE_IRQ:
            case DISABLE_FIQ:
            case DISABLE_FIQ_IRQ:
#if defined ( __GNUC__ ) && !(__CC_ARM)
            asm
                (
                    "MRS    r0, CPSR  \n"
                    "ORR    r0, r0, #0x80  \n"
                    "MSR    CPSR_c, r0  \n"
                );
#else
            __asm
            {
                MRS    temp, CPSR
                ORR    temp, temp, nIntState
                MSR    CPSR_c, temp
            }
#endif
            break;

            default:
			;
    }
    return 0;
}

/**
 *  @brief  system AIC - Get Interrupt Enable State
 *
 *  @param[in]  eIntNo  Interrupt number. \ref IRQn_Type
 *
 *  @return   0 (Disable) / 1 (Enable)
 */
INT32 sysGetInterruptEnableState(IRQn_Type eIntNo)
{
    int idx, offs;

    idx = eIntNo / 4;
    offs = eIntNo % 32;

    return (AIC->IE[idx] >> offs) & 0x1;
}

/**
 *  @brief  system AIC - Get Interrupt Status
 *
 *  @param[in]  eIntNo  Interrupt number. \ref IRQn_Type
 *
 *  @return   0 (interrupt source is inactive) / 1 (interrupt source is active)
 */
INT32 sysGetInterruptStatus(IRQn_Type eIntNo)
{
    int idx, offs;

    idx = eIntNo / 4;
    offs = eIntNo % 32;

    return (AIC->IS[idx] >> offs) & 0x1;
}

BOOL sysGetIBitState(void)
{
    INT32 temp;
#if defined (__GNUC__) && !(__CC_ARM)
    asm
    (
        "MRS %0, CPSR   \n"
        :"=r" (temp) : :
    );
#else
    __asm
    {
        MRS temp, CPSR
    }
#endif

    if (temp & 0x80)
        return FALSE;
    else
        return TRUE;
}

INT32 sysGetPLL(UINT32 reg)
{
    UINT32 N,M,P;

    N = ((inpw(reg) & 0x007F) >> 0) + 1;
    M = ((inpw(reg) & 0x1F80) >> 7) + 1;
    P = ((inpw(reg) & 0xE000) >> 13) + 1;

    return ((__HXT * N) / (M * P));    /* 12MHz HXT */
}

UINT32 sysGetClock(CLK_Type clk)
{
    UINT32 src, divN, reg;

    switch(clk)
    {
        case SYS_UPLL:
            return sysGetPLL((UINT32)&CLK->UPLLCON);

        case SYS_APLL:
            return sysGetPLL((UINT32)&CLK->APLLCON);

        case SYS_SYSTEM:
        {
            reg = CLK->DIVCTL0;
            switch (reg & 0x18)
            {
                case 0x0:
                    src = __HXT;
                    break;
                case 0x10:
                    src = sysGetPLL((UINT32)&CLK->APLLCON);
                    break;
                case 0x18:
                    src = sysGetPLL((UINT32)&CLK->UPLLCON);
                    break;
                default:
                    return 0;
            }
            return src;
        }

        case SYS_HCLK:
        {
            reg = CLK->DIVCTL0;
            switch (reg & 0x18)
            {
                case 0x0:
                    src = __HXT;
                    break;
                case 0x10:
                    src = sysGetPLL((UINT32)&CLK->APLLCON);
                    break;
                case 0x18:
                    src = sysGetPLL((UINT32)&CLK->UPLLCON);
                    break;
                default:
                    return 0;
            }
            return (src / 2);
        }

        case SYS_PCLK01:
        {
            reg = CLK->DIVCTL0;
            switch (reg & 0x18)
            {
                case 0x0:
                    src = __HXT;
                    break;
                case 0x10:
                    src = sysGetPLL((UINT32)&CLK->APLLCON);
                    break;
                case 0x18:
                    src = sysGetPLL((UINT32)&CLK->UPLLCON);
                    break;
                default:
                    return 0;
            }
            return (src / 2);
        }

        case SYS_CPU:
        {
            reg = CLK->DIVCTL0;
            switch (reg & 0x18)
            {
                case 0x0:
                    src = __HXT;   /* HXT */
                    break;
                case 0x10:
                    src = sysGetPLL((UINT32)&CLK->APLLCON);
                    break;
                case 0x18:
                    src = sysGetPLL((UINT32)&CLK->UPLLCON);
                    break;
                default:
                    return 0;
            }
            divN = ((reg & 0x100) >> 8) + 1;
            return (src / divN);
        }

        case SYS_PCLK2:
        {
            reg = CLK->DIVCTL0;
            switch (reg & 0x18)
            {
                case 0x0:
                    src = __HXT;
                    break;
                case 0x10:
                    src = sysGetPLL((UINT32)&CLK->APLLCON);
                    break;
                case 0x18:
                    src = sysGetPLL((UINT32)&CLK->UPLLCON);
                    break;
                default:
                    return 0;
            }
            return (src / 4);
        }
    }

    return 0;
}

INT32 sysGetSdramSizebyMB(void)
{
    unsigned int volatile reg, totalsize=0;

    reg = inpw(SDIC_BASE+0x10) & 0x07;
    switch(reg)
    {
        case 1:
            totalsize += 2;
            break;

        case 2:
            totalsize += 4;
            break;

        case 3:
            totalsize += 8;
            break;

        case 4:
            totalsize += 16;
            break;

        case 5:
            totalsize += 32;
            break;

        case 6:
            totalsize += 64;
            break;

        case 7:
            totalsize += 128;
            break;
    }

    if((inpw(SDIC_BASE+0x14) & (0xFF<<21)) !=0)
        totalsize +=totalsize;

    return totalsize;
}

/**
  * @brief      Reset selected module
  * @param[in]  u32ModuleIndex is module index. Including :
  *             - \ref PDMA0_RST
  *             - \ref PDMA1_RST
  *             - \ref PDMA2_RST
  *             - \ref PDMA3_RST
  *             - \ref DISPC_RST
  *             - \ref VCAP0_RST
  *             - \ref VCAP1_RST
  *             - \ref GFX_RST
  *             - \ref VDEC_RST
  *             - \ref WRHO0_RST
  *             - \ref WRHO1_RST
  *             - \ref GMAC0_RST
  *             - \ref GMAC1_RST
  *             - \ref HWSEM_RST
  *             - \ref EBI_RST
  *             - \ref HSUSBH0_RST
  *             - \ref HSUSBH1_RST
  *             - \ref HSUSBD_RST
  *             - \ref USBHL_RST
  *             - \ref SDH0_RST
  *             - \ref SDH1_RST
  *             - \ref NAND_RST
  *             - \ref GPIO_RST
  *             - \ref MCTLP_RST
  *             - \ref MCTLC_RST
  *             - \ref DDRPUB_RST
  *             - \ref TMR0_RST
  *             - \ref TMR1_RST
  *             - \ref TMR2_RST
  *             - \ref TMR3_RST
  *             - \ref I2C0_RST
  *             - \ref I2C1_RST
  *             - \ref I2C2_RST
  *             - \ref I2C3_RST
  *             - \ref QSPI0_RST
  *             - \ref SPI0_RST
  *             - \ref SPI1_RST
  *             - \ref SPI2_RST
  *             - \ref UART0_RST
  *             - \ref UART1_RST
  *             - \ref UART2_RST
  *             - \ref UART3_RST
  *             - \ref UART4_RST
  *             - \ref UART5_RST
  *             - \ref UART6_RST
  *             - \ref UART7_RST
  *             - \ref CANFD0_RST
  *             - \ref CANFD1_RST
  *             - \ref EADC0_RST
  *             - \ref I2S0_RST
  *             - \ref SC0_RST
  *             - \ref SC1_RST
  *             - \ref QSPI1_RST
  *             - \ref SPI3_RST
  *             - \ref EPWM0_RST
  *             - \ref EPWM1_RST
  *             - \ref QEI0_RST
  *             - \ref QEI1_RST
  *             - \ref ECAP0_RST
  *             - \ref ECAP1_RST
  *             - \ref CANFD2_RST
  *             - \ref ADC0_RST
  *             - \ref TMR4_RST
  *             - \ref TMR5_RST
  *             - \ref TMR6_RST
  *             - \ref TMR7_RST
  *             - \ref TMR8_RST
  *             - \ref TMR9_RST
  *             - \ref TMR10_RST
  *             - \ref TMR11_RST
  *             - \ref UART8_RST
  *             - \ref UART9_RST
  *             - \ref UART10_RST
  *             - \ref UART11_RST
  *             - \ref UART12_RST
  *             - \ref UART13_RST
  *             - \ref UART14_RST
  *             - \ref UART15_RST
  *             - \ref UART16_RST
  *             - \ref I2S1_RST
  *             - \ref I2C4_RST
  *             - \ref I2C5_RST
  *             - \ref EPWM2_RST
  *             - \ref ECAP2_RST
  *             - \ref QEI2_RST
  *             - \ref CANFD3_RST
  *             - \ref KPI_RST
  *             - \ref GIC_RST
  *             - \ref SSMCC_RST
  *             - \ref SSPCC_RST
  *
  * @details    This function reset selected module.
  */
void sysResetModule(uint32_t u32ModuleIndex)
{
    uint32_t u32tmpVal = 0UL;
	uint32_t u32tmpAddr = 0UL;

    /* Generate reset signal to the corresponding module */
    u32tmpVal = (1UL << (u32ModuleIndex & 0x00ffffffUL));
    u32tmpAddr = (uint32_t)&SYS->AHBIPRST + (u32ModuleIndex >> 24UL);
    M32(u32tmpAddr) |= u32tmpVal;

    /* Release corresponding module from reset state */
    u32tmpVal = ~(1UL << (u32ModuleIndex & 0x00ffffffUL));
    M32(u32tmpAddr) &= u32tmpVal;
}

/**
  * @brief      Enter to Power-down mode
  * @param      None
  * @return     None
  * @details    This function is used to let system enter to Power-down mode. \n
  *             The register write-protection function should be disabled before using this function.
  */
#ifdef _POWER_MANAGEMENT_
void sysEnterPowerDown(void)
{
	/* Crystal off (Power-down mode) */
    CLK_DisableXtalRC();

	/* Switches the processor into a low-power state */
    __wfi();
}
#endif

/**
  * @brief      Enter to Idle mode
  * @param      None
  * @return     None
  * @details    This function let system enter to Idle mode. \n
  *             The register write-protection function should be disabled before using this function.
  */
#ifdef _POWER_MANAGEMENT_
void sysEnterIdle(void)
{
    /* Switches the processor into a low-power state */
    __wfi();
}
#endif

#ifdef _POWER_MANAGEMENT_
#if defined ( __GNUC__ ) && !(__CC_ARM)
void __wfi(void)
{
    asm
    (
        "MCR p15, 0, r1, c7, c0, 4\n"
    );
}
#else
__asm void __wfi(void)
{
    MCR p15, 0, r1, c7, c0, 4
    BX  lr
}
#endif
#endif

/*@}*/ /* end of group SYS_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group SYS_Driver */

/*@}*/ /* end of group Standard_Driver */

/*** (C) COPYRIGHT 2025 Nuvoton Technology Corp. ***/
