#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class RenderWindow;
class Entity2D
{
	public:
		Entity2D();
		virtual ~Entity2D();

		sf::Vector2f GetTile() const;
		void SetTextureFromSpritesheet(const std::string& filePath, const int tileNumber, const sf::Vector2i& dimension);
		void SetTextureFromFile(const std::string& filePath);
		void SetTexture(const sf::Texture& texture);

		void SetPosition(const float x, const float y);
		void SetPosition(const sf::Vector2f& pos);
		//should probably make private and accesible to friend classes
		static void DrawSprites(sf::RenderWindow& window);
		static void UpdateEntities();

		std::string name;
	protected:
		virtual void Update();
	private:
		void Init();
		static sf::Vector2f TileToPosition(const sf::Vector2f& tile);
		static sf::Vector2f PositionToTile(const sf::Vector2f& position);

		sf::Sprite sprite;
		static std::vector<sf::Sprite*> sprites;
		static std::vector<Entity2D*> entities;
};
