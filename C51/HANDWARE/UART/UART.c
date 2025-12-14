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
#include "Uart.h"

//==============================================================================
//---------------------------------Variables------------------------------------
//==============================================================================
#if UART2_ENABLE
Uartx_Define xdata Uart2;           ///< UART2 configuration and state.
Uartx_Frame_Data xdata Uart2_Frame; ///< UART2 frame data.
#endif
#if UART3_ENABLE
Uartx_Define xdata Uart3;           ///< UART3 configuration and state.
Uartx_Frame_Data xdata Uart3_Frame; ///< UART3 frame data.
#endif
#if UART4_ENABLE
Uartx_Define xdata Uart4;           ///< UART4 configuration and state.
Uartx_Frame_Data xdata Uart4_Frame; ///< UART4 frame data.
#endif
#if UART5_ENABLE
Uartx_Define xdata Uart5;           ///< UART5 configuration and state.
Uartx_Frame_Data xdata Uart5_Frame; ///< UART5 frame data.
#endif

bit ResponseFlag = 0;               ///< Response flag.
bit AutoDataUpload = 0;             ///< Auto data upload flag.
bit CrcCheckFlag = 0;               ///< CRC check flag.

//==============================================================================
//--------------------------------Functions-------------------------------------
//==============================================================================
#if UART2_ENABLE
/**
 * @brief Initializes UART2 interface.
 */
static void Uart2Init(void)
{
    uint16_t i;
    Uart2.Id = 2;
    Uart2.TxRead = 0;
    Uart2.TxWrite = 0;
    Uart2.TxBusy = 0;
    Uart2.RxRead = 0;
    Uart2.RxWrite = 0;
    Uart2.RxBusy = 0;
    Uart2.RxFlag = UART_REV_PRE;
    Uart2.Response = RESPONSE_UART2;
    Uart2.CrcCheck = CRC_CHECK_UART2;
    Uart2.Delay = DELAY_UART2;
    for (i = 0; i < UART_TX_LENGTH; i++) Uart2.TxBuffer[i] = 0;
    for (i = 0; i < UART_RX_LENGTH; i++) Uart2.RxBuffer[i] = 0;
    i = 1024 - FOSC / 64 / BAUD_UART2;
    MUX_SEL |= 0x40;
    P0MDOUT &= 0xCF;
    P0MDOUT |= 0x10;
    ADCON = 0x80;
    SCON0 = 0x50;
    SREL0H = (uint8_t)(i >> 8);
    SREL0L = (uint8_t)i;
    ES0 = 1;
    EA = 1;
}
#endif

#if UART3_ENABLE
/**
 * @brief Initializes UART3 interface.
 */
static void Uart3Init(void)
{
    uint16_t i;
    Uart3.Id = 3;
    Uart3.TxRead = 0;
    Uart3.TxWrite = 0;
    Uart3.TxBusy = 0;
    Uart3.RxRead = 0;
    Uart3.RxWrite = 0;
    Uart3.RxBusy = 0;
    Uart3.RxFlag = UART_REV_PRE;
    Uart3.Response = RESPONSE_UART3;
    Uart3.CrcCheck = CRC_CHECK_UART3;
    Uart3.Delay = DELAY_UART3;
    for (i = 0; i < UART_TX_LENGTH; i++) Uart3.TxBuffer[i] = 0;
    for (i = 0; i < UART_RX_LENGTH; i++) Uart3.RxBuffer[i] = 0;
    i = 1024 - FOSC / 32 / BAUD_UART3;
    SREL1H = (uint8_t)(i >> 8);
    SREL1L = (uint8_t)i;
    MUX_SEL |= 0x20;
    P0MDOUT |= 0x40;
    SCON1 = 0x90;
    IEN2 |= 0x01;
    EA = 1;
}
#endif

#if UART4_ENABLE
/**
 * @brief Initializes UART4 interface.
 */
static void Uart4Init(void)
{
    uint16_t i;
    Uart4.Id = 4;
    Uart4.TxRead = 0;
    Uart4.TxWrite = 0;
    Uart4.TxBusy = 0;
    Uart4.RxRead = 0;
    Uart4.RxWrite = 0;
    Uart4.RxBusy = 0;
    Uart4.RxFlag = UART_REV_PRE;
    Uart4.Response = RESPONSE_UART4;
    Uart4.CrcCheck = CRC_CHECK_UART4;
    Uart4.Delay = DELAY_UART4;
    for (i = 0; i < UART_TX_LENGTH; i++) Uart4.TxBuffer[i] = 0;
    for (i = 0; i < UART_RX_LENGTH; i++) Uart4.RxBuffer[i] = 0;
    P0MDOUT |= 0x03;
    i = FOSC / 8 / BAUD_UART4;
    SCON2T = 0x80;
    SCON2R = 0x80;
    ES2R = 1;
    ES2T = 1;
    BODE2_DIV_H = (uint8_t)(i >> 8);
    BODE2_DIV_L = (uint8_t)i;
    P0MDOUT |= (1 << 0);
    TR4 = 0;
    EA = 1;
}
#endif

#if UART5_ENABLE
/**
 * @brief Initializes UART5 interface.
 */
static void Uart5Init(void)
{
    uint16_t i;
    Uart5.Id = 5;
    Uart5.TxRead = 0;
    Uart5.TxWrite = 0;
    Uart5.TxBusy = 0;
    Uart5.RxRead = 0;
    Uart5.RxWrite = 0;
    Uart5.RxBusy = 0;
    Uart5.RxFlag = UART_REV_PRE;
    Uart5.Response = RESPONSE_UART5;
    Uart5.CrcCheck = CRC_CHECK_UART5;
    Uart5.Delay = DELAY_UART5;
    for (i = 0; i < UART_TX_LENGTH; i++) Uart5.TxBuffer[i] = 0;
    for (i = 0; i < UART_RX_LENGTH; i++) Uart5.RxBuffer[i] = 0;
    P0MDOUT |= 0x03;
    i = FOSC / 8 / BAUD_UART5;
    SCON3T = 0x80;
    SCON3R = 0x80;
    ES3R = 1;
    ES3T = 1;
    BODE3_DIV_H = (uint8_t)(i >> 8);
    BODE3_DIV_L = (uint8_t)i;
    P0MDOUT |= (1 << 1);
    EA = 1;
}
#endif

/**
 * @brief Initializes all enabled UART interfaces.
 */
void UartInit(void)
{
#if UART2_ENABLE
    Uart2Init();
#endif
#if UART3_ENABLE
    Uart3Init();
#endif
#if UART4_ENABLE
    Uart4Init();
#endif
#if UART5_ENABLE
    Uart5Init();
#endif
}

/**
 * @brief Decrements delay counters for all enabled UART interfaces.
 */
void InterfaceDelay(void)
{
#if UART2_ENABLE
    if (Uart2.Delay > 0) Uart2.Delay--;
#endif
#if UART3_ENABLE
    if (Uart3.Delay > 0) Uart3.Delay--;
#endif
#if UART4_ENABLE
    if (Uart4.Delay > 0) Uart4.Delay--;
#endif
#if UART5_ENABLE
    if (Uart5.Delay > 0) Uart5.Delay--;
#endif
}

/**
 * @brief Writes a byte to the UART transmit buffer.
 * @param uart Pointer to UART configuration structure.
 * @param dat Byte to transmit.
 */
void UartTxWriteBuffer(Uartx_Define* uart, uint8_t dat)
{
    uart->TxBuffer[uart->TxWrite] = dat;
    if (uart->TxRead > uart->TxWrite)
    {
        while ((uart->TxWrite + 1) == uart->TxRead);
    }
    ++uart->TxWrite;
    if (uart->TxWrite >= UART_TX_LENGTH)
    {
        while (uart->TxRead == 0);
        uart->TxWrite = 0;
    }
    if (uart->TxBusy == 0)
    {
        uart->TxBusy = 1;
        if (uart->Id == 2) TI0 = 1;
        else if (uart->Id == 3) SCON1 |= 0x02;
        else if (uart->Id == 4) { SCON2T |= 0x01; }
        else if (uart->Id == 5) SCON3T |= 0x01;
    }
}

/**
 * @brief Sends a single byte over the specified UART.
 * @param uart_number UART identifier (2, 3, 4, or 5).
 * @param dat Byte to send.
 */
void UartSendByte(uint8_t uart_number, uint8_t dat)
{
#if UART2_ENABLE
    if (uart_number == 2) UartTxWriteBuffer(&Uart2, dat);
#endif
#if UART3_ENABLE
    if (uart_number == 3) UartTxWriteBuffer(&Uart3, dat);
#endif
#if UART4_ENABLE
    if (uart_number == 4) UartTxWriteBuffer(&Uart4, dat);
#endif
#if UART5_ENABLE
    if (uart_number == 5) UartTxWriteBuffer(&Uart5, dat);
#endif
}

/**
 * @brief Sends a string of bytes over the specified UART.
 * @param uart_number UART identifier (2, 3, 4, or 5).
 * @param str Pointer to the byte array to send.
 * @param len Length of the byte array.
 */
void UartSendStr(uint8_t uart_number, uint8_t* str, uint8_t len)
{
    uint8_t i;
    for (i = 0; i < len; i++)
    {
        UartSendByte(uart_number, *str++);
    }
}

/**
 * @brief Sends data over the specified UART with optional CRC.
 * @param arr Data array to send.
 * @param uart_num UART identifier (2, 3, 4, or 5).
 * @param auto_send Enable automatic data upload.
 * @param crc_ck Enable CRC check.
 */
void UartDataSend(uint8_t* arr, uint8_t uart_num, bit auto_send, bit crc_ck)
{
    uint16_t v1 = ReadDgus(0x0f01);
    AutoDataUpload = auto_send;
    if (AutoDataUpload)
    {
        CrcCheckFlag = crc_ck;
        if (CrcCheckFlag)
        {
            uint16_t crc = 0;
            arr[2] = (((uint8_t)v1) << 1) + 6;
            crc = Crc16Table(arr + 3, arr[2] - 2);
            arr[arr[2] + 1] = crc & 0x00FF;
            arr[arr[2] + 2] = crc >> 8;
            UartSendStr(uart_num, arr, arr[2] + 3);
            arr[2] = (((uint8_t)v1) << 1) + 4;
        }
        else
        {
            UartSendStr(uart_num, arr, arr[2] + 3);
        }
    }
}

/**
 * @brief Reads data from DGUS register 0x0F00 and sends it over enabled UARTs.
 */
void Read0xF00(void)
{
    uint16_t va = ReadDgus(0x0f00);
    uint16_t v1 = ReadDgus(0x0f01);
    if (((uint8_t)(va >> 8)) == 0x5A)
    {
        uint8_t i;
        uint16_t temp;
        uint8_t xdata val[100] = {0};
        val[0] = DTHD1;
        val[1] = DTHD2;
        val[2] = (((uint8_t)v1) << 1) + 4;
        val[3] = 0x83;
        val[4] = (uint8_t)va;
        val[5] = (uint8_t)(v1 >> 8);
        val[6] = (uint8_t)v1;
        for (i = 0; i < (uint8_t)v1; i++)
        {
            temp = ReadDgus(((val[4] << 8) + val[5] + i));
            val[7 + 2 * i] = (uint8_t)(temp >> 8);
            val[8 + 2 * i] = (uint8_t)(temp);
        }
#if UART2_ENABLE
        UartDataSend(val, 2, DATA_UPLOAD_UART2, CRC_CHECK_UART2);
#endif
#if UART3_ENABLE
        UartDataSend(val, 3, DATA_UPLOAD_UART3, CRC_CHECK_UART3);
#endif
#if UART4_ENABLE
        UartDataSend(val, 4, DATA_UPLOAD_UART4, CRC_CHECK_UART4);
#endif
#if UART5_ENABLE
        UartDataSend(val, 5, DATA_UPLOAD_UART5, CRC_CHECK_UART5);
#endif
        WriteDgus(0x0f00, 0);
        WriteDgus(0x0f01, 0);
    }
}

/**
 * @brief Processes command 0x82 for writing data to DGUS registers.
 * @param uart_num UART identifier (2, 3, 4, or 5).
 * @param arr Data array containing the command.
 */
void Deal82Cmd(uint8_t uart_num, uint8_t* arr)
{
    if (CrcCheckFlag == 0)
    {
        if (arr[4] == 0 && arr[5] == 6)
        {
            arr[7] = 0xA5;
        }
        WriteDgusVp((arr[4] << 8) + arr[5], arr + 6, arr[2] - 3);
        if (ResponseFlag)
        {
            uint8_t temp_arr[] = {DTHD1, DTHD2, 0x03, 0x82, 0x4F, 0x4B};
            UartSendStr(uart_num, temp_arr, 6);
        }
    }
    else
    {
        uint16_t crc = Crc16Table(&arr[3], arr[2] - 2);
        uint16_t crc_check = (uint16_t)(arr[3 + arr[2] - 1] << 8) + (uint16_t)(arr[3 + arr[2] - 2]);
        if (crc == crc_check)
        {
            WriteDgusVp((arr[4] << 8) + arr[5], arr + 6, arr[2] - 5);
            if (ResponseFlag)
            {
                uint8_t temp_arr[] = {DTHD1, DTHD2, 0x05, 0x82, 0x4F, 0x4B, 0xA5, 0xEF};
                UartSendStr(uart_num, temp_arr, 8);
            }
        }
    }
}

/**
 * @brief Processes command 0x83 for reading data from DGUS registers.
 * @param uart_num UART identifier (2, 3, 4, or 5).
 * @param arr Output data array.
 * @param arr1 Input data array containing the command.
 */
void Deal83Cmd(uint8_t uart_num, uint8_t* arr, uint8_t* arr1)
{
    uint8_t i;
    if (CrcCheckFlag == 0)
    {
        for (i = 0; i < 7; i++) arr[i] = arr1[i];
        ReadDgusVp((arr[4] << 8) + arr[5], &arr[7], arr[6]);
        arr[2] = (2 * arr[6]) + 4;
        UartSendStr(uart_num, arr, arr[2] + 3);
    }
    else
    {
        uint16_t crc, crc_check;
        for (i = 0; i < 9; i++) arr[i] = arr1[i];
        crc = Crc16Table(&arr[3], arr[2] - 2);
        crc_check = (uint16_t)(arr[3 + arr[2] - 1] << 8) + (uint16_t)(arr[3 + arr[2] - 2]);
        if (crc == crc_check)
        {
            ReadDgusVp((arr[4] << 8) + arr[5], &arr[7], arr[6]);
            arr[2] = (2 * arr[6]) + 4 + 2;
            crc = Crc16Table(arr + 3, arr[2] - 2);
            arr[arr[2] + 1] = crc & 0x00FF;
            arr[arr[2] + 2] = crc >> 8;
            UartSendStr(uart_num, arr, arr[2] + 3);
        }
    }
}

/**
 * @brief Processes received UART data and dispatches commands.
 * @param arr_rece Received data array.
 * @param uart_num UART identifier (2, 3, 4, or 5).
 * @param response Response enable flag.
 * @param crc_ck CRC check enable flag.
 */
void DealUartData(uint8_t* arr_rece, uint8_t uart_num, uint8_t response, uint8_t crc_ck)
{
    if ((arr_rece[0] == DTHD1) && (arr_rece[1] == DTHD2))
    {
        if (arr_rece[3] == 0x82)
        {
            ResponseFlag = response;
            CrcCheckFlag = crc_ck;
            Deal82Cmd(uart_num, arr_rece);
        }
        else if (arr_rece[3] == 0x83)
        {
            uint8_t xdata val[UARTX_FRAME_DATA_LENGTH] = {0};
            CrcCheckFlag = crc_ck;
            Deal83Cmd(uart_num, val, arr_rece);
        }
    }
}

/**
 * @brief Processes received UART frames for a specific UART.
 * @param uart Pointer to UART configuration structure.
 */
void UartHandleFrame(Uartx_Define* uart)
{
    uint8_t c;
    Uartx_Frame_Data* uart_data;
#if UART2_ENABLE
    if (uart->Id == 2) uart_data = &Uart2_Frame;
    else
#endif
#if UART3_ENABLE
    if (uart->Id == 3) uart_data = &Uart3_Frame;
    else
#endif
#if UART4_ENABLE
    if (uart->Id == 4) uart_data = &Uart4_Frame;
    else
#endif
#if UART5_ENABLE
    if (uart->Id == 5) uart_data = &Uart5_Frame;
    else
#endif
    {
        return; // Exit if no valid UART is found
    }

    while ((uart->RxWrite - uart->RxRead + UART_RX_LENGTH) % UART_RX_LENGTH)
    {
        EA = 0;
        c = uart->RxBuffer[uart->RxRead++];
        uart->RxRead %= UART_RX_LENGTH;
        uart->RxBusy = 0;
        EA = 1;
        if (uart->RxFlag == UART_REV_PRE)
        {
            uart_data->DataLen = 0;
            uart_data->DataCode = 0x00;
            uart_data->VarAddr = 0x0000;
            uart_data->VarIndex = 0;
            if (c == DTHD1)
            {
                uart->RxFlag = UART_REV_GETFH1;
                uart_data->VarData[uart_data->VarIndex++] = c;
            }
        }
        else if (uart->RxFlag == UART_REV_GETFH1)
        {
            if (c == DTHD2)
            {
                uart->RxFlag = UART_REV_GETFH2;
                uart_data->VarData[uart_data->VarIndex++] = c;
            }
            else
            {
                uart->RxFlag = UART_REV_PRE;
            }
        }
        else if (uart->RxFlag == UART_REV_GETFH2)
        {
            if (c < 3 || c > UARTX_FRAME_DATA_LENGTH)
            {
                uart->RxFlag = UART_REV_PRE;
            }
            else
            {
                uart_data->DataLen = c;
                uart_data->VarData[uart_data->VarIndex++] = c;
                uart->RxFlag = UART_REV_GETLEN;
            }
        }
        else if (uart->RxFlag == UART_REV_GETLEN)
        {
            if (c != 0x82 && c != 0x83)
            {
                if (c == 0x80 || c == 0x81)
                {
                    uart_data->DataCode = c;
                    uart_data->VarData[uart_data->VarIndex++] = c;
                    uart->RxFlag = UART_REV_GETADDR2;
                    uart_data->DataLen += 2;
                }
                else
                {
                    uart->RxFlag = UART_REV_PRE;
                }
            }
            else
            {
                uart_data->DataCode = c;
                uart_data->VarData[uart_data->VarIndex++] = c;
                uart->RxFlag = UART_REV_GETCODE;
            }
        }
        else if (uart->RxFlag == UART_REV_GETCODE)
        {
            uart_data->VarAddr = ((uint16_t)c) << 8;
            uart_data->VarData[uart_data->VarIndex++] = c;
            uart->RxFlag = UART_REV_GETADDR1;
        }
        else if (uart->RxFlag == UART_REV_GETADDR1)
        {
            uart_data->VarAddr |= c;
            uart_data->VarData[uart_data->VarIndex++] = c;
            uart->RxFlag = UART_REV_GETADDR2;
        }
        else if (uart->RxFlag == UART_REV_GETADDR2)
        {
            uart_data->VarData[uart_data->VarIndex++] = c;
            if (uart_data->VarIndex == uart_data->DataLen + 3)
            {
                uart->RxFlag = UART_REV_DONE;
                break;
            }
        }
    }
    if (uart->RxFlag == UART_REV_DONE)
    {
        uart->RxFlag = UART_REV_PRE;
        DealUartData(uart_data->VarData, uart->Id, uart->Response, uart->CrcCheck);
    }
}

/**
 * @brief Processes UART frame data for all enabled interfaces.
 */
void UartProcess(void)
{
#if UART2_ENABLE
    if (Uart2.Delay == 0) UartHandleFrame(&Uart2);
#endif
#if UART3_ENABLE
    if (Uart3.Delay == 0) UartHandleFrame(&Uart3);
#endif
#if UART4_ENABLE
    if (Uart4.Delay == 0) UartHandleFrame(&Uart4);
#endif
#if UART5_ENABLE
    if (Uart5.Delay == 0) UartHandleFrame(&Uart5);
#endif
}

#if UART2_ENABLE
/**
 * @brief Interrupt service routine for UART2 transmit and receive.
 */
void Uart2TxRxIsr(void) interrupt 4
{
    EA = 0;
    if (RI0 == 1)
    {
        RI0 = 0;
        Uart2.RxBuffer[Uart2.RxWrite] = SBUF0;
        Uart2.RxWrite++;
        Uart2.RxWrite %= UART_RX_LENGTH;
    }
    else if (TI0 == 1)
    {
        TI0 = 0;
        if (Uart2.TxRead != Uart2.TxWrite)
        {
            SBUF0 = Uart2.TxBuffer[Uart2.TxRead];
            Uart2.TxRead++;
            Uart2.TxRead %= UART_TX_LENGTH;
        }
        else
        {
            Uart2.TxBusy = 0;
        }
    }
    EA = 1;
}
#endif

#if UART3_ENABLE
/**
 * @brief Interrupt service routine for UART3 receive and transmit.
 */
void Uart3RxIsr(void) interrupt 16
{
    if (SCON1 & 0x01)
    {
        SCON1 &= 0xFE;
        Uart3.RxBuffer[Uart3.RxWrite] = SBUF1;
        Uart3.RxWrite++;
        Uart3.RxWrite %= UART_RX_LENGTH;
    }
    else if (SCON1 & 0x02)
    {
        SCON1 &= 0xFD;
        if (Uart3.TxRead != Uart3.TxWrite)
        {
            SBUF1 = Uart3.TxBuffer[Uart3.TxRead];
            Uart3.TxRead++;
            Uart3.TxRead %= UART_TX_LENGTH;
        }
        else
        {
            Uart3.TxBusy = 0;
        }
    }
}
#endif

#if UART4_ENABLE
/**
 * @brief Interrupt service routine for UART4 receive.
 */
void Uart4RxIsr(void) interrupt 11
{
    EA = 0;
    SCON2R &= 0xFE;
    Uart4.RxBuffer[Uart4.RxWrite] = SBUF2_RX;
    Uart4.RxWrite++;
    Uart4.RxWrite %= UART_RX_LENGTH;
    EA = 1;
}

/**
 * @brief Interrupt service routine for UART4 transmit.
 */
void Uart4TxIsr(void) interrupt 10
{
    EA = 0;
    SCON2T &= 0xFE;
    if (Uart4.TxRead != Uart4.TxWrite)
    {
        SBUF2_TX = Uart4.TxBuffer[Uart4.TxRead];
        Uart4.TxRead++;
        Uart4.TxRead %= UART_TX_LENGTH;
    }
    else
    {
        TR4 = 0;
        Uart4.TxBusy = 0;
    }
    EA = 1;
}
#endif

#if UART5_ENABLE
/**
 * @brief Interrupt service routine for UART5 receive.
 */
void Uart5RxIsr(void) interrupt 13
{
    EA = 0;
    SCON3R &= 0xFE;
    Uart5.RxBuffer[Uart5.RxWrite] = SBUF3_RX;
    Uart5.RxWrite++;
    Uart5.RxWrite %= UART_RX_LENGTH;
    EA = 1;
}

/**
 * @brief Interrupt service routine for UART5 transmit.
 */
void Uart5TxIsr(void) interrupt 12
{
    EA = 0;
    SCON3T &= 0xFE;
    if (Uart5.TxRead != Uart5.TxWrite)
    {
        SBUF3_TX = Uart5.TxBuffer[Uart5.TxRead];
        Uart5.TxRead++;
        Uart5.TxRead %= UART_TX_LENGTH;
    }
    else
    {
        Uart5.TxBusy = 0;
    }
    EA = 1;
}
#endif
