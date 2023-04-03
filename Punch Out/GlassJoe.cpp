#include "GlassJoe.h"
#include <iostream>


GlassJoe::GlassJoe()
{
	health = 96;
	name = "Glass Joe";
	location = "Paris, France";
	stats = "1-99      1 KO";
	round = 1;
	texture.loadFromFile("punchout sprites/GlassJoe.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 55, 100));
	sprite.setOrigin(55 / 2, 115 / 2);
	sprite.setPosition(148, 125);
	sprite.setScale(.95, .95);
}

/*
To Do: finish what happens after vive
do was hit
*/
void GlassJoe::update(int time,Player& mac)
{
	if (round == 1)
	{
		if (time < 4000)
			idle(time);

		else if (time < 4500)
		{
			vive(time);
		}
		else
		{
			if (time % 1000 < 500)
				idle(time);
			else
			{
				if (time % 4000 < 3000)
					hook(time);
				else
					jab(time);
			}
		}
	}

	if (wasHit(mac) == 1)
	{
		sprite.setTextureRect(sf::IntRect(13, 585, 32, 79));

	}
}


void GlassJoe::idle(int time)//joe's idle animation before vive la france
{
	if (time % 150 < 50)//timing on these doesn't exactly line up, need to look at it more
	{
		sprite.setTextureRect(sf::IntRect(518, 13, 31, 98));
		sprite.setPosition(148, 125);
	}

	else if (time % 150 < 75)
	{
		sprite.setTextureRect(sf::IntRect(474, 17, 31, 94));
		sprite.setPosition(152, 125);
	}

	else if (time % 150< 125)
	{
		sprite.setTextureRect(sf::IntRect(430, 13, 31, 98));
		sprite.setPosition(156, 125);
	}

	else if (time % 150 < 150)
	{
		sprite.setTextureRect(sf::IntRect(474, 17, 31, 94));
		sprite.setPosition(152, 125);
	}


}


void GlassJoe::hook(int time)
{//hook, seems to happen about 80 % of the time but I couldn't find actual stats for how often it happens
	if (time % 500 < 30)
	{
		sprite.setTextureRect(sf::IntRect(13, 241, 35, 87));
		sprite.move(-1, 0);
	}
		
	else if ( time % 500 < 60)
		sprite.setTextureRect(sf::IntRect(58, 241, 35, 87));
	else if(time % 500 < 90)
		sprite.setTextureRect(sf::IntRect(13, 241, 35, 87));
	else if (time % 500 < 120)
	{
		sprite.setTextureRect(sf::IntRect(105, 249, 34, 79));
		sprite.move(1, 0);

	}
	else if (time % 500 < 470)
		sprite.setTextureRect(sf::IntRect(151, 237, 39, 91));
	else
		sprite.setTextureRect(sf::IntRect(518, 13, 31, 98));
		
	punch = 1;
	
}


void GlassJoe::jab(int time)// jab, seems to happen about 20% of the time.
{
	if (time % 500 < 50)
	{
		sprite.setTextureRect(sf::IntRect(13, 126, 29, 98));
		sprite.move(1, -.5);
	}

	else if (time % 500 < 100)
		sprite.setTextureRect(sf::IntRect(53, 126, 29, 98));

	else if (time % 500 < 150)
	{
		sprite.setTextureRect(sf::IntRect(95, 126, 29, 98));
		sprite.move(-1, .5);
	}

	else if (time % 500 < 200)
		sprite.setTextureRect(sf::IntRect(138, 126, 29, 98));


	else if (time % 500 < 250)
	{
		sprite.setTextureRect(sf::IntRect(226, 127, 30, 97));
		sprite.move(-1, .5);
	}
	else if (time % 500 < 300)
	{
		sprite.setTextureRect(sf::IntRect(95,126,29,98));
		sprite.move(1, -.5);
	}
	else
		sprite.setTextureRect(sf::IntRect(518, 13, 31, 98));
	
	punch = 2;

}


void GlassJoe::vive(int time)
{
	if (time % 300 < 25)
	{
		sprite.setTextureRect(sf::IntRect(337, 17, 29, 94));
		sprite.move(.5, -2);
	}
	else if (time % 300 < 50)
	{
		sprite.setTextureRect(sf::IntRect(380, 13, 29, 98));
		sprite.move(.5, .5);
	}
	else if (time % 300 < 75)
	{
		sprite.setTextureRect(sf::IntRect(337, 17, 29, 94));
		sprite.move(.5, -2);
	}

	else if (time % 300 < 100)
	{
		sprite.setTextureRect(sf::IntRect(380, 13, 29, 98));
		sprite.move(.5, .5);
	}
	else if (time % 300 < 125)
		sprite.setTextureRect(sf::IntRect(146, 342, 31, 98));
	else if (time % 300 < 150)
		sprite.setTextureRect(sf::IntRect(193, 342, 29, 98));
	else if (time % 300 < 175)
		sprite.setTextureRect(sf::IntRect(146, 342, 31, 98));
	else if (time % 300 < 200)
		sprite.setTextureRect(sf::IntRect(193, 342, 29, 98));
	else if (time % 300 < 250)
	{
		sprite.setTextureRect(sf::IntRect(337, 17, 29, 94));
		sprite.move(-1, 1.5);
	}
	else if (time % 300 < 275)
		sprite.setTextureRect(sf::IntRect(518, 13, 31, 98));
	
	
	
	
}
void GlassJoe::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

int GlassJoe::getHealth()
{
	return health;
}

int GlassJoe::getDamage()
{
	return 11;
}


int GlassJoe::getStamina()
{
	return stamina;
}

int GlassJoe::wasHit(Player& mac)
{
	if (mac.isPunching() == 1 || mac.isPunching() == 2)
	{
		if (jabsHit < 3)
		{
			if (punch != 0)
			{
				
			}

			else
			{
				if (mac.isPunching() == 1 || mac.isPunching() == 2)
				{
					return 1;
				}
			
			}
		}
		else
		{

		}
		
	}
}

GlassJoe::~GlassJoe()
{}
