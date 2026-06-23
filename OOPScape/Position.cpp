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

void Position::setX(unsigned int aX)
{
    this->x = aX;
}

void Position::setY(unsigned int aY)
{
    this->y = aY;
}

Position& Position::operator+=(const Position& pos)
{
    this->x += pos.getX();
    this->y += pos.getY();

    return *this;
}

bool Position::operator==(const Position& pos) const
{
    return (x == pos.getX()) && (y == pos.getY());
}
