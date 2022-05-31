/*
 * Encoding : GBK
 * 单片机课程设计 基于DS18B20温度传感器的温度传感与控制系统
 * 邓君卓 208200611
 *
 * ds18b20.c
 * DS18B20温度传感器驱动
 * 通过OneWire与传感器通讯,解码传回的温度数据
 */

#include <reg51.h>
#include "onewire.h"

#include "ds18b20.h"

char DS_CurrentTemperature(Temperature *t)
{
    unsigned char tmp1, tmph;
    char success = 1;
    success = OneWire_Reset();
    Delay(12);
    OneWire_WriteByte(SkipROM);
    OneWire_WriteByte(StartConvert);
    success = success && OneWire_Reset();
    Delay(12);
    OneWire_WriteByte(SkipROM);
    OneWire_WriteByte(ReadMemory);
    tmp1 = OneWire_ReadByte();
    tmph = OneWire_ReadByte();
    t->z = (int)((tmph & 0x07) << 4 | (tmp1 & 0Xf0) >> 4);
    t->x = (int)((tmp1 & 0x0f) * 625);
    return success;
}