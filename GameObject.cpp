#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <iostream>

GameObject::GameObject(int p_positionX, int p_positionY, int p_radius) : shape(p_radius)
{
	shape.setPosition(p_positionX, p_positionY);
	shape.setFillColor(sf::Color::Blue);
}

GameObject::~GameObject()
{
	std::cout << "destructeur" << std::endl;
}

void GameObject::DrawCircle(sf::RenderTarget &target) {

	target.draw(shape);
}


//GameObject::GameObject(int positionX, int positionY, float hight, float width) {

//}


