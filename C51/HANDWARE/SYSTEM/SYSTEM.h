#ifndef __SYSTEM_H__
#define __SYSTEM_H__
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
#include "GlobalConfig.h"

//==============================================================================
//---------------------------------Typedef--------------------------------------
//==============================================================================
/**
 * @typedef uint8_t
 * @brief Unsigned 8-bit integer.
 */
typedef unsigned char   uint8_t;

/**
 * @typedef uint16_t
 * @brief Unsigned 16-bit integer.
 */
typedef unsigned int    uint16_t;

/**
 * @typedef uint32_t
 * @brief Unsigned 32-bit integer.
 */
typedef unsigned long   uint32_t;

/**
 * @typedef int8_t
 * @brief Signed 8-bit integer.
 */
typedef signed char     int8_t;

/**
 * @typedef int16_t
 * @brief Signed 16-bit integer.
 */
typedef signed int      int16_t;

/**
 * @typedef int32_t
 * @brief Signed 32-bit integer.
 */
typedef signed long     int32_t;

//==============================================================================
//---------------------------------Defines--------------------------------------
//==============================================================================
/**
 * @def NOR_FLASH
 * @brief Address for NOR flash configuration (0x0008).
 */
#define NOR_FLASH				0x0008

/**
 * @def SOFT_VERSION
 * @brief Address for software version (0x000F).
 */
#define SOFT_VERSION			0x000F

/**
 * @def RTC
 * @brief Address for real-time clock (0x0010).
 */
#define RTC						0x0010

/**
 * @def PIC_NOW
 * @brief Address for current page ID (0x0014).
 */
#define PIC_NOW					0x0014

/**
 * @def TP_STATUS
 * @brief Address for touch panel status (0x0016).
 */
#define TP_STATUS				0x0016

/**
 * @def LED_NOW
 * @brief Address for current LED state (0x0031).
 */
#define LED_NOW					0x0031

/**
 * @def AD_VALUE
 * @brief Address for ADC value (0x0032).
 */
#define AD_VALUE				0x0032

/**
 * @def SYSTEM_CONFIG
 * @brief Address for system configuration (0x0080).
 */
#define SYSTEM_CONFIG			0x0080

/**
 * @def LED_CONFIG
 * @brief Address for LED configuration (0x0082).
 */
#define LED_CONFIG				0x0082

/**
 * @def PIC_SET
 * @brief Address for setting page ID (0x0084).
 */
#define PIC_SET					0x0084

/**
 * @def RTC_Set
 * @brief Address for setting real-time clock (0x009C).
 */
#define RTC_SET					0x009C

/**
 * @def FOSC
 * @brief System clock frequency (206.4384 MHz).
 */
#define FOSC     				206438400UL

/**
 * @def T1MS
 * @brief Timer period for 1ms interval (65536 - FOSC/12/1000).
 */
#define T1MS    				(65536-FOSC/12/1000)

//==============================================================================
//--------------------------------FUNCTIONS-------------------------------------
//==============================================================================
/**
 * @brief Reads a 16-bit value from a DGUS register.
 * @param Dgus_Addr Address of the DGUS register.
 * @return uint16_t The 16-bit value read from the register.
 */
uint16_t ReadDgus(uint16_t Dgus_Addr);

/**
 * @brief Writes a 16-bit value to a DGUS register.
 * @param Dgus_Addr Address of the DGUS register.
 * @param Val The 16-bit value to write.
 */
void WriteDgus(uint16_t Dgus_Addr, uint16_t Val);

/**
 * @brief Writes a buffer to a DGUS variable pointer register.
 * @param Addr Starting address of the DGUS register.
 * @param pBuf Pointer to the buffer containing data to write.
 * @param Len16 Number of 16-bit words to write.
 */
void WriteDgusVp(uint16_t Addr, uint8_t* pBuf, uint16_t Len16);

/**
 * @brief Reads a buffer from a DGUS variable pointer register.
 * @param Addr Starting address of the DGUS register.
 * @param pBuf Pointer to the buffer to store the read data.
 * @param Len16 Number of 16-bit words to read.
 */
void ReadDgusVp(uint16_t Addr, uint8_t* pBuf, uint16_t Len16);

/**
 * @brief Initializes the CPU and system peripherals.
 */
void InitCPU(void);

/**
 * @brief Gets the current page ID from the DGUS register.
 * @return uint16_t The current page ID.
 */
uint16_t GetPageID(void);

/**
 * @brief Changes the current page to the specified page ID.
 * @param PageID The page ID to switch to.
 */
void PageChange(uint16_t PageID);

//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================
#endif