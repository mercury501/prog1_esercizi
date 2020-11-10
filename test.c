#include <stdio.h>
#define A 100

int inserimento(int Array[], int lung, int i, int x )
{
    int c;
    for(c = lung-1; c >= i; c--)
    {
        Array[c+1] = Array[c];
    }

    Array[i] = x;

    return lung+1;
}


int main(void)
{
    int Array[A], lunghezza, valore, c, cpf, casella;

    printf("Inserisci la lunghezza dell'array: \n");
    scanf("%d", &lunghezza);
    for(c = 0; c < lunghezza; c++)
    {
        printf("inserisci un valore: \n");
        scanf("%d", &Array[c]);
    }

    printf("Inserire il valore da aggiungere: \n");
    scanf("%d", &valore);
    printf("In che casella vuoi aggiungere il valore: \n");
    scanf("%d", &casella);

    lunghezza = inserimento(Array, lunghezza, casella, valore );

    for(cpf = 0; cpf < lunghezza; cpf++)

    {
        printf("\n\n%d\n\n", Array[cpf]);

    }

return 0;
}