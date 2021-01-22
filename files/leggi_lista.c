#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 50

typedef struct persona {
    int num;
    char nome[MAX_LEN];
    char cognome[MAX_LEN];
    char noidea[MAX_LEN];

} persona;


void *xmalloc(size_t nbytes){

    void *result;

    result = malloc(nbytes);

    if (!result){
        fprintf(stderr, "xmalloc(%lu) failed, BYE\n", nbytes);
        exit(-1);
    }

    return result;

}

void stampa_persone(persona lista[], int dim){

    int i;

    for (i = 0; i < dim; i++)
        printf("\nIndice:  %d\nNome: %s\nCognome: %s\nCodice: %s\n", lista[i].num, lista[i].nome, lista[i].cognome, lista[i].noidea);


    return;
}


void carica_persone(FILE *file, persona lista[], int dim){
    char buffer[1000];
    int temp;
    int i, j, k, comma_found = 0, firstcomma;
    
    
    

    for (i = 0; i < dim; i++){
        fscanf(file, "%d", &temp);  //prendo il codice all'inizio con una scanf
        lista[i].num = temp;
        
        fgets(buffer, 100, file);   //poi il resto della riga in un buffer
        

        for(j = 0; buffer[j] != '\0'; j++){

            if (buffer[j] == ',' && comma_found == 0){    //prima virgola
            strncpy(lista[i].nome, buffer + 1, j - 1);  //copio dal secondo spazio fino alla virgola

            firstcomma = j; //salvo il posto della prima virgola che mi serve per dopo
            comma_found ++; //e salvo che ho trovato la prima virgola
            }

            else if (buffer[j] == ',' && comma_found == 1){    //seconda virgola
                for (k = firstcomma + 1; k != j && buffer[k] == ' '; k ++) {} //alla fine del ciclo in k ci sarà la posizione della prima lettera del cognome
                
                strncpy(lista[i].cognome, buffer + k, j - k);   // salvo dalla prima lettera del cognome, per j - k lettere

                for (k = j + 1; buffer[k] == ' '; k++) {}   //trovo il codice finale

                strncpy(lista[i].noidea, buffer + k, 4);        //e lo salvo

                comma_found ++; //potrei uscire dal ciclo, ma mettendo comma_found a 2 ciclerà fino alla fine del buffer senza fare nulla
            }
            

        }

        comma_found = 0;    //azzeriamo comma_found per la prossima iterazione

    }





    return;
}


int main(void){
    char ch;
    int linee = 0;
    //apro il file, conto le linee, alloco dinamicamente la lista e chiudo il file
    FILE *file;
    file = fopen("./files/lista.txt", "r");

    if (file == NULL){
        fprintf(stderr, "cant open file\n");
        exit(1);
    }

    while((ch=fgetc(file))!=EOF) {
      if(ch=='\n')
         linee++;
    }

    rewind(file);

    persona *lista = xmalloc(linee * sizeof(persona));

    carica_persone(file, lista, linee);

    fclose(file);
    //------------------------------------------
    
    stampa_persone(lista, linee);


    return 0;




}