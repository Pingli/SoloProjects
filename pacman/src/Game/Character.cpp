#include "Character.hpp"
#include "../Settings.hpp"
#include "Structs.hpp"

Character::Character()
{
	positionOffset.x = TILE_WIDTH / 2;
	positionOffset.y = TILE_HEIGHT / 2;
}

void Character::MoveLeft()
{
	sf::Vector2i tile = GetTile();
	tile.x -= moveDistance;
	SetPositionToTile(tile);
}

void Character::MoveRight()
{
	sf::Vector2i tile = GetTile();
	tile.x += moveDistance;
	SetPositionToTile(tile);
}

void Character::MoveUp()
{
	sf::Vector2i tile = GetTile();
	tile.y -= moveDistance;
	SetPositionToTile(tile);
}

void Character::MoveDown()
{
	sf::Vector2i tile = GetTile();
	tile.y += moveDistance;
	SetPositionToTile(tile);
}

bool Character::CanMoveToTile(const GameInfo& info, const sf::Vector2i& tile)
{
	Tile t = (Tile)info.level[tile.y][tile.x];
	switch (t)
	{
		case Tile::EMPTY:
		case Tile::PICKUP:
		case Tile::PICKUP_BIG:
			return true;
		default:
			return false;
	}
}

bool Character::IsInIntersection()
{
	return false;
}

void Character::Update(const GameInfo& info)
{
}
