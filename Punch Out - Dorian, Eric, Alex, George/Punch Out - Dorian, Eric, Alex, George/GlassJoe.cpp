#include "GlassJoe.h"

GlassJoe::GlassJoe()
{
	health = 96;
	name = "Glass Joe";
	location = "Paris, France";
	stats = "1-99      1 KO";
}

void GlassJoe::update()
{

}
void GlassJoe::draw()
{

}

int GlassJoe::getHealth()
{
	return health;
}

int GlassJoe::getDamage()
{
	return 11;
}

void GlassJoe::wasHit(Player& p)
{
	health -= 6;//this will need to be changed later, just for testing
}

