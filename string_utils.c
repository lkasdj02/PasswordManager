#include "string_utils.h"

int len(char *s) {

    // PRE: s è un puntatore ad un array di caratteri
    // POST: la funzione ritorna la lunghezza di una parola.
    
    int counter = 0;
    while (*(s + counter) != '\0') 
        counter += 1;
    return counter;
}

void split(char *s, char **r) {
    int l_word = 0;
    for (int i = 0; i < sizeof(s) / sizeof(char); i += 1) {
         
    } 
}
