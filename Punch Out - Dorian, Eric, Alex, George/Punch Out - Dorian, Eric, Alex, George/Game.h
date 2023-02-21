#pragma once
#include "Player.h"
#include "UIManager.h"

class Game
{
public:
	Game();
	~Game();
	void play(sf::RenderWindow&, sf::Event&, sf::View&);


	void setOppo();
	int getPlayerKO();
	void setPlayerKO();
	int getOppoKO();
	void setOppoKO();

private:
	int time, points, round, playerKO, oppoKO, state;
	Player littleMax;
	bool isKeyPressed;
	sf::View view;
	UIManager ui;
	sf::Music mainTheme;
};

