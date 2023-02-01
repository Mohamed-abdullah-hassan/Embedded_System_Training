//  Using Vendor supplied definitions 

#include "tm4c123gh6pm.h"

// Note that in the header file the register definition be like
//#define GPIO_PORTF_DATA_R       (*((volatile uint32_t *)0x400253FC))
//take note that "uint32_t" is same as "unsigned int"
//also for safe practice a volatile keyword is added also which is used to instruct the compiler not to optimize the code for this data
//As some compilers tends to remove the instruction if it finds that its allways write or read or might replace it with a constant to save some code
//So Adding volatile tells that this variable can be changed outside the compiler knnow.


int main()
{
  
    unsigned int delay =0;  //A varible to hold a value for simple delay function.
    SYSCTL_RCGCGPIO_R = 0x00000020U;
    GPIO_PORTF_DIR_R = 0x0EU;
    GPIO_PORTF_DEN_R = 0x0EU;
    // GPIO_PORTF_DATA_R = 0x02U;
    // GPIO_PORTF_DATA_R = 0x04U;
    // GPIO_PORTF_DATA_R = 0x08U;
    while(1)
    {
        GPIO_PORTF_DATA_R = 0x0EU;
        while (delay <4000000) delay++;    //Make some delay for visualy notice the blinking
        delay =0;
        GPIO_PORTF_DATA_R = 0x00U;
        while (delay <4000000) delay++;    //Another delay...
        delay =0;
        GPIO_PORTF_DATA_R = 0x0EU;
    }
     return 0;
}
