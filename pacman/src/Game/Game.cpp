#include "Game.hpp"
#include "../Settings.hpp"
#include "../Entity2D.hpp"
#include "Ghost.hpp"
#include "LevelLoader.hpp"
#include <SFML/Graphics.hpp>

Game::Game()
{
	LevelLoader::LoadLevel(LEVEL_FULL_PATH, info);
	printf("game init\n");
}

void Game::Update()
{
	//update entity
	Entity2D::UpdateEntities(info);
	//collision checks?
	//TODO: UI, while at it give credits to this person for the pacman spritesheet. https://github.com/rm-hull/big-bang/tree/master/examples/pacman


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