/* 

Descrizione programma: funzione che restituisce la lunghezza di una stringa

Dati in ingresso:  la stringa, in un array di char

Dati in uscita:  la lunghezza della stringa

Precondizione: 

Postcondizone: il valore ritornato deve essere uguale al numero caratteri della stringa

Pseudocodice: ciclo i finchè a(i) non è uguale a \0
                aumento contatore

*/

#include <stdio.h>


int impostor_strlen(char a[]){
    int n = 0;

    for (int i = 0; a[i] != '\0'; i++)  //finchè non trova il carattere terminatore, incrementa
        n++;

    return n;
}

int main (void){
    char lello[] ="asdrubale";

    printf("\nLa stringa è lunga:    %d\n", impostor_strlen(lello));



    return 0;
}

