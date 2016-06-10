#include <SFML/Graphics.hpp>
#include <string>
#include <vector>


class RenderWindow;
class Entity2D
{
	public:
		Entity2D();
		Entity2D(const std::string filePath);
		Entity2D(const sf::Texture& texture);
		virtual ~Entity2D();
		void SetTextureFromFile(const std::string filePath);
		void SetTexture(const sf::Texture& texture);
		static void DrawSprites(sf::RenderWindow& window);

	private:
		void Init();
		sf::Sprite sprite;
		static std::vector<sf::Sprite*> sprites;
};
