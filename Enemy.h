
#pragma once
#include <SFML\Graphics.hpp>
#include "SpriteSheet.h"
using namespace sf;
class Enemy
{
public:
	Enemy(int hp, float _speed,int _maxX,Sprite sp,int frameWidth,int frameHeight,int frameCount, float frameTime= 200.0f);
	Enemy(int hp, float _speed,int _maxX,Sprite sp,int frameWidth,int frameHeight,int frameCount, float frameTime,float attackTimer,float damage,int minY,int maxY);
	~Enemy(void);
	void Update(float dT);
	Sprite getSprite();
	bool isDead;
		bool canAttack();
	float getDamage();
	void loseHealth(float amount);
protected:
	float attackTimer;
	float damage;
	int health;
	float speed;
	int maxX;
	Vector2f p;
	SpriteSheet *spritesheet;
};

