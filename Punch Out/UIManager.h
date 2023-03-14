#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "Player.h"
#include "Opponent.h"


class UIManager
{
public:
  UIManager();
  UIManager(sf::RenderWindow&, sf::View&, Player&);
  ~UIManager();
  void setPointers(sf::RenderWindow&, sf::View&, Player&);
  void winScreen(float);
  void loseScreen();
  void drawText(std::string);
  void drawStats(Player&, Opponent&, int, int);
  void roundStartScreen(Player&, Opponent&);

private:
  sf::RenderWindow *window;
  sf::View *view;
  Player *player;
  sf::RectangleShape pHealth, oHealth;
};
