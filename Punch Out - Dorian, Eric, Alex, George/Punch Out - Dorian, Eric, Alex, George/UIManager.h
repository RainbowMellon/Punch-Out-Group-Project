#pragma once
#include <SFML/Graphics.hpp>
#include <string>


class UIManager
{
public:
  UIManager(&sf::RenderWindow, &sf::View);
  ~UIManager();
  void winScreen(float);
  void loseScreen();
  void drawText(std::string);
  //give how much to take away
  void updatePlayerHealth(int);
  void updateOppoHealth(int);

private:
  *sf::RenderWindow window;
  *sf::View view;
};

