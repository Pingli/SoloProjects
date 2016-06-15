#include "LevelLoader.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "../Settings.hpp"
#include "../Entity2D.hpp"


std::vector<std::vector<std::string>> LevelLoader::LoadLevel(const std::string& filePath)
{
	std::vector<std::vector<std::string>> level;
	FileTo2DVector(filePath, level);

	SpawnLevelObjects(level);

	return level;
}

void LevelLoader::SpawnLevelObjects(const std::vector<std::vector<std::string>>& level)
{
	int i = 0;
	for (auto vectorIterator = level.begin(); vectorIterator != level.end(); ++vectorIterator)
	{
		int n = 0;
		auto rowVector = *vectorIterator;
		for (auto it = rowVector.begin(); it != rowVector.end(); ++it)
		{
			//maybe not that safe?
			int tileNumber = atoi((*it).c_str());
			Tile tileEnum = (Tile)tileNumber;
			//static int count = 0;
			//intentional memory leak at this point, needs to be moved somewhere else
			Entity2D* ent;

			switch (tileEnum)
			{
				case Tile::EMPTY:
				case Tile::PICKUP:
				default:
					ent = new Entity2D();
					ent->SetTextureFromSpritesheet(SPRITESHEET_PACMAN_FULL_PATH, tileNumber);
					ent->SetPosition(n * TILE_WIDTH, i * TILE_HEIGHT);
					break;

					break;
					//printf("%i is not yet supported, should add it asap.\n", tileEnum);
					break;
			}
			++n;
		}
		++i;
	}
}

void LevelLoader::FileTo2DVector(const std::string& filePath, std::vector<std::vector<std::string>>& level)
{
	std::ifstream myfile(filePath);
	if (myfile.is_open())
	{
		std::string line;
		while (getline(myfile, line))
		{
			level.push_back(Split(line, ','));
		}
		myfile.close();
	}
}

std::vector<std::string>& LevelLoader::Split(const std::string& s, char delim, std::vector<std::string>& elems)
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim))
	{
		elems.push_back(item);
	}
	return elems;
}


std::vector<std::string> LevelLoader::Split(const std::string& s, char delim)
{
	std::vector<std::string> elems;
	Split(s, delim, elems);
	return elems;
}
