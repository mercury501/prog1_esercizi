#include <stdio.h>
#define N 100

int main(void){

    int *a;
    int dim = 10;

    //calloc inizializza l'area di memoria a 0
    a = calloc(sizeof(int), dim);  //sizeof ritorna la dimensione di un elemento di quel tipo

    int i;
    for (i = 0; i < dim - 1; i++)   //assegno un valore random a ogni elemento
        a[i] = rand();  //tranne l'ultimo
    
    for (i = 0; i < dim; i++)   //stampo i valori
        printf("%d, ", a[i]);

    printf("\n");


    return 0;
}