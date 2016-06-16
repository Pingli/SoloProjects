#pragma once

#include <memory>
#include <vector>

class Entity2D;
struct GameInfo
{
	//TODO: clean up ghosts and level
	std::vector<std::vector<int>> level;
	std::unique_ptr<Entity2D> player;
	Entity2D* ghosts[4];
};