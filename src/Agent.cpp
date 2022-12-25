#include "Agent.h"

Agent::Agent() : pos(0, 0)
{

}

Agent::~Agent()
{

}

void Agent::print()
{
  printf("  Position: %d, %d", get_pos_x(), get_pos_y());
  printf("  Direction: %s", dir_to_cstr(dir));
  printf("  Hunger   : %d", hunger);
  printf("  Health   : %d", health);
  printf("  State    : %d", state);
}
