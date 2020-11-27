/* 
Nome funzione:check_substring

Descrizione funzione: cerca una sottostringa in una stringa, in maniera sovrapposta

Dati in ingresso: stringa e sottostringa

Dati in uscita: un bool, che indica 1 se è trovata e 0 altrimenti

Precondizione: la sottostringa deve essere più piccola della stringa, altrimenti è sicuramente non presente

Postcondizone: deve restituire 1 se trova la sottostringa nella stringa

Pseudocodice:
    controlla la precondizione
    scorri i caratteri della stringa
        flag = 0
        scorri la substringa confrontandola con stringa + offset
        se non ci son stati elementi diversi, esci e restituisci 1
        altrimenti continua col ciclo

*/

#include <stdio.h>
#include <stdbool.h>
#define N 1000

int impostor_strlen(char a[]){
    int n = 0;

    for (int i = 0; a[i] != '\0'; i++)  //finchè non trova il carattere terminatore, incrementa
        n++;

    return n;
}

bool check_substring(char string_[], char string_sub[]){
    bool flag;  //flag diventa 1 ogniqualvolta il ciclo interno trova lettere diverse nelle due stringhe, segnalando di dover uscire, sentinella per ciclo interno
    int i, j;

    if (impostor_strlen(string_) < impostor_strlen(string_sub)) //se la substringa è più grande della stringa, controllato usando una strlen fatta in casa, esci
        return 0;

    for (i = 0; string_[i] != '\0'; i++){  //gira sull'array principale
        flag = 0; 

        for (j = 0; string_sub[j] != '\0' && flag == 0; j++)    //compara la substringa con la stringa che parte dall'offset
            if (string_sub[j] != string_[i + j])    //se trova una lettera diversa, esce
                flag = 1;
    
        if (flag == 0)  //se non ci son stati elementi diversi nell'ultimo ciclo, vuol dire che la substringa è stata trovata
            return 1;
        
    }


return 0;

}

bool find_substring(char str[], char substr[]){
    bool result = check_substring(str, substr);
    printf("\n\nStringa: %s\nSubstringa: %s\n", str, substr);
    printf("Trovata: %d", result);
    
    return result;

}


int main (void){

    char s1[N] ="aaa bbb ccc d";
    char s2[N] ="a";
    char s3[N] ="a b";
    char s4[N] ="ccc d";
    char s5[N] ="d";
    char s6[N] ="bbbb";
    char s7[N] ="a cc";

    find_substring(s1, s2);
    find_substring(s1, s3);
    find_substring(s1, s4);
    find_substring(s1, s5);
    find_substring(s1, s6);
    find_substring(s1, s7);

    printf("\n\n");
    return 0;
}

