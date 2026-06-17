#pragma once
#include "Level.h"
class Dungeon
{
	std::vector<Level> levels;
	unsigned int floors;
public:


	Dungeon ( std::ifstream& ifs);
	friend std::ostream& operator<<(std::ostream& os, const Dungeon& dungeon);
};

