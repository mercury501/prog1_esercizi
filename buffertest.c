/* 

Descrizione programma:

Dati in ingresso: 

Dati in uscita: 

Precondizione: 

Postcondizone: 

*/

#include <stdio.h>

void riempi_array_int(int A[], int dim){


    for (int i = 0; i < dim; i++){
        printf("\nPer favore, inserisci l'elemento %d:  ", i);
        scanf("%d", &A[i]);
    }
}

void stampa_array_int(int arr[], int dim){
    for (int p = 0; p < dim; p++){
        printf("Numero in posizione %d:  %d\n", p, arr[p]);
    }
    return;
}

int main (void){

    int vettore[10];
    int dieci = 10;

    for(int i = 0; i < 13; i++){
        printf("\nInserire numer :  ");
        scanf("%d", &vettore[i]);
    }

    printf("\nDieci è :  %d", dieci);



    return 0;
}

