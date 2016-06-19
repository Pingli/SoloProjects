#pragma once
#include "Structs.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
	public:
		Game();
		void Update();
		void DrawBackgroundAndWalls(sf::RenderWindow& window);
		void DrawGhosts(sf::RenderWindow& window);
		void DrawSprites(sf::RenderWindow& window);
	private:
		GameInfo info;
};
