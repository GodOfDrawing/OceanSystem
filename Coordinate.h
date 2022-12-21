#ifndef CoordinateDefined
#define CoordinateDefined

class Coordinate
{
private:
	unsigned x;
	unsigned y;

public:
	Coordinate(unsigned aX, unsigned aY);
	Coordinate(void);
	Coordinate(Coordinate& aCoord);

	~Coordinate(void) {}

	unsigned getX(void);
	unsigned getY(void);
	void setX(unsigned aX);
	void setY(unsigned aY);

	void operator = (const Coordinate& aCoord);
	int operator == (Coordinate& c);
	int operator != (Coordinate& c);
};

#endif