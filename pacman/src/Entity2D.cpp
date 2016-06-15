#include "Entity2D.hpp"
#include <SFML/Graphics/Texture.hpp>
#include "AssetCache.hpp"
#include "Settings.hpp"
#include <cassert>

std::vector<sf::Sprite*> Entity2D::sprites;
std::vector<Entity2D*> Entity2D::entities;

Entity2D::Entity2D() : name("")
{
	Init();
}

void Entity2D::Init()
{
	sprites.push_back(&sprite);
	entities.push_back(this);
}

sf::Vector2f Entity2D::TileToPosition(const sf::Vector2f& tile)
{
	return sf::Vector2f(tile.x * TILE_WIDTH, tile.y * TILE_HEIGHT);
}

sf::Vector2f Entity2D::PositionToTile(const sf::Vector2f& position)
{
	return sf::Vector2f(floorf(position.x / TILE_WIDTH), floorf(position.y / TILE_HEIGHT));
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

sf::Vector2f Entity2D::GetTile() const
{
	sf::IntRect rect = sprite.getTextureRect();
	sf::Vector2f pos = sprite.getPosition();
	sf::Vector2f center;

	center.x = pos.x + (rect.width / 2);
	center.y = pos.y + (rect.height / 2);

	return PositionToTile(center);
}

//TODO add parameter for sprite size (characters are 2x2 tiles instead of 1x1)
void Entity2D::SetTextureFromSpritesheet(const std::string& filePath, const int tileNumber, const sf::Vector2i& dimension)
{
	SetTextureFromFile(filePath);

	sf::Vector2u size = sprite.getTexture()->getSize();
	int numberOfColumns = size.x / dimension.x;
	int numberOfRows = size.y / dimension.y;

	int column = tileNumber % numberOfColumns;
	int row = (tileNumber ) / numberOfColumns;

	assert(row < numberOfRows);
	assert(column < numberOfColumns);

	sf::IntRect rect;
	rect.left = column * TILE_WIDTH;
	rect.top = row * TILE_HEIGHT;
	rect.width = TILE_WIDTH;
	rect.height = TILE_HEIGHT;
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
	sprite.setPosition(x , y);
}

void Entity2D::SetPosition(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
}