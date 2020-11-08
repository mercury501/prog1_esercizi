#include <stdio.h>

#define len 100

int main (void) {
    int dim = 0;  //dimensione del vettore
    int vet[len];  //vettore originale
    int i = 0; //indice per il while a breve scrittto
    int temp;

    printf("Inserire una serie di numeri, seguita da invio, e terminata da 0\n");
    do {
        
        scanf("%d", &vet[i]);
        dim++;

    } while (vet[dim - 1] != 0);

    dim--;

//------------------------- FINO A QUA TUTT APPOST A DAVIDE 8===============D vet[0]

    for (int k = 0; k < dim ; k++)   // k= 0
        for (int l = 0; l < dim ; l++)
            if (vet[l] == vet[k] && l != k && vet[k] != 0){
                
                //printf("\nTrovata ripetizione:   %d", vet [l]);
                vet[l] = 0;
            
            }

    printf("\n\n");
    return 0;
}