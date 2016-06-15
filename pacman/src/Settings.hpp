#pragma once
#include <string>

extern const int LEVEL_WIDTH_COUNT;
extern const int LEVEL_HEIGHT_COUNT;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int TILE_WIDTH;
extern const int TILE_HEIGHT;
extern const char* WINDOW_TITLE;
extern const std::string ASSET_PATH;
extern const std::string LEVEL_FILE_NAME;
extern const std::string LEVEL_FULL_PATH;
extern const std::string SPRITESHEET_PACMAN;
extern const std::string SPRITESHEET_PACMAN_FULL_PATH;

enum class Tile
{
	PICKUP = 16,
	EMPTY = 160,
	PACMAN = 448,
	BLINKY = 384, //red
	PINKY = 512, //pink
	INKY = 528, //blue
	CLIDE = 576 //orange
};