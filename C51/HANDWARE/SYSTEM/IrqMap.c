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
#include "IrqMap.h" 
#include "UART.h"   
#include "TIMER.h"  

//==============================================================================
//---------------------------------Defines--------------------------------------
//==============================================================================

//==============================================================================
//---------------------------------VARIABLES------------------------------------
//==============================================================================
/**
 * @var uint32_t DelayMsTick
 * @brief Global tick counter for millisecond delays.
 */
uint32_t DelayMsTick = 0;

/**
 * @var uint32_t Uptime
 * @brief System uptime counter in seconds.
 */
extern uint32_t Uptime;

/**
 * @var uint32_t CntMs
 * @brief Millisecond counter for uptime tracking.
 */
uint32_t CntMs;

/**
 * @var uint32_t SysTimCnt
 * @brief System timer counter.
 */
extern uint32_t SysTimCnt;

/**
 * @var uint32_t Tim0Cnt
 * @brief Timer0 interrupt counter.
 */
uint32_t Tim0Cnt;

/**
 * @var uint32_t Tim1Cnt
 * @brief Timer1 interrupt counter.
 */
uint32_t Tim1Cnt;

//==============================================================================
//--------------------------------FUNCTIONS-------------------------------------
//==============================================================================
/**
 * @brief Interrupt service routine for external interrupt 0.
 */
void ExternaPin0Irq(void) interrupt 0
{
    EA = 0; // Disable global interrupts
    EA = 1; // Re-enable global interrupts
}

/**
 * @brief Interrupt service routine for Timer0.
 * Reloads Timer0 and decrements DelayMsTick.
 */
void Timer0Isr(void) interrupt 1
{
    TH0 = (uint8_t)(T0_PERIOD_1MS >> 8); // Reload high byte
    TL0 = (uint8_t)T0_PERIOD_1MS;       // Reload low byte
    Tim0Cnt++;                 // Increment Timer0 counter
    if (DelayMsTick) DelayMsTick--; // Decrement delay counter
}

/**
 * @brief Interrupt service routine for external interrupt 1.
 */
void ExternaPin1Irq(void) interrupt 2
{
    EA = 0; // Disable global interrupts
    EA = 1; // Re-enable global interrupts
}

/**
 * @brief Interrupt service routine for Timer1.
 * Reloads Timer1 and decrements DelayMsTick.
 */
void Timer1Isr(void) interrupt 3
{
    TH1 = (uint8_t)(T1_PERIOD_1MS >> 8); // Reload high byte
    TL1 = (uint8_t)T1_PERIOD_1MS;       // Reload low byte
    Tim1Cnt++;                 // Increment Timer1 counter
    if (DelayMsTick) DelayMsTick--; // Decrement delay counter
}

/**
 * @brief Interrupt service routine for Timer2.
 * Updates uptime, decrements DelayMsTick, and calls InterfaceDelay.
 */
void Timer2Isr(void) interrupt 5
{
	SysTimCnt++;
    TF2 = 0; // Clear Timer2 overflow flag
    CntMs++; // Increment millisecond counter
    if (DelayMsTick) DelayMsTick--; // Decrement delay counter
    if (CntMs >= 999)
    {
        CntMs = 0;
        Uptime++; // Increment uptime in seconds
    }
    InterfaceDelay(); // Handle UART interface delay
}

/**
 * @brief Interrupt service routine for CAN.
 */
void CanIrq(void) interrupt 9
{
    ; // Placeholder for CAN interrupt handling
}



//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================