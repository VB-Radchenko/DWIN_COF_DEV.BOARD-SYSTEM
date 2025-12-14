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
#include "PWM.h" // OK
#include "UART.h"
#include "Delay.h"

//==============================================================================
//---------------------------------Defines--------------------------------------
//==============================================================================
/**
 * @def PWM0_SET_ADDR
 * @brief DGUS register address for PWM0 settings (0x86).
 */
#define PWM0_SET_ADDR			0x86

/**
 * @def PWM1_SET_ADDR
 * @brief DGUS register address for PWM1 (DAC) settings (0x88).
 */
#define PWM1_SET_ADDR			0x88

/**
 * @def DUTY_MAX
 * @brief Maximum duty cycle percentage (100%).
 */
#define DUTY_MAX				100

/**
 * @def MILI_VOLTAGE_MAX
 * @brief Maximum DAC output voltage in millivolts (13200 mV).
 */
#define MILI_VOLTAGE_MAX		13200

//==============================================================================
//---------------------------------VARIABLES------------------------------------
//==============================================================================
/**
 * @var uint16_t SetDataPwm0
 * @brief Stores PWM0 setting data.
 */
uint16_t SetDataPwm0;

/**
 * @var uint16_t SetDataPwm1
 * @brief Stores PWM1 (DAC) setting data.
 */
uint16_t SetDataPwm1;

/**
 * @var uint8_t TempSet[6]
 * @brief Buffer for UART transmission of PWM/DAC settings.
 */
uint8_t TempSet[6] = {0xAA, 0x0A, 0x3A, 0x56, 0x78, 0x00};

//==============================================================================
//----------------------------------INIT---------------------------------------
//==============================================================================
/**
 * @brief Initializes PWM0 with specified divider and precision.
 * @param Div Clock divider for PWM0 frequency.
 * @param Precision PWM0 resolution value.
 */
void PwmInit(uint8_t Div, uint16_t Precision)
{
    WriteDgus((PWM0_SET_ADDR + 1), Precision);
    WriteDgus(PWM0_SET_ADDR, (0x5A00 + Div));
    while (ReadDgus(PWM0_SET_ADDR) & 0xFF00) { SysDelayUs(500); }
}

/**
 * @brief Initializes DAC (PWM1) with specified divider and precision.
 * @param Div Clock divider for DAC frequency.
 * @param Precision DAC resolution value.
 */
void DacInit(uint8_t Div, uint16_t Precision)
{
    WriteDgus((PWM1_SET_ADDR + 1), Precision);
    WriteDgus(PWM1_SET_ADDR, (0x5A00 + Div));
    while (ReadDgus(PWM1_SET_ADDR) & 0xFF00) { SysDelayUs(500); }
}

//==============================================================================
//--------------------------------FUNCTIONS-------------------------------------
//==============================================================================

//==============================================================================
//-----------------------------------PWM----------------------------------------
//==============================================================================
/**
 * @brief Sets the duty cycle for PWM0.
 * @param duty Duty cycle percentage (0 to 100).
 */
void PwmSetDuty(uint16_t duty)
{
    uint8_t cnt = 0;
    uint16_t TempDuty = 0;

    if (duty > DUTY_MAX) duty = DUTY_MAX;
    if (duty == DUTY_MAX) { TempDuty = PWM_ACCURACY; }
    else { TempDuty = ((uint32_t)PWM_ACCURACY * (uint32_t)duty) / DUTY_MAX; }
    TempSet[0] = 0xAA;
    TempSet[1] = TempDuty >> 8;
    TempSet[2] = (uint8_t)TempDuty;
    TempSet[5] = 0;
    for (cnt = 0; cnt < 5; cnt++) TempSet[5] += TempSet[cnt];
    for (cnt = 0; cnt < 6; cnt++) UartSendByte(3, TempSet[cnt]);
}

//==============================================================================
//-----------------------------------DAC----------------------------------------
//==============================================================================
/**
 * @brief Sets the output voltage for DAC (PWM1) in millivolts.
 * @param mV Output voltage in millivolts (0 to 10000).
 */
void DacSetOut(uint16_t mV)
{
    uint8_t cnt = 0;
    uint16_t TempVoltage = 0;
    if (mV > MILI_VOLTAGE_MAX) { mV = MILI_VOLTAGE_MAX; }
    if (mV == MILI_VOLTAGE_MAX) { TempVoltage = PWM_ACCURACY; }
    else { TempVoltage = ((uint32_t)PWM_ACCURACY * (uint32_t)mV) / MILI_VOLTAGE_MAX; }
    TempSet[0] = 0xAA;
    TempSet[3] = TempVoltage >> 8;
    TempSet[4] = (uint8_t)TempVoltage;
    TempSet[5] = 0;
    for (cnt = 0; cnt < 5; cnt++) TempSet[5] += TempSet[cnt];
    for (cnt = 0; cnt < 6; cnt++) { UartSendByte(3, TempSet[cnt]); }
}


//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================