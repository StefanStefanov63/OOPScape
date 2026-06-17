#pragma once
#include <vector>
#include "Node.h"
#include "FactoryNode.h"
#include <string>
class Level
{
	std::vector<std::vector<Node>> map;
	unsigned int size;

	Position heroStarting;
	Position exit;

public:

	Level() = delete;
	Level(std::ifstream& ifs);
	friend std::ostream& operator<<(std::ostream& os, const Level& level);
};

