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
sbit ONEWIRE = P0 ^ 0;

// LCM16X2P 引脚连接设置
#define LCM_DB P1
sbit LCM_RS = P0 ^ 4;
sbit LCM_RW = P0 ^ 5;
sbit LCM_E = P0 ^ 6;
sbit LCM_BLE = P0 ^ 7;

#endif  