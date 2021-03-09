#ifndef BLACKMAMBA_BODY_HPP
#define BLACKMAMBA_BODY_HPP

#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "Game.hpp"

namespace Engine
{
    class Body
    {
    private:
        int xPos;
        int yPos;
        sf::Sprite head;
        sf::CircleShape body;
        sf::Color color;
        std::shared_ptr<Context> context;
    public:
        Body();
        Body(std::shared_ptr<Context> &context, int xPos, int yPos);

        void drawBody();
        void drawHead(char direction);
        int getXPos();
        void setXPos(int xPos);
        int getYPos();
        void setYPos(int yPos);
    };
}


#endif //BLACKMAMBA_BODY_HPP
