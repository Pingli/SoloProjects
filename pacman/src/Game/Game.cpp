#include "Game.hpp"
#include "../Entity2D.hpp"
#include "LevelLoader.hpp"
#include "../Settings.hpp"

Game::Game()
{
	LevelLoader::LoadLevel(LEVEL_FULL_PATH, info);



	printf("game init\n");
}

void Game::Update()
{
	//update entity
	Entity2D::UpdateEntities();
	//collision checks?
	//TODO: UI, while at it give credits to this person for the pacman spritesheet. https://github.com/rm-hull/big-bang/tree/master/examples/pacman


}
