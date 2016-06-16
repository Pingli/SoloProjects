#include "Settings.hpp"


extern const int LEVEL_WIDTH_COUNT = 28;
extern const int LEVEL_HEIGHT_COUNT = 31;
extern const int VIDEO_WIDTH = TILE_WIDTH * LEVEL_WIDTH_COUNT;
extern const int VIDEO_HEIGHT = TILE_HEIGHT * LEVEL_HEIGHT_COUNT;
extern const int SCREEN_WIDTH = VIDEO_WIDTH * 2;
extern const int SCREEN_HEIGHT = VIDEO_HEIGHT * 2;
extern const int TILE_WIDTH = 6;
extern const int TILE_HEIGHT = 6;
extern const char* WINDOW_TITLE = "Pacman";
extern const std::string ASSET_PATH = "../assets/";
extern const std::string LEVEL_FILE_NAME = "level.csv";
extern const std::string LEVEL_FULL_PATH = ASSET_PATH + LEVEL_FILE_NAME;
extern const std::string SPRITESHEET_PACMAN = "spritesheet.png";
extern const std::string SPRITESHEET_PACMAN_FULL_PATH = ASSET_PATH + SPRITESHEET_PACMAN;



