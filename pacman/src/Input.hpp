#pragma once

#include <SFML/Window/Keyboard.hpp>

class Input
{
public:
	static Input& GetInstance()
	{
		static Input* instance = new Input();
		return *instance;
	}

	bool OnKey(sf::Keyboard::Key key) const;
	bool OnKeyDown(sf::Keyboard::Key key) const;
	bool OnKeyUp(sf::Keyboard::Key key) const;

	void KeyPressedEvent(sf::Keyboard::Key key);
	void KeyReleasedEvent(sf::Keyboard::Key key);
	void StepKeyboardState();
private:
	enum class KeyEvent
	{
		NOTHING = 0,
		DOWN,
		HOLD,
		RELEASE
	};

	struct KeyState
	{
		KeyEvent triggerEvent;
		bool usedInCurrentFrame;
	};

private:
	Input();
	KeyState keyState[sf::Keyboard::KeyCount] {};
};
