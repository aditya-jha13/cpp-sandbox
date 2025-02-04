#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl

using String = std::string;

class Entity
{
public:
    virtual String getName(){return "Entity";}
};

class Player: public Entity
{
    private:
        String m_Name;
    public:
        Player(const String& name): 
            m_Name(name){}
        String getName() override {return m_Name;} // override - its not neccesary to write it, just for the compile-time.
};

void Print(Entity& e)
{
    std::cout << e.getName() << std::endl;
}

int main()
{
    Entity* e = new Entity();
    Player* player = new Player("Player");
    Print(*e);
    Print(*player);
    delete player;
    delete e;
}