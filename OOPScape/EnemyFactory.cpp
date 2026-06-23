#include "EnemyFactory.h"

std::vector<std::unique_ptr<Enemy>> EnemyFactory::createAll(const Level& level)
{

	std::vector<std::unique_ptr<Enemy>> enemies;

	for (auto c : level.getEnemyStarting())
	{
		enemies.push_back(create(c, level.getMap()[c.getX()][c.getY()].getSymbol()));
	}

	return enemies;
}

std::unique_ptr<Enemy> EnemyFactory::create(const Position& currentPosition, char type)
{
	switch (type)
	{
	case 'E':
	{
		return std::make_unique<Enemy>(currentPosition, std::make_unique<BFSMovementStrategy>());
	}
	case 'R':
	{
		return std::make_unique<Enemy>(currentPosition, std::make_unique<RandomMovementStrategy>());
	}
	default:
		return nullptr;
	}
}
