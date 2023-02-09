#include "TM4C123.h"                    // Device header



unsigned int	ADC_Read(void);
void ADC_Init (void);

int main (void)
{
	unsigned int value;
	ADC_Init();
	
	while (1)
	{
		value = ADC_Read();
	}

	

	
}


void ADC_Init (void)
{
	
	SYSCTL->RCGCADC							|=	 0X01;
	SYSCTL->RCGCGPIO						|=	 0X10;
	GPIOE->AFSEL								|=	 0X08;
	GPIOE->DEN									&=	~0X08;
	GPIOE->AMSEL								|=	 0X08;
	
	ADC0->ACTSS									&=	~0X08;
	ADC0->EMUX									&=	~0XF000;
	ADC0->SSMUX3								 =	 0;
	ADC0->SSCTL3								|=	 6;
	ADC0->ACTSS									|=	 0X08;
	
}

unsigned int	ADC_Read(void)
{
	ADC0->PSSI									|=	0X08;
	while((ADC0->RIS	&	0X08)	== 0);
	ADC0->ISC										 =	0X08;
	return	ADC0->SSFIFO3;
}

