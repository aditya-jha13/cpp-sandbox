#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[2][3] = {{1,2,3},{4,5,6}};
    // if array is arr[m][n]
    cout << a[0]+3 << "  " << a[1]<<endl; // Same output
    cout << a[0]<< "  " << *a<<endl; // Unlike 1D array, where a[0] is an integer. Here a[0] is a pointer to the first size 3 array.
    cout << a[0][0] << "  "<< **a << endl;
    // cout << **(a+1) << "  " << *(*a+1) << endl; // 4 2 | *a+1 can be written as (a[0] + 1) or *a[0][1] and *(*a + 1) as a[0][1]
    
    // array of integer pointers of size 3
    int (*p)[3] = a; // Here, p is a pointer to an int array of size 3.
    
    cout << **(p+1) << endl;
    return 0;
}
