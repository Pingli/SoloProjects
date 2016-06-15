#include <SFML/Graphics.hpp>
#include "Game/Game.hpp"
#include "Entity2D.hpp"
#include "Settings.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_TITLE);
	Game game;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		Entity2D::DrawSprites(window);
		window.display();

		game.Update();
	}

	return 0;
}