/* 

Descrizione programma:

Dati in ingresso: 

Dati in uscita: 

Precondizione: 

Postcondizone: 

Pseudocodice:

*/

#include <stdio.h>

void riempi_array_int(int A[], int dim){  //legge un array di interi
    for (int i = 0; i < dim; i++){
        printf("\nPer favore, inserisci l'elemento %d:  ", i);
        scanf("%d", &A[i]);
    }
}

void stampa_array_int(int arr[], int dim){  // stampa un array di interi con un ciclo for
    for (int p = 0; p < dim; p++){
        printf("Numero in posizione %d:  %d\n", p, arr[p]);
    }
    return;
}

int main (void){





    return 0;
}

