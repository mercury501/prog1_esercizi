/* 
Nome funzione: sopravvivono_maiuscole( char *stringhe[], int n) se la stringa inizia con maiuscola, tutto maiuscolo, altrimenti azzera

Descrizione funzione:

Dati in ingresso: 

Dati in uscita: 

Precondizione: 

Postcondizone: 

Pseudocodice:

*/
    // wip, da rifare con allocazione dinamica
#include <stdio.h>
#include <string.h>

#define N 1000

void transform_uppercase(char letter[], char buf[]){
    int i;
    char temp[N];
    strcpy(temp, letter);

    for (i = 0; temp[i] != '\0'; i++)
        if (temp[i] >= 'a' && temp[i] <= 'z') { //se la lettera è tra 65 e 90 è uppercase
            temp[i] -= 32;   //quindi sottrai 32 
        }
    strcpy(buf, temp);
    return;
}

void sopravvivono_maiuscole(char *stringhe[], int n){
    int i;
    char buffer[N];

    for (i = 0; i < n; i++)    //ciclo i per il primo indice del vettore di stringhe
        if (*stringhe[i] >= 'A' && *stringhe[i] <= 'Z'){   //se la prima lettera della stringa è maiuscola, maiuscoliamo tutto
            transform_uppercase(stringhe[i], buffer);
            strcpy(stringhe[i], buffer);   //senza stella è la stringa
            *buffer = '\0';
            //strcpy(stringhe[i], buffer); //needs malloc?
        }

        else    //altrimenti azzeriamo 
        {
            stringhe[i] = ""; //senza stella punta alla stringa
        }
        


    return;
}


int main (void){
    char *str[10];
    int num = 3;

    str[0] = "lel";
    str[1] = "Lel";
    str[2] = "La vispa teresa";



    sopravvivono_maiuscole(&str, num);

    for (int k = 0; k < num; k++){
        printf("\nStringa n. %d", k);
        printf("\n%s\n\n", str[k]);
    }



    return 0;
}

