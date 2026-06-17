#include "Node.h"


Node::Node(unsigned int aX, unsigned int aY, char aSymbol, const Color& aColor, bool aWalkable)
	: pos(Position(aX, aY)) , symbol(aSymbol), color(aColor), walkable(aWalkable)
{
   
}

const Position& Node::getPos() const
{
	return pos;
}

char Node::getSymbol() const
{
	return symbol;
}

const Color& Node::getColor() const
{
	return color;
}

bool Node::isWalkable() const
{
	return walkable;
}


WORD toConsoleColor(Color color)
{
	switch (color)
	{
	case Color::Red:    return 12;
	case Color::Yellow: return 14;
	case Color::Green:  return 10;
	case Color::Blue:   return 9;
	case Color::White:  return 15;
	case Color::None:   return 7;
	}

	return 7;
}

std::ostream& operator<<(std::ostream& os, const Node& node)
{
	os << ' '; 

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, toConsoleColor(node.getColor()));
	std::cout << node.getSymbol();

	SetConsoleTextAttribute(hConsole, 7);

	os << ' ';

	return os;
}
