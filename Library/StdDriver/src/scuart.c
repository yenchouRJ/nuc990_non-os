/**************************************************************************//**
 * @file     scuart.c
 * @brief    NUC990 series Smartcard UART mode (SCUART) driver source file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2018 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include "scuart.h"

/** @addtogroup Standard_Driver Standard Driver
  @{
*/

/** @addtogroup SCUART_Driver SCUART Driver
  @{
*/


/** @addtogroup SCUART_EXPORTED_FUNCTIONS SCUART Exported Functions
  @{
*/

/**
  * @brief Disable smartcard uart interface.
  * @param sc Smartcard module number
  * @return None
  * @details The function is used to disable smartcard interface UART mode.
  */
void SCUART_Close(UINT sc)
{
    SC_T *pSC = (sc == 0) ? SC0 : SC1;
    pSC->INTEN = 0;
    pSC->UARTCTL = 0;
    pSC->CTL = 0;
}

/// @cond HIDDEN_SYMBOLS
/**
  * @brief This function returns module clock of specified SC interface
  * @param[in] sc Smartcard module number
  * @return Module clock of specified SC interface
  */
static uint32_t SCUART_GetClock(UINT sc)
{
    uint32_t u32Div;

    if(sc == 0)
        u32Div = ((CLK->DIVCTL6 >> CLK_DIVCTL6_SMC0_N_Pos) & 0xF) + 1;
    else
        u32Div = ((CLK->DIVCTL6 >> CLK_DIVCTL6_SMC1_N_Pos) & 0xF) + 1;

    return 12000000 / u32Div;
}
/// @endcond HIDDEN_SYMBOLS

/**
  * @brief Enable smartcard uart interface.
  * @param[in] sc Smartcard module number
  * @param[in] u32baudrate Target baudrate of smartcard module.
  * @return Actual baudrate of smartcard mode.
  * @details This function use to enable smartcard module UART mode and set baudrate.
  * @note This function configures character width to 8 bits, 1 stop bit, and no parity.
  *       And can use \ref SCUART_SetLineConfig function to update these settings.
  */
UINT SCUART_Open(UINT sc, UINT u32baudrate)
{
    SC_T *pSC = (sc == 0) ? SC0 : SC1;
    uint32_t u32Clk = SCUART_GetClock(sc), u32Div;

    // Calculate divider for target baudrate
    u32Div = (u32Clk + (u32baudrate >> 1) - 1) / u32baudrate - 1;

    pSC->CTL = SC_CTL_SCEN_Msk | SC_CTL_NSB_Msk;   // Enable smartcard interface and stop bit = 1
    pSC->UARTCTL = SCUART_CHAR_LEN_8 | SCUART_PARITY_NONE | SC_UARTCTL_UARTEN_Msk; // Enable UART mode, disable parity and 8 bit per character
    pSC->ETUCTL = u32Div;

    return(u32Clk / (u32Div + 1));
}

/**
  * @brief Read data from smartcard UART interface.
  * @param[in] sc Smartcard module number
  * @param[in] pu8RxBuf The buffer to store receive the data.
  * @param[in] u32ReadBytes Target number of characters to receive.
  * @return Actual character number reads to buffer.
  * @details The function is used to read Rx data from RX FIFO.
  * @note This function does not block and return immediately if there's no data available.
  */
UINT SCUART_Read(UINT sc, char *pu8RxBuf, UINT u32ReadBytes)
{
    SC_T *pSC = (sc == 0) ? SC0 : SC1;
    uint32_t u32Count;

    for(u32Count = 0; u32Count < u32ReadBytes; u32Count++)
    {
        if(pSC->STATUS & SC_STATUS_RXEMPTY_Msk)   // no data available
            break;
        pu8RxBuf[u32Count] = pSC->DAT;    // get data from FIFO
    }

    return u32Count;
}

/**
  * @brief This function use to config smartcard UART mode line setting.
  * @param[in] sc Smartcard module number
  * @param[in] u32Baudrate Target baudrate of smartcard module. If this value is 0, UART baudrate will not change.
  * @param[in] u32DataWidth The data length, could be:
  *                 - \ref SCUART_CHAR_LEN_5
  *                 - \ref SCUART_CHAR_LEN_6
  *                 - \ref SCUART_CHAR_LEN_7
  *                 - \ref SCUART_CHAR_LEN_8
  * @param[in] u32Parity The parity setting, could be:
  *                 - \ref SCUART_PARITY_NONE
  *                 - \ref SCUART_PARITY_ODD
  *                 - \ref SCUART_PARITY_EVEN
  * @param[in] u32StopBits The stop bit length, could be:
  *                 - \ref SCUART_STOP_BIT_1
  *                 - \ref SCUART_STOP_BIT_2
  * @return Actual baudrate of smartcard.
  * @details Smartcard UART mode is operated in LIN data frame.
  */
UINT SCUART_SetLineConfig(UINT sc, UINT u32Baudrate, UINT u32DataWidth, UINT u32Parity, UINT  u32StopBits)
{
    SC_T *pSC = (sc == 0) ? SC0 : SC1;
    uint32_t u32Clk = SCUART_GetClock(sc), u32Div;

    if(u32Baudrate == 0)    // keep original baudrate setting
    {
        u32Div = pSC->ETUCTL & SC_ETUCTL_ETURDIV_Msk;
    }
    else
    {
        // Calculate divider for target baudrate
        u32Div = (u32Clk + (u32Baudrate >> 1) - 1) / u32Baudrate - 1;
        pSC->ETUCTL = u32Div;
    }

    pSC->CTL = u32StopBits | SC_CTL_SCEN_Msk;  // Set stop bit
    pSC->UARTCTL = u32Parity | u32DataWidth | SC_UARTCTL_UARTEN_Msk;   // Set character width and parity

    return(u32Clk / (u32Div + 1));
}

/**
  * @brief This function use to set receive timeout count.
  * @param[in] sc Smartcard module number
  * @param[in] u32TOC Rx timeout counter, using baudrate as counter unit. Valid range are 0~0x1FF,
  *                   set this value to 0 will disable timeout counter.
  * @return None
  */
void SCUART_SetTimeoutCnt(UINT sc, UINT u32TOC)
{
    SC_T *pSC = (sc == 0) ? SC0 : SC1;
    pSC->RXTOUT = u32TOC;
}


/**
  * @brief Write data to smartcard UART interface.
  * @param[in] sc Smartcard module number
  * @param[in] pu8TxBuf The buffer containing data to send to transmit FIFO.
  * @param[in] u32WriteBytes Number of data to send.
  * @return None
  * @details This function is to write data into transmit FIFO to send data out.
  * @note This function blocks until all data write into FIFO.
  */
void SCUART_Write(UINT sc, char *pu8TxBuf, UINT u32WriteBytes)
{
    SC_T *pSC = (sc == 0) ? SC0 : SC1;
    uint32_t u32Count;

    for(u32Count = 0; u32Count != u32WriteBytes; u32Count++)
    {
        while(pSC->STATUS & SC_STATUS_TXFULL_Msk);  // Wait 'til FIFO not full
        pSC->DAT = pu8TxBuf[u32Count];    // Write 1 byte to FIFO
    }
}


/*@}*/ /* end of group SCUART_EXPORTED_FUNCTIONS */

/*@}*/ /* end of group SCUART_Driver */

/*@}*/ /* end of group Standard_Driver */
