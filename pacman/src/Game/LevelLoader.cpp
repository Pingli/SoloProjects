#include "LevelLoader.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "../Settings.hpp"
#include "../Entity2D.hpp"


std::vector<std::vector<int>> LevelLoader::LoadLevel(const std::string& filePath)
{
	std::vector<std::vector<int>> level;
	FileTo2DVectorInt(filePath, level);
	SpawnLevelObjects(level);

	return level;
}

void LevelLoader::SpawnLevelObjects(const std::vector<std::vector<int>>& level)
{
	//TODO: think about this for more than 2 seconds
	int i = 0;
	for (auto vectorIterator = level.begin(); vectorIterator != level.end(); ++vectorIterator)
	{
		int n = 0;
		auto rowVector = *vectorIterator;
		for (auto it = rowVector.begin(); it != rowVector.end(); ++it)
		{
			int tileNumber = *it;
			Tile tileEnum = (Tile)tileNumber;

			//TODO: intentional memory leak at this point, needs to be moved somewhere else
			Entity2D* ent;
			ent = new Entity2D();
			ent->SetTextureFromSpritesheet(SPRITESHEET_PACMAN_FULL_PATH, tileNumber);
			ent->SetPosition(n * TILE_WIDTH, i * TILE_HEIGHT);

			//TODO: tile specific logic here, such as pickup spawning or ghost/player
			switch (tileEnum)
			{
				case Tile::EMPTY:
				case Tile::PICKUP:
				default:
					break;
			}
			++n;
		}
		++i;
	}
}

void LevelLoader::FileTo2DVectorInt(const std::string& filePath, std::vector<std::vector<int>>& level)
{
	std::ifstream myfile(filePath);
	if (myfile.is_open())
	{
		std::string line;
		while (getline(myfile, line))
		{
			level.push_back(SplitStringToInt(line, ','));
		}
		myfile.close();
	}
}

void LevelLoader::SplitStringToInt(const std::string& s, char delim, std::vector<int>& elems)
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim))
	{
		//TODO: error checks
		elems.push_back(atoi(item.c_str()));
	}
}

std::vector<int> LevelLoader::SplitStringToInt(const std::string& s, char delim)
{
	std::vector<int> elems;
	SplitStringToInt(s, delim, elems);
	return elems;
}
