#pragma once
#include <string>
#include "Player.h"
#include <SFML/Graphics.hpp>

class Opponent
{
public:
	Opponent(int);
	Opponent();
	~Opponent();
	virtual void update(int);
	virtual void draw(sf::RenderWindow&);
	int getHealth();
	int getStamina();
	virtual void setHealth(int);
	virtual int getDamage();
	//virtual void wasHit(Player&)=0;  <--somethings broken


protected:
	int health, damage, stamina, canDodgeCD, cantDodgeCD, rank, age, weight;
	/*Health is the number of hp the opponent has left, damage is how much they do 
	to mac, cool downs for when the opponent can dodge, and nums for the screens
	between the rounds*/
	bool isInPattern, isStunned;
	//Whether or not the opponent is in a pattern or stunned
	std::string name, location, stats;
	//for the screens before and between rounds
};
