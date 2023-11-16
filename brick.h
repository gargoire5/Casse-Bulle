#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Brick : public GameObject
{
public:
    Brick() : GameObject(0, 0, 0, 0, sf::Color::White), hp(0), isActive(false) {}
    Brick(float x, float y, float width, float height, sf::Color color, int initialHp);
    bool isAlive() const;
    void takeDamage();

private:
    int hp;
    bool isActive;
};