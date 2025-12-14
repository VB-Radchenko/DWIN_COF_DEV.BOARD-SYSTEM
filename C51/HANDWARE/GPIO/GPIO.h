#ifndef __GPIO_H__
#define __GPIO_H__
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

//==============================================================================
//---------------------------------Defines--------------------------------------
//==============================================================================
#define GPIO_PORT_0				0 
#define GPIO_PORT_1 			1
#define GPIO_PORT_2				2
#define GPIO_PORT_3  			3
#define GPIO_PIN_0				0
#define GPIO_PIN_1				1
#define GPIO_PIN_2				2
#define GPIO_PIN_3				3
#define GPIO_PIN_4				4
#define GPIO_PIN_5				5
#define GPIO_PIN_6				6
#define GPIO_PIN_7				7

/**
 * @brief Enum for GPIO operation status.
 */
typedef enum
{
    GPIO_OK = 0x00,  ///< Operation successful.
    GPIO_ERR = 0xFF, ///< Operation failed.
} EGpioStatus;

/**
 * @brief Enum for GPIO pin state.
 */
typedef enum
{
    GPIO_LOW = 0,    ///< Pin is in low state (0V).
    GPIO_HIGHT = 1,  ///< Pin is in high state (VCC).
} EPinState;

/**
 * @brief Enum for GPIO pin type (input or output).
 */
typedef enum
{
    GPIO_IN = 0,     ///< Pin configured as input.
    GPIO_OUT = 1,    ///< Pin configured as output.
} EPinType;

//==============================================================================
//--------------------------------FUNCTIONS-------------------------------------
//==============================================================================
/**
 * @brief Initializes a GPIO pin with specified type and state.
 * @param Type The type of the pin (input or output).
 * @param Port The port number (0 to 3).
 * @param Pin The pin number (0 to 7 for ports 0-2, 0 to 3 for port 3).
 * @param StatePin The initial state of the pin (for output pins).
 * @return EGpioStatus GPIO_OK on success, GPIO_ERR on invalid port or pin.
 */
EGpioStatus InitGpio(EPinType Type, uint8_t Port, uint8_t Pin, EPinState StatePin);

/**
 * @brief Reads the state of a GPIO pin.
 * @param Port The port number (0 to 3).
 * @param Pin The pin number (0 to 7 for ports 0-2, 0 to 3 for port 3).
 * @param StatePin Pointer to store the pin state (GPIO_LOW or GPIO_HIGHT).
 * @return EGpioStatus GPIO_OK on success, GPIO_ERR on invalid port or pin.
 */
EGpioStatus GetGpioState(uint8_t Port, uint8_t Pin, EPinState* StatePin);

/**
 * @brief Sets the state of an output GPIO pin.
 * @param Port The port number (0 to 3).
 * @param Pin The pin number (0 to 7 for ports 0-2, 0 to 3 for port 3).
 * @param State The state to set (GPIO_LOW or GPIO_HIGHT).
 * @return EGpioStatus GPIO_OK on success, GPIO_ERR on invalid port or pin.
 */
EGpioStatus SetGpioOutState(uint8_t Port, uint8_t Pin, EPinState State);

//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================
#endif