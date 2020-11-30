/* 
Nome funzione: map_lenght

Descrizione funzione: popola un array di int con le dimensioni delle stringhe contenute in un altro array

Dati in ingresso: array di stringhe, array di interi e le loro dimensioni

Dati in uscita: l'array delle lunghezze opportunamente popolato

Precondizione: devono essere della stessa dimensione array di stringhe e array lunghezze

Postcondizone: array di stringhe invariato, array dimensioni popolato

Pseudocodice:
    ciclo i sulla dimensione
        lunghezza i = lunghezza(stringhe i)

*/
// wip, da rifare con allocazione dinamica

#include <stdio.h>
#include <string.h>
#define N 1000


void stampa_array_int(int arr[], int dim){  // stampa un array di interi con un ciclo for
    for (int p = 0; p < dim; p++){
        printf("Numero in posizione %d:  %d\n", p, arr[p]);
    }

    printf("\n\n");
    return;
}

void map_lenght(char *stringhe[], int *lunghezze, int n){
    int j;  

    for (j = 0; j < n; j++) //assegnamo ai valori di lunghezze le lunghezze delle stringhe
        lunghezze[j] = strlen(stringhe[j]);
    
    
    return;

}

int main (void){
    
    char *str[10];
    str[0] = "lel";
    str[1] = "Lel"; //popoliamo le stringhe nel vettore stringhe

    int lung[N];
    int dim = 2;


    map_lenght(&str, lung, dim);

    stampa_array_int(lung, dim);

    return 0;
}

