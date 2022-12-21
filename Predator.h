#ifndef PredatorDefined
#define PredatorDefined

#include "Prey.h"
class Predator : public Prey
{
private:
	virtual Cell* reproduce(Coordinate anOffset, Ocean* ocean);

protected:
	unsigned timeToFeed;

public:
	Predator(Coordinate aCoord, Ocean* ocean);
	virtual ~Predator(void) {};

	virtual void process(void);
};

#endif
