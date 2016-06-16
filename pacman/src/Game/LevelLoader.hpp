#pragma once

#include <vector>
#include <SFML/System/Vector2.hpp>

struct GameInfo;
class Entity2D;

class LevelLoader
{
	public:
		static void LoadLevel(const std::string& filePath, GameInfo &outInfo);
		static void SetEntitySpriteAndPosition(sf::Vector2i tilePosition, int tileNumber, const sf::Vector2i& dimension, Entity2D& ent);
	private:
		static void FileTo2DVectorInt(const std::string& filePath, std::vector<std::vector<int>>& level);
		static void SpawnLevelObjects(const std::vector<std::vector<int>>& level, GameInfo &outInfo);
		static std::vector<int> SplitStringToInt(const std::string& s, char delim);
		static void SplitStringToInt(const std::string& s, char delim, std::vector<int>& elems);
};
