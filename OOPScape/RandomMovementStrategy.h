#pragma once
#include "EnemyMovementStrategy.h"
class RandomMovementStrategy : public EnemyMovementStrategy
{
public:
	bool move(Position& enemyPos, const Position& heroPos, const Level& level) override;
};

