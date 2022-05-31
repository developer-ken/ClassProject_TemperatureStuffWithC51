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
sbit ONEWIRE = P0 ^ 0;

// LCM16X2P ������������
#define LCM_DB P1
sbit LCM_RS = P0 ^ 4;
sbit LCM_RW = P0 ^ 5;
sbit LCM_E = P0 ^ 6;
sbit LCM_BLE = P0 ^ 7;

#endif  