#pragma once

#include <SFML/Window/Keyboard.hpp>

class Input
{
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

	public:
		Input();
		~Input();

		bool OnKey(sf::Keyboard::Key key ) const;
		bool OnKeyDown(sf::Keyboard::Key key ) const;
		bool OnKeyUp(sf::Keyboard::Key key ) const;

		void KeyPressedEvent(sf::Keyboard::Key key);
		void KeyReleasedEvent(sf::Keyboard::Key key);
		void StepKeyboardState();
	private:
		KeyState keyState[sf::Keyboard::KeyCount];
};
