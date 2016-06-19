#include "Player.hpp"
#include "../Input.hpp"
#include "../Settings.hpp"
#include "Structs.hpp"

void Player::Update(GameInfo& info)
{
	PlayerInput(info);
}

void Player::PlayerInput(GameInfo& info)
{
	sf::Vector2i currentTile = GetCurrentTilePosition();
	sf::Vector2i dir;

	if (Input::GetInstance().OnKeyDown(sf::Keyboard::A))
	{
		dir = Left;
	}
	else if (Input::GetInstance().OnKeyDown(sf::Keyboard::D))
	{
		dir = Right;
	}
	else if (Input::GetInstance().OnKeyDown(sf::Keyboard::S))
	{
		dir = Down;
	}
	else if (Input::GetInstance().OnKeyDown(sf::Keyboard::W))
	{
		dir = Up;
	}

	int outTile;
	sf::Vector2i moveToTile = currentTile + dir;
	if (CanMoveToTile(info, currentTile + dir, outTile))
	{
		Tile tile = (Tile)outTile;
		MoveDirection(info, dir);
		switch (tile)
		{
			case Tile::PICKUP:
			case Tile::PICKUP_BIG:
				info.level[moveToTile.y][moveToTile.x] = (int)Tile::EMPTY;
				info.levelEntities[moveToTile.y][moveToTile.x]->SetSpriteNumber((int)Tile::EMPTY);
				break;
		}
	}
}