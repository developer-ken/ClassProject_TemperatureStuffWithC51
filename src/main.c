#include <REG51.H>
#include "config.h"
#include "ds18b20.h"
#include <stdio.h>

sbit DS_PIN = P0 ^ 0;

void main()
{
    Temperature t;
    DS_PIN = 0;
    while (1)
    {
        DS_ReadTemperature(&t);
        Delay(50);
    }
}