#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100


char *concatena(char *s1, char *s2){

    char *p = (char *) malloc(strlen(s1) + strlen(s2) + 1);

    if (!p) //se not p è vera vuol dire che p è null, quindi da errore
        printf("error allocating \n");

    strcpy(p, s1);
    strcat(p, s2);

    return p;
}



int main(void){
    char str_0[N];
    char str_1[N];   //dichiara due stringhe da usare come buffer

    printf("Inserisci stringa 1:  ");
    gets(str_0);  //legge le due stringhe da tastiera
    printf("\nInserisci stringa 2: ");
    gets(str_1);

    printf("\n");


    char *str_2 = concatena(str_0, str_1);  //chiama la funzione concatena e assegna la nuova stringa a str_2

    printf("%s\n", str_2);   //stampa la stringa risultante

    char *str_test = (char *) malloc(strlen(str_1) + strlen(str_0) + 1);  //qui invece allochiamo prima un puntatore s

    str_test = concatena(str_1, str_0);   //e poi assegnamo il risultato di concatena

    printf("%s\n", str_test);

    free(str_test);    //liberiamo la memoria occupata da s

    //printf("%s\n", str_test);  //non da errore, ma str_test non esiste più

    char *str_ultratest = calloc(N, sizeof(char));  //calloc vuole il numero di elementi, e la taglia, inizializa tutto a 0
    strcpy(str_ultratest, "eccola qui la stringhella\n");
    printf("%s", str_ultratest);

    return 0;
}