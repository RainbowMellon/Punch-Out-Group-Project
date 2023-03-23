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
	void update();
	void draw();
	int getHealth();
	int getDamage();
	int getStarCount();
	int getStamina();
	int isPunching();
	bool isDodging();
	bool isBlocking();
	bool getWinded();
	void punchMac(int);
private:

	sf::Sprite sprite;
	sf::Texture texture;
	int moveCoolD, dir, starCount, damage, health, action, punch, aniCoolD, stamina, struggle;
	bool isWinded, keyPressed, blocking, dodging, upper, knockedDown;
	sf::SoundBuffer buffer;
	sf::Sound sound;
};
