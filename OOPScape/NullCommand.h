#pragma once
#include "ICommand.h"
#include "Color.h"
#include <iostream>
class NullCommand : public ICommand
{
public:
    void execute() override;
};

