#include "../../include/Food.hpp"

using namespace Engine;
Food::Food()
{
}

Food::Food(std::shared_ptr<Context> &context, int xPos, int yPos)
    : context(context), xPos(xPos), yPos(yPos)
{
}

/**
 * Initialise donut image file and draws it to the current position
 */
void Food::draw()
{
    context->assets->addTexture(FOOD, "../assets/images/donut.png");
    food.setTexture(context->assets->getTexture(FOOD));
    food.setPosition(xPos, yPos);
    context->window->draw(food);
}

/**
 * @return x position of food
 */
int Food::getXPos()
{
    return xPos;
}

/**
 * @param xPos: x position to set
 */
void Food::setXPos(int xPos)
{
    this->xPos = xPos;
}

/**
 * @return y position of food
 */
int Food::getYPos()
{
    return yPos;
}

/**
 * @param yPos: y position to set
 */
void Food::setYPos(int yPos)
{
    this->yPos = yPos;
}
