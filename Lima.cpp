#include "Lima.h"

//viholliset.push_back(new Enemy(100.0f,80.0f,640,enemy_sprite,480,480,12,35.0f));
Lima::Lima(Sprite sp):Enemy(100,80.0f,640,sp,480,480,12,35.0f)
{

}


Lima::~Lima(void)
{
}
void Lima::Update(float dT)
{
	Enemy::Update(dT);
}