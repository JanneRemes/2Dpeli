#include "GUI.h"
#include "TextureHandler.h"
#include <iostream>
#include <sstream>
using namespace std;

GUI::GUI(RenderWindow& window,Font *font,WeaponManager *w)
{
	this->w = w;
		/*if(!fontti.loadFromFile("Arial.ttf"))
	{
		cout<<"Error loading font"<<endl;
	}*/
	_font = font;
		hp_fill.setTexture(*TextureHandler::getTexture("hp_fill"));
	hp_border.setTexture(*TextureHandler::getTexture("hp_border"));
	pistol_sprite.setTexture(*TextureHandler::getTexture("pistooli"));
	pistol_sprite.setScale(0.3f,0.3f);
	pistol_sprite.setPosition(0,20.0f);
	m60_sprite.setTexture(*TextureHandler::getTexture("m60"));
	m60_sprite.setScale(0.1f,0.1f);
	m60_sprite.setPosition(150,20.0f);
		hp_fill.setScale(0.2f,-0.2f);
	hp_border.setScale(0.2f,0.2f);
		hp_fill.setPosition(850,718);
	hp_border.setPosition(850,585);
	_window = &window;
	for( int i = 0; i < 5; i++)
	{
		teksti[i].setFont(*_font);
string Result;          // string which will contain the result
ostringstream convert;   // stream used for the conversion
convert << i+1;      // insert the textual representation of 'Number' in the characters in the stream
Result = convert.str();

			teksti[i].setString(Result);
	teksti[i].setColor(Color::Yellow);
	teksti[i].setPosition(i*pistol_sprite.getGlobalBounds().width +10,0);
	}
}

GUI::~GUI(void)
{
}
		
void GUI::Update(int health,float dt)
{
	
		hp_fill.setTextureRect(IntRect(0,0,665,665.0f/100.0f * health));

		
}
void GUI::Draw()
{
	_window->draw(hp_border);
		_window->draw(hp_fill);
		if(w->getActiveWeapon() != -1)
		{
		for(int i = 0; i < 5; i++)
			_window->draw(teksti[i]);

		switch(w->getActiveWeapon())
		{
		case(1):
			_window->draw(pistol_sprite);
			break;
		case(2):
		_window->draw(m60_sprite);
		break;
		}
		
		}

}
