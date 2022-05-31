/*
 * Encoding : GBK
 * 单片机课程设计 基于DS18B20温度传感器的温度传感与控制系统
 * 邓君卓 208200611
 * 
 * LCM16X2P.c
 * LCM16X2P系列LCD驱动
 * 控制LCD显示指定内容
 */

#ifndef LCM16X2_H_
#define LCM16X2_H_
#define BUSYFLAG 0X80
#define BLINK 0x01
#define NOBLINK 0x00
unsigned char LCMReadState(void);
void LCMDelay(int);
void LCMWriteCmd(unsigned char);
void LCMWriteData(unsigned char);
void LCMInit(void);
void LCMClear(void);
void LCMGoXY(unsigned char,unsigned char);
void LCMDisplayChar(unsigned char,unsigned char,unsigned char);
void LCMDisplayString(unsigned char,unsigned char,unsigned char *);
void LCMBlink(unsigned char,unsigned char,unsigned char);
#endif