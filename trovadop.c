/* 
Dati in ingresso: numeri di un array

dati in uscita: il valore dei numeri presenti due volte in tale array

precondizione: l'utente non può immettere 0 nell'array, dato che lo termina

postcondizone: nessuna

*/


#include <stdio.h>

#define len 100

int main (void) {
    int dim = 0;  //dimensione del vettore
    int vet[len];  //vettore originale
    int copy[len]; // vettore copiato che distruggiamo
    int i = 0; //indice per il while a breve scrittto
    int temp;
    int bubble = 0;

    printf("Inserire una serie di numeri, seguita da invio, e terminata da 0\n");
    do {
        
        scanf("%d", &vet[i]);
        i++;
        dim++;

    } while (vet[i - 1] != 0);

    dim--;



    for (int j = 0; j < dim; j++)
        copy[j] = vet[j];

    for (int k = 0; k < dim ; k++){
        for (int l = 0; l < dim ; l++)
            if (copy[l] == copy[k] && l != k && copy[l] != 0){
                if (bubble == 0){
                    printf("\nTrovata ripetizione:   %d", copy [l]);
                    bubble = 1;
                }
                
                copy[l] = 0;
            
            }
        
        bubble = 0;
    }

    printf("\n\n");
    return 0;
}