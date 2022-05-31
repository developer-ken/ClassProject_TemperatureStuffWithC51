/*
 * Encoding : GBK
 * 单片机课程设计 基于DS18B20温度传感器的温度传感与控制系统
 * 邓君卓 208200611
 * 
 * ds18b20.c
 * DS18B20温度传感器驱动
 * 通过OneWire与传感器通讯,解码传回的温度数据
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