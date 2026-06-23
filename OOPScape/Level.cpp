#include "Level.h"

Level::Level(std::ifstream& ifs) 
	: heroStarting(Position(0,0)), exit(Position(0,0))
{
	bool hasStart = false , hasEnd = false;
	unsigned int n;
	ifs >> n;
	size = n;
	ifs.ignore();
	if (n<2 || n > 64)
		throw std::runtime_error("invalid level size");

	for (unsigned int row = 0; row < n; row++)
	{
		std::string line;
		std::getline(ifs, line);
		std::vector<Node> nodeLine;
		nodeLine.reserve(size);

		for (unsigned int col = 0; col < n; col++)
		{
			char cSym =  line[col];

			switch (cSym)
			{
			case 'R':
			case 'E':
			{
				enemyStarting.push_back(Position(row, col));
				break;
			}
			case 'S':
			{
				if (hasStart)
					throw std::runtime_error("Multiple start positions");

				heroStarting = Position(row, col);
				hasStart = true;

				break;
			}
			case 'F':
			{
				if (hasEnd)
					throw std::runtime_error("Multiple end positions");

				exit = Position(row, col);
				hasEnd = true;

				break;
			}
			}

			nodeLine.push_back(NodeFactory::createNode(cSym));
		}
		map.push_back(nodeLine);
	}

	if (!hasStart)
		throw std::runtime_error("Missing start position");

	if (!hasEnd)
		throw std::runtime_error("Missing end position");
}

bool Level::isWalable(const Position& pos) const
{
	if (pos.getX() < 0 || pos.getX() >= this->size)
		return false;

	if (pos.getY() < 0 || pos.getY() >= this->size)
		return false;

	return map[pos.getX()][pos.getY()].isWalkable();
}

const Position& Level::getHeroStarting() const
{
	return heroStarting;
}

const Position& Level::getExit() const
{
	return exit;
}

unsigned int Level::getSize() const
{
	return size;
}

const std::vector<std::vector<Node>>& Level::getMap() const
{
	return map;
}

const std::vector<Position>& Level::getEnemyStarting() const
{
	return enemyStarting;
}

std::ostream& operator<<(std::ostream& os, const Level& level)
{
	setConsolColor(Color::Blue);
	os << std::string(level.getSize() * 3 + 2, '-');
	os << '\n';
	setConsolColor(Color::None);

	for (unsigned int row = 0; row < level.size; row++)
	{
		setConsolColor(Color::Blue);
		os << ' ' << row << " |";
		setConsolColor(Color::None);


		for (unsigned int col = 0; col < level.size; col++)
		{
			os << level.map[row][col];
		}
		setConsolColor(Color::Blue);
		os << "|\n";
		setConsolColor(Color::None);
	}

	setConsolColor(Color::Blue);
	os << std::string(level.getSize() * 3 + 2, '-');
	os << '\n';
	setConsolColor(Color::None);

	return os;
}
