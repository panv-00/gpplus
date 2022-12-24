#ifndef POINT_H
#define POINT_H

#include "definitions.h"

class Point
{
public:
  Point();
  ~Point();

  void set_x(int x) { this->x = x; };
  void set_y(int y) { this->y = y; };

  int get_x () { return x; };
  int get_y () { return y; };

protected:

private:
  int x, y;
};

#endif
