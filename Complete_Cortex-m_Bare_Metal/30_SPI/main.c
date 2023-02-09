#include "TM4C123.h"                    // Device header

void SPI_Init(void);
void SPI_Write(unsigned char data );
	
int main (void)
{
	SPI_Init();
		
	while (1)
	{
		for (unsigned char c = 'A'; c<='z';c++)
			SPI_Write(c);
		
	}
}

void SPI_Init(void)
{
	SYSCTL->RCGCSSI					|=	 0X02;
	SYSCTL->RCGCGPIO				|=	 0X28;
	GPIOD->AMSEL						&=	~0X09;
	GPIOD->DEN							|=	 0X09;
	GPIOD->AFSEL						|=	 0X09;
	GPIOD->PCTL							&=	~0X0000F00F;
	GPIOD->PCTL							|=	 0X00002002;
	
	GPIOF->DEN							|=	 0X04;
	GPIOF->DIR							|=	 0X04;
	GPIOF->DATA							|=	 0X04;
	
	SSI1->CR1								 =	 0;
	SSI1->CC								 =	 0;
	SSI1->CPSR							 =	 2;
	SSI1->CR0								 =	 0X0007;
	SSI1->CR1								|=	 2;
}

void SPI_Write(unsigned char data )
{
	GPIOF->DATA							&=	~0X04;
	while( (SSI1->SR	&	2)	==	0	) { }
	SSI1->DR 								 =	data;
	while( (SSI1->SR	&	0X01)	==	0	) { }
	GPIOF->DATA							|=	 0X04;
	
	
}


