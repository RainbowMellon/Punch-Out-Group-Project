#include "Opponent.h"
#include "UIManager.h"
#include <string>
#include <SFML/Graphics.hpp>


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
}


//pass a reference to the window and view for more convinent drawing
//pass a reference to the player to get access stats
UIManager::UIManager(sf::RenderWindow& newWindow, sf::View& newView, Player& newPlayer)
{
  window = &newWindow;
  view = &newView;
  player = &newPlayer;

  //player health on screen
  pHealth.setSize(sf::Vector2f(7, 48));
  pHealth.setFillColor(sf::Color::Black);
  pHealth.setOutlineThickness(0);

  //opponent health on screen
  oHealth.setSize(sf::Vector2f(7, 48));
  oHealth.setFillColor(sf::Color::Black);
  oHealth.setOutlineThickness(0);
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
void UIManager::winScreen(float time)
{
  //view.setCenter(0, 0);
  //coordinate of the win screen
  //view.move(?, ?);

  //how long it took to win
  //window.draw(sf::Text(std::to_string(time)));
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
void UIManager::drawStats(Player& player, Opponent& opponent, int clock, int stage, int round)
{
	sf::Font font;
	font.loadFromFile("punch-out-nes.ttf");

	std::string starCount_str, stamina_str, clock_str, round_str;
	int starCount, stamina, second, minute;
	float playerHealth = 1, opponentHealth = 1;
	//facilitates the different views
	sf::Vector2f starcount_pos(33, 17),
		stamina_pos(63, 17),
		playerHB_pos(138, 18),
		opponentHB_pos(146, 18),
		sec_pos(226, 18),
		min_pos(210, 18),
		round_pos(237, 28);

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
	}
	//star count num
	starCount = player.getStarCount();
	starCount_str = std::to_string(starCount);
	sf::Text text(starCount_str, font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(100);
	text.setScale(0.1, 0.1);
	text.setPosition(starcount_pos);
	(*window).draw(text);

	//stamina num
	stamina = opponent.getStamina();
	stamina_str = std::to_string(stamina);
	text.setPosition(stamina_pos);
	text.setScale(0.1, 0.1);
	text.setString(stamina_str);
	(*window).draw(text);

	//round
	round_str = std::to_string(round);
	text.setString(round_str);
	text.setPosition(round_pos);
	text.setScale(0.06, 0.06);
	(*window).draw(text);

	//player healthBar
	playerHealth = player.getHealth() / 96.f;
	pHealth.setPosition(playerHB_pos);
	pHealth.setOrigin(pHealth.getLocalBounds().width, 0);
	pHealth.setSize(sf::Vector2f(48 - 48 * playerHealth, 7));
	(*window).draw(pHealth);

	//opponent healthBar
	opponentHealth = opponent.getHealth() / 96.f;
	oHealth.setPosition(opponentHB_pos);
	oHealth.setSize(sf::Vector2f(48 * opponentHealth, 7));
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
}


//pass a refrence to the opponent to access the states
//used for inbetween fighting
void UIManager::roundStartScreen(Player& player, Opponent& opponent)
{

}
