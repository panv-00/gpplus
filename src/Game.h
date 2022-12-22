#ifndef GAME_H
#define GAME_H

#include "definitions.h"

#include "Agent.h"
#include "Food.h"
#include "Wall.h"

class Game
{
public:
  Game();
  ~Game();

  void init_game();
  void step_game();
  Agent get_agent(int i) { return agents[i]; };

protected:

private:
  int random_int_range(int low, int high);
  Dir random_dir(void);
  Agent random_agent(int index);
  
  Agent agents[AGENTS_COUNT];
  Food foods[FOODS_COUNT];
  Wall walls[WALLS_COUNT];
};

#endif
