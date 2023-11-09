#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{

public:


	GameObject(int positionX, int positionY, int radius, sf::Color colorObject);//Constructeur cercle


	GameObject(int positionX, int positionY, float height, float width, sf::Color colorObject);//Constructeur rectangle

	~GameObject();//Destructeur


	void Draw(sf::RenderTarget& target);

	void rotate(float angle);


private:

	int p_positionX, p_positionY, p_radius;
	float p_width, p_height;

	sf::Shape* pShape;

};

