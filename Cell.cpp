#include "Cell.h"
#include <iostream>

Cell* Cell::getCellAt(Coordinate aCoord)
{
	return _owner->getCells(aCoord.getY(), aCoord.getX());
}

void Cell::assignCellAt(Coordinate aCoord, Cell* aCell)
{
	_owner->setCells(aCoord.getY(), aCoord.getX(), aCell);
}
Cell* Cell::getNeighborWithImage(char im)
{
	Cell* neighbors[4];
	unsigned count = 0;

	if (north()->getImage() == im) neighbors[count++] = north();
	if (south()->getImage() == im) neighbors[count++] = south();
	if (east()->getImage() == im) neighbors[count++] = east();
	if (west()->getImage() == im) neighbors[count++] = west();

	if (count == 0) return this;
	else return neighbors[_owner->getRandom().RanMax(count - 1)];
}

Coordinate Cell::getEmptyNeighborCoord(void)
{
	return getNeighborWithImage(DefaultImage)->getOffset();
}

Coordinate Cell::getPreyNeighborCoord(void)
{
	return getNeighborWithImage(DefaultPreyImage)->getOffset();
}

Cell* Cell::north(void)
{
	unsigned yvalue;
	yvalue = (_offset.getY() > 0) ? (_offset.getY() - 1) : (_owner->getRows() - 1);
	return _owner->getCells(yvalue, _offset.getX());
}

Cell* Cell::south(void)
{
	unsigned yvalue;
	yvalue = (_offset.getY() + 1) % _owner->getRows();
	return _owner->getCells(yvalue, _offset.getX());
}

Cell* Cell::west(void)
{
	unsigned xvalue;
	xvalue = (_offset.getX() > 0) ? (_offset.getX() - 1) : (_owner->getCols() - 1);
	return _owner->getCells(_offset.getY(), xvalue);
}

Cell* Cell::east(void)
{
	unsigned xvalue;
	xvalue = (_offset.getX() + 1) % _owner->getCols();
	return _owner->getCells(_offset.getY(), xvalue);
}

Cell* Cell::reproduce(Coordinate anOffset, Ocean* ocean)
{
	Cell* temp = new Cell(anOffset, ocean);
	return temp;
}

Cell::Cell(Coordinate& aCoord, Ocean* ocean) : _offset(aCoord), _owner(ocean)
{
	image = DefaultImage;
}

Coordinate& Cell::getOffset(void)
{
	return _offset;
}

void Cell::setOffset(Coordinate& anOffset)
{
	_offset = anOffset;
}

char Cell::getImage(void)
{
	return image;
}

void Cell::display(void)
{
	std::cout << image;
}

