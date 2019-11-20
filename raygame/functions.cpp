#include "myHero.h"
#include <iostream>

void MyHero::operator +(Potion & p) {
	hitPoints += (p.getQuality() * p.getHealth());
}
int MyHero::getHealth() {
	return hitPoints;
}
void MyHero::setHealth(int hp) {
	hitPoints = hp;
}
void MyHero::draw() {
	DrawTexture(player, 5, (GetScreenHeight()-player.height)-5,WHITE);
}
void MyHero::setPlayerText(Texture2D texture) {
	player = texture;
}
void MyHero::health(int hp) {
	hitPoints += hp;
	
}

std::string Item::getName() {
	return name;
}
int Item::getQuality() {
	return quality;
}
int Item::getGold() {
	return gold;
}
void Item::setName(std::string nm) {
	name = nm;
}
void Item::setQuality(int q) {
	quality = q;
}
void Item::setGold(int g) {
	gold = g;
}

void Equipped::changeWeapon() {

}
void Equipped::changeArmor() {

}

Potion::Potion() {
	hpMod = 0;
}
Potion::Potion(int hp, int q) {
	hpMod = hp; setQuality(q);
}
void Potion::setHealth(int h){
	hpMod = h;
}
int Potion::getHealth() {
	return hpMod;
}

Weapon::Weapon(){
	damage = 0; range = 0;
}
Weapon::Weapon(int d, int r) {
	damage = d;
	range = r;
}
void Weapon::setDamage(int d) {
	damage = d;
}
int Weapon::getDamage() {
	return damage;
}
void Weapon::setRange(int r) {
	range = r;
}
int Weapon::getRange() {
	return range;
}

Armor::Armor() {
	defense = 0;
}
Armor::Armor(int d) {
	defense = d;
}
void Armor::setDefense(int d) {
	defense = d;
}
int Armor::getDefense() {
	return defense;
}
void Inventory::add(Weapon w) {
	if (currWeapon < 10) {
		weapons[currWeapon] = w;
		currWeapon++;
	}
	else {
		std::cout << "Maximum weapons reached.\n";
	}
}
void Inventory::add(Armor a) {
	if (currArmor < 10) {
		armor[currArmor] = a;
		currArmor++;
	}
	else {
		std::cout << "Maximum armor reached.\n";
	}
	
}
void Inventory::add(Potion p) {
	if (currPotion < 10) {
		potions[currPotion] = p;
		currPotion++;
	}
	else {
		std::cout << "Maximum potions reached.\n";
	}
}
void Inventory::subWeapon() {
	Weapon nothing;
	for (int i = 0; i < currWeapon; i++) {
		std::cout << "[" << i << "]" << weapons[i].getName() << std::endl;
	}
	int place;
	std::cout << "Please enter number:\n";
	std::cin >> place;
	weapons[place] = nothing;
	for (int i = place; i < currWeapon; i++) {
		if (i == currWeapon-1) {
			weapons[i] = nothing;
		}
		else {
			weapons[i] = weapons[i + 1];
		}
	}
	currWeapon--;
}
void Inventory::subArmor() {
	Armor nothing;
	for (int i = 0; i < currArmor; i++) {
		std::cout << "[" << i << "]" << armor[i].getName() << std::endl;
	}
	int place;
	std::cout << "Please enter number:\n";
	std::cin >> place;
	armor[place] = nothing;
	for (int i = place; i < currArmor; i++) {
		if (place == currArmor - 1) {
			armor[place] = nothing;
		}
		else {
			armor[i] = armor[i + 1];
		}
	}
	currArmor--;
}
void Inventory::subPotion() {
	Potion nothing;
	for (int i = 0; i < currPotion; i++) {
		std::cout << "[" << i << "]" << potions[i].getName() << std::endl;
	}
	int place;
	std::cout << "Please enter number:\n";
	std::cin >> place;
	potions[place] = nothing;
	for (int i = place; i < currPotion; i++) {
		if (place == currPotion - 1) {
			potions[place] = nothing;
		}
		else {
			weapons[i] = weapons[i + 1];
		}
	}
	currPotion--;
}

