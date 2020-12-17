#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct giocatore{

    char nickname[20];
    int punteggio;

} giocatore;

void *xmalloc(size_t nbytes){

    void *result;

    result = malloc(nbytes);

    if (!result){
        fprintf(stderr, "xmalloc(%lu) failed, BYE\n", nbytes);
        exit(-1);
    }

    return result;

}

int salva(FILE *outf, char lettera, giocatore players[], int nplayers){
    giocatore *ppointer;
    int i;
    int letter_players = 0;

    ppointer = xmalloc(sizeof(giocatore) * nplayers);

    //fread(ppointer, sizeof(giocatore), nplayers, outf);

    for (i = 0; i < nplayers; i++)
        if (players[i].nickname[0] == lettera){
            strcpy(ppointer[letter_players].nickname, players[i].nickname);
            ppointer[letter_players].punteggio = players[i].punteggio;
            letter_players++;
        }

    
    fwrite(ppointer, sizeof(giocatore), letter_players, outf);

    return letter_players;
}

int main(void){


    FILE *savefile;
    savefile = fopen("davide.bin", "wb");

    if (savefile == NULL){
    fprintf(stderr, "cant open es1 for writing\n");
    exit(1);

}

    giocatore player_list[10];
    int player_dim = 3;

    strcpy(player_list[0].nickname, "Biagio");
    strcpy(player_list[1].nickname, "Luca");
    strcpy(player_list[2].nickname, "Letizia");

    player_list[0].punteggio = 4234;
    player_list[1].punteggio = 53434;
    player_list[2].punteggio = 6434;


    char let = 'L';

    salva(savefile, let, player_list, player_dim);

    fclose(savefile);

    return 0;



}