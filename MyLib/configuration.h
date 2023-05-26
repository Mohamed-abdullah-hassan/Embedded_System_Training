#include "TM4C123.h"
#ifndef		__CONFIGURATION__
#define		__CONFIGURATION__


#define __SYSTEM_CLOCK      50000000

//////////////////////////////////////////////////////
// System Peripheral implementation
/////////////////////////////////////////////////////
#define __DEFINE_USE_SSI
#define __DEFINE_USE_UART
#define __DEFINE_USE_I2c      











//////////////////////////////////////////////////////////
//                Peripheral setup                      //
//////////////////////////////////////////////////////////


  /////////////////////////
 //     SSI setup       //
/////////////////////////
#ifdef      __DEFINE_USE_SSI
#include "MCAL/SSI.h"

//SSI Configuration
//#define     __SSI_ENABLE_FSS_PIN    
#define     __SSI_SERIAL_CLOCK_RATE     0X0
#define     __SSI_CLK_PRESCALE          0X2

//#define     __SSI_CLOCK_PHASE_0
 #define     __SSI_CLOCK_PHASE_1

//#define     __SSI_CLOCK_POL_0
#define     __SSI_CLOCK_POL_1

#define     __SSI_MODE_FREESCALE
// #define     __SSI_MODE_TI
// #define     __SSI_MODE_MICROWIRE

// #define     __SSI_DATA_SIZE_4bit
// #define     __SSI_DATA_SIZE_5bit
// #define     __SSI_DATA_SIZE_6bit
// #define     __SSI_DATA_SIZE_7bit
#define     __SSI_DATA_SIZE_8bit
// #define     __SSI_DATA_SIZE_9bit
// #define     __SSI_DATA_SIZE_10bit
// #define     __SSI_DATA_SIZE_11bit
// #define     __SSI_DATA_SIZE_12bit
// #define     __SSI_DATA_SIZE_13bit
// #define     __SSI_DATA_SIZE_14bit
// #define     __SSI_DATA_SIZE_15bit
// #define     __SSI_DATA_SIZE_16bit

//#define     __SSI_END_OF_TX_0
#define     __SSI_END_OF_TX_1
#define     __SSI_MASTER
// #define     __SSI_SLAVE
#define     __SSI_PORT_EN     
// #define     __SSI_LOOPBACK_EN   


//////////
// SSI Module Selector
//////////
//#define			__USE_SSI0
//#define			__USE_SSI1_PF
//#define			__USE_SSI1_PD
//#define			__USE_SSI2
//#define			__USE_SSI3



// SSI Functions
void SSI_Init (void);
void SSI_Send(unsigned char data);
void SSI_Send_Multi(unsigned char *buffer, unsigned char size);
void SSI_Send_Fast(unsigned char data);
#endif
//////////////////////////////////////


  /////////////////////////
 //     I2C setup       //
/////////////////////////
#ifdef      __DEFINE_USE_I2c
#include "MCAL/I2C.h"

// I2C Bus speed Mode
//  #define __I2C_STANDARD_100K   //   100 Kbps
#define __I2C_FAST_400K       //   400 Kbps
// #define __I2C_FAST_PLUS_1M    //  1000 Kbps
// #define __I2C_HIGH_3M3        //  3300 Kbps



// I2C Module Selector
// #define		__USE_I2c0
// #define		__USE_I2c1
// #define		__USE_I2c2
#define		__USE_I2c3

void I2C_Init ( void );
unsigned int I2C_Multi_Write_Start(unsigned char ,unsigned char  );
unsigned int I2C_Multi_Write(unsigned char  );
unsigned int I2C_Multi_Write_Stop(unsigned char  );
unsigned int I2C_Write(unsigned char slave_address,unsigned char data );
unsigned char I2C_get_Status(void);

#endif
//////////////////////////////////////

  /////////////////////////
 //     UART setup      //
/////////////////////////

#ifdef      __DEFINE_USE_UART
#include "MCAL/uart.h"

// UART Baud Rate selector
#define		__UART_BAUD_RATE		9600

// UART Word Length selector
//#define		__UART_WORD_5bit
//#define		__UART_WORD_6bit
//#define		__UART_WORD_7bit
#define		__UART_WORD_8bit

// UART Enable 2 Stop Bits
//#define		__UART_2_STOP_Bits

//UART Setup
#define		__UART_EN_FIFO
#define		__UART_EN_RX
#define		__UART_EN_TX

/// UART Module Selectro
//#define			__USE_UART0
//#define		__USE_UART1_PORTB           
//#define		__USE_UART1_PORTC
//#define		__USE_UART2
//#define		__USE_UART3
//#define		__USE_UART4
//#define		__USE_UART5
//#define		__USE_UART6
#define		__USE_UART7

// UART function Decleration
void UART_Init(void);
void UART_Write(unsigned char);
#endif


#endif

