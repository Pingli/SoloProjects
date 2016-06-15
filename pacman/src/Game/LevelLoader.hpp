#pragma once

#include <vector>

class LevelLoader
{
	public:
		static std::vector<std::vector<int>> LoadLevel(const std::string& filePath);
	private:
		static void FileTo2DVectorInt(const std::string& filePath, std::vector<std::vector<int>>& level);
		static void SpawnLevelObjects(const std::vector<std::vector<int>>& level);
		static std::vector<int> SplitStringToInt(const std::string& s, char delim);
		static void SplitStringToInt(const std::string& s, char delim, std::vector<int>& elems);
};
