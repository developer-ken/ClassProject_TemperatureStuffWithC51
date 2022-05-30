#ifndef _ds_h_
#define _ds_h_

#define ReadROM 0x33
#define MatchROM 0x55
#define SkipROM 0xCC
#define AlarmSearch 0xEC
#define ConvertT 0x44
#define ReadMem 0xBE

typedef struct{
    int z,x;
} Temperature;

void Delay(unsigned int);

bit DS_Reset();
void DS_WriteByte(unsigned char);
void DS_ReadByte(unsigned char);
void DS_Command(unsigned char);

void DS_ReadTemperature(Temperature*);

#endif