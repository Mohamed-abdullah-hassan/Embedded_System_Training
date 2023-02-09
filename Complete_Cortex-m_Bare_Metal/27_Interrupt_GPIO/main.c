#include "TM4C123.h"                    // Device header



#define LED_Red			0X02
#define	LED_Blue		0X04
#define LED_Green		0X08
#define	SW1					0x10
#define	SW2					0X01



int main(void)
{
	SYSCTL->RCGCGPIO				|=	 0X20;
	GPIOF->LOCK							 =	 0X4C4F434B;
	GPIOF->CR								 =	 0X01;
	GPIOF->LOCK							 =	 0;
	GPIOF->DIR							 =	 (LED_Blue | LED_Green | LED_Red);
	GPIOF->DEN							|=	 (LED_Blue | LED_Green | LED_Red | SW1 | SW2 );
	GPIOF->PUR							|=	 (SW1 | SW2 );
	
	__disable_irq();
	
	GPIOF->IS								&=	~0X11;
	GPIOF->IBE							&=	~0X11;
	GPIOF->IEV							&=	~0X11;
	GPIOF->ICR							|=	 0X11;
	GPIOF->IM								|=	 0X11;
	NVIC->IP[30]						 = 	 3<<5;
	NVIC->ISER[0]						 =	 0X40000000;
		
	__enable_irq();
	
	while(1)
	{
		
	}
	
}

void GPIOF_Handler(void)
{
	volatile int readback;
	
	GPIOF->ICR						|=	 0X11;
	readback		= GPIOF->ICR;
}

