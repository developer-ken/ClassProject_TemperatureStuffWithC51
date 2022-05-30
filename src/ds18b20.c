#include <reg51.h>
#include <stdio.h>
#include <intrins.h>

#include "ds18b20.h"
#include "config.h"
sbit DQ = P0 ^ 0;

void Delay(unsigned int i)
{
    i *= 8;
    while (i--);
}

bit DS_Reset(void)
{
    bit x;
    DQ = 1;
    Delay(8);
    DQ = 0;
    Delay(80);
    DQ = 1;
    Delay(8);
    x = DQ;
    Delay(20);
    if (x == 0)
        return 1;
    else
        return 0;
}
void DS_WriteByte(unsigned char c)
{
    unsigned char ic;
    for (ic = 0; ic < 8; ic++)
    {
        DQ = 0;
        Delay(0);
        DQ = c & 0x01;
        Delay(5);
        DQ = 1;
        c >>= 1;
    }
}

unsigned char DS_ReadByte(void)
{
    unsigned char c, ic;
    c = 0;
    for (ic = 0; ic < 8; ic++)
    {
        DQ = 0;
        c >>= 1;
        DQ = 1;
        if (DQ)
            c |= 0x80;
        Delay(5);
    }
    return c;
}

void DS_ReadTemperature(Temperature *t)
{
    unsigned char tmp1, tmph;
    DS_Reset();
    Delay(12);
    DS_WriteByte(SkipROM);
    DS_WriteByte(StartConvert);
    DS_Reset();
    Delay(12);
    DS_WriteByte(SkipROM);
    DS_WriteByte(ReadMemory);
    tmp1 = DS_ReadByte();
    tmph = DS_ReadByte();
    t->z = (int)((tmph & 0x07) << 4 | (tmp1 & 0Xf0) >> 4);
    t->x = (int)((tmp1 & 0x0f) * 625);
}