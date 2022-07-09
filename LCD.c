#include "TM4C123GH6PM.h"
#include <stdint.h>
#include "LCD.h"
#define RS 0x20 
#define RW 0x40 
#define EN 0x80 


void LCD_command(unsigned char cmnd);


void LCD_init(void)
{
SYSCTL_RCGCGPIO_R |= 0x01; 
SYSCTL_RCGCGPIO_R |= 0x02; 
GPIO_PORTA_DIR_R |= 0xE0; 
GPIO_PORTA_DEN_R |= 0xE0; 
    
GPIO_PORTB_DIR_R = 0xFF; 
GPIO_PORTB_DEN_R = 0xFF; 
delayMs(20); 
LCD_command(0x30);
delayMs(5);
LCD_command(0x30);
delayUs(100);
LCD_command(0x30);
LCD_command(0x38); 
LCD_command(0x06); 
LCD_command(0x01); 
LCD_command(0x0F); 
LCD_command(0x80);
}
void LCD_command(unsigned char cmnd)
{
GPIO_PORTA_DATA_R = 0; 
GPIO_PORTB_DATA_R = cmnd;
GPIO_PORTA_DATA_R = EN; 
delayUs(0);
GPIO_PORTA_DATA_R  = 0;
if (cmnd < 4)
delayMs(2); 
else      
delayUs(40); 
}
void lcd_data(unsigned char data)
{
GPIO_PORTA_DATA_R = RS; 
GPIO_PORTB_DATA_R = data;
GPIO_PORTA_DATA_R = EN | RS;
delayUs(0);
GPIO_PORTA_DATA_R= 0;
delayUs(40);
}
