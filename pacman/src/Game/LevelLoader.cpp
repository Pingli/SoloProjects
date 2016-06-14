#include "LevelLoader.hpp"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

void LevelLoader::LoadLevel()
{
	std::string line;
	std::ifstream myfile("example.txt");
	std::vector<std::string> file;

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			file.push_back(line);
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