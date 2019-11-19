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
void MyHero::changeWeapon() {

}
void MyHero::changeArmor() {

}

std::string Item::getName() {
	return name;
}
int Item::getQuality() {
	return quality;
}
void Item::setName(std::string nm) {
	name = nm;
}
void Item::setQuality(int q) {
	quality = q;
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
Potion::~Potion() {

}

Weapon::Weapon(){
	damage = 1;
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
Weapon::~Weapon(){
	std::cout << name << " has broke and no longer exists in this wolrd.\n";
}

Armor::Armor() {
	defense = 1;
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
Armor::~Armor() {

}

Inventory::~Inventory()
{
	std::cout << "I think you died\n";
}


Equipped::~Equipped(){

}