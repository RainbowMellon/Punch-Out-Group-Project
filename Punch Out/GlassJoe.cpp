#include "GlassJoe.h"
#include <iostream>

GlassJoe::GlassJoe()
{
	health = 96;
	rank = "2";
	name = "Glass Joe\n\n\n\n\n\n";
	location = "\n\nFrom\n Paris,\n    France\n\n";
	stats = "\n\n\n\n\n\n 1-99  1KO\n\n";
	age = "38\n\n";
	weight = "110";
	round = 1;
	texture.loadFromFile("punchout sprites/GlassJoe.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 55, 100));
	sprite.setOrigin(55 / 2, 115 / 2);
	sprite.setPosition(210, 90);
	sprite.setScale(.95, .95);
	jabsHit = 0;
	upsHit = 0;
}


/*
To Do: finish what happens after vive
do was hit
*/
void GlassJoe::update(int time,Player& mac, int round)
{
	std::cout << punch;
	sprite.setScale(1.f, 1.f);

	switch (round)
	{
	case 1:

		if (mac.getAction() != 0)
			wasHit(mac, time);
		else
		{
			if (time < 4000)
			{
				idle(time);
			}


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
					{

						if (time % 500 == 1)
							punch = 1;
						else
							punch = 0;
						hook(time);

					}
					
					else
					{
						if (time % 500 == 1)
							punch = 2;
						else
							punch = 0;
						jab(time);
					}
						
					
				}
			}
		}
		
		break;
	}

}


void GlassJoe::idle(int time)//joe's idle animation before vive la france
{

	if (time % 150 < 50)
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

bool GlassJoe::wasHit(Player& mac, int time)
{
	
	

	switch (mac.getAction())
	{
		
	case 1:

		upsHit = 0;
		if (jabsHit < 7)//for some reason jabsHit is increasing by 2 instead of one
		{
			if (time % 100 < 100)
			{
				sprite.setPosition(140, 155);
				sprite.setTextureRect(sf::IntRect(13, 585, 32, 79));
				sprite.move(1, -1);
				
				if (mac.getPunch() == 1)
				{
					setHealth(health - 2);
					jabsHit++;
					timesHit++;
					
				}
				return true;

			}
			 
		}


		else if (jabsHit > 6)
		{
			
			sprite.setPosition(140, 145);
			if (time % 100 < 40)
				sprite.setTextureRect(sf::IntRect(13, 458, 32, 91));
			else
				sprite.setTextureRect(sf::IntRect(54, 458, 32, 91));
		}
		 

		break;

	case 2:

		upsHit = 0;
		if (jabsHit < 7)
		{
			if (time % 100 < 100)
			{
				sprite.setPosition(140, 155);
				sprite.setTextureRect(sf::IntRect(13, 585, 32, 79));
				sprite.move(1, -1);

				if (mac.getPunch() == 2)
				{
					setHealth(health - 2);
					jabsHit++;
					timesHit++;
				}
				return true;

			}

		}


		else if (jabsHit > 6)
		{
			sprite.setPosition(140, 145);
			if (time % 100 < 40)
				sprite.setTextureRect(sf::IntRect(13, 458, 32, 91));
			else
				sprite.setTextureRect(sf::IntRect(54, 458, 32, 91));
		}
		 
		break;

	case 3:
		jabsHit = 0;
		sprite.setScale(-1.f, 1.f);

		if (upsHit < 7)
		{
			
			if (mac.getMoveCD() * 4 >= 60)
			{
				
				sprite.setPosition(120, 150);
				sprite.setTextureRect(sf::IntRect(99, 572, 35, 92));
			}

			else
			{
				sprite.setTextureRect(sf::IntRect(146, 572, 38, 92));
				sprite.move(-.5, -.5);
			}

			if (mac.getPunch() == 3)
			{
				setHealth(health - 2);
				upsHit++;
				timesHit++;
			}
			return true;
		}

		else if (upsHit > 6)
		{
			sprite.setPosition(115, 140);
			if (time % 100 < 30)
			{
				sprite.setTextureRect(sf::IntRect(108, 452, 34, 97));
			}

			else if (time % 100 < 60)
			{
				sprite.setTextureRect(sf::IntRect(153, 452, 34, 97));
			}

			else if (time % 100 < 100)
			{
				sprite.setTextureRect(sf::IntRect(198, 452, 34, 97));
			}
		}
		upsHit++;
		break;

	case 4:
		jabsHit = 0;
		if (upsHit < 7)
		{

			if (mac.getMoveCD() * 4 >= 60)
			{
				sprite.setPosition(140, 150);
				sprite.setTextureRect(sf::IntRect(99, 572, 35, 92));
			}

			else 
			{
				sprite.setTextureRect(sf::IntRect(146, 572, 38, 92));
				sprite.move(.5, -.5);
			}
		

			

			if (mac.getPunch() == 4)
			{
				setHealth(health - 2);
				upsHit++;
				timesHit++;
			}
			return true;
		}

		else if (upsHit > 6)
		{
			sprite.setPosition(145, 140);
			if (time % 100 < 30)
			{
				sprite.setTextureRect(sf::IntRect(108, 452, 34, 97));
			}

			else if (time % 100 < 60)
			{
				sprite.setTextureRect(sf::IntRect(153, 452, 34, 97));
			}

			else if (time % 100 < 100)
			{
				sprite.setTextureRect(sf::IntRect(198, 452, 34, 97));
			}
		}
		upsHit++;
		break;

	case 9:
		if (mac.getPunch() == 5)
		{
			setHealth(health - 10);
			timesHit++;
		}
		
		if (mac.getMoveCD() >= 40)
		{
			sprite.setTextureRect(sf::IntRect(518, 13, 31, 98));
			sprite.setPosition(140, 150);
		}

		
		else
		{
			sprite.setScale(-1.f, 1.f);

			if (mac.getMoveCD() >= 20)
			{
				sprite.setTextureRect(sf::IntRect(99, 572, 35, 92));
				sprite.move(-.5, -.5);
			}
			else if (mac.getMoveCD() >= 0)
			{
				sprite.setTextureRect(sf::IntRect(146, 572, 38, 92));
				sprite.move(-.5, -.5);
			}
			
		}

		
		
		
	}
}


bool GlassJoe::hasIntro()
{
	return true;
}

sf::String GlassJoe::introMusicFile()
{
	return "sounds/GlassJoeTheme.flac";
}

void GlassJoe::Intro()
{

	sprite.setTextureRect(sf::IntRect(55, 110 * 7, 55, 110));
}

void GlassJoe::toStage()
{
	
	if (sprite.getPosition().x > 140)
			sprite.move(-0.75, 0);
	if (sprite.getPosition().y < 90)
			sprite.move(0, 0.5);
}


std::string GlassJoe::getUIStuff(int type)
{
	std::string whatGet;
	switch(type)
	{
	case 1:
		whatGet = rank;
		break;
	case 2:
		whatGet = name;
		break;
	case 3:
		whatGet = stats;
		break;
	case 4:
		whatGet = location;
		break;
	case 5:
		whatGet = age;
		break;
	case 6:
		whatGet = weight;
	}

	return whatGet;
}


GlassJoe::~GlassJoe()
{}

int GlassJoe::getPunch()
{
	return punch;
}

void GlassJoe::setHealth(int newHealth)
{
	health = newHealth;
}

