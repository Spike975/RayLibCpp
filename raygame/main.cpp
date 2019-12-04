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
#include "sprite.h"
#include "tile.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 800;
	int screenHeight = 450;
	int lands = 0;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
	Texture2D blocks[] = { LoadTexture("resources/water.png"),LoadTexture("resources/dirt.png"),LoadTexture("resources/grass.png") };
	Texture2D faces[] = { LoadTexture("resources/ouch1.png"), LoadTexture("resources/ouch2.png"),LoadTexture("resources/ouch3.png"),LoadTexture("resources/ouch4.png"),LoadTexture("resources/ouch5.png") };
	Texture2D playerText[5] = {LoadTexture("resources/adventurer_idle.png"), LoadTexture("resources/adventurer_stand.png"),LoadTexture("resources/adventurer_jump.png"),LoadTexture("resources/adventurer_walk1.png"),LoadTexture("resources/adventurer_walk2.png")};
	int currentPlayer = 0;
	Tile water[13*8];
	int temp1 = 0;
	int temp2 = 0;
	int waterTiles = 0;
	do{
		water[waterTiles].Background = blocks[0];
		water[waterTiles].position.x = (float)temp1;
		water[waterTiles].position.y = (float)temp2;

		temp1 += water[waterTiles].Background.width;
		if (temp1 > GetScreenWidth()) {
			temp1 = 0;
			temp2 += water[waterTiles].Background.height;
		}
		waterTiles++;
	} while(temp2 < GetScreenHeight());
	
	Sprite charecter(playerText[0], 2,1);

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
		if (IsKeyPressed(KEY_F)){
			player + p1;
		}
		if (IsKeyPressed(KEY_T)) {
			player + p2;
		}
		if (IsKeyPressed(KEY_Q)) {
			SetTextureFilter(playerText[0], -1);
			charecter.spriteCells = playerText[0];
		}
		if (IsKeyPressed(KEY_R)) {
			lands++;
			if (lands > 2){
				lands = 0;
			}
			for (int i = 0; i < waterTiles; i++) {
				water[i].Background = blocks[lands];
			}
		}
		if (IsKeyDown(KEY_W)) {
			charecter.y--;
		}
		if (IsKeyDown(KEY_S)) {
			charecter.y++;
		}
		if (IsKeyDown(KEY_A)) {
			charecter.x--;
		}
		if (IsKeyDown(KEY_D)) {
			charecter.x++;
		}
		if (player.getHealth() > 100) {
			player.setHealth(100);
		}
		if (player.getHealth() < 0) {
			player.setHealth(0);
		}
		//----------------------------------------------------------------------------------
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();
		ClearBackground(RAYWHITE);
		for (int i = 0; i < waterTiles; i++) {
			water[i].draw();
		}
		charecter.Draw();
		player.draw();
		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();
	//--------------------------------------------------------------------------------------

	return 0;
}