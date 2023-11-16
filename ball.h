#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Ball : public GameObject
{
public:
    Ball(int positionX, int positionY, int radius, sf::Color color);
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;

private:
    sf::CircleShape shape;
};

