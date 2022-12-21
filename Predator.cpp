#include "Predator.h"

Predator::Predator(Coordinate aCoord, Ocean* ocean) : Prey(aCoord, ocean)
{
	timeToFeed = TimeToFeed;
	image = DefaultPredImage;
}

void Predator::process(void)
{
	Coordinate toCoord;
	if (--timeToFeed <= 0)
	{
		assignCellAt(_offset, new Cell(_offset, _owner));
		_owner->setNumPredators(_owner->getNumPredators() - 1);
	}
	else
	{
		toCoord = getPreyNeighborCoord();
		if (toCoord != _offset)
		{
			_owner->setNumPrey(_owner->getNumPrey() - 1);
			timeToFeed = TimeToFeed;
			moveFrom(_offset, toCoord);
		}
		else
			Prey::process();//Метод перемещения из травоядных
	}
}

Cell* Predator::reproduce(Coordinate anOffset, Ocean* ocean)
{
	Predator* temp = new Predator(anOffset, ocean);
	_owner->setNumPredators(_owner->getNumPredators() + 1); 
	return (Cell*)temp;
}
