#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Cannon
{
public:
    Cannon(sf::RenderWindow& window);
    void update(sf::Vector2i cursorPosition);
    void draw();

private:
    sf::RectangleShape rectangle;
    sf::Vector2f position;
    sf::RenderWindow& window;
};