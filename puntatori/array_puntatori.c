#include <stdio.h>
#define MAX 4



void riempi(int **arr, int colonne){
    int i, j;

    for (i = 0; i < colonne; i++)   //cicla su tutte le colonne
    
        for (j = 1; j < *arr[i] + 1; j++){  //e su ogni elemento della riga, a parte il primo dove c'è la dimensione
            printf("\nInserisci numero %d, %d \n", i, j);
            scanf("%d", &arr[i][j]);    //legge il numero, passando a scanf l'indirizzo dell'elemento i j esimo

        }

    

    return;
}

int main(void){
    int *A[MAX], i, n, j;

    for(i = 0; i < MAX; i++){
        printf("\nLunghezza riga %d:  ", i);    //chiede all'utente la lunghezza di ogni riga dell'array bidimensionale
        scanf("%d", &n);
        A[i] = calloc(n + 1, sizeof(int));  //alloca n+1 celle della grandezza di un int
        if (!A[i]){
            printf("Spazio in memoria esaurito\n"); //se il puntatore è null, la memoria è finita
            return;
        }
        A[i][0] = n;    //piazza la lunghezza della riga nl primo elemento di ognuna

    }

    riempi(A, MAX); //chiamiamo la funzione
    
    for (i = 0; i < MAX; i++)   //stampiamo l'array
        for (j = 1; j <= A[i][0]; j++)
            printf("\nNumero %d, %d:   %d", i, j, A[i][j]);
    
    


    printf("\n");
    return 0;
}