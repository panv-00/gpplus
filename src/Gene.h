#ifndef GENE_H
#define GENE_H

#include "definitions.h"

class Gene
{
public:
  Gene();
  ~Gene();

protected:

private:
  State state;
  Env env;
  Action action;
  State next_state;
};

#endif
