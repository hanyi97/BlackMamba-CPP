#ifndef BLACKMAMBA_GAMEPANEL_HPP
#define BLACKMAMBA_GAMEPANEL_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "Food.hpp"
#include "Player.hpp"

namespace Engine
{
    class GamePanel : public State
    {
    private:
        std::shared_ptr<Context> context;
        sf::Time elapsedTime;
        sf::Sprite background;
        sf::RectangleShape panel;
        sf::RectangleShape divider;

        Player player1;
        Player player2;

        bool running;
    public:
        GamePanel(std::shared_ptr<Context> &context);
        ~GamePanel();

        void init() override;
        void processInput() override;
        void update(sf::Time deltaTime) override;
        void draw() override;
        void pause() override;
        void start() override;
        void drawGrid();
    };
}

#endif //BLACKMAMBA_GAMEPANEL_HPP
