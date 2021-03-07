#ifndef BLACKMAMBA_PLAYER_HPP
#define BLACKMAMBA_PLAYER_HPP

#include "Food.hpp"
#include "Snake.hpp"

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
        int lives;
        int score;
        bool lose;

        bool up;
        bool down;
        bool left;
        bool right;

        Food food;
        Snake snake;
    public:
        Player(std::shared_ptr<Context> &context, int player);
        void Init();
        void draw();
        void moveSnake();
        void changeDirection(bool up, bool down, bool left, bool right);
    };
}


#endif //BLACKMAMBA_PLAYER_HPP
