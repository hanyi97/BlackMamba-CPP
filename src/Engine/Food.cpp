#include "../../include/Food.hpp"

using namespace Engine;
Food::Food()
{

}

Food::Food(std::shared_ptr<Context> &context, int xPos, int yPos)
    : context(context), xPos(xPos), yPos(yPos)
{
}

void Food::draw()
{
    context->assets->addTexture(FOOD, "../assets/images/donut.png");
    food.setTexture(context->assets->getTexture(FOOD));
    food.setPosition(xPos, yPos);
    context->window->draw(food);
}

int Food::getXPos()
{
    return xPos;
}

void Food::setXPos(int xPos)
{
    this->xPos = xPos;
}

int Food::getYPos()
{
    return yPos;
}

void Food::setYPos(int yPos)
{
    this->yPos = yPos;
}
