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


#include <stdio.h>
#include <string.h>
#define N 100


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
    int x = 3;
    int maxdim_str = 100;

    int len[N];
    char **str = (char **) malloc(x * sizeof(char*));   // questo alloca solo il primo strato, i puntatori a stringa

    int i;
    for (i = 0; i < x; i++)
        str[i] = malloc((maxdim_str + 1) * sizeof(char));   //il ciclo alloca lo spazio per le singole stringhe

    strcpy(str[0], "L'altro ieri ero lì");
    strcpy(str[1], "questa non va bene credo"); //popoliamo le stringhe nell'array
    strcpy(str[2], "credo funzioni ora");

    map_lenght(str, len, x);

    stampa_array_int(len, x);

   

    return 0;
}

