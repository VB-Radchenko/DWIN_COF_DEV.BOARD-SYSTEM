#ifndef __TIMER_H__
#define __TIMER_H__
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
 * @def T0_PERIOD_1MS
 * @brief Timer0 period for 1ms interval.
 */
#define T0_PERIOD_1MS		T1MS
/**
 * @def T1_PERIOD_1MS
 * @brief Timer1 period for 1ms interval.
 */
#define T1_PERIOD_1MS		T1MS

/**
 * @def T2_PERIOD_1MS
 * @brief Timer2 period for 1ms interval.
 */
#define T2_PERIOD_1MS		T1MS
//==============================================================================
//--------------------------------FUNCTIONS-------------------------------------
//==============================================================================
/**
 * @brief Initializes enabled timers (Timer0, Timer1, Timer2).
 */
void TimerInit(void);

//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================
#endif