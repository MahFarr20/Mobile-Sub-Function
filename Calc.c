
#include <stdint.h>
#include "KEYPAD.h"
#include "LCD.h"
#include "Calc.h"

int key;
float result;
 int j=0;
 float x[2];
 char y[1];
 int z=0;
 int flag=1;
 int flag2=1;
char result2;
int tens;
int result3;
int ones;
float tens_2;
int result4;
int result5;
int result8;
int result6;
int result7;

void cal()
{
  do{                         
           key=keypad_getkey();
           delayMs(200);   
}
   while(key==0);


switch(key)
{
  case'0'://printf("0") ;
  
   if(flag==1)
    {
    //printf("%d",0);
    lcd_data('0');
    flag++;
    x[j]=0;
    j++;

    }
  
  
 
  break;
  case'1'://printf("1");
  if(flag==1)
    {
    //printf("%d",1);
    lcd_data('1');
   
    flag++;
    x[j]=1;
    j++;
    }

  break;
  case'2'://printf("2");
    if(flag==1)
    {
    //printf("%d",2); 
    lcd_data('2');
    flag++;
    x[j]=2;
    j++;
    }
 
  break;
  case'3'://printf("3"); 
  if(flag==1)
    {
    //printf("%d",3);
    lcd_data('3');
    flag++;
     x[j]=3;
    j++;
    }
 
  break;
  case'4'://printf("4"); 
    if(flag==1)
    {
    //printf("%d",4);
    lcd_data('4');
    flag++;
     x[j]=4;
    j++;
    }
 
  break;
  case'5'://printf("5"); 
    if(flag==1)
    {
    //printf("%d",5);
    lcd_data('5');
    flag++;
     x[j]=5;
    j++;
    }
 
  break;
  case'6'://printf("6");
 if(flag==1)
    {
    //printf("%d",6);
    lcd_data('6');
    flag++;
     x[j]=6;
    j++;
    }
  break;
  case'7'://printf("7");
    if(flag==1)
    {
    //printf("%d",7);
    lcd_data('7');
    flag++;
    x[j]=7;
    j++;
    }
  
  break;
  case'8'://printf("8");
    if(flag==1)
    {
    //printf("%d",8);
    lcd_data('8');
    flag++;
    x[j]=8;
    j++;
    }
  break;
  case'9'://printf("9");
    if(flag==1)
    {
    //printf("%d",9);
    lcd_data('9');
    flag++;
    x[j]=9;
    j++;
    }
  break;
  case'+'://printf("+");
     if(flag2==1)
    {
    flag=1;
    //printf("+");
    lcd_data('+'); 
    flag2++;
    y[z]='+';
    }
  break;
   case'-'://printf("-");
     if(flag2==1)
    {
    flag=1;
   //printf("-");
   lcd_data('-'); 
    flag2++;
    y[z]='-';
    }
    
  break;
   case'*'://printf("*");
     if(flag2==1)
    {
    flag=1;
    //printf("*");
    lcd_data('*'); 
    flag2++;
    y[z]='*';
    }
  break;
   case'/'://printf("/");
     if(flag2==1)
    {
    flag=1;
    //printf("/");
    lcd_data('/'); 
    flag2++;
    y[z]='/';
    }
  break;
  
  case'='://printf("=");
    if(flag2==2)
    {
      
      lcd_data('='); 
      
      operation();
     
    }
    
    break;
    
    case'c':
      //printf("c");
    flag=1;
    flag2=1;
    LCD_command(1);
    //printf("0");
    j=0;
    break;
  
  
}
}


  

void operation()
{
  
  switch(y[0])
  {
    case'+':result=x[0]+x[1]; 
    printf("%.2f",result); 
    //result2=result+48;
    //char c=result;
    calculate(result);
    //lcd_data(result2); 
    break;
    case'-': 
      result=x[0]-x[1];
      //result2=result+48;
      //printf("%.2f",result);
      //lcd_data(result2); 
       calculate(result);
    break;
    case'*': 
      
      result=x[0]*x[1];
      //result2=result+48;
      //printf("%.2f",result);
      //lcd_data(result2); 
      calculate(result);
    break;
    case'/': 
      result=x[0]/x[1];
      //printf("%.2f",result);
      //result2=result+48;
      //lcd_data(result2);
      calculate_divide(result);
    break;
      
  }
}

    
  
void delayMs(uint32_t n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
     {
     } /* do nothing for 1 ms */
}
void delayUs(uint32_t n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3; j++)
{} /* do nothing for 1 us */

}

void calculate(int calculation)
{
   if(calculation>=0&&calculation<=99)
  {
     tens=calculation/10;
 
     printf("%f",tens_2);
   
     
     result2=tens+48;  
    lcd_data(result2);
    result3=calculation%10;
   
    result4=result3+48;
    lcd_data(result4); 
    
  } 
  
  if(calculation<0)
  {
     lcd_data('-');
result3=abs(calculation);
result4=result3+48;
    lcd_data(result4); 
    
        
  } 

}

void calculate_divide(float calculation)
{
 
  if(x[1]==0)
  {
    lcd_data('e');
    lcd_data('r');
    lcd_data('r');
    lcd_data('o');
    lcd_data('r');
 
  }
 else
 {
   if((x[0]>x[1]))
   {
  result5=(int)calculation;
  result5=calculation+48;
  lcd_data(result5);
  lcd_data('.');
  result6=(calculation*10)-10;
  result7=result6+48;
  lcd_data(result7);
   }
     else if((x[0]==x[1])||(x[1]==1))
        {
           result5=(int)calculation;
           result5=calculation+48;
           lcd_data(result5);
    
        }
     else if(x[0]==0){
     lcd_data('0');
     }
  
 }


}