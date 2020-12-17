#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 20

struct persona{
    char nome[N];
    char cognome[N];
    char cod_fiscal[N];   //hash è ogni lettera di username moltiplicata, e divisa per dieci, più il numero, vedi add user

};

bool check_c_fisc(char cod[]){

    bool numbers[16] = {0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0};
    int i;

    if (strlen(cod) != 16)
        return 0;

    for(i = 0; i < 16; i++)
        if (cod[i] > 'a' && cod[i] < 'z' && numbers[i])   //se il carattere corrente è una lettera, e non deve esserlo
            return 0;
    
    return 1;

}


void print_user(struct persona *p, int index){

    printf("\nIndice: %d\nNome: %s\nCognome: %s\nC.Fiscale: %s\n", index, p[index].nome, p[index].cognome, p[index].cod_fiscal);

    return;
}

/*
void delete_user(struct persona *p,int *dim, int index){    //TODO

    int i;
    for (i = index + 1; i < dim; i++ ) {   //copia ogni elemento a ritroso, sovrascrivendo quello da eliminare

        strcpy(p[i - 1].nome, p[i].nome);
        strcpy(p[i - 1].cognome, p[i].cognome);
        strcpy(p[i - 1].cod_fiscal, p[i].cod_fiscal);

    }

    *dim --;
    return;
}
*/

void add_user(struct persona *p, int *d){

    int i;
    //TODO allocazione dinamica

    printf("\nInserire il nome :  ");
    scanf("%s", p[*d].nome);
    printf("\nInserire il cognome:  "); //legge i valori da tastiera
    scanf("%s", p[*d].cognome);

    do{
    printf("\nInserire il codice fiscale esatto:  ");
    scanf("%s", p[*d].cod_fiscal);

    } while (!check_c_fisc(p[*d].cod_fiscal));

    *d = *d + 1;
    return;
}

bool check_string_equal(char s[], char s1[]){

    int i;
    int len = strlen(s);
    if (len!= strlen(s1))
        return false;


    for(i = 0; i < len; i++)
        if (s[i] != s1[i])
            return false;
    
    return true;
}

void cerca_per_nome(struct persona *p, int dim){
    char nome[N];
    char cognome[N];
    int i;

    printf("\nInserire nome:  ");
    scanf("%s", nome);

    printf("\nInserire cognome:  ");
    scanf("%s", cognome);

    for (i=0; i < dim; i++)
        if (check_string_equal(nome, p[i].nome) && check_string_equal(cognome, p[i].cognome)){

            printf("\nMatch trovato : %d\n", i);
            print_user(p, i);


        }

    


    return;
}


void cerca_per_codice(struct persona *p, int dim){

    char codice[N];
    int i;

    printf("\nInserire il codice fiscale:  ");
    scanf("%s", codice);

    for (i = 0; i < dim; i++)
        if (check_string_equal(codice, p[i].cod_fiscal)){
            printf("\nMatch trovato : %d\n", i);
            print_user(p, i);

        }

    return;
}



void cerca_persona(struct persona *p, int dim){
    int choice;
    printf("\nCercare per nome e cognome (1) o per codice fiscale(2)?\n");
    scanf("%d", &choice);

    switch (choice){
        case 1:
            cerca_per_nome(p, dim);
            break;

        case 2:
            cerca_per_codice(p, dim);
            break;

        default:
            printf("\nSelezione non valida\n");
            break;




    }


    return;

}

int main(void){
    int choice, i;
    struct persona *lista_utenti;  //crea una lista di utenti
    int dim = 0;


    while (choice != -1) {

        printf("Operazione? 1 aggiungi utente, 2 elimina utente, 3 stampa utente, 4 cerca persona, -1 per uscire\n");
        scanf("%d", &choice);

        switch(choice){ //sceglie l'operazione da effetturare sulla lista
            case 1:
                add_user(lista_utenti, &dim);
                break;

            case 2:
                printf("qual'è l'indice dell'utente da eliminare?\n");
                scanf("%d", &choice);
                //delete_user(lista_utenti, choice);
                break;
            
            case 3:
                printf("qual'è l'indice dell'utente da stampare?\n");
                scanf("%d", &choice);
                print_user(lista_utenti, choice);
                break;

            case 4: //cerca nome e cognome
                cerca_persona(lista_utenti, dim);
                break;

            case 5: //cerca cod fiscale

                break;


            case -1:
                printf("Exiting\n");
                break;
            
            default:
                printf("error, command not recognized\n");
                choice = -1;
                break;

        }
    }
    

    return 0;

}