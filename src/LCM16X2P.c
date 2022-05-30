#include <REG51.H>
#include <INTRINS.H>
#include "LCM16X2P.h"

#define LCM_DB P1
sbit LCM_RS = P0 ^ 4;
sbit LCM_RW = P0 ^ 5;
sbit LCM_E = P0 ^ 6;
sbit LCM_BLE = P0 ^ 7;

unsigned int data DelayConst = 140;

void LCMDelay(int ms)
{
    unsigned int i, cnt;
    cnt = ms * DelayConst;
    for (i = 0; i < cnt; i++)
        ;
}

unsigned char LCMReadState(void)
{
    unsigned char state;
    LCM_E = 0;
    LCM_RS = 0;
    LCM_RW = 1;
    LCM_E = 1;
    LCMDelay(1);
    state = LCM_DB;
    LCM_E = 0;
    return state;
}

void LCMClear(void)
{
    LCMDelay(1);
    LCM_E = 0;
    LCM_RS = 0;
    LCM_RW = 0;
    LCM_DB = 0X01;
    LCM_E = 1;
    LCMDelay(1);
    LCM_E = 0;
    LCMDelay(1);
}

void LCMWriteCmd(unsigned char cmd)
{
    LCMDelay(1);
    LCM_E = 0;
    LCM_RS = 0;
    LCM_RW = 0;
    LCM_DB = cmd;
    LCM_E = 1;
    LCMDelay(1);
    LCM_E = 0;
}

void LCMWriteData(unsigned char dc)
{
    while (LCMReadState() & BUSYFLAG)
        ;
    LCM_RS = 1;
    LCM_RW = 0;
    LCM_DB = dc;
    LCM_E = 1;
    LCMDelay(1);
    LCM_E = 0;
}

void LCMInit(void)
{
    LCMDelay(60);
    LCMWriteCmd(0x38);
    LCMDelay(5);
    LCMWriteCmd(0x38);
    LCMDelay(1);
    LCMWriteCmd(0x38);
    while (LCMReadState() & BUSYFLAG)
        ;
    LCMWriteCmd(0x08);
    while (LCMReadState() & BUSYFLAG)
        ;
    LCMWriteCmd(0x01);
    while (LCMReadState() & BUSYFLAG)
        ;
    LCMWriteCmd(0x06);
    while (LCMReadState() & BUSYFLAG)
        ;
    LCMWriteCmd(0x0e);
    while (LCMReadState() & BUSYFLAG)
        ;
    LCM_BLE = 0;
}

void LCMGotoXY(unsigned char x, unsigned char y)
{
    unsigned char addr;
    if (x == 0)
    {
        addr = 0x80 | y;
    }
    else
    {
        addr = 0x80 | 0x40 | y;
    }
    LCMWriteCmd(addr);
    while (LCMReadState() & BUSYFLAG)
        ;
}

void LCMDisplayChar(unsigned char x, unsigned char y, unsigned char dc)
{
    LCMGotoXY(x, y);
    LCMWriteData(dc);
}

void LCMDisplayString(unsigned char x, unsigned char y, unsigned char *str)
{
    unsigned char ptr;
    ptr = 0;
    while (*(str + ptr))
    {
        LCMDisplayChar(x, y + ptr, *(str + ptr));
        ptr++;
    }
}

void LCMBlink(unsigned char x, unsigned char y, unsigned char cmd)
{
    LCMGotoXY(x, y);
    if (cmd == BLINK)
    {
        LCMWriteCmd(0x0d);
    }
    else
    {
        LCMWriteCmd(0x0c);
    }
}