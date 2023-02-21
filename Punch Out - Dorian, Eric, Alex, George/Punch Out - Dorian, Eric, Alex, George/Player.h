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

private:
	sf::Sprite sprite;
	sf::Texture texture;
	int moveCoolD, dir, startCount, damage, health;
	bool isWinded, keyPressed;
	sf::SoundBuffer buffer;
	sf::Sound sound;
};

