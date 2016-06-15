#pragma once

#include "../Entity2D.hpp"

class Character : public Entity2D
{
	public:
	protected:
		void MoveLeft();
		void MoveRight();
		void MoveUp();
		void MoveDown();
		bool IsInIntersection();
		virtual void Update() override;
};
