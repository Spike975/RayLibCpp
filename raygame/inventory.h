#include "items.h"
#pragma once

class Inventory {
public:
	void add(Weapon w);
	void add(Armor a);
	void add(Potion p);
	void subWeapon();
	void subArmor();
	void subPotion();
private:
	Potion potions[10];
	int currPotion = 0;
	Armor armor[10];
	int currArmor = 0;
	Weapon weapons[10];
	int currWeapon = 0;
};

class ShopKeep {
public:

private:
	Potion potions[10];
	
};

class Equipped{
public:
	void changeWeapon();
	void changeArmor();
private:
	Armor equippedArmor;
	Weapon equippedWeapon;
};
