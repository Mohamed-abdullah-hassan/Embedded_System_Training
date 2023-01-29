//Blinking the LEDs ON and OFF for the TIVA C board using pointers

//Below is a table of used registers to enable port F and use the LEDs
//       Register           Base adress     offset
//  RCGCPIO address         0x400F.E000     0x608
//  GPIO DIR Port F         0x4002.5000     0x400
//  GPIO DEN Port F         0x4002.5000     0x51C
//  GPIO DATA Port F        0x4002.5000     0x3FC


int main()
{
    unsigned int delay =0;  //A varible to hold a value for simple delay function.
    unsigned int *pt;
    pt = (unsigned int *) 0x400FE608U;
    *pt = 0x00000020U;
    pt = (unsigned int *) 0x40025400U;
    *pt = 0x0EU;
    pt = (unsigned int *) 0x4002551CU;
    *pt = 0x0EU;
    pt = (unsigned int *) 0x400253FCU;
    // *pt = 0x02U;     //The value for the RED LED
    // *pt = 0x04U;     //Blue LED
    // *pt = 0x08U;     //Green LED
    *pt = 0x0EU;        //Turn All LED gives a white light

    while(1)
    {
        delay =0;
        while (delay <4000000) delay++;    //Make some delay for visualy notice the blinking
        *pt = 0x00U;
        delay =0;
        while (delay <4000000) delay++;    //Another delay...
        *pt = 0x0EU;
    }


    return 0;
}
