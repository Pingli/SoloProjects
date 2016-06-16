#pragma once

#include <vector>
#include <memory>
#include <SFML/System/Vector2.hpp>

class Entity2D;
struct GameInfo
{
	std::vector<std::vector<int>> level;
	std::unique_ptr<Entity2D> player;
	Entity2D* ghosts[4];
};

class LevelLoader
{
	public:
		static void LoadLevel(const std::string& filePath, GameInfo &outInfo);
		static void do_work(sf::Vector2i tilePosition, int tileNumber, const sf::Vector2i& dimension, Entity2D& ent);
		static void UnloadLevel();
	private:
		static void FileTo2DVectorInt(const std::string& filePath, std::vector<std::vector<int>>& level);
		static void SpawnLevelObjects(const std::vector<std::vector<int>>& level, GameInfo &outInfo);
		static std::vector<int> SplitStringToInt(const std::string& s, char delim);
		static void SplitStringToInt(const std::string& s, char delim, std::vector<int>& elems);
};
