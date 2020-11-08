#include <stdio.h>


float calcola_cons(float kil, float l){

    return (kil/l);

}





int main(){

    float num_k, litr, kil_per_litr;

    printf("Inserire i kilometri percorsi:\n");
    scanf("%f", num_k);

    printf("\n\nInserire i Litri consumati:\n");
    scanf("%f", litr);   


    kil_per_litr = calcola_cons(num_k, litr);



    printf("\n\nL'importo dovuto è:  %f\n", kil_per_litr);

}