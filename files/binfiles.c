#include <stdio.h>
#include <stdlib.h>


int write_file_bin(const void *ptr, size_t size, size_t nmemb, char filename[]){
    FILE *savefile;
    savefile = fopen(filename, "wb");

    if (savefile == NULL){
        fprintf(stderr, "cant open es1 for writing\n");
        exit(1);

    }

    fwrite(ptr, size, nmemb, savefile);
    fclose(savefile);


}



int main(void){
    

    int a[] = {-1, 2, -3, 4, -5, 6};

    
    write_file_bin(&a[0], sizeof(int), 6, "es1.dat");
    

    
    return 0;
    
}