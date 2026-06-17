#pragma once
#include "Node.h"
class FactoryNode
{
public:
	static Node createNode(unsigned int aX, unsigned int aY, char aSymbol);
};

