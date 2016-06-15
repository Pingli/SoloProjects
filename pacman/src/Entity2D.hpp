#pragma once

#include <SFML/Graphics.hpp>
#include <vector>


class RenderWindow;
class Entity2D
{
	public:
		Entity2D();
		virtual ~Entity2D();

		void SetTextureFromFile(const std::string& filePath);
		void SetTexture(const sf::Texture& texture);

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
