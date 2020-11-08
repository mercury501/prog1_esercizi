/* 

Descrizione programma:

Dati in ingresso: 

Dati in uscita: 

Precondizione: 

Postcondizone: 

*/

#include <stdio.h>
#define N 100

void riempi_array(int A[], int dim){

    for (int ij = 0; ij < dim; ij++){
        printf("\nPer favore, inserisci l'elemento %d:  ", ij);
        scanf("%d", &A[ij]);
    }
}

void stampa_array_int(int arr[], int dim){
    for (int p = 0; p < dim; p++){
        printf("Numero in posizione %d:  %d\n", p, arr[p]);
    }
    return;
}

int compatta1(int vett[], int dim){

    int ii, jj;

    for (ii = 0; ii < dim; ii++){

        if (vett[ii] == vett[ii + 1]){
            for (jj = ii + 1; jj < dim; jj++)
                vett[jj] = vett[jj + 1];
            
            dim--;
            ii--;            
        }
    }

    printf("Il numero di elementi unici è:   %d\n\n", dim);
    
    return dim;

}

int main (void){
    int vector[N];
    int vector_dim;

    printf("quanti numeri?\n");
    scanf("%d", &vector_dim);

    riempi_array(vector, vector_dim);

    vector_dim = compatta1(vector, vector_dim);

    stampa_array_int(vector, vector_dim);

    return 0;
}