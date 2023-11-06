#pragma once

class GameObject
{
private:

	int positionX, positionY, radius;
	float width, height;

public:

	GameObject(int postionX, int positionY, float width, float height, int radius);//Constructeur
	~GameObject();//Destructeur


	void DrawRect();




};

