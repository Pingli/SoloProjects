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
		void Move(const GameInfo &info, const sf::Vector2i &direction);
	protected:
		void MoveLeft();
		void MoveRight();
		void MoveUp();
		void MoveDown();
		static bool CanMoveToTile(const GameInfo& info, const sf::Vector2i& tile);
		static bool CanMoveToTile(const GameInfo& info, const sf::Vector2i& tile, int& outTile);
		bool IsInIntersection();
		virtual void Update(const GameInfo& info) override;

		int moveDistance = 1;
	private:
};
