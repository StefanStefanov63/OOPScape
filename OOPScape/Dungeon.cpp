#include "Dungeon.h"

Dungeon::Dungeon( std::ifstream& ifs)
{
	 unsigned int num;
	 ifs >> num;
	 floors = num;

	 for (unsigned int i = 0; i < num; i++)
	 {
		 levels.push_back(ifs);
	 }
	
}

const std::vector<Level>& Dungeon::getLevels() const
{
	return levels;
}

std::ostream& operator<<(std::ostream& os, const Dungeon& dungeon)
{
	for (unsigned int i =0;i < dungeon.floors; ++i)
	{
		os << "Floor: " << i+1 <<'\n'<< dungeon.levels[i];
	}

	return os;
}
