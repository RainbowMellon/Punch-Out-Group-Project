#pragma once
#include "Player.h"
#include "Opponent.h"
#include "UIManager.h"

class Game
{
public:
	Game();
	~Game();
	//Main game, will glue everything together to make the game you play
	void play();
	//Sets the opponet the opponent pointer will point to
	void setOppo();

	

private:
	int time, points, round, playerKO, oppoKO, oppo;
	Player player;
	Opponent oppo;
	UIManager UI;
};

