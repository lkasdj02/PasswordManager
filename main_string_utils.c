#define MAX_LENGTH 255
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
    
    // SPLIT TEST
     
    char **puntatore_parole;
    
    int words = split(stringa, ' ', &puntatore_parole); // leonardo basso leo

    printf("PAROLE NEL MAIN: %d.\n", words);
    for (int i = 0; i < words; i += 1) {
        printf("parola %d: %s\n", i, puntatore_parole[i]);
    }
    // a questo punto, dopo aver allocato queste parole...
    // bisogna fare una cosa...deallocarle...
    // si deallocano prima i contenuti puntato dai vari puntatori a char creati con la funzione split
    // poi si vanno a deallocare i contenuti stessi.
    // 
    /*
    int *p = (int *)malloc(sizeof(int) * 4);

    for (int i = 0; i < 4; i += 1) {
        *(p + i) = i;
        printf("%d", *(p + i));
    } */
}
