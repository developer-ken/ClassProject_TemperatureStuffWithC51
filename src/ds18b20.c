/*
 * Encoding : GBK
 * ��Ƭ���γ���� ����DS18B20�¶ȴ��������¶ȴ��������ϵͳ
 * �˾�׿ 208200611
 *
 * ds18b20.c
 * DS18B20�¶ȴ���������
 * ͨ��OneWire�봫����ͨѶ,���봫�ص��¶�����
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