#pragma once

#include "ICommand.h"
#include "Game.h"

class AbilityCommand : public ICommand
{
    Game& game;
public:
    AbilityCommand(Game& game);
    bool execute() override;
};

