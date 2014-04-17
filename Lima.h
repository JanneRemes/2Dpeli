#pragma once
#include "Enemy.h"
class Lima
	:public Enemy
{
public:
	Lima(Sprite sp);
	~Lima(void);
	void Update(float dT);
};

