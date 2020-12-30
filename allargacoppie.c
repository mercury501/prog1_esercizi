/* 

Descrizione programma: void allargacoppie (int A[], int n), per ogni coppia di elementi adiacenti, 
se il primo è minore del secondo, sottrae 1 al primo e aggiunge 1 al secondo

Dati in ingresso: array di int, e la sua dimensione

Dati in uscita: l'array modificato opportunamente

Precondizione: l'array non deve essere vuoto, e di int

Postcondizone: deve avere la stessa dimensione dell'array in ingresso, e modificato come traccia

Pseudocodice:


*/

#include <stdio.h>
#define N 100

void allargacoppie(int A[], int n){
    for (int i = 0; i < n - 1; i += 2) {  //i arriva a n - 1 poichè l'ultimo elemento non ha un compagno, e non va controllato
        if (A[i] < A[i + 1]){
            A[i] -= 1;
            A[i + 1] += 1;
        }     

    }
    return;
}
void stampa_array_int(int arr[], int dim){
    for (int p = 0; p < dim; p++){
        printf("Numero in posizione %d:  %d\n", p, arr[p]);
    }
    return;
}

int main (void){

    int vett[N] = {33, 21, -7, 9, -100};
    int vett_dim = 5;

    allargacoppie(vett, vett_dim);

    stampa_array_int(vett, vett_dim);


    return 0;
}

