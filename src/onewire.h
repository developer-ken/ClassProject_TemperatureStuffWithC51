/*
 * Encoding : GBK
 * 单片机课程设计 基于DS18B20温度传感器的温度传感与控制系统
 * 邓君卓 208200611
 * 
 * onewire.h
 * OneWire协议栈实现
 */

#ifndef _H_ONEWIREDJZ_H_
#define _H_ONEWIREDJZ_H_
#define ReadROM 0x33
#define MatchROM 0x55
#define SkipROM 0xcc
#define SearchROM 0xf0
#define StartConvert 0x44
#define ReadMemory 0xbe
void Delay(unsigned int);
bit OneWire_Reset(void);
void OneWire_WriteByte(unsigned char);
unsigned char OneWire_ReadByte(void);
#endif