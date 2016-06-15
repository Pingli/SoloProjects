#include "Character.hpp"

void Character::MoveLeft()
{
	sf::Vector2f tile = GetTile();
	tile.x -= 1;
	SetPosition(tile);
}

void Character::MoveRight()
{
	sf::Vector2f tile = GetTile();
	tile.x += 1;
	SetPosition(tile);
}

void Character::MoveUp()
{
	sf::Vector2f tile = GetTile();
	tile.y -= 1;
	SetPosition(tile);
}

void Character::MoveDown()
{
	sf::Vector2f tile = GetTile();
	tile.y += 1;
	SetPosition(tile);
}

bool Character::IsInIntersection()
{
	return false;
}

void Character::Update()
{
}
