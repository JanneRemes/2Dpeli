#pragma once
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include "TextureHandler.h"
#include "gameTimer.h"
#include "PlayerObject.h"
#include "Bullet.h"
#include "Enemy.h"
#include <string>
#include <sstream>
#include <iostream>
#include "SceneParent.h"
#include "GUI.h"
#include "WeaponManager.h"
using namespace sf;
using namespace std;
class Game
	:public SceneParent
{
public:
	Game(RenderWindow *window);
	~Game(void);
	void Update(float dt);
		void Draw();
		 void reduceHealth(int amount);
private:
	void updateShots(float dt);
	GUI gui;
	SoundBuffer _shotSound;
	Sound _shotPlayer;
	 int _health;
	int points;
	//RenderWindow* _window;
		Vector2i mousePos;
		Font fontti;
	Text teksti;
	Sprite sprite;
	Sprite enemy_sprite;
	Sprite player_sprite;
	//Texture enemy;
	//Texture tex;
	Texture player;
	PlayerObject player_object;
	vector<Enemy*> viholliset;
	vector<Enemy*>::iterator it;
	vector<Bullet> bullets;
	WeaponManager w_manager;
	void Update(float dt, int mouseY);
	void createEnemy();
	gameTimer *spawnTimer;
	void openMenu();
	void loadAssets();
void checkEnemyDamage();
void drawEnemies();
void updateEnemies(float dT);
void updateBullets(float dt);
void checkEnemyHit(Vector2i mpos);
};

