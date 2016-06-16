#pragma once

#include "../Entity2D.hpp"

class Character : public Entity2D
{
	public:
		Character();
	protected:
		void MoveLeft();
		void MoveRight();
		void MoveUp();
		void MoveDown();
		static bool CanMoveToTile(const GameInfo& info, const sf::Vector2i& tile);
		bool IsInIntersection();
		virtual void Update(const GameInfo& info) override;
	private:
		int moveDistance = 1;
};
