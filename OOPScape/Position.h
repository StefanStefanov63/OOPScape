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

	void setX(unsigned int aX);
	void setY(unsigned int aY);

	Position& operator +=(const Position& pos);
	bool operator ==(const Position& pos) const;
};

