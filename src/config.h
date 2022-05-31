/*
 * Encoding : GBK
 * ��Ƭ���γ���� ����DS18B20�¶ȴ��������¶ȴ��������ϵͳ
 * �˾�׿ 208200611
 *
 * config.h
 * �����ļ�
 * ���ղ�ͬ��Ӳ�������޸Ĵ��ļ�,�����ļ��еĶ�������Ӳ��
 */

#ifndef _CONF_H_H_
#define _CONF_H_H_

// MCU��������
#define OSC 11059200
#define BAUDRATE 9600

// DS18B20 ����������
#ifdef __SDCC
#define ONEWIRE P0_0
#else
sbit ONEWIRE = P0 ^ 0;
#endif

// LCM16X2P ������������
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

// ������������
#define KEYPAD_PINS P2

// ���� ������ �����趨
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