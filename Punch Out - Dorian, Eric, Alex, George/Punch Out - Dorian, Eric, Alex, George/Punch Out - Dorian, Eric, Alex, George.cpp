#include <SFML/Graphics.hpp>
#include "Game.h"


int main()
{
  sf::RenderWindow window(sf::VideoMode(512, 480), "Punch-Out");
  
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
