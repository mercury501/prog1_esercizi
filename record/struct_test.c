#include <stdio.h>


struct cittadino {
    int number;
    char name[20];

};

void print_cittadino(struct cittadino p){

    printf("Cittadino numero:  %d\n", p.number);
    printf("Nome:  %s\n", p.name);

    return;
}

int main(void){

    struct cittadino lello = {1234, "Lello Esposito"};

    //oppure
    lello.number = 5678;

    print_cittadino(lello);


    return 0;
}