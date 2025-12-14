#ifndef __DELAY_H__
#define __DELAY_H__
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

//==============================================================================
//--------------------------------PROTOTYPE-------------------------------------
//==============================================================================
/**
 * @brief Delays execution for a specified number of milliseconds.
 * @param ms Number of milliseconds to delay.
 */
void SysDelayMs(uint32_t ms);

/**
 * @brief Delays execution for a specified number of milliseconds with watchdog timer reset.
 * @param ms Number of milliseconds to delay.
 */
void SysDelayMsWdtReset(uint32_t ms);

/**
 * @brief Delays execution for a specified number of microseconds.
 * @param us Number of microseconds to delay.
 */
void SysDelayUs(uint32_t us);

//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================
#endif