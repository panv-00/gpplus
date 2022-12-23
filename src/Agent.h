#ifndef AGENT_H
#define AGENT_H

#include "definitions.h"
#include "Point.h"

class Agent
{
public:
  Agent();
  ~Agent();

  void set_pos   (Point pt) { pos.set_x(pt.get_x()); pos.set_y(pt.get_y()); };
  void set_pos_x (int px  ) { pos.set_x(px);                                };
  void set_pos_y (int py  ) { pos.set_y(py);                                };
  void set_dir   (Dir dr  ) { dir = dr;                                     };
  void set_hunger(int h   ) { hunger = (h > HUNGER_MAX ? HUNGER_MAX : h);   };
  void set_health(int h   ) { health = (h > 0          ? h          : 0);   };
  void set_state (State st) { state = st;                                   };

  Point get_pos  ()         { return pos;         };
  int get_pos_x  ()         { return pos.get_x(); };
  int get_pos_y  ()         { return pos.get_y(); };
  Dir get_dir    ()         { return dir;         };
  int get_hunger ()         { return hunger;      };
  int get_health ()         { return health;      };
  State get_state()         { return state;       };

protected:

private:
  Point pos;
  Dir dir;
  int hunger;
  int health;
  State state;
};

#endif
