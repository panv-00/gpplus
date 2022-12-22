#ifndef GAME_H
#define GAME_H

#include <stdio.h>

#include "Agent.h"
#include "definitions.h"

class Game
{
public:
  Game();
  ~Game();

  int Run();

protected:

private:

  int random_int_range(int low, int high);
  Dir random_dir(void);
  Agent random_agent(void);
  void init_agents(void);
  
  Agent agents[AGENTS_COUNT];
};

#endif
