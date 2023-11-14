#pragma once
#include <SFML/Graphics.hpp>

class GameObject
{
public:
	GameObject(int positionX, int positionY, int radius, sf::Color colorObject);//Constructeur cercle
	GameObject(int positionX, int positionY, float width, float height, sf::Color colorObject);//Constructeur rectangle
	~GameObject();//Destructeur
	void Draw(sf::RenderTarget& target);
	void move(sf::Vector2f drt, float tps);
	void rotate(float angle);
	void setPosition(float x, float y);
	bool isActive() const;
	void setActive(bool active);
	sf::Vector2f getPosition() const
	{
		return pShape->getPosition();
	}
	sf::Vector2f getSize() const;
private:
	int p_positionX, p_positionY, p_radius;
	float p_width, p_height;
	sf::Shape* pShape;
	bool active;
};