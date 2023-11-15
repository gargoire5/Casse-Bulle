#include "Ball.h"
#include <cmath>

Ball::Ball(int positionX, int positionY, int radius, sf::Color color)
{
    shape.setPosition(positionX, positionY);
    shape.setRadius(radius);
    shape.setFillColor(color);
}
/*
void Ball::move(sf::Vector2f direction, float deltaTime)
{
    float speed = 300.0f;
    float norm = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    direction.x = direction.x / norm;
    direction.y = direction.y / norm;

    sf::Vector2f newPosition = shape.getPosition() + direction * speed * deltaTime;
    shape.setPosition(newPosition);
}
*/
void Ball::draw(sf::RenderTarget& target) const
{
    target.draw(shape);
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
