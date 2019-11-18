#include "meep.h"
#include "raylib.h"

meep::meep() {
	position.x = 0; position.y = 0;
}
meep::meep(bool _enabled) {
	enabled = _enabled;
	position.x = 0; position.y = 0;
}
meep::meep(char player[], char weapon[], Vector2 point) {
	playerTexture = LoadTextureFromImage(LoadImage(player));
	weaponTexture = LoadTextureFromImage(LoadImage(weapon));
	position.x = point.x; position.y = point.y;
}
void meep::refresh() {
	DrawTexture(playerTexture,(int)position.x, (int)position.y, WHITE);
	if (IsKeyDown(KEY_UP)) {
		position.y--;
	}
	if (IsKeyDown(KEY_DOWN)) {
		position.y++;
	}
	if (IsKeyDown(KEY_RIGHT)) {
		position.x++;

	}
	if (IsKeyDown(KEY_LEFT)) {
		position.x--;
	}
}
meep::~meep() {

}