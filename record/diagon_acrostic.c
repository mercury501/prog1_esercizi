/*
 
 La funzione diagon_acrostic() prende come parametro un array
di n stringhe strings[], unitamente alla sua dimensione n. Il risultato è una nuova
stringa, allocata dinamicamente, che ha in prima posizione il primo carattere della
prima stringa, in seconda posizione il secondo carattere della seconda stringa, e così
via: in ultima posizione si troverà l’n-esimo carattere dell’n-esima stringa.
 
 
 
Per esempio:
stringhe[] = { "abc", "definitivo", "ghiro" }
diagon_acrostic(stringhe, 3) = "aei"
 
 
Ognuna delle stringhe in strings[] dev’essere lunga almeno n caratteri. Se la funzione
scopre un elemento di strings[] che è lungo meno di n, restituisce NULL. Scrivere
diagon_acrostic().
 
 */
 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100

void *xmalloc(size_t nbytes){

    void *result;

    result = malloc(nbytes);

    if (!result){
        fprintf(stderr, "xmalloc(%lu) failed, BYE\n", nbytes);
        exit(-1);
    }

    return result;

}

char *diagon_acrostic(char **str, int n){
    int i;
    char *buf = xmalloc((n + 1) * sizeof(char));

    for (i = 0; i < n; i++)
        if (strlen(str[i]) < n){
            printf("\nstringa n. %d ha dimensione diversa da n\n", i + 1);
            return NULL;
        }

    for (i = 0; i < n; i++)
        buf[i] = str[i][i];

    return buf;

}


int main(void){

    char **stringhe = xmalloc( 3 * sizeof(char *));
    int i;
    int n = 3;

    for (i = 0; i < n; i++)
        stringhe[i] = xmalloc(N);

    strcpy(stringhe[0],"abc");
    strcpy(stringhe[1], "definitivo");
    strcpy(stringhe[2], "ghiro");
    


    for (i = 0; i < n; i++)
        printf("\n%s\n", stringhe[i]);
    
    char *acro = diagon_acrostic(stringhe, n);

    printf("\n Acro:\n%s\n", acro);


    return 0;



}