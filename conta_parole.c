/* 
Nome funzione: count_words

Descrizione funzione: Conta il numero di parole in una stringa

Dati in ingresso: una stringa 

Dati in uscita: il numero delle parole contenute nella stringa

Precondizione: 

Postcondizone: il valore di ritorno deve corrispondere al numero di parole separate da spazi, tab e newline

Pseudocodice:
    ciclo la stringa
        se il carattere corrente è uno degli spazi
            incrementa contatore
    restituisci il contatore + 1

*/

#include <stdio.h>
#define N 1000

int count_words(char str[]){
    int count_breaks = 0;
    int i;

    for (i = 0; str[i] != '\0'; i++) //cicla la stringa fino alla fine
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')  //se il carattere corrente è uno spazio, incrementa il contatore
            count_breaks++;

    return count_breaks + 1;    //ritorna il numero degli spazi +1, ossia le parole
}

int main (void){
    char str_arr[N] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed\ndo eiusmod tempor incididunt ut labore et dolore magna aliqua.";

    printf("La stringa è: %s\n\n", str_arr);
    printf("Le parole sono: %d\n\n", count_words(str_arr));


    return 0;
}

