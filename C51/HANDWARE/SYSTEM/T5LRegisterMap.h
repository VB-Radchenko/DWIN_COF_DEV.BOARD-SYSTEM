#ifndef __T5LREGISTERMAP_H__
#define __T5LREGISTERMAP_H__
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
//---------------------------------Registers------------------------------------
//==============================================================================
/**
 * @def P0
 * @brief Port 0 register (address 0x80).
 * @details 8-bit I/O port, can serve as address bus for external memory.
 *          Each bit (P0.0 to P0.7) can be 0 (low, 0V output or input with pull-down)
 *          or 1 (high, 5V output or input with pull-up, depending on P0MDOUT).
 *          Note: P0.0 is also used as TR4 for UART4 control.
 */
sfr P0 = 0x80;

/**
 * @def SP
 * @brief Stack Pointer register (address 0x81).
 * @details 8-bit register (0x00 to 0xFF) pointing to the next stack location
 *          in internal memory (0x00-0x7F or 0x00-0xFF based on model).
 *          Typically initialized to 0x07 in InitCPU.
 */
sfr SP = 0x81;

/**
 * @def DPL
 * @brief Data Pointer Low byte (address 0x82).
 * @details Low byte of 16-bit data pointer (0x00 to 0xFF), combined with DPH
 *          to form addresses (0x0000 to 0xFFFF) for MOVX or DGUS operations.
 */
sfr DPL = 0x82;

/**
 * @def DPH
 * @brief Data Pointer High byte (address 0x83).
 * @details High byte of 16-bit data pointer (0x00 to 0xFF), combined with DPL.
 */
sfr DPH = 0x83;

/**
 * @def PCON
 * @brief Power Control register (address 0x87).
 * @details Controls power modes and idle states.
 *          Bits PCON.0 to PCON.3: 0 = disabled, 1 = enabled (idle/stop modes).
 *          Bits PCON.4 to PCON.7: Reserved or T5L-specific (e.g., watchdog reset flag).
 *          Requires T5L documentation for exact bit definitions.
 */
sfr PCON = 0x87;

/**
 * @def TCON
 * @brief Timer Control register (address 0x88).
 * @details Manages Timer0, Timer1, and external interrupts.
 */
sfr TCON = 0x88;

/**
 * @def TF1
 * @brief Timer1 overflow flag (TCON^7).
 * @details 0 = no overflow, 1 = Timer1 overflow occurred (cleared in ISR).
 */
sbit TF1 = TCON^7;

/**
 * @def TR1
 * @brief Timer1 run control bit (TCON^6).
 * @details 0 = Timer1 stopped, 1 = Timer1 running.
 */
sbit TR1 = TCON^6;

/**
 * @def TF0
 * @brief Timer0 overflow flag (TCON^5).
 * @details 0 = no overflow, 1 = Timer0 overflow occurred (cleared in ISR).
 */
sbit TF0 = TCON^5;

/**
 * @def TR0
 * @brief Timer0 run control bit (TCON^4).
 * @details 0 = Timer0 stopped, 1 = Timer0 running.
 */
sbit TR0 = TCON^4;

/**
 * @def IE1
 * @brief External interrupt 1 flag (TCON^3).
 * @details 0 = no interrupt, 1 = INT1 triggered (cleared in ISR).
 */
sbit IE1 = TCON^3;

/**
 * @def IT1
 * @brief External interrupt 1 trigger type (TCON^2).
 * @details 0 = level-triggered, 1 = falling-edge triggered.
 */
sbit IT1 = TCON^2;

/**
 * @def IE0
 * @brief External interrupt 0 flag (TCON^1).
 * @details 0 = no interrupt, 1 = INT0 triggered (cleared in ISR).
 */
sbit IE0 = TCON^1;

/**
 * @def IT0
 * @brief External interrupt 0 trigger type (TCON^0).
 * @details 0 = level-triggered, 1 = falling-edge triggered.
 */
sbit IT0 = TCON^0;

/**
 * @def TMOD
 * @brief Timer Mode register (address 0x89).
 * @details Configures Timer0 and Timer1 modes.
 *          Bits TMOD.7 to TMOD.4: Timer1 mode (00 = 13-bit, 01 = 16-bit,
 *          10 = 8-bit autoreload, 11 = stop).
 *          Bits TMOD.3 to TMOD.0: Timer0 mode (same as above).
 *          Bits TMOD.2/TMOD.0: Gate for Timer1/Timer0 (0 = TRx, 1 = INTx).
 *          Values range from 0x00 to 0xFF (e.g., 0x01 = 16-bit Timer0).
 */
sfr TMOD = 0x89;

/**
 * @def TH0
 * @brief Timer0 high byte (address 0x8C).
 * @details High byte of 16-bit Timer0 value (0x00 to 0xFF).
 */
sfr TH0 = 0x8C;

/**
 * @def TL0
 * @brief Timer0 low byte (address 0x8A).
 * @details Low byte of 16-bit Timer0 value (0x00 to 0xFF).
 */
sfr TL0 = 0x8A;

/**
 * @def TH1
 * @brief Timer1 high byte (address 0x8D).
 * @details High byte of 16-bit Timer1 value (0x00 to 0xFF).
 */
sfr TH1 = 0x8D;

/**
 * @def TL1
 * @brief Timer1 low byte (address 0x8B).
 * @details Low byte of 16-bit Timer1 value (0x00 to 0xFF).
 */
sfr TL1 = 0x8B;

/**
 * @def T2CON
 * @brief Timer2 Control register (address 0xC8).
 * @details Controls Timer2 operation.
 *          Bit TR2 (0): 0 = stopped, 1 = running.
 *          Bits T2CON.1 to T2CON.7: Mode settings (0x00 to 0xFF, e.g., 0x70 = autoreload).
 *          Requires T5L documentation for full bit definition.
 */
sfr T2CON = 0xC8;

/**
 * @def TR2
 * @brief Timer2 run control bit (T2CON^0).
 * @details 0 = Timer2 stopped, 1 = Timer2 running.
 */
sbit TR2 = T2CON^0;

/**
 * @def TRL2H
 * @brief Timer2 reload high byte (address 0xCB).
 * @details High byte of reload value for Timer2 (0x00 to 0xFF).
 */
sfr TRL2H = 0xCB;

/**
 * @def TRL2L
 * @brief Timer2 reload low byte (address 0xCA).
 * @details Low byte of reload value for Timer2 (0x00 to 0xFF).
 */
sfr TRL2L = 0xCA;

/**
 * @def TH2
 * @brief Timer2 high byte (address 0xCD).
 * @details High byte of current Timer2 value (0x00 to 0xFF).
 */
sfr TH2 = 0xCD;

/**
 * @def TL2
 * @brief Timer2 low byte (address 0xCC).
 * @details Low byte of current Timer2 value (0x00 to 0xFF).
 */
sfr TL2 = 0xCC;

/**
 * @def CKCON
 * @brief Clock Control register (address 0x8E).
 * @details Configures timer clock dividers.
 *          Bits CKCON.0 to CKCON.3: Divider for Timer0/Timer1 (0 = Fosc/12, 1 = Fosc/4, etc.).
 *          Bits CKCON.4 to CKCON.7: Reserved or T5L-specific.
 *          Values range from 0x00 to 0xFF (e.g., 0x00 = standard division).
 */
sfr CKCON = 0x8E;

/**
 * @def P1
 * @brief Port 1 register (address 0x90).
 * @details 8-bit I/O port.
 *          Bits P1.0 to P1.7: 0 = low (0V), 1 = high (5V), depends on P1MDOUT.
 */
sfr P1 = 0x90;

/**
 * @def DPC
 * @brief Display Control register (address 0x93).
 * @details Controls display settings for T5L.
 *          Bits DPC.0 to DPC.7: 0x00 to 0xFF (e.g., 0x00 = display off).
 *          Requires T5L documentation for exact bit definitions.
 */
sfr DPC = 0x93;

/**
 * @def PAGESEL
 * @brief Page Select register (address 0x94).
 * @details Selects the active display page.
 *          Bits PAGESEL.0 to PAGESEL.7: 0x00 to 0xFF (page ID).
 */
sfr PAGESEL = 0x94;

/**
 * @def D_PAGESEL
 * @brief Display Page Select register (address 0x95).
 * @details Selects the display page for T5L.
 *          Bits D_PAGESEL.0 to D_PAGESEL.7: 0x00 to 0xFF (page ID).
 */
sfr D_PAGESEL = 0x95;

/**
 * @def SCON0
 * @brief UART2 Control register (address 0x98).
 * @details Configures UART2 operation.
 */
sfr SCON0 = 0x98;

/**
 * @def SBUF0
 * @brief UART2 Buffer register (address 0x99).
 * @details Holds transmit/receive data for UART2.
 *          Bits SBUF0.0 to SBUF0.7: 0x00 to 0xFF.
 */
sfr SBUF0 = 0x99;

/**
 * @def SCON1
 * @brief UART3 Control register (address 0x9B).
 * @details Configures UART3 operation (similar to SCON0).
 */
sfr SCON1 = 0x9B;

/**
 * @def SBUF1
 * @brief UART3 Buffer register (address 0x9C).
 * @details Holds transmit/receive data for UART3.
 *          Bits SBUF1.0 to SBUF1.7: 0x00 to 0xFF.
 */
sfr SBUF1 = 0x9C;

/**
 * @def IEN2
 * @brief Interrupt Enable register 2 (address 0x9A).
 * @details Enables additional interrupts (T5L-specific).
 *          Bits IEN2.0 to IEN2.7: 0x00 to 0xFF (requires documentation).
 */
sfr IEN2 = 0x9A;

/**
 * @def P2
 * @brief Port 2 register (address 0xA0).
 * @details 8-bit I/O port, often used as address bus.
 *          Bits P2.0 to P2.7: 0 = low (0V), 1 = high (5V), depends on P2MDOUT.
 */
sfr P2 = 0xA0;

/**
 * @def IEN0
 * @brief Interrupt Enable register 0 (address 0xA8).
 * @details Enables global and specific interrupts.
 */
sfr IEN0 = 0xA8;

/**
 * @def EA
 * @brief Global interrupt enable (IEN0^7).
 * @details 0 = all interrupts disabled, 1 = all enabled if individually set.
 */
sbit EA = IEN0^7;

/**
 * @def ET2
 * @brief Timer2 interrupt enable (IEN0^5).
 * @details 0 = disabled, 1 = enabled.
 */
sbit ET2 = IEN0^5;

/**
 * @def ES0
 * @brief UART2 interrupt enable (IEN0^4).
 * @details 0 = disabled, 1 = enabled.
 */
sbit ES0 = IEN0^4;

/**
 * @def ET1
 * @brief Timer1 interrupt enable (IEN0^3).
 * @details 0 = disabled, 1 = enabled.
 */
sbit ET1 = IEN0^3;

/**
 * @def EX1
 * @brief External interrupt 1 enable (IEN0^2).
 * @details 0 = disabled, 1 = enabled.
 */
sbit EX1 = IEN0^2;

/**
 * @def ET0
 * @brief Timer0 interrupt enable (IEN0^1).
 * @details 0 = disabled, 1 = enabled.
 */
sbit ET0 = IEN0^1;

/**
 * @def EX0
 * @brief External interrupt 0 enable (IEN0^0).
 * @details 0 = disabled, 1 = enabled.
 */
sbit EX0 = IEN0^0;

/**
 * @def IP0
 * @brief Interrupt Priority register 0 (address 0xA9).
 * @details Sets priority for interrupts in IEN0.
 *          Bits IP0.0 to IP0.7: 0 = low, 1 = high priority.
 */
sfr IP0 = 0xA9;

/**
 * @def P3
 * @brief Port 3 register (address 0xB0).
 * @details 8-bit I/O port with alternate functions.
 *          Bits P3.0 to P3.7: 0 = low (0V), 1 = high (5V), depends on P3MDOUT.
 */
sfr P3 = 0xB0;

/**
 * @def IEN1
 * @brief Interrupt Enable register 1 (address 0xB8).
 * @details Enables T5L-specific interrupts.
 */
sfr IEN1 = 0xB8;

/**
 * @def ES2R
 * @brief UART4 receive interrupt enable (IEN1^3).
 * @details 0 = disabled, 1 = enabled.
 */
sbit ES2R = IEN1^3;

/**
 * @def ES2T
 * @brief UART4 transmit interrupt enable (IEN1^2).
 * @details 0 = disabled, 1 = enabled.
 */
sbit ES2T = IEN1^2;

/**
 * @def ECAN
 * @brief CAN interrupt enable (IEN1^1).
 * @details 0 = disabled, 1 = enabled.
 */
sbit ECAN = IEN1^1;

/**
 * @def ES3R
 * @brief UART5 receive interrupt enable (IEN1^5).
 * @details 0 = disabled, 1 = enabled.
 */
sbit ES3R = IEN1^5;

/**
 * @def ES3T
 * @brief UART5 transmit interrupt enable (IEN1^4).
 * @details 0 = disabled, 1 = enabled.
 */
sbit ES3T = IEN1^4;

/**
 * @def IP1
 * @brief Interrupt Priority register 1 (address 0xB9).
 * @details Sets priority for interrupts in IEN1.
 *          Bits IP1.0 to IP1.7: 0 = low, 1 = high priority.
 */
sfr IP1 = 0xB9;

/**
 * @def IRCON2
 * @brief Interrupt Control register 2 (address 0xBF).
 * @details Holds additional interrupt flags (T5L-specific).
 *          Bits IRCON2.0 to IRCON2.7: 0x00 to 0xFF (requires documentation).
 */
sfr IRCON2 = 0xBF;

/**
 * @def IRCON
 * @brief Interrupt Control register (address 0xC0).
 * @details Holds interrupt flags.
 */
sfr IRCON = 0xC0;

/**
 * @def TF2
 * @brief Timer2 overflow flag (IRCON^6).
 * @details 0 = no overflow, 1 = Timer2 overflow occurred (cleared in ISR).
 */
sbit TF2 = IRCON^6;

/**
 * @def PSW
 * @brief Program Status Word register (address 0xD0).
 * @details Stores processor status flags.
 */
sfr PSW = 0xD0;

/**
 * @def CY
 * @brief Carry flag (PSW^7).
 * @details 0 = no carry, 1 = carry occurred.
 */
sbit CY = PSW^7;

/**
 * @def AC
 * @brief Auxiliary carry flag (PSW^6).
 * @details 0 = no auxiliary carry, 1 = auxiliary carry occurred.
 */
sbit AC = PSW^6;

/**
 * @def F0
 * @brief User flag 0 (PSW^5).
 * @details 0 = cleared, 1 = set (user-defined).
 */
sbit F0 = PSW^5;

/**
 * @def RS1
 * @brief Register bank select bit 1 (PSW^4).
 * @details 0/1 with RS0 selects register bank (00 = Bank0, 01 = Bank1, etc.).
 */
sbit RS1 = PSW^4;

/**
 * @def RS0
 * @brief Register bank select bit 0 (PSW^3).
 * @details 0/1 with RS1 selects register bank.
 */
sbit RS0 = PSW^3;

/**
 * @def OV
 * @brief Overflow flag (PSW^2).
 * @details 0 = no overflow, 1 = overflow occurred.
 */
sbit OV = PSW^2;

/**
 * @def F1
 * @brief User flag 1 (PSW^1).
 * @details 0 = cleared, 1 = set (user-defined).
 */
sbit F1 = PSW^1;

/**
 * @def P
 * @brief Parity flag (PSW^0).
 * @details 0 = even parity, 1 = odd parity.
 */
sbit P = PSW^0;

/**
 * @def ADCON
 * @brief ADC Control register (address 0xD8).
 * @details Controls ADC operation (T5L-specific).
 *          Bits ADCON.0 to ADCON.7: 0x00 to 0xFF (e.g., channel select, start).
 *          Requires T5L documentation for exact bit definitions.
 */
sfr ADCON = 0xD8;

/**
 * @def ACC
 * @brief Accumulator register (address 0xE0).
 * @details 8-bit accumulator for arithmetic operations.
 *          Bits ACC.0 to ACC.7: 0x00 to 0xFF.
 */
sfr ACC = 0xE0;

/**
 * @def B
 * @brief B register (address 0xF0).
 * @details Used for multiplication and division.
 *          Bits B.0 to B.7: 0x00 to 0xFF.
 */
sfr B = 0xF0;

/**
 * @def RAMMODE
 * @brief RAM Mode register for DGUS interface (address 0xF8).
 * @details Controls DGUS memory access.
 */
sfr RAMMODE = 0xF8;

/**
 * @def APP_REQ
 * @brief Application request bit (RAMMODE^7).
 * @details 0 = no request, 1 = application request pending.
 */
sbit APP_REQ = RAMMODE^7;

/**
 * @def APP_EN
 * @brief Application enable bit (RAMMODE^6).
 * @details 0 = disabled, 1 = application enabled.
 */
sbit APP_EN = RAMMODE^6;

/**
 * @def APP_RW
 * @brief Application read/write bit (RAMMODE^5).
 * @details 0 = read mode, 1 = write mode.
 */
sbit APP_RW = RAMMODE^5;

/**
 * @def APP_ACK
 * @brief Application acknowledge bit (RAMMODE^4).
 * @details 0 = no acknowledge, 1 = acknowledge received.
 */
sbit APP_ACK = RAMMODE^4;

/**
 * @def ADR_H
 * @brief Address high byte for DGUS interface (address 0xF1).
 * @details High byte of 24-bit address (0x00 to 0xFF).
 */
sfr ADR_H = 0xF1;

/**
 * @def ADR_M
 * @brief Address middle byte for DGUS interface (address 0xF2).
 * @details Middle byte of 24-bit address (0x00 to 0xFF).
 */
sfr ADR_M = 0xF2;

/**
 * @def ADR_L
 * @brief Address low byte for DGUS interface (address 0xF3).
 * @details Low byte of 24-bit address (0x00 to 0xFF).
 */
sfr ADR_L = 0xF3;

/**
 * @def ADR_INC
 * @brief Address increment control for DGUS interface (address 0xF4).
 * @details Sets address increment step (0x00 to 0xFF, typically 0x01).
 */
sfr ADR_INC = 0xF4;

/**
 * @def DATA3
 * @brief Data byte 3 for DGUS interface (address 0xFA).
 * @details Data byte for DGUS operations (0x00 to 0xFF).
 */
sfr DATA3 = 0xFA;

/**
 * @def DATA2
 * @brief Data byte 2 for DGUS interface (address 0xFB).
 * @details Data byte for DGUS operations (0x00 to 0xFF).
 */
sfr DATA2 = 0xFB;

/**
 * @def DATA1
 * @brief Data byte 1 for DGUS interface (address 0xFC).
 * @details Data byte for DGUS operations (0x00 to 0xFF).
 */
sfr DATA1 = 0xFC;

/**
 * @def DATA0
 * @brief Data byte 0 for DGUS interface (address 0xFD).
 * @details Data byte for DGUS operations (0x00 to 0xFF).
 */
sfr DATA0 = 0xFD;

/**
 * @def SM0
 * @brief UART2 mode select bit 0 (SCON0^7).
 * @details 0 = shift register mode, 1 = 8-bit UART mode.
 */
sbit SM0 = SCON0^7;

/**
 * @def SM1
 * @brief UART2 mode select bit 1 (SCON0^6).
 * @details 0 = 8-bit UART, 1 = 9-bit UART.
 */
sbit SM1 = SCON0^6;

/**
 * @def SM2
 * @brief UART2 multiprocessor communication enable (SCON0^5).
 * @details 0 = disabled, 1 = enabled.
 */
sbit SM2 = SCON0^5;

/**
 * @def REN0
 * @brief UART2 receive enable (SCON0^4).
 * @details 0 = disabled, 1 = enabled.
 */
sbit REN0 = SCON0^4;

/**
 * @def TB80
 * @brief UART2 transmit bit 8 (SCON0^3).
 * @details 0 or 1, ninth bit for 9-bit mode.
 */
sbit TB80 = SCON0^3;

/**
 * @def RB80
 * @brief UART2 receive bit 8 (SCON0^2).
 * @details 0 or 1, ninth bit for 9-bit mode.
 */
sbit RB80 = SCON0^2;

/**
 * @def TI0
 * @brief UART2 transmit interrupt flag (SCON0^1).
 * @details 0 = not ready, 1 = transmit complete (cleared by software).
 */
sbit TI0 = SCON0^1;

/**
 * @def RI0
 * @brief UART2 receive interrupt flag (SCON0^0).
 * @details 0 = no data, 1 = data received (cleared by software).
 */
sbit RI0 = SCON0^0;

/**
 * @def SREL0H
 * @brief UART2 baud rate reload high byte (address 0xBA).
 * @details High byte of baud rate reload value (0x00 to 0xFF).
 */
sfr SREL0H = 0xBA;

/**
 * @def SREL0L
 * @brief UART2 baud rate reload low byte (address 0xAA).
 * @details Low byte of baud rate reload value (0x00 to 0xFF).
 */
sfr SREL0L = 0xAA;

/**
 * @def SREL1H
 * @brief UART3 baud rate reload high byte (address 0xBB).
 * @details High byte of baud rate reload value (0x00 to 0xFF).
 */
sfr SREL1H = 0xBB;

/**
 * @def SREL1L
 * @brief UART3 baud rate reload low byte (address 0x9D).
 * @details Low byte of baud rate reload value (0x00 to 0xFF).
 */
sfr SREL1L = 0x9D;

/**
 * @def SCON2T
 * @brief UART4 transmit control register (address 0x96).
 * @details Configures UART4 transmit (T5L-specific).
 *          Bits SCON2T.0 to SCON2T.7: 0x00 to 0xFF (requires documentation).
 */
sfr SCON2T = 0x96;

/**
 * @def SCON2R
 * @brief UART4 receive control register (address 0x97).
 * @details Configures UART4 receive (T5L-specific).
 *          Bits SCON2R.0 to SCON2R.7: 0x00 to 0xFF (requires documentation).
 */
sfr SCON2R = 0x97;

/**
 * @def SBUF2_TX
 * @brief UART4 transmit buffer (address 0x9E).
 * @details Holds data to transmit (0x00 to 0xFF).
 */
sfr SBUF2_TX = 0x9E;

/**
 * @def SBUF2_RX
 * @brief UART4 receive buffer (address 0x9F).
 * @details Holds received data (0x00 to 0xFF).
 */
sfr SBUF2_RX = 0x9F;

/**
 * @def BODE2_DIV_H
 * @brief UART4 baud rate divider high byte (address 0xD9).
 * @details High byte of baud rate divider (0x00 to 0xFF).
 */
sfr BODE2_DIV_H = 0xD9;

/**
 * @def BODE2_DIV_L
 * @brief UART4 baud rate divider low byte (address 0xE7).
 * @details Low byte of baud rate divider (0x00 to 0xFF).
 */
sfr BODE2_DIV_L = 0xD7;

/**
 * @def SCON3T
 * @brief UART5 transmit control register (address 0xA7).
 * @details Configures UART5 transmit (T5L-specific).
 *          Bits SCON3T.0 to SCON3T.7: 0x00 to 0xFF (requires documentation).
 */
sfr SCON3T = 0xA7;

/**
 * @def SCON3R
 * @brief UART5 receive control register (address 0xAB).
 * @details Configures UART5 receive (T5L-specific).
 *          Bits SCON3R.0 to SCON3R.7: 0x00 to 0xFF (requires documentation).
 */
sfr SCON3R = 0xAB;

/**
 * @def SBUF3_TX
 * @brief UART5 transmit buffer (address 0xAC).
 * @details Holds data to transmit (0x00 to 0xFF).
 */
sfr SBUF3_TX = 0xAC;

/**
 * @def SBUF3_RX
 * @brief UART5 receive buffer (address 0xAD).
 * @details Holds received data (0x00 to 0xFF).
 */
sfr SBUF3_RX = 0xAD;

/**
 * @def BODE3_DIV_H
 * @brief UART5 baud rate divider high byte (address 0xAE).
 * @details High byte of baud rate divider (0x00 to 0xFF).
 */
sfr BODE3_DIV_H = 0xAE;

/**
 * @def BODE3_DIV_L
 * @brief UART5 baud rate divider low byte (address 0xAF).
 * @details Low byte of baud rate divider (0x00 to 0xFF).
 */
sfr BODE3_DIV_L = 0xAF;

/**
 * @def CAN_CR
 * @brief CAN Control register (address 0x8F).
 * @details Controls CAN module operation (T5L-specific).
 *          Bits CAN_CR.0 to CAN_CR.7: 0x00 to 0xFF (requires documentation).
 */
sfr CAN_CR = 0x8F;

/**
 * @def CAN_IR
 * @brief CAN Interrupt register (address 0x91).
 * @details Holds CAN interrupt flags (T5L-specific).
 *          Bits CAN_IR.0 to CAN_IR.7: 0x00 to 0xFF (requires documentation).
 */
sfr CAN_IR = 0x91;

/**
 * @def CAN_ET
 * @brief CAN Error and Transmit register (address 0xE8).
 * @details Manages CAN errors and transmission (T5L-specific).
 *          Bits CAN_ET.0 to CAN_ET.7: 0x00 to 0xFF (requires documentation).
 */
sfr CAN_ET = 0xE8;

/**
 * @def P0MDOUT
 * @brief Port 0 mode output register (address 0xB7).
 * @details Configures P0 pin output mode.
 *          Bits P0MDOUT.0 to P0MDOUT.7: 0 = open-drain, 1 = push-pull.
 */
sfr P0MDOUT = 0xB7;

/**
 * @def P1MDOUT
 * @brief Port 1 mode output register (address 0xBC).
 * @details Configures P1 pin output mode.
 *          Bits P1MDOUT.0 to P1MDOUT.7: 0 = open-drain, 1 = push-pull.
 */
sfr P1MDOUT = 0xBC;

/**
 * @def P2MDOUT
 * @brief Port 2 mode output register (address 0xBD).
 * @details Configures P2 pin output mode.
 *          Bits P2MDOUT.0 to P2MDOUT.7: 0 = open-drain, 1 = push-pull.
 */
sfr P2MDOUT = 0xBD;

/**
 * @def P3MDOUT
 * @brief Port 3 mode output register (address 0xBE).
 * @details Configures P3 pin output mode.
 *          Bits P3MDOUT.0 to P3MDOUT.7: 0 = open-drain, 1 = push-pull.
 */
sfr P3MDOUT = 0xBE;

/**
 * @def MUX_SEL
 * @brief Multiplexer Select register for watchdog control (address 0xC9).
 * @details Controls multiplexer and watchdog settings.
 *       Bit 7 (0x80): CAN interface (1=enabled on P0.2/3).
 *       Bit 6 (0x40): UART2 interface (1=enabled on P0.4/5).
 *       Bit 5 (0x20): UART3 interface (1=enabled on P0.6/7).
 *       Bit 1 (0x02): WDT enable (1=on).
 *       Bit 0 (0x01): WDT refresh (1=feed).
 */
sfr MUX_SEL = 0xC9;

/**
 * @def PORTDRV
 * @brief Port Drive Strength register (address 0xF9).
 * @details Sets drive strength for ports.
 *          Bits PORTDRV.0 to PORTDRV.7: 0x00 to 0xFF (e.g., 0x01 = standard).
 */
sfr PORTDRV = 0xF9;

/**
 * @def MAC_MODE
 * @brief MAC Mode register (address 0xE5).
 * @details Configures MAC operation (T5L-specific).
 *          Bits MAC_MODE.0 to MAC_MODE.7: 0x00 to 0xFF (requires documentation).
 */
sfr MAC_MODE = 0xE5;

/**
 * @def DIV_MODE
 * @brief Divider Mode register (address 0xE6).
 * @details Configures divider settings (T5L-specific).
 *          Bits DIV_MODE.0 to DIV_MODE.7: 0x00 to 0xFF (requires documentation).
 */
sfr DIV_MODE = 0xE6;

/**
 * @def EXADR
 * @brief External Address register (address 0xFE).
 * @details Holds address for external memory access.
 *          Bits EXADR.0 to EXADR.7: 0x00 to 0xFF.
 */
sfr EXADR = 0xFE;

/**
 * @def EXDATA
 * @brief External Data register (address 0xFF).
 * @details Holds data for external memory access.
 *          Bits EXDATA.0 to EXDATA.7: 0x00 to 0xFF.
 */
sfr EXDATA = 0xFF;

//==============================================================================
//---------------------------------Defines--------------------------------------
//==============================================================================
/**
 * @def HEADER_ADC
 * @brief DGUS protocol ADC header byte (0xAA).
 * @details Used in PWM.c for ADC packet framing.
 */
#define HEADER_ADC 0xAA

/**
 * @def FRAME_LEN
 * @brief Maximum frame length for DGUS protocol (0xFF).
 * @details Defines maximum data length, unused in current code but retained.
 */
#define FRAME_LEN 0xFF

//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================
#endif