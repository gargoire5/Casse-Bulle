#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
public:
    Ball(int positionX, int positionY, int radius, sf::Color color);
    void move(sf::Vector2f direction, float deltaTime);
    void draw(sf::RenderTarget& target) const;
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;

private:
    sf::CircleShape shape;
};

