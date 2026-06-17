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

std::ostream& operator<<(std::ostream& os, const Dungeon& dungeon)
{
	for (auto it = dungeon.levels.begin();it != dungeon.levels.end(); ++it)
	{
		os << "Floor: " << 1 <<'\n'<< (*it);
	}

	return os;
}
