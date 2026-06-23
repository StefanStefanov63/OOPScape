#include "IEntity.h"

void IEntity::setPosition(const Position& currentPosition)
{
    this->currentPosition = currentPosition;
}

const Position& IEntity::getPosition() const
{
    return currentPosition;
}


IEntity::IEntity(const Position& currentPosition): currentPosition(currentPosition)
{
}
