#include <SFML/Graphics.hpp>
#include "Settings.hpp"
#include "Entity2D.hpp"


bool qwerty = true;
Entity2D* ent;

void Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && qwerty)
	{
		qwerty = false;
		ent = new Entity2D(ASSET_PATH + "yellow.png");
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && !qwerty)
	{
		qwerty = true;
		delete ent;
		ent = nullptr;
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), WINDOW_TITLE);

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

		Update();
	}

	return 0;
}