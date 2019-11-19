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
#include "raylib.h"
#include "myHero.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	Texture2D temp[] = { LoadTexture("resources/ouch1.png"), LoadTexture("resources/ouch2.png"),LoadTexture("resources/ouch3.png"),LoadTexture("resources/ouch4.png"),LoadTexture("resources/ouch5.png") };

	MyHero player;
	Potion p1(10, 1);
	Potion p2(-15, 1);
	player.setHealth(100);

	std::string life;

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------
	std::cout << life;
	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		if (player.getHealth() >= 80) {
			player.setPlayerText(temp[0]);
		}
		else if (player.getHealth() >= 60) {
			player.setPlayerText(temp[1]);
		}
		else if (player.getHealth() >= 40) {
			player.setPlayerText(temp[2]);
		}
		else if (player.getHealth() >= 20) {
			player.setPlayerText(temp[3]);
		}
		else {
			player.setPlayerText(temp[4]);
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