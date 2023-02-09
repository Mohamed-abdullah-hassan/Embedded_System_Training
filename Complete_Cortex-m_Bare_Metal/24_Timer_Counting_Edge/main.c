#include "TM4C123.h"                    // Device header


void Timer3A_Edge_Event_Init(void);
int	Timer3A_Edge_Event_Capture (void);

int main (void)
{
	unsigned int event_count =0;
	
	Timer3A_Edge_Event_Init();
	while (1)
	{
		event_count = Timer3A_Edge_Event_Capture();
	}
	return 0;
}


void Timer3A_Edge_Event_Init(void)
{
	SYSCTL->RCGCGPIO		|= 0X02;						// 	Enable Port B Clock
	SYSCTL->RCGCTIMER		|= 0X08;						//	Enable Timer 3 block
	GPIOB->DIR					&=~0X04;						//	Make Pin 2 in Port B as an Input
	GPIOB->DEN					|= 0X04;						//	Configure PB2 as a digital pin
	GPIOB->AFSEL				|= 0X04;						//	Enable Alternate function on PB2
	GPIOB->PCTL					&=~0x00000F00;			//	Configure PB2 as Timer 3 CCP0 pin
	GPIOB->PCTL					|= 0x00000700;			//	Configure PB2 as Timer 3 CCP0 pin
	TIMER3->CTL					 = 0X00;						//	Disable Timer 3 A while configuring
	TIMER3->CFG					 = 0X04;						//	Configure	as 16-bit	timer mode
	TIMER3->TAMR				 = 0X13;						//	Up-Counter, Edge-Counter, Capture-mode
	TIMER3->TAMATCHR		 = 0XFFFF;					//	Set count limit which is compared with TAR to determine match event
	TIMER3->TAPMR				 = 0XFF;						//	Used in conjuction with TAMATRCH to expand the counter to to 0XFFFFFF
	TIMER3->CTL					 = 0X01;						//	Enable Timer 3 A block
}

int	Timer3A_Edge_Event_Capture (void)
{
	return	TIMER3->TAR;
}
