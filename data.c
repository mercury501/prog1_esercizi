
/*

gg
dati ingresso: data
precondizione: data > 1101582 e < 31129999 (gia controllata)
dati in uscita: giorni
postcondizione: i giorni sono le prime due cifre di data


mm
dati ingresso: data
precondizione: data > 1101582 e < 31129999 (gia controllata)
dati in uscita: mese
postcondizione: i mesi sono le seconde due cifre di data

verifica

dati ingresso: anno mese giorno
precondizione: nessuna
dati in uscita: valido

postcondizione: valido è vero se:
    giorno è compreso tra 1 e 31 se mese è 1 3 5 7 8 10 12
    giorno è compreso tra 1 e 30 se mese è 4 6 9 11
    giorno è compreso tra 1 e 30 se mese è 2 o 29 se bisestile
mese è compreso tra 1 e 12
anno è compreso tra 582 e 9999


*/

#include <stdio.h>


int verifica(int numero_data){

    int giorno, mese, anno;
    int valid = 1;
    int bisestile = 0;

    giorno = gg(numero_data);
    mese = mm(numero_data);
    anno = aaaa(numero_data);

    //controllo se l'anno è bisestile, lo è se è divisibile per 499 o se è divisibile per 4 ma non per 100
    if (((anno % 400) == 0) || (((anno % 4) == 0) && !((anno % 100) == 0 )))
        bisestile = 1;
    

    if (numero_data >= 1101582 && numero_data <= 31129999) {

        if (mese < 1 || mese > 12)
            valid = 0;
        if (anno < 582 || anno > 9999)
            valid = 0;

        if (mese == 4 || mese == 6 || mese == 9 || mese == 11)
            if (giorno > 30)
                valid = 0;

        if (mese == 2){
            if (bisestile == 1 && giorno > 29)
                valid = 0;
            if (bisestile == 0 && giorno > 28)
                valid = 0;       
        }

        else {
            if (giorno > 31)
                valid = 0;
        }
    
        
    }

    else {
        valid = 0;
    }


    
printf ("\nGiorno: %d, Mese: %d, Anno: %d \nBisestile: %d \n", giorno, mese, anno, bisestile);

return valid;   

}




int gg(int numero_data){
    return numero_data / 1000000;
}

int mm(int numero_data){
    int temp;
    temp = ((numero_data / 10000) % 10);
    temp += (((numero_data / 100000) % 10) * 10);
    return temp;
}

int aaaa(int numero_data){ // TODO controllo anno di 3 cifre
    int temp;
    temp = (numero_data % 10);
    temp += (((numero_data / 10) % 10) * 10);
    temp += (((numero_data / 100) % 10) * 100);
    temp += (((numero_data / 1000) % 10) * 1000);

    return temp;
}






int main(void){

    int data;

    printf("Inserisci una data per favore, ggmmaaaa:  ");
    scanf("%d", &data);



    if (verifica(data) == 1)    //== true è superfluo, ma scrivo per chiarezza
        printf("\nLa data è valida. \n\n");

    else
        printf("\nLa data non è valida. \n\n");


    return 0;
}