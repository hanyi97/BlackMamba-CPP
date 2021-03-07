#include "../../include/GamePanel.hpp"
#include "../../include/Settings.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>

using namespace Engine;

GamePanel::GamePanel(std::shared_ptr<Context> &context)
         : context(context),
           elapsedTime(sf::Time::Zero),
           player1(context, PLAYER1),
           player2(context, PLAYER2)
{
    srand(time(nullptr));
}

GamePanel::~GamePanel() = default;

void GamePanel::Init()
{
    context->assets->AddTexture(BACKGROUND, "../assets/images/background.jpg", true);

    // Background image
    background.setTexture(context->assets->GetTexture(BACKGROUND));
    background.setPosition(0, Settings::GAME_YPOS);
    background.setTextureRect(context->window->getViewport(context->window->getDefaultView()));

    // Top panel
    panel.setSize(sf::Vector2f(Settings::WINDOW_WIDTH, Settings::GAME_YPOS));
    panel.setPosition(0, 0);
    panel.setFillColor(sf::Color::Black);
    panel.setOutlineColor(sf::Color::White);
    panel.setOutlineThickness(2);

    // Center divider
    divider.setSize(sf::Vector2f(2, Settings::GAME_HEIGHT));
    divider.setPosition(Settings::CENTER, Settings::GAME_YPOS);
    divider.setFillColor(sf::Color::White);
}

void GamePanel::ProcessInput()
{
    sf::Event event{};

    while (context->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            context->window->close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {

        }
    }
}

void GamePanel::Update(sf::Time deltaTime)
{
    elapsedTime += deltaTime;
    elapsedTime = sf::Time::Zero;
}

void GamePanel::Draw()
{
    context->window->clear();
    context->window->draw(background);
    context->window->draw(panel);
    context->window->draw(divider);
//    drawGrid();
    player1.draw();
    player2.draw();
    context->window->display();
}

void GamePanel::Pause()
{

}

void GamePanel::Start()
{

}

void GamePanel::drawGrid()
{
    // Draw vertical lines
    for (int i = 0; i < Settings::WINDOW_HEIGHT / Settings::UNIT_SIZE; i++)
    {
        sf::RectangleShape line;
        line.setSize(sf::Vector2f(Settings::WINDOW_WIDTH, 2));
        line.setPosition(0, i * Settings::UNIT_SIZE + Settings::GAME_YPOS);
        line.setFillColor(sf::Color::White);
        context->window->draw(line);
    }
    // Draw horizontal lines
    for (int i = 0; i < Settings::WINDOW_WIDTH / Settings::UNIT_SIZE; i++)
    {
        sf::RectangleShape line;
        line.setSize(sf::Vector2f(2, Settings::GAME_HEIGHT));
        line.setPosition(i * Settings::UNIT_SIZE, Settings::GAME_YPOS);
        line.setFillColor(sf::Color::White);
        context->window->draw(line);
    }
}