#include <iostream>
#define LOG(x) std::cout << x << std::endl

using namespace std;

class Entity
{
    public:
        Entity(float x,float y)
        {
            X = x;
            Y = y;
        }
        float X,Y;
        void Move(float xa,float ya)
        {
            X += xa;
            Y += ya;
        }
};

class Player: public Entity // Now Player class inherits all the public attributes of the Entity Class. Entity class is the BASE class and Player class is the SUPER class.
{
    public: 
        Player(int x,int y,const char* name): Entity(x,y), name(name) {} // Initialiser List - a faster way of init. Neccesary for static member, base class init and references. 

        const char* name;
        void PrintName()
        {
            LOG(name);
        }
        void PrintPos()
        {
            LOG("PRINTING POSITION");
            LOG(X);
            LOG(Y);
        }
};

int main()
{
    Player player(2.,3.,"aditya");
    player.PrintName();
    player.Move(-2.,-3);
    player.PrintPos();
    return 0;
}