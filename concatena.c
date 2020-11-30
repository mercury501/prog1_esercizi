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
    char str[N];
    char str1[N];   //dichiara due stringhe da usare come buffer

    printf("Inserisci stringa 1:  ");
    gets(str);  //legge le due stringhe da tastiera
    printf("\nInserisci stringa 2: ");
    gets(str1);

    printf("\n");


    char *str2 = concatena(str, str1);  //chiama la funzione concatena e assegna la nuova stringa a str2

    printf("%s\n", str2);   //stampa la stringa risultante

    char *s = (char *) malloc(strlen(str1) + strlen(str) + 1);  //qui invece allochiamo prima un puntatore s

    s = concatena(str1, str);   //e poi assegnamo il risultato di concatena

    printf("%s\n", s);

    free(s);    //liberiamo la memoria occupata da s

    //printf("%s\n", s);  //non da errore, ma s non esiste più

    return 0;
}