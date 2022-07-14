#include <stdio.h>
#include <stdlib.h>

// tipo di dato fondamentale da memorizzare su disco.
typedef struct record {
    char sito[50];
    char mail[50];
    char password[50];
} RECORD; 

RECORD *create_record(char *sito, char *account, char *password);
int insert(FILE *fp, char *path, char *mode, RECORD *r);
int count_records(FILE *fp, char *path, char *mode);
int find_position(FILE *fp, char *path, char *mode, char *s, char *a);
int select_all(FILE *fp, char *path, char *mode, RECORD **array_destinazione);
int select_some(FILE *fp, char *path, char *mode, char *s, char *a, RECORD **array_destinazione); 
int update_record(FILE *fp, char *path, char *mode, RECORD *r);
