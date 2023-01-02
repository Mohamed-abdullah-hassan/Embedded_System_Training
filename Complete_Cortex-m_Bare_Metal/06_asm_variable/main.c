// Demo for using external variable created by assembly file

extern unsigned int amount;             // Telling the compiler that there is a variable called "amount" which is created outside the c file and then defiening its datatype
unsigned int myFunc(void);


int main()
{
    unsigned int locVariable;
    amount = 0x1234567;
    myFunc();
    locVariable = amount;

    return 0;
}