#ifndef _DS18B20H_
#define _DS18B20H_
#define StartConvert 0x44

typedef struct{
    unsigned int z;
    unsigned int x;
} Temperature;

bit DS_CurrentTemperature(Temperature*);

#endif