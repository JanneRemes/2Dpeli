#pragma once
#include<map>
#include <SFML\Graphics.hpp>
#include<string>
#include <utility>
using namespace std;
using namespace sf;
class SpriteHandler
{
public:
	 static Sprite* getSprite(string name);
	 static void addSprite(string texturename,Sprite *sprite);
private:
	 static map<string,Sprite*> lista;
};

