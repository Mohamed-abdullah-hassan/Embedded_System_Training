#include "TM4C123.h"                    // Device header

#define LED_RED (1U<<1)
#define LED_BLUE (1UL<<2)
#define LED_GREEN (1UL<<3)

#define SW1 (1U<<4)
#define SW2 (1U<<0)

#define LOCK_KEY	0x4C4F434B

uint32_t SW_input();
void LED_ON(uint32_t LED);
void delay(volatile uint32_t time);

int main()
{
	SYSCTL->RCGCGPIO |= (1U<<5);
	GPIOF->LOCK = LOCK_KEY;
	GPIOF->CR	= 0xFF;
	GPIOF->DEN |= (LED_RED | LED_BLUE |LED_GREEN | SW1 | SW2);
	GPIOF->DIR |= (LED_RED | LED_BLUE |LED_GREEN);
	GPIOF->PUR |= (SW1 | SW2);
	
	while(1)
	{
		switch(SW_input())
		{
			case SW1:
					LED_ON(LED_GREEN);
					break;
			case SW2:
					LED_ON(LED_BLUE);
					break;
			case (SW1 | SW2):
					LED_ON(LED_RED);
					break;
		}
	}

return 0;	
}

uint32_t SW_input()
{
	
	return (~(GPIOF->DATA) & (SW1 | SW2));
	
	}

void LED_ON(uint32_t LED)
{
	GPIOF->DATA = LED;	
	delay(1000000);
	GPIOF->DATA &= ~LED;
	delay(500000);

}

void delay(volatile uint32_t time)
{
	while(time)
		time--;
}
