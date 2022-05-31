#ifndef _KEYPAD_H_
#define _KEYPAD_H_
typedef void (*callback_t) (char,char);
void keyloop(callback_t);
#endif