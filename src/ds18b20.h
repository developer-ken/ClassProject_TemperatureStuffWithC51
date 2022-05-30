#ifndef _DS18B20H_
#define _DS18B20H_
#include <intrins.h>
#define ReadROM 0x33
#define MatchROM 0x55
#define SkipROM 0xcc
#define SearchROM 0xf0
#define StartConvert 0x44
#define ReadMemory 0xbe

typedef struct{
    unsigned int z;
    unsigned int x;
} Temperature;

void Delay(unsigned int);

bit DS_Reset();
void DS_WriteByte(unsigned char);
unsigned char DS_ReadByte(void);

void DS_ReadTemperature(Temperature*);

#endif