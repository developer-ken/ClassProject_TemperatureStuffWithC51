/*
 * Encoding : GBK
 * 单片机课程设计 基于DS18B20温度传感器的温度传感与控制系统
 * 邓君卓 208200611
 *
 * main.c
 * 主程序文件
 */

#include <reg51.h>
#include "ds18b20.h"
#include "config.h"
#include "Mech.h"
#include "onewire.h"
#include "keypad.h"
#include "LCM16X2P.h"

char keyarray[4][4] = {
    {7, 8, 9, 0},
    {4, 5, 6, 0},
    {1, 2, 3, 0},
    {0, 0, 0, 0}};
char inputbuffer[3];
char inputpointer = 0;
char mode = 0;

void KeyUp(char x, char y)
{
    if (x == 1 && y == 4)
        mode = 'A';
    else if (x == 4 && y == 4)
        mode = 'B';
    else if (inputpointer < 2)
    {
        char key = keyarray[y - 1][x - 1];
        inputbuffer[inputpointer] = key;
        inputpointer++;
    }
}

main()
{
    char fan_temp = 26;
    char warn_temp = 27;
    char strtmp[16];
    Temperature t;
    TMOD = 0X21;
    SCON = 0X50;
    PCON |= 0X80;
    TL1 = 256 - (OSC / 12 / 16 / BAUDRATE);
    TH1 = 256 - (OSC / 12 / 16 / BAUDRATE);
    TR1 = 1;
    TI = 1;
    Beep();
    LCMInit();
    LCMClear();
    while (!OneWire_Reset())
    {
        LCMDisplayString(0, 0, "ERROR");
        LCMDisplayString(1, 0, "Missing Sensor");
        printf("Sensor communication error\n");
        printf("Retrying...\n");
    }
    LCMClear();
    LCMDisplayString(0, 0, "-  208200611  -");
    while (1)
    {
        char success = DS_CurrentTemperature(&t);
        if (inputpointer >= 2)
        {
            inputpointer = 0;
            switch (mode)
            {
            case 'A':
            {
                fan_temp = inputbuffer[0] * 10 + inputbuffer[1];
                LCMDisplayString(0, 0, "-  208200611  -");
            }
            break;
            case 'B':
            {
                warn_temp = inputbuffer[0] * 10 + inputbuffer[1];
                LCMDisplayString(0, 0, "-  208200611  -");
            }
            break;
            default:
            {
                LCMDisplayString(0, 0, "Invalid Command");
            }
            break;
            }
            mode = 0;
        }
        else if (inputpointer > 0 || (mode == 'A' || mode == 'B'))
        {
            LCMDisplayString(0, 0, "                ");
            LCMDisplayChar(0, 0, mode);
            LCMDisplayChar(0, 1, inputbuffer[0] + '0');
            LCMDisplayChar(0, 2, inputbuffer[1] + '0');
        }
        else
        {
            LCMDisplayString(0, 0, "-  208200611  -");
        }
        if (!success)
        {
            LCMDisplayString(1, 0, "Sensor Failure");
            FanOn();
            Beep();
            LCM_BLE = !LCM_BLE;
            continue;
        }
        if (t.z >= warn_temp)
        {
            sprintf(strtmp, "T=%d.%04d  X_X  ", t.z, t.x);
            FanOn();
        }
        else if (t.z >= fan_temp)
        {
            FanOn();
            sprintf(strtmp, "T=%d.%04d  >_<  ", t.z, t.x);
        }
        else
        {
            FanOff();
            sprintf(strtmp, "T=%d.%04d  OvO  ", t.z, t.x);
        }
        LCMDisplayString(1, 0, strtmp);
        if (t.z >= warn_temp)
        {
            Beep();
            LCM_BLE = !LCM_BLE;
        }
        else
        {
            LCM_BLE = 0;
        }
        keyloop(KeyUp);
    }
}