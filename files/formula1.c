#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *xmalloc(size_t nbytes){

    void *result;

    result = malloc(nbytes);

    if (!result){
        fprintf(stderr, "xmalloc(%lu) failed, BYE\n", nbytes);
        exit(-1);
    }

    return result;

}

typedef struct pilota{
    char nome[20];
    char cognome[20];
    char nazionalita[4];
    char scuderia[30];

    int punteggio;

} pilota;

void stampa_pilota(pilota pl){

    printf("nome:  %s\ncognome:  %s\nnaz:  %s\nscud:  %s\npunt:  %d\n", pl.nome, pl.cognome, pl.nazionalita, pl.scuderia, pl.punteggio);


    return;

}


void carica_dati(char nomefile[]){
    int linee = 0;
    char buffer[1000];
    char ch;
    int i, j, k;
    int sp, internome, finlinea = 0;
    long temp;

    FILE *file;
    file = fopen(nomefile, "r");

    if (file == NULL){
        fprintf(stderr, "cant open file\n");
        exit(1);
    }


    while((ch=fgetc(file))!=EOF) {
      if(ch=='\n')
         linee++;
    }

    rewind(file);

    pilota *classifica = xmalloc(linee * sizeof(pilota));

    for (i = 0; i < linee; i++){
        fscanf(file, "%s %s %s",classifica[i].nome, classifica[i].cognome, classifica[i].nazionalita);


        for( j = 0; finlinea == 0; j++) {
            fscanf(file, "%s", buffer);
            
            if (buffer[0] > 48 && buffer[0] < 58){
                temp = strtol(buffer, NULL, 0);
                classifica[i].punteggio = (int)temp;

                finlinea = 1;

            }
                
                
            else {
                strcat(classifica[i].scuderia, " ");
                strcat(classifica[i].scuderia, buffer);
            }

        }


        

        stampa_pilota(classifica[i]);
        sp = 0;
        finlinea = 0;

    }


}

int main(void){

    

    carica_dati("./files/classifica.txt");

    return 0;


}