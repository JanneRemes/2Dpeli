#include "Enemy.h"
#include "Game.h"
//(Sprite sprite, int frameWidth, int frameHeight, int frameCount, float frameTime = 200.0f);
Enemy::Enemy(int hp, float _speed,int _maxX,Sprite sp,int frameWidth,int frameHeight,int frameCount, float frameTime)
	:health(hp),speed(_speed),maxX(_maxX)
{
	p = Vector2f(-50,rand() % 350 + 250);
	spritesheet = new SpriteSheet(sp,frameWidth,frameHeight,frameCount,frameTime,false);
	isDead = false;
	attackTimer = 0.5f;
	damage = 3.0f;
}
	Enemy::Enemy(int hp, float _speed,int _maxX,Sprite sp,int frameWidth,int frameHeight,int frameCount, float frameTime,float attackTimer,float damage,int minY, int maxY)
		:health(hp),speed(_speed),maxX(_maxX)
{
	p = Vector2f(-50,rand() % 350 + 250);
	spritesheet = new SpriteSheet(sp,frameWidth,frameHeight,frameCount,frameTime,false);
	isDead = false;
	this->attackTimer = attackTimer;
	this->damage = damage;
}
Enemy::~Enemy(void)
{
}
void Enemy::Update(float dT)
{
	if(p.x + speed * dT < maxX)
	p = Vector2f(p.x + speed * dT,p.y);
	else
	{
		attackTimer -= dT;
	}
	spritesheet->Update(dT);
}
bool Enemy::canAttack()
{
			if(attackTimer <= 0)
		{
			
		cout<<"Dealth: "<<damage<<" damage."<<endl;
			attackTimer = 3.0f;
			return true;
		}
			return false;
}
float Enemy::getDamage()
{
	return damage;
}
Sprite Enemy::getSprite()
{
	Sprite a = spritesheet->getSprite();
	a.setPosition(p);

	return a;
}
void Enemy::loseHealth(float amount)
{
	health -= amount;
	if(health <= 0)
		isDead = true;
}