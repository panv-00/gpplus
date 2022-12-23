#ifndef GAME_H
#define GAME_H

#include "definitions.h"

#include "Point.h"
#include "Chromo.h"
#include "Agent.h"
#include "Food.h"
#include "Wall.h"

class Game
{
public:
  Game();
  ~Game();

  Point get_free_location();
  void init_game();
  Point point_infront_of_agent(Agent *agent);
  Env env_of_agent(size_t agent_index);
  size_t food_infront_of_agent(size_t agent_index);
  size_t agent_infront_of_agent(size_t agent_index);
  size_t wall_infront_of_agent(size_t agent_index);
  void execute_action(size_t agent_index, Action action);
  void step_game();

  Agent get_agent(int i) { return agents[i]; };
  Wall get_wall  (int i) { return walls[i];  };
  Food get_food  (int i) { return foods[i];  };

protected:

private:
  int random_int_range(int low, int high) { return rand() % (high - low) + low; };
  int mod_int         (int a  , int b   ) { return (a % b + b) % b;             };

  Point points_dir[4];
  Agent agents[AGENTS_COUNT];
  Chromo chromos[AGENTS_COUNT];
  Food foods[FOODS_COUNT];
  Wall walls[WALLS_COUNT];
  size_t agents_count = 0;
  size_t foods_count  = 0;
  size_t walls_count  = 0;
};

#endif
