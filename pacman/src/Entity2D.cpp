#include "Entity2D.hpp"
#include <SFML/Graphics/Texture.hpp>
#include "AssetCache.hpp"
#include "Settings.hpp"
#include <cassert>

std::vector<sf::Sprite*> Entity2D::sprites;
std::vector<Entity2D*> Entity2D::entities;

Entity2D::Entity2D() : name(""), positionOffset(0.f, 0.f)
{
	Init();
}

void Entity2D::Init()
{
	sprites.push_back(&sprite);
	entities.push_back(this);
}

sf::Vector2f Entity2D::TileToPosition(const sf::Vector2i& tile)
{
	return sf::Vector2f(tile.x * TILE_WIDTH, tile.y * TILE_HEIGHT);
}

sf::Vector2i Entity2D::PositionToTile(const sf::Vector2f& position)
{
	return sf::Vector2i(position.x / TILE_WIDTH, position.y / TILE_HEIGHT);
}

void Entity2D::DrawSprites(sf::RenderWindow& window)
{
	for (auto it = sprites.begin(); it != sprites.end(); ++it)
	{
		sf::Sprite& sprite = **it;
		window.draw( sprite );
	}
}

void Entity2D::UpdateEntities()
{
	for (auto it = entities.begin(); it != entities.end(); ++it)
	{
		Entity2D& entity = **it;
		entity.Update();
	}
}

void Entity2D::Update()
{
}

Entity2D::~Entity2D()
{
	for (auto it = sprites.begin(); it != sprites.end(); ++it)
	{
		if (*it == &sprite)
		{
			sprites.erase(it);
			break;
		}
	}
	for (auto it = entities.begin(); it != entities.end(); ++it)
	{
		if (*it == this)
		{
			entities.erase(it);
			break;
		}
	}
}

sf::Vector2i Entity2D::GetTile() const
{
	sf::IntRect rect = sprite.getTextureRect();
	sf::Vector2f pos = sprite.getPosition();

	pos.x = pos.x + (rect.width / 2);
	pos.y = pos.y + (rect.height / 2);
	return PositionToTile(pos);;
}

void Entity2D::SetTextureFromSpritesheet(const std::string& filePath, const int tileNumber, const sf::Vector2i& dimension)
{
	SetTextureFromFile(filePath);

	sf::Vector2u size = sprite.getTexture()->getSize();
	int numberOfColumns = size.x / TILE_WIDTH;
	int numberOfRows = size.y / TILE_HEIGHT;

	int column = tileNumber % numberOfColumns;
	int row = (tileNumber ) / numberOfColumns;

	assert(row < numberOfRows);
	assert(column < numberOfColumns);

	sf::IntRect rect;
	rect.left = column * TILE_WIDTH;
	rect.top = row * TILE_HEIGHT;
	rect.width = dimension.x;
	rect.height = dimension.y;
	sprite.setTextureRect(rect);
}

void Entity2D::SetTextureFromFile(const std::string& filePath)
{
	sf::Texture& texture = AssetCache::GetInstance().AddNewCacheEntry(filePath);
	//TODO make nice
	if (texture.getSize().x == 0)
	{
		texture.loadFromFile(filePath);
		printf("loading new \n");
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