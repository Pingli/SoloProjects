#pragma once

#include "Character.hpp"

class Player : public Character
{
	protected:
		virtual void Update(const GameInfo& info) override;

};