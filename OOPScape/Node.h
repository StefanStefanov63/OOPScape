#pragma once
#include "Position.h"
#include "Color.h"
#include <iostream>
#include <fstream>
class Node
{
	Position pos;
	char symbol;
	Color color;
	bool walkable;

public:

	Node() = delete;

	Node(unsigned int x, unsigned int y, char symbol, const Color& color, bool walkable);

    const Position& getPos() const;
    char getSymbol() const;
	const Color& getColor() const;
	bool isWalkable() const;

	friend std::ostream& operator<<(std::ostream& os, const Node& node);
};

WORD toConsoleColor(Color color);