#include "GlassJoe.h"

GlassJoe::GlassJoe()
{
	health = 96;
	name = "Glass Joe";
	location = "Paris, France";
	stats = "1-99      1 KO";
	texture.loadFromFile("punchout sprites/GlassJoe.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 55, 100));
	sprite.setOrigin(55 / 2, 115 / 2);
	sprite.setPosition(256 / 2, 100);
	srand(time(NULL));
}

void GlassJoe::update(int time, Game& game)
{
	if (game.getRound() == 1)
	{
		if (time < 4000)
			idle(time);
		else if (time < 5000)
		{
			vive(time);
			jab(time);
		}

		/*else if (time >= 5000) not working correctly
		{

			if (rand() % 5 != 0)
				hook(time);
			else
				jab(time);
		}*/
	}
		
}


void GlassJoe::idle(int time)//joe's idle animation before vive la france
{
	if (time % 100 < 100. / 3)//timing on these doesn't exactly line up, need to look at it more
	{
		sprite.setTextureRect(sf::IntRect(518, 13, 31, 98));
		sprite.setPosition(128, 100);
	}

	else if (time % 100 >= 100. / 3 && time % 100 < 200. / 3)
	{
		sprite.setTextureRect(sf::IntRect(474, 17, 31, 94));
		sprite.setPosition(132, 100);
	}

	else if (time % 100 >= 200. / 3)
	{
		sprite.setTextureRect(sf::IntRect(430, 13, 31, 98));
		sprite.setPosition(136, 100);
	}


}

void GlassJoe::hook(int time)
{//hook, seems to happen about 80 % of the time but I couldn't find actual stats for how often it happens
	if (time % 180 < 30)
		sprite.setTextureRect(sf::IntRect(13, 241, 35, 87));
	else if (time % 180 < 60)
		sprite.setTextureRect(sf::IntRect(58, 241, 35, 87));
	else if (time % 180 < 90)
		sprite.setTextureRect(sf::IntRect(105, 249, 34, 79));
	else if (time % 180 < 180)
		sprite.setTextureRect(sf::IntRect(151, 237, 39, 91));
}
void GlassJoe::jab(int time)// jab, seems to happen about 20% of the time.
{
	if (time % 180 < 30)
		sprite.setTextureRect(sf::IntRect(13, 126, 29, 98));
	else if (time % 180 < 60)
		sprite.setTextureRect(sf::IntRect(53, 126, 29, 98));
	else if (time % 180 < 90)
		sprite.setTextureRect(sf::IntRect(95, 126, 29, 98));
	else if (time % 180 < 120)
		sprite.setTextureRect(sf::IntRect(138, 126, 29, 98));
	else if (time % 180 < 150)
		sprite.setTextureRect(sf::IntRect(182, 126, 29, 98));
	else if (time % 180 < 180)
		sprite.setTextureRect(sf::IntRect(226, 127, 30, 97));
}
void GlassJoe::vive(int time)//the taunt joe does, probably need to rework cause it looks stupid.
{
	if (time % 1000 < 50)
	{
		sprite.setTextureRect(sf::IntRect(13, 342, 29, 98));
		sprite.setPosition(136, 90);
	}
	else if (time % 1000 < 100)
	{
		sprite.setTextureRect(sf::IntRect(56, 342, 31, 98));
		sprite.setPosition(144, 80);
	}
	else if (time % 1000 < 150)
	{
		sprite.setTextureRect(sf::IntRect(103, 342, 29, 98));
		sprite.setPosition(152, 70);
	}
	else if (time % 1000 < 175)
		sprite.setTextureRect(sf::IntRect(146, 342, 31, 98));
	else if (time % 1000 < 200)
		sprite.setTextureRect(sf::IntRect(193, 342, 29, 98));
	else if (time % 1000 < 225)
		sprite.setTextureRect(sf::IntRect(146, 342, 31, 98));
	else if (time % 1000 < 250)
		sprite.setTextureRect(sf::IntRect(193, 342, 29, 98));
	else if (time % 1000 < 275)
		sprite.setTextureRect(sf::IntRect(146, 342, 31, 98));
	else if (time % 1000 < 300)
		sprite.setTextureRect(sf::IntRect(193, 342, 29, 98));
	else if (time % 1000 < 325)
		sprite.setTextureRect(sf::IntRect(146, 342, 31, 98));
	else if (time % 1000 < 350)
		sprite.setTextureRect(sf::IntRect(193, 342, 29, 98));
	else if (time % 1000 < 400)
		sprite.setPosition(128, 100);
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

//void GlassJoe::wasHit(Player& p)
//{
	//health -= 6;//this will need to be changed later, just for testing
//}

GlassJoe::~GlassJoe()
{}
