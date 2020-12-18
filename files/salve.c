#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *load_name(FILE *fl){
    char nome[20];
    char *dyname;

    fread(nome, sizeof(char), 19, fl);   //se esiste leggiamo il nome

    return dyname;

}

char *read_save_name(FILE *fl){
    char nome[20];
    char *dyname;

    printf("Inserisci il tuo nome:  ");
    scanf("%s", nome);


    fwrite(nome, sizeof(char), strlen(nome), fl);  //scriviamo il nome sul file

    dyname = malloc(sizeof(char) * strlen(nome) + 1);
    strcpy(dyname, nome);

    return dyname;
}

int main(void){

    FILE *name_file;
    char *nome;

    name_file = fopen("nome123.txt", "r");  //proviamo ad aprire il file in lettura

    if (name_file == 0){ //se il file non esiste, allora
    name_file = fopen("nome123.txt", "w");  //creiamo un file in scrittura
    
    nome = read_save_name(name_file);
    
    }

    else
    {
        nome = load_name(name_file);
    }

    printf("\nSalve signor %s\n", nome);
    


    return 0;
}