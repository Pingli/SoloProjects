#pragma once

#include "../Entity2D.hpp"

enum class Direction
{
	Up,
	Left,
	Right,
	Down,
	None
};

class Character : public Entity2D
{
	public:
		Character();
		virtual void Update(GameInfo& info) override;
		void MoveToDirection(GameInfo & info, const sf::Vector2i &direction);
	protected:
		static bool CanMoveToTile(const GameInfo& info, const sf::Vector2i& tile);
		static bool CanMoveToTile(const GameInfo& info, const sf::Vector2i& tile, int& outTile);
		bool CanMoveToTile(const GameInfo& info, const Direction& direction, int& outTile) const;
		bool CanMoveToTile(const GameInfo& info, const Direction& direction) const;
		static sf::Vector2i DirectionEnumToVector2i(const Direction& direction);
		bool IsInIntersection(const GameInfo& info) const;
		int moveDistance = 1;
};
