#include "Ball.h"
#include <cmath>

Ball::Ball(int positionX, int positionY, int radius, sf::Color color)
{
    shape.setPosition(positionX, positionY);
    shape.setRadius(radius);
    shape.setFillColor(color);
}

void Ball::setPosition(float x, float y)
{
    shape.setPosition(x, y);
}

sf::Vector2f Ball::getPosition() const
{
    return shape.getPosition();
}

sf::Vector2f Ball::getSize() const
{
    return sf::Vector2f(shape.getRadius() * 2.0f, shape.getRadius() * 2.0f);
}