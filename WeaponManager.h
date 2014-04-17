#pragma once
#include "Bullet.h"
#include <vector>
#include <iostream>
#include "gameTimer.h"
using namespace std;

class WeaponManager
{
public:
	struct weapon
{
	string nimi;
	float attackSpeed;
	float reloadTime;
	float damage;
	int ammo;

}pistol,machinegun,shotgun,rpg;
	WeaponManager(vector<Bullet> *b);
	WeaponManager(void){};
	~WeaponManager(void);
	void addWeapon(int weapon);
	void Update(float dt);
	void handleShot();
	int getActiveWeaponSlot();
	int getActiveWeapon();
	float getWeaponDamage();
	int* getWeapons()
	{
		return weapons;
	}
private:
	void setWeaponStats();
	void changeActiveWeaponSlot(int slot);
	int weapons[5];
	int selectedSlot;
	vector<Bullet> *bullets;
};

