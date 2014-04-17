#include "PlayerObject.h"

#include <iostream>
#define speed 2.0f
#define minY 300.0f
#define maxY 670.0f
PlayerObject::PlayerObject(Sprite sp,float _speed)
{
	p = Vector2f(750,300);
	p_drawed = Vector2f (750,300);
	sprite = sp;
}
PlayerObject::PlayerObject()
{
}
PlayerObject::~PlayerObject(void)
{
}
void PlayerObject::Update(float dT,int mouseY)
{
	//std::cout<<mouseY<<"mouse"<<std::endl;
	if(mouseY> minY && mouseY < maxY)
		p = Vector2f(p.x,mouseY - 35);
	//std::cout<<"pos: "<<p.x<<","<<p.y<<std::endl;
	if(p_drawed.y < p.y  && p.y - p_drawed.y > 0.1f)
	{
		//std::cout<<p.y-p_drawed.y<<std::endl;
		p_drawed.y+= (p.y - p_drawed.y)*0.05f ;
	}
	else if(p_drawed.y > p.y && p_drawed.y - p.y > 0.1f)
	{
		p_drawed.y-= (p_drawed.y - p.y) * 0.05f;
	}
}
Sprite PlayerObject::getSprite()
{
	sprite.setPosition(p_drawed);

	return sprite;
}