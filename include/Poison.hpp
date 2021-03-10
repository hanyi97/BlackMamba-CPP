#ifndef BLACKMAMBA_POISON_HPP
#define BLACKMAMBA_POISON_HPP

#include <memory>
#include <SFML/Graphics/Sprite.hpp>
#include "Drawable.hpp"
#include "Game.hpp"

namespace Engine
{
    class Poison : public Drawable
    {
    private:
        int xPos{};
        int yPos{};
        sf::Sprite poison;
        std::shared_ptr<Context> context;
    public:
        Poison();
        Poison(std::shared_ptr<Context> &context, int xPos, int yPos);
        void draw() override;
        int getXPos() override;
        void setXPos(int xPos) override;
        int getYPos() override;
        void setYPos(int yPos) override;
    };
}


#endif //BLACKMAMBA_POISON_HPP
