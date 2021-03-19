#ifndef BLACKMAMBA_HIGHSCORE_HPP
#define BLACKMAMBA_HIGHSCORE_HPP

#include <string>

namespace Engine
{
    class HighScore
    {
    private:
        inline static const std::string FILE_PATH = "highscore.txt";
    public:
        static void checkScore(int, int);
        static void fileWrite(std::string);
        static std::string getHighScore();
    };
}

#endif //BLACKMAMBA_HIGHSCORE_HPP
