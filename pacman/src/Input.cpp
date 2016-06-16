#include "Input.hpp"

Input::Input()
{
	for (int i = 0; i < sf::Keyboard::KeyCount; ++i)
	{
		keyState[i].triggerEvent = KeyEvent::NOTHING;
		keyState[i].usedInCurrentFrame = false;
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
	for (int i = 0; i < sf::Keyboard::KeyCount; ++i)
	{
		if (keyState[i].usedInCurrentFrame)
		{
			keyState[i].usedInCurrentFrame = false;

			if (keyState[i].triggerEvent == KeyEvent::DOWN)
			{
				keyState[i].triggerEvent = KeyEvent::HOLD;
			}
			else if (keyState[i].triggerEvent == KeyEvent::RELEASE)
			{
				keyState[i].triggerEvent = KeyEvent::NOTHING;
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