#include "Game.hpp"
#include "../Settings.hpp"
#include "../Entity2D.hpp"
#include "Ghost.hpp"
#include "LevelLoader.hpp"
#include <SFML/Graphics.hpp>

Game::Game()
{
	info.pickupCount = 0;
	LevelLoader::LoadLevel(LEVEL_FULL_PATH, info);
	printf("game init\n");
}

void Game::Update()
{
	//TODO: UI

	if (info.pickupCount != 0)
	{
		UpdateGhosts();
		info.player->Update(info);
	}
}

void Game::UpdateGhosts()
{
	for (auto it = info.ghosts.begin(); it != info.ghosts.end(); ++it)
	{
		(*it)->Update(info);
	}
}

void Game::DrawSprites(sf::RenderWindow& window)
{
	DrawBackgroundAndWalls(window);
	DrawGhosts(window);
	window.draw(info.player->GetSprite());
}

void Game::DrawBackgroundAndWalls(sf::RenderWindow& window)
{
	for (auto it = info.levelEntities.begin(); it != info.levelEntities.end(); ++it)
	{
		for (auto it2 = (*it).begin(); it2 != (*it).end(); ++it2)
		{
			Entity2D& ent = **it2;
			const sf::Sprite& sprite = ent.GetSprite();
			window.draw(sprite);
		}
	}
}

void Game::DrawGhosts(sf::RenderWindow& window)
{
	for (auto it = info.ghosts.begin(); it != info.ghosts.end(); ++it)
	{
		Ghost& ent = **it;
		const sf::Sprite& sprite = ent.GetSprite();
		window.draw(sprite);
	}
}