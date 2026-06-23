#pragma once
#include "Enemy.h"
class EnemyFactory
{
public:
	static std::vector<std::unique_ptr<Enemy>> createAll(const Level& level);
	static std::unique_ptr <Enemy> create(const Position& currentPosition, char type);
};

