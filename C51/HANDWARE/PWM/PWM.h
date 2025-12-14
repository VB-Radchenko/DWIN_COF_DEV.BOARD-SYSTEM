#ifndef __PWM_H__
#define __PWM_H__
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
/**
 * @def PWM_FREQ_32KHZ
 * @brief PWM frequency setting for 32 kHz (value 255).
 */
#define PWM_FREQ_32KHZ		255


//==============================================================================
//--------------------------------FUNCTIONS-------------------------------------
//==============================================================================
/**
 * @brief Initializes PWM0 with specified divider and precision.
 * @param Div Clock divider for PWM0 frequency.
 * @param Precision PWM0 resolution value.
 */
void PwmInit(uint8_t Div, uint16_t Precision);

/**
 * @brief Sets the duty cycle for PWM0.
 * @param duty Duty cycle percentage (0 to 100).
 */
void PwmSetDuty(uint16_t duty);

/**
 * @brief Initializes DAC (PWM1) with specified divider and precision.
 * @param Div Clock divider for DAC frequency.
 * @param Precision DAC resolution value.
 */
void DacInit(uint8_t Div, uint16_t Precision);

/**
 * @brief Sets the output voltage for DAC (in millivolts).
 * @param mV Output voltage in millivolts (0 to 10000).
 */
void DacSetOut(uint16_t mV);

//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================
#endif