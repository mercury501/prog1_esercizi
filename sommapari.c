#include <stdio.h>



int main(void){

    int number;
    int count = 0;

    
    printf("Please insert number\n");
    scanf("%d", &number);

    if ((number%2) != 0)
        number -= 1;


    for(int i = number; i > 0; i-=2){  //queste parentesi sono superflue, ma le includo
        count += i;

    }

    printf("\n\nTotale:   %d", count);

    return 0;
}