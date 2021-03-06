#ifndef BLACKMAMBA_FOOD_HPP
#define BLACKMAMBA_FOOD_HPP

#include <SFML/Graphics/Sprite.hpp>
#include "Game.hpp"

namespace Engine
{
    class Food
    {
    private:
        int xPos;
        int yPos;
        sf::Sprite food;
        std::shared_ptr<Context> context;
    public:
        Food(std::shared_ptr<Context> &context, int xPos, int yPos);

        void draw();
        int getXPos();
        void setXPos(int xPos);
        int getYPos();
        void setYPos(int yPos);
    };
}


#endif //BLACKMAMBA_FOOD_HPP
