#include "UIManager.h"
#include <SFML/Graphics.hpp>


UIManager::UIManager(&sf::RenderWindow newWindow, &sf::View newView)
{
  window = newWindow;
  view = newView;
}


UIManager::~UIManager()
{
  
}


void UIManager::winScreen(sf::float time)
{
  
}


void UIManager::loseScreen()
{
  
}


void UIManager::drawText(std::string text)
{
  
}


void UIManager::updatePlayerHealth(int damage)
{
  
}


void UIManager::updateOppoHealth(int damage)
{
  
}
