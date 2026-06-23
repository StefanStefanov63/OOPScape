#pragma once
#include "EnemyMovementStrategy.h"
#include <queue>
class BFSMovementStrategy : public EnemyMovementStrategy
{
public:
    bool move(Position& enemyPos, const Position& heroPos, const Level& level) override;
};

