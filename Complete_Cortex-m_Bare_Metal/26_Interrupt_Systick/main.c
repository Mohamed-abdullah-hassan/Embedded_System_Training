#include "TM4C123.h"                    // Device header

#define LED_Red			0X02
#define	LED_Blue		0X04
#define LED_Green		0X08



int main(void)
{
	SYSCTL->RCGCGPIO				|=	 0X20;
	GPIOF->DIR							|=	 (LED_Blue | LED_Green | LED_Red);
	GPIOF->DEN							|=	 (LED_Blue | LED_Green | LED_Red);
	GPIOF->DATA							^=	LED_Blue;
	
	__disable_irq();
	SysTick->LOAD						 =	16000000U - 1;
	SysTick->CTRL						 =	7;
	__enable_irq();
	
	
	while(1){}
	
}

void SysTick_Handler()
{
	GPIOF->DATA							^=	(LED_Blue|LED_Red);

}

