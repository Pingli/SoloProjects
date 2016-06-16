#include "Player.hpp"
#include "../Input.hpp"

void Player::Update(const GameInfo& info)
{
	if (Input::GetInstance().OnKeyDown(sf::Keyboard::A))
	{
		MoveLeft();
	}
	else if (Input::GetInstance().OnKeyDown(sf::Keyboard::D))
	{
		MoveRight();
	}
	else if (Input::GetInstance().OnKeyDown(sf::Keyboard::S))
	{
		MoveDown();
	}
	else if (Input::GetInstance().OnKeyDown(sf::Keyboard::W))
	{
		MoveUp();
	}
}
