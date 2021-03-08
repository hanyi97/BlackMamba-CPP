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

void GamePanel::init()
{
    context->assets->addTexture(BACKGROUND, "../assets/images/background.jpg", true);

    // Background image
    background.setTexture(context->assets->getTexture(BACKGROUND));
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

    // Borders
    borders.setSize(sf::Vector2f(Settings::WINDOW_WIDTH - 4, Settings::GAME_HEIGHT - 4));
    borders.setPosition(2, Settings::GAME_YPOS);
    borders.setFillColor(sf::Color::Transparent);
    borders.setOutlineColor(sf::Color::White);
    borders.setOutlineThickness(2);

    player1.init();
    player2.init();
}

void GamePanel::processInput()
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
            int key = event.key.code;

            if (key == sf::Keyboard::W && !player1.getDown())
                player1.changeDirection(true, false, false, false);
            else if (key == sf::Keyboard::S && !player1.getUp())
                player1.changeDirection(false, true, false, false);
            else if (key == sf::Keyboard::A && !player1.getRight())
                player1.changeDirection(false, false, true, false);
            else if (key == sf::Keyboard::D && !player1.getLeft())
                player1.changeDirection(false, false, false, true);
            else if (key == sf::Keyboard::Up && !player2.getDown())
                player2.changeDirection(true, false, false, false);
            else if (key == sf::Keyboard::Down && !player2.getUp())
                player2.changeDirection(false, true, false, false);
            else if (key == sf::Keyboard::Left && !player2.getRight())
                player2.changeDirection(false, false, true, false);
            else if (key == sf::Keyboard::Right && !player2.getLeft())
                player2.changeDirection(false, false, false, true);
        }
    }
}

void GamePanel::update(sf::Time deltaTime)
{
    elapsedTime += deltaTime;
    if (elapsedTime.asSeconds() > 0.1)
    {
        if (!player1.isLose())
        {
            player1.moveSnake();
            player1.checkHit();
            player1.checkEat();
        }

        if (!player2.isLose())
        {
            player2.moveSnake();
            player2.checkHit();
            player2.checkEat();
        }

        elapsedTime = sf::Time::Zero;
    }
}

void GamePanel::draw()
{
    context->window->clear();
    context->window->draw(background);
    context->window->draw(panel);
    context->window->draw(divider);
//    drawGrid();
    if (!player1.isLose())
        player1.draw();
    else
        showP1LoseScreen();

    if (!player2.isLose())
        player2.draw();
    else
        showP2LoseScreen();

    context->window->draw(borders);
    context->window->display();
}

void GamePanel::pause()
{
    running = false;
}

void GamePanel::start()
{
    running = true;
}

void GamePanel::drawGrid()
{
    // draw vertical lines
    for (int i = 0; i < Settings::WINDOW_HEIGHT / Settings::UNIT_SIZE; i++)
    {
        sf::RectangleShape line;
        line.setSize(sf::Vector2f(Settings::WINDOW_WIDTH, 2));
        line.setPosition(0, i * Settings::UNIT_SIZE + Settings::GAME_YPOS);
        line.setFillColor(sf::Color::White);
        context->window->draw(line);
    }
    // draw horizontal lines
    for (int i = 0; i < Settings::WINDOW_WIDTH / Settings::UNIT_SIZE; i++)
    {
        sf::RectangleShape line;
        line.setSize(sf::Vector2f(2, Settings::GAME_HEIGHT));
        line.setPosition(i * Settings::UNIT_SIZE, Settings::GAME_YPOS);
        line.setFillColor(sf::Color::White);
        context->window->draw(line);
    }
}

void GamePanel::showGameOverScreen()
{

}

void GamePanel::showP1LoseScreen()
{
    sf::RectangleShape rect;
    rect.setPosition(1, 1 + Settings::GAME_YPOS);
    rect.setSize(sf::Vector2f {(Settings::WINDOW_WIDTH / 2) - 1, Settings::GAME_HEIGHT - 2});
    rect.setFillColor(sf::Color::Black);
    context->window->draw(rect);
}

void GamePanel::showP2LoseScreen()
{
    sf::RectangleShape rect;
    rect.setPosition(Settings::CENTER + 1, 1 + Settings::GAME_YPOS);
    rect.setSize(sf::Vector2f{(Settings::WINDOW_WIDTH / 2) - 2, Settings::GAME_HEIGHT - 2});
    rect.setFillColor(sf::Color::Black);
    context->window->draw(rect);
}
