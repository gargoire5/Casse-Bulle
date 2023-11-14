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

sf::Vector2f GameObject::getSize() const
{
	if (pShape->getPointCount() == 0) {
		return sf::Vector2f(0, 0);
	}

	sf::FloatRect bounds = pShape->getLocalBounds();
	return sf::Vector2f(bounds.width, bounds.height);
}

void GameObject::setPosition(float x, float y)
{
	pShape->setPosition(x, y);
}

void GameObject::Draw(sf::RenderTarget &target) 
{
	target.draw(*pShape);
}

void GameObject::move(sf::Vector2f drt, float tps)
{
	float vitesse = 420;
	// a mettre dans une fonction maths
	float norme = std::sqrt(drt.x * drt.x + drt.y * drt.y);
	drt.x = drt.x / norme;
	drt.y = drt.y / norme;
	//
    float fNewX = pShape->getPosition().x + (drt.x * tps * vitesse);
    float fNewY = pShape->getPosition().y + (drt.y * tps * vitesse);
    pShape->setPosition(fNewX, fNewY);
}