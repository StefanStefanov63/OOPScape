#pragma once
#include <vector>
#include "Node.h"
#include "NodeFactory.h"
#include <string>
class Level
{
	std::vector<std::vector<Node>> map;
	unsigned int size;

	Position heroStarting;
	std::vector<Position> enemyStarting;
	Position exit;

public:

	Level() = delete;
	Level(std::ifstream& ifs);
	friend std::ostream& operator<<(std::ostream& os, const Level& level);
	bool isWalable(const Position& pos) const;
	const Position& getHeroStarting() const;
	const Position& getExit() const;
	unsigned int getSize() const;
	const std::vector<std::vector<Node>>& getMap() const;
	const std::vector<Position>& getEnemyStarting() const;
};

