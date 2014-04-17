#include "RoundHandler.h"
static int _floor = 0;
void RoundHandler::addFloor()
{
	_floor++;
}
 int RoundHandler::getEnemyAmount()
{
	return _floor * 5;
}
void RoundHandler::getEnemyTypes()
{

}



RoundHandler::~RoundHandler(void)
{
}
