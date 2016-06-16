#include "Character.hpp"
#include "../Settings.hpp"

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

bool Character::IsInIntersection()
{
	return false;
}

void Character::Update()
{
}
