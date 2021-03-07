#include <iostream>
#include "../../include/Body.hpp"
#include "../../include/Settings.hpp"

using namespace Engine;

Body::Body()
{

}

Body::Body(std::shared_ptr<Context> &context, int xPos, int yPos)
    :context(context), xPos(xPos), yPos(yPos)
{

}


void Body::drawBody()
{
    body.setRadius(Settings::UNIT_SIZE/2);
    body.setPosition(xPos, yPos);
    body.setFillColor(sf::Color::Cyan);
    context->window->draw(body);
}

void Body::drawHead(char direction)
{
    int id;
    switch (direction)
    {
        case 'U':
            context->assets->AddTexture(UP_MOUTH, "../assets/images/upmouth.png");
            id = UP_MOUTH;
            break;
        case 'D':
            context->assets->AddTexture(DOWN_MOUTH, "../assets/images/downmouth.png");
            id = DOWN_MOUTH;
            break;
        case 'L':
            context->assets->AddTexture(LEFT_MOUTH, "../assets/images/leftmouth.png");
            id = LEFT_MOUTH;
            break;
        case 'R':
            context->assets->AddTexture(RIGHT_MOUTH, "../assets/images/rightmouth.png");
            id = RIGHT_MOUTH;
            break;
        default:
            id = UP_MOUTH;
            break;
    }

    head.setTexture(context->assets->GetTexture(id));
    head.setPosition(xPos, yPos);
    context->window->draw(head);
}

int Body::getXPos()
{

}

void Body::setXPos(int xPos)
{

}

int Body::getYPos()
{

}

void Body::setYPos(int yPos)
{

}
