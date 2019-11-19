#pragma once
#include <string>

class Item {
public:
	void setName(std::string nm);
	void setQuality(int q);
	int getQuality();
	std::string getName();
private:
	std::string name;
	int quality;
};

class Potion: public Item {
public:
	Potion();
	Potion(int hp, int q);
	void setHealth(int h);
	int getHealth();
	~Potion();
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
	~Weapon();

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
	~Armor();

private:
	int defense;
};