#include <reg51.h>
#include <stdio.h>
#include <intrins.h>
#include "onewire.h"

#include "ds18b20.h"

bit DS_CurrentTemperature(Temperature *t)
{
    unsigned char tmp1, tmph;
    bit success = 1;
    success &= OneWire_Reset();
    Delay(12);
    OneWire_WriteByte(SkipROM);
    OneWire_WriteByte(StartConvert);
    success &= OneWire_Reset();
    Delay(12);
    OneWire_WriteByte(SkipROM);
    OneWire_WriteByte(ReadMemory);
    tmp1 = OneWire_ReadByte();
    tmph = OneWire_ReadByte();
    t->z = (int)((tmph & 0x07) << 4 | (tmp1 & 0Xf0) >> 4);
    t->x = (int)((tmp1 & 0x0f) * 625);
    return success;
}