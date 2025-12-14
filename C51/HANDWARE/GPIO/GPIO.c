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
#include "GPIO.h"

//==============================================================================
//---------------------------------Defines--------------------------------------
//==============================================================================

//==============================================================================
//----------------------------------INIT---------------------------------------
//==============================================================================
/**
 * @brief Initializes a GPIO pin with specified type and state.
 * @param Type The type of the pin (input or output).
 * @param Port The port number (0 to 3).
 * @param Pin The pin number (0 to 7 for ports 0-2, 0 to 3 for port 3).
 * @param StatePin The initial state of the pin (for output pins).
 * @return EGpioStatus GPIO_OK on success, GPIO_ERR on invalid port or pin.
 */
EGpioStatus InitGpio(EPinType Type, uint8_t Port, uint8_t Pin, EPinState StatePin)
{
    if (Type == GPIO_OUT)
    {
        if (Port == GPIO_PORT_0) { if (Pin > GPIO_PIN_7) { return GPIO_ERR; } P0MDOUT |= (1 << Pin); }
        else if (Port == GPIO_PORT_1) { if (Pin > GPIO_PIN_7) { return GPIO_ERR; } P1MDOUT |= (1 << Pin); }
        else if (Port == GPIO_PORT_2) { if (Pin > GPIO_PIN_7) { return GPIO_ERR; } P2MDOUT |= (1 << Pin); }
        else if (Port == GPIO_PORT_3) { if (Pin > GPIO_PIN_3) { return GPIO_ERR; } P3MDOUT |= (1 << Pin); }
        else { return GPIO_ERR; }
        SetGpioOutState(Port, Pin, StatePin);
    }
    else if (Type == GPIO_IN)
    {
        if (Port == GPIO_PORT_0) { if (Pin > GPIO_PIN_7) { return GPIO_ERR; } P0MDOUT &= ~(1 << Pin); }
        else if (Port == GPIO_PORT_1) { if (Pin > GPIO_PIN_7) { return GPIO_ERR; } P1MDOUT &= ~(1 << Pin); }
        else if (Port == GPIO_PORT_2) { if (Pin > GPIO_PIN_7) { return GPIO_ERR; } P2MDOUT &= ~(1 << Pin); }
        else if (Port == GPIO_PORT_3) { if (Pin > GPIO_PIN_3) { return GPIO_ERR; } P3MDOUT &= ~(1 << Pin); }
        else { return GPIO_ERR; }
    }
    else
    {
        return GPIO_ERR;
    }
    return GPIO_OK;
}

//==============================================================================
//--------------------------------FUNCTIONS-------------------------------------
//==============================================================================
/**
 * @brief Reads the state of a GPIO pin.
 * @param Port The port number (0 to 3).
 * @param Pin The pin number (0 to 7 for ports 0-2, 0 to 3 for port 3).
 * @param StatePin Pointer to store the pin state (GPIO_LOW or GPIO_HIGHT).
 * @return EGpioStatus GPIO_OK on success, GPIO_ERR on invalid port or pin.
 */
EGpioStatus GetGpioState(uint8_t Port, uint8_t Pin, EPinState* StatePin)
{
    uint16_t state = 0;
    uint8_t returnStatus = GPIO_OK;

    if (Port == GPIO_PORT_0)
    {
        if (Pin == GPIO_PIN_0) { if ((P0 & 0x01) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_1) { if ((P0 & 0x02) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_2) { if ((P0 & 0x04) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_3) { if ((P0 & 0x08) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_4) { if ((P0 & 0x10) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_5) { if ((P0 & 0x20) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_6) { if ((P0 & 0x40) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_7) { if ((P0 & 0x80) != 0) state = 1; else state = 0; }
        else return GPIO_ERR;
    }
    else if (Port == GPIO_PORT_1)
    {
        if (Pin == GPIO_PIN_0) { if ((P1 & 0x01) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_1) { if ((P1 & 0x02) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_2) { if ((P1 & 0x04) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_3) { if ((P1 & 0x08) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_4) { if ((P1 & 0x10) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_5) { if ((P1 & 0x20) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_6) { if ((P1 & 0x40) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_7) { if ((P1 & 0x80) != 0) state = 1; else state = 0; }
        else return GPIO_ERR;
    }
    else if (Port == GPIO_PORT_2)
    {
        if (Pin == GPIO_PIN_0) { if ((P2 & 0x01) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_1) { if ((P2 & 0x02) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_2) { if ((P2 & 0x04) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_3) { if ((P2 & 0x08) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_4) { if ((P2 & 0x10) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_5) { if ((P2 & 0x20) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_6) { if ((P2 & 0x40) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_7) { if ((P2 & 0x80) != 0) state = 1; else state = 0; }
        else return GPIO_ERR;
    }
    else if (Port == GPIO_PORT_3)
    {
        if (Pin == GPIO_PIN_0) { if ((P3 & 0x01) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_1) { if ((P3 & 0x02) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_2) { if ((P3 & 0x04) != 0) state = 1; else state = 0; }
        else if (Pin == GPIO_PIN_3) { if ((P3 & 0x08) != 0) state = 1; else state = 0; }
        else return GPIO_ERR;
    }
    else
    {
        return GPIO_ERR;
    }

    if (state != 0) *StatePin = GPIO_LOW;
    else *StatePin = GPIO_HIGHT;
    return returnStatus;
}

/**
 * @brief Sets the state of an output GPIO pin.
 * @param Port The port number (0 to 3).
 * @param Pin The pin number (0 to 7 for ports 0-2, 0 to 3 for port 3).
 * @param State The state to set (GPIO_LOW or GPIO_HIGHT).
 * @return EGpioStatus GPIO_OK on success, GPIO_ERR on invalid port or pin.
 */
EGpioStatus SetGpioOutState(uint8_t Port, uint8_t Pin, EPinState State)
{
    if (Port == GPIO_PORT_0)
    {
        if (Pin == GPIO_PIN_0) { if (State == GPIO_HIGHT) { P0 |= 0x01; } else { P0 &= 0xFE; } }
        else if (Pin == GPIO_PIN_1) { if (State == GPIO_HIGHT) { P0 |= 0x02; } else { P0 &= 0xFD; } }
        else if (Pin == GPIO_PIN_2) { if (State == GPIO_HIGHT) { P0 |= 0x04; } else { P0 &= 0xFB; } }
        else if (Pin == GPIO_PIN_3) { if (State == GPIO_HIGHT) { P0 |= 0x08; } else { P0 &= 0xF7; } }
        else if (Pin == GPIO_PIN_4) { if (State == GPIO_HIGHT) { P0 |= 0x10; } else { P0 &= 0xEF; } }
        else if (Pin == GPIO_PIN_5) { if (State == GPIO_HIGHT) { P0 |= 0x20; } else { P0 &= 0xDF; } }
        else if (Pin == GPIO_PIN_6) { if (State == GPIO_HIGHT) { P0 |= 0x40; } else { P0 &= 0xBF; } }
        else if (Pin == GPIO_PIN_7) { if (State == GPIO_HIGHT) { P0 |= 0x80; } else { P0 &= 0x7F; } }
        else return GPIO_ERR;
    }
    else if (Port == GPIO_PORT_1)
    {
        if (Pin == GPIO_PIN_0) { if (State == GPIO_HIGHT) { P1 |= 0x01; } else { P1 &= 0xFE; } }
        else if (Pin == GPIO_PIN_1) { if (State == GPIO_HIGHT) { P1 |= 0x02; } else { P1 &= 0xFD; } }
        else if (Pin == GPIO_PIN_2) { if (State == GPIO_HIGHT) { P1 |= 0x04; } else { P1 &= 0xFB; } }
        else if (Pin == GPIO_PIN_3) { if (State == GPIO_HIGHT) { P1 |= 0x08; } else { P1 &= 0xF7; } }
        else if (Pin == GPIO_PIN_4) { if (State == GPIO_HIGHT) { P1 |= 0x10; } else { P1 &= 0xEF; } }
        else if (Pin == GPIO_PIN_5) { if (State == GPIO_HIGHT) { P1 |= 0x20; } else { P1 &= 0xDF; } }
        else if (Pin == GPIO_PIN_6) { if (State == GPIO_HIGHT) { P1 |= 0x40; } else { P1 &= 0xBF; } }
        else if (Pin == GPIO_PIN_7) { if (State == GPIO_HIGHT) { P1 |= 0x80; } else { P1 &= 0x7F; } }
        else return GPIO_ERR;
    }
    else if (Port == GPIO_PORT_2)
    {
        if (Pin == GPIO_PIN_0) { if (State == GPIO_HIGHT) { P2 |= 0x01; } else { P2 &= 0xFE; } }
        else if (Pin == GPIO_PIN_1) { if (State == GPIO_HIGHT) { P2 |= 0x02; } else { P2 &= 0xFD; } }
        else if (Pin == GPIO_PIN_2) { if (State == GPIO_HIGHT) { P2 |= 0x04; } else { P2 &= 0xFB; } }
        else if (Pin == GPIO_PIN_3) { if (State == GPIO_HIGHT) { P2 |= 0x08; } else { P2 &= 0xF7; } }
        else if (Pin == GPIO_PIN_4) { if (State == GPIO_HIGHT) { P2 |= 0x10; } else { P2 &= 0xEF; } }
        else if (Pin == GPIO_PIN_5) { if (State == GPIO_HIGHT) { P2 |= 0x20; } else { P2 &= 0xDF; } }
        else if (Pin == GPIO_PIN_6) { if (State == GPIO_HIGHT) { P2 |= 0x40; } else { P2 &= 0xBF; } }
        else if (Pin == GPIO_PIN_7) { if (State == GPIO_HIGHT) { P2 |= 0x80; } else { P2 &= 0x7F; } }
        else return GPIO_ERR;
    }
    else if (Port == GPIO_PORT_3)
    {
        if (Pin == GPIO_PIN_0) { if (State == GPIO_HIGHT) { P3 |= 0x01; } else { P3 &= 0xFE; } }
        else if (Pin == GPIO_PIN_1) { if (State == GPIO_HIGHT) { P3 |= 0x02; } else { P3 &= 0xFD; } }
        else if (Pin == GPIO_PIN_2) { if (State == GPIO_HIGHT) { P3 |= 0x04; } else { P3 &= 0xFB; } }
        else if (Pin == GPIO_PIN_3) { if (State == GPIO_HIGHT) { P3 |= 0x08; } else { P3 &= 0xF7; } }
        else return GPIO_ERR;
    }
    else
    {
        return GPIO_ERR;
    }
    return GPIO_OK;
}

//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================