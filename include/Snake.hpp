#ifndef BLACKMAMBA_SNAKE_HPP
#define BLACKMAMBA_SNAKE_HPP

#include <vector>
#include "Body.hpp"
#include "Food.hpp"

namespace Engine
{
    class Snake
    {
    private:

        std::shared_ptr<Context> context;
        std::vector<Body> body;

        char direction;

        int xPos;
        int yPos;
        int player;
        int size = 5;
    public:
        Snake();
        Snake(std::shared_ptr<Context> &context, int player);

        void init();
        void move();
        void increaseSize(int increment = 1);
        void draw(char direction);

        bool hitBorder() const;
        bool hitItself();
        bool hitFood(Drawable &food) const;

        void setXPos(int x);
        int getXPos() const;
        void setYPos(int y);
        int getYPos() const;
    };
}


#endif //BLACKMAMBA_SNAKE_HPP
