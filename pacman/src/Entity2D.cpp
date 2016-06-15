#include "Entity2D.hpp"
#include <SFML/Graphics/Texture.hpp>
#include "AssetCache.hpp"

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

void Entity2D::SetTextureFromFile(const std::string& filePath)
{
	sf::Texture& texture = AssetCache::GetInstance().AddNewCacheEntry(filePath);
	texture.loadFromFile(filePath);

	SetTexture(texture);
}

void Entity2D::SetTexture(const sf::Texture& texture)
{
	sprite.setTexture(texture);
}
