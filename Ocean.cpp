#include <iostream>
#include "Ocean.h"
#include "Obstacle.h"
#include "Predator.h"
#include "Prey.h"


Cell* Ocean::getCells(unsigned y, unsigned x)
{
	return cells[y][x];
}

void Ocean::setCells(unsigned y, unsigned x, Cell* newPlace)
{
	cells[y][x] = newPlace;
}


unsigned Ocean::getRows(void)
{
	return numRows;
}

unsigned Ocean::getCols(void)
{
	return numCols;
}

Random Ocean::getRandom(void)
{
	return random;
}

void Ocean::initialize(void)
{
	numRows = MaxRows;
	numCols = MaxCols;
	size = numRows * numCols;
	numObstacles = DefaultNumObstacles;
	numPredators = DefaultNumPredators;
	numPrey = DefaultNumPrey;

	initCells();
}


void Ocean::initCells(void)
{
	addEmptyCells(this);

	std::cout << "\nКоличество преград (по умолчанию 75):";
	std::cout.flush();
	std::cin >> numObstacles;
	if (numObstacles >= size) numObstacles = size;
	std::cout << "\nТекущее количество преград= " << numObstacles;
	std::cout.flush();

	std::cout << "\n\nКоличество хищников (по умолчанию 20): ";
	std::cout.flush();
	std::cin >> numPredators;
	if (numPredators >= (size - numObstacles)) numPredators = (size - numObstacles);
	std::cout << "\n Текущая популяция хищников= " << numPredators;
	std::cout.flush();

	std::cout << "\n\nКоличество травоядных (по умолчанию 150): ";
	std::cout.flush();
	std::cin >> numPrey;
	if (numPrey >= (size - numObstacles - numPredators)) numPrey = (size - numObstacles - numPredators);
	std::cout << "\nТекущая популяция травоядных= " << numPrey;

	addObstacles(this);
	std::cout << "\n\nПреграды возведены";
	addPredators(this);
	std::cout << "\nПопуляция хищников увеличена";
	addPrey(this);
	std::cout << "\nПопуляция травоядных увеличена ";
	displayStats(-1);
	displayCells();
	displayBorder();
}

void Ocean::addEmptyCells(Ocean* ocean)
{
	for (unsigned row = 0; row < numRows; row++)
		for (unsigned col = 0; col < numCols; col++)
		{
			Coordinate temp(col, row);
			cells[row][col] = new Cell(temp, ocean);
		}
}

void Ocean::addObstacles(Ocean* ocean)
{
	Coordinate empty;
	for (unsigned count = 0; count < numObstacles; count++)
	{
		empty = getEmptyCellCoord();
		cells[empty.getY()][empty.getX()] = new Obstacle(empty, ocean);
	}
}

void Ocean::addPredators(Ocean* ocean)
{
	Coordinate empty;
	for (unsigned count = 0; count < numPredators; count++)
	{
		empty = getEmptyCellCoord();
		cells[empty.getY()][empty.getX()] = new Predator(empty, ocean);
	}
}

void Ocean::addPrey(Ocean* ocean)
{
	Coordinate empty;
	for (unsigned count = 0; count < numPrey; count++)
	{
		empty = getEmptyCellCoord();
		cells[empty.getY()][empty.getX()] = new Prey(empty, ocean);
	}
}

Coordinate Ocean::getEmptyCellCoord(void)
{
	unsigned x, y;
	Coordinate empty;

	do
	{
		x = random.RanMax(numCols - 1);
		y = random.RanMax(numRows - 1);
	} while (cells[y][x]->getImage() != DefaultImage);
	empty = cells[y][x]->getOffset();
	return empty;
}

void Ocean::displayBorder(void)
{
	for (unsigned col = 0; col < numCols; col++) std::cout << "-";
	std::cout << "\n";
}

void Ocean::displayCells(void)
{
	for (unsigned row = 0; row < numRows; row++)
	{
		for (unsigned col = 0; col < numCols; col++) cells[row][col]->display();
		std::cout << "\n";
	}
}

void Ocean::displayStats(int iteration)
{
	std::cout << "\n\n";
	std::cout << "  Номер итеррации = " << ++iteration;
	std::cout << " Преград = " << numObstacles;
	std::cout << " Хищников = " << numPredators;
	std::cout << " Травоядных = " << numPrey;
	std::cout.flush() << std::endl;
	Ocean::displayBorder();
}

unsigned Ocean::getNumPrey(void)
{
	return numPrey;
}

unsigned Ocean::getNumPredators(void)
{
	return numPredators;
}

void Ocean::setNumPrey(unsigned aNumber)
{
	numPrey = aNumber;
}

void Ocean::setNumPredators(unsigned aNumber)
{
	numPredators = aNumber;
}

void Ocean::run(void)
{
	unsigned numIterations = DefaultNumIterations;

	std::cout << "\n\nВведите количество циклов (макс = 1000): ";
	std::cout.flush();
	std::cin >> numIterations;
	if (numIterations > 1000) numIterations = 1000;
	std::cout << "\nНомер итеррации = " << numIterations << std::endl;
	std::cout.flush();
	Cell* work = cells[0][0];
	bool moved[MaxRows][MaxCols];
	for (unsigned iteration = 0; iteration < numIterations; iteration++)
	{
		if (numPredators > 0 && numPrey > 0)
		{
			for (unsigned row = 0; row < numRows; row++)
				for (unsigned col = 0; col < numCols; col++) moved[row][col] = false;
			for (unsigned row = 0; row < numRows; row++)
				for (unsigned col = 0; col < numCols; col++)
				{
					if (moved[row][col] == true) continue;
					work = cells[row][col];
					cells[row][col]->process();
					moved[work->getOffset().getY()][work->getOffset().getX()] = true;
				}
			displayStats(iteration);
			displayCells();
			displayBorder();
			std::cout.flush();
		}
		else break;
	}

	std::cout << "\n\nGAME OVER\n";
	std::cout.flush();
}
