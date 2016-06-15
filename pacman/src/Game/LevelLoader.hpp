#pragma once

#include <vector>

class LevelLoader
{
	public:
		static std::vector<std::vector<std::string>> LoadLevel(const std::string& filePath);
		static void FileTo2DVector(const std::string& filePath, std::vector<std::vector<std::string>>& level);
	private:
		static std::vector<std::string> Split(const std::string& s, char delim);
		static std::vector<std::string>& Split(const std::string& s, char delim, std::vector<std::string>& elems);
};
