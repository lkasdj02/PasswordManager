#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define MAX_LENGTH 255
#define VOID_STRING " "
#define SPACE ' ' 

// PRE: s è un puntatore ad un array di caratteri
// POST: la funzione ritorna la lunghezza di una parola.
// (per lunghezza si intende il numero di caratteri escluso il new line feed)
int len(char *s);
void copy(char *s, char *c);
int replace(char *s, int pos, char replacement);
int to_lowercase(char *s);
int equals(char *s1, char *s2);
void clear_string(char *s, int len);
int split(char *s, char split, char ***puntatore);
int free_split(char ***p, int words);
