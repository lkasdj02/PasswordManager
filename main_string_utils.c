#define MAX_LENGTH 255
#define SPACE ' ' 
#include <stdio.h>
#include <stdlib.h>
#include "string_utils.h"

int main() {

    char stringa[MAX_LENGTH];


    printf("inserire una stringa: \t");
    fgets(stringa, MAX_LENGTH, stdin);
    int r = replace(stringa, (len(stringa) - 1), '\0'); 
    if (r) 
        for (int i = 0; i < len(stringa); i += 1)
            printf("%d ", stringa[i]);

    printf("\n"); 
    printf("lunghezza: %d\n", len(stringa)); 
    
    // LOWERCASE TEST

    /*
    int c = to_lowercase(stringa);
    c ? 
        printf("%s", stringa) : 
        printf("vi è stato un problema con la funzione.");    
    */

    // SPLIT TEST
    char **puntatore_parole;
    int words = split(stringa, SPACE, &puntatore_parole); // leonardo basso leo

    printf("PAROLE NEL MAIN: %d.\n", words);
    printf("indirizzo nella heap dell'array di parole: %p \t sizeof puntatore: %lu \n", puntatore_parole, sizeof(puntatore_parole));
    for (int i = 0; i < words; i += 1) 
        printf("parola %d: %s. \t indirizzo nella heap: %p \n", i, *(puntatore_parole + i), puntatore_parole[i]);

    printf("%p indirizzo nel main \t indirizzo contenuto: %p \t primo indirizzo puntato: %p\n", &puntatore_parole, puntatore_parole, puntatore_parole[0]);
    int s = free_split(&puntatore_parole, words);   
    s ? 
        printf("memoria deallocata con successo") : 
        printf("vi è stato un problema con la gestione della memoria.");
    // FREE DELLA MEMORIA DINAMICA.
    // a questo punto, dopo aver allocato queste parole...
    // bisogna fare una cosa...deallocarle...
    // si deallocano prima i contenuti puntato dai vari puntatori a char creati con la funzione split
    // poi si vanno a deallocare i contenuti stessi.
/*
    for (int i = 0; i < words; i += 1) {
        free(puntatore_parole[i]);
    }
    free(puntatore_parole);
 */    

}
