#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Ball : public GameObject 
{
public:
    Ball(int positionX, int positionY, int radius, sf::Color color);
    virtual bool CheckCollisions(const GameObject& goOther) const;
    void setPosition(float x, float y);
    void move(sf::Vector2f direction, float deltaTime);
    void Draw(sf::RenderTarget& target);
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
private:
    sf::CircleShape shape;
};

