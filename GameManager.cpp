#include "GameManager.h"
#include "GameObject.h"
#include <iostream>
#include <vector>
#include "ball.h"


void GameManager::runGame() 
{

    //Création des objects
    Ball ball(335, 825, 30, sf::Color::Yellow);
    std::vector<std::vector<GameObject*>> bricks;
    int numColBrick = 7;
    int numLigneBrick = 6;
    bricks.resize(numColBrick, std::vector<GameObject*>(numLigneBrick));
    
    for (int row = 0; row < numLigneBrick; ++row)
    {
        for (int col = 0; col < numColBrick; ++col)
        {
            sf::Color brickColor = (row % 2 == 0 && col % 2 == 0) ? sf::Color::Yellow : sf::Color::White;
            int brickX = 10 + (100 * col);
            int brickY = 10 + (50 * row);
            bricks[col][row]= new GameObject(brickX, brickY, 80, 30, brickColor);
        }
    }

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
                std::cout << "Coordonnées de la souris : x = " << mousePosition.x << ", y = " << mousePosition.y << std::endl;
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
            if (ballPosition.y - ballSize.y / 2 < -30)
            {
                direction.y = std::abs(direction.y);
            }
            // Bord inférieur
            if (ballPosition.y + ballSize.y / 2 > windowSize.y)
            {
                ball.setPosition(325, 825);
                ballLaunched = false;
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
        if (ballLaunched && ball.getPosition().y - ball.getSize().y / 2 < windowSize.y)
        {
            ball.draw(oWindow);
        }
        for (int col = 0; col < numColBrick; ++col)
        {
            for (int row = 0; row < numLigneBrick; ++row)
            {
                bricks[col][row]->Draw(oWindow);
                /*if (bricks[col][row]->isActive())
                {
                    bricks[col][row]->Draw(oWindow);
                }*/
            }
        }
        oWindow.display();
        sf::Time elapsedTime = clock.restart();
        deltaTime = elapsedTime.asSeconds();
    }
}