#include "Opponent.h"
#include "UIManager.h"
#include <string>
#include <SFML/Graphics.hpp>


UIManager::UIManager()
{
	player = NULL;
	window = NULL;
	view = NULL;
	"punch-out-nes.ttf";

	//player health on screen
	pHealth.setSize(sf::Vector2f(7, 48));
	pHealth.setFillColor(sf::Color::Black);
	pHealth.setOutlineThickness(0);

	//opponent health on screen
	oHealth.setSize(sf::Vector2f(7, 48));
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
void UIManager::drawStats(Player& player, Opponent& opponent)
{
	// Declare and load a font
	sf::Font font;
	font.loadFromFile("punch-out-nes.ttf");
	// Create a text
	sf::Text text("hello", font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Red);
	// Draw it
	(*window).draw(text);
}


//pass a refrence to the opponent to access the states
//used for inbetween fighting
void UIManager::roundStartScreen(Player& player, Opponent& opponent)
{

}
