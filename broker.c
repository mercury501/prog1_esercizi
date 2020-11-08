#include <stdio.h>

int main(){

    int somma_investita;
    float commissione = 0;
    
    
   printf("Inserire la somma investita:  ");
   scanf("%d", &somma_investita);

    if (somma_investita > 500000)  //controllo prima se va oltre mezzo milione
        commissione = commissione + 255 + ((somma_investita / 100) * 0.09);
    
    else if (somma_investita < 2500) { //poi controllo a salire, con una condizione soltanto
            commissione = commissione + 30 + ((somma_investita / 100) * 1.7);
            if (commissione < 39)  //controlliamo la commissione minima
                commissione = 39;
        }
    else if (somma_investita <= 6250)
            commissione = commissione + 56 + ((somma_investita / 100) * 0.66);
    
    else if (somma_investita <= 20000)
            commissione = commissione + 76 + ((somma_investita / 100) * 0.34);
    
    else if (somma_investita <= 50000)
            commissione = commissione + 100 + ((somma_investita / 100) * 0.22);
    
    else         //se arriva fin qui vuol dire che non è maggiore di 500000 ne minore di 50000,  quindi è compreso
        commissione = commissione + 155 + ((somma_investita / 100) * 0.11);
        
    printf("\n\nLa commissione è:  %f\nSu %d investiti.\n", commissione, somma_investita);

    return 0;
}