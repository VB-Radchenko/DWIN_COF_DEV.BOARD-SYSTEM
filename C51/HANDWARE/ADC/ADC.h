#ifndef __ADC_H__
#define __ADC_H__
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
 * @brief Enum for ADC channel selection.
 */
typedef enum
{
    ADC_CHANNEL_1 = 1, ///< ADC channel 1.
    ADC_CHANNEL_2 = 2, ///< ADC channel 2.
    ADC_CHANNEL_3 = 3, ///< ADC channel 3.
    ADC_CHANNEL_4 = 4, ///< ADC channel 4.
    ADC_CHANNEL_5 = 5, ///< ADC channel 5.
    ADC_CHANNEL_6 = 6, ///< ADC channel 6.
    ADC_CHANNEL_7 = 7  ///< ADC channel 7.
} AdcChannel;

/**
 * @brief Enum for ADC operation status.
 */
typedef enum
{
    ADC_OK = 0x00,  ///< ADC operation successful.
    ADC_ERR = 0xFF, ///< ADC operation failed.
} StatusAdc;

//==============================================================================
//--------------------------------FUNCTIONS-------------------------------------
//==============================================================================
/**
 * @brief Reads a single ADC value from the specified channel.
 * @param Channel The ADC channel to read (1 to 7).
 * @return uint16_t The 16-bit ADC value.
 */
uint16_t AdcRead(AdcChannel Channel);

/**
 * @brief Reads and averages ADC values from the specified channel.
 * @param Channel The ADC channel to read (1 to 7).
 * @param AvgCnt The number of samples to average.
 * @return uint16_t The averaged 16-bit ADC value.
 */
uint16_t AdcReadAvg(AdcChannel Channel, uint16_t AvgCnt);

//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================
#endif