#include "SpriteHandler.h"
#include <iostream>
#include <algorithm>
map<string,Sprite*> SpriteHandler::lista;
	Sprite* SpriteHandler::getSprite(string name)
	{
		map<string, Sprite*>::iterator it;
		for(it = lista.find(name);it != lista.upper_bound(name);it++)
		{
				return  (*it).second;
		}
	
			cout<<"Error loading sprite!"<<endl;
		
	}
	void SpriteHandler::addSprite(string texturename,Sprite *sprite)
	{
		lista.insert(make_pair(texturename,sprite));
	}