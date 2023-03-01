#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Opponent.h"

class Player
{
public:
	Player();
	~Player();
	void updatePlayer(sf::Event&);
	void drawPlayer(sf::RenderWindow&);
	void update();
	void draw();
	int getHealth();
	int getDamage();
	int getStarCount();
	//void wasHit(Opponent);  <--somethings broken

private:
	sf::Sprite sprite;
	sf::Texture texture;
	int moveCoolD, dir, startCount, damage, health;
	bool isWinded, keyPressed, punching;
	sf::SoundBuffer buffer;
	sf::Sound sound;
};

