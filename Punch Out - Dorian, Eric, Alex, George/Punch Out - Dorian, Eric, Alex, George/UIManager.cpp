#include "UIManager.h"
#include "Game.h"
#include <SFML/Graphics.hpp>


//pass a reference to the window and view for more convinent drawing
UIManager::UIManager(&sf::RenderWindow newWindow, &sf::View newView)
{
  window = newWindow;
  view = newView;
}


UIManager::~UIManager()
{
  
}


//give the time on the win clock
void UIManager::winScreen(sf::float time)
{
  
}


void UIManager::loseScreen()
{
  (*window).draw();
}

//give the text you want to draw
void UIManager::drawText(std::string text)
{
  
}


//give how much damage the player takes
void UIManager::updatePlayerHealth(int damage)
{
  
}


//give how much damage the player takes
void UIManager::updateOppoHealth(int damage)
{
  
}


//pass a refrence to the player and opponent to access the states
void UIManager::drawStats(&Player player, &Opponent opponent)
{
  
}


void roundStartScreen(&Player&, Opponent)
{
  
}
