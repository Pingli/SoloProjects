#include <map>
#include <SFML/Graphics/Texture.hpp>


class AssetCache
{

	public:
		static AssetCache& GetInstance()
		{
			static AssetCache instance;
			return instance;
		}

		sf::Texture& AddNewCacheEntry(std::string key)
		{
			auto it = cache.find(key);
			if (it == cache.end())
			{
				cache.emplace(std::pair<std::string, sf::Texture>(key, sf::Texture()));
			}

			return cache[key];
		}

		sf::Texture& GetCacheEntry(std::string key)
		{
			return cache[key];
		}

	private:
		std::map<std::string, sf::Texture> cache;

};

