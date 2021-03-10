#include "../../include/Food.hpp"
#include "../../include/Settings.hpp"

using namespace Engine;
Food::Food()
{
}

Food::Food(std::shared_ptr<Context> &context, int xPos, int yPos)
    : context(context), xPos(xPos), yPos(yPos)
{
}

/**
 * Initialise food image file and draws it to the current position
 */
void Food::draw()
{
    context->assets->addTexture(FOOD, "../assets/images/apple.png");
    food.setTexture(context->assets->getTexture(FOOD));
    food.setPosition((float)xPos, (float)yPos);
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
