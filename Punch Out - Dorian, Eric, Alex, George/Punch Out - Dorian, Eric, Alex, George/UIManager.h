#pragma once
#include <SFML/Graphics.hpp>


class UIManager
{
public:
  UIManager();
  ~UIManager();
  void winScreen(float);
  void loseScreen();
  void drawText(string);
  //give how much to take away
  void updatePlayerBar(int);
  void updateOppoBar(int);

private:
  
};

