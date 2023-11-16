#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameObject::GameObject(float positionX, float positionY, float width, float height, sf::Color colorObject)
{
	pShape = new sf::RectangleShape(sf::Vector2f(width, height));
	pShape->setPosition(positionX, positionY);
	pShape->setFillColor(colorObject);
}

GameObject::GameObject(float positionX, float positionY, int radius, sf::Color colorObject)
{
	pShape = new sf::CircleShape(radius);
	pShape->setPosition(positionX, positionY);
	pShape->setFillColor(colorObject);
}

GameObject::~GameObject()
{
	std::cout << "destructeur" << std::endl;
}
/*
void GameObject::rotate(float angle)
{
	float angle = std::atan2(cursorPosition.y - position.y, cursorPosition.x - position.x);
	shape.setRotation(angle * 180 / 3.1415);
}*/

void GameObject::setPosition(float x, float y)
{
	pShape->setPosition(x, y);
}

void GameObject::Draw(sf::RenderTarget &target) 
{
	target.draw(*pShape);
}
/*
void GameObject::move(sf::Vector2f drt, float tps)
{
	float vitesse = 300;
	// a mettre dans une fonction maths
	float norme = std::sqrt(drt.x * drt.x + drt.y * drt.y);
	drt.x = drt.x / norme;
	drt.y = drt.y / norme;
	//
    float fNewX = pShape->getPosition().x + (drt.x * tps * vitesse);
    float fNewY = pShape->getPosition().y + (drt.y * tps * vitesse);
    pShape->setPosition(fNewX, fNewY);
}*/

bool GameObject::CheckCollisions(const GameObject& goOther) 
{
	if (pShape->getGlobalBounds().intersects(goOther.pShape->getGlobalBounds())) {
		std::cout << "collision";
		return true;
	}
		

	return false;
}


sf::Vector2f GameObject::getSize() const
{
	if (pShape->getPointCount() == 0) {
		return sf::Vector2f(0, 0);
	}

	sf::FloatRect bounds = pShape->getLocalBounds();
	return sf::Vector2f(bounds.width, bounds.height);
}

sf::Vector2f GameObject::getPosition() const
{
	return pShape->getPosition();
}