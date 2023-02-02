#include "TM4C123.h" // Device header
 
#define LCD_CTRLP GPIOA
#define LCD_DATAP GPIOB
#define RS 0x20 /* PORTA BIT5 mask */
#define RW 0x40 /* PORTA BIT6 mask */
#define EN 0x80 /* PORTA BIT7 mask */
#define HIGH 1
#define LOW 0
 
void delay_milli(int n);
void delay_micro(int n);
void LCD_init(void);
void LCD4bit_Cmd(unsigned char command);
void LCD4bit_Data(unsigned char data);
 
int main()
{
 LCD_init();
 LCD4bit_Cmd(0x01);
 LCD4bit_Cmd(0x80);
 delay_milli(500);
 
 LCD4bit_Data('a');
 delay_micro(20);
// LCD4bit_Data('E');
 delay_milli(500);
// 
 
}
 
void LCD_init(void)
{
 SYSCTL->RCGCGPIO |=0x01;
 SYSCTL->RCGCGPIO |=0x02;
 LCD_DATAP ->DIR |=0xF0;
 LCD_DATAP ->DEN |=0xF0;
 LCD_CTRLP ->DIR |=0xF0;
 LCD_CTRLP ->DEN |=0xF0;
 
 LCD4bit_Cmd(0x20);
 LCD4bit_Cmd(0x28);
 LCD4bit_Cmd(0x06);
 LCD4bit_Cmd(0x01);
 LCD4bit_Cmd(0x0F);
 
 //..
 //...
}
void LCD4bit_Data(unsigned char data)
{
 unsigned char temp;
 LCD_CTRLP->DATA = RS;
 temp = data;
 temp = temp>>4;
 LCD_DATAP->DATA = temp;
 LCD_CTRLP->DATA = RS |EN;
 delay_micro(10);
 LCD_CTRLP->DATA =RS;
 delay_micro(37);
 
 temp =data;
 //LCD_CTRLP->DATA = RS;
 LCD_DATAP->DATA = temp;
 LCD_DATAP->DATA = RS |EN;
 delay_micro(10);
 LCD_CTRLP->DATA =0x00;
 delay_micro(37);
 
}
 
void LCD4bit_Cmd(unsigned char command)
{
 unsigned char temp;
 LCD_CTRLP->DATA = 0x00;
 temp = command;
 temp = temp>>4;
 LCD_DATAP->DATA =temp;
 LCD_CTRLP->DATA = EN;
 delay_micro(0);
 LCD_CTRLP->DATA = 0x00;
 if(command < 4) delay_milli(2); else delay_micro(37); temp = command; LCD_DATAP->DATA =temp;
 LCD_CTRLP->DATA = EN;
 delay_micro(0);
 LCD_CTRLP->DATA =0x00;
 
}
 
void delay_milli(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3180;j++)
 {}
}
 
void delay_micro(int n)
{
 int i,j;
 for(i=0;i<n;i++)
 for(j=0;j<3;j++)
 {}
 
}