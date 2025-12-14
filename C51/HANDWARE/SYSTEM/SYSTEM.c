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
//---------------------------------VARIABLES------------------------------------
//==============================================================================


//==============================================================================
//--------------------------------FUNCTIONS-------------------------------------
//==============================================================================
/**
 * @brief Reads a buffer from a DGUS variable pointer register.
 * @param Addr Starting address of the DGUS register.
 * @param pBuf Pointer to the buffer to store the read data.
 * @param Len16 Number of 16-bit words to read.
 */
void ReadDgusVp(uint16_t Addr, uint8_t* pBuf, uint16_t Len16)
{
    /**
     * @var unsigned char i
     * @brief Flag for handling odd/even address alignment.
     */
    unsigned char i;

    EA = 0;
    i = (unsigned char)(Addr & 0x01);
    Addr = Addr / 2;
    ADR_H = 0x00;
    ADR_M = (unsigned char)(Addr >> 8);
    ADR_L = (unsigned char)(Addr);
    ADR_INC = 0x01;
    RAMMODE = 0xAF;
    while (APP_ACK == 0);
    while (Len16 > 0)
    {
        APP_EN = 1;
        while (APP_EN == 1);
        if ((i == 0) && (Len16 > 0))
        {
            *pBuf++ = DATA3;
            *pBuf++ = DATA2;
            i = 1;
            Len16--;
        }
        if ((i == 1) && (Len16 > 0))
        {
            *pBuf++ = DATA1;
            *pBuf++ = DATA0;
            i = 0;
            Len16--;
        }
    }
    RAMMODE = 0x00;
		EA = 1;
}

/**
 * @brief Writes a buffer to a DGUS variable pointer register.
 * @param Addr Starting address of the DGUS register.
 * @param pBuf Pointer to the buffer containing data to write.
 * @param Len16 Number of 16-bit words to write.
 */
void WriteDgusVp(uint16_t Addr, uint8_t* pBuf, uint16_t Len16)
{
    /**
     * @var unsigned char i
     * @brief Flag for handling odd/even address alignment.
     */
	uint8_t i;  
	    EA = 0;
	i = (uint8_t)(Addr&0x01);
	Addr >>= 1;
	ADR_H = 0x00;
	ADR_M = (uint8_t)(Addr>>8);
	ADR_L = (uint8_t)Addr;    
	ADR_INC = 0x01;
	RAMMODE = 0x8F;
	while(APP_ACK==0);
	if(i && Len16>0)
	{	
		RAMMODE = 0x83;	
		DATA1 = *pBuf++;		
		DATA0 = *pBuf++;	
		APP_EN = 1;		
		Len16--;
	}
	RAMMODE = 0x8F;
	while(Len16>=2)
	{	
		DATA3 = *pBuf++;		
		DATA2 = *pBuf++;
		DATA1 = *pBuf++;		
		DATA0 = *pBuf++;
		APP_EN = 1;		
		Len16 -= 2;
	}
	if(Len16)
	{	
		RAMMODE = 0x8C;
		DATA3 = *pBuf++;		
		DATA2 = *pBuf++;
		APP_EN = 1;
	}
	RAMMODE = 0x00;
    EA = 1;
}

/**
 * @brief Gets the current page ID from the DGUS register.
 * @return uint16_t The current page ID.
 */
uint16_t GetPageID(void)
{
    /**
     * @var uint16_t nPage
     * @brief Stores the current page ID read from DGUS register.
     */
    uint16_t nPage;
		nPage = ReadDgus(PIC_NOW);
    return nPage;
}

/**
 * @brief Changes the current page to the specified page ID.
 * @param PageID The page ID to switch to.
 */
void PageChange(uint16_t PageID)
{
    /**
     * @var uint8_t buf[4]
     * @brief Buffer for constructing page change command.
     */
    uint8_t buf[4];

    buf[0] = 0x5A;
    buf[1] = 0x01;
    buf[2] = (uint8_t)(PageID >> 8);
    buf[3] = (uint8_t)PageID;
    WriteDgusVp(PIC_SET, buf, 2);
}

/**
 * @brief Reads a 16-bit value from a DGUS register.
 * @param DgusAddr Address of the DGUS register.
 * @return uint16_t The 16-bit value read from the register.
 */
uint16_t ReadDgus(uint16_t DgusAddr)
{
    /**
     * @var uint16_t R_Dgus
     * @brief Stores the 16-bit value read from the DGUS register.
     */
    uint16_t R_Dgus = 0;
    EA = 0;
    ADR_H = 0x00;
    ADR_M = (uint8_t)((DgusAddr / 2) >> 8);
    ADR_L = (uint8_t)(DgusAddr / 2);
    RAMMODE = 0xAF;
    while (!APP_ACK);
    APP_EN = 1;
    while (APP_EN);
    if (DgusAddr % 2)
        R_Dgus = (DATA1 << 8) + DATA0;
    else
        R_Dgus = (DATA3 << 8) + DATA2;
    RAMMODE = 0x00;
    EA = 1;

    return R_Dgus;
}

/**
 * @brief Writes a 16-bit value to a DGUS register.
 * @param DgusAddr Address of the DGUS register.
 * @param Val The 16-bit value to write.
 */
void WriteDgus(uint16_t DgusAddr, uint16_t Val)
{
    EA = 0;
    ADR_H = 0x00;
    ADR_M = (uint8_t)((DgusAddr / 2) >> 8);
    ADR_L = (uint8_t)(DgusAddr / 2);
    RAMMODE = 0xAF;
    while (!APP_ACK);
    APP_EN = 1;
    while (APP_EN);
    RAMMODE = 0x00;
    ADR_M = (uint8_t)((DgusAddr / 2) >> 8);
    ADR_L = (uint8_t)(DgusAddr / 2);
    RAMMODE = 0x8F;
    while (!APP_ACK);
    if (DgusAddr % 2)
    {
        DATA1 = (uint8_t)(Val >> 8);
        DATA0 = (uint8_t)(Val);
    }
    else
    {
        DATA3 = (uint8_t)(Val >> 8);
        DATA2 = (uint8_t)(Val);
    }
    APP_EN = 1;
    while (APP_EN);
    RAMMODE = 0x00;
    EA = 1;
}

/**
 * @brief Initializes system configuration registers.
 */
void InitCFG(void)
{
    CKCON = 0x00;      ///< Set clock control register.
    T2CON = 0x70;      ///< Configure Timer2.
    DPC = 0x00;        ///< Set display control register.
    PAGESEL = 0x01;    ///< Set page select register.
    D_PAGESEL = 0x02;  ///< Set display page select register.
    MUX_SEL = 0x60;    ///< Configure multiplexer select.
    PORTDRV = 0x01;    ///< Set port drive strength.
    RAMMODE = 0x00;    ///< Reset RAM mode.
}

/**
 * @brief Initializes interrupt control registers.
 */
void InitInt(void)
{
    IEN0 = 0x00;       ///< Clear interrupt enable register 0.
    IEN1 = 0x00;       ///< Clear interrupt enable register 1.
    IEN2 = 0x00;       ///< Clear interrupt enable register 2.
    IP0 = 0x00;        ///< Clear interrupt priority register 0.
    IP1 = 0x00;        ///< Clear interrupt priority register 1.
}

/**
 * @brief Initializes the CPU and system peripherals.
 */
void InitCPU(void)
{
    EA = 0;            ///< Disable global interrupts.
    InitCFG();         ///< Initialize configuration registers.
    InitInt();         ///< Initialize interrupt registers.
    EA = 1;            ///< Enable global interrupts.
}


//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================