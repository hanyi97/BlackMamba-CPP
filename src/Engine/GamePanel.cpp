#include "../../include/GamePanel.hpp"
#include "../../include/Settings.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>

using namespace Engine;

GamePanel::GamePanel(std::shared_ptr<Context> &context)
         : context(context),
           elapsedTime(sf::Time::Zero),
           running(true),
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

    player1.Init();
    player2.Init();
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
            switch (event.key.code)
            {
                case sf::Keyboard::W:
                    player1.changeDirection(true, false, false, false);
                    break;
                case sf::Keyboard::A:
                    player1.changeDirection(false, false, false, true);
                    break;
                case sf::Keyboard::S:
                    player1.changeDirection(false, true, false, false);
                    break;
                case sf::Keyboard::D:
                    player1.changeDirection(false, false, true, false);
                    break;
                case sf::Keyboard::Up:
                    player2.changeDirection(true, false, false, false);
                    break;
                case sf::Keyboard::Down:
                    player2.changeDirection(false, true, false, false);
                    break;
                case sf::Keyboard::Left:
                    player2.changeDirection(false, false, true, false);
                    break;
                case sf::Keyboard::Right:
                    player2.changeDirection(false, false, false, true);
                    break;
                default:
                    break;
            }
        }
    }
}

void GamePanel::Update(sf::Time deltaTime)
{
    elapsedTime += deltaTime;
    if (elapsedTime.asSeconds() > 0.1)
    {
        player1.moveSnake();
        player2.moveSnake();
        elapsedTime = sf::Time::Zero;
    }
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
    running = false;
}

void GamePanel::Start()
{
    running = true;
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