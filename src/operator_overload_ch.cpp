#include <iostream>
#include <string>

using namespace std;

struct Vec2
{
    float x,y;
    Vec2(float x, float y): x(x), y(y){}
    Vec2 Add(const Vec2& other) const{
        return Vec2(x + other.x,y + other.y);
    }
    Vec2 Multiply(const Vec2& other) const{
        return Vec2(x*other.x,y*other.y);
    }
    Vec2 operator+(const Vec2& other) const{
        return Add(other);
    }
    Vec2 operator*(const Vec2& other) const{
        return Multiply(other);
    }
};
ostream& operator<<(ostream& stream, Vec2& vector)
{
    stream << vector.x << "," << vector.y<<endl;
    return stream;
}

int main()
{
    Vec2 v1(1.0f,3.0f);
    cout << v1;
    Vec2 v2(3.0f,0.4f);
    cout << v2;
    Vec2 add = v1 + v2;
    Vec2 mul = v1*v2;
    cout << add;
    cout<<mul;
    return 0;
}