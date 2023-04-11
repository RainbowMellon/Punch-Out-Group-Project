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
	fadeout.setPosition(sf::Vector2f(878, 345));
	UI.setPointers(window, view, littleMac);
	mainTheme.openFromFile("sounds/Bout Theme.wav");
}

void Game::play(sf::RenderWindow& window, sf::Event& event, sf::View& view)
{
		if (event.type == sf::Event::KeyReleased) // No repeat keys, because window.setKeyRepeat doesn't work in this scenario
		isKeyPressed = false;
		UI.roundStartScreen(littleMac, *opponent);
	switch (state) //what ever the current state of the game, game does this. Ex, if we're not in the fight state don't show or update fight screen
	{	
		case 0: //Main menu
			view.setCenter(898 + 5, 110 + 2); //center of first + borders
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
			{
				view.setCenter(898 + 5, 340 + 3);
				state = 1;
			}
			break;
		case 1: //Stats screen
			
			//draw states, if round >= 2, draw the opponents and docs quotes
			
			//when enter is press, scroll down to round image, fade in black box, then switch states
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				state = 2;
			}
			break;

		case 2: //view transistion? I might make stats screen absorb this
			window.draw(fadeout);

			if (view.getCenter().y < 350 * 1.6)
				view.move(0, 5);
			else if (time < 75)
				time++;
			else if (fadeout.getFillColor().a < 255)
				fadeout.setFillColor(sf::Color(0, 0, 0, fadeout.getFillColor().a + 5));
			else //if (mainTheme.openFromFile("sounds/Bout Theme.wav"))
			{
				time = 0;
				fadeout.setFillColor(sf::Color(0, 0, 0, 0));
				//backgroundTexture.loadFromFile("punchout sprites/stage1.png");
				mainTheme.play();
				state = 4;
			}

			break;
		case 3: // intro to the fight
			break;
		case 4: //Fight screen
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !isKeyPressed)
			{
				state = 4;
				isKeyPressed = true;
				mainTheme.stop();
			}
			view.setCenter(128 + 2, 110 + 2); //center of first + 2 for border
			//update FightUI, player, Opponent

			
			if (time % 6000 == 0 && time != 0)
				time = 10000;
			else if (time % 16000 == 0 && time != 0)
				time = 20000;
			else if (time % 26000 == 0 && time != 0)
				time = 30000;
			else
				time+= 3;
			
			littleMac.updatePlayer(event);
			opponent->update(time, littleMac);

			//If timer is 3,00,00 (3 minutes) stop the fight and go back to the states screen, increase round as well


				//if the timer is 3 minutes and it's round three, go to the disision screen.
			if (time == 30000)
			{
				state = 5;
				playerKO = 0;
				oppoKO = 0;
				fadeout.setPosition(0, 0);
			}

			//Draw Player, Opponent, FightUI
			opponent->draw(window);
			littleMac.drawPlayer(window);
			UI.drawStats(littleMac, *opponent, time, 1,round);

			//If the opponent or player is KOed, go to win or lose screen
			break;
		case 5: //time out, return to 
			opponent->draw(window);
			littleMac.drawPlayer(window);
			UI.drawStats(littleMac, *opponent, time, 1, round);
			window.draw(fadeout);

			if (playerKO < 75)
				playerKO++; //since playerKO isn't needed anymore and reseted, we're using it as a placeholder
			else if (fadeout.getFillColor().a < 255)
				fadeout.setFillColor(sf::Color(0, 0, 0, fadeout.getFillColor().a + 5));
			else if(round + 1 < 4)
			{
				state = 1;
				round++;
				playerKO = 0;
				fadeout.setFillColor(sf::Color(0, 0, 0, 0));
				fadeout.setPosition(0, 220);
			}
			//else
			break;
		case 6: //Mario counts for opponent
			view.setCenter(384 + 3, 110 + 2); //center of second + 3 for border
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !isKeyPressed)
			{
				state = 3;
				isKeyPressed = true;
				mainTheme.play();
			}
			//UI.drawStats(littleMac, *opponent, time, 2);
			break;
		case 7: //Mario counts for little mac
			break;
		case 8: // fadeout into win screen
			break;
		case 9: //win screen, will either fadeout to state 1 (while changing opponent), or scroll to state 9
			break;
		case 10: // scroll to title bout screen, then change state to 1(while changing oppponent
			break;
		case 11: //Doc biking with mac, after a title bout
				break;

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
