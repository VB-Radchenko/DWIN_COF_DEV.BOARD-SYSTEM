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
#include "ADC.h" // OK

//==============================================================================
//---------------------------------Defines--------------------------------------
//==============================================================================
#define ADC_START_ADDR		0x32 ///< Starting address for ADC data in DGUS registers.

//==============================================================================
//---------------------------------VARIABLES------------------------------------
//==============================================================================

//==============================================================================
//---------------------------------ADC READ-------------------------------------
//==============================================================================
/**
 * @brief Reads a single ADC value from the specified channel.
 * @param Channel The ADC channel to read (1 to 7).
 * @return uint16_t The 16-bit ADC value read from the specified channel.
 */
uint16_t AdcRead(AdcChannel Channel)
{
    uint8_t readData[2];

    uint16_t ReturnValue;

    ReadDgusVp(ADC_START_ADDR + Channel, &readData, 1);
    ReturnValue = (uint16_t)(readData[0] << 8) + (uint16_t)readData[1];
    return ReturnValue;
}

//==============================================================================
//-----------------------------ADC READ AVERAGE---------------------------------
//==============================================================================
/**
 * @brief Reads and averages ADC values from the specified channel.
 * @param Channel The ADC channel to read (1 to 7).
 * @param AvgCnt The number of samples to average.
 * @return uint16_t The averaged 16-bit ADC value, or 0 if AvgCnt is 0.
 */
uint16_t AdcReadAvg(AdcChannel Channel, uint16_t AvgCnt)
{
    uint16_t Cnt = 0;
    uint16_t AdcValue = 0;
    uint32_t AdcSum = 0;

    if (AvgCnt == 0) return 0;

    for (Cnt = 0; Cnt < AvgCnt; Cnt++)
    {
        AdcValue = AdcRead(Channel);
        AdcSum += AdcValue;
    }

    AdcValue = (uint16_t)(AdcSum / AvgCnt);
    return AdcValue;
}

//==============================================================================
//-------------------------------ADC PROCESS------------------------------------
//==============================================================================


//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================