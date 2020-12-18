#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "protos.h"
#include "adv-types.h"

#define NUM_PEOPLE	3

//start of mercury's code, the rest is professor code

int save_pcs(PC *ap[], int n, FILE *fp){
  int i;
  PC *player;
  player = xmalloc(sizeof(PC)); //creiamo un player temporaneo


  for (i = 0; i < n; i++){  //assegnamo a player i valori di ap[i]
    strcpy(player->name,ap[i]->name);
    strcpy(player->title, ap[i]->title);
    player->race = ap[i]->race;
    player->class = ap[i]->class;
    player->gold = ap[i]->gold;
    fwrite(player, sizeof(PC), 1, fp);  //scriviamo player su file
  }

    return i + 1;

}

int load_pcs(PC *ap[], int n, FILE *fp){
  int i;
  PC *player;
  player = xmalloc(sizeof(PC)); //creiamo un player temporaneo

  for (i = 0; i < n; i++){
    fread(player, sizeof(PC), 1, fp); //leggiamo un giocatore da file
    ap[i] = xmalloc(sizeof(PC));  //allochiamo lo spazio in ap
    strcpy(ap[i]->name, player->name);
    strcpy(ap[i]->title, player->title);  //assegnamo i valori di player ad ap[i]
    ap[i]->race = player->race;
    ap[i]->class = player->class;
    ap[i]->gold = player->gold;
    
  }
    

    return i + 1;


}

void free_pcs(PC **ap, int n){
  int i;
  for (i = 0; i < n; i++) //chiamiamo Free per ogni puntatore in ap
    free(ap[i]);

  return;

}

//end of mercury's code



int main(void)
{
  PC *people[NUM_PEOPLE];
  size_t saved, loaded;
  char *filename = "savefile.dat";
  FILE *fin, *fout;

  people[0] =
    create_pc("Zorg", "Slayer of innocents", PC_RACE_TROLL, PC_CLASS_WARRIOR,
              0);
  people[1] =
    create_pc("Arya", "Avenger of the North", PC_RACE_HUMAN, PC_CLASS_THIEF,
              0);
  people[2] =
    create_pc("Barnyth", "Enchanter of trees", PC_RACE_ELF, PC_CLASS_WIZARD,
              0);

  print_pcs(people, NUM_PEOPLE);

  // let's save the data
  fout = fopen(filename, "wb");
  if (fout == NULL)
    {
      fprintf(stderr, "Couldn't open %s for writing.\n", filename);
      exit(-2);
    }
  saved = save_pcs(people, NUM_PEOPLE, fout);
  printf("** Saved %lu PCs\n", saved);
  fclose(fout);

  // let's change the data
  strcpy(people[0]->name, "ScassoZorg");
  people[0]->gold = 111;
  strcpy(people[1]->name, "Aria fritta");
  people[1]->gold = 222;
  strcpy(people[2]->name, "XXXXXX");
  people[2]->gold = 333;

  printf("** Changed the data\n");
  print_pcs(people, NUM_PEOPLE);

  // let's not waste memory and free everything
  free_pcs(people, NUM_PEOPLE);

  // let's load the saved data back into memory
  fin = fopen(filename, "rb");
  if (fout == NULL)
    {
      fprintf(stderr, "Couldn't open %s for reading.\n", filename);
      exit(-2);
    }
  loaded = load_pcs(people, NUM_PEOPLE, fin);
  fclose(fin);
  printf("**Loaded %lu PCs\n", loaded);
  print_pcs(people, NUM_PEOPLE);

  return 0;
}
