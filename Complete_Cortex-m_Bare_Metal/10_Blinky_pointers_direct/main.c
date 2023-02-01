// Using Direct address to place value into memory
// placing an address between *( ) convert it to be direct pointer  like *(pt)
// Then inserting Type casted value for the compiler to accept.  

int main()
{
  
    unsigned int delay =0;  //A varible to hold a value for simple delay function.
    *((unsigned int *) 0x400FE608U) = 0x00000020U;
    *((unsigned int *) 0x40025400U) = 0x0EU;
    *((unsigned int *) 0x4002551CU) = 0x0EU;


    // *((unsigned int *) 0x400253FCU) = 0x02U;
    // *((unsigned int *) 0x400253FCU) = 0x04U;
    // *((unsigned int *) 0x400253FCU) = 0x08U;
    *((unsigned int *) 0x400253FCU) = 0x0EU;

    while(1)
    {
        delay =0;
        while (delay <4000000) delay++;    //Make some delay for visualy notice the blinking
        *((unsigned int *) 0x400253FCU) = 0x00U;
        delay =0;
        while (delay <4000000) delay++;    //Another delay...
        *((unsigned int *) 0x400253FCU) = 0x0EU;
    }
     return 0;
}
