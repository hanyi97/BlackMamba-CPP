#include "../../include/GamePanel.hpp"
#include "../../include/Settings.hpp"
#include <stdlib.h>
#include <fstream>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../../include/HighScore.hpp"
#include "../../include/GameMath.hpp"
#include "../../include/Menu.hpp"
#include <iostream>

using namespace Engine;

GamePanel::GamePanel(std::shared_ptr<Context> &context)
         : context(context),
           elapsedTime(sf::Time::Zero),
           running(true),
           ticks(0),
           player1(context, PLAYER1),
           player2(context, PLAYER2)
{
    srand(time(nullptr));
}

GamePanel::~GamePanel() = default;

/**
 * Initialises screen objects
 */
void GamePanel::init()
{
    context->assets->addFont(MAIN_FONT, "../assets/fonts/Helvetica.ttf");
    context->assets->addFont(BOLD_FONT, "../assets/fonts/Helvetica-Bold.ttf");
    context->assets->addTexture(BACKGROUND, "../assets/images/background.jpg", true);
    context->assets->addTexture(HEART, "../assets/images/heart.png");

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
    borders.setSize(sf::Vector2f(Settings::WINDOW_WIDTH - 4, Settings::GAME_HEIGHT - 2));
    borders.setPosition(2, Settings::GAME_YPOS);
    borders.setFillColor(sf::Color::Transparent);
    borders.setOutlineColor(sf::Color::White);
    borders.setOutlineThickness(2);

    player1.init();
    player2.init();
    start();
}

/**
 * Wait for user keypress
 */
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
            else if (key == sf::Keyboard::Space)
            {
                if (running) pause();
                else start();
            }
            else if (key == sf::Keyboard::Enter)
            {
                if (!running)
                {
                    running = true;
                    player1 = Player(context, PLAYER1);
                    player2 = Player(context, PLAYER2);
                    player1.init();
                    player2.init();
                }
            }
            else if (key == sf::Keyboard::Escape)
            {
                if (!running)
                {
                    context->states->addState(std::make_unique<Menu>(context), true);
                }
            }
        }
    }
}

/**
 * Updates game frame
 *
 * @param deltaTime: Elapsed time
 */
void GamePanel::update(sf::Time deltaTime)
{
    elapsedTime += deltaTime;
    if (elapsedTime.asSeconds() > 0.1)
    {
        if (running)
        {
            // Both lost
            if (player1.isLose() && player2.isLose()) running = false;

            // Player 1
            if (!player1.isLose())
            {
                player1.moveSnake();
                player1.checkHit();
                player1.checkEat();
            }

            // Player 2
            if (!player2.isLose())
            {
                player2.moveSnake();
                player2.checkHit();
                player2.checkEat();
            }

            // Reposition poison
            if (ticks >= 20)
            {
                player1.repositionPoison();
                player2.repositionPoison();
                ticks = 0;
            }
            ticks++;
        }
        elapsedTime = sf::Time::Zero;
    }
}

/**
 * Clears screen frame and redraw objects
 */
void GamePanel::draw()
{
    // Clear screen
    context->window->clear();

    // Draw objects
    context->window->draw(background);
    context->window->draw(panel);
    context->window->draw(divider);
    context->window->draw(borders);
//    drawGrid();
    if (!player1.isLose()) player1.draw();
    else showP1LoseScreen();
    if (!player2.isLose()) player2.draw();
    else showP2LoseScreen();
    if (player1.isLose() && player2.isLose()) showGameOverScreen();
    displayPanelText();

    // Display objects
    context->window->display();
}

/**
 * Set running state to false
 */
void GamePanel::pause()
{
    running = false;
}

/**
 * Set running state to true
 */
void GamePanel::start()
{
    running = true;
}

/**
 * Helper method to draw grid lines
 */
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

/**
 * Draws game over screen
 */
void GamePanel::showGameOverScreen()
{
    //show highscore of both players
    checkScore(getHighScore());
    sf::RectangleShape rect;
    rect.setSize(sf::Vector2f {Settings::WINDOW_WIDTH, Settings::GAME_HEIGHT});
    rect.setPosition(0, Settings::GAME_YPOS + 1);
    rect.setFillColor(sf::Color::Black);

    sf::Text gameOver, restart, result, menu;

    // Game over text
    gameOver.setCharacterSize(30);
    gameOver.setString("GAME OVER");
    gameOver.setFont(context->assets->getFont(BOLD_FONT));
    sf::FloatRect gameOverRect = gameOver.getLocalBounds();
    gameOver.setOrigin(gameOverRect.left + gameOverRect.width/2.0f,gameOverRect.top  + gameOverRect.height/2.0f);
    gameOver.setPosition(sf::Vector2f(Settings::WINDOW_WIDTH/2.0f, Settings::WINDOW_HEIGHT/2.0f));
    gameOver.setFillColor(sf::Color(255, 102, 102));


    // Result text
    result.setCharacterSize(30);
    result.setFont(context->assets->getFont(BOLD_FONT));
    if (player1.getScore() > player2.getScore()){
        result.setString("Player 1 Won!!");
    }

    else if (player2.getScore() > player1.getScore()){
        result.setString("Player 2 Won!!");
    }
    else result.setString("Draw");
    sf::FloatRect resultRect = result.getLocalBounds();
    result.setOrigin(resultRect.left + resultRect.width/2.0f,resultRect.top  + resultRect.height/2.0f);
    result.setPosition(sf::Vector2f(Settings::WINDOW_WIDTH/2.0f, Settings::WINDOW_HEIGHT/2.0f + 50));
    result.setFillColor(sf::Color(102, 255, 153));



    // Restart text
    restart.setCharacterSize(15);
    restart.setString("Press Enter to Restart");
    restart.setFont(context->assets->getFont(MAIN_FONT));
    sf::FloatRect restartRect = restart.getLocalBounds();
    restart.setOrigin(restartRect.left + restartRect.width/2.0f,restartRect.top  + restartRect.height/2.0f);
    restart.setPosition(sf::Vector2f(Settings::WINDOW_WIDTH/2.0f, Settings::WINDOW_HEIGHT/2.0f + 100));
    restart.setFillColor(sf::Color(255, 77, 77));

    // Menu text
    menu.setCharacterSize(15);
    menu.setString("Press Escape to return to Main Menu");
    menu.setFont(context->assets->getFont(MAIN_FONT));
    sf::FloatRect menuRect = menu.getLocalBounds();
    menu.setOrigin(menuRect.left + menuRect.width/2.0f,menuRect.top  + menuRect.height/2.0f);
    menu.setPosition(sf::Vector2f(Settings::WINDOW_WIDTH/2.0f, Settings::WINDOW_HEIGHT/2.0f + 130));
    menu.setFillColor(sf::Color(255, 77, 77));

    context->window->draw(rect);
    context->window->draw(gameOver);
    context->window->draw(result);
    context->window->draw(restart);
    context->window->draw(menu);
}

/**
 * Draws player 1 game over screen
 */
void GamePanel::showP1LoseScreen()
{
    // Clear left screen
    sf::RectangleShape rect;
    rect.setPosition(1, 1 + Settings::GAME_YPOS);
    rect.setSize(sf::Vector2f {(Settings::WINDOW_WIDTH / 2.0f) - 1, Settings::GAME_HEIGHT - 1});
    rect.setFillColor(sf::Color::Black);

    // Game over text
    sf::Text gameOver;
    gameOver.setCharacterSize(30);
    gameOver.setString("Player 1 Game Over");
    gameOver.setFont(context->assets->getFont(BOLD_FONT));
    sf::FloatRect gameOverRect = gameOver.getLocalBounds();
    gameOver.setOrigin(gameOverRect.left + gameOverRect.width/2.0f,gameOverRect.top  + gameOverRect.height/2.0f);
    gameOver.setPosition(sf::Vector2f(Settings::CENTER/2.0f, Settings::WINDOW_HEIGHT/2.0f));
    gameOver.setFillColor(sf::Color(255, 102, 102));

    context->window->draw(rect);
    context->window->draw(gameOver);
}

/**
 * Draws player 2 game over screen
 */
void GamePanel::showP2LoseScreen()
{
    // Clear right screen
    sf::RectangleShape rect;
    rect.setPosition(Settings::CENTER + 1, 1 + Settings::GAME_YPOS);
    rect.setSize(sf::Vector2f{(Settings::WINDOW_WIDTH / 2.0f) - 2, Settings::GAME_HEIGHT - 1});
    rect.setFillColor(sf::Color::Black);


    // Game over text
    sf::Text gameOver;
    gameOver.setCharacterSize(30);
    gameOver.setString("Player 2 Game Over");
    gameOver.setFont(context->assets->getFont(BOLD_FONT));
    sf::FloatRect gameOverRect = gameOver.getLocalBounds();
    gameOver.setOrigin(gameOverRect.left + gameOverRect.width/2.0f,gameOverRect.top  + gameOverRect.height/2.0f);
    gameOver.setPosition(sf::Vector2f(Settings::CENTER + Settings::CENTER/2.0f, Settings::WINDOW_HEIGHT/2.0f));
    gameOver.setFillColor(sf::Color(255, 102, 102));

    context->window->draw(rect);
    context->window->draw(gameOver);
}


void GamePanel::checkScore(std::string highScore){
    // int to store the high score.
    int high;
    // compare if player 1 is higher than high score.
    if(player1.getScore() > std::stoi(highScore)){
        high = player1.getScore();

        // if got new high score update the high score.
        fileWrite(std::to_string(high));
    }
    // compare if player 2 is higher than high score.
    else if (player2.getScore() > std::stoi(highScore)){
        high = player2.getScore();

        // if got new high score update the high score.
        fileWrite(std::to_string(high));
    }
}

void GamePanel::fileWrite(std::string highScore) {
    // int to store the high score
    int hs;
    // write initial score to highscore.txt
    std::ofstream outfile("highscore.txt");

    // read highscore.txt
    std::ifstream myFile("highscore.txt");

    // if file is empty then write 0 to the highscore.txt
    if (myFile.peek() == std::ifstream::traits_type::eof()){
        outfile << "0";
        outfile.close();
    }

    // get the int from highscore.txt
    myFile >> hs;
    myFile.close();

    // overwrite the current score with new high score.
    std::ofstream hscore("highscore.txt", std::ofstream::trunc);
    // update high score.
    hscore << highScore;
    hscore.close();
}

std::string GamePanel::getHighScore()
{
    int line;
    std::ifstream myfile;
    myfile.open ("highscore.txt");
    if (myfile.is_open())
    {
        myfile >> line;
        myfile.close();
    }
    return std::to_string(line);
}

/**
 * Display hearts for player 1 remaining lives
 */
void GamePanel::displayP1Hearts()
{
    for (int i = 0; i < player1.getLives(); i++)
    {
        sf::Sprite heart;
        heart.setTexture(context->assets->getTexture(HEART));
        heart.setPosition((float)60+((float )i*25), (float)30);
        context->window->draw(heart);
    }
}

/**
 * Display hearts for player 2 remaining lives
 */
void GamePanel::displayP2Hearts()
{
    for (int i = 0; i < player2.getLives(); i++)
    {
        sf::Sprite heart;
        heart.setTexture(context->assets->getTexture(HEART));
        heart.setPosition(Settings::CENTER + 480 + ((float )i*25), (float)30);
        context->window->draw(heart);
    }
}

/**
 * Draws objects for top panel
>>>>>>> main
 */
void GamePanel::displayPanelText()
{
    sf::Text p1, p1Score, p1Lives,
             p2, p2Score, p2Lives,
             pauseText, HighScore;

    // Player 1 text
    p1.setCharacterSize(25);
    p1.setPosition(Settings::CENTER/2.0f, 18);
    p1.setFillColor(sf::Color(255, 102, 153));
    p1.setFont(context->assets->getFont(BOLD_FONT));
    p1.setString("Player 1");

    // Player 1 score
    p1Score.setCharacterSize(15);
    p1Score.setPosition(10, 10);
    p1Score.setFillColor(sf::Color::White);
    p1Score.setFont(context->assets->getFont(BOLD_FONT));
    p1Score.setString("Score: " + std::to_string(player1.getScore()));

    // Player 1 lives
    GamePanel::displayP1Hearts();
    p1Lives.setCharacterSize(15);
    p1Lives.setPosition(10, 30);
    p1Lives.setFillColor(sf::Color::White);
    p1Lives.setFont(context->assets->getFont(BOLD_FONT));
    p1Lives.setString("Lives: ");

    // Player 2 text
    p2.setCharacterSize(25);
    p2.setPosition(Settings::CENTER + Settings::CENTER/2.0f - 60, 18);
    p2.setFillColor(sf::Color(255, 102, 153));
    p2.setFont(context->assets->getFont(BOLD_FONT));
    p2.setString("Player 2");

    // Player 2 score
    p2Score.setCharacterSize(15);
    p2Score.setPosition(Settings::CENTER + 430, 10);
    p2Score.setFillColor(sf::Color::White);
    p2Score.setFont(context->assets->getFont(BOLD_FONT));
    p2Score.setString("Score: " + std::to_string(player2.getScore()));

    // Player 2 lives
    GamePanel::displayP2Hearts();
    p2Lives.setCharacterSize(15);
    p2Lives.setPosition(Settings::CENTER + 430, 30);
    p2Lives.setFillColor(sf::Color::White);
    p2Lives.setFont(context->assets->getFont(BOLD_FONT));
    p2Lives.setString("Lives: ");

    // Pause text
    pauseText.setCharacterSize(12);
    pauseText.setPosition(10, Settings::GAME_YPOS - 20);
    pauseText.setFillColor(sf::Color::Red);
    pauseText.setFont(context->assets->getFont(MAIN_FONT));
    pauseText.setString("Press 'spacebar' to pause");

    // High score text
    HighScore.setCharacterSize(15);
    HighScore.setPosition(Settings::CENTER - 50, 20);
    HighScore.setFillColor(sf::Color::Cyan);
    HighScore.setFont(context->assets->getFont(BOLD_FONT));
    HighScore.setString("High Score: " + getHighScore());

    context->window->draw(p1);
    context->window->draw(p2);
    context->window->draw(p1Score);
    context->window->draw(p2Score);
    context->window->draw(p1Lives);
    context->window->draw(p2Lives);
    context->window->draw(pauseText);
    context->window->draw(HighScore);
}