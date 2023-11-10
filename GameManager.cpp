#include "GameManager.h"
#include "GameObject.h"


void GameManager::runGame() 
{
    GameObject c(200, 200, 50, sf::Color::Magenta);
    GameObject r(50, 350, 20, 200, sf::Color::Cyan);

    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(700, 1000), "Casse Bulles");
    sf::Clock clock;
    float deltaTime=0;
    

    //GameLoop
    while (oWindow.isOpen())
    {
        sf::Vector2u windowSize = oWindow.getSize();
        c.moveWithinScreen(windowSize, deltaTime);
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
            if (oEvent.type == sf::Event::MouseButtonPressed && oEvent.mouseButton.button == sf::Mouse::Left)
            {
                r.rotate(45.0f);
            }
            if (oEvent.type == sf::Event::KeyPressed && oEvent.key.code == sf::Keyboard::Right)
            {
                float movementSpeed = 20.f;
                c.move(movementSpeed * deltaTime, 0.0f);
                //c.moveWithinScreen(oWindow.getSize(),deltaTime);
            }
            if (oEvent.type == sf::Event::KeyPressed && oEvent.key.code == sf::Keyboard::Left)
            {
                float movementSpeed = 20.f;

                c.move(-movementSpeed * deltaTime, 0.0f);
                c.moveWithinScreen(oWindow.getSize(), deltaTime);
            }
            if (oEvent.type == sf::Event::KeyPressed && oEvent.key.code == sf::Keyboard::Up)
            {
                float movementSpeed = 20.f;

                c.move(0.0f, -movementSpeed * deltaTime);
                c.moveWithinScreen(oWindow.getSize(), deltaTime);
            }
            if (oEvent.type == sf::Event::KeyPressed && oEvent.key.code == sf::Keyboard::Down)
            {
                float movementSpeed = 20.f;

                c.move(0.0f, movementSpeed * deltaTime);
                c.moveWithinScreen(oWindow.getSize(), deltaTime);
            }
        }
        //UPDATE
        // 
        //DRAW
        oWindow.clear();
        c.Draw(oWindow);
        r.Draw(oWindow);
        oWindow.display();
        sf::Time elapsedTime = clock.restart();
        deltaTime = elapsedTime.asSeconds();
    }
}

