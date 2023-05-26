#include "SSI.h"

void SSI_Init (void)
{
	SYSCTL->RCGCSSI		= SSI_NUMBER;
	SYSCTL->RCGCGPIO	|= SSI_GPIO_RCGC_EN;
	SSI_GPIO_PORT->AFSEL 	= SSI_GPIO_PINS;
	//SSI_GPIO_PORT->PCTL		= (SSI_GPIO_PORT->PCTL & SSI_GPIO_PCTL_MSK) | SSI_GPIO_PCTL_SET;
	SSI_GPIO_PORT->PCTL		= SSI_GPIO_PCTL_SET;
	SSI_GPIO_PORT->DEN		|= SSI_GPIO_PINS;
	while( (SYSCTL->PRSSI & SSI_NUMBER) ==0);
	SSI_BLOCK->CR1 = 0;
	//SSI_BLOCK->CR1 = __SSI_CR1_VALUE;
	SSI_BLOCK->CC		= 0;
	SSI_BLOCK->CPSR = __SSI_CPSDVSR;
	//SSI_BLOCK->CPSR = 0x02;
	//SSI_BLOCK->CR0 |= (1<<7);
	SSI_BLOCK->CR0 = __SSI_CR0_VALUE;
	//SSI_BLOCK->CR0 |= 0x7 ;
	SSI_BLOCK->CR1 = 1<<1;
}

void SSI_Send(unsigned char data)
{
	while ((SSI_BLOCK->SR & __SSI_SR_TNF__) == 0);
	SSI_BLOCK->DR		= data;	

	while((SSI_BLOCK->RIS & 1<<3) ==0);
	//while((SSI_BLOCK->SR & __SSI_SR_BSY__));
	//while((SSI_BLOCK->SR & 0x01) != 1);
}

void SSI_Send_Multi(unsigned char *buffer, unsigned char count)
{
	unsigned char i;
	if(count == 0)
		return;
	else
	{
		for(i=0;i<count;i++)
		{
			while ((SSI_BLOCK->SR & __SSI_SR_TNF__) == 0);
			SSI_BLOCK->DR		= buffer[i];
		}
	}
	while((SSI_BLOCK->RIS & 1<<3) ==0);
	//while((SSI_BLOCK->SR & __SSI_SR_BSY__));
	//while((SSI_BLOCK->SR & 0x01) != 1);
}

void SSI_Send_Fast(unsigned char data)
{
			while ((SSI_BLOCK->SR & __SSI_SR_TNF__) == 0);
			SSI_BLOCK->DR		= data;	
	
}
