#pragma once
#include "IEntity.h"
#include <queue>
#include "Node.h"
#include "BFSMovementStrategy.h"
#include "RandomMovementStrategy.h"
class Enemy : public IEntity
{
protected:
	std::unique_ptr<EnemyMovementStrategy> strategy;
	unsigned int stunTurns;

public:
	unsigned int getStunTurns()const;
	void setStunTurns(unsigned int n);
	bool move(const Position& herePosition, const Level& level);
	Enemy(const Position& currentPosition, std::unique_ptr<EnemyMovementStrategy> strategy);
	EnemyMovementStrategy& getStrategy();
};

