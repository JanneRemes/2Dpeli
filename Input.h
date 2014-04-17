#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class Input
{
public:
	Input(void);
	~Input(void);
	static bool isKeyPressed(Keyboard::Key key);
private:
};

