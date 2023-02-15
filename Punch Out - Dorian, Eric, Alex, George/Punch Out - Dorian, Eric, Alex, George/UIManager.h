#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Game.h"


class UIManager
{
public:
  UIManager(&sf::RenderWindow, &sf::View, &Player);
  ~UIManager();
  void winScreen(float);
  void loseScreen();
  void drawText(std::string);
  void drawStats(&Player, &Opponent);
  void roundStartScreen(&Player&, Opponent);

private:
  *sf::RenderWindow window;
  *sf::View view;
  Player player;
};

