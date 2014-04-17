#include "TextureHandler.h"
#include <iostream>
#include <algorithm>
map<string,Texture*> TextureHandler::lista;
void TextureHandler::addTextures()
{
	addTexture("hp_border",nameToTexture("hp_border"));
	addTexture("hp_fill",nameToTexture("hp_fill"));
	addTexture("tausta",nameToTexture("kuva"));
	addTexture("enemy",nameToTexture("image1"));
	addTexture("shot",nameToTexture("shot"));
	addTexture("pistooli",nameToTexture("pistooli"));
	addTexture("m60",nameToTexture("m60"));
	addTexture("bird",nameToTexture("lokki_anim"));
}
Texture*  TextureHandler::nameToTexture(string name)
{
	Texture *tex = new Texture();
	string filename = name + ".png";
	cout<<filename<<" TextureHandler"<<endl;
	if(!tex->loadFromFile(filename))
	{
		cout<<"Error loading "<<name<<" texture."<<endl;
	}
	return tex;
}
Texture* TextureHandler::getTexture(string name)
	{
		map<string, Texture*>::iterator it;
		for(it = lista.find(name);it != lista.upper_bound(name);it++)
		{
				return  (*it).second;
		}
	
			cout<<"Error loading texture!"<<endl;
		
	}
bool TextureHandler::textureExists(string name)
{
		map<string, Texture*>::iterator it;
		for(it = lista.find(name);it != lista.upper_bound(name);it++)
		{
			cout<<"Error tex already exists! "<<name<<endl;
				return  true;
		}
		cout<<"Texture doesn't exist! "<<name<<endl;
	return false;
}
void TextureHandler::addTexture(string texName,Texture *tex)
	{
		//if(!textureExists(texName))
		lista.insert(make_pair(texName,tex));
	}
void TextureHandler::print()
{
	map<string, Texture*>::iterator it;
	int i= 0;
	for(it = lista.begin(); it != lista.end();it++)
		i++;
	cout<<"Size of textureHandler: "<<i<<endl;
}