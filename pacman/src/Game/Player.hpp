#pragma once

#include "Character.hpp"

class Player : public Character
{
	public:
		Player();
		virtual void Update(GameInfo& info) override;
	private:
		void PlayerInput(GameInfo& info);
		void MovePlayer(GameInfo& info);

		Direction currentFacingDirection;
		Direction lastDirectionInput;
};