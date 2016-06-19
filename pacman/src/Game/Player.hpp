#pragma once

#include "Character.hpp"

class Player : public Character
{
	public:
		virtual void Update(GameInfo& info) override;
	protected:
		void PlayerInput(GameInfo& info);

};