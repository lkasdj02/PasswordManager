#include "string_utils.h"

int len(char *s) {

    // PRE: s è un puntatore ad un array di caratteri
    // POST: la funzione ritorna la lunghezza di una parola.
    
    int counter = 0;
    while (*(s + counter) != '\0') 
        counter += 1;
    return counter;
}

int replace(char *s, int pos, char replacement) {
    
    // PRE: s è un puntatore ad un array di caratteri
    // POST: la funzione ritorna un intero che specifica se l'operazione di rimpiazzo del.
    // carattere in una posizione della stringa è andato a buon fine.

    if (pos > (len(s) - 1))
        return 0;
    else {
        s[pos] = replacement;
        return 1;
    }
        
}

void split(char *s, char **r) {
    int l_word = 0;
    for (int i = 0; i < sizeof(s) / sizeof(char); i += 1) {
         
    } 
}
