#include <stdio.h>

void stampa_oriz(int lato){

    while (lato > 0){
        printf("*");
        lato--;

    }

    return;
}

void stampa_vert(int latoa, int latob){

    int temp;
    latoa = latoa - 2;   //sottraggo 2 per avere il numero di spazi da stampare

    latob = latob - 2;  //sottraggo 2 poichè la prima e ultima riga le stampo in stampa_oriz

    while (latob > 0){
        temp = latoa;
        printf("\n*");         //a capo e primo asterisco

        while (temp > 0){     //spazi intermedi

            printf(" ");
            temp--;            

        }

        printf("*");        //asterisco finale
        latob--;
    }

    printf("\n");
    return;
}

int main(){

    int a, b;
    
    
    printf("Inserire numero a:  \n");
    scanf("%d", &a);

    printf("\n\nInserire numero b:  \n");
    scanf("%d", &b);


    stampa_oriz(a);

    stampa_vert(a, b);

    stampa_oriz(a);


    return 0;
}