#pragma once
#include "Opponent.h"
class GlassJoe : public Opponent
{
public:
	GlassJoe();
	~GlassJoe();
	void update();
	void draw();
	int getHealth();
	int getDamage();
	void wasHit(Player&);
private:
	int health, stamina, canDodgeCD, cantDodgeCD, rank, age, weight;
	bool isInPattern, isStunned;
	std::string name, location, stats;
};

