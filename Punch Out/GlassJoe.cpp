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
void GlassJoe::update(int time, Player& mac, int round)
{
	sprite.setScale(1.f, 1.f);
	std::cout << jabsHit << "   " << upsHit << std::endl;

	if (mac.getAction() != 0)
	{
		switch (mac.getAction())
		{

		case 1:


			upsHit = 0;

			if (jabsHit >= 3)
			{
				sprite.setPosition(140, 145);
				if (time % 100 < 40)
					sprite.setTextureRect(sf::IntRect(13, 458, 32, 91));
				else
					sprite.setTextureRect(sf::IntRect(54, 458, 32, 91));

			}
			


			else if (jabsHit < 4)
			{
				if (mac.getMoveCD() >= 0)
				{
					sprite.setPosition(140, 155);
					sprite.setTextureRect(sf::IntRect(13, 585, 32, 79));
					sprite.move(1, -1);

					if (mac.getPunch() == mac.RightHook)
					{
						setHealth(health - 4);
						jabsHit++;
						

					}

				}

			}


			break;

		case 2:

			upsHit = 0;
			
			if (jabsHit >= 3)
			{

				sprite.setPosition(140, 145);
				if (time % 100 < 40)
					sprite.setTextureRect(sf::IntRect(13, 458, 32, 91));
				else
					sprite.setTextureRect(sf::IntRect(54, 458, 32, 91));

			}

			else if (jabsHit < 4)
			{
				if (mac.getMoveCD() >= 0)
				{
					sprite.setPosition(140, 155);
					sprite.setTextureRect(sf::IntRect(13, 585, 32, 79));
					sprite.move(1, -1);

					if (mac.getPunch() == mac.LeftHook)
					{
						setHealth(health - 4);
						jabsHit++;

					}


				}

			}


			break;

		case 3:
			jabsHit = 0;
			sprite.setScale(-1.f, 1.f);


			if (upsHit >= 3)
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

			

			else if (upsHit < 4)
			{
				if (mac.getMoveCD() == 25)
				{
					sprite.setPosition(140, 150);
				}
				else if (mac.getMoveCD() >= 15)
				{

					sprite.move(-.5, -.5);
					sprite.setTextureRect(sf::IntRect(99, 572, 35, 92));
				}

				else
				{
					sprite.setTextureRect(sf::IntRect(146, 572, 38, 92));

				}

				if (mac.getPunch() == mac.RightJab)
				{
					setHealth(health - 4);
					upsHit++;
				}

			}
			break;

		case 4:
			jabsHit = 0;
			if (upsHit >= 3)
			{

				sprite.setPosition(140, 140);
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
			

			else if(upsHit < 4)
			{
				if (mac.getMoveCD() == 25)
				{
					sprite.setPosition(140, 150);
				}
				else if (mac.getMoveCD() >= 15)
				{

					sprite.move(.5, -.5);
					sprite.setTextureRect(sf::IntRect(99, 572, 35, 92));
				}

				else
				{
					sprite.setTextureRect(sf::IntRect(146, 572, 38, 92));
				}

				if (mac.getPunch() == mac.LeftJab)
				{
					setHealth(health - 4);
					upsHit++;
				}
				

			}
			break;

		case 9:
			if (mac.getPunch() == mac.StarPunch)
			{
				setHealth(health - 10);
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

	
	else
	{
		switch (round)
		{
		case 1:

			
			
				if (time % 150 == 0)
				{ 
					action = 1;
					coolDown = 150;
				}


				else if (time == 4000)
				{
					action = 2;
					coolDown = 300;
				}
				else
				{
					if (time % 1000 < 500)
						idle(time);
					else
					{
						if (time % 4000 == 0)
						{

							action = 3;
							coolDown = 500;
						}

						else if(time % 1000 == 0)
						{
							action = 4;
							coolDown = 500;
						}


					}
				}
			

			break;
		}
	}
	
	if (coolDown > 0)
		coolDown--;
}


//Glass joe idle animation
void GlassJoe::idle(int time)
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

	else if (time % 150 < 125)
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


//Glass joe hook animation
void GlassJoe::hook(int time)
{//hook, seems to happen about 80 % of the time but I couldn't find actual stats for how often it happens


	if (time % 500 < 30)
	{
		sprite.setTextureRect(sf::IntRect(13, 241, 35, 87));
		sprite.move(-1, 0);
	}

	else if (time % 500 < 60)
		sprite.setTextureRect(sf::IntRect(58, 241, 35, 87));
	else if (time % 500 < 90)
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


//Glass joe jab animation
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
		sprite.setTextureRect(sf::IntRect(95, 126, 29, 98));
		sprite.move(1, -.5);
	}
	else
		sprite.setTextureRect(sf::IntRect(518, 13, 31, 98));


}

//Glass joe vive la france animation
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


//Draws Glass joe sprite
void GlassJoe::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}


//Returns Glass joe's current health
int GlassJoe::getHealth()
{
	return health;
}


//returns damage of glass joe
int GlassJoe::getDamage()
{
	return 11;
}


//returns max stamina for player
int GlassJoe::getStamina()
{
	return stamina;
}


//returns whether or not he was hit
int GlassJoe::wasHit(Player& mac, int time)
{



	switch (mac.getAction())
	{
	case 1:
		if (jabsHit <= 3)
			return 10;
		else
			return 0;
		break;
	case 2:
		if (jabsHit <= 3)
			return 10;
		else
			return 0;
		break;

	case 3:
		if (upsHit <= 3)
			return 10;
		else
			return 0;
		break;
	
	case 4:
		if (upsHit <= 3)
			return 10;
		else
			return 0;
		break;

	case 5:
		return 500;
		
	default:
		return 0;
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
	switch (type)
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


int GlassJoe::getPunch()
{
	return punch;
}


void GlassJoe::setHealth(int newHealth)
{
	health = newHealth;
}


GlassJoe::~GlassJoe()
{}
