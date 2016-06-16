#include <SFML/Graphics.hpp>
#include "Game/Game.hpp"
#include "Entity2D.hpp"
#include "Settings.hpp"
#include "Input.hpp"


int main()
{
	sf::RenderWindow window(sf::VideoMode(VIDEO_WIDTH, VIDEO_HEIGHT), WINDOW_TITLE);
	window.setSize(sf::Vector2u(SCREEN_WIDTH, SCREEN_HEIGHT));
	auto mode = sf::VideoMode::getDesktopMode();
	window.setPosition(sf::Vector2i((mode.width - SCREEN_WIDTH) / 2, (mode.height - SCREEN_HEIGHT) / 2));

	Game game;
	Input& input = Input::GetInstance();
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


