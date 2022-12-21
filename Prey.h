#ifndef PreyDefined
#define PreyDefined
#include "Cell.h"
class Prey :
    public Cell
{
protected:
    int timeToReproduce;

    void moveFrom(Coordinate from, Coordinate to);
    Cell* reproduce(Coordinate anOffset);

public:
    Prey(Coordinate& aCoord, Ocean* ocean);
    virtual ~Prey(void) {};

    virtual void process(void);
};

#endif

