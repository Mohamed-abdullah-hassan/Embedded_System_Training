

unsigned int myFunc(void);       // It's important to declare the function for using
unsigned int value=0;
unsigned int ans=0;

int main (void)
{
    value = myFunc();
    ans = (value + 222) * (152 + myFunc());


    return 0;
}
