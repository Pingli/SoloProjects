#include "Game.hpp"
#include "../Entity2D.hpp"
#include "LevelLoader.hpp"
#include "../Settings.hpp"
#include "Player.hpp"

Game::Game()
{
	//set up playing field
	//TODO: add references for characters, vector pickups
	LevelLoader::LoadLevel(LEVEL_FULL_PATH);

	//TODO: Character class that inherits from entity. Needs a move-l/r/u/d function that deals with collision
	Player* player = new Player();
	player->name = "pacman";
	sf::Vector2i dim(TILE_WIDTH * 2, TILE_HEIGHT * 2);
	player->SetTextureFromSpritesheet(SPRITESHEET_PACMAN_FULL_PATH, (int)Tile::PACMAN, dim);

	auto shadow = new Entity2D();
	shadow->name = "blinky";
	auto speedy = new Entity2D();
	speedy->name = "pinky";
	auto bashful = new Entity2D();
	bashful->name = "inky";
	auto pokey = new Entity2D();
	pokey->name = "clide";



	printf("game init\n");
}

void Game::Update()
{
	//update entity
	Entity2D::UpdateEntities();
	//collision checks?
	//TODO: UI, while at it give credits to this person for the pacman spritesheet. https://github.com/rm-hull/big-bang/tree/master/examples/pacman
}
