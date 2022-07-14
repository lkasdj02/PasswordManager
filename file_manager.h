#include <stdio.h>
#include <stdlib.h>

// tipo di dato fondamentale da memorizzare su disco.
typedef struct record {
    char sito[50];
    char mail[50];
    char password[50];
} RECORD; 

RECORD *create_record(char *sito, char *account, char *password);
int select_all(FILE *fp, char *path, char *mode, RECORD **array_destinazione);
int select_some(FILE *fp, char *path, char *mode, char *s, char *a, RECORD **array_destinazione); 
int insert(FILE *fp, char *path, char *mode, RECORD *r);
