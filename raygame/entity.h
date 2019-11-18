#pragma once

class Entity
{
public:
	float * healthPoints;
	float * attack;
	float * defense;
	char * nameFirst[16];
	char * nameLast[16];
	
	Entity();
	///<summary> Used to declare a specific entity
	/// <param name="hP">Used to indicate health points of entity.</param>
	/// <param name="atk">Used to indicate attack stat of entity.</param>
	/// <param name="def">Used to indicate defense stat of entity.</param>
	/// <param name="first">First name of entity.</param>
	/// <param name="last">Last name of entity.</param>
	///</summary>
	Entity(float hP, float atk, float def, char * first[], char * last[]);
	~Entity();

};