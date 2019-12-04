#pragma once


#include "raylib.h"
#include <iostream>

class Sprite : public Vector2
{
public:
	Texture2D spriteCells;
	float frameRate = 25.0;
	int frameCount = 0;
	int direction = 1;

	void Draw();
	Sprite();
	Sprite(Texture2D  texture, const int cellCount, const float _frameRate);
	~Sprite();
};