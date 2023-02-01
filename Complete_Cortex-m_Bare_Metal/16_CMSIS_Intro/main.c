#include "TM4C123.h"                    // Device header


#define LED_RED (1U<<1)
#define LED_BLUE (1UL<<2)
#define LED_GREEN (1UL<<3)


int main ()
{
	int delay =0;
	SYSCTL->RCGCGPIO = 0x20U;
	GPIOF->DIR = (LED_RED | LED_BLUE | LED_GREEN);
	GPIOF->DEN = (LED_RED | LED_BLUE | LED_GREEN);;
	GPIOF->DATA = LED_GREEN;
	while (1)
	{
		GPIOF->DATA |= LED_BLUE;
		while (delay <4000000) delay++;    //Make some delay for visualy notice the blinking
        delay =0;
		GPIOF->DATA &= ~(LED_BLUE);
		while (delay <4000000) delay++;    //Make some delay for visualy notice the blinking
        delay =0;
	}
	
	return 0;
}
