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
        Food(std::shared_ptr<Context> &context, int xPos, int yPos);

        void draw() override;
        int getXPos() override;
        void setXPos(int xPos) override;
        int getYPos() override;
        void setYPos(int yPos) override;
    };
}


#endif //BLACKMAMBA_FOOD_HPP
