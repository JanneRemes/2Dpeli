#include "gameTimer.h"
#include "SpriteSheet.h"
#include <iostream>

SpriteSheet::SpriteSheet(Sprite sprite, int fWidth, int fHeight, int fCount, float fTime = 200.0f,bool playOnce = false)
	:frameWidth(fWidth),frameHeight(fHeight),frameCount(fCount)
{
	frameTimer = new gameTimer(fTime);
	sp = sprite;
	currentFrame = 0;
	tex_width = sp.getTextureRect().width;
	tex_height = sp.getTextureRect().height;
		sp.setTextureRect(IntRect((currentFrame * frameWidth) % tex_width,
                                                ((currentFrame * frameWidth) / tex_width) * frameHeight,
                                                frameWidth,
                                                frameHeight));
	this->playedOnce = false;
	this->playOnce = playOnce;
}
SpriteSheet::SpriteSheet(void)
{
	this->playedOnce = false;
}
SpriteSheet::~SpriteSheet(void)
{
}
 void SpriteSheet::Update(float dT)
{
	if(playOnce)
	{
		if(playedOnce)
		{
			return;
		}
	}
	if (frameCount != 0 && frameTimer->Update(dT))
	{
		if(currentFrame == frameCount-1 && playOnce)
		{
			playedOnce = true;
			return;
		}
	currentFrame = (currentFrame + 1) % frameCount;

	sp.setTextureRect(IntRect((currentFrame * frameWidth) % tex_width,
                                                ((currentFrame * frameWidth) / tex_width) * frameHeight,
                                                frameWidth,
                                                frameHeight));
	}
}
 Sprite SpriteSheet::getSprite()
 {
	 return sp;
 }
 void SpriteSheet::setPosition(Vector2f p)
 {
	 sp.setPosition(p);
 }
 bool SpriteSheet::getPlayedOnce()
 {
	 return playedOnce;
 }