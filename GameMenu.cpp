#include "GameMenu.h"
#include "InputHandler.h"
#include "SceneSys.h"
#include "Game.h"
#include "SpriteHandler.h"
#include "TextureHandler.h"
#include <iostream>
using namespace std;
GameMenu::GameMenu(RenderWindow *WINDOW):SceneParent(WINDOW)
{
	p = Vector2f(-70,500);
	_window = WINDOW;
	loadTextures();
	setSprites();
	setTexts();
}


GameMenu::~GameMenu(void)
{
}
void GameMenu::setTexts()
{
	if(!font.loadFromFile("Arial.ttf"))
	{
		cout<<"Error loading font"<<endl;
	}
	credits.setFont(font);
	//credits.setString("Made by Miika Silvola");
	credits.setColor(Color::Black);
	credits.setPosition(700,680);
}
void GameMenu::loadTextures()
{
	if(!testi.loadFromFile("image1.png"))
	{
		std::cout<<"Error"<<std::endl;
	}
	if(!menu_button_tex.loadFromFile("menu_nappi.png"))
	{
		std::cout<<"Error"<<std::endl;
	}
	if(!background_tex.loadFromFile("kuva.png"))
	{
	cout<< "Error"<<endl;
	}
	if(!bird_tex.loadFromFile("lokki_anim.png"))
	{
		cout<<"Error loading texture"<<endl;
	}
}
void GameMenu::setSprites()
{
	testi_sprite.setTexture(testi);
	testi_sprite.setScale(0.3f,0.3f);
	testi_sprite.setPosition(-70,500);
	testi_spritesheet = SpriteSheet(testi_sprite,480,480,12,35.0f,false);

	menu_button_sprite.setTexture(menu_button_tex);
	//VideoMode videoMode(1028u, 720u);
	menu_button_sprite.setOrigin(menu_button_sprite.getGlobalBounds().width/2,menu_button_sprite.getGlobalBounds().height/2);
	menu_button_sprite.setPosition(514,360);
	//SpriteHandler::addSprite("menu",&menu_button_sprite);
	background_sprite.setTexture(background_tex);
	bird_sprite.setTexture(bird_tex);
	bird_sprite.setScale(0.1f,0.1f);
	bird_sheet = SpriteSheet(bird_sprite,795,593,9,50.0f,false);
	pistol_sprite.setTexture(*TextureHandler::getTexture("pistooli"));
	pistol_sprite.setScale(0.3f,0.3f);

}
void GameMenu::Update(float dt)
{
	testi_spritesheet.Update(dt);
	bird_sheet.Update(dt);
	testi_spritesheet.setPosition(p);
	if(p.x< 1028u)
		p.x+= 3u;
	else
		p.x = -70;

	if(InputHandler::leftMouseStartedPressing())
	{
		FloatRect collision = menu_button_sprite.getGlobalBounds();
		Vector2i m_pos = Mouse::getPosition(*_window);
		if(collision.contains(m_pos.x,m_pos.y))
		{
			cout<<"Nappulaa painetaan."<<endl;
			//SceneSys::ChangeScene(new Game(_window));
			SceneSys::ChangeScene(new Game(_window));
		}
	}
}
void GameMenu::Draw()
{
	
	_window->clear(Color(255,255,255));
	_window->draw(background_sprite);
	_window->draw(pistol_sprite);
	_window->draw(bird_sheet.getSprite());
	_window->draw(testi_spritesheet.getSprite());
	_window->draw(menu_button_sprite);
	//_window->draw(*SpriteHandler::getSprite("menu"));
	_window->draw(credits);
	_window->display();
}
