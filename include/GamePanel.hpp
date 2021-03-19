#ifndef BLACKMAMBA_GAMEPANEL_HPP
#define BLACKMAMBA_GAMEPANEL_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "State.hpp"
#include "Game.hpp"
#include "Food.hpp"
#include "Player.hpp"
#include "HighScore.hpp"

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
        sf::RectangleShape borders;

        Player player1;
        Player player2;

        bool running;
        bool gameOver;
        int ticks;
    public:
        GamePanel(std::shared_ptr<Context> &);
        ~GamePanel() = default;

        void init() override;
        void processInput() override;
        void update(sf::Time) override;
        void draw() override;
        void pause() override;
        void start() override;
        void drawGrid();
        void showGameOverScreen();
        void showP1LoseScreen();
        void showP2LoseScreen();
        void displayPanelText();
        void displayP1Hearts();
        void displayP2Hearts();
    };
}

#endif //BLACKMAMBA_GAMEPANEL_HPP
