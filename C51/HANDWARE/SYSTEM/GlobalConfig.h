#ifndef __GLOBAL_CONFIG_H__
#define __GLOBAL_CONFIG_H__
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
//---------------------------------Defines--------------------------------------
//==============================================================================
/**
 * @def SELECT_RTC_TYPE
 * @brief RTC type selection (2).
 */
#define SELECT_RTC_TYPE				2

/**
 * @def TIMER_0_ENABLE
 * @brief Enable Timer0 (1 = enabled).
 */
#define TIMER_0_ENABLE				1

/**
 * @def TIMER_1_ENABLE
 * @brief Enable Timer1 (1 = enabled).
 */
#define TIMER_1_ENABLE				1

/**
 * @def UART_CONNECT_CONTROL
 * @brief Enable UART connection control (1 = enabled).
 */
#define UART_CONNECT_CONTROL			1

/**
 * @def UART2_ENABLE
 * @brief Enable UART2 (1 = enabled).
 */
#define UART2_ENABLE				1

/**
 * @def UART3_ENABLE
 * @brief Enable UART3 (1 = enabled).
 */
#define UART3_ENABLE				1

/**
 * @def UART4_ENABLE
 * @brief Enable UART4 (0 = disabled).
 */
#define UART4_ENABLE				0

/**
 * @def UART5_ENABLE
 * @brief Enable UART5 (0 = disabled).
 */
#define UART5_ENABLE				0

/**
 * @def UART4_485_EN
 * @brief Enable RS-485 for UART4 (0 = disabled).
 */
#define UART4_485_EN				0

/**
 * @def UART5_485_EN
 * @brief Enable RS-485 for UART5 (1 = enabled).
 */
#define UART5_485_EN				1

/**
 * @def UART2_RX_LENTH
 * @brief UART2 receive buffer length (512 bytes).
 */
#define UART2_RX_LENTH				512

/**
 * @def UART3_RX_LENTH
 * @brief UART3 receive buffer length (512 bytes).
 */
#define UART3_RX_LENTH				512

/**
 * @def UART4_RX_LENTH
 * @brief UART4 receive buffer length (512 bytes).
 */
#define UART4_RX_LENTH				512

/**
 * @def UART5_RX_LENTH
 * @brief UART5 receive buffer length (512 bytes).
 */
#define UART5_RX_LENTH				512

/**
 * @def BAUD_UART2
 * @brief UART2 baud rate (115200 bps).
 */
#define BAUD_UART2					115200

/**
 * @def BAUD_UART3
 * @brief UART3 baud rate (1612800 bps).
 */
#define BAUD_UART3					1612800

/**
 * @def BAUD_UART4
 * @brief UART4 baud rate (115200 bps).
 */
#define BAUD_UART4					115200

/**
 * @def BAUD_UART5
 * @brief UART5 baud rate (115200 bps).
 */
#define BAUD_UART5					115200

/**
 * @def RESPONSE_UART2
 * @brief Enable UART2 response (1 = enabled).
 */
#define RESPONSE_UART2				1

/**
 * @def RESPONSE_UART3
 * @brief Enable UART3 response (1 = enabled).
 */
#define RESPONSE_UART3				1

/**
 * @def RESPONSE_UART4
 * @brief Enable UART4 response (0 = disabled).
 */
#define RESPONSE_UART4				0

/**
 * @def RESPONSE_UART5
 * @brief Enable UART5 response (1 = enabled).
 */
#define RESPONSE_UART5				1

/**
 * @def DATA_UPLOAD_UART2
 * @brief Enable UART2 data upload (1 = enabled).
 */
#define DATA_UPLOAD_UART2			1

/**
 * @def DATA_UPLOAD_UART3
 * @brief Enable UART3 data upload (1 = enabled).
 */
#define DATA_UPLOAD_UART3			1

/**
 * @def DATA_UPLOAD_UART4
 * @brief Enable UART4 data upload (1 = enabled).
 */
#define DATA_UPLOAD_UART4			1

/**
 * @def DATA_UPLOAD_UART5
 * @brief Enable UART5 data upload (1 = enabled).
 */
#define DATA_UPLOAD_UART5			1

/**
 * @def CRC_CHECK_UART2
 * @brief Enable CRC check for UART2 (0 = disabled).
 */
#define CRC_CHECK_UART2				0

/**
 * @def CRC_CHECK_UART3
 * @brief Enable CRC check for UART3 (0 = disabled).
 */
#define CRC_CHECK_UART3				0

/**
 * @def CRC_CHECK_UART4
 * @brief Enable CRC check for UART4 (0 = disabled).
 */
#define CRC_CHECK_UART4				0

/**
 * @def CRC_CHECK_UART5
 * @brief Enable CRC check for UART5 (0 = disabled).
 */
#define CRC_CHECK_UART5				0

/**
 * @def DELAY_UART2
 * @brief UART2 communication delay (5 units).
 */
#define DELAY_UART2					5

/**
 * @def DELAY_UART3
 * @brief UART3 communication delay (5 units).
 */
#define DELAY_UART3					5

/**
 * @def DELAY_UART4
 * @brief UART4 communication delay (5 units).
 */
#define DELAY_UART4					5

/**
 * @def DELAY_UART5
 * @brief UART5 communication delay (5 units).
 */
#define DELAY_UART5					5

/**
 * @def PWM_ACCURACY
 * @brief PWM resolution (0x2042 = 8258 for 13-bit precision).
 */
#define PWM_ACCURACY				0x2042

/**
 * @def DTHD1
 * @brief DGUS protocol header byte 1 (0x5A).
 */
#define DTHD1						0x5A

/**
 * @def DTHD2
 * @brief DGUS protocol header byte 2 (0xA5).
 */
#define DTHD2						0xA5

//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================
#endif