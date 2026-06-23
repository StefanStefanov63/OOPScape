#include "Enemy.h"

unsigned int Enemy::getStunTurns() const
{
	return stunTurns;
}

void Enemy::setStunTurns(unsigned int n)
{
	stunTurns = n;
}

bool Enemy::move(const Position& herePosition, const Level& level)
{
	if (stunTurns > 0)
	{
		stunTurns--;
		return true;
	}
	return strategy->move(currentPosition, herePosition, level);
}

Enemy::Enemy(const Position& currentPosition, std::unique_ptr<EnemyMovementStrategy> strategy)
	: IEntity(currentPosition), strategy(std::move(strategy)), stunTurns(0)
{
}

EnemyMovementStrategy& Enemy::getStrategy()
{
	return *strategy;
}
