#include "Opponent.h"
#include "Player.h"
//this file is pretty much useless, we just need these constructors to exist for subclasses

Opponent::Opponent()
{

}

void Opponent::update(int time, Player& mac)
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


int Opponent::getStamina()
{
	return stamina;
}

bool Opponent::wasHit(Player& mac, int time)
{
	return false;
}
Opponent::~Opponent()
{}


bool Opponent::hasIntro()
{
	return false;
}

bool Opponent::Intro()
{
	return false;
}

bool Opponent::toStage()
{
	return false;
}

sf::String Opponent::introMusicFile()
{
	return sf::String();
}

