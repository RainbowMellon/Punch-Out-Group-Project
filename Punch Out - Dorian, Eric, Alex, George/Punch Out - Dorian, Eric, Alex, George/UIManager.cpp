#include "UIManager.h"
#include "Game.h"
#include <string>
#include <SFML/Graphics.hpp>


//pass a reference to the window and view for more convinent drawing
//pass a reference to the player to get access stats
UIManager::UIManager(&sf::RenderWindow newWindow, &sf::View newView, &Player newPlayer)
{
  window = newWindow;
  view = newView;
  player = newPlayer;
}


UIManager::~UIManager()
{
  
}


//give the time on the win clock
void UIManager::winScreen(sf::float time)
{
  //view.setCenter(0, 0);
  //coordinate of the win screen
  //view.move(?, ?);
  
  //how long it took to win
  //window.draw(sf::Text(std::to_string(time)));
}


void UIManager::loseScreen()
{
  
}

//give the text you want to draw
void UIManager::drawText(std::string text)
{
  
}


//pass a refrence to the opponent to access the states
//used for while fighting
void UIManager::drawStats(&Opponent opponent)
{
  
}


//pass a refrence to the opponent to access the states
//used for inbetween fighting
void roundStartScreen(&Opponent opponent)
{
  
}
