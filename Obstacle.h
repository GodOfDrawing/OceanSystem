#ifndef ObstacleDefined
#define ObstacleDefined

#include "Cell.h"

class Obstacle : public Cell
{
public:
    Obstacle(Coordinate& aCoord, Ocean* ocean);

    virtual ~Obstacle(void) {};
};

#endif
