#pragma once
#include "SFML\Graphics.hpp"
class InputHandler
{
public:
	static bool leftMouseStartedPressing();
	static void Update(bool p);
private:
	static bool leftMouseDown;
};

