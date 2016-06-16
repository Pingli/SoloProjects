#include "Character.hpp"

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

bool Character::IsInIntersection()
{
	return false;
}

void Character::Update()
{
}
