/*
 * Encoding : GBK
 * ��Ƭ���γ���� ����DS18B20�¶ȴ��������¶ȴ��������ϵͳ
 * �˾�׿ 208200611
 *
 * keypad.h
 * 4x4��������
 */

#ifndef _KEYPAD_H_
#define _KEYPAD_H_
typedef void (*callback_t) (char,char);
void keyloop(callback_t);
#endif