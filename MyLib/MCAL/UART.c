#include "uart.h"

void UART_Init(void)
{
	SYSCTL->RCGCUART		 =	UART_NUMBER;
	SYSCTL->RCGCGPIO		|=	UART_GPIO_RCGC_EN;
	while ( ( SYSCTL->PRGPIO & UART_GPIO_RCGC_EN) == 0); //wait for GPIO to be ready
#ifdef		UART_LOCK_EXIST
		UART_GPIO_PORT->LOCK		=	0x4C4F434B;
		UART_GPIO_PORT->CR		 |= UART_LOCK_PIN;
#endif
	
	UART_GPIO_PORT->DEN		|= (UART_GPIO_RX_PIN | UART_GPIO_TX_PIN);
	UART_GPIO_PORT->AFSEL	|= (UART_GPIO_RX_PIN | UART_GPIO_TX_PIN);
	
#ifdef		UART_LOCK_EXIST
		UART_GPIO_PORT->LOCK		=	0;		
#endif
	UART_GPIO_PORT->PCTL	 = ( UART_GPIO_PORT->PCTL & ~UART_GPIO_PCTL_MASK) | UART_GPIO_PCTL_SET;
	while ( ( SYSCTL->PRUART & UART_NUMBER ) == 0) {} //wait for uart module to be ready;
	UART_BLOCK->CTL				 = 0;
	UART_BLOCK->IBRD			 = __UART_IBRD; 
	UART_BLOCK->FBRD			 = __UART_FBRD;
	UART_BLOCK->LCRH			 = __UART_LCRH;  
	UART_BLOCK->CC				 = 0b0000; 
	UART_BLOCK->CTL				 = __UART_CTL; 
}

void UART_Write(unsigned char c)
{
	while(UART_BLOCK->FR & 0x20);
	UART_BLOCK->DR				 = c;	
}

