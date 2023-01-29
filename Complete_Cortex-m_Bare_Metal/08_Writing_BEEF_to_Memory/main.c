

int main ()
{
    int *pt;                     //Declaring a pointer pt

    pt = (int *) (0x20000014U); // Placing the memory address 0x20000014 on pointer
                                // Note adding (int *) before the address to type cast it meanning that the following
                                //value will be a memory location of type int.
                                // Also adding U in the end of the hexadicemal value instructs the compiler to treat it 
                                //as unsigned value.

    *pt = 0x0000BEEF;           // Place the hex value 0x0000BEEF in decimal (48879) in the memory location pointed by pt


    return 0;
}
