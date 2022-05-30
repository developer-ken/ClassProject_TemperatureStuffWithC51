#include <reg51.h>
#include <stdio.h>
#include <intrins.h>

#include "ds18b20.h"
#include "config.h"

sbit DS_PIN = P0^0;

void Delay(unsigned int i)
{
    while (i--);
}

void DS_WriteByte(unsigned char b)
{
    unsigned char i;
    for (i = 0; i < 8; i++)
    {
        DS_PIN = b & 0x01;
        b >>= 1;
        Delay(5);
        DS_PIN = 1;
    }
}

void DS_ReadByte(unsigned char *b)
{
    unsigned char i;
    *b = 0;
    for (i = 0; i < 8; i++)
    {
        *b >>= 1;
        DS_PIN = 0;
        Delay(5);
        DS_PIN = 1;
        Delay(5);
        if (DS_PIN)
            *b |= 0x80;
    }
}

void DS_Command(unsigned char c)
{
    DS_WriteByte(c);
}

void DS_ReadTemperature(Temperature *t)
{
    unsigned char temp_l, temp_h;
    DS_Reset();
    Delay(12);
    DS_Command(SkipROM);
    DS_Command(ConvertT);
    DS_Reset();
    Delay(12);
    DS_Command(SkipROM);
    DS_Command(ReadMem);
    DS_ReadByte(&temp_l);
    DS_ReadByte(&temp_h);
    t->z = (int)((temp_h & 0x07) << 4 | (temp_l & 0xf0) >> 4);
    t->x = (int)((temp_l & 0x0f) * 625);
}


bit DS_Reset()
{
    bit rst;
    DS_PIN = 1;
    Delay(8);
    DS_PIN = 0;
    Delay(80);
    DS_PIN = 1;
    Delay(8);
    rst = DS_PIN;
    Delay(20);
    return !rst;
}