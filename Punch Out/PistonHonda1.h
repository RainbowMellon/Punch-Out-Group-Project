#pragma once
#include "Opponent.h"
#include <SFML/Graphics.hpp>


class PistonHonda1 : public Opponent
{
public:
	PistonHonda1();
	~PistonHonda1();
	void update(int time, Player&);
	void draw(sf::RenderWindow&);
	int getHealth();
	int getDamage();
	int wasHit(Player&);
	void taunt(int);
	void jab(int);
	void hook(int);
	void idle(int);


private:
	int health, stamina, canDodgeCD, cantDodgeCD, rank, age, weight, punch;
	bool isInPattern, isStunned;
	std::string name, location, stats;
	sf::Sprite sprite;
	sf::Texture texture;
};