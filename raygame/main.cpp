/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include <iostream>
#include <stdlib.h>
#include "raylib.h"
#include "myHero.h"
#include "tile.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	Texture2D blocks[] = { LoadTexture("resources/water.png"),LoadTexture("resources/dirt.png"),LoadTexture("resources/grass.png") };
	Texture2D faces[] = { LoadTexture("resources/ouch1.png"), LoadTexture("resources/ouch2.png"),LoadTexture("resources/ouch3.png"),LoadTexture("resources/ouch4.png"),LoadTexture("resources/ouch5.png") };
	

	const int something = (int)ceil((floor(GetScreenWidth() / blocks[0].width) + 1)*(floor(GetScreenHeight() / blocks[0].height) + 1));

	Tile water[something];
	int temp1 = 0;
	int temp2 = 0;
	int waterTiles = 0;
	do{
		water[waterTiles].Background = blocks[0];
		water[waterTiles].position.x = temp1;
		water[waterTiles].position.y = temp2;

		temp1 += water[waterTiles].Background.width;
		if (temp1 > GetScreenWidth()) {
			temp1 = 0;
			temp2 += water[waterTiles].Background.height;
		}
		waterTiles++;
	} while(temp2 < GetScreenHeight());

	std::cout << GetScreenWidth() / blocks[0].width <<std::endl;
	std::cout << GetScreenHeight() / blocks[0].height <<std::endl;

	std::cout << something <<std::endl;
	std::cout << waterTiles <<std::endl;

	MyHero player;
	Potion p1(10, 1);
	Potion p2(-15, 1);
	player.setHealth(100);

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		if (player.getHealth() >= 80) {
			player.setPlayerText(faces[0]);
		}
		else if (player.getHealth() >= 60) {
			player.setPlayerText(faces[1]);
		}
		else if (player.getHealth() >= 40) {
			player.setPlayerText(faces[2]);
		}
		else if (player.getHealth() >= 20) {
			player.setPlayerText(faces[3]);
		}
		else {
			player.setPlayerText(faces[4]);
		}
		//----------------------------------------------------------------------------------
		if (IsKeyPressed(KEY_F)){
			player + p1;
		}
		if (IsKeyPressed(KEY_T)) {
			player + p2;
		}
		if (player.getHealth() > 100) {
			player.setHealth(100);
		}
		if (player.getHealth() < 0) {
			player.setHealth(0);
		}
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);
		for (int i = 0; i < waterTiles; i++) {
			water[i].draw();
		}
		player.draw();
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}