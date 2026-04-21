/**************************************************************************//**
 * @file     timer.c
 * @version  V1.00
 * @brief    NuMicro TIMER driver source file
 *
 * @note
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2024 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include "NuMicro.h"
#include "sys.h"
#include "timer.h"

/// @cond HIDDEN_SYMBOLS

/**
 * @brief This API is used to get the clock frequency of Timer
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return Timer clock frequency
 * @note This API cannot return correct clock rate if timer source is external clock input.
 */
uint32_t TIMER_GetModuleClock(TIMER_T *timer)
{
    uint32_t src;

    if (timer == TIMER0)
    {
        src = (CLK->DIVCTL8 >> (16)) & 0x3;
    }
    else if (timer == TIMER1)
    {
        src = (CLK->DIVCTL8 >> (16 + 1 * 2)) & 0x3;
    }
    else if (timer == TIMER2)
    {
        src = (CLK->DIVCTL8 >> (16 + 2 * 2)) & 0x3;
    }
    else if (timer == TIMER3)
    {
        src = (CLK->DIVCTL8 >> (16 + 3 * 2)) & 0x3;
    }
    else if (timer == TIMER4)
    {
        src = (CLK->DIVCTL8 >> (16 + 4 * 2)) & 0x3;
    }
    else /* Timer 5 */
    {
        src = (CLK->DIVCTL8 >> (16 + 5 * 2)) & 0x3;
    }

    if (src == 0)
        return 12000000;
    else if (src == 1)
        return (sysGetClock(SYS_PCLK01));         // 20250811 HH, the return value in now in Hz, not MHz.
    else if (src == 2)
        return (sysGetClock(SYS_PCLK01) / 4096);  // 20250811 HH, the return value in now in Hz, not MHz.
    else
        return 32768;
}

/// @endcond /* HIDDEN_SYMBOLS */

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup TIMER_Driver TIMER Driver
  @{
*/

/** @addtogroup TIMER_EXPORTED_FUNCTIONS TIMER Exported Functions
  @{
*/

/**
 * @brief This API is used to configure timer to operate in specified mode
 *        and frequency. If timer cannot work in target frequency, a closest
 *        frequency will be chose and returned.
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @param[in] u32Mode Operation mode. Possible options are
 *                 - \ref TIMER_ONESHOT_MODE
 *                 - \ref TIMER_PERIODIC_MODE
 *                 - \ref TIMER_TOGGLE_MODE
 *                 - \ref TIMER_CONTINUOUS_MODE
 * @param[in] u32Freq Target working frequency
 * @return Real Timer working frequency
 * @note After calling this API, Timer is \b NOT running yet. But could start timer running be calling
 *       \ref TIMER_Start macro or program registers directly
 */
uint32_t TIMER_Open(TIMER_T *timer, uint32_t u32Mode, uint32_t u32Freq)
{
    uint32_t u32Clk = TIMER_GetModuleClock(timer);
    uint32_t u32Cmpr = 0, u32Prescale = 0;

    // Fastest possible timer working freq is u32Clk / 2. While cmpr = 2, pre-scale = 0
    if (u32Freq > (u32Clk / 2))
    {
        u32Cmpr = 2;
    }
    else
    {
        u32Cmpr = u32Clk / u32Freq;
        u32Prescale = (u32Cmpr >> 24);  /* for 24 bits CMPDAT */

        if (u32Prescale > 0UL)
            u32Cmpr = u32Cmpr / (u32Prescale + 1UL);
    }

    timer->CTL = u32Mode | u32Prescale;
    timer->CMP = u32Cmpr;

    return (u32Clk / (u32Cmpr * (u32Prescale + 1UL)));
}

/**
 * @brief This API stops Timer counting and disable the Timer interrupt function
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return None
 */
void TIMER_Close(TIMER_T *timer)
{
    timer->CTL = 0UL;
    timer->EXTCTL = 0UL;
}

/**
 * @brief This API is used to create a delay loop for u32usec micro seconds
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @param[in] u32Usec Delay period in micro seconds with 10 usec every step. Valid values are between 10~1000000 (10 micro second ~ 1 second)
 * @return None
 * @note This API overwrites the register setting of the timer used to count the delay time.
 * @note This API use polling mode. So there is no need to enable interrupt for the timer module used to generate delay
 */
void TIMER_Delay(TIMER_T *timer, uint32_t u32Usec)
{
    uint32_t u32Clk;
    uint32_t u32Prescale = 0UL, delay;
    uint32_t u32Cmpr, u32NsecPerTick;

    u32Clk = TIMER_GetModuleClock(timer);
    delay = (CLK_GetUPLLClockFreq() / u32Clk) + 1UL;

    /* Clear current timer configuration */
    timer->CTL = 0UL;
    timer->EXTCTL = 0UL;

    if (u32Clk <= 1000000UL) /* min delay is 1000 us if timer clock source is <= 1 MHz */
    {
        if (u32Usec < 1000UL)
        {
            u32Usec = 1000UL;
        }
        if (u32Usec > 1000000UL)
        {
            u32Usec = 1000000UL;
        }
    }
    else
    {
        if (u32Usec < 100UL)
        {
            u32Usec = 100UL;
        }
        if (u32Usec > 1000000UL)
        {
            u32Usec = 1000000UL;
        }
    }

    if (u32Clk <= 1000000UL)
    {
        u32Prescale = 0UL;
        u32NsecPerTick = 1000000000UL / u32Clk;
        u32Cmpr = (u32Usec * 1000UL) / u32NsecPerTick;
    }
    else
    {
        u32Cmpr = u32Usec * (u32Clk / 1000000UL);
        u32Prescale = (u32Cmpr >> 24); /* for 24 bits CMPDAT */
        if (u32Prescale > 0UL)
            u32Cmpr = u32Cmpr / (u32Prescale + 1UL);
    }

    timer->CMP = u32Cmpr;
    timer->CTL = TIMER_CTL_CNTEN_Msk | TIMER_ONESHOT_MODE | u32Prescale;

    /* When system clock is faster than timer clock, it is possible timer active bit cannot set in time while we check it.
       And the while loop below return immediately, so put a tiny delay here allowing timer start counting and raise active flag. */
    for (; delay > 0UL; delay--)
    {
#if defined(__GNUC__) && !(__CC_ARM)
        asm(
            "nop  \n");
#else
        __asm
        {
            NOP
        }
#endif
    }

    while (timer->CTL & TIMER_CTL_ACTSTS_Msk)
    {
        ;
    }
}

/**
 * @brief This API is used to enable timer capture function with specified mode and capture edge
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @param[in] u32CapMode Timer capture mode. Could be
 *                 - \ref TIMER_CAPTURE_FREE_COUNTING_MODE
 *                 - \ref TIMER_CAPTURE_TRIGGER_COUNTING_MODE
 *                 - \ref TIMER_CAPTURE_COUNTER_RESET_MODE
 * @param[in] u32Edge Timer capture edge. Possible values are
 *                 - \ref TIMER_CAPTURE_FALLING_EDGE
 *                 - \ref TIMER_CAPTURE_RISING_EDGE
 *                 - \ref TIMER_CAPTURE_FALLING_THEN_RISING_EDGE
 *                 - \ref TIMER_CAPTURE_RISING_THEN_FALLING_EDGE
 * @return None
 * @note Timer frequency should be configured separately by using \ref TIMER_Open API, or program registers directly
 */
void TIMER_EnableCapture(TIMER_T *timer, uint32_t u32CapMode, uint32_t u32Edge)
{
    timer->EXTCTL = (timer->EXTCTL & ~(TIMER_EXTCTL_CAPFUNCS_Msk | TIMER_EXTCTL_CAPEDGE_Msk)) |
                    u32CapMode | u32Edge | TIMER_EXTCTL_CAPEN_Msk;
}

/**
 * @brief This API is used to disable the Timer capture function
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return None
 */
void TIMER_DisableCapture(TIMER_T *timer)
{
    timer->EXTCTL &= ~TIMER_EXTCTL_CAPEN_Msk;
}

/**
 * @brief This function is used to enable the Timer counter function with specify detection edge
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @param[in] u32Edge Detection edge of counter pin. Could be ether
 *             - \ref TIMER_COUNTER_RISING_EDGE, or
 *             - \ref TIMER_COUNTER_FALLING_EDGE
 * @return None
 * @note Timer compare value should be configured separately by using \ref TIMER_SET_CMP_VALUE macro or program registers directly
 */
void TIMER_EnableEventCounter(TIMER_T *timer, uint32_t u32Edge)
{
    timer->EXTCTL = (timer->EXTCTL & ~TIMER_EXTCTL_CNTPHASE_Msk) | u32Edge;
    timer->CTL |= TIMER_CTL_EXTCNTEN_Msk;
}

/**
 * @brief This API is used to disable the Timer event counter function.
 * @param[in] timer TIMER number. Range from 0 ~ 5
 * @return None
 */
void TIMER_DisableEventCounter(TIMER_T *timer)
{
    timer->CTL &= ~TIMER_CTL_EXTCNTEN_Msk;
}

/**
 * @brief This function is used to enable the Timer frequency counter function
 * @param[in] timer The base address of Timer module. Can be \ref TIMER0 or \ref TIMER2 or \ref TIMER4
 * @param[in] u32DropCount This parameter has no effect in M480 series BSP
 * @param[in] u32Timeout This parameter has no effect in M480 series BSP
 * @param[in] u32EnableInt Enable interrupt assertion after capture complete or not. Valid values are TRUE and FALSE
 * @return None
 * @details This function is used to calculate input event frequency. After enable this function,
 *          a pair of timers, TIMER0 and TIMER1, TIMER2 and TIMER3, or TIMER4 and TIMER5
 *          will be configured for this function. The mode used to calculate input
 *          event frequency is mentioned as "Inter Timer Trigger Mode" in Technical
 *          Reference Manual
 */
void TIMER_EnableFreqCounter(TIMER_T *timer,
                             uint32_t u32DropCount,
                             uint32_t u32Timeout,
                             uint32_t u32EnableInt)
{
    TIMER_T *t; /* store the timer base to configure compare value */

    t = (timer == TIMER0) ? TIMER1 : (timer == TIMER2) ? TIMER3
                                                       : TIMER5;

    t->CMP = 0xFFFFFFUL;
    t->EXTCTL = u32EnableInt ? TIMER_EXTCTL_CAPIEN_Msk : 0UL;
    timer->CTL = TIMER_CTL_INTRGEN_Msk | TIMER_CTL_CNTEN_Msk;

    return;
}

/**
 * @brief This function is used to disable the Timer frequency counter function.
 * @param[in] timer The base address of Timer module
 * @return None
 */
void TIMER_DisableFreqCounter(TIMER_T *timer)
{
    timer->CTL &= ~TIMER_CTL_INTRGEN_Msk;
}

/**
 * @brief This function is used to select the interrupt source used to trigger other modules.
 * @param[in] timer The base address of Timer module
 * @param[in] u32Src Selects the interrupt source to trigger other modules. Could be:
 *              - \ref TIMER_TRGSRC_TIMEOUT_EVENT
 *              - \ref TIMER_TRGSRC_CAPTURE_EVENT
 * @return None
 */
void TIMER_SetTriggerSource(TIMER_T *timer, uint32_t u32Src)
{
    timer->TRGCTL = (timer->TRGCTL & ~TIMER_TRGCTL_TRGSSEL_Msk) | u32Src;
}

/**
 * @brief This function is used to set modules trigger by timer interrupt
 * @param[in] timer The base address of Timer module
 * @param[in] u32Mask The mask of modules (ADC and PDMA) trigger by timer. Is the combination of
 *             - \ref TIMER_TRG_TO_ADC
 *             - \ref TIMER_TRG_TO_PDMA
 * @return None
 */
void TIMER_SetTriggerTarget(TIMER_T *timer, uint32_t u32Mask)
{
    timer->TRGCTL = (timer->TRGCTL & ~(TIMER_TRGCTL_TRGADC_Msk | TIMER_TRGCTL_TRGPDMA_Msk)) | u32Mask;
}

/*@}*/ /* end of group TIMER_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group TIMER_Driver */

/*@}*/ /* end of group Standard_Driver */
