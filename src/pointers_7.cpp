#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
// we can allot memory for variables in heap when we want to access it outside of its scope in the main function. And later we should free the memory.
int *sum(int* a, int* b)
{
    int* c = (int*) malloc(sizeof(int)); // here, we allot the memory in heap so unless we deallocate it, we can access it.
    *c = *a + *b;
    return c;
}
int main()
{
    int a = 9; int b = 10;
    int* p = sum(&a,&b);
    
    cout << *p << endl;
    free(p);
    cout<<*p<<endl;
    return 0;
}