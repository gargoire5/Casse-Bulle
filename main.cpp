#include <SFML/Graphics.hpp>
#include "GameManager.h"

int main(int argc, char** argv)
{
    GameManager::getInstance().runGame();
    return 0;
}