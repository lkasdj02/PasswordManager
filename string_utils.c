#include "string_utils.h"
#define MAX_LENGTH 255
#define VOID_STRING " "
#define SPACE ' ' 

//#include <stdlib.h>

int len(char *s) {

    // PRE: s è un puntatore ad un array di caratteri
    // POST: la funzione ritorna la lunghezza di una parola.
    
    int counter = 0;
    while (s[counter] != '\0' && s[counter] != 10) {
      // printf("%d ", s[counter]); DEBUG
      counter+=1;
    }
    return counter;
}

void copy(char *s, char *c) {
    for (int i = 0; i <= len(c); i += 1)
        if (i == len(c))
            s[i] = '\0';
        else
            s[i] = c[i];
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

int to_lowercase(char *s) {

    // PRE: s è un puntatore ad un array di caratteri.
    // POST: la funzione rimpiazza ogni singolo carattere alfabetico maiuscolo con il corrispondente minuscolo.
    
    for (int i = 0; i < len(s); i+=1) 
        if (s[i] >= 65 && s[i] <= 90)
            s[i]+=32; // conversione in codice ASCII minuscolo.
    return 1;
}

int equals(char *s1, char *s2) {

    // PRE: s1 e s2 sono due array di caratteri
    // POST: la funzione ritorna 1 se le due stringhe sono uguali
    // 0 altrimenti.
    
    //printf("equals function : %s %s\n", s1, s2);
    //printf("equals function : %d %d\n", len(s1), len(s2));
  
    if (len(s1) != len(s2)) {
        return 0;
    }

    for (int i = 0; i < len(s2); i += 1)
        if (s1[i] != s2[i])
            return 0;

    return 1;
}

void clear_string(char *s, int len) {
    
    // PRE: s è un puntatore ad un array di caratteri e len è la sua lunghezza.
    // POST: la funzione ritorna l'array s ma pieno di spazi (un'array ripulito dai caratteri precedenti). 

    for (int i = 0; i < len; i += 1) {
        s[i] = ' ';
    }
}

int split(char *s, char split, char ***puntatore) {
    
    if (len(s) == 0)
      return 0;
    // PRE: s è un puntatore ad un array di caratteri, split è il carattere separatore e 
    // puntatore è il riferimento (indirizzo) ad un puntatore a puntatore.
    
    // POST: la funzione ritorna il numero di parole che si ottengono dividendo la stringa in corrispondenza
    // del carattere separatore; inoltre memorizza nella HEAP le parole ottenute da tale divisione.
    // questo sono accedibili alla funzione chiamante mediante puntatore a puntatore.
    
    // BUFFER
    char buffer[MAX_LENGTH]; 
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
    //printf("string count: %d\n\n", string_count); // DEBUG
     
    // dichiarazione di un array di puntatori locale.
    char *words[string_count];
    *puntatore = malloc(sizeof(char *) * string_count);
    string_count = 0; // reinizializzazione per poter copiare i puntatori nell'array di puntatori denominato words.
    
    printf("lunghezza di s: %d.\n", len(s));

    for(int i = 0; i < len(s); i += 1) {
        if (s[i] == split) // CARATTERE DI SPLIT
        {
            buffer[buffer_count] = '\0'; // inizializzare ultimo elemento come fine riga.
            char *p = (char *)malloc(sizeof(char) * len(buffer)); 
            // array_puntatori[string_count] = p; // mettere il puntatore all'interno dell'array degli indirizzi.
            printf("%s\n", buffer);
            //copy(p, buffer); 
            strcpy(p, buffer); // copia della stringa la stringa.
            words[string_count++] = p; // posizione corrente di words va assegnata al puntatore appena creato.
            
            clear_string(buffer, buffer_count); // "ripulire" il contenuto del buffer. 
            buffer_count = 0;
        } 
        else
        {
            buffer[buffer_count++] = s[i];
            //printf("%c", buffer[buffer_count - 1]);
            if (i == (len(s) - 1)) // caso in cui siamo al carattere finale.
            {  
                buffer[buffer_count] = '\0';
                char *p = (char *)malloc(sizeof(char) * len(buffer)); 
                // array_puntatori[string_count] = p; // mettere il puntatore all'interno dell'array degli indirizzi.

                printf("%s\n", buffer);
                //copy(p, buffer);
                strcpy(p, buffer); // copia della stringa la stringa.
                words[string_count++] = p; // posizione corrente di words va assegnata al puntatore appena creato.
            }
        } 
    }

    // DEBUG 
    //for (int i = 0; i < string_count; i += 1)
    //  printf("stringa words in posizione %d: %s; indirizzo nella heap: %p.\n", i, words[i], words[i]);

    for (int i = 0; i < string_count; i += 1) {
      *((*puntatore) + i) = words[i];
        //printf("stringa words in posizione %d: %s; \t indirizzo nella heap: %p.\n", i, array_puntatori[i], array_puntatori[i]);
    } 
    //for (int i = 0; i < string_count; i += 1)
    //  printf("stringa words in posizione %d: %s; indirizzo nella heap: %p.\n", i, (*puntatore)[i], (*puntatore)[i]);


    return string_count;
}

int free_split(char ***p, int words) {
    
    // PRE: p è il riferimento ad un puntatore a puntatore/i 
    // POST: la funzione permette di ripulire la memoria allocata dinamicamente dalla funzione split.

    for (int i = 0; i < words; i += 1) 
        free((*p)[i]);
    free(*p);
    return 1;
}


