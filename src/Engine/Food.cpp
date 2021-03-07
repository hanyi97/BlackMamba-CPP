#include "../../include/Food.hpp"
#include "../../include/Settings.hpp"

using namespace Engine;
Food::Food()
{

}

Food::Food(std::shared_ptr<Context> &context, int xPos, int yPos) : context(context)
{
    this->xPos = xPos;
    this->yPos = yPos;
}

void Food::draw()
{
    context->assets->AddTexture(FOOD, "../assets/images/donut.png");
    food.setTexture(context->assets->GetTexture(FOOD));
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
