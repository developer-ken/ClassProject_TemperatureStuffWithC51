#include <REG51.H>
#include "keypad.h"
#include "config.h"

void keyloop(callback_t CallBack)
{
    unsigned char Mask, ScanCode, Line, Col, i;

    KEYPAD_PINS = 0xFF;
    Line = 1;
    Mask = 0x01;
    for (i = 0; i < 4; i++)
    {
        Col = 0;
        KEYPAD_PINS = ~Mask;
        ScanCode = KEYPAD_PINS & 0xf0;
        if (ScanCode != 0xf0)
        {
            
        }
        ScanCode = KEYPAD_PINS & 0xf0;
        switch (ScanCode)
        {
        case 0xe0:
            Col = 1;
            break;
        case 0xd0:
            Col = 2;
            break;
        case 0xb0:
            Col = 3;
            break;
        case 0x70:
            Col = 4;
            break;
        default:
            Col = 0;
            break;
        }
        if (Col > 0)
        {
            CallBack(Line, Col);
            while (1)
            {
                ScanCode = KEYPAD_PINS & 0xf0;
                if (ScanCode == 0xf0)
                    break;
            }
        }
        Mask <<= 1;
        Line++;
    }
}