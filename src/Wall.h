#ifndef WALL_H
#define WALL_H

#include "definitions.h"

class Wall
{
public:
  Wall();
  ~Wall();

  void set_pos_x(int x) { pos_x = x; };
  void set_pos_y(int y) { pos_y = y; };

  int get_pos_x() { return pos_x; };
  int get_pos_y() { return pos_y; };

protected:

private:
  int pos_x, pos_y;
};

#endif
