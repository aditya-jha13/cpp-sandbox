#include <iostream>
#include <string>
#include <memory>
#define LOG(x) std::cout << x << std::endl

using String = std::string;
using namespace std;

class Entity
{
public:
    Entity()
    {
        LOG("Object Created");
    }
    ~Entity()
    {
        LOG("Object Destroyed");
    }
    void Name(Entity& e)
    {

    }
};

int main()
{
    {
        unique_ptr<Entity> entity(new Entity()); // constructor is explicit.
        shared_ptr<Entity> ent = make_shared<Entity>();
        // ent->Name(entity); cannot do this
    }
}
