#include "Position.h"

Position::Position(unsigned int aX, unsigned int aY):x(aX), y(aY)
{
}

unsigned int Position::getX() const
{
    return this->x;
}

unsigned int Position::getY() const
{
    return this->y;
}
