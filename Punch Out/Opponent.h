#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Player.h"


//Opponent is a class ment to be a rule for it's children to follow. So that in game
//The opponent methods don't change but whatever the opponetn pointer is pointing to does
class Opponent
{
public:
	Opponent(int);
	Opponent();
	~Opponent();
	virtual void update(int, Player&,int);
	virtual void draw(sf::RenderWindow&);
	virtual int getHealth();
	virtual int getStamina();
	virtual void setHealth(int);
	virtual int getDamage();
	virtual int wasHit(Player&, int);
	virtual bool hasIntro();
	virtual std::string getUIStuff(int)=0;
	virtual sf::String introMusicFile();
	//Returns true while the character is doing his intro, returns false when it's done
	virtual void Intro();
	//Returns true while the opponent is moving toward the middle stage, returns false if it isn't there yet
	virtual void toStage();
	virtual int getTimesHit();



protected:
	int health, damage, stamina, canDodgeCD, cantDodgeCD, rank, age, weight, round, timesHit;
	/*Health is the number of hp the opponent has left, damage is how much they do 
	to mac, cool downs for when the opponent can dodge, and nums for the screens
	between the rounds*/
	bool isInPattern, isStunned;
	//Whether or not the opponent is in a pattern or stunned
	std::string name, location, stats;
	//for the screens before and between rounds
};
