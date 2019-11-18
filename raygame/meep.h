#pragma once
#include "raylib.h"

class meep
{
public:

	//Vars
	bool enabled = true;
	Vector2 position;
	Texture2D playerTexture;
	Texture2D weaponTexture;

	// Constructors & Destructors
	meep();
	meep(bool _enabled);
	meep(char player[], char weapon[], Vector2 point);
	~meep();

	// Misc Functions
	void refresh();

private:
};