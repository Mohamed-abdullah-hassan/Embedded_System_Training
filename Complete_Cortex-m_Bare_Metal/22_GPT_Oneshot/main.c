// General Purpose Timers Implementation
// One Shot timer

#include "TM4C123.h"                    // Device header

#define LED_Red			(1U<<1)
#define LED_Blue		(1U<<2)
#define LED_Green		(1U<<3)

void Timer1_Oneshot(unsigned int mdelay);

int main()
{
	SYSCTL->RCGCGPIO		|= 0X20;
	GPIOF->DIR					|= LED_Red;
	GPIOF->DEN					|= LED_Red;
	
	
	while (1)
	{
		GPIOF->DATA				^= LED_Red;
		Timer1_Oneshot(1000);
		
	}
}

void Timer1_Oneshot(unsigned int mdelay)
{
	while (mdelay)
	{
		SYSCTL->RCGCTIMER		|= 0X01;									// Enable Timer 0 Module Clock
		TIMER0->CTL					 = 0X00;									// Disable Timer 0 operation before making changes
		TIMER0->CFG					 = 0X04;									// Select 16-bit operation 
		TIMER0->TAMR				 = 0X01;									// Select One-Shot counter
		//TIMER0->TAILR				 = (16000U * mdelay-1);	// Set Interveal of Timer 0 A 
		TIMER0->TAILR				 = (40000U);							// Set Interveal of Timer 0 A 
		TIMER0->ICR					 = 0X01;									// Reset the counter flag by writing 1 
		TIMER0->CTL					|= 0X01;									// Enable Timer 0 Operation
		
		while((TIMER0->RIS & 0X01) == 0);  						//wait for timer 0 flag set
		mdelay --;
	}
}
