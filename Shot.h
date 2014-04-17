#pragma once
#include "SFML\Graphics.hpp"
#include "SpriteSheet.h"
using namespace sf;
class Shot
{
public:
	Shot(Sprite sprite, int fWidth,int fHeight,int fCount, float fTime);
	virtual ~Shot(void);
	virtual void Update(float dt){};
	virtual void Draw(){};
	Sprite getSprite(){return _sp.getSprite();};
	bool playedOnce();
	bool getIsKilled(){return isKilled;};
protected:
	SpriteSheet _sp;
	bool isKilled;
};

