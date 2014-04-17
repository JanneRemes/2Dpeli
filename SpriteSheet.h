#pragma once
#include <SFML\Graphics.hpp>
#include "gameTimer.h"
using namespace sf;
class SpriteSheet
{
public:
	SpriteSheet(Sprite sprite, int fWidth, int fHeight, int fCount, float frameTime,bool playOnce);
	~SpriteSheet(void);
	void Update(float dt);
	Sprite getSprite();
	SpriteSheet(void);
	 void setPosition(Vector2f p);
	  bool getPlayedOnce();
private:
	bool playOnce;
	int frameWidth, frameHeight,
     currentFrame, frameCount;
	Sprite sp;
	bool playedOnce;
	gameTimer *frameTimer;
	int tex_width, tex_height;

};

