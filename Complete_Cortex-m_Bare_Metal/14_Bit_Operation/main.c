//  Bit wise operation for registers manupulation
#include "tm4c123gh6pm.h"

// The C language has some bit operation which is important for data processing
// & And operator
// | OR operator
// ^ EOR operator "Exclosve OR"
// ~ NOT operator "Invert"
// >> Rotate Roght
// << Rotate Left 


#define     LED_RED     0x02U
#define     LED_BLUE    0x04U
#define     LED_GREEN   0x08U


int main()
{
    unsigned short count =0;  
    unsigned int delay =0;  //A varible to hold a value for simple delay function.
    SYSCTL_RCGCGPIO_R = 0x00000020U;
    GPIO_PORTF_DIR_R = 0x0EU;
    GPIO_PORTF_DEN_R = 0x0EU;

    GPIO_PORTF_DATA_R = LED_RED;
    
    while(1)
    {
        switch (count)
        {
        case 0:
            GPIO_PORTF_DATA_R = LED_RED;
            break;
        case 1:
            GPIO_PORTF_DATA_R = LED_BLUE;
            break;
        case 2:
            GPIO_PORTF_DATA_R = LED_GREEN;
            break;
        case 3:
            GPIO_PORTF_DATA_R |= LED_BLUE;
            break;
        case 4:
            GPIO_PORTF_DATA_R |= LED_RED;
            break;
        case 5:
            GPIO_PORTF_DATA_R &= ~(LED_GREEN);
            break;
        case 6:
            GPIO_PORTF_DATA_R = ((GPIO_PORTF_DATA_R &(~LED_BLUE))|(GPIO_PORTF_DATA_R | (LED_GREEN)));
            break;
        default:
            GPIO_PORTF_DATA_R = 0;
            break;
        }
        count++;
        if (count >7 ) count =0;
        delay =0;
        while (delay <1000000) delay++;    
    }
     return 0;
}
