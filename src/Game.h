#ifndef GAME_H
#define GAME_H

#include "definitions.h"

#include "Agent.h"
#include "Food.h"
#include "Wall.h"

typedef struct
{
  int x;
  int y;

} Point;

class Game
{
public:
  Game();
  ~Game();

  Point get_free_location();
  void init_game();
  void step_game();

  Agent get_agent(int i) { return agents[i]; };
  Wall get_wall(int i) { return walls[i]; };
  Food get_food(int i) { return foods[i]; };

protected:

private:
  int random_int_range(int low, int high)
  {
    return rand() % (high - low) + low;
  }

  Agent agents[AGENTS_COUNT];
  Food foods[FOODS_COUNT];
  Wall walls[WALLS_COUNT];
  size_t agents_count = 0;
  size_t foods_count = 0;
  size_t walls_count = 0;
};

#endif
