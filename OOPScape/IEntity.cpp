#include "IEntity.h"

void IEntity::setPosition(const Position& currentPosition)
{
    this->currentPosition = currentPosition;
}

const Position& IEntity::getPosition() const
{
    return currentPosition;
}

bool IEntity::move(const Level& level, Direction direction)
{
    Position next = currentPosition;

    switch (direction)
    { 
    case Direction::Up: { next += Position(-1, 0); break; };
    case Direction::Right: { next += Position(0, 1); break; };
    case Direction::Down: { next += Position(1, 0); break; }
    case Direction::Left: { next += Position(0, -1); break; }
    
    }

    if (level.isWalable(next))
    {
        currentPosition = next;
        return true;
    }

    return false;
}

IEntity::IEntity(const Position& currentPosition): currentPosition(currentPosition)
{
}
