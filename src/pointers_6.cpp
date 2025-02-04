#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[2][3][3]= {{{1,2,3},
                    {4,5,6},
                    {7,8,9}},
                    {{11,22,33},
                    {44,55,66},
                    {77,88,99}}};
    int (*p)[3][3] = a; // pointer to a 3*3 2D array
    cout << p << "|"<<*p<<"|"<<**p<<"|"<<***p<<endl;

    cout<< "address to 11:"<<&a[1][0][0]<<endl;
    cout << **(p+1) << "|" << *(**(p+1)+4)<<endl; // address to 11 | 55
    return 0;
}