#include <SFML/Graphics.hpp>
#include "Game.h"
#include "GlassJoe.h"
#include <iostream>


int main()
{
  sf::RenderWindow window(sf::VideoMode(512, 480), "Punch-Out");
  window.setFramerateLimit(60);
  //Setting up main view
  sf::View view;
  view.setCenter(0, 0);
  view.setSize(256, 220);

  //Loading stage sprite sheet
  sf::Texture stageT;
  sf::Sprite stageS;
  stageT.loadFromFile("punchout sprites/stage_SpriteSheet.png");
  stageS.setTexture(stageT);
  stageS.setTextureRect(sf::IntRect(0, 0, 1280, 960));

  Game game(window, view);

  while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
    
        window.draw(stageS);

        game.play(window,event,view);


        window.setView(view); //Comment this line out to see the full screen
        window.display();
    }
}
