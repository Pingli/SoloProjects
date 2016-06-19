#pragma once

#include "../Entity2D.hpp"

#define Up sf::Vector2i(0,-1)
#define Down sf::Vector2i(0,1)
#define Left sf::Vector2i(-1,0)
#define Right sf::Vector2i(1,0)


class Character : public Entity2D
{
	public:
		Character();
		virtual void Update(GameInfo& info) override;
		void MoveDirection(GameInfo & info, const sf::Vector2i &direction);
	protected:
		static bool CanMoveToTile(const GameInfo& info, const sf::Vector2i& tile);
		static bool CanMoveToTile(const GameInfo& info, const sf::Vector2i& tile, int& outTile);
		bool IsInIntersection();
		void MovedOnPickup(const sf::Vector2i& tile);
		int moveDistance = 1;
};
