#include "Chromo.h"

Chromo::Chromo()
{

}

Chromo::~Chromo()
{

}

void Chromo::print()
{
  for (size_t i = 0; i < GENES_COUNT; i++)
  {
    printf("State: %d, Env: %d, Action: %d, Next_State: %d\n",
        get_gene(i)->get_state(),
        get_gene(i)->get_env(),
        get_gene(i)->get_action(),
        get_gene(i)->get_next_state());
  }
  printf("\n");
}
