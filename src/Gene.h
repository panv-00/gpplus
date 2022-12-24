#ifndef GENE_H
#define GENE_H

#include "definitions.h"

class Gene
{
public:
   Gene();
  ~Gene();

  State  get_state     () { return state;      };
  Env    get_env       () { return env;        };
  Action get_action    () { return action;     };
  State  get_next_state() { return next_state; };

  void set_state      (State state     ) { this->state      = state;      };
  void set_env        (Env env         ) { this->env        = env;        };
  void set_action     (Action action   ) { this->action     = action;     };
  void set_next_action(State next_state) { this->next_state = next_state; };

protected:

private:
  State  state;
  Env    env;
  Action action;
  State  next_state;
};

#endif
