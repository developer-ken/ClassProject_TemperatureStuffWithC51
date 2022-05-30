#ifndef _MECH_H__
#define _MECH_H__
sbit BeepPin = P2 ^ 4;
sbit FanPin = P2 ^ 5;
void Beep()
{
    int i, j, cnt = 100;
    for (i = 0; i < 11602 / 2; i++)
    {
        cnt = cnt == 0 ? 100 : cnt - 1;

        for (j = 0; j < cnt; j++)
            ;

        BeepPin = i % 2;
    }
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