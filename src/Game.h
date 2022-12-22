#ifndef GAME_H
#define GAME_H

#include <stdio.h>

#include "Agent.h"
#include "Food.h"
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
  Agent random_agent(int index);
  void init_agents(void);
  
  Agent agents[AGENTS_COUNT];
  Food foods[FOODS_COUNT];
};

#endif
