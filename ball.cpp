#include "Ball.h"
#include <cmath>

Ball::Ball(int positionX, int positionY, int radius, sf::Color color) /*: GameObject(positionX, positionY, radius, color)*/
{
    shape.setPosition(positionX, positionY);
    shape.setRadius(radius);
    shape.setFillColor(color);
}

void Ball::setPosition(float x, float y)
{
    shape.setPosition(x, y);
}

void Ball::move(sf::Vector2f drt, float tps)
{
    float vitesse = 300;
    // a mettre dans une fonction maths
    float norme = std::sqrt(drt.x * drt.x + drt.y * drt.y);
    drt.x = drt.x / norme;
    drt.y = drt.y / norme;
    //
    float fNewX = shape.getPosition().x + (drt.x * tps * vitesse);
    float fNewY = shape.getPosition().y + (drt.y * tps * vitesse);
    shape.setPosition(fNewX, fNewY);
}

void Ball::Draw(sf::RenderTarget& target)
{
    target.draw(shape);
}

sf::Vector2f Ball::getPosition() const
{
    return shape.getPosition();
}

sf::Vector2f Ball::getSize() const
{
    return sf::Vector2f(shape.getRadius() * 2, shape.getRadius() * 2);
}