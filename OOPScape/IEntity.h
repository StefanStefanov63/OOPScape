#pragma once
#include "Position.h"
#include "Level.h"
#include "Direction.h"
#include <memory>
#include <iostream>
class IEntity
{
protected:
	Position currentPosition;
public:
	void setPosition(const Position& currentPosition);
	const Position& getPosition() const;

	IEntity(const Position& currentPosition);

	virtual ~IEntity() = default;
};

