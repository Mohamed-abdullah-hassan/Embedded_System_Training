//Implemntation of pointers in C programming language


//Add counter to watch window to see that its increment using pt pointer
int counter = 0;

int main ()
{
	int *pt;        //Declars a pointer to an int variable

	pt = &counter;  // Assignning the pointer pt to counter address
					// Note that when assinning the * is removed which means that the pt content holds the address of counter
					// Also adding & befor counter means that it will pass the address of the variable in memory insted of its content

	while (*pt <8)  //Adding * to pt means that memory location pt holding it address.
	{
		++(*pt);
		// if(counter ==8)
		// {
		// 	counter =0;
			
		// }
	}
	return 0;
}
