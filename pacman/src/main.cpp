#include <SFML/Graphics.hpp>
#include "Game/Game.hpp"
#include "Entity2D.hpp"
#include "Settings.hpp"
#include "Input.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_TITLE);

	Game game;
	Input input;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::KeyPressed:
					input.KeyPressedEvent(event.key.code);
					break;
				case sf::Event::KeyReleased:
					input.KeyReleasedEvent(event.key.code);
					break;
			}
		}

		window.clear();
		Entity2D::DrawSprites(window);
		window.display();
		game.Update();
		input.StepKeyboardState();
	}

	return 0;
}


