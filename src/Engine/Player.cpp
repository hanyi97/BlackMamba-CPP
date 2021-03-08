#include "../../include/Player.hpp"
#include "../../include/GameMath.hpp"
#include "../../include/Settings.hpp"

using namespace Engine;
using namespace Math;

Player::Player(std::shared_ptr<Context> &context, int player)
      :context(context), player(player), lives(3), score(0), lose(false)
{
    switch (player)
    {
        case PLAYER1:
            this->food = createFood();
            this->snake = Snake(context, PLAYER1);
            right = true, left = false, up = false, down = false;
            break;
        case PLAYER2:
            this->food = createFood();
            this->snake = Snake(context, PLAYER2);
            right = false, left = true, up = false, down = false;
            break;
        default:
            break;
    }
}

void Player::init()
{
    snake.init();
}

void Player::draw()
{
    char dir = 'A';
    if (up) dir = 'U';
    else if (down) dir = 'D';
    else if (left) dir = 'L';
    else if (right) dir = 'R';

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
    snake.move();
}

void Player::changeDirection(bool up, bool down, bool left, bool right)
{
    this->up = up;
    this->down = down;
    this->left = left;
    this->right = right;
}

void Player::checkHit()
{
    if (snake.hitBorder() || snake.hitItself()) lose = true;
}

void Player::checkEat()
{
    if (snake.hitFood(food)) food = createFood();
}

Food Player::createFood()
{
    switch (player)
    {
        case PLAYER1:
            return Food(context, GameMath::getRandomLeftX(Settings::CENTER, Settings::UNIT_SIZE),
                        GameMath::getRandomY(Settings::GAME_YPOS, Settings::GAME_HEIGHT, Settings::UNIT_SIZE));
        case PLAYER2:
            return Food(context, GameMath::getRandomRightX(Settings::CENTER, Settings::UNIT_SIZE),
                        GameMath::getRandomY(Settings::GAME_YPOS, Settings::GAME_HEIGHT, Settings::UNIT_SIZE));
        default:
            return Food();
    }
}

bool Player::getUp() const
{
    return up;
}

bool Player::getDown() const
{
    return down;
}

bool Player::getLeft() const
{
    return left;
}

bool Player::getRight() const
{
    return right;
}

void Player::setLose(bool lose)
{
    this->lose = lose;
}

bool Player::isLose() const
{
    return lose;
}

int Player::getScore() const
{
    return score;
}

int Player::getLives() const
{
    return lives;
}