#include "LevelLoader.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <cassert>
#include "../Settings.hpp"
#include "../Entity2D.hpp"
#include "Player.hpp"
#include "Ghost.hpp"
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

void LevelLoader::SpawnLevelObjects(std::vector<std::vector<int>>& level, GameInfo &outInfo)
{
	assert(outInfo.levelEntities.size() == 0);

	//Perhaps use integer loop? Shouldn't make a big difference for vectors
	int i = 0;
	for (auto vectorIterator = level.begin(); vectorIterator != level.end(); ++vectorIterator)
	{
		int n = 0;
		auto rowVector = *vectorIterator;
		outInfo.levelEntities.emplace_back();

		for (auto it = rowVector.begin(); it != rowVector.end(); ++it)
		{
			int tileNumber = *it;
			Tile tileEnum = (Tile)tileNumber;

			outInfo.levelEntities[i].emplace_back(std::make_unique<Entity2D>());
			Entity2D& levelEntity = *outInfo.levelEntities[i][n];

			switch (tileEnum)
			{
				case Tile::PACMAN:
					level[i][n] = (int)Tile::EMPTY;
					SetSprite1x1(levelEntity, i, n, Tile::EMPTY);

					outInfo.player = std::make_unique<Player>();
					SetSprite2x2(*outInfo.player, i, n, tileEnum);
					break;
				case Tile::BLINKY:
				case Tile::INKY:
				case Tile::PINKY:
				case Tile::CLIDE:
				{
					level[i][n] = (int)Tile::EMPTY;
					SetSprite1x1(levelEntity, i, n, Tile::EMPTY);

					outInfo.ghosts.emplace_back(std::make_unique<Ghost>());
					Ghost& ghost = *outInfo.ghosts.back();
					ghost.name = tileNumber;
					SetSprite2x2(ghost, i, n, tileEnum);
					break;
				}
				case Tile::PICKUP:
				case Tile::PICKUP_BIG:
				case Tile::EMPTY:
				default:
					level[i][n] = tileNumber;
					SetSprite1x1(levelEntity, i, n, tileEnum);
					break;
			}
			++n;
		}
		++i;
	}
}

void LevelLoader::SetSprite1x1(Entity2D& entity, int row, int col, Tile tile)
{
	SetEntitySpriteAndPosition(sf::Vector2i(col, row), (int)tile, sf::Vector2i(TILE_WIDTH, TILE_HEIGHT), entity);
}

void LevelLoader::SetSprite2x2(Entity2D& entity, int row, int col, Tile tile)
{
	SetEntitySpriteAndPosition(sf::Vector2i(col, row), (int)tile, sf::Vector2i(TILE_WIDTH * 2, TILE_HEIGHT * 2), entity);
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
