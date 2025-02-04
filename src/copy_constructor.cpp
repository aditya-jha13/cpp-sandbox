#include <iostream>
#include <cstring>

#define LOG(x) std::cout << x << std::endl
using namespace std;

struct String
{
    private:
        char* m_Buffer;
        unsigned int len;
    public:
        String(const char* string)
        {
            LOG("Fresh Assignment");
            len = strlen(string);
            m_Buffer = new char[len+1];
            memcpy(m_Buffer,string,len); // similar arguments as memset()
            m_Buffer[len] = 0;
        }
        ~String()
        {
            LOG("Destruction!!");
            delete[] m_Buffer;
        }
        String(const String& other): len(other.len)
        {
            LOG("Copy from one string to another");
            m_Buffer = new char[len+1];
            memcpy(m_Buffer,other.m_Buffer,len+1);
        }
        friend ostream& operator<<(ostream& stream, const String& string); // friend keyword allows any external fn to access even private members.
};

ostream& operator<<(ostream& stream, const String& string)
{
    stream << string.m_Buffer;
    return stream;
}

int main()
{
    String a = "Hello";
    String b = a;
    cout << a << "," << b << endl;
    cout << &a << "," << &b << endl;
    return 0;
}