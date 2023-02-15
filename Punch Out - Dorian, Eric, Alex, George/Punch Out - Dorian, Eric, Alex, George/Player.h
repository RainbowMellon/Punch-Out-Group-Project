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
	/*
	position is what position mac is in
	0 = standing still
	1 = dodging right 
	2 = dodging back
	3 = dodging left
	4 = blocking
	*/
	int position;
	bool isWinded;
};
