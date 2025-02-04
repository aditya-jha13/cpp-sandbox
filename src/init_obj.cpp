#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl

using String = std::string;

class Entity
{
private:
    String m_Name;
public:
    Entity(): m_Name("Unknown"){};
    Entity(const String& name): m_Name(name){};

    const String& getName() const {return m_Name;}
};

int main()
{
    Entity* e_h; Entity* e;

    {
        // Stack Allocation
        Entity entity("aditya");
        entity.getName();
        e = &entity;
        // Heap Allocation
        Entity* h_entity = new Entity("h_aditya");
        e_h = h_entity;
        (*h_entity).getName();
    }
    std::cout << e->getName() << std::endl; // its working is purely coincidental
    std::cout << e_h->getName() << std::endl;
    delete e_h; // VERY IMPORTANT!
    return 0;
}