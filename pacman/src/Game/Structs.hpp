#pragma once

#include <memory>
#include <vector>
#include "../Entity2D.hpp"
#include "Ghost.hpp"

struct GameInfo
{
	std::vector<std::vector<int>> level;
	//walls, pickups and empty tiles
	std::vector<std::vector<std::unique_ptr<Entity2D>>> levelEntities;
	std::unique_ptr<Entity2D> player;
	std::vector<std::unique_ptr<Ghost>> ghosts;
};