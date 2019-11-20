#pragma once
#include <string>
#include <iostream>
#include "raylib.h"
class Tile{
public:
	bool masterTile = true;
    Texture2D Background ;
	Vector2 position;
    Color tint;
    Tile();
    Tile(std::string imageFilename);
	void draw();
    ~Tile();
};