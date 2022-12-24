#ifndef WALL_H
#define WALL_H

#include "definitions.h"
#include "Point.h"

class Wall
{
public:
   Wall();
  ~Wall();

  void set_pos  (Point pos  ) { this->pos.set_x(pos.get_x());
                                this->pos.set_y(pos.get_y()); };
  void set_pos_x(int   pos_x) { this->pos.set_x(pos_x);       };
  void set_pos_y(int   pos_y) { this->pos.set_y(pos_y);       };

  Point *get_pos  () { return &pos;        };
  int   get_pos_x () { return pos.get_x(); };
  int   get_pos_y () { return pos.get_y(); };

protected:

private:
  Point pos;
};

#endif
