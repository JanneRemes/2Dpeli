#include <SFML\Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include "SpriteHandler.h"
#include <vector>
#include "Enemy.h"
#include <string>
#include <sstream>
#include "gameTimer.h"
#include "PlayerObject.h"
#include "Bullet.h"
#include "Game.h"
#include "SceneSys.h"
#include "InputHandler.h"
#include "GameMenu.h"
#include "SaveGame.h"
#include "SaveAndLoad.h"
#include "TextureHandler.h"
using namespace sf;
using namespace std;


static void update(RenderWindow& window);


int main()
{
	//SaveGame::loadFromFile(1);
	//SaveGame a = SaveAndLoad::loadFromFile(1);
		//a.print();
		//a.setCash(500);
		//SaveAndLoad::saveToFile(1,&a);
	TextureHandler::addTextures();
	TextureHandler::print();
	VideoMode videoMode(1028u, 720u);
			RenderWindow window(videoMode,"SFML works!");
		window.setFramerateLimit(60);
		SceneSys::OpenScene(new GameMenu(&window));
	update(window);


	
	return 0;
}

void update(RenderWindow& window)
{
	Event event;
	Clock clock;
	while(window.isOpen())
	{

		while (window.pollEvent(event))
		{
			switch(event.type)
			{
				case Event::Closed:
					window.close();
					return;

				default:
					break;
			}
		}
		if(event.type == Event::LostFocus)
		{
			//TODO muuta että tarkistaa eka onko paused
			SceneSys::PauseCurrentScene(true);
		}
		else if(event.type == Event::GainedFocus)
		{
			//TODO muuta että tarkistaa eka onko paused
			SceneSys::PauseCurrentScene(false);
		}
				if(Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
				
		SceneSys::Update(clock.getElapsedTime().asSeconds());
		InputHandler::Update(Mouse::isButtonPressed(Mouse::Left));
		//game.Update(clock.getElapsedTime().asSeconds());
		clock.restart();
		//game.draw();
		SceneSys::Draw();

	}
}
