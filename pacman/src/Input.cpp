#include "Input.hpp"

Input::Input()
{
	for (auto& keyState : keyState)
	{
		keyState.triggerEvent = KeyEvent::NOTHING;
		keyState.usedInCurrentFrame = false;
	}
}

bool Input::OnKeyDown(sf::Keyboard::Key key) const
{
	return keyState[(int)key].triggerEvent == KeyEvent::DOWN;
}

bool Input::OnKeyUp(sf::Keyboard::Key key) const
{
	return keyState[(int)key].triggerEvent == KeyEvent::RELEASE;
}

bool Input::OnKey(sf::Keyboard::Key key) const
{
	return keyState[key].triggerEvent == KeyEvent::HOLD || keyState[key].triggerEvent == KeyEvent::DOWN;
}

void Input::StepKeyboardState()
{
	for (auto& keyState : keyState)
	{
		if (keyState.usedInCurrentFrame)
		{
			keyState.usedInCurrentFrame = false;

			if (keyState.triggerEvent == KeyEvent::DOWN)
			{
				keyState.triggerEvent = KeyEvent::HOLD;
			}
			else if (keyState.triggerEvent == KeyEvent::RELEASE)
			{
				keyState.triggerEvent = KeyEvent::NOTHING;
			}
		}
	}
}

void Input::KeyPressedEvent(sf::Keyboard::Key key)
{
	if (!keyState[key].usedInCurrentFrame && keyState[key].triggerEvent != KeyEvent::HOLD)
	{
		keyState[key].triggerEvent = KeyEvent::DOWN;
	}
	else
	{
		keyState[key].triggerEvent = KeyEvent::HOLD;
	}
	keyState[key].usedInCurrentFrame = true;
}

void Input::KeyReleasedEvent(sf::Keyboard::Key key)
{
	keyState[key].triggerEvent = KeyEvent::RELEASE;
	keyState[key].usedInCurrentFrame = true;
}