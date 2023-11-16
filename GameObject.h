#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(float positionX, float positionY, float width, float height, sf::Color colorObject);
	GameObject(float positionX, float positionY, int radius, sf::Color colorObject);
	~GameObject();
	//void rotate(float angle);
	virtual bool CheckCollisions(const GameObject& goOther);
	void Draw(sf::RenderTarget& target);
	void move(sf::Vector2f drt, float tps);
	void setPosition(float x, float y);
	sf::Vector2f getPosition() const;
	sf::Vector2f getSize() const;

protected : 
	
private: 
	float p_width, p_height, p_positionX, p_positionY;
	int  p_radius;
	sf::Shape* pShape;
};