#include "NodeFactory.h"
#include <stdexcept>

Node NodeFactory::createNode(char aSymbol)
{
    switch (aSymbol) 
    {
    case ' ':
        return Node(aSymbol, Color::None, true);
    case '*':
        return Node( aSymbol, Color::None, false);
    case 'S':
        return Node(aSymbol, Color::Green, true);
    case 'E':
        return Node(aSymbol, Color::Red, true);
    case 'F':
        return Node(aSymbol, Color::White, true);
    case 'H':
        return Node(aSymbol, Color::Yellow, true);
    }

    throw std::runtime_error("Unknown Node Symbol");
}
