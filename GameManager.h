#pragma once
#include <SFML/Graphics.hpp>

class GameManager
{
public:
	static GameManager& getInstance() 
	{
		static GameManager instance;
		return instance;
	}
	void runGame();
private:
    GameManager() {}
};