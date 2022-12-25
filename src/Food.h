#ifndef FOOD_H
#define FOOD_H

#include "definitions.h"
#include "Point.h"

class Food
{
public:
  Food();
 ~Food();

  void set_eaten(bool eaten) { this->eaten = eaten;          };
  void set_pos  (Point pos ) { this->pos.set_x(pos.get_x());
                               this->pos.set_y(pos.get_y()); };
  void set_pos_x(int pos_x ) { this->pos.set_x(pos_x);       };
  void set_pos_y(int pos_y ) { this->pos.set_y(pos_y);       };

  bool  get_eaten() { return eaten;       };
  Point *get_pos () { return &pos;        };
  int   get_pos_x() { return pos.get_x(); };
  int   get_pos_y() { return pos.get_y(); };

protected:

private:
  bool  eaten;
  Point pos;
};

#endif
