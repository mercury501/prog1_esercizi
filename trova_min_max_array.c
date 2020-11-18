/* 

Descrizione funzione: Scrivere una funzione trova_min_max che prende in ingresso un vettore e la sua dimensione, e restituisce con 2 puntatori a int il minimo ed il massimo

Dati in ingresso: array, dimensione, puntatore a minimo, puntatore a massimo

Dati in uscita: minimo e massimo tramite puntatore, non ritorno

Precondizione:  il vettore deve essere di int

Postcondizone: min e max devono contenere rispettivamente il minimo e il massimo

Pseudocodice:
    for elementi
        se elemento < min
            min = elemento
        se elemento > max
            max = elemento
        

*/

#include <stdio.h>
#define N 100


void stampa_array_int(int arr[], int dim){  // stampa un array di interi con un ciclo for
    for (int p = 0; p < dim; p++){
        printf("Numero in posizione %d:  %d\n", p, arr[p]);
    }
    return;
}

void trova_min_max(int a[], int dim, int *min, int *max){  //in ingresso abbiamo puntatori a int
    int temp_min = a[0];
    int temp_max = a[0];  //inizializza minimo e massimo al primo elemento dell'array
    

    for (int i = 1; i < dim; i++){  //parte il loop sull'array dall'elemento 1, l'elemento 0 è già minimo e massimo in questo istante
        if (a[i] < temp_min)  //se l'elemento considerato è minore del minimo, cambiamo il minimo
            temp_min = a[i];
        if (a[i] > temp_max)  //se l'elemento considerato è maggiore del massimo, cambiamo il massimo
            temp_max = a[i];
                
    }

    *min = temp_min; //popoliamo i parametri d'uscita
    *max = temp_max;

}

int main (void){
    int a[N] = {12, 0, 543, 43, -4};
    int dim = 5;
    int min, max;

    stampa_array_int(a, dim);

    trova_min_max(a, dim, &min, &max);  //chiamiamo la funzione, passando indirizzi di min e max

    printf("\nMinimo: %d\nMassimo: %d\n", min, max);


    return 0;
}

