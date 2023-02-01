// Using Original Nameming form the Datasheet

#define     RCGCGPIO        (*((unsigned int *) 0x400FE608U))
#define     GPIOF_DIR       (*((unsigned int *) 0x40025400U))
#define     GPIOF_DEN       (*((unsigned int *) 0x4002551CU))
#define     GPIOF_DATA      (*((unsigned int *) 0x400253FCU))
int main()
{
  
    unsigned int delay =0;  //A varible to hold a value for simple delay function.
    RCGCGPIO = 0x00000020U;
    GPIOF_DIR = 0x0EU;
    GPIOF_DEN = 0x0EU;
    // GPIOF_DATA = 0x02U;
    // GPIOF_DATA = 0x04U;
    // GPIOF_DATA = 0x08U;
    while(1)
    {
        GPIOF_DATA = 0x0EU;
        while (delay <4000000) delay++;    //Make some delay for visualy notice the blinking
        delay =0;
        GPIOF_DATA = 0x00U;
        while (delay <4000000) delay++;    //Another delay...
        delay =0;
        GPIOF_DATA = 0x0EU;
    }
     return 0;
}
