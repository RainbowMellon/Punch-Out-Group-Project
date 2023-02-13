#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>


int main()
{
  sf::RenderWindow window(sf::VideoMode(1536, 960), "Punch-Out");
  sf::View view(sf::FloatRect(0, 0, 512, 480));
  
  Game game;
  
  while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
    
        // window.draw(...);

        window.display();
    }
}
