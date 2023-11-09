#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameObject::GameObject(int p_positionX, int p_positionY, int p_radius, sf::Color colorObject)
{
	pShape = new sf::CircleShape(p_radius);
	

	pShape->setPosition(p_positionX, p_positionY);
	pShape->setFillColor(colorObject);
	
}



GameObject::GameObject(int p_positionX, int p_positionY, float p_height, float p_width, sf::Color colorObject)
{
	pShape = new sf::RectangleShape(sf::Vector2f(p_height, p_width));



	pShape->setPosition(p_positionX, p_positionY);
	pShape->setFillColor(colorObject);
	pShape->setOrigin(p_width / 2, p_height / 2);
}

GameObject::~GameObject()
{
	std::cout << "destructeur" << std::endl;
}

void GameObject::rotate(float angle)
{
	pShape->setRotation(angle);
}

void GameObject::Draw(sf::RenderTarget &target) 
{
	target.draw(*pShape);
}



