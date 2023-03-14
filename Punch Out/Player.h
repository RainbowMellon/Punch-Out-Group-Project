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
	int isPunching();
	bool isDodging();
	bool isBlocking();
	bool getWinded();
private:

	sf::Sprite sprite;
	sf::Texture texture;
	int moveCoolD, dir, starCount, damage, health, action, punch, aniCoolD;
	bool isWinded, keyPressed, blocking, dodging, upper;
	sf::SoundBuffer buffer;
	sf::Sound sound;
};

