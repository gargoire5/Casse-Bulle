#include <SFML/Graphics.hpp>
#include "GameObject.h"

int main(int argc, char** argv)
{


    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");

  
    GameObject c(50, 50, 50, sf::Color::Magenta);
    
    GameObject r(0, 0, 50, 50, sf::Color::Cyan);

    //GameLoop
    while (oWindow.isOpen())
    {
        //EVENT
        sf::Event oEvent;
        while (oWindow.pollEvent(oEvent))
        {
            if (oEvent.type == sf::Event::Closed)
                oWindow.close();
        }

        //UPDATE



        //DRAW
        oWindow.clear();

        c.Draw(oWindow);

        r.Draw(oWindow);
        

        oWindow.display();
    }

    return 0;
}