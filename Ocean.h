#ifndef OceanDefined
#define OceanDefined

#include "Random.h"
#include "Constants.h"
#include "Coordinate.h"
class Cell;

class Ocean
{
private:
	unsigned numRows;
	unsigned numCols;
	unsigned size;
	unsigned numPrey;
	unsigned numPredators;
	unsigned numObstacles;
	Random random;
	Cell* cells[MaxRows][MaxCols];
	void initCells(void);
	void addEmptyCells(Ocean* ocean);
	void addObstacles(Ocean* ocean);
	void addPredators(Ocean* ocean);
	void addPrey(Ocean* ocean);
	Coordinate getEmptyCellCoord(void);

	void displayBorder(void);
	void displayCells(void);
	void displayStats(int iteration);
public:
	unsigned getNumPrey(void);
	unsigned getNumPredators(void);
	void setNumPrey(unsigned aNumber);
	void setNumPredators(unsigned aNumber);

	Cell* getCells(unsigned x, unsigned y);
	void setCells(unsigned x, unsigned y, Cell* newPlace);
	unsigned getRows(void);
	unsigned getCols(void);
	Random getRandom(void);
	void initialize(void);
	void run(void);
};

#endif
