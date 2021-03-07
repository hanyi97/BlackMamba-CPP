#ifndef BLACKMAMBA_PLAYER_HPP
#define BLACKMAMBA_PLAYER_HPP

#include "Food.hpp"

namespace Engine
{
    enum PlayerID
    {
        PLAYER1,
        PLAYER2
    };

    class Player
    {
    private:
        int lives{};
        int score{};
        bool lose{};
        Food food;
    public:
        Player(std::shared_ptr<Context> &context, int player);
        void draw();
    };
}


#endif //BLACKMAMBA_PLAYER_HPP
