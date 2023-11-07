#include <SFML/Graphics.hpp>
#include "GameObject.h"

int main(int argc, char** argv)
{

    

    //Création d'une fenêtre
    sf::RenderWindow oWindow(sf::VideoMode(640, 480), "SFML");

    
   

    GameObject g(50, 50, 50);

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

        //UPDATEw

        //DRAW
        oWindow.clear();

        g.DrawCircle(oWindow);
        

        oWindow.display();
    }

    return 0;
}