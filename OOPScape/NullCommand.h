#pragma once
#include "ICommand.h"
#include "Color.h"
#include <iostream>
class NullCommand : public ICommand
{
public:
    bool execute() override;
};

