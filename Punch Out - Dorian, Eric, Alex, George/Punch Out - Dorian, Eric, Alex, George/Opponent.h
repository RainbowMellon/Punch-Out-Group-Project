#pragma once
#include <string>
class Opponent
{
public:
	Opponent(int);
	Opponent();
	~Opponent();
	virtual void update()=0;
	virtual void draw()=0;
	int getHealth();
	virtual int getDamage()=0;
	virtual void wasHit(Player&)=0;


private:
	int health, damage, stamina, canDodgeCD, cantDodgeCD, rank, age, weight;
	/*Health is the number of hp the opponent has left, damage is how much they do 
	to mac, cool downs for when the opponent can dodge, and nums for the screens
	between the rounds*/
	bool isInPattern, isStunned;
	//Whether or not the opponent is in a pattern or stunned
	std::string name, location, stats;
	//for the screens before and between rounds
};

