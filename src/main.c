#include <reg51.h>
#include <stdio.h>
#include "ds18b20.h"
#include "config.h"
#include "Mech.h"

#include "LCM16X2P.h"

sbit LCM_BLE = P0 ^ 7;

main()
{
    unsigned int i;
    unsigned char tmph, tmp1;
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
    if (DS_Reset())
        printf("\r\n18B20 Reset OK!");
    else
        printf("\r\n18B20 Not present!");
    LCMInit();
    LCMClear();
    LCMDisplayString(0, 0, "-  208200611  -");
    while (1)
    {
        DS_ReadTemperature(&t);
        printf("%d.%04d\n", t.z, t.x);
        if (t.z >= 27)
        {
            sprintf(strtmp, "T=%d.%04d X_X", t.z, t.x);
            FanOn();
        }
        else if (t.z >= 26)
        {
            FanOn();
            sprintf(strtmp, "T=%d.%04d >_<", t.z, t.x);
        }
        else
        {
            FanOff();
            sprintf(strtmp, "T=%d.%04d OvO", t.z, t.x);
        }
        LCMDisplayString(1, 0, strtmp);
        if (t.z >= 27)
        {
            Beep();
            LCM_BLE = !LCM_BLE;
        }
        else
        {
            LCM_BLE = 0;
        }
    }
}