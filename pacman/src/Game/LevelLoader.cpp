#include "LevelLoader.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>



std::vector<std::vector<std::string>> LevelLoader::LoadLevel(const std::string& filePath)
{
	std::vector<std::vector<std::string>> level;
	FileTo2DVector(filePath, level);

	for (auto vectorIterator = level.begin(); vectorIterator != level.end(); ++vectorIterator)
	{
		auto rowVector = *vectorIterator;
		for (auto it = rowVector.begin(); it != rowVector.end(); ++it)
		{
			std::string value = *it;
			static int count = 0;
			printf("%i \n", ++count);


		}
	}

	return level;
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
