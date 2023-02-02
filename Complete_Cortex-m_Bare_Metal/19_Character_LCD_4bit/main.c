#include "TM4C123.h"                    // Device header

#define LCD_Port	GPIOB
#define	LCD_RS		1U<<0
#define	LCD_RW		1U<<1
#define	LCD_EN		1U<<2
#define	lcd_cmd		0
#define	lcd_data	LCD_RS


void LCD_Init_4bit(void);
void LCD_Write_4bit(unsigned char data, unsigned char control);
void LCD_Cmd_4bit (unsigned char cmd);
void LCD_Data_4bit (unsigned char data);
void LCD_Print_Str (unsigned char *str);

void delay_us(unsigned int n);
void delay_ms(unsigned int n);

int main()
{
	unsigned char c[]="Hello!";
	LCD_Init_4bit();
	LCD_Cmd_4bit(1);
	LCD_Cmd_4bit(0x80);
	delay_ms(500);	
	LCD_Print_Str(&c[0]);
}

void LCD_Init_4bit(void)
{
	SYSCTL->RCGCGPIO		|= 	0x02;
	LCD_Port->DEN					|=  0XFF;
	LCD_Port->DIR					|=  0XFF;   // LCD controls RS,E,RW
	LCD_Cmd_4bit (0x28);
	LCD_Cmd_4bit (0x06);
	LCD_Cmd_4bit (0x01);
	LCD_Cmd_4bit (0x0F);
}

void LCD_Write_4bit(unsigned char data, unsigned char control)
{
	control &= 0x0F;
	LCD_Port->DATA = ((data &0xF0) | control);
	LCD_Port->DATA |= LCD_EN;
	delay_us(1);
	LCD_Port->DATA &= 0x0F;
	delay_us(1);
	data <<= 4;
	LCD_Port->DATA = ((data &0xF0) | control);
	LCD_Port->DATA |= LCD_EN;
	delay_us(1);
	LCD_Port->DATA &= 0x0F;	
}

void LCD_Cmd_4bit (unsigned char cmd)
{
	LCD_Write_4bit(cmd,lcd_cmd);
	if(cmd <4)
		delay_ms(2);
	else
		delay_us(40);
}

void LCD_Data_4bit (unsigned char data)
{
	LCD_Write_4bit(data,lcd_data);
	delay_us(40);
}

void LCD_Print_Str (unsigned char *str)
{
	while(*str != 0)
	{
		LCD_Data_4bit(*str);
		str++;
	}
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

