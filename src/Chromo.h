#ifndef CHROMO_H
#define CHROMO_H

#include "definitions.h"
#include "Gene.h"

class Chromo
{
public:
  Chromo();
  ~Chromo();

  Gene get_gene(int index) { return genes[index]; };

protected:

private:
  size_t count;
  Gene genes[GENES_COUNT];

};

#endif
