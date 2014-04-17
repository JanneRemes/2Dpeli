#include "Bird.h"


Bird::Bird(Sprite sp):Enemy(50,100.0f,300,sp,795,593,5,50.0f)
{
}


Bird::~Bird(void)
{
}
void Bird::Update(float dT)
{
	Enemy::Update(dT);
}