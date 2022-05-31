#ifndef _H_ONEWIREDJZ_H_
#define _H_ONEWIREDJZ_H_
#define ReadROM 0x33
#define MatchROM 0x55
#define SkipROM 0xcc
#define SearchROM 0xf0
#define StartConvert 0x44
#define ReadMemory 0xbe
void Delay(unsigned int);
bit OneWire_Reset(void);
void OneWire_WriteByte(unsigned char);
unsigned char OneWire_ReadByte(void);
#endif