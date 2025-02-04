#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

// here i can pass int A[] or int* A as a parameter -  stores the starting address of the array
int sumofelements(int* A,int size)
{
    int sum = 0;
    for(int i = 0;i<size;i++)
    {
        sum+=*A;
        A++;
    }
    return sum;
}
int main()
{
    int a[] = {1,2,3,4,5};
    int size = sizeof(a)/sizeof(a[0]);
    int total = sumofelements(a,size);
    cout << total;
    return 0;
}
