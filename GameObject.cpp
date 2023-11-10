#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameObject::GameObject(int p_positionX, int p_positionY, int p_radius, sf::Color colorObject)
{
	pShape = new sf::CircleShape(p_radius);
	pShape->setPosition(p_positionX, p_positionY);
	pShape->setFillColor(colorObject);
}

GameObject::GameObject(int p_positionX, int p_positionY, float p_width, float p_height, sf::Color colorObject)
{
	pShape = new sf::RectangleShape(sf::Vector2f(p_width, p_height));
	pShape->setPosition(p_positionX, p_positionY);
	pShape->setFillColor(colorObject);
	pShape->setOrigin(p_width / 2, p_height);
}

GameObject::~GameObject()
{
	std::cout << "destructeur" << std::endl;
}

void GameObject::rotate(float angle) 
{
	float currentRotation = pShape->getRotation();
	pShape->setRotation(currentRotation + angle);
}

void GameObject::Draw(sf::RenderTarget &target) 
{
	target.draw(*pShape);
}

void GameObject::moveWithinScreen(const sf::Vector2u& screenSize, float deltaTime)
{
    sf::Vector2f newPosition = pShape->getPosition();

    // Assurez-vous que le cercle ne quitte pas le côté gauche ou le côté droit de l'écran
    if (newPosition.x - pShape->getRadius() < 0)
    {
        newPosition.x = pShape->getRadius();
    }
    else if (newPosition.x + pShape->getRadius() > screenSize.x)
    {
        newPosition.x = screenSize.x - pShape->getRadius();
    }

    // Assurez-vous que le cercle ne quitte pas le haut ou le bas de l'écran
    if (newPosition.y - pShape->getRadius() < 0)
    {
        newPosition.y = pShape->getRadius();
    }
    else if (newPosition.y + pShape->getRadius() > screenSize.y)
    {
        newPosition.y = screenSize.y - pShape->getRadius();
    }

    // Appliquer la nouvelle position
    pShape->setPosition(newPosition);
}

void GameObject::move(float offsetX, float offsetY)
{
    float fNewX = pShape->getPosition().x + offsetX;
    float fNewY = pShape->getPosition().y + offsetY;

    pShape->setPosition(fNewX, fNewY);
}




