#include "Player.hpp"
#include "../Input.hpp"
#include "../Settings.hpp"
#include "Structs.hpp"

Player::Player():
	currentFacingDirection(Direction::None),
	lastDirectionInput(Direction::None)
{
}

void Player::Update(GameInfo& info)
{
	PlayerInput(info);
	MovePlayer(info);
}

void Player::MovePlayer(GameInfo& info)
{
	sf::Vector2i currentTile = GetCurrentTilePosition();
	sf::Vector2i moveDir(0, 0);
	int outTile;

	if (CanMoveToTile(info, lastDirectionInput, outTile))
	{
		currentFacingDirection = lastDirectionInput;
		moveDir = DirectionEnumToVector2i(lastDirectionInput);
	}
	else if (lastDirectionInput != currentFacingDirection && CanMoveToTile(info, currentFacingDirection, outTile))
	{
		moveDir = DirectionEnumToVector2i(currentFacingDirection);
	}

	{
		Tile tile = (Tile)outTile;
		sf::Vector2i moveToTile = currentTile + moveDir;
		MoveDirection(info, moveDir);
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

void Player::PlayerInput(GameInfo& info)
{
	sf::Vector2i dir;

	if (Input::GetInstance().OnKeyDown(sf::Keyboard::A))
	{
		lastDirectionInput = Direction::dLeft;
	}
	else if (Input::GetInstance().OnKeyDown(sf::Keyboard::D))
	{
		lastDirectionInput = Direction::dRight;
	}
	else if (Input::GetInstance().OnKeyDown(sf::Keyboard::S))
	{
		lastDirectionInput = Direction::dDown;
	}
	else if (Input::GetInstance().OnKeyDown(sf::Keyboard::W))
	{
		lastDirectionInput = Direction::dUp;
	}

}
