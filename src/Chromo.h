#ifndef CHROMO_H
#define CHROMO_H

#include "definitions.h"
#include "Gene.h"

class Chromo
{
public:
   Chromo();
  ~Chromo();

  size_t get_count(         ) { return count;         };
  Gene   *get_gene(int index) { return &genes[index]; };

  void   set_count(size_t count) { this->count = count; };

  void   print();

protected:

private:
  size_t count;
  Gene   genes[GENES_COUNT];

};

#endif
