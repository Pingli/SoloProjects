#include "LevelLoader.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "../Settings.hpp"
#include "../Entity2D.hpp"
#include "Player.hpp"
#include "Ghost.hpp"
#include <memory>
#include "Structs.hpp"


void LevelLoader::LoadLevel(const std::string& filePath, GameInfo &outInfo)
{
	std::vector<std::vector<int>> level;
	FileTo2DVectorInt(filePath, level);
	SpawnLevelObjects(level, outInfo);
	outInfo.level = level;
}

void LevelLoader::SetEntitySpriteAndPosition(sf::Vector2i tilePosition, int tileNumber, const sf::Vector2i& dimension, Entity2D& ent)
{
	ent.SetTextureFromSpritesheet(SPRITESHEET_PACMAN_FULL_PATH, tileNumber, dimension);
	ent.SetPositionToTile(tilePosition);
}

void LevelLoader::SpawnLevelObjects(const std::vector<std::vector<int>>& level, GameInfo &outInfo)
{
	//TODO: think about this loop for more than 2 seconds
	int i = 0;
	for (auto vectorIterator = level.begin(); vectorIterator != level.end(); ++vectorIterator)
	{
		int n = 0;
		auto rowVector = *vectorIterator;
		for (auto it = rowVector.begin(); it != rowVector.end(); ++it)
		{
			int tileNumber = *it;
			Tile tileEnum = (Tile)tileNumber;
			sf::Vector2i dimension(TILE_WIDTH, TILE_HEIGHT);
			Entity2D* ent;


			//TODO: tile specific logic here, such as pickup spawning or ghost/player
			switch (tileEnum)
			{
				case Tile::PACMAN:
					//ent = new Player();
					dimension *= 2;
					outInfo.player = std::make_unique<Player>();
					ent = outInfo.player.get();
					*it = (int)Tile::EMPTY;
					break;
				case Tile::BLINKY:
				case Tile::INKY:
				case Tile::PINKY:
				case Tile::CLIDE:
					ent = new Ghost();
					dimension *= 2;
					break;

				case Tile::EMPTY:
				case Tile::PICKUP:
				case Tile::PICKUP_BIG:
					ent = new Entity2D();
					break;
				default:
					ent = new Entity2D();
					break;
			}

			SetEntitySpriteAndPosition(sf::Vector2i(n, i), tileNumber, dimension, *ent);
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
