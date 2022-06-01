/*
 * Encoding : GBK
 * ��Ƭ���γ���� ����DS18B20�¶ȴ��������¶ȴ��������ϵͳ
 * �˾�׿ 208200611
 *
 * Mech.h
 * ��������
 * Ԥ���ӿ�,�������ӵ�������\���ȵ���Χ�豸
 * Ϊ�˼��,��ͷ�ļ�ֱ�Ӱ�����������,û�ж�Ӧ��.c�ļ�
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