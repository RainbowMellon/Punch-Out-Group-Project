#pragma once
#include "Opponent.h"
#include <SFML/Graphics.hpp>

class GlassJoe : public Opponent
{
public:
	GlassJoe();
	~GlassJoe();
	void update(sf::Event&);
	void draw(sf::RenderWindow&);
	int getHealth();
	int getDamage();
	void wasHit(Player&);
private:
	int health, stamina, canDodgeCD, cantDodgeCD, rank, age, weight;
	bool isInPattern, isStunned;
	std::string name, location, stats;
	sf::Sprite sprite;
	sf::Texture texture;
};