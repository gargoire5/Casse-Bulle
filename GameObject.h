#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{

public:


	GameObject(int positionX, int positionY, int radius);//Constructeur cercle

	void DrawCircle(sf::RenderTarget &target);


	//GameObject(int positionX, int positionY, float hight, float width);//Constructeur rectangle

	~GameObject();//Destructeur


	// DrawcCircle(sf::CircleShape cercle());

	


private:

	int p_positionX, p_positionY, p_radius;
	float p_width, p_height;

	sf::CircleShape shape;

};

