#include <stdio.h>

void trasforma_secondi(int *ore, int *min, int *sec, int numsec){

    *ore = numsec / 3600;

    numsec -= *ore * 3600;

    *min = numsec / 60;

    numsec -= *min * 60;
    
    *sec = numsec;

    return;
}

void trasforma_secondi_2(int *ore, int *min, int *sec){
    int temp = *sec;

    *ore = temp / 3600;

    temp -= *ore * 3600;

    *min = temp / 60;

    temp -= *min * 60;
    
    *sec = temp;
    
    return;
}

void trasforma_secondi_3(int *ore, int *min, int *sec){
    
    *ore = *sec / 3600; //prendendo i nomi con la stella equivale a manipolare il valore

    *sec -= *ore * 3600;

    *min = *sec / 60;

    *sec -= *min * 60;
    
    return;
}

int main(void){
    
    
    int ore, min, sec;
   
    int *h = &ore;  //inizializziamo puntatori alle variabili sopra dichiarate
    int *m = &min;
    int *s = &sec;

    printf("inserisci i secondi\n");
    scanf("%d", s); //legge i secondi da tastiera, dato che s è puntatore non c'è bisogno della &



    //qui chiama la funzione, solo coi nomi dei puntatori che equivalgono agli indirizzi
    trasforma_secondi_3(h, m, s);   //qui usa la terza iterazione della funzione

    printf("\nore : %d, minuti : %d, secondi: %d\n", ore, min, sec);



    return 0;
}