#include "Prey.h"

void Prey::moveFrom(Coordinate from, Coordinate to)
{
	Cell* toCell;
	--timeToReproduce;
	if (to != from)
	{
		toCell = getCellAt(to);
		delete toCell;
		setOffset(to);
		assignCellAt(to, this);
		if (timeToReproduce <= 0)
		{
			timeToReproduce = TimeToReproduce;
			assignCellAt(from, reproduce(from));
		}
		else assignCellAt(from, new Cell(from, _owner));
	}
}

Cell* Prey::reproduce(Coordinate anOffset)
{
	Prey* temp = new Prey(anOffset, _owner);
	_owner->setNumPrey(_owner->getNumPrey() + 1);
	return (Cell*)temp;
}

Prey::Prey(Coordinate& aCoord, Ocean* ocean) : Cell(aCoord, ocean)
{
	timeToReproduce = TimeToReproduce;
	image = DefaultPreyImage;
}

void Prey::process(void)
{
	Coordinate toCoord;
	toCoord = getEmptyNeighborCoord();
	moveFrom(_offset, toCoord);
}
