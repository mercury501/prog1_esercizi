/* 
Nome funzione: sopravvivono_maiuscole( char *stringhe[], int n) se la stringa inizia con maiuscola, tutto maiuscolo, altrimenti azzera

Descrizione funzione:

Dati in ingresso: 

Dati in uscita: 

Precondizione: 

Postcondizone: 

Pseudocodice:

*/

#include <stdio.h>
#include <string.h>

#define max_len 100
#define N 1000

void transform_uppercase(char letter[]){
    int i;
    char *willy = (char *)malloc((max_len + 1) * sizeof(char)); // variabile temporanea

    strcpy(willy, letter);

    for (i = 0; willy[i] != '\0'; i++)
        if (willy[i] >= 'a' && willy[i] <= 'z') { //se la lettera è tra 65 e 90 è uppercase
            willy[i] -= 32;   //quindi sottrai 32 
        }

    strcpy(letter, willy);
    free(willy);

    return;
}

char **i_will_survive_if_uppercase(char **strng, int dm){

    int i;
    char **buffer = malloc(dm * sizeof(char *));    // allochiamo array di stringhe, come nel main
    for (i = 0; i < dm; i++){
        buffer[i] = malloc( (max_len + 1) * sizeof(char));
        strcpy(buffer[i], strng[i]);
    }

    for (i = 0; i < dm; i++)   //ciclo i per il primo indice del vettore di stringhe
        if (*buffer[i] >= 'A' && *buffer[i] <= 'Z'){   //se la prima lettera della stringa è maiuscola, maiuscoliamo tutto
            transform_uppercase(buffer[i]);
            
        }

        else    //altrimenti azzeriamo 
        {
            *buffer[i] = '\0';
        }
    
        
    return buffer;
}

/*
void sopravvivono_maiuscole(char **stringhe, int n){    //deprecata, confusa e con seri problemi di carburatore
    int i;
    char *buffer = (char *)malloc((max_len + 1) * sizeof(char));

    for (i = 0; i < n; i++)   //ciclo i per il primo indice del vettore di stringhe
        if (*stringhe[i] >= 'A' && *stringhe[i] <= 'Z'){   //se la prima lettera della stringa è maiuscola, maiuscoliamo tutto
            transform_uppercase(stringhe[i], buffer);
            strcpy(stringhe[i], "buffer");  //needs aritmetica puntatori?
            //strcpy(stringhe[i], buffer);   //senza stella è la stringa
            *buffer = '\0';
            
        }

        else    //altrimenti azzeriamo 
        {
            stringhe[i] = "\0"; //senza stella punta alla stringa
        }
    
        
    free(buffer);

    return;
}
*/

int main (void){
    int num = 7;    //dimensione dell'array di stringhe

    char **str = malloc( num * sizeof(char *)); //allochiamo spazio per l'array di puntatori a stringa
    int i, k;
    for (i = 0; i < num; i++)   //allochiamo lo spazio effettivo per le stringhe
        str[i] = malloc ((max_len + 1) * sizeof(char));

    str[0] = "Lul";
    str[1] = "aael";
    str[2] = "Il succo della storia fin qui.";
    str[3] = "io non resisterò";
    str[4] = "Al principio fu creato l'Universo.";
    str[5] = "io neanche"; 
    str[6] = "Questo fatto ha sconcertato non poche persone ed è stato considerato dai più come una cattiva mossa.";



    //sopravvivono_maiuscole(str, num);

    str = i_will_survive_if_uppercase(str, num);   //la funzione ritorna un puntatore a puntatori di stringhe
    
    for (k = 0; k < num; k++){  // stampiamo le stringhe
        printf("\nStringa n. %d:  ", k);
        printf("%s", str[k]);
    }

    printf("\n");

    return 0;
}

