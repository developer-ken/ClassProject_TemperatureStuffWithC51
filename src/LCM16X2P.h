#ifndef LCM16X2_H_
#define LCM16X2_H_
#define BUSYFLAG 0X80
#define BLINK 0x01
#define NOBLINK 0x00
unsigned char LCMReadState(void);
void LCMDelay(int);
void LCMWriteCmd(unsigned char);
void LCMWriteData(unsigned char);
void LCMInit(void);
void LCMClear(void);
void LCMGoXY(unsigned char,unsigned char);
void LCMDisplayChar(unsigned char,unsigned char,unsigned char);
void LCMDisplayString(unsigned char,unsigned char,unsigned char *);
void LCMBlink(unsigned char,unsigned char,unsigned char);
#endif