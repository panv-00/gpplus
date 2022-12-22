#ifndef AGENT_H
#define AGENT_H

#include "definitions.h"

class Agent
{
public:
  Agent();
  ~Agent();

  void set_pos_x(int px) { pos_x = px; };
  void set_pos_y(int py) { pos_y = py; };
  void set_dir(Dir dr) { dir = dr; };
  int get_pos_x() { return pos_x; };
  int get_pos_y() { return pos_y; };
  Dir get_dir() { return dir; };

protected:

private:
  int pos_x, pos_y;
  Dir dir;
};

#endif
