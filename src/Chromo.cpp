#include "Chromo.h"

Chromo::Chromo()
{

}

Chromo::~Chromo()
{

}

void Chromo::print()
{
  printf("\n    Chromo: \n");
  for (size_t i = 0; i < GENES_COUNT; i++)
  {
    printf("      State: %d, Env: %s, Action: %s, Next_State: %d\n",
        get_gene(i)->get_state(),
        env_to_cstr(get_gene(i)->get_env()),
        action_to_cstr(get_gene(i)->get_action()),
        get_gene(i)->get_next_state());
  }
  printf("\n");
}
