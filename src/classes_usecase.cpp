#include <iostream>
#define LOG(x) std::cout << x << std::endl

using namespace std;

class Player
{

    public:
        Player(int x,int y,int speed)
        {
            x = 0,y=0,speed=0;
        }
        int x,y;
        int speed;

        void move(int xa, int ya)
        {
            x += xa*speed;
            y += ya*speed;
        }
};

class Log
{
    public:
        enum level //starts with 0, if nothing specified and only works for integers
        {
            LevelError=0,LevelWarning,LevelInfo
        };
        const int LogLevelError = 0;
        const int LogLevelWarning = 1;
        const int LogLevelInfo = 2;
    private:
        int m_LogLevel;

    public:
        void SetLevel(level level)
        {
            m_LogLevel = level;
        }
        // need to add the functionality for only printing msgs based on log level
        void Error(const char* message)
        {
            if (m_LogLevel >= LevelError)
                LOG(message);
        }
        void Warn(const char* message)
        {
            if (m_LogLevel >= LevelWarning)
                LOG(message);
        }
        void Info(const char* message)
        {
            if (m_LogLevel >= LevelInfo)
                LOG(message);
        }
};

int main()
{
    Player player(1,2,3);
    player.x = 2; // so here we cant do it unless we specify the variable scope to be 'public' inside the class
    player.y = 3;
    player.speed = 0;
    player.move(1,1);
    Log log;
    log.SetLevel(log.LevelWarning);
    log.Error("lets goooo!");
    log.Warn("lets goooo!");
    log.Info("lets goooo!");
    return 0;
}