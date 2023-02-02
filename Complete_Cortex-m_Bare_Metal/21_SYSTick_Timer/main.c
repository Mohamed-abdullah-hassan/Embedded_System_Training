#include "TM4C123.h"                    // Device header

#define LED_Green		(1U<<3)


int main()
{
	SYSCTL->RCGCGPIO	|= 0X20;
	GPIOF->DIR				|= LED_Green;
	GPIOF->DEN				|= LED_Green;
	
	SysTick->LOAD			 = 16777216UL -1;
	SysTick->CTRL			 = 5;
	
	while(1)
	{
		if (SysTick->CTRL & 0X10000)
			GPIOF->DATA		^= LED_Green;
	}
}
