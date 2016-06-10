#include "Entity2D.hpp"
#include <SFML/Graphics/Texture.hpp>
#include "AssetCache.hpp"

std::vector<sf::Sprite*> Entity2D::sprites;

Entity2D::Entity2D()
{
	Init();
}

Entity2D::Entity2D(const std::string filePath)
{
	Init();
	SetTextureFromFile(filePath);
}

Entity2D::Entity2D(const sf::Texture& texture)
{
	Init();
	SetTexture(texture);
}

void Entity2D::Init()
{
	sprites.push_back(&sprite);
}

void Entity2D::DrawSprites(sf::RenderWindow& window)
{
	for (std::vector<sf::Sprite*>::iterator it = sprites.begin(); it != sprites.end(); ++it)
	{
		sf::Sprite& sprite = *(sf::Sprite*)*it;
		window.draw( sprite );
	}
}

Entity2D::~Entity2D()
{
	for (std::vector<sf::Sprite*>::iterator it = sprites.begin(); it != sprites.end(); ++it)
	{
		if (*it == &sprite)
		{
			sprites.erase(it);
			printf("removed one\n");
			break;
		}
	}
}

void Entity2D::SetTextureFromFile(const std::string filePath)
{
	sf::Texture& texture = AssetCache::GetInstance().AddNewCacheEntry(filePath);
	texture.loadFromFile(filePath);

	SetTexture(texture);
}

void Entity2D::SetTexture(const sf::Texture& texture)
{
	sprite.setTexture(texture);
}
