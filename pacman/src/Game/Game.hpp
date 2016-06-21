#pragma once
#include "Structs.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
	public:
		void Init();
		Game();
		void UpdateGhosts();
		void Update();
		void DrawBackgroundAndWalls(sf::RenderWindow& window);
		void DrawGhosts(sf::RenderWindow& window);
		void DrawSprites(sf::RenderWindow& window);
	private:
		GameInfo info;
		bool exitGame;
};
