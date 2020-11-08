/* 

Descrizione programma:

Dati in ingresso: 

Dati in uscita: 

Precondizione: 

Postcondizone: 

*/
#include <stdio.h>


#define N 100


int potenz(int n, int e){
    int count = n;
    e--;

    for (int t = 0; t < e; t++)
        count *= n;

    return count;
}

void cerca_armstrong(int A[], int dim){

    int temp[10];
    int temp_dim = 0;
    int token = 0;

    int pot_armstrong = 0;
    int array_element;
    

    int i, j, k;

    for (i = 0; i < dim; i++){ //loopa l'array
        
        array_element = A[i];   //popolo la variabile temporanea
        for (j = 0; token == 0 ; j++){
            

            temp[j] = array_element % 10;  //carichiamo l'unità del numero in esame nell'array temp, aumentandone la dimensione
            temp_dim++;
            
            if ((array_element/10) == 0)  //se la divisione da 0 è finito il numero   5--> 0
                token = 1;
            else
            {
                array_element = array_element / 10;   //scalo a destra il numero, 457 -> 45
            }
            
        }

        for (k = 0; k < temp_dim; k++)    // in temp ci son le cifre, e il loro indice corrisponde alla posizione ( pos 2 = 10^2), in temp_dim c'è la lunghezza del numero
            pot_armstrong += potenz(temp[k], temp_dim);

        if (pot_armstrong != A[i])  //se il numero ottenuto non è uguale al numero iniziale non è di armstrong, reset a 0
            A[i] = 0;
        
        pot_armstrong = 0; //puliamo le variabili temporanee usate
        temp_dim = 0;
        token = 0;
        
    } 

    return;
}

int main (void){

    int s;
    int vett[N] = {57, 23, 24678050, 24678051, 88593477, 146511208, 472335975, 534494836, 912985153, 23};
    int dim_vett = 10;

    cerca_armstrong(vett, dim_vett);

    for (s=0; s < dim_vett; s++)
        printf("Numero indice %d:  %d\n", s, vett[s]);

    return 0;
}