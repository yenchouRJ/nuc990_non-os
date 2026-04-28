/**************************************************************************//**
 * @file     sc.h
 * @brief    NUC990 Smartcard (SC) driver header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2026 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __SC_H__
#define __SC_H__
#include "NuMicro.h"
#ifdef __cplusplus
extern "C"
{
#endif


/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup SC_Driver SC Driver
  @{
*/

/** @addtogroup SC_EXPORTED_CONSTANTS SC Exported Constants
  @{
*/
#define SC_INTERFACE_NUM        2                /*!< Smartcard interface numbers */
#define SC_PIN_STATE_HIGH       1                /*!< Smartcard pin status high   */
#define SC_PIN_STATE_LOW        0                /*!< Smartcard pin status low    */
#define SC_PIN_STATE_IGNORE     0xFFFFFFFF       /*!< Ignore pin status           */
#define SC_CLK_ON               1                /*!< Smartcard clock on          */
#define SC_CLK_OFF              0                /*!< Smartcard clock off         */

#define SC_TMR_MODE_0                   (0ul << SC_TMRCTL0_OPMODE_Pos)  /*!<Timer Operation Mode 0, down count                                                      */
#define SC_TMR_MODE_1                   (1ul << SC_TMRCTL0_OPMODE_Pos)  /*!<Timer Operation Mode 1, down count, start after detect start bit                        */
#define SC_TMR_MODE_2                   (2ul << SC_TMRCTL0_OPMODE_Pos)  /*!<Timer Operation Mode 2, down count, start after receive start bit                       */
#define SC_TMR_MODE_3                   (3ul << SC_TMRCTL0_OPMODE_Pos)  /*!<Timer Operation Mode 3, down count, use for activation, only timer 0 support this mode  */
#define SC_TMR_MODE_4                   (4ul << SC_TMRCTL0_OPMODE_Pos)  /*!<Timer Operation Mode 4, down count with reload after timeout                            */
#define SC_TMR_MODE_5                   (5ul << SC_TMRCTL0_OPMODE_Pos)  /*!<Timer Operation Mode 5, down count, start after detect start bit, reload after timeout  */
#define SC_TMR_MODE_6                   (6ul << SC_TMRCTL0_OPMODE_Pos)  /*!<Timer Operation Mode 6, down count, start after receive start bit, reload after timeout */
#define SC_TMR_MODE_7                   (7ul << SC_TMRCTL0_OPMODE_Pos)  /*!<Timer Operation Mode 7, down count, start and reload after detect start bit             */
#define SC_TMR_MODE_8                   (8ul << SC_TMRCTL0_OPMODE_Pos)  /*!<Timer Operation Mode 8, up count                                                        */
#define SC_TMR_MODE_F                   (0xFul << SC_TMRCTL0_OPMODE_Pos) /*!<Timer Operation Mode 15, down count, reload after detect start bit                      */

/* Legacy aliases for pin control masks (sc_reg.h uses different names) */
#define SC_PINCTL_SCDOUT_Msk    SC_PINCTL_SCDATA_Msk
#define SC_PINCTL_SCRST_Msk     SC_PINCTL_RSTEN_Msk

/*@}*/ /* end of group SC_EXPORTED_CONSTANTS */


/** @addtogroup SC_EXPORTED_FUNCTIONS SC Exported Functions
  @{
*/

/**
  * @brief Enable smartcard interrupt.
  * @param[in] sc Smartcard module number
  * @param[in] u32Mask Interrupt mask to be enabled. A combination of
  *             - \ref SC_INTEN_ACERRIEN_Msk
  *             - \ref SC_INTEN_RXTOIEN_Msk
  *             - \ref SC_INTEN_INITIEN_Msk
  *             - \ref SC_INTEN_CDIEN_Msk
  *             - \ref SC_INTEN_BGTIEN_Msk
  *             - \ref SC_INTEN_TMR2IEN_Msk
  *             - \ref SC_INTEN_TMR1IEN_Msk
  *             - \ref SC_INTEN_TMR0IEN_Msk
  *             - \ref SC_INTEN_TERRIEN_Msk
  *             - \ref SC_INTEN_TBEIEN_Msk
  *             - \ref SC_INTEN_RDAIEN_Msk
  * @return None
  * \hideinitializer
  */
#define SC_ENABLE_INT(sc, u32Mask) \
    do {\
        SC_T *_pSC = ((sc) == 0) ? SC0 : SC1;\
        _pSC->INTEN |= (u32Mask);\
    }while(0)


/**
  * @brief Disable smartcard interrupt.
  * @param[in] sc Smartcard module number
  * @param[in] u32Mask Interrupt mask to be disabled. A combination of the same masks as SC_ENABLE_INT.
  * @return None
  * \hideinitializer
  */
#define SC_DISABLE_INT(sc, u32Mask) \
    do {\
        SC_T *_pSC = ((sc) == 0) ? SC0 : SC1;\
        _pSC->INTEN &= ~(u32Mask);\
    }while(0)

/**
  * @brief This macro set VCC pin state of smartcard interface.
  * @param[in] sc Smartcard module number
  * @param[in] u32State Pin state of VCC pin, valid parameters are:
  *                 \ref SC_PIN_STATE_HIGH    :Smartcard pin status high.
  *                 \ref SC_PIN_STATE_LOW     :Smartcard pin status low.
  * @return None
  * \hideinitializer
  */
#define SC_SET_VCC_PIN(sc, u32State) \
    do {\
        SC_T *_pSC = ((sc) == 0) ? SC0 : SC1;\
        while(_pSC->PINCTL & SC_PINCTL_SYNC_Msk);\
        if(u32State)\
            _pSC->PINCTL |= SC_PINCTL_PWREN_Msk;\
        else\
            _pSC->PINCTL &= ~SC_PINCTL_PWREN_Msk;\
    }while(0)


/**
  * @brief Set CLK output status.
  * @param[in] sc Smartcard module number
  * @param[in] u32OnOff Clock on or off for selected smartcard module, valid values are:
  *                 \ref SC_CLK_ON    :Smartcard clock on.
  *                 \ref SC_CLK_OFF   :Smartcard clock off.
  * @return None
  * \hideinitializer
  */
#define SC_SET_CLK_PIN(sc, u32OnOff)\
    do {\
        SC_T *_pSC = ((sc) == 0) ? SC0 : SC1;\
        while(_pSC->PINCTL & SC_PINCTL_SYNC_Msk);\
        if(u32OnOff)\
            _pSC->PINCTL |= SC_PINCTL_CLKKEEP_Msk;\
        else\
            _pSC->PINCTL &= ~SC_PINCTL_CLKKEEP_Msk;\
    }while(0)


/**
  * @brief Set I/O pin state.
  * @param[in] sc Smartcard module number
  * @param[in] u32State Pin state of I/O pin, valid parameters are:
  *                 \ref SC_PIN_STATE_HIGH    :Smartcard pin status high.
  *                 \ref SC_PIN_STATE_LOW     :Smartcard pin status low.
  * @return None
  * \hideinitializer
  */
#define SC_SET_IO_PIN(sc, u32State)\
    do {\
        SC_T *_pSC = ((sc) == 0) ? SC0 : SC1;\
        while(_pSC->PINCTL & SC_PINCTL_SYNC_Msk);\
        if(u32State)\
            _pSC->PINCTL |= SC_PINCTL_SCDATA_Msk;\
        else\
            _pSC->PINCTL &= ~SC_PINCTL_SCDATA_Msk;\
    }while(0)

/**
  * @brief Set RST pin state.
  * @param[in] sc Smartcard module number
  * @param[in] u32State Pin state of RST pin, valid parameters are:
  *                 \ref SC_PIN_STATE_HIGH    :Smartcard pin status high.
  *                 \ref SC_PIN_STATE_LOW     :Smartcard pin status low.
  * @return None
  * \hideinitializer
  */
#define SC_SET_RST_PIN(sc, u32State)\
    do {\
        SC_T *_pSC = ((sc) == 0) ? SC0 : SC1;\
        while(_pSC->PINCTL & SC_PINCTL_SYNC_Msk);\
        if(u32State)\
            _pSC->PINCTL |= SC_PINCTL_RSTEN_Msk;\
        else\
            _pSC->PINCTL &= ~SC_PINCTL_RSTEN_Msk;\
    }while(0)

/**
  * @brief Read one byte from smartcard module receive FIFO.
  * @param[in] sc Smartcard module number
  * @return One byte read from receive FIFO.
  * \hideinitializer
  */
#define SC_READ(sc) (((sc) == 0) ? SC0->DAT : SC1->DAT)

/**
  * @brief Write one byte to smartcard module transmit FIFO.
  * @param[in] sc Smartcard module number
  * @param[in] u8Data Data to write to transmit FIFO.
  * @return None
  * \hideinitializer
  */
#define SC_WRITE(sc, u8Data) \
    do {\
        if((sc) == 0)\
            SC0->DAT = (u8Data);\
        else\
            SC1->DAT = (u8Data);\
    }while(0)

/**
  * @brief This macro set smartcard stop bit length.
  * @param[in] sc Smartcard module number
  * @param[in] u32Len Stop bit length, either 1 or 2.
  * @return None
  * @details Stop bit length must be 1 for T = 1 protocol and 2 for T = 0 protocol.
  * \hideinitializer
  */
#define SC_SET_STOP_BIT_LEN(sc, u32Len) \
    do {\
        SC_T *_pSC = ((sc) == 0) ? SC0 : SC1;\
        _pSC->CTL = (_pSC->CTL & ~SC_CTL_NSB_Msk) | (((u32Len) == 1) ? SC_CTL_NSB_Msk : 0);\
    }while(0)

/**
  * @brief Enable/Disable Tx error retry, and set Tx error retry count.
  * @param[in] sc Smartcard module number
  * @param[in] u32Count The number of times of Tx error retry count, between 0~8. 0 means disable Tx error retry.
  * @return None
  */
static __inline void SC_SetTxRetry(UINT sc, uint32_t u32Count)
{
    SC_T *pSC = (sc == 0) ? SC0 : SC1;

    while(pSC->CTL & SC_CTL_SYNC_Msk);
    pSC->CTL &= ~(SC_CTL_TXRTY_Msk | SC_CTL_TXRTYEN_Msk);
    if(u32Count != 0)
    {
        while(pSC->CTL & SC_CTL_SYNC_Msk);
        pSC->CTL |= (((u32Count - 1) << SC_CTL_TXRTY_Pos) | SC_CTL_TXRTYEN_Msk);
    }
}

/**
  * @brief Enable/Disable Rx error retry, and set Rx error retry count.
  * @param[in] sc Smartcard module number
  * @param[in] u32Count The number of times of Rx error retry count, between 0~8. 0 means disable Rx error retry.
  * @return None
  */
static __inline void SC_SetRxRetry(UINT sc, uint32_t u32Count)
{
    SC_T *pSC = (sc == 0) ? SC0 : SC1;

    while(pSC->CTL & SC_CTL_SYNC_Msk);
    pSC->CTL &= ~(SC_CTL_RXRTY_Msk | SC_CTL_RXRTYEN_Msk);
    if(u32Count != 0)
    {
        while(pSC->CTL & SC_CTL_SYNC_Msk);
        pSC->CTL |= (((u32Count - 1) << SC_CTL_RXRTY_Pos) | SC_CTL_RXRTYEN_Msk);
    }
}


UINT SC_IsCardInserted(UINT sc);
void SC_ClearFIFO(UINT sc);
void SC_Close(UINT sc);
void SC_Open(UINT sc, UINT u32CardDet, UINT u32PWR);
void SC_ResetReader(UINT sc);
void SC_SetBlockGuardTime(UINT sc, UINT u32BGT);
void SC_SetCharGuardTime(UINT sc, UINT u32CGT);
void SC_StopAllTimer(UINT sc);
void SC_StartTimer(UINT sc, UINT u32TimerNum, UINT u32Mode, UINT u32ETUCount);
void SC_StopTimer(UINT sc, UINT u32TimerNum);


/*@}*/ /* end of group SC_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group SC_Driver */

/*@}*/ /* end of group Standard_Driver */

#ifdef __cplusplus
}
#endif

#endif //__SC_H__
