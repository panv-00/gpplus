#ifndef FOOD_H
#define FOOD_H

#include <stdio.h>
#include "definitions.h"

class Food
{
public:
  Food();
  ~Food();

protected:

private:
  bool eaten;
  int pos_x, pos_y;
};

#endif
