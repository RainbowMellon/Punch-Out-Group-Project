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
	std::string getUIStuff(int);
	int getPunch();
	
	bool hasIntro();
	sf::String introMusicFile();

	//Returns true while the character is doing his intro, returns false when it's done
	bool Intro();
	bool toStage();

private:
	int health, stamina, canDodgeCD, cantDodgeCD;
	int punch, jabsHit, upsHit, macPunch, timer;
	bool isInPattern, isStunned;
	std::string name, location, stats, rank, age, weight;
	sf::Sprite sprite;
	sf::Texture texture;
};
