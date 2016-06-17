#include "Character.hpp"
#include "../Settings.hpp"
#include "Structs.hpp"
#include <cassert>

Character::Character()
{
	positionOffset.x = TILE_WIDTH / 2;
	positionOffset.y = TILE_HEIGHT / 2;
}

void Character::Move(const GameInfo &info, const sf::Vector2i &direction)
{
	assert(abs(direction.x) + abs(direction.y) <= 1);
	sf::Vector2i tile = GetTile();
	tile += direction;
	if (CanMoveToTile(info, tile))
	{
		SetPositionToTile(tile);
	}
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
	int a;
	return CanMoveToTile(info, tile, a);
}

bool Character::CanMoveToTile(const GameInfo& info, const sf::Vector2i& tile, int& outTile)
{
	outTile = info.level[tile.y][tile.x];
	Tile t = (Tile)outTile;

	switch (t)
	{
		case Tile::EMPTY:
		case Tile::PICKUP:
		case Tile::PICKUP_BIG:
			return true;
		default:
			printf("cant move to tile %i\n", t);
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
