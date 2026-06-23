#pragma once
#include "MoveCommand.h"
#include "NullCommand.h"
class Game;

class CommandFactory
{
public:

    static std::unique_ptr<ICommand> create(const std::string& input, Game& game);
    
};

