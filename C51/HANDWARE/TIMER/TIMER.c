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
#include "TIMER.h"  // OK +
#include "Delay.h"

//==============================================================================
//---------------------------------Defines--------------------------------------
//==============================================================================


//==============================================================================
//---------------------------------VARIABLES------------------------------------
//==============================================================================
/**
 * @var uint16_t TimeOut
 * @brief Timeout counter for timer operations.
 */
xdata uint16_t TimeOut = 0;

/**
 * @var uint32_t Counter
 * @brief General-purpose counter initialized to 1000.
 */
xdata uint32_t Counter = 1000;


//==============================================================================
//---------------------------------- INIT---------------------------------------
//==============================================================================
/**
 * @brief Initializes Timer0 with a 1ms period in 16-bit mode.
 */
void InitTimer0(void)
{
    TMOD = (TMOD & 0xF0) | 0x01; // Set 16-bit mode for Timer0
    TH0 = (uint8_t)(T0_PERIOD_1MS >> 8); // High byte of 1ms period
    TL0 = (uint8_t)T0_PERIOD_1MS;       // Low byte of 1ms period
    ET0 = 1; // Enable Timer0 interrupt
    TR0 = 1; // Start Timer0
}

/**
 * @brief Initializes Timer1 with a 1ms period in 16-bit mode.
 */
void InitTimer1(void)
{
    TMOD = (TMOD & 0x0F) | 0x10; // Set 16-bit mode for Timer1
    TH1 = (uint8_t)(T1_PERIOD_1MS >> 8); // High byte of 1ms period
    TL1 = (uint8_t)T1_PERIOD_1MS;       // Low byte of 1ms period
    ET1 = 1; // Enable Timer1 interrupt
    TR1 = 1; // Start Timer1
}

/**
 * @brief Initializes Timer2 with a 1ms period.
 */
void InitTimer2(void)
{
    T2CON = 0x70; // Configure Timer2
    TH2 = 0x00;   // Initialize counter high byte
    TL2 = 0x00;   // Initialize counter low byte
    TRL2H = (uint8_t)(T2_PERIOD_1MS >> 8); // High byte of 1ms period
    TRL2L = (uint8_t)T2_PERIOD_1MS;       // Low byte of 1ms period
    IEN0 |= 0x20; // Enable Timer2 interrupt
    TR2 = 0x01;   // Start Timer2
    ET2 = 1;      // Enable Timer2 interrupt
}

/**
 * @brief Initializes enabled timers (Timer0, Timer1, Timer2).
 */
void TimerInit(void)
{
    EA = 0; // Disable global interrupts
#ifdef TIMER_0_ENABLE
    InitTimer0();
#endif
#ifdef TIMER_1_ENABLE
    InitTimer1();
#endif
    InitTimer2();
    EA = 1; // Enable global interrupts
}

//==============================================================================
//--------------------------------FUNCTIONS-------------------------------------
//==============================================================================



//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================
