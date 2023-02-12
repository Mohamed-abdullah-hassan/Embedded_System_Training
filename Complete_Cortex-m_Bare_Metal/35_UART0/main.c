
#include "TM4C123.h"                    // Device header
// Current system clk is 40MHz by deafult
#define		UART0_RX_PIN			1<<0
#define		UART0_TX_PIN			1<<1
#define		UART0_MODULE			1<<0
#define		UART0_GPIO_PORT		GPIOA
#define		GPIO_PCTL_1				0X0F
#define		GPIO_PCTL_2				0XF0


void UART0_Init(void);
void UART0_Write(unsigned char);
void Delay(unsigned long counter);

int main (void)
{
	UART0_Init();
	while(1){
	UART0_Write('H');
	UART0_Write('e');
	UART0_Write('l');
	UART0_Write('l');
	UART0_Write('o');
	UART0_Write('!');
	UART0_Write('\n');
	Delay(10000000);
	
	}
}

void UART0_Init(void)
{
	SYSCTL->RCGCUART		 =	UART0_MODULE;
	SYSCTL->RCGCGPIO		|=	0x01;
	while ( ( SYSCTL->PRGPIO & 1<<0) != 1); //wait for GPIOA to be ready
	GPIOA->DEN					|= 0x03;
	GPIOA->AFSEL				|= (0x03);
	GPIOA->PCTL					 = ( GPIOA->PCTL & 0XFF) | 0x11;
	while ( ( SYSCTL->PRUART & UART0_MODULE ) != 1) {} //wait for uart0 module to be ready;
	UART0->CTL					 = 0;
	UART0->IBRD					 = 27; //Intergral part to achive 115200 using 50MHz SYSCLK
	UART0->FBRD					 = 8;
	UART0->LCRH					 = 0b01100000;  //Page 916
	UART0->CC						 = 0b0000; //Page 939
	UART0->CTL					 = 0b0000001100000001; //Page 918
}

void UART0_Write(unsigned char c)
{
	while(UART0->FR & 0x20);
	UART0->DR						 = c;	
}



void Delay(unsigned long counter)
{
	unsigned long i = 0;
	
	for(i=0; i< counter; i++);
}
