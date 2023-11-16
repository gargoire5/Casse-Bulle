#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Brick
{
public:
    Brick(float x, float y, int initialHp);
    void draw(sf::RenderWindow& window);
    bool isAlive() const;
    void takeDamage();

private:
    sf::RectangleShape shape;
    int hp;
    bool isActive;
};