#include "GlassJoe.h"

GlassJoe::GlassJoe()
{
	health = 96;
	name = "Glass Joe";
	location = "Paris, France";
	stats = "1-99      1 KO";
	texture.loadFromFile("punchout sprites/GlassJoe.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 55, 115));
	//sprite.scale(1.5, 1.5);
	sprite.setOrigin(55 / 2, 115 / 2);
	sprite.setPosition(256 / 2, 100);
}

void GlassJoe::update(int time)
{
	if (time < 4000)
	{
		if (time % 400 == 0)
			sprite.setTextureRect(sf::IntRect(0, 115 * 3, 50, 115));
		else
			sprite.setTextureRect(sf::IntRect(50, 115 * 3, 50, 115));
	}
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
