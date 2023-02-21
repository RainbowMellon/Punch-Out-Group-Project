#include "Game.h"

Game::Game()
{
	isKeyPressed = false;
	playerKO = 0;
	oppoKO = 0;
	points = 0;
	round = 1;
	state = 1;
	time = 0;

	mainTheme.openFromFile("sounds/Bout Theme.wav");
}

void Game::play(sf::RenderWindow& window, sf::Event& event, sf::View& view)
{
	if (event.type == sf::Event::KeyReleased) // No repeat keys, because window.setKeyRepeat doesn't work in this scenario
		isKeyPressed = false;

	switch (state) //what ever the current state of the game, game does this. Ex, if we're not in the fight state don't show or update fight screen
	{	
		case 0:
			view.setCenter(512 * 0.75, 480 /4); //right of the fight screen, 3/4 of main's screens x, 1/4 of main screens Y
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !isKeyPressed)
			{
				state = 1;
				isKeyPressed = true;
				mainTheme.play();
			}
			
			break;
	
		case 1: //Fighting state, little mac vs the opponent
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !isKeyPressed)
			{
				state = 0;
				isKeyPressed = true;
				mainTheme.stop();
			}
			view.setCenter(512 / 4, 480 / 4); // 1/4 of the main screen in both axis's
			//update FightUI, player, Opponent
			littleMax.updatePlayer(event);

			//Draw Player, Opponent, FightUI
			littleMax.drawPlayer(window);
			
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