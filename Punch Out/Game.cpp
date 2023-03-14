#include "Game.h"
#include "UIManager.h"
#include <iostream>

Game::Game(sf::RenderWindow& window, sf::View& view)
{
	opponent = &joe;
	isKeyPressed = false;
	playerKO = 0;
	oppoKO = 0;
	points = 0;
	round = 1;
	state = 0;
	time = 0; //For timer, first 2 digits are milliseconds, second two are seconds, fifth one is minute 
	fadeout.setSize(sf::Vector2f(256, 240));
	fadeout.setFillColor(sf::Color(0, 0, 0, 0));
	fadeout.getFillColor().a;
	UI.setPointers(window, view, littleMac);
	mainTheme.openFromFile("sounds/Bout Theme.wav");
}

void Game::play(sf::RenderWindow& window, sf::Event& event, sf::View& view)
{
	if (event.type == sf::Event::KeyReleased) // No repeat keys, because window.setKeyRepeat doesn't work in this scenario
		isKeyPressed = false;

	switch (state) //what ever the current state of the game, game does this. Ex, if we're not in the fight state don't show or update fight screen
	{	
		case 0: //Main menu
			view.setCenter(898 + 5, 110 + 2); //center of first + borders
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
			{
				//do transitions
				state = 3;
			}
			break;
		case 1: //Stats screen
			
			//draw states, if round >= 2, draw the opponents and docs quotes

			//when enter is press, scroll down to round image, fade in black box, then switch states

			break;

		case 2: //view transistion? I might make stats screen absorb this

			break;
		case 3: //Fight screen
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !isKeyPressed)
			{
				state = 4;
				isKeyPressed = true;
				mainTheme.stop();
			}
			view.setCenter(128 + 2, 110 + 2); //center of first + 2 for border
			//update FightUI, player, Opponent

			
			if (time % 6000 == 0 && time != 0)
				time += 4000;
			else
				time+= 3;
			littleMac.updatePlayer(event);
			opponent->update(time);

			//If timer is 3,00,00 (3 minutes) stop the fight and go back to the states screen, increase round as well


			//if the timer is 3 minutes and it's round three, go to the disision screen.

			//Draw Player, Opponent, FightUI
			opponent->draw(window);
			littleMac.drawPlayer(window);
			UI.drawStats(littleMac, *opponent, time, 1);
			std::cout << time << std::endl;

			//If the opponent or player is KOed, go to win or lose screen
			break;
		
		case 4: //Second ring
			view.setCenter(384 + 3, 110 + 2); //center of second + 3 for border
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !isKeyPressed)
			{
				state = 3;
				isKeyPressed = true;
				mainTheme.play();
			}
			UI.drawStats(littleMac, *opponent, time, 2);
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
