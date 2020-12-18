#include <stdio.h>
#include <stdlib.h>

/*
 * malloc() with error checking
 */
void *xmalloc(size_t nbytes)
{
  void *memory_block = malloc(nbytes);

  if (memory_block == NULL)
    {
      fprintf(stderr, "xmalloc(%lu) failed. Sorry, bye!\n", nbytes);
      exit(-1);
    }
  // else
  return memory_block;
}
