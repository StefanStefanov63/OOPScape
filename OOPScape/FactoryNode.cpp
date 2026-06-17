#include "FactoryNode.h"
#include <stdexcept>

Node FactoryNode::createNode(unsigned int aX, unsigned int aY, char aSymbol)
{
    switch (aSymbol) 
    {
    case ' ':
        return Node(aX, aY, aSymbol, Color::None, true);
    case '*':
        return Node(aX, aY, aSymbol, Color::None, false);
    case 'S':
        return Node(aX, aY, aSymbol, Color::Green, true);
    case 'E':
        return Node(aX, aY, aSymbol, Color::Red, true);
    case 'F':
        return Node(aX, aY, aSymbol, Color::White, true);
    }

    throw std::runtime_error("Unknown Node Symbol");
}
