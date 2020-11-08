/* 

Descrizione programma: realizzare un programma che calcola la media voti di una classe

Dati in ingresso: i voti degli alunni

Dati in uscita: la media

Precondizione: il voto deve essere compreso tra 18 e 30

Postcondizone:  la media deve essere compresa tra 18 e 30

*/

#include <stdio.h>




int main(){

    int num_alunni = 0;
    int temp_voto = 1;   //lo mettiamo uguale a 1 così il ciclo while parte, avrei fatto do while ma non l'ha spiegat
    int voti = 0;   //inizializzo a 0 poichè lo userò per aggiungerci i voti
    float media = 0;
    
    while (temp_voto > 0) {

        
        printf("Inserire il voto di uno studente, se ha terminato inserisca 0: \n");
        scanf("%d", &temp_voto);
        
        if (temp_voto >0){    //se ha inserito un voto valido, allora lo aggiungiamo al montepremi e incrementiamo il numero degli alunni
            voti += temp_voto;
            num_alunni += 1;
        }
    } 

    media =voti / num_alunni;
    


    printf("\n\nLa media è:  %f\nSu %d alunni.\n", media, num_alunni);

}