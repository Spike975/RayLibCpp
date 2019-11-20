#include "tile.h"
Tile::Tile() {

}
Tile::Tile(std::string imageFilename) {
	Background = LoadTexture(imageFilename.c_str());
}
void Tile::draw() {
	DrawTexture(Background, (int)position.x, (int)position.y, tint);
}
Tile::~Tile() {

}