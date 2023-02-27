#include "GlassJoe.h"

GlassJoe::GlassJoe()
{
	health = 96;
	name = "Glass Joe";
	location = "Paris, France";
	stats = "1-99      1 KO";
	texture.loadFromFile("sprites/littleMac.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(6, 0, 16, 44));
	sprite.scale(1.5, 1.5);
	sprite.setOrigin(16 / 2, 44 / 2);
	sprite.setPosition(256 / 2, 250 * .75);
}

void GlassJoe::update(sf::Event& window)
{

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

