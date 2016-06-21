#include "Character.hpp"
#include "../Settings.hpp"
#include "Structs.hpp"
#include <cassert>

Character::Character()
{
	positionOffset.x = TILE_WIDTH / 2;
	positionOffset.y = TILE_HEIGHT / 2;
}

void Character::MoveToDirection(GameInfo & info, const sf::Vector2i &direction)
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
			return false;
	}
}

bool Character::CanMoveToTile(const GameInfo& info, const Direction& direction, int& outTile) const
{
	sf::Vector2i dir = DirectionEnumToVector2i(direction);
	return CanMoveToTile(info, GetCurrentTilePosition() + dir, outTile);
}

bool Character::CanMoveToTile(const GameInfo& info, const Direction& direction) const
{
	int outTile;
	sf::Vector2i dir = DirectionEnumToVector2i(direction);
	return CanMoveToTile(info, GetCurrentTilePosition() + dir, outTile);
}

bool Character::IsInIntersection(const GameInfo& info) const
{
	//TODO be consistant, should set sizes of all primitive types
	//Since both forward and backward are counted too, it requires 3 options to consider it an intersection
	const short numberOfDirections = 3;

	//2 bytes vs 4 bits?
	unsigned short count = 0;
	count += CanMoveToTile(info, Direction::Down);
	count += CanMoveToTile(info, Direction::Left);
	count += CanMoveToTile(info, Direction::Up);
	count += CanMoveToTile(info, Direction::Right);
	if (count >= numberOfDirections)
	{
		return true;
	}
	return false;
}

void Character::Update(GameInfo& info)
{
}

sf::Vector2i Character::DirectionEnumToVector2i(const Direction& direction)
{
	switch (direction)
	{
		case Direction::Up:
			return sf::Vector2i(0, -1);
		case Direction::Left:
			return sf::Vector2i(-1, 0);
		case Direction::Right:
			return sf::Vector2i(1, 0);
		case Direction::Down:
			return sf::Vector2i(0, 1);
		case Direction::None:
		default:
			return sf::Vector2i(0, 0);
	}
}