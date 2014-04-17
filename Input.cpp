#include "Input.h"
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace sf;

Input::Input(void)
{
}


Input::~Input(void)
{
}
 void Input::updateKeys()
{

}
bool Input::isKeyPressed(Keyboard::Key key)
{
	return (Keyboard::isKeyPressed(key));
}