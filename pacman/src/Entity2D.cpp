#include "Entity2D.hpp"
#include <SFML/Graphics/Texture.hpp>
#include "AssetCache.hpp"
#include "Settings.hpp"
#include <cassert>
#include "Game/Game.hpp"



Entity2D::Entity2D() : positionOffset(3.f, 3.f), name("")
{
}

sf::Vector2f Entity2D::TileToPosition(const sf::Vector2i& tile)
{
	sf::Vector2i tileCopy(tile);
	WrapTileX(tileCopy);

	return sf::Vector2f(tileCopy.x * TILE_WIDTH, tileCopy.y * TILE_HEIGHT);
}

sf::Vector2i Entity2D::PositionToTile(const sf::Vector2f& position)
{
	return sf::Vector2i(position.x / TILE_WIDTH, position.y / TILE_HEIGHT);
}

void Entity2D::Update(GameInfo& info)
{
}

Entity2D::~Entity2D()
{
}

sf::Vector2i Entity2D::GetCurrentTilePosition() const
{
	sf::IntRect rect = sprite.getTextureRect();
	sf::Vector2f pos = sprite.getPosition();

	pos.x = pos.x + (rect.width / 2);
	pos.y = pos.y + (rect.height / 2);
	return PositionToTile(pos);;
}

const sf::Sprite& Entity2D::GetSprite() const
{
	return sprite;
}

void Entity2D::SetTextureRectPosition(const int tileNumber, sf::IntRect& rect) const
{
	sf::Vector2u size = sprite.getTexture()->getSize();
	int numberOfColumns = size.x / TILE_WIDTH;
	int numberOfRows = size.y / TILE_HEIGHT;
	int column = tileNumber % numberOfColumns;
	int row = (tileNumber) / numberOfColumns;

	assert(row < numberOfRows);
	assert(column < numberOfColumns);

	rect = sprite.getTextureRect();
	rect.left = column * TILE_WIDTH;
	rect.top = row * TILE_HEIGHT;
}

void Entity2D::SetSpriteNumber(const int tileNumber)
{
	sf::IntRect rect;
	SetTextureRectPosition(tileNumber, rect);
	sprite.setTextureRect(rect);
}

void Entity2D::SetTextureFromSpritesheet(const std::string& filePath, const int tileNumber, const sf::Vector2i& dimension)
{
	SetTextureFromFile(filePath);
	sf::IntRect rect;

	SetTextureRectPosition(tileNumber, rect);
	rect.width = dimension.x;
	rect.height = dimension.y;
	sprite.setTextureRect(rect);
}

void Entity2D::SetTextureFromFile(const std::string& filePath)
{
	sf::Texture& texture = AssetCache::GetInstance().AddNewCacheEntry(filePath);
	if (texture.getSize().x == 0)
	{
		texture.loadFromFile(filePath);
		printf("loading new texture \n");
	}

	SetTexture(texture);
}

void Entity2D::SetTexture(const sf::Texture& texture)
{
	sprite.setTexture(texture);
}

void Entity2D::SetPosition(const float x, const float y)
{
	sprite.setPosition(sf::Vector2f(x , y));
}

void Entity2D::SetPosition(const sf::Vector2f& pos)
{
	sprite.setPosition(pos + positionOffset);
}

void Entity2D::SetPositionToTile(const sf::Vector2i& tile)
{
	sf::Vector2f pos = TileToPosition(tile);
	sf::IntRect rect = sprite.getTextureRect();

	pos.x = pos.x - (rect.width / 2);
	pos.y = pos.y - (rect.height / 2);

	SetPosition(pos);
}

void Entity2D::WrapTileX(sf::Vector2i& tile)
{
	if (tile.x < 0)
	{
		tile.x = LEVEL_WIDTH_COUNT - 1;
	}
	else if (tile.x > LEVEL_WIDTH_COUNT - 1)
	{
		tile.x = 0;
	}
}