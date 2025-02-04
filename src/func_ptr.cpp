#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
void Func(int value)
{
    cout << "Hello World" << value << endl;
}
void ForEach(vector<int>& values, void(*func)(int value)) // This function takes a function pointer as an argument and performs that function steps to each of the entries.
{
    for (int i: values)
    {
        func(i);
    }
}
int main()
{
    // typedef void(*FuncType)(int value);
    // FuncType func = Func; // here func is the function pointer to Func()
    // func(10);
    // func(11);

    vector<int> values = {1,2,3,4,5};
    ForEach(values,[](int value){cout << "Value: "<< value;}); // here we have used lambda functions 
    return 0;
}