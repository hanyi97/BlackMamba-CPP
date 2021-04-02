#ifndef BLACKMAMBA_FOOD_HPP
#define BLACKMAMBA_FOOD_HPP

#include <SFML/Graphics/Sprite.hpp>

#include "Game.hpp"
#include "Drawable.hpp"

namespace Engine
{
    class Food : public Drawable
    {
    private:
        int xPos{};
        int yPos{};
        sf::Sprite food;
        std::shared_ptr<Context> context;
    public:
        Food();
        Food(std::shared_ptr<Context> &, int, int);

        void draw() override;
        void setXPos(int) override;
        void setYPos(int) override;

        int getXPos() override;
        int getYPos() override;
    };
}

#endif
