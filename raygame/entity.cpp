#include "entity.h"
#include <cstring>
#include <iostream>

Entity::Entity()
{
	char first[] = { "Default" };

	*nameFirst = first;
	*nameLast= first;
	*healthPoints = 10;
	*attack = 5;
	*defense = 5;
}
Entity::Entity(float hP, float atk, float def, char * first[], char * last[]) {
	*healthPoints = hP;
	*attack = atk;
	*defense = def;
	strcpy_s(*nameFirst,16, *first);
	strcpy_s(*nameLast,16, *last);
}

Entity::~Entity()
{
	std::cout << nameFirst << " " << nameLast << " has died.\n";
}