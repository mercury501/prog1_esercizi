#include <stdio.h>
#include <stdlib.h>

#include "protos.h"
#include "adv-types.h"

void print_pcs(PC * ap[], int n)
{
  int i;

  for (i = 0; i < n; i++)
    {
      printf("PC n.%04d: %s, %s\n\tRace:%2d, Class:%2d, Gold:%7d\n",
             i, ap[i]->name, ap[i]->title,
             ap[i]->race, ap[i]->class, ap[i]->gold);
    }
}
