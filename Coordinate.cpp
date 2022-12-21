#include "Coordinate.h"

Coordinate::Coordinate(unsigned aX, unsigned aY) : x(aX), y(aY) {}

Coordinate::Coordinate(void) { x = 0; y = 0; }

Coordinate::Coordinate(Coordinate& aCoord) : x(aCoord.x), y(aCoord.y) {}

unsigned Coordinate::getX(void)
{
	return x;
}

unsigned Coordinate::getY(void)
{
	return y;
}

void Coordinate::setX(unsigned aX)
{
	x = aX;
}

void Coordinate::setY(unsigned aY)
{
	y = aY;
}

void Coordinate::operator = (const Coordinate& aCoord)
{
	x = aCoord.x;
	y = aCoord.y;
}

int Coordinate::operator == (Coordinate& c)
{
	return (x == c.x && y == c.y);
}

int Coordinate::operator != (Coordinate& c)
{
	return (x != c.x || y != c.y);
}