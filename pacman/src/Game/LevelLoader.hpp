#include <vector>

class LevelLoader
{
	public:
		void LoadLevel();
	private:
		std::vector<std::string> Split(const std::string& s, char delim);
		std::vector<std::string>& Split(const std::string& s, char delim, std::vector<std::string>& elems);
};
