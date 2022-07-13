#include <stdio.h>
#include <stdlib.h>

// tipo di dato fondamentale da memorizzare su disco.
typedef struct record {
    char sito[50];
    char mail[50];
    char password[50];
} RECORD; 

RECORD *create_record(char *sito, char *account, char *password);
int select_all(FILE *fp, char *mode, RECORD **array_destinazione);
int insert(FILE *fp, char *mode, RECORD *r);
