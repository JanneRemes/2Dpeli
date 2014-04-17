#pragma once
#include "SFML/Graphics.hpp"
#include "SceneParent.h"
#include "SpriteSheet.h"
using namespace sf;
class GameMenu
	:public SceneParent
{
public:
	GameMenu(RenderWindow *WINDOW);
	~GameMenu(void);
	void Update(float dt);
		void Draw();
private:
	Vector2f p;
	void setTexts();
	void loadTextures();
	void setSprites();
	Sprite pistol_sprite;
	Texture bird_tex;
	Sprite bird_sprite;
	SpriteSheet bird_sheet;
	Texture menu_button_tex;
	Texture background_tex;
	Sprite background_sprite;
	Sprite menu_button_sprite;
	Texture testi;
	Sprite testi_sprite;
	 SpriteSheet testi_spritesheet;
	Text credits;
	Font font;
	RenderWindow *_window;
};

