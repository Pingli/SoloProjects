#include "Character.hpp"
#include "../Settings.hpp"
#include "Structs.hpp"
#include <cassert>

Character::Character()
{
	positionOffset.x = TILE_WIDTH / 2;
	positionOffset.y = TILE_HEIGHT / 2;
}

void Character::MoveDirection(GameInfo & info, const sf::Vector2i &direction)
{
	assert(abs(direction.x) + abs(direction.y) <= 1);
	sf::Vector2i tile = GetCurrentTilePosition();
	tile += direction;
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

bool Character::CanMoveToTile(const GameInfo& info, const Direction& direction, int& outTile)
{
	sf::Vector2i dir = DirectionEnumToVector2i(direction);
	return CanMoveToTile(info, GetCurrentTilePosition() + dir, outTile);
}

bool Character::IsInIntersection()
{
	return false;
}

void Character::Update(GameInfo& info)
{
}

sf::Vector2i Character::DirectionEnumToVector2i(const Direction& direction)
{
	switch (direction)
	{
		case Direction::dUp:
			return sf::Vector2i(0, -1);
		case Direction::dLeft:
			return sf::Vector2i(-1, 0);
		case Direction::dRight:
			return sf::Vector2i(1, 0);
		case Direction::dDown:
			return sf::Vector2i(0, 1);
		case Direction::None:
		default:
			return sf::Vector2i(0, 0);
	}
}