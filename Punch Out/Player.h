#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Player
{
public:
	Player();
	~Player();
	void updatePlayer(sf::Event&);
	void drawPlayer(sf::RenderWindow&);
	int getHealth();
	int getDamage();
	int getStarCount();
	int getStamina();
	int isPunching();
	int getAction();
	bool isDodging();
	bool isBlocking();
	bool getWinded();
	void punchMac(int, int);
	void setHealth(int);
	int getPunch();
	int getMoveCD();
private:

	sf::Sprite sprite;
	sf::Texture texture;
	int moveCoolD, dir, starCount, health, action, punch, aniCoolD, stamina, struggle;
	bool isWinded, keyPressed, blocking, dodging, upper, knockedDown, punched;
	sf::SoundBuffer buffer;
	sf::Sound sound;
};
