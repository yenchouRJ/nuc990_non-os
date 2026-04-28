/**************************************************************************//**
 * @file     adc.c
 * @brief    NUC990 ADC driver source file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright(C) 2024 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#include "NuMicro.h"
#include "adc.h"
#include "string.h"

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup ADC_Driver ADC Driver
  @{
*/

/** @addtogroup ADC_EXPORTED_FUNCTIONS ADC Exported Functions
  @{
*/

/*---------------------------------------------------------------*/
/*  Struct-based API (new style)                                 */
/*---------------------------------------------------------------*/

/**
  * @brief This API configures ADC module to be ready for convert the input from selected channel
  * @param[in] adc Base address of ADC module
  * @param[in] u32InputMode Input mode. Valid values are:
  *                     - \ref ADC_INPUT_MODE_NORMAL_CONV
  *                     - \ref ADC_INPUT_MODE_4WIRE_TOUCH
  *                     - \ref ADC_INPUT_MODE_5WIRE_TOUCH
  * @param[in] u32OpMode Could be
  *                     - \ref ADC_HIGH_SPEED_MODE
  *                     - \ref ADC_NORMAL_SPEED_MODE
  * @param[in] u32ChMask Channel enable bit. Each bit corresponds to a input channel. Bit 0 is channel 0, bit 1 is channel 1...
  *                      This parameter is only used while u32InputMode set to ADC_INPUT_MODE_NORMAL_CONV.
  * @return  None
  * @note ADC can only convert 1 channel at a time. If more than 1 channels are enabled, only channel
  *       with smallest number will be convert.
  * @note This API does not turn on ADC power nor does trigger ADC conversion
  */
void ADC_Open(ADC_T *adc,
              uint32_t u32InputMode,
              uint32_t u32OpMode,
              uint32_t u32ChMask)
{
    uint32_t u32Ch = 0, i;

    if(u32InputMode == ADC_INPUT_MODE_NORMAL_CONV)
    {
        for(i = 0; i < ADC_CH_NUM; i++) {
            if(u32ChMask & (1 << i)) {
                u32Ch = i;
                break;
            }
        }
        adc->CONF = (u32Ch << ADC_CONF_CHSEL_Pos) | u32OpMode | ADC_CONF_NAC_EN_Msk;
    }
    else if (u32InputMode == ADC_INPUT_MODE_4WIRE_TOUCH)
    {
        adc->CONF = 0;
    }
    else /* 5-wire mode */
    {
        adc->CTL |= ADC_CTL_WMSWCH_Msk;
        adc->CONF = 0;
    }
}

/**
  * @brief Disable ADC module
  * @param[in] adc Base address of ADC module
  */
void ADC_Close(ADC_T *adc)
{
    adc->CTL = 0;
    adc->CONF = 0;
    adc->IER = 0;
    adc->ISR = adc->ISR;
}

/**
  * @brief Enable the interrupt(s) selected by u32Mask parameter.
  * @param[in] adc Base address of ADC module
  * @param[in] u32Mask  The interrupt flags
  */
void ADC_EnableInt(ADC_T *adc, uint32_t u32Mask)
{
    adc->IER |= u32Mask;
}

/**
  * @brief Disable the interrupt(s) selected by u32Mask parameter.
  * @param[in] adc Base address of ADC module
  * @param[in] u32Mask  The interrupt flags
  */
void ADC_DisableInt(ADC_T *adc, uint32_t u32Mask)
{
    adc->IER &= ~u32Mask;
}

/*---------------------------------------------------------------*/
/*  Callback-based legacy API                                    */
/*---------------------------------------------------------------*/

/// @cond HIDDEN_SYMBOLS
#define ADC_FIFO_LENGTH 128
volatile int mst_complete;

typedef struct
{
    ADC_CALLBACK normal_callback;
    UINT32 normal_userData;

    ADC_CALLBACK touch_callback;
    UINT32 touch_userData;

    ADC_CALLBACK touchz_callback;
    UINT32 touchz_userData;

    ADC_CALLBACK pendown_callback;
    UINT32 pendown_userData;

    INT16 fifoX[ADC_FIFO_LENGTH];
    INT32 fifoHeadX;
    INT32 fifoTailX;
    INT32 fifoLengthX;

    INT16 fifoY[ADC_FIFO_LENGTH];
    INT32 fifoHeadY;
    INT32 fifoTailY;
    INT32 fifoLengthY;

    INT16 fifoZ1[ADC_FIFO_LENGTH];
    INT32 fifoHeadZ1;
    INT32 fifoTailZ1;
    INT32 fifoLengthZ1;

    INT16 fifoZ2[ADC_FIFO_LENGTH];
    INT32 fifoHeadZ2;
    INT32 fifoTailZ2;
    INT32 fifoLengthZ2;
} ADC_HANDLE;
/// @endcond HIDDEN_SYMBOLS

static ADC_HANDLE adcHandler;

void adcISR(void);

/**
 * @brief       Open ADC Function.
 *
 * @retval      <0              Fail
 * @retval      0               Success
 *
 * @details     This function is used to open adc function.
 */
INT adcOpen(void)
{
    return adcOpen2(4000);
}

/**
 * @brief       Open ADC2 Function.
 *
 * @param[in]   freqKhz  The ADC engine clock. It should be 1000Khz~4000Khz
 *
 * @retval      <0              Fail
 * @retval      0               Success
 *
 * @details     This function is used to open adc function.
 */
INT adcOpen2(uint32_t freqKhz)
{
    uint32_t div;

    /* Enable ADC engine clock */
    CLK->PCLKEN1 |= CLK_PCLKEN1_ADCCKEN_Msk;

    /* Reset the ADC IP */
    SYS->APBIPRST1 |= SYS_APBIPRST1_ADCRST_Msk;
    SYS->APBIPRST1 &= ~SYS_APBIPRST1_ADCRST_Msk;

    /* ADC Engine Clock is set to freq Khz */
    if (freqKhz > 4000) freqKhz = 4000;
    if (freqKhz < 1000) freqKhz = 1000;
    div = 12000 / freqKhz;
    CLK->DIVCTL7 = (CLK->DIVCTL7 & ~(CLK_DIVCTL7_ADC_S_Msk | CLK_DIVCTL7_ADC_N_Msk)) |
                   ((div - 1) << CLK_DIVCTL7_ADC_N_Pos);

    /* Enable ADC Power */
    ADC->CTL = ADC_CTL_AD_EN_Msk;

    /* Enable ADC to high speed mode */
    ADC->CONF |= ADC_CONF_HSPEED_Msk;

    /* Set interrupt */
    sysInstallISR(IRQ_LEVEL_7, ADC_IRQn, (PVOID)adcISR);
    sysSetLocalInterrupt(ENABLE_IRQ);
    sysEnableInterrupt(ADC_IRQn);

    /* Init the FIFO buffer */
    memset(&adcHandler, 0, sizeof(ADC_HANDLE));

    return Successful;
}

/**
 * @brief       Close ADC Function.
 *
 * @retval      <0              Fail
 * @retval      0               Success
 *
 * @details     This function is used to close adc function.
 */
int adcClose(void)
{
    /* Disable interrupt */
    sysDisableInterrupt(ADC_IRQn);
    sysSetLocalInterrupt(DISABLE_IRQ);

    /* Disable ADC Power */
    ADC->CTL &= ~ADC_CTL_AD_EN_Msk;

    /* Disable ADC engine clock */
    CLK->PCLKEN1 &= ~CLK_PCLKEN1_ADCCKEN_Msk;

    return Successful;
}

/**
 * @brief       The read touch xy data of ADC.
 *
 * @param[out]  bufX     Data buffer for x-position data
 * @param[out]  bufY     Data buffer for y-position data
 * @param[in]   dataCnt  The length of ADC x- and y-position data from FIFO
 *
 * @return      Data count actually
 */
INT adcReadXY(INT16 *bufX, INT16 *bufY, int dataCnt)
{
    INT32 i;
    volatile INT16 *fifoX, *fifoY;
    volatile INT32 headX, headY;
    volatile INT32 fifoLengthX, readLengthX;
    volatile INT32 fifoLengthY, readLengthY;

    fifoX = adcHandler.fifoX;
    fifoY = adcHandler.fifoY;
    headX = adcHandler.fifoHeadX;
    headY = adcHandler.fifoHeadY;
    fifoLengthX = adcHandler.fifoLengthX;
    fifoLengthY = adcHandler.fifoLengthY;

    readLengthX = 0;
    readLengthY = 0;

    for (i = 0; i < dataCnt; i++)
    {
        if (fifoLengthX > readLengthX)
        {
            bufX[i] = fifoX[headX];
            readLengthX++;
            headX++;
            if (headX >= ADC_FIFO_LENGTH)
                headX = 0;
        }
        else
        {
            break;
        }
    }

    for (i = 0; i < dataCnt; i++)
    {
        if (fifoLengthY > readLengthY)
        {
            bufY[i] = fifoY[headY];
            readLengthY++;
            headY++;
            if (headY >= ADC_FIFO_LENGTH)
                headY = 0;
        }
        else
        {
            break;
        }
    }

    /* Update FIFO information */
    adcHandler.fifoHeadX = headX;
    adcHandler.fifoLengthX -= readLengthX;
    adcHandler.fifoHeadY = headY;
    adcHandler.fifoLengthY -= readLengthY;
    return i;
}

/**
 * @brief       The read touch z data of ADC.
 *
 * @param[out]  bufZ1    Data buffer for pressure measure Z1 data
 * @param[out]  bufZ2    Data buffer for pressure measure Z2 data
 * @param[in]   dataCnt  The length of data to read
 *
 * @return      Data count actually
 */
int adcReadZ(short *bufZ1, short *bufZ2, int dataCnt)
{
    INT32 i;
    volatile INT16 *fifoZ1, *fifoZ2;
    volatile INT32 headZ1, headZ2;
    volatile INT32 fifoLengthZ1, readLengthZ1;
    volatile INT32 fifoLengthZ2, readLengthZ2;

    fifoZ1 = adcHandler.fifoZ1;
    fifoZ2 = adcHandler.fifoZ2;
    headZ1 = adcHandler.fifoHeadZ1;
    headZ2 = adcHandler.fifoHeadZ2;
    fifoLengthZ1 = adcHandler.fifoLengthZ1;
    fifoLengthZ2 = adcHandler.fifoLengthZ2;

    readLengthZ1 = 0;
    readLengthZ2 = 0;

    for (i = 0; i < dataCnt; i++)
    {
        if (fifoLengthZ1 > readLengthZ1)
        {
            bufZ1[i] = fifoZ1[headZ1];
            readLengthZ1++;
            headZ1++;
            if (headZ1 >= ADC_FIFO_LENGTH)
                headZ1 = 0;
        }
        else
        {
            break;
        }
    }

    for (i = 0; i < dataCnt; i++)
    {
        if (fifoLengthZ2 > readLengthZ2)
        {
            bufZ2[i] = fifoZ2[headZ2];
            readLengthZ2++;
            headZ2++;
            if (headZ2 >= ADC_FIFO_LENGTH)
                headZ2 = 0;
        }
        else
        {
            break;
        }
    }

    /* Update FIFO information */
    adcHandler.fifoHeadZ1 = headZ1;
    adcHandler.fifoLengthZ1 -= readLengthZ1;
    adcHandler.fifoHeadZ2 = headZ2;
    adcHandler.fifoLengthZ2 -= readLengthZ2;
    return i;
}

/**
 * @brief       The ioctl function of ADC device library.
 *
 * @param[in]   cmd   The command of adcIoctl function
 * @param[in]   arg1  The first argument of adcIoctl function
 * @param[in]   arg2  The second argument of adcIoctl function
 *
 * @retval      <0              Wrong command of adcIoctl
 * @retval      0               Success
 */
INT adcIoctl(ADC_CMD cmd, INT32 arg1, INT32 arg2)
{
    switch (cmd)
    {
    case START_MST:             /* Menu Start Conversion */
    {
        mst_complete = 0;
        ADC->IER |= ADC_IER_M_IEN_Msk;
        ADC->CTL |= ADC_CTL_MST_Msk;
        while (!mst_complete);
    }
    break;

    case START_MST_POLLING:     /* Menu Start Conversion (polling) */
    {
        ADC->IER &= ~ADC_IER_M_IEN_Msk;
        ADC->CTL |= ADC_CTL_MST_Msk;
        while ((ADC->ISR & ADC_ISR_M_F_Msk) == 0);
        adcISR();
    }
    break;

    case VBPOWER_ON:            /* Not supported on NUC990 */
    case VBPOWER_OFF:
        break;

    case NAC_ON:                /* Enable Normal AD Conversion */
    {
        ADC_CALLBACK normal_callback;
        ADC->CONF |= (ADC_CONF_NAC_EN_Msk | ADC_REFSEL_AVDD);
        normal_callback = (ADC_CALLBACK)arg1;
        if (normal_callback != NULL)
        {
            adcHandler.normal_callback = normal_callback;
            adcHandler.normal_userData = (UINT32)arg2;
        }
    }
    break;

    case NAC_OFF:               /* Disable Normal AD Conversion */
    {
        ADC->CONF &= ~ADC_CONF_NAC_EN_Msk;
        adcHandler.normal_callback = (ADC_CALLBACK)NULL;
        adcHandler.normal_userData = (UINT32)0;
    }
    break;

    case PEPOWER_ON:            /* Enable Pen Power */
    {
        UINT32 treg;
        UINT32 delay;
        treg = ADC->IER;
        ADC->IER = treg & ~(ADC_IER_PEDE_IEN_Msk | ADC_IER_PEUE_IEN_Msk);

        ADC->CTL |= ADC_CTL_PEDE_EN_Msk;

        do
        {
            ADC->ISR = (ADC_ISR_PEDE_F_Msk | ADC_ISR_PEUE_F_Msk);
            for (delay = 0; delay < 10000; delay++)
            {
#if defined ( __GNUC__ ) && !(__CC_ARM)
                asm("nop");
#else
                __nop();
#endif
            }
        }
        while (ADC->ISR & (ADC_ISR_PEDE_F_Msk | ADC_ISR_PEUE_F_Msk));

        ADC->IER = treg;
    }
    break;

    case PEPOWER_OFF:           /* Disable Pen Power */
    {
        ADC->CTL &= ~ADC_CTL_PEDE_EN_Msk;
    }
    break;

    case PEDEF_ON:              /* Enable Pen Down Event */
    {
        ADC_CALLBACK pendown_callback;
        ADC->IER |= ADC_IER_PEDE_IEN_Msk;
        pendown_callback = (ADC_CALLBACK)arg1;
        if (pendown_callback != NULL)
        {
            adcHandler.pendown_callback = pendown_callback;
            adcHandler.pendown_userData = (UINT32)arg2;
        }
    }
    break;

    case PEDEF_OFF:             /* Disable Pen Down Event */
    {
        ADC->IER &= ~ADC_IER_PEDE_IEN_Msk;
        adcHandler.pendown_callback = (ADC_CALLBACK)NULL;
        adcHandler.pendown_userData = (UINT32)0;
    }
    break;

    case T_ON:                  /* Enable Touch detection function */
    {
        ADC_CALLBACK touch_callback;
        ADC->CONF |= ADC_CONF_T_EN_Msk;
        touch_callback = (ADC_CALLBACK)arg1;
        if (touch_callback != NULL)
        {
            adcHandler.touch_callback = touch_callback;
            adcHandler.touch_userData = (UINT32)arg2;
        }
        /* Flush the FIFO */
        adcHandler.fifoHeadX = 0;
        adcHandler.fifoTailX = 0;
        adcHandler.fifoLengthX = 0;
        adcHandler.fifoHeadY = 0;
        adcHandler.fifoTailY = 0;
        adcHandler.fifoLengthY = 0;
    }
    break;

    case T_OFF:                 /* Disable Touch detection function */
    {
        ADC->CONF &= ~ADC_CONF_T_EN_Msk;
        adcHandler.touch_callback = (ADC_CALLBACK)NULL;
        adcHandler.touch_userData = (UINT32)0;
    }
    break;

    case Z_ON:                  /* Enable Press measure function */
    {
        ADC_CALLBACK touchz_callback;
        ADC->CONF |= ADC_CONF_Z_EN_Msk;
        touchz_callback = (ADC_CALLBACK)arg1;
        if (touchz_callback != NULL)
        {
            adcHandler.touchz_callback = touchz_callback;
            adcHandler.touchz_userData = (UINT32)arg2;
        }
        /* Flush the FIFO */
        adcHandler.fifoHeadZ1 = 0;
        adcHandler.fifoTailZ1 = 0;
        adcHandler.fifoLengthZ1 = 0;
        adcHandler.fifoHeadZ2 = 0;
        adcHandler.fifoTailZ2 = 0;
        adcHandler.fifoLengthZ2 = 0;
    }
    break;

    case Z_OFF:                 /* Disable Press measure function */
    {
        ADC->CONF &= ~ADC_CONF_Z_EN_Msk;
    }
    break;

    default:
        return ADC_ERR_CMD;
    }
    return Successful;
}

/// @cond HIDDEN_SYMBOLS
#if 0
    #define DbgPrintf printf
#else
    #define DbgPrintf(...)
#endif
/// @endcond HIDDEN_SYMBOLS

/**
 * @brief       The interrupt service routines of ADC
 * @return      None
 * @details     This function is used to ADC interrupt handler.
 */
void adcISR(void)
{
    unsigned int isr, ier, conf;
    conf = ADC->CONF;
    isr  = ADC->ISR;
    ier  = ADC->IER;

    DbgPrintf("ADC_CTL=0x%08x\n", ADC->CTL);
    DbgPrintf("ADC_IER=0x%08x\n", ADC->IER);
    DbgPrintf("ADC_ISR=0x%08x\n", ADC->ISR);

    if ((isr & ADC_ISR_NAC_F_Msk) && (conf & ADC_CONF_NAC_EN_Msk))
    {
        ADC->ISR = ADC_ISR_NAC_F_Msk;
        if (adcHandler.normal_callback != NULL)
            adcHandler.normal_callback(ADC->DATA, adcHandler.normal_userData);
        DbgPrintf("normal AD conversion complete\n");
    }

    if (isr & ADC_ISR_M_F_Msk)
    {
        ADC->ISR = ADC_ISR_M_F_Msk;
        mst_complete = 1;
        DbgPrintf("menu complete\n");
    }

    if (isr & ADC_ISR_T_F_Msk)
    {
        unsigned int value;
        INT32 tailX, lengthX;
        INT32 tailY, lengthY;
        INT16 *fifoX, *fifoY;
        tailX   = adcHandler.fifoTailX;
        lengthX = adcHandler.fifoLengthX;
        tailY   = adcHandler.fifoTailY;
        lengthY = adcHandler.fifoLengthY;
        fifoX   = adcHandler.fifoX;
        fifoY   = adcHandler.fifoY;
        ADC->ISR = ADC_ISR_T_F_Msk;
        value = ADC->XYDATA;
        if (adcHandler.touch_callback != NULL)
            adcHandler.touch_callback(value, adcHandler.touch_userData);

        if ((lengthX < ADC_FIFO_LENGTH) && (lengthY < ADC_FIFO_LENGTH))
        {
            fifoX[tailX] = value & ADC_XYDATA_XDATA_Msk;
            lengthX++;
            tailX++;
            if (tailX == ADC_FIFO_LENGTH) tailX = 0;

            fifoY[tailY] = (value >> ADC_XYDATA_YDATA_Pos) & 0xFFF;
            lengthY++;
            tailY++;
            if (tailY == ADC_FIFO_LENGTH) tailY = 0;
        }
        adcHandler.fifoTailX = tailX;
        adcHandler.fifoLengthX = lengthX;
        adcHandler.fifoTailY = tailY;
        adcHandler.fifoLengthY = lengthY;
        DbgPrintf("touch detect complete\n");
    }

    if ((isr & ADC_ISR_Z_F_Msk) && (conf & ADC_CONF_Z_EN_Msk))
    {
        unsigned int value;
        volatile INT32 tailZ1, lengthZ1;
        volatile INT32 tailZ2, lengthZ2;
        volatile INT16 *fifoZ1, *fifoZ2;
        tailZ1   = adcHandler.fifoTailZ1;
        lengthZ1 = adcHandler.fifoLengthZ1;
        tailZ2   = adcHandler.fifoTailZ2;
        lengthZ2 = adcHandler.fifoLengthZ2;
        fifoZ1   = adcHandler.fifoZ1;
        fifoZ2   = adcHandler.fifoZ2;
        ADC->ISR = ADC_ISR_Z_F_Msk;
        value = ADC->ZDATA;
        if (adcHandler.touchz_callback != NULL)
            adcHandler.touchz_callback(value, adcHandler.touchz_userData);
        if ((lengthZ1 < ADC_FIFO_LENGTH) && (lengthZ2 < ADC_FIFO_LENGTH))
        {
            fifoZ1[tailZ1] = value & ADC_ZDATA_Z1DATA_Msk;
            lengthZ1++;
            tailZ1++;
            if (tailZ1 == ADC_FIFO_LENGTH) tailZ1 = 0;

            fifoZ2[tailZ2] = (value >> ADC_ZDATA_Z2DATA_Pos) & 0x7FF;
            lengthZ2++;
            tailZ2++;
            if (tailZ2 == ADC_FIFO_LENGTH) tailZ2 = 0;
        }
        adcHandler.fifoTailZ1 = tailZ1;
        adcHandler.fifoLengthZ1 = lengthZ1;
        adcHandler.fifoTailZ2 = tailZ2;
        adcHandler.fifoLengthZ2 = lengthZ2;
        DbgPrintf("z conversion complete\n");
    }

    if ((isr & ADC_ISR_PEUE_F_Msk) && (ier & ADC_IER_PEUE_IEN_Msk))
    {
        ADC->ISR = (ADC_ISR_PEUE_F_Msk | ADC_ISR_PEDE_F_Msk);
        DbgPrintf("pen up complete\n");
    }
    else if ((isr & ADC_ISR_PEDE_F_Msk) && (ier & ADC_IER_PEDE_IEN_Msk))
    {
        if (adcHandler.pendown_callback != NULL)
            adcHandler.pendown_callback(isr, adcHandler.pendown_userData);
        ADC->ISR = (ADC_ISR_PEUE_F_Msk | ADC_ISR_PEDE_F_Msk);
        DbgPrintf("pen down complete\n");
    }
}

/**
 * @brief       The ChangeChannel function of ADC device library
 *
 * @param       channel    Channel number (0~7 for external, 8 for Vref),
 *                         pre-shifted by ADC_CONF_CHSEL_Pos
 *
 * @retval      <0         Wrong argument
 * @retval      0          Success
 */
INT adcChangeChannel(int channel)
{
    UINT32 reg;
    if ((channel >> ADC_CONF_CHSEL_Pos) < 0 || (channel >> ADC_CONF_CHSEL_Pos) > 8)
    {
        return ADC_ERR_CMD;
    }
    reg = ADC->CONF;
    reg = (reg & ~ADC_CONF_CHSEL_Msk) | channel;
    ADC->CONF = reg;
    return Successful;
}

/*! @}*/ /* end of group ADC_EXPORTED_FUNCTIONS */

/*! @}*/ /* end of group ADC_Driver */

/*! @}*/ /* end of group Standard_Driver */

/*** (C) COPYRIGHT 2024 Nuvoton Technology Corp. ***/
