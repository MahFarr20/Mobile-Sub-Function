#ifndef _KEYPAD_
#define _KEYPAD_
#include "tm4c123gh6pm.h"
#include <stdint.h>
void keypad_init(void);
unsigned char keypad_getkey(void);

#endif