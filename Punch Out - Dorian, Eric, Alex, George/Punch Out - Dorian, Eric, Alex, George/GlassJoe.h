#pragma once
#include "Opponent.h"
class GlassJoe : public Opponent
{
public:
	GlassJoe();
	~GlassJoe();
	void update();
	virtual void draw();
	int getHealth();
	virtual int getDamage();
	virtual void wasHit(Player&);
private:
	int health, stamina, canDodgeCD, cantDodgeCD, rank, age, weight;
	bool isInPattern, isStunned;
	std::string name, location, stats;
};

