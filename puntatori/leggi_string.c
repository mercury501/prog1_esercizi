#include <stdio.h>
#include <string.h>
#define N 100

char *leggi_stringa(){  //**a = a[0] *a[0]
    char buf[N];

    printf("Scrivi la stringa");
    scanf("%s", buf);

    char *s = calloc(strlen(buf) + 1, sizeof(char));  

    strcpy(s, buf);
    
    return s;
}

char **crea_array_string(int *rg){
    char buf[N];
    int righe, i;



    printf("Quante stringhe?\n");
    scanf("%d", &righe);
    getchar();  //per levare il carattere newline dal buffer

    *rg = righe;    //portiamo fuori il numero di righe
    char **arr_str = malloc( righe * sizeof(char *));   //dichiara array di puntatori a char

    for(i = 0; i < righe;i ++){

        printf("\nInserire stringa numero %d:  ", i);

        fgets(buf, N, stdin);
        //scanf("%s", buf);

        arr_str[i] = calloc(strlen(buf) + 1, sizeof(char));
        strcpy(arr_str[i], buf);


    }
    

    return arr_str;

}



int main(void){
    int i;
    int rg;


    char *st = leggi_stringa();

    printf("%s\n\n", st);
    

    char **a_st = crea_array_string(&rg);    //la funzione ritorna un puntatore a puntatori, e le passiamo l'indirizzo di rg, cioè quante righe ci sono nell'array

// sezione array stringhe

    for (i = 0; i < rg; i++)
        printf("\n%s", a_st[i]);

    printf("\n");

    return 0;

}