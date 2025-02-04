// The only difference between the primitive data types is THEIR SIZE.
#include <iostream>
using namespace std;
int main()
{
    int a; // Only 31 bits available, 1 bit is for the sign - we have total of 2^32 options available.
    unsigned int b; // Here we have 32 bits available as it is always positive. Total values we have 2^32. [0,2^32-1]

    // Integer Datatypes
    // char, int, long, long long - 1,4,8,16 bytes of memory (ALSO, n bits store 2^n -1 numbers, think GP)

    // Float Datatypes
    // float, double - 4,8 bytes

    //Bool Datatypes - to store boolean variables, we only need one bit of data but because we cannot access one bit in memory - we store it in a byte.
    cout << sizeof(double)<<endl; //prints 8
}