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

  Point  get_free_location();
  void   init_game();
  int    agent_at(int pos_x, int pos_y);
  Point  point_infront_of_agent(Agent *agent);
  Env    env_infront_of_agent(size_t agent_index);
  int    food_infront_of_agent(size_t agent_index);
  int    agent_infront_of_agent(size_t agent_index);
  int    wall_infront_of_agent(size_t agent_index);
  void   execute_action(size_t agent_index, Action action);
  void   step_game();

  Agent  *get_agent (int i) { return &agents [i]; };
  Chromo *get_chromo(int i) { return &chromos[i]; };
  Food   *get_food  (int i) { return &foods  [i]; };
  Wall   *get_wall  (int i) { return &walls  [i]; };

protected:

private:
  int random_int_range(int low, int high) { return rand() % (high - low) + low; };
  int mod_int         (int a  , int b   ) { return (a % b + b) % b;             };

  Point  points_dir[DIR_COUNT] =
  {
    // DIR_RT
    Point(1, 0),

    // DIR_UP
    Point(0, -1),
  
    // DIR_LT
    Point(-1, 0),

    // DIR_DN
    Point(0, 1)
  
  };

  Agent  agents[AGENTS_COUNT];
  Chromo chromos[AGENTS_COUNT];
  Food   foods[FOODS_COUNT];
  Wall   walls[WALLS_COUNT];
};

#endif
