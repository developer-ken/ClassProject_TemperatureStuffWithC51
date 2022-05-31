/*
 * Encoding : GBK
 * 单片机课程设计 基于DS18B20温度传感器的温度传感与控制系统
 * 邓君卓 208200611
 *
 * config.h
 * 配置文件
 * 依照不同的硬件连接修改此文件,或按照文件中的定义连接硬件
 */

#ifndef _CONF_H_H_
#define _CONF_H_H_

// MCU基础设置
#define OSC 11059200
#define BAUDRATE 9600

// DS18B20 数据线设置
#ifdef __SDCC
#define ONEWIRE P0_0
#else
sbit ONEWIRE = P0 ^ 0;
#endif

// LCM16X2P 引脚连接设置
#define LCM_DB P1
#ifdef __SDCC
#define LCM_RS P0_4
#define LCM_RW P0_5
#define LCM_E P0_6
#define LCM_BLE P0_7
#else
sbit LCM_RS = P0 ^ 4;
sbit LCM_RW = P0 ^ 5;
sbit LCM_E = P0 ^ 6;
sbit LCM_BLE = P0 ^ 7;
#endif

// 键盘引脚设置
#define KEYPAD_PINS P2

// 风扇 蜂鸣器 引脚设定
#ifdef __SDCC
#define BeepPin P3_4
#define FanPin P3_5
#else
sbit BeepPin = P3 ^ 4;
sbit FanPin = P3 ^ 5;
#endif
#endif

#include <stdio.h>

#ifdef __SDCC
#define printf(X,...) ;
#endif