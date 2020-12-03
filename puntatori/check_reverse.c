#include <stdio.h>
#define N 100

int check_reverse(int *a, int *b, int dim){
    int reverse = 1;
    int i;

    for (i = 0; i < dim; i++)
        if (a[i] != b[dim - 1 - i])
            reverse = 0;

    return reverse;
}


int main(void){
    int a[N] = {10, 2, 5, 55};
    int b[N] = {55, 5, 2, 10};
    int dim = 4;

    int reverse = 1;

    int i, j;

    for (i = 0; i < dim; i++)
        if (a[i] != b[dim - 1 - i])
            reverse = 0;

    if (reverse)    //significa se il risultato di check reverse è 1
        printf("gli array sono uno  il contrario dell'altro\n");
    else
    {
        printf("gli array non sono uno il reverse dell'altro");
    }

    // oppure, con la funzione
    reverse = check_reverse(a, b, dim);

    if (reverse)    //significa se il risultato di check reverse è 1
        printf("gli array sono uno  il contrario dell'altro\n");
    else
    {
        printf("gli array non sono uno il reverse dell'altro");
    }
    


    return 0;
}