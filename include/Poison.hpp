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
        Poison(std::shared_ptr<Context> &, int, int);

        void draw() override;
        void setXPos(int) override;
        void setYPos(int) override;

        int getXPos() override;
        int getYPos() override;
    };
}

#endif
