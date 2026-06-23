#include "Node.h"


Node::Node( char aSymbol, const Color& aColor, bool aWalkable)
	:symbol(aSymbol), color(aColor), walkable(aWalkable)
{
   
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



std::ostream& operator<<(std::ostream& os, const Node& node)
{
	os << ' '; 
	setConsolColor(node.getColor());

	std::cout << node.getSymbol();

	setConsolColor(Color::None);

	os << ' ';

	return os;
}
