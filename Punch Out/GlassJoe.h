#pragma once
#include "Opponent.h"
#include <SFML/Graphics.hpp>

class GlassJoe : public Opponent
{
public:
	GlassJoe();
	~GlassJoe();
	void update(int time,Player&);
	void draw(sf::RenderWindow&);
	int getHealth();
	void setHealth(int);
	int getDamage();
	int getStamina();
	bool wasHit(Player&, int);
	void vive(int);
	void jab(int);
	void hook(int);
	void idle(int);
	int getPunch();
	

private:
	int health, stamina, canDodgeCD, cantDodgeCD, rank, age, weight;
	int punch, jabsHit, upsHit, macPunch;
	bool isInPattern, isStunned;
	std::string name, location, stats;
	sf::Sprite sprite;
	sf::Texture texture;
};
