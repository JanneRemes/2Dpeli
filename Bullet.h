#pragma once
#include "SFML\Graphics.hpp"
using namespace sf;
class Bullet
{
public:
	Bullet(void);
	Bullet(Sprite sprite,Vector2f pos, bool left,float speed);
	~Bullet(void);
	void Update(float dt);
	Sprite getSprite();
private:
	bool goingLeft;
	Vector2f position;
	float speed;
	Sprite bullet_sprite;
};

