#include "WeaponManager.h"
#include <string>
using namespace std;
gameTimer weapon_timer(2000);
WeaponManager::WeaponManager(vector<Bullet> *b)
{
	for(int i = 0; i < 5;i++)
		weapons[i] = -1;
	addWeapon(1);
	addWeapon(2);
	for(int i = 0; i < 5;i++)
		std::cout<<weapons[i]<<std::endl;
	selectedSlot = -1;
	setWeaponStats();
}
void WeaponManager::setWeaponStats()
{
	pistol.ammo = 10;
	pistol.attackSpeed = 0.25f;
	pistol.damage = 50.0f;
	pistol.nimi = "pistol";
	pistol.reloadTime = 1.0f;

	machinegun.ammo = 10;
	machinegun.attackSpeed = 0.25f;
	machinegun.damage = 20.0f;
	machinegun.nimi = "machinegun";
	machinegun.reloadTime = 1.0f;
}
WeaponManager::~WeaponManager(void)
{

}
void WeaponManager::addWeapon(int weapon)
{
	for(int i = 0; i< 5;i++)
	{
		if(weapons[i] == -1)
		{
			weapons[i] = weapon;
			break;
		}
	}
}
void WeaponManager::handleShot()
{

}
void WeaponManager::Update(float dt)
{
			if(!weapon_timer.Update(dt))
	{
		if(Keyboard::isKeyPressed(Keyboard::Num1))
			changeActiveWeaponSlot(0);
		else if(Keyboard::isKeyPressed(Keyboard::Num2))
			changeActiveWeaponSlot(1);
	}else
		selectedSlot = -1;
}
void WeaponManager::changeActiveWeaponSlot(int slot)
{
	if(weapons[slot] != -1)
	{
	cout<<"pressed 1"<<endl;
	selectedSlot = slot;
	weapon_timer = gameTimer(2000);
	}
}
int WeaponManager::getActiveWeaponSlot()
{
	return selectedSlot;
}
int WeaponManager::getActiveWeapon()
{
	if(selectedSlot  != -1)
		return weapons[selectedSlot];
	else 
		return -1;
}
float WeaponManager::getWeaponDamage()
{
	switch(weapons[selectedSlot])
	{
	case 1:
		return pistol.damage;
		break;
	case 2:
		return machinegun.damage;
		break;
	default:
		return pistol.damage;
		break;
	}
}