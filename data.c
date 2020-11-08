
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
#include <stdbool.h>

bool verifica(int numero_data){

    int data_temp, giorno_1, giorno_2;
    if (numero_data >= 1101582)  //se dopo l'if c'è un unica istruzione, le parentesi sono superflue
        if(numero_data <= 31129999){

            //MANCA VERIFICA

        }


    data_temp = numero_data;

    giorno_1 = data_temp/10000000;
    data_temp


}






//funzioni gg mm aaaa mancanti





int main(void){

    bool valido = 0;
    int data;

    printf("Inserisci una data per favore, ggmmaaaa:  ");
    scanf("%d", &data);


    if (verifica(data) == true)    //== true è superfluo, ma scrivo per chiarezza
        printf("\nLa data è valida.");

    else
        printf("\nLa data non è valida.");


    return 0;
}