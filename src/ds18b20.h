/*
 * Encoding : GBK
 * ��Ƭ���γ���� ����DS18B20�¶ȴ��������¶ȴ��������ϵͳ
 * �˾�׿ 208200611
 * 
 * ds18b20.c
 * DS18B20�¶ȴ���������
 * ͨ��OneWire�봫����ͨѶ,���봫�ص��¶�����
 */

#ifndef _DS18B20H_
#define _DS18B20H_
#define StartConvert 0x44

typedef struct{
    unsigned int z;
    unsigned int x;
} Temperature;

char DS_CurrentTemperature(Temperature*);

#endif