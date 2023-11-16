#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Cannon : public GameObject
{
public:
    Cannon(sf::RenderWindow& window);
    void update(sf::Vector2i cursorPosition);

private:
    sf::RectangleShape rectangle;
    sf::Vector2f position;
    sf::RenderWindow& window;
};
