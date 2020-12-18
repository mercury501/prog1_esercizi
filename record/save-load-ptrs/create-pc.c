#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "protos.h"
#include "adv-types.h"

/*
 * create a new playing character (PC)
 * in freshly allocated memory,
 * fill the fields with the values provided by the parameters,
 * and return a pointer to it.
 */
PC *create_pc(char *name, char *title, int race, int class, int gold)
{
  PC *new_pc;

  new_pc = xmalloc(sizeof(PC));
  strncpy(new_pc->name, name, PC_NAME_SIZE);
  strncpy(new_pc->title, title, PC_TITLE_SIZE);
  new_pc->race = race;
  new_pc->class = class;
  new_pc->gold = gold;
  return new_pc;
}
