#include <stdio.h>


int calcola_park(int time){

    return (2 + (time-1));

}





int main(){

    int ore_park, money_owed;

    printf("Inserire le ore di parcheggio:\n");
    scanf("%d", &ore_park);


    money_owed = calcola_park(ore_park);


    printf("\n\nL'importo dovuto è:  %d\n", money_owed);

}