/* 
Nome funzione: sopravvivono_maiuscole( char *stringhe[], int n) se la stringa inizia con maiuscola, tutto maiuscolo, altrimenti azzera

Descrizione funzione:

Dati in ingresso: 

Dati in uscita: 

Precondizione: 

Postcondizone: 

Pseudocodice:

*/
  // WIP serve aritmetica puntatori(forse)
#include <stdio.h>
#include <string.h>

#define max_len 30
#define N 1000

void transform_uppercase(char letter[], char buf[]){
    int i;
    char *willy = (char *)malloc((max_len + 1) * sizeof(char)); // variabile temporanea

    strcpy(willy, letter);

    for (i = 0; willy[i] != '\0'; i++)
        if (willy[i] >= 'a' && willy[i] <= 'z') { //se la lettera è tra 65 e 90 è uppercase
            willy[i] -= 32;   //quindi sottrai 32 
        }

    strcpy(buf, willy);
    free(willy);

    return;
}

void sopravvivono_maiuscole(char **stringhe, int n){
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


int main (void){
    int num = 3;
    char **str = malloc( num * sizeof(char *));
    int i;
    for (i = 0; i < num; i++)
        str[i] = malloc ((max_len + 1) * sizeof(char));

    str[0] = "Lel";
    str[1] = "aael";
    str[2] = "La vispa teresa";



    sopravvivono_maiuscole(str, num);

    for (int k = 0; k < num; k++){  // stampiamo le stringhe
        printf("\nStringa n. %d", k);
        printf("\n%s\n\n", str[k]);
    }



    return 0;
}

