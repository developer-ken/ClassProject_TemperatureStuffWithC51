/*
 * Encoding : GBK
 * 单片机课程设计 基于DS18B20温度传感器的温度传感与控制系统
 * 邓君卓 208200611
 * 
 * onewire.c
 * OneWire协议栈实现
 */

#include <reg51.h>
#include "config.h"
#include "onewire.h"

void Delay(unsigned int i)
{
    i *= 8;
    while (i--);
}

char OneWire_Reset(void)
{
    char x;
    ONEWIRE = 1;
    Delay(8);
    ONEWIRE = 0;
    Delay(80);
    ONEWIRE = 1;
    Delay(8);
    x = ONEWIRE;
    Delay(20);
    if (x == 0)
        return 1;
    else
        return 0;
}
void OneWire_WriteByte(unsigned char c)
{
    unsigned char ic;
    for (ic = 0; ic < 8; ic++)
    {
        ONEWIRE = 0;
        Delay(0);
        ONEWIRE = c & 0x01;
        Delay(5);
        ONEWIRE = 1;
        c >>= 1;
    }
}

unsigned char OneWire_ReadByte(void)
{
    unsigned char c, ic;
    c = 0;
    for (ic = 0; ic < 8; ic++)
    {
        ONEWIRE = 0;
        c >>= 1;
        ONEWIRE = 1;
        if (ONEWIRE)
            c |= 0x80;
        Delay(5);
    }
    return c;
}