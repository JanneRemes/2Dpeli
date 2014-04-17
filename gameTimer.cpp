#include "gameTimer.h"


gameTimer::gameTimer(float delaymillis)

{
	   delay = delaymillis* 0.001f;
	   currentTime = delay;
}


gameTimer::~gameTimer(void)
{
}
bool gameTimer::Update(float dT)
{
	currentTime -= dT;
	if(currentTime <= 0)
	{
		currentTime = delay;
		return true;
	}
	return false;
}
void gameTimer::setDelay(float d)
{
	delay = d * 0.001f;
}
float gameTimer::getDelay()
{
	return delay * 1000.0f;
}