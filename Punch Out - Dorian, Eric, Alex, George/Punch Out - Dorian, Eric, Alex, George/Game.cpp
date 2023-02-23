#include "Game.h"
#include "UIManager.h"

Game::Game(sf::RenderWindow& window, sf::View& view)
{
	isKeyPressed = false;
	playerKO = 0;
	oppoKO = 0;
	points = 0;
	round = 1;
	state = 0;
	time = 0;
	ui = UIManager(window, view, &littleMax);
	mainTheme.openFromFile("sounds/Bout Theme.wav");
}

void Game::play(sf::RenderWindow& window, sf::Event& event, sf::View& view)
{
	if (event.type == sf::Event::KeyReleased) // No repeat keys, because window.setKeyRepeat doesn't work in this scenario
		isKeyPressed = false;

	switch (state) //what ever the current state of the game, game does this. Ex, if we're not in the fight state don't show or update fight screen
	{	
		case 0: //First ring
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !isKeyPressed)
			{
				state = 1;
				isKeyPressed = true;
				mainTheme.stop();
			}
			view.setCenter(128 + 2, 110 + 2); //center of first + 2 for border
			//update FightUI, player, Opponent
			littleMax.updatePlayer(event);

			//Draw Player, Opponent, FightUI
			littleMax.drawPlayer(window);
			
			break;
		
		case 1: //Second ring
			view.setCenter(384 + 3, 110 + 2); //center of second + 3 for border
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !isKeyPressed)
			{
				state = 0;
				isKeyPressed = true;
				mainTheme.play();
			}
			
			break;
	
		

		/*
			using a bigger comment for  stuff Im gonna add in the future,
			
			states:
			player & opponent stats states;
			a state that will just croll the view then go to the next state
			
			im tired and am going to eat
		
		*/
	}

}
int Game::getPlayerKO()
{
	return 3;
}
void Game::setPlayerKO()
{

}
void Game::setOppoKO()
{

}
void Game::setOppo()
{

}
int Game::getOppoKO()
{

	return 2;
}
Game::~Game(){}