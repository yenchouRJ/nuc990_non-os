/**************************************************************************//**
 * @file     sc.c
 * @brief    NUC990 series Smartcard(SC) driver source file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2026 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include "sc.h"

// Below are variables used locally by SC driver and does not want to parse by doxygen unless HIDDEN_SYMBOLS is defined
/// @cond HIDDEN_SYMBOLS
static uint32_t u32CardStateIgnore[SC_INTERFACE_NUM] = {0, 0};

/// @endcond HIDDEN_SYMBOLS

/**
  * @brief  Get SC_T pointer from interface number
  * @param[in] sc Smartcard module number (0 or 1)
  * @return Pointer to SC_T register base
  */
static SC_T *SC_GetBase(UINT sc)
{
    return (sc == 0) ? SC0 : SC1;
}

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup SC_Driver SC Driver
  @{
*/


/** @addtogroup SC_EXPORTED_FUNCTIONS SC Exported Functions
  @{
*/

/**
  * @brief This function indicates specified smartcard slot status.
  * @param[in] sc Smartcard module number
  * @retval TRUE Card insert.
  * @retval FALSE Card remove.
  * @details This function is used to check if specified smart card slot is presented.
  */
UINT SC_IsCardInserted(UINT sc)
{
    SC_T *pSC = SC_GetBase(sc);
    uint32_t cond1, cond2;

    cond1 = (pSC->STATUS & SC_STATUS_CDPINSTS_Msk) >> SC_STATUS_CDPINSTS_Pos;
    cond2 = (pSC->CTL & SC_CTL_CDLV_Msk) >> SC_CTL_CDLV_Pos;

    if(u32CardStateIgnore[sc] == 1)
        return TRUE;
    else if(cond1 != cond2)
        return FALSE;
    else
        return TRUE;
}

/**
  * @brief Reset the Tx/Rx FIFO.
  * @param[in] sc Smartcard module number
  * @return None
  * @details This function reset both transmit and receive FIFO of specified smartcard module.
  */
void SC_ClearFIFO(UINT sc)
{
    SC_T *pSC = SC_GetBase(sc);
    pSC->ALTCTL |= (SC_ALTCTL_TXRST_Msk | SC_ALTCTL_RXRST_Msk);
}

/**
  * @brief This function disable specified smartcard module.
  * @param[in] sc Smartcard module number
  * @return None
  * @details SC will force all transition to IDLE state.
  */
void SC_Close(UINT sc)
{
    SC_T *pSC = SC_GetBase(sc);
    pSC->INTEN = 0;
    pSC->PINCTL = 0;
    pSC->ALTCTL = 0;
    pSC->CTL = 0;
}

/**
  * @brief This function initialized smartcard module.
  * @param[in] sc Smartcard module number
  * @param[in] u32CD Card detect polarity, select the CD pin state which indicates card absent. Could be:
  *                 -\ref SC_PIN_STATE_HIGH.
  *                 -\ref SC_PIN_STATE_LOW.
  *                 -\ref SC_PIN_STATE_IGNORE, no card detect pin, always assumes card present.
  * @param[in] u32PWR Power off polarity, select the PWR pin state which could set smartcard VCC to high level. Could be:
  *                 -\ref SC_PIN_STATE_HIGH.
  *                 -\ref SC_PIN_STATE_LOW.
  * @return None
  * @details Initialization process configures smartcard and enables engine clock.
  */
void SC_Open(UINT sc, UINT u32CD, UINT u32PWR)
{
    SC_T *pSC = SC_GetBase(sc);
    uint32_t u32Reg = 0;

    if(u32CD != SC_PIN_STATE_IGNORE)
    {
        u32Reg = u32CD ? 0: SC_CTL_CDLV_Msk;
        u32CardStateIgnore[sc] = 0;
    }
    else
    {
        u32CardStateIgnore[sc] = 1;
    }

    while(pSC->PINCTL & SC_PINCTL_SYNC_Msk);
    pSC->PINCTL = u32PWR ? 0 : SC_PINCTL_PWRINV_Msk;
    while(pSC->CTL & SC_CTL_SYNC_Msk);
    pSC->CTL = SC_CTL_SCEN_Msk | u32Reg;
}

/**
  * @brief This function reset specified smartcard module to its default state for activate smartcard.
  * @param[in] sc Smartcard module number
  * @return None
  * @details Reset the Tx/Rx FIFO & clock & initial default parameter.
  */
void SC_ResetReader(UINT sc)
{
    SC_T *pSC = SC_GetBase(sc);

    // Reset FIFO, enable auto de-activation while card removal
    pSC->ALTCTL |= (SC_ALTCTL_TXRST_Msk | SC_ALTCTL_RXRST_Msk | SC_ALTCTL_ADACEN_Msk);
    // Set Rx trigger level to 1 character, longest card detect debounce period, disable error retry (EMV ATR does not use error retry)
    while(pSC->CTL & SC_CTL_SYNC_Msk);
    // Enable auto convention, and all three smartcard internal timers
    pSC->CTL = (pSC->CTL & ~(SC_CTL_RXTRGLV_Msk | SC_CTL_CDDBSEL_Msk | SC_CTL_TXRTY_Msk | SC_CTL_TXRTYEN_Msk | SC_CTL_RXRTY_Msk | SC_CTL_RXRTYEN_Msk)) | SC_CTL_AUTOCEN_Msk | SC_CTL_TMRSEL_Msk;

    // Disable Rx timeout
    pSC->RXTOUT = 0;
    // 372 clocks per ETU by default
    pSC->ETUCTL = 371;

    /* Enable necessary interrupt for smartcard operation */
    if(u32CardStateIgnore[sc]) // Do not enable card detect interrupt if card present state ignore
        pSC->INTEN = SC_INTEN_RDAIEN_Msk |
                     SC_INTEN_TERRIEN_Msk |
                     SC_INTEN_TMR0IEN_Msk |
                     SC_INTEN_TMR1IEN_Msk |
                     SC_INTEN_TMR2IEN_Msk |
                     SC_INTEN_BGTIEN_Msk |
                     SC_INTEN_ACERRIEN_Msk;
    else
        pSC->INTEN = SC_INTEN_RDAIEN_Msk |
                     SC_INTEN_TERRIEN_Msk |
                     SC_INTEN_TMR0IEN_Msk |
                     SC_INTEN_TMR1IEN_Msk |
                     SC_INTEN_TMR2IEN_Msk |
                     SC_INTEN_BGTIEN_Msk |
                     SC_INTEN_ACERRIEN_Msk |
                     SC_INTEN_CDIEN_Msk;

    return;
}

/**
  * @brief Set Block Guard Time.
  * @param[in] sc Smartcard module number
  * @param[in] u32BGT Block guard time using ETU as unit, valid range are between 1 ~ 32.
  * @return None
  * @details This function block guard time (BGT) of specified smartcard module.
  */
void SC_SetBlockGuardTime(UINT sc, UINT u32BGT)
{
    SC_T *pSC = SC_GetBase(sc);
    pSC->CTL = (pSC->CTL & ~SC_CTL_BGT_Msk) | (((u32BGT) - 1) << SC_CTL_BGT_Pos);
}

/**
  * @brief Set character guard time.
  * @param[in] sc Smartcard module number
  * @param[in] u32CGT Character guard time using ETU as unit, valid range are between 11 ~ 267.
  * @return None
  * @details This function character guard time (CGT) of specified smartcard module.
  */
void SC_SetCharGuardTime(UINT sc, UINT u32CGT)
{
    SC_T *pSC = SC_GetBase(sc);
    u32CGT -= (pSC->CTL & SC_CTL_NSB_Msk) ? 11 : 12;
    pSC->EGT = u32CGT;
}

/**
  * @brief Stop all Timer counting.
  * @param[in] sc Smartcard module number
  * @return None
  * @details This function stop all smartcard timer of specified smartcard module.
  * @note This function stop the timers within smartcard module, \b not timer module.
  */
void SC_StopAllTimer(UINT sc)
{
    SC_T *pSC = SC_GetBase(sc);
    pSC->ALTCTL &= ~(SC_ALTCTL_CNTEN0_Msk | SC_ALTCTL_CNTEN1_Msk | SC_ALTCTL_CNTEN2_Msk);
}

/**
  * @brief This function configure and start a smartcard timer of specified smartcard module.
  * @param[in] sc Smartcard module number
  * @param[in] u32TimerNum Timer(s) to start. Valid values are 0, 1, 2.
  * @param[in] u32Mode Timer operating mode, valid values are:
  *             - \ref SC_TMR_MODE_0
  *             - \ref SC_TMR_MODE_1
  *             - \ref SC_TMR_MODE_2
  *             - \ref SC_TMR_MODE_3
  *             - \ref SC_TMR_MODE_4
  *             - \ref SC_TMR_MODE_5
  *             - \ref SC_TMR_MODE_6
  *             - \ref SC_TMR_MODE_7
  *             - \ref SC_TMR_MODE_8
  *             - \ref SC_TMR_MODE_F
  * @param[in] u32ETUCount Timer timeout duration, ETU based. For timer 0, valid  range are between 1~0x1000000ETUs.
  *                        For timer 1 and timer 2, valid range are between 1 ~ 0x100 ETUs.
  * @return None
  * @details Enable Timer starting, counter will count when condition match.
  * @note This function start the timer within smartcard module, \b not timer module.
  * @note Depend on the timer operating mode, timer may not start counting immediately.
  */
void SC_StartTimer(UINT sc, UINT u32TimerNum, UINT u32Mode, UINT u32ETUCount)
{
    SC_T *pSC = SC_GetBase(sc);
    uint32_t reg = u32Mode | (SC_TMRCTL0_CNT_Msk & (u32ETUCount - 1));

    if(u32TimerNum == 0)
    {
        pSC->TMRCTL0 = reg;
        pSC->ALTCTL |= SC_ALTCTL_CNTEN0_Msk;
    }
    else if(u32TimerNum == 1)
    {
        pSC->TMRCTL1 = reg;
        pSC->ALTCTL |= SC_ALTCTL_CNTEN1_Msk;
    }
    else    // timer 2
    {
        pSC->TMRCTL2 = reg;
        pSC->ALTCTL |= SC_ALTCTL_CNTEN2_Msk;
    }
}

/**
  * @brief Stop Timer counting.
  * @param[in] sc Smartcard module number
  * @param[in] u32TimerNum Timer(s) to stop. Valid values are 0, 1, 2.
  * @return None
  * @details This function stop a smartcard timer of specified smartcard module.
  * @note This function stop the timer within smartcard module, \b not timer module.
  */
void SC_StopTimer(UINT sc, UINT u32TimerNum)
{
    SC_T *pSC = SC_GetBase(sc);

    if(u32TimerNum == 0)
        pSC->ALTCTL &= ~SC_ALTCTL_CNTEN0_Msk;
    else if(u32TimerNum == 1)
        pSC->ALTCTL &= ~SC_ALTCTL_CNTEN1_Msk;
    else    // timer 2
        pSC->ALTCTL &= ~SC_ALTCTL_CNTEN2_Msk;
}


/*@}*/ /* end of group SC_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group SC_Driver */

/*@}*/ /* end of group Standard_Driver */
