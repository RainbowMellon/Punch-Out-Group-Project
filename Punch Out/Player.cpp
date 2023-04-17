#include "Player.h"
#include <iostream>

Player::Player()
{
	isWinded = false;
	keyPressed = false;
	action = 0;
	moveCoolD = 0;
	health = 96;
	stamina = 20;
	dir = 0;
	texture.loadFromFile("punchout sprites/little-mac.png"); //FullSpriteSheet
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 27, 25, 61)); //Just a rectangle covering the sprite sheet
	sprite.scale(1.1, 1.1);
	sprite.setOrigin(25 / 2, 61 / 2);
	sprite.setPosition(256 / 2, 240 * 0.75 - 10);
	buffer.loadFromFile("sounds/Dodge.flac");
	sound.setBuffer(buffer);
}

void Player::drawPlayer(sf::RenderWindow& window)
{
	window.draw(sprite);
}


/*
punch 1 = forward right punch
punch 2 = forward left punch
punch 3 = upper right punch
punch 4 = upper left punch
punch 5 = star punch
*/
void Player::updatePlayer(sf::Event& event)
{
	sprite.setScale(1.1, 1.1);


	if (event.type == sf::Event::KeyReleased) //No repeating keys if key is held down
		keyPressed = false;


	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::P) && moveCoolD <= 0) && !keyPressed && !isWinded) //punch forward
	{
		keyPressed = true;
		action = 1;
		dir = 1;//right punch
		moveCoolD = 20;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))//left upper
		{
			moveCoolD = 30;
			action = 3;
		}
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::O) && moveCoolD <= 0) && !keyPressed && !isWinded)
	{
		keyPressed = true;
		action = 2;
		dir = -1;//left punch
		moveCoolD = 20;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))//left upper
		{
			action = 4;
			moveCoolD = 30;
			upper = true;
		}
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) && moveCoolD <= 0) && !keyPressed) //Move right
	{
		keyPressed = true;
		action = 6;
		moveCoolD = 30;
		dir = -2;
		sound.play();
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) && moveCoolD <= 0) && !keyPressed) //move left
	{
		action = 7;
		keyPressed = true;
		moveCoolD = 30;
		dir = 2;
		sound.play();
	}
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) && moveCoolD <= 0) && !keyPressed && !isWinded)
	{
		action = 5;
		keyPressed = true;
		moveCoolD = 15;
		blocking = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && moveCoolD > 0 && blocking && !keyPressed)
	{
		action = 8;
		keyPressed = true;
		moveCoolD = 20;
		blocking = false;
		dodging = true;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && moveCoolD <= 0 && !keyPressed && !isWinded)
	{
		//star punch
		action = 9;
		moveCoolD = 55;
		keyPressed = true;
	}

	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::P) || sf::Keyboard::isKeyPressed(sf::Keyboard::O)) && knockedDown && moveCoolD <= 0)
	{
		aniCoolD -= 20;
	}

	//all this is temporary testing tools until we link up opponent and player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
	{
		//this is temp until the oppo actually punches
		action = 10;
		punch = 0;
		moveCoolD = 15;
		blocking = false;
		dodging = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal))
	{
		//this is temp until the oppo actually punches
		action = 11;
		punch = 0;
		moveCoolD = 15;
		blocking = false;
		dodging = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::U) && moveCoolD <= 0)
	{
		keyPressed = true;
		isWinded = !isWinded;
		moveCoolD = 5;
		aniCoolD = 200;
		action = 12;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && moveCoolD <= 0)
	{
		struggle = 12;
		knockedDown = true;
		action = 13;
		moveCoolD = 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && moveCoolD <= 0)
	{
		knockedDown = true;
		action = 13;
		aniCoolD = 200;
		moveCoolD = 8;
	}

	/*
	To-Do:
	make mac fall over when he runs out of health
	make mac able to get back up a total of 3 times a round
	make the heart system actually do something
	*/


	if (isWinded)
		sprite.setColor(sf::Color(250, 0, 255));
	else
		sprite.setColor(sf::Color(255, 255, 255));


	switch (action)
	{
	case 1://forward right punch
	{
		sprite.setScale(-1.1, 1.1);
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
			punch = 0;
			sprite.setTextureRect(sf::IntRect(191, 17, 25, 67));
			if (moveCoolD == 10)
			{
				punch = 1;
				std::cout << "thing" << std::endl;
				sprite.move(0, -10);
			}
			moveCoolD--;
		}
		if (moveCoolD == 0)
		{
			sprite.scale(-1, 1);
			sprite.move(0, 10);
			action = 0;
			sprite.setTextureRect(sf::IntRect(0, 27, 25, 61));
		}
		break;
	}
	case 2://forward left punch
	{
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
			punch = 0;
			if (moveCoolD == 10)
				punch = 2;
			sprite.setTextureRect(sf::IntRect(191, 17, 25, 67));
			if (moveCoolD == 10)
				sprite.move(0, -10);
			moveCoolD--;
		}
		if (moveCoolD == 0)
		{
			punch = 0;
			sprite.move(0, 10);
			action = 0;
			sprite.setTextureRect(sf::IntRect(0, 27, 25, 61));
		}
		break;
	}
	case 3://upper right punch
	{
		sprite.setScale(-1.1, 1.1);
		if (moveCoolD > 25)
		{
			sprite.setTextureRect(sf::IntRect(132, 23, 26, 61));
		}
		else if (moveCoolD > 20)
		{
			if (moveCoolD == 25)
				sprite.move(0, -10);
			sprite.setTextureRect(sf::IntRect(163, 22, 28, 61));
		}
		else if (moveCoolD > 15)
		{
			if (moveCoolD == 20)
				sprite.move(0, -10);
			sprite.setTextureRect(sf::IntRect(191, 19, 28, 70));
		}
		else if (moveCoolD > 10)
		{
			punch = 0;
			if (moveCoolD == 15)
				sprite.move(0, -10);
			if (moveCoolD == 15)
				punch = 3;
			sprite.setTextureRect(sf::IntRect(216, 7, 28, 83));
		}
		else if (moveCoolD > 5)
		{
			punch = 0;
			if (moveCoolD == 10)
				sprite.move(0, 20);
			sprite.setTextureRect(sf::IntRect(163, 22, 28, 61));
		}
		else if (moveCoolD > 0)
		{
			if (moveCoolD == 5)
				sprite.move(0, 10);
			sprite.setTextureRect(sf::IntRect(163, 22, 28, 61));
		}
		else if (moveCoolD <= 0)
		{
			sprite.setTextureRect(sf::IntRect(0, 27, 26, 61));
			action = 0;
		}
		moveCoolD--;
		break;
	}
	case 4://upper left punch
	{
		if (moveCoolD > 25)
		{
			sprite.setTextureRect(sf::IntRect(132, 23, 26, 61));
		}
		else if (moveCoolD > 20)
		{
			if (moveCoolD == 25)
				sprite.move(0, -10);
			sprite.setTextureRect(sf::IntRect(163, 22, 28, 61));
		}
		else if (moveCoolD > 15)
		{
			if (moveCoolD == 20)
				sprite.move(0, -10);
			sprite.setTextureRect(sf::IntRect(191, 19, 28, 70));
		}
		else if (moveCoolD > 10)
		{
			punch = 0;
			if (moveCoolD == 15)
				punch = 4;
			if (moveCoolD == 15)
				sprite.move(0, -10);
			sprite.setTextureRect(sf::IntRect(216, 7, 28, 83));
		}
		else if (moveCoolD > 5)
		{
			punch = 0;
			if (moveCoolD == 10)
				sprite.move(0, 20);
			sprite.setTextureRect(sf::IntRect(163, 22, 28, 61));
		}
		else if (moveCoolD > 0)
		{
			if (moveCoolD == 5)
				sprite.move(0, 10);
			sprite.setTextureRect(sf::IntRect(163, 22, 28, 61));
		}
		else if (moveCoolD <= 0)
		{
			sprite.setTextureRect(sf::IntRect(0, 27, 26, 61));
			action = 0;
		}
		moveCoolD--;
		break;
	}
	case 5://blocking
	{
		if (moveCoolD > 0)
		{
			sprite.setTextureRect(sf::IntRect(374, 100, 25, 61));
			blocking = true;
			moveCoolD--;
		}
		else
		{
			sprite.setTextureRect(sf::IntRect(0, 26, 25, 61));
			blocking = false;
			action = 0;
		}
		break;
	}
	case 6://dodge left
	{
		if (moveCoolD > 15)
		{
			if (dir < 0)
				sprite.setTextureRect(sf::IntRect(50, 100, 25, 61)); // when it gets to this point change the rect on the texture
			sprite.move(sf::Vector2f(-2, 0));
			moveCoolD--;
		}
		else if (moveCoolD > 10)
		{
			sprite.setTextureRect(sf::IntRect(26, 27, 25, 61)); // when it gets to this point change the rect on the texture
			sprite.move(2, 0);
			moveCoolD--;
		}
		else if (moveCoolD > 0)
		{
			sprite.setTextureRect(sf::IntRect(0, 27, 25, 61));
			sprite.move(sf::Vector2f(2, 0));
			moveCoolD--;

		}
		else if (moveCoolD == 0)
		{
			action = 0;
			if (isWinded)
				action = 12;
		}
		break;
	}
	case 7://dodge right
	{
		if (moveCoolD > 15)
		{
			sprite.setTextureRect(sf::IntRect(100, 100, 25, 61)); // when it gets to this point change the rect on the texture
			sprite.move(sf::Vector2f(2, 0));
			moveCoolD--;
		}
		else if (moveCoolD > 10)
		{
			sprite.setTextureRect(sf::IntRect(26, 27, 25, 61)); // when it gets to this point change the rect on the texture
			sprite.move(-2, 0);
			moveCoolD--;
		}
		else if (moveCoolD > 0)
		{
			sprite.setTextureRect(sf::IntRect(0, 27, 25, 61));
			sprite.move(sf::Vector2f(-2, 0));
			moveCoolD--;
		}
		else if (moveCoolD == 0)
		{
			action = 0;
			if (isWinded)
				action = 12;
		}
		break;
	}
	case 8://dodge back
	{
		if (moveCoolD > 0)
		{
			sprite.setTextureRect(sf::IntRect(399, 100, 25, 61));
			moveCoolD--;
		}
		else
		{
			action = 0;
			sprite.setTextureRect(sf::IntRect(0, 26, 25, 61));
			dodging = false;
		}
		break;
	}
	case 9://star punch
	{
		if (moveCoolD > 50)
		{
			sprite.setTextureRect(sf::IntRect(245, 26, 27, 61));
		}
		else if (moveCoolD > 45)
		{
			sprite.setTextureRect(sf::IntRect(275, 26, 27, 61));
		}
		else if (moveCoolD > 40)
		{
			sprite.setTextureRect(sf::IntRect(245, 26, 27, 61));
		}
		else if (moveCoolD > 35)
		{
			sprite.setTextureRect(sf::IntRect(275, 26, 27, 61));
		}
		else if (moveCoolD > 30)
		{
			sprite.setTextureRect(sf::IntRect(314, 23, 28, 61));
		}
		else if (moveCoolD > 25)
		{
			if (moveCoolD == 30)
				sprite.move(0, -20);
			sprite.setTextureRect(sf::IntRect(350, 15, 26, 80));
		}
		else if (moveCoolD > 20)
		{
			if (moveCoolD == 25)
				sprite.move(0, -20);
			sprite.setTextureRect(sf::IntRect(376, 5, 24, 85));
		}
		else if (moveCoolD > 15)
		{
			punch = 0;
			if (moveCoolD == 20)
				punch = 5;
			sprite.setTextureRect(sf::IntRect(400, 0, 31, 85));
		}
		else if (moveCoolD > 10)
		{
			sprite.setTextureRect(sf::IntRect(376, 5, 24, 85));
		}
		else if (moveCoolD > 5)
		{
			if (moveCoolD == 10)
				sprite.move(0, 20);
			sprite.setTextureRect(sf::IntRect(350, 15, 26, 80));
		}
		else if (moveCoolD > 0)
		{
			if (moveCoolD == 5)
			{
				sprite.move(0, 20);
			}
			sprite.setTextureRect(sf::IntRect(314, 15, 26, 80));
		}
		if (moveCoolD <= 0)
		{
			sprite.setTextureRect(sf::IntRect(0, 27, 25, 61));
			action = 0;
		}
		moveCoolD--;
		break;
	}
	case 10://punched right
	{
		if (moveCoolD > 13)
		{
			sprite.setTextureRect(sf::IntRect(150, 100, 29, 62));
			sprite.move(0, 1);
		}
		else if (moveCoolD > 0)
		{
			if (moveCoolD > 11)
				sprite.move(0, 1);
			else if (moveCoolD > 0)
				sprite.move(0, -1);
			sprite.setTextureRect(sf::IntRect(190, 100, 27, 62));
		}
		else if (moveCoolD <= 0)
		{
			sprite.setTextureRect(sf::IntRect(0, 27, 25, 61));
			action = 0;
			sprite.setPosition(256 / 2, 240 * 0.75);
			punched = false;
		}
		moveCoolD--;
		break;
	}
	case 11://punched left
	{
		sprite.setScale(-1.1, 1.1);
		if (moveCoolD > 13)
		{
			sprite.setTextureRect(sf::IntRect(150, 100, 29, 62));
			sprite.move(0, 1);
		}
		else if (moveCoolD > 0)
		{
			if (moveCoolD > 11)
				sprite.move(0, 1);
			else if (moveCoolD > 0)
				sprite.move(0, -1);
			sprite.setTextureRect(sf::IntRect(190, 100, 27, 62));
		}
		else if (moveCoolD <= 0)
		{
			sprite.setTextureRect(sf::IntRect(0, 27, 25, 61));
			action = 0;
			sprite.setPosition(256 / 2, 240 * 0.75 - 10);
			sprite.setScale(1.1, 1.1);
			punched = false;
		}
		moveCoolD--;
		break;
	}
	case 12://winded animation
	{
		if (aniCoolD % 40 > 20)
		{
			sprite.setTextureRect(sf::IntRect(50, 27, 25, 61));
		}
		else
			sprite.setTextureRect(sf::IntRect(100, 27, 25, 61));
		aniCoolD--;
		if (aniCoolD <= 0)
		{
			isWinded = false;
			sprite.setColor(sf::Color(255, 255, 255));
			sprite.setTextureRect(sf::IntRect(0, 27, 25, 61));
		}

		if (moveCoolD > 0)
			moveCoolD--;
		break;
	}
	case 13://knocked down
	{
		sprite.setTextureRect(sf::IntRect(0, 27 - (aniCoolD / 5), 25, 61));
		if (aniCoolD <= 0)
		{
			knockedDown = false;
			action = 0;
		}
		aniCoolD++;

		if (moveCoolD >= 0)
			moveCoolD--;
		break;
	}
	default:
	{
		action = 0;
	}
	}
}


int Player::getPunch()
{
	return punch;
}


int Player::getAction()
{
	return action;
}


int Player::isPunching()
{
	return punch;
}


bool Player::isBlocking()
{
	return blocking;
}


bool Player::isDodging()
{
	return dodging;
}


Player::~Player() {}


bool Player::getWinded()
{
	return isWinded;
}


int Player::getHealth()
{
	return health;
}


int Player::getStarCount()
{
	return starCount;
}


int Player::getStamina()
{
	return stamina;
}


void Player::setHealth(int h)
{
	health = h;
}


void Player::punchMac(int punch_type, int hitDmg)
{
	if (punch_type == 1 && !punched)
	{
		action = 10;
		moveCoolD = 15;
		punched = true;
	}
	if (punch_type == 2 && !punched)
	{
		action = 11;
		moveCoolD = 15;
		punched = true;
	}
	if (moveCoolD == 15 && punched)
	{
		health -= hitDmg;
	}
}


int Player::getMoveCD()
{
	return moveCoolD;	
}
