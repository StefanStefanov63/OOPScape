#pragma once
#include "IEntity.h"
#include "Regression.h"

class Hero : public IEntity
{
protected:
	std::unique_ptr<Ability> ability;

public:

	Hero(const Position& currentPosition, std::unique_ptr<Ability> ability);

};

