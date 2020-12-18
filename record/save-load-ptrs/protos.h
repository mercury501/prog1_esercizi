#include "adv-types.h"

// xmalloc.c
void *xmalloc(size_t nbytes);

// load-save-ptrs.c
void free_pcs(PC * ap[], int n);
int save_pcs(PC ** ap, int n, FILE * fp);
int load_pcs(PC ** ap, int n, FILE * fp);

// create-pc.c
PC *create_pc(char *name, char *title, int race, int class, int gold);

// print-pcs.c
void print_pcs(PC * ap[], int n);
