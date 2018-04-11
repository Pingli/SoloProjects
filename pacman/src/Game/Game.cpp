#include "Game.hpp"
#include "../Settings.hpp"
#include "../Entity2D.hpp"
#include "Ghost.hpp"
#include "LevelLoader.hpp"
#include <SFML/Graphics.hpp>
#include "../Input.hpp"

Game::Game() : exitGame(false)
{
	Init();
	printf("game init\n");
}

void Game::Init()
{
	info = GameInfo();
	info.pickupCount = 0;
	LevelLoader::LoadLevel(LEVEL_FULL_PATH, info);
}

void Game::Update()
{
	if (Input::GetInstance().OnKeyDown(sf::Keyboard::R))
	{
		printf("Restarting level\n");
		Init();
	}
	if (Input::GetInstance().OnKeyDown(sf::Keyboard::Escape))
	{
		exitGame = true;
	}
	//TODO: UI

	if (info.pickupCount != 0)
	{
		UpdateGhosts();
		info.player->Update(info);
	}
}

void Game::UpdateGhosts()
{
	for (auto& ghost : info.ghosts)
	{
		ghost->Update(info);
	}
}

void Game::DrawSprites(sf::RenderWindow& window)
{
	if (exitGame)
	{
		window.close();
	}

	DrawBackgroundAndWalls(window);
	DrawGhosts(window);
	window.draw(info.player->GetSprite());
}

void Game::DrawBackgroundAndWalls(sf::RenderWindow& window)
{
	for (auto& levelEntity : info.levelEntities)
	{
		for (auto& entity2D : levelEntity)
		{
			Entity2D& ent = *entity2D;
			const sf::Sprite& sprite = ent.GetSprite();
			window.draw(sprite);
		}
	}
}

void Game::DrawGhosts(sf::RenderWindow& window)
{
	for (auto& ghost : info.ghosts)
	{
		Ghost& ent = *ghost;
		const sf::Sprite& sprite = ent.GetSprite();
		window.draw(sprite);
	}
}