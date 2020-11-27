/* 
check_letter_lowercase
Descrizione programma: prende in input un carattere, e se è upper case lo restituisce lower, altrimenti lo lascia invariato

Dati in ingresso: un carattere char

Dati in uscita: lo stesso carattere char, lowercase se fosse upper

Precondizione: 

Postcondizone: il valore restituito non può essere uppercase

Pseudocodice:
    se il carattere rientra tra i valori ascii di A e Z
        somma l'offset per farlo diventare lowercase

*/

#include <stdio.h>
#define N 100
char check_letter_lowercase(char letter){
    if (letter >= 65 && letter <= 90)  //se la lettera è tra 65 e 90 è uppercase
        letter += 32;   //quindi agginugi 32 
    
    return letter;
}

char *strlower(char arr_str[]){
    int i;
    for (i = 0; arr_str[i] != '\0'; i++)  //ciclo sulla stringa fino a null
        arr_str[i] = check_letter_lowercase(arr_str[i]);    //associamo il return della funzione precedente

    return &arr_str[0]; //ritorniamo l'indirizzo del primo elemento di arr_str, facendo return arr_str; sarebbe la stessa cosa
}

int main (void){
    char array[N] = "Buon Natale";

    printf("%s\n", strlower(array));


    return 0;
}

