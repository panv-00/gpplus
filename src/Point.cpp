#include "Wall.h"

Point::Point(int x, int y) : x {x}, y {y}
{

}

Point::~Point()
{

}


bool Point::is_equal(Point point)
  {
    if (this->x == point.get_x() && this->y == point.get_y()) { return true; }
    return false;
  };


