#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>
#include <memory>

struct GameInfo;
enum class Tile;
class Entity2D;

class LevelLoader
{
	public:
		static void LoadLevel(const std::string& filePath, GameInfo &outInfo);
		static void SetEntitySpriteAndPosition(sf::Vector2i tilePosition, int tileNumber, const sf::Vector2i& dimension, Entity2D& ent);
	private:
		static void FileTo2DVectorInt(const std::string& filePath, std::vector<std::vector<int>>& level);
		static void SpawnLevelObjects(std::vector<std::vector<int>>& level, GameInfo &outInfo);
		static void SetSprite1x1(Entity2D& levelEntities, int row, int col, Tile tile);
		static void SetSprite2x2(Entity2D& entity, int row, int col, Tile tile);
		static std::vector<int> SplitStringToInt(const std::string& s, char delim);
		static void SplitStringToInt(const std::string& s, char delim, std::vector<int>& elems);
};
