#ifndef		__UART_CONFIGURATION__
#define		__UART_CONFIGURATION__
#include "../configuration.h"
// Prohepted pins PC[3:0]

#ifdef    __DEFINE_USE_UART

#ifdef		__USE_UART0

#define		UART_NUMBER				1<<0
#define		UART_GPIO_PORT			GPIOA
#define		UART_GPIO_RCGC_EN		1<<0
#define		UART_GPIO_RX_PIN		1<<0
#define		UART_GPIO_TX_PIN		1<<1
#define		UART_GPIO_PCTL_MASK		0XFF
#define		UART_GPIO_PCTL_SET		0X11
#define		UART_BLOCK				UART0




#elif		defined(__USE_UART1_PORTB)
//Using 
// PB0 for RX and PB1 for TX PMC 1 in PCTL
#define		UART_NUMBER				1<<1
#define		UART_GPIO_PORT			GPIOB
#define		UART_GPIO_RCGC_EN		1<<1
#define		UART_GPIO_RX_PIN		1<<0
#define		UART_GPIO_TX_PIN		1<<1
#define		UART_GPIO_PCTL_MASK		0XFF
#define		UART_GPIO_PCTL_SET		0X11
#define		UART_BLOCK				UART1

#elif		defined(__USE_UART1_PORTC)
//Using 
// PC4 for RX and PC5 for TX PMC 2 in PCTL
#define		UART_NUMBER				1<<1
#define		UART_GPIO_PORT			GPIOC
#define		UART_GPIO_RCGC_EN		1<<2
#define		UART_GPIO_RX_PIN		1<<4
#define		UART_GPIO_TX_PIN		1<<5
#define		UART_GPIO_PCTL_MASK		0XFF0000
#define		UART_GPIO_PCTL_SET		0X220000
#define		UART_BLOCK				UART1

#elif		defined(__USE_UART2)
//Using 
// PD6 for RX and PD7 for TX PMC 1 in PCTL
#define		UART_NUMBER				1<<2
#define		UART_GPIO_PORT			GPIOD
#define		UART_GPIO_RCGC_EN		1<<3
#define		UART_GPIO_RX_PIN		1<<6
#define		UART_GPIO_TX_PIN		1<<7
#define		UART_GPIO_PCTL_MASK		0XFF000000
#define		UART_GPIO_PCTL_SET		0X11000000
#define		UART_BLOCK				UART2
#define		UART_LOCK_EXIST			
#define		UART_LOCK_PIN			1<<7

#elif		defined(__USE_UART3)
//Using 
// PC6 for RX and PC7 for TX PMC 1 in PCTL
#define		UART_NUMBER				1<<3
#define		UART_GPIO_PORT			GPIOC
#define		UART_GPIO_RCGC_EN		1<<2
#define		UART_GPIO_RX_PIN		1<<6
#define		UART_GPIO_TX_PIN		1<<7
#define		UART_GPIO_PCTL_MASK		0XFF000000
#define		UART_GPIO_PCTL_SET		0X11000000
#define		UART_BLOCK				UART3

#elif		defined(__USE_UART4)
//Using 
// PC4 for RX and PC5 for TX PMC 1 in PCTL
#define		UART_NUMBER				1<<4
#define		UART_GPIO_PORT			GPIOC
#define		UART_GPIO_RCGC_EN		1<<2
#define		UART_GPIO_RX_PIN		1<<4
#define		UART_GPIO_TX_PIN		1<<5
#define		UART_GPIO_PCTL_MASK		0X00FF0000
#define		UART_GPIO_PCTL_SET		0X00110000
#define		UART_BLOCK				UART4

#elif		defined(__USE_UART5)
//Using 
// PE4 for RX and PE5 for TX PMC 1 in PCTL
#define		UART_NUMBER				1<<5
#define		UART_GPIO_PORT			GPIOE
#define		UART_GPIO_RCGC_EN		1<<4
#define		UART_GPIO_RX_PIN		1<<4
#define		UART_GPIO_TX_PIN		1<<5
#define		UART_GPIO_PCTL_MASK		0X00FF0000
#define		UART_GPIO_PCTL_SET		0X00110000
#define		UART_BLOCK				UART5

#elif		defined(__USE_UART6)
//Using 
// PD4 for RX and PD5 for TX PMC 1 in PCTL
#define		UART_NUMBER				1<<6
#define		UART_GPIO_PORT			GPIOD
#define		UART_GPIO_RCGC_EN		1<<3
#define		UART_GPIO_RX_PIN		1<<4
#define		UART_GPIO_TX_PIN		1<<5
#define		UART_GPIO_PCTL_MASK		0X00FF0000
#define		UART_GPIO_PCTL_SET		0X00110000
#define		UART_BLOCK				UART6

#elif		defined(__USE_UART7)
//Using 
// PE0 for RX and PE1 for TX PMC 1 in PCTL
#define		UART_NUMBER				1<<7
#define		UART_GPIO_PORT			GPIOE
#define		UART_GPIO_RCGC_EN		1<<4
#define		UART_GPIO_RX_PIN		1<<0
#define		UART_GPIO_TX_PIN		1<<1
#define		UART_GPIO_PCTL_MASK		0X000000FF
#define		UART_GPIO_PCTL_SET		0X00000011
#define		UART_BLOCK				UART7
#endif

#define		__UART_BRD		(long double)((__SYSTEM_CLOCK)/(16.0 * __UART_BAUD_RATE)) 
#define		__UART_IBRD		(((unsigned int)(__UART_BRD)) & 0xFFFF)
#define		__UART_FBRD		(((unsigned int)((__UART_BRD - __UART_IBRD)* 64 +0.5))&0X3F)

#ifdef		__UART_WORD_8bit
	#define	__UART_LCRH_WLEN		0b01100000
#elif		defined(__UART_WORD_7bit)
	#define		__UART_LCRH_WLEN			0b01000000
#elif		defined(__UART_WORD_6bit)
	#define		__UART_LCRH_WLEN			0b00100000
#elif		defined(__UART_WORD_5bit)
	#define		__UART_LCRH_WLENRT_WLEN		0b00000000
#else
	#define		__UART_LCRH_WLEN			0b01100000
#endif

#ifdef		__UART_2_STOP_Bits
	#define	__UART_LCRH_STP2				0b00001000
#else
	#define	__UART_LCRH_STP2				0b00000000
#endif

#ifdef		__UART_EN_FIFO
	#define	__UART_LCRH_FEN					0b00010000
#else
	#define	__UART_LCRH_FEN				0b00000000
#endif


#ifdef		__UART_EN_RX
	#define		__UART_CTL_RXE		0b001000000000
#else
	#define		__UART_CTL_RXE		0b000000000000
#endif

#ifdef		__UART_EN_TX
	#define		__UART_CTL_TXE		0b000100000000
#else
	#define		__UART_CTL_TXE		0b000000000000
#endif

#define		__UART_CTL_UARTEN		0b000000000001

#define		__UART_LCRH			( __UART_LCRH_WLEN | __UART_LCRH_FEN | __UART_LCRH_STP2  )
#define		__UART_CTL			( __UART_CTL_RXE | __UART_CTL_TXE | __UART_CTL_UARTEN)
#endif

#endif
