#include "../../include/Player.hpp"
#include "../../include/GameMath.hpp"
#include "../../include/Settings.hpp"

using namespace Engine;
using namespace Math;

Player::Player(std::shared_ptr<Context> &context, int player):lives(3), score(0), lose(false)
{
    switch (player)
    {
        case PLAYER1:
            this->food = Food(context, GameMath::getRandomLeftX(Settings::CENTER, Settings::UNIT_SIZE),
                     GameMath::getRandomY(Settings::GAME_YPOS, Settings::GAME_HEIGHT, Settings::UNIT_SIZE));
            this->snake = Snake(context, PLAYER1);
            right = true, left = false, up = false, down = false;
            break;
        case PLAYER2:
            this->food = Food(context, GameMath::getRandomRightX(Settings::CENTER, Settings::UNIT_SIZE),
                      GameMath::getRandomY(Settings::GAME_YPOS, Settings::GAME_HEIGHT, Settings::UNIT_SIZE));
            this->snake = Snake(context, PLAYER2);
            right = false, left = true, up = false, down = false;
            break;
        default:
            break;
    }
}

void Player::Init()
{
    snake.Init();
}

void Player::draw()
{
    char dir = 'A';
    if (up) dir = 'U';
    if (down) dir = 'D';
    if (left) dir = 'L';
    if (right) dir = 'R';

    food.draw();
    snake.draw(dir);
}

void Player::moveSnake()
{
    int x = snake.getXPos();
    int y = snake.getYPos();

    if (right)  x += Settings::UNIT_SIZE;
    if (left) x -= Settings::UNIT_SIZE;
    if (up) y -= Settings::UNIT_SIZE;
    if (down) y += Settings::UNIT_SIZE;

    snake.setXPos(x);
    snake.setYPos(y);
    snake.Move();
}

void Player::changeDirection(bool up, bool down, bool left, bool right)
{
    this->up = up;
    this->down = down;
    this->left = left;
    this->right = right;
}

bool Player::getUp()
{
    return up;
}

bool Player::getDown()
{
    return down;
}

bool Player::getLeft()
{
    return left;
}

bool Player::getRight()
{
    return right;
}