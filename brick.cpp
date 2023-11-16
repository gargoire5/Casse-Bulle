#include "Brick.h"

Brick::Brick(float x, float y, float width, float height, sf::Color color, int initialHp)
    : GameObject(x, y, width, height, color), hp(initialHp), isActive(true)
{
    
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