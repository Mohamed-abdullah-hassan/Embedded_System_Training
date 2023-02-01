// Imlementation of structures in C
// Keywords "struct" "typedef"


// Defining a struct to store data of reading of speed sensor which is represented by ammount of count in defiend time slots 
// "Count" represent how many counts recived
// "time_division_ms" represents how much is the time division
// "tooth" represents how many teeth in the flywheel for on turn.

// Structures is a tool to group related data in a single memory block 
// structures can hold any data types like int short double float char string pointers arrays

/*
// Method 1
struct __speed{
    unsigned int count;
    unsigned int time_division_ms;
    unsigned short tooth;
};
// To declare a variable "wheel" from ther structure __speed
struct __speed wheel;
*/

/*
// Method 2
struct __speed{
    unsigned int count;
    unsigned int time_division_ms;
    unsigned short tooth;
} wheel;
// this declare a variable "wheel" from ther structure __speed

*/

/*
// Method 3
struct {
    unsigned int count;
    unsigned int time_division_ms;
    unsigned short tooth;
} wheel;
*/

/*
// Method 4  Using typedef
struct __speed{
    unsigned int count;
    unsigned int time_division_ms;
    unsigned short tooth;
};
typedef struct __speed spped_struc
spped_struc wheel;
*/


// Method 6  Using typedef
typedef struct {
    unsigned int count;
    unsigned int time_division_ms;
    unsigned short tooth;
} spped_struc;
spped_struc wheel;

// typedef can also used for normal decleration also

typedef unsigned int velocity;   //This defiens a new datatype with name velocity of type (unsigned int)

int main(void)
{
    wheel.tooth = 4;
    velocity x = wheel.count/wheel.tooth;


    return 0;
}
