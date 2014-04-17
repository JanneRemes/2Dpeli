#pragma once
#include "Shot.h"
class PistolShot
	:public Shot
{
public:
	PistolShot(Sprite sprite);
	~PistolShot(void);
	void Update(float dt);
	void Draw();
};

