#include "TM4C123.h"                    // Device header

void LCD_Init(void);
void LCD_Cmd (unsigned char cmd);
void LCD_Data(unsigned char data);

void delay_us(unsigned int n);
void delay_ms(unsigned int n);

int main()
{
	LCD_Init();
	LCD_Cmd(0x01);
	LCD_Cmd(0X08);
	delay_ms(500);
	LCD_Data('C');
	delay_ms(1);
	LCD_Data('O');
	delay_ms(1);
	LCD_Data('R');
	delay_ms(1);	
	LCD_Data('T');
	delay_ms(1);
	LCD_Data('E');
	delay_ms(1);
	LCD_Data('X');
	delay_ms(1);
	LCD_Data('-');
	delay_ms(1);
	LCD_Data('M');
	delay_ms(1);
	LCD_Data('.');
	delay_ms(1);
	LCD_Data('C');
	delay_ms(1);
	LCD_Data('O');
	delay_ms(1);
	LCD_Data('M');
	delay_ms(1);
}

void LCD_Init(void)
{
	SYSCTL->RCGCGPIO	|=  0x03;
	GPIOA->DIR				|=  0XE0;   // LCD controls RS,E,RW
	GPIOA->DEN				|=  0XE0;
	GPIOB->DEN				 =  0XFF;
	GPIOB->DIR				 =  0xFF;
	LCD_Cmd(0X38);
	LCD_Cmd(0X06);
	LCD_Cmd(0X0F);
	LCD_Cmd(0X01);
}

void LCD_Data(unsigned char data)
{
	GPIOA->DATA				&= ~0XE0;
	GPIOA->DATA				|=  0x20;		// RS=1, RW=0, E=0
	GPIOB->DATA				 = 	data;
	GPIOA->DATA				|=	0x80;		// Set RW=1
	delay_us(1);
	GPIOA->DATA				&= ~0XE0;
	delay_us(1);	
}


void LCD_Cmd (unsigned char cmd)
{
	GPIOA->DATA &= ~0xE0;
	GPIOB->DATA	 = cmd;
	GPIOA->DATA	 = 0x80;    // E=1
	delay_us(1);
	GPIOA->DATA &= ~0xE0;
	if(cmd <4)
		delay_us(2);
	else
		delay_us(4);
}

void delay_us(unsigned int n)
{
	volatile int i,j;
	for (i=0;i<=n;i++)
		for(j=0;j<=3;j++)
			{}
}

void delay_ms(unsigned int n)
{
	volatile int i,j;
	for (i=0;i<=n;i++)
		for(j=0;j<=3180;j++)
			{}
}
