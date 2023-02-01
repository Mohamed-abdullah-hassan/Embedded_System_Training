// Giving names for  address pointer

#define     Clock_Reg       (*((unsigned int *) 0x400FE608U))
#define     Dir_Reg         (*((unsigned int *) 0x40025400U))
#define     En_Reg          (*((unsigned int *) 0x4002551CU))
#define     Data_Reg        (*((unsigned int *) 0x400253FCU))
int main()
{
  
    unsigned int delay =0;  //A varible to hold a value for simple delay function.
    Clock_Reg = 0x00000020U;
    Dir_Reg = 0x0EU;
    En_Reg = 0x0EU;
    // Data_Reg = 0x02U;
    // Data_Reg = 0x04U;
    // Data_Reg = 0x08U;
    while(1)
    {
        Data_Reg = 0x0EU;
        while (delay <4000000) delay++;    //Make some delay for visualy notice the blinking
        delay =0;
        Data_Reg = 0x00U;
        while (delay <4000000) delay++;    //Another delay...
        delay =0;
        Data_Reg = 0x0EU;
    }
     return 0;
}
