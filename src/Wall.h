#ifndef WALL_H
#define WALL_H

#include "definitions.h"
#include "Point.h"

class Wall
{
public:
  Wall();
  ~Wall();

  void set_pos  (Point pt) { pos.set_x(pt.get_x()); pos.set_y(pt.get_y()); };
  void set_pos_x(int x   ) { pos.set_x(x);                                 };
  void set_pos_y(int y   ) { pos.set_y(y);                                 };

  Point get_pos ()         { return pos;         };
  int get_pos_x ()         { return pos.get_x(); };
  int get_pos_y ()         { return pos.get_y(); };

protected:

private:
  Point pos;
};

#endif
