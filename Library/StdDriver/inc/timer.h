 /**************************************************************************//**
 * @file     timer.h
 * @version  V1.00
 * @brief    NuMicro TIMER driver header file
 *
 * @note
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2024 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#ifndef __TIMER_H__
#define __TIMER_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "NuMicro.h"
#include "timer_reg.h"
#include "sys.h"

/** @addtogroup Standard_Driver Standard Driver
@{
*/

/** @addtogroup TIMER_Driver TIMER Driver
@{
*/

/** @addtogroup TIMER_EXPORTED_CONSTANTS TIMER Exported Constants
@{
*/

#define TIMER_ONESHOT_MODE (0UL << TIMER_CTL_OPMODE_Pos)    /*!< Timer working in one shot mode   */
#define TIMER_PERIODIC_MODE (1UL << TIMER_CTL_OPMODE_Pos)   /*!< Timer working in periodic mode   */
#define TIMER_TOGGLE_MODE (2UL << TIMER_CTL_OPMODE_Pos)     /*!< Timer working in toggle mode     */
#define TIMER_CONTINUOUS_MODE (3UL << TIMER_CTL_OPMODE_Pos) /*!< Timer working in continuous mode */

#define TIMER_TOUT_PIN_FROM_TMX (0UL << TIMER_CTL_TGLPINSEL_Pos)     /*!< Timer toggle-output pin is from TMx pin \hideinitializer */
#define TIMER_TOUT_PIN_FROM_TMX_EXT (1UL << TIMER_CTL_TGLPINSEL_Pos) /*!< Timer toggle-output pin is from TMx_EXT pin \hideinitializer */

#define TIMER_COUNTER_FALLING_EDGE (0UL << TIMER_EXTCTL_CNTPHASE_Pos) /*!< Counter increase on falling edge detection \hideinitializer */
#define TIMER_COUNTER_RISING_EDGE (1UL << TIMER_EXTCTL_CNTPHASE_Pos)  /*!< Counter increase on rising edge detection \hideinitializer */

#define TIMER_CAPTURE_FREE_COUNTING_MODE (0UL << TIMER_EXTCTL_CAPFUNCS_Pos) /*!< Timer capture event to get timer counter value \hideinitializer */
#define TIMER_CAPTURE_COUNTER_RESET_MODE (1UL << TIMER_EXTCTL_CAPFUNCS_Pos) /*!< Timer capture event to reset timer counter \hideinitializer */

#define TIMER_CAPTURE_FALLING_EDGE (0UL << TIMER_EXTCTL_CAPEDGE_Pos)             /*!< Falling edge detection to trigger capture event \hideinitializer */
#define TIMER_CAPTURE_RISING_EDGE (1UL << TIMER_EXTCTL_CAPEDGE_Pos)              /*!< Rising edge detection to trigger capture event \hideinitializer */
#define TIMER_CAPTURE_FALLING_THEN_RISING_EDGE (2UL << TIMER_EXTCTL_CAPEDGE_Pos) /*!< Both falling and rising edge detection to trigger capture event, and first event at falling edge \hideinitializer */
#define TIMER_CAPTURE_RISING_THEN_FALLING_EDGE (3UL << TIMER_EXTCTL_CAPEDGE_Pos) /*!< Both rising and falling edge detection to trigger capture event, and first event at rising edge \hideinitializer */
#define TIMER_CAPTURE_EVENT_GET_LOW_PERIOD (6UL << TIMER_EXTCTL_CAPEDGE_Pos)     /*!< First capture event is at falling edge, follows are at at rising edge \hideinitializer */
#define TIMER_CAPTURE_EVENT_GET_HIGH_PERIOD (7UL << TIMER_EXTCTL_CAPEDGE_Pos)    /*!< First capture event is at rising edge, follows are at at falling edge \hideinitializer */

#define TIMER_INTERCAPSEL_HXT (2UL << TIMER_EXTCTL_INTERCAPSEL_Pos) /*!< Capture source from Internal event HXT \hideinitializer */
#define TIMER_INTERCAPSEL_LXT (3UL << TIMER_EXTCTL_INTERCAPSEL_Pos) /*!< Capture source from Internal event LXT \hideinitializer */

#define TIMER_TIMEOUT_TRIGGER (0UL << TIMER_TRGCTL_TRGSSEL_Pos) /*!< Select internal trigger source from timer time-out event \hideinitializer */
#define TIMER_CAPTURE_TRIGGER (1UL << TIMER_TRGCTL_TRGSSEL_Pos) /*!< Select internal trigger source from timer capture event \hideinitializer */

#define TIMER_TRG_TO_EADC (TIMER_TRGCTL_TRGEADC_Msk) /*!< Each timer event to start EADC conversion \hideinitializer */
#define TIMER_TRG_TO_PDMA (TIMER_TRGCTL_TRGPDMA_Msk) /*!< Each timer event to trigger PDMA transfer \hideinitializer */

/*@}*/ /* end of group TIMER_EXPORTED_CONSTANTS */

/** @addtogroup TIMER_EXPORTED_FUNCTIONS TIMER Exported Functions
    @{
*/

/**
 * @brief This macro is used to set new Timer compared value
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @param[in] u32Value  Timer compare value. Valid values are between 2 to 0xFFFFFF
 * @return None
 * \hideinitializer
 */
#define TIMER_SET_CMP_VALUE(timer, u32Value) ((timer)->CMP = (u32Value))

/**
 * @brief This macro is used to set new Timer prescale value
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @param[in] u32Value  Timer prescale value. Valid values are between 0 to 0xFF
 * @return None
 * @note Clock input is divided by (prescale + 1) before it is fed into timer
 * \hideinitializer
 */
#define TIMER_SET_PRESCALE_VALUE(timer, u32Value) ((timer)->CTL = ((timer)->CTL & ~TIMER_CTL_PSC_Msk) | (u32Value))

/**
 * @brief This macro is used to check if specify Timer is inactive or active
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return timer is activate or inactivate
 * @retval 0 Timer 24-bit up counter is inactive
 * @retval 1 Timer 24-bit up counter is active
 * \hideinitializer
 */
#define TIMER_Is_Active(timer) (((timer)->CTL & TIMER_CTL_ACTSTS_Msk) ? 1 : 0)

/**
 * @brief      Select Toggle-output Pin
 *
 * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3, TIMER4, TIMER5.
 * @param[in]  u32ToutSel  Toggle-output pin selection, valid values are:
 *                         - \ref TIMER_TOUT_PIN_FROM_TMX
 *                         - \ref TIMER_TOUT_PIN_FROM_TMX_EXT
 *
 * @return     None
 *
 * @details    This macro is used to select timer toggle-output pin is output on TMx or TMx_EXT pin.
 * \hideinitializer
 */
#define TIMER_SELECT_TOUT_PIN(timer, u32ToutSel) ((timer)->CTL = ((timer)->CTL & ~TIMER_CTL_TGLPINSEL_Msk) | (u32ToutSel))

/**
 * @brief      Select Timer operating mode
 *
 * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3, TIMER4, TIMER5.
 * @param[in]  u32OpMode   Operation mode. Possible options are
 *                         - \ref TIMER_ONESHOT_MODE
 *                         - \ref TIMER_PERIODIC_MODE
 *                         - \ref TIMER_TOGGLE_MODE
 *                         - \ref TIMER_CONTINUOUS_MODE
 *
 * @return     None
 * \hideinitializer
 */
#define TIMER_SET_OPMODE(timer, u32OpMode) ((timer)->CTL = ((timer)->CTL & ~TIMER_CTL_OPMODE_Msk) | (u32OpMode))

/**
 * @brief This function is used to start Timer counting
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return None
 */
static __inline void TIMER_Start(TIMER_T *timer)
{
    timer->CTL |= TIMER_CTL_CNTEN_Msk;
}

/**
 * @brief This function is used to stop Timer counting
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return None
 */
static __inline void TIMER_Stop(TIMER_T *timer)
{
    timer->CTL &= ~TIMER_CTL_CNTEN_Msk;
}

/**
 * @brief      Start Timer Capture Function
 *
 * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3, TIMER4, TIMER5.
 *
 * @return     None
 *
 * @details    This function is used to start Timer capture function.
 */
static __inline void TIMER_StartCapture(TIMER_T *timer)
{
    timer->EXTCTL |= TIMER_EXTCTL_CAPEN_Msk;
}

/**
 * @brief      Stop Timer Capture Function
 *
 * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3, TIMER4, TIMER5.
 *
 * @return     None
 *
 * @details    This function is used to stop Timer capture function.
 */
static __inline void TIMER_StopCapture(TIMER_T *timer)
{
    timer->EXTCTL &= ~TIMER_EXTCTL_CAPEN_Msk;
}

/**
 * @brief This function is used to enable the capture pin detection de-bounce function.
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return None
 */
static __inline void TIMER_EnableCaptureDebounce(TIMER_T *timer)
{
    timer->EXTCTL |= TIMER_EXTCTL_CAPDBEN_Msk;
}

/**
 * @brief This function is used to disable the capture pin detection de-bounce function.
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return None
 */
static __inline void TIMER_DisableCaptureDebounce(TIMER_T *timer)
{
    timer->EXTCTL &= ~TIMER_EXTCTL_CAPDBEN_Msk;
}

/**
 * @brief      Enable Counter Pin De-bounce
 *
 * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3, TIMER4, TIMER5.
 *
 * @return     None
 *
 * @details    This function is used to enable the detect de-bounce function of counter pin.
 */
static __inline void TIMER_EnableEventCounterDebounce(TIMER_T *timer)
{
    timer->EXTCTL |= TIMER_EXTCTL_CNTDBEN_Msk;
}

/**
 * @brief      Disable Counter Pin De-bounce
 *
 * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3, TIMER4, TIMER5.
 *
 * @return     None
 *
 * @details    This function is used to disable the detect de-bounce function of counter pin.
 */
static __inline void TIMER_DisableEventCounterDebounce(TIMER_T *timer)
{
    timer->EXTCTL &= ~TIMER_EXTCTL_CNTDBEN_Msk;
}

/**
 * @brief This function is used to enable the Timer time-out interrupt function.
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return None
 */
static __inline void TIMER_EnableInt(TIMER_T *timer)
{
    timer->CTL |= TIMER_CTL_INTEN_Msk;
}

/**
 * @brief This function is used to disable the Timer time-out interrupt function.
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return None
 */
static __inline void TIMER_DisableInt(TIMER_T *timer)
{
    timer->CTL &= ~TIMER_CTL_INTEN_Msk;
}

/**
 * @brief This function is used to enable the Timer capture trigger interrupt function.
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return None
 */
static __inline void TIMER_EnableCaptureInt(TIMER_T *timer)
{
    timer->EXTCTL |= TIMER_EXTCTL_CAPIEN_Msk;
}

/**
 * @brief This function is used to disable the Timer capture trigger interrupt function.
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return None
 */
static __inline void TIMER_DisableCaptureInt(TIMER_T *timer)
{
    timer->EXTCTL &= ~TIMER_EXTCTL_CAPIEN_Msk;
}

/**
 * @brief This function indicates Timer time-out interrupt occurred or not.
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return Timer time-out interrupt occurred or not
 * @retval 0 Timer time-out interrupt did not occur
 * @retval 1 Timer time-out interrupt occurred
 */
static __inline uint32_t TIMER_GetIntFlag(TIMER_T *timer)
{
    return ((timer->INTSTS & TIMER_INTSTS_TIF_Msk) ? 1UL : 0UL);
}

/**
 * @brief This function clears the Timer time-out interrupt flag.
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return None
 */
static __inline void TIMER_ClearIntFlag(TIMER_T *timer)
{
    timer->INTSTS = TIMER_INTSTS_TIF_Msk;
}

/**
 * @brief This function indicates Timer capture interrupt occurred or not.
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return Timer capture interrupt occurred or not
 * @retval 0 Timer capture interrupt did not occur
 * @retval 1 Timer capture interrupt occurred
 */
static __inline uint32_t TIMER_GetCaptureIntFlag(TIMER_T *timer)
{
    return timer->EINTSTS;
}

/**
 * @brief This function clears the Timer capture interrupt flag.
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return None
 */
static __inline void TIMER_ClearCaptureIntFlag(TIMER_T *timer)
{
    timer->EINTSTS = TIMER_EINTSTS_CAPIF_Msk;
}

/**
 * @brief This function gets the Timer capture data.
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return Timer capture data value
 */
static __inline uint32_t TIMER_GetCaptureData(TIMER_T *timer)
{
    return timer->CAP;
}

/**
 * @brief This function reports the current timer counter value.
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return Timer counter value
 */
static __inline uint32_t TIMER_GetCounter(TIMER_T *timer)
{
    return timer->CNT;
}
/**
 * @brief      Reset Counter
 *
 * @param[in]  timer       The pointer of the specified Timer module. It could be TIMER0, TIMER1, TIMER2, TIMER3, TIMER4, TIMER5.
 *
 * @return     None
 *
 * @details    This function is used to reset current counter value and internal prescale counter value.
 */
static __inline void TIMER_ResetCounter(TIMER_T *timer)
{
    timer->CNT = 0UL;
    while ((timer->CNT & TIMER_CNT_RSTACT_Msk) == TIMER_CNT_RSTACT_Msk);
}

uint32_t TIMER_Open(TIMER_T *timer, uint32_t u32Mode, uint32_t u32Freq);
void TIMER_Close(TIMER_T *timer);
void TIMER_Delay(TIMER_T *timer, uint32_t u32Usec);
void TIMER_EnableCapture(TIMER_T *timer, uint32_t u32CapMode, uint32_t u32Edge);
void TIMER_DisableCapture(TIMER_T *timer);
void TIMER_EnableEventCounter(TIMER_T *timer, uint32_t u32Edge);
void TIMER_DisableEventCounter(TIMER_T *timer);
uint32_t TIMER_GetModuleClock(TIMER_T *timer);
void TIMER_EnableFreqCounter(TIMER_T *timer, uint32_t u32DropCount, uint32_t u32Timeout, uint32_t u32EnableInt);
void TIMER_DisableFreqCounter(TIMER_T *timer);
void TIMER_SetTriggerSource(TIMER_T *timer, uint32_t u32Src);
void TIMER_SetTriggerTarget(TIMER_T *timer, uint32_t u32Mask);

/*@}*/ /* end of group TIMER_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group TIMER_Driver */

/*@}*/ /* end of group Standard_Driver */

#ifdef __cplusplus
}
#endif

#endif //__TIMER_H__
