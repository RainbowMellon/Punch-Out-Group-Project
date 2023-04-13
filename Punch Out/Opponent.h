#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Player.h"

class Opponent
{
public:
	Opponent(int);
	Opponent();
	~Opponent();
	virtual void update(int, Player&);
	virtual void draw(sf::RenderWindow&);
	virtual int getHealth();
	virtual int getStamina();
	virtual void setHealth(int);
	virtual int getDamage();
	virtual bool wasHit(Player&, int);
	virtual bool hasIntro();
	virtual std::string getUIStuff(int)=0;
	virtual sf::String introMusicFile();
	//Returns true while the character is doing his intro, returns false when it's done
	virtual bool Intro();
	//Returns true while the opponent is moving toward the middle stage, returns false if it isn't there yet
	virtual bool toStage();



protected:
	int health, damage, stamina, canDodgeCD, cantDodgeCD, rank, age, weight,round;
	/*Health is the number of hp the opponent has left, damage is how much they do 
	to mac, cool downs for when the opponent can dodge, and nums for the screens
	between the rounds*/
	bool isInPattern, isStunned;
	//Whether or not the opponent is in a pattern or stunned
	std::string name, location, stats;
	//for the screens before and between rounds
};
