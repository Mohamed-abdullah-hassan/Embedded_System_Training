#include "TM4C123.h"                    // Device header

#define Ulrtasonic_Echo		(1U<<6)				//PB6
#define Ulrtasonic_Trig		(1U<<2)				//PA4
#define LED_Blue					(1U<<2)

void Timer0_Init(void);
void delay_us(unsigned int time);
void Ports_Init (void);
unsigned int	Measure_Distance (void);

const	double	_Clock_Time	=	62.5e-9;
const	double	sound_speed	=	5882; 



int main (void)
{
	Ports_Init();
	Timer0_Init();
	while(1)
	{
		if(Measure_Distance() < 15)
			GPIOF->DATA				|=	LED_Blue;
		else
			GPIOF->DATA				&= ~LED_Blue;
	}
}

void Timer0_Init(void)
{
	SYSCTL->RCGCTIMER			|=	0x01;
	SYSCTL->RCGCGPIO			|=	0x02;
	GPIOB->DIR						&= ~Ulrtasonic_Echo;
	GPIOB->DEN						|=	Ulrtasonic_Echo;
	GPIOB->AFSEL					|=	Ulrtasonic_Echo;
	GPIOB->PCTL						&= ~0X0F000000;
	GPIOB->PCTL						|=	0X07000000;
	
	TIMER0->CTL						&= ~1;
	TIMER0->CFG						 = 	4;
	TIMER0->TAMR					 =	0X17;
	TIMER0->CTL						|=	0X0C;
}



void delay_us(unsigned int time)
{
	SYSCTL->RCGCTIMER			|=	0x02;
	TIMER1->CTL						 =	0;
	TIMER1->CFG						 =	0X04;
	TIMER1->TAMR					 =	0X02;
	TIMER1->TAILR					 =	16-1;
	TIMER1->ICR						 =	0X01;
	TIMER1->CTL						 = 	0X01;
	while(time)
	{
		while ((TIMER1->RIS & 0X01) ==0);
		TIMER1->ICR					 =	0X01;
		time--;			
	}
	TIMER1->CTL						 =	0;
}

void Ports_Init (void)
{
	SYSCTL->RCGCGPIO			|=	((1U<<0) | (1U<<5));
	GPIOA->DIR						|=	Ulrtasonic_Trig;
	GPIOF->DIR						|=	LED_Blue;
	GPIOA->DEN						|=	Ulrtasonic_Trig;
	GPIOF->DEN						|=	LED_Blue;
}

unsigned int	Measure_Distance (void)
{
	unsigned int time =0;
	GPIOA->DATA						&=	~Ulrtasonic_Trig;
	delay_us(10);
	GPIOA->DATA						|=	Ulrtasonic_Trig;
	delay_us(10);
	GPIOA->DATA						&=	~Ulrtasonic_Trig;
	
	TIMER0->ICR						 =	4;
	while( (TIMER0->RIS	&	4 )	==	0);
	time		=		TIMER0->TAR;
	TIMER0->ICR						 =	4;
	while( (TIMER0->RIS	&	4 )	==	0);
	time		=		TIMER0->TAR - time;
	
	return	(sound_speed * (double) _Clock_Time * (double) time);
}

