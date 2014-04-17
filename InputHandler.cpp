#include "InputHandler.h"
#include <iostream>
using namespace sf;
bool InputHandler::leftMouseDown;
void InputHandler::Update(bool p)
{
		leftMouseDown = Mouse::isButtonPressed(Mouse::Left);
}
bool InputHandler::leftMouseStartedPressing()
{
	return(Mouse::isButtonPressed(Mouse::Left) && !leftMouseDown);
}