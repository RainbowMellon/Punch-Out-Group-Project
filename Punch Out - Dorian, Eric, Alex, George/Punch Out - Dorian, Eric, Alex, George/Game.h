#pragma once
#include<SFML\Graphics.hpp>
#include"Player.h"
#include"Opponent.h"
#include"UIManager.h"


class Game
{
public:
	Game(sf::RenderWindow&);
	~Game();


	//the input int indexes for glass joe being 0 ect
	void setOppo();
	int getPlayerKO();
	void setPlayerKO();
	int getOppoKO();
	void setOppoKO();
	

	Opponent getOppo();
private:
	int time, points, round, playerKO, oppoKO;
	sf::View view;
	Player player;
	Opponent opponent;
	UIManager ui;
};
