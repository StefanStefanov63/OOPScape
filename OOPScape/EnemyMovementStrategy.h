#pragma once
#include "Position.h"
#include "Level.h"
class EnemyMovementStrategy
{
public:
    virtual bool move(Position& enemyPos, const Position& heroPos, const Level& level) = 0;
    bool canMove(int x, int y, const Level& level);
    virtual ~EnemyMovementStrategy() = default;
};

