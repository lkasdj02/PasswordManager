#include "string_utils.h"
#include <stdlib.h>
#include <string.h>

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

void clear_string(char *s, int len) {
    for (int i = 0; i < len; i += 1) {
        s[i] = ' ';
    }
}

int split(char *s, char split, char ***puntatore) {
    
    // BUFFER
    char buffer[255]; 
    int buffer_count = 0;
    
    // VARIABILI UTILI AL PROCESSO DI SPLITTING
    int char_count = 0;
    int string_count = 0;
    

    // CONTARE NUMERO PAROLE in base al carattere split.
    for (int i = 0; i < len(s); i += 1) {
        if (s[i] == split) {
            char_count+=1;
        }
    } 
    string_count = char_count + 1;
    printf("string count: %d\n\n", string_count); // DEBUG
     
    // dichiarazione di un array di puntatori locale.
    char *words[string_count];
    *puntatore = malloc(sizeof(char *) * string_count);
    string_count = 0; // reinizializzazione per poter copiare i puntatori nell'array di puntatori denominato words.
    
    for(int i = 0; i < len(s); i += 1) {
        if (s[i] == split) // CAARATTERE DI SPLIT
        {
            buffer[i] = '\0'; // inizializzare ultimo elemento come fine riga.
            char *p = (char *)malloc(sizeof(char) * len(buffer)); 
            // array_puntatori[string_count] = p; // mettere il puntatore all'interno dell'array degli indirizzi.

            strcpy(p, buffer); // copia della stringa la stringa.
            words[string_count++] = p; // posizione corrente di words va assegnata al puntatore appena creato.
            
            clear_string(buffer, buffer_count); // "ripulire" il contenuto del buffer. 
            buffer_count = 0;
        } 
        else
        {
            buffer[buffer_count++] = s[i];
            printf("%c\n", buffer[buffer_count - 1]);
            if (i == (len(s) - 1)) // caso in cui siamo al carattere finale.
            {  
                buffer[buffer_count] = '\0';
                char *p = (char *)malloc(sizeof(char) * len(buffer)); 
                // array_puntatori[string_count] = p; // mettere il puntatore all'interno dell'array degli indirizzi.

                strcpy(p, buffer); // copia della stringa la stringa.
                words[string_count++] = p; // posizione corrente di words va assegnata al puntatore appena creato.
            }
        } 
    }

    // DEBUG 
    for (int i = 0; i < string_count; i += 1)
        printf("stringa words in posizione %d: %s; \t indirizzo nella heap: %p.\n", i, words[i], words[i]);

    for (int i = 0; i < string_count; i += 1) {
        *((*puntatore) + i) = words[i];
        //printf("stringa words in posizione %d: %s; \t indirizzo nella heap: %p.\n", i, array_puntatori[i], array_puntatori[i]);
    } 
    return string_count;
}

