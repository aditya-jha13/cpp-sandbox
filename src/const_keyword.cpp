#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl

using String = std::string;

class Entity
{
private:
    String m_Name;
    mutable int count=0; // func.() const - can allow the changes to happen to the mutable class attributes.
public:
    Entity(): m_Name("Unknown"){};
    Entity(const String& name): m_Name(name){};

    const String& getName() const {return m_Name;} // cannot modify any class attributes because const is present after func. name

    const String& setName(const String& name) const {
        count++;
        return m_Name;
    
    } // here, we can modify the class attributes, cant modify the pointer address (2nd const) as well as the contents of the pointers
};

int main()
{
    const int a = 8;
    // a=8; cannot do this.
    int* b = new int;
    b = (int*)&a; // casting the const int to int

    const int* c = new int;
    //*c = 10; // cannot do this
    //BUT
    c = b; // can make the pointer address change.

    int* const d = new int; // here i can change the value the pointer points to but cannot update the pointer address
    const int* const d = new int; // cannot change anything
}