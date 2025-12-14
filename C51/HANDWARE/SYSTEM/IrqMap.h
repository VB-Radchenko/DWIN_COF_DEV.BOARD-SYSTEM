#ifndef __IRQ_MAP_H__
#define __IRQ_MAP_H__
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
#include "T5LRegisterMap.h"
#include "SYSTEM.h"

//==============================================================================
//---------------------------------Typedef--------------------------------------
//==============================================================================

//==============================================================================//---------------------------------Defines--------------------------------------
//==============================================================================

//==============================================================================
//--------------------------------FUNCTIONS-------------------------------------
//==============================================================================
/**
 * @brief Interrupt service routine for external interrupt 0.
 */
void ExternaPin0Irq(void);

/**
 * @brief Interrupt service routine for Timer0.
 */
void Timer0Isr(void);

/**
 * @brief Interrupt service routine for external interrupt 1.
 */
void ExternaPin1Irq(void);

/**
 * @brief Interrupt service routine for Timer1.
 */
void Timer1Isr(void);

/**
 * @brief Interrupt service routine for Timer2.
 */
void Timer2Isr(void);

/**
 * @brief Interrupt service routine for CAN.
 */
void CanIrq(void);


//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================
#endif