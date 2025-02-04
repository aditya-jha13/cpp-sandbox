#include <iostream>
#include <string>

using namespace std;

struct Entity
{
    float x,y;
    Entity(float x, float y)
    {
        Entity* e = this; // can define as Entity* const e but in that case cannot reassign this to some nullptr
        this->x = x;
        this->y = y;
        PrintEntity(*this);
    }
};
void PrintEntity(const Entity& e)
{

}
int main()
{
    Entity e(1,2);
    return 0;
}