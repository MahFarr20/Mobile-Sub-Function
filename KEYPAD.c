#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "KEYPAD.h"
void keypad_init(void)
{

  
SYSCTL_RCGCGPIO_R |= 0x04; 
SYSCTL_RCGCGPIO_R |= 0x10; 
GPIO_PORTE_DIR_R |= 0x0F; //row
GPIO_PORTE_DEN_R |= 0x0F;  //row
GPIO_PORTE_ODR_R |= 0x0F;  //row
GPIO_PORTC_DIR_R &= ~0xF0; //coloumn
GPIO_PORTC_DEN_R |= 0xF0;  //coloumn
GPIO_PORTC_PUR_R |= 0xF0; //cooumn

}

unsigned char keypad_getkey(void)
{
const unsigned char keymap[4][4] = {
{ '1', '2', '3', '+'},
{ '4', '5', '6', '-'},
{ '7', '8', '9', '*'},
{ 'c', '0', '=', '/'},
};
int row, col;
GPIO_PORTE_DATA_R= 0; 
col =GPIO_PORTC_DATA_R & 0xF0;
if (col == 0xF0) return 0;


while (1)
{
row = 0;
GPIO_PORTE_DATA_R = 0x0E; 
delayUs(2); 
col = GPIO_PORTC_DATA_R & 0xF0;
if (col != 0xF0) break;
row = 1;
GPIO_PORTE_DATA_R = 0x0D; 
delayUs(2); 
col = GPIO_PORTC_DATA_R & 0xF0;
if (col != 0xF0) break;
row = 2;
GPIO_PORTE_DATA_R = 0x0B; 
delayUs(2); 
col = GPIO_PORTC_DATA_R & 0xF0;
if (col != 0xF0) break;
row = 3;
GPIO_PORTE_DATA_R = 0x07; 
delayUs(2); 
col = GPIO_PORTC_DATA_R & 0xF0;
if (col != 0xF0) break;
return 0; 
}

if (col == 0xE0) return keymap[row][0]; 
if (col == 0xD0) return keymap[row][1]; 
if (col == 0xB0) return keymap[row][2]; 
if (col == 0x70) return keymap[row][3]; 
return 0; 
}