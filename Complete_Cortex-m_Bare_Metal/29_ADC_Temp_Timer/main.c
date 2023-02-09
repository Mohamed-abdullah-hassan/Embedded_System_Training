#include "TM4C123.h"                    // Device header



unsigned int	ADC_Read(void);
void ADC_Init (void);
void Timer_Init(void);

int main ( )
{
	volatile int x =0;
		
	volatile unsigned int temp;
	ADC_Init();
	Timer_Init();
	//while (1)
	//	{
	//		x++;
	//		if(x >= 50000) x=0;
	//	}
	
	while (1)
	{
		temp = 147 - ( 247 * ADC_Read())/4096;
	}

	

	return 0;
}

void Timer_Init(void)
{
	SYSCTL->RCGCWTIMER					|=	 0X01;
	WTIMER0->CTL								|=	 0X00;
	WTIMER0->CFG								 =	 0X04;
	WTIMER0->TAMR								 =	 0X02;
	WTIMER0->TAILR							 =	 16000000;
	WTIMER0->CTL								|=	 0X20;
	WTIMER0->CTL								|=	 0X01;
}


void ADC_Init (void)
{
	
	SYSCTL->RCGCADC							|=	 0X01;
	while( (SYSCTL->PRADC	&	0X01) ==	0);
	ADC0->ACTSS									&=	~0X08;
	ADC0->EMUX									&=	~0XF000;
	ADC0->EMUX									|=	 0X5000;
	ADC0->SSMUX3								 =	 0;
	ADC0->SSCTL3								|=	 0X0E;
	ADC0->ACTSS									|=	 0X08;
	
}

unsigned int	ADC_Read(void)
{
	//ADC0->PSSI									|=	0X08;
	while((ADC0->RIS	&	0X08)	== 0);
	ADC0->ISC										 =	0X08;
	return	ADC0->SSFIFO3;
}

