#include <stdio.h>
#include <string.h>
#define N 100


char *concatena(char *s1, char *s2){

    char *p = (char *) malloc(strlen(s1) + strlen(s2) + 1);

    if (!p)
        printf("error allocating \n");

    strcpy(p, s1);
    strcat(p, s2);

    return p;
}



int main(void){
    char *str = "lello ";
    char *str1 = "bidello";

    char *str2 = concatena(str, str1);

    printf("%s\n", str2);

    char *s = (char *) calloc(strlen(str1) + strlen(str) + 1);

    s = concatena(str1, str);

    printf("%s\n", s);

    free(s);    //liberiamo la memoria occupata da s

    printf("%s\n", s);  //non da errore, ma s non esiste più

    return 0;
}