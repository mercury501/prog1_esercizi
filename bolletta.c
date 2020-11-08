/*

dati in ingresso: codice cliente, lettura precedente, lettura attuale, canone. tutti float
costante: costo per kwh
variabile: lettura netta, costo

dati in uscita:codice cliente, kwh da addebitare, costo bolletta, float


pseudocode:
leggi codice cliente, lettura precedente e attuale, canone
differenza tra lettura attuale e precedente in lettura netta
moltiplicazione lettura netta per costo unitario più canone in costo
stampa codice, lettura netta, costo



*/
#include <stdio.h>



int main(){

    float prec_l, att_l, canone, nett_l, due_payment;
    int codice;
    float euro_per_kwh = 0.5;

    printf("Inserire, seguiti da invio, codice cliente, lettura precedente, lettura attuale ed infine il canone.\n");
    scanf("%d%f%f%f", &codice, &prec_l, &att_l, &canone);

    nett_l = att_l - prec_l;

    due_payment = (nett_l * euro_per_kwh) + canone;

    printf("\n\n Caro cliente %d,\nLei ci deve la bellezza di %.2f euro per i %.3f kwh che ha consumato.\n", codice, due_payment, nett_l);

    return 0;

}