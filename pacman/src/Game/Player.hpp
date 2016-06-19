#pragma once

#include "Character.hpp"

class Player : public Character
{
	protected:
		void PlayerInput(GameInfo& info);
		virtual void Update(GameInfo& info) override;

};