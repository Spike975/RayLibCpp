#pragma once
#include "inventory.h"

#include "raylib.h"
class MyHero{
public:
	void operator +(Potion & p);
	int getHealth();
	void setHealth(int hp);
	void health(int hp);
	void draw();
	void changeWeapon();
	void changeArmor();
	void setPlayerText(Texture2D texture);
private:
	char name[21], special[21];
	int age, hitPoints, wealth;
	Texture2D player;
	Inventory inv;
	Equipped equ;
};

