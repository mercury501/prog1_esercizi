/* 
Nome funzione:

Descrizione funzione:

Dati in ingresso: 

Dati in uscita: 

Precondizione: 

Postcondizone: 

Pseudocodice:

*/

#include <stdio.h>
#define N 1000

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
    printf("\n\n");
    
    return;
}

int main (void){
    int arr[N] = {23, 123, 664, 6754, 212, 564, 55, 658, 87, 12};
    int arr_dim = 10;

    char str_arr[N] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";




    return 0;
}

