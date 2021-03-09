#include "../../include/Poison.hpp"

using namespace Engine;

Poison::Poison()
{

}

Poison::Poison(std::shared_ptr<Context> &context, int xPos, int yPos)
      : context(context), xPos(xPos), yPos(yPos)
{

}

/**
 * Initialise poison image and draws it to the current position
 */
void Poison::draw()
{
    context->assets->addTexture(POISON, "../assets/images/poison.png");
    poison.setTexture(context->assets->getTexture(POISON));
    poison.setPosition(xPos, yPos);
    context->window->draw(poison);
}

/**
 * @return x position of a poison
 */
int Poison::getXPos()
{
    return xPos;
}

/**
 * @param xPos:	x position to set
 */
void Poison::setXPos(int xPos)
{
    this->xPos = xPos;
}

/**
 * @return y position of a poison
 */
int Poison::getYPos()
{
    return yPos;
}

/**
 * @param yPos: y position to set
 */
void Poison::setYPos(int yPos)
{
    this->yPos;
}
