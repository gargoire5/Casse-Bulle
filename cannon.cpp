#include "Cannon.h"

Cannon::Cannon(sf::RenderWindow& window) : window(window)
{
    position = sf::Vector2f(window.getSize().x / 2, window.getSize().y + 20);
    rectangle.setSize(sf::Vector2f(-170, 90));
    rectangle.setOrigin(rectangle.getSize().x, rectangle.getSize().y / 2);
    rectangle.setPosition(position);
    rectangle.setFillColor(sf::Color::White);
}

void Cannon::update(sf::Vector2i cursorPosition)
{
    float angle = std::atan2(cursorPosition.y - position.y, cursorPosition.x - position.x);
    rectangle.setRotation(angle * 180 / 3.1415);
}

void Cannon::draw()
{
    window.draw(rectangle);
}