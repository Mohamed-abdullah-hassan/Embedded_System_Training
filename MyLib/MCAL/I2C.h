//I2C pin in TM4C123gh6pm
//  Module    SCL     SDA   PMCn
//  I2C0	  PB2	  PB3    3
//  I2C1	  PA6	  PA7    3
//  I2C2	  PE4	  PE5    3
//  I2C3	  PD0	  PD1    3
//            Clock   Data
//SDA Pin must be configured to open drain using the GPIO Open Drain Select (GPIOODR) Page 649

#ifndef		__I2C_CONFIGURATION__
    #define		__I2C_CONFIGURATION__
    #include "../configuration.h"
    #ifdef    __DEFINE_USE_I2c

        #if 		defined(__USE_I2c0)
            //I2C0	  SCL = PB2	  SDA = PB3   PMCn 3
            #define		I2C_NUMBER				1<<0
            #define		I2C_GPIO_PORT			GPIOB
            #define		I2C_GPIO_RCGC_EN		1<<1
            #define		I2C_GPIO_SCL_PIN		1<<2
            #define		I2C_GPIO_SDA_PIN		1<<3
            #define		I2C_GPIO_PCTL_MASK		0XFF00
            #define		I2C_GPIO_PCTL_SET		0X3300
            #define		I2C_BLOCK				I2C0

        #elif		defined(__USE_I2c1)
            //I2C0	  SCL = PA6	  SDA = PA7   PMCn 3
            #define		I2C_NUMBER				1<<1
            #define		I2C_GPIO_PORT			GPIOA
            #define		I2C_GPIO_RCGC_EN		1<<0
            #define		I2C_GPIO_SCL_PIN		1<<6
            #define		I2C_GPIO_SDA_PIN		1<<7
            #define		I2C_GPIO_PCTL_MASK		0XFF000000
            #define		I2C_GPIO_PCTL_SET		0X33000000
            #define		I2C_BLOCK				I2C1

        #elif		defined(__USE_I2c2)
            //I2C0	  SCL = PE4	  SDA = PE5   PMCn 3
            #define		I2C_NUMBER				1<<2
            #define		I2C_GPIO_PORT			GPIOE
            #define		I2C_GPIO_RCGC_EN		1<<4
            #define		I2C_GPIO_SCL_PIN		1<<4
            #define		I2C_GPIO_SDA_PIN		1<<5
            #define		I2C_GPIO_PCTL_MASK		0XFF0000
            #define		I2C_GPIO_PCTL_SET		0X330000
            #define		I2C_BLOCK				I2C2

        #elif		defined(__USE_I2c3)
            //I2C0	  SCL = PD0	  SDA = PD1   PMCn 3
            #define		I2C_NUMBER				1<<3
            #define		I2C_GPIO_PORT			GPIOD
            #define		I2C_GPIO_RCGC_EN		1<<3
            #define		I2C_GPIO_SCL_PIN		1<<0
            #define		I2C_GPIO_SDA_PIN		1<<1
            #define		I2C_GPIO_PCTL_MASK		0XFF
            #define		I2C_GPIO_PCTL_SET		0X33
            #define		I2C_BLOCK				I2C3
            
        #endif


        // I2C Bus speed Mode
        #if defined(__I2C_STANDARD_100K)
            #define     __I2C_Kbps__        100000
        #elif defined(__I2C_FAST_400K)
            #define     __I2C_Kbps__        400000
        #elif defined(__I2C_FAST_PLUS_1M)
            #define     __I2C_Kbps__        1000000
        #elif defined(__I2C_HIGH_3M3)
            #define     __I2C_Kbps__        33000000
        #else
            #define     __I2C_Kbps__       100000
        #endif

        #define I2C_TIMER_PERIOD            (__SYSTEM_CLOCK/(2*(6.0+4.0)*__I2C_Kbps__))

    #endif

#endif

