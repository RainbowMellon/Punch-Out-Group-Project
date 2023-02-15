#pragma once
#include"Opponent.h"

class Player
{
public:
	Player();
	~Player();

	void draw();
	void update();
	//health is the heart points that make you wended
	int getHealth();
	//damage is your hp bar that determines when you get ko'd
	int getDamage();
	int getStarCount();
	void wasHit(Opponent&);


private:
	//moveCD is move cooldown
	int health, damage, starCount, moveCD;
	bool isWinded;
};
