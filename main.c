// group names:

// Mohamed Ayman Mohamed Hefny (15p8036)
// Mahmoud abdelaziz (15p3028)
// Amr Amer Hussein (15p8028)
// Amr ezz el-din (15p3054)

/* this calculator has the following functions : add, subtract, divide, multiply and clear.*/


#include "tm4c123gh6pm.h"
#include <stdint.h>
#include <stdio.h>
#include "KEYPAD.h"
#include "LCD.h"
#include "Calc.h"


     int main()
{
       LCD_init();
        keypad_init();
      
      LCD_command(1);    
               LCD_command(0x80); 
   
while(1)
{


cal();
}
}