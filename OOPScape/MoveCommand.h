#pragma once
#include "ICommand.h"
#include "Hero.h"
#include "Direction.h"
#include "Level.h"
class MoveCommand : public ICommand
{
    Hero& hero;
    Direction direction;
    const Level& level;

public:
    MoveCommand(Hero& aHero, const Direction& aDirection, const Level& aLevel);
    bool execute() override;
    
};

