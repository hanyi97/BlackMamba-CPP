#ifndef BLACKMAMBA_PLAYER_HPP
#define BLACKMAMBA_PLAYER_HPP

#include "Food.hpp"

namespace Engine
{
    class Player
    {
    private:
        int lives;
        int score;
        bool lose;
        Food food;
    public:
        Player();
        // TODO add methods
    };
}


#endif //BLACKMAMBA_PLAYER_HPP
