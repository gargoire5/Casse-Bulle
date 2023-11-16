#include "brick.h"


Brick::Brick(float x, float y, int initialHp)
    : hp(initialHp), isActive(true)
{
    shape.setSize(sf::Vector2f(70, 30)); 
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Green); 
}

void Brick::draw(sf::RenderWindow& window)
{
    if (isActive)
    {
        window.draw(shape);
    }
}

bool Brick::isAlive() const
{
    return isActive && hp > 0;
}

void Brick::takeDamage()
{
    if (isActive)
    {
        hp--;
        if (hp <= 0)
        {
            isActive = false;
        }
    }
}
