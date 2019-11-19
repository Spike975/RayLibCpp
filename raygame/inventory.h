#include "items.h"
#pragma once

class Inventory {
public:

	~Inventory();
private:

};

class Equipped{
public:
	~Equipped();
private:
	Armor equippedArmor;
	Weapon equippedWeapon;
};
