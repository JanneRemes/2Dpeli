#pragma once
class gameTimer
{
public:
	gameTimer(float delaymillis);
	~gameTimer(void);
	bool Update(float dt);
	void setDelay(float d);
	float getDelay();
private:
	float currentTime;
	float delay;
};

