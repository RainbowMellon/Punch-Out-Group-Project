#pragma once
#include "Player.h"
#include "UIManager.h"
#include "Opponent.h"
#include "GlassJoe.h"

class Game
{
public:
	Game(sf::RenderWindow&, sf::View&);
	~Game();
	void play(sf::RenderWindow&, sf::Event&, sf::View&);


	void setOppo();
	int getPlayerKO();
	void setPlayerKO();
	int getOppoKO();
	void setOppoKO();

private:
	int time, points, round, playerKO, oppoKO, state;
	sf::View view;
	Player littleMac;
	Opponent *opponent;
	//UIManager uiManager;
	sf::Music mainTheme;
	bool isKeyPressed;
	GlassJoe joe;
};

