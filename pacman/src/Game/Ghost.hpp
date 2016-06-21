#pragma once

#include "Character.hpp"

class Ghost : public Character
{
	public:
		virtual void Update(GameInfo& info) override;
};