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
#include "APP.h"
#include "SYSTEM.h"
#include "UART.h"
#include "TIMER.h"

//==============================================================================
//---------------------------------Defines--------------------------------------
//==============================================================================

//==============================================================================
//--------------------------------Variables-------------------------------------
//==============================================================================

xdata uint32_t SysTimCnt = 0;
xdata uint32_t Uptime = 0;
xdata uint32_t UptimeOld = 0;
xdata uint16_t ReadPage = 0;


//==============================================================================
//---------------------------------- INIT---------------------------------------
//==============================================================================
void AppInit()
{
	UartInit();		
  TimerInit();  			//Timer initialization
	SysTimCnt = 0;
	Uptime = 0;
}


//==============================================================================
//--------------------------------FUNCTIONS-------------------------------------
//==============================================================================
void AppProcess()
{
	if (UptimeOld != Uptime)
  {
    UptimeOld = Uptime;
		ReadPage = GetPageID();
		if (ReadPage == 1)
		{
			PageChange(0);
		}
		else if (ReadPage == 0)
		{
			PageChange(1);
		}
		else
		{
			PageChange(2);
		}				  
	}
    UartProcess();
}

//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================