#include "Opponent.h"
//this file is pretty much useless, we just need these constructors to exist for subclasses

Opponent::Opponent()
{

}

void Opponent::update(int time)
{

}

void Opponent::setHealth(int newHealth)
{
	health = newHealth;
}

Opponent::Opponent(int num)
{

}

void Opponent::draw(sf::RenderWindow& window)
{

}

int Opponent::getDamage()
{
	return damage;
}

int Opponent::getHealth()
{
	return health;
}

Opponent::~Opponent()
{}



