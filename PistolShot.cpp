#include "PistolShot.h"
#include <iostream>
//Sprite sprite, int fWidth,int fHeight,int fCount, float fTime
PistolShot::PistolShot(Sprite sprite):Shot(sprite,84,96,5,100.0f)
{
}


PistolShot::~PistolShot(void)
{
	std::cout<<"pistolshot deleted"<<std::endl;
}
void PistolShot::Update(float dt)
{
		_sp.Update(dt);
	if(playedOnce()) 
	isKilled = true;
	
}
void PistolShot::Draw()
{

}
