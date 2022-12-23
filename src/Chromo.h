#ifndef CHROMO_H
#define CHROMO_H

#include "definitions.h"
#include "Gene.h"

class Chromo
{
public:
  Chromo();
  ~Chromo();

protected:

private:
  size_t count;
  Gene Genes[GENES_COUNT];

};

#endif
