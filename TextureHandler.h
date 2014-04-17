#pragma once
#include<map>
#include <SFML\Graphics.hpp>
#include<string>
#include <utility>
using namespace std;
using namespace sf;
class TextureHandler
{
public:
	static Texture* getTexture(string name);
	 static void addTexture(string texName,Texture *tex);
	 static void addTextures();
	static Texture* nameToTexture(string name);
	static void print();
private:
	 static map<string,Texture*> lista;
	static bool textureExists(string name);
};

