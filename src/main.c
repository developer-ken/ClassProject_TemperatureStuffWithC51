#include <REG51.H>
#include "config.h"
#include "ds18b20.h"
#include <stdio.h>

sbit DS_PIN = P0 ^ 0;
sbit DEBUG_TRIGGER = P0 ^ 1;

void main()
{
    Temperature t;
    DS_PIN = 0;
    while (1)
    {
        DEBUG_TRIGGER = 0;
        Delay(10);
        DEBUG_TRIGGER = 1;
        Delay(10);
        DEBUG_TRIGGER = 0;
        DS_ReadTemperature(&t);
        Delay(50);
    }
}