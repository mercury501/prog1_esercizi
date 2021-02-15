#include <stdio.h>
#include <stdlib.h>


int write_file_bin(const void *ptr, size_t size, size_t nmemb, char filename[]){ //ptr è puntatore a cosa scrivere sul file, size è la dimensione di ogni elemento, dato che è
    FILE *savefile; //un array di int la chiameremo con sizeof(int), nmemb è il numero di elementi da scrivere, e il filename è il nome del file. qui creiamo un puntatore a file
    savefile = fopen(filename, "wb");   //apriamo il file in Write Binary mode

    if (savefile == NULL){  //controlliamo che non sia  inesistente il file
        fprintf(stderr, "cant open es1 for writing\n");
        exit(1);

    }

    fwrite(ptr, size, nmemb, savefile); //chiamiamo fwrite con gli argomenti sopracitati
    fclose(savefile);   //chiudiamo il file


}



int main(void){
    

    int a[] = {-1, 2, -3, 4, -5, 6};

    
    write_file_bin(&a[0], sizeof(int), 6, "es1.dat");
    

    
    return 0;
    
}
