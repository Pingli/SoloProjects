#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

struct GameInfo;
class RenderWindow;
class Entity2D
{
	public:
		Entity2D();
		virtual ~Entity2D();
		virtual void Update(GameInfo& info);

		sf::Vector2i GetCurrentTilePosition() const;
		const sf::Sprite& GetSprite() const;
		void SetTextureRectPosition(const int tileNumber, sf::IntRect& rect) const;
		void SetSpriteNumber(const int tileNumber);
		void SetTextureFromSpritesheet(const std::string& filePath, const int tileNumber, const sf::Vector2i& dimension);
		void SetTextureFromFile(const std::string& filePath);
		void SetTexture(const sf::Texture& texture);

		void SetPosition(const float x, const float y);
		void SetPosition(const sf::Vector2f& pos);
		void SetPositionToTile(const sf::Vector2i& tile);
		static void WrapPositionX(sf::Vector2i& tileCopy);

		sf::Vector2f positionOffset;
		std::string name;
		sf::Sprite sprite;
	private:
		static sf::Vector2f TileToPosition(const sf::Vector2i& tile);
		static sf::Vector2i PositionToTile(const sf::Vector2f& position);

};
