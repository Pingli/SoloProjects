#include <SFML/Graphics.hpp>
#include "Game/Game.hpp"
#include "Settings.hpp"
#include "Input.hpp"


void EventPolling(sf::RenderWindow& window, Input& input)
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
}

int main()
{
	//set up window
	sf::RenderWindow window(sf::VideoMode(VIDEO_WIDTH, VIDEO_HEIGHT), WINDOW_TITLE);
	window.setSize(sf::Vector2u(SCREEN_WIDTH, SCREEN_HEIGHT));
	auto mode = sf::VideoMode::getDesktopMode();
	window.setPosition(sf::Vector2i((mode.width - SCREEN_WIDTH) / 2, (mode.height - SCREEN_HEIGHT) / 2));


	Game game;
	Input& input = Input::GetInstance();


	//Update loop related variables
	sf::Clock clock;
	constexpr float millisecondModifier = 1000.0f;
	const float updateInterval = 1.0f / GAME_UPDATES_PER_SECOND * millisecondModifier;
	sf::Int32 currentTicks = clock.getElapsedTime().asMilliseconds();
	float prevTicks = currentTicks;

#if DEBUG
	//Render speed
	long lastTime = clock.getElapsedTime().asSeconds();
	int numberFrames = 0;
#endif

	while (window.isOpen())
	{
		//Clear/Render
		window.clear();
		game.DrawSprites(window);
		window.display();

#if DEBUG
		//Render speed
		const float reportInterval = 1.0f;
		long currentTime = clock.getElapsedTime().asSeconds();
		numberFrames++;
		if (currentTime - lastTime >= reportInterval)
		{
			// printf and reset timer
			printf("%i FPS, %f ms/frame\n", numberFrames, 1000.0f / numberFrames);
			numberFrames = 0;
			lastTime += 1.0;
		}
#endif

		currentTicks = clock.getElapsedTime().asMilliseconds();
		float deltaTimeGame = currentTicks - prevTicks;

		//Run the update at a fixed rate per second
		while (deltaTimeGame > updateInterval)
		{
			deltaTimeGame -= updateInterval;

			EventPolling(window, input);
			game.Update();

			//Update no longer behind
			if (deltaTimeGame < updateInterval)
			{
				prevTicks = currentTicks - deltaTimeGame;
			}
		}

		input.StepKeyboardState();
	}

	return 0;
}


