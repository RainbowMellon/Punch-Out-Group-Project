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

	
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::P) && moveCoolD <= 0) && !keyPressed) //punch forward
	{
		keyPressed = punching = true;
		dir = 1;//right punch
		moveCoolD = 20;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::O) && moveCoolD <= 0) && !keyPressed)
	{
		keyPressed = punching = true;
		dir = -1;//left punch
		moveCoolD = 20;
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) && moveCoolD <= 0) && !keyPressed) //Move right
	{
		keyPressed = true;
		moveCoolD = 30;
		dir = -2;
		sound.play();
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) && moveCoolD <= 0) && !keyPressed) //move left
	{
		keyPressed = true;
		moveCoolD = 30;
		dir = 2;
		sound.play();
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) && moveCoolD <= 0) && !keyPressed)
    {
		keyPressed = true;
		moveCoolD = 15;
		blocking = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && moveCoolD > 0 && blocking && !keyPressed)
	{
		keyPressed = true;
		moveCoolD = 20;
		blocking = false;
		dodging = true;

	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) && moveCoolD <= 0) && !keyPressed)
	{
		punching = true;
		moveCoolD = 30;
		dir = 10;
		upper = true;
	}

	if (upper)
	{
		if (moveCoolD > 25)
		{
			sprite.setTextureRect(sf::IntRect(125,26,25,61));
			moveCoolD--;
		}
		if (moveCoolD > 0)
			moveCoolD--;
		if (moveCoolD <= 0)
		{
			upper = false;
			punching = false;
			//sprite.setTextureRect(sf::IntRect(0, 27, 26, 61));
		}
	}

	else if (dodging)
	{
		if (moveCoolD > 0)
		{
			sprite.setTextureRect(sf::IntRect(399, 100, 25, 61));
			moveCoolD--;
		}
		else
		{
			sprite.setTextureRect(sf::IntRect(0, 26, 25, 61));
			dodging = false;
		}
	}

	else if (blocking)
	{
		if (moveCoolD > 0)
		{
			sprite.setTextureRect(sf::IntRect(374, 100, 25, 61));
			moveCoolD--;
		}
		else
		{
			sprite.setTextureRect(sf::IntRect(0, 26, 25, 61));
			blocking = false;
		}
	}
	
	else if (punching && dir != 10)
	{
		if(moveCoolD == 20 && dir == 1)//mirrors the sprite if it's right punching
			sprite.scale(-1, 1);
		if (moveCoolD > 15)
		{
			sprite.setTextureRect(sf::IntRect(132, 23, 27, 61));
			moveCoolD--;
		}
		else if (moveCoolD > 10)
		{
			sprite.setTextureRect(sf::IntRect(163, 23, 28, 64));
			moveCoolD--;
		}
		else if (moveCoolD > 0)
		{
			sprite.setTextureRect(sf::IntRect(191, 17, 25, 67));
			if (moveCoolD == 10 && !upper)
				sprite.move(0, -10);
			moveCoolD--;
		}
		if (moveCoolD == 0)
		{
			sprite.move(0, 10);
			if(dir == 1)
				sprite.scale(-1, 1);
			punching = false;
			sprite.setTextureRect(sf::IntRect(0, 27, 25, 61));
		}
	}

	else  //if they aren't punching they're moving
	{
		if (moveCoolD > 15)
		{
			if (dir < 0)
				sprite.setTextureRect(sf::IntRect(50, 100, 25, 61)); // when it gets to this point change the rect on the texture
			else
				sprite.setTextureRect(sf::IntRect(100, 100, 25, 61));
			sprite.move(sf::Vector2f(dir, 0));
			moveCoolD--;
		}
		else if (moveCoolD > 10)
		{
			sprite.setTextureRect(sf::IntRect(26, 27, 25, 61)); // when it gets to this point change the rect on the texture
			sprite.move(dir * -1, 0);
			moveCoolD--;
		}
		else if (moveCoolD > 0)
		{
			sprite.setTextureRect(sf::IntRect(0, 27, 25, 61));
			sprite.move(sf::Vector2f(dir * -1, 0));
			moveCoolD--;
		}
	}
}


int Player::getHealth()
{
	return health;
}


int Player::getStarCount()
{
	return starCount;
}

bool Player::isPunching()
{
	return(punching && moveCoolD > 10 && moveCoolD < 15);
}


bool Player::isBlocking()
{
	return blocking;
}

Player::~Player() {}
