#ifndef CellDefined
#define CellDefined
#include "Ocean.h"

class Cell
{
protected:
	Ocean* _owner;
	Coordinate _offset;
	char image;

	Cell* getCellAt(Coordinate aCoord);
	void assignCellAt(Coordinate aCoord, Cell* aCell);
	Cell* getNeighborWithImage(char im);
	Coordinate getEmptyNeighborCoord(void);
	Coordinate getPreyNeighborCoord(void);
	Cell* north(void);
	Cell* south(void);
	Cell* east(void);
	Cell* west(void);

	virtual Cell* reproduce(Coordinate anOffset, Ocean* ocean);

public:
	Cell(Coordinate& aCoord, Ocean* ocean);
	Cell(void) {};
	virtual ~Cell(void) {};

	Coordinate& getOffset(void);
	void setOffset(Coordinate& anOffset);
	char getImage(void);
	void display(void);
	virtual void process(void) {}
};

#endif
