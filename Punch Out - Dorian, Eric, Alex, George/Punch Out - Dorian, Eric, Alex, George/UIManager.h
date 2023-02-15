#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"


class UIManager
{
public:
  UIManager(&sf::RenderWindow, &sf::View);
  ~UIManager();
  void winScreen(float);
  void loseScreen();
  void drawText(std::string);
  void updatePlayerHealth(int);
  void updateOppoHealth(int);
  void drawStats(&Player, &Opponent);
  void roundStartScreen(&Player&, Opponent);

private:
  *sf::RenderWindow window;
  *sf::View view;
};

