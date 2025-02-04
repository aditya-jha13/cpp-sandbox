#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main()
{
    // If I want to iterate through all the bytes of an int, i can define a char* pointer and point it to the int.
    // prints - 1 4 0 0 -  starts from right to left.
    // 00000000 00000000 00000100 00000001
    int a = 1025;
    int *p = &a;
    char* c;
    c = (char*)p;
    int i=0;
    for(i=0;i<4;i++)
    {
        cout << (int)*(c+i)<<endl;
    }
    return 0;
}
