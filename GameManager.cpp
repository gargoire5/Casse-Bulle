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
            sf::Vector2f ballPosition = ball.getPosition();
            sf::Vector2f ballSize = ball.getSize();
            //Bord Supérieur
            if (ballPosition.y - ballSize.y / 2 < 0-30)
            {
                direction.y = std::abs(direction.y);
            }
            // Bord inférieur
            if (ballPosition.y + ballSize.y / 2 > windowSize.y-30)
            {
                direction.y = -std::abs(direction.y);
            }
            // Bord gauche
            if (ballPosition.x - ballSize.x / 2 < -30)
            {
                direction.x = std::abs(direction.x);
            }
            // Bord droit
            if (ballPosition.x + ballSize.x / 2 > windowSize.x-30)
            {
                direction.x = -std::abs(direction.x);
            }
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