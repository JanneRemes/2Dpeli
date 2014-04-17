#pragma once
#include "Enemy.h"
class Bird
	:public Enemy
{
public:
	Bird(Sprite sp);
	~Bird(void);
	void Update(float dT);
};

