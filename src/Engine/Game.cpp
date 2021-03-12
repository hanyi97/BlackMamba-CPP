#include "../../include/Game.hpp"
#include "../../include/GamePanel.hpp"
#include "../../include/Settings.hpp"
#include "../../include/Menu.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#ifdef __APPLE__
#define OS 0
#elif defined(_WIN32) || defined(_WIN64)
#define OS 1
#endif

using namespace Engine;

Game::Game() : context(std::make_shared<Context>())
{
    // Setup window and show first screen to display
    if (OS == 0)
    {
        context->window->create(sf::VideoMode(Settings::WINDOW_WIDTH*2, Settings::WINDOW_HEIGHT*2), "Black Mamba", sf::Style::Close);
        context->window->setView(sf::View(sf::FloatRect(0, 0, Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT)));
    }
    else
    {
        context->window->create(sf::VideoMode(Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT), "Black Mamba", sf::Style::Close);
    }
    context->states->addState(std::make_unique<GamePanel>(context));

}

/**
 * Start timer and run game loop
 */
void Game::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    while (context->window->isOpen())
    {
        timeSinceLastFrame += clock.restart();
        while (timeSinceLastFrame > TIME_PER_FRAME)
        {
            timeSinceLastFrame -= TIME_PER_FRAME;

            context->states->processStateChange();
            context->states->GetCurrent()->processInput();
            context->states->GetCurrent()->update(TIME_PER_FRAME);
            context->states->GetCurrent()->draw();
        }
    }
}

int main()
{
    Game game;
    game.Run();

    return 0;
}