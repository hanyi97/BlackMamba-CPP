#include "../../include/Poison.hpp"

using namespace Engine;

Poison::Poison()
{

}

Poison::Poison(std::shared_ptr<Context> &context, int xPos, int yPos)
      : context(context), xPos(xPos), yPos(yPos)
{

}

void Poison::draw()
{
    context->assets->addTexture(POISON, "../assets/images/poison.png");
    poison.setTexture(context->assets->getTexture(POISON));
    poison.setPosition(xPos, yPos);
    context->window->draw(poison);
}

int Poison::getXPos()
{
    return xPos;
}

void Poison::setXPos(int xPos)
{
    this->xPos = xPos;
}

int Poison::getYPos()
{
    return yPos;
}

void Poison::setYPos(int yPos)
{
    this->yPos;
}
