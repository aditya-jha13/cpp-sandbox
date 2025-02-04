#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

int main()
{
    char a = 'a';
    char *p = &a;
    char* b = p+1;

    // C++ see char *p as strings and not pointers.
    // if we remove the casting and print the variables, it will print a string till '\n' is found.
    cout <<(void*)p<< endl;
    cout<<(void*)b<<endl;
    return 0;
}
