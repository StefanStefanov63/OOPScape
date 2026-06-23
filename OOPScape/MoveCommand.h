#pragma once
#include "ICommand.h"
#include "IEntity.h"
#include "Direction.h"
#include "Level.h"
class MoveCommand : public ICommand
{
    IEntity& entity;
    Direction direction;
    const Level& level;

public:
    MoveCommand(IEntity& anEntity, const Direction& aDirection, const Level& aLevel);
    void execute() override;
    
};

