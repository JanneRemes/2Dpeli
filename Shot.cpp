#include "Shot.h"


Shot::Shot(Sprite sprite, int fWidth,int fHeight,int fCount, float fTime)
{
	_sp = SpriteSheet(sprite,fWidth,fHeight,fCount,fTime,true);
	isKilled = false;
}


Shot::~Shot(void)
{
}
bool Shot::playedOnce()
{
	return _sp.getPlayedOnce();
}