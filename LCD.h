#ifndef _LCD_
#define _LCD_
#include "tm4c123gh6pm.h"
#include <stdint.h>
void LCD_command(unsigned char cmnd);
void LCD_init(void);

#endif