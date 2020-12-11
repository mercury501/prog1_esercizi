#include <stdio.h>
#include <string.h>
#define N 100

struct persona{
    int number;
    char username[20];
    int hash;   //hash è ogni lettera di username moltiplicata, e divisa per dieci, più il numero, vedi add user

};

void print_user(struct persona *p, int index){

    printf("\nNumero utente: %d\nUsername: %s\nHash: %d\n", p[index].number, p[index].username, p[index].hash);

    return;
}

void delete_user(struct persona *p, int index){

    int i;
    for (i = index + 1; p[i].number != 0; i++ ) {   //copia ogni elemento a ritroso, sovrascrivendo quello da eliminare

        p[i - 1].number = p[i].number;
        strcpy(p[i - 1].username, p[i].username);
        p[i - 1].hash  = p[i].hash;

        if (p[i + 1].number == 0)   //se il prossimo elemento è vuoto, questo va azzerato 
            p[i].number = 0;

    }


    return;
}

void add_user(struct persona *p){

    int i, index;
    int temp = 1;

    for(i = 0; i <= N && p[i].number != 0; i++)    {}   //usa un for per trovare l'index del primo utente vuoto
    index = i;

    printf("\nInserire il numero utente:  ");
    scanf("%d", &p[index].number);
    printf("\nInserire l'username:  "); //legge i valori da tastiera
    scanf("%s", p[index].username);

    for (i = 0; i < strlen(p[index].username); i++) //crea l'hash con un algoritmo arbitrario
        temp *= ((int)p[index].username[i]) / 10;

    temp += p[index].number;

    p[index].hash = temp;



    return;
}



int main(void){
    int choice, i;
    struct persona lista_utenti[N];  //crea una lista di utenti

    for (i = 0; i <= N; i++)    //pone tutti i campi number a 0
        lista_utenti[i].number = 0;


    while (choice != -1) {

        printf("Operazione? 1 aggiungi utente, 2 elimina utente, 3 stampa utente, -1 per uscire\n");
        scanf("%d", &choice);

        switch(choice){ //sceglie l'operazione da effetturare sulla lista
            case 1:
                add_user(lista_utenti);
                break;

            case 2:
                printf("qual'è l'indice dell'utente da eliminare?\n");
                scanf("%d", &choice);
                delete_user(lista_utenti, choice);
                break;
            
            case 3:
                printf("qual'è l'indice dell'utente da stampare?\n");
                scanf("%d", &choice);
                print_user(lista_utenti, choice);
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