#include <stdio.h>


int main(void){

    int data, temp_data, giorno1, giorno2, giorno, mese1, mese2, mese, anno;


    printf("Inserire data\n");
    scanf("%d", &data);

    temp_data = data; // copio data in una variabile temporanea, dato che dopo i nostri inciarmi perdiamo il contenuto
    
    giorno1 = temp_data / 10000000;
    temp_data = temp_data - giorno1 * 10000000;

    giorno2 = temp_data / 1000000;
    temp_data = temp_data - giorno2 * 1000000;

    giorno = giorno1*10 + giorno2;  //compongo il numero finale del giorno

    mese1 = temp_data / 100000;
    temp_data = temp_data - mese1 * 100000;

    mese2 = temp_data / 10000;
    temp_data = temp_data - mese2 * 10000;

    mese = mese1 * 10 + mese2;  //compongo il numero finale del mese

    anno = temp_data; //quello che rimane è sicuramente l'anno

    printf("Giorno:  %d\nMese:  %d\nAnno:  %d\n", giorno, mese, anno);

    return 0;

}