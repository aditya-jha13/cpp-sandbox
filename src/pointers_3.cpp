#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void print(char* c)
{
    // int i = 0;
    while(*c != '\0')
    {
        cout<<*c;
        c++;
    }
    printf("\n");

}
int main()
{
    char c1[6] = "Hello";
    // char* acts like a string and not address.
    char* c2 = c1;
    cout << c2<<"."<<c1[1];

    print(c1);
    return 0;
}