#include "GameManager.h"
#include "GameObject.h"
#include <iostream>


void GameManager::runGame() 
{
    GameObject c(200, 200, 50, sf::Color::Magenta);
    GameObject r(50, 350, 20, 200, sf::Color::Cyan);
    GameObject ball(335, 825, 30, sf::Color::Yellow);

    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(700, 1000), "Casse Bulles");
    sf::Clock clock;
    sf::Vector2f direction;
    float deltaTime=0;
    bool ballLaunched = false;

    //GameLoop
    while (oWindow.isOpen())
    {
        sf::Vector2u windowSize = oWindow.getSize();
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
            if (oEvent.type == sf::Event::MouseButtonPressed && oEvent.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(oWindow);
                direction.x = mousePosition.x - ball.getPosition().x;
                direction.y = mousePosition.y - ball.getPosition().y;
                ballLaunched = true;
            }
        }
        //UPDATE
        if (ballLaunched)
        {
            ball.move(direction, deltaTime);
        }
        //DRAW
        oWindow.clear();
        ball.Draw(oWindow);
        c.Draw(oWindow);
        r.Draw(oWindow);
        oWindow.display();
        sf::Time elapsedTime = clock.restart();
        deltaTime = elapsedTime.asSeconds();
    }
}