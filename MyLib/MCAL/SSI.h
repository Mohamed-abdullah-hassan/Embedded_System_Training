#ifndef		__SSI_CONFIGURATION__
	#define		__SSI_CONFIGURATION__
	#include "../configuration.h"
	#if     defined(__DEFINE_USE_SSI)
		#if			defined(__USE_SSI0)
 			//SSI_0	PMCn = 2
			//CLK= PA2  RX=PA4 TX=PA5 SS=PA3
            #define		SSI_NUMBER				1<<0
            #define		SSI_GPIO_PORT			GPIOA
            #define		SSI_GPIO_RCGC_EN		1<<0
            #define		SSI_GPIO_CLK_PIN		1<<2
            #define		SSI_GPIO_RX_PIN			1<<4
            #define		SSI_GPIO_TX_PIN			1<<5
            #define		SSI_GPIO_SS_PIN			1<<3
            #define		SSI_GPIO_CLK_PCTL_MSK	~0X00000F00
            #define		SSI_GPIO_RX_PCTL_MSK	~0X000F0000
            #define		SSI_GPIO_TX_PCTL_MSK	~0X00F00000
            #define		SSI_GPIO_SS_PCTL_MSK	~0X0000F000
            #define		SSI_GPIO_CLK_PCTL_SET	 0X00222200
            #define		SSI_GPIO_RX_PCTL_SET	 0X00222200
            #define		SSI_GPIO_TX_PCTL_SET	 0X00222200
            #define		SSI_GPIO_SS_PCTL_SET	 0X00222200			
            #define		SSI_BLOCK				SSI0

		#elif		defined(__USE_SSI1_PF)
			//SSI_1_PF	PMCn = 2
			//CLK= PF2  RX=PF0 TX=PF1 SS=PF3
            #define		SSI_NUMBER				1<<1
            #define		SSI_GPIO_PORT			GPIOF
            #define		SSI_GPIO_RCGC_EN		1<<5
            #define		SSI_GPIO_CLK_PIN		1<<2
            #define		SSI_GPIO_RX_PIN			1<<0
            #define		SSI_GPIO_TX_PIN			1<<1
            #define		SSI_GPIO_SS_PIN			1<<3
			#define		SSI_GPIO_CLK_PCTL_MSK	~0X00000F00
			#define		SSI_GPIO_RX_PCTL_MSK	~0X0000000F
			#define		SSI_GPIO_TX_PCTL_MSK	~0X000000F0
			#define		SSI_GPIO_SS_PCTL_MSK	~0X0000F000
			#define		SSI_GPIO_CLK_PCTL_SET	 0X00000200
			#define		SSI_GPIO_RX_PCTL_SET	 0X00000002
			#define		SSI_GPIO_TX_PCTL_SET	 0X00000020
			#define		SSI_GPIO_SS_PCTL_SET	 0X00002000
            #define		SSI_BLOCK				SSI1

		#elif		defined(__USE_SSI1_PD)
			//SSI_1_PD	PMCn = 2
			//CLK= PD0  RX=PD2 TX=PD3 SS=PD1
            #define		SSI_NUMBER				1<<1
            #define		SSI_GPIO_PORT			GPIOD
            #define		SSI_GPIO_RCGC_EN		1<<3
            #define		SSI_GPIO_CLK_PIN		1<<0
            #define		SSI_GPIO_RX_PIN			1<<2
            #define		SSI_GPIO_TX_PIN			1<<3
            #define		SSI_GPIO_SS_PIN			1<<1
			#define		SSI_GPIO_CLK_PCTL_MSK	~0X0000000F
			#define		SSI_GPIO_RX_PCTL_MSK	~0X00000F00
			#define		SSI_GPIO_TX_PCTL_MSK	~0X0000F000
			#define		SSI_GPIO_SS_PCTL_MSK	~0X000000F0
			#define		SSI_GPIO_CLK_PCTL_SET	 0X00000002
			#define		SSI_GPIO_RX_PCTL_SET	 0X00000200
			#define		SSI_GPIO_TX_PCTL_SET	 0X00002000
			#define		SSI_GPIO_SS_PCTL_SET	 0X00000020
            #define		SSI_BLOCK				SSI1

		#elif		defined(__USE_SSI2)
			//SSI_2	PMCn = 2
			//CLK= PB4  RX=PB6 TX=PB7 SS=PB5
            #define		SSI_NUMBER				1<<2
            #define		SSI_GPIO_PORT			GPIOB
            #define		SSI_GPIO_RCGC_EN		1<<1
            #define		SSI_GPIO_CLK_PIN		1<<4
            #define		SSI_GPIO_RX_PIN			1<<6
            #define		SSI_GPIO_TX_PIN			1<<7
            #define		SSI_GPIO_SS_PIN			1<<5
			#define		SSI_GPIO_CLK_PCTL_MSK	~0X000F0000
			#define		SSI_GPIO_RX_PCTL_MSK	~0X0F000000
			#define		SSI_GPIO_TX_PCTL_MSK	~0XF0000000
			#define		SSI_GPIO_SS_PCTL_MSK	~0X00F00000
			#define		SSI_GPIO_CLK_PCTL_SET	 0X00020000
			#define		SSI_GPIO_RX_PCTL_SET	 0X02000000
			#define		SSI_GPIO_TX_PCTL_SET	 0X20000000
			#define		SSI_GPIO_SS_PCTL_SET	 0X00200000
            #define		SSI_BLOCK				SSI2

		#elif		defined(__USE_SSI3)
			//SSI_3	PMCn = 1
			//CLK= PD0  RX=PD2 TX=PD3 SS=PD1
            #define		SSI_NUMBER				1<<3
            #define		SSI_GPIO_PORT			GPIOD
            #define		SSI_GPIO_RCGC_EN		1<<3
            #define		SSI_GPIO_CLK_PIN		1<<0
            #define		SSI_GPIO_RX_PIN			1<<2
            #define		SSI_GPIO_TX_PIN			1<<3
            #define		SSI_GPIO_SS_PIN			1<<1
            #define		SSI_GPIO_CLK_PCTL_MSK	~0X0000000F
			#define		SSI_GPIO_RX_PCTL_MSK	~0X00000F00
			#define		SSI_GPIO_TX_PCTL_MSK	~0X0000F000
			#define		SSI_GPIO_SS_PCTL_MSK	~0X000000F0
			#define		SSI_GPIO_CLK_PCTL_SET	 0X00000001
			#define		SSI_GPIO_RX_PCTL_SET	 0X00000100
			#define		SSI_GPIO_TX_PCTL_SET	 0X00001000
			#define		SSI_GPIO_SS_PCTL_SET	 0X00000010
            #define		SSI_BLOCK				SSI3

		#endif

		#define 	__SSI_SCR			((__SSI_SERIAL_CLOCK_RATE & 0xFF)<<8)

		#if (defined(__SSI_CLOCK_PHASE_0))
			#define __SSI_SPH			0
		#elif (defined(__SSI_CLOCK_PHASE_1))
			#define __SSI_SPH			1<<7
		#else
			#define	__SSI_SPH			0
//			#warning Please Select one Clock Phase using default SPH = 0
		#endif

		#if (defined(__SSI_CLOCK_POL_0))
			#define __SSI_SPO			0
		#elif (defined(__SSI_CLOCK_POL_1))
			#define __SSI_SPO			1<<6
		#else
			#define	__SSI_SPO			0
//			#warning Please Select one Clock Polarity diverting to SPO = 0
		#endif

		#if (defined(__SSI_MODE_FREESCALE))
			#define __SSI_FRF			0
		#elif (defined(__SSI_MODE_TI))
			#define __SSI_FRF			1<<4
		#elif (defined(__SSI_MODE_MICROWIRE))
			#define __SSI_FRF			2<<4
		#else
			#define	__SSI_FRF			0
//			#warning Please Select SSI Frame Format to FRF = Freescale
		#endif

		#if (defined(__SSI_DATA_SIZE_8bit))  // Making the default to 8-bit in case some other is selected
			#define __SSI_DSS			0X07
		#elif (defined(__SSI_DATA_SIZE_4bit))
			#define __SSI_DSS			0x03
		#elif (defined(__SSI_DATA_SIZE_5bit))
			#define __SSI_DSS			0X04
		#elif (defined(__SSI_DATA_SIZE_6bit))
			#define __SSI_DSS			0X05
		#elif (defined(__SSI_DATA_SIZE_7bit))
			#define __SSI_DSS			0X06
		#elif (defined(__SSI_DATA_SIZE_9bit))
			#define __SSI_DSS			0X08
		#elif (defined(__SSI_DATA_SIZE_10bit))
			#define __SSI_DSS			0X09
		#elif (defined(__SSI_DATA_SIZE_11bit))
			#define __SSI_DSS			0X0A
		#elif (defined(__SSI_DATA_SIZE_12bit))
			#define __SSI_DSS			0X0B
		#elif (defined(__SSI_DATA_SIZE_13bit))
			#define __SSI_DSS			0X0C
		#elif (defined(__SSI_DATA_SIZE_14bit))
			#define __SSI_DSS			0X0D
		#elif (defined(__SSI_DATA_SIZE_15bit))
			#define __SSI_DSS			0X0E
		#elif (defined(__SSI_DATA_SIZE_16bit))
			#define __SSI_DSS			0X0F
		#else
			#define	__SSI_FRF			0
//			#warning Please Select SSI Frame Format to DSS = 8-Bit
		#endif

		#if (defined(__SSI_END_OF_TX_0))
			#define __SSI_EOT			0
		#elif (defined(__SSI_END_OF_TX_1))
			#define __SSI_EOT			1<<4
		#else
			#define	__SSI_EOT			0
//			#warning Please Select SSI End of transmition default to EOT = OFF
		#endif

		#if (defined(__SSI_MASTER))
			#define __SSI_MS			0
		#elif (defined(__SSI_SLAVE))
			#define __SSI_MS			1<<2
		#else
			#define	__SSI_MS			0
//			#warning Please Select SSI Master/Slave default to MS = Master
		#endif
		
		#if (defined(__SSI_PORT_EN))
			#define __SSI_SSE			1<<1
		#else
			#define	__SSI_SSE			0
		#endif

		#if (defined(__SSI_LOOPBACK_EN))
			#define __SSI_LBM			1
		#else
			#define	__SSI_LBM			0
		#endif

		#if					defined(__SSI_ENABLE_FSS_PIN)
			#define 	SSI_GPIO_PCTL_MSK				(SSI_GPIO_CLK_PCTL_MSK | SSI_GPIO_RX_PCTL_MSK | SSI_GPIO_TX_PCTL_MSK | SSI_GPIO_SS_PCTL_MSK)
			#define 	SSI_GPIO_PCTL_SET		(SSI_GPIO_CLK_PCTL_SET | SSI_GPIO_RX_PCTL_SET | SSI_GPIO_TX_PCTL_SET | SSI_GPIO_SS_PCTL_SET)
			#define		SSI_GPIO_PINS						(SSI_GPIO_CLK_PIN 		 | SSI_GPIO_RX_PIN      | SSI_GPIO_TX_PIN      | SSI_GPIO_SS_PIN     )
		#else
			#define 	SSI_GPIO_PCTL_MSK				(SSI_GPIO_CLK_PCTL_MSK | SSI_GPIO_RX_PCTL_MSK | SSI_GPIO_TX_PCTL_MSK)
			#define 	SSI_GPIO_PCTL_SET				(SSI_GPIO_CLK_PCTL_SET | SSI_GPIO_RX_PCTL_SET | SSI_GPIO_TX_PCTL_SET)
			#define		SSI_GPIO_PINS					(SSI_GPIO_CLK_PIN 	   | SSI_GPIO_RX_PIN      | SSI_GPIO_TX_PIN     )
		#endif
		
		#define		__SSI_CR0_VALUE			(__SSI_SCR | __SSI_SPH | __SSI_SPO | __SSI_FRF | __SSI_DSS  )
		#define 	__SSI_CR1_VALUE			(__SSI_EOT | __SSI_MS  | __SSI_LBM )
		#define		__SSI_CPSDVSR			(__SSI_CLK_PRESCALE & 0XFF)
		
		#define 	__SSI_SR_BSY__				1<<5
		#define		__SSI_SR_TNF__				1<<1

	#endif
#endif


/*
==============================================================================================================================
|| Module		|    Pin		| Pin		| GPIO Pin	|   PMCn	|   Type	| Compata	| Description					||
||  Name		|    Name		| Number	|    Name	|			|			|	bility	|								||
||--------------------------------------------------------------------------------------------------------------------------||
||	SSI_0		|	SSI0Clk		|	19		|	PA2		|	(2)		|	I/O		|	TTL		|	SSI module 0 clock			||
||				|	SSI0Fss		|	20		|	PA3		|	(2)		|	I/O		|	TTL		|	SSI module 0 frame signal	||
||				|	SSI0Rx		|	21		|	PA4		|	(2)		|	I		|	TTL		|	SSI module 0 receive		||
||				|	SSI0Tx		|	22		|	PA5		|	(2)		|	O		|	TTL		|	SSI module 0 transmit		||
||--------------|---------------|-----------|-----------|-----------|-----------|-----------|-------------------------------||
||	SSI_1_PF	|	SSI1Clk		|	30		|	PF2		|	(2)		|	I/O		|	TTL		|	SSI module 1 clock.			||
||				|	SSI1Fss		|	31		|	PF3		|	(2)		|	I/O		|	TTL		|	SSI module 1 frame signal.	||
||				|	SSI1Rx		|	28		|	PF0		|	(2)		|	I		|	TTL		|	SSI module 1 receive.		||
||				|	SSI1Tx		|	29		|	PF1		|	(2)		|	O		|	TTL		|	SSI module 1 transmit.		||
||--------------|---------------|-----------|-----------|-----------|-----------|-----------|-------------------------------||
||	SSI_1_PD	|	SSI1Clk		|	61		|	PD0		|	(2)		|	I/O		|	TTL		|	SSI module 1 clock.			||
||				|	SSI1Fss		|	62		|	PD1		|	(2)		|	I/O		|	TTL		|	SSI module 1 frame signal.	||
||				|	SSI1Rx		|	63		|	PD2		|	(2)		|	I		|	TTL		|	SSI module 1 receive.		||  
||				|	SSI1Tx		|	64		|	PD3		|	(2)		|	O		|	TTL		|	SSI module 1 transmit.		||
||--------------|---------------|-----------|-----------|-----------|-----------|-----------|-------------------------------||
||	SSI_2		|	SSI2Clk		|	58		|	PB4		|	(2)		|	I/O		|	TTL		|	SSI module 2 clock.			||
||				|	SSI2Fss		|	57		|	PB5		|	(2)		|	I/O		|	TTL		|	SSI module 2 frame signal.	||
||				|	SSI2Rx		|	1		|	PB6		|	(2)		|	I		|	TTL		|	SSI module 2 receive.		||
||				|	SSI2Tx		|	4		|	PB7		|	(2)		|	O		|	TTL		|	SSI module 2 transmit.		||
||--------------|---------------|-----------|-----------|-----------|-----------|-----------|-------------------------------||
||	SSI_3		|	SSI3Clk		|	61		|	PD0		|	(1)		|	I/O		|	TTL		|	SSI module 3 clock.			||
||				|	SSI3Fss		|	62		|	PD1		|	(1)		|	I/O		|	TTL		|	SSI module 3 frame signal.	||
||				|	SSI3Rx		|	63		|	PD2		|	(1)		|	I		|	TTL		|	SSI module 3 receive.		||
||				|	SSI3Tx		|	64		|	PD3		|	(1)		|	O		|	TTL		|	SSI module 3 transmit.		||
==============================================================================================================================
*/
