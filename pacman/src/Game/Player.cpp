#include "Player.hpp"
#include "../Input.hpp"

void Player::Update(const GameInfo& info)
{
	if (Input::GetInstance().OnKeyDown(sf::Keyboard::A))
	{
		Move(info, Left);
	}
	else if (Input::GetInstance().OnKeyDown(sf::Keyboard::D))
	{
		Move(info, Right);
	}
	else if (Input::GetInstance().OnKeyDown(sf::Keyboard::S))
	{
		Move(info, Down);
	}
	else if (Input::GetInstance().OnKeyDown(sf::Keyboard::W))
	{
		Move(info, Up);
	}
}
