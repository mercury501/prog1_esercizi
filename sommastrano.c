#include <stdio.h>



int main(void){

    int number;
    int count = 0;

    
    printf("Please insert number\n");
    scanf("%d", &number);

    if ((number%2) != 0)
        number -= 1;


    for(int i = 0; i <= number; i++){  
        count += 2*i;

    }

    printf("\n\nTotale:   %d", count);

    return 0;
}