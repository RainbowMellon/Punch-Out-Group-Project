#include "Opponent.h"
#include <string>
#include <SFML/Graphics.hpp>


UIManager::UIManager()
{

}


//pass a reference to the window and view for more convinent drawing
//pass a reference to the player to get access stats
UIManager::UIManager(sf::RenderWindow& newWindow, sf::View& newView, Player& newPlayer)
{
  window = &newWindow;
  view = &newView;
  player = &newPlayer;

  //player health on screen
  pHealth.setSize(sf::Vector2f(7, 48));
  pHealth.setFillColor(sf::Color::Black);
  pHealth.setOutlineThickness(0);

  //opponent health on screen
  oHealth.setSize(sf::Vector2f(7, 48));
  oHealth.setFillColor(sf::Color::Black);
  oHealth.setOutlineThickness(0);
}


UIManager::~UIManager()
{

}


//give the time on the win clock
void UIManager::winScreen(float time)
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
void UIManager::drawStats(Opponent& opponent)
{

}


//pass a refrence to the opponent to access the states
//used for inbetween fighting
void UIManager::roundStartScreen(Opponent& opponent)
{

}
