#include "Opponent.h"
#include "Player.h"


//this file is pretty much useless, we just need these constructors to exist for subclasses
Opponent::Opponent()
{

}


//Updates the opponent as the game progresses
void Opponent::update(int time, Player& mac, int round)
{

}


//Sets the health of the opponent
void Opponent::setHealth(int newHealth)
{
	health = newHealth;
}


Opponent::Opponent(int num)
{

}


//Draws the sprite of the opponent
void Opponent::draw(sf::RenderWindow& window)
{

}


//Returns the damage it will do to mac
int Opponent::getDamage()
{
	return damage;
}


//Returns the current health of the opponent
int Opponent::getHealth()
{
	return health;
}


//retruns the maxStamina mac will have for the fight
int Opponent::getStamina()
{
	return stamina;
}


//Returns whether or not the opponent was hit by mac
int Opponent::wasHit(Player& mac, int time)
{
	return 0;
}


//Returns if the opponent has a special intro before it moves to the center stage
bool Opponent::hasIntro()
{
	return false;
}


//Plays the special intro of the opponent, if it has one
void Opponent::Intro()
{
	
}


//Moves the opponent toword the center of the stage
void Opponent::toStage()
{
	
}


//Returns the file location of the music the oppoonent will use for thier special intro, if they have one
sf::String Opponent::introMusicFile()
{
	return sf::String();
}


//Returns the amount of times the opponent was hit
int Opponent::getTimesHit()
{
	return timesHit;
}


Opponent::~Opponent()
{

}
