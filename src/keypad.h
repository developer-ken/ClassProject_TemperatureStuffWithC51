/*
 * Encoding : GBK
 * 单片机课程设计 基于DS18B20温度传感器的温度传感与控制系统
 * 邓君卓 208200611
 *
 * keypad.h
 * 4x4键盘阵列
 */

#ifndef _KEYPAD_H_
#define _KEYPAD_H_
typedef void (*callback_t) (char,char);
void keyloop(callback_t);
#endif