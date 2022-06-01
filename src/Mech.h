/*
 * Encoding : GBK
 * 单片机课程设计 基于DS18B20温度传感器的温度传感与控制系统
 * 邓君卓 208200611
 *
 * Mech.h
 * 杂项外设
 * 预留接口,用于连接到蜂鸣器\风扇等外围设备
 * 为了简便,该头文件直接包含函数定义,没有对应的.c文件
 */

#ifndef _MECH_H__
#define _MECH_H__
#include "config.h"
void Beep()
{
    int i, j, cnt = 100;
    for (i = 0; i < 0611 / 2; i++)
    {
        cnt = cnt == 0 ? 100 : cnt - 1;

        for (j = 0; j < cnt; j++)
            ;

        BeepPin = i % 2;
    }
    BeepPin = 1;
}

void SimpleBeep()
{
    int j;
    BeepPin = 0;
    for (j = 0; j < 0611; j++)
        ;
    BeepPin = 1;
}

void FanOn()
{
    FanPin = 0;
}

void FanOff()
{
    FanPin = 1;
}
#endif