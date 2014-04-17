#pragma once
#include "SFML\Graphics.hpp"
#include "SpriteSheet.h"
using namespace std;
class PlayerObject
{
public:
	PlayerObject(Sprite sp,float _speed);
	PlayerObject();
	~PlayerObject(void);
	void Update(float dT,int mouseY);
	Sprite getSprite();
private:
	Sprite sprite;
	Vector2f p;
	Vector2f p_drawed;
};

