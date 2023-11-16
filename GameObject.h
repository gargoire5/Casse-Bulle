#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(int positionX, int positionY, float width, float height, sf::Color colorObject);
	GameObject(int positionX, int positionY, int radius, sf::Color colorObject);
	//Constructeur rectangle
	~GameObject();//Destructeur
	void rotate(float angle);
	void Draw(sf::RenderTarget& target);
	void move(sf::Vector2f drt, float tps);
	void setPosition(float x, float y);
	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;
private:
	int p_positionX, p_positionY, p_radius;
	float p_width, p_height;
	sf::Shape* pShape;
};