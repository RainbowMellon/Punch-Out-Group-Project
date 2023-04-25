#include "Game.h"
#include "UIManager.h"
#include <iostream>



Game::Game(sf::RenderWindow& window, sf::View& view)
{
	timer = 0;
	opponent = &joe;
	isKeyPressed = false;
	playerKO = 0;
	oppoKO = 0;
	points = 0;
	round = 1;
	state = 5;
	time = 0; //For timer, first 2 digits are milliseconds, second two are seconds, fifth one is minute 
	placeHolderInt = 0;

	//setting up fadeout transition
	fadeout.setSize(sf::Vector2f(256, 240));
	fadeout.setFillColor(sf::Color(0, 0, 0, 0));
	fadeout.getFillColor().a;
	fadeout.setPosition(770, 430);

	//setting up mario
	marioTex.loadFromFile("punchout Sprites/Mario.png");
	marioSprite.setTexture(marioTex);
	marioSprite.setTextureRect(sf::IntRect(8 + 32 * 1, 8, 32, 48));
	marioSprite.setPosition(180, 110);

	//setting up sound & music
	mainTheme.openFromFile("sounds/Bout Theme.wav");
	gameSound.setBuffer(gameSoundBuffer);
	gameSoundBuffer.loadFromFile("sounds/KnockedOut.flac");

	UI.setPointers(window, view, littleMac);
}


//Shows/plays the game for the player based on what state the game is in
void Game::play(sf::RenderWindow& window, sf::Event& event, sf::View& view)
{
	if (event.type == sf::Event::KeyReleased) // No repeat keys, because window.setKeyRepeat doesn't work in this scenario
		isKeyPressed = false;
	switch (state) //what ever the current state of the game, game does this. Ex, if we're not in the fight state don't show or update fight screen
	{	
		case 0: //Main menu
			view.setCenter(898 + 5, 110 + 2); //center of first + borders
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !isKeyPressed)
			{
				state = 1;
				isKeyPressed = true;
			}
			break;
		case 1: //Stats screen
			view.setCenter(898 + 5, 340 + 3);
			//draw states, if round >= 2, draw the opponents and docs quotes

			UI.roundStartScreen(littleMac, *opponent, round);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !isKeyPressed)
			{
				state = 2;
				isKeyPressed = true;
			}
			break;

		case 2: //scroll down to round image, fade in black box, then switch states
			UI.roundStartScreen(littleMac, *opponent, round);
			window.draw(roundSprite);
			window.draw(fadeout);
			if (view.getCenter().y < 350 * 1.6)
				view.move(0, 5);
			else if (time < 75)
				time++;
			else if (fadeout.getFillColor().a < 255)
				fadeout.setFillColor(sf::Color(0, 0, 0, fadeout.getFillColor().a + 5));
			else if (opponent->hasIntro() && round == 1) //Check to see if the opponent has an intro
			{
				fadeout.setFillColor(sf::Color(0, 0, 0, 0));
				mainTheme.openFromFile(opponent->introMusicFile());
				mainTheme.play();
				state = 3;
			}
			else //if he doesn't do what opponents usally do
			{
				time = 0;
				fadeout.setFillColor(sf::Color(0, 0, 0, 0));
				//backgroundTexture.loadFromFile("punchout sprites/stage1.png");
				mainTheme.openFromFile("sounds/RoundStart.flac");
				mainTheme.play();
				state = 4;
			}

			break;
		case 3: // the opponents intro
			view.setCenter(128 + 2, 110 + 2);
			if (mainTheme.getStatus() == mainTheme.Playing)
			{
				opponent->Intro();
				UI.drawStats(littleMac, *opponent, time, 1, round, points);
				opponent->draw(window);
				littleMac.drawPlayer(window);
				window.draw(marioSprite);
			}
			else 
			{
				state = 4;
				mainTheme.openFromFile("sounds/RoundStart.flac");
				mainTheme.play();
			}
			break;
		case 4: //opponent moving toward Little Mac
			if (mainTheme.getStatus() == mainTheme.Playing)
			{
				opponent->toStage();

				UI.drawStats(littleMac, *opponent, time, 1, round, points);
				opponent->draw(window);
				littleMac.drawPlayer(window);
				window.draw(marioSprite);
			}
			else
			{
				time = 0;
				state = 5;
				mainTheme.openFromFile("sounds/Bout Theme.wav");
				mainTheme.play();
				mainTheme.setLoop(true);
			}
			break;
		case 5: //Fight screen
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !isKeyPressed)
			{
				littleMac.setHealth(0);
				state = 3;
				isKeyPressed = true;
			}
			view.setCenter(128 + 2, 110 + 2); //center of first + 2 for border

			//incremention of time	
			if (time % 6000 == 0 && time != 0)
				time = 10000;
			else if (time % 16000 == 0 && time != 0)
				time = 20000;
			else if (time % 26000 == 0 && time != 0)
				time = 30000;
			else if (time >= 30000 && time <=30100)
			{
				if (round == 3)
					state = 10;
				else
				{
					round++;
					state = 1;
				}
				time = 0;
			}
			else
				time+= 3;
			
			littleMac.updatePlayer(event);
			opponent->update(time, littleMac,round);

			if (opponent->wasHit(littleMac,time) != 0)
			{
				points += opponent->wasHit(littleMac, time);
				if (opponent->getTimesHit() > 5)
					littleMac.giveStar();
			}

			if (opponent->getHealth() <= 0)
			{
				points += 1000;
				state = 7;
				gameSound.play();
			}
				//if the timer is 3 minutes and it's round three, go to the disicion screen.
			if (time == 30000)
			{
				state = 6;
				playerKO = 0;
				oppoKO = 0;
				fadeout.setPosition(0, 0);
			}
			if (littleMac.getHealth() == 0)
			{
				state = 8; //State is where ever teh opponent counts for mac is
				gameSound.play();
				//macDowned()
			}

			//Draw Player, Opponent, FightUI
			opponent->draw(window);
			littleMac.drawPlayer(window);
			UI.drawStats(littleMac, *opponent, time, 1, round, points);

			//If the opponent or player is KOed, go to win or lose screen
			if (opponent->getHealth() == 0)
				state = 10; //win screen, is temp
			break;
		case 6: //time out, return to 
			opponent->draw(window);
			littleMac.drawPlayer(window);
			UI.drawStats(littleMac, *opponent, time, 1, round, points);
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
		case 7: //Mario counts for opponent
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && !isKeyPressed)
			{
				state = 3;
				isKeyPressed = true;
				mainTheme.play();
			}

			//marioCount(int)

			UI.drawStats(littleMac, *opponent, time, 1, round, points);
			opponent->draw(window);
			littleMac.drawPlayer(window);
			break;
		case 8: //Mario counts for little mac

			if (gameSound.getStatus() != gameSound.Playing && placeHolderInt == 0)
			{
				mainTheme.openFromFile("sounds/GetUpMac.flac");
				mainTheme.play();
				placeHolderInt = 1;
			}
			
			UI.drawStats(littleMac, *opponent, time, 1, round, points);
			opponent->draw(window);
			littleMac.drawPlayer(window);

			break;
		case 9: // fadeout into win screen
			break;
		case 10: //win screen, will either fadeout to state 1 (while changing opponent), or scroll to state 9
			view.setCenter(130, 570);
			UI.winScreen(time);
			break;
		case 11: // scroll to title bout screen, then change state to 1(while changing oppponent
			break;
	}
}


Game::~Game(){}
