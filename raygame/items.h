#pragma once
#include <string>

class Item {
public:
	void setQuality(int q);
	void setGold(int g);
	void setName(std::string nm);
	int getQuality();
	int getGold();
	std::string getName();
private:
	std::string name;
	int quality, gold;
};

class Potion: public Item {
public:
	Potion();
	Potion(int hp, int q);
	void setHealth(int h);
	int getHealth();
private:
	int hpMod;
};

class Weapon: public Item {
public:
	Weapon();
	Weapon(int d, int r);
	void setDamage(int d);
	int getDamage();
	void setRange(int d);
	int getRange();

private:
	std::string name;
	int damage, range;
};

class Armor: public Item {
public:
	Armor();
	Armor(int d);
	void setDefense(int d);
	int getDefense();

private:
	int defense;
};