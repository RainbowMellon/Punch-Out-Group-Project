#include "Opponent.h"
#include "UIManager.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <iostream>


UIManager::UIManager()
{
	player = NULL;
	window = NULL;
	view = NULL;

	//player health on screen
	pHealth.setSize(sf::Vector2f(48, 7));
	pHealth.setFillColor(sf::Color::Black);
	pHealth.setOutlineThickness(0);

	//opponent health on screen
	oHealth.setSize(sf::Vector2f(48, 7));
	oHealth.setFillColor(sf::Color::Black);
	oHealth.setOutlineThickness(0);

	roundSprite.setPosition(776, 455);
}


//pass a reference to the window and view for more convinent drawing
//pass a reference to the player to get access stats
UIManager::UIManager(sf::RenderWindow& newWindow, sf::View& newView, Player& newPlayer)
{
  window = &newWindow;
  view = &newView;
  player = &newPlayer;

  //player health on screen
  pHealth.setSize(sf::Vector2f(48, 7));
  pHealth.setFillColor(sf::Color::Black);
  pHealth.setOutlineThickness(0);

  //opponent health on screen
  oHealth.setSize(sf::Vector2f(48, 7));
  oHealth.setFillColor(sf::Color::Black);
  oHealth.setOutlineThickness(0);

  roundSprite.setPosition(770, 430);
}

void UIManager::setPointers(sf::RenderWindow& window, sf::View& view, Player& player)
{
	this->window = &window;
	this->view = &view;
	this->player = &player;
}

UIManager::~UIManager()
{

}


//give the time on the win clock
void UIManager::winScreen(float time, int round, std::string newRank)
{
  	sf::Font font;
	font.loadFromFile("punch-out-nes.ttf");
	std::string stats[6];
	sf::Text text;
	int minute, second, milli;
	text.setFont(font);
	text.setScale(.25, .25);

	text.setString("The w.v.b.a.\n   minor\n  circuit");
	text.setOrigin(text.getLocalBounds().width / 2, 0);
	text.setPosition(128, 475);
	text.setFillColor(sf::Color(31, 255, 255));
	(*window).draw(text);

	text.setString("------------------------------");
	text.setOrigin(text.getLocalBounds().width / 2, 0);
	text.setPosition(128, 497);
	(*window).draw(text);

	text.setString("\"Great fighting\"");
	text.setOrigin(text.getLocalBounds().width / 2, 0);
	text.setPosition(128, 510);
	text.setFillColor(sf::Color::White);
	(*window).draw(text);

	text.setString(" You won by tko!");
	text.setOrigin(text.getLocalBounds().width / 2, 0);
	text.setPosition(128, 525);
	(*window).draw(text);

	minute = time / 10000;
	second = (time / 100) - (minute * 100);
	milli = time - minute * 100 - second * 100;
	text.setString("Time " + std::to_string(minute) + ":" + std::to_string(second) +
		"." + std::to_string(milli) + ",R" + std::to_string(round));
	text.setOrigin(text.getLocalBounds().width / 2, 0);
	text.setPosition(128, 540);
	(*window).draw(text);
	
	text.setString(" You will be ranked up to #" + newRank);
	text.setOrigin(text.getLocalBounds().width / 2, 0);
	text.setPosition(128, 560);
	(*window).draw(text);

	text.setString("      and\n\n are you ready\n\n      for\n\nnext challenge ?");
	text.setPosition(178, 585);
	(*window).draw(text);
}


void UIManager::loseScreen()
{

}

//give the text you want to draw
void UIManager::drawText(std::string text)
{

}


//pass a refrence to the opponent to access the states
//used for while fighting
void UIManager::drawStats(Player& player, Opponent& opponent, int clock, int stage, int round, int points)
{
	sf::Font font;
	font.loadFromFile("punch-out-nes.ttf");

	std::string starCount_str, stamina_str, clock_str, round_str, points_str;
	int starCount, stamina, second, minute;
	float playerHealth = 1, opponentHealth = 1;
	//facilitates the different views
	sf::Vector2f starcount_pos(33, 17),
		stamina_pos(74, 17),
		playerHB_pos(138, 18),
		opponentHB_pos(194, 18),
		sec_pos(228, 18),
		min_pos(210, 18),
		round_pos(237, 28),
		points_pos(196, 25);

	switch (stage)
	{
	case 1:
		break;
	case 2:
		starcount_pos.x += 257;
		stamina_pos.x += 257;
		playerHB_pos.x += 257;
		opponentHB_pos.x += 257;
		min_pos.x += 257;
		sec_pos.x += 257;
		round_pos.x += 257;
		points_pos.x += 257;
	}
	//star count num
	starCount = player.getStarCount();
	starCount_str = std::to_string(starCount);
	sf::Text text(starCount_str, font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(100);
	text.setScale(0.09, 0.09);
	text.setPosition(starcount_pos);
	(*window).draw(text);

	//stamina num
	stamina = player.getStamina();
	stamina_str = std::to_string(stamina);
	text.setPosition(stamina_pos);
	text.setScale(0.09, 0.09);
	text.setString(stamina_str);
	text.setOrigin(text.getLocalBounds().width, 0);
	(*window).draw(text);
	text.setOrigin(0, 0);

	//round
	round_str = std::to_string(round);
	text.setString(round_str);
	text.setPosition(round_pos);
	text.setScale(0.06, 0.06);
	(*window).draw(text);

	//player healthBar
	playerHealth = player.getHealth() / 96.f;
	pHealth.setSize(sf::Vector2f(48 - 48 * playerHealth, 7));
	pHealth.setOrigin(pHealth.getLocalBounds().width, 0);
	pHealth.setPosition(playerHB_pos);
	(*window).draw(pHealth);

	//opponent healthBar
	opponentHealth = opponent.getHealth() / 96.f;
	oHealth.setSize(sf::Vector2f(48 - 48 * opponentHealth, 7));
	oHealth.setOrigin(oHealth.getLocalBounds().width, 0);
	oHealth.setPosition(opponentHB_pos);
	(*window).draw(oHealth);

	//clock
	//	second
	minute = clock / 10000;
	second = (clock / 100) - (minute * 100);
	clock_str = std::to_string(second);
	if (second < 10)
		clock_str = "0" + clock_str;
	text.setString(clock_str);
	text.setPosition(sec_pos);
	text.setScale(0.08, 0.08);
	(*window).draw(text);
	//	minute
	clock_str = std::to_string(minute);
	text.setString(clock_str);
	text.setPosition(min_pos);
	text.setScale(0.08, 0.08);
	(*window).draw(text);

	//points
	points_str = std::to_string(points);
	text.setString(points_str);
	text.setOrigin(text.getLocalBounds().width, 0);
	text.setPosition(points_pos);
	text.setScale(0.09, 0.09);
	(*window).draw(text);
}


//pass a refrence to the opponent to access the states
//used for inbetween fighting
void UIManager::roundStartScreen(Player& player, Opponent& opponent, int round)
{
	sf::Sprite playerFace, oppoFace;
	sf::Texture texture;
	roundTex.loadFromFile("punchout Sprites/round" + std::to_string(round) + ".png");
	roundSprite.setTexture(roundTex);

	//player face
	texture.loadFromFile("punchout sprites/Stat_screen_faces.png", sf::IntRect(85, 322, 80, 69));
	playerFace.setTexture(texture);
	playerFace.setPosition(790, 346);
	(*window).draw(playerFace);

	//opponent face
	texture.loadFromFile("punchout sprites/Stat_screen_faces.png", sf::IntRect(2, 162, 80, 77));
	oppoFace.setTexture(texture);
	oppoFace.setPosition(940, 280);
	(*window).draw(oppoFace);

	sf::Font font;
	font.loadFromFile("punch-out-nes.ttf");
	std::string stats[6];
	sf::Text text;
	text.setFont(font);
	text.setScale(.25, .25);

	for (int i = 0; i < 6; i++)
		stats[i] = opponent.getUIStuff(i + 1);

	//opponent rank
	text.setString("Ranked: #" + stats[0]);
	text.setPosition(941, 255);
	text.setFillColor(sf::Color::Green);
	(*window).draw(text);

	//player rank
	text.setString("Ranked: #3");
	text.setPosition(790, 420);
	text.setFillColor(sf::Color::Green);
	(*window).draw(text);	

	//player profile
	text.setString("From bronx\n      n.y.\nage: 17\n\nweight:107\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\little mac");
	text.setFillColor(sf::Color::White);
	text.setPosition(790, 290);
	(*window).draw(text);
	
	//player stats
	text.setString(" 0- -  -ko");
	text.setPosition(790, 330);
	(*window).draw(text);

	//opponent profile
	text.setString(stats[1] + stats[2] + "\"profile\"" + stats[3] 
		+ "age: " + stats[4] + "weight:" + stats[5]);
	text.setPosition(941, 270);
	(*window).draw(text);

	//vs. and push start!
	text.setString("  vs.\n\n\n\n\n\n\n push\n\nstart!");
	text.setPosition(880, 345);
	text.setFillColor(sf::Color(235, 140, 40));
	(*window).draw(text);

	//circuit
	text.setString("  minor circuit");
	text.setPosition(790, 260);
	(*window).draw(text);

	(*window).draw(roundSprite);
}
