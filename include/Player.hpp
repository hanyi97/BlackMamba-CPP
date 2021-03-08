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
        std::shared_ptr<Context> context;

        int lives;
        int score;
        int player;
        bool lose;

        bool up;
        bool down;
        bool left;
        bool right;

        Food food;
        Snake snake;

        static const int SCORE_INCREMENT = 10;
        static const int SCORE_DECREMENT = 5;
    public:
        Player(std::shared_ptr<Context> &context, int player);
        void init();
        void draw();
        void moveSnake();
        void changeDirection(bool up, bool down, bool left, bool right);

        Food createFood();

        void checkHit();
        void checkEat();

        bool getUp() const;
        bool getDown() const;
        bool getLeft() const;
        bool getRight() const;

        void setLose(bool lose);
        bool isLose() const;

        int getScore() const;
        int getLives() const;
    };
}


#endif //BLACKMAMBA_PLAYER_HPP
