#include "Player.hpp"

void Player::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		MoveLeft();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		MoveRight();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		MoveDown();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		MoveUp();
	}
}
