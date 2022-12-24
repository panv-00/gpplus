#ifndef AGENT_H
#define AGENT_H

#include "definitions.h"
#include "Point.h"

class Agent
{
public:
   Agent();
  ~Agent();

  void set_pos   (Point pos   ) { this->pos.set_x(pos.get_x());
                                  this->pos.set_y(pos.get_y());          };
  void set_pos_x (int   pos_x ) { this->pos.set_x(pos_x);                };
  void set_pos_y (int   pos_y ) { this->pos.set_y(pos_y);                };
  void set_dir   (Dir   dir   ) { this->dir = dir;                       };
  void set_hunger(int   hunger) { this->hunger = (hunger > HUNGER_MAX ?
                                                  HUNGER_MAX : hunger);  };
  void set_health(int   health) { this->health = (health > 0          ?
                                                  health     : 0     );  };
  void set_state (State state ) { this->state = state;                   };

  Point *get_pos  () { return &pos;        };
  int   get_pos_x () { return pos.get_x(); };
  int   get_pos_y () { return pos.get_y(); };
  Dir   get_dir   () { return dir;         };
  int   get_hunger() { return hunger;      };
  int   get_health() { return health;      };
  State get_state () { return state;       };

protected:

private:
  Point pos;
  Dir   dir;
  int   hunger;
  int   health;
  State state;
};

#endif
