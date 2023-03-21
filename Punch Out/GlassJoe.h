#pragma once
#include "Opponent.h"
#include <SFML/Graphics.hpp>

class GlassJoe : public Opponent
{
public:
	GlassJoe();
	~GlassJoe();
	void update(int time);
	void draw(sf::RenderWindow&);
	int getHealth();
	int getDamage();
	int getStamina();
	void wasHit(Player&);
	void vive(int);
	void jab(int);
	void hook(int);
	void idle(int);
	

private:
	int health, stamina, canDodgeCD, cantDodgeCD, rank, age, weight,punch,jabsHit,upsHit;
	bool isInPattern, isStunned;
	std::string name, location, stats;
	sf::Sprite sprite;
	sf::Texture texture;
};
