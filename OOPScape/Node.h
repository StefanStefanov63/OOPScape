#pragma once
#include "Position.h"
#include "Color.h"
#include <iostream>
#include <fstream>
class Node
{
	char symbol;
	Color color;
	bool walkable;

public:

	Node() = delete;

	Node(char symbol, const Color& color, bool walkable);

    char getSymbol() const;
	const Color& getColor() const;
	bool isWalkable() const;

	friend std::ostream& operator<<(std::ostream& os, const Node& node);
};
