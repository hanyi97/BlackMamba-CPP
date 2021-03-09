#include "../../include/Game.hpp"
#include "../../include/GamePanel.hpp"
#include "../../include/Settings.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

using namespace Engine;

Game::Game() : context(std::make_shared<Context>())
{
    context->window->create(sf::VideoMode(Settings::WINDOW_WIDTH*2, Settings::WINDOW_HEIGHT*2), "Black Mamba", sf::Style::Close);
    context->window->setView(sf::View(sf::FloatRect(0, 0, Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT)));
    context->states->addState(std::make_unique<GamePanel>(context));
}

Game::~Game() = default;


void Game::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Cyan);

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