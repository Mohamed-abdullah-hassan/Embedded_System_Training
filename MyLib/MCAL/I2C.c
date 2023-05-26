#include "I2C.h"
//#include <stdint.h>



void I2C_Init ( void )
{
    float y = I2C_TIMER_PERIOD;
    int x = I2C_TIMER_PERIOD;
    if (x== y) x--;

// Enable the clock for GPIO Port
SYSCTL->RCGCGPIO  |= I2C_GPIO_RCGC_EN ; 

// Enable the clock for I2C 
SYSCTL->RCGCI2C   |= I2C_NUMBER ; 

// Configure DEN for GPIO Port
I2C_GPIO_PORT->DEN |= ( I2C_GPIO_SCL_PIN | I2C_GPIO_SDA_PIN ); 

// Configure GPIO Port for I2C Pins SCL and SDA
I2C_GPIO_PORT->AFSEL |= ( I2C_GPIO_SCL_PIN | I2C_GPIO_SDA_PIN ) ;
I2C_GPIO_PORT->PCTL |= I2C_GPIO_PCTL_SET ;

// Set SDA pin as open darin
I2C_GPIO_PORT->ODR |= I2C_GPIO_SDA_PIN ;

// Enable I2C master function
I2C_BLOCK->MCR  = 0x0010; 


/* Configure I2C clock frequency (TIME_PERIOD ) = ((SYS_CLK /(2*( SCL_LP + SCL_HP ) * I2C_CLK_Freq )) -1)*/
I2C_BLOCK->MTPR  = x ;
}


// Start a  Master multiple data write
unsigned int I2C_Multi_Write_Start(unsigned char slave_address,unsigned char data )
{
    while(I2C_BLOCK->MCS & (0b00000001));  // Check I2C is busy
    while(I2C_BLOCK->MCS & (0b01000000)); // Check if I2C Bus is Busy
    if(I2C_BLOCK->MCR & 0b00000010) return (I2C_BLOCK->MCR);  // Check if ther was any error during last operation
    I2C_BLOCK->MSA  = ((slave_address) << 1) ;
    I2C_BLOCK->MDR  = data;
    I2C_BLOCK->MCS  = 0b00011; // Generate Start condition + Enable I2C Master 
    return 0;
}

// send another data in multiple data write
unsigned int I2C_Multi_Write(unsigned char data )
{
    while(I2C_BLOCK->MCS & (0b00000001));  // Check I2C is busy
    if(I2C_BLOCK->MCS & 0b00000010) return (I2C_BLOCK->MCR);  // Check if ther was any error during last operation
    I2C_BLOCK->MDR  = data;
    I2C_BLOCK->MCS  = 0b00001; // Enable I2C Master Transmition 
    return 0;
}

// send a last byte of data in multiple data write and generate stop condition
unsigned int I2C_Multi_Write_Stop(unsigned char data )
{
    while(I2C_BLOCK->MCS & (0b00000001));  // Check I2C is busy
    if(I2C_BLOCK->MCS & 0b00000010) return (I2C_BLOCK->MCR);  // Check if ther was any error during last operation
    I2C_BLOCK->MDR  = data;
    I2C_BLOCK->MCS  = 0b00101; // Enable I2C Master Transmition and generate stop condition
    while(I2C_BLOCK->MCS & 1);  //There is aneed to insert some delay still don't understand the reason but propably due to mcu re init the start condition as soon as the stop condition finishes.
    return I2C_BLOCK->MCS & 0xE; 
}

// Start sending a byte of data and generate stop condition
unsigned int I2C_Write(unsigned char slave_address,unsigned char data )
{
    while(I2C_BLOCK->MCR & (0b00000001));  // Check I2C is busy
    if(I2C_BLOCK->MCR & 0b00000010) return (I2C_BLOCK->MCR);  // Check if ther was any error during last operation
    I2C_BLOCK->MSA  = ((slave_address & 0x7F) << 1) ;
    I2C_BLOCK->MDR  = data;
    while(I2C_BLOCK->MCR & (0b01000000)); // Check if I2C Bus is Busy
    I2C_BLOCK->MCS  = 0b00111; // Generate Start condition + Enable I2C Master + Genrate Stop condition
    while(I2C_BLOCK->MCS & 1);
    return 0;
}

unsigned char I2C_get_Status(void)
{
    return I2C_BLOCK->MCS;
}
