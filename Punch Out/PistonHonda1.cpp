#include "PistonHonda1.h"
#include <iostream>


PistonHonda1::PistonHonda1()
{
	health = 96;
	name = "Piston Honda";
	location = "Tokyo, Japan";
	stats = "26-1      18 KO";
	round = 1;
	texture.loadFromFile("punchout sprites/Piston-Honda.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(9, 9, 39, 108));
	sprite.setOrigin(39 / 2, 108 / 2);
	sprite.setPosition(148, 125);
	srand(time(NULL));
}


void PistonHonda1::update(int time, Player&)
{
	/*
	int r = rand() % 150;
	if (r == 0)
		jab(time);
	else if (r == 1)
		hook(time);
	else
		idle(time);
	*/
	

	switch (round)
	{
	case 1:
		
		if (time < 1400)
			idle(time);

		else if (time >= 1400 && time <= 1800)
		{
			jab(time);
		}
		break;

	case 2:
		if (time == 4002)
			//Banzai;
			if (time == 22001)
				//Banzai;
		break;

	case 3:
		if (time == 2001)
			//Banzai;
			if (time == 23000)
				//Banzai;
				if (time == 24002)
					//Banzai;
		break;
	}
}


void PistonHonda1::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}


int PistonHonda1::getHealth()
{
	return health;
}


int PistonHonda1::getDamage()
{
	return damage;
}


int PistonHonda1::wasHit(Player&)
{
	return 0;
}


void PistonHonda1::taunt(int)
{

}


void PistonHonda1::jab(int)
{
	std::cout << "Jab" << std::endl;
}


void PistonHonda1::hook(int)
{
	std::cout << "Hook" << std::endl;
}


void PistonHonda1::idle(int time)
{
	if (time % 150 < 50)
	{
		sprite.setTextureRect(sf::IntRect(9, 129, 39, 110));
		sprite.setPosition(134, 125);
	}

	else if (time % 150 < 75)
	{
		sprite.setTextureRect(sf::IntRect(61, 130, 39, 110));
		sprite.setPosition(139, 125);
	}

	else if (time % 150 < 125)
	{
		sprite.setTextureRect(sf::IntRect(113, 130, 39, 110));
		sprite.setPosition(144, 125);
	}

	else if (time % 150 < 150)
	{
		sprite.setTextureRect(sf::IntRect(61, 130, 39, 110));
		sprite.setPosition(139, 125);
	}
}


PistonHonda1::~PistonHonda1()
{

}