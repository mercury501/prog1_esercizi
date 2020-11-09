/* 

Descrizione programma: aggiungiel(a[], n, el, index) aggiunge l'elemento el nell'opportuna posizione,
rimuoviel(a[], n, index) rimuove l'elemento [index] dall'array

Dati in ingresso: per aggiungi, array, dimensione, elemento e l'indice dove inserirlo
    per rimuovi array, dimensione e l'indice da eliminare

Dati in uscita: l'array opportunamente modificato, inoltre ritorna la nuova dimensione

Precondizione: l'indice dove inserire o rimuovere l'elemento deve essere valido

Postcondizone: l'array deve essere opportunamente modificato, come la dimensione

Pseudocodice:

*/

#include <stdio.h>
#define N 100

int aggiungiel(int A[], int dim, int el, int index){

    if (index < 0 || index > dim) // controllo la validità dell'index
        return -1;

    for(int i = dim + 1; i >= index; i--) //spostiamo ogni elemento dopo index a destra di una casella
        A[i] = A[i - 1];

    A[index] = el; //e mettiamo el in index
    

    return dim + 1; //ritorniamo la dimensione incrementata
}

int rimuoviel(int A[], int dim, int index){
    if (index < 0 || index > dim - 1) // controllo la validità dell'index
        return -1;

    for(int i = index; i < dim; i++) // spostiamo ogni elemento a sinistra di una casella
        A[i] = A[i + 1]; // sovrascrivendo l'elemento in posizione index
    
    return dim - 1; //ritorniamo la dimensione decrementata
}

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

    int vett1[N] = {23, 11, 55, 65, 12};
    int dim1 = 5;

    stampa_array_int(vett1, dim1);

    dim1 = rimuoviel(vett1, dim1, 2);

    stampa_array_int(vett1, dim1);

    dim1 = aggiungiel(vett1, dim1, 55, 2);

    stampa_array_int(vett1, dim1);



    return 0;
}

