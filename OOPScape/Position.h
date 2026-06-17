#pragma once
class Position
{
	unsigned int x;
	unsigned int y;

public:
	Position() = default;
	Position(unsigned int aX, unsigned int aY);

	unsigned int getX() const;
	unsigned int getY() const;
};

