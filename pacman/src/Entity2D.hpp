#pragma once

#include <SFML/Graphics.hpp>
#include <vector>



class RenderWindow;
class Entity2D
{
	public:
		Entity2D();
		virtual ~Entity2D();

		sf::Vector2i GetTile() const;
		void SetTextureFromSpritesheet(const std::string& filePath, const int tileNumber);
		void SetTextureFromFile(const std::string& filePath);
		void SetTexture(const sf::Texture& texture);

		void SetPosition(const float x, const float y);

		//should probably make private and accesible to friend classes
		static void DrawSprites(sf::RenderWindow& window);
		static void UpdateEntities();

		std::string name;
	protected:
		virtual void Update();
	private:

		void Init();
		sf::Sprite sprite;
		static std::vector<sf::Sprite*> sprites;
		static std::vector<Entity2D*> entities;
};
