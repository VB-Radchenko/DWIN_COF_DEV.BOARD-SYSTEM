#ifndef __UART_H__
#define __UART_H__
/*
@verbatim
--------------------------------------------------------------------------------
MIT License

Copyright (c) [2025] [Vladimir Radchenko]
Version 1.0

For communication or thanks, you can contact me by mail DwinRVB@mail.ru

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
--------------------------------------------------------------------------------
@endverbatim
*/

//==============================================================================
//---------------------------------Includes-------------------------------------
//==============================================================================
#include "SYSTEM.h"
#include "crc16.h"

//==============================================================================
//---------------------------------Defines--------------------------------------
//==============================================================================
#define UART_REV_PRE          0x00
#define UART_REV_GETFH1       0x01
#define UART_REV_GETFH2       0x02
#define UART_REV_GETLEN       0x03
#define UART_REV_GETCODE      0x04
#define UART_REV_GETADDR1     0x05
#define UART_REV_GETADDR2     0x06
#define UART_REV_DONE         0x07

#define UART_TX_LENGTH        256
#define UART_RX_LENGTH        1024
#define TIMEOUT_SET           10
#define UARTX_FRAME_DATA_LENGTH 264

//==============================================================================
//--------------------------------Structures------------------------------------
//==============================================================================
/**
 * @brief Structure for UART configuration and state.
 */
typedef struct
{
    uint8_t  Id;               ///< UART identifier (2, 3, 4, or 5).
    uint16_t TxRead;           ///< Transmit buffer read pointer.
    uint16_t TxWrite;          ///< Transmit buffer write pointer.
    uint8_t  TxBusy;           ///< Transmit busy flag.
    uint16_t RxRead;           ///< Receive buffer read pointer.
    uint16_t RxWrite;          ///< Receive buffer write pointer.
    uint8_t  RxBusy;           ///< Receive busy flag.
    uint8_t  RxFlag;           ///< Receive state flag.
    uint8_t  RxBuffer[UART_RX_LENGTH]; ///< Receive buffer.
    uint8_t  TxBuffer[UART_TX_LENGTH]; ///< Transmit buffer.
    uint8_t  Response;         ///< Response enable flag.
    uint8_t  CrcCheck;         ///< CRC check enable flag.
    uint8_t  Delay;            ///< Delay counter for response (in ms).
} Uartx_Define;

/**
 * @brief Structure for UART frame data.
 */
typedef struct
{
    uint8_t  DataLen;          ///< Length of frame data.
    uint8_t  DataCode;         ///< Frame command code.
    uint16_t VarAddr;          ///< Variable address.
    uint8_t  VarData[UARTX_FRAME_DATA_LENGTH]; ///< Frame data buffer.
    uint8_t  VarIndex;         ///< Current index in data buffer.
} Uartx_Frame_Data;

//==============================================================================
//--------------------------------Functions-------------------------------------
//==============================================================================
/**
 * @brief Initializes all enabled UART interfaces.
 */
void UartInit(void);

/**
 * @brief Processes UART frame data for all enabled interfaces.
 */
void UartProcess(void);

/**
 * @brief Decrements delay counters for all enabled UART interfaces.
 */
void InterfaceDelay(void);

/**
 * @brief Sends a single byte over the specified UART.
 * @param uart_number UART identifier (2, 3, 4, or 5).
 * @param dat Byte to send.
 */
void UartSendByte(uint8_t uart_number, uint8_t dat);
#endif