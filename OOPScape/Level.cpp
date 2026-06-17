#include "Level.h"

Level::Level(std::ifstream& ifs) 
	: heroStarting(Position(0,0)), exit(Position(0,0))
{
	bool hasStart = false , hasEnd = false;
	unsigned int n;
	ifs >> n;
	size = n;

	for (unsigned int row = 0; row < n; row++)
	{
		std::vector<Node> line;
		line.reserve(size);
		ifs.ignore();
		for (unsigned int col = 0; col < n; col++)
		{

			char cSym;
			ifs.get(cSym);
			
			
			if (cSym == 'S')
			{
				if(hasStart)
					throw std::runtime_error("Multiple start positions");

				heroStarting = Position(row, col);
				hasStart = true;
			}

			if (cSym == 'F')
			{
				if (hasEnd)
					throw std::runtime_error("Multiple end positions");

				exit = Position(row, col);
				hasEnd = true;
			}

			line.push_back(FactoryNode::createNode(row, col, cSym));
		}
		map.push_back(line);
	}

	if (!hasStart)
		throw std::runtime_error("Missing start position");

	if (!hasEnd)
		throw std::runtime_error("Missing end position");
}

std::ostream& operator<<(std::ostream& os, const Level& level)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 9);
	os << std::string(4, ' ');
	for (unsigned int i = 0; i < level.size; i++)
	{
		os << ' ' << i << ' ';
	}
	os << '\n';

	os << std::string(4, ' ');
	os << std::string(level.size * 3 , '-');
	os << '\n';




	for (unsigned int row = 0; row < level.size; row++)
	{
		SetConsoleTextAttribute(hConsole, 9);
		os << ' ' << row << " |";
		SetConsoleTextAttribute(hConsole, 7);


		for (unsigned int col = 0; col < level.size; col++)
		{
			os << level.map[row][col];
		}
		os << '\n';
	}

	SetConsoleTextAttribute(hConsole, 9);

	os << std::string(4, ' ');
	os << std::string(level.size * 3, '-');
	os << '\n';

	os << std::string(4, ' ');
	for (unsigned int i = 0; i < level.size; i++)
	{
		os << ' ' << i << ' ';
	}
	SetConsoleTextAttribute(hConsole, 7);


	return os;
}
