#include "Obstacle.h"

Obstacle::Obstacle(Coordinate& aCoord, Ocean* ocean) : Cell(aCoord, ocean)
{
    image = ObstacleImage;
}