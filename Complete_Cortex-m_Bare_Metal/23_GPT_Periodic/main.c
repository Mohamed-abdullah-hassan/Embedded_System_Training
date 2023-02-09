// General Purpose Timers Implementation
// Peroidic timer

#include "TM4C123.h"                    // Device header

#define LED_Red			(1U<<1)
#define LED_Blue		(1U<<2)
#define LED_Green		(1U<<3)

void Timer0_Periodic(unsigned int mdelay);

int main()
{
	SYSCTL->RCGCGPIO		|= 0X20;
	GPIOF->DIR					|= LED_Blue;
	GPIOF->DEN					|= LED_Blue;
	
	
	while (1)
	{
		GPIOF->DATA				^= LED_Blue;
		Timer0_Periodic(1000);
		
	}
}

void Timer0_Periodic(unsigned int mdelay)
{

	SYSCTL->RCGCTIMER		|= 0X01;									// Enable Timer 0 Module Clock
	TIMER0->CTL					 = 0X00;									// Disable Timer 0 operation before making changes
	TIMER0->CFG					 = 0X04;									// Select 16-bit operation 
	TIMER0->TAMR				 = 0X02;									// Select Periodic counter
	TIMER0->TAILR				 = 16000U -1;							// Set Interveal of Timer 0 A 
	TIMER0->CTL					|= 0X01;									// Enable Timer 0 Operation
	while (mdelay)
	{
		TIMER0->ICR					 = 0X01;								// Reset the counter flag by writing 1 
		while((TIMER0->RIS & 0X01) == 0);  					//wait for timer 0 flag set
		mdelay --;
	}
}
