#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>


int main()
{
  sf::RenderWindow window(sf::VideoMode(512, 480), "Punch-Out");
  window.setFramerateLimit(60);
  //Setting up main view
  sf::View view;
  view.setCenter(512/4, 480/4);
  view.setSize(256, 220);

  //Loading stage sprite, place holder,
  sf::Texture stage;
  sf::Sprite stageT;
  stage.loadFromFile("PunchoutStage.png");
  stageT.setTexture(stage);
  stageT.setTextureRect(sf::IntRect(0, 0, 256, 240));
  
  //Rectangles, too see if I'm getting the viewing right
  sf::RectangleShape rect;
  rect.setSize(sf::Vector2f(256, 240));
  rect.setPosition(256, 0);
  rect.setFillColor(sf::Color(0, 0, 255));

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
    
        window.draw(stageT);
        game.play(window,event,view);
        window.draw(rect);

        window.setView(view); //Comment this line out to see the full screen
        window.display();
    }
}
