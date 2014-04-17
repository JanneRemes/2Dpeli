#pragma once
#include "SFML\Graphics.hpp"
#include "WeaponManager.h"
#include "gameTimer.h"
using namespace sf;
class GUI
{
public:
	GUI(RenderWindow& window,Font *font,WeaponManager *w);
	GUI(void){};
	~GUI(void);
	void Update(int health,float dt);
	void Draw();
private:
	WeaponManager *w;
	Font *_font;
	Text teksti[5];
	Sprite pistol_sprite;
	Sprite m60_sprite;
	RenderWindow *_window;
	Sprite hp_fill;
Sprite hp_border;
void changeActiveWeaponSlot(int slot);
};

