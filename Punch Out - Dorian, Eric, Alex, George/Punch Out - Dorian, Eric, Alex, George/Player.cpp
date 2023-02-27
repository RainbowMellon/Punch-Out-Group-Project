#include "Player.h"
#include <iostream>

Player::Player()
{
	isWinded = false;
	keyPressed = false;
	moveCoolD = 0;
	dir = 0;
	texture.loadFromFile("punchout sprites/little-mac.png"); //FullSpriteSheet
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 27, 25, 61)); //Just a rectangle covering the sprite sheet
	sprite.scale(1.2, 1.2);
	sprite.setOrigin(25 / 2, 61 / 2);
	sprite.setPosition(256 / 2, 240 * 0.75);

	buffer.loadFromFile("sounds/Dodge.flac");
	sound.setBuffer(buffer);
}

void Player::drawPlayer(sf::RenderWindow& window)
{
	window.draw(sprite);
}

void Player::updatePlayer(sf::Event& event)
{

	if (event.type == sf::Event::KeyReleased) //No repeating keys if key is held down
		keyPressed = false;


	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) && moveCoolD <= 0) && !keyPressed) //Move right
	{
		keyPressed = true;
		moveCoolD = 50;
		dir = -2;
		sound.play();
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) && moveCoolD <= 0) && !keyPressed) //move left
	{
		keyPressed = true;
		moveCoolD = 50;
		dir = 2;
		sound.play();
	}


	if (moveCoolD > 30)
	{
		if (dir < 0)
			sprite.setTextureRect(sf::IntRect(50, 100, 25, 61)); // when it gets to this point change the rect on the texture
		else
			sprite.setTextureRect(sf::IntRect(100, 100, 25, 61));
		sprite.move(sf::Vector2f(dir, 0));
		moveCoolD--;
	}
	else if (moveCoolD > 20)
	{

		moveCoolD--;
	}
	else if (moveCoolD > 0)
	{
		sprite.setTextureRect(sf::IntRect(0, 27, 25, 61));
		sprite.move(sf::Vector2f(dir * -1, 0));
		moveCoolD--;
	}
}

Player::~Player() {}


