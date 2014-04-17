#include "Bullet.h"

Bullet::Bullet()
{
}
Bullet::Bullet(Sprite sprite,Vector2f pos, bool left,float speed)
{
	position = pos;
	goingLeft = left;
	this->speed = speed;
	bullet_sprite = sprite;
}


Bullet::~Bullet(void)
{
}
void Bullet::Update(float dt)
{
	if(goingLeft && position.y > -10)
		position.y -= speed * dt;
}
Sprite Bullet::getSprite()
{
	bullet_sprite.setPosition(position);

	return bullet_sprite;
}