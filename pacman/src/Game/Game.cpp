#include "Game.hpp"
#include "../Entity2D.hpp"

Game::Game()
{
	//set up playing field
	//spawn pickups
	//spawn ghosts
	//spawn player
	auto player =  new Entity2D();
	player->name = "pacman";
	auto shadow =  new Entity2D();
	shadow->name = "blinky";
	auto speedy =  new Entity2D();
	speedy->name = "pinky";
	auto bashful =  new Entity2D();
	bashful->name = "inky";
	auto pokey =  new Entity2D();
	pokey->name = "clide";

	printf("game init\n");
}

void Game::Update()
{
	//update entity
	Entity2D::UpdateEntities();
	//collision checks?

}
